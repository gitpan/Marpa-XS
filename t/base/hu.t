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
use 5.010;
use strict;
use warnings;

use Test::More tests => 9;

use Marpa::XS::Test;

BEGIN {
    Test::More::use_ok('Marpa::XS');
}

# A grammar from Hopcroft & Ullman,
# _Introduction to Automata Theory, Languages and Computation_,
# (Addison-Wesley, Reading, Massachusetts: 1979),
# pp. 248, 250.

my $g = Marpa::XS::Grammar->new(
    {   start => q{S'},
        strip => 0,
        rules => [
            [ q{S'}, [qw/S c/] ],
            [ 'S',   [qw/S A/] ],
            [ 'S',   [qw/A/] ],
            [ 'A',   [qw/a S b/] ],
            [ 'A',   [qw/a b/] ],
        ],
        academic => 1,
    }
);

$g->set( { terminals => [qw(a b c)] } );

$g->precompute();

Marpa::XS::Test::is( $g->show_rules, <<'EOS', 'Hopcroft/Ullman Rules' );
0: S' -> S c
1: S -> S A
2: S -> A
3: A -> a S b
4: A -> a b
EOS

Marpa::XS::Test::is( $g->show_symbols, <<'EOS', 'Hopcroft/Ullman Symbols' );
0: S', lhs=[0] rhs=[]
1: S, lhs=[1 2] rhs=[0 1 3]
2: c, lhs=[] rhs=[0] terminal
3: A, lhs=[3 4] rhs=[1 2]
4: a, lhs=[] rhs=[3 4] terminal
5: b, lhs=[] rhs=[3 4] terminal
EOS

Marpa::XS::Test::is( $g->show_nullable_symbols, q{},
    'Hopcroft/Ullman Nullable Symbols' );
Marpa::XS::Test::is( $g->show_nulling_symbols, q{},
    'Hopcroft/Ullman Nulling Symbols' );
Marpa::XS::Test::is(
    $g->show_productive_symbols,
    'A S S\' a b c',
    'Hopcroft/Ullman Productive Symbols'
);
Marpa::XS::Test::is(
    $g->show_accessible_symbols,
    'A S S\' a b c',
    'Hopcroft/Ullman Accessible Symbols'
);
Marpa::XS::Test::is( $g->show_NFA, <<'EOS', 'Hopcroft/Ullman NFA' );
S0: /* empty */
 empty => S1
S1: S' -> . S c
 empty => S4 S7
 <S> => S2
S2: S' -> S . c
 <c> => S3
S3: S' -> S c .
S4: S -> . S A
 empty => S4 S7
 <S> => S5
S5: S -> S . A
 empty => S9 S13
 <A> => S6
S6: S -> S A .
S7: S -> . A
 empty => S9 S13
 <A> => S8
S8: S -> A .
S9: A -> . a S b
 <a> => S10
S10: A -> a . S b
 empty => S4 S7
 <S> => S11
S11: A -> a S . b
 <b> => S12
S12: A -> a S b .
S13: A -> . a b
 <a> => S14
S14: A -> a . b
 <b> => S15
S15: A -> a b .
EOS

Marpa::XS::Test::is( $g->show_AHFA, <<'EOS', 'Hopcroft/Ullman AHFA' );
Start States: S0; S1
S0:
S' -> . S c
 <S> => S2
S1: predict
S -> . S A
S -> . A
A -> . a S b
A -> . a b
 <A> => S3; leo(S)
 <S> => S4; S5
 <a> => S1; S6
S2:
S' -> S . c
 <c> => S7
S3: leo-c
S -> A .
S4:
S -> S . A
 <A> => S8; leo(S)
S5: predict
A -> . a S b
A -> . a b
 <a> => S1; S6
S6:
A -> a . S b
A -> a . b
 <S> => S9
 <b> => S10
S7:
S' -> S c .
S8: leo-c
S -> S A .
S9:
A -> a S . b
 <b> => S11
S10:
A -> a b .
S11:
A -> a S b .
EOS

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
