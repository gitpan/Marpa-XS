#!/usr/bin/perl
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
use strict;
use warnings;

use Getopt::Long;
my $verbose = 1;
my $result = GetOptions ("verbose=i"  => \$verbose);  # flag
die "usage $0 [--verbose=n] file ...\n" if not $result;

require 'lib/Marpa/XS/License.pm';

my $file_count = @ARGV;
my @license_problems =
    map { Marpa::XS::License::file_license_problems( $_, $verbose ) } @ARGV;

print join "\n", @license_problems;

my $problem_count = scalar @license_problems;

$problem_count and say ('=' x 50);
say "Found $problem_count license language problems after examining $file_count files";
