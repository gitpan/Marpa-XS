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

# Rewriting tests, to check the accuracy of the
# tracing documentation.

use 5.010;
use strict;
use warnings;

use Fatal qw(open close);
use Test::More tests => 3;

use Marpa::XS::Test;

BEGIN {
    Test::More::use_ok('Marpa::XS');
}

my $chaf_rule =
#<<< no perltidy
# Marpa::XS::Display
# name: CHAF Rule

{   lhs => 'statement',
    rhs => [
        qw/optional_whitespace expression
            optional_whitespace optional_modifier
            optional_whitespace/
    ]
}

# Marpa::XS::Display::End
; # semicolon to terminate rule

#>>> no perltidy

my $separated_sequence_rule =
#<<< no perltidy
# Marpa::XS::Display
# name: Separated Sequence Rule

{
    lhs       => 'statements',
    rhs       => [qw/statement/],
    separator => 'comma',
    min       => 1
}

# Marpa::XS::Display::End
; # semicolon to terminate rule

#>>> no perltidy

my $sequence_rule =
#<<< no perltidy
# Marpa::XS::Display
# name: Sequence Rule

    { lhs => 'block', rhs => [qw/statements/], min => 0 },

# Marpa::XS::Display::End
; # semicolon to terminate rule

#>>> no perltidy

my $grammar = Marpa::XS::Grammar->new(
    {   start   => 'block',
        strip   => 0,
        symbols => {
            'block' => {
                terminal   => 1,
                null_value => 'Null parse'
            }
        },
        terminals => [qw(whitespace modifier expression comma)],
        rules     => [
            $chaf_rule,
            $separated_sequence_rule,
            $sequence_rule,
            { lhs => 'optional_whitespace', rhs => [qw(whitespace)] },
            { lhs => 'optional_whitespace', },
            { lhs => 'optional_modifier',   rhs => [qw(modifier)] },
            { lhs => 'optional_modifier', },
        ],
    }
);

$grammar->precompute();

my $recce = Marpa::XS::Recognizer->new( { grammar => $grammar } );

# While we are at it, test the handling of null parses in
# the Single Parse Evaluator
my @tokens = ();

$recce->tokens( \@tokens );

# Marpa::XS::Display::End

my $show_rules_output = $grammar->show_rules();

# Marpa::XS::Display
# name: Rewrite show_rules Output
# start-after-line: END_RULES
# end-before-line: '^END_RULES$'

Marpa::XS::Test::is( $show_rules_output, <<'END_RULES', 'Rewritten Rules' );
0: statement -> optional_whitespace expression optional_whitespace optional_modifier optional_whitespace /* !used */
1: statements -> statement[Seq:1-*][Sep:comma] /* vrhs discard_sep real=0 */
2: statements -> statement[Seq:1-*][Sep:comma] comma /* vrhs discard_sep real=1 */
3: statement[Seq:1-*][Sep:comma] -> statement /* vlhs real=1 */
4: statement[Seq:1-*][Sep:comma] -> statement[Seq:1-*][Sep:comma] comma statement /* vlhs vrhs real=2 */
5: block -> /* empty !used */
6: block -> statements[Seq:1-*] /* vrhs real=0 */
7: statements[Seq:1-*] -> statements /* vlhs real=1 */
8: statements[Seq:1-*] -> statements[Seq:1-*] statements /* vlhs vrhs real=1 */
9: optional_whitespace -> whitespace
10: optional_whitespace -> /* empty !used */
11: optional_modifier -> modifier
12: optional_modifier -> /* empty !used */
13: statement -> optional_whitespace expression statement[R0:2] /* vrhs real=2 */
14: statement -> optional_whitespace expression optional_whitespace[] optional_modifier[] optional_whitespace[]
15: statement -> optional_whitespace[] expression statement[R0:2] /* vrhs real=2 */
16: statement -> optional_whitespace[] expression optional_whitespace[] optional_modifier[] optional_whitespace[]
17: statement[R0:2] -> optional_whitespace statement[R0:3] /* vlhs vrhs real=1 */
18: statement[R0:2] -> optional_whitespace optional_modifier[] optional_whitespace[] /* vlhs real=3 */
19: statement[R0:2] -> optional_whitespace[] statement[R0:3] /* vlhs vrhs real=1 */
20: statement[R0:3] -> optional_modifier optional_whitespace /* vlhs real=2 */
21: statement[R0:3] -> optional_modifier optional_whitespace[] /* vlhs real=2 */
22: statement[R0:3] -> optional_modifier[] optional_whitespace /* vlhs real=2 */
23: block['] -> block /* vlhs real=1 */
24: block['][] -> /* empty vlhs real=1 */
END_RULES

# Marpa::XS::Display::End

my $value_ref = $recce->value();
my $value = $value_ref ? ${$value_ref} : 'No Parse';

Marpa::XS::Test::is( $value, 'Null parse', 'Null parse value' );

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:
