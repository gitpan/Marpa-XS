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

package Marpa::XS;

use 5.010;
use strict;
use warnings;
use Carp;
use English qw( -no_match_vars );

use Marpa::XS::Version;

# Sensible defaults if not defined
$Marpa::XS::USE_PP //= 0;
$Marpa::XS::USE_XS //= ! $Marpa::XS::USE_PP;

# Die if both PP and XS were chosen
if ( $Marpa::XS::USE_PP and $Marpa::XS::USE_XS ) {
    Carp::croak('Cannot specify both USE_XS and USE_PP');
}
# Die if both PP and XS were unset
if ( ! $Marpa::XS::USE_PP and ! $Marpa::XS::USE_XS ) {
    Carp::croak('Cannot unset both USE_XS and USE_PP');
}

if ( $Marpa::XS::USE_XS ) {

    # PERL_DL_NONLAZY must be false, or any errors in loading will just
    # cause the perl code to be tested
    local $ENV{PERL_DL_NONLAZY} = 0 if $ENV{PERL_DL_NONLAZY};
    eval {
        require XSLoader;
        XSLoader::load( 'Marpa::XS' => $Marpa::XS::STRING_VERSION );
        1;
    } or do {
        Carp::croak("Could not load XS version of Marpa: $EVAL_ERROR");
    };

    $Marpa::XS::USING_XS = 1;
    $Marpa::XS::USING_PP = 0;

    my $version_found = join q{.}, Marpa::XS::version();
    my $version_wanted = '0.1.0';
    Carp::croak('Marpa::XS ', "fails version check, wanted $version_wanted, found $version_found")
        if $version_wanted ne $version_found;

    require Marpa::XS::Internal;
    require Marpa::XS::Internal::Carp_Not;
    Marpa::XS::Internal::Carp_Not->import();
    require Marpa::XS::Grammar;
    require Marpa::XS::Recognizer;
    require Marpa::XS::Value;
    require Marpa::XS::Callback;
    require Marpa::XS::Slot;

    return 1;
}

undef $Marpa::XS::VERSION;
undef $Marpa::XS::STRING_VERSION;
$Marpa::XS::USING_XS = 0;
$Marpa::XS::USING_PP = 1;

require Marpa::XS::Internal;
require Marpa::XS::Internal::Carp_Not;
Marpa::XS::Internal::Carp_Not->import();
require Marpa::XS::Grammar_PP;
require Marpa::XS::Recognizer_PP;
require Marpa::XS::Value_PP;
require Marpa::XS::Callback_PP;

1;

__END__
