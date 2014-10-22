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

package Marpa::XS::Grammar;

use 5.010;

use warnings;

# There's a problem with this perlcritic check
# as of 9 Aug 2010
## no critic (TestingAndDebugging::ProhibitNoWarnings)
no warnings qw(recursion qw);
## use critic

use strict;

# It's all integers, except for the version number
use integer;
use utf8;

use Marpa::XS::Internal::Carp_Not;

=begin Implementation:

Structures and Objects: The design is to present an object-oriented
interface, but internally to avoid overheads.  So internally, where
objects might be used, I use array with constant indices to imitate
what in C would be structures.

=end Implementation:

=cut

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Symbol

    ID
    NAME

    =LAST_BASIC_DATA_FIELD

    NULL_ALIAS { for a non-nullable symbol,
    ref of a its nulling alias,
    if there is one
    otherwise undef }

    NULLING { always is null? }
    RANKING_ACTION
    NULL_VALUE { null value }

    NULLABLE { The number of nullable symbols
    the symbol represents,
    0 if the symbol is not nullable. }

    =LAST_EVALUATOR_FIELD

    TERMINAL { terminal? }

    =LAST_RECOGNIZER_FIELD

    LH_RULE_IDS { rules with this as the lhs,
    as a ref to an array of rule refs }

    RH_RULE_IDS { rules with this in the rhs,
    as a ref to an array of rule refs }

    ACCESSIBLE { reachable from start symbol? }
    PRODUCTIVE { reachable from input symbol? }
    START { is one of the start symbols? }
    COUNTED { used on rhs of counted rule? }

    WARN_IF_NO_NULL_VALUE { should have a null value -- warn
    if not }

    =LAST_FIELD
);

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Rule

    ID
    LHS { ref of the left hand symbol }
    RHS { array of symbol refs }
    =LAST_BASIC_DATA_FIELD

    USED { Use this rule in NFA? }
    ACTION { action for this rule as specified by user }
    RANKING_ACTION
    VIRTUAL_LHS
    VIRTUAL_RHS
    DISCARD_SEPARATION
    REAL_SYMBOL_COUNT
    CYCLE { Can this rule be part of a cycle? }
    VIRTUAL_CYCLE { Is this rule part of a cycle from the virtual
    point of view? }

    =LAST_EVALUATOR_FIELD
    =LAST_RECOGNIZER_FIELD

    ORIGINAL_RULE { for a rewritten rule, the original }
    VIRTUAL_START
    VIRTUAL_END
    ACCESSIBLE { reachable from start symbol? }
    PRODUCTIVE { reachable from input symbol? }

    =LAST_FIELD
);

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::NFA

    ID
    NAME
    ITEM { an LR(0) item }
    TRANSITION { the transitions, as a hash from symbol name to NFA states }
    AT_NULLING { dot just before a nullable symbol? }
    COMPLETE { rule is complete? }

);

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::AHFA

    ID
    NAME
    =LAST_BASIC_DATA_FIELD

    COMPLETE_RULES { an array of lists of the complete rules,
    indexed by lhs }

    START_RULE { the start rule }

    =LAST_EVALUATOR_FIELD

    TRANSITION { the transitions, as a hash
    from symbol name to references to arrays
    of AHFA states }

    COMPLETE_LHS { an array of the lhs's of complete rules }

    RESET_ORIGIN { reset origin for this state? }

    =LAST_RECOGNIZER_FIELD

    LEO_COMPLETION { Is this a Leo completion state? }

    NFA_STATES { in an AHFA: an array of NFA states }

    =LAST_FIELD
);

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::LR0_item

    RULE
    POSITION

);

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Grammar

    RULES { array of rule refs }
    SYMBOLS { array of symbol refs }
    AHFA { array of states }
    PHASE { the grammar's phase }
    ACTIONS { Default package in which to find actions }
    DEFAULT_ACTION { Action for rules without one }
    CYCLE_RANKING_ACTION { Action for ranking rules which cycle }
    HAS_CYCLE { Does this grammar have a cycle? }
    TRACE_FILE_HANDLE
    STRIP { Boolean.  If true, strip unused data to save space. }
    LHS_TERMINALS { Boolean.  If true, LHS terminals are allowed. }
    WARNINGS { print warnings about grammar? }
    TRACING { master flag, set if any tracing is being done
    (to control overhead for non-tracing processes) }

    =LAST_BASIC_DATA_FIELD

    { === Evaluator Fields === }

    TERMINAL_NAMES { hash of terminal symbols, by name }
    SYMBOL_HASH { hash to symbol ID by name of symbol refs }
    DEFAULT_NULL_VALUE { default value for nulled symbols }
    ACTION_OBJECT
    INFINITE_ACTION
    IS_INFINITE

    =LAST_EVALUATOR_FIELD

    PROBLEMS { fatal problems }
    START_STATES { ref to array of the start states }
    ACADEMIC { true if this is a textbook grammar,
    for checking the NFA and AHFA, and NOT
    for actual Earley parsing }

    =LAST_RECOGNIZER_FIELD

    RULE_SIGNATURE_HASH
    START { ref to start symbol }
    START_NAME { name of original symbol }
    NFA { array of states }
    AHFA_BY_NAME { hash from AHFA name to AHFA reference }
    NULLABLE_SYMBOL { array of refs of the nullable symbols }
    INACCESSIBLE_OK
    UNPRODUCTIVE_OK
    TRACE_RULES

    =LAST_FIELD
);

package Marpa::XS::Internal::Grammar;

use POSIX qw(ceil);

# values for grammar phases
use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Phase
    NEW RULES PRECOMPUTED

);

sub phase_description {
    my $phase = shift;
    return 'grammar without rules'
        if $phase == Marpa::XS::Internal::Phase::NEW;
    return 'grammar with rules entered'
        if $phase == Marpa::XS::Internal::Phase::RULES;
    return 'precomputed grammar'
        if $phase == Marpa::XS::Internal::Phase::PRECOMPUTED;
    return 'unknown phase';
} ## end sub phase_description

package Marpa::XS::Internal::Grammar;

use English qw( -no_match_vars );

use Marpa::XS::Internal::Carp_Not;

# Longest RHS is 2**28-1.  It's 28 bits, not 32, so
# it will fit in the internal priorities computed
# for the CHAF rules
use constant RHS_LENGTH_MASK => ~(0x7ffffff);

sub Marpa::XS::Internal::code_problems {
    my $args = shift;

    my $grammar;
    my $fatal_error;
    my $warnings = [];
    my $where    = '?where?';
    my $long_where;
    my @msg = ();
    my $eval_value;
    my $eval_given = 0;

    push @msg, q{=} x 60, "\n";
    while ( my ( $arg, $value ) = each %{$args} ) {
        given ($arg) {
            when ('fatal_error') { $fatal_error = $value }
            when ('grammar')     { $grammar     = $value }
            when ('where')       { $where       = $value }
            when ('long_where')  { $long_where  = $value }
            when ('warnings')    { $warnings    = $value }
            when ('eval_ok') {
                $eval_value = $value;
                $eval_given = 1;
            }
            default { push @msg, "Unknown argument to code_problems: $arg" };
        } ## end given
    } ## end while ( my ( $arg, $value ) = each %{$args} )

    my @problem_line     = ();
    my $max_problem_line = -1;
    for my $warning_data ( @{$warnings} ) {
        my ( $warning, $package, $filename, $problem_line ) =
            @{$warning_data};
        $problem_line[$problem_line] = 1;
        $max_problem_line = List::Util::max $problem_line, $max_problem_line;
    } ## end for my $warning_data ( @{$warnings} )

    $long_where //= $where;

    my $warnings_count = scalar @{$warnings};
    {
        my @problems;
        my $false_eval = $eval_given && !$eval_value && !$fatal_error;
        if ($false_eval) {
            push @problems, '* THE MARPA SEMANTICS RETURNED A PERL FALSE',
                'Marpa::XS requires its semantics to return a true value';
        }
        if ($fatal_error) {
            push @problems, '* THE MARPA SEMANTICS PRODUCED A FATAL ERROR';
        }
        if ($warnings_count) {
            push @problems,
                "* THERE WERE $warnings_count WARNING(S) IN THE MARPA SEMANTICS:",
                'Marpa::XS treats warnings as fatal errors';
        }
        if ( not scalar @problems ) {
            push @msg, '* THERE WAS A FATAL PROBLEM IN THE MARPA SEMANTICS';
        }
        push @msg, ( join "\n", @problems ) . "\n";
    }

    push @msg, "* THIS IS WHAT MARPA WAS DOING WHEN THE PROBLEM OCCURRED:\n"
        . $long_where . "\n";

    for my $warning_ix ( 0 .. ( $warnings_count - 1 ) ) {
        push @msg, "* WARNING MESSAGE NUMBER $warning_ix:\n";
        my $warning_message = $warnings->[$warning_ix]->[0];
        $warning_message =~ s/\n*\z/\n/xms;
        push @msg, $warning_message;
    } ## end for my $warning_ix ( 0 .. ( $warnings_count - 1 ) )

    if ($fatal_error) {
        push @msg, "* THIS WAS THE FATAL ERROR MESSAGE:\n";
        my $fatal_error_message = $fatal_error;
        $fatal_error_message =~ s/\n*\z/\n/xms;
        push @msg, $fatal_error_message;
    } ## end if ($fatal_error)

    push @msg, q{* ONE PLACE TO LOOK FOR THE PROBLEM IS IN THE CODE};
    Marpa::XS::exception(@msg);
} ## end sub Marpa::XS::Internal::code_problems

package Marpa::XS::Internal::Grammar;

sub Marpa::XS::Grammar::new {
    my ( $class, @arg_hashes ) = @_;

    my $grammar = [];
    bless $grammar, $class;

    # set the defaults and the default defaults
    $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE] = *STDERR;

    $grammar->[Marpa::XS::Internal::Grammar::ACADEMIC]        = 0;
    $grammar->[Marpa::XS::Internal::Grammar::LHS_TERMINALS]   = 1;
    $grammar->[Marpa::XS::Internal::Grammar::TRACE_RULES]     = 0;
    $grammar->[Marpa::XS::Internal::Grammar::TRACING]         = 0;
    $grammar->[Marpa::XS::Internal::Grammar::STRIP]           = 1;
    $grammar->[Marpa::XS::Internal::Grammar::WARNINGS]        = 1;
    $grammar->[Marpa::XS::Internal::Grammar::INACCESSIBLE_OK] = {};
    $grammar->[Marpa::XS::Internal::Grammar::UNPRODUCTIVE_OK] = {};
    $grammar->[Marpa::XS::Internal::Grammar::INFINITE_ACTION] = 'fatal';

    $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS]             = [];
    $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH]         = {};
    $grammar->[Marpa::XS::Internal::Grammar::RULES]               = [];
    $grammar->[Marpa::XS::Internal::Grammar::RULE_SIGNATURE_HASH] = {};
    $grammar->[Marpa::XS::Internal::Grammar::AHFA_BY_NAME]        = {};
    $grammar->[Marpa::XS::Internal::Grammar::PHASE] =
        Marpa::XS::Internal::Phase::NEW;

    $grammar->set(@arg_hashes);
    return $grammar;
} ## end sub Marpa::XS::Grammar::new

# For use some day to make locator() more efficient on repeated calls
sub binary_search {
    my ( $target, $data ) = @_;
    my ( $lower, $upper ) = ( 0, $#{$data} );
    while ( $lower <= $upper ) {
        my $i = int +( ( $lower + $upper ) / 2 );
        given ( $data->[$i] ) {
            when ( $_ < $target ) { $lower = $i; }
            when ( $_ > $target ) { $upper = $i; }
            default               { return $i };
        }
    } ## end while ( $lower <= $upper )
    return $lower;
} ## end sub binary_search

sub locator {
    my $earleme = shift;
    my $string  = shift;

    my $lines;
    $lines //= [0];
    my $pos = pos ${$string} = 0;
    NL: while ( ${$string} =~ /\n/gxms ) {
        $pos = pos ${$string};
        push @{$lines}, $pos;
        last NL if $pos > $earleme;
    }
    my $line = ( @{$lines} ) - ( $pos > $earleme ? 2 : 1 );
    my $line_start = $lines->[$line];
    return ( $line, $line_start );
} ## end sub locator

sub Marpa::XS::show_location {
    my ( $msg, $source, $earleme ) = @_;
    my $result = q{};

    my ( $line, $line_start ) = locator( $earleme, $source );
    $result .= $msg . ' at line ' . ( $line + 1 ) . ", earleme $earleme\n";
    given ( index ${$source}, "\n", $line_start ) {
        when (undef) {
            $result .= ( substr ${$source}, $line_start ) . "\n";
        }
        default {
            $result .= ( substr ${$source}, $line_start, $_ - $line_start )
                . "\n";
        }
    } ## end given
    $result .= ( q{ } x ( $earleme - $line_start ) ) . "^\n";
    return $result;
} ## end sub Marpa::XS::show_location

use constant GRAMMAR_OPTIONS => [
    qw{
        academic
        action_object
        actions
        cycle_ranking_action
        infinite_action
        default_action
        default_null_value
        inaccessible_ok
        lhs_terminals
        rules
        start
        strip
        symbols
        terminals
        trace_file_handle
        trace_rules
        unproductive_ok
        warnings
        }
];

sub Marpa::XS::Grammar::set {
    my ( $grammar, @arg_hashes ) = @_;

    # set trace_fh even if no tracing, because we may turn it on in this method
    my $trace_fh =
        $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];
    my $tracing = $grammar->[Marpa::XS::Internal::Grammar::TRACING];
    my $phase   = $grammar->[Marpa::XS::Internal::Grammar::PHASE];

    for my $args (@arg_hashes) {

        my $ref_type = ref $args;
        if ( not $ref_type or $ref_type ne 'HASH' ) {
            Carp::croak(
                'Marpa::XS Grammar expects args as ref to HASH, got ',
                ( "ref to $ref_type" || 'non-reference' ),
                ' instead'
            );
        } ## end if ( not $ref_type or $ref_type ne 'HASH' )
        if (my @bad_options =
            grep { not $_ ~~ Marpa::XS::Internal::Grammar::GRAMMAR_OPTIONS }
            keys %{$args}
            )
        {
            Carp::croak( 'Unknown option(s) for Marpa::XS Grammar: ',
                join q{ }, @bad_options );
        } ## end if ( my @bad_options = grep { not $_ ~~ ...})

        if ( defined( my $value = $args->{'trace_file_handle'} ) ) {
            $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE] =
                $value;
        }

        if ( defined( my $value = $args->{'trace_rules'} ) ) {
            $grammar->[Marpa::XS::Internal::Grammar::TRACE_RULES] = $value;
            if ($value) {
                my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
                my $rule_count = @{$rules};
                say {$trace_fh} 'Setting trace_rules'
                    or Marpa::XS::exception("Could not print: $ERRNO");
                if ($rule_count) {
                    say {$trace_fh}
                        "Warning: Setting trace_rules after $rule_count rules have been defined"
                        or Marpa::XS::exception("Could not print: $ERRNO");
                }
                $grammar->[Marpa::XS::Internal::Grammar::TRACING] = 1;
            } ## end if ($value)
        } ## end if ( defined( my $value = $args->{'trace_rules'} ) )

        # First pass options: These affect processing of other
        # options and are expected to take force for the other
        # options, even if specified afterwards

        # Second pass options
        if ( defined( my $value = $args->{'symbols'} ) ) {
            Marpa::XS::exception(
                'symbols option not allowed after grammar is precomputed')
                if $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED;
            Marpa::XS::exception('symbols value must be REF to HASH')
                if ref $value ne 'HASH';
            while ( my ( $symbol, $properties ) = each %{$value} ) {
                assign_user_symbol( $grammar, $symbol, $properties );
            }
            $phase = $grammar->[Marpa::XS::Internal::Grammar::PHASE] =
                Marpa::XS::Internal::Phase::RULES;
        } ## end if ( defined( my $value = $args->{'symbols'} ) )

        if ( defined( my $value = $args->{'lhs_terminals'} ) ) {
            Marpa::XS::exception(
                'lhs_terminals option not allowed after grammar is precomputed'
            ) if $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED;
            $grammar->[Marpa::XS::Internal::Grammar::LHS_TERMINALS] = $value;
            $phase = $grammar->[Marpa::XS::Internal::Grammar::PHASE] =
                Marpa::XS::Internal::Phase::RULES;
        } ## end if ( defined( my $value = $args->{'lhs_terminals'} ))

        if ( defined( my $value = $args->{'terminals'} ) ) {
            Marpa::XS::exception(
                'terminals option not allowed after grammar is precomputed')
                if $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED;
            Marpa::XS::exception('terminals value must be REF to ARRAY')
                if ref $value ne 'ARRAY';
            for my $symbol ( @{$value} ) {
                assign_user_symbol( $grammar, $symbol, { terminal => 1 } );
            }
            $phase = $grammar->[Marpa::XS::Internal::Grammar::PHASE] =
                Marpa::XS::Internal::Phase::RULES;
        } ## end if ( defined( my $value = $args->{'terminals'} ) )

        if ( defined( my $value = $args->{'start'} ) ) {
            Marpa::XS::exception(
                'start option not allowed after grammar is precomputed')
                if $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED;
            $grammar->[Marpa::XS::Internal::Grammar::START_NAME] = $value;
        } ## end if ( defined( my $value = $args->{'start'} ) )

        if ( defined( my $value = $args->{'rules'} ) ) {
            Marpa::XS::exception(
                'rules option not allowed after grammar is precomputed')
                if $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED;
            Marpa::XS::exception('rules value must be reference to array')
                if ref $value ne 'ARRAY';
            add_user_rules( $grammar, $value );
            $phase = $grammar->[Marpa::XS::Internal::Grammar::PHASE] =
                Marpa::XS::Internal::Phase::RULES;
        } ## end if ( defined( my $value = $args->{'rules'} ) )

        if ( defined( my $value = $args->{'academic'} ) ) {
            Marpa::XS::exception(
                'academic option not allowed after grammar is precomputed')
                if $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED;
            $grammar->[Marpa::XS::Internal::Grammar::ACADEMIC] = $value;
        } ## end if ( defined( my $value = $args->{'academic'} ) )

        if ( defined( my $value = $args->{'default_null_value'} ) ) {
            $grammar->[Marpa::XS::Internal::Grammar::DEFAULT_NULL_VALUE] =
                $value;
        }

        if ( defined( my $value = $args->{'actions'} ) ) {
            $grammar->[Marpa::XS::Internal::Grammar::ACTIONS] = $value;
        }

        if ( defined( my $value = $args->{'action_object'} ) ) {
            $grammar->[Marpa::XS::Internal::Grammar::ACTION_OBJECT] = $value;
        }

        if ( defined( my $value = $args->{'cycle_ranking_action'} ) ) {
            $grammar->[Marpa::XS::Internal::Grammar::CYCLE_RANKING_ACTION] =
                $value;
        }

        if ( defined( my $value = $args->{'default_action'} ) ) {
            $grammar->[Marpa::XS::Internal::Grammar::DEFAULT_ACTION] = $value;
        }

        if ( defined( my $value = $args->{'strip'} ) ) {
            $grammar->[Marpa::XS::Internal::Grammar::STRIP] = $value;
        }

        if ( defined( my $value = $args->{'infinite_action'} ) ) {
            if ( $value && $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED )
            {
                say {$trace_fh}
                    '"infinite_action" option is useless after grammar is precomputed'
                    or Marpa::XS::exception("Could not print: $ERRNO");
            } ## end if ( $value && $phase >= ...)
            Marpa::XS::exception(
                q{infinite_action must be 'warn', 'quiet' or 'fatal'})
                if not $value ~~ [qw(warn quiet fatal)];
            $grammar->[Marpa::XS::Internal::Grammar::INFINITE_ACTION] =
                $value;
        } ## end if ( defined( my $value = $args->{'infinite_action'}...))

        if ( defined( my $value = $args->{'warnings'} ) ) {
            if ( $value && $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED )
            {
                say {$trace_fh}
                    q{"warnings" option is useless after grammar is precomputed}
                    or Marpa::XS::exception("Could not print: $ERRNO");
            } ## end if ( $value && $phase >= ...)
            $grammar->[Marpa::XS::Internal::Grammar::WARNINGS] = $value;
        } ## end if ( defined( my $value = $args->{'warnings'} ) )

        if ( defined( my $value = $args->{'inaccessible_ok'} ) ) {
            if ( $value && $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED )
            {
                say {$trace_fh}
                    q{"inaccessible_ok" option is useless after grammar is precomputed}
                    or Marpa::XS::exception("Could not print: $ERRNO");

            } ## end if ( $value && $phase >= ...)
            given ( ref $value ) {
                when (q{}) {
                    $value //= {
                    }
                }
                when ('ARRAY') {
                    $value = {
                        map { ( $_, 1 ) } @{$value}
                    }
                }
                default {
                    Marpa::XS::exception(
                        'value of inaccessible_ok option must be boolean or an array ref'
                        )
                }
            } ## end given
            $grammar->[Marpa::XS::Internal::Grammar::INACCESSIBLE_OK] =
                $value;
        } ## end if ( defined( my $value = $args->{'inaccessible_ok'}...))

        if ( defined( my $value = $args->{'unproductive_ok'} ) ) {
            if ( $value && $phase >= Marpa::XS::Internal::Phase::PRECOMPUTED )
            {
                say {$trace_fh}
                    q{"unproductive_ok" option is useless after grammar is precomputed}
                    or Marpa::XS::exception("Could not print: $ERRNO");
            } ## end if ( $value && $phase >= ...)
            given ( ref $value ) {
                when (q{}) {
                    $value //= {
                    };
                }
                when ('ARRAY') {
                    $value = {
                        map { ( $_, 1 ) } @{$value}
                    }
                }
                default {
                    Marpa::XS::exception(
                        'value of unproductive_ok option must be boolean or an array ref'
                        )
                }
            } ## end given
            $grammar->[Marpa::XS::Internal::Grammar::UNPRODUCTIVE_OK] =
                $value;
        } ## end if ( defined( my $value = $args->{'unproductive_ok'}...))

    } ## end for my $args (@arg_hashes)

    return 1;
} ## end sub Marpa::XS::Grammar::set

=begin Implementation:

In order to automatically ELIMINATE inaccessible and unproductive
productions from a grammar, you have to first eliminate the
unproductive productions, THEN the inaccessible ones.  I don't do
this in the below.

The reason is my purposes are primarily diagnostic.  The difference
shows in the case of an unproductive start symbol.  Following the
correct procedure for automatically cleaning the grammar, I would
have to regard the start symbol and its productions as eliminated
and therefore go on to report every other production and symbol as
inaccessible.  Almost certainly all these inaccessiblity reports,
while theoretically correct, are irrelevant, since the user will
probably respond by making the start symbol productive, and the
extra "information" would only get in the way.

The downside is that in a few uncommon cases, a user relying entirely
on the Marpa::XS warnings to clean up his grammar will have to go through
more than a single pass of the diagnostics.  I think even those
users will prefer less cluttered diagnostics, and I'm sure most
users will.

=end Implementation:

=cut

sub Marpa::XS::Grammar::precompute {
    my $grammar = shift;

    my $tracing = $grammar->[Marpa::XS::Internal::Grammar::TRACING];
    my $trace_fh =
        $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];

    my $problems = $grammar->[Marpa::XS::Internal::Grammar::PROBLEMS];
    if ($problems) {
        Marpa::XS::exception(
            Marpa::XS::Grammar::show_problems($grammar),
            "Second attempt to precompute grammar with fatal problems\n",
            'Marpa::XS cannot proceed'
        );
    } ## end if ($problems)

    my $phase = $grammar->[Marpa::XS::Internal::Grammar::PHASE];

    # Be idempotent.  If the grammar is already precomputed, just
    # return success without doing anything.
    if ( $phase == Marpa::XS::Internal::Phase::PRECOMPUTED ) {
        return $grammar;
    }

    if ( $phase != Marpa::XS::Internal::Phase::RULES ) {
        Marpa::XS::exception(
            "Attempt to precompute grammar in inappropriate state\nAttempt to precompute ",
            phase_description($phase)
        );
    } ## end if ( $phase != Marpa::XS::Internal::Phase::RULES )

    SET_TERMINALS: {
        my $lhs_terminals_ok =
            $grammar->[Marpa::XS::Internal::Grammar::LHS_TERMINALS];
        my $distinguished = terminals_distinguished($grammar);
        if ( $distinguished and not $lhs_terminals_ok ) {
            check_lhs_non_terminal($grammar);
            last SET_TERMINALS;
        }
        last SET_TERMINALS if $distinguished;
        if ( not $lhs_terminals_ok ) {
            mark_non_lhs_terminal($grammar);
            last SET_TERMINALS;
        }
        if ( has_empty_rule($grammar) ) {
            Marpa::XS::exception(
                'A grammar with empty rules must mark its terminals or unset lhs_terminals'
            );
        }
        mark_all_symbols_terminal($grammar);
    } ## end SET_TERMINALS:

    nulling($grammar);
    nullable($grammar) or return $grammar;
    productive($grammar);
    check_start($grammar) or return $grammar;
    accessible($grammar);
    if ( $grammar->[Marpa::XS::Internal::Grammar::ACADEMIC] ) {
        setup_academic_grammar($grammar);
    }
    else {
        rewrite_as_CHAF($grammar);
        detect_infinite($grammar);
    }
    create_NFA($grammar);
    create_AHFA($grammar);
    mark_leo_states($grammar);

    $grammar->[Marpa::XS::Internal::Grammar::TERMINAL_NAMES] = {
        map { ( $_->[Marpa::XS::Internal::Symbol::NAME] => 1 ) }
            grep { $_->[Marpa::XS::Internal::Symbol::TERMINAL] }
            @{ $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS] }
    };

    if ($grammar->[Marpa::XS::Internal::Grammar::WARNINGS]
        and ref(
            my $ok = $grammar->[Marpa::XS::Internal::Grammar::INACCESSIBLE_OK]
        ) eq 'HASH'
        )
    {
        SYMBOL:
        for my $symbol (
            @{ Marpa::XS::Grammar::inaccessible_symbols($grammar) } )
        {

            # Inaccessible internal symbols may be created
            # from inaccessible use symbols -- ignore these.
            # This assumes that Marpa::XS's logic
            # is correct and that
            # it is not creating inaccessible symbols from
            # accessible ones.
            next SYMBOL if $symbol =~ /\]/xms;
            next SYMBOL if $ok->{$symbol};
            say {$trace_fh} "Inaccessible symbol: $symbol"
                or Marpa::XS::exception("Could not print: $ERRNO");
        } ## end for my $symbol ( @{ Marpa::XS::Grammar::inaccessible_symbols...})
    } ## end if ( $grammar->[Marpa::XS::Internal::Grammar::WARNINGS...])

    if ($grammar->[Marpa::XS::Internal::Grammar::WARNINGS]
        and ref(
            my $ok = $grammar->[Marpa::XS::Internal::Grammar::UNPRODUCTIVE_OK]
        ) eq 'HASH'
        )
    {
        SYMBOL:
        for my $symbol (
            @{ Marpa::XS::Grammar::unproductive_symbols($grammar) } )
        {

            # Unproductive internal symbols may be created
            # from unproductive use symbols -- ignore these.
            # This assumes that Marpa::XS's logic
            # is correct and that
            # it is not creating unproductive symbols from
            # productive ones.
            next SYMBOL if $symbol =~ /\]/xms;
            next SYMBOL if $ok->{$symbol};
            say {$trace_fh} "Unproductive symbol: $symbol"
                or Marpa::XS::exception("Could not print: $ERRNO");
        } ## end for my $symbol ( @{ Marpa::XS::Grammar::unproductive_symbols...})
    } ## end if ( $grammar->[Marpa::XS::Internal::Grammar::WARNINGS...])

    if ( $grammar->[Marpa::XS::Internal::Grammar::WARNINGS] ) {
        SYMBOL:
        for my $symbol (
            @{ $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS] } )
        {

            next SYMBOL
                if not $symbol
                    ->[Marpa::XS::Internal::Symbol::WARN_IF_NO_NULL_VALUE];
            next SYMBOL
                if $symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE];
            my $symbol_name = $symbol->[Marpa::XS::Internal::Symbol::NAME];
            say {$trace_fh}
                qq{Zero length sequence for symbol without null value: "$symbol_name"}
                or Marpa::XS::exception("Could not print: $ERRNO");
        } ## end for my $symbol ( @{ $grammar->[...]})
    } ## end if ( $grammar->[Marpa::XS::Internal::Grammar::WARNINGS...])

    $grammar->[Marpa::XS::Internal::Grammar::PHASE] =
        Marpa::XS::Internal::Phase::PRECOMPUTED;

    if ( $grammar->[Marpa::XS::Internal::Grammar::STRIP] ) {

        $#{$grammar} = Marpa::XS::Internal::Grammar::LAST_RECOGNIZER_FIELD;

        for my $symbol (
            @{ $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS] } )
        {
            $#{$symbol} = Marpa::XS::Internal::Symbol::LAST_RECOGNIZER_FIELD;
        }

        for my $rule ( @{ $grammar->[Marpa::XS::Internal::Grammar::RULES] } )
        {
            $#{$rule} = Marpa::XS::Internal::Rule::LAST_RECOGNIZER_FIELD;
        }

        for my $AHFA ( @{ $grammar->[Marpa::XS::Internal::Grammar::AHFA] } ) {
            $#{$AHFA} = Marpa::XS::Internal::AHFA::LAST_RECOGNIZER_FIELD;
        }

    } ## end if ( $grammar->[Marpa::XS::Internal::Grammar::STRIP])

    return $grammar;

} ## end sub Marpa::XS::Grammar::precompute

sub Marpa::XS::Grammar::show_problems {
    my ($grammar) = @_;

    my $problems = $grammar->[Marpa::XS::Internal::Grammar::PROBLEMS];
    if ($problems) {
        my $problem_count = scalar @{$problems};
        return
            "Grammar has $problem_count problems:\n"
            . ( join "\n", @{$problems} ) . "\n";
    } ## end if ($problems)
    return "Grammar has no problems\n";
} ## end sub Marpa::XS::Grammar::show_problems

sub Marpa::XS::show_symbol {
    my ($symbol) = @_;
    my $text     = q{};
    my $stripped = $#{$symbol} < Marpa::XS::Internal::Symbol::LAST_FIELD;

    my $name = $symbol->[Marpa::XS::Internal::Symbol::NAME];
    $text .= sprintf '%d: %s,', $symbol->[Marpa::XS::Internal::Symbol::ID],
        $name;

    if ($stripped) { $text .= ' stripped' }
    else {
        $text .= sprintf ' lhs=[%s]',
            join q{ },
            @{ $symbol->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] };

        $text .= sprintf ' rhs=[%s]',
            join q{ },
            @{ $symbol->[Marpa::XS::Internal::Symbol::RH_RULE_IDS] };

    } ## end else [ if ($stripped) ]

    my $nullable = $symbol->[Marpa::XS::Internal::Symbol::NULLABLE];
    if ($nullable) {
        $text .= " nullable";
    }

    ELEMENT:
    for my $comment_element (
        (   [ 1, 'unproductive', Marpa::XS::Internal::Symbol::PRODUCTIVE, ],
            [ 1, 'inaccessible', Marpa::XS::Internal::Symbol::ACCESSIBLE, ],
            [ 0, 'nulling',      Marpa::XS::Internal::Symbol::NULLING, ],
            [ 0, 'terminal',     Marpa::XS::Internal::Symbol::TERMINAL, ],
        )
        )
    {
        my ( $reverse, $comment, $offset ) = @{$comment_element};
        next ELEMENT if not exists $symbol->[$offset];
        my $value = $symbol->[$offset];
        if ($reverse) { $value = !$value }
        if ($value) { $text .= " $comment" }
    } ## end for my $comment_element ( ( [ 1, 'unproductive', ...]))

    $text .= "\n";
    return $text;

} ## end sub Marpa::XS::show_symbol

sub Marpa::XS::Grammar::show_symbols {
    my ($grammar) = @_;
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $text      = q{};
    for my $symbol_ref ( @{$symbols} ) {
        $text .= Marpa::XS::show_symbol($symbol_ref);
    }
    return $text;
} ## end sub Marpa::XS::Grammar::show_symbols

sub Marpa::XS::Grammar::show_nulling_symbols {
    my ($grammar) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return 'stripped_'
        if scalar grep { $#{$_} < Marpa::XS::Internal::Symbol::LAST_FIELD }
            @{$symbols};
    return join q{ }, sort map { $_->[Marpa::XS::Internal::Symbol::NAME] }
        grep { $_->[Marpa::XS::Internal::Symbol::NULLING] } @{$symbols};
} ## end sub Marpa::XS::Grammar::show_nulling_symbols

sub Marpa::XS::Grammar::show_nullable_symbols {
    my ($grammar) = @_;
    return 'stripped_'
        if not
            exists $grammar->[Marpa::XS::Internal::Grammar::NULLABLE_SYMBOL];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::NULLABLE_SYMBOL];
    return join q{ },
        sort map { $_->[Marpa::XS::Internal::Symbol::NAME] } @{$symbols};
} ## end sub Marpa::XS::Grammar::show_nullable_symbols

sub Marpa::XS::Grammar::show_productive_symbols {
    my ($grammar) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return 'stripped_'
        if scalar grep { $#{$_} < Marpa::XS::Internal::Symbol::LAST_FIELD }
            @{$symbols};
    return join q{ }, sort map { $_->[Marpa::XS::Internal::Symbol::NAME] }
        grep { $_->[Marpa::XS::Internal::Symbol::PRODUCTIVE] } @{$symbols};
} ## end sub Marpa::XS::Grammar::show_productive_symbols

sub Marpa::XS::Grammar::show_accessible_symbols {
    my ($grammar) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return 'stripped_'
        if scalar grep { $#{$_} < Marpa::XS::Internal::Symbol::LAST_FIELD }
            @{$symbols};
    return join q{ }, sort map { $_->[Marpa::XS::Internal::Symbol::NAME] }
        grep { $_->[Marpa::XS::Internal::Symbol::ACCESSIBLE] } @{$symbols};
} ## end sub Marpa::XS::Grammar::show_accessible_symbols

sub Marpa::XS::Grammar::inaccessible_symbols {
    my ($grammar) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return [
        sort map { $_->[Marpa::XS::Internal::Symbol::NAME] }
            grep { !$_->[Marpa::XS::Internal::Symbol::ACCESSIBLE] }
            @{$symbols}
    ];
} ## end sub Marpa::XS::Grammar::inaccessible_symbols

sub Marpa::XS::Grammar::unproductive_symbols {
    my ($grammar) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return [
        sort map { $_->[Marpa::XS::Internal::Symbol::NAME] }
            grep { !$_->[Marpa::XS::Internal::Symbol::PRODUCTIVE] }
            @{$symbols}
    ];
} ## end sub Marpa::XS::Grammar::unproductive_symbols

sub Marpa::XS::brief_rule {
    my ($rule) = @_;
    my ( $lhs, $rhs, $rule_id ) = @{$rule}[
        Marpa::XS::Internal::Rule::LHS, Marpa::XS::Internal::Rule::RHS,
        Marpa::XS::Internal::Rule::ID
    ];
    my $text .= $rule_id . ': '
        . $lhs->[Marpa::XS::Internal::Symbol::NAME] . ' ->';
    if ( @{$rhs} ) {
        $text .= q{ }
            . (
            join q{ }, map { $_->[Marpa::XS::Internal::Symbol::NAME] } @{$rhs}
            );
    } ## end if ( @{$rhs} )
    return $text;
} ## end sub Marpa::XS::brief_rule

sub Marpa::XS::brief_original_rule {
    my ($rule) = @_;
    my $original_rule = $rule->[Marpa::XS::Internal::Rule::ORIGINAL_RULE]
        // $rule;
    return Marpa::XS::brief_rule($original_rule);
} ## end sub Marpa::XS::brief_original_rule

sub Marpa::XS::brief_virtual_rule {
    my ( $rule, $dot_position ) = @_;
    my $original_rule = $rule->[Marpa::XS::Internal::Rule::ORIGINAL_RULE];
    if ( not defined $original_rule ) {
        return Marpa::XS::show_dotted_rule( $rule, $dot_position )
            if defined $dot_position;
        return Marpa::XS::brief_rule($rule);
    }

    my $rule_id          = $rule->[Marpa::XS::Internal::Rule::ID];
    my $original_rule_id = $original_rule->[Marpa::XS::Internal::Rule::ID];
    my $original_lhs     = $original_rule->[Marpa::XS::Internal::Rule::LHS];
    my $chaf_rhs         = $rule->[Marpa::XS::Internal::Rule::RHS];
    my $original_rhs     = $original_rule->[Marpa::XS::Internal::Rule::RHS];
    my $chaf_start       = $rule->[Marpa::XS::Internal::Rule::VIRTUAL_START];
    my $chaf_end         = $rule->[Marpa::XS::Internal::Rule::VIRTUAL_END];

    if ( not defined $chaf_start ) {
        return "dot at $dot_position, virtual "
            . Marpa::XS::brief_rule($original_rule)
            if defined $dot_position;
        return 'virtual ' . Marpa::XS::brief_rule($original_rule);
    } ## end if ( not defined $chaf_start )

    my $text .= "(part of $original_rule_id) ";
    $text .= $original_lhs->[Marpa::XS::Internal::Symbol::NAME] . ' ->';
    my @rhs_names =
        map { $_->[Marpa::XS::Internal::Symbol::NAME] } @{$original_rhs};

    my @chaf_symbol_start;
    my @chaf_symbol_end;

    # Mark the beginning and end of the non-CHAF symbols
    # in the CHAF rule.
    for my $chaf_ix ( $chaf_start .. $chaf_end ) {
        $chaf_symbol_start[$chaf_ix] = 1;
        $chaf_symbol_end[ $chaf_ix + 1 ] = 1;
    }

    # Mark the beginning and special CHAF symbol
    # for the "rest" of the rule.
    if ( $chaf_end < $#rhs_names ) {
        $chaf_symbol_start[ $chaf_end + 1 ] = 1;
        $chaf_symbol_end[ scalar @rhs_names ] = 1;
    }

    $dot_position =
        $dot_position >= scalar @{$chaf_rhs}
        ? scalar @rhs_names
        : ( $chaf_start + $dot_position );

    for ( 0 .. scalar @rhs_names ) {
        when ( defined $chaf_symbol_end[$_] )   { $text .= ' >';  continue }
        when ($dot_position)                    { $text .= q{ .}; continue; }
        when ( defined $chaf_symbol_start[$_] ) { $text .= ' <';  continue }
        when ( $_ < scalar @rhs_names ) {
            $text .= q{ } . $rhs_names[$_]
        }
    } ## end for ( 0 .. scalar @rhs_names )

    return $text;

} ## end sub Marpa::XS::brief_virtual_rule

sub Marpa::XS::show_rule {
    my ($rule) = @_;

    my $stripped = $#{$rule} < Marpa::XS::Internal::Rule::LAST_FIELD;
    my $rhs      = $rule->[Marpa::XS::Internal::Rule::RHS];
    my @comment  = ();

    if ( not( @{$rhs} ) ) { push @comment, 'empty'; }

    if ($stripped) { push @comment, 'stripped'; }

    ELEMENT:
    for my $comment_element (
        (   [ 1, '!used',        Marpa::XS::Internal::Rule::USED, ],
            [ 1, 'unproductive', Marpa::XS::Internal::Rule::PRODUCTIVE, ],
            [ 1, 'inaccessible', Marpa::XS::Internal::Rule::ACCESSIBLE, ],
            [ 0, 'vlhs',         Marpa::XS::Internal::Rule::VIRTUAL_LHS, ],
            [ 0, 'vrhs',         Marpa::XS::Internal::Rule::VIRTUAL_RHS, ],
            [   0, 'discard_sep',
                Marpa::XS::Internal::Rule::DISCARD_SEPARATION,
            ],
        )
        )
    {
        my ( $reverse, $comment, $offset ) = @{$comment_element};
        next ELEMENT if not exists $rule->[$offset];
        my $value = $rule->[$offset];
        if ($reverse) { $value = !$value }
        next ELEMENT if not $value;
        push @comment, $comment;
    } ## end for my $comment_element ( ( [ 1, '!used', ...]))

    if (   $rule->[Marpa::XS::Internal::Rule::VIRTUAL_LHS]
        or $rule->[Marpa::XS::Internal::Rule::VIRTUAL_RHS] )
    {
        push @comment, sprintf 'real=%d',
            $rule->[Marpa::XS::Internal::Rule::REAL_SYMBOL_COUNT];
    } ## end if ( $rule->[Marpa::XS::Internal::Rule::VIRTUAL_LHS]...)

    my $text = Marpa::XS::brief_rule($rule);

    if (@comment) {
        $text .= q{ } . ( join q{ }, q{/*}, @comment, q{*/} );
    }

    return $text .= "\n";

}    # sub show_rule

sub Marpa::XS::Grammar::show_rules {
    my ($grammar) = @_;
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $text;

    for my $rule ( @{$rules} ) {
        $text .= Marpa::XS::show_rule($rule);
    }
    return $text;
} ## end sub Marpa::XS::Grammar::show_rules

sub Marpa::XS::show_dotted_rule {
    my ( $rule, $dot_position ) = @_;

    my $text =
        $rule->[Marpa::XS::Internal::Rule::LHS]
        ->[Marpa::XS::Internal::Symbol::NAME] . q{ ->};

    # In the bocage, when we are starting a rule and
    # there is no current symbol, the position may
    # be -1.
    # Position has different semantics in the bocage, than in an LR-item.
    # In the bocage, the position is *AT* a symbol.
    # In the bocage the position is the number OF the current symbol.
    # An LR-item the position how far into the rule parsing has
    # proceded and is therefore between symbols (or at the end
    # or beginning or a rule).
    # Usually bocage position is one less than the analagous
    # LR-item position.
    if ( $dot_position < 0 ) {
        $text .= q{ !};
    }

    my @rhs_names =
        map { $_->[Marpa::XS::Internal::Symbol::NAME] }
        @{ $rule->[Marpa::XS::Internal::Rule::RHS] };

    POSITION: for my $position ( 0 .. scalar @rhs_names ) {
        if ( $position == $dot_position ) {
            $text .= q{ .};
        }
        my $name = $rhs_names[$position];
        next POSITION if not defined $name;
        $text .= " $name";
    } ## end for my $position ( 0 .. scalar @rhs_names )

    return $text;

} ## end sub Marpa::XS::show_dotted_rule

sub Marpa::XS::show_item {
    my ($item) = @_;
    my $text = q{};
    if ( not defined $item ) {
        $text .= '/* empty */';
    }
    else {
        $text .= Marpa::XS::show_dotted_rule(
            @{$item}[
                Marpa::XS::Internal::LR0_item::RULE,
            Marpa::XS::Internal::LR0_item::POSITION
            ]
        );
    } ## end else [ if ( not defined $item ) ]
    return $text;
} ## end sub Marpa::XS::show_item

sub Marpa::XS::show_NFA_state {
    my ($state) = @_;
    my ( $name, $item, $transition, $at_nulling, ) = @{$state}[
        Marpa::XS::Internal::NFA::NAME,
        Marpa::XS::Internal::NFA::ITEM,
        Marpa::XS::Internal::NFA::TRANSITION,
        Marpa::XS::Internal::NFA::AT_NULLING,
    ];
    my $text = $name . ': ';
    $text .= Marpa::XS::show_item($item) . "\n";
    my @properties = ();
    if ($at_nulling) {
        push @properties, 'at_nulling';
    }
    if (@properties) {
        $text .= ( join q{ }, @properties ) . "\n";
    }

    for my $symbol_name ( sort keys %{$transition} ) {
        my $transition_states = $transition->{$symbol_name};
        $text
            .= q{ }
            . ( $symbol_name eq q{} ? 'empty' : '<' . $symbol_name . '>' )
            . ' => '
            . join( q{ },
            map { $_->[Marpa::XS::Internal::NFA::NAME] }
                @{$transition_states} )
            . "\n";
    } ## end for my $symbol_name ( sort keys %{$transition} )
    return $text;
} ## end sub Marpa::XS::show_NFA_state

sub Marpa::XS::Grammar::show_NFA {
    my ($grammar) = @_;
    my $text = q{};

    return "stripped\n"
        if not exists $grammar->[Marpa::XS::Internal::Grammar::NFA];

    my $NFA = $grammar->[Marpa::XS::Internal::Grammar::NFA];
    for my $state ( @{$NFA} ) {
        $text .= Marpa::XS::show_NFA_state($state);
    }

    return $text;
} ## end sub Marpa::XS::Grammar::show_NFA

sub Marpa::XS::brief_AHFA_state {
    my ($state) = @_;
    return 'S' . $state->[Marpa::XS::Internal::AHFA::ID];
}

sub Marpa::XS::show_AHFA_state {
    my ( $state, $verbose ) = @_;
    $verbose //= 1;    # legacy is to be verbose, so default to it

    my $text     = q{};
    my $stripped = $#{$state} < Marpa::XS::Internal::AHFA::LAST_FIELD;

    $text .= Marpa::XS::brief_AHFA_state($state) . ': ';

    if ( $state->[Marpa::XS::Internal::AHFA::LEO_COMPLETION] ) {
        $text .= 'leo-c; ';
    }
    if ( $state->[Marpa::XS::Internal::AHFA::RESET_ORIGIN] ) {
        $text .= 'predict; ';
    }

    $text .= $state->[Marpa::XS::Internal::AHFA::NAME] . "\n";

    if ( exists $state->[Marpa::XS::Internal::AHFA::NFA_STATES] ) {
        my $NFA_states = $state->[Marpa::XS::Internal::AHFA::NFA_STATES];
        for my $NFA_state ( @{$NFA_states} ) {
            my $item = $NFA_state->[Marpa::XS::Internal::NFA::ITEM];
            $text .= Marpa::XS::show_item($item) . "\n";
        }
    } ## end if ( exists $state->[Marpa::XS::Internal::AHFA::NFA_STATES...])

    if ($stripped) { $text .= "stripped\n" }

    return $text if not $verbose;

    if ( exists $state->[Marpa::XS::Internal::AHFA::TRANSITION] ) {
        my $transition = $state->[Marpa::XS::Internal::AHFA::TRANSITION];
        for my $symbol_name ( sort keys %{$transition} ) {
            $text .= ' <' . $symbol_name . '> => ';
            my @ahfa_labels;
            TO_STATE: for my $to_state ( @{ $transition->{$symbol_name} } ) {
                if ( not ref $to_state ) {
                    push @ahfa_labels, qq{leo($to_state)};
                    next TO_STATE;
                }
                my $to_name = $to_state->[Marpa::XS::Internal::AHFA::NAME];
                push @ahfa_labels, Marpa::XS::brief_AHFA_state($to_state);
            }    # for my $to_state
            $text .= join '; ', sort @ahfa_labels;
            $text .= "\n";
        } ## end for my $symbol_name ( sort keys %{$transition} )
    } ## end if ( exists $state->[Marpa::XS::Internal::AHFA::TRANSITION...])

    return $text;
} ## end sub Marpa::XS::show_AHFA_state

sub Marpa::XS::Grammar::show_AHFA {
    my ($grammar) = @_;

    my $text         = q{};
    my $AHFA         = $grammar->[Marpa::XS::Internal::Grammar::AHFA];
    my $start_states = $grammar->[Marpa::XS::Internal::Grammar::START_STATES];
    $text .= 'Start States: ';
    $text .= join '; ',
        sort map { Marpa::XS::brief_AHFA_state($_) } @{$start_states};
    $text .= "\n";

    for my $state ( @{$AHFA} ) {
        $text .= Marpa::XS::show_AHFA_state($state);
    }
    return $text;
} ## end sub Marpa::XS::Grammar::show_AHFA

# Used by lexers to check that symbol is a terminal
sub Marpa::XS::Grammar::check_terminal {
    my ( $grammar, $name ) = @_;
    return 0 if not defined $name;
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $symbol_id   = $symbol_hash->{$name};
    return 0 if not defined $symbol_id;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $symbol  = $symbols->[$symbol_id];
    return 0 if not $symbol->[Marpa::XS::Internal::Symbol::TERMINAL];
    return 1;
} ## end sub Marpa::XS::Grammar::check_terminal

sub assign_symbol {
    my ( $grammar, $name ) = @_;

    my $new         = 0;
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $symbols     = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];

    my $symbol;
    if ( defined( my $symbol_id = $symbol_hash->{$name} ) ) {
        $symbol = $symbols->[$symbol_id];
    }

    if ( not defined $symbol ) {
        $new = 1;
        $#{$symbol} = Marpa::XS::Internal::Symbol::LAST_FIELD;
        $symbol->[Marpa::XS::Internal::Symbol::NAME]        = $name;
        $symbol->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] = [];
        $symbol->[Marpa::XS::Internal::Symbol::RH_RULE_IDS] = [];

        my $symbol_id = @{$symbols};
        push @{$symbols}, $symbol;
        $symbol_hash->{$name} = $symbol->[Marpa::XS::Internal::Symbol::ID] =
            $symbol_id;

    } ## end if ( not defined $symbol )

    return ( $new, $symbol );
} ## end sub assign_symbol

sub assign_user_symbol {
    my $self    = shift;
    my $name    = shift;
    my $options = shift;

    if ( my $type = ref $name ) {
        Marpa::XS::exception(
            "Symbol name was ref to $type; it must be a scalar string");
    }
    Marpa::XS::exception("Symbol name $name ends in ']': that's not allowed")
        if $name =~ /\]\z/xms;
    my ( $new, $symbol ) = assign_symbol( $self, $name );

    my $greed;
    my $ranking_action;
    my $terminal;

    PROPERTY: while ( my ( $property, $value ) = each %{$options} ) {
        if (not $property ~~
            [qw(terminal ranking_action null_value)] )
        {
            Marpa::XS::exception(qq{Unknown symbol property "$property"});
        }
        if ( $property eq 'terminal' ) {
            $symbol->[Marpa::XS::Internal::Symbol::TERMINAL] = $value;
        }
        if ( $property eq 'null_value' ) {
            $symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE] = \$value;
        }
    } ## end while ( my ( $property, $value ) = each %{$options} )

    return $symbol;

} ## end sub assign_user_symbol

sub add_rule {

    my ($arg_hash) = @_;
    my $grammar;
    my $lhs;
    my $rhs;
    my $action;
    my $ranking_action;
    my $greed;
    my $virtual_lhs;
    my $virtual_rhs;
    my $discard_separation;
    my $real_symbol_count;

    while ( my ( $option, $value ) = each %{$arg_hash} ) {
        given ($option) {
            when ('grammar')        { $grammar        = $value }
            when ('lhs')            { $lhs            = $value }
            when ('rhs')            { $rhs            = $value }
            when ('action')         { $action         = $value }
            when ('ranking_action') { $ranking_action = $value }
            when ('virtual_lhs')        { $virtual_lhs        = $value }
            when ('virtual_rhs')        { $virtual_rhs        = $value }
            when ('discard_separation') { $discard_separation = $value }
            when ('real_symbol_count')  { $real_symbol_count  = $value }
            default {
                Marpa::XS::exception("Unknown option in rule: $option");
            };
        } ## end given
    } ## end while ( my ( $option, $value ) = each %{$arg_hash} )

    my $rules       = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $trace_rules = $grammar->[Marpa::XS::Internal::Grammar::TRACE_RULES];
    my $trace_fh =
        $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];

    my $lhs_name = $lhs->[Marpa::XS::Internal::Symbol::NAME];

    {
        my $rhs_length = scalar @{$rhs};
        if ( $rhs_length & Marpa::XS::Internal::Grammar::RHS_LENGTH_MASK ) {
            Marpa::XS::exception(
                "Rule rhs too long\n",
                '  Rule #',
                $#{$rules},
                " has $rhs_length symbols\n",
                '  Rule starts ',
                $lhs_name,
                ' -> ',
                (   join q{ },

                    # Just print the first 5 symbols on the RHS
                    map { $_->[Marpa::XS::Internal::Symbol::NAME] }
                        @{$rhs}[ 0 .. 5 ]
                ),
                " ... \n"
            );
        } ## end if ( $rhs_length & ...)
    }

    my $new_rule_id = @{$rules};
    my $new_rule    = [];
    $#{$new_rule} = Marpa::XS::Internal::Rule::LAST_FIELD;

    my $nulling = @{$rhs} ? undef : 1;

    if ( $action and $nulling ) {
        Marpa::XS::exception(
            "Empty Rule cannot have an action\n",
            '  Rule #',
            $#{$rules},
            ': ',
            $lhs->[Marpa::XS::Internal::Symbol::NAME],
            ' -> /* empty */',
            "\n"
        );
    } ## end if ( $action and $nulling )

    $new_rule->[Marpa::XS::Internal::Rule::ID]             = $new_rule_id;
    $new_rule->[Marpa::XS::Internal::Rule::LHS]            = $lhs;
    $new_rule->[Marpa::XS::Internal::Rule::RHS]            = $rhs;
    $new_rule->[Marpa::XS::Internal::Rule::ACTION]         = $action;
    $new_rule->[Marpa::XS::Internal::Rule::RANKING_ACTION] = $ranking_action;
    $new_rule->[Marpa::XS::Internal::Rule::VIRTUAL_LHS] = $virtual_lhs;
    $new_rule->[Marpa::XS::Internal::Rule::VIRTUAL_RHS] = $virtual_rhs;
    $new_rule->[Marpa::XS::Internal::Rule::DISCARD_SEPARATION] =
        $discard_separation;
    $new_rule->[Marpa::XS::Internal::Rule::REAL_SYMBOL_COUNT] =
        $real_symbol_count;

    push @{$rules}, $new_rule;
    {
        my $lhs_rule_ids = $lhs->[Marpa::XS::Internal::Symbol::LH_RULE_IDS];
        push @{$lhs_rule_ids}, $new_rule_id;
    }

    SYMBOL: for my $symbol ( @{$rhs} ) {
        my $rhs_rule_ids =
            $symbol->[Marpa::XS::Internal::Symbol::RH_RULE_IDS];
        next SYMBOL if $new_rule_id ~~ @{$rhs_rule_ids};
        push @{$rhs_rule_ids}, $new_rule_id;
    } ## end for my $symbol ( @{$rhs} )

    if ($trace_rules) {
        print {$trace_fh} 'Added rule #', $#{$rules}, ': ',
            $lhs->[Marpa::XS::Internal::Symbol::NAME], ' -> ',
            join( q{ },
            map { $_->[Marpa::XS::Internal::Symbol::NAME] } @{$rhs} ),
            "\n"
            or Marpa::XS::exception("Could not print: $ERRNO");
    } ## end if ($trace_rules)
    return $new_rule;
} ## end sub add_rule

# add one or more rules
sub add_user_rules {
    my ( $grammar, $rules ) = @_;

    RULE: for my $rule ( @{$rules} ) {

        given ( ref $rule ) {
            when ('ARRAY') {
                my $arg_count = @{$rule};

                if ( $arg_count > 4 or $arg_count < 1 ) {
                    Marpa::XS::exception(
                        "Rule has $arg_count arguments: "
                            . join( ', ',
                            map { defined $_ ? $_ : 'undef' } @{$rule} )
                            . "\n"
                            . 'Rule must have from 1 to 4 arguments'
                    );
                } ## end if ( $arg_count > 4 or $arg_count < 1 )
                my ( $lhs, $rhs, $action, ) = @{$rule};
                add_user_rule(
                    $grammar,
                    {   lhs      => $lhs,
                        rhs      => $rhs,
                        action   => $action,
                    }
                );

            } ## end when ('ARRAY')
            when ('HASH') {
                add_user_rule( $grammar, $rule );
            }
            default {
                Marpa::XS::exception(
                    'Invalid rule: ',
                    Data::Dumper->new( [$rule], ['Invalid_Rule'] )->Indent(2)
                        ->Terse(1)->Maxdepth(2)->Dump,
                    'Rule must be ref to HASH or ARRAY'
                );
            } ## end default
        } ## end given

    }    # RULE

    return;

} ## end sub add_user_rules

sub add_user_rule {
    my ( $grammar, $options ) = @_;

    Marpa::XS::exception('Missing argument to add_user_rule')
        if not defined $grammar
            or not defined $options;

    my ( $lhs_name, $rhs_names, $action );
    my ( $min, $separator_name );
    my $ranking_action;
    my $proper_separation = 0;
    my $keep_separation   = 0;

    while ( my ( $option, $value ) = each %{$options} ) {
        given ($option) {
            when ('rhs')            { $rhs_names         = $value }
            when ('lhs')            { $lhs_name          = $value }
            when ('action')         { $action            = $value }
            when ('ranking_action') { $ranking_action    = $value }
            when ('min')            { $min               = $value }
            when ('separator')      { $separator_name    = $value }
            when ('proper')         { $proper_separation = $value }
            when ('keep')           { $keep_separation   = $value }
            default {
                Marpa::XS::exception("Unknown user rule option: $option");
            };
        } ## end given
    } ## end while ( my ( $option, $value ) = each %{$options} )

    my $rule_signature_hash =
        $grammar->[Marpa::XS::Internal::Grammar::RULE_SIGNATURE_HASH];

    my $lhs = assign_user_symbol( $grammar, $lhs_name );
    $rhs_names //= [];
    CHECK_RULE: {
        my @problems     = ();
        my $rhs_ref_type = ref $rhs_names;
        if ( not $rhs_ref_type or $rhs_ref_type ne 'ARRAY' ) {
            push @problems,
                  "RHS is not ref to ARRAY\n"
                . 'rhs is '
                . ( $rhs_ref_type ? $rhs_ref_type : 'not a ref' );
        } ## end if ( not $rhs_ref_type or $rhs_ref_type ne 'ARRAY' )
        if ( not defined $lhs_name ) {
            push @problems, "Missing LHS\n";
        }
        last CHECK_RULE if not scalar @problems;
        my %dump_options = %{$options};
        delete $dump_options{grammar};
        my $msg =
            ( scalar @problems ) . " problem(s) in the following rule:\n";
        my $d = Data::Dumper->new( [ \%dump_options ], ['rule'] );
        $msg .= $d->Dump();
        for my $problem_number ( 0 .. $#problems ) {
            $msg
                .= 'Problem '
                . ( $problem_number + 1 ) . q{: }
                . $problems[$problem_number] . "\n";
        } ## end for my $problem_number ( 0 .. $#problems )
        Marpa::XS::exception($msg);
    } ## end CHECK_RULE:

    my $rhs = [ map { assign_user_symbol( $grammar, $_ ); } @{$rhs_names} ];

    # Don't allow the user to duplicate a rule
    my $rule_signature = join q{,},
        map { $_->[Marpa::XS::Internal::Symbol::ID] } ( $lhs, @{$rhs} );
    Marpa::XS::exception( 'Duplicate rule: ',
        $lhs_name, ' -> ', ( join q{ }, @{$rhs_names} ) )
        if exists $rule_signature_hash->{$rule_signature};

    $rule_signature_hash->{$rule_signature} = 1;

    if ( scalar @{$rhs_names} == 0 or not defined $min ) {

        if ( defined $separator_name ) {
            Marpa::XS::exception(
                'separator defined for rule without repetitions');
        }

        # This is an ordinary, non-counted rule,
        # which we'll take care of first as a special case
        my $ordinary_rule = add_rule(
            {   grammar        => $grammar,
                lhs            => $lhs,
                rhs            => $rhs,
                action         => $action,
                ranking_action => $ranking_action,
            }
        );

        return;

    }    # not defined $min

    # At this point we know that min must be 0 or 1
    # and that there is at least one symbol on the rhs

    # nulling rule is special case
    if ( $min == 0 ) {
        my @rule_args = (
            grammar => $grammar,
            lhs     => $lhs,
            rhs     => [],
        );

        # For a zero-length sequence
        # with an action
        # warn if we don't also have a null value.

        if ($action) {
            $lhs->[Marpa::XS::Internal::Symbol::WARN_IF_NO_NULL_VALUE] = 1;
        }

        if ($ranking_action) {
            push @rule_args, ranking_action => $ranking_action;
        }
        add_rule( {@rule_args} );
        $min = 1;
    } ## end if ( $min == 0 )

    Marpa::XS::exception('Only one rhs symbol allowed for counted rule')
        if scalar @{$rhs_names} != 1;

    my $sequence_item = $rhs->[0];
    $sequence_item->[Marpa::XS::Internal::Symbol::COUNTED] = 1;

    # create the separator symbol, if we're using one
    my $separator;
    if ( defined $separator_name ) {
        $separator = assign_user_symbol( $grammar, $separator_name );
        $separator->[Marpa::XS::Internal::Symbol::COUNTED] = 1;
    }

    # create the sequence symbol
    my $sequence_name = $rhs_names->[0] . "[Seq:$min-*]";
    if ( defined $separator_name ) {
        my $punctuation_free_separator_name = $separator_name;
        $punctuation_free_separator_name =~ s/[^[:alnum:]]/_/gxms;
        $sequence_name .= '[Sep:' . $punctuation_free_separator_name . ']';
    }
    my $sequence = assign_symbol( $grammar, $sequence_name );

    # The top sequence rule
    add_rule(
        {   grammar           => $grammar,
            lhs               => $lhs,
            rhs               => [$sequence],
            virtual_rhs       => 1,
            real_symbol_count => 0,
            discard_separation =>
                ( not $keep_separation and defined $separator ),
            action         => $action,
            ranking_action => $ranking_action,
        }
    );

    # An alternative top sequence rule needed for perl5 separation
    if ( defined $separator and not $proper_separation ) {
        add_rule(
            {   grammar            => $grammar,
                lhs                => $lhs,
                rhs                => [ $sequence, $separator, ],
                virtual_rhs        => 1,
                real_symbol_count  => 1,
                discard_separation => !$keep_separation,
                action             => $action,
                ranking_action     => $ranking_action,
            }
        );
    } ## end if ( defined $separator and not $proper_separation )

    my @separated_rhs =
        defined $separator
        ? ( $separator, $sequence_item )
        : ($sequence_item);

    my $counted_rhs = [ $sequence_item, (@separated_rhs) x ( $min - 1 ) ];

    # Minimal sequence rule
    add_rule(
        {   grammar           => $grammar,
            lhs               => $sequence,
            rhs               => $counted_rhs,
            virtual_lhs       => 1,
            real_symbol_count => ( scalar @{$counted_rhs} ),
        }
    );

    # iterating sequence rule
    my @iterating_rhs = ( $sequence, @separated_rhs );
    add_rule(
        {   grammar           => $grammar,
            lhs               => $sequence,
            rhs               => \@iterating_rhs,
            virtual_lhs       => 1,
            virtual_rhs       => 1,
            real_symbol_count => ( scalar @separated_rhs ),
        }
    );

    return;

} ## end sub add_user_rule

sub check_start {
    my $grammar = shift;
    my $success = 1;

    my $start_name = $grammar->[Marpa::XS::Internal::Grammar::START_NAME];
    Marpa::XS::exception('No start symbol specified')
        if not defined $start_name;
    if ( my $ref_type = ref $start_name ) {
        Marpa::XS::exception(
            "Start symbol name specified as a ref to $ref_type, it should be a string"
        );
    }

    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $symbols     = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $start_id    = $symbol_hash->{$start_name};

    Marpa::XS::exception(qq{Start symbol "$start_name" not in grammar})
        if not defined $start_id;

    my $start = $symbols->[$start_id];
    Marpa::XS::exception(
        qq{Internal error: Start symbol "$start_name" id not found})
        if not $start;

    my $lh_rule_ids = $start->[Marpa::XS::Internal::Symbol::LH_RULE_IDS];
    my $terminal    = $start->[Marpa::XS::Internal::Symbol::TERMINAL];

    if ( not scalar @{$lh_rule_ids} and not $terminal ) {
        my $problem =
            'Start symbol ' . $start_name . ' not on LHS of any rule';
        push @{ $grammar->[Marpa::XS::Internal::Grammar::PROBLEMS] },
            $problem;
        $success = 0;
    } ## end if ( not scalar @{$lh_rule_ids} and not $terminal )

    if ( not $start->[Marpa::XS::Internal::Symbol::PRODUCTIVE] ) {
        my $problem = 'Unproductive start symbol: ' . $start_name;
        push @{ $grammar->[Marpa::XS::Internal::Grammar::PROBLEMS] },
            $problem;
        $success = 0;
    } ## end if ( not $start->[Marpa::XS::Internal::Symbol::PRODUCTIVE...])

    $grammar->[Marpa::XS::Internal::Grammar::START] = $start;

    return $success;
} ## end sub check_start

# return list of rules reachable from the start symbol;
sub accessible {
    my $grammar = shift;
    my $start   = $grammar->[Marpa::XS::Internal::Grammar::START];
    my $rules   = $grammar->[Marpa::XS::Internal::Grammar::RULES];

    $start->[Marpa::XS::Internal::Symbol::ACCESSIBLE] = 1;
    my $symbol_work_set = [$start];
    my $rule_work_set   = [];

    my $work_to_do = 1;

    while ($work_to_do) {
        $work_to_do = 0;

        SYMBOL_PASS: while ( my $work_symbol = shift @{$symbol_work_set} ) {
            my $produced_rule_ids =
                $work_symbol->[Marpa::XS::Internal::Symbol::LH_RULE_IDS];
            PRODUCED_RULE: for my $rule_id ( @{$produced_rule_ids} ) {

                my $rule = $rules->[$rule_id];
                next PRODUCED_RULE
                    if defined $rule->[Marpa::XS::Internal::Rule::ACCESSIBLE];

                $rule->[Marpa::XS::Internal::Rule::ACCESSIBLE] = 1;
                $work_to_do++;
                push @{$rule_work_set}, $rule;

            } ## end for my $rule_id ( @{$produced_rule_ids} )
        }    # SYMBOL_PASS

        RULE: while ( my $work_rule = shift @{$rule_work_set} ) {
            my $rhs_symbol = $work_rule->[Marpa::XS::Internal::Rule::RHS];

            RHS: for my $symbol ( @{$rhs_symbol} ) {

                next RHS
                    if defined
                        $symbol->[Marpa::XS::Internal::Symbol::ACCESSIBLE];
                $symbol->[Marpa::XS::Internal::Symbol::ACCESSIBLE] = 1;
                $work_to_do++;

                push @{$symbol_work_set}, $symbol;
            } ## end for my $symbol ( @{$rhs_symbol} )

        }    # RULE

    }    # work_to_do loop

    return 1;

} ## end sub accessible

sub productive {
    my ($grammar) = @_;

    my $rules   = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];

    # All nullable and terminal symbols are productive.
    for my $symbol ( @{$symbols} ) {
        $symbol->[Marpa::XS::Internal::Symbol::PRODUCTIVE] =
               $symbol->[Marpa::XS::Internal::Symbol::TERMINAL]
            || $symbol->[Marpa::XS::Internal::Symbol::NULLABLE];
    }

    my @workset;
    my @potential_productive_symbol_ids =
        ( map { $_->[Marpa::XS::Internal::Symbol::ID] } @{$symbols} );
    @workset[@potential_productive_symbol_ids] =
        (1) x scalar @potential_productive_symbol_ids;

    while ( my @symbol_ids = grep { $workset[$_] } ( 0 .. $#{$symbols} ) ) {
        @workset = ();
        SYMBOL: for my $symbol ( map { $symbols->[$_] } @symbol_ids ) {

            # Look for the first rule with no unproductive symbols
            # on the RHS.  (It could be an empty rule.)
            # If there is one, this is a productive symbol.
            # If there is none, we have not yet shown this
            # symbol to be productive.
            next SYMBOL if not defined List::Util::first {
                not defined List::Util::first {
                    not $_->[Marpa::XS::Internal::Symbol::PRODUCTIVE];
                }
                @{ $rules->[$_]->[Marpa::XS::Internal::Rule::RHS] };
            } ## end List::Util::first
            @{ $symbol->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] };

            $symbol->[Marpa::XS::Internal::Symbol::PRODUCTIVE] = 1;
            my @potential_new_productive_symbol_ids =
                map  { $_->[Marpa::XS::Internal::Symbol::ID] }
                grep { not $_->[Marpa::XS::Internal::Symbol::PRODUCTIVE] }
                map  { $rules->[$_]->[Marpa::XS::Internal::Rule::LHS] }
                @{ $symbol->[Marpa::XS::Internal::Symbol::RH_RULE_IDS] };
            @workset[@potential_new_productive_symbol_ids] =
                (1) x scalar @potential_new_productive_symbol_ids;
        } ## end for my $symbol ( map { $symbols->[$_] } @symbol_ids )
    } ## end while ( my @symbol_ids = grep { $workset[$_] } ( 0 .. $#...))

    # Now that we know productivity for all the symbols,
    # determine it for the rules.
    # If the are no unproductive symbols on the RHS of
    # a rule, then the rule is productive.
    # The double negative catches the vacuous case:
    # A rule with an empty RHS is productive.
    RULE: for my $rule ( @{$rules} ) {
        next RULE
            if defined List::Util::first {
            not $_->[Marpa::XS::Internal::Symbol::PRODUCTIVE];
        }
        @{ $rule->[Marpa::XS::Internal::Rule::RHS] };
        $rule->[Marpa::XS::Internal::Rule::PRODUCTIVE]++;
    } ## end for my $rule ( @{$rules} )

    return 1;

} ## end sub productive

sub has_empty_rule {
    my ($grammar) = @_;
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    RULE: for my $rule ( @{$rules} ) {
        next RULE if scalar @{ $rule->[Marpa::XS::Internal::Rule::RHS] };
        Marpa::XS::exception(
            'A grammar with empty rules must mark its terminals or unset lhs_terminals'
        );
    } ## end for my $rule ( @{$rules} )
    return;
} ## end sub has_empty_rule

sub terminals_distinguished {
    my ($grammar) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    for my $symbol ( @{$symbols} ) {
        return 1 if $symbol->[Marpa::XS::Internal::Symbol::TERMINAL];
    }
    return 0;
} ## end sub terminals_distinguished

sub mark_all_symbols_terminal {
    my ($grammar) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    for my $symbol ( @{$symbols} ) {
        $symbol->[Marpa::XS::Internal::Symbol::TERMINAL] = 1;
    }
    return 1;
} ## end sub mark_all_symbols_terminal

sub check_lhs_non_terminal {
    my ($grammar) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    SYMBOL: for my $symbol ( @{$symbols} ) {
        next SYMBOL if not $symbol->[Marpa::XS::Internal::Symbol::TERMINAL];
        next SYMBOL
            if not
                scalar @{ $symbol->[Marpa::XS::Internal::Symbol::LH_RULE_IDS]
                };
        my $name = $symbol->[Marpa::XS::Internal::Symbol::NAME];
        Marpa::XS::exception(
            "lhs_terminals option is off, but Symbol $name is both on LHS and a terminal"
        );
    } ## end for my $symbol ( @{$symbols} )
    return 1;
} ## end sub check_lhs_non_terminal

sub mark_non_lhs_terminal {
    my ($grammar) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    SYMBOL: for my $symbol ( @{$symbols} ) {
        next SYMBOL
            if
            scalar @{ $symbol->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] };
        $symbol->[Marpa::XS::Internal::Symbol::TERMINAL] = 1;
    } ## end for my $symbol ( @{$symbols} )
    return 1;
} ## end sub mark_non_lhs_terminal

# Assumes that, at the point when nulling() is called,
# no symbol already has NULLING set.  The loop control
# logic relies on this.
sub nulling {
    my $grammar = shift;

    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];

    my @worklist =
        map  { $_->[Marpa::XS::Internal::Rule::LHS] }
        grep { not scalar @{ $_->[Marpa::XS::Internal::Rule::RHS] } }
        @{$rules};

    SYMBOL: while ( my $symbol = pop @worklist ) {

        # this one we've already done
        next SYMBOL if $symbol->[Marpa::XS::Internal::Symbol::NULLING];

        # terminals are never nulling
        next SYMBOL if $symbol->[Marpa::XS::Internal::Symbol::TERMINAL];

        for my $lh_rule_id (
            @{ $symbol->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] } )
        {
            for my $rh_symbol (
                @{ $rules->[$lh_rule_id]->[Marpa::XS::Internal::Rule::RHS] } )
            {
                next SYMBOL
                    if not $rh_symbol->[Marpa::XS::Internal::Symbol::NULLING];
            } ## end for my $rh_symbol ( @{ $rules->[$lh_rule_id]->[...]})
        } ## end for my $lh_rule_id ( @{ $symbol->[...]})

        $symbol->[Marpa::XS::Internal::Symbol::NULLING] = 1;
        for my $rh_rule_id (
            @{ $symbol->[Marpa::XS::Internal::Symbol::RH_RULE_IDS] } )
        {
            push @worklist,
                $rules->[$rh_rule_id]->[Marpa::XS::Internal::Rule::LHS];

        } ## end for my $rh_rule_id ( @{ $symbol->[...]})

    } ## end while ( my $symbol = pop @worklist )

    return 1;

} ## end sub nulling

# Assumes that nulling symbols have been marked, but
# that no symbol has been marked nullable -- the loop control
# logic requires this.
#
# Returns undef if there was a problem
#
sub nullable {
    my ($grammar) = @_;
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];

    my @worklist =
        map  { $_->[Marpa::XS::Internal::Rule::LHS] }
        grep { not scalar @{ $_->[Marpa::XS::Internal::Rule::RHS] } }
        @{$rules};

    SYMBOL: while ( my $symbol = pop @worklist ) {

        # this one we've already done
        next SYMBOL if $symbol->[Marpa::XS::Internal::Symbol::NULLABLE];

        # terminals can be nullable if they are also LHS symbols

        # Assume it is not nullable and look for a nullable rule
        # with this symbol on the LHS
        my $nullable = 0;
        RULE: for my $lh_rule_id (
            @{ $symbol->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] } )
        {
            for my $rh_symbol (
                @{ $rules->[$lh_rule_id]->[Marpa::XS::Internal::Rule::RHS] } )
            {
                next RULE
                    if not $rh_symbol->[Marpa::XS::Internal::Symbol::NULLABLE];
            } ## end for my $rh_symbol ( @{ $rules->[$lh_rule_id]->[...]})

            # No non-nullable symbol found, so the rule and therefore its
            # LHS symbol are nullable
            $nullable = 1;
            last RULE;

        } ## end for my $lh_rule_id ( @{ $symbol->[...]})

        next SYMBOL if not $nullable;

        $symbol->[Marpa::XS::Internal::Symbol::NULLABLE] = 1;
        for my $rh_rule_id (
            @{ $symbol->[Marpa::XS::Internal::Symbol::RH_RULE_IDS] } )
        {
            push @worklist,
                $rules->[$rh_rule_id]->[Marpa::XS::Internal::Rule::LHS];

        } ## end for my $rh_rule_id ( @{ $symbol->[...]})

    } ## end while ( my $symbol = pop @worklist )

    my $counted_nullable_count;
    for my $symbol ( @{$symbols} ) {
        my ( $name, $nullable, $counted, ) = @{$symbol}[
            Marpa::XS::Internal::Symbol::NAME,
            Marpa::XS::Internal::Symbol::NULLABLE,
            Marpa::XS::Internal::Symbol::COUNTED,
        ];
        if ( $nullable and $counted ) {
            my $problem =
                qq{Nullable symbol "$name" is on rhs of counted rule};
            push @{ $grammar->[Marpa::XS::Internal::Grammar::PROBLEMS] },
                $problem;
            $counted_nullable_count++;
        } ## end if ( $nullable and $counted )
    } ## end for my $symbol ( @{$symbols} )
    if ($counted_nullable_count) {
        my $problem =
            'Counted nullables confuse Marpa::XS -- please rewrite the grammar';
        push @{ $grammar->[Marpa::XS::Internal::Grammar::PROBLEMS] },
            $problem;
        return;
    } ## end if ($counted_nullable_count)

    return 1;

} ## end sub nullable

# This assumes the CHAF rewrite has been done,
# so that every symbol is either nulling or
# non-nullable.  There are no proper nullables.
sub infinite_rules {
    my ($grammar) = @_;
    my $rules     = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];

    my @unit_derivation;         # for the unit derivation matrix
    my @new_unit_derivations;    # a list of new unit derivations
    my @unit_rules;              # a list of the unit rules

    # initialize the unit derivations from the rules
    RULE: for my $rule ( @{$rules} ) {
        next RULE if not $rule->[Marpa::XS::Internal::Rule::USED];
        my $rhs = $rule->[Marpa::XS::Internal::Rule::RHS];
        my $non_nulling_symbol;

        # Looking for unit rules:
        # Eliminate all rules with two or more non-nullables on
        # the RHS.
        for my $rhs_symbol ( @{$rhs} ) {
            if ( not $rhs_symbol->[Marpa::XS::Internal::Symbol::NULLABLE] ) {

                # if we have two non-nullables on the RHS in this rule,
                # it cannot be a unit rule and we can ignore it
                next RULE if defined $non_nulling_symbol;

                $non_nulling_symbol = $rhs_symbol;
            } ## end if ( not $rhs_symbol->[...])
        }    # for $rhs_symbol

        # Above we've eliminated all rules with two or more non-nulling
        # on the RHS.  So here we have a rule with zero or one non-nulling
        # symbol on the RHS.  With zero non-nulling rules, this rule
        # must be nulling (empty) and cannot cycle.
        # Only one empty rule is allowed in a CHAF grammar -- a nulling
        # start rule -- this takes care of that exception.
        next RULE if not defined $non_nulling_symbol;

        my $start_id =
            $rule->[Marpa::XS::Internal::Rule::LHS]
            ->[Marpa::XS::Internal::Symbol::ID];
        my $derived_id =
            $non_nulling_symbol->[Marpa::XS::Internal::Symbol::ID];

        # Keep track of our unit rules
        push @unit_rules, [ $rule, $start_id, $derived_id ];

        $unit_derivation[$start_id][$derived_id] = 1;
        push @new_unit_derivations, [ $start_id, $derived_id ];

    } ## end for my $rule ( @{$rules} )

    # Now find the transitive closure of the unit derivation matrix
    CLOSURE_LOOP:
    while ( my $new_unit_derivation = shift @new_unit_derivations ) {

        my ( $start_id, $derived_id ) = @{$new_unit_derivation};
        ID: for my $id ( 0 .. $#{$symbols} ) {

            # does the derived symbol derive this id?
            # if not, no new derivation, and continue looping
            next ID if not $unit_derivation[$derived_id][$id];

            # also, if we've already recorded this unit derivation,
            # skip it
            next ID if $unit_derivation[$start_id][$id];

            $unit_derivation[$start_id][$id] = 1;
            push @new_unit_derivations, [ $start_id, $id ];
        } ## end for my $id ( 0 .. $#{$symbols} )

    } ## end while ( my $new_unit_derivation = shift @new_unit_derivations)

    my @infinite_rules = ();

    # produce a list of the rules which cycle
    RULE: while ( my $unit_rule_data = pop @unit_rules ) {

        my ( $rule, $start_symbol_id, $derived_symbol_id ) =
            @{$unit_rule_data};

        next RULE
            if $start_symbol_id != $derived_symbol_id
                and
                not $unit_derivation[$derived_symbol_id][$start_symbol_id];

        push @infinite_rules, $rule;

        $rule->[Marpa::XS::Internal::Rule::CYCLE] = 1;

        # From a virtual point of view, a rule is a cycle if it is
        # not a CHAF rule, or if it does not have a virtual RHS.
        # Rules from a sequence rule rewrite count as "virtual"
        # rules for this purpose, at least for now.
        $rule->[Marpa::XS::Internal::Rule::VIRTUAL_CYCLE] =
               !( defined $rule->[Marpa::XS::Internal::Rule::VIRTUAL_START] )
            || !$rule->[Marpa::XS::Internal::Rule::VIRTUAL_RHS];
    } ## end while ( my $unit_rule_data = pop @unit_rules )

    $grammar->[Marpa::XS::Internal::Grammar::HAS_CYCLE] =
        scalar @infinite_rules;

    return \@infinite_rules;

} ## end sub infinite_rules

# This assumes the grammar has been rewritten into CHAF form.
sub detect_infinite {
    my $grammar = shift;
    my $rules   = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $trace_fh =
        $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];

    my $infinite_is_fatal = 1;
    my $warn_on_infinite  = 1;
    given ( $grammar->[Marpa::XS::Internal::Grammar::INFINITE_ACTION] ) {
        when ('warn') { $infinite_is_fatal = 0; }
        when ('quiet') {
            $infinite_is_fatal = 0;
            $warn_on_infinite  = 0;
        }
    } ## end given

    my $infinite_rules = infinite_rules($grammar);

    # produce a list of the rules which cycle
    RULE: for my $rule ( @{$infinite_rules} ) {

        my $warning_rule = $rule->[Marpa::XS::Internal::Rule::ORIGINAL_RULE]
            // $rule;

        if ( $warn_on_infinite and defined $warning_rule ) {
            print {$trace_fh}
                'Cycle found involving rule: ',
                Marpa::XS::brief_rule($warning_rule), "\n"
                or Marpa::XS::exception("Could not print: $ERRNO");
        } ## end if ( $warn_on_infinite and defined $warning_rule )
    } ## end for my $rule ( @{$infinite_rules} )

    if ( scalar @{$infinite_rules} ) {
        Marpa::XS::exception('Cycle in grammar, fatal error')
            if $infinite_is_fatal;
        $grammar->[Marpa::XS::Internal::Grammar::IS_INFINITE] = 1;
    }

    return 1;

}    # sub detect_infinite

sub create_NFA {
    my $grammar = shift;
    my ( $rules, $symbols, $start, $academic ) = @{$grammar}[
        Marpa::XS::Internal::Grammar::RULES,
        Marpa::XS::Internal::Grammar::SYMBOLS,
        Marpa::XS::Internal::Grammar::START,
        Marpa::XS::Internal::Grammar::ACADEMIC
    ];

    # start rules are rules with the start symbol
    # or with the start alias on the LHS.
    my @start_rule_ids =
        @{ $start->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] };
    if (defined(
            my $start_alias =
                $start->[Marpa::XS::Internal::Symbol::NULL_ALIAS]
        )
        )
    {
        push @start_rule_ids,
            @{ $start_alias->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] };
    } ## end if ( defined( my $start_alias = $start->[...]))

    $grammar->[Marpa::XS::Internal::Grammar::NULLABLE_SYMBOL] =
        [ grep { $_->[Marpa::XS::Internal::Symbol::NULLABLE] } @{$symbols} ];

    my $NFA = [];
    $grammar->[Marpa::XS::Internal::Grammar::NFA] = $NFA;

    my $state_id = 0;
    my @NFA_by_item;

    # create S0
    my $s0 = [];
    @{$s0}[
        Marpa::XS::Internal::NFA::ID,
        Marpa::XS::Internal::NFA::NAME,
        Marpa::XS::Internal::NFA::TRANSITION
        ]
        = ( $state_id++, 'S0', {} );
    push @{$NFA}, $s0;

    # create the other states
    RULE: for my $rule ( @{$rules} ) {
        my ( $rule_id, $rhs, $useful ) = @{$rule}[
            Marpa::XS::Internal::Rule::ID, Marpa::XS::Internal::Rule::RHS,
            Marpa::XS::Internal::Rule::USED
        ];
        next RULE if not $academic and not $useful;
        for my $position ( 0 .. scalar @{$rhs} ) {
            my $new_state = [];
            @{$new_state}[
                Marpa::XS::Internal::NFA::ID,
                Marpa::XS::Internal::NFA::NAME,
                Marpa::XS::Internal::NFA::ITEM,
                Marpa::XS::Internal::NFA::TRANSITION
                ]
                = ( $state_id, 'S' . $state_id, [ $rule, $position ], {} );
            $state_id++;
            push @{$NFA}, $new_state;
            $NFA_by_item[$rule_id][$position] = $new_state;
        }    # position
    }    # rule

    # now add the transitions
    STATE: for my $state ( @{$NFA} ) {
        my ( $id, $name, $item, $transition ) = @{$state};

        # First, deal with transitions from state 0.
        # S0 is the state with no LR(0) item
        if ( not defined $item ) {

            # From S0, add an empty transition to the every NFA state
            # corresponding to a start rule with the dot at the beginning
            # of the RHS.
            RULE: for my $start_rule_id (@start_rule_ids) {
                my $start_rule = $rules->[$start_rule_id];
                next RULE
                    if not $start_rule->[Marpa::XS::Internal::Rule::USED];
                push @{ $transition->{q{}} }, $NFA_by_item[$start_rule_id][0];
            } ## end for my $start_rule_id (@start_rule_ids)
            next STATE;
        } ## end if ( not defined $item )

        # transitions from states other than state 0:

        my $rule     = $item->[Marpa::XS::Internal::LR0_item::RULE];
        my $position = $item->[Marpa::XS::Internal::LR0_item::POSITION];
        my $rule_id  = $rule->[Marpa::XS::Internal::Rule::ID];
        my $next_symbol =
            $rule->[Marpa::XS::Internal::Rule::RHS]->[$position];

        # no transitions if position is after the end of the RHS
        if ( not defined $next_symbol ) {
            $state->[Marpa::XS::Internal::NFA::COMPLETE] = 1;
            next STATE;
        }

        if ( $next_symbol->[Marpa::XS::Internal::Symbol::NULLING] ) {
            $state->[Marpa::XS::Internal::NFA::AT_NULLING] = 1;
        }

        # the scanning transition: the transition if the position is at symbol X
        # in the RHS, via symbol X, to the state corresponding to the same
        # rule with the position incremented by 1
        # should I use ID as the key for those hashes, or NAME?
        push @{ $transition
                ->{ $next_symbol->[Marpa::XS::Internal::Symbol::NAME] } },
            $NFA_by_item[$rule_id][ $position + 1 ];

        # the prediction transitions: transitions if the position is at symbol X
        # in the RHS, via the empty symbol, to all states with X on the LHS and
        # position 0
        RULE:
        for my $predicted_rule_id (
            @{ $next_symbol->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] } )
        {
            my $predicted_rule = $rules->[$predicted_rule_id];
            next RULE
                if not $predicted_rule->[Marpa::XS::Internal::Rule::USED];
            push @{ $transition->{q{}} }, $NFA_by_item[$predicted_rule_id][0];
        } ## end for my $predicted_rule_id ( @{ $next_symbol->[...]})
    } ## end for my $state ( @{$NFA} )

    return 1;
} ## end sub create_NFA

# take a list of kernel NFA states, possibly with duplicates, and return
# a reference to an array of the fully built Aycock-Horspool (AHFA) states.
# as necessary.  The build is complete, except for transitions, which are
# left to be set up later.
sub assign_AHFA_state_set {
    my $grammar       = shift;
    my $kernel_states = shift;

    my ( $symbols, $NFA_states, $AHFA_by_name, $AHFA ) = @{$grammar}[
        Marpa::XS::Internal::Grammar::SYMBOLS,
        Marpa::XS::Internal::Grammar::NFA,
        Marpa::XS::Internal::Grammar::AHFA_BY_NAME,
        Marpa::XS::Internal::Grammar::AHFA
    ];

    # Track if a state has been seen in @NFA_state_seen.
    # Value is Undefined if never seen.
    # Value is -1 if seen, but not a result
    # Value is >=0 if seen and a result.
    #
    # If seen and to go into result, the
    # value is the reset flag, which must be
    # 0 or 1.
    my @NFA_state_seen;

    # pre-allocate the array
    $#NFA_state_seen = @{$NFA_states};

    # The work list is an array of work items.  Each work item
    # is an NFA state, following by an optional prediction flag.
    my @work_list = map { [ $_, 0 ] } @{$kernel_states};

    # Use index because we extend this list while processing it.
    my $work_list_index = -1;
    WORK_ITEM: while (1) {

        my $work_list_entry = $work_list[ ++$work_list_index ];
        last WORK_ITEM if not defined $work_list_entry;

        my ( $NFA_state, $reset ) = @{$work_list_entry};

        my $NFA_id = $NFA_state->[Marpa::XS::Internal::NFA::ID];
        next WORK_ITEM if defined $NFA_state_seen[$NFA_id];
        $NFA_state_seen[$NFA_id] = -1;

        my $transition = $NFA_state->[Marpa::XS::Internal::NFA::TRANSITION];

        # if we are at a nulling symbol, this NFA state does NOT go into the
        # result, but all transitions go into the work list.  All the transitions
        # are assumed to be (and should be) empty transitions.
        if ( $NFA_state->[Marpa::XS::Internal::NFA::AT_NULLING] ) {
            push @work_list, map { [ $_, $reset ] }
                map { @{$_} } values %{$transition};
            next WORK_ITEM;
        }

        # If we are here, were have an NFA state NOT at a nulling symbol.
        # This NFA state goes into the result, and the empty transitions
        # go into the worklist as reset items.
        my $empty_transitions = $transition->{q{}};
        if ($empty_transitions) {
            push @work_list, map { [ $_, 1 ] } @{$empty_transitions};
        }

        $reset //= 0;
        $NFA_state_seen[$NFA_id] = $reset;

    }    # WORK_ITEM

    # this will hold the AHFA state set,
    # which is the result
    my @result_states = ();

    RESET: for my $reset ( 0, 1 ) {

        my @NFA_ids = grep {
            defined $NFA_state_seen[$_]
                and $NFA_state_seen[$_] == $reset
        } ( 0 .. $#NFA_state_seen );

        next RESET if not scalar @NFA_ids;

        my $name = join q{,}, @NFA_ids;
        my $AHFA_state = $AHFA_by_name->{$name};

        # this is a new AHFA state -- create it
        if ( not $AHFA_state ) {
            my $id = scalar @{$AHFA};

            my $start_rule;
            my $lhs_list       = [];
            my $complete_rules = [];
            my $AHFA_complete  = 0;
            my $NFA_state_list = [ @{$NFA_states}[@NFA_ids] ];
            NFA_STATE: for my $NFA_state ( @{$NFA_state_list} ) {
                next NFA_STATE
                    if not $NFA_state->[Marpa::XS::Internal::NFA::COMPLETE];
                $AHFA_complete = 1;
                my $item = $NFA_state->[Marpa::XS::Internal::NFA::ITEM];
                my $rule = $item->[Marpa::XS::Internal::LR0_item::RULE];
                my $lhs  = $rule->[Marpa::XS::Internal::Rule::LHS];
                my ( $lhs_id, $lhs_is_start ) = @{$lhs}[
                    Marpa::XS::Internal::Symbol::ID,
                    Marpa::XS::Internal::Symbol::START
                ];
                $lhs_list->[$lhs_id] = 1;
                push @{ $complete_rules->[$lhs_id] }, $rule;

                if ($lhs_is_start) {
                    $start_rule = $rule;
                }
            } ## end for my $NFA_state ( @{$NFA_state_list} )

            $AHFA_state->[Marpa::XS::Internal::AHFA::ID]   = $id;
            $AHFA_state->[Marpa::XS::Internal::AHFA::NAME] = $name;
            $AHFA_state->[Marpa::XS::Internal::AHFA::NFA_STATES] =
                $NFA_state_list;
            $AHFA_state->[Marpa::XS::Internal::AHFA::RESET_ORIGIN] = $reset;
            $AHFA_state->[Marpa::XS::Internal::AHFA::START_RULE] =
                $start_rule;
            $AHFA_state->[Marpa::XS::Internal::AHFA::COMPLETE_RULES] =
                $complete_rules;

            $AHFA_state->[Marpa::XS::Internal::AHFA::COMPLETE_LHS] =
                [ map { $_->[Marpa::XS::Internal::Symbol::NAME] }
                    @{$symbols}[ grep { $lhs_list->[$_] }
                    ( 0 .. $#{$lhs_list} ) ] ];

            push @{$AHFA}, $AHFA_state;
            $AHFA_by_name->{$name} = $AHFA_state;
        } ## end if ( not $AHFA_state )

        push @result_states, $AHFA_state;

    } ## end for my $reset ( 0, 1 )

    return \@result_states;
} ## end sub assign_AHFA_state_set

sub create_AHFA {
    my $grammar = shift;
    my ( $symbols, $NFA, $tracing ) = @{$grammar}[
        Marpa::XS::Internal::Grammar::SYMBOLS,
        Marpa::XS::Internal::Grammar::NFA,
        Marpa::XS::Internal::Grammar::TRACING,
    ];

    my $trace_fh;
    if ($tracing) {
        $trace_fh =
            $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];
    }

    my $AHFA = $grammar->[Marpa::XS::Internal::Grammar::AHFA] = [];
    my $NFA_s0 = $NFA->[0];

    # next AHFA state to compute transitions for
    my $next_state_id = 0;

    my $initial_NFA_states =
        $NFA_s0->[Marpa::XS::Internal::NFA::TRANSITION]->{q{}};
    if ( not defined $initial_NFA_states ) {
        Marpa::XS::exception('Empty NFA, cannot create AHFA');
    }
    $grammar->[Marpa::XS::Internal::Grammar::START_STATES] =
        assign_AHFA_state_set( $grammar, $initial_NFA_states );

    # assign_AHFA_state_set extends this array, which we are
    # simultaneously going through and adding transitions.
    # There is no problem with the process of adding transitions
    # overtaking assign_AHFA_state_set: if we reach a point where
    # all transitions have been added, and we are at the end of @$AHFA
    # we are finished.
    while ( $next_state_id < scalar @{$AHFA} ) {

        # compute the AHFA state transitions from the transitions
        # of the NFA states of which it is composed
        my $NFA_to_states_by_symbol = {};

        my $AHFA_state = $AHFA->[ $next_state_id++ ];

        # aggregrate the transitions, by symbol, for every NFA state in this AHFA
        # state
        for my $NFA_state (
            @{ $AHFA_state->[Marpa::XS::Internal::AHFA::NFA_STATES] } )
        {
            my $transition =
                $NFA_state->[Marpa::XS::Internal::NFA::TRANSITION];
            NFA_TRANSITION:
            for my $symbol ( sort keys %{$transition} ) {
                my $to_states = $transition->{$symbol};
                next NFA_TRANSITION if $symbol eq q{};
                push @{ $NFA_to_states_by_symbol->{$symbol} }, @{$to_states};
            }
        }    # $NFA_state

        # for each transition symbol, create the transition to the AHFA kernel state
        for my $symbol ( sort keys %{$NFA_to_states_by_symbol} ) {
            my $to_states_by_symbol = $NFA_to_states_by_symbol->{$symbol};
            $AHFA_state->[Marpa::XS::Internal::AHFA::TRANSITION]->{$symbol} =
                assign_AHFA_state_set( $grammar, $to_states_by_symbol );
        }
    } ## end while ( $next_state_id < scalar @{$AHFA} )

    return;

} ## end sub create_AHFA

# To the reader:
# You are not expected to understand the following.  It is
# notes toward a proof.  This is useful, along with testing,
# to increase confidence
# that Marpa::XS correctly incorporates Leo Joop's algorithm.
#
# Theorem: In Marpa::XS,
# all Leo completion states are in their own LR(0) state.
#
# Proof: Every Marpa::XS LR(0) item has its own NFA state.
# (By definition, no Marpa::XS LR(0) item will have
# a nulling post-dot symbol.)
# The Leo completion LR(0) item will have a non-nulling symbol,
# by its definiton.
# Call the Leo completion item's final non-nulling symbol,
# symbol S.
# Suppose, for reduction to absurdity,
# that another LR(0) item is combined with
# the Leo completion item in creating the LR(0) DFA.
# Call that other LR(0) item, item X.
# If so,
# there must be a Leo kernel LR(0) state where two of the
# LR(0) items, after a transition on symbol S,
# produce both item X and the Leo completion item.
# That means that in the Leo kernel LR(0) state, there
# are two LR(0) items with S as the postdot symbol.
# Therefore the parent Earley set (which contains the
# Leo kernel LR(0) DFA state) will have multiple
# LR(0) items with S as the postdot symbol.
# But by Leo's definitions, the LR(0) item with S as
# the postdot symbol must be unique.
# So the assumption that another LR(0) item will be
# combined with a Leo completion LR(0) item in producing
# a DFA state must be false.
# QED
#
# Theorem: All Leo completion states are in their own AHFA state.
# Proof: By the theorem above, all Leo completion states are in
# their own state in the LR(0) DFA.
# The conversion to an epsilion-DFA will not add any items to this
# state, because the only item in it is a completion item.
# And conversion to a split epsilon-DFA will not add items.
# So the Leo completion item will remain in its own AHFA state.
# QED.

# Mark the Leo kernel and completion states
sub mark_leo_states {
    my $grammar = shift;
    my $AHFA    = $grammar->[Marpa::XS::Internal::Grammar::AHFA];

    # An Leo completion state will have only one NFA state,
    # and will contain a completion.
    STATE: for my $state ( @{$AHFA} ) {
        my $NFA_states = $state->[Marpa::XS::Internal::AHFA::NFA_STATES];
        next STATE if scalar @{$NFA_states} != 1;
        my $left_hand_sides =
            $state->[Marpa::XS::Internal::AHFA::COMPLETE_LHS];
        next STATE if not scalar @{$left_hand_sides};
        my $LR0_item    = $NFA_states->[0]->[Marpa::XS::Internal::NFA::ITEM];
        my $rule        = $LR0_item->[Marpa::XS::Internal::LR0_item::RULE];
        my $rhs         = $rule->[Marpa::XS::Internal::Rule::RHS];
        my $non_nulling = (
            List::Util::first {
                not $_->[Marpa::XS::Internal::Symbol::NULLING];
            }
            reverse @{$rhs}
        );

        # In the null parse rules, there will be no non-nulling symbol
        next STATE if not defined $non_nulling;

        # Not a Leo completion unless the next non-nulling symbol is on at least
        # one left hand side.
        next STATE
            if not scalar
                @{ $non_nulling->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] };
        $state->[Marpa::XS::Internal::AHFA::LEO_COMPLETION] =
            $rule->[Marpa::XS::Internal::Rule::LHS];
    } ## end for my $state ( @{$AHFA} )

    AHFA_STATE: for my $AHFA_state ( @{$AHFA} ) {
        my %symbol_count = ();
        LR0_ITEM:
        for my $LR0_item ( map { $_->[Marpa::XS::Internal::NFA::ITEM] }
            @{ $AHFA_state->[Marpa::XS::Internal::AHFA::NFA_STATES] } )
        {
            my $rule = $LR0_item->[Marpa::XS::Internal::LR0_item::RULE];
            my $position =
                $LR0_item->[Marpa::XS::Internal::LR0_item::POSITION];
            my $symbol = $rule->[Marpa::XS::Internal::Rule::RHS]->[$position];
            next LR0_ITEM if not defined $symbol;
            $symbol_count{ $symbol->[Marpa::XS::Internal::Symbol::NAME] }++;
        } ## end for my $LR0_item ( map { $_->[Marpa::XS::Internal::NFA::ITEM...]})
        my $transitions =
            $AHFA_state->[Marpa::XS::Internal::AHFA::TRANSITION];
        SYMBOL:
        for my $symbol_name (
            grep { $symbol_count{$_} == 1 }
            keys %symbol_count
            )
        {
            my $to_states = $transitions->{$symbol_name};

            # Since there is only one to-state, @leo_lhs
            # will have only one entry -- this will be the
            # lhs of the only rule in the Leo completion
            # item
            my @leo_lhs =
                map  { $_->[Marpa::XS::Internal::Symbol::NAME] }
                grep {defined}
                map  { $_->[Marpa::XS::Internal::AHFA::LEO_COMPLETION] }
                @{$to_states};
            $transitions->{$symbol_name} = [ @leo_lhs, @{$to_states} ];
        } ## end for my $symbol_name ( grep { $symbol_count{$_} == 1 }...)
    } ## end for my $AHFA_state ( @{$AHFA} )

    return;
} ## end sub mark_leo_states

sub setup_academic_grammar {
    my $grammar = shift;
    my $rules   = $grammar->[Marpa::XS::Internal::Grammar::RULES];

    # in an academic grammar, consider all rules useful
    for my $rule ( @{$rules} ) {
        $rule->[Marpa::XS::Internal::Rule::USED] = 1;
    }

    return;
} ## end sub setup_academic_grammar

# given a nullable symbol, create a nulling alias and make the first symbol non-nullable
sub alias_symbol {
    my $grammar         = shift;
    my $nullable_symbol = shift;
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $symbols     = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my ( $accessible, $productive, $name, $null_value ) = @{$nullable_symbol}[
        Marpa::XS::Internal::Symbol::ACCESSIBLE,
        Marpa::XS::Internal::Symbol::PRODUCTIVE,
        Marpa::XS::Internal::Symbol::NAME,
        Marpa::XS::Internal::Symbol::NULL_VALUE,
    ];

    # create the new, nulling symbol
    my $alias_name =
        $nullable_symbol->[Marpa::XS::Internal::Symbol::NAME] . '[]';
    my $alias = [];
    $#{$alias} = Marpa::XS::Internal::Symbol::LAST_FIELD;
    $alias->[Marpa::XS::Internal::Symbol::NAME]        = $alias_name;
    $alias->[Marpa::XS::Internal::Symbol::LH_RULE_IDS] = [];
    $alias->[Marpa::XS::Internal::Symbol::RH_RULE_IDS] = [];
    $alias->[Marpa::XS::Internal::Symbol::ACCESSIBLE]  = $accessible;
    $alias->[Marpa::XS::Internal::Symbol::PRODUCTIVE]  = $productive;
    $alias->[Marpa::XS::Internal::Symbol::NULLING]     = 1;
    $alias->[Marpa::XS::Internal::Symbol::NULL_VALUE]  = $null_value;
    $nullable_symbol->[Marpa::XS::Internal::Symbol::NULLABLE] //= 0;
    $alias->[Marpa::XS::Internal::Symbol::NULLABLE] = 1;

    my $symbol_id = @{$symbols};
    push @{$symbols}, $alias;
    $alias->[Marpa::XS::Internal::Symbol::ID] = $symbol_hash->{$alias_name} =
        $symbol_id;

    # turn the original symbol into a non-nullable with a reference to the new alias
    $nullable_symbol->[Marpa::XS::Internal::Symbol::NULLABLE] =
        $nullable_symbol->[Marpa::XS::Internal::Symbol::NULLING] = 0;
    return $nullable_symbol->[Marpa::XS::Internal::Symbol::NULL_ALIAS] =
        $alias;
} ## end sub alias_symbol

# For efficiency, steps in the CHAF evaluation
# work on a last-is-rest principle -- productions
# with a CHAF head always return reference to an array
# of values, of which the last value is (in turn)
# a reference to an array with the "rest" of the values.
# An empty array signals that there are no more.

# rewrite as Chomsky-Horspool-Aycock Form
sub rewrite_as_CHAF {
    my $grammar = shift;

    my $rules            = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $symbols          = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $old_start_symbol = $grammar->[Marpa::XS::Internal::Grammar::START];

    # add null aliases to symbols which need them
    my $symbol_count = @{$symbols};
    SYMBOL: for my $ix ( 0 .. ( $symbol_count - 1 ) ) {
        my $symbol = $symbols->[$ix];
        my ( $productive, $accessible, $nulling, $nullable, $null_alias ) =
            @{$symbol}[
            Marpa::XS::Internal::Symbol::PRODUCTIVE,
            Marpa::XS::Internal::Symbol::ACCESSIBLE,
            Marpa::XS::Internal::Symbol::NULLING,
            Marpa::XS::Internal::Symbol::NULLABLE,
            Marpa::XS::Internal::Symbol::NULL_ALIAS
            ];

        # not necessary is the symbol already has a null
        # alias
        next SYMBOL if $null_alias;

        #  we don't bother with unreachable symbols
        next SYMBOL if not $productive;
        next SYMBOL if not $accessible;

        # look for proper nullable symbols
        next SYMBOL if $nulling;
        next SYMBOL if not $nullable;

        alias_symbol( $grammar, $symbol );
    } ## end for my $ix ( 0 .. ( $symbol_count - 1 ) )

    # mark, or create as needed, the useful rules

    # get the initial rule count -- new rules will be added but we don't iterate
    # over them
    my $rule_count = @{$rules};
    RULE: for my $rule_id ( 0 .. ( $rule_count - 1 ) ) {
        my $rule = $rules->[$rule_id];

        # Rules are useless unless proven otherwise
        $rule->[Marpa::XS::Internal::Rule::USED] = 0;

        # unreachable rules are useless
        my $productive = $rule->[Marpa::XS::Internal::Rule::PRODUCTIVE];
        next RULE if not $productive;
        my $accessible = $rule->[Marpa::XS::Internal::Rule::ACCESSIBLE];
        next RULE if not $accessible;

        my $rhs = $rule->[Marpa::XS::Internal::Rule::RHS];

        # A nulling rule -- one with only nulling symbols on
        # the rhs is useless.
        # By this definition, it is vacuously true
        # that empty rules are nulling.
        next RULE
            if (
            not defined List::Util::first {
                not $_->[Marpa::XS::Internal::Symbol::NULLING];
            }
            @{$rhs}
            );

        my $lhs      = $rule->[Marpa::XS::Internal::Rule::LHS];
        my $nullable = !defined List::Util::first {
            not $_->[Marpa::XS::Internal::Symbol::NULLABLE] and
            not $_->[Marpa::XS::Internal::Symbol::NULL_ALIAS];
        }
        @{$rhs};

        # Keep track of whether the lhs side of any new rules we create should
        # be nullable.  If any symbol in a production is not nullable, the lhs
        # is not nullable.  If the original production is nullable, all symbols
        # are nullable, all subproductions will be, and all new lhs's should be.
        # But even if the original production is not nullable, some of the
        # subproductions may be.  These will always be in a series starting from
        # the far right.

        # Going from right to left,
        # once the first non-nullable symbol is encountered,
        # that subproduction is non-nullable,
        # that lhs will be non-nullable, and since that
        # new lhs is on the far rhs of subsequent (going left) subproductions,
        # all subsequent subproductions and their lhs's will be non-nullable.

        my @aliased_rhs =
            map { $_->[Marpa::XS::Internal::Symbol::NULL_ALIAS] // $_ }
            @{$rhs};
        my @proper_nullable_ixes =
            grep { $rhs->[$_]->[Marpa::XS::Internal::Symbol::NULL_ALIAS] }
            ( 0 .. $#{$rhs} );
        my $last_nonnullable_ix = (
            List::Util::first {
                not $aliased_rhs[$_]->[Marpa::XS::Internal::Symbol::NULLABLE];
            }
            ( reverse 0 .. $#aliased_rhs )
        ) // -1;

        # we found no properly nullable symbols in the RHS, so this rule is useful without
        # any changes
        if ( not scalar @proper_nullable_ixes ) {
            $rule->[Marpa::XS::Internal::Rule::USED] = 1;
            next RULE;
        }

        # Delete these?  Or turn into smart comment assertions?
        if ( $rule->[Marpa::XS::Internal::Rule::VIRTUAL_LHS] ) {
            Marpa::XS::exception(
                'Internal Error: attempted CHAF rewrite of rule with virtual LHS'
            );
        }
        if ( $rule->[Marpa::XS::Internal::Rule::VIRTUAL_RHS] ) {
            Marpa::XS::exception(
                'Internal Error: attempted CHAF rewrite of rule with virtual RHS'
            );
        }

        # The left hand side of the first subproduction is the lhs of the original rule
        my $subproduction_lhs      = $lhs;
        my $subproduction_start_ix = 0;

        # break this production into subproductions with a fixed number of proper nullables,
        # then factor out the proper nullables into a set of productions
        # with only non-nullable and nulling symbols.
        SUBPRODUCTION: while (1) {

            my $subproduction_end_ix;
            my $proper_nullable_0_ix = $proper_nullable_ixes[0];
            my $proper_nullable_0_subproduction_ix =
                $proper_nullable_0_ix - $subproduction_start_ix;

            my $proper_nullable_1_ix = $proper_nullable_ixes[1];
            my $proper_nullable_1_subproduction_ix;
            if ( defined $proper_nullable_1_ix ) {
                $proper_nullable_1_subproduction_ix =
                    $proper_nullable_1_ix - $subproduction_start_ix;
            }

            my $nothing_nulling_rhs;
            my $next_subproduction_lhs;

            given ( scalar @proper_nullable_ixes ) {

                # When there are 1 or 2 proper nullables
                when ( $_ <= 2 ) {
                    $subproduction_end_ix = $#{$rhs};
                    $nothing_nulling_rhs  = [
                        @{$rhs}[
                            $subproduction_start_ix .. $subproduction_end_ix
                        ]
                    ];
                    @proper_nullable_ixes = ();
                } ## end when ( $_ <= 2 )

                # When there are 3 or more proper nullables
                default {
                    $subproduction_end_ix = $proper_nullable_1_ix - 1;
                    shift @proper_nullable_ixes;

                    # If the next subproduction is not nullable,
                    # we can include two proper nullables
                    if ( $proper_nullable_1_ix < $last_nonnullable_ix ) {
                        $subproduction_end_ix++;
                        shift @proper_nullable_ixes;
                    }

                    $next_subproduction_lhs = assign_symbol( $grammar,
                              $lhs->[Marpa::XS::Internal::Symbol::NAME] . '[R'
                            . $rule_id . q{:}
                            . ( $subproduction_end_ix + 1 )
                            . ']' );

                    $next_subproduction_lhs
                        ->[Marpa::XS::Internal::Symbol::NULLABLE] = 0;
                    $next_subproduction_lhs
                        ->[Marpa::XS::Internal::Symbol::NULLING] = 0;
                    $next_subproduction_lhs
                        ->[Marpa::XS::Internal::Symbol::ACCESSIBLE] = 1;
                    $next_subproduction_lhs
                        ->[Marpa::XS::Internal::Symbol::PRODUCTIVE] = 1;

                    $nothing_nulling_rhs = [
                        @{$rhs}[
                            $subproduction_start_ix .. $subproduction_end_ix
                        ],
                        $next_subproduction_lhs
                    ];
                } ## end default

            }    # SETUP_SUBPRODUCTION

            my @factored_rh_sides = ($nothing_nulling_rhs);

            FACTOR: {

                # We have additional factored productions if
                # 1) there is more than one proper nullable;
                # 2) there's only one, but replacing it with a nulling symbol will
                #    not make the entire production nulling
                #
                # Here and below we use the nullable flag to establish whether a
                # factored subproduction rhs would be nulling, on this principle:
                #
                # If substituting nulling symbols for all proper nullables does not
                # make a production nulling, then it is not nullable, and vice versa.

                last FACTOR
                    if $nullable and not defined $proper_nullable_1_ix;

                # The factor rhs which nulls the last proper nullable
                my $last_nullable_subproduction_ix =
                    $proper_nullable_1_subproduction_ix
                    // $proper_nullable_0_subproduction_ix;
                my $last_nulling_rhs = [ @{$nothing_nulling_rhs} ];
                if (    $next_subproduction_lhs
                    and $last_nullable_subproduction_ix
                    > ( $last_nonnullable_ix - $subproduction_start_ix ) )
                {

                    # Remove the final rhs symbol, which is the lhs symbol
                    # of the next subproduction, and splice on the null
                    # aliases for the rest of the rule.
                    # At this point we are guaranteed all the
                    # rest of the rhs symbols DO have a null alias.
                    splice @{$last_nulling_rhs}, -1, 1,
                        (
                        map { $_->[Marpa::XS::Internal::Symbol::NULL_ALIAS] }
                            @{$rhs}[ $subproduction_end_ix + 1 .. $#{$rhs} ]
                        );
                } ## end if ( $next_subproduction_lhs and ...)
                else {
                    $last_nulling_rhs->[$last_nullable_subproduction_ix] =
                        $nothing_nulling_rhs
                        ->[$last_nullable_subproduction_ix]
                        ->[Marpa::XS::Internal::Symbol::NULL_ALIAS];
                } ## end else [ if ( $next_subproduction_lhs and ...)]

                push @factored_rh_sides, $last_nulling_rhs;

                # If there was only one proper nullable, then no more factors
                last FACTOR if not defined $proper_nullable_1_ix;

                # Now factor again, by nulling the first proper nullable
                # Don't include the rhs with one symbol already nulled,
                # if nulling anothing symbol would make the whole production
                # null.
                my @rh_sides_for_2nd_factoring = ($nothing_nulling_rhs);
                if ( not $nullable ) {
                    push @rh_sides_for_2nd_factoring, $last_nulling_rhs;
                }

                for my $rhs_to_refactor (@rh_sides_for_2nd_factoring) {
                    my $new_factored_rhs = [ @{$rhs_to_refactor} ];
                    $new_factored_rhs->[$proper_nullable_0_subproduction_ix] =
                        $nothing_nulling_rhs
                        ->[$proper_nullable_0_subproduction_ix]
                        ->[Marpa::XS::Internal::Symbol::NULL_ALIAS];
                    push @factored_rh_sides, $new_factored_rhs;
                } ## end for my $rhs_to_refactor (@rh_sides_for_2nd_factoring)

            }    # FACTOR

            for my $factor_rhs (@factored_rh_sides) {

                # if the LHS is the not LHS of the original rule, we have a
                # special CHAF header
                my $virtual_lhs = ( $subproduction_lhs != $lhs );

                # if a CHAF LHS was created for the next subproduction,
                # there is a CHAF continuation for this subproduction.
                # It applies to this factor if there is one of the first two
                # factors of more than two.

                # The only virtual symbol on the RHS will be the last
                # one.  If present it will be the lhs of the next
                # subproduction.  And, if it is nulling in this factored
                # subproduction, it is not a virtual symbol.
                my $virtual_rhs       = 0;
                my $real_symbol_count = scalar @{$factor_rhs};

                if (    $next_subproduction_lhs
                    and $factor_rhs->[-1] == $next_subproduction_lhs )
                {
                    $virtual_rhs = 1;
                    $real_symbol_count--;
                } ## end if ( $next_subproduction_lhs and $factor_rhs->[-1] ...)

                # NOTE: The following comment is obsolete.
                # Priorities are no longer used.
                #
                # Add new rule.   In assigning internal priority:
                # Leftmost subproductions have highest priority.
                # Within each subproduction,
                # the first factored production is
                # highest, last is lowest, but middle two are
                # reversed.
                my $new_rule = add_rule(
                    {   grammar           => $grammar,
                        lhs               => $subproduction_lhs,
                        rhs               => $factor_rhs,
                        virtual_lhs       => $virtual_lhs,
                        virtual_rhs       => $virtual_rhs,
                        real_symbol_count => $real_symbol_count,
                        action => $rule->[Marpa::XS::Internal::Rule::ACTION],
                        ranking_action => $rule
                            ->[Marpa::XS::Internal::Rule::RANKING_ACTION],
                    }
                );

                $new_rule->[Marpa::XS::Internal::Rule::USED]          = 1;
                $new_rule->[Marpa::XS::Internal::Rule::ACCESSIBLE]    = 1;
                $new_rule->[Marpa::XS::Internal::Rule::PRODUCTIVE]    = 1;
                $new_rule->[Marpa::XS::Internal::Rule::ORIGINAL_RULE] = $rule;
                $new_rule->[Marpa::XS::Internal::Rule::VIRTUAL_START] =
                    $subproduction_start_ix;
                $new_rule->[Marpa::XS::Internal::Rule::VIRTUAL_END] =
                    $subproduction_end_ix;

            }    # for each factored rhs

            # no more
            last SUBPRODUCTION if not $next_subproduction_lhs;
            $subproduction_lhs      = $next_subproduction_lhs;
            $subproduction_start_ix = $subproduction_end_ix + 1;
            $nullable = $subproduction_start_ix > $last_nonnullable_ix;

        }    # SUBPRODUCTION

    }    # RULE

    # Create a new start symbol
    my $new_start_symbol;
    my $start_is_nulling =
        $old_start_symbol->[Marpa::XS::Internal::Symbol::NULLING];
    my $start_is_productive =
        $old_start_symbol->[Marpa::XS::Internal::Symbol::PRODUCTIVE];
    if ( not $start_is_nulling ) {
        $new_start_symbol =
            assign_symbol( $grammar,
            $old_start_symbol->[Marpa::XS::Internal::Symbol::NAME] . q{[']} );
        $new_start_symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE] =
            $old_start_symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE];
        $new_start_symbol->[Marpa::XS::Internal::Symbol::PRODUCTIVE] =
            $start_is_productive;
        $new_start_symbol->[Marpa::XS::Internal::Symbol::ACCESSIBLE] = 1;
        $new_start_symbol->[Marpa::XS::Internal::Symbol::START]      = 1;

        # Create a new start rule
        my $new_start_rule = add_rule(
            {   grammar           => $grammar,
                lhs               => $new_start_symbol,
                rhs               => [$old_start_symbol],
                virtual_lhs       => 1,
                real_symbol_count => 1,
            }
        );

        $new_start_rule->[Marpa::XS::Internal::Rule::PRODUCTIVE] =
            $start_is_productive;
        $new_start_rule->[Marpa::XS::Internal::Rule::ACCESSIBLE] = 1;
        $new_start_rule->[Marpa::XS::Internal::Rule::USED]       = 1;
    } ## end if ( not $start_is_nulling )

    # If we created a null alias for the original start symbol, we need
    # to create a nulling start rule
    my $nulling_old_start =
          $start_is_nulling
        ? $old_start_symbol
        : $old_start_symbol->[Marpa::XS::Internal::Symbol::NULL_ALIAS];
    if ($nulling_old_start) {
        my $nulling_new_start_symbol;
        if ($new_start_symbol) {
            $nulling_new_start_symbol =
                alias_symbol( $grammar, $new_start_symbol );
        }
        else {
            $new_start_symbol = $nulling_new_start_symbol = assign_symbol(
                $grammar,
                $old_start_symbol->[Marpa::XS::Internal::Symbol::NAME]
                    . q{['][]}
            );
            $nulling_new_start_symbol
                ->[Marpa::XS::Internal::Symbol::NULL_VALUE] =
                $old_start_symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE];
            $nulling_new_start_symbol
                ->[Marpa::XS::Internal::Symbol::PRODUCTIVE] =
                $start_is_productive;
            $nulling_new_start_symbol->[Marpa::XS::Internal::Symbol::NULLING]
                = 1;
            $nulling_new_start_symbol->[Marpa::XS::Internal::Symbol::NULLABLE]
                = 1;
            $nulling_new_start_symbol
                ->[Marpa::XS::Internal::Symbol::ACCESSIBLE] = 1;
        } ## end else [ if ($new_start_symbol) ]
        $nulling_new_start_symbol->[Marpa::XS::Internal::Symbol::START] = 1;

        my $new_start_alias_rule = add_rule(
            {   grammar           => $grammar,
                lhs               => $nulling_new_start_symbol,
                rhs               => [],
                virtual_lhs       => 1,
                real_symbol_count => 1,
            }
        );

        # Nulling rules are not considered useful, but the top-level one is an exception
        $new_start_alias_rule->[Marpa::XS::Internal::Rule::PRODUCTIVE] =
            $start_is_productive;
        $new_start_alias_rule->[Marpa::XS::Internal::Rule::ACCESSIBLE] = 1;
        $new_start_alias_rule->[Marpa::XS::Internal::Rule::USED]       = 1;

    } ## end if ($nulling_old_start)

    $grammar->[Marpa::XS::Internal::Grammar::START] = $new_start_symbol;
    return;
} ## end sub rewrite_as_CHAF

1;
