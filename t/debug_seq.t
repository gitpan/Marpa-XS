#!/usr/bin/perl

# Debug Sequence Example

use 5.010;
use strict;
use warnings;

use Test::More tests => 3;

use English qw( -no_match_vars );
use Fatal qw( open close );
use Marpa::XS::Test;

BEGIN {
    Test::More::use_ok('Marpa::XS');
}

my $progress_report = q{};

# Marpa::XS::Display
# name: Debug Sequence Example

my $grammar = Marpa::XS::Grammar->new(
    {   start         => 'Document',
        strip         => 0,
        lhs_terminals => 0,
        rules => [ { lhs => 'Document', rhs => [qw/Stuff/], min => 1 }, ],
    }
);

# Marpa::XS::Display::End

$grammar->precompute();

my @tokens = ( ( ['Stuff'] ) x 3 );

my $recce =
    Marpa::XS::Recognizer->new( { grammar => $grammar, mode => 'stream' } );

my $token_ix = 0;

my ( $current_earleme, $expected_tokens ) =
    $recce->tokens( \@tokens, \$token_ix );

$progress_report = $recce->show_progress(0);

my $value_ref = $recce->value;
Test::More::ok( $value_ref, 'Parse ok?' );

# Marpa::XS::Display
# name: Debug Sequence Example Progress Report
# start-after-line: END_PROGRESS_REPORT
# end-before-line: '^END_PROGRESS_REPORT$'

Marpa::XS::Test::is( $progress_report,
    << 'END_PROGRESS_REPORT', 'progress report' );
PREDICTING @0 0: Document -> Stuff[Seq:1-*]
PREDICTING @0 1: Stuff[Seq:1-*] -> Stuff
PREDICTING @0 2: Stuff[Seq:1-*] -> Stuff[Seq:1-*] Stuff
PREDICTING @0 3: Document['] -> Document
END_PROGRESS_REPORT

# Marpa::XS::Display::End

1; # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
