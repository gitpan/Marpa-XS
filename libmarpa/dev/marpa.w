% Copyright 2010 Jeffrey Kegler
% This file is part of Marpa::XS.  Marpa::XS is free software: you can
% redistribute it and/or modify it under the terms of the GNU Lesser
% General Public License as published by the Free Software Foundation,
% either version 3 of the License, or (at your option) any later version.
%
% Marpa::XS is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
% Lesser General Public License for more details.
%
% You should have received a copy of the GNU Lesser
% General Public License along with Marpa::XS.  If not, see
% http://www.gnu.org/licenses/.

% Here is TeX material that gets inserted after \input cwebmac
\def\hang{\hangindent 3em\indent\ignorespaces}
\def\pb{$\.|\ldots\.|$} % C brackets (|...|)
\def\v{\char'174} % vertical (|) in typewriter font
\def\dleft{[\![} \def\dright{]\!]} % double brackets
\mathchardef\RA="3221 % right arrow
\mathchardef\BA="3224 % double arrow
\def\({} % ) kludge for alphabetizing certain section names
\def\TeXxstring{\\{\TEX/\_string}}
\def\skipxTeX{\\{skip\_\TEX/}}
\def\copyxTeX{\\{copy\_\TEX/}}

\def\title{Code for Marpa}
\def\topofcontents{\null\vfill
  \centerline{\titlefont Code for Marpa}
  \vfill}
\def\botofcontents{\vfill
\noindent
@i copyright_page_license.w
\bigskip
\leftline{\sc\today\ at \hours} % timestamps the contents page
}
% \datecontentspage

\pageno=\contentspagenumber \advance\pageno by 1
\let\maybe=\iftrue
@s not_eq normal @q unreserve a C++ keyword @>

@** Introduction.

The following abbreviations are used in Marpa's variable names:
\yskip \hang r for Recognizer.

\hang g for Grammar.

\hang recce for Recognizer.

\hang alloc for Allocate

\yskip \noindent

@ Include files

@<Body of C file@> =

#include "config.h"
#include "marpa.h"

@ |marpa.h| Include files

All the include files that users of Marpa
will need.

@<Body of |marpa.h| file@> =

#include <glib.h>
#include <obstack.h>
#include <stdio.h>

@ Constants

@<Body of C file@> =

@<Logging domain@>@/
@<Logging domain@>@/
@<Version constants@>@/

@ Structures at the top of |marpa.c|

@<Body of C file@> =

@<Private structures@>

@ Version Constants

@<Version constants@> =

const unsigned int marpa_major_version = MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version = MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version = MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age = MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age = MARPA_BINARY_AGE;

@ Return the version in a 3 element int array

@<Body of C file@> =

void marpa_version(int* version) {
        version[0] = MARPA_MAJOR_VERSION;
        version[1] = MARPA_MINOR_VERSION,
        version[2] = MARPA_MICRO_VERSION;
}

@

@<Public function prototypes@> =

void marpa_version(int* version);

@ Header file.

|GLIB_VAR| is to
prefix variable declarations so that they
will be exported properly for windows dlls.

@f GLIB_VAR const

@<Body of |marpa.h| file@> =

#ifndef __MARPA_H__
#define __MARPA_H__ @#

#include "glib.h" @#

GLIB_VAR const guint marpa_major_version;@/
GLIB_VAR const guint marpa_minor_version;@/
GLIB_VAR const guint marpa_micro_version;@/
GLIB_VAR const guint marpa_interface_age;@/
GLIB_VAR const guint marpa_binary_age;@#

#define MARPA_CHECK_VERSION(major,minor,micro) @| \
    @[ (MARPA_MAJOR_VERSION > (major) \
        @| || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION > (minor)) \
        @| || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION == (minor) \
        @|  && MARPA_MICRO_VERSION >= (micro)))
        @]@#

@<Development phase public macros@>@/
@<Public structures@>@/
@<Eventually private structures@>@/
@<Public function prototypes@>@/
@<Eventually inline function prototypes@>@/

@# #endif /* |MARPA_H| */

@ Marpa Global Setup

Marpa does no global initialization at the moment.
When it does, I need to be aware of the issue
of thread safety.

@ Development Phase Features

A number of macros are to support features that are
temporary -- shims and hacks to allow "test as I go"
development.
These macros, and the features they guard, are destined
for elimination in the final version.
In addition to the macros,
"development phase only" features include structure members.

@ |EVENTUALLY_INLINE|

Some functions that I intend to inline
cannot be inlined while
the XS iterface calls them directly.
Eventually they will be converted to internal
use only.
At that point the |EVENTUALLY_INLINE|
macro can be deleted.
As a transitional, test, measure it can
be defined as |static inline| -- that to make
sure nothing breaks.

@d EVENTUALLY_INLINE 

@<Body of C file@> =

@ |MARPA_DEVELOPMENT_PHASE|

@<Development phase public macros@> =

#define MARPA_DEVELOPMENT_PHASE 1@/

@ Grammar Objects

@ Symbol Objects

Temporarily just point to the SV.

@<Eventually private structures@> =

struct marpa_symbol {
#ifdef MARPA_DEVELOPMENT_PHASE@/
    void *SV;
#endif /* |MARPA_DEVELOPMENT_PHASE| */@/
};

@ Recognizer Objects

@<Public structures@> =

struct marpa_r {
    struct obstack stack;
#ifdef MARPA_DEVELOPMENT_PHASE@/
    void *SV;
#endif /* |MARPA_DEVELOPMENT_PHASE| */@/
};

@ Initialize Recognizer Object

@<Body of C file@> =

void marpa_r_init( struct marpa_r *recce)
{
    if (recce == (void *)NULL) {
        g_error("EIF No alloc routine in marpa allocator");
    }

    obstack_init(&recce->stack);

   return;

}

@

@<Public function prototypes@> =

void marpa_r_init( struct marpa_r *recce);

@ Free Recognizer Object

@<Body of C file@> =

void marpa_r_destroy(struct marpa_r *recce)
{
    obstack_free(&recce->stack, (void *)NULL);
}

@

@<Public function prototypes@> =

void marpa_r_destroy(struct marpa_r *recce);

@ Earley Item Objects

A lot of thought was given to potential optimizations,
but these all seem counter-production.
Principles to observe:
First,
optimization should favor unambiguous grammars,
without unduly penalizing ambiguous grammars.
Second,
optimization should favor mildly ambiguous grammars,
without unduly penalizing very ambiguous grammars.

Third,
optimization should focus on space, even at a some
cost in time.
This is because in practical applications
there can easily be many millions of
Earley items and links.
If there are 1M copies of a structure,
each byte saved is a 1M saved.

Nonetheless, the implementation below is
pretty straightforward.
Linked lists are chosen because they are easy on
space, and fast where prepending and full
traversal are the only operations.

Consideration was given to treating the one link case
as special, and including the first link in the Earley item.
But then the special case has to be tested for,
and that's pretty much a wash with the indirection.
Consideration was also given to putting the three kinds
of links (token, cause and Leo) into a single list.
But then a key has to included to separate them, so
that the space saved in the Earley item structure winds
up being used in the lists.

@<Eventually private structures@> =

struct marpa_earley_item {
    struct marpa_token_link *token_links;
    struct marpa_cause_link *cause_links;
    void *leo_links;
#ifdef MARPA_DEVELOPMENT_PHASE@/
    void *SV;
#endif /* |MARPA_DEVELOPMENT_PHASE| */@/
};

@ Initialize Earley Item Object

@<Body of C file@> =

EVENTUALLY_INLINE@/
struct marpa_earley_item* marpa_earley_item_new( struct marpa_r *recce)
{
    if (recce == (void *)NULL) {
        g_error("EIF No alloc routine in marpa allocator");
    }

    struct marpa_earley_item* item =
        obstack_alloc(&recce->stack, sizeof(struct marpa_earley_item));
    item->token_links = NULL;
    item->cause_links = NULL;
    item->leo_links = NULL;

   return item;

}

@

@<Eventually inline function prototypes@> =

struct marpa_earley_item* marpa_earley_item_new( struct marpa_r *recce);

@ Free Earley Item Object

A no-op.
The memory is freed with the recognizer.

@ Token Link Objects

@<Private structures@> =

struct marpa_token_link {
    struct marpa_token_link* next;
    struct marpa_earley_item* predecessor;
    struct marpa_symbol* symbol;
    void* value;
};

@ Add Token Link to Earley Item

@<Body of C file@> =

EVENTUALLY_INLINE@/
void
marpa_token_link_add(
    struct marpa_r* recce,
    struct marpa_earley_item* item,
    struct marpa_symbol *symbol,
    struct marpa_earley_item *predecessor,
    void *value
)
{
    struct marpa_token_link* next = item->token_links;
    struct marpa_token_link* new = item->token_links = 
        obstack_alloc(&recce->stack, sizeof(*next));
    new->next = next;
    new->symbol = symbol;
    new->predecessor = predecessor;
    new->value = value;
}

@

@<Eventually inline function prototypes@> =

void
marpa_token_link_add(
    struct marpa_r* recce,
    struct marpa_earley_item* item,
    struct marpa_symbol *symbol,
    struct marpa_earley_item *predecessor,
    void *value
);

@ Cause Link Objects

@<Private structures@> =

struct marpa_cause_link {
    struct marpa_cause_link* next;
    struct marpa_earley_item* predecessor;
    struct marpa_earley_item* cause;
};

@ Add Cause Link to Earley Item

@<Body of C file@> =

EVENTUALLY_INLINE@/
void
marpa_cause_link_add(
    struct marpa_r* recce,
    struct marpa_earley_item* item,
    struct marpa_earley_item* predecessor,
    struct marpa_earley_item* cause
)
{
    struct marpa_cause_link* next = item->cause_links;
    struct marpa_cause_link* new = item->cause_links = 
        obstack_alloc(&recce->stack, sizeof(*next));
    new->next = next;
    new->predecessor = predecessor;
    new->cause = cause;
}

@

@<Eventually inline function prototypes@> =

void
marpa_cause_link_add(
    struct marpa_r* recce,
    struct marpa_earley_item* item,
    struct marpa_earley_item* predecessor,
    struct marpa_earley_item* cause
);

@** Error and Message Logging.
Marpa uses the |glib| Message Logging framework.
Message logging is in the "Marpa" domain,
except for memory allocation.

@ Set the Logging Domain

@<Logging domain@> =

#undef G_LOG_DOMAIN@/
#define G_LOG_DOMAIN "Marpa"@/

@ Memory allocation

Marpa uses |g_malloc| for memory allocation.
Marpa already depends on |glib|, and |g_malloc| plays
nicely with that, but is also highly
configurable.

One consequence is that a memory allocation
inside the Marpa library is a fatal error.
This error is logged in the domain that |g_malloc|
is using, instead of in the Marpa domain.
Memory allocation
errors are not usually treated as recoverable in modern
applications.
An application that does not want Marpa abending on its
behalf can
configure |g_malloc| to use its own allocator.

@ Obstack

Marpa uses obstack on top of |g_malloc|.
Right now Marpa uses obstack unchanged.
As an alternative, I could hack |obstack.c| and
|obstack.h| to take advantage of the fact that
they always call |g_malloc|, and that memory
allocation never returns failure.
This would save two Boolean tests and an indirection
per allocation.
That is not a big deal these days (perhaps not even
measurable) but if other reasons come up for Marpa
to "roll its own" obstack,
it's something to consider.

@d obstack_chunk_alloc g_malloc
@d obstack_chunk_free g_free


@ A test routine.

This was a version compatibility checker.
I no longer use it as such, but keep it around as a simple
test routine, one slightly less trivial than |marpa_version|.

@<Body of C file@> =

static char output_buffer[1000];

const char *
marpa_check_version (unsigned int required_major,
                    unsigned int required_minor,
                    unsigned int required_micro)
{
  int marpa_effective_micro = 1000 * MARPA_MINOR_VERSION + MARPA_MICRO_VERSION;
  int required_effective_micro = 1000 * required_minor + required_micro;

  @<Return message if major version too old@>@/
  @<Return message if major version too new@>@/
  @<Return message if minor/micro version too new@>@/
  @<Return message if minor/micro version too old@>@/

  return "Perfect!";
}

@

@<Public function prototypes@> = 
const char *
marpa_check_version (unsigned int required_major,
                    unsigned int required_minor,
                    unsigned int required_micro);

@ Is the major version too old?

@<Return message if major version too old@> =

  if (required_major > MARPA_MAJOR_VERSION) {
    sprintf(output_buffer, "marpa major version too old: "
    "require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        MARPA_MAJOR_VERSION,
        MARPA_MINOR_VERSION,
        MARPA_MICRO_VERSION);
    return output_buffer;
  }

@ Is the major version too new?

@<Return message if major version too new@> =

  if (required_major < MARPA_MAJOR_VERSION) {
    sprintf(output_buffer,
    "marpa major version too new: "
    "require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        MARPA_MAJOR_VERSION,
        MARPA_MINOR_VERSION,
        MARPA_MICRO_VERSION);
    return output_buffer;
  }


@ Is the minor/micro version too new?

@<Return message if minor/micro version too new@> =

  if (required_effective_micro < marpa_effective_micro) {
    sprintf(output_buffer,
        "marpa minor/micro version too new: "
        "require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        MARPA_MAJOR_VERSION,
        MARPA_MINOR_VERSION,
        MARPA_MICRO_VERSION);
    return output_buffer;
  }


@ Is the minor/micro version too old?

@<Return message if minor/micro version too old@> =
  if (required_effective_micro > marpa_effective_micro) {
    sprintf(
        output_buffer,
        "marpa minor/micro version too old: "
        "require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        MARPA_MAJOR_VERSION,
        MARPA_MINOR_VERSION,
        MARPA_MICRO_VERSION);
    return output_buffer;
  }

@ Prematter

Force the beginning the tangle output to contain a comment to the
effect that it is not intended to be edited directly.

Also, even though the output are not source file,
add the license to them anyway.

@ The physical structure of the |marpa.c| file

@q This is a hack to get the @>
@q license language nearer the top of the files. @>

@c
@=/*@>@/
@= * Copyright 2010 Jeffrey Kegler@>@/
@= * This file is part of Marpa::XS.  Marpa::XS is free software: you can@>@/
@= * redistribute it and/or modify it under the terms of the GNU Lesser@>@/
@= * General Public License as published by the Free Software Foundation,@>@/
@= * either version 3 of the License, or (at your option) any later version.@>@/
@= *@>@/
@= * Marpa::XS is distributed in the hope that it will be useful,@>@/
@= * but WITHOUT ANY WARRANTY; without even the implied warranty of@>@/
@= * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU@>@/
@= * Lesser General Public License for more details.@>@/
@= *@>@/
@= * You should have received a copy of the GNU Lesser@>@/
@= * General Public License along with Marpa::XS.  If not, see@>@/
@= * http://www.gnu.org/licenses/.@>@/
@= */@>@/
@=/*@>@/
@= * DO NOT EDIT DIRECTLY@>@/
@= * This file is written by ctangle@>@/
@= * It is not intended to be modified directly@>@/
@= */@>@/

@h

@<Body of C file@>

@ The physical structure of the |marpa.h| file

@q Separating out the prematter.w file is a hack to get the @>
@q license language nearer the top of the files. @>

@(marpa.h@> =
@=/*@>@/
@= * Copyright 2010 Jeffrey Kegler@>@/
@= * This file is part of Marpa::XS.  Marpa::XS is free software: you can@>@/
@= * redistribute it and/or modify it under the terms of the GNU Lesser@>@/
@= * General Public License as published by the Free Software Foundation,@>@/
@= * either version 3 of the License, or (at your option) any later version.@>@/
@= *@>@/
@= * Marpa::XS is distributed in the hope that it will be useful,@>@/
@= * but WITHOUT ANY WARRANTY; without even the implied warranty of@>@/
@= * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU@>@/
@= * Lesser General Public License for more details.@>@/
@= *@>@/
@= * You should have received a copy of the GNU Lesser@>@/
@= * General Public License along with Marpa::XS.  If not, see@>@/
@= * http://www.gnu.org/licenses/.@>@/
@= */@>@/
@=/*@>@/
@= * DO NOT EDIT DIRECTLY@>@/
@= * This file is written by ctangle@>@/
@= * It is not intended to be modified directly@>@/
@= */@>@/

@<Body of |marpa.h| file@>

@** Index.


