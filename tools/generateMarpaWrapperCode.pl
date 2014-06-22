#!env perl
#
# This program creates a Marpa BNF of a W3C BNF.
#
# The negation form "term - term" is forced to be a lexeme.
#
use strict;
use diagnostics;
use warnings FATAL => 'all';
use Data::Section -setup;

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
      push(@{$rcp}, $content = join(' ', $_->{lhs}, $_->{rulesep}, "@{$_->{rhs}}", $_->{quantifier}));
      $self->{symbols}->{$_->{lhs}} = {terminal => 0, content => $content};
    }
}

sub _rules {
  my ($self, @rules) = @_;

  my @rc = ();
  if (defined($self->{start}->{number})) {
      push(@rc, 'inaccessible is warn by default');
      push(@rc, ':start ::= ' . $self->{start}->{rule});
      push(@rc, 'lexeme default = latm => 1');
      push(@rc, '');
  }
  $self->_pushG1(\@rc);
  $self->_pushLexemes(\@rc, 'lexemes');
  $self->_pushLexemes(\@rc, 'lexemesWithExclusion');

  #
  # Rework the grammar:
  #
  # IF the context is lexeme, we change on the fly all the definitions of RHS to be lexeme as well
  # and say this is a terminal
  #
  if (0) {
      foreach (@{$self->{rules}}) {
	  my $rule = $_;
	  if ($rule->{rulesep} eq '~') {
	      foreach (@{$rule->{rhs}}) {
		  print STDERR "$rule->{lhs} : Making sure context is ~\n";
		  $self->{symbols}->{$rule->{lhs}}->{terminal} = 1;
		  foreach (@{$rule->{rhs}}) {
		      my $rhs = $_;
		      my @rhsToChange = ($rhs);
		      #
		      # If this is a quantified rule do it also for the raw version
		      #
		      if ($rhs =~ /(\w+)_m?any/) {
			  push(@rhsToChange, $1);
		      }
		      foreach (@rhsToChange) {
			  my $rhs = $_;
			  print STDERR "$rule->{lhs} : Making sure rhs $rhs context is ~\n";
			  $self->{symbols}->{$rhs}->{terminal} = 1;
			  foreach (0..$#rc) {
			      $rc[$_] =~ s/^(\s*$rhs\s*)::=(.*)/$1~$2/;
			  }
		      }
		  }
	      }
	  }
      }
  }

  $self->{grammar} = join("\n", @rc) . "\n";

  return $self;
}

sub _rule {
  my ($self, $rulenumber, $symbol, $rulesep, $expressions, $lhscontraints, $quantifier) = @_;

  #
  # Ignore rulesep "~"
  #
  $rulesep = '::=';

  foreach (@{$expressions}) {
    push(@{$self->{rules}}, {lhs => $symbol, rhs => $_, rulesep => $rulesep, quantifier => $quantifier || ''});
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
  $self->_rule(undef, $symbol, '::=', $expressions, []);
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
  $self->_rule(undef, $symbol, '::=', [ [ @range1 ] ], []);

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
      $self->_rule(undef, $symbol, '::=', [ [ $factor ] ], [], $quantifier);
      $self->{quantifier}->{$symbol}++;
    }
  } elsif ($quantifier eq '+') {
    $symbol = sprintf('%s_many', $factor);
    if (! exists($self->{quantifier}->{$symbol})) {
      $self->_rule(undef, $symbol, '::=', [ [ $factor ] ], [], $quantifier);
      $self->{quantifier}->{$symbol}++;
    }
  } elsif ($quantifier eq '?') {
    $symbol = sprintf('%s_maybe', $factor);
    if (! exists($self->{quantifier}->{$symbol})) {
      $self->_rule(undef, $symbol, '::=', [ [ "$factor" ] ], []);
      $self->_rule(undef, $symbol, '::=', [ [] ], []);
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
	# $self->{lexemesWithExclusion}->{$name} = $term1;
	print STDERR "[WARN] Lexeme with exclusion: $name ::= $value\n";
    } else {
	$name = $name[0];
    }
    my $symbol = sprintf('_Gen%03d', 1 + (scalar @{$self->{rules}}));
    $self->_rule(undef, $symbol, '~', [ [ $name ] ], []);
    # $self->_rule(undef, $symbol, '~', [ [ $term1 ] ], []);
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

our $DATA = ${__PACKAGE__->section_data('bnf')};

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
    # These calls are to make sure:
    # - this is a valid Marpa grammar
    # - this is an unambiguous grammar
    #
    print STDERR "Marpa grammar:\n" . $value->{grammar} . "\n";
    my $grammar = Marpa::R2::Scanless::G->new( { source => \$value->{grammar} } );
    if (0) {
	foreach (grep {$_ ne 'bnf'} __PACKAGE__->section_data_names) {
	    my $dataSection = $_;
	    my $testDatap = __PACKAGE__->section_data($dataSection);
	    my $recce = Marpa::R2::Scanless::R->new( { grammar => $grammar, trace_terminals => 1 } );
	    if (! eval { $recce->read($testDatap) }) {
		print STDERR "Test fail with data section $dataSection:\n$@\n";
		print STDERR "Progress::\n" . $recce->show_progress() . "\n";
		print STDERR "Terminals expected:: @{$recce->terminals_expected()}\n";
		exit(EXIT_FAILURE);
	    }
	}
    }
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
/****************************/
/* This is a generated file */
/****************************/
#include <stdlib.h>
#include <errno.h>
#include "internal/streamIn.h"
#include "internal/grammar/$namespace.h"

INCLUDES

  $c .= generateTypedef(@_);

  $c .= <<DECLARATIONS;
static C_INLINE marpaWrapperBool_t _${namespace}_buildGrammarb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp);
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbolsb(${namespace}_t *${namespace}p);
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbols_withStartb(${namespace}_t *${namespace}p, int starti);
static C_INLINE marpaWrapperBool_t _${namespace}_buildRulesb(${namespace}_t *${namespace}p);
static C_INLINE marpaWrapperBool_t _${namespace}_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
DECLARATIONS
  foreach (sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}}) {
    $c .= "static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);\n";
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
  my @sortedTerminals = sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}};
  my @terminalsToString = map {
      my $content = $value->{symbols}->{$_}->{content};
      $content =~ s/\\/\\\\/g;
      $content =~ s/"/\\"/g;
      "\"$content\"";
  } @sortedTerminals;
  my @terminals = map {
    $terminal_max = "${namespace}_${_}";
    my $content = $value->{symbols}->{$_}->{content};
    my $fullname = "${namespace}_${_}";
    if ($i++ == 0) {
      sprintf('  %-30s, /* %s */', "$fullname = 0", $content);
    } else {
      sprintf('  %-30s, /* %s */', $fullname, $content);
    }} @sortedTerminals;
  my @sortedNonTerminals = sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} != 1} keys %{$value->{symbols}};
  my @nonTerminalsToString = map {
      my $content = $_;
      $content =~ s/\\/\\\\/g;
      $content =~ s/"/\\"/g;
      "\"$content\"";
  } @sortedNonTerminals;
  my @g1 = map {
    sprintf('  %-30s,', "${namespace}_${_}");
  } @sortedNonTerminals;

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
  my @rulesToString = map {
      my $content = join(' ', $_->{lhs}, $_->{rulesep}, "@{$_->{rhs}}", $_->{quantifier});
      $content =~ s/\\/\\\\/g;
      $content =~ s/"/\\"/g;
      "\"$content\"";
  } @{$value->{rules}};
  my @rules = map {
    my $content = join(' ', $_->{lhs}, $_->{rulesep}, "@{$_->{rhs}}", $_->{quantifier});
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
  my $symbolsToString =
      "  /* Terminals */\n  " .
      join(",\n  ", @terminalsToString) .
      ",\n  /* Non-terminals */\n  " .
      join(",\n  ", @nonTerminalsToString);
  my $rulesToString = join(",\n  ", @rulesToString);
  $typedef .=<<STRUCTURE;

/* Callback structure for symbols */
typedef struct ${namespace}_callback {
  ${namespace}_t *${namespace}p;
  ${namespace}_symbol_t ${namespace}_symboli;
} ${namespace}_callback_t;

/* Work structure */
struct $namespace {
  marpaWrapper_t          *marpaWrapperp;
  marpaWrapperSymbol_t   **marpaWrapperSymbolArrayp;
  size_t                   marpaWrapperSymbolArrayLengthi;
  marpaWrapperRule_t     **marpaWrapperRuleArrayp;
  size_t                   marpaWrapperRuleArrayLengthi;
  ${namespace}_callback_t *marpaWrapperSymbolCallbackArrayp;
  size_t                   marpaWrapperSymbolCallbackArrayLengthi;
};

/* Terminals to string - indexed by ${namespace}_symbol_t */
static const char *symbolsToString[] = {
  $symbolsToString
};

/* Rules to string indexed by ${namespace}_rule_t */
static const char *rulesToString[] = {
  $rulesToString
};

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
  ${namespace}p->marpaWrapperSymbolCallbackArrayp = NULL;
  ${namespace}p->marpaWrapperSymbolCallbackArrayLengthi = 0;

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
  ${namespace}p->marpaWrapperSymbolCallbackArrayp = malloc(${NAMESPACE}_SYMBOL_MAX * sizeof(${namespace}_callback_t));
  if (${namespace}p->marpaWrapperSymbolCallbackArrayp == NULL) {
    free(${namespace}p->marpaWrapperSymbolArrayp);
    return MARPAWRAPPER_BOOL_FALSE;
  }
 
  ${namespace}p->marpaWrapperSymbolArrayLengthi = ${NAMESPACE}_SYMBOL_MAX;
  ${namespace}p->marpaWrapperSymbolCallbackArrayLengthi = ${NAMESPACE}_SYMBOL_MAX;

  for (i = 0; i < ${NAMESPACE}_SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data associated to symbol will be the symbol enum */
    ${namespace}p->marpaWrapperSymbolCallbackArrayp[i].${namespace}p = ${namespace}p;
    ${namespace}p->marpaWrapperSymbolCallbackArrayp[i].${namespace}_symboli = i;
    marpaWrapperSymbolOption.datavp = (void *) &(${namespace}p->marpaWrapperSymbolCallbackArrayp[i]);

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

  my $pushLexemeb = <<ISLEXEMEB_HEADER;

/************************/
/* _${namespace}_isLexemeb */
/************************/

static C_INLINE marpaWrapperBool_t _${namespace}_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  marpaWrapperBool_t rcb;
  ${namespace}_callback_t *${namespace}_callbackp = (${namespace}_callback_t *) p;

  switch (${namespace}_callbackp->${namespace}_symboli) {
ISLEXEMEB_HEADER
  foreach (sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}}) {
      $pushLexemeb .= <<ISLEXEMEB;
    case ${namespace}_${_}:
      rcb = _${namespace}_${_}b(${namespace}_callbackp->${namespace}p, currenti, streamInp, sizelp);
      break;
ISLEXEMEB
    }
  $pushLexemeb .= <<ISLEXEMEB_TRAILER;
    default:
      rcb = MARPAWRAPPER_BOOL_FALSE;
      break;
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
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

ISLEXEMEB
    } else {
      if ($value->{lexemesExact}->{$_}->{type} == $LEXEME_RANGES ||
	  $value->{lexemesExact}->{$_}->{type} == $LEXEME_CARET_RANGES) {
	  my $rcIfMatch = ($value->{lexemesExact}->{$_}->{type} == $LEXEME_RANGES) ? 'MARPAWRAPPER_BOOL_TRUE' : 'MARPAWRAPPER_BOOL_FALSE';
	  my $rcIfNoMatch = ($value->{lexemesExact}->{$_}->{type} == $LEXEME_RANGES) ? 'MARPAWRAPPER_BOOL_FALSE' : 'MARPAWRAPPER_BOOL_TRUE';
        my @wanted = ();
        my $n = scalar(@{$value->{lexemesExact}->{$_}->{value}});
        foreach (@{$value->{lexemesExact}->{$_}->{value}}) {
          my @range = @{$_};
	  if ($range[0] ne $range[1]) {
	      push(@wanted, sprintf('%scurrenti >= 0x%x && currenti <= 0x%x%s /* [%s-%s] */', ($n > 1 ? '(' : ''), ord($range[0]), ord($range[1]), ($n > 1 ? ')' : ''), _chprint($range[0]), _chprint($range[1])));
	  } else {
	      push(@wanted, sprintf('%scurrenti == 0x%x%s /* %s */', ($n > 1 ? '(' : ''), ord($range[0]), ($n > 1 ? ')' : ''), _chprint($range[0])));
	  }
        }
	my $wanted = join(" ||\n      ", @wanted);
	$pushLexemeb .= <<ISLEXEMEB;
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ($wanted) {
    *sizelp = 1;
    return $rcIfMatch;
  } else {
    return $rcIfNoMatch;
  }
}
ISLEXEMEB
      } elsif ($value->{lexemesExact}->{$_}->{type} == $LEXEME_HEXMANY) {
	  my @wanted = ();
          my $n = scalar(@{$value->{lexemesExact}->{$_}->{value}});
	  foreach (@{$value->{lexemesExact}->{$_}->{value}}) {
              if ($n > 1) {
  	        push(@wanted, sprintf('(currenti == 0x%x) /* %s */', ord($_), _chprint($_)));
              } else {
  	        push(@wanted, sprintf('0x%x /* %s */', ord($_), _chprint($_)));
              }
	  }
	  my $wanted = join(" ||\n      ", @wanted);
          if ($n == 1) {
          $pushLexemeb .= <<ISLEXEMEB;
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == $wanted) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
ISLEXEMEB
          } else {
	$pushLexemeb .= <<ISLEXEMEB;
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInP, size_t *sizelp) {
  if ($wanted) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
ISLEXEMEB
        }
      } elsif ($value->{lexemesExact}->{$_}->{type} == $LEXEME_STRING) {
        my @wanted = map {sprintf("0x%x /* %s */", ord($_), _chprint($_))} split('', $value->{lexemesExact}->{$_}->{value});
        my $wanted = join(",\n    ", @wanted);
	my $length = length($value->{lexemesExact}->{$_}->{value});
        if ($length == 1) {
          $pushLexemeb .= <<ISLEXEMEB;
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == $wanted) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
ISLEXEMEB
        } else {
          $pushLexemeb .= <<ISLEXEMEB;
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[$length] = {
    $wanted
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < $length);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = $length;
  }

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
__[ bnf ]__
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

RULESEP       ~ '::=' |'~'
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
__[ test01 ]__
<?xml version="1.0" encoding="UTF-8"?>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Common.mod#16 $
-->

<!--
    A few character entities the XML recommendation says should be defined
    "for interoperability" with existing SGML parsers.  By default, these
    are not included to avoid warnings (about entity redefinition) from
    many XML parsers.
-->
<!ENTITY % SGML-help "IGNORE">
<![%SGML-help;[
<!ENTITY lt     "&#38;#60;">
<!ENTITY gt     "&#62;">
<!ENTITY amp    "&#38;#38;">
<!ENTITY apos   "&#39;">
<!ENTITY quot   "&#34;">
]]>

<!--
    Common types used throughout the cXML definition.

    The types try to follow the XML DATA definition submitted to the W3C. See
    the following for more information,

        http://msdn.microsoft.com/xml/reference/schema/datatypes.asp
        http://www.w3c.org/TR/1998/NOTE-XML-data-0105/

-->

<!-- Atomic-level Types -->
<!ENTITY % bin.base64 "CDATA">
<!ENTITY % bin.hex "CDATA">
<!ENTITY % boolean "(0 | 1)">    <!-- 0 is false, 1 is true -->
<!ENTITY % char "CDATA">
<!ENTITY % date "CDATA">
<!ENTITY % datetime.tz "CDATA">  <!-- Time zone is required -->
<!ENTITY % fixed.14.4 "CDATA">
<!ENTITY % i8 "CDATA">
<!ENTITY % int "%i8;">
<!ENTITY % r8 "CDATA">
<!ENTITY % number "CDATA">       <!-- No limit on number of digits, unlike
                                      %r8; -->
<!ENTITY % string "CDATA">
<!ENTITY % time.tz "CDATA">      <!-- Time zone is required -->
<!ENTITY % ui8 "CDATA">
<!ENTITY % uint "%ui8;">         <!-- Unique to this specification -->
<!ENTITY % uri "CDATA">
<!ENTITY % uuid "CDATA">

<!-- Higher-level Types -->
<!--
    NOTE: The following is a temporary *hack* to allow empty values for
    some attributes with these types.  The nmtoken entity should resolve to
    NMTOKEN.
-->
<!ENTITY % nmtoken "CDATA">      <!-- Any combination of XML name chars. -->
<!ENTITY % isoLangCode "%nmtoken;">         <!-- ISO 639 Language Code -->
<!ENTITY % isoCountryCode "%nmtoken;">      <!-- ISO 3166 Country Code -->
<!ENTITY % isoCurrencyCode "%nmtoken;">     <!-- ISO 4217 Currency Code -->
<!ENTITY % xmlLangCode "%nmtoken;"> <!-- Language code as defined by XML
                                         recommendation: Language and
					 country. -->
<!ENTITY % URL "%uri;">
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Base.mod#26 $
-->

<!--
    This file defines the basic elements used to build higher level
    constructs in cXML.
-->

<!-- Basic Name/Data Elements -->
<!--
    Name is used to provide an identifier for other elements.

    xml:lang
        The language in which the name is written.
-->
<!ELEMENT Name (#PCDATA)> <!-- string -->
<!ATTLIST Name
    xml:lang  %xmlLangCode;  #REQUIRED
>

<!--
    An Extrinsic is an element which can be used to extend the data
    associated with known elements.

    Since this Element is of type ANY, it could contain any arbitrary XML
    document within itself, or a binary ![CDATA[]] document.

    name
        Name used to identify this extrinsic.
-->
<!ELEMENT Extrinsic ANY>
<!ATTLIST Extrinsic
    name  %string;  #REQUIRED
>

<!--
    Description is a string which describes something.
    Though text may be interspersed with ShortName elements in this content
    model, placing the ShortName at the beginning or end of the element is
    much preferred.  At most one ShortName element is allowed per
    Description.  The intended content model would be more like
    (( ShortName, #PCDATA ) | ( #PCDATA | ShortName? )) if DTD syntax
    supported it.

    xml:lang
        The language in which the description is written.
-->
<!ELEMENT Description ( #PCDATA | ShortName )* > <!-- mixed: string and
                                                      ShortName -->
<!ATTLIST Description
    xml:lang  %xmlLangCode;  #REQUIRED
>

<!--
    A short string which describes something in fewer characters than the
    entire Description.  This should be used when limited space is available.
    For example, a table of elements might show the ShortName's of each.  A
    linked "details" view would show the entire Description (including the
    ShortName).  Without a ShortName, the user interface must default to a
    truncation of the Description.
    This element does not require an xml:lang attribute since it appears only
    within a Description element.  The language of the ShortName must match
    that of the surrounding Description.
-->
<!ELEMENT ShortName (#PCDATA)> <!-- string -->

<!-- Telephone Number Elements -->
<!--
    International ITU dial code for the country code in question.

    isoCountryCode
        The ISO 3166 country code for the dial code in question
-->
<!ELEMENT CountryCode (#PCDATA)> <!-- uint -->
<!ATTLIST CountryCode
    isoCountryCode  %isoCountryCode;  #REQUIRED
>

<!--
    The areacode or city code within a CountryCode.
-->
<!ELEMENT AreaOrCityCode (#PCDATA)> <!-- uint -->

<!--
    The local number part of a telephone number.
-->
<!ELEMENT Number (#PCDATA)> <!-- string -->

<!--
    An extension within relative to the Number element. This element has no
    meaning without an associated Number element.
-->
<!ELEMENT Extension (#PCDATA)> <!-- uint -->

<!--
    TelephoneNumber represents international telephone numbers.
-->
<!ELEMENT TelephoneNumber (CountryCode, AreaOrCityCode, Number, Extension?)>

<!--
     Phone is a "named" TelephoneNumber.

     name
          specifies an identifier which indicates the type of phone number.
          US examples would include "work","home", etc.
-->
<!ELEMENT Phone (TelephoneNumber)>
<!ATTLIST Phone
    name  %string;  #IMPLIED
>

<!--
    Fax number.
-->
<!ELEMENT Fax (TelephoneNumber | URL | Email)>
<!ATTLIST Fax
    name  %string;  #IMPLIED
>

<!-- Addressing Elements -->
<!--
    URL. A string which represents a URL
-->
<!ELEMENT URL (#PCDATA)> <!-- URL -->
<!ATTLIST URL
    name  %string;  #IMPLIED
>

<!--
    An email address. Address must conform to RFC 821 (SMTP Standard).
-->
<!ELEMENT Email (#PCDATA)> <!-- string -->
<!ATTLIST Email
    name  %string;  #IMPLIED
>

<!--
    Contact represents an entity at a location. The nature of this
    element is that it represents a communication "end point" for a
    location.

    role
        Position this person or group plays in the procurement process.
        Likely values include endUser, administrator, purchasingAgent,
           technicalSupport, customerService, sales,
           supplierMasterAccount, supplierAccount, buyerMasterAccount,
           and buyerAccount.  Other values may be allowed in some cases.
-->
<!ELEMENT Contact (Name, PostalAddress*, Email*, Phone*, Fax*, URL*)>
<!ATTLIST Contact
    role NMTOKEN #IMPLIED
>

<!--
    The DeliverTo part of an Address. This would be internal to the actual
    address know to the outside world. Similar to what an extension is to a
    TelephoneNumber.
-->
<!ELEMENT DeliverTo (#PCDATA)> <!-- string -->

<!--
    Street is a single line of an Address' location.
-->
<!ELEMENT Street (#PCDATA)> <!-- string -->

<!--
    City is the name of the city in an Address' location.
-->
<!ELEMENT City (#PCDATA)> <!-- string -->

<!--
    State is an optional state identifier in an Address' location.
-->
<!ELEMENT State (#PCDATA)> <!-- string -->

<!--
    PostalCode (I have no idea how to describe it)
-->
<!ELEMENT PostalCode (#PCDATA)> <!-- string -->

<!--
    Country is the name of the country in an Address' location

    isoCountryCode
        The ISO 3166 2-letter country code.
-->
<!ELEMENT Country (#PCDATA)> <!-- string -->
<!ATTLIST Country
    isoCountryCode  %isoCountryCode;  #REQUIRED
>

<!--
    PostalAddress is a real-world location for a business or person.
-->
<!ELEMENT PostalAddress (DeliverTo*, Street+, City, State?,
                         PostalCode?, Country)>
<!ATTLIST PostalAddress
    name  %string;  #IMPLIED
>

<!--
    Address is the association of a Contact and an Location.

    isoCountryCode
        The ISO 3166 country code for the dial code in question

    addressID
        An id for the address. Needed to support address codes for
        relationships that require id references.
-->
<!ELEMENT Address (Name, PostalAddress?, Email?, Phone?, Fax?, URL?)>
<!ATTLIST Address
    isoCountryCode  %isoCountryCode;  #IMPLIED
    addressID       %string;          #IMPLIED
>

<!-- Financial Elements -->
<!--
    Money is the representation of the object used to pay for items.

    currency
        specifies the currency in which amount is stated, must conform to ISO
        4217 currency codes.

    alternateAmount
        the amount of money in the alternateCurrency. Optional and used to
        support dual-currency requirements such as the Euro.

    alternateCurrency
        specifies the currency in which the alternateAmount is stated, must
        conform to ISO 4217 currency codes.
-->
<!ELEMENT Money (#PCDATA)> <!-- number -->
<!ATTLIST Money
    currency           %isoCurrencyCode;  #REQUIRED
    alternateAmount    %number;           #IMPLIED
    alternateCurrency  %isoCurrencyCode;  #IMPLIED
>

<!--
    Optional textual child for communicating arbitrary comments or
    description along with the parent.
    Though text may be interspersed with Attachment elements in this content
    model, grouping the Attachment list at the begging or end of the element
    is much preferred.  The intended content model would be more like
    (( Attachment+, #PCDATA ) | ( #PCDATA | Attachment* )) if the DTD syntax
    supported it.

    xml:lang
        The language in which the Comments are written.  This attribute
    will be required in a future version of cXML.  (Leaving it out is
    deprecated.)
-->
<!ELEMENT Comments ( #PCDATA | Attachment )* > <!-- mixed: string and
                                                    opt. Attachment list -->
<!ATTLIST Comments
    xml:lang  %xmlLangCode;  #IMPLIED
>

<!--
    Optional child of Comments element referencing a part in a multipart MIME
    transmission.

    The contained URL must use the scheme "cid:".  This is the identifier for
    the referenced attachment within the larger transmission.  Must match the
    Content-ID header of one (and only one) part of the MIME transmission
    containing this cXML document.  May also be used to retrieve the
    attachment file separately.
-->
<!ELEMENT Attachment (URL)>

<!--
    Price per unit of item.
-->
<!ELEMENT UnitPrice (Money)>

<!--
    Reference to an earlier document (for example, OrderRequest).  In a
    StatusUpdateRequest, this element identifies the purchase order to be
    updated.

    payloadID
        A unique identifier for the document.  Copied directly from the
        cXML element of the original document.
-->
<!ELEMENT DocumentReference EMPTY>
<!ATTLIST DocumentReference
    payloadID       %string;      #REQUIRED
>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Version.mod#2 $
-->

<!--
     Another top-level entity used in Transport.mod.  Defined here to allow
     easy updates to the release version of cXML without opening
     Transport.mod.  This should also provide an easy file to search for
     the current release version string.
-->

<!-- cxml.version
    Current default string for the cXML@version attribute.  Corresponds to
    the final directory of the SYSTEM identifier used in all up-to-date
    cXML documents.
    For easy parsing of this file, do not remove whitespace surrounding the
    actual version string.
-->
<!ENTITY cxml.version "1.1.009" >
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Entities.mod#2 $
-->

<!--
     Top-level entities used in Transport.mod.  Defined here to allow easy
     extention of the cXML specification (using additional DTDs) without
     redefining these entities.
-->

<!-- cxml.messages
     Possible elements (for particular situations) within Message.  These
     are all of the messages defined in the base cXML protocol.
-->
<!ENTITY % cxml.messages "(PunchOutOrderMessage |
                           SubscriptionChangeMessage |
                           SupplierChangeMessage)"
>

<!-- cxml.requests
     Possible elements (for particular situations) within Request.  These
     are all of the requests defined in the base cXML protocol.
-->
<!ENTITY % cxml.requests "(ProfileRequest |
                           OrderRequest |
                           PunchOutSetupRequest |
                           StatusUpdateRequest |
                           GetPendingRequest |
                           SubscriptionListRequest |
                           SubscriptionContentRequest |
                           SupplierListRequest |
                           SupplierDataRequest)"
>

<!-- cxml.responses
     Possible elements (for particular situations) within Response.  These
     are all of the responses (corresponding to a subset of the possible
     requests) defined in the base cXML protocol.
-->
<!ENTITY % cxml.responses "(ProfileResponse |
                            PunchOutSetupResponse |
                            GetPendingResponse |
                            SubscriptionListResponse |
                            SubscriptionContentResponse |
                            SupplierListResponse |
                            SupplierDataResponse)"
>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Profile.mod#5 $
-->

<!--
    Request for the latest profile from the server.  May also be used as
    a 'ping' transaction (to check if the server is available).
-->
<!ELEMENT ProfileRequest EMPTY >

<!--
    Static profile response describing the transactions supported by this
    server.  The content should not change frequently.

    effectiveDate
        When these services were first available.  Should not be in the
    future since new clients may need to interact with a server.

    a-dtype
        Datatype enumeration for the attributes of this element.  May be
    ignored by most XML parsers (used for documentation purposes).
-->
<!ELEMENT ProfileResponse ( Option*, Transaction+ )>
<!ATTLIST ProfileResponse
    effectiveDate %datetime.tz; #REQUIRED
    a-dtype       NMTOKENS      #FIXED 'effectiveDate dateTime'
>

<!--
    Value for a defined option (either for the overall service or a
    specific transaction.  At this time, no options are defined at either
    level.

    name
        The name of this option.  Future versions of cXML will define
    values for this attribute.  This is not intended to be viewed
    directly (the profile is intended mostly for machine consumption).

    a-dtype
        Datatype enumeration for the attributes of this element.  May be
    ignored by most XML parsers (used for documentation purposes).
-->
<!ELEMENT Option ( #PCDATA )>   <!-- string -->
<!ATTLIST Option
    name          %string;      #REQUIRED
    a-dtype       NMTOKENS      #FIXED 'name string'
>

<!--
    A transaction supported by this server.

    requestName
        A specific request this server accepts at the given URL.  The
    %cxml.requests entity (defined in transport.mod) contains the
    possible values for this attribute.

    a-dtype
        Datatype enumeration for the attributes of this element.  May be
    ignored by most XML parsers (used for documentation purposes).
-->
<!ELEMENT Transaction ( URL, Option* )>
<!ATTLIST Transaction
    requestName   %nmtoken;     #REQUIRED
    a-dtype       NMTOKENS      #FIXED 'requestName NMTOKEN'
>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Supplier.mod#13 $
-->

<!--
    Supplier of goods and services. Includes a list of SupplierIDs which
    identify the Supplier.

    corporateURL
        URL to web site about the supplier

    storeFrontURL
        URL to web site where a user can shop or browse
-->
<!ELEMENT Supplier (Name, Comments?, SupplierID+, SupplierLocation*)>
<!ATTLIST Supplier
    corporateURL   %URL;  #IMPLIED
    storeFrontURL  %URL;  #IMPLIED
>

<!--
    One of the locations for a supplier. Supplier location is
    generally a physical location.
-->
<!ELEMENT SupplierLocation (Address, OrderMethods)>

<!--
    OrderMethods is the list of methods by which one can order
    from a supplier. The contact element is the technical contact
    who should be able to assist with order processing issues.
    The list is to be ordered by supplier preference, the first
    element having the highest degree of preference.
-->
<!ELEMENT OrderMethods (OrderMethod+, Contact?)>

<!--
    OrderMethod is a method for ordering. It is comprised of a
    target address for the order and the protocol expected by
    the address.
-->
<!ELEMENT OrderMethod (OrderTarget, OrderProtocol?)>

<!--
    OrderTarget represents an address to which orders can be
    sent.
-->
<!ELEMENT OrderTarget (Phone | Email | Fax | URL | OtherOrderTarget)>

<!--
    OrderProtocol is the communication method to be used when
    communicating an order to a supplier. An example would be "cXML".
-->
<!ELEMENT OrderProtocol (#PCDATA)> <!-- string -->

<!--
    OtherOrderTarget represents an address which is not enumerated by
    default in the OrderTarget Element. This may contain address targets
    beyond the ability of this document to describe.

    name
        Optional name for target.
-->
<!ELEMENT OtherOrderTarget ANY>
<!ATTLIST OtherOrderTarget
    name  %string;  #IMPLIED
>

<!--
    Definition of a supplier id.  A supplier id is a (domain, value)
    pair so that suppliers have the flexibility to define their id's
    according to an arbitrary convention (e.g., (DUNS, 12345),
    (TaxID, 88888888)).

    domain
        the domain of the id
-->

<!ELEMENT SupplierID (#PCDATA)> <!-- string -->
<!ATTLIST SupplierID
    domain  %string;  #REQUIRED
>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Item.mod#18 $
-->

<!--
    Must be a UN/CEFACT (Recommendation 20) unit of measure code.
-->
<!ELEMENT UnitOfMeasure (#PCDATA)> <!-- nmtoken -->

<!--
    ID with which the item's manufacturer identifies the item.
-->
<!ELEMENT ManufacturerPartID (#PCDATA)> <!-- string -->

<!--
    Name of the item's manufacturer.

    xml:lang
        The language in which the ManufacturerName is written.  This
    attribute will be required in a future version of cXML.  (Leaving it
    out is deprecated.)
-->
<!ELEMENT ManufacturerName (#PCDATA)> <!-- string -->
<!ATTLIST ManufacturerName
    xml:lang %xmlLangCode; #IMPLIED
>

<!--
    Classification is used to group items into similar categories.

    domain
        "name" of classification, ie., SPSC
-->
<!ELEMENT Classification (#PCDATA)> <!-- string -->
<!ATTLIST Classification
    domain  %string;  #REQUIRED
>

<!--
    How the supplier identifies an item they sell.

    If SupplierPartID does not provide a unique key to identify the item,
    then the supplier should generate a key which identifies the part
    uniquely when combined with the SupplierID and SupplierPartID. The
    key is called SupplierPartAuxiliaryID.

    An example is where a Supplier would use the same PartID for an
    item but have a different price for units of "EA" versus "BOX".
    In this case, the ItemIDs should be:
    <ItemID>
        <SupplierPartID>pn12345</SupplierPartID>
        <SupplierPartAuxiliaryID>EA</SupplierPartAuxiliaryID>
    </ItemID>
    <ItemID>
        <SupplierPartID>pn12345</SupplierPartID>
        <SupplierPartAuxiliaryID>
           <foo>well formed XML here</foo>
        </SupplierPartAuxiliaryID>
    </ItemID>
    In this case, the "foo" element must be defined in an internal subset
    sent with the cXML document.  Otherwise, parsers will not be able to
    validate that document.

    In a preferred approach, the sending application may escape the contained
    XML using CDATA sections.  This would appear as:
       ...
       <SupplierPartAuxiliaryID>
           <![CDATA[<foo>well formed XML here</foo>]]>
       </SupplierPartAuxiliaryID>
       ...

    Finally, the angle brackets could be escaped using XML character
    entities.  This might be a bit harder for humans to read.  For example:
       ...
       <SupplierPartAuxiliaryID>
           &lt;foo&gt;well formed XML here&lt;/foo&gt;
       </SupplierPartAuxiliaryID>
       ...
-->
<!ELEMENT SupplierPartID (#PCDATA)> <!-- string -->

<!ELEMENT SupplierPartAuxiliaryID ANY>

<!--
    A unique identification of an item. SupplierID is not required since
    ItemIDs never travel alone.
-->
<!ELEMENT ItemID (SupplierPartID, SupplierPartAuxiliaryID?)>

<!--
    ItemDetail contains detailed information about an item. All the data that
    a user would want to see about an item instead of the bare essentials
    that are represented in the ItemID.
-->
<!ELEMENT ItemDetail (UnitPrice, Description+, UnitOfMeasure,
                      Classification+, ManufacturerPartID?,
                      ManufacturerName?, URL?, Extrinsic*)>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Transaction.mod#29 $
-->

<!--
    For better definitions of these Elements/Entities, refer to the cXML
    Transaction Specification documents.
-->

<!-- Basic transactional elements used throughout -->
<!--
    The total for something.
-->
<!ELEMENT Total (Money)>

<!--
    The bill to for an item.
-->
<!ELEMENT BillTo (Address)>

<!--
    The ship to for a item.
-->
<!ELEMENT ShipTo (Address)>

<!--
    Definition of a cXML Shipping item. Represents a shipping cost in the
    shopping basket (PunchOutOrderMessage) or an order to the supplier
    (OrderRequest). There could be one of these for the entire order, or one
    per lineitem.

    trackingDomain
        represents the logistics supplier, I.E., "FedEx", "UPS", etc.

    trackingId
        an optional element value that represents the logistics supplier
        tracking number

    tracking
        Deprecated - Do Not Use
-->
<!ELEMENT Shipping (Money, Description)>
<!ATTLIST Shipping
    trackingDomain  %string;  #IMPLIED
    trackingId      %string;  #IMPLIED
    tracking        %string;  #IMPLIED
>

<!--
    Defines a Purchasing Card element used for payment
-->
<!ELEMENT PCard (PostalAddress?)>
<!ATTLIST PCard
    number      %number;  #REQUIRED
    expiration  %date;    #REQUIRED
    name        %string;  #IMPLIED
>

<!--
    The list of valid payment types.
-->
<!ENTITY % cxml.payment  "PCard">
<!ELEMENT Payment (%cxml.payment;)>

<!--
    Defines an accounting segment.  Segment is an older, deprecated way to
    transport this information.

    type
        The accounting type of this segment.

    id
        The unique key of this Segment against the type.

    description
        Textual description of the Segment. For human readability.
-->
<!ELEMENT Segment EMPTY>
<!ATTLIST Segment
    type         %string;  #REQUIRED
    id           %string;  #REQUIRED
    description  %string;  #REQUIRED
>

<!--
    Defines an accounting segment.  AccountingSegment is the newer, better
    way to transport this information.  Name corresponds to the type
    attribute of Segment; Description corresponds to description.  Both add
    required locale attributes to the strings.

    id
        The unique key of this Segment against the type.
-->
<!ELEMENT AccountingSegment ( Name, Description )>
<!ATTLIST AccountingSegment
    id           %string;  #REQUIRED
>

<!--
    An accounting object.  Use of the Segment element here is deprecated.

    name
        The name of the object containing the specified accounting segments.
-->
<!ENTITY % cxml.accounting  "( Segment+ | AccountingSegment+ )">
<!ELEMENT Accounting (%cxml.accounting;)>
<!ATTLIST Accounting
    name  %string;  #REQUIRED
>

<!--
    A charge against an Accounting element.
-->
<!ELEMENT Charge (Money)>

<!--
    The combination of a Charge against an Accounting Element. A distribution
    represents the breakdown of one overall amount into sub-amounts.
-->
<!ELEMENT Distribution (Accounting, Charge)>

<!--
    Definition of a cXML Tax item. This represents what a Tax element should
    be in the classic notion of a line on a PO or Invoice. It can also
    represent a per-lineitem tax element depending on where it appears
    (inside of a item ELEMENT or inside of a something like a supplierOrder
    ELEMENT).

    Represents a tax item in the shopping basket. There could be one of these
    for the entire order, or one per lineitem.
-->
<!ELEMENT Tax (Money, Description)>

<!-- Item Elements -->
<!--
    The representation of a line item as it needs to be for sending to a
    supplier.

    quantity
        How many items are desired.
    lineNumber
        Position (counting from 1) of this item in an order.  Used to
        maintain a reference between items in create and update OrderRequest
        documents.
    requisitionID
        The buyers system requisition id for this line item. It might be the
        same as orderID, and it might not be included at all.  Must not be
        included if requisitionID is specified in the OrderRequestHeader.
    requestedDeliveryDate
        The date this item was requested for delivery.
-->
<!ELEMENT ItemOut (ItemID, ItemDetail?, SupplierID?, ShipTo?, Shipping?,
                   Tax?, Distribution*, Contact*, Comments?)>
<!ATTLIST ItemOut
    quantity               %r8;      #REQUIRED
    lineNumber             %uint;    #IMPLIED
    requisitionID          %string;  #IMPLIED
    requestedDeliveryDate  %date;    #IMPLIED
>

<!--
    The representation of a line item as it needs to be for sending to a
    buyer.

    quantity
        How many items are desired.
    lineNumber
        Position (counting from 1) of this item in an order.  Used to
        maintain a reference between items in create and update OrderRequest
        documents.
-->
<!ELEMENT ItemIn (ItemID, ItemDetail, SupplierID?, ShipTo?, Shipping?, Tax?)>
<!ATTLIST ItemIn
    quantity   %r8;      #REQUIRED
    lineNumber %uint;    #IMPLIED
>

<!-- OrderRequest* Elements -->
<!--
    Definition of an order.  This is the data that is sent to the supplier
    to have them place an order in their order management system. The new
    world order equivalent of a PO.
-->
<!ELEMENT OrderRequest (OrderRequestHeader, ItemOut+)>

<!--
    Header of an order.  This is the data that is sent to the supplier
    to have them place an order in their order management system. Money
    represents the total amount of this order.

    orderID
        The buyer system orderID for this request. Basically, what the PO
        number is today.

    orderDate
        The date and time the order request was created.

    type
        The type of the order request. Defaults to "new".

    requisitionID
        The buyers system requisition id for this entire order. It might be
        the same as orderID, and it might not be included at all.  Must not
        be included if requisitionID is specified in any ItemOut elements.

    shipComplete
        Optional preference for "hold until complete" processing.  Defaults
        to shipping when available if not specified.  Future versions of the
        protocol may extend the datatype of this attribute to include
        additional possible values (such as "unlessGreatlyBackOrdered"?).

    The contained DocumentReference element would appear in a document only
    when the type is "update" or "delete".  In that case, the
    DocumentReference would reference the most recent OrderRequest document
    for the order.  For example when an order is created, updated and then
    deleted, the final document should contain a DocumentReference
    referring to the OrderRequest with type="update".  That document would,
    in turn, refer to the original (type="new") OrderRequest document.
-->
<!ELEMENT OrderRequestHeader (Total, ShipTo?, BillTo, Shipping?, Tax?,
                              Payment?, Contact*, Comments?, Followup?,
                              DocumentReference?, Extrinsic*)>
<!ATTLIST OrderRequestHeader
    orderID    %string;        #REQUIRED
    orderDate  %datetime.tz;   #REQUIRED
    type       (new | update | delete)  "new"
    requisitionID   %string;   #IMPLIED
    shipComplete    (yes)      #IMPLIED
>

<!-- Followup

     Location to which future StatusUpdateRequest documents should be
     posted.  In general, this is the input location for any later
     documents which reference the current OrderRequest document.
-->
<!ELEMENT Followup (URL)>

<!-- PunchOut* Elements -->
<!--
     Definition of a PunchOut Setup Request.  This is the data that is sent
     to the external system that the Ariba ORMS is going to extract catalog
     data from.

     The BrowserFormPost element contains the URL we would like the browser
     re-directed to when the PunchOut shopping experience is finished (where
     the PunchOutOrder message should be returned).
-->
<!ELEMENT PunchOutSetupRequest (BuyerCookie, Extrinsic*, BrowserFormPost?,
                                Contact*, SupplierSetup?, ShipTo?,
                SelectedItem?, ItemOut*)>
<!ATTLIST PunchOutSetupRequest
    operation  (create | inspect | edit)  #REQUIRED
>

<!ELEMENT BuyerCookie ANY> <!-- any valid XML data -->

<!ELEMENT BrowserFormPost (URL)>
<!ELEMENT SelectedItem (ItemID)>
<!ELEMENT SupplierSetup (URL)>

<!ELEMENT PunchOutSetupResponse (StartPage)>
<!ELEMENT StartPage (URL)>

<!--
     Definition of a PunchOut Order Message.  This is the data that is sent
     back to the Ariba ORMS system from the external system that the PunchOut
     Request was targeted at.
-->
<!ELEMENT PunchOutOrderMessage (BuyerCookie, PunchOutOrderMessageHeader,
                                ItemIn*)>

<!--
     Header of a PunchOut Order Request.  This is the data that is sent from
     the supplier to transfer the supplier acquired shopping basket back to
     the buyer system.

     operationAllowed
          Highest operation allowed on the PunchOut shopping basket.
          "create" allows only later OrderRequest operations on these items.
          "inspect" adds a PunchOutSetupRequest with operation="inspect".
          And, "edit" allows operation="edit" in that later Setup request.
-->
<!ELEMENT PunchOutOrderMessageHeader (Total, ShipTo?, Shipping?, Tax?)>
<!ATTLIST PunchOutOrderMessageHeader
    operationAllowed  (create | inspect | edit)  #REQUIRED
>

<!--
    Request to update the status of an earlier order.
-->
<!ELEMENT StatusUpdateRequest  (DocumentReference, Status)>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Transport.mod#36 $
-->

<!--
    For better definitions of these Elements/Entities, refer to the cXML
    Protocol Specification documents.
-->

<!--
    cXML envelope

    version
        Version of this cXML transmission.  Should be less than or equal
    to the version portion of the SYSTEM identifier for this document.

    payloadID
        A unique identifier for this document.

    timestamp
        The date and time at which this document was originally created.

    xml:lang
        The default locale for all strings (not formatted items such as
    dates, times and numbers) in this document.  This attribute will be
    required in a future version of cXML.  (Leaving it out is
    deprecated.)
-->
<!ELEMENT cXML (( Header, (Message | Request)) | Response)>
<!ATTLIST cXML
    version    %string;       "&cxml.version;"
    payloadID  %string;       #REQUIRED
    timestamp  %datetime.tz;  #REQUIRED
    xml:lang   %xmlLangCode;  #IMPLIED
>

<!-- header -->
<!ELEMENT Header (From, To, Sender)>

<!ELEMENT From (Credential+)>
<!ELEMENT To (Credential+)>
<!ELEMENT Sender (Credential+, UserAgent)>

<!--
    A textual string representing who the UserAgent is conducting the cXML
    conversation. Analogous to UserAgent for HTTP conversations.
-->
<!ELEMENT UserAgent (#PCDATA)>

<!--
    A digital signature.  The recommended format is self-contained PK7. The
    exact signed content is not that significant but current timestamp would
    be used just as a convention.

    type
        The type of digital signature used.

    encoding
        How is the signature encoded in the XML stream.
-->
<!ELEMENT DigitalSignature ANY>
<!ATTLIST DigitalSignature
    type      %string;  "PK7 self-contained"
    encoding  %string;  "Base64"
>

<!--
    A shared secret. Typically, this is a username/password type of secret
    exchanged through a secure transport before communication takes place.
-->
<!ELEMENT SharedSecret ANY>

<!--
    Represents an identity for a credential.

    lastChangedTimestamp
       When the underlying object last changed in the originating system.
       This is used in cases where the same object (e.g. a buyer
       organization) is replicated, and kept synchronized, across two
       systems.
-->
<!ELEMENT Identity ANY>
<!ATTLIST Identity
    lastChangedTimestamp  %datetime.tz;  #IMPLIED
>

<!--
    A combination of an Identity and authentication element. If the
    authentication element is present, it strongly authenticates who/what
    someone is.  The authentication element should not be sent within Message
    documents transported via an end user's browser.  One-way communication
    must be authenticated in the transport layer.

    domain
        In what domain is this Credential represented?
    type
        Does this Credential identify a marketplace or one of its member
        companies?  A Credential without this attribute describes a member
        company or unaffiliated buying organization.
-->
<!ENTITY % cxml.authentication  "SharedSecret |
                                 DigitalSignature"
>
<!ELEMENT Credential (Identity, (%cxml.authentication;)?)>
<!ATTLIST Credential
    domain  %string;      #REQUIRED
    type    (marketplace) #IMPLIED
>

<!--
    Status of a Response or Message.  If present, the element content
    describes specifics of a problem.

    code
        HTTP or cXML-specific status code.

    text
        Textual version of the status code (not specific issue).

    xml:lang
        The language in which the text attribute and element content are
    written.  This attribute will be required in a future version of
    cXML.  (Leaving it out is deprecated.)
-->
<!ELEMENT Status (#PCDATA)>
<!ATTLIST Status
    code     %uint;        #REQUIRED
    text     %string;      #REQUIRED
    xml:lang %xmlLangCode; #IMPLIED
>

<!--
    Message

    When Status not present, '<Status code="200" text="OK" />' is implied.
-->
<!ELEMENT Message (Status?, %cxml.messages;)>
<!ATTLIST Message
    deploymentMode  (production | test)  "production"
    inReplyTo       %string;  #IMPLIED
>

<!-- request -->
<!ELEMENT Request (%cxml.requests;)>
<!ATTLIST Request
    deploymentMode  (production | test)  "production"
>

<!-- response -->
<!ELEMENT Response (Status, (%cxml.responses;)?)>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Contract.mod#14 $
-->

<!ELEMENT Contract (SupplierID+, Comments?, ItemSegment+)>
<!ATTLIST Contract
    effectiveDate   %datetime.tz;  #REQUIRED
    expirationDate  %datetime.tz;  #REQUIRED
>

<!--
    Defines an item segment for the index.  An item segment is an
    overlay for index items, allowing suppliers to override certain
    item attributes on a per-contract basis.

    Items may be segmented by some agreed-upon user-specific key that
    is used to determine who is eligible for these particular overlaid
    attributes (such as reduced or different prices).  Omitting the
    segmentKey indicates that the supplier wishes to set the given
    contract price system wide (for all users).

    segmentKey      - optional agreed-upon string used to segment
                      custom prices
-->
<!ELEMENT ItemSegment (ContractItem+)>
<!ATTLIST ItemSegment
    segmentKey  %string;  #IMPLIED
>

<!--
    A particular (custom) item overlay for a index item.  The item is
    referenced by the supplierPartID.

    ItemID - ID for the part to be overlaid.
    UnitPrice - Contract price for item
    Extrinsic - Named overlay. The Extrinsic should be named with the
    item field name it is to overlay. The Extrinsic must contain a
    <value> element which supplies the replacement value for the item
    field.
    For example:
    <ContractItem>
      <ItemID>
           <SupplierPartID>123456</SupplierPartID>
      </ItemID>
      <Extrinsic name="URL">http://www.newaddress.com</Extrinsic>
    </ContractItem>
-->
<!ELEMENT ContractItem (ItemID, UnitPrice?, Extrinsic*)>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Index.mod#13 $
-->

<!--
     IndexItemAdd is the element used to insert an item in an index.

     ItemID          - uniquely identifies the item
     ItemDetail      - general information about the item
     IndexItemDetail - Index specific item detail

-->
<!ELEMENT IndexItemAdd (ItemID, ItemDetail, IndexItemDetail)>
<!--
     IndexItemDelete is the element used to remove an item from the
     index.
     ItemID          - uniquely identifies the item

-->
<!ELEMENT IndexItemDelete (ItemID) >

<!--
     IndexItemPunchout is the element used to dynamically connect an
     index item to the supplier's resource for that item.

     ItemID          - uniquely identifies the item
     PunchoutDetail  - Describes the item being accessed
-->
<!ELEMENT IndexItemPunchout (ItemID, PunchoutDetail)>

<!--
     IndexItem is the general ELEMENT for the list of items in an
     index.

     IndexItemAdd      - Item(s) to be added to the index
     IndexItemDelete   - Item(s) to be removed from the index
     IndexItemPunchout - PunchOut Item(s) to be added to the index

-->
<!ELEMENT IndexItem (IndexItemAdd+ | IndexItemDelete+ | IndexItemPunchout+)>

<!--
     PunchoutDetail is the description of an item which is referenced
     in the index.

-->
<!ELEMENT PunchoutDetail (Description+, URL, Classification+,
                          ManufacturerName?, ManufacturerPartID?,
                          ExpirationDate?, EffectiveDate?,
                          SearchGroupData*, TerritoryAvailable*)>

<!--
     Index is the element used to update the list of goods and/or
     services which are being handled by the system.

     SupplierID  - One or more identities by which this supplier is
                   known. NOTE: These are to be considered synonyms
                   for the same Supplier.
     SearchGroup - Description(s) of parametric search(es) for this
                   index
     IndexItem   - The list of items with which to modify the index

-->
<!ELEMENT Index (SupplierID+, Comments?, SearchGroup*, IndexItem+)>

<!--
     SearchGroup is a grouping of attributes which constitute a search
     which can be performed against an index.

     Name            - Name of the search
     SearchAttribute - List of searchable index fields.
-->
<!ELEMENT SearchGroup (Name, SearchAttribute+)>

<!--
     An attribute that can searched parametrically.

     name - name of the attribute.
     type - the type of the attribute
-->
<!ELEMENT SearchAttribute EMPTY>
<!ATTLIST SearchAttribute
    name  %string;  #REQUIRED
    type  %string;  #IMPLIED
>

<!--
     LeadTime specifies, in days, the amount of time required to
     receive the item.
-->
<!ELEMENT LeadTime (#PCDATA)>   <!-- uint -->

<!--
     ExpirationDate is the date and time after which the element is no longer
     valid.  Must be specified in ISO 8601 format.

-->
<!ELEMENT ExpirationDate (#PCDATA)>   <!-- datetime.tz -->
<!--
     EffectiveDate date and time at which the element becomes valid.
     Must be specified in ISO 8601 format.
-->
<!ELEMENT EffectiveDate (#PCDATA)>    <!-- datetime.tz -->

<!--
     IndexItemDetail contains various index specific elements which
     help to define an index item.
     LeadTime           - time in days to receive the item
     ExpirationDate     - Expiration date and time for the item in this index
     EffectiveDate      - Effective date and time for the item in this index
     SearchGroupData    - Parametric search data
     TerritoryAvailable - Country codes
-->
<!ELEMENT IndexItemDetail (LeadTime, ExpirationDate?, EffectiveDate?,
                           SearchGroupData*, TerritoryAvailable*)>

<!--
     Specification of a territory (using ISO country and/or region codes)
     in which the particular index item is available.
-->
<!ELEMENT TerritoryAvailable (#PCDATA)>

<!--
     SearchGroupData specifies the data which should be used to identify
     this item in a search.
-->
<!ELEMENT SearchGroupData (Name, SearchDataElement+)>

<!--
     SearchDataElement is a field and value which are used to provide the
     parametric data to a search.
-->
<!ELEMENT SearchDataElement EMPTY>
<!ATTLIST SearchDataElement
     name  %string; #REQUIRED
     value %string; #REQUIRED
>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/Pending.mod#7 $
-->

<!--
    For better definitions of these Elements/Entities, refer to the cXML
    Specification documents.
-->

<!--
    A request used for polling for waiting messages. A waiting message, if
    any, will be included in the returned stream. The lastReceivedTimestamp
    attribute, if present, provides the timestamp of the last received
    message. When the Receiver sees this, it can remove messages with earlier
    timestamps from the pending queue.

    The maxMessages attribute is used to indicate the maximum number of
    pending messages that can be included in the response.


-->
<!ELEMENT GetPendingRequest (MessageType+)>
<!ATTLIST GetPendingRequest
    maxMessages            %uint;         #IMPLIED
    lastReceivedTimestamp  %datetime.tz;  #IMPLIED
>

<!--
    Indicates the type of message(s) being polled for. The valid values are
    the corresponding element names e.g. SubscriptionChangeMessage.
-->
<!ELEMENT MessageType (#PCDATA)> <!-- nmtoken -->


<!--
    The data elements being carried back in the response. These are fully
    formed cXML messages being carried through the Request/Response channel.
-->
<!ELEMENT GetPendingResponse (cXML+)>
<!--
    For cXML license agreement information, please see
    http://www.cxml.org/home/license.asp

    $Id: //ariba/specs/cXML/subscription.mod#10 $
-->

<!--
    Indicates that something changed in a buyer's content subscription.
    Since this is a Message, it can come at any time - no explicit Request
    needs to be sent first.
-->
<!ELEMENT SubscriptionChangeMessage (Subscription+)>
<!ATTLIST SubscriptionChangeMessage
    type  (new | update | delete)  #REQUIRED
>

<!--
    A content subscription.
-->
<!ELEMENT Subscription (InternalID, Name, Changetime, SupplierID+, Format?,
                        Description?)>

<!ELEMENT InternalID (#PCDATA)> <!-- string -->
<!ATTLIST InternalID
    domain   %string;  #IMPLIED
>

<!ELEMENT Changetime (#PCDATA)> <!-- datetime.tz -->
<!ELEMENT Format (#PCDATA)> <!-- string -->
<!ATTLIST Format
    version  %string;  #REQUIRED
>

<!--
    Requests a complete list of catalog subscriptions for a buyer.
-->
<!ELEMENT SubscriptionListRequest EMPTY>

<!--
    The list of Subscriptions for the given buyer.
-->
<!ELEMENT SubscriptionListResponse (Subscription+)>

<!--
    Requests the contents of a catalog that the buyer is subscribed to.
-->
<!ELEMENT SubscriptionContentRequest (InternalID, SupplierID+)>

<!--
    The data associated with a particular subscription.
-->
<!ELEMENT SubscriptionContentResponse (Subscription, SubscriptionContent+)>

<!--
    The actual content associated with a particular subscription.
-->
<!ELEMENT SubscriptionContent (CIFContent | Index | Contract)>
<!ATTLIST SubscriptionContent
    filename  %string;  #IMPLIED
>

<!--
    Contents of CIF file in base64 encoding.
-->
<!ELEMENT CIFContent (#PCDATA)> <!-- bin.base64 -->

<!--
    Indicates that something has changed in the supplier data for
    a supplier the buyer has a relationship with. Since this is a message, no
    Request needs to be sent to receive this Message.
-->
<!ELEMENT SupplierChangeMessage (Supplier+)>
<!ATTLIST SupplierChangeMessage
    type  (new | update | delete)  #REQUIRED
>

<!--
    Requests for a complete list of suppliers the buyer currently has
    relationships with.
-->
<!ELEMENT SupplierListRequest EMPTY>

<!--
    The list of suppliers requested by SupplierListRequest.
-->
<!ELEMENT SupplierListResponse (Supplier+)>

<!--
    Requests for a data associated with a particular supplier identified by
    SupplierID.
-->
<!ELEMENT SupplierDataRequest (SupplierID+)>

<!--
    The data associated with the desired supplier.
-->
<!ELEMENT SupplierDataResponse (Supplier)>
