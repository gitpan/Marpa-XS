#!/usr/bin/perl

use 5.010;
use strict;
use warnings;
use Carp;
use Fatal qw(open close);

use Module::Build;
use ExtUtils::PkgConfig;

my %glib2_info = ExtUtils::PkgConfig->find('glib-2.0');
my $glib_2_0_compiler_flags = $glib2_info{cflags};
my $glib_2_0_linker_flags   = $glib2_info{libs};

my $marpa_xs_version = '0.001_002';

my $class = Module::Build->subclass(
    class => 'Module::Build::Custom',
    code  => <<'SUBCLASS' );

    use IPC::Cmd;
    use File::Spec;
    use Config;

    sub do_libmarpa {
        my $self         = shift;
        my $cwd          = $self->cwd();
        my $base_dir     = $self->base_dir();
        my $libmarpa_dir = File::Spec->catdir( $base_dir, qw(inc libmarpa) );
        chdir($libmarpa_dir) or Carp::croak("Cannot chdir to $libmarpa_dir");
        my $shell = $Config{sh};
        $shell or Carp::croak(q{No Bourne shell available says $Config{sh}});
        if (not -r 'stamp-h1' ) {
            print "Configuring libmarpa\n" if $self->{verbose};
            Carp::croak('Cannot run libmarpa configure')
                if not IPC::Cmd::run( command => [ $shell, 'configure' ], verbose => 1 );
        } else {
            print "Found configuration for libmarpa\n" if $self->{verbose};
        }
        print "Making libmarpa\n" if $self->{verbose};
        Carp::croak('Cannot run libmarpa make')
            if not IPC::Cmd::run( command => ['make'], verbose => 1 );
        chdir($cwd) or Carp::croak("Cannot chdir to $cwd");

    } ## end sub process_libmarpa_files

    sub ACTION_code {
        my $self = shift;
        $self->{verbose} = 1;
        $self->do_libmarpa();
        $self->SUPER::ACTION_code;
    }

    sub ACTION_clean {
        my $self = shift;

        my $curdir = File::Spec->rel2abs(File::Spec->curdir());
        my $libmarpa_dir = File::Spec->catdir($curdir, qw(inc libmarpa));
        chdir($libmarpa_dir) or Carp::croak("Cannot chdir to $libmarpa_dir");
        print "Cleaning libmarpa\n" if $self->verbose;
        Carp::croak('Cannot run libmarpa make clean')
            if not IPC::Cmd::run( command => ['make', 'clean'] );
        chdir($curdir) or Carp::croak("Cannot chdir to $curdir");

        $self->SUPER::ACTION_clean;
    } ## end sub ACTION_dist

SUBCLASS

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
    'inc/libmarpa/stamp-h1',   'inc/libmarpa/*.o',
    'inc/libmarpa/*.la',       'inc/libmarpa/*.lo',
    'inc/libmarpa/*.a',        'inc/libmarpa/*.in~',
    'inc/libmarpa/.deps',      'inc/libmarpa/.libs',
    # 'inc/libmarpa/Makefile', # Don't know about this one
    'inc/libmarpa/config.h',
    'inc/libmarpa/config.log', 'inc/libmarpa/config.status',
    'inc/libmarpa/libtool',    'inc/libmarpa/m4',
    'inc/libmarpa/autom4te.cache',
);

my $build = $class->new(
    add_to_cleanup => \@files_to_cleanup,
    dist_name      => 'Marpa-XS',
    dist_author    => 'Jeffrey Kegler',
    dist_version   => $marpa_xs_version,
    dist_abstract  => 'Generate Parsers from any BNF grammar',
    recommends     => { 'PPI' => '1.206', },
    requires       => {
        'Scalar::Util'     => 0,
        'HTML::Parser'     => '3.64',
        'HTML::PullParser' => '3.57',
    },
    build_requires => {
        'ExtUtils::CBuilder'  => 0,
        'Test::More'          => 0.94,
        'ExtUtils::PkgConfig' => 1.12,
    },
    dynamic_config       => 1,
    extra_compiler_flags => "$glib_2_0_compiler_flags -Iinc/libmarpa",
    extra_linker_flags =>
        "$glib_2_0_linker_flags inc/libmarpa/.libs/libmarpa.a",
    requires   => {},
    PL_files   => {},
    xs_files   => { 'xs/XS.xs' => 'lib/Marpa/XS.xs' },
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
    license            => 'perl',
    create_license     => 1,
    create_readme      => 0,
    create_makefile_pl => 'small',
    test_files         => [ map { glob $_ } qw(t/*.t t/*/*.t) ],
);

$build->add_build_element('libmarpa');
$build->create_build_script;
