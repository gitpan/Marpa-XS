#!perl

use 5.010;

package Marpa::XS;

use strict;
use warnings;

# force perl-only version to be tested
our $TESTING_PERL_ONLY;
$Marpa::XS::TESTING_PERL_ONLY = 1;

package main;

use English qw( -no_match_vars );
use File::Spec;

my ($volume, $dirs, $file_name ) = File::Spec->splitpath( __FILE__ );
my @dirs = File::Spec->splitdir( $dirs );
my $top_dir = '';
1 while @dirs and not $top_dir = pop @dirs;
if ($top_dir ne 'pp') {
    @dirs = File::Spec->updir();
}
$dirs = File::Spec->catdir( @dirs );
my $f = File::Spec->catpath( $volume, $dirs, $file_name );
DO: {
    local $ERRNO;
    local $EVAL_ERROR;
    last DO if defined  do $f;
    die "$f: $ERRNO" if $ERRNO;
    die qq{Compilation error in $f\n"$EVAL_ERROR"} if $EVAL_ERROR;
}
