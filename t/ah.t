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
#
# The example grammar in Aycock/Horspool "Practical Earley Parsing",
# _The Computer Journal_, Vol. 45, No. 6, pp. 620-630

use 5.010;
use strict;
use warnings;
use Test::More tests => 8;
use Marpa::XS::Test;

BEGIN {
    Test::More::use_ok('Marpa::XS');
}

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
        strip    => 0.
    }
);

$g->set( { terminals => [qw(a)] } );

$g->precompute();

Marpa::XS::Test::is( $g->show_rules, <<'EOS', 'Aycock/Horspool Rules' );
0: S' -> S /* nullable */
1: S -> A A A A /* nullable */
2: A -> a
3: A -> E /* nullable */
4: E -> /* empty nullable */
EOS

Marpa::XS::Test::is( $g->show_symbols, <<'EOS', 'Aycock/Horspool Symbols' );
0: S', lhs=[0] rhs=[] nullable=4
1: S, lhs=[1] rhs=[0] nullable=4
2: A, lhs=[2 3] rhs=[1] nullable=1
3: a, lhs=[] rhs=[2] terminal
4: E, lhs=[4] rhs=[3] nullable=1 nulling
EOS

Marpa::XS::Test::is( $g->show_nullable_symbols, q{A E S S'},
    'Aycock/Horspool Nullable Symbols' );
Marpa::XS::Test::is( $g->show_nulling_symbols, 'E',
    'Aycock/Horspool Nulling Symbols' );
Marpa::XS::Test::is( $g->show_productive_symbols, q{A E S S' a},
    'Aycock/Horspool Productive Symbols' );
Marpa::XS::Test::is( $g->show_accessible_symbols, q{A E S S' a},
    'Aycock/Horspool Accessible Symbols' );

Marpa::XS::Test::is( $g->show_NFA, <<'EOS', 'Aycock/Horspool NFA' );
S0: /* empty */
 empty => S1
S1: S' -> . S
 empty => S3
 <S> => S2
S2: S' -> S .
S3: S -> . A A A A
 empty => S8 S10
 <A> => S4
S4: S -> A . A A A
 empty => S8 S10
 <A> => S5
S5: S -> A A . A A
 empty => S8 S10
 <A> => S6
S6: S -> A A A . A
 empty => S8 S10
 <A> => S7
S7: S -> A A A A .
S8: A -> . a
 <a> => S9
S9: A -> a .
S10: A -> . E
at_nulling
 empty => S12
 <E> => S11
S11: A -> E .
S12: E -> .
EOS

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
