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
    ID { Unique ID }
    NAME
    RANKING_ACTION
    NULL_VALUE { null value }
    WARN_IF_NO_NULL_VALUE { should have a null value -- warn
    if not }
);

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Rule

    C { A C structure }

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

    C { A C structure }
    ID { Unique ID, from libmarpa }

    RULES { array of rule refs }
    SYMBOLS { array of symbol refs }
    AHFA { array of states }
    ACTIONS { Default package in which to find actions }
    DEFAULT_ACTION { Action for rules without one }
    CYCLE_RANKING_ACTION { Action for ranking rules which cycle }
    TRACE_FILE_HANDLE
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

    =LAST_EVALUATOR_FIELD

    PROBLEMS { fatal problems }
    START_STATES { ref to array of the start states }

    =LAST_RECOGNIZER_FIELD

    START_NAME { name of original symbol }
    NFA { array of states }
    AHFA_BY_NAME { hash from AHFA name to AHFA reference }
    INACCESSIBLE_OK
    UNPRODUCTIVE_OK
    TRACE_RULES

    NEXT_SYMBOL_NAME {
        Should this be one of a hash of context values;
    }

    =LAST_FIELD
);

package Marpa::XS::Internal::Grammar;

use English qw( -no_match_vars );

use Marpa::XS::Internal::Carp_Not;

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

sub Marpa::XS::uncaught_error {
     my ($error) = @_;
     # This would be Carp::confess, but in the testing
     # the stack trace includes the hoped for error
     # message, which causes spurious success reports.
     Carp::croak(
	 "libmarpa reported an error which Marpa::XS did not catch\n",
	 qq{  The libmarpa internal error code was "$error"},
    );
}

package Marpa::XS::Internal::Grammar;

my %grammar_by_id;

sub Marpa::XS::Grammar::new {
    my ( $class, @arg_hashes ) = @_;

    my $grammar = [];
    bless $grammar, $class;

    # set the defaults and the default defaults
    $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE] = *STDERR;

    $grammar->[Marpa::XS::Internal::Grammar::TRACE_RULES]     = 0;
    $grammar->[Marpa::XS::Internal::Grammar::TRACING]         = 0;
    $grammar->[Marpa::XS::Internal::Grammar::WARNINGS]        = 1;
    $grammar->[Marpa::XS::Internal::Grammar::INACCESSIBLE_OK] = {};
    $grammar->[Marpa::XS::Internal::Grammar::UNPRODUCTIVE_OK] = {};
    $grammar->[Marpa::XS::Internal::Grammar::INFINITE_ACTION] = 'fatal';

    $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS]             = [];
    $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH]         = {};
    $grammar->[Marpa::XS::Internal::Grammar::RULES]               = [];
    $grammar->[Marpa::XS::Internal::Grammar::AHFA_BY_NAME]        = {};

    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C] =
        Marpa::XS::Internal::G_C->new($grammar);
    my $grammar_id = $grammar_c->id();
    $grammar->[Marpa::XS::Internal::Grammar::ID] = $grammar_id;
    $grammar_by_id{$grammar_id} = $grammar;
    Scalar::Util::weaken( $grammar_by_id{$grammar_id} );
    $grammar_c->message_callback_set(\&message_cb);
    $grammar_c->rule_callback_set(\&wrap_rule_cb);
    $grammar_c->symbol_callback_set(\&wrap_symbol_cb);

    $grammar->set(@arg_hashes);

    return $grammar;
} ## end sub Marpa::XS::Grammar::new

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
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];

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
                if $grammar_c->is_precomputed();
            Marpa::XS::exception('symbols value must be REF to HASH')
                if ref $value ne 'HASH';
            while ( my ( $symbol, $properties ) = each %{$value} ) {
                assign_user_symbol( $grammar, $symbol, $properties );
            }
        } ## end if ( defined( my $value = $args->{'symbols'} ) )

        if ( defined( my $value = $args->{'lhs_terminals'} ) ) {
            my $ok = $grammar_c->is_lhs_terminal_ok_set($value);
            if ( not $ok ) {
                my $error = $grammar_c->error();
                if ( $error eq "precomputed" ) {
                    Marpa::XS::exception(
                        'lhs_terminals option not allowed after grammar is precomputed'
                    );
                }
		Marpa::XS::uncaught_error($error);
            }
        }

        if ( defined( my $value = $args->{'terminals'} ) ) {
            Marpa::XS::exception(
                'terminals option not allowed after grammar is precomputed'
            ) if $grammar_c->is_precomputed();
            Marpa::XS::exception('terminals value must be REF to ARRAY')
                if ref $value ne 'ARRAY';
            for my $symbol ( @{$value} ) {
                assign_user_symbol( $grammar, $symbol, { terminal => 1 } );
            }
        } ## end if ( defined( my $value = $args->{'terminals'} ) )

        if ( defined( my $value = $args->{'start'} ) ) {
            Marpa::XS::exception(
                'start option not allowed after grammar is precomputed')
             if $grammar_c->is_precomputed();
            $grammar->[Marpa::XS::Internal::Grammar::START_NAME] = $value;
        } ## end if ( defined( my $value = $args->{'start'} ) )

        if ( defined( my $value = $args->{'rules'} ) ) {
            Marpa::XS::exception(
                'rules option not allowed after grammar is precomputed')
             if $grammar_c->is_precomputed();
            Marpa::XS::exception('rules value must be reference to array')
                if ref $value ne 'ARRAY';
            add_user_rules( $grammar, $value );
        } ## end if ( defined( my $value = $args->{'rules'} ) )

        if ( defined( my $value = $args->{'academic'} ) ) {
            Marpa::XS::exception(
                'academic option not allowed after grammar is precomputed')
                if $grammar_c->is_precomputed();
            $grammar_c->is_academic_set($value);
        }

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
	  ; # A no-op in the XS version
	}

        if ( defined( my $value = $args->{'infinite_action'} ) ) {
            if ( $value && $grammar_c->is_precomputed() ) {
                say {$trace_fh}
                    '"infinite_action" option is useless after grammar is precomputed'
                    or Marpa::XS::exception("Could not print: $ERRNO");
            }
            Marpa::XS::exception(
                q{infinite_action must be 'warn', 'quiet' or 'fatal'})
                if not $value ~~ [qw(warn quiet fatal)];
            $grammar->[Marpa::XS::Internal::Grammar::INFINITE_ACTION] =
                $value;
        } ## end if ( defined( my $value = $args->{'infinite_action'}...))

        if ( defined( my $value = $args->{'warnings'} ) ) {
            if ( $value && $grammar_c->is_precomputed() ) {
                say {$trace_fh}
                    q{"warnings" option is useless after grammar is precomputed}
                    or Marpa::XS::exception("Could not print: $ERRNO");
            }
            $grammar->[Marpa::XS::Internal::Grammar::WARNINGS] = $value;
        } ## end if ( defined( my $value = $args->{'warnings'} ) )

        if ( defined( my $value = $args->{'inaccessible_ok'} ) ) {
            if ( $value && $grammar_c->is_precomputed() ) {
                say {$trace_fh}
                    q{"inaccessible_ok" option is useless after grammar is precomputed}
                    or Marpa::XS::exception("Could not print: $ERRNO");

            }
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
            if ( $value && $grammar_c->is_precomputed() ) {
                say {$trace_fh}
                    q{"unproductive_ok" option is useless after grammar is precomputed}
                    or Marpa::XS::exception("Could not print: $ERRNO");
            }
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

sub Marpa::XS::Grammar::precompute {
    my $grammar = shift;

    my $tracing   = $grammar->[Marpa::XS::Internal::Grammar::TRACING];
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
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

    return $grammar if $grammar_c->is_precomputed();

    set_start_symbol($grammar);
    if ( not $grammar_c->precompute() ) {
        my $error = $grammar_c->error();

        # Be idempotent.  If the grammar is already precomputed, just
        # return success without doing anything.
        return $grammar if $error eq "precomputed";

        if ( $error eq "no rules" ) {
            Marpa::XS::exception(
                'Attempted to precompute grammar with no rules');
        }
        if ( $error eq 'empty rule and unmarked terminals' ) {
            Marpa::XS::exception(
                'A grammar with empty rules must mark its terminals or unset lhs_terminals'
            );
        }
        if ( $error eq 'counted nullable' ) {
            Marpa::XS::exception(
		Marpa::XS::Grammar::show_problems($grammar),
                'Counted nullables confuse Marpa::XS -- please rewrite the grammar'
            );
        }
	if ($error eq 'no start symbol') {
	    Marpa::XS::exception('No start symbol');
	}
	if ($error eq 'start symbol not on LHS') {
	    my $symbol_id = $grammar_c->context('symbol_id');
	    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
	    my $name = $symbols->[$symbol_id]->[Marpa::XS::Internal::Symbol::NAME];
	    Marpa::XS::exception(qq{Start symbol "$name" not on LHS of any rule});
	}
	if ($error eq 'unproductive start symbol') {
	    my $symbol_id = $grammar_c->context('symbol_id');
	    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
	    my $name = $symbols->[$symbol_id]->[Marpa::XS::Internal::Symbol::NAME];
	    Marpa::XS::exception(qq{Unproductive start symbol: "$name"});
	}
        Marpa::XS::uncaught_error($error);
    }

    # Here I update the Perl structures to reflect changes made
    # in the C structures.  Eventually I will eliminate the Perl
    # structurres, and this code with them.
    #
    # The intent is that this code will "roll forward" as I move
    # more and more of what follows it into libmarpa.
    shadow_all_rules($grammar);

    create_NFA($grammar);
    create_AHFA($grammar);
    mark_leo_states($grammar);
    $grammar->[Marpa::XS::Internal::Grammar::TERMINAL_NAMES] = {
        map { ( $_->[Marpa::XS::Internal::Symbol::NAME] => 1 ) }
            grep {
            $grammar_c->symbol_is_terminal(
                $_->[Marpa::XS::Internal::Symbol::ID] )
            } @{ $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS] }
    };
    populate_semantic_equivalences($grammar);
    populate_null_values($grammar);

    # A bit hackish here: INACCESSIBLE_OK is not a HASH ref iff
    # it is a Boolean TRUE indicating that all inaccessibles are OK.
    # A Boolean FALSE will have been replaced with an empty hash.
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
    
    # A bit hackish here: UNPRODUCTIVE_OK is not a HASH ref iff
    # it is a Boolean TRUE indicating that all inaccessibles are OK.
    # A Boolean FALSE will have been replaced with an empty hash.
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
                if defined $symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE];

	    my $symbol_name = $symbol->[Marpa::XS::Internal::Symbol::NAME];
            say {$trace_fh}
                qq{Zero length sequence for symbol without null value: "$symbol_name"}
                or Marpa::XS::exception("Could not print: $ERRNO");
        } ## end for my $symbol ( @{ $grammar->[...]})
    } ## end if ( $grammar->[Marpa::XS::Internal::Grammar::WARNINGS...])

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

sub Marpa::XS::Grammar::show_symbol {
    my ( $grammar, $symbol ) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $text      = q{};
    my $symbol_id = $symbol->[Marpa::XS::Internal::Symbol::ID];

    my $name = $symbol->[Marpa::XS::Internal::Symbol::NAME];
    $text .= "$symbol_id: $name,";

    $text .= sprintf ' lhs=[%s]',
        join q{ },
        $grammar_c->symbol_lhs_rule_ids($symbol_id);

    $text .= sprintf ' rhs=[%s]',
        join q{ },
        $grammar_c->symbol_rhs_rule_ids($symbol_id);

    $grammar_c->symbol_is_nullable($symbol_id) and $text .= ' nullable';
    $grammar_c->symbol_is_productive($symbol_id) or $text .= ' unproductive';
    $grammar_c->symbol_is_accessible($symbol_id) or $text .= ' inaccessible';
    $grammar_c->symbol_is_nulling($symbol_id)  and $text .= ' nulling';
    $grammar_c->symbol_is_terminal($symbol_id) and $text .= ' terminal';

    $text .= "\n";
    return $text;

} ## end sub Marpa::XS::show_symbol

sub Marpa::XS::Grammar::show_symbols {
    my ($grammar) = @_;
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $text      = q{};
    for my $symbol_ref ( @{$symbols} ) {
        $text .= $grammar->show_symbol($symbol_ref);
    }
    return $text;
} ## end sub Marpa::XS::Grammar::show_symbols

sub Marpa::XS::Grammar::show_nulling_symbols {
    my ($grammar) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return join q{ },
        sort map { $_->[Marpa::XS::Internal::Symbol::NAME] } grep {
        $grammar_c->symbol_is_nulling( $_->[Marpa::XS::Internal::Symbol::ID] )
        } @{$symbols};
} ## end sub Marpa::XS::Grammar::show_nulling_symbols

sub Marpa::XS::Grammar::show_nullable_symbols {
    my ($grammar) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return join q{ },
        sort map { $_->[Marpa::XS::Internal::Symbol::NAME] } grep {
        $grammar_c->symbol_is_nullable( $_->[Marpa::XS::Internal::Symbol::ID] )
        } @{$symbols};
} ## end sub Marpa::XS::Grammar::show_nullable_symbols

sub Marpa::XS::Grammar::show_productive_symbols {
    my ($grammar) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return join q{ }, sort map { $_->[Marpa::XS::Internal::Symbol::NAME] }
        grep {
        $grammar_c->symbol_is_productive(
            $_->[Marpa::XS::Internal::Symbol::ID] )
        } @{$symbols};
} ## end sub Marpa::XS::Grammar::show_productive_symbols

sub Marpa::XS::Grammar::show_accessible_symbols {
    my ($grammar) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return join q{ },
        sort map { $_->[Marpa::XS::Internal::Symbol::NAME] } grep {
        $grammar_c->symbol_is_accessible(
            $_->[Marpa::XS::Internal::Symbol::ID] )
        } @{$symbols};
} ## end sub Marpa::XS::Grammar::show_accessible_symbols

sub Marpa::XS::Grammar::inaccessible_symbols {
    my ($grammar) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return [
        sort map { $_->[Marpa::XS::Internal::Symbol::NAME] } grep {
            !$grammar_c->symbol_is_accessible(
                $_->[Marpa::XS::Internal::Symbol::ID] )
            } @{$symbols}
    ];
} ## end sub Marpa::XS::Grammar::inaccessible_symbols

sub Marpa::XS::Grammar::unproductive_symbols {
    my ($grammar) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return [
        sort map { $_->[Marpa::XS::Internal::Symbol::NAME] } grep {
            !$grammar_c->symbol_is_productive(
                $_->[Marpa::XS::Internal::Symbol::ID] )
            } @{$symbols}
    ];
} ## end sub Marpa::XS::Grammar::unproductive_symbols

sub Marpa::XS::Grammar::brief_rule {
    my ($grammar, $rule) = @_;
    my $rule_id = $rule->[Marpa::XS::Internal::Rule::ID];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $lhs_id = $grammar_c->rule_lhs($rule_id);
    my $text .= $rule_id . ': '
        . $symbols->[$lhs_id]->[Marpa::XS::Internal::Symbol::NAME] . ' ->';
    my $rh_length = $grammar_c->rule_length($rule_id);
    if ( $rh_length ) {
	my @rhs_ids = $grammar_c->rule_rhs($rule_id);
        $text .= q{ }
            . (
            join q{ }, map { $symbols->[$_]->[Marpa::XS::Internal::Symbol::NAME] } @rhs_ids
            );
    } ## end if ( @{$rhs} )
    return $text;
} ## end sub Marpa::XS::brief_rule

sub Marpa::XS::Grammar::brief_original_rule {
    my ($grammar, $rule) = @_;
    my $original_rule = $rule->[Marpa::XS::Internal::Rule::ORIGINAL_RULE]
        // $rule;
    return Marpa::XS::brief_rule($grammar, $original_rule);
} ## end sub Marpa::XS::brief_original_rule

sub Marpa::XS::Grammar::brief_virtual_rule {
    my ( $grammar, $rule, $dot_position ) = @_;
    my $original_rule = $rule->[Marpa::XS::Internal::Rule::ORIGINAL_RULE];
    if ( not defined $original_rule ) {
        return Marpa::XS::show_dotted_rule( $rule, $dot_position )
            if defined $dot_position;
        return $grammar->brief_rule($rule);
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
            . $grammar->brief_rule($original_rule)
            if defined $dot_position;
        return 'virtual ' . $grammar->brief_rule($original_rule);
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

sub Marpa::XS::Grammar::show_rule {
    my ($grammar, $rule) = @_;

    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $rule_id = $rule->[Marpa::XS::Internal::Rule::ID];

    my $stripped = $#{$rule} < Marpa::XS::Internal::Rule::LAST_FIELD;
    my $rhs      = $rule->[Marpa::XS::Internal::Rule::RHS];
    my @comment  = ();

    if ( not( @{$rhs} ) ) { push @comment, 'empty'; }

    if ($stripped) { push @comment, 'stripped'; }

    ELEMENT:
    for my $comment_element (
        [ 1, '!used', Marpa::XS::Internal::Rule::USED, ] )
    {
        my ( $reverse, $comment, $offset ) = @{$comment_element};
        next ELEMENT if not exists $rule->[$offset];
        my $value = $rule->[$offset];
        if ($reverse) { $value = !$value }
        next ELEMENT if not $value;
        push @comment, $comment;
    } ## end for my $comment_element ( ( [ 1, '!used', ...]))

    $grammar_c->rule_is_productive($rule_id) or push @comment, 'unproductive';
    $grammar_c->rule_is_accessible($rule_id) or push @comment, 'inaccessible';

    ELEMENT:
    for my $comment_element (
        ( [ 0, 'vlhs',         Marpa::XS::Internal::Rule::VIRTUAL_LHS, ],
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

    my $text = $grammar->brief_rule($rule);

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
        $text .= $grammar->show_rule($rule);
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
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $symbol_id   = $symbol_hash->{$name};
    return 0 if not defined $symbol_id;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $symbol  = $symbols->[$symbol_id];
    return $grammar_c->symbol_is_terminal( $symbol_id) ? 1 : 0;
} ## end sub Marpa::XS::Grammar::check_terminal

sub get_grammar_by_id {
    my ( $grammar_id ) = @_;
    my $grammar     = $grammar_by_id{$grammar_id};
    if (not defined $grammar) {
	Carp::croak(
	    "Attempting to use a grammar which has been garbage collected\n",
	    "Grammar with id ", q{#}, "$grammar_id no longer exists\n"
	);
    }
    $grammar;
}

sub message_cb {
    my ( $grammar_id, $message_id ) = @_;
    my $grammar     = get_grammar_by_id($grammar_id);
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $trace_fh =
        $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];
    if ($message_id eq "counted nullable") {
	my $symbol_id = $grammar_c->context("symbol_id");
	my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
	my $name = $symbols->[$symbol_id]->[Marpa::XS::Internal::Symbol::NAME];
	my $problem =
	    qq{Nullable symbol "$name" is on rhs of counted rule};
	push @{ $grammar->[Marpa::XS::Internal::Grammar::PROBLEMS] },
	    $problem;
	return;
    }
    if ($message_id eq "lhs is terminal") {
	my $symbol_id = $grammar_c->context("symbol_id");
	my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
	my $name = $symbols->[$symbol_id]->[Marpa::XS::Internal::Symbol::NAME];
	Marpa::XS::exception(
	    "lhs_terminals option is off, but Symbol $name is both an LHS and a terminal"
	);
    }
    if ($message_id eq 'loop rule') {
	return if $grammar->[Marpa::XS::Internal::Grammar::INFINITE_ACTION] eq 'quiet';
	my $loop_rule_id = $grammar_c->context("rule_id");
	my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
	my $rule = $rules->[$loop_rule_id];
        my $warning_rule = $rule->[Marpa::XS::Internal::Rule::ORIGINAL_RULE]
            // $rule;
	print {$trace_fh}
	    'Cycle found involving rule: ',
	    $grammar->brief_rule($warning_rule), "\n"
                or Marpa::XS::exception("Could not print: $ERRNO");
	return;
    }
    if ($message_id eq 'loop rule tally') {
        Marpa::XS::exception('Cycle in grammar, fatal error')
	    if $grammar->[Marpa::XS::Internal::Grammar::INFINITE_ACTION] eq 'fatal' and 
	    $grammar_c->context("loop_rule_count");
	return;
    }
    Marpa::XS::exception( qq{Unexpected message, type "$message_id"} );
    return;
}

sub wrap_symbol_cb {
    my ( $grammar_id, $symbol_id ) = @_;
    my $grammar     = get_grammar_by_id($grammar_id);
    my $grammar_c   = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols     = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $symbol      = bless [], 'Marpa::XS::Internal::Symbol';
    my $name;
    DETERMINE_NAME: {
        $name = $grammar->[Marpa::XS::Internal::Grammar::NEXT_SYMBOL_NAME];
        $grammar->[Marpa::XS::Internal::Grammar::NEXT_SYMBOL_NAME] = undef;
        last DETERMINE_NAME if defined $name;
	my $old_start_id = $grammar_c->context('old_start_id');
	if (defined $old_start_id) { # This is new start symbol
	    my $old_name = $symbols->[$old_start_id]->[ Marpa::XS::Internal::Symbol::NAME];
	    $name = $old_name . q{[']};
	    $grammar_c->symbol_is_nulling($symbol_id) and $name .= '[]';
            last DETERMINE_NAME;
	}
        my $proper_alias_id = $grammar_c->symbol_proper_alias($symbol_id);
        if ( defined $proper_alias_id ) {
            my $proper_alias = $symbols->[$proper_alias_id];
            $name = $symbol->[Marpa::XS::Internal::Symbol::NAME] =
                $proper_alias->[Marpa::XS::Internal::Symbol::NAME] . '[]';
            last DETERMINE_NAME;
        }
	# If we are here, this should be a virtual LHS from the CHAF
	# rewrite.
	my $virtual_end = $grammar_c->context('virtual_end');
	if (defined $virtual_end)  {
	    my $rule_id = $grammar_c->context('rule_id') // "[RULE?]";
	    my $lhs_id = $grammar_c->context('lhs_id') // "[LHS?]";
            my $lhs = $symbols->[$lhs_id];
	    $name = $lhs->[Marpa::XS::Internal::Symbol::NAME]
		. '[R' . $rule_id . q{:} . ( $virtual_end + 1 ) . ']';
            last DETERMINE_NAME;
	}
        die "Internal Marpa Perl wrapper error: No way to name unnamed symbol"
            if not defined $proper_alias_id;
    }
    $symbol->[Marpa::XS::Internal::Symbol::NAME] = $name;
    $symbol->[Marpa::XS::Internal::Symbol::ID] = $symbol_id;
    $symbols->[$symbol_id]                     = $symbol;
    $symbol_hash->{$name}                      = $symbol_id;

    return;
}

# This routine to be deleted after development
sub shadow_rule {
    my ( $grammar, $new_rule ) = @_;
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];

    my $new_rule_id = $new_rule->[Marpa::XS::Internal::Rule::ID];
    ## Scope all the variables, even the useful stuff,
    # so they can't be used later
    # This "shadowing" code is eventually to be eliminated
    my $lhs_id  = $grammar_c->rule_lhs($new_rule_id);
    my @rhs_ids = $grammar_c->rule_rhs($new_rule_id);
    $new_rule->[Marpa::XS::Internal::Rule::VIRTUAL_LHS] =
        $grammar_c->rule_is_virtual_lhs($new_rule_id);
    $new_rule->[Marpa::XS::Internal::Rule::VIRTUAL_RHS] =
        $grammar_c->rule_is_virtual_rhs($new_rule_id);
    $new_rule->[Marpa::XS::Internal::Rule::DISCARD_SEPARATION] =
        $grammar_c->rule_is_discard_separation($new_rule_id);
    $new_rule->[Marpa::XS::Internal::Rule::REAL_SYMBOL_COUNT] =
        $grammar_c->real_symbol_count($new_rule_id);
    $new_rule->[Marpa::XS::Internal::Rule::CYCLE] =
        $grammar_c->rule_is_loop($new_rule_id);
    $new_rule->[Marpa::XS::Internal::Rule::VIRTUAL_CYCLE] =
        $grammar_c->rule_is_virtual_loop($new_rule_id);
    my $original_rule_id = $grammar_c->rule_original($new_rule_id);

    if ( defined $original_rule_id ) {
        $new_rule->[Marpa::XS::Internal::Rule::ORIGINAL_RULE] =
            $rules->[$original_rule_id];
    }
    $new_rule->[Marpa::XS::Internal::Rule::USED] =
        $grammar_c->rule_is_used($new_rule_id);
    $new_rule->[Marpa::XS::Internal::Rule::LHS] = $symbols->[$lhs_id];
    $new_rule->[Marpa::XS::Internal::Rule::RHS] =
        [ map { $symbols->[$_] } @rhs_ids ];

}

sub shadow_all_rules {
    my ( $grammar ) = @_;
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    for my $rule (@{$rules}) {
         shadow_rule($grammar, $rule);
    }
}

sub wrap_rule_cb {
    my ( $grammar_id, $new_rule_id ) = @_;
    my $grammar   = get_grammar_by_id($grammar_id);
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $new_rule  = bless [], 'Marpa::XS::Internal::Rule';
    $#$new_rule = Marpa::XS::Internal::Rule::LAST_FIELD;
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    $new_rule->[Marpa::XS::Internal::Rule::ID] = $new_rule_id;
    $rules->[$new_rule_id] = $new_rule;

    shadow_rule( $grammar, $new_rule );

    my $trace_rules = $grammar->[Marpa::XS::Internal::Grammar::TRACE_RULES];
    my $trace_fh =
        $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];
    if ($trace_rules) {
        my $lhs_id  = $grammar_c->rule_lhs($new_rule_id);
        my @rhs_ids = $grammar_c->rule_rhs($new_rule_id);
        my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
        print {$trace_fh} 'Added rule #', $new_rule_id, ': ',
            $symbols->[$lhs_id]->[Marpa::XS::Internal::Symbol::NAME], ' -> ',
            join( q{ },
            map { $symbols->[$_]->[Marpa::XS::Internal::Symbol::NAME] }
                @rhs_ids ),
            "\n"
            or Marpa::XS::exception("Could not print: $ERRNO");
    } ## end if ($trace_rules)
    return;
}

sub populate_semantic_equivalences {
    my ($grammar) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    RULE: for my $rule ( @{$rules} ) {

        # Do I need to copy the actions for this rule from another rule?
        my $rule_id = $rule->[Marpa::XS::Internal::Rule::ID];
        my $semantic_equivalent_id =
            $grammar_c->semantic_equivalent($rule_id);
        next RULE if not defined $semantic_equivalent_id;
        my $semantic_equivalent = $rules->[$semantic_equivalent_id];
        $rule->[Marpa::XS::Internal::Rule::RANKING_ACTION] =
            $semantic_equivalent->[Marpa::XS::Internal::Rule::RANKING_ACTION];
        next RULE if not defined $grammar_c->rule_length($rule_id);
        $rule->[Marpa::XS::Internal::Rule::ACTION] =
            $semantic_equivalent->[Marpa::XS::Internal::Rule::ACTION];
    }
}

sub populate_null_values {
    my ($grammar) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $symbol_hash   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    RULE: for my $nulling_symbol ( @{$symbols} ) {

        # Copy the null values for a nulling alias from its proper alias
        my $nulling_symbol_id =
            $nulling_symbol->[Marpa::XS::Internal::Symbol::ID];
        next RULE if not $grammar_c->symbol_is_nulling($nulling_symbol_id);
	if ( $grammar_c->symbol_is_start($nulling_symbol_id) ) {
	    my $old_start_symbol_id =
		$symbol_hash->{ $grammar->[Marpa::XS::Internal::Grammar::START_NAME]
		};
	    my $null_value =
		$symbols->[$old_start_symbol_id]
		->[Marpa::XS::Internal::Symbol::NULL_VALUE];
	    $nulling_symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE] = $null_value;
	    next RULE;
	}
        my $proper_alias_id =
            $grammar_c->symbol_proper_alias($nulling_symbol_id);
        next RULE if not defined $proper_alias_id;
        my $proper_alias = $symbols->[$proper_alias_id];
        $nulling_symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE] =
            $proper_alias->[Marpa::XS::Internal::Symbol::NULL_VALUE];
    }
}

sub Marpa::XS::Internal::Symbol::new {
    my ( $class, $grammar, $name ) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    $grammar->[Marpa::XS::Internal::Grammar::NEXT_SYMBOL_NAME] = $name;
    my $symbol_id = $grammar_c->symbol_new();
    return $symbol_id;
} ## end sub Marpa::XS::Internal::Symbol::new

sub Marpa::XS::Internal::Symbol::null_alias {
    my ( $symbol, $grammar ) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $null_alias_id = $grammar_c->symbol_null_alias( $symbol->[Marpa::XS::Internal::Symbol::ID] );
    return if not defined $null_alias_id;
    return $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS]->[$null_alias_id];
}

sub assign_symbol {
    my ( $grammar, $name ) = @_;

    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $symbol_id = $symbol_hash->{$name};
    $symbol_id //= Marpa::XS::Internal::Symbol->new($grammar, $name);

    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    return $symbols->[$symbol_id];
} ## end sub assign_symbol

sub assign_user_symbol {
    my $grammar = shift;
    my $name    = shift;
    my $options = shift;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];

    if ( my $type = ref $name ) {
        Marpa::XS::exception(
            "Symbol name was ref to $type; it must be a scalar string");
    }
    Marpa::XS::exception("Symbol name $name ends in ']': that's not allowed")
        if $name =~ /\]\z/xms;
    my $symbol = assign_symbol( $grammar, $name );
    my $symbol_id = $symbol->[Marpa::XS::Internal::Symbol::ID];

    my $ranking_action;
    my $terminal;

    PROPERTY: while ( my ( $property, $value ) = each %{$options} ) {
        if (not $property ~~
            [qw(terminal ranking_action null_value)] )
        {
            Marpa::XS::exception(qq{Unknown symbol property "$property"});
        }
        if ( $property eq 'terminal' ) {
            $grammar_c->symbol_is_terminal_set( $symbol_id, $value );
        }
        if ( $property eq 'null_value' ) {
            $symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE] = \$value;
        }
    } ## end while ( my ( $property, $value ) = each %{$options} )

    return $symbol;

} ## end sub assign_user_symbol

sub Marpa::XS::Internal::Rule::action_set {
    my ( $rule, $grammar, $action ) = @_;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $rule_id     = $rule->[Marpa::XS::Internal::Rule::ID];
    my $rh_length = $grammar_c->rule_length($rule_id);
    if ( defined $action and $rh_length < 0 ) {
        my $lhs_id = $grammar_c->rule_lhs($rule_id);
        my $lhs_name =
            $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS]->[$lhs_id]
            ->[Marpa::XS::Internal::Symbol::NAME];
        Marpa::XS::exception(
            "Empty Rule cannot have an action\n",
            "  Rule #$rule_id: $lhs_name  -> /* empty */",
            "\n"
        );
    }
    $rule->[Marpa::XS::Internal::Rule::ACTION] = $action;
}

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
                my ( $lhs, $rhs, $action ) = @{$rule};
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

    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];

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

    # Is this is an ordinary, non-counted rule?
    my $is_ordinary_rule = scalar @{$rhs_names} == 0 || !defined $min;
    if ( defined $separator_name and $is_ordinary_rule ) {
        if ( defined $separator_name ) {
            Marpa::XS::exception(
                'separator defined for rule without repetitions');
        }
    }

    my @rhs_ids = map { $_->[Marpa::XS::Internal::Symbol::ID] } @{$rhs};
    my $lhs_id = $lhs->[Marpa::XS::Internal::Symbol::ID];

    if ( $is_ordinary_rule ) {
        my $ordinary_rule_id = $grammar_c->rule_new( $lhs_id, \@rhs_ids );
	if (not defined $ordinary_rule_id) {
	    my $rule_description = "$lhs_name -> " . ( join q{ }, @{$rhs_names} );
	    my $error = $grammar_c->error();
	    my $problem_description =
		$error eq "duplicate rule"
		? 'Duplicate rule'
		: qq{Unknown problem ("$error")};
	    Marpa::XS::exception( "$problem_description: $rule_description" );
	}
        my $ordinary_rule    = $rules->[$ordinary_rule_id];
        $ordinary_rule->action_set( $grammar, $action );
        $ordinary_rule->[Marpa::XS::Internal::Rule::RANKING_ACTION] =
            $ranking_action;
        return;
    }    # not defined $min

    Marpa::XS::exception('Only one rhs symbol allowed for counted rule')
        if scalar @{$rhs_names} != 1;

    # For a zero-length sequence
    # with an action
    # warn if we don't also have a null value.
    if ( $min == 0 and $action ) {
        $lhs->[Marpa::XS::Internal::Symbol::WARN_IF_NO_NULL_VALUE] = 1;
    }

    # create the separator symbol, if we're using one
    my $separator;
    my $separator_id = -1;
    if ( defined $separator_name ) {
        $separator = assign_user_symbol( $grammar, $separator_name );
	$separator_id = $separator->[Marpa::XS::Internal::Symbol::ID];
    }

    # Name the internal lhs symbol
    my $internal_lhs_name = $lhs_name . '[Subseq:' . $lhs_id . ':' . $rhs_ids[0] . ']';
    $grammar->[Marpa::XS::Internal::Grammar::NEXT_SYMBOL_NAME] =
        $internal_lhs_name;

    my $original_rule_id =
        $grammar_c->sequence_new( $lhs_id, $rhs_ids[0],
	{ separator => $separator_id,
	    keep => $keep_separation,
	    proper => $proper_separation,
	    min => $min,
	} );
    if ( not defined $original_rule_id ) {
        my $rule_description = "$lhs_name -> " . ( join q{ }, @{$rhs_names} );
        my $error = $grammar_c->error();
        my $problem_description =
            $error eq "duplicate rule"
            ? 'Duplicate rule'
            : qq{Unknown problem ("$error")};
        Marpa::XS::exception("$problem_description: $rule_description");
    }

    # The original rule for a sequence rule is
    # not actually used in parsing,
    # but some of the rewritten sequence rules are its
    # semantic equivalents.
    my $original_rule = $rules->[$original_rule_id];
    $original_rule->action_set( $grammar, $action );
    $original_rule->[Marpa::XS::Internal::Rule::RANKING_ACTION] =
        $ranking_action;

    $grammar->[Marpa::XS::Internal::Grammar::NEXT_SYMBOL_NAME] = undef;

    return;

} ## end sub add_user_rule

sub set_start_symbol {
    my $grammar = shift;

    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $start_name = $grammar->[Marpa::XS::Internal::Grammar::START_NAME];
    # Let libmarpa catch this error
    return if not defined $start_name;
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $start_id    = $symbol_hash->{$start_name};
    Marpa::XS::exception(qq{Start symbol "$start_name" not in grammar})
        if not defined $start_id;

    if (!$grammar_c->start_symbol_set($start_id)) {
        my $error = $grammar_c->error();
        Marpa::XS::uncaught_error($error);
    }
} ## end sub check_start

sub create_NFA {
    my $grammar = shift;
    my ( $rules, $symbols ) = @{$grammar}[
        Marpa::XS::Internal::Grammar::RULES,
        Marpa::XS::Internal::Grammar::SYMBOLS,
    ];
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];

    my $start_symbol_id = $grammar_c->start_symbol();
    my @start_rule_ids  = $grammar_c->symbol_lhs_rule_ids($start_symbol_id);
    my $start_alias_id  = $grammar_c->symbol_null_alias($start_symbol_id);
    if ( defined $start_alias_id ) {
        push @start_rule_ids,
            $grammar_c->symbol_lhs_rule_ids($start_alias_id);
    }

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
	next RULE if not $useful;
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

        my $next_symbol_id = $next_symbol->[Marpa::XS::Internal::Symbol::ID];

        if ( $grammar_c->symbol_is_nulling($next_symbol_id) ) {
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
            $grammar_c->symbol_lhs_rule_ids($next_symbol_id) )
        {

            my $predicted_rule = $rules->[$predicted_rule_id];
            next RULE
                if not $predicted_rule->[Marpa::XS::Internal::Rule::USED];
            push @{ $transition->{q{}} }, $NFA_by_item[$predicted_rule_id][0];
        } ## end for my $predicted_rule_id ( $grammar_c->lhs_rule_ids(...))
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
    my $grammar_c = $grammar->[ Marpa::XS::Internal::Grammar::C ];

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
                my $item   = $NFA_state->[Marpa::XS::Internal::NFA::ITEM];
                my $rule   = $item->[Marpa::XS::Internal::LR0_item::RULE];
                my $lhs    = $rule->[Marpa::XS::Internal::Rule::LHS];
                my $lhs_id = $lhs->[Marpa::XS::Internal::Symbol::ID];

                $lhs_list->[$lhs_id] = 1;
                push @{ $complete_rules->[$lhs_id] }, $rule;

                $grammar_c->symbol_is_start($lhs_id) and $start_rule = $rule;
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
    my $grammar   = shift;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $AHFA      = $grammar->[Marpa::XS::Internal::Grammar::AHFA];

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
                not $grammar_c->symbol_is_nulling(
                    $_->[Marpa::XS::Internal::Symbol::ID] );
            }
            reverse @{$rhs}
        );

        # In the null parse rules, there will be no non-nulling symbol
        next STATE if not defined $non_nulling;

        my $non_nulling_id = $non_nulling->[Marpa::XS::Internal::Symbol::ID];

        # Not a Leo completion unless the next non-nulling symbol is on at least
        # one left hand side.
        next STATE
            if not scalar $grammar_c->symbol_lhs_rule_ids($non_nulling_id);
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

# For efficiency, steps in the CHAF evaluation
# work on a the-last-is-the-rest principle --
# productions
# with a CHAF head always return reference to an array
# of values, of which the last value is (in turn)
# a reference to an array with the "rest" of the values.
# An empty array signals that there are no more.

1;
