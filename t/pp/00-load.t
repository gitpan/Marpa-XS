#!perl

use 5.010;
use warnings;
use strict;

use Test::More tests => 2;

use Carp;
use Data::Dumper;

package Marpa::XS;
our $TESTING_PERL_ONLY;

package main;

BEGIN {

    # force perl-only version to be tested
    $Marpa::XS::TESTING_PERL_ONLY = 1;
    Test::More::use_ok('Marpa::XS');
} ## end BEGIN

defined $INC{'Marpa/XS.pm'}
    or Test::More::BAIL_OUT('Could not load Marpa::XS');

Test::More::ok( ( not defined &Marpa::XS::Internal::libmarpa_check_version ),
    "Pure Perl mode" );

