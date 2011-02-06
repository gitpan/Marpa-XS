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

package Marpa::XS::Recognizer;

use 5.010;
use warnings;

# As of 9 Aug 2010 there's a problem with this perlcritic check
## no critic (TestingAndDebugging::ProhibitNoWarnings)
no warnings 'recursion';
## use critic

use strict;
use integer;

use English qw( -no_match_vars );

use Marpa::XS::Offset qw(
    :package=Marpa::XS::Internal::Earley_Set
    ITEMS { The Earley items for this set. }
    HASH { Hash by origin & state.  To prevent dups. }
    POSTDOT { Index by postdot symbol. }
);

# Elements of the EARLEY ITEM structure
# Note that these are Earley items as modified by Aycock & Horspool,
# with AHFA states instead of
# LR(0) items.

# We don't prune the Earley items because we want ORIGIN and SET
# around for debugging.

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Earley_Item

    ID { ID of Earley item.  Unique within recognizer. }
    STATE { The AHFA state. }
    LINKS { A list of the links from the completer step. }

    LEO_LINKS { Leo Links sources -- not necessarily unique.
    No more than one Leo link can come from a single
    Earleme.
    But the distance to the origin of this item can be
    "factored" differently between predecessor and cause.
    Each different "factoring" can contribute a Leo
    link. }

    ORIGIN { The number of the Earley set with the parent item(s) }
    SET { The set this item is in. For debugging. }

);

our $LEO_CLASS;
$LEO_CLASS = 'Marpa::XS::Internal::Leo_Item';

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Leo_Item

    { Memoized from base Earley item. }
    BASE_TO_STATE { The AHFA to-state of the base's transition. }

    LEO_SYMBOL { A symbol name.  Used only for tracing and debugging. }

    { Memoized.  Recomputation would require recursion --
    possibly through all Earley sets so far. }
    ORIGIN { The number of the Earley set with the parent item(s) }

    BASE { The Earley item on which this item is based. }

    PREDECESSOR { The Leo item prior in the series to this one. }
    SET { The set this item is in.  Used only for tracing and debugging. }

    { Memoized.  Recomputation would require recursion --
    possibly through all Earley sets so far. }
    TOP_TO_STATE { The AHFA to-state of the top-level transition. }

);

# Elements of the RECOGNIZER structure
use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Recognizer

    C { A C structure }

    GRAMMAR { the grammar used }
    EARLEY_SETS { the array of the Earley sets }
    NEXT_EARLEY_ITEM_ID { ID of the next Earley item to be created. }
    FURTHEST_EARLEME { last earley set with something in it }
    LAST_COMPLETED_EARLEME { the current earleme }
    FINISHED
    EXHAUSTED { can parse continue? }
    EXPECTED_TERMINALS { terminals which are expected at the
        current earleme }
    USE_LEO { Use Leo items? }
    INTERACTIVE { Return undef if token is rejected? }
    SLOTS { Array of slots for data to pass to libmarpa }

    TRACE_FILE_HANDLE

    END
    CLOSURES
    TRACE_ACTIONS
    TRACE_VALUES
    TRACE_TASKS
    TRACING
    MAX_PARSES
    NULL_VALUES
    RANKING_METHOD

    { The following fields must be reinitialized when
    evaluation is reset }

    SINGLE_PARSE_MODE
    PARSE_COUNT :{ number of parses in an ambiguous parse :}

    AND_NODES
    AND_NODE_HASH
    OR_NODES
    OR_NODE_HASH

    ITERATION_STACK

    EVALUATOR_RULES

    { This is the end of the list of fields which
    must be reinitialized when evaluation is reset }

    TRACE_EARLEY_SETS
    TRACE_TERMINALS
    WARNINGS

    MODE

);

package Marpa::XS::Internal::Recognizer;

use Marpa::XS::Internal::Carp_Not;

use English qw( -no_match_vars );

use constant EARLEME_MASK => ~(0x7fffffff);

my $parse_number = 0;

sub message_cb {
    my ( $recce_id, $message_id ) = @_;
    my $recce     = get_recognizer_by_id($recce_id);
    my $recce_c = $recce->[Marpa::XS::Internal::Grammar::C];
    my $trace_fh =
        $recce->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];
    Marpa::XS::exception( qq{Unexpected message, type "$message_id"} );
    return;
}

# Returns the new parse object or throws an exception
sub Marpa::XS::Recognizer::new {
    my ( $class, @arg_hashes ) = @_;
    my $recce = bless [], $class;

    my $grammar;
    ARG_HASH: for my $arg_hash (@arg_hashes) {
        if ( defined( $grammar = $arg_hash->{grammar} ) ) {
            delete $arg_hash->{grammar};
            last ARG_HASH;
        }
    } ## end for my $arg_hash (@arg_hashes)
    Marpa::XS::exception('No grammar specified') if not defined $grammar;

    $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR] = $grammar;

    my $grammar_class = ref $grammar;
    Marpa::XS::exception(
        "${class}::new() grammar arg has wrong class: $grammar_class")
        if not $grammar_class eq 'Marpa::XS::Grammar';

    my $grammar_c  = $grammar->[Marpa::XS::Internal::Grammar::C];

    my $problems = $grammar->[Marpa::XS::Internal::Grammar::PROBLEMS];
    if ($problems) {
        Marpa::XS::exception(
            Marpa::XS::Grammar::show_problems($grammar),
            "Attempt to parse grammar with fatal problems\n",
            'Marpa::XS cannot proceed',
        );
    } ## end if ($problems)

    # set the defaults
    local $Marpa::XS::Internal::TRACE_FH = my $trace_fh =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE] =
        $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];

    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C] =
        Marpa::XS::Internal::R_C->new( $grammar_c );
    if ( not defined $recce_c ) {
        my $error = $grammar_c->error();
        if ( $error eq 'grammar not precomputed' ) {
            Marpa::XS::exception(
                'Attempt to parse grammar which is not precomputed');
        }
        Marpa::XS::exception(
            qq{Recognizer created failed with unexpected error code: "$error"}
        );
    } ## end if ( not defined $recce_c )
    $recce_c->message_callback_set(\&message_cb);

    $recce->[Marpa::XS::Internal::Recognizer::WARNINGS] = 1;
    $recce->[Marpa::XS::Internal::Recognizer::MODE]           = 'default';
    $recce->[Marpa::XS::Internal::Recognizer::RANKING_METHOD] = 'none';
    $recce->[Marpa::XS::Internal::Recognizer::USE_LEO]        = 1;
    $recce->[Marpa::XS::Internal::Recognizer::MAX_PARSES]     = 0;
    $recce->[Marpa::XS::Internal::Recognizer::NEXT_EARLEY_ITEM_ID]     = 0;
    $recce->[Marpa::XS::Internal::Recognizer::SLOTS]     = Marpa::XS::Internal::Slot->new();
    $recce->reset_evaluation();

    $recce->set(@arg_hashes);

    if (    $grammar_c->has_loop()
        and $recce->[Marpa::XS::Internal::Recognizer::RANKING_METHOD] ne
        'none'
        and not $grammar->[Marpa::XS::Internal::Grammar::CYCLE_RANKING_ACTION]
        )
    {
        Marpa::XS::exception(
            "The grammar cycles (is infinitely ambiguous)\n",
            "    but it has no 'cycle_ranking_action'.\n",
            "    Either rewrite the grammar to eliminate cycles\n",
            "    or define a 'cycle ranking action'\n"
        );
    }

    my $trace_terminals =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_TERMINALS] // 0;
    my $trace_tasks = $recce->[Marpa::XS::Internal::Recognizer::TRACE_TASKS]
        // 0;

    if (not $recce_c->start_input()) {
        my $error = $recce_c->error();
        Marpa::XS::exception(
            qq{Recognizer start of input failed with unexpected error code: "$error"}
        );
    }

    # Some of this processing -- to find terminals and Leo symbols
    # by state -- should perhaps be done in the grammar.

    my $terminal_names =
        $grammar->[Marpa::XS::Internal::Grammar::TERMINAL_NAMES];

    my $AHFA        = $grammar->[Marpa::XS::Internal::Grammar::AHFA];
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];

    my @earley_items = ();

    my $start_states = $grammar->[Marpa::XS::Internal::Grammar::START_STATES];
    my %postdot      = ();

    for my $state ( @{$start_states} ) {
        my $state_id = $state->[Marpa::XS::Internal::AHFA::ID];
        my $name     = sprintf
            'S%d@%d-%d',
            $state_id, 0, 0;

        my $item = [];
        $item->[Marpa::XS::Internal::Earley_Item::ID] =
            $recce->[Marpa::XS::Internal::Recognizer::NEXT_EARLEY_ITEM_ID]++;
        $item->[Marpa::XS::Internal::Earley_Item::STATE]  = $state;
        $item->[Marpa::XS::Internal::Earley_Item::ORIGIN] = 0;
        $item->[Marpa::XS::Internal::Earley_Item::LINKS]  = [];
        $item->[Marpa::XS::Internal::Earley_Item::SET]    = 0;

        push @earley_items, $item;

        while ( my ( $transition_symbol, $to_states ) =
            each %{ $state->[Marpa::XS::Internal::AHFA::TRANSITION] } )
        {
            my @to_states = grep {ref} @{$to_states};
            push @{ $postdot{$transition_symbol} }, $item;
        } ## end while ( my ( $transition_symbol, $to_states ) = each %{...})

    } ## end for my $state ( @{$start_states} )

    $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR]     = $grammar;
    my $earley_set = [];
    $earley_set->[Marpa::XS::Internal::Earley_Set::POSTDOT] = \%postdot;
    $earley_set->[Marpa::XS::Internal::Earley_Set::ITEMS] = \@earley_items;
    $recce->[Marpa::XS::Internal::Recognizer::EARLEY_SETS] = [$earley_set];

    $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME]       = 0;
    $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME] = 0;

    my @terminals_expected = grep { $terminal_names->{$_} } keys %postdot;
    $recce->[Marpa::XS::Internal::Recognizer::EXPECTED_TERMINALS] =
        \@terminals_expected;

    $recce->[Marpa::XS::Internal::Recognizer::EXHAUSTED] =
        scalar @terminals_expected <= 0;

    if ( $trace_terminals > 1 ) {
        for my $terminal (@terminals_expected) {
            say {$Marpa::XS::Internal::TRACE_FH}
                qq{Expecting "$terminal" at earleme 0}
                or Marpa::XS::exception("Cannot print: $ERRNO");
        }
    } ## end if ( $trace_terminals > 1 )

    return $recce;
} ## end sub Marpa::XS::Recognizer::new

use constant RECOGNIZER_OPTIONS => [
    qw{
        closures
        end
	interactive
        leo
        max_parses
        mode
        ranking_method
        too_many_earley_items
        trace_actions
        trace_earley_sets
        trace_fh
        trace_file_handle
        trace_tasks
        trace_terminals
        trace_values
        warnings
        }
];

use constant RECOGNIZER_MODES => [qw(default stream)];

sub Marpa::XS::Recognizer::reset_evaluation {
    my ($recce) = @_;
    $recce->[Marpa::XS::Internal::Recognizer::PARSE_COUNT]       = 0;
    $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] = undef;
    $recce->[Marpa::XS::Internal::Recognizer::AND_NODES]         = [];
    $recce->[Marpa::XS::Internal::Recognizer::AND_NODE_HASH]     = {};
    $recce->[Marpa::XS::Internal::Recognizer::OR_NODES]          = [];
    $recce->[Marpa::XS::Internal::Recognizer::OR_NODE_HASH]      = {};
    $recce->[Marpa::XS::Internal::Recognizer::ITERATION_STACK]   = [];
    $recce->[Marpa::XS::Internal::Recognizer::EVALUATOR_RULES]   = [];
    return;
} ## end sub Marpa::XS::Recognizer::reset_evaluation

sub Marpa::XS::Recognizer::set {
    my ( $recce, @arg_hashes ) = @_;
    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];

    # This may get changed below
    my $trace_fh =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE];

    for my $args (@arg_hashes) {

        my $ref_type = ref $args;
        if ( not $ref_type or $ref_type ne 'HASH' ) {
            Carp::croak(
                'Marpa::XS Recognizer expects args as ref to HASH, got ',
                ( "ref to $ref_type" || 'non-reference' ),
                ' instead'
            );
        } ## end if ( not $ref_type or $ref_type ne 'HASH' )
        if (my @bad_options =
            grep {
                not $_ ~~ Marpa::XS::Internal::Recognizer::RECOGNIZER_OPTIONS
            }
            keys %{$args}
            )
        {
            Carp::croak( 'Unknown option(s) for Marpa::XS Recognizer: ',
                join q{ }, @bad_options );
        } ## end if ( my @bad_options = grep { not $_ ~~ ...})

        if ( defined( my $value = $args->{'interactive'} ) ) {
            $recce->[Marpa::XS::Internal::Recognizer::INTERACTIVE] =
                $value ? 1 : 0;
        }

        if ( defined( my $value = $args->{'leo'} ) ) {
            $recce->[Marpa::XS::Internal::Recognizer::USE_LEO] =
                $value ? 1 : 0;
        }

        if ( defined( my $value = $args->{'max_parses'} ) ) {
            $recce->[Marpa::XS::Internal::Recognizer::MAX_PARSES] = $value;
        }

        if ( defined( my $value = $args->{'mode'} ) ) {
            if (not $value ~~
                Marpa::XS::Internal::Recognizer::RECOGNIZER_MODES )
            {
                Carp::croak( 'Unknown mode for Marpa::XS Recognizer: ',
                    $value );
            } ## end if ( not $value ~~ ...)
            $recce->[Marpa::XS::Internal::Recognizer::MODE] = $value;
        } ## end if ( defined( my $value = $args->{'mode'} ) )

        if ( defined( my $value = $args->{'ranking_method'} ) ) {
            Marpa::XS::exception(
                q{ranking_method must be 'constant' or 'none'})
                if not $value ~~ [qw(constant none)];
            $recce->[Marpa::XS::Internal::Recognizer::RANKING_METHOD] =
                $value;
        } ## end if ( defined( my $value = $args->{'ranking_method'} ...))

        if ( defined( my $value = $args->{'trace_fh'} ) ) {
            $trace_fh =
                $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE] =
                $value;
        }

        if ( defined( my $value = $args->{'trace_file_handle'} ) ) {
            $trace_fh =
                $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE] =
                $value;
        }

        if ( defined( my $value = $args->{'trace_actions'} ) ) {
            $recce->[Marpa::XS::Internal::Recognizer::TRACE_ACTIONS] = $value;
            ## Do not allow setting this option in recognizer for single parse mode
            $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] = 0;
            if ($value) {
                say {$trace_fh} 'Setting trace_actions option'
                    or Marpa::XS::exception("Cannot print: $ERRNO");
                $recce->[Marpa::XS::Internal::Recognizer::TRACING] = 1;
            }
        } ## end if ( defined( my $value = $args->{'trace_actions'} ))

        if ( defined( my $value = $args->{'trace_tasks'} ) ) {
            Marpa::XS::exception('trace_tasks must be set to a number >= 0')
                if $value !~ /\A\d+\z/xms;
            $recce->[Marpa::XS::Internal::Recognizer::TRACE_TASKS] =
                $value + 0;
            if ($value) {
                say {$trace_fh} "Setting trace_tasks option to $value"
                    or Marpa::XS::exception("Cannot print: $ERRNO");
                $recce->[Marpa::XS::Internal::Recognizer::TRACING] = 1;
            }
        } ## end if ( defined( my $value = $args->{'trace_tasks'} ) )

        if ( defined( my $value = $args->{'trace_terminals'} ) ) {
            $recce->[Marpa::XS::Internal::Recognizer::TRACE_TERMINALS] =
                $value;
            if ($value) {
                say {$trace_fh} 'Setting trace_terminals option'
                    or Marpa::XS::exception("Cannot print: $ERRNO");
                $recce->[Marpa::XS::Internal::Recognizer::TRACING] = 1;
            }
        } ## end if ( defined( my $value = $args->{'trace_terminals'}...))

        if ( defined( my $value = $args->{'trace_earley_sets'} ) ) {
            $recce->[Marpa::XS::Internal::Recognizer::TRACE_EARLEY_SETS] =
                $value;
            if ($value) {
                say {$trace_fh} 'Setting trace_earley_sets option'
                    or Marpa::XS::exception("Cannot print: $ERRNO");
                $recce->[Marpa::XS::Internal::Recognizer::TRACING] = 1;
            }
        } ## end if ( defined( my $value = $args->{'trace_earley_sets'...}))

        if ( defined( my $value = $args->{'trace_values'} ) ) {
            $recce->[Marpa::XS::Internal::Recognizer::TRACE_VALUES] = $value;
            ## Do not allow setting this option in recognizer for single parse mode
            $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] = 0;
            if ($value) {
                say {$trace_fh} 'Setting trace_values option'
                    or Marpa::XS::exception("Cannot print: $ERRNO");
                $recce->[Marpa::XS::Internal::Recognizer::TRACING] = 1;
            }
        } ## end if ( defined( my $value = $args->{'trace_values'} ) )

        if ( defined( my $value = $args->{'end'} ) ) {

            # Not allowed once parsing is started
            if ( $recce->[Marpa::XS::Internal::Recognizer::PARSE_COUNT] > 0 )
            {
                Marpa::XS::exception(
                    q{Cannot reset end once parsing has started});
            }
            $recce->[Marpa::XS::Internal::Recognizer::END] = $value;
            ## Do not allow setting this option in recognizer for single parse mode
            $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] = 0;
        } ## end if ( defined( my $value = $args->{'end'} ) )

        if ( defined( my $value = $args->{'closures'} ) ) {

            # Not allowed once parsing is started
            if ( $recce->[Marpa::XS::Internal::Recognizer::PARSE_COUNT] > 0 )
            {
                Marpa::XS::exception(
                    q{Cannot reset end once parsing has started});
            }
            my $closures =
                $recce->[Marpa::XS::Internal::Recognizer::CLOSURES] = $value;
            ## Do not allow setting this option in recognizer for single parse mode
            $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] = 0;
            while ( my ( $action, $closure ) = each %{$closures} ) {
                Marpa::XS::exception(qq{Bad closure for action "$action"})
                    if ref $closure ne 'CODE';
            }
        } ## end if ( defined( my $value = $args->{'closures'} ) )

        if ( defined( my $value = $args->{'warnings'} ) ) {
            $recce->[Marpa::XS::Internal::Recognizer::WARNINGS] = $value;
        }

        if ( defined( my $value = $args->{'too_many_earley_items'} ) ) {
            $recce_c->set_too_many_earley_items( $value );
        }

    } ## end for my $args (@arg_hashes)

    return 1;
} ## end sub Marpa::XS::Recognizer::set

# Not intended to be documented.
# Returns the size of the lasy completed earley set.
# For testing, especially that the Leo items
# are doing their job.
sub Marpa::XS::Recognizer::earley_set_size {
    my ( $recce, $name ) = @_;
    my $last_completed_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];
    return if not defined $last_completed_earleme;
    my $earley_set = $recce->[EARLEY_SETS]->[$last_completed_earleme];
    return if not defined $earley_set;
    return scalar @{ $earley_set->[Marpa::XS::Internal::Earley_Set::ITEMS] };
} ## end sub Marpa::XS::Recognizer::earley_set_size

sub Marpa::XS::Recognizer::check_terminal {
    my ( $recce, $name ) = @_;
    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    return $grammar->check_terminal($name);
}

sub Marpa::XS::Recognizer::exhausted {
    return $_[0]->[Marpa::XS::Internal::Recognizer::EXHAUSTED];
}

sub Marpa::XS::Recognizer::current_earleme {
    return $_[0]->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];
}

sub Marpa::XS::Recognizer::terminals_expected {
    return  $_[0]->[Marpa::XS::Internal::Recognizer::EXPECTED_TERMINALS];
}

# Deprecated -- obsolete
sub Marpa::XS::Recognizer::status {
    my ($recce) = @_;
    return ( $recce->current_earleme(), $recce->terminals_expected() )
        if wantarray;
    return $recce->current_earleme();

} ## end sub Marpa::XS::Recognizer::status

# Now useless and deprecated
sub Marpa::XS::Recognizer::strip { return 1; }

# Viewing methods, for debugging

sub Marpa::XS::show_link_choice {
    my ($link) = @_;
    my ( $predecessor, $cause, $token_name, $value_ref ) = @{$link};
    my @pieces = ();
    if ($predecessor) {
        push @pieces,
            'p=' .  Marpa::XS::Internal::Earley_Item::name($predecessor);
    }
    if ( not defined $cause ) {
        push @pieces, "s=$token_name";
        my $token_dump = Data::Dumper->new( [$value_ref] )->Terse(1)->Dump;
        chomp $token_dump;
        push @pieces, "t=$token_dump";
    } ## end if ( not defined $cause )
    else {
        push @pieces,
            'c=' .  Marpa::XS::Internal::Earley_Item::name($link->[1]);
    }
    return '[' . ( join '; ', @pieces ) . ']';
} ## end sub Marpa::XS::show_link_choice

sub Marpa::XS::show_leo_link_choice {
    my ($leo_link) = @_;
    my ( $leo_item, $cause, $symbol_name, $value_ref ) = @{$leo_link};
    my @link_texts = ();
    if ($leo_item) {
        push @link_texts,
            ( 'l=' . $leo_item->name() );
    }
    if ($cause) {
        push @link_texts,
            'c=' .  Marpa::XS::Internal::Earley_Item::name($cause);
    }
    else {
        my $token_dump = Data::Dumper->new( [$value_ref] )->Terse(1)->Dump;
        chomp $token_dump;
        push @link_texts, "s=$symbol_name", "t=$token_dump";
    }
    return '[' . ( join '; ', @link_texts ) . ']';
} ## end sub Marpa::XS::show_leo_link_choice

sub Marpa::XS::Internal::Earley_Item::name {
    my ($item) = @_;
    return sprintf 'S%d@%d-%d',
        $item->[Marpa::XS::Internal::Earley_Item::STATE]
        ->[Marpa::XS::Internal::AHFA::ID],
        $item->[Marpa::XS::Internal::Earley_Item::ORIGIN],
        $item->[Marpa::XS::Internal::Earley_Item::SET];
} ## end sub Marpa::XS::Internal::Earley_Item::name

sub Marpa::XS::show_earley_item {
    my ($item)    = @_;
    my $links     = $item->[Marpa::XS::Internal::Earley_Item::LINKS];
    my $leo_links = $item->[Marpa::XS::Internal::Earley_Item::LEO_LINKS];

    my $text = Marpa::XS::Internal::Earley_Item::name($item);

    if ( defined $links and @{$links} ) {
        for my $link ( @{$links} ) {
            $text .= q{ } . Marpa::XS::show_link_choice($link);
        }
    }
    if ( defined $leo_links and @{$leo_links} ) {
        for my $leo_link ( @{$leo_links} ) {
            $text .= q{ } . Marpa::XS::show_leo_link_choice($leo_link);
        }
    }
    return $text;
} ## end sub Marpa::XS::show_earley_item

sub Marpa::XS::Internal::Leo_Item::name {
    my ($item) = @_;
    my $to_state  = $item->[Marpa::XS::Internal::Leo_Item::BASE_TO_STATE];
    my $parent = $item->[Marpa::XS::Internal::Leo_Item::ORIGIN];
    my $set    = $item->[Marpa::XS::Internal::Leo_Item::SET];
    my $symbol = $item->[Marpa::XS::Internal::Leo_Item::LEO_SYMBOL];
    return sprintf 'L%d:%d@%d-%d',
        $to_state->[Marpa::XS::Internal::AHFA::ID],
        $symbol->[Marpa::XS::Internal::Symbol::ID],
        $parent, $set;
} ## end sub Marpa::XS::Internal::Leo_Item::name

sub Marpa::XS::show_leo_item {
    my ($item)          = @_;
    my $base            = $item->[Marpa::XS::Internal::Leo_Item::BASE];
    my $predecessor     = $item->[Marpa::XS::Internal::Leo_Item::PREDECESSOR];
    my $leo_symbol      = $item->[Marpa::XS::Internal::Leo_Item::LEO_SYMBOL];
    my $leo_symbol_name = $leo_symbol->[Marpa::XS::Internal::Symbol::NAME];

    my $text = $item->name();
    $text .= qq{; "$leo_symbol_name";};

    my @link_texts = ();
    if ($predecessor) {
        push @link_texts, ( 'l=' . $predecessor->name() );
    }
    if ($base) {
        push @link_texts,
            'c=' .  Marpa::XS::Internal::Earley_Item::name($base);
    }
    $text .= ' [' . ( join '; ', @link_texts ) . ']';
    return $text;
} ## end sub Marpa::XS::show_leo_item

sub Marpa::XS::show_earley_set {
    my ($earley_set) = @_;
    my $text = q{};
    my $items = $earley_set->[Marpa::XS::Internal::Earley_Set::ITEMS];
    for my $earley_item ( @{$items} ) {
        $text .= Marpa::XS::show_earley_item($earley_item) . "\n";
    }
    return $text;
} ## end sub Marpa::XS::show_earley_set

sub Marpa::XS::new_show_earley_set {
    my ($recce, $earleme) = @_;
    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $text = q{};
    my @earley_item_keys = $recce_c->earley_items($earleme);
    my %transitions = ();
    while ( my ( $state_id, $origin ) = splice( @earley_item_keys, 0, 2 ) )
	{
	   $text .= sprintf "S%d@%d-%d\n", $state_id, $origin, $earleme;
	}
    return $text;
}

sub Marpa::XS::show_postdot_set {
    my ($postdot_set)       = @_;
    my $text                = q{};
    my @decorated_leo_items = ();
    for my $leo_item (
        grep { ref eq $LEO_CLASS }
        map { @{$_} } values %{$postdot_set}
        )
    {
        my $to_state_id =
            $leo_item->[Marpa::XS::Internal::Leo_Item::BASE_TO_STATE]
            ->[Marpa::XS::Internal::AHFA::ID],
            my $origin = $leo_item->[Marpa::XS::Internal::Leo_Item::ORIGIN];
        my $symbol_id =
            $leo_item->[Marpa::XS::Internal::Leo_Item::LEO_SYMBOL]
            ->[Marpa::XS::Internal::Symbol::ID];
        push @decorated_leo_items,
            [ $leo_item, $to_state_id, $symbol_id, $origin ];
    } ## end for my $leo_item ( grep { ref eq $LEO_CLASS } map { @...})
    my @sorted_leo_items = map { $_->[0] } sort {
               $a->[1] <=> $b->[1]
            || $a->[2] <=> $b->[2]
            || $a->[3] <=> $b->[3];
    } @decorated_leo_items;
    for my $postdot_item (@sorted_leo_items) {
        $text .= Marpa::XS::show_leo_item($postdot_item) . "\n";
    }
    return $text;
} ## end sub Marpa::XS::show_postdot_set

sub Marpa::XS::show_earley_set_list {
    my ( $earley_set_list ) = @_;
    my $text             = q{};
    my $earley_set_count = @{$earley_set_list};
    LIST: for my $ix ( 0 .. $earley_set_count - 1 ) {
        my $set = $earley_set_list->[$ix];
        next LIST if not defined $set;
        $text .= "Earley Set $ix\n" . Marpa::XS::show_earley_set($set);
        my $postdot_set =
            $earley_set_list->[$ix]
            ->[Marpa::XS::Internal::Earley_Set::POSTDOT];
        next LIST if not defined $postdot_set;
        $text .= Marpa::XS::show_postdot_set($postdot_set);
    } ## end for my $ix ( 0 .. $earley_set_count - 1 )
    return $text;
} ## end sub Marpa::XS::show_earley_set_list

sub Marpa::XS::Recognizer::show_earley_sets {
    my ($recce) = @_;
    my $last_completed_earleme = $recce->[LAST_COMPLETED_EARLEME]
        // 'stripped';
    my $furthest_earleme = $recce->[FURTHEST_EARLEME];
    my $earley_set_list  = $recce->[EARLEY_SETS];
    return
          "Last Completed: $last_completed_earleme; "
        . "Furthest: $furthest_earleme\n"
        . Marpa::XS::show_earley_set_list( $earley_set_list );

} ## end sub Marpa::XS::Recognizer::show_earley_sets

sub Marpa::XS::new_show_earley_set_list {
    my ( $recce, $earley_set_list ) = @_;
    my $text             = q{};
    my $earley_set_count = @{$earley_set_list};
    LIST: for my $ix ( 0 .. $earley_set_count - 1 ) {
        # my $set = $earley_set_list->[$ix];
        # next LIST if not defined $set;
        $text .= "Earley Set $ix\n"
            . Marpa::XS::new_show_earley_set( $recce, $ix );

        # my $postdot_set =
        # $earley_set_list->[$ix]
        # ->[Marpa::XS::Internal::Earley_Set::POSTDOT];
        # next LIST if not defined $postdot_set;
        # $text .= Marpa::XS::show_postdot_set($postdot_set);
    } ## end for my $ix ( 0 .. $earley_set_count - 1 )
    return $text;
} ## end sub Marpa::XS::new_show_earley_set_list

sub Marpa::XS::Recognizer::new_show_earley_sets {
    my ($recce) = @_;
    my $last_completed_earleme = $recce->[LAST_COMPLETED_EARLEME]
        // 'stripped';
    my $furthest_earleme = $recce->[FURTHEST_EARLEME];
    my $earley_set_list  = $recce->[EARLEY_SETS];
    return
          "Last Completed: $last_completed_earleme; "
        . "Furthest: $furthest_earleme\n"
        . Marpa::XS::new_show_earley_set_list($recce, $earley_set_list);

} ## end sub Marpa::XS::Recognizer::new_show_earley_sets

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Progress_Report

    RULE_ID
    POSITION
    ORIGIN
    CURRENT
    IS_LEO

);

sub Marpa::XS::Recognizer::show_progress {
    my ( $recce, $start_ix, $end_ix ) = @_;
    my $earley_set_list =
        $recce->[Marpa::XS::Internal::Recognizer::EARLEY_SETS];
    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $grammar_c   = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $rules   = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $last_ix = $#{$earley_set_list};
    $start_ix //=
        $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];
    if ( $start_ix < 0 or $start_ix > $last_ix ) {
        return
            "Marpa::XS::Recognizer::show_progress start index is $start_ix, must be in range 0-$last_ix";
    }
    $end_ix //= $start_ix;
    if ( $end_ix < 0 ) {
        $end_ix += $last_ix + 1;
    }
    if ( $end_ix < 0 or $end_ix > $last_ix ) {
        return
            "Marpa::XS::Recognizer::show_progress end index is $end_ix, must be in range 0-$last_ix";
    }
    my $text = q{};
    for my $ix ( $start_ix .. $end_ix ) {
        my $items = $earley_set_list->[$ix]->[Marpa::XS::Internal::Earley_Set::ITEMS];
        my $reports    = report_progress($recce, $items);
        my @sort_data;
        for my $report ( @{$reports} ) {
            my $rule_id =
                $report->[Marpa::XS::Internal::Progress_Report::RULE_ID];
            my $rule = $rules->[$rule_id];
            my $position =
                $report->[Marpa::XS::Internal::Progress_Report::POSITION];
            my $origin =
                $report->[Marpa::XS::Internal::Progress_Report::ORIGIN];
            my $current =
                $report->[Marpa::XS::Internal::Progress_Report::CURRENT];
            my $is_leo =
                $report->[Marpa::XS::Internal::Progress_Report::IS_LEO];
            my $rhs_length = $grammar_c->rule_length( $rule_id );
            my $item_text;
            my $type;

            # flag indicating whether we need to show the dot in the rule
            my $show_dotted;
            if ( $position >= $rhs_length ) {
                $item_text .= 'COMPLETED';
                $type = 3;
                $item_text .= q{ @} . $origin . q{-} . $current . q{ };
                $is_leo and $item_text .= '(Leo) ';
            } ## end if ( $position >= $rhs_length )
            elsif ($position) {
                $item_text .= 'BUILDING';
                $type = 2;
                $item_text .= q{ @} . $origin . q{-} . $current . q{ };
                $show_dotted++;
            } ## end elsif ($position)
            else {
                $item_text .= 'PREDICTING';
                $type = 1;
                $item_text .= q{ @} . $origin . q{ };
            }
            if ($show_dotted) {
                $item_text .= $grammar->show_dotted_rule( $rule, $position );
            }
            else {
                $item_text .= $grammar->brief_rule($rule);
            }
            push @sort_data,
                [
                ( pack 'N*', $type, $rule_id, $position, $origin ), $item_text
                ];
        } ## end for my $report ( @{$reports} )
        $text .= (
            join "\n", map { $_->[1] } sort { $a->[0] cmp $b->[0] } @sort_data
        ) . "\n";
    } ## end for my $ix ( $start_ix .. $end_ix )
    return $text;
} ## end sub Marpa::XS::Recognizer::show_progress

sub report_progress {
    my ($recce, $earley_items) = @_;
    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];

    # Reports must be unique by a key
    # composted of original rule, rule position, and
    # location in the parse.  This hash is to
    # quarantee that.
    my %progress_report_hash = ();

    for my $earley_item ( @{$earley_items} ) {
        my $AHFA_state =
            $earley_item->[Marpa::XS::Internal::Earley_Item::STATE];
        my $origin = $earley_item->[Marpa::XS::Internal::Earley_Item::ORIGIN];
        my $current = $earley_item->[Marpa::XS::Internal::Earley_Item::SET];
        my $leo_links =
            $earley_item->[Marpa::XS::Internal::Earley_Item::LEO_LINKS];
        my $is_leo = $leo_links && scalar @{$leo_links};
        my @AHFA_items =
            $grammar_c->AHFA_state_items(
            $AHFA_state->[Marpa::XS::Internal::AHFA::ID] );
        AHFA_ITEM: for my $AHFA_item_id (@AHFA_items) {
            my $marpa_rule_id = $grammar_c->AHFA_item_rule($AHFA_item_id);
            my $marpa_rule    = $rules->[$marpa_rule_id];
            my $marpa_position =
                $grammar_c->AHFA_item_position($AHFA_item_id);
            $marpa_position < 0
                and $marpa_position = $grammar_c->rule_length($marpa_rule_id);
            my $chaf_start = $grammar_c->rule_virtual_start($marpa_rule_id);
            $chaf_start < 0 and $chaf_start = undef;
            my $original_rule_id =
                defined $chaf_start
                ? ( $grammar_c->rule_original($marpa_rule_id)
                    // $marpa_rule_id )
                : $marpa_rule_id;

            # position in original rule, to be calculated
            my $original_position;
            if ( defined $chaf_start ) {
                $original_position =
                    $marpa_position >= $grammar_c->rule_length($marpa_rule_id)
                    ? $grammar_c->rule_length($original_rule_id)
                    : ( $chaf_start + $marpa_position );
            } ## end if ( defined $chaf_start )
            $original_position //= $marpa_position;
            my $rule_id         = $original_rule_id;
            my @data            = ( $rule_id, $original_position, $origin );
            my $key             = join q{;}, @data;
            my $progress_report = $progress_report_hash{$key};

            # If an entry already exists, just update the Leo flag
            if ( defined $progress_report ) {
                if ($is_leo) {
                    $progress_report
                        ->[Marpa::XS::Internal::Progress_Report::IS_LEO] = 1;
                }
                next NFA_STATE;
            } ## end if ( defined $progress_report )
            $progress_report_hash{$key} = [ @data, $current, $is_leo ];
        } ## end for my $AHFA_item_id (@AHFA_items)
    } ## end for my $earley_item ( @{$earley_items} )
    return [ values %progress_report_hash ];
} ## end sub report_progress

sub Marpa::XS::Recognizer::read {
    # For efficiency, not unpacked
    # my ( $recce, $symbol_name, $value ) = @_;
    my $recce = shift;
    return defined $recce->alternative(@_) ? $recce->earleme_complete() : undef;
}

sub Marpa::XS::Recognizer::alternative {

    my ( $recce, $symbol_name, $value, $length ) = @_;
    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $slots = $recce->[Marpa::XS::Internal::Recognizer::SLOTS];
    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $symbol_id = $symbol_hash->{$symbol_name};
    my $slot = $slots->slot($value);
    $length //= 1;

    my $current_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];
    my $result = $recce_c->alternative($symbol_id, $slot, $length);
    if ( not defined $result ) {
        my $error = $recce_c->error();
        if ( $error eq "duplicate token" ) {
            Marpa::XS::exception(
                qq{"$symbol_name" already scanned with length $length at location $current_earleme}
            );
        }
        Marpa::XS::exception( "Uncaught error from alternative(): ",
            $recce_c->error() );
    } ## end if ( not defined $result )

    # Eventually will return -1 as undef, other results directly

    Marpa::XS::exception(
        'No recognizer object for Marpa::XS::Recognizer::tokens')
        if not defined $recce
            or ref $recce ne 'Marpa::XS::Recognizer';

    local $Marpa::XS::Internal::TRACE_FH = my $trace_fh =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE];
    my $trace_terminals =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_TERMINALS];
    my $warnings = $recce->[Marpa::XS::Internal::Recognizer::WARNINGS];

    Marpa::XS::exception('Attempt to read token after parsing is finished')
        if $recce->[Marpa::XS::Internal::Recognizer::FINISHED];

    Marpa::XS::exception('Attempt to read token when parsing is exhausted')
        if $recce->[Marpa::XS::Internal::Recognizer::EXHAUSTED];

    my $terminal_names =
        $grammar->[Marpa::XS::Internal::Grammar::TERMINAL_NAMES];

    my $earley_set_list =
        $recce->[Marpa::XS::Internal::Recognizer::EARLEY_SETS];
    my $AHFA = $grammar->[Marpa::XS::Internal::Grammar::AHFA];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];

    my $postdot_here =
        $earley_set_list->[$current_earleme]
        ->[Marpa::XS::Internal::Earley_Set::POSTDOT];

    if ( not defined $symbol_name or not $terminal_names->{$symbol_name} ) {
        my $problem =
            defined $symbol_name
            ? qq{Token name "$symbol_name" is not the name of a terminal symbol}
            : q{Undef given, instead of the name of a terminal symbol};
        Marpa::XS::exception($problem);
    } ## end if ( not defined $symbol_name or not $terminal_names...)

    # Make sure it's an allowed terminal symbol.
    my $postdot_data = $postdot_here->{$symbol_name};
    if ( not $postdot_data ) {
        if ( not $recce->[Marpa::XS::Internal::Recognizer::INTERACTIVE] ) {
            Marpa::XS::exception(
                qq{Rejected "$symbol_name" at token $current_earleme});
        }
        if ($trace_terminals) {
            say {$trace_fh} qq{Rejected "$symbol_name" at $current_earleme}
                or Marpa::XS::exception("Cannot print: $ERRNO");
        }
        return;
    } ## end if ( not $postdot_data )

    my $value_ref = \($value);

    if ( $length & Marpa::XS::Internal::Recognizer::EARLEME_MASK ) {
        Marpa::XS::exception(
            'Token ' . $symbol_name . " is too long\n",
            "  Token starts at $current_earleme, and its length is $length\n"
        );
    } ## end if ( $length & ...)

    if ( $length <= 0 ) {
        Marpa::XS::exception(
            'Token ' . $symbol_name . ' has non-positive length ' . $length );
    } ## end if ( $length <= 0 )

    my $end_earleme = $current_earleme + $length;

    Marpa::XS::exception(
        'Token ' . $symbol_name . " makes parse too long\n",
        "  Token starts at $current_earleme, and its length is $length\n"
    ) if $end_earleme & Marpa::XS::Internal::Recognizer::EARLEME_MASK;

    my $accepted = 0;    # for trace_terminals
    my $target_ix = $current_earleme + $length;
    my $target_earley_set = $earley_set_list->[$target_ix] //= [];
    my $target_earley_items = $target_earley_set->[Marpa::XS::Internal::Earley_Set::ITEMS] //= [];
    my $target_hash = $target_earley_set->[Marpa::XS::Internal::Earley_Set::HASH] //= {};

    EARLEY_ITEM: for my $postdot_item ( @{$postdot_data} ) {

	my $origin;
	my @to_states;
	my $postdot_item_is_leo = ref $postdot_item eq $LEO_CLASS;
	if ($postdot_item_is_leo) {
	    @to_states =
		$postdot_item->[Marpa::XS::Internal::Leo_Item::TOP_TO_STATE];
	    $origin = $postdot_item->[Marpa::XS::Internal::Leo_Item::ORIGIN];
	}
	else {
	    my $state = $postdot_item->[Marpa::XS::Internal::Earley_Item::STATE];
	    @to_states =
		grep {ref}
		@{ $state->[Marpa::XS::Internal::AHFA::TRANSITION]
		    ->{$symbol_name} };
	    next EARLEY_ITEM if not scalar @to_states;
	    $origin = $postdot_item->[Marpa::XS::Internal::Earley_Item::ORIGIN];
	} ## end else [ if ($postdot_item_is_leo) ]

        $accepted++;

        TO_STATE: for my $to_state ( @to_states ) {
            my $reset = $to_state->[Marpa::XS::Internal::AHFA::RESET_ORIGIN];
            my $new_origin = $reset ? $target_ix : $origin;
            my $to_state_id = $to_state->[Marpa::XS::Internal::AHFA::ID];
	    my $hash_key = join ':', $to_state_id, $new_origin;
            my $target_item = $target_hash->{$hash_key};
            if ( defined $target_item ) {
                next TO_STATE if $reset;
                if (not $postdot_item_is_leo
                    and
                    $postdot_item->[Marpa::XS::Internal::Earley_Item::ID] ~~
                    [   map {
                            $_->[0]->[Marpa::XS::Internal::Earley_Item::ID]
                            } @{
                            $target_item
                                ->[Marpa::XS::Internal::Earley_Item::LINKS]
                            }
                    ]
                    )
                {
                    Marpa::XS::exception(
                        qq{"$symbol_name" already scanned with length $length at location $current_earleme}
                    );
                } ## end if ( not $postdot_item_is_leo and $postdot_item->[...])
            } ## end if ( defined $target_item )
            else {

                $target_item = [];
		$target_item->[Marpa::XS::Internal::Earley_Item::ID] =
		    $recce->[Marpa::XS::Internal::Recognizer::NEXT_EARLEY_ITEM_ID]++;
                $target_item->[Marpa::XS::Internal::Earley_Item::STATE] =
                    $to_state;
                $target_item->[Marpa::XS::Internal::Earley_Item::ORIGIN] =
                    $new_origin;
                $target_item->[Marpa::XS::Internal::Earley_Item::LEO_LINKS] =
                    [];
                $target_item->[Marpa::XS::Internal::Earley_Item::LINKS] = [];
                $target_item->[Marpa::XS::Internal::Earley_Item::SET] =
                    $target_ix;
                $target_hash->{$hash_key} = $target_item;
                push @{$target_earley_items}, $target_item;

            }

            next TO_STATE if $reset;

            if ($postdot_item_is_leo) {
                push @{ $target_item
                        ->[Marpa::XS::Internal::Earley_Item::LEO_LINKS] },
                    [ $postdot_item, undef, $symbol_name, $value_ref ];
            } ## end if ($leo_item)
            else {
                push
                    @{ $target_item->[Marpa::XS::Internal::Earley_Item::LINKS]
                    },
                    [ $postdot_item, undef, $symbol_name, $value_ref ];
            }
        }    # for my $to_state

    }

    if ( $accepted and $target_ix
	> $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME] )
    {
	$recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME] =
	    $target_ix;
    }


    if ($trace_terminals) {
        my $verb = $accepted ? 'Accepted' : 'Rejected';
        say {$trace_fh} qq{$verb "$symbol_name" at $current_earleme-}
            . ( $length + $current_earleme )
            or Marpa::XS::exception("Cannot print: $ERRNO");
    }

    return $current_earleme;

}

# Deprecated -- obsolete
sub Marpa::XS::Recognizer::tokens {

    my ( $recce, $tokens, $token_ix_ref ) = @_;

    Marpa::XS::exception(
        'No recognizer object for Marpa::XS::Recognizer::tokens')
        if not defined $recce
            or ref $recce ne 'Marpa::XS::Recognizer';

    Marpa::XS::exception('No tokens arg for Marpa::XS::Recognizer::tokens')
        if not defined $tokens;

    my $mode = $recce->[Marpa::XS::Internal::Recognizer::MODE];
    my $interactive;

    if ( defined $token_ix_ref ) {
        my $ref_type = ref $token_ix_ref;
        if ( ref $token_ix_ref ne 'SCALAR' ) {
            my $description = $ref_type ? "ref to $ref_type" : 'not a ref';
            Marpa::XS::exception(
                "Token index arg for Marpa::XS::Recognizer::tokens is $description, must be ref to SCALAR"
            );
        } ## end if ( ref $token_ix_ref ne 'SCALAR' )
        Marpa::XS::exception(
            q{'Tokens index ref for Marpa::XS::Recognizer::tokens allowed only in 'stream' mode}
        ) if $mode ne 'stream';
        $interactive = 1;
    } ## end if ( defined $token_ix_ref )

    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    local $Marpa::XS::Internal::TRACE_FH = my $trace_fh =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE];
    my $trace_terminals =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_TERMINALS];

    Marpa::XS::exception('Attempt to scan tokens after parsing is finished')
        if $recce->[Marpa::XS::Internal::Recognizer::FINISHED]
            and scalar @{$tokens};

    Marpa::XS::exception('Attempt to scan tokens when parsing is exhausted')
        if $recce->[Marpa::XS::Internal::Recognizer::EXHAUSTED]
            and scalar @{$tokens};

    my $symbol_hash =
        $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];

    my $next_token_earleme = my $last_completed_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];

    $token_ix_ref //= \( my $token_ix = 0 );

    my $token_args = $tokens->[ ${$token_ix_ref} ];

    # If the token list is empty, we will go straight to the
    # next token
    if ( not scalar @{$tokens} ) { $next_token_earleme++ }

    EARLEME: while ( ${$token_ix_ref} < scalar @{$tokens} ) {

        my $current_token_earleme = $last_completed_earleme;
	# At this point, typically, $current_token_earleme,
	# $next_token_earleme and $last_completed_earleme are
	# all equal.

        # It's not 100% clear whether it's best to leave
        # the token_ix_ref pointing at the start of the
        # earleme, or at the actual problem token.
        # Right now, we set it at the actual problem
        # token, which is probably what will turn out
        # to be easiest.
        # my $first_ix_of_this_earleme = ${$token_ix_ref};

	# For as long the $next_token_earleme does not advance ...
        TOKEN: while ( $current_token_earleme == $next_token_earleme ) {

	    # ... or until we run out of tokens
            last TOKEN if not my $token_args = $tokens->[ ${$token_ix_ref} ];
            Marpa::XS::exception(
                'Tokens must be array refs: token #',
                ${$token_ix_ref}, " is $token_args\n",
            ) if ref $token_args ne 'ARRAY';
            ${$token_ix_ref}++;
            my ( $symbol_name, $value, $length, $offset ) = @{$token_args};

            Marpa::XS::exception(
                "Attempt to add token '$symbol_name' at location where processing is complete:\n",
                "  Add attempted at $current_token_earleme\n",
                "  Processing complete to $last_completed_earleme\n"
            ) if $current_token_earleme < $last_completed_earleme;

	    my $symbol_id = $symbol_hash->{$symbol_name};
	    if ( not defined $symbol_id ) {
		say {$trace_fh}
		    qq{Attempted to add non-existent symbol named "$symbol_name" at $last_completed_earleme\n}
		    or Marpa::XS::exception("Cannot print: $ERRNO");
	    }

	    # Kludge alert!  Interactive mode in this deprecated interface and in the new one
	    # are incompatible.  I temporarily reset the recce's interactive status
	    # to be what tokens() needs.  Ugly, but this code is destined to be thrown
	    # away.
	    my $save_interactive_flag = $recce->[Marpa::XS::Internal::Recognizer::INTERACTIVE];
	    $recce->[Marpa::XS::Internal::Recognizer::INTERACTIVE] = $interactive;
            my $result = $recce->alternative($symbol_name, $value, $length);
	    $recce->[Marpa::XS::Internal::Recognizer::INTERACTIVE] = $save_interactive_flag;

            if ( not defined $result ) {
                if ( not $interactive ) {
                    Marpa::XS::exception(
                        qq{Terminal "$symbol_name" received when not expected}
                    );
                }

                # Current token didn't actually work, so back out
                # the increment
                ${$token_ix_ref}--;

                return $recce->status();
            } ## end if ( not $postdot_data )

            $offset //= 1;
            Marpa::XS::exception(
                'Token ' . $symbol_name . " has negative offset\n",
                "  Token starts at $last_completed_earleme, and its length is $length\n",
                "  Tokens are required to be in sequence by location\n",
            ) if $offset < 0;
            $next_token_earleme += $offset;

        } ## end while ( $current_token_earleme == $next_token_earleme )

	# We've ended the loop for the tokens at $current_token_earleme.
	# It is possible that $next_token_earleme did not advance,
	# and the loop ended when we ran out of tokens in the
	# argument list.
        # We arrange it so that the last descriptor in
        # a tokens call always advances the current earleme by at least one --
	# as if it had incremented $next_token_earleme
        $current_token_earleme++;
        $current_token_earleme = $next_token_earleme
            if $next_token_earleme > $current_token_earleme;

        $recce->earleme_complete();
        $last_completed_earleme++;

    } ## end while ( ${$token_ix_ref} < scalar @{$tokens} )

    if ( $mode eq 'stream' ) {
        while ( $last_completed_earleme < $next_token_earleme ) {
            $recce->earleme_complete();
            $last_completed_earleme++;
        }
    } ## end if ( $mode eq 'stream' )

    if ( $mode eq 'default' ) {
        while ( $last_completed_earleme
            < $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME] )
        {
            $recce->earleme_complete();
            $last_completed_earleme++;
        }
        $recce->[Marpa::XS::Internal::Recognizer::FINISHED] = 1;
    } ## end if ( $mode eq 'default' )

    return $recce->status();

} ## end sub Marpa::XS::Recognizer::tokens


# Perform the completion step on an earley set

sub Marpa::XS::Recognizer::end_input {
    my ($recce) = @_;
    my $last_completed_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];
    my $furthest_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME];
    while ( $last_completed_earleme < $furthest_earleme ) {
	$recce->earleme_complete();
        $last_completed_earleme++;
    }
    $recce->[Marpa::XS::Internal::Recognizer::FINISHED] = 1;
    return 1;
} ## end sub Marpa::XS::Recognizer::end_input

sub Marpa::XS::Recognizer::earleme_complete {
    my ($recce) = @_;

    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];
    local $Marpa::XS::Internal::TRACE_FH =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE];
    my $grammar     = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $AHFA        = $grammar->[Marpa::XS::Internal::Grammar::AHFA];
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    my $symbols     = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $earley_set_list =
        $recce->[Marpa::XS::Internal::Recognizer::EARLEY_SETS];

    my $result = $recce_c->earleme_complete();
    if (not defined $result) {
        my $error = $recce_c->error();
        if ( $error eq "parse exhausted" ) {
            Marpa::XS::exception(
                qq{parse exhausted}
            );
        }
        Marpa::XS::exception( "Uncaught error from alternative(): ",
            $recce_c->error() );
    }

    my $terminal_names =
        $grammar->[Marpa::XS::Internal::Grammar::TERMINAL_NAMES];
    my $too_many_earley_items = $recce_c->too_many_earley_items();
    my $trace_earley_sets =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_EARLEY_SETS];
    my $trace_terminals =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_TERMINALS] // 0;

    my $earleme_to_complete =
        ++$recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];

    my $earley_set = $earley_set_list->[$earleme_to_complete] //= [];
    my $earley_items =
        $earley_set->[Marpa::XS::Internal::Earley_Set::ITEMS] //= [];
    my $earley_hash = $earley_set->[Marpa::XS::Internal::Earley_Set::HASH] //=
        {};
    my $postdot_here =
        $earley_set->[Marpa::XS::Internal::Earley_Set::POSTDOT] //= {};

    # Important: more earley sets can be added in the loop
    my $earley_set_ix = -1;
    EARLEY_ITEM: while (1) {

        my $earley_item = $earley_items->[ ++$earley_set_ix ];
        last EARLEY_ITEM if not defined $earley_item;

        my ( $state, $parent ) = @{$earley_item}[
            Marpa::XS::Internal::Earley_Item::STATE,
            Marpa::XS::Internal::Earley_Item::ORIGIN
        ];
        my $state_id = $state->[Marpa::XS::Internal::AHFA::ID];

        next EARLEY_ITEM if $earleme_to_complete == $parent;

	LHS_SYMBOL: for my $lhs_symbol ( @{ $state->[Marpa::XS::Internal::AHFA::COMPLETE_LHS] } ) {
	my $postdot_data =
	    $earley_set_list->[$parent]
	    ->[Marpa::XS::Internal::Earley_Set::POSTDOT]->{$lhs_symbol};
	next LHS_SYMBOL if not defined $postdot_data;
        PARENT_ITEM:
        for my $postdot_item ( @{$postdot_data} )
        {
            my $parent_origin;
            my @transition_states;

	    my $postdot_item_is_leo = ref $postdot_item eq $LEO_CLASS;
	    if ($postdot_item_is_leo) {
		$parent_origin =
		    $postdot_item->[Marpa::XS::Internal::Leo_Item::ORIGIN];
		@transition_states =
		    $postdot_item->[Marpa::XS::Internal::Leo_Item::TOP_TO_STATE];
	    } ## end if ($postdot_item_is_leo)
	    else {
		my $parent_state =
		    $postdot_item->[Marpa::XS::Internal::Earley_Item::STATE];
		@transition_states =
		    grep {ref}
		    @{ $parent_state->[Marpa::XS::Internal::AHFA::TRANSITION]
			->{$lhs_symbol} };
		$parent_origin =
		    $postdot_item->[Marpa::XS::Internal::Earley_Item::ORIGIN];
	    } ## end else [ if ($postdot_item_is_leo) ]

            TRANSITION_STATE:
            for my $transition_state ( @transition_states ) {
                my $reset = $transition_state
                    ->[Marpa::XS::Internal::AHFA::RESET_ORIGIN];
                my $origin =
                      $reset
                    ? $earleme_to_complete
                    : $parent_origin;
                my $transition_state_id =
                    $transition_state->[Marpa::XS::Internal::AHFA::ID];
                my $name = sprintf
                    'S%d@%d-%d',
                    $transition_state_id, $origin, $earleme_to_complete;
		my $hash_key = join ':', $transition_state_id, $origin;
                my $target_item = $earley_hash->{$hash_key};
                if ( not defined $target_item ) {
                    $target_item = [];
		    $target_item->[Marpa::XS::Internal::Earley_Item::ID] =
			$recce->[Marpa::XS::Internal::Recognizer::NEXT_EARLEY_ITEM_ID]++;
                    $target_item->[Marpa::XS::Internal::Earley_Item::STATE] =
                        $transition_state;
                    $target_item->[Marpa::XS::Internal::Earley_Item::ORIGIN] =
                        $origin;
                    $target_item
                        ->[Marpa::XS::Internal::Earley_Item::LEO_LINKS] = [];
                    $target_item->[Marpa::XS::Internal::Earley_Item::LINKS] =
                        [];
                    $target_item->[Marpa::XS::Internal::Earley_Item::SET] =
                        $earleme_to_complete;
                    $earley_hash->{$hash_key} = $target_item;
                    push @{$earley_items}, $target_item;
                }    # unless defined $target_item
                next TRANSITION_STATE if $reset;
                if ($postdot_item_is_leo) {
                    push @{ $target_item
                            ->[Marpa::XS::Internal::Earley_Item::LEO_LINKS] },
                        [ $postdot_item, $earley_item ];
                }
                else {
                    push @{ $target_item
                            ->[Marpa::XS::Internal::Earley_Item::LINKS] },
                        [ $postdot_item, $earley_item ];
                }
            }    # TRANSITION_STATE

        }    # PARENT_ITEM
	}

    }    # EARLEY_ITEM

    if ( $too_many_earley_items >= 0
        and ( my $item_count = scalar @{$earley_items} )
        >= $too_many_earley_items )
    {
        if ( $recce->[Marpa::XS::Internal::Recognizer::WARNINGS] ) {
            say {$Marpa::XS::Internal::TRACE_FH}
                "Very large earley set: $item_count items at location $earleme_to_complete"
                or Marpa::XS::exception("Cannot print: $ERRNO");
        }
    } ## end if ( $too_many_earley_items >= 0 and ( my $item_count...))

    # Each possible cause
    # link is only visited once.
    # It may be paired with several different predecessors.
    # The cause may complete several different LHS symbols
    # and Marpa::XS will seek predecessors for each at
    # the parent location.
    # Different completed LHS symbols might be postdot
    # symbols for the same predecessor Earley item.
    # For this reason,
    # predecessor-cause pairs might not be unique
    # within an Earley item.
    #
    # This is not an issue for unambiguous parsing.
    # It *IS* an issue for iterating ambiguous parses.

    if ($trace_earley_sets) {
        print {$Marpa::XS::Internal::TRACE_FH}
            "=== Earley set $earleme_to_complete\n"
            or Marpa::XS::exception("Cannot print: $ERRNO");
        print {$Marpa::XS::Internal::TRACE_FH}
            Marpa::XS::show_earley_set($earley_set)
            or Marpa::XS::exception("Cannot print: $ERRNO");
    } ## end if ($trace_earley_sets)

    for my $earley_item ( @{$earley_items} ) {
        my $state  = $earley_item->[Marpa::XS::Internal::Earley_Item::STATE];
        my $parent = $earley_item->[Marpa::XS::Internal::Earley_Item::ORIGIN];
        for my $postdot_symbol_name (
            keys %{ $state->[Marpa::XS::Internal::AHFA::TRANSITION] } )
        {
            push @{ $postdot_here->{$postdot_symbol_name} }, $earley_item;
        }
    } ## end for my $earley_item ( @{$earley_items} )

    my @leo_worklist = ();
    if ( $recce->[Marpa::XS::Internal::Recognizer::USE_LEO] ) {
        SYMBOL: for my $postdot_symbol_name ( keys %{$postdot_here} ) {
            my $postdot_data = $postdot_here->{$postdot_symbol_name};
            next SYMBOL if scalar @{$postdot_data} != 1;
            my $earley_item = $postdot_data->[0];
            my $leo_lhs =
                $earley_item->[Marpa::XS::Internal::Earley_Item::STATE]
                ->[Marpa::XS::Internal::AHFA::TRANSITION]
                ->{$postdot_symbol_name}->[0];

            # Only one transition in the Earley set on this symbol,
            # but it is not to a Leo completion.
            next SYMBOL if ref $leo_lhs;
            push @leo_worklist, $postdot_symbol_name;
        } ## end for my $postdot_symbol_name ( keys %{$postdot_here} )
    } ## end if ( $recce->[Marpa::XS::Internal::Recognizer::USE_LEO...])
    my $no_of_work_entries = scalar @leo_worklist;
    my $final_pass = 0;
    # Pretend there was an pre-pass
    PASS: for (;;) {
        my $to_ix = 0;
    SYMBOL:
    for (my $ix = 0; $ix < $no_of_work_entries; $ix++) {
        my $postdot_symbol_name = $leo_worklist[$ix];
        my $postdot_data = $postdot_here->{$postdot_symbol_name};
        my $base_earley_item = $postdot_data->[0];

	my $leo_origin =
	    $base_earley_item->[Marpa::XS::Internal::Earley_Item::ORIGIN];
	my ( $leo_lhs, $top_to_state ) =
	    @{ $base_earley_item->[Marpa::XS::Internal::Earley_Item::STATE]
		->[Marpa::XS::Internal::AHFA::TRANSITION]
		->{$postdot_symbol_name} };
	my $base_to_state = $top_to_state;

        # A flag that indicates if we working on a prediction
        # Leo item.  Set here because $leo_origin is changed
        # below.
        my $prediction = $leo_origin == $earleme_to_complete;


	my $predecessor_postdot =
	    $earley_set_list->[$leo_origin]
	    ->[Marpa::XS::Internal::Earley_Set::POSTDOT]->{$leo_lhs};
	my $postdot_item = $predecessor_postdot->[0];
        my $predecessor_leo_item = ref $postdot_item eq $LEO_CLASS ? $postdot_item : undef;

	if ( not $predecessor_leo_item and not $final_pass and $prediction ) {
            # We didn't find a predecessor Leo item.
            # That's ok in the final phase,
            # or if we are not working on a Leo prediction item.
	    $leo_worklist[ $to_ix++ ] = $postdot_symbol_name;
	    next SYMBOL;
	}

	if ( $predecessor_leo_item ) {
	    $leo_origin = $predecessor_leo_item->[Marpa::XS::Internal::Leo_Item::ORIGIN];
	    $top_to_state = $predecessor_leo_item->[Marpa::XS::Internal::Leo_Item::TOP_TO_STATE];
	} ## end if ($predecessor_leo_item)

        my $leo_item = bless [], $LEO_CLASS;
        $leo_item->[Marpa::XS::Internal::Leo_Item::BASE_TO_STATE] = $base_to_state;
        $leo_item->[Marpa::XS::Internal::Leo_Item::ORIGIN] = $leo_origin;
        $leo_item->[Marpa::XS::Internal::Leo_Item::SET] =
            $earleme_to_complete;
        $leo_item->[Marpa::XS::Internal::Leo_Item::LEO_SYMBOL] =
            $symbols->[$symbol_hash->{$postdot_symbol_name}];
        $leo_item->[Marpa::XS::Internal::Leo_Item::BASE] = $base_earley_item;
        $leo_item->[Marpa::XS::Internal::Leo_Item::PREDECESSOR] =
            $predecessor_leo_item;
        $leo_item->[Marpa::XS::Internal::Leo_Item::TOP_TO_STATE] = $top_to_state;

        $postdot_here->{$postdot_symbol_name} = [ $leo_item ];

    } ## end for ( ;; )
    last PASS if $final_pass;
    # Final pass if nothing accomplished
    $final_pass = $no_of_work_entries == $to_ix;
    $no_of_work_entries = $to_ix;
    }

    my @terminals_expected =
        grep { $terminal_names->{$_} } keys %{$postdot_here};
    $recce->[Marpa::XS::Internal::Recognizer::EXPECTED_TERMINALS] =
        \@terminals_expected;

    $recce->[Marpa::XS::Internal::Recognizer::EXHAUSTED] =
        ( scalar @terminals_expected <= 0 )
        && $earleme_to_complete
        >= $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME];

    if ( $trace_terminals > 1 ) {
        for my $terminal (@terminals_expected) {
            say {$Marpa::XS::Internal::TRACE_FH}
                qq{Expecting "$terminal" at $earleme_to_complete}
                or Marpa::XS::exception("Cannot print: $ERRNO");
        }
    } ## end if ( $trace_terminals > 1 )

    return \@terminals_expected;

} ## end sub Marpa::XS::Recognizer::earleme_complete

1;
