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

# Elements of the EARLEY ITEM structure
# Note that these are Earley items as modified by Aycock & Horspool,
# with AHFA states instead of
# LR(0) items.

# We don't prune the Earley items because we want PARENT and SET
# around for debugging.

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Earley_Item

    C { A C structure }

    NAME { Unique string describing Earley item. }
    STATE { The AHFA state. }
    LINKS { A list of the links from the completer step. }

    LEO_LINKS { Leo Links source }

    =LAST_EVALUATOR_FIELD

    PARENT { The number of the Earley set with the parent item(s) }
    =ORIGIN { A synonym I prefer to PARENT. }
    SET { The set this item is in. For debugging. }

    =LAST_FIELD

);

use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Leo_Item

    NAME { Unique string describing Leo item. }
    STATE { The AHFA state. }
    LINKS { A list of the links from the completer step. }

    LEO_SYMBOL { A symbol name. }
    LEO_ACTUAL_STATE { An AHFA state. }

    =LAST_EVALUATOR_FIELD

    PARENT { The number of the Earley set with the parent item(s) }
    =ORIGIN { A synonym I prefer to PARENT. }

    SET { The set this item is in. For debugging. }

    =LAST_FIELD

);

# Elements of the RECOGNIZER structure
use Marpa::XS::Offset qw(

    :package=Marpa::XS::Internal::Recognizer

    C { A C structure }

    GRAMMAR { the grammar used }
    EARLEY_SETS { the array of the Earley sets }
    FURTHEST_EARLEME { last earley set with something in it }
    LAST_COMPLETED_EARLEME
    FINISHED
    USE_LEO { Use Leo items? }

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

    =LAST_EVALUATOR_FIELD

    EARLEY_HASH { Hash of the Earley items by Earley set.
    Used to prevent duplicates.  It is a hash by name
    to Earley item. }

    EXHAUSTED { parse can't continue? }

    LEO_SETS { An array. Indexed by AHFA state id.
    of hashes by symbol name to Leo items. }

    POSTDOT { An array. Indexed by AHFA state id.
    of hashes by symbol name to Earley item and to-states }

    TOO_MANY_EARLEY_ITEMS
    TRACE_EARLEY_SETS
    TRACE_TERMINALS
    WARNINGS

    MODE

);

package Marpa::XS::Internal::Recognizer;

use Marpa::XS::Internal::Carp_Not;

use English qw( -no_match_vars );

use constant EARLEME_MASK => ~(0x7fffffff);

use constant DEFAULT_TOO_MANY_EARLEY_ITEMS => 100;

my $parse_number = 0;

sub Marpa::XS::Internal::Earley_Item::new {
    my ( $class, $recce ) = @_;
    my $item = bless [], $class;

    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $earley_item_c = Marpa::XS::Internal::Earley_Item_C->new( $recce_c );
    $item->[Marpa::XS::Internal::Earley_Item::C] = $earley_item_c;
    return $item;
} ## end sub Marpa::XS::Internal::Earley_Item::new

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

    if ( !$grammar_c->is_precomputed() ) {
        Marpa::XS::exception(
            'Attempt to parse grammar which is not precomputed');
    }

    # set the defaults
    local $Marpa::XS::Internal::TRACE_FH = my $trace_fh =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE] =
        $grammar->[Marpa::XS::Internal::Grammar::TRACE_FILE_HANDLE];
    $recce->[Marpa::XS::Internal::Recognizer::WARNINGS] = 1;
    $recce->reset_evaluation();
    $recce->[Marpa::XS::Internal::Recognizer::C] =
        Marpa::XS::Internal::R_C->new( $grammar_c );
    $recce->[Marpa::XS::Internal::Recognizer::MODE]           = 'default';
    $recce->[Marpa::XS::Internal::Recognizer::RANKING_METHOD] = 'none';
    $recce->[Marpa::XS::Internal::Recognizer::USE_LEO]        = 1;
    $recce->[Marpa::XS::Internal::Recognizer::MAX_PARSES]     = 0;

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

    if (not defined
        $recce->[Marpa::XS::Internal::Recognizer::TOO_MANY_EARLEY_ITEMS] )
    {
        my $AHFA_size =
            scalar @{ $grammar->[Marpa::XS::Internal::Grammar::AHFA] };
        $recce->[Marpa::XS::Internal::Recognizer::TOO_MANY_EARLEY_ITEMS] =
            List::Util::max( ( 2 * $AHFA_size ),
            Marpa::XS::Internal::Recognizer::DEFAULT_TOO_MANY_EARLEY_ITEMS );
    } ## end if ( not defined $recce->[...])

    # Some of this processing -- to find terminals and Leo symbols
    # by state -- should perhaps be done in the grammar.

    my $terminal_names =
        $grammar->[Marpa::XS::Internal::Grammar::TERMINAL_NAMES];

    my $AHFA        = $grammar->[Marpa::XS::Internal::Grammar::AHFA];
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];

    my $earley_set;

    my $start_states = $grammar->[Marpa::XS::Internal::Grammar::START_STATES];
    my $postdot      = {};

    for my $state ( @{$start_states} ) {
        my $state_id = $state->[Marpa::XS::Internal::AHFA::ID];
        my $name     = sprintf
            'S%d@%d-%d',
            $state_id, 0, 0;

        my $item = Marpa::XS::Internal::Earley_Item->new($recce);
        $item->[Marpa::XS::Internal::Earley_Item::NAME]   = $name;
        $item->[Marpa::XS::Internal::Earley_Item::STATE]  = $state;
        $item->[Marpa::XS::Internal::Earley_Item::PARENT] = 0;
        $item->[Marpa::XS::Internal::Earley_Item::LINKS]  = [];
        $item->[Marpa::XS::Internal::Earley_Item::SET]    = 0;

        push @{$earley_set}, $item;

        while ( my ( $transition_symbol, $to_states ) =
            each %{ $state->[Marpa::XS::Internal::AHFA::TRANSITION] } )
        {
            my @to_states = grep {ref} @{$to_states};
            push @{ $postdot->{0}->{$transition_symbol} },
                [ $item, \@to_states, 0 ];
        } ## end while ( my ( $transition_symbol, $to_states ) = each %{...})

    } ## end for my $state ( @{$start_states} )

    $recce->[Marpa::XS::Internal::Recognizer::EARLEY_HASH] = {};

    $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR]     = $grammar;
    $recce->[Marpa::XS::Internal::Recognizer::EARLEY_SETS] = [$earley_set];

    $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME]       = 0;
    $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME] = 0;

    $recce->[Marpa::XS::Internal::Recognizer::POSTDOT] = $postdot;

    # Don't include the start states in the Leo sets.
    $recce->[Marpa::XS::Internal::Recognizer::LEO_SETS] = [];

    if ( $trace_terminals > 1 ) {
        for my $terminal (
            grep { $terminal_names->{$_} }
            keys %{ $postdot->{0} }
            )
        {
            say {$Marpa::XS::Internal::TRACE_FH}
                qq{Expecting "$terminal" at earleme 0}
                or Marpa::XS::exception("Cannot print: $ERRNO");
        } ## end for my $terminal ( grep { $terminal_names->{$_} } keys...)
    } ## end if ( $trace_terminals > 1 )

    return $recce;
} ## end sub Marpa::XS::Recognizer::new

use constant RECOGNIZER_OPTIONS => [
    qw{
        closures
        end
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
            $recce->[Marpa::XS::Internal::Recognizer::TOO_MANY_EARLEY_ITEMS] =
                $value;
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
    return scalar @{$earley_set};
} ## end sub Marpa::XS::Recognizer::earley_set_size

sub Marpa::XS::Recognizer::check_terminal {
    my ( $recce, $name ) = @_;
    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    return $grammar->check_terminal($name);
}

sub Marpa::XS::Recognizer::status {
    my ($recce) = @_;

    my $exhausted = $recce->[Marpa::XS::Internal::Recognizer::EXHAUSTED];
    return if $exhausted;

    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $terminal_names =
        $grammar->[Marpa::XS::Internal::Grammar::TERMINAL_NAMES];
    my $last_completed_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];

    return (
        $last_completed_earleme,
        [   grep { $terminal_names->{$_} }
                keys %{
                $recce->[Marpa::XS::Internal::Recognizer::POSTDOT]
                    ->{$last_completed_earleme}
                }
        ]
    ) if wantarray;
    return $last_completed_earleme;

} ## end sub Marpa::XS::Recognizer::status

sub Marpa::XS::Recognizer::strip {
    my ($recce) = @_;
    Marpa::XS::exception('Cannot strip recognizer before input is finished')
        if not $recce->[Marpa::XS::Internal::Recognizer::FINISHED];
    $#{$recce} = Marpa::XS::Internal::Recognizer::LAST_EVALUATOR_FIELD;
    return 1;
} ## end sub Marpa::XS::Recognizer::strip

# Viewing methods, for debugging

sub Marpa::XS::show_link_choice {
    my ($link) = @_;
    my ( $predecessor, $cause, $token_name, $value_ref ) = @{$link};
    my @pieces = ();
    if ($predecessor) {
        push @pieces,
            'p=' . $predecessor->[Marpa::XS::Internal::Earley_Item::NAME];
    }
    if ( not defined $cause ) {
        push @pieces, "s=$token_name";
        my $token_dump = Data::Dumper->new( [$value_ref] )->Terse(1)->Dump;
        chomp $token_dump;
        push @pieces, "t=$token_dump";
    } ## end if ( not defined $cause )
    else {
        push @pieces,
            'c=' . $link->[1]->[Marpa::XS::Internal::Earley_Item::NAME];
    }
    return '[' . ( join '; ', @pieces ) . ']';
} ## end sub Marpa::XS::show_link_choice

sub Marpa::XS::show_leo_link_choice {
    my ($leo_link) = @_;
    my ( $leo_item, $cause, $symbol_name, $value_ref ) = @{$leo_link};
    my @link_texts = ();
    if ($leo_item) {
        push @link_texts,
            ( 'l=' . $leo_item->[Marpa::XS::Internal::Leo_Item::NAME] );
    }
    if ($cause) {
        push @link_texts,
            'c=' . $cause->[Marpa::XS::Internal::Earley_Item::NAME];
    }
    else {
        my $token_dump = Data::Dumper->new( [$value_ref] )->Terse(1)->Dump;
        chomp $token_dump;
        push @link_texts, "s=$symbol_name", "t=$token_dump";
    }
    return '[' . ( join '; ', @link_texts ) . ']';
} ## end sub Marpa::XS::show_leo_link_choice

sub Marpa::XS::show_earley_item {
    my ($item)    = @_;
    my $links     = $item->[Marpa::XS::Internal::Earley_Item::LINKS];
    my $leo_links = $item->[Marpa::XS::Internal::Earley_Item::LEO_LINKS];

    my $text = $item->[Marpa::XS::Internal::Earley_Item::NAME];

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

sub Marpa::XS::show_leo_item {
    my ($item)     = @_;
    my $links      = $item->[Marpa::XS::Internal::Leo_Item::LINKS];
    my $leo_symbol = $item->[Marpa::XS::Internal::Leo_Item::LEO_SYMBOL];

    my $text = $item->[Marpa::XS::Internal::Leo_Item::NAME];

    my $actual_to_state = my $leo_state_id =
        $item->[Marpa::XS::Internal::Leo_Item::LEO_ACTUAL_STATE]
        ->[Marpa::XS::Internal::AHFA::ID];
    $text .= qq{; actual="$leo_symbol"->$leo_state_id;};

    if ( defined $links and @{$links} ) {
        for my $link ( @{$links} ) {
            $text .= q{ } . Marpa::XS::show_leo_link_choice($link);
        }
    }
    return $text;
} ## end sub Marpa::XS::show_leo_item

sub Marpa::XS::show_earley_set {
    my ($earley_set) = @_;
    my $text = q{};
    for my $earley_item ( @{$earley_set} ) {
        $text .= Marpa::XS::show_earley_item($earley_item) . "\n";
    }
    return $text;
} ## end sub Marpa::XS::show_earley_set

sub Marpa::XS::show_leo_set {
    my ($leo_set) = @_;
    my $text = q{};
    for my $leo_item ( @{$leo_set} ) {
        $text .= Marpa::XS::show_leo_item($leo_item) . "\n";
    }
    return $text;
} ## end sub Marpa::XS::show_leo_set

sub Marpa::XS::show_earley_set_list {
    my ( $earley_set_list, $leo_set_list ) = @_;
    my $text             = q{};
    my $earley_set_count = @{$earley_set_list};
    LIST: for my $ix ( 0 .. $earley_set_count - 1 ) {
        my $set = $earley_set_list->[$ix];
        next LIST if not defined $set;
        $text .= "Earley Set $ix\n" . Marpa::XS::show_earley_set($set);
        my $leo_set = $leo_set_list->[$ix];
        next LIST if not defined $leo_set;
        $text .= Marpa::XS::show_leo_set($leo_set);
    } ## end for my $ix ( 0 .. $earley_set_count - 1 )
    return $text;
} ## end sub Marpa::XS::show_earley_set_list

sub Marpa::XS::Recognizer::show_earley_sets {
    my ($recce) = @_;
    my $last_completed_earleme = $recce->[LAST_COMPLETED_EARLEME]
        // 'stripped';
    my $furthest_earleme = $recce->[FURTHEST_EARLEME];
    my $earley_set_list  = $recce->[EARLEY_SETS];
    my $leo_set_list     = $recce->[LEO_SETS];

    return
          "Last Completed: $last_completed_earleme; "
        . "Furthest: $furthest_earleme\n"
        . Marpa::XS::show_earley_set_list( $earley_set_list, $leo_set_list );

} ## end sub Marpa::XS::Recognizer::show_earley_sets

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
        my $earley_set = $earley_set_list->[$ix];
        my $reports    = report_progress($recce, $earley_set);
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
            my $rhs_length =
                scalar @{ $rule->[Marpa::XS::Internal::Rule::RHS] };
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
                $item_text .= Marpa::XS::show_dotted_rule( $rule, $position );
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
    my ($recce, $earley_set) = @_;
    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $rules = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];

    # Reports must be unique by a key
    # composted of original rule, rule position, and
    # location in the parse.  This hash is to
    # quarantee that.
    my %progress_report_hash = ();

    for my $earley_item ( @{$earley_set} ) {
        my $AHFA_state =
            $earley_item->[Marpa::XS::Internal::Earley_Item::STATE];
        my $origin = $earley_item->[Marpa::XS::Internal::Earley_Item::PARENT];
        my $current = $earley_item->[Marpa::XS::Internal::Earley_Item::SET];
        my $leo_links =
            $earley_item->[Marpa::XS::Internal::Earley_Item::LEO_LINKS];
        my $is_leo = $leo_links && scalar @{$leo_links};
        my @AHFA_items = $grammar_c->AHFA_state_items($AHFA_state->[Marpa::XS::Internal::AHFA::ID]);
        AHFA_ITEM: for my $AHFA_item_id ( @AHFA_items ) {
            my $marpa_rule_id = $grammar_c->AHFA_item_rule($AHFA_item_id);
	    my $marpa_rule = $rules->[$marpa_rule_id];
            my $marpa_position = $grammar_c->AHFA_item_position($AHFA_item_id);
	    $marpa_position < 0 and $marpa_position = $grammar_c->rule_length($marpa_rule_id);
            my $chaf_start = $grammar_c->rule_virtual_start($marpa_rule_id);
	    $chaf_start < 0 and $chaf_start = undef;
            my $original_rule = $marpa_rule;
	    if (defined $chaf_start
		and ( my $chaf_original_rule =
		    $marpa_rule->[Marpa::XS::Internal::Rule::ORIGINAL_RULE] )
		)
	    {
		my $original_rule = $chaf_original_rule;
	    }
            my $original_rhs =
                $original_rule->[Marpa::XS::Internal::Rule::RHS];

            # position in original rule, to be calculated
            my $original_position;
            if ( defined $chaf_start )
            {
                my $chaf_rhs = $marpa_rule->[Marpa::XS::Internal::Rule::RHS];
                $original_position =
                    $marpa_position >= scalar @{$chaf_rhs}
                    ? scalar @{$original_rhs}
                    : ( $chaf_start + $marpa_position );
            } ## end if ( my $chaf_start = $marpa_rule->[...])
            $original_position //= $marpa_position;
            my $rule_id = $original_rule->[Marpa::XS::Internal::Rule::ID];
            my @data    = ( $rule_id, $original_position, $origin );
            my $key     = join q{;}, @data;
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
        } ## end for my $NFA_state ( @{$NFA_states} )
    } ## end for my $earley_item ( @{$earley_set} )
    return [ values %progress_report_hash ];
} ## end sub report_progress

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
    my $warnings = $recce->[Marpa::XS::Internal::Recognizer::WARNINGS];

    my $earley_hash = $recce->[Marpa::XS::Internal::Recognizer::EARLEY_HASH];

    Marpa::XS::exception('Attempt to scan tokens after parsing is finished')
        if $recce->[Marpa::XS::Internal::Recognizer::FINISHED]
            and scalar @{$tokens};

    Marpa::XS::exception('Attempt to scan tokens when parsing is exhausted')
        if $recce->[Marpa::XS::Internal::Recognizer::EXHAUSTED]
            and scalar @{$tokens};

    # TOKEN PROCESSING PHASE

    my $terminal_names =
        $grammar->[Marpa::XS::Internal::Grammar::TERMINAL_NAMES];

    my $next_token_earleme = my $last_completed_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];
    my $furthest_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME];
    my $earley_set_list =
        $recce->[Marpa::XS::Internal::Recognizer::EARLEY_SETS];
    my $AHFA = $grammar->[Marpa::XS::Internal::Grammar::AHFA];

    $token_ix_ref //= \( my $token_ix = 0 );

    my $token_args = $tokens->[ ${$token_ix_ref} ];

    if ( not scalar @{$tokens} ) { $next_token_earleme++ }

    EARLEME: while ( ${$token_ix_ref} < scalar @{$tokens} ) {

        my $tokens_here;
        my $token_hash_here;

        my $current_token_earleme = $last_completed_earleme;

        # It's not 100% clear whether it's best to leave
        # the token_ix_ref pointing at the start of the
        # earleme, or at the actual problem token.
        # Right now, we set it at the actual problem
        # token, which is probably what will turn out
        # to be easiest.
        # my $first_ix_of_this_earleme = ${$token_ix_ref};

        TOKEN: while ( $current_token_earleme == $next_token_earleme ) {

            last TOKEN if not my $token_args = $tokens->[ ${$token_ix_ref} ];
            Marpa::XS::exception(
                'Tokens must be array refs: token #',
                ${$token_ix_ref}, " is $token_args\n",
            ) if ref $token_args ne 'ARRAY';
            ${$token_ix_ref}++;
            my ( $symbol_name, $value, $length, $offset ) = @{$token_args};

            my $postdot = $recce->[Marpa::XS::Internal::Recognizer::POSTDOT];
            my $postdot_here = $postdot->{$current_token_earleme};

            Marpa::XS::exception(
                "Attempt to add token '$symbol_name' at location where processing is complete:\n",
                "  Add attempted at $current_token_earleme\n",
                "  Processing complete to $last_completed_earleme\n"
            ) if $current_token_earleme < $last_completed_earleme;

            if (   not defined $symbol_name
                or not $terminal_names->{$symbol_name} )
            {
                local $Data::Dumper::Terse    = 1;
                local $Data::Dumper::Maxdepth = 1;
                my $problem =
                    defined $symbol_name
                    ? qq{Token name "$symbol_name" is not the name of a terminal symbol}
                    : q{The name of a terminal symbol was an undef};
                Marpa::XS::exception( q{Fatal Problem with token: },
                    Data::Dumper::Dumper($token_args), $problem );
            } ## end if ( not defined $symbol_name or not $terminal_names...)

            # Make sure it's an allowed terminal symbol.
            my $postdot_data = $postdot_here->{$symbol_name};
            if ( not $postdot_data ) {
                if ( not $interactive ) {
                    Marpa::XS::exception(
                        qq{Terminal "$symbol_name" received when not expected}
                    );
                }
                if ($trace_terminals) {
                    say {$trace_fh}
                        qq{Rejected "$symbol_name" at $last_completed_earleme}
                        or Marpa::XS::exception("Cannot print: $ERRNO");
                }

                # Current token didn't actually work, so back out
                # the increment
                ${$token_ix_ref}--;

                return (
                    $last_completed_earleme,
                    [   grep { $terminal_names->{$_} }
                            keys %{ $postdot->{$last_completed_earleme} }
                    ]
                ) if wantarray;
                return $last_completed_earleme;

            } ## end if ( not $postdot_data )

            my $value_ref = \($value);

            if ( not defined $length ) {
                $length = 1;
            }

            if ( $length & Marpa::XS::Internal::Recognizer::EARLEME_MASK ) {
                Marpa::XS::exception(
                    'Token ' . $symbol_name . " is too long\n",
                    "  Token starts at $last_completed_earleme, and its length is $length\n"
                );
            } ## end if ( $length & ...)

            if ( $length <= 0 ) {
                Marpa::XS::exception( 'Token '
                        . $symbol_name
                        . ' has non-positive length '
                        . $length );
            } ## end if ( $length <= 0 )

            my $end_earleme = $current_token_earleme + $length;

            Marpa::XS::exception(
                'Token ' . $symbol_name . " makes parse too long\n",
                "  Token starts at $last_completed_earleme, and its length is $length\n"
                )
                if $end_earleme
                    & Marpa::XS::Internal::Recognizer::EARLEME_MASK;

            $offset //= 1;
            Marpa::XS::exception(
                'Token ' . $symbol_name . " has negative offset\n",
                "  Token starts at $last_completed_earleme, and its length is $length\n",
                "  Tokens are required to be in sequence by location\n",
            ) if $offset < 0;
            $next_token_earleme += $offset;

            my $token_entry =
                [ $symbol_name, $value_ref, $length, $postdot_data ];

            # This logic is arranged so that non-overlapping tokens do not incur the cost
            # of the checks for duplicates
            if ( not $tokens_here ) {
                $tokens_here = [$token_entry];
                next TOKEN;
            }

            if ( not $token_hash_here ) {
                $token_hash_here =
                    { map { ( join q{;}, @{$_}[ 0, 2 ] ) => 1 }
                        @{$tokens_here} };
            }

            my $hash_key = join q{;}, $symbol_name, $length;
            Marpa::XS::exception(
                qq{"$symbol_name" already scanned with length $length at location $current_token_earleme}
            ) if $token_hash_here->{$hash_key};

            $token_hash_here->{$hash_key} = 1;
            push @{$tokens_here}, $token_entry;

        } ## end while ( $current_token_earleme == $next_token_earleme )

        # The last descriptor in
        # a tokens call always advances the current earleme by at least one
        $current_token_earleme++;
        $current_token_earleme = $next_token_earleme
            if $next_token_earleme > $current_token_earleme;

        $tokens_here //= [];

        $earley_set_list->[$last_completed_earleme] //= [];
        my $earley_set = $earley_set_list->[$last_completed_earleme];

        my %accepted = ();    # used only if trace_terminals set

        ALTERNATIVE: for my $alternative ( @{$tokens_here} ) {
            my ( $token_name, $value_ref, $length, $postdot_data ) =
                @{$alternative};

            # compute goto(state, token_name)
            if ($trace_terminals) {
                $accepted{$token_name} //= 0;
            }

            EARLEY_ITEM: for my $postdot_data_entry ( @{$postdot_data} ) {

                my ( $earley_item, $to_states, $parent, $leo_item ) =
                    @{$postdot_data_entry};

                next EARLEY_ITEM if not $to_states;

                if ($trace_terminals) {
                    $accepted{$token_name} = $length;
                }

                # Create the kernel item and its link.
                my $target_ix = $last_completed_earleme + $length;
                if ( $target_ix > $furthest_earleme ) {
                    $furthest_earleme = $target_ix;
                }

                my $target_set = ( $earley_set_list->[$target_ix] //= [] );
                TO_STATE: for my $to_state ( grep {ref} @{$to_states} ) {
                    my $reset =
                        $to_state->[Marpa::XS::Internal::AHFA::RESET_ORIGIN];
                    my $origin = $reset ? $target_ix : $parent;
                    my $to_state_id =
                        $to_state->[Marpa::XS::Internal::AHFA::ID];
                    my $name = sprintf
                        'S%d@%d-%d',
                        $to_state_id, $origin, $target_ix;

                    my $target_item = $earley_hash->{$name};
                    if ( not defined $target_item ) {
                        $target_item =
                            Marpa::XS::Internal::Earley_Item->new($recce);
                        $target_item->[Marpa::XS::Internal::Earley_Item::NAME]
                            = $name;
                        $target_item
                            ->[Marpa::XS::Internal::Earley_Item::STATE] =
                            $to_state;
                        $target_item
                            ->[Marpa::XS::Internal::Earley_Item::PARENT] =
                            $origin;
                        $target_item
                            ->[Marpa::XS::Internal::Earley_Item::LEO_LINKS] =
                            [];
                        $target_item
                            ->[Marpa::XS::Internal::Earley_Item::LINKS] = [];
                        $target_item->[Marpa::XS::Internal::Earley_Item::SET]
                            = $target_ix;
                        $earley_hash->{$name} = $target_item;
                        push @{$target_set}, $target_item;

                    } ## end if ( not defined $target_item )

                    next TO_STATE if $reset;

                    if ($leo_item) {
                        push @{
                            $target_item->[
                                Marpa::XS::Internal::Earley_Item::LEO_LINKS
                            ]
                            },
                            [ $leo_item, undef, $token_name, $value_ref ];
                    } ## end if ($leo_item)
                    else {
                        push @{ $target_item
                                ->[Marpa::XS::Internal::Earley_Item::LINKS] },
                            [ $earley_item, undef, $token_name, $value_ref ];
                    }
                }    # for my $to_state

            }    # ALTERNATIVE

        }    # EARLEY_ITEM

        if ($trace_terminals) {
            TOKEN: while ( my ( $token_name, $length ) = each %accepted ) {

                # The logic assumes that
                # length is non-zero only for accepted tokens
                if ( $length <= 0 ) {
                    say {$trace_fh}
                        qq{Rejected "$token_name" at $last_completed_earleme}
                        or Marpa::XS::exception("Cannot print: $ERRNO");
                    next TOKEN;
                } ## end if ( $length <= 0 )

                say {$trace_fh}
                    qq{Accepted "$token_name" at $last_completed_earleme-}
                    . ( $length + $last_completed_earleme )
                    or Marpa::XS::exception("Cannot print: $ERRNO")

            } ## end while ( my ( $token_name, $length ) = each %accepted )
        } ## end if ($trace_terminals)

        $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME] =
            $furthest_earleme;
        if ( $furthest_earleme < $last_completed_earleme ) {
            $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME] =
                $furthest_earleme;
            $recce->[Marpa::XS::Internal::Recognizer::EXHAUSTED] = 1;
            return;
        } ## end if ( $furthest_earleme < $last_completed_earleme )

        $last_completed_earleme =
            Marpa::XS::Internal::Recognizer::complete($recce);

    } ## end while ( ${$token_ix_ref} < scalar @{$tokens} )

    $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME] =
        $furthest_earleme;

    if ( $mode eq 'stream' ) {
        while ( $last_completed_earleme < $next_token_earleme ) {
            $last_completed_earleme =
                Marpa::XS::Internal::Recognizer::complete($recce);
        }
    } ## end if ( $mode eq 'stream' )

    if ( $mode eq 'default' ) {
        while ( $last_completed_earleme < $furthest_earleme ) {
            $last_completed_earleme =
                Marpa::XS::Internal::Recognizer::complete($recce);
        }
        $recce->[Marpa::XS::Internal::Recognizer::FINISHED] = 1;
    } ## end if ( $mode eq 'default' )

    return (
        $last_completed_earleme,
        [   grep { $terminal_names->{$_} }
                keys %{
                $recce->[Marpa::XS::Internal::Recognizer::POSTDOT]
                    ->{$last_completed_earleme}
                }
        ]
    ) if wantarray;

    return $last_completed_earleme;

} ## end sub Marpa::XS::Recognizer::tokens

# Perform the completion step on an earley set

sub Marpa::XS::Recognizer::end_input {
    my ($recce) = @_;
    local $Marpa::XS::Internal::TRACE_FH =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE];
    my $last_completed_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];
    my $furthest_earleme =
        $recce->[Marpa::XS::Internal::Recognizer::FURTHEST_EARLEME];
    while ( $last_completed_earleme < $furthest_earleme ) {
        $last_completed_earleme =
            $recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME]
            = Marpa::XS::Internal::Recognizer::complete($recce);
    }
    $recce->[Marpa::XS::Internal::Recognizer::FINISHED] = 1;
    return 1;
} ## end sub Marpa::XS::Recognizer::end_input

sub complete {
    my ($recce) = @_;

    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $AHFA    = $grammar->[Marpa::XS::Internal::Grammar::AHFA];
    my $earley_set_list =
        $recce->[Marpa::XS::Internal::Recognizer::EARLEY_SETS];

    my $earley_hash = $recce->[Marpa::XS::Internal::Recognizer::EARLEY_HASH];
    my $terminal_names =
        $grammar->[Marpa::XS::Internal::Grammar::TERMINAL_NAMES];
    my $postdot  = $recce->[Marpa::XS::Internal::Recognizer::POSTDOT];
    my $leo_sets = $recce->[Marpa::XS::Internal::Recognizer::LEO_SETS];
    my $too_many_earley_items =
        $recce->[Marpa::XS::Internal::Recognizer::TOO_MANY_EARLEY_ITEMS];
    my $trace_earley_sets =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_EARLEY_SETS];
    my $trace_terminals =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_TERMINALS] // 0;

    my $earleme_to_complete =
        ++$recce->[Marpa::XS::Internal::Recognizer::LAST_COMPLETED_EARLEME];

    $earley_set_list->[$earleme_to_complete] //= [];
    my $earley_set = $earley_set_list->[$earleme_to_complete];

    # Important: more earley sets can be added in the loop
    my $earley_set_ix = -1;
    EARLEY_ITEM: while (1) {

        my $earley_item = $earley_set->[ ++$earley_set_ix ];
        last EARLEY_ITEM if not defined $earley_item;

        my ( $state, $parent ) = @{$earley_item}[
            Marpa::XS::Internal::Earley_Item::STATE,
            Marpa::XS::Internal::Earley_Item::PARENT
        ];
        my $state_id = $state->[Marpa::XS::Internal::AHFA::ID];

        next EARLEY_ITEM if $earleme_to_complete == $parent;

        PARENT_ITEM:
        for my $parent_data (
            map  { @{$_} }
            grep {defined}
            map  { $postdot->{$parent}->{$_} }
            @{ $state->[Marpa::XS::Internal::AHFA::COMPLETE_LHS] }
            )
        {
            my ( $parent_item, $states, $grandparent, $leo_item ) =
                @{$parent_data};
            my $parent_state =
                $parent_item->[Marpa::XS::Internal::Earley_Item::STATE];

            TRANSITION_STATE:
            for my $transition_state ( grep {ref} @{$states} ) {
                my $reset = $transition_state
                    ->[Marpa::XS::Internal::AHFA::RESET_ORIGIN];
                my $origin =
                      $reset
                    ? $earleme_to_complete
                    : $grandparent;
                my $transition_state_id =
                    $transition_state->[Marpa::XS::Internal::AHFA::ID];
                my $name = sprintf
                    'S%d@%d-%d',
                    $transition_state_id, $origin, $earleme_to_complete;
                my $target_item = $earley_hash->{$name};
                if ( not defined $target_item ) {
                    $target_item =
                        Marpa::XS::Internal::Earley_Item->new($recce);
                    $target_item->[Marpa::XS::Internal::Earley_Item::NAME] =
                        $name;
                    $target_item->[Marpa::XS::Internal::Earley_Item::STATE] =
                        $transition_state;
                    $target_item->[Marpa::XS::Internal::Earley_Item::PARENT] =
                        $origin;
                    $target_item
                        ->[Marpa::XS::Internal::Earley_Item::LEO_LINKS] = [];
                    $target_item->[Marpa::XS::Internal::Earley_Item::LINKS] =
                        [];
                    $target_item->[Marpa::XS::Internal::Earley_Item::SET] =
                        $earleme_to_complete;
                    $earley_hash->{$name} = $target_item;
                    push @{$earley_set}, $target_item;
                }    # unless defined $target_item
                next TRANSITION_STATE if $reset;
                if ($leo_item) {
                    push @{ $target_item
                            ->[Marpa::XS::Internal::Earley_Item::LEO_LINKS] },
                        [ $leo_item, $earley_item ];
                }
                else {
                    push @{ $target_item
                            ->[Marpa::XS::Internal::Earley_Item::LINKS] },
                        [ $parent_item, $earley_item ];
                } ## end else [ if ($leo_item) ]
            }    # TRANSITION_STATE

        }    # PARENT_ITEM

    }    # EARLEY_ITEM

    if ( $too_many_earley_items >= 0
        and ( my $item_count = scalar @{$earley_set} )
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

    my $postdot_here = $postdot->{$earleme_to_complete} = {};
    for my $earley_item ( @{$earley_set} ) {
        my $state  = $earley_item->[Marpa::XS::Internal::Earley_Item::STATE];
        my $parent = $earley_item->[Marpa::XS::Internal::Earley_Item::PARENT];
        while ( my ( $postdot_symbol_name, $next_states ) =
            each %{ $state->[Marpa::XS::Internal::AHFA::TRANSITION] } )
        {
            push @{ $postdot_here->{$postdot_symbol_name} },
                [ $earley_item, $next_states, $parent ];
        } ## end while ( my ( $postdot_symbol_name, $next_states ) = each...)
    } ## end for my $earley_item ( @{$earley_set} )

    my $leo_set = $leo_sets->[$earleme_to_complete] = [];
    my @leo_worklist =
        $recce->[Marpa::XS::Internal::Recognizer::USE_LEO]
        ? ( keys %{$postdot_here}, ['prediction'] )
        : ();
    my %leo_triggers = ();
    my $leo_phase    = 'initial';
    SYMBOL:
    for ( ;; ) {
        my $postdot_symbol = shift @leo_worklist;
        if ( not defined $postdot_symbol ) {
            last SYMBOL if $leo_phase eq 'final';
            $leo_phase    = 'final';
            @leo_worklist = values %leo_triggers;
            next SYMBOL;
        } ## end if ( not defined $postdot_symbol )
        if ( ref $postdot_symbol ) {
            $leo_phase = $postdot_symbol->[0];
            next SYMBOL;
        }
        my $postdot_data = $postdot_here->{$postdot_symbol};
        next SYMBOL if scalar @{$postdot_data} != 1;
        my $postdot_0 = $postdot_data->[0];
        my ( $base_earley_item, $next_states, $leo_parent, $already_done ) =
            @{$postdot_0};

        # $already_done is actually the leo item.
        # It is true iff we've already added a leo item for this postdot symbol
        next SYMBOL if $already_done;

        my ( $leo_lhs, $leo_state ) = @{$next_states};

        # Only one transition in the Earley set on this symbol,
        # but it is not to a Leo completion.
        next SYMBOL if ref $leo_lhs;

        my $leo_actual_state = List::Util::first {ref} (
            @{  $base_earley_item->[Marpa::XS::Internal::Earley_Item::STATE]
                    ->[Marpa::XS::Internal::AHFA::TRANSITION]
                    ->{$postdot_symbol}
                }
        );

        # A flag that indicates if we working on a prediction
        # Leo item.  Set here because $leo_parent is changed
        # below.
        my $prediction = $leo_parent == $earleme_to_complete;

        my $predecessor_leo_item;
        FIND_LEO_ITEM_DATA: {

            my $predecessor_postdot = $postdot->{$leo_parent}->{$leo_lhs};
            (   undef,
                ( my $predecessor_to_states ),
                ( my $predecessor_parent ),
                $predecessor_leo_item
            ) = @{ $predecessor_postdot->[0] };

            if ($predecessor_leo_item) {
                $leo_parent = $predecessor_parent;
                $leo_state =
                    List::Util::first {ref} @{$predecessor_to_states};
                last FIND_LEO_ITEM_DATA;
            } ## end if ($predecessor_leo_item)

            # If here, we didn't find a predecessor Leo item.
            # That's ok in the final phase,
            # or if we are not working on a Leo prediction item.
            last FIND_LEO_ITEM_DATA
                if not $prediction
                    or $leo_phase eq 'final';

            # Set up so that when we do find the $leo_lhs,
            # we will 'trigger' this postdot symbol again.
            $leo_triggers{$leo_lhs} = $postdot_symbol;

            next SYMBOL;

        } ## end FIND_LEO_ITEM_DATA:

        my $name = sprintf
            'L%d@%d-%d',
            $leo_state->[Marpa::XS::Internal::AHFA::ID], $leo_parent,
            $earleme_to_complete;
        my $leo_item = [];
        $leo_item->[Marpa::XS::Internal::Leo_Item::NAME]   = $name;
        $leo_item->[Marpa::XS::Internal::Leo_Item::STATE]  = $leo_state;
        $leo_item->[Marpa::XS::Internal::Leo_Item::PARENT] = $leo_parent;
        $leo_item->[Marpa::XS::Internal::Leo_Item::SET] =
            $earleme_to_complete;
        $leo_item->[Marpa::XS::Internal::Leo_Item::LEO_SYMBOL] =
            $postdot_symbol;
        $leo_item->[Marpa::XS::Internal::Leo_Item::LEO_ACTUAL_STATE] =
            $leo_actual_state;
        $leo_item->[Marpa::XS::Internal::Leo_Item::LINKS] =
            [ [ $predecessor_leo_item, $base_earley_item ] ];

        push @{$leo_set},   $leo_item;
        push @{$postdot_0}, $leo_item;
        $postdot_here->{$postdot_symbol} =
            [ [ $base_earley_item, [$leo_state], $leo_parent, $leo_item ] ];

        # The rest of the processing is to deal with Leo prediction items.
        next SYMBOL if not $prediction;

        next SYMBOL
            if not my $triggered_symbol = $leo_triggers{$postdot_symbol};

        push @leo_worklist, $triggered_symbol;
        delete $leo_triggers{$postdot_symbol};

    } ## end for ( ;; )

    if ( $trace_terminals > 1 ) {
        for my $terminal (
            grep { $terminal_names->{$_} }
            keys %{ $postdot->{$earleme_to_complete} }
            )
        {
            say {$Marpa::XS::Internal::TRACE_FH}
                qq{Expecting "$terminal" at $earleme_to_complete}
                or Marpa::XS::exception("Cannot print: $ERRNO");
        } ## end for my $terminal ( grep { $terminal_names->{$_} } keys...)
    } ## end if ( $trace_terminals > 1 )

    return $earleme_to_complete;

} ## end sub complete

1;
