package Marpa::XS;

use 5.010;
use strict;
use warnings;

use Marpa::XS::Version;

our $TESTING_PERL_ONLY;

eval {

    # PERL_DL_NONLAZY must be false, or any errors in loading will just
    # cause the perl code to be tested
    local $ENV{PERL_DL_NONLAZY} = 0 if $ENV{PERL_DL_NONLAZY};
    eval {
        require XSLoader;
        XSLoader::load( 'Marpa::XS' => $Marpa::XS::STRING_VERSION );
    };
} unless $TESTING_PERL_ONLY;

no strict 'refs';
my $check_version_code = *{'Marpa::XS::Internal::libmarpa_check_version'}{'CODE'};
use strict;

if (not defined $check_version_code) {
    undef $Marpa::XS::VERSION;
    undef $Marpa::XS::STRING_VERSION;
}

# If can't load Marpa::XS, use the Pure Perl version
if ( not defined $Marpa::XS::VERSION ) {
    require Marpa::XS::Internal;
    require Marpa::XS::Internal::Carp_Not;
    Marpa::XS::Internal::Carp_Not->import();
    require Marpa::XS::Grammar_PP;
    require Marpa::XS::Recognizer_PP;
    require Marpa::XS::Value_PP;
    require Marpa::XS::Callback_PP;
} ## end if ( not defined $Marpa::XS::VERSION )
else {
    no strict 'refs';
    *{'Marpa::XS::check_version'} = $check_version_code;
    use strict;
    my $check_version_result = Marpa::XS::check_version( 0, 1, 0 ) // 'undef';
    Carp::croak("Marpa::XS fails libmarpa_check_version")
        if $check_version_result ne 'Perfect!';

    require Marpa::XS::Internal;
    require Marpa::XS::Internal::Carp_Not;
    Marpa::XS::Internal::Carp_Not->import();
    require Marpa::XS::Grammar;
    require Marpa::XS::Recognizer;
    require Marpa::XS::Recce_Value;
    require Marpa::XS::Callback;
} ## end else [ if ( not defined $Marpa::XS::VERSION ) ]

1;

__END__
