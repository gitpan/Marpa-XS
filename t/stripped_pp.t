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
use Test::More tests => 8;
use Marpa::XS::Test;

package Marpa::XS;
our $FORCE_PP;

BEGIN {

    # force perl-only version to be tested
    $Marpa::XS::FORCE_PP = 1;
    Test::More::use_ok('Marpa::XS');
}

# The example grammar in Aycock/Horspool "Practical Earley Parsing",
# _The Computer Journal_, Vol. 45, No. 6, pp. 620-630
# This time testing the stripped output

my $g = Marpa::XS::Grammar->new(
    {   start => q{S'},
        rules => [
            [ q{S'}, [qw/S/] ],
            [ 'S',   [qw/A A A A/] ],
            [ 'A',   [qw/a/] ],
            [ 'A',   [qw/E/] ],
            ['E'],
        ],
        academic => 1,
    }
);

$g->set( { terminals => ['a'] } );

$g->precompute();

Marpa::XS::Test::is( $g->show_rules, <<'EOS', 'Aycock/Horspool Rules' );
0: S' -> S /* stripped */
1: S -> A A A A /* stripped */
2: A -> a /* stripped */
3: A -> E /* stripped */
4: E -> /* empty stripped */
EOS

Marpa::XS::Test::is( $g->show_symbols, <<'EOS', 'Aycock/Horspool Symbols' );
0: S', stripped nullable
1: S, stripped nullable
2: A, stripped nullable
3: a, stripped terminal
4: E, stripped nullable nulling
EOS

Marpa::XS::Test::is( $g->show_nullable_symbols, 'stripped_',
    'Aycock/Horspool Nullable Symbols' );
Marpa::XS::Test::is( $g->show_nulling_symbols, 'stripped_',
    'Aycock/Horspool Nulling Symbols' );
Marpa::XS::Test::is( $g->show_productive_symbols, 'stripped_',
    'Aycock/Horspool Productive Symbols' );
Marpa::XS::Test::is( $g->show_accessible_symbols, 'stripped_',
    'Aycock/Horspool Accessible Symbols' );

Marpa::XS::Test::is( $g->show_NFA, <<'EOS', 'Aycock/Horspool NFA' );
stripped
EOS

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
