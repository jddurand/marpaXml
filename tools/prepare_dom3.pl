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
    push(@c, $match);
}
my $h = "#define STRINGLITERAL_DDL_NBTABLES " . scalar(@c) . "\n";
$h .= "static const char *STRINGLITERAL_DDL[STRINGLITERAL_DDL_NBTABLES] = {\n" . join(",\n", @c) . "};\n";
$h .= "static const char *STRINGLITERAL_DDL_NAME[STRINGLITERAL_DDL_NBTABLES] = {\n\"" . join("\", \"", @name) . "\"};\n";

open(H, '>', $dom3h) || die "Cannot open $dom3h, $!";
print H $h;
close(H) || warn "Cannot close $dom3h, $!";

exit(EXIT_SUCCESS);
