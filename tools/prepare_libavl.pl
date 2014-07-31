#!env perl
use strict;
use diagnostics;
use POSIX qw/EXIT_SUCCESS/;
use File::Copy;
use File::Path;
use ExtUtils::Command qw/rm_rf cp/;
use File::Spec::Functions;

my ($AVL_VERSION) = @ARGV;

my $dir = "avl-${AVL_VERSION}";
my $dir_dist = $dir;

rmtree($dir);
system($^X, catfile('tools', 'extract.pl'), catfile('tar', "$dir.tar.gz"));

exit(EXIT_SUCCESS);
