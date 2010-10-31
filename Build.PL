#!/usr/bin/perl
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
use strict;
use warnings;
use Fatal qw(open close);
use File::Spec;

use Config;
use Module::Build;
use ExtUtils::PkgConfig;
use Glib::Install::Files;

my $gperl_h_location = $Glib::Install::Files::CORE;

my %glib2_info              = ExtUtils::PkgConfig->find('glib-2.0');
my $glib_2_0_compiler_flags = $glib2_info{cflags};
my $glib_2_0_linker_flags   = $glib2_info{libs};

my $marpa_xs_version      = '0.001_010';
my $marpa_xs_perl_version = $marpa_xs_version;

my %version = (
    'Scalar::Util'        => 1.21,
    'List::Util'          => 1.21,
    'Carp'                => 1.08,
    'Data::Dumper'        => '2.125',
    'Storable'            => 2.21,
    'Marpa::XS'           => $marpa_xs_version,
    'PPI'                 => '1.206',
    'Test::Weaken'        => '3.004000',
    'ExtUtils::PkgConfig' => 1.12,
    'Module::Build'       => 0.3601,
    'ExtUtils::CBuilder'  => 0.27,
    'Test::More'          => 0.94,
    'Glib'                => 1.223,
);

my %build_requires =
    map { ( $_, $version{$_} ) } qw( ExtUtils::CBuilder Test::More );
my %configure_requires =
    map { ( $_, $version{$_} ) } qw( ExtUtils::PkgConfig Module::Build Glib );
my %requires =
    map { ( $_, $version{$_} ) }
    qw( Scalar::Util List::Util Carp Data::Dumper Storable Glib );
my %recommends = map { ( $_, $version{$_} ) } qw( PPI Test::Weaken );

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
        my $version = $version{$package};
        die "No version defined for $package" if not defined $version;
        $text .= "use $package $version ();\n";
    }
    $text .= "1;\n";
    return $text;
} ## end sub version_contents

my $subclass_code = q{};

## no critic (ValuesAndExpressions::RequireInterpolationOfMetachars)
$subclass_code .= q{my $version_pm = <<'END_OF_FILE';} . "\n";
## use critic
$subclass_code .= version_contents( 'Marpa::XS', @marpa_xs_use );
$subclass_code .= 'END_OF_FILE' . "\n\n";

## no critic (ValuesAndExpressions::RequireInterpolationOfMetachars)
$subclass_code .= q{my $perl_version_pm = <<'END_OF_FILE';} . "\n";
## use critic
$subclass_code .= version_contents( 'Marpa::XS::Perl', @marpa_xs_perl_use );
$subclass_code .= 'END_OF_FILE' . "\n\n";

## no critic (ValuesAndExpressions::RequireInterpolationOfMetachars)
$subclass_code .= q{my $version_string = '} . $marpa_xs_version . q{';};
## use critic

$subclass_code .= <<'SUBCLASS';

    use IPC::Cmd;
    use File::Spec;
    use File::Path;
    use Config;
    use Fatal qw(open close mkdir chdir);
    use English qw( -no_match_vars );

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
        die qq{"$version_string" not in Changes file}
            if 0 > index $changes, $version_string;
        $self->SUPER::ACTION_dist;
    } ## end sub ACTION_dist

    sub do_xs {
        my $self = shift;
        my $from = 'xs/XS.xs';
        my $to = 'lib/Marpa/XS.xs';
        $self->add_to_cleanup($to);
        $self->copy_if_modified( from => $from, to => $to );
        $self->process_xs($to);
    }

    sub ACTION_code {
        my $self = shift;
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

SUBCLASS

my $class = Module::Build->subclass(
    class => 'Module::Build::Custom',
    code  => $subclass_code
);

my %pod_files = map { ( "pod/$_" => "lib/Marpa/XS/$_" ) } qw(
    Advanced/Algorithm.pod
    Advanced/Bibliography.pod
    Advanced/Implementation.pod
    Advanced/Models.pod
    Grammar.pod
    Parse_Terms.pod
    Recognizer.pod
    Semantics.pod
    Support.pod
    Tracing.pod
);
$pod_files{'pod/Marpa_XS.pod'} = 'lib/Marpa/XS.pod';

my @no_index_namespace_inclusive = (

    # not for now, at least
    qw(Marpa::XS::Perl Marpa::XS::Offset Marpa::XS::Test Marpa::XS::Display ),

    # never intended to see the light of day
    qw( Marpa::XS::Internal),

);

my @files_to_cleanup = (
    'lib/Marpa/XS/Version.pm',      'lib/Marpa/XS/Perl/Version.pm',
    'lib/Marpa/XS.o',               'libmarpa/main/autoscan.log',
    'libmarpa/main/configure.scan', 'libmarpa/main/build',
    'libmarpa/main/autom4te.cache',
);

my $build = $class->new(
    add_to_cleanup     => \@files_to_cleanup,
    dist_name          => 'Marpa-XS',
    dist_author        => 'Jeffrey Kegler',
    dist_version       => $marpa_xs_version,
    dist_abstract      => 'XS Version of Marpa (Experimental)',
    recommends         => \%recommends,
    requires           => \%requires,
    configure_requires => \%configure_requires,
    build_requires     => \%build_requires,
    dynamic_config     => 1,
    extra_compiler_flags =>
        "$glib_2_0_compiler_flags -I$gperl_h_location -Ilibmarpa/main/src",
    extra_linker_flags =>
        "$glib_2_0_linker_flags libmarpa/main/build/src/.libs/libmarpa.a",
    PL_files   => {},
    # The XS file compilation is hard coded, above
    # xs_files   => { 'xs/XS.xs' => 'lib/Marpa/XS.xs' },
    meta_merge => {
        resources =>
            { repository => 'git://github.com/jeffreykegler/Marpa-XS.git', },
        no_index => {
            directory => [qw( inc t author.t )],
            namespace => [
                'Marpa::XS::Recognizer', 'Marpa::XS::Grammar',
                @no_index_namespace_inclusive
            ],
            package => [@no_index_namespace_inclusive],
        }
    },
    meta_add => {
        distribution_type => 'module',
        provides          => {
            'Marpa::XS' => {
                file    => 'lib/Marpa/XS.pm',
                version => $marpa_xs_version,
            },
        },
    },
    pod_files          => \%pod_files,
    create_readme      => 0,
    create_makefile_pl => 'small',
    test_files         => [ map { glob $_ } qw(t/*.t t/xs/*.t t/pp/*.t) ],
);

$build->add_build_element('libmarpa');
$build->create_build_script;
