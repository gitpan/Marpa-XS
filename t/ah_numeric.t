#!perl
# Copyright 2011 Jeffrey Kegler
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

# the example grammar in Aycock/Horspool "Practical Earley Parsing",
# _The Computer Journal_, Vol. 45, No. 6, pp. 620-630,
# in its "NNF" form

use 5.010;
use strict;
use warnings;

use Test::More tests => 11;
use lib 'tool/lib';
use Marpa::Test;

BEGIN {
    Test::More::use_ok('Marpa::XS');
}

## no critic (Subroutines::RequireArgUnpacking)

# Marpa::XS::Display
# name: Marpa::token_location example

sub rank_null_a {
    return \( ( $MyTest::MAXIMAL ? -1 : 1 )
        * 10**( 3 - Marpa::token_location() ) );
}

# Marpa::XS::Display::End

sub default_action {
    shift;
    my $v_count = scalar @_;
    return q{}   if $v_count <= 0;
    return $_[0] if $v_count == 1;
    return '(' . join( q{;}, @_ ) . ')';
} ## end sub default_action

## use critic

my $grammar = Marpa::Grammar->new(
    {   start => 'S',
        rules => [
            [ 'S', [qw/A A A A/] ],
            [ 'A', [qw/a/] ],
            [ 'A', [qw/E/] ],
            { lhs => 'A', rhs => [], ranking_action => 'main::rank_null_a' },
            ['E'],
        ],
        default_null_value => q{},
        default_action     => 'main::default_action',
    }
);

$grammar->set( { terminals => ['a'], } );

$grammar->precompute();

my $recce = Marpa::Recognizer->new(
    { grammar => $grammar, ranking_method => 'constant' } );

my $input_length = 4;
$recce->tokens( [ ( [ 'a', 'a', 1 ] ) x $input_length ] );

my @maximal = ( q{}, qw[(a;;;) (a;a;;) (a;a;a;) (a;a;a;a)] );
my @minimal = ( q{}, qw[(;;;a) (;;a;a) (;a;a;a) (a;a;a;a)] );

for my $i ( 0 .. $input_length ) {
    for my $maximal ( 0, 1 ) {
        local $MyTest::MAXIMAL = $maximal;
        my $expected = $maximal ? \@maximal : \@minimal;
        my $name     = $maximal ? 'maximal' : 'minimal';
        $recce->reset_evaluation();
        $recce->set( { end => $i, } );
        my $result = $recce->value();
        Test::More::is( ${$result}, $expected->[$i],
            "$name parse permutation $i" );

    } ## end for my $maximal ( 0, 1 )
} ## end for my $i ( 0 .. $input_length )

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
