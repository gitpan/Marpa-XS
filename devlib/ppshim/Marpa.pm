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

use 5.010;

use warnings;
use strict;

package Marpa;

# Faked version to fool Marpa::HTML
$Marpa::VERSION = 0.100000;

use Marpa::XS;
$Marpa::XS::FORCE_PP = 1;

sub compatible { return 1; }
sub Marpa::Grammar::new {
return bless Marpa::XS::Grammar::new(@_), 'Marpa::XS::Grammar';
}
sub Marpa::Grammar::set { return Marpa::XS::Grammar::set(@_); }
sub Marpa::Grammar::precompute { return Marpa::XS::Grammar::precompute(@_); }
sub Marpa::Recognizer::new {
return bless Marpa::XS::Recognizer::new(@_), 'Marpa::XS::Recognizer';
}
sub Marpa::Recognizer::reset_evaluation { return Marpa::XS::Recognizer::reset_evaluation(@_); }
sub Marpa::Recognizer::set { return Marpa::XS::Recognizer::set(@_); }
sub Marpa::Recognizer::tokens { return Marpa::XS::Recognizer::tokens(@_); }

1;
