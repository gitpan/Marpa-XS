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
use strict;
use warnings;

# force perl-only version to be tested
package Marpa::XS;
our $FORCE_XS;
$Marpa::XS::FORCE_XS = 1;

package main;

use English qw( -no_match_vars );
use File::Spec;

my ( $volume, $dirs, $file_name ) = File::Spec->splitpath(__FILE__);
my @dirs    = File::Spec->splitdir($dirs);
my $top_dir = q{};
1 while @dirs and not $top_dir = pop @dirs;
if ( $top_dir ne 'xs' ) {
    @dirs = File::Spec->updir();
}
$dirs = File::Spec->catdir( @dirs, 'base' );
my $f = File::Spec->catpath( $volume, $dirs, $file_name );
DO: {
    local $ERRNO      = undef;
    local $EVAL_ERROR = undef;
    last DO                                        if defined do $f;
    die "$f: $ERRNO"                               if $ERRNO;
    die qq{Compilation error in $f\n"$EVAL_ERROR"} if $EVAL_ERROR;
} ## end DO:
