#!env perl
#
# This program creates a Marpa BNF of a W3C BNF.
#
# The negation form "term - term" is forced to be a lexeme.
#
use strict;
use diagnostics;
use warnings FATAL => 'all';

our $LEXEME_RANGES       = 0;
our $LEXEME_CARET_RANGES = 1;
our $LEXEME_STRING       = 2;
our $LEXEME_HEXMANY      = 3;

###########################################################################
# package Actions                                                         #
###########################################################################

package Actions;
sub new() {
  my $self = {
              quantifiers => {},
              rules => [],
              lexemes => {},
              lexemesExact => {},
              lexemesWithExclusion => {},
              constraints => {},
	      symbols => {},
              start => {number => undef, rule => ''},
	      grammar => ''
             };
  return bless $self, shift;
}

sub _pushLexemes {
    my ($self, $rcp, $key) = @_;

  foreach (sort {$a cmp $b} keys %{$self->{$key}}) {
    if ($self->{$key}->{$_} eq '\'') {
      $self->{$key}->{$_} = '[\']';
    }
    my $content;
    if ($self->{$key}->{$_} =~ /^\[.+/) {
      push(@{$rcp}, $content = join(' ', $_, '~', $self->{$key}->{$_}));
    } elsif ($self->{$key}->{$_} =~ /^\\x\{/) {
      push(@{$rcp}, $content = join(' ', $_, '~', '[' . $self->{$key}->{$_} . ']'));
    } else {
      push(@{$rcp}, $content = join(' ', $_, '~', '\'' . $self->{$key}->{$_} . '\''));
    }
    $self->{symbols}->{$_} = {terminal => 1, content => $content};
  }
}

sub _pushG1 {
    my ($self, $rcp) = @_;

    foreach (@{$self->{rules}}) {
      my $content;
      push(@{$rcp}, $content = join(' ', $_->{lhs}, '::=', "@{$_->{rhs}}", $_->{quantifier}));
      $self->{symbols}->{$_->{lhs}} = {terminal => 0, content => $content};
    }
}

sub _rules {
  my ($self, @rules) = @_;

  my @rc = ();
  if (defined($self->{start}->{number})) {
      push(@rc, 'inaccessible is ok by default');
      push(@rc, ':start ::= ' . $self->{start}->{rule});
      push(@rc, '');
  }
  $self->_pushG1(\@rc);
  $self->_pushLexemes(\@rc, 'lexemes');
  $self->_pushLexemes(\@rc, 'lexemesWithExclusion');

  $self->{grammar} = join("\n", @rc) . "\n";

  return $self;
}

sub _rule {
  my ($self, $rulenumber, $symbol, $rulesep, $expressions, $lhscontraints, $quantifier) = @_;

  foreach (@{$expressions}) {
    push(@{$self->{rules}}, {lhs => $symbol, rhs => $_, quantifier => $quantifier || ''});
  }

  if (defined($rulenumber)) {
      #
      # Generated rules have number undefined
      #
      $rulenumber =~ /\d+/;
      my $number = $&;
      if (! defined($self->{start}->{number}) ||
	  $number < $self->{start}->{number}) {
	  $self->{start} = {number => $number, rule => $symbol};
      }
  }

  return $self;
}

sub _concatenation {
  my ($self, $exceptions, $RHSconstraints) = @_;

  foreach (@{$RHSconstraints}) {
    $self->{constraints}->{$_} //= undef;
  }

  return $exceptions;
}

sub _constraint {
  my ($self, $type, $name, $end) = @_;
  $name =~ s/[^\w]/_/g;
  $type =~ /\w+/;
  return "$&_$name";
}

sub _char {
  my ($self, $char) = @_;
  #
  # A char is either and _HEX or a _CHAR_RANGE
  #
  my $rc = undef;
  if ($char =~ /^\#x(.*)/) {
    $rc = chr(hex($1));
  } else {
    $rc = $char;
  }
}

sub _chprint {
  my ($chr) = @_;
  if ($chr =~ /[\s]/ || (! ($chr =~ /[[:ascii:]]/) || ($chr =~ /[[:cntrl:]]/))) {
    $chr = sprintf('\\x{%x}', ord($chr));
  }
  return $chr;
}

sub _factorCaretRange {
  my ($self, $lbracket, $caret, $ranges, $rbracket) = @_;
  my ($printRanges, $exactRangesp) = @{$ranges};
  return $self->_factor("[^$printRanges]", $LEXEME_CARET_RANGES, $exactRangesp);
}

sub _factorRange {
  my ($self, $lbracket, $ranges, $rbracket) = @_;
  my ($printRanges, $exactRangesp) = @{$ranges};
  return $self->_factor("[$printRanges]", $LEXEME_RANGES, $exactRangesp);
}

sub _ranges {
  my ($self, @ranges) = @_;
  my $printRanges = '';
  my @exactRanges = ();
  foreach (@ranges) {
    my ($range, $exactRange) = @{$_};
    $printRanges .= $range;
    push(@exactRanges, $exactRange);
  }
  return [$printRanges, [ @exactRanges ]];
}

sub _printable {
  my ($self, $chr) = @_;
  if ($chr =~ /[\s]/ || (! ($chr =~ /[[:ascii:]]/) || ($chr =~ /[[:cntrl:]]/))) {
    $chr = sprintf('\\x{%x}', ord($chr));
  }
  return $chr;
}

sub _range {
  my ($self, $char1, $char2) = @_;
  my $range;
  if (substr($char1, 0, 1) eq '\\') { substr($char1, 0, 1, ''); }
  if (defined($char2) && substr($char2, 0, 1) eq '\\') { substr($char2, 0, 1, ''); }
  my $exactRange = [$char1, defined($char2) ? $char2 : $char1];
  $char1 = $self->_printable($char1);
  if (defined($char2)) {
    $char2 = $self->_printable($char2);
    $range = "$char1-$char2";
  } else {
    $range = $char1;
  }
  return [$range, $exactRange];
}

sub _range1 {
  my ($self, $char) = @_;
  return $self->_range($self->_char($char));
}

sub _range2 {
  my ($self, $char1, $minus, $char2) = @_;
  return $self->_range($self->_char($char1), $self->_char($char2));
}

sub _factorExpressions {
  my ($self, $lparen, $expressions, $rparen) = @_;

  my $symbol = sprintf('_Gen%03d', 1 + (scalar @{$self->{rules}}));
  $self->_rule(undef, $symbol, undef, $expressions, []);
  return $symbol;
}

sub _factor {
  my ($self, $value, $type, $exact) = @_;

  my @name = grep {$self->{lexemes}->{$_} eq $value} keys %{$self->{lexemes}};
  my $name;
  if (! @name) {
    $name = sprintf('_Lex%03d', 1 + (keys %{$self->{lexemes}}));
    $self->{lexemes}->{$name} = $value;
  } else {
    $name = $name[0];
  }

  $self->{lexemesExact}->{$name} = {type => $type, value => $exact};

  return $name;
}

sub _factorString {
  my ($self, $esc, $string) = @_;

  my @real = ();
  my @ch = split('', $string);
  while (@ch) {
    my $ch = shift(@ch);
    if ($ch eq '\\' && @ch && $ch[0] eq $esc) {
      push(@real, shift(@ch));
    } else {
      push(@real, $ch);
    }
  }
  my @range1 = map {$self->_factor($self->_printable($self->_char(sprintf("#x%x", ord($_)))), $LEXEME_HEXMANY, [ $_ ])} @real;

  my $symbol = sprintf('_Gen%03d', 1 + (scalar @{$self->{rules}}));
  $self->_rule(undef, $symbol, undef, [ [ @range1 ] ], []);

  return $symbol;
}

sub _factorStringDquote {
  my ($self, $dquote1, $stringDquote, $dquote2) = @_;
  #
  # _STRING_DQUOTE_UNIT    ~ [^"] | '\"'
  #
  # return $self->_factorString('"', $stringDquote);
  return $self->_factor($stringDquote, $LEXEME_STRING, $stringDquote);
}

sub _factorStringSquote {
  my ($self, $squote1, $stringSquote, $squote2) = @_;
  #
  # _STRING_SQUOTE_UNIT    ~ [^'] | '\' [']
  #
  # return $self->_factorString('\'', $stringSquote);
  return $self->_factor($stringSquote, $LEXEME_STRING, $stringSquote);
}

sub _hexMany {
  my ($self, @hex) = @_;
  return $self->_factor(join('', map {$self->_printable($self->_char($_))} @hex), $LEXEME_HEXMANY, [ map {s/^#x//; chr(hex($_));} @hex ]);
}

sub _termFactorQuantifier {
  my ($self, $factor, $quantifier) = @_;

  my $symbol;
  if ($quantifier eq '*') {
    $symbol = sprintf('%s_any', $factor);
    if (! exists($self->{quantifier}->{$symbol})) {
      $self->_rule(undef, $symbol, undef, [ [ $factor ] ], [], $quantifier);
      $self->{quantifier}->{$symbol}++;
    }
  } elsif ($quantifier eq '+') {
    $symbol = sprintf('%s_many', $factor);
    if (! exists($self->{quantifier}->{$symbol})) {
      $self->_rule(undef, $symbol, undef, [ [ $factor ] ], [], $quantifier);
      $self->{quantifier}->{$symbol}++;
    }
  } elsif ($quantifier eq '?') {
    $symbol = sprintf('%s_maybe', $factor);
    if (! exists($self->{quantifier}->{$symbol})) {
      $self->_rule(undef, $symbol, undef, [ [ "$factor" ] ], []);
      $self->_rule(undef, $symbol, undef, [ [] ], []);
      $self->{quantifier}->{$symbol}++;
    }
  } else {
    die "Unsupported quantifier '$quantifier'";
  }
  return $symbol;
}

sub _exceptionTermMinusTerm {
    my ($self, $term1, $minus, $term2) = @_;

    my $value = "$term1 $minus $term2";

    my @name = grep {$self->{lexemesWithExclusion}->{$_} eq $value} keys %{$self->{lexemesWithExclusion}};
    my $name;
    if (! @name) {
	$name = sprintf('_Exclusion%03d', 1 + (keys %{$self->{lexemesWithExclusion}}));
	$self->{lexemesWithExclusion}->{$name} = $value;
	print STDERR "[WARN] Lexeme with exclusion: $name ::= $value\n";
    } else {
	$name = $name[0];
    }
    my $symbol = sprintf('_Gen%03d', 1 + (scalar @{$self->{rules}}));
    $self->_rule(undef, $symbol, undef, [ [ $name ] ], []);
    return $symbol;
}

###########################################################################
# package main                                                            #
###########################################################################

package main;
use Marpa::R2;
use Getopt::Long;
use File::Slurp;
use File::Basename qw/basename/;
use POSIX qw/EXIT_SUCCESS EXIT_FAILURE/;

our $DATA = do {local $/; <DATA>};

my $bnf = '';
GetOptions('bnf=s' => \$bnf)
  or die("Error in command line arguments\n");

if (! $bnf) {
  print STDERR "Usage: $^X $0 --bnf filename.bnf\n";
  exit(EXIT_FAILURE);
}

my $grammar = Marpa::R2::Scanless::G->new( { source => \$DATA, action_object => 'Actions' });
my $recce = Marpa::R2::Scanless::R->new( {grammar => $grammar
                                          # , trace_terminals => 1
                                         });

open(BNF, '<', $bnf) || die "Cannot open $bnf, $!";
my $BNF = do {local $/; <BNF>};
close(BNF) || warn "Cannot close $bnf, $!";

#
# The C namespace will be the fist part of the basename of the grammar
#
my $namespace;
{
  my $bname = basename($bnf);
  $bname =~ /^(\w+)/;
  $namespace = $1;
}

eval {$recce->read(\$BNF)} || do {print STDERR "$@\n" . $recce->show_progress(); exit(1)};
my $nbvalue = 0;
my $value = undef;
while (defined($_ = $recce->value)) {
  ++$nbvalue;
  last if ($nbvalue >= 2);
  $value = ${$_};
}
if ($nbvalue != 1) {
  print STDERR "Oups, \$nbvalue != 1\n";
  exit(EXIT_FAILURE);
} else {
  #
  # This call is just to make sure that this is a valid Marpa grammar
  #
  Marpa::R2::Scanless::G->new( { source => \$value->{grammar} } );
  #
  # Generate a typedef containing all symbols, lexemes first, then the rules
  #
  my $c = generateC($value, $namespace);
  print $c;
  print STDERR "Symbols: " . join(' ', sort keys %{$value->{symbols}} ) . "\n";
}

exit(EXIT_SUCCESS);

sub generateC {
  my $c = '';

  $c .= <<INCLUDES;
#include <stdlib.h>
#include <errno.h>
#include "unicode/ustring.h"
#include "unicode/utext.h"
#include "internal/grammar/$namespace.h"

INCLUDES

  $c .= generateTypedef(@_);

  $c .= <<DECLARATIONS;
static C_INLINE marpaWrapperBool_t _${namespace}_buildGrammarb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp);
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbolsb(${namespace}_t *${namespace}p);
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbols_withStartb(${namespace}_t *${namespace}p, int starti);
static C_INLINE marpaWrapperBool_t _${namespace}_buildRulesb(${namespace}_t *${namespace}p);
static C_INLINE marpaWrapperBool_t _${namespace}_pushLexemeb(${namespace}_t *${namespace}p, ${namespace}_symbol_t ${namespace}_symbol, UText *utextp);
DECLARATIONS
  foreach (sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}}) {
    $c .= "static C_INLINE ${namespace}_lexemeState_t _${namespace}_${_}b(${namespace}_t *${namespace}p, UChar32 c, UText *utextp);\n";
  }

  $c .= generateNewp(@_);
  $c .= generateDestroyv(@_);
  $c .= generateBuildGrammarb(@_);
  $c .= generateBuildSymbolsb(@_);
  $c .= generateBuildRulesb(@_);
  $c .= generatePushLexemeb(@_);

  return $c;
}

sub generateTypedef {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);

  my $typedef = '';

  $typedef .= "/* Symbols */\n";
  $typedef .= "typedef enum ${namespace}_symbol {\n";
  my $i = 0;
  my $terminal_max = '';
  my @terminals = map {
    $terminal_max = "${namespace}_${_}";
    my $content = $value->{symbols}->{$_}->{content};
    my $fullname = "${namespace}_${_}";
    if ($i++ == 0) {
      sprintf('  %-30s, /* %s */', "$fullname = 0", $content);
    } else {
      sprintf('  %-30s, /* %s */', $fullname, $content);
    }} sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}};
  my @g1 = map {
    sprintf('  %-30s,', "${namespace}_${_}");
  } sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} != 1} keys %{$value->{symbols}};

  $typedef .= "  /* Terminals */\n";
  $typedef .= join("\n", @terminals) . "\n";
  $typedef .= "  /* Non-terminals */\n";
  $typedef .= join("\n", @g1) . "\n";
  $typedef .= "  ${NAMESPACE}_SYMBOL_MAX\n";
  $typedef .= "} ${namespace}_symbol_t;\n";
  $typedef .= "\n";
  $typedef .= "#define ${NAMESPACE}_TERMINAL_MAX $terminal_max\n";
  $typedef .= "\n";
  $typedef .= "/* Rules */\n";
  $typedef .= "typedef enum ${namespace}_rule {\n";
  my $prevlhs = '';
  my $ilhs;
  $i = 0;
  my @rules = map {
    my $content = join(' ', $_->{lhs}, '::=', "@{$_->{rhs}}", $_->{quantifier});
    my $enumed;
    if (! $prevlhs || $prevlhs ne $_->{lhs}) {
      $ilhs = 1;
      $prevlhs = $_->{lhs};
    } else {
      ++$ilhs;
    }
    $enumed = sprintf('%s_%03d', "${namespace}_" . ${_}->{lhs}, $ilhs);
    if ($i++ == 0) {
      sprintf('  %-30s, /* %s */', "$enumed = 0", $content);
    } else {
      sprintf('  %-30s, /* %s */', $enumed, $content);
    }} @{$value->{rules}};
  $typedef .= join("\n", @rules) . "\n";
  $typedef .= "  ${NAMESPACE}_RULE_MAX\n";
  $typedef .= "} ${namespace}_rule_t;\n";
  $typedef .= "\n";
  $typedef .=<<STRUCTURE;

/* Work structure */
struct $namespace {
  marpaWrapper_t        *marpaWrapperp;
  marpaWrapperSymbol_t **marpaWrapperSymbolArrayp;
  size_t                 marpaWrapperSymbolArrayLengthi;
  marpaWrapperRule_t   **marpaWrapperRuleArrayp;
  size_t                 marpaWrapperRuleArrayLengthi;
};

/* Lexeme state */
typedef enum ${namespace}_lexemeState {
  ${NAMESPACE}_LEXEMESTATE_SENTINEL = -1,
  ${NAMESPACE}_LEXEMESTATE_KO = 0,
  ${NAMESPACE}_LEXEMESTATE_OK = 1
} ${namespace}_lexemeState_t;

STRUCTURE

  return $typedef;
}

sub generateNewp {
  my ($value, $namespace) = @_;

  my $newp = <<NEWP;

/*******************/
/* ${namespace}_newp  */
/*******************/
${namespace}_t *${namespace}_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_commonOption_t *xml_commonOptionp) {
  ${namespace}_t           *${namespace}p;
  marpaWrapperOption_t marpaWrapperOption;

  /* Fill the defaults */
  if (marpaWrapperOptionp == NULL) {
    marpaWrapper_optionDefaultb(&marpaWrapperOption);
  } else {
    marpaWrapperOption = *marpaWrapperOptionp;
  }

  ${namespace}p = malloc(sizeof(${namespace}_t));
  if (${namespace}p == NULL) {
    marpaWrapper_log(marpaWrapperOption.logCallbackp,
		     marpaWrapperOption.logCallbackDatavp,
		     NULL,
		     marpaWrapperOption.logLevelWantedi,
		     MARPAWRAPPERERRORORIGIN_SYSTEM,
		     errno,
		     "malloc()",
		     MARPAWRAPPER_LOGLEVEL_ERROR);
    return NULL;
  }

  ${namespace}p->marpaWrapperp = NULL;
  ${namespace}p->marpaWrapperSymbolArrayp = NULL;
  ${namespace}p->marpaWrapperSymbolArrayLengthi = 0;
  ${namespace}p->marpaWrapperRuleArrayp = NULL;
  ${namespace}p->marpaWrapperRuleArrayLengthi = 0;

  if (_${namespace}_buildGrammarb(${namespace}p, &marpaWrapperOption) == MARPAWRAPPER_BOOL_FALSE) {
    ${namespace}_destroyv(&${namespace}p);
  }

  return ${namespace}p;
}
NEWP

  return $newp;
}

sub generateDestroyv {
  my ($value, $namespace) = @_;

  my $destroyv = <<DESTROYV;

/*********************/
/* ${namespace}_destroyv  */
/*********************/
void ${namespace}_destroyv(${namespace}_t **${namespace}pp) {
  ${namespace}_t *${namespace}p;

  if (${namespace}pp != NULL) {
    ${namespace}p = *${namespace}pp;

    if (${namespace}p != NULL) {
      if (${namespace}p->marpaWrapperp != NULL) {
	marpaWrapper_destroyv(&(${namespace}p->marpaWrapperp));
      }
      if (${namespace}p->marpaWrapperSymbolArrayp != NULL) {
	free(${namespace}p->marpaWrapperSymbolArrayp);
      }
      if (${namespace}p->marpaWrapperRuleArrayp != NULL) {
	free(${namespace}p->marpaWrapperRuleArrayp);
      }
      free(${namespace}p);
    }

    *${namespace}pp = NULL;
  }
}
DESTROYV
  return $destroyv;
}

sub generateBuildGrammarb {
  my ($value, $namespace) = @_;

  my $buildGrammarb = <<BUILDGRAMMARB;

/**************************/
/* _${namespace}_buildGrammarb */
/**************************/
static C_INLINE marpaWrapperBool_t _${namespace}_buildGrammarb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp) {

  ${namespace}p->marpaWrapperp = marpaWrapper_newp(marpaWrapperOptionp);
  if (${namespace}p->marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_${namespace}_buildSymbolsb(${namespace}p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_${namespace}_buildRulesb(${namespace}p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapper_g_precomputeb(${namespace}p->marpaWrapperp) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}
BUILDGRAMMARB
  return $buildGrammarb;
}

sub generateBuildSymbolsb {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);

  my $buildSymbolsb = <<BUILDSYMBOLSB;

/**************************/
/* _${namespace}_buildSymbolsb */
/**************************/
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbolsb(${namespace}_t *${namespace}p) {
  return _${namespace}_buildSymbols_withStartb(${namespace}p, ${namespace}_$value->{start}->{rule});
}

/**************************/
/* _${namespace}_buildSymbols_withStartb */
/**************************/
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbols_withStartb(${namespace}_t *${namespace}p, int starti) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  ${namespace}p->marpaWrapperSymbolArrayp = malloc(${NAMESPACE}_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (${namespace}p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  ${namespace}p->marpaWrapperSymbolArrayLengthi = ${NAMESPACE}_SYMBOL_MAX;

  for (i = 0; i < ${NAMESPACE}_SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data associated to symbol will be the symbol enum */
    marpaWrapperSymbolOption.datavp = (void *) i;

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= ${NAMESPACE}_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    marpaWrapperSymbolOption.startb = (i == starti) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Create the symbol */
    ${namespace}p->marpaWrapperSymbolArrayp[i] = marpaWrapper_g_addSymbolp(${namespace}p->marpaWrapperp, &marpaWrapperSymbolOption);
    if (${namespace}p->marpaWrapperSymbolArrayp[i] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

  }

  return MARPAWRAPPER_BOOL_TRUE;
}
BUILDSYMBOLSB

  return $buildSymbolsb;
}

sub generatePushLexemeb {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);
  my $SENTINEL  = "${NAMESPACE}_LEXEMESTATE_SENTINEL";
  my $KO        = "${NAMESPACE}_LEXEMESTATE_KO";
  my $OK        = "${NAMESPACE}_LEXEMESTATE_OK";

  my $pushLexemeb = <<ISLEXEMEB_HEADER;

/************************/
/* _${namespace}_pushLexemeb */
/************************/

/***************************************************************************************/
/* exeme Lroutines are called perl character they all maintain their own state:        */
/*                                                                                     */
/* SENTINEL   value -1  : need more data                                               */
/* FALSE      value  0  : KO                                                           */
/* COMPLETE   value  1  : OK                                                           */
/*                                                                                     */
/***************************************************************************************/

static C_INLINE marpaWrapperBool_t _${namespace}_pushLexemeb(${namespace}_t *${namespace}p, ${namespace}_symbol_t ${namespace}_symbol, UText *utextp) {
  marpaWrapperBool_t rcb;
  ${namespace}_lexemeState_t lexemeb;
  UChar32 c = UTEXT_CURRENT32(utextp);

  switch (${namespace}_symbol) {
ISLEXEMEB_HEADER
  foreach (sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}}) {
      $pushLexemeb .= <<ISLEXEMEB;
    case ${namespace}_${_}:
      lexemeb = _${namespace}_${_}b(${namespace}p, c, utextp);
      break;
ISLEXEMEB
    }
  $pushLexemeb .= <<ISLEXEMEB_TRAILER;
    default:
      lexemeb = $KO;
      break;
  }

  /* Special processing if lexemeb is sentinel */
  if (lexemeb == $SENTINEL) {
    /* Try to get another buffer */
    rcb = $KO;
  }

  return rcb;
}
ISLEXEMEB_TRAILER

  foreach (sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}}) {
    $pushLexemeb .= <<COMMENT;
/************************************************
  $value->{symbols}->{$_}->{content}
 ************************************************/
COMMENT
    if (! exists($value->{lexemesExact}->{$_}->{type})) {
      $pushLexemeb .= <<ISLEXEMEB;
static C_INLINE ${namespace}_lexemeState_t _${namespace}_${_}b(${namespace}_t *${namespace}p, UChar32 c, UText *utextp) {
  /* Writen by hand */
  return $OK;
}

ISLEXEMEB
    } else {
      if ($value->{lexemesExact}->{$_}->{type} == $LEXEME_RANGES ||
	  $value->{lexemesExact}->{$_}->{type} == $LEXEME_CARET_RANGES) {
	  my $rcIfMatch = ($value->{lexemesExact}->{$_}->{type} == $LEXEME_RANGES) ? $OK : $KO;
	  my $rcIfNoMatch = ($value->{lexemesExact}->{$_}->{type} == $LEXEME_RANGES) ? $KO : $OK;
        my @wanted = ();
        my $n = scalar(@{$value->{lexemesExact}->{$_}->{value}});
        foreach (@{$value->{lexemesExact}->{$_}->{value}}) {
          my @range = @{$_};
	  if ($range[0] ne $range[1]) {
	      push(@wanted, sprintf('%sc >= 0x%x && c <= 0x%x%s /* [%s-%s] */', ($n > 1 ? '(' : ''), ord($range[0]), ord($range[1]), ($n > 1 ? ')' : ''), _chprint($range[0]), _chprint($range[1])));
	  } else {
	      push(@wanted, sprintf('%sc == 0x%x%s /* %s */', ($n > 1 ? '(' : ''), ord($range[0]), ($n > 1 ? ')' : ''), _chprint($range[0])));
	  }
        }
	my $wanted = join(" ||\n          ", @wanted);
	$pushLexemeb .= <<ISLEXEMEB;
static C_INLINE ${namespace}_lexemeState_t _${namespace}_${_}b(${namespace}_t *${namespace}p, UChar32 c, UText *utextp) {
  return ($wanted) ? $rcIfMatch : $rcIfNoMatch;
}
ISLEXEMEB
      } elsif ($value->{lexemesExact}->{$_}->{type} == $LEXEME_HEXMANY) {
	  my @wanted = ();
          my $n = scalar(@{$value->{lexemesExact}->{$_}->{value}});
	  foreach (@{$value->{lexemesExact}->{$_}->{value}}) {
              if ($n > 1) {
  	        push(@wanted, sprintf('(c == 0x%x) /* %s */', ord($_), _chprint($_)));
              } else {
  	        push(@wanted, sprintf('0x%x /* %s */', ord($_), _chprint($_)));
              }
	  }
	  my $wanted = join(" ||\n          ", @wanted);
          if ($n == 1) {
          $pushLexemeb .= <<ISLEXEMEB;
static C_INLINE ${namespace}_lexemeState_t _${namespace}_${_}b(${namespace}_t *${namespace}p, UChar32 c, UText *utextp) {
  return (c == $wanted) ? $OK : $KO;
}
ISLEXEMEB
          } else {
	$pushLexemeb .= <<ISLEXEMEB;
static C_INLINE ${namespace}_lexemeState_t _${namespace}_${_}b(${namespace}_t *${namespace}p, UChar32 c, UText *utextp) {
  return ($wanted) ? $OK : $KO;
}
ISLEXEMEB
        }
      } elsif ($value->{lexemesExact}->{$_}->{type} == $LEXEME_STRING) {
        my @wanted = map {sprintf("0x%x /* %s */", ord($_), _chprint($_))} split('', $value->{lexemesExact}->{$_}->{value});
        my $wanted = join(",\n    ", @wanted);
	my $length = length($value->{lexemesExact}->{$_}->{value});
        #
        # Well, if length is 1 no need to play with the native index
        #
        if ($length == 1) {
          $pushLexemeb .= <<ISLEXEMEB;
static C_INLINE ${namespace}_lexemeState_t _${namespace}_${_}b(${namespace}_t *${namespace}p, UChar32 c, UText *utextp) {
  return (c == $wanted) ? $OK : $KO;
}
ISLEXEMEB
        } else {
          $pushLexemeb .= <<ISLEXEMEB;
static C_INLINE ${namespace}_lexemeState_t _${namespace}_${_}b(${namespace}_t *${namespace}p, UChar32 c, UText *utextp) {
  static const UChar32 wanted[$length] = {
    $wanted
  };
  UChar32              got = c;
  int64_t              foundIndex = UTEXT_GETNATIVEINDEX(utextp);
  int                  i = 0;
  ${namespace}_lexemeState_t  rcb = $OK;

  do {
    if (got != wanted[i]) {
      rcb = (got == U_SENTINEL) ? $SENTINEL : $KO;
      break;
    }
    got = UTEXT_NEXT32(utextp);
  } while (++i < $length);

  UTEXT_SETNATIVEINDEX(utextp, foundIndex);

  return rcb;
}
ISLEXEMEB
        }
      }
    }
  }
  return $pushLexemeb;
}

sub _chprint {
  my ($chr) = @_;
  if ($chr =~ /[\s]/ || (! ($chr =~ /[[:ascii:]]/) || ($chr =~ /[[:cntrl:]]/))) {
    $chr = sprintf('#x%x', ord($chr));
  }
  return $chr;
}

sub generateBuildRulesb {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);
  my $prevlhs = '';
  my $ilhs;
  my $buildRulesb = <<BUILDRULESB_HEADER;

/************************/
/* _${namespace}_buildRulesb */
/************************/
static C_INLINE marpaWrapperBool_t _${namespace}_buildRulesb(${namespace}_t *${namespace}p) {
  marpaWrapperRuleOption_t   marpaWrapperRuleOption;

  ${namespace}p->marpaWrapperRuleArrayp = malloc(${NAMESPACE}_RULE_MAX * sizeof(marpaWrapperRule_t *));
  if (${namespace}p->marpaWrapperRuleArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  ${namespace}p->marpaWrapperRuleArrayLengthi = ${NAMESPACE}_RULE_MAX;

BUILDRULESB_HEADER
  foreach (@{$value->{rules}}) {

    my $enumed;
    if (! $prevlhs || $prevlhs ne $_->{lhs}) {
      $ilhs = 1;
      $prevlhs = $_->{lhs};
    } else {
      ++$ilhs;
    }
    $enumed = sprintf('%s_%03d', "${namespace}_" . $_->{lhs}, $ilhs);

    my $rule = $_;
    $buildRulesb .= "  {\n";
    $buildRulesb .= "    /* [$enumed] $rule->{lhs} ::= @{$rule->{rhs}} $rule->{quantifier} */\n";
    my $nbRhs = scalar(@{$rule->{rhs}});
    if ($nbRhs > 0) {
      $buildRulesb .= "    marpaWrapperSymbol_t *rhsSymbolpp[$nbRhs] = {\n";
      foreach (0..$#{$rule->{rhs}}) {
        $buildRulesb .= "      ${namespace}p->marpaWrapperSymbolArrayp[${namespace}_${$rule->{rhs}}[$_]]";
        $buildRulesb .= "," if ($_ < $#{$rule->{rhs}});
        $buildRulesb .= "\n";
      }
      $buildRulesb .= "    };\n";
    }
    $buildRulesb .= <<BUILDRULESB_INNER1;
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) $enumed;
    marpaWrapperRuleOption.lhsSymbolp = ${namespace}p->marpaWrapperSymbolArrayp[${namespace}_$rule->{lhs}];
BUILDRULESB_INNER1
    if ($nbRhs > 0) {
      $buildRulesb .= <<BUILDRULESB_INNER2;
    marpaWrapperRuleOption.nRhsSymboli = $nbRhs;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
BUILDRULESB_INNER2
    }
    if ($value->{quantifier} eq '*') {
      $buildRulesb .= <<QUANTIFIER_STAR;
      marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
      marpaWrapperRuleOption.minimumi = 0;
QUANTIFIER_STAR
    } elsif ($value->{quantifier} eq '+') {
      $buildRulesb .= <<QUANTIFIER_PLUS;
      marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
      marpaWrapperRuleOption.minimumi = 1;
QUANTIFIER_PLUS
    }
    $buildRulesb .= <<BUILDRULESB_GO;
    /* Create the rule */
    ${namespace}p->marpaWrapperRuleArrayp[$enumed] = marpaWrapper_g_addRulep(${namespace}p->marpaWrapperp, &marpaWrapperRuleOption);
    if (${namespace}p->marpaWrapperRuleArrayp[$enumed] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
BUILDRULESB_GO
    $buildRulesb .= "  }\n";
  }

  $buildRulesb .= <<BUILDRULESB_TRAILER;
    return MARPAWRAPPER_BOOL_TRUE;
}
BUILDRULESB_TRAILER

  return $buildRulesb;
}

__DATA__
:start ::= rules
:default ::= action => ::first
lexeme default = latm => 1
#
# Inspired by ebnf-ebx.el from Emacs's ebnf2ps package
#
# The XML Spec seems to apply [WFC:] and [VC:] constraints to all rule that are on the
# same line.
# This would have complicated too much the grammar given that almost all contraints
# apply on all RHSs of a given LHS.
# The exceptions are marked with [RWFC:] and [RCV:], i.e. when the contraint is on a
# specific RHS member.
rules          ::= rule+                                                action => _rules
rule           ::= RULENUMBER SYMBOL RULESEP expressions LHSconstraints action => _rule
expressions    ::= concatenation+ separator => PIPE                     action => [values]
concatenation  ::= exceptions RHSconstraints                            action => _concatenation
exceptions     ::= exception+                                           action => [values]
exception      ::= term
               |   term MINUS term                                      action => _exceptionTermMinusTerm
term           ::= factor
               |   factor QUANTIFIER                                    action => _termFactorQuantifier
hexMany        ::= HEX+                                                 action => _hexMany
factor         ::= hexMany
               |   LBRACKET       ranges RBRACKET                       action => _factorRange
               |   LBRACKET CARET ranges RBRACKET                       action => _factorCaretRange
               |   DQUOTE STRINGDQUOTE DQUOTE                           action => _factorStringDquote
               |   SQUOTE STRINGSQUOTE SQUOTE                           action => _factorStringSquote
               |   LPAREN expressions RPAREN                            action => _factorExpressions
               |   SYMBOL
ranges         ::= range+                                               action => _ranges
range          ::= CHAR                                                 action => _range1
               |   CHAR MINUS CHAR                                      action => _range2
LHSconstraint  ::= LHSWfcConstraint
               |   LHSVcConstraint
LHSconstraints ::= LHSconstraint*                                       action => [values]
LHSWfcConstraint ::= LHSWFCSTART CONSTRAINTBODY RBRACKET                action => _constraint
LHSVcConstraint  ::= LHSVCSTART CONSTRAINTBODY RBRACKET                 action => _constraint
RHSconstraint  ::= RHSWfcConstraint
               |   RHSVcConstraint
RHSconstraints ::= RHSconstraint*                                       action => [values]
RHSWfcConstraint ::= RHSWFCSTART CONSTRAINTBODY RBRACKET                action => _constraint
RHSVcConstraint  ::= RHSVCSTART CONSTRAINTBODY RBRACKET                 action => _constraint

RULESEP       ~ '::='
PIPE          ~ '|'
MINUS         ~ '-'
QUANTIFIER    ~ '*' | '+' | '?'
HEX           ~ _HEX
CHAR          ~ _CHAR
LBRACKET      ~ '['
RBRACKET      ~ ']'
LPAREN        ~ '('
RPAREN        ~ ')'
CARET         ~ '^'
DQUOTE        ~ '"'
SQUOTE        ~ [']
STRINGDQUOTE  ~ _STRING_DQUOTE_UNIT*
STRINGSQUOTE  ~ _STRING_SQUOTE_UNIT*
SYMBOL        ~ _SYMBOL_START _SYMBOL_END
LHSWFCSTART   ~ '[wfc:':i
LHSVCSTART    ~ '[vc:':i
RHSWFCSTART   ~ '[rhs_wfc:':i
RHSVCSTART    ~ '[rhs_vc:':i
RULENUMBER    ~ '[' _RULE_NUMBER_START _RULE_NUMBER_END ']'

_STRING_DQUOTE_UNIT    ~ [^"] | '\"'
_STRING_SQUOTE_UNIT    ~ [^'] | '\' [']
_HEX                   ~ __HEX_START __HEX_END
_CHAR_RANGE            ~ [^\r\n\t\v\f\]\[\-\^]
                       | '\['
                       | '\]'
                       | '\-'
                       | '\^'
_CHAR                  ~ _HEX | _CHAR_RANGE
CONSTRAINTBODY         ~ [^\]]*
_SYMBOL_START          ~ [a-zA-Z]
_SYMBOL_END            ~ [-_a-zA-Z]*
_RULE_NUMBER_START     ~ [\d]+
_RULE_NUMBER_END       ~ [a-zA-Z]*

__HEX_START          ~ '#x'
__HEX_END            ~ [0-9A-Fa-f]+

############################################################################
# Discard of a C comment, c.f. https://gist.github.com/jeffreykegler/5015057
############################################################################
<C style comment> ~ '/*' <comment interior> '*/'
<comment interior> ~
    <optional non stars>
    <optional star prefixed segments>
    <optional pre final stars>
<optional non stars> ~ [^*]*
<optional star prefixed segments> ~ <star prefixed segment>*
<star prefixed segment> ~ <stars> [^/*] <optional star free text>
<stars> ~ [*]+
<optional star free text> ~ [^*]*
<optional pre final stars> ~ [*]*
:discard ~ <C style comment>

#################
# Generic discard
#################
__SPACE_ANY ~ [\s]+
:discard ~ __SPACE_ANY
