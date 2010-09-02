#!perl

use 5.010;
use warnings;
use strict;

use Test::More tests => 5;
use lib 'lib';
use lib 'blib/arch';

BEGIN {
    Test::More::use_ok('Devel::SawAmpersand');
    Test::More::use_ok('Marpa::XS');
    Test::More::use_ok('Marpa::XS::Perl');
    Test::More::use_ok('Marpa::XS::Test');
} ## end BEGIN

Test::More::ok( !Devel::SawAmpersand::sawampersand(), 'PL_sawampersand set' );
