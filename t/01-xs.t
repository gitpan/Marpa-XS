#!perl
# Copyright 2010 Jeffrey Kegler
# This file is part of Marpa::XS.  Marpa::XS is free software: you can
# redistribute it and/or modify it under the terms of the GNU Lesser
# General Public License as published by the Free Software Foundation,
# either version 3 of the License, or (at your option) any later version.
#
# Marpa::XS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser
# General Public License along with Marpa::XS.  If not, see
# http://www.gnu.org/licenses/.

use 5.010;
use warnings;
use strict;

use Test::More tests => 6;

use Carp;
use Data::Dumper;

$Marpa::XS_FORCE = 1;

BEGIN {
    $Marpa::XS_FORCE = 1;
    Test::More::use_ok('Marpa::XS');
}

my @tests =
    ( [ 42, 7, 11 ], [ 0, 0, 1 ], [ 0, 2, 0 ], [ 0, 1, 0 ], [ 0, 0, 0 ] );

my @results = (
    'marpa major version too old: require 42.007011, but have 0.001000',
    'marpa minor/micro version too new: require 0.000001, but have 0.001000',
    'marpa minor/micro version too old: require 0.002000, but have 0.001000',
    'Perfect!',
    'marpa minor/micro version too new: require 0.000000, but have 0.001000',
);

for ( my $i = 0; $i < @tests; $i++ ) {
    Test::More::is( Marpa::XS::Internal::check_version( @{ $tests[$i] } ),
        $results[$i] );
}

1;    # In case used as "do" file

