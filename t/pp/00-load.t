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

use Test::More tests => 4;

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

Test::More::ok( ( not defined $Marpa::XS::VERSION ),
    'XS version not defined' );
Test::More::ok( ( not defined $Marpa::XS::STRING_VERSION ),
    'XS string version not defined' );

Test::More::ok( ( not defined $Marpa::XS::Internal::{check_version}{CODE} ),
    'Pure Perl mode' );

