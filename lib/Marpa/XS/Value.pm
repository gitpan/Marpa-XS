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

package Marpa::XS::Internal::Value;

use 5.010;
use warnings;
use strict;
use integer;

use English qw( -no_match_vars );

# This perlcritic check is broken as of 9 Aug 2010
## no critic (TestingAndDebugging::ProhibitNoWarnings)
no warnings qw(qw);
## use critic

BEGIN {
my $structure = <<'END_OF_STRUCTURE';

    :package=Marpa::XS::Internal::And_Node

    ID

    INITIAL_RANK_REF

    =LAST_FIELD

END_OF_STRUCTURE
    Marpa::offset($structure);
} ## end BEGIN

BEGIN {
my $structure = <<'END_OF_STRUCTURE';

    :package=Marpa::XS::Internal::Iteration_Node

    OR_NODE_ID { The or-node }
    CHOICE { The current choice }
    PARENT { Offset of the parent in the iterations stack }

    IS_CAUSE_READY
    HAS_CAUSE
    IS_PREDECESSOR_READY
    HAS_PREDECESSOR

    IS_PREDECESSOR_OF_PARENT
    IS_CAUSE_OF_PARENT

END_OF_STRUCTURE
    Marpa::offset($structure);
} ## end BEGIN

BEGIN {
my $structure = <<'END_OF_STRUCTURE';

    :package=Marpa::XS::Internal::Op

    :{ These are the valuation-time ops }
    ARGC
    CALL
    CONSTANT_RESULT
    VIRTUAL_HEAD
    VIRTUAL_HEAD_NO_SEP
    VIRTUAL_KERNEL
    VIRTUAL_TAIL

END_OF_STRUCTURE
    Marpa::offset($structure);
} ## end BEGIN

use constant SKIP => -1;

use warnings;

# Not in test suite, and at this point may be broken.
sub Marpa::XS::Recognizer::show_bocage {
    my ($recce) = @_;
    my $text;
    my @data = ();
    my $id = 0;
    my $recce_c     = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $grammar     = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $symbol_hash = $grammar->[Marpa::XS::Internal::Grammar::SYMBOL_HASH];
    OR_NODE: for my $or_node_id ( 0 .. $recce_c->or_node_count()-1 ) {
	my $position = $recce_c->or_node_position($or_node_id);
	my $rule = $recce_c->or_node_rule($or_node_id);
	my $or_origin = $recce_c->or_node_origin($or_node_id);
	my $origin_earleme = $recce_c->earleme($or_origin);
	my $or_set = $recce_c->or_node_set($or_node_id);
	my $current_earleme = $recce_c->earleme($or_set);
        my @and_node_ids =
            ( $recce_c->or_node_first_and($or_node_id)
                .. $recce_c->or_node_last_and($or_node_id) );
        AND_NODE:
        for my $and_node_id (@and_node_ids) {
            my $symbol = $recce_c->and_node_symbol($and_node_id);
            my $cause_tag;

            if ( defined $symbol ) {
                $cause_tag = "S$symbol";
            }
            my $cause_rule = -1;
            my $cause_id   = $recce_c->and_node_cause($and_node_id);
            if ( defined $cause_id ) {
                $cause_rule = $recce_c->or_node_rule($cause_id);
                $cause_tag =
                    Marpa::XS::Recognizer::or_node_tag( $recce, $cause_id );
            }
            my $parent_tag =
                Marpa::XS::Recognizer::or_node_tag( $recce, $or_node_id );
            my $predecessor_id = $recce_c->and_node_predecessor($and_node_id);
            my $predecessor_tag = q{-};
            if ( defined $predecessor_id ) {
                $predecessor_tag = Marpa::XS::Recognizer::or_node_tag( $recce,
                    $predecessor_id );
            }
            my $tag = join q{ }, $parent_tag, $predecessor_tag, $cause_tag;
	    my $middle_earleme = $origin_earleme;
	    if (defined $predecessor_id) {
		my $predecessor_set = $recce_c->or_node_set($predecessor_id);
		$middle_earleme = $recce_c->earleme($predecessor_set);
	    }

            push @data,
                [
                $origin_earleme, $current_earleme, $rule,
                $position,       $middle_earleme,  $cause_rule,
                ( $symbol // -1 ), $tag
                ];
        } ## end for my $and_node_id (@and_node_ids)
    } ## end for my $or_node_id ( 0 .. $#{$or_nodes} )
    my @sorted_data = map { $_->[-1] } sort {
        $a->[0] <=> $b->[0]
	or $a->[1] <=> $b->[1]
	or $a->[2] <=> $b->[2]
	or $a->[3] <=> $b->[3]
	or $a->[4] <=> $b->[4]
	or $a->[5] <=> $b->[5]
	or $a->[6] <=> $b->[6]
    } @data;
    return (join "\n", @sorted_data) . "\n";;
}

sub Marpa::XS::Recognizer::and_node_tag {
    my ( $recce, $and_node_id ) = @_;
    my $recce_c            = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $parent_or_node_id  = $recce_c->and_node_parent($and_node_id);
    my $origin             = $recce_c->or_node_origin($parent_or_node_id);
    my $origin_earleme     = $recce_c->earleme($origin);
    my $current_earley_set = $recce_c->or_node_set($parent_or_node_id);
    my $current_earleme    = $recce_c->earleme($current_earley_set);
    my $cause_id           = $recce_c->and_node_cause($and_node_id);
    my $predecessor_id     = $recce_c->and_node_predecessor($and_node_id);
    my $middle_earleme     = $origin_earleme;
    if ( defined $predecessor_id ) {
        my $middle_set = $recce_c->or_node_set($predecessor_id);
        $middle_earleme = $recce_c->earleme($middle_set);
    }
    my $position = $recce_c->or_node_position($parent_or_node_id);
    my $rule     = $recce_c->or_node_rule($parent_or_node_id);
    my $tag =
          'R' 
        . $rule . q{:}
        . $position . q{@}
        . $origin_earleme . q{-}
        . $current_earleme;
    if ( defined $cause_id ) {
        my $cause_rule = $recce_c->or_node_rule($cause_id);
        $tag .= 'C' . $cause_rule;
    }
    else {
        my $symbol = $recce_c->and_node_symbol($and_node_id);
        $tag .= 'S' . $symbol;
    }
    $tag .= q{@} . $middle_earleme;
    return $tag;
} ## end sub Marpa::XS::Recognizer::and_node_tag

sub Marpa::XS::Recognizer::show_and_nodes {
    my ($recce) = @_;
    my $recce_c     = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $text;
    my @data = ();
    AND_NODE: for ( my $id = 0;;  $id++) {
	my $parent = $recce_c->and_node_parent($id);
	my $predecessor = $recce_c->and_node_predecessor($id);
	my $cause = $recce_c->and_node_cause($id);
	my $symbol = $recce_c->and_node_symbol($id);
        last AND_NODE if not defined $parent;
	my $origin = $recce_c->or_node_origin( $parent );
	my $set = $recce_c->or_node_set( $parent );
	my $rule = $recce_c->or_node_rule( $parent );
	my $position = $recce_c->or_node_position( $parent );
        my $origin_earleme  = $recce_c->earleme($origin);
        my $current_earleme = $recce_c->earleme($set);
	my $middle_earleme = $origin_earleme;
	if (defined $predecessor) {
	    my $predecessor_set = $recce_c->or_node_set( $predecessor );
	    $middle_earleme = $recce_c->earleme($predecessor_set);
	}
        my $desc =
              'R'
            . $rule . q{:}
            . $position . q{@}
            . $origin_earleme . q{-}
            . $current_earleme;
	my $cause_rule = -1;
	if (defined $cause) {
	    $cause_rule = $recce_c->or_node_rule( $cause );
	    $desc .= 'C' . $cause_rule;
	} else {
	    $desc .= 'S' . $symbol;
	}
	$desc .= q{@} . $middle_earleme;
        push @data,
            [ $origin_earleme, $current_earleme, $rule, $position,
		$middle_earleme,
		$cause_rule,
		($symbol // -1),
		$desc ];
    } ## end for ( ;; )
    my @sorted_data = map { $_->[-1] } sort {
        $a->[0] <=> $b->[0]
	or $a->[1] <=> $b->[1]
	or $a->[2] <=> $b->[2]
	or $a->[3] <=> $b->[3]
	or $a->[4] <=> $b->[4]
	or $a->[5] <=> $b->[5]
	or $a->[6] <=> $b->[6]
    } @data;
    return (join "\n", @sorted_data) . "\n";;
}

sub Marpa::XS::Recognizer::or_node_tag {
    my ($recce, $or_node_id) = @_;
    my $recce_c     = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $set = $recce_c->or_node_set($or_node_id);
    my $rule = $recce_c->or_node_rule($or_node_id);
    my $origin = $recce_c->or_node_origin($or_node_id);
    my $position = $recce_c->or_node_position($or_node_id);
    return 'R' . $rule . q{:} . $position . q{@} . $origin . q{-} . $set;
}

sub Marpa::XS::Recognizer::show_or_nodes {
    my ($recce, $verbose) = @_;
    my $recce_c     = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $text;
    my @data = ();
    my $id = 0;
    OR_NODE: for ( ;; ) {
	my $origin = $recce_c->or_node_origin( $id );
	my $set = $recce_c->or_node_set( $id );
	my $rule = $recce_c->or_node_rule( $id );
	my $position = $recce_c->or_node_position( $id );
	$id++;
        last OR_NODE if not defined $origin;
        my $origin_earleme  = $recce_c->earleme($origin);
        my $current_earleme = $recce_c->earleme($set);
        my $desc =
              'R'
            . $rule . q{:}
            . $position . q{@}
            . $origin_earleme . q{-}
            . $current_earleme;
        push @data,
            [ $origin_earleme, $current_earleme, $rule, $position, $desc ];
    } ## end for ( ;; )
    my @sorted_data = map { $_->[-1] } sort {
        $a->[0] <=> $b->[0]
	or $a->[1] <=> $b->[1]
	or $a->[2] <=> $b->[2]
	or $a->[3] <=> $b->[3]
    } @data;
    return (join "\n", @sorted_data) . "\n";;
}

# Not tested and not in test suite.
sub Marpa::XS::brief_iteration_node {
    my ($recce, $iteration_node) = @_;
    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];

    my $or_node_id =
        $iteration_node->[Marpa::XS::Internal::Iteration_Node::OR_NODE_ID];
    my $text         = "o$or_node_id";
    DESCRIBE_CHOICES: {
        my $choice =
            $iteration_node->[Marpa::XS::Internal::Iteration_Node::CHOICE];
        if ( not defined $choice ) {
            $text .= ' Choices not initialized';
            last DESCRIBE_CHOICES;
        }
        my $and_node_id = $recce_c->and_node_order_get($or_node_id, $choice);
        if ( defined $choice ) {
            $text .= " [$choice] == a" . $and_node_id;
            last DESCRIBE_CHOICES;
        } ## end if ( defined $choice )
        $text .= "o$or_node_id has no choices left";
    } ## end DESCRIBE_CHOICES:
    my $parent_ix = $iteration_node->[Marpa::XS::Internal::Iteration_Node::PARENT];
    $parent_ix = q{-} if $parent_ix < 0;
    return "$text; p=$parent_ix";
} ## end sub Marpa::XS::brief_iteration_node

sub Marpa::XS::show_rank_ref {
    my ($rank_ref) = @_;
    return 'undef' if not defined $rank_ref;
    return 'SKIP'  if $rank_ref == Marpa::XS::Internal::Value::SKIP;
    return ${$rank_ref};
} ## end sub Marpa::XS::show_rank_ref

# Never tested and not in test suite.
sub Marpa::XS::Recognizer::show_iteration_node {
    my ( $recce, $iteration_node, $verbose ) = @_;
    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];

    my $or_node_id =
        $iteration_node->[Marpa::XS::Internal::Iteration_Node::OR_NODE_ID];
    my $or_node_tag = Marpa::XS::Recognizer::or_node_tag($recce, $or_node_id);
    my $text        = "o$or_node_id $or_node_tag; ";
    CHILD_TYPE: {
        if ( $iteration_node
            ->[Marpa::XS::Internal::Iteration_Node::IS_CAUSE_OF_PARENT] )
        {
            $text .= 'cause ';
            last CHILD_TYPE;
        } ## end if ( $iteration_node->[...])
        if ( $iteration_node
            ->[Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_OF_PARENT]
            )
        {
            $text .= 'predecessor ';
            last CHILD_TYPE;
        } ## end if ( $iteration_node->[...])
        $text .= '- ';
    } ## end CHILD_TYPE:

    my $parent_ix = $iteration_node->[Marpa::XS::Internal::Iteration_Node::PARENT];
    if ( $iteration_node->[Marpa::XS::Internal::Iteration_Node::HAS_PREDECESSOR] ) {
        $text .= 'p=';
        $text
            .= $iteration_node
            ->[Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_READY]
            ? 'ok'
            : q{-};
    } ## end if ( $iteration_node->[...])
    if ( $iteration_node->[Marpa::XS::Internal::Iteration_Node::HAS_CAUSE] ) {
        $text .= '; c=';
        $text
            .= $iteration_node
            ->[Marpa::XS::Internal::Iteration_Node::IS_CAUSE_READY]
            ? 'ok'
            : q{-};
    } ## end if ( $iteration_node->[...])
    $text .= q{;p=} . ( $parent_ix >= 0 ? $parent_ix : q{-} )
        . "\n";

    DESCRIBE_CHOICES: {
        my $this_choice =
            $iteration_node->[Marpa::XS::Internal::Iteration_Node::CHOICE];
	$text .= " Current Choice is " . (defined $this_choice ? "a$this_choice" : 'uninitialized');
	my $choice_ix = 0;
	CHOICE: while (1) {
	    my $and_node_id = $recce_c->and_node_order_get($or_node_id, $choice_ix);
	    last CHOICE if not defined $and_node_id;
            $text .= " o$or_node_id" . '[' . $choice_ix . '] ';
            my $and_node_tag =
		 Marpa::XS::Recognizer::and_node_tag($recce, $and_node_id);
            $text .= " ::= a$and_node_id $and_node_tag";
            $text .= "\n";
        } ## end for my $choice_ix ( 0 .. $#{$choices} )
    } ## end DESCRIBE_CHOICES:
    return $text;
} ## end sub Marpa::XS::Recognizer::show_iteration_node

sub Marpa::XS::Recognizer::show_iteration_stack {
    my ( $recce, $verbose ) = @_;
    my $iteration_stack =
        $recce->[Marpa::XS::Internal::Recognizer::ITERATION_STACK];
    my $text = q{};
    for my $ix ( 0 .. $#{$iteration_stack} ) {
        my $iteration_node = $iteration_stack->[$ix];
        $text .= "$ix: "
            . $recce->show_iteration_node( $iteration_node, $verbose );
    }
    return $text;
} ## end sub Marpa::XS::Recognizer::show_iteration_stack

package Marpa::XS::Internal::Recognizer;
our $DEFAULT_ACTION_VALUE = \undef;

package Marpa::XS::Internal::Value;

sub Marpa::XS::Internal::Recognizer::set_null_values {
    my ($recce) = @_;
    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $grammar_c   = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $trace_values =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_VALUES];

    my $rules   = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $default_null_value =
        $grammar->[Marpa::XS::Internal::Grammar::DEFAULT_NULL_VALUE];

    my $null_values;
    $#{$null_values} = $#{$symbols};

    SYMBOL: for my $symbol ( @{$symbols} ) {

        my $symbol_id = $symbol->[Marpa::XS::Internal::Symbol::ID];

        next SYMBOL if not $grammar_c->symbol_is_nulling( $symbol_id );

        my $null_value = undef;
        if ( $symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE] ) {
            $null_value =
                ${ $symbol->[Marpa::XS::Internal::Symbol::NULL_VALUE] };
        }
        else {
            $null_value = $default_null_value;
        }
        next SYMBOL if not defined $null_value;

        $null_values->[$symbol_id] = $null_value;

        if ($trace_values) {
            print {$Marpa::XS::Internal::TRACE_FH}
                'Setting null value for symbol ',
                $symbol->[Marpa::XS::Internal::Symbol::NAME],
                ' to ', Data::Dumper->new( [ \$null_value ] )->Terse(1)->Dump
                or Marpa::exception('Could not print to trace file');
        } ## end if ($trace_values)

    } ## end for my $symbol ( @{$symbols} )

    return $null_values;

}    # set_null_values

# Given the grammar and an action name, resolve it to a closure,
# or return undef
sub Marpa::XS::Internal::Recognizer::resolve_semantics {
    my ( $recce, $closure_name ) = @_;
    my $grammar  = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $closures = $recce->[Marpa::XS::Internal::Recognizer::CLOSURES];
    my $trace_actions =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_ACTIONS];

    Marpa::exception(q{Trying to resolve 'undef' as closure name})
        if not defined $closure_name;

    if ( my $closure = $closures->{$closure_name} ) {
        if ($trace_actions) {
            print {$Marpa::XS::Internal::TRACE_FH}
                qq{Resolved "$closure_name" to explicit closure\n}
                or Marpa::exception('Could not print to trace file');
        }

        return $closure;
    } ## end if ( my $closure = $closures->{$closure_name} )

    my $fully_qualified_name;
    DETERMINE_FULLY_QUALIFIED_NAME: {
        if ( $closure_name =~ /([:][:])|[']/xms ) {
            $fully_qualified_name = $closure_name;
            last DETERMINE_FULLY_QUALIFIED_NAME;
        }
        if (defined(
                my $actions_package =
                    $grammar->[Marpa::XS::Internal::Grammar::ACTIONS]
            )
            )
        {
            $fully_qualified_name = $actions_package . q{::} . $closure_name;
            last DETERMINE_FULLY_QUALIFIED_NAME;
        } ## end if ( defined( my $actions_package = $grammar->[...]))

        if (defined(
                my $action_object_class =
                    $grammar->[Marpa::XS::Internal::Grammar::ACTION_OBJECT]
            )
            )
        {
            $fully_qualified_name =
                $action_object_class . q{::} . $closure_name;
        } ## end if ( defined( my $action_object_class = $grammar->[...]))
    } ## end DETERMINE_FULLY_QUALIFIED_NAME:

    return if not defined $fully_qualified_name;

    no strict 'refs';
    my $closure = *{$fully_qualified_name}{'CODE'};
    use strict 'refs';

    if ($trace_actions) {
        print {$Marpa::XS::Internal::TRACE_FH}
            ( $closure ? 'Successful' : 'Failed' )
            . qq{ resolution of "$closure_name" },
            'to ', $fully_qualified_name, "\n"
            or Marpa::exception('Could not print to trace file');
    } ## end if ($trace_actions)

    return $closure;

} ## end sub Marpa::XS::Internal::Recognizer::resolve_semantics

sub Marpa::XS::Internal::Recognizer::set_actions {
    my ($recce)   = @_;
    my $grammar   = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $rules     = $grammar->[Marpa::XS::Internal::Grammar::RULES];
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $default_action =
        $grammar->[Marpa::XS::Internal::Grammar::DEFAULT_ACTION];

    my $evaluator_rules = [];

    my $default_action_closure;
    if ( defined $default_action ) {
        $default_action_closure =
            Marpa::XS::Internal::Recognizer::resolve_semantics( $recce,
            $default_action );
        Marpa::exception(
            "Could not resolve default action named '$default_action'")
            if not $default_action_closure;
    } ## end if ( defined $default_action )

    RULE: for my $rule ( @{$rules} ) {

        my $rule_id = $rule->[Marpa::XS::Internal::Rule::ID];
        next RULE if not $grammar_c->rule_is_used($rule_id);

        my $ops = $evaluator_rules->[$rule_id] = [];

        my $virtual_rhs = $grammar_c->rule_is_virtual_rhs($rule_id);
        my $virtual_lhs = $grammar_c->rule_is_virtual_lhs($rule_id);

        if ($virtual_lhs) {
            push @{$ops},
                (
                $virtual_rhs
                ? Marpa::XS::Internal::Op::VIRTUAL_KERNEL
                : Marpa::XS::Internal::Op::VIRTUAL_TAIL
                ),
                $grammar_c->real_symbol_count($rule_id);
            next RULE;
        } ## end if ($virtual_lhs)

        # If we are here the LHS is real, not virtual

        if ($virtual_rhs) {
            push @{$ops},
                (
                $grammar_c->rule_is_discard_separation($rule_id)
                ? Marpa::XS::Internal::Op::VIRTUAL_HEAD_NO_SEP
                : Marpa::XS::Internal::Op::VIRTUAL_HEAD
                ),
                $grammar_c->real_symbol_count($rule_id);
        } ## end if ($virtual_rhs)
            # assignment instead of comparison is deliberate
        elsif ( my $argc = $grammar_c->rule_length($rule_id) ) {
            push @{$ops}, Marpa::XS::Internal::Op::ARGC, $argc;
        }

        if ( my $action = $rule->[Marpa::XS::Internal::Rule::ACTION] ) {
            my $closure =
                Marpa::XS::Internal::Recognizer::resolve_semantics( $recce,
                $action );

            Marpa::exception(qq{Could not resolve action name: "$action"})
                if not defined $closure;
            push @{$ops}, Marpa::XS::Internal::Op::CALL, $closure;
            next RULE;
        } ## end if ( my $action = $rule->[Marpa::XS::Internal::Rule::ACTION...])

        # Try to resolve the LHS as a closure name,
        # if it is not internal.
        # If we can't resolve
        # the LHS as a closure name, it's not
        # a fatal error.
	FIND_CLOSURE_BY_LHS: {
	    my $lhs_id = $grammar_c->rule_lhs($rule_id);
	    my $action = $symbols->[$lhs_id]->[Marpa::XS::Internal::Symbol::NAME];
	    last FIND_CLOSURE_BY_LHS if substr($action, -1) eq ']';
	    my $closure =
		Marpa::XS::Internal::Recognizer::resolve_semantics( $recce,
		$action );
	    last FIND_CLOSURE_BY_LHS if not defined $closure;
	    push @{$ops}, Marpa::XS::Internal::Op::CALL, $closure;
	    next RULE;
	} ## end FIND_CLOSURE_BY_LHS:

        if ( defined $default_action_closure ) {
            push @{$ops}, Marpa::XS::Internal::Op::CALL,
                $default_action_closure;
            next RULE;
        }

        # If there is no default action specified, the fallback
        # is to return an undef
        push @{$ops}, Marpa::XS::Internal::Op::CONSTANT_RESULT,
            $Marpa::XS::Internal::Recognizer::DEFAULT_ACTION_VALUE;

    } ## end for my $rule ( @{$rules} )

    return $evaluator_rules;

}    # set_actions

# Sub-optimal.
# This routine should be written to do a depth-first traversal.

# Returns false if no parse
sub do_rank_all {
    my ( $recce, $depth_by_id ) = @_;
    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $grammar = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my @and_node_rank_refs;
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols   = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $rules     = $grammar->[Marpa::XS::Internal::Grammar::RULES];

    my @or_node_rank = ();
    my @and_node_token_rank_ref = ();

    my $cycle_ranking_action =
        $grammar->[Marpa::XS::Internal::Grammar::CYCLE_RANKING_ACTION];
    my $cycle_closure;
    if ( defined $cycle_ranking_action ) {
        $cycle_closure =
            Marpa::XS::Internal::Recognizer::resolve_semantics( $recce,
            $cycle_ranking_action );
        Marpa::exception(
            "Could not resolve cycle ranking action named '$cycle_ranking_action'"
        ) if not $cycle_closure;
    } ## end if ( defined $cycle_ranking_action )

    # Set up rank closures by symbol
    my %ranking_closures_by_symbol = ();
    SYMBOL: for my $symbol ( @{$symbols} ) {
        my $ranking_action =
            $symbol->[Marpa::XS::Internal::Symbol::RANKING_ACTION];
        next SYMBOL if not defined $ranking_action;
        my $ranking_closure =
            Marpa::XS::Internal::Recognizer::resolve_semantics( $recce,
            $ranking_action );
        my $symbol_name = $symbol->[Marpa::XS::Internal::Symbol::NAME];
        Marpa::exception(
            "Could not resolve ranking action for symbol.\n",
            qq{    Symbol was "$symbol_name".},
            qq{    Ranking action was "$ranking_action".}
        ) if not defined $ranking_closure;
        $ranking_closures_by_symbol{$symbol_name} = $ranking_closure;
    }    # end for my $symbol ( @{$symbols} )

    # Get closure used in ranking, by rule
    my @ranking_closures_by_rule = ();
    RULE: for my $rule ( @{$rules} ) {

        my $ranking_action =
            $rule->[Marpa::XS::Internal::Rule::RANKING_ACTION];
	my $rule_id = $rule->[Marpa::XS::Internal::Rule::ID];
        my $cycle_rule = $grammar_c->rule_is_loop($rule_id);

        Marpa::exception(
            "Rule which cycles has an explicit ranking action\n",
            qq{   The ranking action is "$ranking_action"\n},
            qq{   To solve this problem,\n},
            qq{   Rewrite the grammar so that this rule does not cycle\n},
            qq{   Or eliminate its ranking action.\n}
        ) if $ranking_action and $cycle_rule;

        my $ranking_closure;
        if ($ranking_action) {
            $ranking_closure =
                Marpa::XS::Internal::Recognizer::resolve_semantics( $recce,
                $ranking_action );
            Marpa::exception(
                "Ranking closure '$ranking_action' not found")
                if not defined $ranking_closure;
        } ## end if ($ranking_action)

        if ($cycle_rule) {
            $ranking_closure = $cycle_closure;
        }

        next RULE if not $ranking_closure;

	# If the RHS is empty ...
	# Empty rules are never in cycles -- they are either
	# unused (because of the CHAF rewrite) or the special
	# null start rule.
	if ( $grammar_c->rule_length($rule_id) == 0 ) {
	    Marpa::exception("Ranking closure '$ranking_action' not found")
		if not defined $ranking_closure;

	    my $lhs_id = $grammar_c->rule_lhs($rule_id);
	    my $lhs_null_alias =
		$symbols->[ $grammar_c->symbol_null_alias($lhs_id) ];
	    $ranking_closures_by_symbol{ $lhs_null_alias
		    ->[Marpa::XS::Internal::Symbol::NAME] } = $ranking_closure;
	} ## end if ( $grammar_c->rule_length($rule_id) == 0 )

        next RULE if not $grammar_c->rule_is_used($rule_id);

        $ranking_closures_by_rule[$rule_id] = $ranking_closure;

    } ## end for my $rule ( @{$rules} )

    my @and_node_worklist = ();
    AND_NODE: for my $and_node_id ( 0 .. $recce_c->and_node_count()-1 ) {

	my $parent_or_node_id = $recce_c->and_node_parent($and_node_id);
        my $rule_id  = $recce_c->or_node_rule($parent_or_node_id);
        my $rule_closure = $ranking_closures_by_rule[$rule_id];
        my $token_id = $recce_c->and_node_symbol($and_node_id);
        my $token_closure;
        if ($token_id) {
            my $token_name =
                $symbols->[$token_id]->[Marpa::XS::Internal::Symbol::NAME];
            $token_closure = $ranking_closures_by_symbol{$token_name};
        }

        my $token_rank_ref;
        my $rule_rank_ref;

        # It is a feature of the ranking closures that they are always
        # called once per instance, even if the result is never used.
        # This sometimes makes for unnecessary calls,
        # but it makes these closures predictable enough
        # to allow their use for side effects.
        EVALUATION:
        for my $evaluation_data (
            [ \$token_rank_ref, $token_closure ],
            [ \$rule_rank_ref,  $rule_closure ]
            )
        {
            my ( $rank_ref_ref, $closure ) = @{$evaluation_data};
            next EVALUATION if not defined $closure;

            my @warnings;
            my $eval_ok;
            my $rank_ref;
            DO_EVAL: {
                local $Marpa::XS::Internal::CONTEXT =
                    [ 'and-node', $and_node_id, $recce ];
                local $SIG{__WARN__} =
                    sub { push @warnings, [ $_[0], ( caller 0 ) ]; };
                $eval_ok = eval { $rank_ref = $closure->(); 1; };
            } ## end DO_EVAL:

            my $fatal_error;
            CHECK_FOR_ERROR: {
                if ( not $eval_ok or scalar @warnings ) {
                    $fatal_error = $EVAL_ERROR // 'Fatal Error';
                    last CHECK_FOR_ERROR;
                }
                if ( defined $rank_ref and not ref $rank_ref ) {
                    $fatal_error =
                        "Invalid return value from ranking closure: $rank_ref";
                }
            } ## end CHECK_FOR_ERROR:

            if ( defined $fatal_error ) {

                Marpa::XS::Internal::code_problems(
                    {   fatal_error => $fatal_error,
                        grammar     => $grammar,
                        eval_ok     => $eval_ok,
                        warnings    => \@warnings,
                        where       => 'ranking and-node '
                            . Marpa::XS::Recognizer::and_node_tag(
                            $recce, $and_node_id
                            )
                    }
                );
            } ## end if ( defined $fatal_error )

            ${$rank_ref_ref} = $rank_ref // Marpa::XS::Internal::Value::SKIP;

        } ## end for my $evaluation_data ( [ \$token_rank_ref, $token_closure...])

        # Set the token rank if there is a token.
        # It is zero if there is no token, or
        # if there is one with no closure.
        # Note: token can never cause a cycle, but they
        # can cause an and-node to be skipped.
        if (defined $token_id) {
            $and_node_token_rank_ref[$and_node_id] =
                $token_rank_ref // \0;
        }

        # See if we can set the rank for this node to a constant.
        my $constant_rank_ref;
        SET_CONSTANT_RANK: {

            if ( defined $token_rank_ref && !ref $token_rank_ref ) {
                $constant_rank_ref = Marpa::XS::Internal::Value::SKIP;
                last SET_CONSTANT_RANK;
            }

            # If we have ranking closure for this rule, the rank
            # is constant:
            # 0 for a non-final node,
            # the result of the closure for a final one
            if ( defined $rule_rank_ref ) {
                $constant_rank_ref =
                    (
                    $recce_c->or_node_position($parent_or_node_id)
                        == $grammar_c->rule_length(
                        $recce_c->or_node_rule($parent_or_node_id)
                        )
                    )
                    ? $rule_rank_ref
                    : \0;
                last SET_CONSTANT_RANK;
            } ## end if ( defined $rule_rank_ref )

            # It there is a token and no predecessor, the rank
            # of this rule is a constant:
            # 0 is there was not token symbol closure
            # the result of that closure if there was one
            if ( defined $token_id
                and not defined $recce_c->and_node_predecessor($and_node_id) )
            {
                $constant_rank_ref = $token_rank_ref // \0;
            }

        } ## end SET_CONSTANT_RANK:

        if ( defined $constant_rank_ref ) {
            $and_node_rank_refs[$and_node_id] =
                $constant_rank_ref;

            next AND_NODE;
        } ## end if ( defined $constant_rank_ref )

        # If we are here there is (so far) no constant rank
        # so we stack this and-node for depth-sensitive evaluation
        push @and_node_worklist, $and_node_id;

    } ## end for my $and_node_id ( 0 .. $#{$and_nodes} )

    # From here on we may be calculating ranks, so use floating point
    no integer;

    # Now go through the and-nodes that require context to be ranked
    # This loop assumes that all cycles has been taken care of
    # with constant ranks
    AND_NODE: while ( defined( my $and_node_id = pop @and_node_worklist ) ) {

        # Go to next if we have already ranked this and-node
        next AND_NODE if defined $and_node_rank_refs[$and_node_id];

        # The rank calculated so far from the
        # children
        my $calculated_rank = 0;

        my $is_cycle = 0;
        my $is_skip  = 0;
        OR_NODE:
        for my $or_node_id (
	    grep { defined }
            $recce_c->and_node_predecessor($and_node_id),
            $recce_c->and_node_cause($and_node_id),
            )
        {
            if (defined(
                    my $or_node_initial_rank_ref =
                        $or_node_rank[$or_node_id]
                )
                )
            {
                if ( ref $or_node_initial_rank_ref ) {
                    $calculated_rank += ${$or_node_initial_rank_ref};
                    next OR_NODE;
                }

                # At this point only possible value is skip
                $and_node_rank_refs[$and_node_id] =
                    Marpa::XS::Internal::Value::SKIP;

                next AND_NODE;
            } ## end if ( defined( my $or_node_initial_rank_ref = $or_node...))
            my @ranks              = ();
            my @unranked_and_nodes = ();
	    my @and_node_ids =
		( $recce_c->or_node_first_and($or_node_id)
		    .. $recce_c->or_node_last_and($or_node_id) );
            CHILD_AND_NODE:
            for my $child_and_node_id ( @and_node_ids ) {
                my $rank_ref = $and_node_rank_refs[$child_and_node_id];
                if ( not defined $rank_ref ) {
                    push @unranked_and_nodes, $child_and_node_id;

                    next CHILD_AND_NODE;
                } ## end if ( not defined $rank_ref )

                # Right now the only defined scalar value for a rank is
                # Marpa::XS::Internal::Value::SKIP
                next CHILD_AND_NODE if not ref $rank_ref;

                push @ranks, ${$rank_ref};

            } ## end for my $child_and_node_id ( @{ $or_node->[...]})

            # If we have unranked child and nodes, those have to be
            # ranked first.  Schedule the work and move on.
            if ( scalar @unranked_and_nodes ) {

                push @and_node_worklist, $and_node_id, @unranked_and_nodes;
                next AND_NODE;
            }

            # If there were no non-skipped and-nodes, the
            # parent and-node must also be skipped
            if ( not scalar @ranks ) {
                $or_node_rank[$or_node_id] =
                    $and_node_rank_refs[$and_node_id] =
                    Marpa::XS::Internal::Value::SKIP;

                next AND_NODE;
            } ## end if ( not scalar @ranks )

            my $or_calculated_rank = List::Util::max @ranks;
	    $or_node_rank[$or_node_id] = \$or_calculated_rank;
            $calculated_rank += $or_calculated_rank;

        } ## end for my $field ( ...)

        my $token_rank_ref = $and_node_token_rank_ref[$and_node_id];
        $calculated_rank += defined $token_rank_ref ? ${$token_rank_ref} : 0;
	$and_node_rank_refs[$and_node_id] = \$calculated_rank;

    } ## end while ( defined( my $and_node_id = pop @and_node_worklist...))

    my @or_node_choices = ();
    AND_NODE: for my $and_node_id (0 .. $#and_node_rank_refs) {
	my $rank_ref = $and_node_rank_refs[$and_node_id];
	next AND_NODE if $rank_ref == Marpa::XS::Internal::Value::SKIP;
	my $or_node_id = $recce_c->and_node_parent($and_node_id);
	push @{$or_node_choices[$or_node_id]}, [ ${$rank_ref}, $and_node_id ];
    }

    OR_NODE: for my $or_node_id (0 .. $#or_node_choices) {
	my $choices = $or_node_choices[$or_node_id] // [];
	# Sort is in reverse order
        my @and_node_ids = map { $_->[-1] } sort { $b->[0] <=> $a->[0] } @{$choices};
	$recce_c->and_node_order_set($or_node_id, \@and_node_ids);
    } ## end for my $or_node_id ( 0 .. $recce_c->or_node_count() -...)

    return;

} ## end sub do_rank_all

# Does not modify stack
sub Marpa::XS::Internal::Recognizer::evaluate {
    my ( $recce, $iteration_stack ) = @_;
    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];
    my $null_values = $recce->[Marpa::XS::Internal::Recognizer::NULL_VALUES];
    my $token_values = $recce->[Marpa::XS::Internal::Recognizer::TOKEN_VALUES];
    my $evaluator_rules =
        $recce->[Marpa::XS::Internal::Recognizer::EVALUATOR_RULES];
    my $grammar      = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $grammar_c = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $trace_values = $recce->[Marpa::XS::Internal::Recognizer::TRACE_VALUES]
        // 0;

    my $action_object_class =
        $grammar->[Marpa::XS::Internal::Grammar::ACTION_OBJECT];

    my $action_object_constructor;
    if ( defined $action_object_class ) {
        my $constructor_name = $action_object_class . q{::new};
        my $closure =
            Marpa::XS::Internal::Recognizer::resolve_semantics( $recce,
            $constructor_name );
        Marpa::exception(
            qq{Could not find constructor "$constructor_name"})
            if not defined $closure;
        $action_object_constructor = $closure;
    } ## end if ( defined $action_object_class )

    my $action_object;
    if ($action_object_constructor) {
        my @warnings;
        my $eval_ok;
        my $fatal_error;
        DO_EVAL: {
            local $EVAL_ERROR = undef;
            local $SIG{__WARN__} = sub {
                push @warnings, [ $_[0], ( caller 0 ) ];
            };

            $eval_ok = eval {
                $action_object =
                    $action_object_constructor->($action_object_class);
                1;
            };
            $fatal_error = $EVAL_ERROR;
        } ## end DO_EVAL:

        if ( not $eval_ok or @warnings ) {
            Marpa::XS::Internal::code_problems(
                {   fatal_error => $fatal_error,
                    grammar     => $grammar,
                    eval_ok     => $eval_ok,
                    warnings    => \@warnings,
                    where       => 'constructing action object',
                }
            );
        } ## end if ( not $eval_ok or @warnings )
    } ## end if ($action_object_constructor)

    $action_object //= {};

    my @evaluation_stack   = ();
    my @virtual_rule_stack = ();
    TREE_NODE: for my $iteration_node (reverse @{$iteration_stack}) {

	my $parent_or_node_id = $iteration_node->[Marpa::XS::Internal::Iteration_Node::OR_NODE_ID];
	my $choice = $iteration_node->[Marpa::XS::Internal::Iteration_Node::CHOICE];
        my $and_node_id = $recce_c->and_node_order_get($parent_or_node_id, $choice);

        if ( $trace_values >= 3 ) {
            for my $i ( reverse 0 .. $#evaluation_stack ) {
                printf {$Marpa::XS::Internal::TRACE_FH} 'Stack position %3d:',
                    $i
                    or Marpa::exception('print to trace handle failed');
                print {$Marpa::XS::Internal::TRACE_FH} q{ },
                    Data::Dumper->new( [ $evaluation_stack[$i] ] )->Terse(1)
                    ->Dump
                    or Marpa::exception('print to trace handle failed');
            } ## end for my $i ( reverse 0 .. $#evaluation_stack )
        } ## end if ( $trace_values >= 3 )

	my $value_ref;
	SET_VALUE_REF: {
	    my $token_id = $recce_c->and_node_symbol($and_node_id);
	    last SET_VALUE_REF if not defined $token_id;
	    my $token_name =
		$symbols->[$token_id]->[Marpa::XS::Internal::Symbol::NAME];
	    if ( $grammar_c->symbol_is_nulling($token_id) ) {
		$value_ref = \$null_values->[$token_id];
		last SET_VALUE_REF;
	    }
	    my $current_earley_set = $recce_c->or_node_set($parent_or_node_id);
	    my $end_earleme = $recce_c->earleme($current_earley_set);
	    my $origin = $recce_c->or_node_origin($parent_or_node_id);
	    my $origin_earleme = $recce_c->earleme($origin);
	    my $predecessor = $recce_c->and_node_predecessor($and_node_id);
	    my $middle_earleme = $origin_earleme;
	    if (defined $predecessor) {
	        my $predecessor_set = $recce_c->or_node_set($predecessor);
		$middle_earleme = $recce_c->earleme($predecessor_set);
	    }
	    my $value_key = join q{;}, $middle_earleme, ($end_earleme-$middle_earleme), $token_name;
	    last SET_VALUE_REF if not exists $token_values->{$value_key};
	    $value_ref = \($token_values->{$value_key});
	}

        if ( defined $value_ref ) {

            push @evaluation_stack, $value_ref;

            if ($trace_values) {
                my $token_name;
		my $token_id = $recce_c->and_node_symbol($and_node_id);
		if  (defined $token_id) {
		     $token_name = $symbols->[$token_id]->[Marpa::XS::Internal::Symbol::NAME];
		}

                print {$Marpa::XS::Internal::TRACE_FH}
                    'Pushed value from ',
		    Marpa::XS::Recognizer::and_node_tag($recce, $and_node_id),
                    ': ',
                    ( $token_name ? qq{$token_name = } : q{} ),
                    Data::Dumper->new( [$value_ref] )->Terse(1)->Dump
                    or Marpa::exception('print to trace handle failed');
            } ## end if ($trace_values)

        }    # defined $value_ref

	my $ops;
	{
	    my $rule_id = $recce_c->or_node_rule($parent_or_node_id);
	    if ( $recce_c->or_node_position($parent_or_node_id)
		== $grammar_c->rule_length($rule_id) )
	    {
		$ops = $evaluator_rules->[$rule_id];
	    }
	}

        next TREE_NODE if not defined $ops;

        my $current_data = [];
        my $op_ix        = 0;
        while ( $op_ix < scalar @{$ops} ) {
            given ( $ops->[ $op_ix++ ] ) {

                when (Marpa::XS::Internal::Op::ARGC) {

                    my $argc = $ops->[ $op_ix++ ];

                    if ($trace_values) {
			my $rule_id = $recce_c->or_node_rule($parent_or_node_id);
                        say {$Marpa::XS::Internal::TRACE_FH}
                            'Popping ',
                            $argc,
                            ' values to evaluate ',
			     Marpa::XS::Recognizer::and_node_tag($recce, $and_node_id),
                            ', rule: ', $grammar->brief_rule($rule_id)
                            or Marpa::exception(
                            'Could not print to trace file');
                    } ## end if ($trace_values)

                    $current_data =
                        [ map { ${$_} }
                            ( splice @evaluation_stack, -$argc ) ];

                } ## end when (Marpa::XS::Internal::Op::ARGC)

                when (Marpa::XS::Internal::Op::VIRTUAL_HEAD) {
                    my $real_symbol_count = $ops->[ $op_ix++ ];

                    if ($trace_values) {
			my $rule_id = $recce_c->or_node_rule($parent_or_node_id);
                        say {$Marpa::XS::Internal::TRACE_FH}
                            'Head of Virtual Rule: ',
			     Marpa::XS::Recognizer::and_node_tag($recce, $and_node_id),
                            ', rule: ', $grammar->brief_rule($rule_id),
                            "\n",
                            "Incrementing virtual rule by $real_symbol_count symbols\n",
                            'Currently ',
                            ( scalar @virtual_rule_stack ),
                            ' rules; ', $virtual_rule_stack[-1], ' symbols;',
                            or Marpa::exception(
                            'Could not print to trace file');
                    } ## end if ($trace_values)

                    $real_symbol_count += pop @virtual_rule_stack;
                    $current_data =
                        [ map { ${$_} }
                            ( splice @evaluation_stack, -$real_symbol_count )
                        ];

                } ## end when (Marpa::XS::Internal::Op::VIRTUAL_HEAD)

                when (Marpa::XS::Internal::Op::VIRTUAL_HEAD_NO_SEP) {
                    my $real_symbol_count = $ops->[ $op_ix++ ];

                    if ($trace_values) {
			my $rule_id = $recce_c->or_node_rule($parent_or_node_id);
                        say {$Marpa::XS::Internal::TRACE_FH}
                            'Head of Virtual Rule (discards separation): ',
			    Marpa::XS::Recognizer::and_node_tag($recce, $and_node_id),
                            ', rule: ', $grammar->brief_rule($rule_id),
                            "\nAdding $real_symbol_count symbols; currently ",
                            ( scalar @virtual_rule_stack ),
                            ' rules; ', $virtual_rule_stack[-1], ' symbols'
                            or Marpa::exception(
                            'Could not print to trace file');
                    } ## end if ($trace_values)

                    $real_symbol_count += pop @virtual_rule_stack;
                    my $base =
                        ( scalar @evaluation_stack ) - $real_symbol_count;
                    $current_data = [
                        map { ${$_} } @evaluation_stack[
                            map { $base + 2 * $_ }
                            ( 0 .. ( $real_symbol_count + 1 ) / 2 - 1 )
                        ]
                    ];

                    # truncate the evaluation stack
                    $#evaluation_stack = $base - 1;

                } ## end when (Marpa::XS::Internal::Op::VIRTUAL_HEAD_NO_SEP)

                when (Marpa::XS::Internal::Op::VIRTUAL_KERNEL) {
                    my $real_symbol_count = $ops->[ $op_ix++ ];
                    $virtual_rule_stack[-1] += $real_symbol_count;

                    if ($trace_values) {
			my $rule_id = $recce_c->or_node_rule($parent_or_node_id);
                        say {$Marpa::XS::Internal::TRACE_FH}
                            'Virtual Rule: ',
			     Marpa::XS::Recognizer::and_node_tag($recce, $and_node_id),
                            ', rule: ', $grammar->brief_rule($rule_id),
                            "\nAdding $real_symbol_count, now ",
                            ( scalar @virtual_rule_stack ),
                            ' rules; ', $virtual_rule_stack[-1], ' symbols'
                            or Marpa::exception(
                            'Could not print to trace file');
                    } ## end if ($trace_values)

                } ## end when (Marpa::XS::Internal::Op::VIRTUAL_KERNEL)

                when (Marpa::XS::Internal::Op::VIRTUAL_TAIL) {
                    my $real_symbol_count = $ops->[ $op_ix++ ];

                    if ($trace_values) {
			my $rule_id = $recce_c->or_node_rule($parent_or_node_id);
                        say {$Marpa::XS::Internal::TRACE_FH}
                            'New Virtual Rule: ',
			     Marpa::XS::Recognizer::and_node_tag($recce, $and_node_id),
                            ', rule: ', $grammar->brief_rule($rule_id),
                            "\nSymbol count is $real_symbol_count, now ",
                            ( scalar @virtual_rule_stack + 1 ), ' rules',
                            or Marpa::exception(
                            'Could not print to trace file');
                    } ## end if ($trace_values)

                    push @virtual_rule_stack, $real_symbol_count;

                } ## end when (Marpa::XS::Internal::Op::VIRTUAL_TAIL)

                when (Marpa::XS::Internal::Op::CONSTANT_RESULT) {
                    my $result = $ops->[ $op_ix++ ];
                    if ($trace_values) {
                        print {$Marpa::XS::Internal::TRACE_FH}
                            'Constant result: ',
                            'Pushing 1 value on stack: ',
                            Data::Dumper->new( [$result] )->Terse(1)->Dump
                            or Marpa::exception(
                            'Could not print to trace file');
                    } ## end if ($trace_values)
                    push @evaluation_stack, $result;
                } ## end when (Marpa::XS::Internal::Op::CONSTANT_RESULT)

                when (Marpa::XS::Internal::Op::CALL) {
                    my $closure = $ops->[ $op_ix++ ];
                    my $result;

                    my @warnings;
                    my $eval_ok;
                    DO_EVAL: {
                        local $SIG{__WARN__} = sub {
                            push @warnings, [ $_[0], ( caller 0 ) ];
                        };

                        $eval_ok = eval {
                            $result =
                                $closure->( $action_object,
                                @{$current_data} );
                            1;
                        };

                    } ## end DO_EVAL:

                    if ( not $eval_ok or @warnings ) {
			my $rule_id = $recce_c->or_node_rule($parent_or_node_id);
                        my $fatal_error = $EVAL_ERROR;
                        Marpa::XS::Internal::code_problems(
                            {   fatal_error => $fatal_error,
                                grammar     => $grammar,
                                eval_ok     => $eval_ok,
                                warnings    => \@warnings,
                                where       => 'computing value',
                                long_where  => 'Computing value for rule: '
                                    . $grammar->brief_rule($rule_id),
                            }
                        );
                    } ## end if ( not $eval_ok or @warnings )

                    if ($trace_values) {
                        print {$Marpa::XS::Internal::TRACE_FH}
                            'Calculated and pushed value: ',
                            Data::Dumper->new( [$result] )->Terse(1)->Dump
                            or Marpa::exception(
                            'print to trace handle failed');
                    } ## end if ($trace_values)

                    push @evaluation_stack, \$result;

                } ## end when (Marpa::XS::Internal::Op::CALL)

                default {
                    Marpa::XS::Exception("Unknown evaluator Op: $_");
                }

            } ## end given
        } ## end while ( $op_ix < scalar @{$ops} )

    }    # TREE_NODE

    return pop @evaluation_stack;
} ## end sub Marpa::XS::Internal::Recognizer::evaluate

# null parse is special case
sub Marpa::XS::Internal::Recognizer::do_null_parse {
    my ( $recce ) = @_;
    my $grammar     = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $grammar_c     = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols     = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $rules     = $grammar->[Marpa::XS::Internal::Grammar::RULES];

    # The nulling start rule is the only nulling rule that is used
    my $start_rule_id;
    RULE: for my $rule (@{$rules}) {
	$start_rule_id = $rule->[Marpa::XS::Internal::Rule::ID];
	next RULE if not $grammar_c->rule_is_used($start_rule_id);
	last RULE if $grammar_c->rule_length($start_rule_id) <= 0;
    }

    my $start_symbol_id = $grammar_c->rule_lhs($start_rule_id);

    # Cannot increment the null parse
    return if $recce->[Marpa::XS::Internal::Recognizer::PARSE_COUNT]++;

    my $null_values = $recce->[Marpa::XS::Internal::Recognizer::NULL_VALUES];
    return \$null_values->[$start_symbol_id];

} ## end sub Marpa::XS::Internal::Recognizer::do_null_parse

# Returns false if no parse
sub Marpa::XS::Recognizer::value {
    my ( $recce, @arg_hashes ) = @_;

    Marpa::XS::Internal::Recognizer::update_earleme_map($recce);

    my $recce_c = $recce->[Marpa::XS::Internal::Recognizer::C];

    my $parse_set_arg = $recce->[Marpa::XS::Internal::Recognizer::END];

    local $Marpa::XS::Internal::TRACE_FH =
        $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE];

    my $slots = $recce->[Marpa::XS::Internal::Recognizer::SLOTS];
    my $ranking_method =
        $recce->[Marpa::XS::Internal::Recognizer::RANKING_METHOD];

    if ( $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] ) {
        Marpa::exception(
            qq{Arguments were passed directly to value() in a previous call\n},
            qq{Only one call to value() is allowed per recognizer when arguments are passed directly\n},
            qq{This is the second call to value()\n}
        );
    } ## end if ( $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE...])

    my $parse_count = $recce->[Marpa::XS::Internal::Recognizer::PARSE_COUNT];
    my $max_parses  = $recce->[Marpa::XS::Internal::Recognizer::MAX_PARSES];
    if ( $max_parses and $parse_count > $max_parses ) {
        Marpa::exception("Maximum parse count ($max_parses) exceeded");
    }

    for my $arg_hash (@arg_hashes) {

        if ( exists $arg_hash->{end} ) {
            if ($parse_count) {
                Marpa::exception(
                    q{Cannot change "end" after first parse result});
            }
            $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] = 1;
            $parse_set_arg = $arg_hash->{end};
            delete $arg_hash->{end};
        } ## end if ( exists $arg_hash->{end} )

        if ( exists $arg_hash->{closures} ) {
            if ($parse_count) {
                Marpa::exception(
                    q{Cannot change "closures" after first parse result});
            }
            $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] = 1;
            my $closures = $arg_hash->{closures};
            while ( my ( $action, $closure ) = each %{$closures} ) {
                Marpa::exception(qq{Bad closure for action "$action"})
                    if ref $closure ne 'CODE';
            }
            $recce->[Marpa::XS::Internal::Recognizer::CLOSURES] = $closures;
            delete $arg_hash->{closures};
        } ## end if ( exists $arg_hash->{closures} )

        if ( exists $arg_hash->{trace_actions} ) {
            $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] = 1;
            $recce->[Marpa::XS::Internal::Recognizer::TRACE_ACTIONS] =
                $arg_hash->{trace_actions};
            delete $arg_hash->{trace_actions};
        } ## end if ( exists $arg_hash->{trace_actions} )

        if ( exists $arg_hash->{trace_values} ) {
            $recce->[Marpa::XS::Internal::Recognizer::SINGLE_PARSE_MODE] = 1;
            $recce->[Marpa::XS::Internal::Recognizer::TRACE_VALUES] =
                $arg_hash->{trace_values};
            delete $arg_hash->{trace_values};
        } ## end if ( exists $arg_hash->{trace_values} )

        # A typo made its way into the documentation, so now it's a
        # synonym.
        for my $trace_fh_alias (qw(trace_fh trace_file_handle)) {
            if ( exists $arg_hash->{$trace_fh_alias} ) {
                $recce->[Marpa::XS::Internal::Recognizer::TRACE_FILE_HANDLE] =
                    $Marpa::XS::Internal::TRACE_FH =
                    $arg_hash->{$trace_fh_alias};
                delete $arg_hash->{$trace_fh_alias};
            } ## end if ( exists $arg_hash->{$trace_fh_alias} )
        } ## end for my $trace_fh_alias (qw(trace_fh trace_file_handle))

        my @unknown_arg_names = keys %{$arg_hash};
        Marpa::exception(
            'Unknown named argument(s) to Marpa::XS::Recognizer::value: ',
            ( join q{ }, @unknown_arg_names ) )
            if @unknown_arg_names;

    } ## end for my $arg_hash (@arg_hashes)

    my $grammar     = $recce->[Marpa::XS::Internal::Recognizer::GRAMMAR];
    my $grammar_c     = $grammar->[Marpa::XS::Internal::Grammar::C];
    my $symbols = $grammar->[Marpa::XS::Internal::Grammar::SYMBOLS];
    my $rules   = $grammar->[Marpa::XS::Internal::Grammar::RULES];

    my $furthest_earleme = $recce_c->furthest_earleme();
    my $last_completed_earleme = $recce_c->current_earleme();
    Marpa::exception(
        "Attempt to evaluate incompletely recognized parse:\n",
        "  Last token ends at location $furthest_earleme\n",
        "  Recognition done only as far as location $last_completed_earleme\n"
    ) if $furthest_earleme > $last_completed_earleme;

    my $iteration_stack;
    my $iteration_node_worklist;
    my @and_node_in_use = ();
    my $evaluator_rules;
    my $initial_pass = 0;

    my $top_or_node_id;
    if ( not $parse_count ) {

	$initial_pass = 1;

        # Perhaps this call should be moved.
        # The null values are currently a function of the grammar,
        # and should be constant for the life of a recognizer.
        my $null_values =
            $recce->[Marpa::XS::Internal::Recognizer::NULL_VALUES] //=
            Marpa::XS::Internal::Recognizer::set_null_values($recce);

        $evaluator_rules =
            $recce->[Marpa::XS::Internal::Recognizer::EVALUATOR_RULES] =
            Marpa::XS::Internal::Recognizer::set_actions($recce);

        $recce_c->eval_clear();
        $top_or_node_id =
            $recce_c->eval_setup( -1, ( $parse_set_arg // -1 ) );
        if ( not defined $top_or_node_id ) {
            Marpa::exception(qq{libmarpa's marpa_value() call failed\n});
        }
        if ( $top_or_node_id == 0 ) {
            return Marpa::XS::Internal::Recognizer::do_null_parse($recce);
        }

	my $start_iteration_node = [];
	# -999 because -1 will NOT work -- because of some hackery
	# it confuses the logic into thinking the top or-node is the cause of
	# a or-node numberbed -1
	$start_iteration_node->[Marpa::XS::Internal::Iteration_Node::PARENT] = -999;
	$start_iteration_node->[Marpa::XS::Internal::Iteration_Node::OR_NODE_ID]
	    = $top_or_node_id;

        if ( $ranking_method eq 'constant' ) {
            do_rank_all($recce);
        } ## end if ( $ranking_method eq 'constant' )

        my $choice = $start_iteration_node->[Marpa::XS::Internal::Iteration_Node::CHOICE] = 0;

        # Due to skipping, even an initialized set of choices
        # may be empty.  If it is, return no parse.
        my $and_node_id = $recce_c->and_node_order_get($top_or_node_id, $choice);
        return if not defined $and_node_id;
        $and_node_in_use[$and_node_id] = 1;

	$recce->[Marpa::XS::Internal::Recognizer::ITERATION_STACK] =
	    $iteration_stack = [$start_iteration_node];
        $iteration_node_worklist = [ 0 ];

    } else {

        # Not the first parse of a parse series
	$evaluator_rules =
	    $recce->[Marpa::XS::Internal::Recognizer::EVALUATOR_RULES];
	$iteration_stack =
	    $recce->[Marpa::XS::Internal::Recognizer::ITERATION_STACK];
	ITERATION_NODE: for my $iteration_node (@{$iteration_stack}) {
	    my $or_node_id = $iteration_node->[Marpa::XS::Internal::Iteration_Node::OR_NODE_ID];
	    my $choice = $iteration_node->[Marpa::XS::Internal::Iteration_Node::CHOICE];
	    my $and_node_id = $recce_c->and_node_order_get($or_node_id, $choice);
	    next ITERATION_NODE if not defined $and_node_id;
	    $and_node_in_use[$and_node_id] = 1;
	}

    }

    ITERATION: while (1) {

        # Special processing for the top iteration node
        SETUP_ITERATION: {

            if ($initial_pass) {
                $initial_pass = 0;
                last SETUP_ITERATION;
            }

            # In this pass, we go up the iteration stack,
            # looking a node which we can iterate.
            my $iteration_node;
            my $choices;
            ITERATION_NODE:
            while ( $iteration_node = pop @{$iteration_stack} ) {

		my $iteration_node_ix = scalar @{$iteration_stack};

                my $choice = $iteration_node
                    ->[Marpa::XS::Internal::Iteration_Node::CHOICE];
                my $or_node_id = $iteration_node
                    ->[Marpa::XS::Internal::Iteration_Node::OR_NODE_ID];

                # Mark the current choice not in use
		my $and_node_id = $recce_c->and_node_order_get($or_node_id, $choice);
                $and_node_in_use[$and_node_id] = undef;

                $choice++;

                # Throw away choices until we find one that does not cycle
                CHOICE: while ( 1 ) {
                    $and_node_id = $recce_c->and_node_order_get($or_node_id, $choice);
		    last CHOICE if not defined $and_node_id;
                    last CHOICE if not $and_node_in_use[$and_node_id];
                    $choice++;
                } ## end while ( scalar @{$choices} )

                $iteration_node->[Marpa::XS::Internal::Iteration_Node::CHOICE] = $choice;

                if ( not defined $and_node_id ) {

                    my $direct_parent = $iteration_node
                        ->[Marpa::XS::Internal::Iteration_Node::PARENT];

                    # For the node just popped off the stack
                    # unset the pointer to it in its parent
                    if ($iteration_node->[
                        Marpa::XS::Internal::Iteration_Node::IS_CAUSE_OF_PARENT
                        ]
                        )
                    {
                        $iteration_stack->[$direct_parent]
                            ->[Marpa::XS::Internal::Iteration_Node::IS_CAUSE_READY]
                            = undef;
                    } ## end if ( $iteration_node->[...])
                    if ($iteration_node->[
                        Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_OF_PARENT
                        ]
                        )
                    {
                        $iteration_stack->[$direct_parent]
                            ->[Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_READY]
                            = undef;
                    } ## end if ( $iteration_node->[...])

                    next ITERATION_NODE;
                } ## end if ( not scalar @{$choices} )

                # Dirty the iteration node and put it back
                # on the stack
                $iteration_node->[
                    Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_READY]
                    = undef;
                $iteration_node
                    ->[Marpa::XS::Internal::Iteration_Node::IS_CAUSE_READY] =
                    undef;
                push @{$iteration_stack}, $iteration_node;
                $and_node_in_use[$and_node_id] = 1;
                last ITERATION_NODE;

            } ## end while ( $iteration_node = pop @{$iteration_stack} )

            # If we hit the top of the stack without finding any node
            # to iterate, that is it for parsing.
            return if not defined $iteration_node;

            $iteration_node_worklist = [ 0 .. $#{$iteration_stack} ];

        } ## end SETUP_ITERATION:

        # This task is set up to rerun itself until explicitly exited
        FIX_TREE_LOOP: while (1) {

            # If the work list is undefined, initialize it to the entire stack
            # We are done fixing the tree if the worklist is empty
            last ITERATION if not scalar @{$iteration_node_worklist};
            my $working_node_ix = $iteration_node_worklist->[-1];

            my $working_node = $iteration_stack->[$working_node_ix];
            my $working_or_node_id =
                $working_node->[Marpa::XS::Internal::Iteration_Node::OR_NODE_ID];
            my $choice =
                $working_node->[Marpa::XS::Internal::Iteration_Node::CHOICE];
            my $working_and_node_id =
                    $recce_c->and_node_order_get($working_or_node_id, $choice);

            my $new_iteration_node = [];
            my $or_node_id;
            if (not 
                $working_node->[Marpa::XS::Internal::Iteration_Node::IS_CAUSE_READY]
                )
            {
                $or_node_id = $recce_c->and_node_cause($working_and_node_id);
                if ( defined $or_node_id ) {
                    $new_iteration_node->[
                        Marpa::XS::Internal::Iteration_Node::IS_CAUSE_OF_PARENT
                    ] = 1;
                }
                else {
		    $working_node->[Marpa::XS::Internal::Iteration_Node::IS_CAUSE_READY] = 1;
                    $working_node ->[Marpa::XS::Internal::Iteration_Node::HAS_CAUSE] = undef;
                }
            } ## end if ( not defined $working_node->[...])
            if (not defined $or_node_id and not
                $working_node->[Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_READY]
                )
            {
                $or_node_id = $recce_c->and_node_predecessor($working_and_node_id);
                if ( defined $or_node_id ) {
                    $new_iteration_node->[
                        Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_OF_PARENT
                    ] = 1;
                }
                else {
		    $working_node->[Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_READY] = 1;
                    $working_node ->[Marpa::XS::Internal::Iteration_Node::HAS_PREDECESSOR] = undef;
                }
            } ## end if ( not defined $working_node->[...])

            if ( not defined $or_node_id ) {
                pop @{$iteration_node_worklist};
                next FIX_TREE_LOOP;
            }

            $new_iteration_node
                ->[Marpa::XS::Internal::Iteration_Node::OR_NODE_ID] =
                $or_node_id;
            $new_iteration_node->[Marpa::XS::Internal::Iteration_Node::PARENT]
                = $working_node_ix;

            my $new_iteration_node_choice = 0;

            CHOICE: while (1) {

                my $and_node_id =
                    $recce_c->and_node_order_get( $or_node_id,
                    $new_iteration_node_choice );

                # Due to skipping, even an initialized set of choices
                # may be empty.  If it is, throw away the stack and iterate.
                if (not defined $and_node_id) {
		    $new_iteration_node
			->[Marpa::XS::Internal::Iteration_Node::CHOICE] =
			$new_iteration_node_choice;
		    next ITERATION;
		}

                # End the loop if we do not cycle on this and-node.
                if ( not $and_node_in_use[$and_node_id] ) {
                    $and_node_in_use[$and_node_id] = 1;
                    last CHOICE;
                }

                $new_iteration_node_choice++;

            } ## end while (1)

	    $new_iteration_node->[Marpa::XS::Internal::Iteration_Node::CHOICE] =
		$new_iteration_node_choice;
	    my $new_iteration_node_ix = scalar @{$iteration_stack};
	    my $parent_ix =
		$new_iteration_node->[Marpa::XS::Internal::Iteration_Node::PARENT];

            # Tell the parent that the new iteration node is its child.
            if ( $new_iteration_node
                ->[Marpa::XS::Internal::Iteration_Node::IS_CAUSE_OF_PARENT] )
            {
                $iteration_stack->[$parent_ix]
                    ->[Marpa::XS::Internal::Iteration_Node::IS_CAUSE_READY] =
                    1;
            } ## end if ( $new_iteration_node->[...])

            if ($new_iteration_node->[
                Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_OF_PARENT]
                )
            {
                $iteration_stack->[$parent_ix]->[
                    Marpa::XS::Internal::Iteration_Node::IS_PREDECESSOR_READY]
                    = 1;
            } ## end if ( $new_iteration_node->[...])

            # Add this node to the iteration node worklist.
            push @{$iteration_node_worklist}, $new_iteration_node_ix;
            push @{$iteration_stack},         $new_iteration_node;

        } ## end while (1)

    } ## end while (1)

    if ($recce->[Marpa::XS::Internal::Recognizer::TRACE_AND_NODES]) {
	print {$Marpa::XS::Internal::TRACE_FH} 'AND_NODES: ',
	    $recce->show_and_nodes()
	or Marpa::exception('print to trace handle failed');
    }

    if ($recce->[Marpa::XS::Internal::Recognizer::TRACE_OR_NODES]) {
	print {$Marpa::XS::Internal::TRACE_FH} 'OR_NODES: ',
	    $recce->show_or_nodes()
	or Marpa::exception('print to trace handle failed');
    }

    if ($recce->[Marpa::XS::Internal::Recognizer::TRACE_BOCAGE]) {
	print {$Marpa::XS::Internal::TRACE_FH} 'BOCAGE: ',
	    $recce->show_bocage()
	or Marpa::exception('print to trace handle failed');
    }

    $recce->[Marpa::XS::Internal::Recognizer::PARSE_COUNT]++;
    return Marpa::XS::Internal::Recognizer::evaluate( $recce, $iteration_stack );

} ## end sub Marpa::XS::Recognizer::value

1;
