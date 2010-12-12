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
# Catch the case of a final non-nulling symbol at the end of a rule
# which has more than 2 proper nullables
# This is to test an untested branch of the CHAF logic.

use 5.010;
use strict;
use warnings;

use Test::More tests => 12;

use Marpa::XS::Test;

BEGIN {
    Test::More::use_ok('Marpa::XS');
}

## no critic (Subroutines::RequireArgUnpacking)

sub default_action {
    shift;
    my $v_count = scalar @_;
    return q{} if $v_count <= 0;
    my @vals = map { $_ // q{-} } @_;
    return $vals[0] if $v_count == 1;
    return '(' . join( q{;}, @vals ) . ')';
} ## end sub default_action

## use critic

my $grammar = Marpa::XS::Grammar->new(
    {   start   => 'S',
        strip   => 0,

        rules => [
            [ 'S', [qw/p p p n/], ],
            [ 'p', ['a'], ],
            [ 'p', [], ],
            [ 'n', ['a'], ],
        ],
        terminals      => ['a'],
        default_action => 'main::default_action',
    }
);

$grammar->precompute();

Marpa::XS::Test::is( $grammar->show_rules,
    <<'END_OF_STRING', 'final nonnulling Rules' );
0: S -> p p p n /* !used */
1: p -> a
2: p -> /* empty !used */
3: n -> a
4: S -> p p S[R0:2] /* vrhs real=2 */
5: S -> p p[] S[R0:2] /* vrhs real=2 */
6: S -> p[] p S[R0:2] /* vrhs real=2 */
7: S -> p[] p[] S[R0:2] /* vrhs real=2 */
8: S[R0:2] -> p n /* vlhs real=2 */
9: S[R0:2] -> p[] n /* vlhs real=2 */
10: S['] -> S /* vlhs real=1 */
END_OF_STRING

SKIP: { skip 'Not using XS', 1 if not $Marpa::XS::USING_XS ;

Marpa::XS::Test::is( $grammar->show_new_AHFA(), <<'EOS', 'final nonnulling New AHFA States' );
S0:
S['] -> . S
EOS

} ## SKIP of XS tests

Marpa::XS::Test::is( $grammar->show_AHFA,
    <<'END_OF_STRING', 'final nonnulling AHFA' );
Start States: S0; S1
S0:
S['] -> . S
 <S> => S2; leo(S['])
S1: predict
p -> . a
n -> . a
S -> . p p S[R0:2]
S -> . p p[] S[R0:2]
S -> p[] . p S[R0:2]
S -> p[] p[] . S[R0:2]
S[R0:2] -> . p n
S[R0:2] -> p[] . n
 <S[R0:2]> => S3; leo(S)
 <a> => S4
 <n> => S5; leo(S[R0:2])
 <p> => S6; S7
S2: leo-c
S['] -> S .
S3: leo-c
S -> p[] p[] S[R0:2] .
S4:
p -> a .
n -> a .
S5: leo-c
S[R0:2] -> p[] n .
S6:
S -> p . p S[R0:2]
S -> p p[] . S[R0:2]
S -> p[] p . S[R0:2]
S[R0:2] -> p . n
 <S[R0:2]> => S8
 <n> => S9; leo(S[R0:2])
 <p> => S10; S7
S7: predict
p -> . a
n -> . a
S[R0:2] -> . p n
S[R0:2] -> p[] . n
 <a> => S4
 <n> => S5; leo(S[R0:2])
 <p> => S11; S12
S8:
S -> p p[] S[R0:2] .
S -> p[] p S[R0:2] .
S9: leo-c
S[R0:2] -> p n .
S10:
S -> p p . S[R0:2]
 <S[R0:2]> => S13; leo(S)
S11:
S[R0:2] -> p . n
 <n> => S9; leo(S[R0:2])
S12: predict
n -> . a
 <a> => S14
S13: leo-c
S -> p p S[R0:2] .
S14:
n -> a .
END_OF_STRING

my @expected = map {
    +{ map { ( $_ => 1 ) } @{$_} }
    }
    [q{}],
    [qw( (-;-;-;a) )],
    [qw( (a;-;-;a) (-;-;a;a) (-;a;-;a) )],
    [qw( (a;a;-;a) (-;a;a;a) (a;-;a;a))],
    [qw( (a;a;a;a) )];

for my $input_length ( 1 .. 4 ) {

    # Set max at 10 just in case there's an infinite loop.
    # This is for debugging, after all
    my $recce = Marpa::XS::Recognizer->new(
        { grammar => $grammar, max_parses => 10 } );
    $recce->tokens( [ ( [ 'a', 'a', 1 ] ) x $input_length ] );
    while ( my $value_ref = $recce->value() ) {
        my $value = $value_ref ? ${$value_ref} : 'No parse';
        my $expected = $expected[$input_length];
        if ( defined $expected->{$value} ) {
            delete $expected->{$value};
            Test::More::pass(qq{Expected value: "$value"});
        }
        else {
            Test::More::fail(qq{Unexpected value: "$value"});
        }
    } ## end while ( my $value_ref = $recce->value() )
} ## end for my $input_length ( 1 .. 4 )

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
