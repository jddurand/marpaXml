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
our $LEXEME_HEX          = 3;

###########################################################################
# package Actions                                                         #
###########################################################################

package Actions;
use POSIX qw/EXIT_FAILURE/;
sub new() {
  my $self = {
              rules => [],
              lexemes => {},
              lexemesExact => {},
              lexemesWithExclusion => {},
	      symbols => {},
              start => {number => undef, rule => ''},
	      grammar => '',
	      nbConstraintsByType => {},
	      nullablesForParseEvents => {}
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
      push(@{$rcp}, $content = join(' ', "<$_>", '~', $self->{$key}->{$_}));
    } elsif ($self->{$key}->{$_} =~ /^\\x\{/) {
      my $thisContent = $self->{$key}->{$_};
      my $lastCharacter = substr($thisContent, -1, 1);
      if ($lastCharacter eq '+' || $lastCharacter eq '*') {
        substr($thisContent, -1, 1, '');
        push(@{$rcp}, $content = join(' ', "<$_>", '~', '[' . $thisContent . "]$lastCharacter"));
      } else {
        push(@{$rcp}, $content = join(' ', "<$_>", '~', '[' . $thisContent . ']'));
      }
    } else {
      push(@{$rcp}, $content = join(' ', "<$_>", '~', '\'' . $self->{$key}->{$_} . '\''));
    }
    $self->{symbols}->{$_} = {terminal => 1, content => $content};
  }
}

sub _addNullablesForParseEvents {
    my ($self) = @_;
    #
    # Loop on all rule and insert nullable symbols as soon as there is lexing event
    #
    foreach (0..$#{$self->{rules}}) {
	my $irule = $_;
	my $rule = $self->{rules}->[$irule];
	my $lhs = $rule->{lhs};
	if ((exists($rule->{constraints}->{event_completed}) && @{$rule->{constraints}->{event_completed}}) ||
	    (exists($rule->{constraints}->{event_predicted}) && @{$rule->{constraints}->{event_predicted}}) ||
	    (exists($rule->{constraints}->{event_nulled}) && @{$rule->{constraints}->{event_nulled}})) {
	    my $nullableName = sprintf('_nullableForParseEvent%03d', 1 + (keys %{$self->{nullablesForParseEvents}}));
	    $self->{nullablesForParseEvents}->{$nullableName} = $irule;
	    print STDERR "[INFO] Inserting nullable symbol $nullableName for rule No $irule: " . main::ruleToChars($rule) . "\n";
	    $self->_rule(undef, $nullableName, '::=',  [ [ [] , {} ] ]);
	    push(@{$rule->{rhs}}, $nullableName);
	}
    }
}

sub _pushG1 {
    my ($self, $rcp) = @_;
    
    $self->_addNullablesForParseEvents();

    foreach (@{$self->{rules}}) {
      my $content;
      if (! (defined($_->{rhs}))) {
        print STDERR "[WARN] Internal error: undefined RHS list for symbol $_->{lhs}\n";
        exit(EXIT_FAILURE);
      }
      push(@{$rcp}, $content = join(' ', "<$_->{lhs}>", $_->{rulesep}, @{$_->{rhs}} ? '<' . join('> <', @{$_->{rhs}}) . '>' : '', $_->{quantifier}));
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

  #
  # Grammar optimization has two steps:
  # - Reduce number of symbols
  # - Reduce number of lexemes
  #
  $self->{reQuantifiedSymbols} = {};
  my $replaced;
  do {
      $replaced = 0;
      foreach (0..$#{$self->{rules}}) {
	  my $irule = $_;
	  my $rule = $self->{rules}->[$irule];
	  my $lhs = $rule->{lhs};
	  next if ($#{$rule->{rhs}} != 0);
	  my $rhs = $rule->{rhs}->[0];
	  next if (! $self->{symbols}->{$rhs}->{terminal});
	  next if (! exists($self->{lexemesExact}->{$rhs}));  # Then it is an exclusion, always done by hand
	  #
	  # We search for rule that has a single terminal on its RHS and that has NO alternative
	  # ------------------------------------------------------------------------------------
	  my $quantifier = $rule->{quantifier};
	  if ($quantifier) {
	      my $many = sprintf('%s_%s', $rhs, 'many');
	      next if (exists($self->{reQuantifiedSymbols}->{$many}));
	  }

	  my $ok = 1;
	  foreach (0..$#{$self->{rules}}) {
	      my $irule2 = $_;
	      next if ($irule == $irule2);
	      my $rule2 = $self->{rules}->[$irule2];
	      my $lhs2 = $rule2->{lhs};
	      if ($lhs2 eq $lhs) {
		  $ok = 0;         # $rule has at least one alternative
		  last;
	      }
	      my $found = 0;
	      
	      foreach (@{$rule2->{rhs}}) {
		  my $rhs2 = $_;
		  my $quantifier2 = $rule2->{quantifier};
		  if ($rhs2 eq $rhs && $quantifier2 eq $quantifier) {
		      $found = 1;
		      last;
		  }
	      }
	      if ($found) {
		  $ok = 0;
		  last;
	      }
	  }

	  if ($ok) {
	      if (! $quantifier) {
		  my $content = $self->{symbols}->{$rhs}->{content};
		  print STDERR "[INFO] Replacing LHS of $content by $lhs\n";
		  $self->{symbols}->{$lhs} = $self->{symbols}->{$rhs};
		  $self->{symbols}->{$lhs}->{content} =~ s/$rhs/$lhs/;
		  print STDERR "[INFO] Deleting $rhs, replaced by $lhs\n";
		  delete($self->{symbols}->{$rhs});
		  $rule->{rhs}->[0] = $lhs;
		  $self->{lexemes}->{$lhs} = $self->{lexemes}->{$rhs};
		  delete($self->{lexemes}->{$rhs});
		  if (exists($self->{lexemesExact}->{$rhs})) {
		      $self->{lexemesExact}->{$lhs} = $self->{lexemesExact}->{$rhs};
		      delete($self->{lexemesExact}->{$rhs});
		  }
		  $replaced = 1;
	      } else {
		  print STDERR "[INFO] Optimizing $rhs$quantifier definition\n";
		  #
		  # There is no destruction or rule, just a change of type, and $self->_termFactorQuantifier() will take care of that
		  # We just have to force it to use our symbol name, and to remove its internal traking of quantified symbols
		  # We also have to do this only ONCE.
		  #
		  my $many = sprintf('%s_%s', $rhs, 'many');
		  $self->{reQuantifiedSymbols}->{$many} = 1;
		  delete($self->{quantifiedSymbols}->{$many});
		  if ($quantifier eq '*') {
		      my $any = sprintf('%s_%s', $rhs, 'any');
		      delete($self->{quantifiedSymbols}->{$any});
		  }
		  $self->_termFactorQuantifier($rhs, $quantifier, $lhs, 1);
		  $replaced = 1;
	      }
	      splice(@{$self->{rules}}, $irule, 1);
	      #
	      # Since we maintained a mapping giving $irule, we check the impact of its removal
	      #
	      foreach (keys %{$self->{nullablesForParseEvents}}) {
		  my $nullableName = $_;
		  if ($self->{nullablesForParseEvents}->{$nullableName} > $irule) {
		      $self->{nullablesForParseEvents}->{$nullableName}--;
		  }
	      }
	  }
      }
  } while ($replaced);

  #
  # Now loop on all rules again and apply the following optimization:
  # If a rule consist of a single exact lexeme with a quantifier, and if this exact lexeme is defined only once
  # in the whole grammar, then, instead on relying of Marpa's sequence, do ourself the loop when reading data.
  # this has the following big advantage:
  # - reduce the number of calls to Mara => reduce the number of earlemes, reduce the number of gems (i.e. lexemes).
  #
  # for example
  # XXX_any ::= XXX *                      YYY_many ::= YYY +
  # XXX     ::= [abc]                      YYY      ::= [def]
  #
  # is translated to something like:
  #
  # XXX_any ::= XXX                        YYY_many ::= YYY
  # XXX_any ::=
  # XXX     ::= [abc]+                     YYY      ::= [def]+
  #
  # where XXX and YYYY are NOT sequences from Marpa point of view: the internal implementation will do the loop itself.
  #
  # Disadvantage: none because the error reporting exactitude will not suffer.
  # Advantages: less earlemes, less lexemes, less everything, except more work on the most optimum part of the s/w: the reader
  #

  $self->{grammar} = join("\n", @rc) . "\n";

  return $self;
}

sub _rule {
  my ($self, $rulenumber, $symbol, $rulesep, $expressions, $quantifier, $symbolp) = @_;

  #
  # $expressions is [@concatenation]
  # Every $concatenation is [$exceptions,$constraints]
  # $exceptions is [@exception]
  # $constraints is [@constraints]
  # Every exception is a symbol

  #
  # Ignore rulesep "~"
  #
  $rulesep = '::=';

  foreach (@{$expressions}) {
    my $concatenation = $_;
    my ($exceptions, $constraints) = @{$concatenation};
    push(@{$self->{rules}}, {lhs => $symbol, rhs => $exceptions, rulesep => $rulesep, quantifier => $quantifier || '', constraints => $constraints});
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
  my ($self, $exceptions, $constraints) = @_;

  foreach (@{$constraints}) {
    my $constraint = $_;
    $self->{constraints}->{$constraint} //= {};
    foreach (@{$exceptions}) {
      $self->{constraints}->{$constraint}->{$_} = 1;
    }
  }

  return $exceptions;
}

sub _wfcConstraint {
  my ($self, undef, $name, $end) = @_;
  $name =~ s/[^\w]/_/g;
  return {'event_completed' => "$&_$name" };
}

sub _vcConstraint {
  my ($self, undef, $name, $end) = @_;
  $name =~ s/[^\w]/_/g;
  return {'step_token' => "$&_$name" };
}

sub _constraints {
  my ($self, @constraints) = @_;
  #
  # Every constraint is in the form {type => functionName}
  # We just merge everything in a single hash, respecting the order of appearance
  #
  my %hash = ();

  foreach (@constraints) {
    my ($type) = keys %{$_};
    my ($functionName) = values %{$_};
    $hash{$type} //= [];
    push(@{$hash{$type}}, $functionName);
    my $category = $type;
    $category = '';
    if ($type =~ /^event_/) {
	$category = 'parseEvent';
    } elsif ($type =~ /^step/) {
	$category = 'valueStep';
    }
    if ($category) {
	$self->{nbConstraintsByType}->{$category}++;
    }
  }
  return \%hash;
}

sub _adverbConstraint {
  my ($self, $adverb, undef, $name) = @_;
  $name =~ s/[^\w]/_/g;
  return {$adverb => "$&_$name" };
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
  my ($self, $chr, $forceHexa) = @_;
  if ($forceHexa || $chr =~ /[\s]/ || (! ($chr =~ /[[:ascii:]]/) || ($chr =~ /[[:cntrl:]]/))) {
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
  $self->_rule(undef, $symbol, '::=', $expressions);
  return $symbol;
}

sub _factor {
  my ($self, $printableValue, $type, $valueDetail, $quantifier, $name) = @_;

  if (! $name) {
      my @name = grep {$self->{lexemes}->{$_} eq $printableValue} keys %{$self->{lexemes}};
      if (! @name) {
	  $name = sprintf('_Lex%03d', 1 + (keys %{$self->{lexemes}}));
      } else {
	  $name = $name[0];
      }
  }

  if (! exists($self->{lexemesExact}->{$name})) {
    $quantifier ||= '';
      $self->{lexemesExact}->{$name} = {type => $type, value => $valueDetail, usage => 1, quantifier => $quantifier};
      $self->{lexemes}->{$name} = $printableValue;
  } else {
      $self->{lexemesExact}->{$name}->{usage}++;
  }

  return $name;
}

sub _factorStringDquote {
  my ($self, $dquote1, $stringDquote, $dquote2) = @_;
  #
  # _STRING_DQUOTE_UNIT    ~ [^"] | '\"'
  #
  return $self->_factor($stringDquote, $LEXEME_STRING, $stringDquote);
}

sub _factorStringSquote {
  my ($self, $squote1, $stringSquote, $squote2) = @_;
  #
  # _STRING_SQUOTE_UNIT    ~ [^'] | '\' [']
  #
  return $self->_factor($stringSquote, $LEXEME_STRING, $stringSquote);
}

sub _hex {
  my ($self, $hex) = @_;
  return $self->_factor($self->_printable($self->_char($hex), 1), $LEXEME_HEX, do {$hex =~ s/^#x//; chr(hex($hex));});
}

sub _termFactorQuantifier {
  my ($self, $factor, $quantifier, $forcedSymbol, $optimizationMode) = @_;

  my $symbol;
  if ($quantifier eq '*' || $quantifier eq '+') {
      $symbol = $forcedSymbol || sprintf('%s_%s', $factor, ($quantifier eq '*') ? 'any' : 'many');
      if (! exists($self->{quantifiedSymbols}->{$symbol})) {
	  $self->{quantifiedSymbols}->{$symbol}++;
	  if (exists($self->{lexemesExact}->{$factor}) &&
	      #
	      # Lexeme optimization is limited to ranges type: [...] or [^...] or #x's
	      #
	      ($self->{lexemesExact}->{$factor}->{type} == $LEXEME_RANGES       ||
               $self->{lexemesExact}->{$factor}->{type} == $LEXEME_CARET_RANGES ||
               $self->{lexemesExact}->{$factor}->{type} == $LEXEME_HEX
              )) {
	      if (! exists($self->{lexemesExact}->{"$factor$quantifier"})) {
                  #
                  # Okay, let's take care of one thing: Marpa does not like lexemes with a zero length.
                  # Therefore, if the quantifier is '*', we create a lexeme as if it was '+' and
                  # replace current factor by a nullable symbol
                  #
                  my $thisQuantifier = $quantifier;
                  my $thisSymbol = $symbol;
		  my $thisContent = "$self->{lexemes}->{$factor}$thisQuantifier";
                  if ($quantifier eq '*') {
                    $thisQuantifier = '+';
                    $thisSymbol = sprintf('%s_%s', $factor, 'many');
                  }
                  print STDERR "[INFO] Transformation to a lexeme: $thisSymbol ::= $factor$thisQuantifier\n";
                  $self->_factor($thisContent, $self->{lexemesExact}->{$factor}->{type}, $self->{lexemesExact}->{$factor}->{value}, $thisQuantifier, $thisSymbol);
		  if ($optimizationMode) {
		      #
		      # We are not in the lexer phase but in the optimization mode
		      #
		      $self->{symbols}->{$thisSymbol} = {terminal => 1, content => $thisContent};
		  }
                  if ($quantifier eq '*') {
                    my $newSymbol = $forcedSymbol || sprintf('_Gen%03d', 1 + (scalar @{$self->{rules}}));
                    print STDERR "[INFO] Using a nullable symbol for: $symbol ::= $factor$quantifier, i.e. $newSymbol ::= $thisSymbol; $newSymbol ::= ;\n";
                    $self->_rule(undef, $newSymbol, '::=', [ [ [ $thisSymbol ] , {} ] ]);
                    $self->_rule(undef, $newSymbol, '::=', [ [ [] , {} ] ]);
                    #
                    # For the return
                    #
		    my $content = "$thisSymbol || ;";
                    $symbol = $newSymbol;
		    if ($optimizationMode) {
			#
			# We are not in the lexer phase but in the optimization mode
			#
			$self->{symbols}->{$symbol} = {terminal => 0, content => $content};
		    }
                  }
		  if (--$self->{lexemesExact}->{$factor}->{usage} == 0) {
		      delete($self->{lexemes}->{$factor});
		  }
	      }
	  } else {
	      $self->_rule(undef, $symbol, '::=', [ [ [ $factor ] , {} ] ], $quantifier);
	  }
      }
  } elsif ($quantifier eq '?') {
      $symbol = sprintf('%s_maybe', $factor);
      if (! exists($self->{quantifiedSymbols}->{$symbol})) {
	  $self->{quantifiedSymbols}->{$symbol}++;
	  $self->_rule(undef, $symbol, '::=', [ [ [ "$factor" ] , {} ] ]);
	  $self->_rule(undef, $symbol, '::=', [ [ [] , {} ] ]);
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
	print STDERR "[INFO] Lexeme with exclusion: $name ::= $value\n";
    } else {
	$name = $name[0];
    }
    my $symbol = sprintf('_Gen%03d', 1 + (scalar @{$self->{rules}}));
    $self->_rule(undef, $symbol, '~', [ [ [ $name ], {} ] ]);
    #
    # hHis is ASSUMING that none of the original symbols already end with _any or _many.
    # If this would the case this is ASSUMING that xxx_any is a nullable, and xxx_many is not
    #
    if ($term1 =~ /_any/) {
	print STDERR "[INFO] Lexeme with exclusion: $name ::= $value appears to be nullable\n";
	$self->_rule(undef, $symbol, '~', [ [ [] , {} ] ]);
    } elsif ($term1 =~ /_many/) {
	print STDERR "[INFO] Lexeme with exclusion: $name ::= $value appears to be not nullable\n";
    } else {
	print STDERR "[WARN] Lexeme with exclusion: $name ::= $value : cannot determine its nullability - ASSUMING NOT\n";
    }
    # $self->_rule(undef, $symbol, '~', [ [ [ $term1 ] , {} ] ]);
    return $symbol;
}

###########################################################################
# package main                                                            #
###########################################################################

package main;
use Marpa::R2;
use Getopt::Long;
use File::Slurp;
use File::Spec;
use File::Basename qw/basename/;
use POSIX qw/EXIT_SUCCESS EXIT_FAILURE/;

our $DATA = ${__PACKAGE__->section_data('bnf')};

my $bnf = '';
my $output = '';
GetOptions('bnf=s' => \$bnf, 'output=s' => \$output)
  or die("Error in command line arguments\n");

if (! $bnf) {
  print STDERR "Usage: $^X $0 --bnf filename.bnf --output outputfilename.c\n";
  exit(EXIT_FAILURE);
}

if ($output) {
    open(STDOUT, '>', $output) || die "Cannot redirect STDOUT to $output";
}

my $grammar = Marpa::R2::Scanless::G->new( { source => \$DATA,
                                             action_object => 'Actions',
                                             bless_package => 'WRAPPER'});
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
my $value2 = undef;
while (defined($_ = $recce->value)) {
  ++$nbvalue;
  if ($nbvalue >= 2) {
      $value2 = ${$_};
      last;
  }
  $value = ${$_};
}
if ($nbvalue != 1) {
  print STDERR "Warning, \$nbvalue != 1\n";
  my $file1 = File::Spec->catfile(File::Spec->tmpdir, 'value1.txt');
  my $file2 = File::Spec->catfile(File::Spec->tmpdir, 'value2.txt');
  open(FILE1, '>', $file1) || die "Cannot open $file1, $!";
  open(FILE2, '>', $file2) || die "Cannot open $file2, $!";
  use Data::Dumper;
  print FILE1 Dumper($value);
  print FILE2 Dumper($value2);
  close(FILE1) || warn "Cannot close $file1, $!";
  close(FILE2) || warn "Cannot close $file2, $!";
  print STDERR "Please compare $file1 and $file2\n";
}
#
# These calls are to make sure:
# - this is a valid Marpa grammar
# - this is an unambiguous grammar
#
# use Data::Dumper;
# print STDERR Dumper($value);
my $withoutExclusions = $value->{grammar};
foreach (sort keys %{$value->{lexemesWithExclusion}}) {
    my ($key, $keyValue) = ($_, $value->{lexemesWithExclusion}->{$_});
    # print STDERR "[TEST] Bypassing $key ~ '$keyValue'\n";
    my $newKeyValue = $keyValue;
    $newKeyValue =~ /(\w+)/;
    $newKeyValue = $1;
    my $quotedKeyValue = quotemeta("'$keyValue'");
    $withoutExclusions =~ s/\s*~\s*$quotedKeyValue/ ::= $newKeyValue/g;
}
{
# print STDERR "[TEST] Marpa grammar: $withoutExclusions\n";
    my $grammar = eval {Marpa::R2::Scanless::G->new( { source => \$withoutExclusions } )};
    if ($@) {
	print STDERR "$@\n\n$withoutExclusions\n";
	exit(EXIT_FAILURE);
    }
    if (1) {
	foreach (grep {$_ ne 'bnf'} grep {$_ =~ /$namespace/i} __PACKAGE__->section_data_names) {
	    my $dataSection = $_;
	    my $testDatap = __PACKAGE__->section_data($dataSection);
	    $$testDatap =~ s/^\s*//;
	    $$testDatap =~ s/\s*$//;
	    my $recce = Marpa::R2::Scanless::R->new( { grammar => $grammar
                                                       # , trace_terminals => 1
						     } );
	    if (! eval { $recce->read($testDatap) }) {
		print STDERR "Test fail with data section $dataSection:\n$@\n";
		print STDERR "Progress:\n" . $recce->show_progress() . "\n";
		print STDERR "Terminals expected: @{$recce->terminals_expected()}\n";
		print STDERR "Grammar: $withoutExclusions\n";
		exit(EXIT_FAILURE);
	    }
	}
    }
}
#
# Generate a typedef containing all symbols, lexemes first, then the rules
#
my $c = generateC($value, $namespace);
print $c;
# print STDERR "Symbols: " . join(' ', sort keys %{$value->{symbols}} ) . "\n";
# print STDERR "\nOK\n";
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
#include "internal/grammar/xml_common.h"

INCLUDES

  $c .= generateTypedef(@_);

  if ($namespace =~ /^xml/) {
  $c .= <<DECLARATIONS;
static C_INLINE marpaWrapperBool_t _${namespace}_buildGrammarb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp);
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbolsb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp);
static C_INLINE marpaWrapperBool_t _${namespace}_readerb(void *readerCallbackDatavp, marpaWrapperBool_t *endOfInputbp);
DECLARATIONS
  } else {
  $c .= <<DECLARATIONS;
static C_INLINE marpaWrapperBool_t _${namespace}_buildGrammarb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp);
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbolsb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp_optionp);
DECLARATIONS
  }
  $c .= <<DECLARATIONS;
static C_INLINE marpaWrapperBool_t _${namespace}_isLexemeb(void *marpaWrapperSymbolOptionDatavp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _${namespace}_lexemeValueb(void *marpaWrapperSymbolOptionDatavp, int *lexemeValueip, int *lexemeLengthip);
static C_INLINE marpaWrapperBool_t _${namespace}_buildRulesb(${namespace}_t *${namespace}p);
static C_INLINE marpaWrapperBool_t _${namespace}_symbolToCharsb(void *marpaWrapperSymbolOptionDatavp, const char **symbolsp);
static C_INLINE marpaWrapperBool_t _${namespace}_ruleToCharsb(void *marpaWrapperRuleOptionDatavp, const char **rulesp);
DECLARATIONS
  foreach (sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}}) {
    $c .= "static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);\n";
  }

  $c .= generateNewp(@_);
  $c .= generateDestroyv(@_);
  $c .= generateBuildGrammarb(@_);
  $c .= generateParseEventsb(@_);
  $c .= generateBuildSymbolsb(@_);
  $c .= generateBuildRulesb(@_);
  $c .= generateNbTerminalsb(@_);
  $c .= generateLexemeValueb(@_);
  $c .= generateRecognizeb(@_);
  $c .= generateToCharsb(@_);
  $c .= generatePushLexemeb(@_);

  return $c;
}

sub ruleToChars {
    my ($rule) = @_;
    my $content = join(' ', "<$rule->{lhs}>", $rule->{rulesep}, @{$rule->{rhs}} ? '<' . join('> <', @{$rule->{rhs}}) . '>' : '', $rule->{quantifier});
    $content =~ s/\\/\\\\/g;
    $content =~ s/"/\\"/g;

    return "\"$content\"";
}

sub generateTypedef {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);

  my $typedef = '';

  $typedef .= "/* Symbols */\n";
  $typedef .= "typedef enum ${namespace}_symbol {\n";
  my $i;
  my $terminal_max = '';
  my @sortedTerminals = sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}};
  my @terminalsToChars = map {
      my $content = $value->{symbols}->{$_}->{content};
      $content =~ s/\\/\\\\/g;
      $content =~ s/"/\\"/g;
      "\"$content\"";
  } @sortedTerminals;
  my $iTerminalToSize = 0;
  my @terminalsToSize = map {
      my $size =
        exists($value->{lexemesExact}->{$_})
        ?
        (($value->{lexemesExact}->{$_}->{type} == $LEXEME_STRING) ? length($value->{lexemesExact}->{$_}->{value}) : 1)
        :
        0;
      sprintf('%3d, /* [Symbol No %3d] %s */', $size, $iTerminalToSize++, $value->{symbols}->{$_}->{content});
  } @sortedTerminals;
  my $iTerminalToFirstChar = 0;
  my @terminalsToFirstChar = map {
      my $firstchar =
        exists($value->{lexemesExact}->{$_})
        ?
        (
         ($value->{lexemesExact}->{$_}->{type} == $LEXEME_STRING)
         ?
         sprintf("0x%x", ord(substr($value->{lexemesExact}->{$_}->{value}, 0, 1)))
         :
         (
          ($value->{lexemesExact}->{$_}->{type} == $LEXEME_RANGES)
          ?
          (
           (($#{$value->{lexemesExact}->{$_}->{value}} == 0) && ($value->{lexemesExact}->{$_}->{value}->[0]->[0] eq $value->{lexemesExact}->{$_}->{value}->[0]->[1]))
           ?
           sprintf("0x%x", ord($value->{lexemesExact}->{$_}->{value}->[0]->[0]))
           :
           -1
          )
          :
          (
           ($value->{lexemesExact}->{$_}->{type} == $LEXEME_HEX)
           ?
           sprintf("0x%x", ord($value->{lexemesExact}->{$_}->{value}))
           :
           -1
          )
         )
        )
        :
        -1;
      sprintf('  %4s, /* [Symbol No %3d] %s */', $firstchar, $iTerminalToFirstChar++, $value->{symbols}->{$_}->{content});
  } @sortedTerminals;
  $i = 0;
  my @terminals = map {
    $terminal_max = "${namespace}_${_}";
    my $content = $value->{symbols}->{$_}->{content};
    my $fullname = "${namespace}_${_}";
    my $rc = ($i == 0) ?
	sprintf('  %-30s, /* [Symbol No %3d] %s */', "$fullname = 0", $i, $content)
	:
	sprintf('  %-30s, /* [Symbol No %3d] %s */', $fullname, $i, $content)
	;
    $i++;
    $rc;
  } @sortedTerminals;
  my @sortedNonTerminals = sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} != 1} keys %{$value->{symbols}};
  my @nonTerminalsToChars = map {
      my $content = $_;
      $content =~ s/\\/\\\\/g;
      $content =~ s/"/\\"/g;
      "\"$content\"";
  } @sortedNonTerminals;
  my @nonTerminalsToSize = map {
      sprintf('%3d, /* [Symbol No %3d] %s */', 0, $iTerminalToSize++, $_);
  } @sortedNonTerminals;
  my @nonTerminalsToFirstChar = map {
      sprintf('    -1, /* [Symbol No %3d] %s */', $iTerminalToFirstChar++, $_);
  } @sortedNonTerminals;
  my @g1 = map {
    sprintf('  %-30s, /* [Symbol No %3d] */', "${namespace}_${_}", $i++);
  } @sortedNonTerminals;

  $typedef .= "  /* Terminals */\n";
  $typedef .= join("\n", @terminals) . "\n";
  $typedef .= "  /* Non-terminals */\n";
  $typedef .= join("\n", @g1) . "\n";
  $typedef .= "  ${NAMESPACE}_SYMBOL_MAX /* $i ! */\n";
  $typedef .= "} ${namespace}_symbol_t;\n";
  $typedef .= "\n";
  $typedef .= "/* Symbols expected size, when possible */\n";
  $typedef .= "size_t ${namespace}_symbol_expectedSizeArrayp[${NAMESPACE}_SYMBOL_MAX] = {\n";
  my @allSizes = (@terminalsToSize, @nonTerminalsToSize);
  $typedef .= join("\n", @allSizes) . "\n";
  $typedef .= "};\n";
  $typedef .= "\n";
  $typedef .= "/* Symbols expected first char, when possible */\n";
  $typedef .= "signed int ${namespace}_symbol_expectedFirstCharArrayp[${NAMESPACE}_SYMBOL_MAX] = {\n";
  my @allFirstChars = (@terminalsToFirstChar, @nonTerminalsToFirstChar);
  $typedef .= join("\n", @allFirstChars) . "\n";
  $typedef .= "};\n";
  $typedef .= "\n";
  $typedef .= "#define ${NAMESPACE}_TERMINAL_MAX $terminal_max\n";
  $typedef .= "\n";
  $typedef .= "/* Rules */\n";
  $typedef .= "typedef enum ${namespace}_rule {\n";
  my $prevlhs = '';
  my $ilhs;
  $i = 0;
  $value->{ruleToEnum} = {};
  my @rulesToChars = map {ruleToChars($_)} @{$value->{rules}};
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
    $value->{ruleToEnum}->{ruleToChars($_)} = $enumed;
    my $rc = ($i == 0) ?
	sprintf('  %-30s, /* [Rule No %3d] %s */', "$enumed = 0", $i, $content)
	:
	sprintf('  %-30s, /* [Rule No %3d] %s */', $enumed, $i, $content)
	;
    $i++;
    $rc;
  } sort {$a->{lhs} cmp $b->{lhs}} @{$value->{rules}};
  $typedef .= join("\n", @rules) . "\n";
  $typedef .= "  ${NAMESPACE}_RULE_MAX /* $i ! */\n";
  $typedef .= "} ${namespace}_rule_t;\n";
  $typedef .= "\n";
  my $symbolsToChars =
      "  /* Terminals */\n  " .
      join(",\n  ", @terminalsToChars) .
      ",\n  /* Non-terminals */\n  " .
      join(",\n  ", @nonTerminalsToChars);
  my $rulesToChars = join(",\n  ", @rulesToChars);
  $typedef .=<<STRUCTURE;

/* Callback structure for symbols */
typedef struct ${namespace}_symbol_callback {
  ${namespace}_t *${namespace}p;
  ${namespace}_symbol_t ${namespace}_symboli;
} ${namespace}_symbol_callback_t;

/* Callback structure for rules */
typedef struct ${namespace}_rule_callback {
  ${namespace}_t *${namespace}p;
  ${namespace}_rule_t ${namespace}_rulei;
} ${namespace}_rule_callback_t;

/* Work structure */
struct $namespace {
  marpaWrapper_t          *marpaWrapperp;
  marpaWrapperSymbol_t   **marpaWrapperSymbolArrayp;
  size_t                   marpaWrapperSymbolArrayLengthi;
  marpaWrapperRule_t     **marpaWrapperRuleArrayp;
  size_t                   marpaWrapperRuleArrayLengthi;
  ${namespace}_symbol_callback_t *marpaWrapperSymbolCallbackArrayp;
  size_t                   marpaWrapperSymbolCallbackArrayLengthi;
  ${namespace}_rule_callback_t *marpaWrapperRuleCallbackArrayp;
  size_t                   marpaWrapperRuleCallbackArrayLengthi;
  streamIn_t              *streamInp;
  signed int               currenti;
  xml_common_option_t      xml_common_option;
  xml_common_t            *xml_commonp;
};

/* From symbol to string - indexed by ${namespace}_symbol_t */
static const char *symbolsToChars[] = {
  $symbolsToChars
};

/* From rule to string - indexed by ${namespace}_rule_t */
static const char *rulesToChars[] = {
  $rulesToChars
};

STRUCTURE

  return $typedef;
}

sub generateNewp {
  my ($value, $namespace) = @_;

  my $newp = '';

  if ($namespace =~ /^xml/) {

  $newp .= <<NEWPWITHOPTION;

/*******************/
/* ${namespace}_newp  */
/*******************/
${namespace}_t *${namespace}_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp) {
  ${namespace}_t           *${namespace}p;
  marpaWrapperOption_t marpaWrapperOption;

  /* Fill the defaults */
  if (marpaWrapperOptionp == NULL) {
    marpaWrapper_optionDefaultb(&marpaWrapperOption);
  } else {
    marpaWrapperOption = *marpaWrapperOptionp;
  }

  /* xml_common_optionp is internal and should always be setted */
  if (xml_common_optionp == NULL) {
    errno = EINVAL;
    return NULL;
  }

  ${namespace}p = malloc(sizeof(${namespace}_t));
  if (${namespace}p == NULL) {
    return NULL;
  }

  ${namespace}p->marpaWrapperp = NULL;
  ${namespace}p->marpaWrapperSymbolArrayp = NULL;
  ${namespace}p->marpaWrapperSymbolArrayLengthi = 0;
  ${namespace}p->marpaWrapperRuleArrayp = NULL;
  ${namespace}p->marpaWrapperRuleArrayLengthi = 0;
  ${namespace}p->marpaWrapperSymbolCallbackArrayp = NULL;
  ${namespace}p->marpaWrapperSymbolCallbackArrayLengthi = 0;
  ${namespace}p->marpaWrapperRuleCallbackArrayp = NULL;
  ${namespace}p->marpaWrapperRuleCallbackArrayLengthi = 0;
  ${namespace}p->streamInp = NULL;
  ${namespace}p->currenti = -1;
  ${namespace}p->xml_common_option = *xml_common_optionp;

  if (_${namespace}_buildGrammarb(${namespace}p, &marpaWrapperOption) == MARPAWRAPPER_BOOL_FALSE) {
    ${namespace}_destroyv(&${namespace}p);
  }

  return ${namespace}p;
}
NEWPWITHOPTION
  } else {

  $newp .= <<NEWPWITHOUTOPTION;

/*******************/
/* ${namespace}_newp  */
/*******************/
${namespace}_t *${namespace}_newp(marpaWrapperOption_t *marpaWrapperOptionp) {
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
    return NULL;
  }

  ${namespace}p->marpaWrapperp = NULL;
  ${namespace}p->marpaWrapperSymbolArrayp = NULL;
  ${namespace}p->marpaWrapperSymbolArrayLengthi = 0;
  ${namespace}p->marpaWrapperRuleArrayp = NULL;
  ${namespace}p->marpaWrapperRuleArrayLengthi = 0;
  ${namespace}p->marpaWrapperSymbolCallbackArrayp = NULL;
  ${namespace}p->marpaWrapperSymbolCallbackArrayLengthi = 0;
  ${namespace}p->marpaWrapperRuleCallbackArrayp = NULL;
  ${namespace}p->marpaWrapperRuleCallbackArrayLengthi = 0;

  if (_${namespace}_buildGrammarb(${namespace}p, &marpaWrapperOption) == MARPAWRAPPER_BOOL_FALSE) {
    ${namespace}_destroyv(&${namespace}p);
  }

  return ${namespace}p;
}
NEWPWITHOUTOPTION
}

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
      if (${namespace}p->marpaWrapperSymbolCallbackArrayp != NULL) {
	free(${namespace}p->marpaWrapperSymbolCallbackArrayp);
      }
      if (${namespace}p->marpaWrapperRuleCallbackArrayp != NULL) {
	free(${namespace}p->marpaWrapperRuleCallbackArrayp);
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

  my $buildGrammarb = '';
  if ($namespace =~ /^xml/) {

    $buildGrammarb .= <<BUILDGRAMMARBWITHOPTION;

/**************************/
/* _${namespace}_buildGrammarb */
/**************************/
static C_INLINE marpaWrapperBool_t _${namespace}_buildGrammarb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp) {

  ${namespace}p->marpaWrapperp = marpaWrapper_newp(marpaWrapperOptionp);
  if (${namespace}p->marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_${namespace}_buildSymbolsb(${namespace}p, marpaWrapperOptionp) == MARPAWRAPPER_BOOL_FALSE) {
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
BUILDGRAMMARBWITHOPTION
  } else {

    $buildGrammarb .= <<BUILDGRAMMARBWITHOUTOPTION;

/**************************/
/* _${namespace}_buildGrammarb */
/**************************/
static C_INLINE marpaWrapperBool_t _${namespace}_buildGrammarb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp) {

  ${namespace}p->marpaWrapperp = marpaWrapper_newp(marpaWrapperOptionp);
  if (${namespace}p->marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_${namespace}_buildSymbolsb(${namespace}p, marpaWrapperOptionp) == MARPAWRAPPER_BOOL_FALSE) {
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
BUILDGRAMMARBWITHOUTOPTION
  }
  return $buildGrammarb;
}

sub generateLexemeValueb {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);

  my $lexemeValueb = '';

  $lexemeValueb .= <<BUILDLEXEMEVALUEB;

/******************************/
/* _${namespace}_lexemeValueb */
/******************************/
static C_INLINE marpaWrapperBool_t _${namespace}_lexemeValueb(void *marpaWrapperSymbolOptionDatavp, int *lexemeValueip, int *lexemeLengthip) {
  ${namespace}_symbol_callback_t *${namespace}_symbol_callbackp = (${namespace}_symbol_callback_t *) marpaWrapperSymbolOptionDatavp;
  streamIn_t *streamInp = ${namespace}_symbol_callbackp->${namespace}p->streamInp;
  marpaWrapperBool_t rcb;

  /* xml_common_lexemeValueb will use streamInUtf8_extractFromMarkedb, which will extract text in the range [marked, current] */
  /* We used the user-marks to remember the end of the lexemes, i.e. a sort of floating "current" */

  /* Lexeme recognition started when at least one character was consumed, and all isLexemeb() routines are guaranteed to restore */
  /* stream to this position */
  /* This mean the lexeme is starting at previous character */

  /* Save current position */
  if (streamInUtf8_userMarkb(streamInp, ${NAMESPACE}_TERMINAL_MAX) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Mark previous position */
  if (streamInUtf8_markPreviousb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Set current position to the end of this lexeme */
  if (streamInUtf8_currentFromUserMarkedb(streamInp, ${namespace}_symbol_callbackp->${namespace}_symboli) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Get and store lexeme value in [marked, current] */
  rcb = xml_common_lexemeValueb(${namespace}_symbol_callbackp->${namespace}p->xml_commonp, ${namespace}_symbol_callbackp->${namespace}p->marpaWrapperp, streamInp, lexemeValueip, lexemeLengthip);

  /* We use the token-per-earleme model, i.e. xml_common_lexemeValueb will put a length of 1. So we leave the string */
  /* at the end of current lexeme */
  /* Restore current position */
  /*
  if (streamInUtf8_currentFromUserMarkedb(streamInp, ${NAMESPACE}_TERMINAL_MAX) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  */

  return rcb;
}

BUILDLEXEMEVALUEB

  return $lexemeValueb;
}

sub generateNbTerminalsb {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);

  my $lexemeValueb = '';

  $lexemeValueb .= <<NBTERMINALSB;

/**************************/
/* ${namespace}_nbTerminalsb */
/**************************/
marpaWrapperBool_t ${namespace}_nbTerminalsb(${namespace}_t *${namespace}p, size_t *nbTerminalslp) {
  if (${namespace}p == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (nbTerminalslp != NULL) {
    *nbTerminalslp = ${NAMESPACE}_TERMINAL_MAX;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

NBTERMINALSB

  return $lexemeValueb;
}

sub generateRecognizeb {
  my ($value, $namespace) = @_;

  my $recognizeb = '';

  $recognizeb .= <<BUILDREGOGNIZEB;

/*************************/
/* _${namespace}_readerb */
/*************************/
static C_INLINE marpaWrapperBool_t _${namespace}_readerb(void *readerCallbackDatavp, marpaWrapperBool_t *endOfInputbp) {
  ${namespace}_t *${namespace}p = (${namespace}_t *) readerCallbackDatavp;

  return xml_common_readerb(${namespace}p->xml_commonp, ${namespace}p->marpaWrapperp, ${namespace}p->streamInp, &(${namespace}p->currenti), endOfInputbp);
}

/**************************/
/* ${namespace}_recognizeb */
/**************************/
marpaWrapperBool_t ${namespace}_recognizeb(${namespace}_t *${namespace}p, streamIn_t *streamInp) {
  marpaWrapperBool_t rcb;
  marpaWrapperRecognizerOption_t marpaWrapperRecognizerOption;

  if (${namespace}p == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  marpaWrapperRecognizerOption.remainingDataIsOkb                                 = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperRecognizerOption.longestAcceptableTokenMatchb                       = MARPAWRAPPER_BOOL_TRUE;
  marpaWrapperRecognizerOption.longestAcceptableTokensShareTheSameValueAndLengthb = MARPAWRAPPER_BOOL_TRUE;
  marpaWrapperRecognizerOption.readerCallbackp                                    = &_${namespace}_readerb;
  marpaWrapperRecognizerOption.readerDatavp                                       = ${namespace}p;
  marpaWrapperRecognizerOption.isLexemebCallbackp                                 = &_${namespace}_isLexemeb;
  marpaWrapperRecognizerOption.lexemeValuebCallbackp                              = &_${namespace}_lexemeValueb;
  marpaWrapperRecognizerOption.ruleToCharsbCallbackp                              = &_${namespace}_ruleToCharsb;
  marpaWrapperRecognizerOption.symbolToCharsbCallbackp                            = &_${namespace}_symbolToCharsb;

  ${namespace}p->streamInp = streamInp;
  if (xml_common_optionDefaultb(&(${namespace}p->xml_common_option)) == marpaXml_false) {
    return MARPAWRAPPER_BOOL_FALSE;     
  }
  ${namespace}p->xml_common_option.marpaXmlLogp = marpaWrapper_marpaXmlLogp(${namespace}p->marpaWrapperp);

  ${namespace}p->xml_commonp = xml_common_new(&(${namespace}p->xml_common_option));
  if (${namespace}p->xml_commonp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;     
  }

  rcb = marpaWrapper_r_recognizeb(${namespace}p->marpaWrapperp, &marpaWrapperRecognizerOption);

  xml_common_free(&(${namespace}p->xml_commonp));

  return rcb;
}

BUILDREGOGNIZEB

  return $recognizeb;
}

sub generateToCharsb {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);

  my $toStringb = '';

  $toStringb .= <<TOSTRINGB;

/******************************/
/* _${namespace}_ruleToCharsb */
/******************************/
static C_INLINE marpaWrapperBool_t _${namespace}_ruleToCharsb(void *marpaWrapperRuleOptionDatavp, const char **rulesp) {
  ${namespace}_rule_callback_t *${namespace}_rule_callbackp = (${namespace}_rule_callback_t *) marpaWrapperRuleOptionDatavp;

  if (rulesp != NULL) {
    *rulesp = rulesToChars[${namespace}_rule_callbackp->${namespace}_rulei];
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/********************************/
/* _${namespace}_symbolToCharsb */
/********************************/
static C_INLINE marpaWrapperBool_t _${namespace}_symbolToCharsb(void *marpaWrapperSymbolOptionDatavp, const char **symbolsp) {
  ${namespace}_symbol_callback_t *${namespace}_symbol_callbackp = (${namespace}_symbol_callback_t *) marpaWrapperSymbolOptionDatavp;

  if (symbolsp != NULL) {
    *symbolsp = symbolsToChars[${namespace}_symbol_callbackp->${namespace}_symboli];
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

TOSTRINGB

  return $toStringb;
}

sub generateParseEventsb {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);

  my $buildSymbolEventsb = '';

  if (exists($value->{nbConstraintsByType}->{parseEvent}) && $value->{nbConstraintsByType}->{parseEvent}) {

      $buildSymbolEventsb .= <<BUILDSYMBOLEVENTS;

/**************************/
/* _${namespace}_parseEventsb */
/**************************/

static C_INLINE marpaWrapperBool_t _${namespace}_parseEventsb(void *datavp, marpaWrapper_t *marpaWrapperp, size_t nEventi, marpaWrapperEvent_t *marpaWrapperEventp) {
  marpaWrapperBool_t              rcb = MARPAWRAPPER_BOOL_TRUE;
  ${namespace}_t                 *${namespace}p;
  ${namespace}_symbol_t           symboli;
  size_t                          i;
#ifndef MARPAXML_NTRACE
  marpaXmlLog_t                  *marpaXmlLogp = marpaWrapper_marpaXmlLogp(marpaWrapperp);
#endif

  for (i = 0; i < nEventi; i++) {
    /* Per definition all parse events are based on nulling symbols. No need to check marpaWrapperEventp[i].eventTypei */
    marpaWrapperSymbol_t *marpaWrapperSymbolp = marpaWrapperEventp[i].marpaWrapperSymbolp;
    ${namespace}_symbol_callback_t *marpaWrapperSymbolCallbackp;

    if (marpaWrapperSymbol_datavp_getb(marpaWrapperSymbolp, (void **) &marpaWrapperSymbolCallbackp) == MARPAWRAPPER_BOOL_FALSE) {
      /* This should never happen, unless marpaWrapperSymbolp is NULL */
       continue;
    }

    /* No need to get more than once our namespace pointer */
    if (i == 0) {
      ${namespace}p = marpaWrapperSymbolCallbackp->${namespace}p;
    }

    switch (symboli = marpaWrapperSymbolCallbackp->${namespace}_symboli) {
BUILDSYMBOLEVENTS
        foreach (sort keys %{$value->{nullablesForParseEvents}}) {
	    my $nullableName = $_;
	    my $irule = $value->{nullablesForParseEvents}->{$nullableName};
	    my $iruleFormatted = sprintf("%3d", $irule);
	    my $ruleToChars = ruleToChars($value->{rules}->[$irule]);
	    $buildSymbolEventsb .= <<BUILDSYMBOLEVENTS;
      case ${namespace}_${nullableName}:
        /* [Rule No $iruleFormatted] $ruleToChars */
        MARPAXML_TRACEX("Event on symbol %s for rule \\\"%s\\\"\\n", symbolsToChars[${namespace}_${nullableName}], rulesToChars[$irule]);
BUILDSYMBOLEVENTS
          $buildSymbolEventsb .= <<BUILDSYMBOLEVENTS;
        break;
BUILDSYMBOLEVENTS
        }
        $buildSymbolEventsb .= <<BUILDSYMBOLEVENTS;
      default:
        break;
    }
BUILDSYMBOLEVENTS
      $buildSymbolEventsb .= <<BUILDSYMBOLEVENTS;
  }

  return rcb;
}
BUILDSYMBOLEVENTS

  }

  return $buildSymbolEventsb;
}

sub generateBuildSymbolsb {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);

  my $caseNullingSymbols = '';
  if (%{$value->{nullablesForParseEvents}}) {
      $caseNullingSymbols .= <<CASENULLINGSYMBOLS;
    /* Parse events are all based on nulling symbols */
    switch (i) {
CASENULLINGSYMBOLS
    foreach (sort keys %{$value->{nullablesForParseEvents}}) {
	my $nullableName = $_;
	$caseNullingSymbols .= <<CASENULLINGSYMBOLS;
      case ${namespace}_${nullableName}:
CASENULLINGSYMBOLS
    }
    $caseNullingSymbols .= <<CASENULLINGSYMBOLS;
        marpaWrapperSymbolOption.eventSeti = MARPAWRAPPER_EVENTTYPE_NULLED;
        break;
      default:
        break;
    }

CASENULLINGSYMBOLS
  }

  my $buildSymbolsb = '';

  if ($namespace =~ /^xml/) {

    $buildSymbolsb .= <<BUILDSYMBOLSBWITHOPTION;

/**************************/
/* _${namespace}_buildSymbolsb */
/**************************/
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbolsb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  ${namespace}p->marpaWrapperSymbolArrayp = malloc(${NAMESPACE}_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (${namespace}p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  ${namespace}p->marpaWrapperSymbolCallbackArrayp = malloc(${NAMESPACE}_SYMBOL_MAX * sizeof(${namespace}_symbol_callback_t));
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

    /* Opaque data associated to symbol will be a pointer to a ${namespace}_symbol_callback_t  */
    ${namespace}p->marpaWrapperSymbolCallbackArrayp[i].${namespace}p = ${namespace}p;
    ${namespace}p->marpaWrapperSymbolCallbackArrayp[i].${namespace}_symboli = i;
    marpaWrapperSymbolOption.datavp = (void *) &(${namespace}p->marpaWrapperSymbolCallbackArrayp[i]);

    /* Optional, but we can make ourself an explicit terminal */
    marpaWrapperSymbolOption.terminalb  = (i <= ${NAMESPACE}_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
    /* and give hints to the recognizer, that will sort expected terminals in the most optimal way */
    marpaWrapperSymbolOption.sizel      = ${namespace}_symbol_expectedSizeArrayp[i];
    marpaWrapperSymbolOption.firstChari = ${namespace}_symbol_expectedFirstCharArrayp[i];
$caseNullingSymbols
    /* Start rule ? */
    switch (${namespace}p->xml_common_option.xml_common_topi) {
      case XML_COMMON_TOP_DOCUMENT:
        marpaWrapperSymbolOption.startb = (i == ${namespace}_document) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
        break;
      case XML_COMMON_TOP_EXTPARSEDENT:
        marpaWrapperSymbolOption.startb = (i == ${namespace}_extParsedEnt) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
        break;
      case XML_COMMON_TOP_EXTSUBSET:
        marpaWrapperSymbolOption.startb = (i == ${namespace}_extSubset) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
        break;
      default:
        return MARPAWRAPPER_BOOL_FALSE;
        break;
      }

    /* Create the symbol */
    ${namespace}p->marpaWrapperSymbolArrayp[i] = marpaWrapper_g_addSymbolp(${namespace}p->marpaWrapperp, &marpaWrapperSymbolOption);
    if (${namespace}p->marpaWrapperSymbolArrayp[i] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

  }

  return MARPAWRAPPER_BOOL_TRUE;
}
BUILDSYMBOLSBWITHOPTION
  } else {

    $buildSymbolsb .= <<BUILDSYMBOLSBWITHOPTION;

/**************************/
/* _${namespace}_buildSymbolsb */
/**************************/
static C_INLINE marpaWrapperBool_t _${namespace}_buildSymbolsb(${namespace}_t *${namespace}p, marpaWrapperOption_t *marpaWrapperOptionp) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  ${namespace}p->marpaWrapperSymbolArrayp = malloc(${NAMESPACE}_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (${namespace}p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  ${namespace}p->marpaWrapperSymbolCallbackArrayp = malloc(${NAMESPACE}_SYMBOL_MAX * sizeof(${namespace}_symbol_callback_t));
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

    /* Opaque data associated to symbol will be a pointer to a ${namespace}_symbol_callback_t  */
    ${namespace}p->marpaWrapperSymbolCallbackArrayp[i].${namespace}p = ${namespace}p;
    ${namespace}p->marpaWrapperSymbolCallbackArrayp[i].${namespace}_symboli = i;
    marpaWrapperSymbolOption.datavp = (void *) &(${namespace}p->marpaWrapperSymbolCallbackArrayp[i]);

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= ${NAMESPACE}_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
    marpaWrapperSymbolOption.startb = (i == ${namespace}_start) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Create the symbol */
    ${namespace}p->marpaWrapperSymbolArrayp[i] = marpaWrapper_g_addSymbolp(${namespace}p->marpaWrapperp, &marpaWrapperSymbolOption);
    if (${namespace}p->marpaWrapperSymbolArrayp[i] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

  }

  return MARPAWRAPPER_BOOL_TRUE;
}
BUILDSYMBOLSBWITHOPTION
  }

  return $buildSymbolsb;
}

sub generatePushLexemeb {
  my ($value, $namespace) = @_;

  my $NAMESPACE = uc($namespace);

  my $pushLexemeb = '';
  #
  # Special inclusion for :discard
  #
  my $haveDiscardb = 0;
  my $funcDiscardb = "_${namespace}__discardb";
  {
      my $byHand = File::Spec->catfile('src', 'internal', 'grammar', $namespace, $funcDiscardb . '.c');
      if (-s $byHand) {
	  $pushLexemeb .= read_file($byHand);
	  print STDERR "[INFO] Inserted $byHand\n";
	  $haveDiscardb = 1;
      }
  }

  $pushLexemeb .= <<ISLEXEMEB_HEADER;

/*********************************************************************************/
/* _${namespace}_isLexemeb                                                       */
/* Note: MARPAWRAPPER_BOOL_TRUE and *sizelp == 0 means this is a discarded input */
/*********************************************************************************/

static C_INLINE marpaWrapperBool_t _${namespace}_isLexemeb(void *marpaWrapperSymbolOptionDatavp, size_t *sizelp) {
  marpaWrapperBool_t rcb;
  ${namespace}_symbol_callback_t *${namespace}_symbol_callbackp = (${namespace}_symbol_callback_t *) marpaWrapperSymbolOptionDatavp;
  ${namespace}_t    *${namespace}p = ${namespace}_symbol_callbackp->${namespace}p;
  signed int         currenti = ${namespace}p->currenti;
  streamIn_t        *streamInp = ${namespace}p->streamInp;
  ${namespace}_symbol_t ${namespace}_symboli = ${namespace}_symbol_callbackp->${namespace}_symboli;

  switch (${namespace}_symboli) {
ISLEXEMEB_HEADER
  foreach (sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}}) {
      $pushLexemeb .= <<ISLEXEMEB;
    case ${namespace}_${_}:
      rcb = _${namespace}_${_}b(${namespace}p, currenti, streamInp, sizelp);
      break;
ISLEXEMEB
    }
  if ($haveDiscardb) {
      $pushLexemeb .= <<ISLEXEMEB_TRAILER;
    default:
      /* Special case: if return is MARPAWRAPPER_BOOL_TRUE and *sizelp is 0, then this is a :discard */
      /* Nevertheless streamInp will have have progressed */
      rcb = $funcDiscardb(${namespace}p, currenti, streamInp, sizelp);
      break;
  }

#ifndef MARPAXML_NTRACE
  {
      marpaXmlLog_t *marpaXmlLogp = marpaWrapper_marpaXmlLogp(${namespace}p->marpaWrapperp);
      if (rcb == MARPAWRAPPER_BOOL_TRUE) {
	  MARPAXML_TRACEX("Accepted symbol No %4d: %s, length %lld", ${namespace}_symboli, symbolsToChars[${namespace}_symboli], (long long) *sizelp);
      } else {
	  MARPAXML_TRACEX("Rejected symbol No %4d: %s", ${namespace}_symboli, symbolsToChars[${namespace}_symboli]);
      }
  }
#endif

  return rcb;
}
ISLEXEMEB_TRAILER
  } else {
      $pushLexemeb .= <<ISLEXEMEB_TRAILER;
    default:
      rcb = MARPAWRAPPER_BOOL_FALSE;
      break;
  }

  return rcb;
}
ISLEXEMEB_TRAILER
  }

  foreach (sort {$a cmp $b} grep {$value->{symbols}->{$_}->{terminal} == 1} keys %{$value->{symbols}}) {
    my $lexeme = $_;
    if (! exists($value->{lexemesExact}->{$lexeme}->{type})) {
      my $func = "_${namespace}_${_}b";
      my $byHand = File::Spec->catfile('src', 'internal', 'grammar', $namespace, $func . '.c');
      if (-s $byHand) {
        $pushLexemeb .= read_file($byHand);
	print STDERR "[INFO] Inserted $byHand\n";
      } else {
	print STDERR "[WARN] Routine $func to be writen by hand\n";
        $pushLexemeb .= <<ISLEXEMEB;

/************************************************
  $value->{symbols}->{$lexeme}->{content}
 ************************************************/
static C_INLINE marpaWrapperBool_t $func(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

ISLEXEMEB
    }
    } else {
      if ($value->{lexemesExact}->{$lexeme}->{type} == $LEXEME_RANGES ||
	  $value->{lexemesExact}->{$lexeme}->{type} == $LEXEME_CARET_RANGES) {

        # -----------------------#
        # [...] and [^...] forms #
        # -----------------------#
        my $rcIfMatch = ($value->{lexemesExact}->{$lexeme}->{type} == $LEXEME_RANGES) ? 'MARPAWRAPPER_BOOL_TRUE' : 'MARPAWRAPPER_BOOL_FALSE';
        my $rcIfQuantifiedMatch = ($value->{lexemesExact}->{$lexeme}->{type} == $LEXEME_RANGES) ? '' : 'break;';
        my $rcIfCaretMatch = ($value->{lexemesExact}->{$lexeme}->{type} == $LEXEME_RANGES) ? 'MARPAWRAPPER_BOOL_FALSE' : 'MARPAWRAPPER_BOOL_TRUE';
        my $rcIfQuantifiedCaretMatch = ($value->{lexemesExact}->{$lexeme}->{type} == $LEXEME_RANGES) ? 'break;' : '';
        my $sizelpMatch = ($rcIfMatch eq 'MARPAWRAPPER_BOOL_TRUE') ? "*sizelp = 1;\n    " : '    ';
        my $sizelQuantifierMatch = ($rcIfMatch eq 'MARPAWRAPPER_BOOL_TRUE') ? "sizel++;\n    " : '    ';
        my $sizelpCaretMatch = ($rcIfCaretMatch eq 'MARPAWRAPPER_BOOL_TRUE') ? "*sizelp = 1;\n    " : '    ';
        my $sizelQuantifierCaretMatch = ($rcIfCaretMatch eq 'MARPAWRAPPER_BOOL_TRUE') ? "sizel++;\n    " : '    ';

        my @wanted = ();
        my $n = scalar(@{$value->{lexemesExact}->{$lexeme}->{value}});
        foreach (@{$value->{lexemesExact}->{$lexeme}->{value}}) {
          my @range = @{$_};
	  if ($range[0] ne $range[1]) {
	      push(@wanted, sprintf('%scurrenti >= 0x%x && currenti <= 0x%x%s /* [%s-%s] */', ($n > 1 ? '(' : ''), ord($range[0]), ord($range[1]), ($n > 1 ? ')' : ''), _chprint($range[0]), _chprint($range[1])));
	  } else {
	      push(@wanted, sprintf('%scurrenti == 0x%x%s /* %s */', ($n > 1 ? '(' : ''), ord($range[0]), ($n > 1 ? ')' : ''), _chprint($range[0])));
	  }
        }
	my $wanted = join(" ||\n      ", @wanted);
        if ($value->{lexemesExact}->{$lexeme}->{quantifier}) {
          $pushLexemeb .= <<ISLEXEMEB;

/************************************************
  $value->{symbols}->{$lexeme}->{content}
 ************************************************/
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t sizel = 0;
  streamInBool_t streamInBoolb;

  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  do {
    if ($wanted) {
      ${sizelQuantifierMatch}${rcIfQuantifiedMatch}
    } else {
      ${sizelQuantifierCaretMatch}${rcIfQuantifiedCaretMatch}
    }
  } while ((streamInBoolb = streamInUtf8_nexti(streamInp, &currenti)) == STREAMIN_BOOL_TRUE);

  if (sizel > 0) {
    if (((streamInBoolb == STREAMIN_BOOL_TRUE) ? streamInUtf8_userMarkPreviousb(streamInp, ${namespace}_${_}) : streamInUtf8_userMarkb(streamInp, ${namespace}_${_})) == STREAMIN_BOOL_FALSE) {
      streamInUtf8_currentFromMarkedb(streamInp); /* Cross the fingers */
      return MARPAWRAPPER_BOOL_FALSE;
    } else {
      if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) { /* Oups */
        return MARPAWRAPPER_BOOL_FALSE;
      } else {
        *sizelp = sizel;
        return MARPAWRAPPER_BOOL_TRUE;
      }
    }
  } else {
    streamInUtf8_currentFromMarkedb(streamInp); /* Cross the fingers */
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
ISLEXEMEB
        } else {
	    $pushLexemeb .= <<ISLEXEMEB;

/************************************************
  $value->{symbols}->{$lexeme}->{content}
 ************************************************/
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  marpaWrapperBool_t rcb;
  if ($wanted) {
    ${sizelpMatch}rcb = $rcIfMatch;
  } else {
    ${sizelpCaretMatch}rcb = $rcIfCaretMatch;
  }
  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    if (streamInUtf8_userMarkb(streamInp, ${namespace}_${_}) == STREAMIN_BOOL_FALSE) {
      rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }
  return rcb;
}
ISLEXEMEB
    }
      } elsif ($value->{lexemesExact}->{$lexeme}->{type} == $LEXEME_HEX) {

        # --------#
        # #x form #
        # --------#

        my $wanted = sprintf('0x%x /* %s */', ord($value->{lexemesExact}->{$lexeme}->{value}), _chprint($value->{lexemesExact}->{$lexeme}->{value}));
        if ($value->{lexemesExact}->{$lexeme}->{quantifier}) {
          $pushLexemeb .= <<ISLEXEMEB;

/************************************************
  $value->{symbols}->{$lexeme}->{content}
 ************************************************/
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t sizel = 0;
  streamInBool_t streamInBoolb;

  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  do {
    if (currenti == $wanted) {
      sizel++;
    } else {
      break;
    }
  } while (streamInUtf8_nexti(streamInp, &currenti) == STREAMIN_BOOL_TRUE);

  if (sizel > 0) {
    if (((streamInBoolb == STREAMIN_BOOL_TRUE) ? streamInUtf8_userMarkPreviousb(streamInp, ${namespace}_${_}) : streamInUtf8_userMarkb(streamInp, ${namespace}_${_})) == STREAMIN_BOOL_FALSE) {
      streamInUtf8_currentFromMarkedb(streamInp); /* Cross the fingers */
      return MARPAWRAPPER_BOOL_FALSE;
    } else {
      if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) { /* Oups */
        return MARPAWRAPPER_BOOL_FALSE;
      } else {
        *sizelp = sizel;
        return MARPAWRAPPER_BOOL_TRUE;
      }
    }
  } else {
    streamInUtf8_currentFromMarkedb(streamInp); /* Cross the fingers */
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
ISLEXEMEB
        } else {
          $pushLexemeb .= <<ISLEXEMEB;

/************************************************
  $value->{symbols}->{$lexeme}->{content}
 ************************************************/
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == $wanted) {
    if (streamInUtf8_userMarkb(streamInp, ${namespace}_${_}) == STREAMIN_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    } else {
      *sizelp = 1;
      return MARPAWRAPPER_BOOL_TRUE;
    }
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
ISLEXEMEB
        }
      } elsif ($value->{lexemesExact}->{$lexeme}->{type} == $LEXEME_STRING) {
        my @wanted = map {sprintf("0x%x /* %s */", ord($_), _chprint($_))} split('', $value->{lexemesExact}->{$lexeme}->{value});
        my $wanted = join(",\n    ", @wanted);
	my $length = length($value->{lexemesExact}->{$lexeme}->{value});
        if ($length == 1) {
          $pushLexemeb .= <<ISLEXEMEB;

/************************************************
  $value->{symbols}->{$lexeme}->{content}
 ************************************************/
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == $wanted) {
    if (streamInUtf8_userMarkb(streamInp, ${namespace}_${_}) == STREAMIN_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    } else {
      *sizelp = 1;
      return MARPAWRAPPER_BOOL_TRUE;
    }
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
ISLEXEMEB
        } else {
          $pushLexemeb .= <<ISLEXEMEB;

/************************************************
  $value->{symbols}->{$lexeme}->{content}
 ************************************************/
static C_INLINE marpaWrapperBool_t _${namespace}_${_}b(${namespace}_t *${namespace}p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[$length] = {
    $wanted
  };
  signed int           got;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_TRUE;

  if (currenti != wanted[0]) {
    /* No need to navigate in the stream if current character is already not ok */
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    while (++i < $length) {
      if (streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    }
    if (streamInUtf8_userMarkb(streamInp, ${namespace}_${_}) == STREAMIN_BOOL_FALSE) {
      rcb = MARPAWRAPPER_BOOL_FALSE;
    } else {
      if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
      }
    }
  } else {
    rcb = MARPAWRAPPER_BOOL_FALSE;
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
  ${namespace}p->marpaWrapperRuleCallbackArrayp = malloc(${NAMESPACE}_RULE_MAX * sizeof(${namespace}_rule_callback_t));
  if (${namespace}p->marpaWrapperRuleCallbackArrayp == NULL) {
    free(${namespace}p->marpaWrapperRuleArrayp);
    return MARPAWRAPPER_BOOL_FALSE;
  }
  ${namespace}p->marpaWrapperRuleArrayLengthi = ${NAMESPACE}_RULE_MAX;
  ${namespace}p->marpaWrapperRuleCallbackArrayLengthi = ${NAMESPACE}_RULE_MAX;

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
    /* Opaque data associated to rule will be a pointer to a ${namespace}_rule_callback_t  */
    ${namespace}p->marpaWrapperRuleCallbackArrayp[$enumed].${namespace}p = ${namespace}p;
    ${namespace}p->marpaWrapperRuleCallbackArrayp[$enumed].${namespace}_rulei = $enumed;
    marpaWrapperRuleOption.datavp = (void *) &(${namespace}p->marpaWrapperRuleCallbackArrayp[$enumed]);

    marpaWrapperRuleOption.lhsSymbolp = ${namespace}p->marpaWrapperSymbolArrayp[${namespace}_$rule->{lhs}];
BUILDRULESB_INNER1
    if ($nbRhs > 0) {
      $buildRulesb .= <<BUILDRULESB_INNER2;
    marpaWrapperRuleOption.nRhsSymboli = $nbRhs;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
BUILDRULESB_INNER2
    }
    if ($rule->{quantifier} eq '*') {
      $buildRulesb .= <<QUANTIFIER_STAR;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
QUANTIFIER_STAR
    } elsif ($rule->{quantifier} eq '+') {
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
# The XML Spec is giving [WFC:] and [VC:] constraints.
# They will apply to the CURRENT rule.
# Take care: if the LHS contains alternatives, and you want the constraints to be applied on all of them, either enclose all alternative with a (),
# or repeat the conditions for every altenative.
#
# Content of [WFC] is translated systematically to a call to a function of the same name, using a MARPA_EVENT_SYMBOL_COMPLETED event during lexing phase.
# Content of [VC]  is translated systematically to a call to a function of the same name, using a MARPA_STEP_RULE event during value phase.
#
# I.e. It is important that WFC's are placed exactly on every symbol they should be applied to, and that VC's are placed on every rule affected.
#
# The data associated with any lexeme, with no exception is always a marpaXml_String_t pointer. This is done during recognition phase, using calls to:
# marpaWrapper_r_alternativeb() and marpaWrapper_r_completeb().
#
# In addition explicit marpa oriented constraints are possible, with the following averbs:
# * Lexing phase
# event_predicted => functionName
# event_nulled    => functionName
# event_completed => functionName
# * Value phase
# step_rule       => functionName
# step_token      => functionName
# step_nulling    => functionName
#
# There can be as many constraints as you want: they will be called in sequence, respecting their order of appearance in the BNF.
# Any constraint that return MARPAWRAPPER_BOOL_FALSE will stop the processing.
#
# If any function is to be called, it is expected that the caller provides an 'actions.c' source code containing functions prototyped like this:
# static C_INLINE marpaWrapperBool_t _${namespace}_<content>(${namespace}_callback_t *${namespace}_callbackp, int subscribedEventi, marpaWrapperEvent_t *marpaWrapperEventp)
# where content is the function name, with every non-alphabetic character replaced by a '_'.
#
# It is guaranteed that ${namespace}_callbackp is a valid pointer whose content is:
# ${namespace}_callbackp->${namespace}p : pointer to the grammar context
# ${namespace}_callbackp->${namespace}_symboli : enum of the symbol
#
# It is also guaranteed that marpaWrapperEventp is a valid pointer to an array of size subscribedEventi, with content:
# marpaWrapperEventp[].eventType = type of event (MARPAWRAPPER_EVENTTYPE_COMPLETED, MARPAWRAPPER_EVENTTYPE_NULLED, MARPAWRAPPER_EVENTTYPE_PREDICTED)
# marpaWrapperEventp[].marpaWrapperSymbolp = pointer to a marpaWrapperSymbol.
#
# Note: opaque data associated with a marpaWrapperSymbol can be obtained using marpaWrapperSymbol_datavp_get(marpaWrapperSymbol_t *marpaWrapperSymbolp, void **datavpp),
# and if successful, *datavp can be typecasted to a (${namespace}_callback_t *${namespace}_callbackp).
#
# For example, for the xml_1_0 namespace, [VC: Proper Declaration/PE Nesting] would translate to:
# static C_INLINE marpaWrapperBool_t _xml_1_0_Proper_Declaration_PE_Nesting(xml_1_0_callback_t *xml_1_0_callbackp, int subscribedEventi, marpaWrapperEvent_t *marpaWrapperEventp)
#
#
rules          ::= rule+                                                action => _rules
rule           ::= RULENUMBER SYMBOL RULESEP expressions                action => _rule
expressions    ::= concatenation+ separator => PIPE                     action => [values]
concatenation  ::= exceptions constraints                               action => [values]
exceptions     ::= exception+                                           action => [values]
exception      ::= term
               |   term MINUS term                                      action => _exceptionTermMinusTerm
term           ::= factor
               |   factor QUANTIFIER                                    action => _termFactorQuantifier
hex            ::= HEX                                                  action => _hex
factor         ::= hex
               |   LBRACKET       ranges RBRACKET                       action => _factorRange
               |   LBRACKET CARET ranges RBRACKET                       action => _factorCaretRange
               |   DQUOTE STRINGDQUOTE DQUOTE                           action => _factorStringDquote
               |   SQUOTE STRINGSQUOTE SQUOTE                           action => _factorStringSquote
               |   LPAREN expressions RPAREN                            action => _factorExpressions
               |   SYMBOL
ranges         ::= range+                                               action => _ranges
range          ::= CHAR                                                 action => _range1
               |   CHAR MINUS CHAR                                      action => _range2
constraint     ::= WfcConstraint
               |   VcConstraint
               |   adverbConstraint
constraints    ::= constraint*                                          action => _constraints
WfcConstraint  ::= WFCSTART CONSTRAINTBODY RBRACKET                     action => _wfcConstraint
VcConstraint   ::= VCSTART CONSTRAINTBODY RBRACKET                      action => _vcConstraint
adverbConstraint ::= ADVERB '=>' ADVERBBODY                             action => _adverbConstraint
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
:lexeme ~ WFCSTART priority => 1
WFCSTART      ~ '[wfc:':i
:lexeme ~ VCSTART priority => 1
VCSTART       ~ '[vc:':i
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
ADVERB                 ~ 'event_predicted'
                       | 'event_nulled'
                       | 'event_completed'
                       | 'step_rule'
                       | 'step_token'
                       | 'step_nulling'
ADVERBBODY             ~ [\w]+
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
__[ xml_1_0_test01 ]__
<HTML>
</HTML>
__[ xml_1_0_test02 ]__
<dictionary>
  <!-- see /usr/share/gtkmathview*xml for examples -->
</dictionary>
__[ xml_1_1_test01 ]__
<?xml version="1.1" standalone="no" ?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN"
  "http://www.w3.org/TR/REC-html40/loose.dtd">
<HTML>
<HEAD>
<TITLE>A typical HTML file</TITLE>
</HEAD>
<BODY>
  This is the typical structure of an HTML file. It follows
  the notation of the HTML 4.0 specification, including tags
  that have been deprecated (hence the "transitional" label).
</BODY>
</HTML>
__[ qname_1_0_test01 ]__
prefix:localpart
__[ qname_1_1_test01 ]__
prefix:localpart
ary>
  <!-- see /usr/share/gtkmathview*xml for examples -->
</dictionary>
__[ xml_1_1_test01 ]__
<?xml version="1.1" standalone="no" ?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN"
  "http://www.w3.org/TR/REC-html40/loose.dtd">
<HTML>
<HEAD>
<TITLE>A typical HTML file</TITLE>
</HEAD>
<BODY>
  This is the typical structure of an HTML file. It follows
  the notation of the HTML 4.0 specification, including tags
  that have been deprecated (hence the "transitional" label).
</BODY>
</HTML>
__[ qname_1_0_test01 ]__
prefix:localpart
__[ qname_1_1_test01 ]__
prefix:localpart
