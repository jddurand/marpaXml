#!env perl
use strict;
use diagnostics;
use POSIX qw/EXIT_SUCCESS/;
use File::Copy;
use File::Path;
use ExtUtils::Command qw/rm_rf cp/;
use File::Spec::Functions;

my ($MARPA_VERSION, $CC_BASENAME, $CMAKE_C_FLAGS, $CMAKE_C_OUTPUT_EXTENSION) = @ARGV;

my $dir = "Marpa-R2-${MARPA_VERSION}";
my $dir_dist = catdir($dir, 'libmarpa_dist');

rmtree($dir);
system($^X, catfile('tools', 'extract.pl'), catfile('tar', "$dir.tar.gz"));
copy(catfile($dir, 'libmarpa_dist', 'LIB_VERSION'), catfile($dir, 'libmarpa_dist', 'VERSION'));
chdir($dir_dist) || die "Cannot chdir to $dir_dist, $!";
system($^X, catfile('win32', 'do_config_h.pl'), '--use_perl_autoconf', '--cc', $CC_BASENAME, '--ccflags', $CMAKE_C_FLAGS, '--obj_ext', $CMAKE_C_OUTPUT_EXTENSION);

exit(EXIT_SUCCESS);
