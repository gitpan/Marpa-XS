% This file is part of CWEB.
% This program by Silvio Levy and Donald E. Knuth
% is based on a program by Knuth.
% It is distributed WITHOUT ANY WARRANTY, express or implied.
% Version 3.64 --- January 2002

% Copyright (C) 1987,1990,1993,2000 Silvio Levy and Donald E. Knuth

% Permission is granted to make and distribute verbatim copies of this
% document provided that the copyright notice and this permission notice
% are preserved on all copies.

% Permission is granted to copy and distribute modified versions of this
% document under the conditions for verbatim copying, provided that the
% entire resulting derived work is given a different name and distributed
% under the terms of a permission notice identical to this one.

\def\v{\char'174} % vertical (|) in typewriter font

\def\title{Common code for CTANGLE and CWEAVE (Version 3.64)}
\def\topofcontents{\null\vfill
  \centerline{\titlefont Common code for {\ttitlefont CTANGLE} and
    {\ttitlefont CWEAVE}}
  \vskip 15pt
  \centerline{(Version 3.64)}
  \vfill}
\def\botofcontents{\vfill
\noindent
Copyright \copyright\ 1987, 1990, 1993, 2000 Silvio Levy and Donald E. Knuth
\bigskip\noindent
Permission is granted to make and distribute verbatim copies of this
document provided that the copyright notice and this permission notice
are preserved on all copies.

\smallskip\noindent
Permission is granted to copy and distribute modified versions of this
document under the conditions for verbatim copying, provided that the
entire resulting derived work is given a different name and distributed
under the terms of a permission notice identical to this one.
}

\pageno=\contentspagenumber \advance\pageno by 1
\let\maybe=\iftrue

@** Introduction.

@c

#include <glib.h>
#include <stdio.h>

#include "config.h"
#include "utils.h"

const unsigned int libmarpa_major_version = LIBMARPA_MAJOR_VERSION;
const unsigned int libmarpa_minor_version = LIBMARPA_MINOR_VERSION;
const unsigned int libmarpa_micro_version = LIBMARPA_MICRO_VERSION;
const unsigned int libmarpa_interface_age = LIBMARPA_INTERFACE_AGE;
const unsigned int libmarpa_binary_age = LIBMARPA_BINARY_AGE;

@ |libmarpa_check_version|:
|required_major|: the required major version.
|required_minor|: the required minor version.
|required_micro|: the required micro version.
 
Checks that the libmarpa library in use is compatible with the
given version. Generally you would pass in the constants
|LIBMARPA_MAJOR_VERSION, LIBMARPA_MINOR_VERSION, LIBMARPA_MICRO_VERSION|
as the three arguments to this function; that produces
a check that the library in use is compatible with
the version of libmarpa the application or module was compiled
against.

Compatibility is defined by two things: first the version
of the running library is newer than the version
|required_major.required_minor.required_micro|.
Second
the running library must be binary compatible with the
version
|required_major.required_minor.required_micro|
(same major version.)

Return value: |NULL| if the libmarpa library is compatible with the
given version, or a string describing the version mismatch.
The returned string is owned by libmarpa and must not be modified
or freed.

@c

static char output_buffer[1000];

const char *
libmarpa_check_version (unsigned int required_major,
                    unsigned int required_minor,
                    unsigned int required_micro)
{
  int libmarpa_effective_micro = 1000 * LIBMARPA_MINOR_VERSION + LIBMARPA_MICRO_VERSION;
  int required_effective_micro = 1000 * required_minor + required_micro;

  if (required_major > LIBMARPA_MAJOR_VERSION) {
    sprintf(output_buffer, "libmarpa major version too old: "
    "require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        LIBMARPA_MAJOR_VERSION,
        LIBMARPA_MINOR_VERSION,
        LIBMARPA_MICRO_VERSION);
    return output_buffer;
  }

  if (required_major < LIBMARPA_MAJOR_VERSION) {
    sprintf(output_buffer,
    "libmarpa major version too new: "
    "require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        LIBMARPA_MAJOR_VERSION,
        LIBMARPA_MINOR_VERSION,
        LIBMARPA_MICRO_VERSION);
    return output_buffer;
  }

@ Not sure what was going on here
| if (required_effective_micro < libmarpa_effective_micro - LIBMARPA_BINARY_AGE) |
| return "libmarpa version too new (micro mismatch)"; |

@c

  if (required_effective_micro < libmarpa_effective_micro) {
    sprintf(output_buffer,
        "libmarpa minor/micro version too new: "
        "require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        LIBMARPA_MAJOR_VERSION,
        LIBMARPA_MINOR_VERSION,
        LIBMARPA_MICRO_VERSION);
    return output_buffer;
  }

  if (required_effective_micro > libmarpa_effective_micro) {
    sprintf(
        output_buffer,
        "libmarpa minor/micro version too old: "
        "require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        LIBMARPA_MAJOR_VERSION,
        LIBMARPA_MINOR_VERSION,
        LIBMARPA_MICRO_VERSION);
    return output_buffer;
  }

  return "Perfect!";
}

