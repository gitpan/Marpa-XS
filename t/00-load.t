#!perl

use 5.010;
use warnings;
use strict;

use Test::More tests => 1;
use lib 'lib';

use Carp;
use Data::Dumper;

$Marpa::XS_FORCE = 1;

BEGIN {
    $Marpa::XS_FORCE = 1;
    Test::More::use_ok('Marpa::XS');
}

say Data::Dumper::Dumper($Marpa::XS::VERSION);
defined $Marpa::XS::VERSION or Test::More::BAIL_OUT('Could not load Marpa');


