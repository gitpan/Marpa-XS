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

package Marpa::XS::Build_Me;

use strict;
use warnings;

@Marpa::XS::Build_Me::ISA = ('Module::Build');

use Config;
use IPC::Cmd;
use Module::Build;
use English qw( -no_match_vars );

use Marpa::XS::Config;

my $marpa_xs_version = $Marpa::XS::VERSION_FOR_CONFIG{'Marpa::XS'};

my @marpa_xs_use =
    qw( Scalar::Util List::Util Carp Data::Dumper Storable Glib );
my @marpa_xs_perl_use = qw( Scalar::Util Carp Data::Dumper PPI Marpa::XS );

sub version_contents {
    my ( $package, @use_packages ) = @_;
    my $text = <<'END_OF_STRING';
# This file is written by Build.PL
# It is not intended to be modified directly
END_OF_STRING

    $text .= "package $package;\n";
    $text .= "BEGIN {\n";
    ## no critic (ValuesAndExpressions::RequireInterpolationOfMetachars)
    $text .= q{$Marpa::XS::VERSION = } . $marpa_xs_version . ";\n";
    $text .= q{$Marpa::XS::STRING_VERSION = '} . $marpa_xs_version . "';\n";
    ## use critic
    $text .= "}\n";
    for my $package (@use_packages) {
        my $version = $Marpa::XS::VERSION_FOR_CONFIG{$package};
        die "No version defined for $package" if not defined $version;
        $text .= "use $package $version ();\n";
    }
    $text .= "1;\n";
    return $text;
} ## end sub version_contents

my $perl_version_pm = version_contents( 'Marpa::XS::Perl', @marpa_xs_perl_use );
my $version_pm = version_contents( 'Marpa::XS', @marpa_xs_use );

sub write_file {
    my ($self, $contents, @name_components) = @_;
    my $base_dir     = $self->base_dir();
    my $file_name = pop @name_components;
    my $dir_name = File::Spec->catdir( $base_dir, @name_components );
    -d $dir_name or mkdir $dir_name;
    my $path_name = File::Spec->catfile( $dir_name, $file_name );
    open my $fh, q{>}, $path_name;
    print {$fh} $contents;
    close $fh;
}

sub do_libmarpa {
    my $self     = shift;
    my $cwd      = $self->cwd();
    my $base_dir = $self->base_dir();
    my $libmarpa_dir =
	File::Spec->catdir( $base_dir, qw(libmarpa main build) );
    -d $libmarpa_dir or mkdir $libmarpa_dir;
    chdir $libmarpa_dir;
    my $updir = File::Spec->updir();
    my $configure_script = File::Spec->catfile( $updir, 'configure' );
    if ( not -r 'stamp-h1' ) {
	print "Configuring libmarpa\n" if $self->verbose();
	my $shell = $Config{sh};
	$shell or die(q{No Bourne shell available says $Config{sh}});
	if (not IPC::Cmd::run(
		command => [ $shell, $configure_script ],
		verbose => 1
	    )
	    )
	{
	    say STDERR "Failed: $configure_script";
	    say STDERR "Current directory: $libmarpa_dir";
	    die 'Cannot run libmarpa configure';
	} ## end if ( not IPC::Cmd::run( command => [ $shell, ...]))
    } ## end if ( not -r 'stamp-h1' )
    else {
	print "Found configuration for libmarpa\n" if $self->verbose();
    }
    print "Making libmarpa: Start\n" if $self->verbose();
    {
	 # Make sure "configure" is writeable
	 my $perm = (stat $configure_script)[2] & 07777;
	 chmod($perm | 0200, $configure_script);
    }
    die('Making libmarpa: Failure')
	if not IPC::Cmd::run( command => ['make'], verbose => 1 );
    chdir $cwd;

} ## end sub do_libmarpa

sub ACTION_manifest {
    die qq{Automatic generation of the MANIFEST file is disabled\n}
	. qq{The Marpa MANIFEST file is handwritten\n};
}

sub ACTION_licensecheck {
    require 'lib/Marpa/XS/License.pm';
    my @manifest = do {
	open my $fh, q{<}, 'MANIFEST';
	local $RS = undef;
	my $text = <$fh>;
	$text =~ s/[#] [^\n]* $//gxms;
	grep { defined and not / \A \s* \z /xms } split '\n', $text;
    };
    my @license_problems =
	Marpa::XS::License::license_problems(@manifest);
    if (@license_problems) {
	print STDERR join q{}, @license_problems;
	die qq{Fatal error due to license language issues};
    }
}

sub ACTION_distcheck {
    my $self = shift;
    $self->ACTION_licensecheck();
    $self->SUPER::ACTION_distcheck;
}

sub ACTION_dist {
    my $self = shift;
    my $changes = do {
	open my $fh, q{<}, 'Changes';
	local $RS = undef;
	<$fh>;
    };
    die qq{"$marpa_xs_version" not in Changes file}
	if 0 > index $changes, $marpa_xs_version;
    $self->SUPER::ACTION_dist;
} ## end sub ACTION_dist

sub do_xs {
    my $self = shift;
    my $from = 'xs/XS.xs';
    my $to = 'lib/Marpa/XS.xs';
    my $base = $self->base_dir();
    my $blib = $self->blib;
    $self->add_to_cleanup($to);
    my $bundle = File::Spec->catfile($blib, qw(arch auto Marpa XS XS.bundle) );
    my $marpa_c = File::Spec->catfile($base, qw(libmarpa main src marpa.c) );
    SOURCE: for my $try_source ($marpa_c) {
	say STDERR "comparing to $marpa_c: $bundle";
	next SOURCE if $self->up_to_date([$marpa_c], $bundle);
	say STDERR "Unlinking $bundle";
	unlink $bundle;
    }
    my $XS_o = File::Spec->catfile($base, qw(lib Marpa XS.o ) );
    my $marpa_h = File::Spec->catfile($base, qw(libmarpa main src marpa.h) );
    SOURCE: for my $try_source ($marpa_h) {
	say STDERR "comparing to $marpa_h: $XS_o";
	next SOURCE if $self->up_to_date([$marpa_h], $XS_o);
	say STDERR "Unlinking $XS_o";
	unlink $XS_o;
    }
    $self->copy_if_modified( from => $from, to => $to );
    $self->process_xs($to);
}

sub ACTION_code {
    my $self = shift;
    say STDERR "Writing version files";
    $self->write_file($version_pm, qw(lib Marpa XS Version.pm) );
    $self->write_file($perl_version_pm, qw(lib Marpa XS Perl Version.pm) );
    $self->do_libmarpa();

    # "Inlined" From Module::Build:
    # All installable stuff gets created in blib/ .
    # Create blib/arch to keep blib.pm happy
    my $blib = $self->blib;
    $self->add_to_cleanup($blib);
    File::Path::mkpath( File::Spec->catdir($blib, 'arch') );

    $self->process_PL_files('PL');
    $self->process_support_files('support');
    $self->process_pm_files('pm');

    $self->do_xs();

    $self->process_share_dir_files('share_dir');
    $self->process_pod_files('pod');
    $self->process_script_files('script');

    $self->depends_on('config_data');
}

sub ACTION_clean {
    my $self = shift;

    my $curdir = File::Spec->rel2abs( File::Spec->curdir() );
    print "Cleaning libmarpa\n" if $self->verbose;
    my $libmarpa_dir = File::Spec->catdir( $curdir, qw(libmarpa build) );
    File::Path::rmtree( $libmarpa_dir, { keep_root => 1 } );

    $self->SUPER::ACTION_clean;
} ## end sub ACTION_dist

