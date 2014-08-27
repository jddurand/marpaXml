#!env perl
use strict;
use diagnostics;
use File::Spec;
use Regexp::Common qw/comment/;
use POSIX qw/EXIT_SUCCESS/;

my ($dom3sql, $dom3h) = @ARGV;

open(SQL, '<', $dom3sql) || die "Cannot open $dom3sql, $!";
my $sql = do {local $/; <SQL>};
close(SQL) || warn "Cannot close $dom3sql, $!";

$sql =~ s/\r\n/\n/g;
$sql =~ s/$RE{comment}{'C++'}//g;

my @c = ();
my @name = ();
my @index = ();
#
# First the tables
#
pos($sql) = undef;
while ($sql =~ m/\bCREATE\s+TABLE\s+(\[(\w+)\]\s*\([^;]+\)\s*;)/sxmg) {
    push(@name, $2);
    my $match = "CREATE TABLE IF NOT EXISTS $1";
    #
    # Well, it appears that the generated SQL says twice PRIMARY KEY on the same column and SQLite does not like it
    # Our model is using [id] everywhere, so we know what we are doing and can safely remove the redundant PRIMARY KEY
    #
    $match =~ s/,\s*\bPRIMARY\s+KEY\s*\(\s*\[\s*id\s*\]\s*\)//;
    $match =~ s/^/"/sxmg;
    $match =~ s/$/\\n"/sxmg;
    #
    ## Well, except the very last one
    #
    #
    # Remove all '[' and ']'
    #
    $match =~ s/[\[\]]//g;
    $match =~ s/\\n"$/"/;
    push(@c, $match);
}
#
# Then the views
#
pos($sql) = undef;
while ($sql =~ m/\bCREATE\s+VIEW\s+(\[(\w+)\]\s*[^;]+\s*;)/sxmg) {
    push(@name, $2);
    my $match = "CREATE VIEW IF NOT EXISTS $1";
    $match =~ s/^/"/sxmg;
    $match =~ s/$/\\n"/sxmg;
    $match =~ s/\\n"$/"/;
    $match =~ s/[\[\]]//g;
    push(@c, $match);
}
#
# Then the indexes
#
pos($sql) = undef;
while ($sql =~ m/\b(CREATE\s+(?:UNIQUE\s+)?INDEX)\s+([^;]+;)/sxmg) {
    my $match = "$1 IF NOT EXISTS $2";
    $match =~ s/^/"/sxmg;
    $match =~ s/$/\\n"/sxmg;
    $match =~ s/\\n"$/"/;
    $match =~ s/[\[\]]//g;
    push(@c, $match);
}
my $h = "#define _DDL_NBSTATEMENT " . scalar(@c) . "\n";
$h .= "static const char *_DDL_STATEMENT[_DDL_NBSTATEMENT] = {\n" . join(",\n", @c) . "};\n";

open(H, '>', $dom3h) || die "Cannot open $dom3h, $!";
print H $h;
close(H) || warn "Cannot close $dom3h, $!";

exit(EXIT_SUCCESS);
