package Marpa::XS::Internal::Callback;

use 5.010;
use warnings;
use strict;
use integer;

use English qw( -no_match_vars );

sub Marpa::XS::location {
    Marpa::XS::exception('No context for location callback')
        if not my $context = $Marpa::XS::Internal::CONTEXT;
    my ( $context_type, $and_node ) = @{$context};
    if ( $context_type eq 'and-node' ) {
        return $and_node->[Marpa::XS::Internal::And_Node::START_EARLEME];
    }
    Marpa::XS::exception('LOCATION called outside and-node context');
} ## end sub Marpa::XS::location

sub Marpa::XS::cause_location {
    Marpa::XS::exception('No context for cause_location callback')
        if not my $context = $Marpa::XS::Internal::CONTEXT;
    my ( $context_type, $and_node ) = @{$context};
    if ( $context_type eq 'and-node' ) {
        return $and_node->[Marpa::XS::Internal::And_Node::CAUSE_EARLEME];
    }
    Marpa::XS::exception('cause_location() called outside and-node context');
} ## end sub Marpa::XS::cause_location

no strict 'refs';
*{'Marpa::XS::token_location'} = \&Marpa::XS::cause_location;
use strict;

sub Marpa::XS::length {
    Marpa::XS::exception('No context for LENGTH tie')
        if not my $context = $Marpa::XS::Internal::CONTEXT;
    my ( $context_type, $and_node ) = @{$context};
    if ( $context_type eq 'and-node' ) {
        return $and_node->[Marpa::XS::Internal::And_Node::END_EARLEME]
            - $and_node->[Marpa::XS::Internal::And_Node::START_EARLEME];
    }
    Marpa::XS::exception('LENGTH called outside and-node context');
} ## end sub Marpa::XS::length

1;
