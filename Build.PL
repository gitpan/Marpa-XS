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

my $marpa_xs_version = '0.001_003';
my $marpa_xs_perl_version = $marpa_xs_version;

my %version = (
    'Scalar::Util'        => 1.22,
    'List::Util'          => 1.22,
    'Carp'                => 1.08,
    'Data::Dumper'        => '2.126',
    'Storable'            => 2.21,
    'Marpa::XS'           => $marpa_xs_version,
    'PPI'                 => '1.206',
    'Test::Weaken'        => '3.004000',
    'ExtUtils::PkgConfig' => 1.12,
    'Module::Build'       => 0.3601,
    'ExtUtils::CBuilder'  => 0.27,
    'Test::More'          => 0.94,
);

my %build_requires =
    map { ( $_, $version{$_} ) } qw( ExtUtils::CBuilder Test::More );
my %configure_requires =
    map { ( $_, $version{$_} ) } qw( ExtUtils::PkgConfig Module::Build     );
my %requires =
    map { ( $_, $version{$_} ) }
    qw( Scalar::Util List::Util Carp Data::Dumper Storable );
my %recommends = map { ( $_, $version{$_} ) } qw( PPI Test::Weaken );

my @marpa_xs_use = qw( Scalar::Util List::Util Carp Data::Dumper Storable );
my @marpa_xs_perl_use = qw( Scalar::Util Carp Data::Dumper PPI Marpa::XS );

sub version_contents {
    my ( $package, @use_packages ) = @_;
    my $text = <<'END_OF_STRING';
# This file is written by Build.PL
# It is not intended to be modified directly
END_OF_STRING

    $text .= "package $package;\n";
    $text .= "BEGIN {\n";
    $text .= q{$Marpa::XS::VERSION = } . $marpa_xs_version . ";\n";
    $text .= q{$Marpa::XS::STRING_VERSION = '} . $marpa_xs_version . "';\n";
    $text .= "}\n";
    for my $package (@use_packages) {
        my $version = $version{$package};
        die("No version defined for $package") if not defined $version;
        $text .= "use $package $version ();\n";
    }
    $text .= "1;\n";
    return $text;
} ## end sub version_contents


my $subclass_code = '';

$subclass_code .= q{my $version_pm = <<'END_OF_FILE';} . "\n";
$subclass_code .= version_contents('Marpa::XS', @marpa_xs_use);
$subclass_code .= 'END_OF_FILE' . "\n\n";

$subclass_code .= q{my $perl_version_pm = <<'END_OF_FILE';} . "\n";
$subclass_code .= version_contents('Marpa::XS::Perl', @marpa_xs_perl_use);
$subclass_code .= 'END_OF_FILE' . "\n\n";

$subclass_code .= q{my $version_string = '} . $marpa_xs_version . q{';};

$subclass_code .= <<'SUBCLASS';

    use IPC::Cmd;
    use File::Spec;
    use Config;
    use Fatal qw(open close mkdir);
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
    }

    sub ACTION_code {
        my $self = shift;
        $self->{verbose} = 1;
        $self->write_file($version_pm, qw(lib Marpa XS Version.pm) );
        $self->write_file($perl_version_pm, qw(lib Marpa XS Perl Version.pm) );
        $self->do_libmarpa();
        $self->SUPER::ACTION_code;
    }

    sub ACTION_clean {
        my $self = shift;

        my $curdir = File::Spec->rel2abs(File::Spec->curdir());
        my $libmarpa_dir = File::Spec->catdir($curdir, qw(inc libmarpa));
        chdir($libmarpa_dir) or Carp::croak("Cannot chdir to $libmarpa_dir");
        print "Cleaning libmarpa\n" if $self->verbose;
        print "Cannot run libmarpa make clean\n"
            if not IPC::Cmd::run( command => ['make', 'clean'] );
        chdir($curdir) or Carp::croak("Cannot chdir to $curdir");

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
    'inc/Marpa/XS/Version.pm',
    'inc/Marpa/XS/Perl/Version.pm',
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
    add_to_cleanup       => \@files_to_cleanup,
    dist_name            => 'Marpa-XS',
    dist_author          => 'Jeffrey Kegler',
    dist_version         => $marpa_xs_version,
    dist_abstract        => 'XS Version of Marpa (Experimental)',
    recommends           => \%recommends,
    requires             => \%requires,
    configure_requires   => \%configure_requires,
    build_requires       => \%build_requires,
    dynamic_config       => 1,
    extra_compiler_flags => "$glib_2_0_compiler_flags -Iinc/libmarpa",
    extra_linker_flags =>
        "$glib_2_0_linker_flags inc/libmarpa/.libs/libmarpa.a",
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
