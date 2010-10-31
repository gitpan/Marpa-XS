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

\def\li{\item{$\bullet$}}

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
@s gboolean int
@s Marpa_Rule_ID int
@s Marpa_Symbol_ID int
@s GArray int

@** Introduction.

@*2 Naming conventions.

External Names have |marpa_| or |MARPA_| as their prefix,
as appropriate under the capitalization conventions.
Many names begin with one of the major "objects" of Marpa:
grammars, recognizers, symbols, etc.
Names of functions typically end with a verb.

Names of booleans are of the form |is_x|, where |x| is some
property.  For example, the element of the symbol structure
which indicates whether the symbol is a terminal or not,
is |is_terminal|.
Boolean names are chosen so that the |TRUE| or |FALSE|
value corresponds correctly to the question implied by the
name.
The most important thing is for the names to be as
accurate as possible consistent with brevity.
Where possible, consistent with brevity and accuracy,
positive names (|is_found|) are preferred
to negative names (|is_not_lost|).

For function names, some final verbs have special meanings.

\li |j_f_get| returns field |f| of object |j|.
It is an internal function, and often will be declared
|static inline|.

\li |j_f_put| assigns a value to field |f| of object |j|.
It is an internal function, and often will be declared
|static inline|.

\li |marpa_j_f_peek| returns field |f| of object |j|.
It is an external equivalent of |j_f_get|.
The returned value is still owned by object |j| -- it should
not be modified or freed.

\li |marpa_j_f_set| sets field |f| of object |j|.
It's the external equivalent of |j_f_put|.

\li |marpa_j_f_value| returns field |f| of object |j|.
It is an external equivalent of |j_f_get|.
The returned value is owned by the caller.
If it is a pointer, it points to memory which must
be freed with |g_splice_free|.

@*2 Abbreviations.

The following abbreviations are used in Marpa's variable names:

\li g for Grammar
\li r for Recognizer
\li recce for Recognizer
\li alloc for Allocate

@*2 Development Plans.

These are notes to myself,
most of which will only be relevant
while |libmarpa| is being written.
Most of these notes will be revised
and then deleted as development proceeds.

@*3 Short Term To Do List.

\li Rewrite Leo link coversion code before converting 
from Perl.

@*3 Long Term To Do List.

\li When symbols and rules are no longer Perl objects,
have them destroyed when the Grammar object is destroyed.

@*3 Development Phase Features.

A number of macros are to support features that are
temporary -- shims and hacks to allow "test as I go"
development.
These macros, and the features they guard, are destined
for elimination in the final version.
In addition to the macros,
"development phase only" features include structure members.

@ Development Phase Macros
@s MARPA_SHIM const
@<Development phase public macros@> =
#define MARPA_SHIM @/

@*3 Development Note: Marpa layers.

|libmarpa|, implemented here is intended as the bottom of potentially
four layers.
The others are, from low to high, the glue layer, the wrapper layer,
and the application.

This glue layer will be in C and will call the |libmarpa| routines
in a way that makes them compatible with another language.
I expect this will usually be a 4GL (4th generation language),
such as Perl.
One example of a glue description lanuage is SWIG.
Another is Perl XS, and currently that is
the only glue layer implemented for |libmarpa|.

|libmarpa| itself is not enormously user-
or application-friendly.
For example, in |libmarpa|, symbols do not have
names, just symbol structures and symbol ID's.
These are all that is needed for the data crunching,
but an application writer will usually want a friendlier
interface, including names for the symbols and
many other conveniences.
For this reason, applications will typically
use |libmarpa| through a {\bf wrapper package}.
Currently the only such package is in Perl.

The top layer is the application.
My expectation is that this will also be in a 4GL.
Currently, |libmarpa|'s only application are
in Perl.

Not all these layers need be present.
For example, it is conceivable that someone might
write their application in C, in which case they could
manage without minimal or no
glue layers or package layers.

Iterfaces between layers are named after the lower
of the two layers.  For example the interface between
|libmarpa| and the glue layer is the |libmarpa| interface.

@*3 Development Note: Representing Objects.
Representation of objects is most commonly in one
of three forms: cookies, ID's or pointers to C structures.
A lot of thought went into which is used where.

@*4 Object ID's.
Object ID's are integers.  They are always issued in sequence.
They are guaranteed unique.
(Note that in C,
pointers to identical objects do {\bf not} necessarily
compare equal.)
If desired, they can be checked easily without risking a memory
violation.

ID's are the only object representation
that can be used in any layer or any interface,
and they are the preferred for the application layer
and the package interface.

Wraparound issues for object ID's are ignored.
By the time any object ID wraps, memory will have long
since overflowed.

@*4 Object Cookies.
Object cookies represent objects in a way that is convenient
and safe in the application layer, which will usually be a 4GL.
Right now it is Perl.
Object cookies are only used when programs which
respect the cookie's integrity
cannot cause memory violations in the |libmarpa|
and glue layers,
even if those programs have programming errors.

"Respecting the cookie's integrity", means not
accessing its internal contents -- using the
cookie only as a cookie.
The overall idea is that,
if an programmer 
writes trick-free higher-level code
using cookies,
any resulting errors occur
in the package or application layer.

The contents of Object Cookies are dependent on
the choice of higher-level language (HLL).
For this reason,
The cookies are never visible in the |libmarpa| layer.

In Perl's cookies, a major consideration is ensuring
that, during the lifetime of a cookie,
all the objects implied by the cookie also exist.
This means that so long as
a recognizer object cookie exists,
the underlying grammar cannot be destroyed.

@*4 Object pointers.
The most efficient representation of objects
are pointers to structures.
These are the main representation of objects
in the |libmarpa| layer.
These must not be visible in the package and application
layers.

With regard to the visibility of object pointers in the
glue layer, the situation is more complicated.
At this writing, I expect to make pointers
to most structures
completely invisible except inside |libmarpa|.
The external accessors do allow the glue layer
some access
to |libmarpa|'s internal structures.
But in the case of the |_peek|
external accessors,
it is intuitive that the memory is owned
by the |libmarpa| layer,
and expected that any use of it will be quick.

In the case of object pointers, their expected ordinary
use is be kept around to refer to the object.
But, for example, symbol object pointers must not
be freed by the glue layer, but will become invalid
when their associated grammar layer is destroyed.

This behavior is not completely unintuitive to an
experienced C programmer -- functions (like |ctime|)
which return
transient information in memory unowned by the caller
have a long tradition in UNIX.
But these are now deprecated.

But tracking the lifetime of symbol object pointers 
in the glue layer
would be tricky, so as this writing the thought is to
avoid the issue, for it and most other object pointers.
The exceptions are grammar and recognizer objects.
The base objects for these {\bf are} owned by
the glue layer, so these do not present the same
issues.
The glue layer creates
grammar and recognizer objects,
it owns them during their lifetime,
and it is up to the glue layer to destroy them.

@*3 Development Note: Converting Elements.
\li Init the data element.

\li Add a destructor.
At first arrange for this to be called when the Perl object
is destroyed.
Add a comment in the place where the destructor must eventually
be called, as a reminder.
This will usually be in the Recognizer or Grammar destructor.

\li {Add whatever mutators are needed,
initially as un-inlined externals.
Mark these with the |MARPA_SHIM| define.
At the end of development, it should be possible to
|#define| |MARPA_SHIM| as |static inline|,
or to simply replace |MARPA_SHIM| with
|static inline|.
\tolerance=9999\par}

\li Now that there are a full set of initializers,
destructors and mutators,
change the Perl code so that it updates both the Perl and C elements.
In other words, have the C element "shadow" the Perl element.

\li Create an internal and an external "accessor".
The external accessor is
to be used by the XS code, and by the debugging and diagnostics.
The internal accessor, declared |static internal| is for "production" uses.
For elements used only in diagnostics and debugging, no internal accessor need ever be
created.

\li
Convert all Perl code to use the external accessor of the C element.

\li Eliminate all accesses to the Perl element.

\li Eliminate the Perl element.

@*3 Development Note: Converting Objects.

\li First, all elements of an object must be converted to C,
as described above.

\li
Next, all "production" code referring to the object must be converted to C.
This probably requires the conversion of other objects to be well along.
In this context, "production" is all code except for code which does debugging,
diagnostic and "utility" functions.
Right now the only "utility" function I can think of is cloning.

\li
If the object is not a Grammar or a Recognizer,
recode the external interface so that
it no longer requires a Perl version
of the object.
Ultimately only the 
Grammar and Recognizer Perl objects will remain.

\li
Remember to use external accessors in XS,
debugging, diagnostic and cloning
code, and the internal accessors in the main routine.

\li When an object is converted to C, it's destructor will no
longer be called in the course of destroying the Perl object.
Make sure the destructor will be called when necessary.
This will usually be when the Recognizer or Grammar object is destroyed.

@*2 Memory Allocation.

Starting out I'll allocate with |g_malloc| and possible |g_slice|.
Once other stuff is in shape, I may consider selective use of the
obstack's.
A lot of the memory in the recognizer is small allocations, never
resized, which are not freed until the recognizer is discarded.
These allocations are good candidates for obstacks.

By default,
a memory allocation failure
inside the Marpa library is a fatal error.
If this is a problem, the application can change
configure |g_malloc| to use its own allocator
which does something else on failure.
What else an application can do is not at all clear,
which is why the usual practice 
is to treatment memory allocation errors are
fatal, irrecoverable problems.

An error
in memory allocation will be logged
in the domain that |g_malloc|
is using, not in the domain being used by Marpa.

@ |marpa.h| Include files

All the include files that users of Marpa
will need.

@<Body of public header file@> =

#include <glib.h>
#include <stdio.h>

@ Private structures

None yet.
While there are none,
this stub prevents \TeX\ from failing.

@<Private structures@> =

@ Constants

@ Version Constants

@<Version constants@> =

const unsigned int marpa_major_version = MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version = MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version = MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age = MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age = MARPA_BINARY_AGE;

@ Return the version in a 3 element int array

@<Function definitions@> =

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
will be exported properly for Windows dlls.

@f GLIB_VAR const

@<Body of public header file@> =

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

#define MARPA_CAT(a, b) @[ a ## b @]

@<Inlining macros@>

@<Public typedefs@>@/
@<Public structures@>@/
@<Public function prototypes@>@/

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE

@<Public inline function definitions@>@/

#endif

@# #endif /* |MARPA_H| */

@ Marpa Global Setup

Marpa does no global initialization at the moment.
I'll try to keep it that way.
If I can't, I will need to deal with the issue
of thread safety.

@** Grammar Objects.

@<Public structures@> =

struct marpa_g {
@<Pointer aligned grammar elements@>
};

@ @<Function definitions@> =
void marpa_g_init( struct marpa_g *g)
{ if (g == (void *)NULL) {
        g_error("E_NULL_R Cannot initialize null grammar");
    }
    @<Initialize grammar elements@>@;
   return; }
@ @<Public function prototypes@> =
void marpa_g_init( struct marpa_g *g);

@ @<Function definitions@> =
void marpa_g_destroy(struct marpa_g *g)
{ @<Destroy grammar elements@>@; }
@ @<Public function prototypes@> =
void marpa_g_destroy(struct marpa_g *g);

@ The Grammar's Symbol List:
This lists the symbols for the grammar,
with their |Marpa_Symbol_ID| as the index.
@<Pointer aligned grammar elements@> = GArray* symbols;
@ @<Initialize grammar elements@> =
g->symbols = g_array_new(FALSE, FALSE, sizeof(struct marpa_symbol *));
@ @<Destroy grammar elements@> = g_array_free(g->symbols, TRUE);

@ The trace accessor returns the GArray.
It remains "owned" by the Grammar,
and must not be freed or modified.
@<Function definitions@> =
GArray *marpa_g_symbols_peek(struct marpa_g* g)
{ return g->symbols; }
@ @<Public function prototypes@> =
GArray *marpa_g_symbols_peek(struct marpa_g* g);

@ Internal accessor to find a symbol by its id.
@<Function definitions@> =
static inline struct marpa_symbol*
symbol_id2p(struct marpa_g* g, Marpa_Symbol_ID id)
{ return ((struct marpa_symbol **)g->symbols->data)[id]; }
@ @<Private function prototypes@> =
static inline struct marpa_symbol*
symbol_id2p(struct marpa_g* g, Marpa_Symbol_ID id);

@ Adds the symbol to the list of symbols kept by the Grammar
object.
@<Private inline functions@> =
static inline
void marpa_g_symbol_add(
    struct marpa_g *g,
    Marpa_Symbol_ID symbol_id,
    struct marpa_symbol*symbol)
{
    g_array_insert_val(g->symbols, symbol_id, symbol);
}

@ Check that symbol is in valid range.
@<Function definitions@> =
static inline gint symbol_is_valid(
struct marpa_g *g, Marpa_Symbol_ID symbol_id) {
return symbol_id < g->symbols->len && symbol_id >= 0;
}
@ @<Private function prototypes@> =
static inline gint symbol_is_valid(
struct marpa_g *g, Marpa_Symbol_ID symbol_id);

@ The Grammar's Rule List:
This lists the rules for the grammar,
with their |Marpa_Rule_ID| as the index.
@<Pointer aligned grammar elements@> = GArray* rules;
@ @<Initialize grammar elements@> =
g->rules = g_array_new(FALSE, FALSE, sizeof(struct marpa_rule *));
@ @<Destroy grammar elements@> = g_array_free(g->rules, TRUE);

@ The trace accessor returns the GArray.
It remains "owned" by the Grammar,
and must not be freed or modified.
@<Function definitions@> =
GArray *marpa_g_rules_peek(struct marpa_g* g)
{ return g->rules; }
@ @<Public function prototypes@> =
GArray *marpa_g_rules_peek(struct marpa_g* g);

@ Internal accessor to find a rule by its id.
@<Function definitions@> =
static inline struct marpa_rule*
rule_id2p(struct marpa_g* g, Marpa_Rule_ID id)
{ return ((struct marpa_rule **)g->rules->data)[id]; }
@ @<Private function prototypes@> =
static inline struct marpa_rule*
rule_id2p(struct marpa_g* g, Marpa_Rule_ID id);

@ Adds the rule to the list of rules kept by the Grammar
object.
@<Private inline functions@> =
static inline
void marpa_g_rule_add(
    struct marpa_g *g,
    Marpa_Rule_ID rule_id,
    struct marpa_rule*rule)
{
    g_array_insert_val(g->rules, rule_id, rule);
}

@** Recognizer Objects.

@<Public structures@> =
struct marpa_r {
    int dummy; /* until I get some contents */
};

@ Initialize Recognizer Object
@<Function definitions@> =
void marpa_r_init( struct marpa_r *recce)
{
    if (recce == (void *)NULL) {
        g_error("EIF No alloc routine in marpa allocator");
    }

   return;

}

@ @<Public function prototypes@> =
void marpa_r_init( struct marpa_r *recce);
@ @<Function definitions@> =
void marpa_r_destroy(struct marpa_r *recce) { }
@ @<Public function prototypes@> =
void marpa_r_destroy(struct marpa_r *recce);

@** Symbol Objects.
@<Public typedefs@> =
typedef gint Marpa_Symbol_ID;
@ @<Private structures@> =
struct marpa_symbol {
    @<Pointer aligned symbol elements@>@/
    @<Int aligned symbol elements@>@/
    @<Bitfield symbol elements@>@/
};

@ @<Function definitions@> =
static inline
struct marpa_symbol* symbol_new(struct marpa_g *g)
{
    struct marpa_symbol* symbol = g_malloc(sizeof(struct marpa_symbol));
    @<Initialize symbol elements@>@/
    marpa_g_symbol_add(g, symbol->id, symbol);
   return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g *g)
{
    return symbol_new(g)->id;
}

@ @<Private function prototypes@> =
static inline
struct marpa_symbol* symbol_new(struct marpa_g *g);
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g *g);

@ @<Destroy grammar elements@> =
{  int id; for (id = 0; id < g->symbols->len; id++)
{ marpa_symbol_free(symbol_id2p(g, id)); } }
@ @<Function definitions@> =
static inline void marpa_symbol_free(struct marpa_symbol* symbol)
{ @<Free symbol elements@>@; g_free(symbol); }
@ @<Private function prototypes@> =
static inline void marpa_symbol_free(struct marpa_symbol* symbol);

@ Symbol ID: This is the unique identifier for the symbol.
@<Int aligned symbol elements@> = Marpa_Symbol_ID id;
@ @<Initialize symbol elements@> = symbol->id = g->symbols->len;

@ Symbol LHS Rules Element:
This tracks the rules for which this symbol is the LHS.
It is an optimization --- the same information could be found
by scanning the rules every time this information is needed.
The implementation is a |GArray|.
@<Pointer aligned symbol elements@> = GArray* lhs;
@ @<Initialize symbol elements@> =
symbol->lhs = g_array_new(FALSE, FALSE, sizeof(Marpa_Rule_ID));
@ @<Free symbol elements@> = g_array_free(symbol->lhs, TRUE);
@ The trace accessor returns the GArray.
It remains "owned" by the Grammar,
and must not be freed or modified.
Right now this function uses a pointer
to the symbol function.
If that becomes private,
the prototype of this function
must be changed.
@<Function definitions@> = 
GArray *marpa_symbol_lhs_peek(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->lhs; }
@ @<Public function prototypes@> =
GArray *marpa_symbol_lhs_peek(struct marpa_g* g, Marpa_Symbol_ID id);
@ @<Function definitions@> = static inline
void symbol_lhs_add(struct marpa_symbol*symbol, Marpa_Rule_ID rule_id)
{ g_array_append_val(symbol->lhs, rule_id); }
void marpa_symbol_lhs_add(struct marpa_g*g, Marpa_Symbol_ID symbol_id, Marpa_Rule_ID rule_id)
{ symbol_lhs_add(symbol_id2p(g, symbol_id), rule_id); }
@ @<Private function prototypes@> = static inline
void symbol_lhs_add(struct marpa_symbol*symbol, Marpa_Rule_ID rule_id);
@ @<Public function prototypes@> =
void marpa_symbol_lhs_add(struct marpa_g*g, Marpa_Symbol_ID symbol_id, Marpa_Rule_ID rule_id);

@ Symbol RHS Rules Element:
This tracks the rules for which this symbol is the RHS.
It is an optimization --- the same information could be found
by scanning the rules every time this information is needed.
The implementation is a |GArray|.
@<Pointer aligned symbol elements@> = GArray* rhs;
@ @<Initialize symbol elements@> =
symbol->rhs = g_array_new(FALSE, FALSE, sizeof(Marpa_Rule_ID));
@ @<Free symbol elements@> = g_array_free(symbol->rhs, TRUE);
@ The trace accessor returns the GArray.
It remains "owned" by the Grammar,
and must not be freed or modified.
Right now this function uses a pointer
to the symbol function.
If that becomes private,
the prototype of this function
must be changed.
@<Function definitions@> = 
GArray *marpa_symbol_rhs_peek(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->rhs; }
@ @<Public function prototypes@> =
GArray *marpa_symbol_rhs_peek(struct marpa_g* g, Marpa_Symbol_ID id);
@ @<Function definitions@> = static inline
void symbol_rhs_add(struct marpa_symbol*symbol, Marpa_Rule_ID rule_id)
{ g_array_append_val(symbol->rhs, rule_id); }
void marpa_symbol_rhs_add(struct marpa_g*g, Marpa_Symbol_ID symbol_id, Marpa_Rule_ID rule_id)
{ symbol_rhs_add(symbol_id2p(g, symbol_id), rule_id); }
@ @<Private function prototypes@> = static inline
void symbol_rhs_add(struct marpa_symbol*symbol, Marpa_Rule_ID rule_id);
@ @<Public function prototypes@> =
void marpa_symbol_rhs_add(struct marpa_g*g, Marpa_Symbol_ID symbol_id, Marpa_Rule_ID rule_id);

@ Symbol Is Accessible Boolean
@<Bitfield symbol elements@> = unsigned int is_accessible:1;
@ @<Initialize symbol elements@> =
symbol->is_accessible = FALSE;
@ The trace accessor returns the Boolean value.
Right now this function uses a pointer
to the symbol function.
If that becomes private,
the prototype of this function
must be changed.
\par
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_symbol_is_accessible_value(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_accessible; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_accessible_value(struct marpa_g* g, Marpa_Symbol_ID id);
@ The external mutator is temporary, for development.
@<Function definitions@> =
void marpa_symbol_is_accessible_set(
struct marpa_g*g, Marpa_Symbol_ID id, gboolean value)
{ symbol_id2p(g, id)->is_accessible = value; }
@ @<Public function prototypes@> =
/* static inline */
void marpa_symbol_is_accessible_set( struct marpa_g*g, Marpa_Symbol_ID id, gboolean value);

@ Symbol Is Counted Boolean
@<Bitfield symbol elements@> = unsigned int is_counted:1;
@ @<Initialize symbol elements@> =
symbol->is_counted = FALSE;
@ The trace accessor returns the Boolean value.
Right now this function uses a pointer
to the symbol function.
If that becomes private,
the prototype of this function
must be changed.
\par
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_symbol_is_counted_value(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_counted; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_counted_value(struct marpa_g* g, Marpa_Symbol_ID id);
@ The external mutator is temporary, for development.
@<Function definitions@> =
void marpa_symbol_is_counted_set(
struct marpa_g*g, Marpa_Symbol_ID id, gboolean value)
{ symbol_id2p(g, id)->is_counted = value; }
@ @<Public function prototypes@> =
/* static inline */
void marpa_symbol_is_counted_set( struct marpa_g*g, Marpa_Symbol_ID id, gboolean value);

@ Symbol Is Nullable Boolean
@<Bitfield symbol elements@> = unsigned int is_nullable:1;
@ @<Initialize symbol elements@> =
symbol->is_nullable = FALSE;
@ The trace accessor returns the Boolean value.
Right now this function uses a pointer
to the symbol function.
If that becomes private,
the prototype of this function
must be changed.
\par
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_symbol_is_nullable_value(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_nullable; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_nullable_value(struct marpa_g* g, Marpa_Symbol_ID id);
@ The external mutator is temporary, for development.
@<Function definitions@> =
void marpa_symbol_is_nullable_set(
struct marpa_g*g, Marpa_Symbol_ID id, gboolean value)
{ symbol_id2p(g, id)->is_nullable = value; }
@ @<Public function prototypes@> =
void marpa_symbol_is_nullable_set( struct marpa_g*g, Marpa_Symbol_ID id, gboolean value);

@ Symbol Is Nulling Boolean
@<Bitfield symbol elements@> = unsigned int is_nulling:1;
@ @<Initialize symbol elements@> =
symbol->is_nulling = FALSE;
@ The trace accessor returns the Boolean value.
Right now this function uses a pointer
to the symbol function.
If that becomes private,
the prototype of this function
must be changed.
\par
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_symbol_is_nulling_value(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_nulling; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_nulling_value(struct marpa_g* g, Marpa_Symbol_ID id);
@ The external mutator is temporary, for development.
@<Function definitions@> =
void marpa_symbol_is_nulling_set(
struct marpa_g*g, Marpa_Symbol_ID id, gboolean value)
{ symbol_id2p(g, id)->is_nulling = value; }
@ @<Public function prototypes@> = 
void marpa_symbol_is_nulling_set( struct marpa_g*g, Marpa_Symbol_ID id, gboolean value);

@ Symbol Is Terminal Boolean
@<Bitfield symbol elements@> = unsigned int is_terminal:1;
@ @<Initialize symbol elements@> =
symbol->is_terminal = FALSE;
@ The trace accessor returns the Boolean value.
Right now this function uses a pointer
to the symbol function.
If that becomes private,
the prototype of this function
must be changed.
\par
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_symbol_is_terminal_value(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_terminal; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_terminal_value(struct marpa_g* g, Marpa_Symbol_ID id);
@ The external mutator is temporary, for development.
@<Function definitions@> =
void marpa_symbol_is_terminal_set(
struct marpa_g*g, Marpa_Symbol_ID id, gboolean value)
{ symbol_id2p(g, id)->is_terminal = value; }
@ @<Public function prototypes@> =
void marpa_symbol_is_terminal_set( struct marpa_g*g, Marpa_Symbol_ID id, gboolean value);


@ Symbol Is Productive Boolean
@<Bitfield symbol elements@> = unsigned int is_productive:1;
@ @<Initialize symbol elements@> =
symbol->is_productive = FALSE;
@ The trace accessor returns the Boolean value.
Right now this function uses a pointer
to the symbol function.
If that becomes private,
the prototype of this function
must be changed.
\par
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_symbol_is_productive_value(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_productive; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_productive_value(struct marpa_g* g, Marpa_Symbol_ID id);
@ The external mutator is temporary, for development.
@<Function definitions@> =
void marpa_symbol_is_productive_set(
struct marpa_g*g, Marpa_Symbol_ID id, gboolean value)
{ symbol_id2p(g, id)->is_productive = value; }
@ @<Public function prototypes@> =
void marpa_symbol_is_productive_set( struct marpa_g*g, Marpa_Symbol_ID id, gboolean value);

@ Symbol Is Start Boolean
@<Bitfield symbol elements@> = unsigned int is_start:1;
@ @<Initialize symbol elements@> = symbol->is_start = FALSE;
@ Accessor: The trace accessor returns the Boolean value.
Right now this function uses a pointer
to the symbol function.
If that becomes private,
the prototype of this function
must be changed.
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
static inline
gboolean symbol_is_start_value(struct marpa_symbol* symbol)
{ return symbol->is_start; }
gboolean marpa_symbol_is_start_value( struct marpa_g*g, Marpa_Symbol_ID id) {
   return symbol_is_start_value(symbol_id2p(g, id));
}
@ @<Private function prototypes@> =
static inline
gboolean symbol_is_start_value(struct marpa_symbol* symbol);
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_start_value( struct marpa_g*g, Marpa_Symbol_ID id);
@ The external mutator is temporary, for development.
@<Function definitions@> =
void marpa_symbol_is_start_set(struct marpa_g* g, Marpa_Symbol_ID id, gboolean value)
{ symbol_id2p(g, id)->is_start = value; }
@ @<Public function prototypes@> =
void marpa_symbol_is_start_set(
struct marpa_g* g, Marpa_Symbol_ID id, gboolean value);

@ Symbol Aliasing:
This is the logic for aliasing symbols.
In the Aycock-Horspool algorithm, from which Marpa is derived,
it is essential that there be no "proper nullable"
symbols.  Therefore, all proper nullable symbols in
the original grammar are converted into two, aliased,
symbols: a non-nullable (or "proper") alias and a nulling alias.
@<Bitfield symbol elements@> =
unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
@ @<Pointer aligned symbol elements@> =
struct marpa_symbol* alias;
@ @<Initialize symbol elements@> =
symbol->is_proper_alias = FALSE;
symbol->is_nulling_alias = FALSE;
symbol->alias = NULL;

@ Proper Alias Trace Accessor:
If this symbol has no proper alias, returns |NULL|.
Otherwise it returns the proper alias.
This implies that if
the argument was the proper alias, it is returned.
For now, this is also the internal accessor.
@<Function definitions@> =
static inline
struct marpa_symbol* symbol_proper_alias_value(struct marpa_symbol* symbol)
{ return symbol->is_proper_alias? symbol :
symbol->is_nulling_alias ? symbol->alias : NULL; }
Marpa_Symbol_ID marpa_symbol_proper_alias_value(struct marpa_g* g, Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol* symbol = symbol_id2p(g, symbol_id);
struct marpa_symbol* alias = symbol_proper_alias_value(symbol);
return alias == NULL ? -1 : alias->id;
}
@ @<Private function prototypes@> =
static inline struct marpa_symbol* symbol_proper_alias_value(struct marpa_symbol* symbol);
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_symbol_proper_alias_value(struct marpa_g* g, Marpa_Symbol_ID symbol_id);

@ Nulling Alias Trace Accessor:
If this symbol has no nulling alias, returns |NULL|.
Otherwise it returns the nulling alias.
This implies that if
the argument was the nulling alias, it is returned.
For now, this is also the internal accessor.
@<Function definitions@> =
static inline
struct marpa_symbol* symbol_null_alias_value(struct marpa_symbol* symbol)
{ return symbol->is_proper_alias? symbol->alias :
symbol->is_nulling_alias ? symbol : NULL; }
Marpa_Symbol_ID marpa_symbol_null_alias_value(struct marpa_g* g, Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol* symbol = symbol_id2p(g, symbol_id);
struct marpa_symbol* alias = symbol_null_alias_value(symbol);
return alias == NULL ? -1 : alias->id;
}
@ @<Private function prototypes@> =
static inline struct marpa_symbol* symbol_null_alias_value(struct marpa_symbol* symbol);
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_symbol_null_alias_value(struct marpa_g* g, Marpa_Symbol_ID symbol_id);

@ Given a proper nullable symbol as its argument,
converts the argument into two "aliases".
The proper (non-nullable) alias will have the same symbol ID
as the arugment.
The nulling alias will have a new symbol ID.
The return value is a pointer to the nulling alias.
TODO: I expect to delete
the external version of this function after
development.
@<Function definitions@> = /* static inline */
struct marpa_symbol* symbol_alias_create(struct marpa_g* g,
struct marpa_symbol* symbol)
{
    struct marpa_symbol* alias = symbol_new(g);
    symbol->is_proper_alias = TRUE;
    symbol->is_nulling = FALSE;
    symbol->is_nullable = FALSE;
    symbol->alias = alias;
    alias->is_nulling_alias = TRUE;
    alias->is_nulling = TRUE;
    alias->is_nullable = TRUE;
    alias->is_productive = symbol->is_productive;
    alias->is_accessible = symbol->is_accessible;
    alias->alias = symbol;
    return alias;
}
Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g* g, Marpa_Symbol_ID symbol_id)
{
if (symbol_id < 0) { return -1; }
if (symbol_id >= g->symbols->len) { return -1; }
return symbol_alias_create(g, symbol_id2p(g, symbol_id))->id;
}
@ @<Public function prototypes@> = 
/* static inline */
struct marpa_symbol* symbol_alias_create(struct marpa_g* g,
struct marpa_symbol* symbol);
Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g* g, Marpa_Symbol_ID symbol_id);

@** Rule Objects.
@<Public typedefs@> =
typedef gint Marpa_Rule_ID;
@ @<Private structures@> =
struct marpa_rule {
    @<Widely aligned rule elements@>@/
    /* Pointer aligned rule elements */@/
    @<Int aligned rule elements@>@/
    @<Bitfield rule elements@>@/
    @<Final rule elements@>@/
};
static inline gsize rule_sizeof(length) {
return sizeof(struct marpa_rule) + length*sizeof(Marpa_Symbol_ID);
}

@ @<Function definitions@> =
static inline
struct marpa_rule* rule_new(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length)
{
    struct marpa_rule* rule;
    @<Return |NULL| on invalid rule symbols@>@/
    rule = g_malloc(rule_sizeof(length));
    @<Initialize rule symbols@>@/
    @<Initialize rule elements@>@/
    marpa_g_rule_add(g, rule->id, rule);
   return rule;
}
Marpa_Rule_ID marpa_rule_new(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length)
{
    struct marpa_rule* rule = rule_new(g, lhs, rhs, length);
    return rule == NULL ? -1 : rule->id;
}

@ @<Private function prototypes@> =
static inline
struct marpa_rule* rule_new(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length);
@ @<Public function prototypes@> =
Marpa_Rule_ID marpa_rule_new(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length);

@ @<Destroy grammar elements@> =
{  int id; for (id = 0; id < g->rules->len; id++)
{ marpa_rule_free(rule_id2p(g, id)); } }
@ TODO: Any rule elements which need to be freed go here.
@<Function definitions@> =
static inline void marpa_rule_free(struct marpa_rule* rule)
{
/* Free rule elements */
g_free(rule); }
@ @<Private function prototypes@> =
static inline void marpa_rule_free(struct marpa_rule* rule);

@ Rule Symbols: The rule's left hand side (LHS), right hand side (RHS)
and its length.  Length is the length of the RHS -- there is always
exactly one LHS symbol.
@<Widely aligned rule elements@> = gsize length;
@ The symbols come at the end of the |marpa_rule| structure,
so that they can be variable length.
@<Final rule elements@> = Marpa_Symbol_ID symbols[1];
@ @<Return |NULL| on invalid rule symbols@> =
if (!symbol_is_valid(g, lhs)) { return NULL; }
{ int i; for (i = 0; i<length; i++) {
    if (!symbol_is_valid(g, rhs[i])) { return NULL; }
} }
@ @<Initialize rule symbols@> =
rule->length = length;
rule->symbols[0] = lhs;
{ int i; for (i = 0; i<length; i++) {
    rule->symbols[i+1] = rhs[i]; } }
@ @<Function definitions@> =
static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule *rule) {
return rule->symbols[0]; }
Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g *g, Marpa_Rule_ID rule_id) {
return rule_lhs_get(rule_id2p(g, rule_id)); }
static inline Marpa_Symbol_ID* rule_rhs_get(struct marpa_rule *rule) {
return rule->symbols+1; }
Marpa_Symbol_ID* marpa_rule_rhs_peek(struct marpa_g *g, Marpa_Rule_ID rule_id) {
return rule_rhs_get(rule_id2p(g, rule_id)); }
static inline gsize rule_length_get(struct marpa_rule *rule) {
return rule->length; }
gsize marpa_rule_length_value(struct marpa_g *g, Marpa_Rule_ID rule_id) {
return rule_length_get(rule_id2p(g, rule_id)); }
@ @<Private function prototypes@> =
static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule *rule);
static inline Marpa_Symbol_ID* rule_rhs_get(struct marpa_rule *rule);
static inline gsize rule_length_get(struct marpa_rule *rule);
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g *g, Marpa_Rule_ID rule_id);
Marpa_Symbol_ID* marpa_rule_rhs_peek(struct marpa_g *g, Marpa_Rule_ID rule_id);
gsize marpa_rule_length_value(struct marpa_g *g, Marpa_Rule_ID rule_id);

@ Rule ID: This is the unique identifier for the rule.
@<Int aligned rule elements@> = Marpa_Rule_ID id;
@ @<Initialize rule elements@> = rule->id = g->rules->len;

@ Rule Is Accessible Boolean
@<Bitfield rule elements@> = unsigned int is_accessible:1;
@ @<Initialize rule elements@> =
rule->is_accessible = FALSE;
@ The trace accessor returns the Boolean value.
Right now this function uses a pointer
to the rule function.
If that becomes private,
the prototype of this function
must be changed.
\par
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_rule_is_accessible_value(struct marpa_g* g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->is_accessible; }
@ @<Public function prototypes@> =
gboolean marpa_rule_is_accessible_value(struct marpa_g* g, Marpa_Rule_ID id);
@ The external mutator is temporary, for development.
@<Function definitions@> =
void marpa_rule_is_accessible_set(
struct marpa_g*g, Marpa_Rule_ID id, gboolean value)
{ rule_id2p(g, id)->is_accessible = value; }
@ @<Public function prototypes@> =
/* static inline */
void marpa_rule_is_accessible_set( struct marpa_g*g, Marpa_Rule_ID id, gboolean value);


@** Earley Item Objects.
Here are some thought about potential optimizations:
Principles to observe:
\li Optimization should favor unambiguous grammars,
without unduly penalizing ambiguous grammars.
\li Optimization should favor mildly ambiguous grammars,
without unduly penalizing very ambiguous grammars.
\li Optimization should focus on space, even at a some
cost in time.
This is because in practical applications
there can easily be many millions of
Earley items and links.
If there are 1M copies of a structure,
each byte saved is a 1M saved.

Consideration was given to treating the one link case
as special, and including the first link in the Earley item.
But then the special case has to be tested for,
and that's pretty much a wash with the indirection.
Consideration was also given to putting the three kinds
of links (token, cause and Leo) into a single list.
But then a key has to included to separate them, so
that the space saved in the Earley item structure winds
up being used in the lists.

@<Public structures@> =
struct marpa_earley_item {
     int dummy; /* until I get some contents */
};
@ Initialize Earley Item Object
@<Function definitions@> = MARPA_SHIM@/
struct marpa_earley_item* marpa_earley_item_new(void)
{ struct marpa_earley_item* item =
        g_malloc(sizeof(struct marpa_earley_item));
   return item; }
@ @<Public function prototypes@> =
struct marpa_earley_item* marpa_earley_item_new(void);
@ Free Earley Item Object
@<Function definitions@> =
void marpa_earley_item_free(struct marpa_earley_item* item)
{ g_free(item); }
@ @<Public function prototypes@> =
void marpa_earley_item_free(struct marpa_earley_item* item);
@ Memory Allocation
Memory for the base of the Earley item object is allocated with 
|g_malloc|.

@** Error and Message Logging.
Marpa uses the |glib| Message Logging framework.
Message logging is in the "Marpa" domain,
except for memory allocation.

@ Set the Logging Domain

@<Logging domain@> =

#undef G_LOG_DOMAIN@/
#define G_LOG_DOMAIN "Marpa"@/

@** Testing.

@ A test routine.

This was a version compatibility checker.
I no longer use it as such, but keep it around as a simple
test routine, one slightly less trivial than |marpa_version|.

@<Function definitions@> =


const char *
marpa_check_version (unsigned int required_major,
                    unsigned int required_minor,
                    unsigned int required_micro)
{
  int marpa_effective_micro = 1000 * MARPA_MINOR_VERSION + MARPA_MICRO_VERSION;
  int required_effective_micro = 1000 * required_minor + required_micro;
    static char output_buffer[1000];

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

@ Return message if major version too old.

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

@ Return message if major version too new

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


@ Return message if minor/micro version too new.

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


@ Return message if minor/micro version too old.

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

@*1 Templates.

@*2 Simple Lists.

@<Simple list public structure template@> =

#undef MARPA_SLIST_LINK
#define MARPA_SLIST_LINK(prefix) MARPA_CAT(prefix, _link)

struct MARPA_SLIST_LINK(MARPA_TEMPLATE_PREFIX) {
   struct MARPA_SLIST_LINK(MARPA_TEMPLATE_PREFIX) *next;
   MARPA_TEMPLATE_PAYLOAD payload;
};

@

@<Simple list public inline definition template@> =

#undef MARPA_SLIST_LINK
#define MARPA_SLIST_LINK(prefix) MARPA_CAT(prefix, _link)
#undef MARPA_SLIST_ADD
#define MARPA_SLIST_ADD(prefix) MARPA_CAT(prefix, _add)

MARPA_PUBLIC_INLINE void MARPA_SLIST_ADD(MARPA_TEMPLATE_PREFIX) (
    struct MARPA_SLIST_LINK(MARPA_TEMPLATE_PREFIX) **base,
    MARPA_TEMPLATE_PAYLOAD payload
) {
    struct MARPA_SLIST_LINK(MARPA_TEMPLATE_PREFIX) *next = *base;
    struct MARPA_SLIST_LINK(MARPA_TEMPLATE_PREFIX) *new
        = *base
        = g_malloc(sizeof(*next));
    new->next = next;
    new->payload = payload;
}

@

@<Simple list public prototype template@> =

#undef MARPA_SLIST_LINK
#define MARPA_SLIST_LINK(prefix) MARPA_CAT(prefix, _link)
#undef MARPA_SLIST_ADD
#define MARPA_SLIST_ADD(prefix) MARPA_CAT(prefix, _add)

MARPA_PUBLIC_INLINE void MARPA_SLIST_ADD(MARPA_TEMPLATE_PREFIX) (
    struct MARPA_SLIST_LINK(MARPA_TEMPLATE_PREFIX) **base,
    MARPA_TEMPLATE_PAYLOAD payload
);

@** Physical Layout.  
@ Prematter:
The output files are not source file,
but I add the license to them anyway,
as close to the top as possible.
Also, it is helpful to someone first
trying to orient herself,
if built source files contain a comment
to that effect and a warning
not that they are
not intended to be edited directly.
So I add such a comment.

@q This is a hack to get the @>
@q license language nearer the top of the files. @>
@ The physical structure of the |marpa.c| file
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

#pragma GCC diagnostic warning "-Wall"
#pragma GCC diagnostic warning "-Wextra"
#pragma GCC diagnostic warning "-Wpointer-arith"
#pragma GCC diagnostic warning "-Wstrict-prototypes"
#pragma GCC diagnostic warning "-Wwrite-strings"
#pragma GCC diagnostic warning "-Wdeclaration-after-statement"
#pragma GCC diagnostic warning "-Wshadow"
#pragma GCC diagnostic warning "-Winline"

#include "config.h"
#include "marpa.h"
@h
@<Logging domain@>@;
@<Version constants@>@;
@<Private structures@>@;
@<Private function prototypes@>@;
@<Private inline functions@>@;
@<Function definitions@>@;

@q This is a separate section in order to get the @>
@q license language nearer the top of the files. @>
@q It's hackish, but in a good cause. @>
@ The physical structure of the |marpa.h| file
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

@<Body of public header file@>

@ Public inline function definitions
None yet.

@<Public inline function definitions@> =

@ Header inline function definitions

This logic is only for inline functions which might need to be "public".
Those that are "local" to single translation unit should simply be 
declared |static inline| keyword.

"Public" inline functions (those which need to be visibile outside a
single translation unit) present complications.
These should have a non-inlined, "standalone" version in case they
are used where inlining is not possible.
(For instance, a pointer to them might be needed.)
Also, it is more complicated to make them portable.

There is no logic here to make the |inline| keyword portable.
Marpa expects autoconf to |#define| the |inline| keyword to
whatever is correct on the target,
so this logic uses that the |inline| keyword.

There is no guarantee, of course, that there is an inlining
keyword or that, if there is such a keyword,
that it actually does inlining.
If there is no inlining keyword, |inline| is |#define|'d
as the empty string.
If inlining actually words,
Marpa's configuration defines the |MARPA_CAN_INLINE| macro.

{|MARPA_STANDALONE| is defined in only one file, the file which should contain
the non-inlined ("standalone") definition of the inlined functions.
Marpa's public inlined functions should be declared |MARPA_PUBLIC_INLINE|.
Conditional compilation should be set up so that,
whenever |MARPA_PUBLIC_INLINE| is used,
|MARPA_STANDALONE| or |MARPA_CAN_INLINE| is defined.
\tolerance=9999\par}

@<Inlining macros@> =
#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__) 
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE 
#endif

@

@<Body of public header file@> =

@ The file for standalone versions of the inline functions

@(standalone.c@> =

#define MARPA_STANDALONE 1
#include "marpa.h"

@ ``Never Used'' Sections

This section is a hack to silence the ``never used'' warnings
for the templates.
I expect to use these sections.

@(never_used.c@> =

@<Simple list public inline definition template@>
@<Simple list public prototype template@>
@<Simple list public structure template@>

@** Index.

