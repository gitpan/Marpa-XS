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

use Marpa::XS::Version;

our $TESTING_PERL_ONLY;
{

    package Marpa::XS::Internal;
    our $check_version;
}

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
my $check_version_code = *{'Marpa::XS::Internal::check_version'}{'CODE'};
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
    *{'Marpa::XS::version'}       = *{'Marpa::XS::Internal::version'}{'CODE'};
    use strict;
    my $check_version_result = Marpa::XS::check_version( 0, 1, 0 ) // 'undef';
    Carp::croak("Marpa::XS fails marpa_check_version")
        if $check_version_result ne 'Perfect!';

    require Marpa::XS::Internal;
    require Marpa::XS::Internal::Carp_Not;
    Marpa::XS::Internal::Carp_Not->import();
    require Marpa::XS::Grammar;
    require Marpa::XS::Recognizer;
    require Marpa::XS::Value;
    require Marpa::XS::Callback;
} ## end else

1;

__END__
