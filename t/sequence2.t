#!/usr/bin/perl

# Tests of the sequence in the Marpa::XS::Grammar doc

use 5.010;
use strict;
use warnings;

use Fatal qw(open close);
use Test::More tests => 4;

use lib 'lib';
use Marpa::XS::Test;

BEGIN {
    Test::More::use_ok('Marpa::XS');
}

## no critic (Subroutines::RequireArgUnpacking)
sub sequence { shift; return 'seq(' .  ( join q{;}, @_ ) . ')' }
sub item     { shift; return 'item(' . ( join q{;}, @_ ) . ')' }
## use critic

my $grammar;
my $recce;
my $value_ref;
my $value;

my $min0 =
#<<< no perltidy
# Marpa::XS::Display
# name: Marpa::XS::Grammar min 0 sequence example

    { lhs => 'sequence', rhs => ['item'], min => 0 }

# Marpa::XS::Display::End
; # semicolon to terminate rule

$grammar = Marpa::XS::Grammar->new(
    {   start     => 'sequence',
        terminals => [qw(item)],
        rules     => [$min0],
        actions => 'main'
    }
);

$grammar->precompute();

$recce = Marpa::XS::Recognizer->new( { grammar => $grammar } );

$recce->tokens( [ [ 'item', '0' ], ['item', '1'] ]);

$value_ref = $recce->value();
$value = $value_ref ? ${$value_ref} : 'No Parse';
$value //= 'undef returned';

Marpa::XS::Test::is( $value, 'seq(0;1)', 'min 0 value' );

my $min1 =
#<<< no perltidy
# Marpa::XS::Display
# name: Marpa::XS::Grammar min 1 sequence example

    { lhs => 'sequence', rhs => ['item'], min => 1 }

# Marpa::XS::Display::End
; # semicolon to terminate rule

$grammar = Marpa::XS::Grammar->new({
     start => 'sequence',
     rules => [ $min1 ],
        actions => 'main'
});

$grammar->precompute();

$recce = Marpa::XS::Recognizer->new( { grammar => $grammar } );

$recce->tokens( [ [ 'item', '0' ], [ 'item', '1' ] ] );

$value_ref = $recce->value();
$value = $value_ref ? ${$value_ref} : 'No Parse';
$value //= 'undef returned';

Marpa::XS::Test::is( $value, 'seq(0;1)', 'min 1 value' );

my $multipart = [
#<<< no perltidy
# Marpa::XS::Display
# name: Marpa::XS::Grammar multipart rhs sequence example

    { lhs => 'sequence', rhs => [qw(item)], min => 0 },
    { lhs => 'item', rhs => [qw(part1 part2)], },

# Marpa::XS::Display::End
]; # semicolon to terminate rule

$grammar = Marpa::XS::Grammar->new(
    {   start => 'sequence',
        terminals => [qw(part1 part2)],
        rules => $multipart,
        actions => 'main'
    }
);


$grammar->precompute();

$recce = Marpa::XS::Recognizer->new( { grammar => $grammar } );

$recce->tokens( [ [ 'part1', '0' ], [ 'part2', '1' ] ] );

$value_ref = $recce->value();
$value = $value_ref ? ${$value_ref} : 'No Parse';
$value //= 'undef returned';

Marpa::XS::Test::is( $value, 'seq(item(0;1))', 'multipart rhs value' );

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
