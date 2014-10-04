#!env perl
use strict;
use diagnostics;
use POSIX qw/EXIT_SUCCESS EXIT_FAILURE/;
use File::Copy;
use File::Path;
use ExtUtils::Command qw/rm_rf cp/;
use File::Spec::Functions;

my ($MARPA_VERSION, $CC_BASENAME, $CMAKE_C_FLAGS, $CMAKE_C_OUTPUT_EXTENSION) = @ARGV;

my $dir = "Marpa-R2-${MARPA_VERSION}";
my @dir_dist = (
    catdir($dir, 'core', 'read_only'),
    catdir($dir, 'engine', 'read_only')
    );

rmtree($dir);
system($^X, catfile('tools', 'extract.pl'), catfile('tar', "$dir.tar.gz"));
#
# Specific to Marpa version <= 2.085_006
#
my $dir_dist = (grep {-d $_} @dir_dist)[0];
if (! $dir_dist) {
    print STDERR "Cannot find libmarpa directory (tried @dir_dist)\n";
    exit(EXIT_FAILURE);
}
my $LIB_VERSION = catfile($dir_dist, 'LIB_VERSION');
my $VERSION = catfile($dir_dist, 'VERSION');
if (-e $LIB_VERSION && ! -e $VERSION) {
    # copy($LIB_VERSION, $VERSION);
}
chdir($dir_dist) || die "Cannot chdir to $dir_dist, $!";
print STDERR "\n";
print STDERR "*** Configuring in $dir_dist\n";
print STDERR "\n";
system($^X, catfile('win32', 'do_config_h.pl'), '--use_perl_autoconf', '--cc', $CC_BASENAME, '--ccflags', $CMAKE_C_FLAGS, '--obj_ext', $CMAKE_C_OUTPUT_EXTENSION);

exit(EXIT_SUCCESS);
