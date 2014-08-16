#!env perl
use strict;
use diagnostics;
use POSIX qw/EXIT_SUCCESS/;
use File::Copy;
use File::Path;
use ExtUtils::Command qw/rm_rf cp/;
use File::Spec::Functions;

my ($SQLITE_VERSION) = @ARGV;

my $dir = "sqlite-amalgamation-${SQLITE_VERSION}";
my $dir_dist = $dir;

rmtree($dir);
system($^X, catfile('tools', 'extract.pl'), catfile('tar', "$dir.tar.gz"));

chdir($dir_dist) || die "Cannot chdir to $dir_dist, $!";

#
# Remove the "#error Need implementation of sqlite3Hwtime() for your platform.": we absolutely
# don't mind if this function is not available
#
open(SQLITE3, '<', 'sqlite3.c') || die "Cannot open sqlite3.c, $!";
my $buf = do {local $/; <SQLITE3>};
close(SQLITE3) || warn "Cannot close sqlite3.c, $!";
$buf =~ s/(^\s*\#error[^\n]*)/\/* $1 *\//sxmg;

#
# Add our extended ICU collation function, inspired by https://gist.github.com/mytskine/5028755
#
our $icuLoadCollationWithStrength = do {local $/; <DATA>};
$buf =~ s/(\bstatic\s+void\s+icuLoadCollation\b)/\n$icuLoadCollationWithStrength\n$1/;
$buf =~ s/(\{\s*\"icu_load_collation\"[^\}]*\}\s*,)/$1\n{"icu_load_collationWithStrength",  3, SQLITE_UTF8, (void*)db, icuLoadCollationWithStrength},/;

open(SQLITE3, '>', 'sqlite3.c') || die "Cannot open sqlite3.c, $!";
print SQLITE3 $buf;
close(SQLITE3) || warn "Cannot close sqlite3.c, $!";

exit(EXIT_SUCCESS);

__DATA__
static void icuLoadCollationWithStrength(
  sqlite3_context *p, 
  int nArg, 
  sqlite3_value **apArg
){
  sqlite3 *db = (sqlite3 *)sqlite3_user_data(p);
  UErrorCode status = U_ZERO_ERROR;
  const char *zLocale;      /* Locale identifier - (eg. "jp_JP") */
  const char *zName;        /* SQL Collation sequence name (eg. "japanese") */
  int collStrength;         /* ICU Collation strength: one of UCOL_PRIMARY, UCOL_SECONDARY, UCOL_TERTIARY, UCOL_QUATERNARY, UCOL_IDENTICAL, UCOL_DEFAULT */
  UCollator *pUCollator;    /* ICU library collation object */
  int rc;                   /* Return code from sqlite3_create_collation_x() */

  assert(nArg==3);
  zLocale = (const char *)sqlite3_value_text(apArg[0]);
  zName = (const char *)sqlite3_value_text(apArg[1]);
  collStrength = sqlite3_value_int(apArg[2]);

  if( !zName ){ /* zLocale == NULL is OK */
    return;
  }

  pUCollator = ucol_open(zLocale, &status);
  if( !U_SUCCESS(status) ){
    icuFunctionError(p, "ucol_open", status);
    return;
  }
  assert(p);
  switch (collStrength) {
  case UCOL_PRIMARY:
  case UCOL_SECONDARY:
  case UCOL_TERTIARY:
  case UCOL_QUATERNARY:
  case UCOL_IDENTICAL:
  case UCOL_DEFAULT:
    break;
  default:
    collStrength = UCOL_DEFAULT;
    break;
  }
  ucol_setStrength(pUCollator, collStrength);

  rc = sqlite3_create_collation_v2(db, zName, SQLITE_UTF16, (void *)pUCollator, 
      icuCollationColl, icuCollationDel
  );
  if( rc!=SQLITE_OK ){
    ucol_close(pUCollator);
    sqlite3_result_error(p, "Error registering collation function", -1);
  }
}
