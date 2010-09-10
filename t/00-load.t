#!perl

use 5.010;
use warnings;
use strict;

use Test::More tests => 6;

use Carp;
use Data::Dumper;

BEGIN {
    Test::More::use_ok('Marpa::XS');
}

defined $INC{'Marpa/XS.pm'}
    or Test::More::BAIL_OUT('Could not load Marpa::XS');

my @tests =
    ( [ 42, 7, 11 ], [ 0, 0, 1 ], [ 0, 2, 0 ], [ 0, 1, 0 ], [ 0, 0, 0 ] );

my @results = (
    'libmarpa major version too old: require 42.007011, but have 0.001000',
    'libmarpa minor/micro version too new: require 0.000001, but have 0.001000',
    'libmarpa minor/micro version too old: require 0.002000, but have 0.001000',
    'Perfect!',
    'libmarpa minor/micro version too new: require 0.000000, but have 0.001000',
);

for ( my $i = 0; $i < @tests; $i++ ) {
    Test::More::is(
        Marpa::XS::Internal::libmarpa_check_version( @{ $tests[$i] } ),
        $results[$i] );
}

1; # In case used as "do" file

