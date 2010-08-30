package Marpa::XS;

# Originally modeled after PPI/XS.pm by Adam Kennedy

use 5.010;
use strict;
use warnings;

use Scalar::Util ();
use List::Util ();
use Carp ();
use Data::Dumper ();
use Storable ();

use Marpa::XS::Internal;
use Marpa::XS::Internal::Carp_Not;
use Marpa::XS::Grammar;
use Marpa::XS::Recognizer;
use Marpa::XS::Recce_Value;
use Marpa::XS::Callback;

use XSLoader;

our $VERSION;

BEGIN {

       $VERSION = '0.001_000';

       # Put Perl code used in the BOOT: section here
       # Load the XS functions

       XSLoader::load( 'Marpa::XS' => $VERSION );

}

no strict 'refs';
my $code = *{'Marpa::XS::Internal::libmarpa_check_version'}{'CODE'};
if ( not defined $code ) {
    Carp::croak("no code for libmarpa_check_version")
        if $Marpa::XS_FORCE;
    undef $VERSION;
    return 1;
}
*{'Marpa::XS::check_version'} = $code;
use strict;

if ( Marpa::XS::check_version( 0, 0, 0 ) ) {
    Carp::croak("Marpa::XS fails libmarpa_check_version")
        if $Marpa::XS_FORCE;
    undef $VERSION;
    return 1;
}

# Find all the functions in Marpa::XS
XS_FUNCTION: for my $xs_function ( keys %{Marpa::XS::Internal::} ) {

    next XS_FUNCTION if $xs_function !~ /^_Marpa/xms;

    # Prepare
    next XS_FUNCTION
        if
        not( my ( $class, $function ) =
                ( $xs_function =~ / \A _(\w+?)__(\w+) \z /xms ) );
    $class =~ s/_/::/gxms;

    if ( 0 ) {
    # if ( $EXCLUDE{$xs_function} ) {

        # Remove the un-needed function.
        # The primary purpose of this is to recover the memory
        # occupied by the useless functions, but has the
        # additional benefit of allowing us to detect which
        # functions were actually mapped in by examining the
        # names of the functions remaining in the Marpa::XS symbol
        # table.
        delete ${'Marpa::XS::'}{$xs_function};
    } ## end if ( $EXCLUDE{$xs_function} )
    else {

        # Map in the function
        no strict 'refs';
        my $code = *{"Marpa::XS::Internal::$xs_function"}{'CODE'};
        use strict;
        next XS_FUNCTION if not defined $code;
        *{"${class}::${function}"} = $code;

    } ## end else [ if ( $EXCLUDE{$xs_function} ) ]
} ## end for my $xs_function ( keys %{'Marpa::XS::Internal::'})

1;

__END__
