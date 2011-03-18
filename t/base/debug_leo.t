#!/usr/bin/perl
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

# Debug Leo Example

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
# name: Debug Leo Example

my $grammar = Marpa::XS::Grammar->new(
    {   start         => 'S',
        strip         => 0,
        lhs_terminals => 0,
        rules         => [
            { lhs => 'S',            rhs => [qw/Top_sequence/] },
            { lhs => 'Top_sequence', rhs => [qw/Top Top_sequence/] },
            { lhs => 'Top_sequence', rhs => [qw/Top/] },
            { lhs => 'Top',          rhs => [qw/Upper_Middle/] },
            { lhs => 'Upper_Middle', rhs => [qw/Lower_Middle/] },
            { lhs => 'Lower_Middle', rhs => [qw/Bottom/] },
            { lhs => 'Bottom',       rhs => [qw/T/] },
        ],
    }
);

# Marpa::XS::Display::End

$grammar->precompute();

my @tokens = ( ['T'] ) x 20;

my $recce = Marpa::XS::Recognizer->new( { grammar => $grammar } );

my $current_earleme = $recce->tokens( \@tokens );

$progress_report = $recce->show_progress();

my $value_ref = $recce->value;
Test::More::ok( $value_ref, 'Parse ok?' );

# Marpa::XS::Display
# name: Debug Leo Example Progress Report
# start-after-line: END_PROGRESS_REPORT
# end-before-line: '^END_PROGRESS_REPORT$'

Marpa::XS::Test::is( $progress_report,
    <<'END_PROGRESS_REPORT', 'sorted progress report' );
PREDICTING @20 1: Top_sequence -> Top Top_sequence
PREDICTING @20 2: Top_sequence -> Top
PREDICTING @20 3: Top -> Upper_Middle
PREDICTING @20 4: Upper_Middle -> Lower_Middle
PREDICTING @20 5: Lower_Middle -> Bottom
PREDICTING @20 6: Bottom -> T
BUILDING @19-20 Top_sequence -> Top . Top_sequence
COMPLETED @0-20 0: S -> Top_sequence
COMPLETED @0-20 (Leo) 1: Top_sequence -> Top Top_sequence
COMPLETED @19-20 2: Top_sequence -> Top
COMPLETED @19-20 (Leo) 3: Top -> Upper_Middle
COMPLETED @19-20 6: Bottom -> T
COMPLETED @0-20 7: S['] -> S
END_PROGRESS_REPORT

# Marpa::XS::Display::End

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
