#!env perl
use strict;
use diagnostics;
use Archive::Extract;
use POSIX qw/EXIT_SUCCESS/;

autoflush STDOUT 1;

my $targz = shift;

print STDERR "\n";
print STDERR "*** Extracting $targz\n";
print STDERR "\n";

my $ae = Archive::Extract->new(archive => $targz);
my $ok = $ae->extract() || die "Failed to extract $targz, $ae->error";
my $outdir = $ae->extract_path();

exit(EXIT_SUCCESS);
