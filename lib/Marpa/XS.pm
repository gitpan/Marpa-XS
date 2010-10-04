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

package Marpa::XS;

use 5.010;
use strict;
use warnings;
use Carp;
use English qw( -no_match_vars );

use Marpa::XS::Version;

# Sensible defaults if not defined
$Marpa::XS::FORCE_PP //= 0;
$Marpa::XS::FORCE_XS //= 0;

# Die if incoherent PP vs. XS choice is made
if ( $Marpa::XS::FORCE_PP and $Marpa::XS::FORCE_XS ) {
    Carp::croak('Cannot specify both FORCE_XS and FORCE_PP');
}

if ( not $Marpa::XS::FORCE_PP ) {

    # PERL_DL_NONLAZY must be false, or any errors in loading will just
    # cause the perl code to be tested
    local $ENV{PERL_DL_NONLAZY} = 0 if $ENV{PERL_DL_NONLAZY};
    my $eval_return = eval {
        require XSLoader;
        XSLoader::load( 'Marpa::XS' => $Marpa::XS::STRING_VERSION );
        1;
    };
    if ( not $eval_return and $Marpa::XS::FORCE_XS ) {
        Carp::croak("Could not load XS version of Marpa: $EVAL_ERROR");
    }
} ## end if ( not $Marpa::XS::FORCE_PP )

my $check_version_code;
{
    no strict 'refs';
    no warnings 'once';
    $check_version_code = *{'Marpa::XS::Internal::check_version'}{'CODE'};
}

if ( not defined $check_version_code ) {
    undef $Marpa::XS::VERSION;
    undef $Marpa::XS::STRING_VERSION;
}

# If can't load Marpa::XS, use the Pure Perl version
if ( not defined $Marpa::XS::VERSION ) {
    Carp::croak('Attempt to use Pure Perl version when FORCE_XS is in effect')
        if $Marpa::XS::FORCE_XS;
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
    *{'Marpa::XS::version'}       = *{'Marpa::XS::Internal::version'}{'CODE'};
    use strict;
    my $check_version_result = Marpa::XS::check_version( 0, 1, 0 ) // 'undef';
    Carp::croak('Marpa::XS fails marpa_check_version')
        if $check_version_result ne 'Perfect!';

    require Marpa::XS::Internal;
    require Marpa::XS::Internal::Carp_Not;
    Marpa::XS::Internal::Carp_Not->import();
    require Marpa::XS::Grammar;
    require Marpa::XS::Recognizer;
    require Marpa::XS::Value;
    require Marpa::XS::Callback;
} ## end else [ if ( not defined $Marpa::XS::VERSION ) ]

1;

__END__
