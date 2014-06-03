#!env perl
#
# This program creates a Marpa BNF of a W3C BNF.
#
# The negation form "term - term" is forced to be a lexeme.
#
use strict;
use diagnostics;
use warnings FATAL => 'all';

package Actions;
sub new() {
  my $self = {
              quantifiers => {},
              rules => [],
              lexemes => {},
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

    foreach (sort {$a->{lhs} cmp $b->{lhs}} @{$self->{rules}}) {
      my $content;
	push(@{$rcp}, $content = join(' ', $_->{lhs}, '::=', $_->{rhs}, $_->{quantifier}));
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

  return "@{$exceptions}";
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

sub _printable {
  my ($self, $chr) = @_;
  if ($chr =~ /[\s]/ || (! ($chr =~ /[[:ascii:]]/) || ($chr =~ /[[:cntrl:]]/))) {
    $chr = sprintf('\\x{%x}', ord($chr));
  }
  return $chr;
}

sub _factorCaretRange {
  my ($self, $lbracket, $caret, $ranges, $rbracket) = @_;
  return $self->_factor("[^$ranges]");
}

sub _factorRange {
  my ($self, $lbracket, $ranges, $rbracket) = @_;
  return $self->_factor("[$ranges]");
}

sub _ranges {
  my ($self, @ranges) = @_;
  return join('', @ranges);
}

sub _range {
  my ($self, $char1, $char2) = @_;
  my $range;
  $char1 = $self->_printable($char1);
  if (defined($char2)) {
    $char2 = $self->_printable($char2);
    $range = "$char1-$char2";
  } else {
    $range = $char1;
  }
  return $range;
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
  my ($self, $value) = @_;

  my @name = grep {$self->{lexemes}->{$_} eq $value} keys %{$self->{lexemes}};
  my $name;
  if (! @name) {
    $name = sprintf('_Lex%03d', 1 + (keys %{$self->{lexemes}}));
    $self->{lexemes}->{$name} = $value;
  } else {
    $name = $name[0];
  }
  return $name;
}

sub _factorString {
  my ($self, $quote1, $string, $quote2) = @_;
  return $self->_factor($string);
}

sub _hexMany {
  my ($self, @hex) = @_;
  return $self->_factor(join('', map {$self->_printable($self->_char($_))} @hex));
}

sub _termFactorQuantifier {
  my ($self, $factor, $quantifier) = @_;

  my $symbol;
  if ($quantifier eq '*') {
    $symbol = sprintf('%s_any', $factor);
    if (! exists($self->{quantifier}->{$symbol})) {
      $self->_rule(undef, $symbol, undef, [ $factor], [], $quantifier);
      $self->{quantifier}->{$symbol}++;
    }
  } elsif ($quantifier eq '+') {
    $symbol = sprintf('%s_many', $factor);
    if (! exists($self->{quantifier}->{$symbol})) {
      $self->_rule(undef, $symbol, undef, [ $factor], [], $quantifier);
      $self->{quantifier}->{$symbol}++;
    }
  } elsif ($quantifier eq '?') {
    $symbol = sprintf('%s_maybe', $factor);
    if (! exists($self->{quantifier}->{$symbol})) {
      $self->_rule(undef, $symbol, undef, ["$factor"], []);
      $self->_rule(undef, $symbol, undef, [], []);
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
    $self->_rule(undef, $symbol, undef, [ $name ], []);
    return $symbol;
}

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
# The namespace will be the fist part of the basename of the grammar
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
  generateTypedef($value, $namespace);
  print STDERR "Symbols: " . join(' ', sort keys %{$value->{symbols}} ) . "\n";
}

exit(EXIT_SUCCESS);

sub generateTypedef {
  my ($value, $namespace) = @_;

  print "/* Symbols */\n";
  print "typedef enum ${namespace}_symbol {\n";
  my $i = 0;
  my @terminals = map {
    my $content = $value->{symbols}->{$_}->{content};
    if ($i++ == 0) {
      sprintf('  %-20s, /* %s */', "$_ = 0", $content);
    } else {
      sprintf('  %-20s, /* %s */', $_, $content);
    }} sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}};
  $i = 0;
  my @g1 = sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} != 1} keys %{$value->{symbols}};
  @g1 = map {
    my $content = $value->{symbols}->{$_}->{content};
    if ($i++ < $#g1) {
      sprintf('  %-20s, /* %s */', $_, $content);
    } else {
      sprintf('  %-20s  /* %s */', $_, $content);
    }
  } @g1;
  print "  /* Terminals */\n";
  print join("\n", @terminals) . "\n";
  print "  /* Non-terminals */\n";
  print join("\n", @g1) . "\n";
  print "} ${namespace}_symbol_t;\n";
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
               |   DQUOTE STRINGDQUOTE DQUOTE                           action => _factorString
               |   SQUOTE STRINGSQUOTE SQUOTE                           action => _factorString
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
