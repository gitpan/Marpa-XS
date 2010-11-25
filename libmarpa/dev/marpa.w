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

\secpagedepth=1

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

\def\marpa_sub#1{{\bf #1}: }

@s not_eq normal @q unreserve a C++ keyword @>
@s gboolean int
@s Marpa_Rule_ID int
@s Marpa_Symbol_ID int
@s GArray int

@** Introduction.

@*0 Naming conventions.

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
In the description below |j| stands for an object,
and |f| for a field of that object.
In cases where there is not ambiguity about which
object a field might belong to, |j| will often be omitted.

\li |j_f_get| returns field |f| of object |j|.
It is an internal function, and often will be declared
|static inline|.

\li |j_f_put| assigns a value to field |f| of object |j|.
It is an internal function, and often will be declared
|static inline|.

\li |marpa_j_f_look| returns field |f| of object |j|.
It is an external equivalent of |j_f_get|.
The returned value is still owned by object |j| -- it should
not be modified or freed.

\li |marpa_j_f_peek| returns field |f| of object |j|.
It is an external equivalent of |j_f_get|.
The returned value is still owned by object |j| -- it should
not be modified or freed.

The difference between "peek" and "look" is somewhat
subjective.
"Look" functions are expected to be called in the normal
course of operation, including in production code.
"Peek" functions break the encapsulation rules.
Their use is expected to be limited
to debugging or tracing situations.

\li |marpa_j_f_set| sets field |f| of object |j|.
It's the external equivalent of |j_f_put|.

\li |marpa_j_f_value| returns field |f| of object |j|.
It is an external equivalent of |j_f_get|.
The returned value is owned by the caller.
If it is a pointer, it points to memory which must
be freed with |g_splice_free|.

@*0 Abbreviations.

The following abbreviations are used in Marpa's variable names:

\li g for Grammar
\li r for Recognizer
\li recce for Recognizer
\li alloc for Allocate

@*0 Development Plans.

These are notes to myself,
most of which will only be relevant
while |libmarpa| is being written.
Most of these notes will be revised
and then deleted as development proceeds.

@*1 Short Term To Do List.

\li The |rule_complete| call.  Do I really need that?

\li Rewrite Leo link coversion code before converting 
from Perl.

@*1 Long Term To Do List.

\li Gather up all the non-internal grammar error cookies,
and make sure they are accounted for in the Perl upper layer.

\li When symbols and rules are no longer Perl objects,
have them destroyed when the Grammar object is destroyed.

@*1 Development Note: Marpa layers.

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

@*1 Development Note: Representing Objects.
Representation of objects is most commonly in one
of three forms: cookies, ID's or pointers to C structures.
A lot of thought went into which is used where.

@*2 Object ID's.
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

@*2 Object Cookies.
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

@*2 Object pointers.
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

@*1 Development Note: Converting Elements.
\li Init the data element.

\li Add a destructor.
At first arrange for this to be called when the Perl object
is destroyed.
Add a comment in the place where the destructor must eventually
be called, as a reminder.
This will usually be in the Recognizer or Grammar destructor.

{\hbadness=10000 \raggedright \noindent \li
Add whatever mutators are needed,
initially as un-inlined externals.
At the end of development, it should be possible to
eliminate the external versions of these.
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

@*1 Development Note: Converting Objects.

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

@*0 Memory Allocation.

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
@ Constants
@ Version Constants @<Private global variables@> =
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
@ @<Public function prototypes@> =
void marpa_version(int* version);

@ Header file.  |GLIB_VAR| is to
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
#define MARPA_CAT(a, b) @[ a ## b @]
@<Inlining macros@>@/
@<Public defines@>@/
struct marpa_g;@/
@<Public typedefs@>@/@\
@<Callback typedefs@>@/
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
@<Public structures@> = struct marpa_g {
@<Pointer aligned grammar elements@>@/
@<Int aligned grammar elements@>@/
@<Bit aligned grammar elements@>@/
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

@*0 The Grammar ID.
A unique ID for the grammar.
This must be unique not just per-thread,
but process-wide.
The counter which tracks grammar ID's
(|next_grammar_id|)
is (at this writing) the only global
non-constant, and requires special handling to
keep |libmarpa| MT-safe.
(|next_grammar_id|) is accessed only via
|glib|'s special atomic operations.
@ @<Int aligned grammar elements@> = int id;
@ @<Public typedefs@> = typedef gint Marpa_Grammar_ID;
@ @<Private global variables@> = static gint next_grammar_id = 1;
@ @<Initialize grammar elements@> =
g->id = g_atomic_int_exchange_and_add(&next_grammar_id, 1);
@ @<Function definitions@> =
gint marpa_grammar_id_value(struct marpa_g* g) { return g->id; }
@ @<Public function prototypes@> =
gint marpa_grammar_id_value(struct marpa_g* g);

@*0 The Grammar's Symbol List.
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

@ Symbol count accesor.
@<Function definitions@> =
static inline gint symbol_count(struct marpa_g* g) {
   return g->symbols->len;
}
@ @<Private function prototypes@> =
static inline gint symbol_count(struct marpa_g* g);

@ Internal accessor to find a symbol by its id.
@<Function definitions@> =
static inline struct marpa_symbol*
symbol_id2p(struct marpa_g* g, Marpa_Symbol_ID id)
{ return g_array_index(g->symbols, struct marpa_symbol*, id); }
@ @<Private function prototypes@> =
static inline struct marpa_symbol*
symbol_id2p(struct marpa_g* g, Marpa_Symbol_ID id);

@ Adds the symbol to the list of symbols kept by the Grammar
object.
@<Private inline functions@> =
static inline
void g_symbol_add(
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

@*0 The Grammar's Rule List.
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

@ Rule count accesor.
@<Function definitions@> =
static inline gint rule_count(struct marpa_g* g) {
   return g->rules->len;
}
@ @<Private function prototypes@> =
static inline gint rule_count(struct marpa_g* g);

@ Internal accessor to find a rule by its id.
@<Function definitions@> =
static inline struct marpa_rule*
rule_id2p(struct marpa_g* g, Marpa_Rule_ID id)
{ return g_array_index(g->rules, struct marpa_rule*, id); }
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
    g->size += 1 + rule->length;
    g->max_rule_length = MAX(rule->length, g->max_rule_length);
}

@ Check that rule is in valid range.
@<Function definitions@> =
static inline gint rule_is_valid(
struct marpa_g *g, Marpa_Rule_ID rule_id) {
return rule_id < g->rules->len && rule_id >= 0;
}
@ @<Private function prototypes@> =
static inline gint rule_is_valid(
struct marpa_g *g, Marpa_Rule_ID rule_id);

@*0 Grammar Start Symbol.
@<Int aligned grammar elements@> = Marpa_Symbol_ID start_symbol;
@ @<Initialize grammar elements@> =
g->start_symbol = -1;
@ The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_start_symbol(struct marpa_g* g)
{ return g->start_symbol; }
@ @<Public function prototypes@> =
gboolean marpa_start_symbol(struct marpa_g* g);
@ Returns |TRUE| on success,
|FALSE| on failure.
@<Function definitions@> =
gboolean marpa_start_symbol_set(struct marpa_g*g, Marpa_Symbol_ID id)
{
    struct marpa_symbol* start;
    if (g->is_precomputed) {
        g->error = "precomputed";
	return FALSE;
    }
    if (!symbol_is_valid(g, id)) {
        g->error = "invalid start symbol";
	return FALSE;
    }
    g->start_symbol = id;
    return TRUE;
}
@ @<Public function prototypes@> =
gboolean marpa_start_symbol_set(struct marpa_g*g, Marpa_Symbol_ID id);

@*0 The Grammar's Size.
Intuitively,
I define a grammar's size as the total size, in symbols, of all of its
rules.
This includes both the LHS symbol and the RHS symbol.
Since every rule has exactly one LHS symbol,
the grammar's size is always equal to the total of
all the rules lengths, plus the total number of rules.
\par
Unused rules are not included in the theoretical number,
but Marpa does not necessarily deduct rules from the
count as they are marked useless.
This means that the
grammar will always be of this size or smaller.
As rules are marked useless, they are not necessarily deducted
from the count.
The purpose of tracking grammar size is to allocating resources,
and for that purpose a high-ball estimate is adequate.
\par
@ @<Int aligned grammar elements@> = int size;
@ @<Initialize grammar elements@> =
g->size = 0;

@*0 The Maximum Rule Length.
This is a high-ball estimate of the length of the
longest rule in the grammar.
The actual value will always be this number or smaller.
\par
The value is used for allocating resources.
Unused rules are not included in the theoretical number,
but Marpa does not adjust this number as rules
are marked useless.
@ @<Int aligned grammar elements@> = int max_rule_length;
@ @<Initialize grammar elements@> =
g->max_rule_length = 0;

@*0 Grammar Boolean: Precomputed.
@<Bit aligned grammar elements@> = unsigned int is_precomputed:1;
@ @<Initialize grammar elements@> =
g->is_precomputed = FALSE;
@ The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_is_precomputed(struct marpa_g* g)
{ return g->is_precomputed; }
@ @<Public function prototypes@> =
gboolean marpa_is_precomputed(struct marpa_g* g);

@*0 Grammar Boolean: LHS Terminal OK.
Traditionally, a BNF grammar did {\bf not} allow a symbol
which was a terminal symbol of the grammar, to also be a LHS
symbol.
By default, this is allowed under Marpa.
@<Bit aligned grammar elements@> = unsigned int is_lhs_terminal_ok:1;
@ @<Initialize grammar elements@> =
g->is_lhs_terminal_ok = TRUE;
@ The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_is_lhs_terminal_ok(struct marpa_g* g)
{ return g->is_lhs_terminal_ok; }
@ @<Public function prototypes@> =
gboolean marpa_is_lhs_terminal_ok(struct marpa_g* g);
@ Returns |TRUE| on success,
|FALSE| on failure.
@<Function definitions@> =
gboolean marpa_is_lhs_terminal_ok_set(
struct marpa_g*g, gboolean value)
{
    if (g->is_precomputed) {
        g->error = "precomputed";
	return FALSE;
    }
    g->is_lhs_terminal_ok = value;
    return TRUE;
}
@ @<Public function prototypes@> =
gboolean marpa_is_lhs_terminal_ok_set( struct marpa_g*g, gboolean value);

@*0 Grammar Boolean: Academic.
Academic grammars are only of interest for maintenance,
development and testing of changes to Marpa.
Academic grammars for which the Marpa's usual
precomputations are not done.
Marpa produces an NFA and an AHFA for them exactly as is.
\par
Following Aycock-Horspool, Marpa needs its grammar to be
rewritten if it is going to use it for parsing,
so no rewrites means no useful parsing.
Academic grammars
can used on to produce the NFA and AHFA for the examples
in the textbooks, exactly as they
appear in the pages.
This makes them useful for testing Marpa's precomputation.
@<Bit aligned grammar elements@> = unsigned int is_academic:1;
@ @<Initialize grammar elements@> =
g->is_academic = FALSE;
@ The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_is_academic(struct marpa_g* g)
{ return g->is_academic; }
@ @<Public function prototypes@> =
gboolean marpa_is_academic(struct marpa_g* g);
@ Returns |TRUE| on success,
|FALSE| on failure.
@<Function definitions@> =
gboolean marpa_is_academic_set(
struct marpa_g*g, gboolean value)
{
    if (g->is_precomputed) {
        g->error = "precomputed";
	return FALSE;
    }
    g->is_academic = value;
    return TRUE;
}
@ @<Public function prototypes@> =
gboolean marpa_is_academic_set( struct marpa_g*g, gboolean value);

@*0 The Grammar's Context.
The "context" is a hash of miscellaneous data,
by keyword.
It is so called because its purpose is to 
provide callbacks with "context" ---
data about
|libmarpa|'s state which is not conveniently
available in other forms.
@<Pointer aligned grammar elements@> = GHashTable* context;
@ @<Initialize grammar elements@> =
g->context = g_hash_table_new_full( g_str_hash, g_str_equal, NULL, g_free );
@ @<Destroy grammar elements@> = g_hash_table_destroy(g->context);

@ @<Public defines@> =
#define MARPA_CONTEXT_INT 1@/
#define MARPA_CONTEXT_CONST 2@/
#define MARPA_IS_CONTEXT_INT(v) @| @[ ((v)->type == MARPA_CONTEXT_INT) @]@/
#define MARPA_CONTEXT_INT_VALUE(v) @| \
@[ ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) @]@/
#define MARPA_CONTEXT_STRING_VALUE(v) @| \
@[ ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) @]@/
@ @<Public structures@> =
struct marpa_context_int_value {
   gint type;
   gint data;
};
@ @<Public structures@> =
struct marpa_context_const_value {
   gint type;
   const gchar* data;
};
@ @<Public structures@> =
union marpa_context_value {
   gint type;
   struct marpa_context_int_value int_value;
   struct marpa_context_const_value const_value;
};

@ Add an integer to the context.
These functions might be converted to be public.
For now they are only for use by |libmarpa| in setting
values to be read by the higher layers,
are therefore internal.

The const qualifier on the key is deliberately discarded.
As implemented, the keys are treated as const's by
|g_hash_table_insert|, but the compiler can't know
that is my intention.
For type safety, I do want to keep the |const|
qualifier in other contexts.
@<Function definitions@> =
static inline
void context_int_add(struct marpa_g* g, const gchar* key, gint payload)
{
    struct marpa_context_int_value* value = g_new(struct marpa_context_int_value, 1);
    value->type = MARPA_CONTEXT_INT;
    value->data = payload;
    g_hash_table_insert(g->context, (gpointer)key, value);
}
@ @<Private function prototypes@> =
static inline
void context_int_add(struct marpa_g* g, const gchar* key, gint value);
@ @<Function definitions@> =
static inline
void marpa_context_const_add(struct marpa_g* g, const gchar* key, const gchar* payload)
{
    struct marpa_context_const_value* value = g_new(struct marpa_context_const_value, 1);
    value->type = MARPA_CONTEXT_CONST;
    value->data = payload;
    g_hash_table_insert(g->context, (gpointer)key, value);
}
@ @<Private function prototypes@> =
static inline
void marpa_context_const_add(struct marpa_g* g, const gchar* key, const gchar* value);

@ Clear the current context.
Used to create a "clean slate" in the context.
@<Function definitions@> =
static inline void context_clear(struct marpa_g* g) {
    g_hash_table_remove_all(g->context); }
@ @<Private function prototypes@> =
static inline void context_clear(struct marpa_g* g);

@ @<Function definitions@> =
union marpa_context_value* marpa_context_value_look(struct marpa_g* g, const gchar* key)
{ return g_hash_table_lookup(g->context, key); }
@ @<Public function prototypes@> =
union marpa_context_value* marpa_context_value_look(struct marpa_g* g, const gchar* key);

@*0 The Grammar's Error ID.
This is an error flag for the grammar.
Error status is not necessarily cleared
on successful return, so that
it is only valid when an external
function has indicated there is an error,
and becomes invalid again when another external method
is called on the grammar.
Checking it at other times may reveal "stale" error
messages.
@<Public typedefs@> =
typedef const gchar* Marpa_Error_ID;
@ @<Pointer aligned grammar elements@> = Marpa_Error_ID error;
@ @<Initialize grammar elements@> =
g->error = 0;
@ There is no destructor.
The error strings are assummed to be
{\bf not} error messages, but "cookies".
These cookies are constants residing in static memory
(which may be read-only depending on implementation).
They cannot and should not be de-allocated.
@ @<Function definitions@> =
Marpa_Error_ID marpa_error_value(struct marpa_g* g)
{ return g->error ? : "unknown error"; }
@ @<Public function prototypes@> =
Marpa_Error_ID marpa_error_value(struct marpa_g* g);

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
    @<Bit aligned symbol elements@>@/
};

@ @<Function definitions@> =
static inline
struct marpa_symbol* symbol_new(struct marpa_g *g)
{ struct marpa_symbol* symbol = g_malloc(sizeof(struct marpa_symbol));
    @<Initialize symbol elements@>@/
    { Marpa_Symbol_ID id = symbol->id;
    g_symbol_add(g, id, symbol); }
   return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g *g)
{ Marpa_Symbol_ID id = symbol_new(g)->id;
symbol_callback(g, id);
return id; }

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

@*0 Symbol LHS Rules Element.
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

@*0 Symbol RHS Rules Element.
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
@<Bit aligned symbol elements@> = unsigned int is_accessible:1;
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
@<Bit aligned symbol elements@> = unsigned int is_counted:1;
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

@ Symbol Is Nullable Boolean
@<Bit aligned symbol elements@> = unsigned int is_nullable:1;
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
@<Bit aligned symbol elements@> = unsigned int is_nulling:1;
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
gint marpa_symbol_is_nulling(struct marpa_g* g, Marpa_Symbol_ID symbol_id)
{ @<Return -1 if |symbol_id| is invalid@>@;
return symbol_id2p(g, symbol_id)->is_nulling; }
@ @<Public function prototypes@> =
gint marpa_symbol_is_nulling(struct marpa_g* g, Marpa_Symbol_ID id);
@ The external mutator is temporary, for development.
@<Function definitions@> =
void marpa_symbol_is_nulling_set(
struct marpa_g*g, Marpa_Symbol_ID id, gboolean value)
{ symbol_id2p(g, id)->is_nulling = value; }
@ @<Public function prototypes@> = 
void marpa_symbol_is_nulling_set( struct marpa_g*g, Marpa_Symbol_ID id, gboolean value);

@ Symbol Is Terminal Boolean
@<Bit aligned symbol elements@> = unsigned int is_terminal:1;
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
@<Bit aligned symbol elements@> = unsigned int is_productive:1;
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
@<Bit aligned symbol elements@> = unsigned int is_start:1;
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
gboolean symbol_is_start(struct marpa_symbol* symbol)
{ return symbol->is_start; }
gboolean marpa_symbol_is_start( struct marpa_g*g, Marpa_Symbol_ID symbol_id) {
   @<Return -1 if |symbol_id| is invalid@>@;
   return symbol_is_start(symbol_id2p(g, symbol_id));
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
@<Bit aligned symbol elements@> =
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
struct marpa_symbol* proper_alias = symbol_proper_alias_value(symbol);
return proper_alias == NULL ? -1 : proper_alias->id;
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
@<Function definitions@> = static inline
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
    alias->is_productive = TRUE;
    alias->is_accessible = symbol->is_accessible;
    alias->alias = symbol;
    return alias;
}
Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g* g, Marpa_Symbol_ID original_id)
{ Marpa_Symbol_ID alias_id;
    if (original_id < 0) { return -1; }
    if (original_id >= g->symbols->len) { return -1; }
    alias_id = symbol_alias_create(g, symbol_id2p(g, original_id))->id;
    symbol_callback(g, alias_id);
    return alias_id; }
@ @<Private function prototypes@> = 
static inline
struct marpa_symbol* symbol_alias_create(struct marpa_g* g,
struct marpa_symbol* symbol);
@ @<Public function prototypes@> = 
Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g* g, Marpa_Symbol_ID symbol_id);

@ {\bf Symbol callbacks}:  The user can define a callback
(with argument) which is invoked whenever a symbol
is created.
@ Function pointer declarations are
hard to type and impossible to read.
This typedef localizes the damage.
@<Callback typedefs@> =
typedef void (Marpa_Symbol_Callback)(struct marpa_g *g, Marpa_Symbol_ID id);
@ @<Pointer aligned grammar elements@> =
    Marpa_Symbol_Callback* symbol_callback;
    void *symbol_callback_arg;
@ @<Function definitions@> =
void marpa_symbol_callback_set(struct marpa_g *g, Marpa_Symbol_Callback*cb)
{ g->symbol_callback = cb; }
void marpa_symbol_callback_arg_set(struct marpa_g *g, void *cb_arg)
{ g->symbol_callback_arg = cb_arg; }
void* marpa_symbol_callback_arg_peek(struct marpa_g *g)
{ return g->symbol_callback_arg; }
@ @<Public function prototypes@> =
void marpa_symbol_callback_set(struct marpa_g *g, Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g *g, void *cb_arg);
void* marpa_symbol_callback_arg_peek(struct marpa_g *g);
@ Do the symbol callback.
@<Function definitions@> =
static inline symbol_callback(struct marpa_g *g, Marpa_Symbol_ID id)
{ Marpa_Symbol_Callback* cb = g->symbol_callback;
if (cb) { (*cb)(g, id); } }
@ @<Private function prototypes@> =
static inline symbol_callback(struct marpa_g *g, Marpa_Symbol_ID id);

@*0 Error Handling.
@<Return -1 if |symbol_id| is invalid@> =
if (!symbol_is_valid(g, symbol_id)) {
    context_int_add(g, "symbol_id", symbol_id);
    g->error = "invalid symbol id";
    return -1;
}

@** Rule Objects.
@<Public typedefs@> =
typedef gint Marpa_Rule_ID;
@ @<Private structures@> =
struct marpa_rule {
    @<Widely aligned rule elements@>@/
    /* Pointer aligned rule elements */@/
    @<Int aligned rule elements@>@/
    @<Bit aligned rule elements@>@/
    @<Final rule elements@>@/
};
@ @<Function definitions@> =
static inline gsize rule_sizeof(gint length) {
return sizeof(struct marpa_rule) + length*sizeof(Marpa_Symbol_ID);
}
@ @<Private function prototypes@> =
static inline gsize rule_sizeof(gint length);

@*0 Rule Construction.
@ Set up the basic data.
This logic is intended to be common to all individual rules.
The name comes from the idea that this logic "starts"
the initialization of a rule.
@<Function definitions@> =
static inline
struct marpa_rule* rule_start(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length)
{
    int i;
    struct marpa_rule* rule;
    @<Return |NULL| on invalid rule symbols@>@/
    rule = g_malloc(rule_sizeof(length));
    @<Initialize rule symbols@>@/
    @<Initialize rule elements@>@/
    marpa_g_rule_add(g, rule->id, rule);
    @<Add this rule to the symbol rule lists@>
   return rule;
}
@ @<Function definitions@> =
Marpa_Rule_ID marpa_rule_start_shim(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length)
{
    struct marpa_rule* rule = rule_start(g, lhs, rhs, length);
    if (!rule) { return -1; }
    return  rule->id;
}
@ "Complete" rule.  Do the callback to the upper layers
telling them about the new rule.
The term "complete" comes from the idea that this completes
the initialization process.
This function may go away once development is finished.
@<Function definitions@> =
void marpa_rule_complete_shim(struct marpa_g *g, Marpa_Rule_ID id)
{
    rule_callback(g, id);
}
@ @<Function definitions@> =
Marpa_Rule_ID marpa_rule_new(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length)
{
    Marpa_Rule_ID rule_id;
    struct marpa_rule* rule;
    if (is_rule_duplicate(g, lhs, rhs, length) == TRUE) {
	g->error = (Marpa_Error_ID)"duplicate rule";
        return -1;
    }@;
    rule = rule_start(g, lhs, rhs, length);
    if (!rule) { return -1; }@;
    rule_id = rule->id;
    rule_callback(g, rule_id);
    return rule_id;
}

@ @<Function definitions@> =
Marpa_Rule_ID marpa_sequence_new(struct marpa_g *g,
Marpa_Symbol_ID lhs_id, Marpa_Symbol_ID rhs_id, Marpa_Symbol_ID separator_id,
gint min, gint flags )
{
    Marpa_Rule_ID original_rule_id;
    struct marpa_rule* original_rule;
    Marpa_Symbol_ID internal_lhs_id, *temp_rhs;@;
    if (min < 0) {
	g->error = (Marpa_Error_ID)"bad min";@;
        return -1;@;
    }@;
    if (is_rule_duplicate(g, lhs_id, &rhs_id, 1) == TRUE) {
	g->error = (Marpa_Error_ID)"duplicate rule";@;
        return -1;@;
    }@;

    @<Add the original rule for a sequence@>@;
    @<Check that the separator is valid or -1@>@;
    @<Mark the counted symbols@>@;
    if (min == 0) { @<Add the nulling rule for a sequence@>@; }
    min = 1;
    @<Create the internal LHS symbol@>@;
    @<Allocate the temporary rhs buffer@>@;
    @<Add the top rule for the sequence@>@;
    if (separator_id >= 0 && !(flags & MARPA_PROPER_SEPARATION)) {
	@<Add the alternate top rule for the sequence@>@;
    }
    @<Add the minimum rule for the sequence@>@;
    @<Add the iterating rule for the sequence@>@;
    @<Free the temporary rhs buffer@>@;
    return original_rule_id;
}
@ @<Public function prototypes@> =
Marpa_Rule_ID marpa_sequence_new(struct marpa_g *g,
Marpa_Symbol_ID lhs_id, Marpa_Symbol_ID rhs_id, Marpa_Symbol_ID separator_id,
gint min, gint flags );
@ @<Return -1 for an internal error@> = g->error = "internal_error"; return -1;
@ As a side effect, this checks the LHS and RHS symbols for validity.
@<Add the original rule for a sequence@> =
    original_rule = rule_start(g, lhs_id, &rhs_id, 1);
    if (!original_rule) { @<Return -1 for an internal error@> }
    original_rule->is_used = 0;
    original_rule_id = original_rule->id;
    rule_callback(g, original_rule_id);
@ @<Check that the separator is valid or -1@> =
if (separator_id != -1 && !symbol_is_valid(g, separator_id)) {
    g->error = "bad separator"; return -1;
}
@ @<Mark the counted symbols@> =
symbol_id2p(g, rhs_id)->is_counted = 1;
if (separator_id >= 0) { symbol_id2p(g, separator_id)->is_counted = 1; }
@ @<Add the nulling rule for a sequence@> =
	{ struct marpa_rule* rule = rule_start(g, lhs_id, 0, 0);
	if (!rule) { @<Return -1 for an internal error@> }
	rule->is_semantic_equivalent = TRUE;
	rule->original = original_rule_id;
	rule_callback(g, rule->id);
	}
@ @<Create the internal LHS symbol@> =
    internal_lhs_id = symbol_new(g)->id;
    symbol_callback(g, internal_lhs_id);
@ The actual size needed for the RHS buffer is determined by
the longer of minimum rule and the iterating rule.
The iterating rule may require 3 RHS symbols, if there is
a separator.
(We have $min>=1$ at this point.)
The minimum rule will require $1 + 2 * (min - 1)$ symbols
with a separator, and $min$ symbols without.
The allocation below uses a simplified expression, which
overallocates.
Worst case is the minimum rule with a separator, in
which case it allocates 4 bytes too many.
@<Allocate the temporary rhs buffer@> =
temp_rhs = g_new(Marpa_Symbol_ID, (3 + (separator_id < 0 ? 1 : 2) * min));
@ @<Free the temporary rhs buffer@> = g_free(temp_rhs);
@ @<Add the top rule for the sequence@> =
{ struct marpa_rule* rule;
temp_rhs[0] = internal_lhs_id;
rule = rule_start(g, lhs_id, temp_rhs, 1);
if (!rule) { @<Return -1 for an internal error@> }
rule->original = original_rule_id;
rule->is_semantic_equivalent = TRUE;
/* Real symbol count remains at default of 0 */
rule->is_virtual_rhs = TRUE;
rule->is_discard = !(flags & MARPA_KEEP_SEPARATION) && separator_id >= 0;
rule_callback(g, rule->id);
}
@ This "alternate" top rule is needed if a final separator is allowed.
@<Add the alternate top rule for the sequence@> =
{ struct marpa_rule* rule;
    temp_rhs[0] = internal_lhs_id;
    temp_rhs[1] = separator_id;
    rule = rule_start(g, lhs_id, temp_rhs, 2);
    if (!rule) { @<Return -1 for an internal error@> }
    rule->original = original_rule_id;
    rule->is_semantic_equivalent = TRUE;
    rule->is_virtual_rhs = TRUE;
    rule->real_symbol_count = 1;
    rule->is_discard = !(flags & MARPA_KEEP_SEPARATION);
    rule_callback(g, rule->id);
}
@ The traditional way to write a sequence in BNF is with one
rule to represent the minimum, and another to deal with iteration.
That's the core of Marpa's rewrite.  This is the minimum
rule.
@<Add the minimum rule for the sequence@> =
{ struct marpa_rule* rule;
gint rhs_ix, i;
    temp_rhs[0] = rhs_id;
    rhs_ix = 1;
    for (i = 0; i < min - 1; i++) {
        if (separator_id >= 0) temp_rhs[rhs_ix++] = separator_id;
        temp_rhs[rhs_ix++] = rhs_id;
    }
    rule = rule_start(g, internal_lhs_id, temp_rhs, rhs_ix);
    if (!rule) { @<Return -1 for an internal error@> }
    rule->is_virtual_lhs = TRUE;
    rule->real_symbol_count = rhs_ix;
    rule_callback(g, rule->id);
}
@ @<Add the iterating rule for the sequence@> =
{ struct marpa_rule* rule;
gint rhs_ix = 0;
    temp_rhs[rhs_ix++] = internal_lhs_id;
    if (separator_id >= 0) temp_rhs[rhs_ix++] = separator_id;
    temp_rhs[rhs_ix++] = rhs_id;
    rule = rule_start(g, internal_lhs_id, temp_rhs, rhs_ix);
    if (!rule) { @<Return -1 for an internal error@> }
    rule->is_virtual_lhs = TRUE;
    rule->is_virtual_rhs = TRUE;
    rule->real_symbol_count = rhs_ix - 1;
    rule_callback(g, rule->id);
}

@ Does this rule duplicate an already existing rule?
A duplicate is a rule with the same lhs symbol,
the same rhs length,
and the same symbol in each position on the rhs.

Note that this definition of duplicate applies to
sequences as well.  That means that a sequence rule
can be a duplicate of a non-sequence rule of length 1,
if they have the same lhs symbols and the same rhs
symbol.
Also, that means you cannot define sequences
that differ only in the separator, or only in the
minimum count.

I do not think the
restrictions on sequence rules represent real limitations.
Multiple sequences with the same lhs and rhs would be
very confusing.
And users who really, really want such them are free
to write the sequences out as BNF rules.
After all, sequence rules are only a shorthand.
And shorthand is counter-productive when it makes
you lose track of what you are trying to say.

The algorithm is the first get a list of all the rules
with the same LHS, which is very fast because
I have pre-computed it.
If there are no such rules, the new rule is
unique (not a duplicate).
If there are such rules, I look at them,
trying to find one that duplicates the new
rule.
For each old rule, I first compare its length to
the new rule, and then its right hand side
symbols, one by one.
If all these comparisons succeed, I conclude
that the old rule duplicates the new one
and return |TRUE|.
If, after having done the comparison for all
the "same LHS" rules, I have found no duplicates,
then I conclude there is no duplicate of the new
rule, and return |FALSE|.
@s rule_is_not_duplicate int
@<Function definitions@> =
static inline
gboolean is_rule_duplicate(struct marpa_g* g,
Marpa_Symbol_ID lhs_id, Marpa_Symbol_ID* rhs_ids, gint length)
{
    gint ix;
    struct marpa_symbol* lhs = symbol_id2p(g, lhs_id);
    GArray* same_lhs_array = lhs->lhs;
    gint same_lhs_count = same_lhs_array->len;
    for (ix = 0; ix < same_lhs_count; ix++) {
	Marpa_Rule_ID same_lhs_rule_id = ((Marpa_Rule_ID *)(same_lhs_array->data))[ix];
	gint rhs_position;
	struct marpa_rule* rule = rule_id2p(g, same_lhs_rule_id);
	if (rule->length != length) { goto rule_is_not_duplicate; }
	for (rhs_position = 0; rhs_position < rule->length; rhs_position++) {
	    if (rhs_symbol_id(rule, rhs_position) != rhs_ids[rhs_position]) {
	        goto rule_is_not_duplicate;
	    }
	}
	return TRUE; /* This rule duplicates the new one */
	rule_is_not_duplicate: ;
    }
    return FALSE; /* No duplicate rules were found */
}
@ @<Private function prototypes@> =
static inline
gboolean is_rule_duplicate(struct marpa_g* g,
Marpa_Symbol_ID lhs_id, Marpa_Symbol_ID* rhs_ids, gint length);

@ @<Private function prototypes@> =
static inline
struct marpa_rule* rule_start(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length);
@ @<Public function prototypes@> =
Marpa_Rule_ID marpa_rule_start_shim(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length);
void marpa_rule_complete_shim(struct marpa_g *g, Marpa_Rule_ID id);
Marpa_Rule_ID marpa_rule_new(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, gint length);

@ Add the rules to the symbol's rule lists:
An obstack scratchpad might be useful for
the copy of the RHS symbols.
|alloca|, while tempting, should not used
because an unusually long RHS could cause
a stack overflow.
Even if such case is pathological,
a core dump is not the right response.
@<Add this rule to the symbol rule lists@> =
    symbol_lhs_add(symbol_id2p(g, rule->symbols[0]), rule->id);@;
    if (rule->length > 0) {
	gint rh_list_ix;
	const gint alloc_size = rule->length*sizeof( Marpa_Symbol_ID);
	Marpa_Symbol_ID *rh_symbol_list = g_slice_alloc(alloc_size);
	gint rh_symbol_list_length = 1;
	@<Create |rh_symbol_list|,
	a duplicate-free list of the right hand side symbols@>@;
       for (rh_list_ix = 0;
	   rh_list_ix < rh_symbol_list_length;
	   rh_list_ix++) {
	    symbol_rhs_add(
		symbol_id2p(g, rh_symbol_list[rh_list_ix]),
		rule->id);
       }@;
       g_slice_free1(alloc_size, rh_symbol_list);
    }

@ \marpa_sub{Create a duplicate-free list of the right hand side symbols}
The algorithm is a
hand-coded
insertion sort, modified to not insert duplicates.
@ The first goal is to optimize for the usual case,
where both the average and root mean square of
number of unique symbols on the RHS of a rule
is a small number -- usually less
than 10.
(Root mean square is more relevant than the average for
comparison with worst case performance.)
bizarrely long.
A hand-inlined insertion sort is perfect for
this.
\par It might be thought that the below could
be improved by finding the insertion point
with a binary search, but when the number of RHS symbols
for most rules is less than a certain number,
a the higher-overhead binary search is worse,
not better.
This number is probably around 8, and in practice most rules
are shorter than that.
A reasonable alternative is to only use binary search above
a certain size, but in most cases that will produce no
measurable improvement.

@ A second goal is that behavior for unusual and pathological
cases be, if not optimal, reasonable.
Worst case for insertion sort is $O(n^2)$).
(This is why I used the root mean square, not a simple average.)
This would be approached if most of the right hand symbols were
in very long rules.
$O(n^2)$ is in fact, not actually a worse case than the quicksort
on which |qsort| is usually based.
The hand-coding here means it would take some effort to
construct a case in which
the theoretical advantage of another
sort algorithm would
show up in practice.
\par If anyone comes to care about very long right hand sides,
this algorithm can be changed to switch over to mergesort
when the right hand side exceeds a certain length.
The cost of an extra comparision is tiny, but then again,
so would the likelihood of any benefit from an alternative sort
algorithm would also
be tiny.

@ The code assumes that the rhs has length greater than zero.
@<Create |rh_symbol_list|, a duplicate-free list of the right hand side symbols@> =
{
/* Handle the first symbol as a special case */
gint rhs_ix = rule->length-1;
rh_symbol_list[0] = rhs_symbol_id(rule, rhs_ix);
rh_symbol_list_length = 1;
rhs_ix--;
for (; rhs_ix >= 0; rhs_ix--) {
    gint higher_ix;
    Marpa_Symbol_ID new_symbol_id = rhs_symbol_id(rule, rhs_ix);
    gint next_highest_ix = rh_symbol_list_length - 1;
    while (next_highest_ix >= 0) {
	Marpa_Symbol_ID current_symbol_id = rh_symbol_list[next_highest_ix];
	if (current_symbol_id == new_symbol_id) goto ignore_this_symbol;
	if (current_symbol_id < new_symbol_id) break;
        next_highest_ix--;
    }
    /* Shift the higher symbol ID's up one slot */
    for (higher_ix = rh_symbol_list_length-1;
	    higher_ix > next_highest_ix;
	    higher_ix--) {
        rh_symbol_list[higher_ix+1] = rh_symbol_list[higher_ix];
    }
    /* Insert the next symbol */
    rh_symbol_list[next_highest_ix+1] = new_symbol_id;
    rh_symbol_list_length++;
    ignore_this_symbol: ;
}
}

@*0 Rule Destruction.
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

@*0 Rule Symbols.
A rule takes the traditiona form of
a left hand side (LHS), and a right hand side (RHS).
The {\bf length} of a rule is the length of the RHS ---
there is always exactly one LHS symbol.
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
@ @<Private function prototypes@> =
static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule *rule);
@ @<Function definitions@> =
Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g *g, Marpa_Rule_ID rule_id) {
    return rule_lhs_get(rule_id2p(g, rule_id)); }
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g *g, Marpa_Rule_ID rule_id);
@ @<Function definitions@> =
static inline Marpa_Symbol_ID* rule_rhs_get(struct marpa_rule *rule) {
    return rule->symbols+1; }
@ @<Private function prototypes@> =
static inline Marpa_Symbol_ID* rule_rhs_get(struct marpa_rule *rule);
@ @<Function definitions@> =
Marpa_Symbol_ID* marpa_rule_rhs_peek(struct marpa_g *g, Marpa_Rule_ID rule_id) {
    return rule_rhs_get(rule_id2p(g, rule_id)); }
@ @<Public function prototypes@> =
Marpa_Symbol_ID* marpa_rule_rhs_peek(struct marpa_g *g, Marpa_Rule_ID rule_id);
@ @<Function definitions@> =
static inline gsize rule_length_get(struct marpa_rule *rule) {
    return rule->length; }
@ @<Private function prototypes@> =
static inline gsize rule_length_get(struct marpa_rule *rule);
@ @<Function definitions@> =
gsize marpa_rule_length_value(struct marpa_g *g, Marpa_Rule_ID rule_id) {
    return rule_length_get(rule_id2p(g, rule_id)); }
@ @<Public function prototypes@> =
gsize marpa_rule_length_value(struct marpa_g *g, Marpa_Rule_ID rule_id);

@ @<Function definitions@> =
static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule* rule) { return rule->symbols[0]; }
@ @<Private function prototypes@> =
static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule* rule);
@ @<Function definitions@> =
static inline Marpa_Symbol_ID
    rhs_symbol_id(struct marpa_rule* rule, gint index) {
	return rule->symbols[index+1];
    }
@ @<Private function prototypes@> =
static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule* rule, gint index);

@*0 Rule ID.
The {bf rule ID} is a number which
acts as the unique identifier for a rule.
@<Int aligned rule elements@> = Marpa_Rule_ID id;
@ @<Initialize rule elements@> = rule->id = g->rules->len;

@*0 Rule Boolean: Keep Separator.
When this rule is evaluated by the semantics,
do they want to see the separators?
Default is that they are thrown away.
Usually the role of the separators is only syntactic,
and that is what is wanted.
For non-sequence rules, this flag should be false.
@<Public defines@> =
#define MARPA_KEEP_SEPARATION @| @[0x1@]@/
@ @<Bit aligned rule elements@> = unsigned int is_discard:1;
@ @<Initialize rule elements@> =
rule->is_discard = FALSE;
@ @<Function definitions@> =
gboolean marpa_rule_is_discard_separation(struct marpa_g* g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->is_discard; }
@ @<Public function prototypes@> =
gboolean marpa_rule_is_discard_separation(struct marpa_g* g, Marpa_Rule_ID id);

@*0 Rule Boolean: Proper Separation.
In Marpa's terminology,
proper separation means that a sequence
cannot legally end with a separator.
In "proper" separation,
the term separator is interpreted strictly,
as something which separates two list items.
A separator coming after the final list item does not separate
two items, and therefore traditionally was considered a syntax
error.
\par
Proper separation is often inconvenient,
or even counter-productive.
Increasingly, the
practice is to be "liberal"
and to allow a separator to come after the last list
item.
Liberal separation is the default in Marpa.
\par
There is not bitfield for this, because proper separation is
a completely syntactic matter,
taken care of in the rewrite itself.
@<Public defines@> =
#define MARPA_PROPER_SEPARATION @| @[0x2@]@/

@*0 Accessible Rules.
@ A rule is accessible if its LHS is accessible.
@<Function definitions@> =
static inline gint rule_is_accessible(struct marpa_g* g, struct marpa_rule* rule)
{
Marpa_Symbol_ID lhs_id = lhs_symbol_id(rule);
 return symbol_id2p(g, lhs_id)->is_accessible; }
gint marpa_rule_is_accessible(struct marpa_g* g, Marpa_Rule_ID rule_id)
{ struct marpa_rule* rule;
@<Return -1 if |rule_id| is invalide@>@;
rule = rule_id2p(g, rule_id);
return rule_is_accessible(g, rule);
}
@ @<Private function prototypes@> =
static inline gint rule_is_accessible(struct marpa_g* g, struct marpa_rule* rule);
@ @<Public function prototypes@> =
gint marpa_rule_is_accessible(struct marpa_g* g, Marpa_Rule_ID id);

@*0 Productive Rules.
@ A rule is productive if every symbol on its RHS is productive.
@<Function definitions@> =
static inline gint rule_is_productive(struct marpa_g* g, struct marpa_rule* rule)
{
gint rh_ix;
for (rh_ix = 0; rh_ix < rule->length; rh_ix++) {
   Marpa_Symbol_ID rhs_id = rhs_symbol_id(rule, rh_ix);
   if ( !symbol_id2p(g, rhs_id)->is_productive ) return FALSE;
}
return TRUE; }
gint marpa_rule_is_productive(struct marpa_g* g, Marpa_Rule_ID rule_id)
{ struct marpa_rule* rule;
@<Return -1 if |rule_id| is invalide@>@;
rule = rule_id2p(g, rule_id);
return rule_is_productive(g, rule);
}
@ @<Private function prototypes@> =
static inline gint rule_is_productive(struct marpa_g* g, struct marpa_rule* rule);
@ @<Public function prototypes@> =
gint marpa_rule_is_productive(struct marpa_g* g, Marpa_Rule_ID id);

@*0 Nulling Rules.
@ A rule is nulling if every symbol on its RHS is nulling.
Note that this can be vacuously true --- an empty rule is nulling.
@<Function definitions@> =
static inline gint rule_is_nulling(struct marpa_g* g, struct marpa_rule* rule)
{
gint rh_ix;
for (rh_ix = 0; rh_ix < rule->length; rh_ix++) {
   Marpa_Symbol_ID rhs_id = rhs_symbol_id(rule, rh_ix);
   if ( !symbol_id2p(g, rhs_id)->is_nulling ) return FALSE;
}
return TRUE; }
@ @<Private function prototypes@> =
static inline gint rule_is_nulling(struct marpa_g* g, struct marpa_rule* rule);

@*0 Rule Boolean: Used.
@<Bit aligned rule elements@> = unsigned int is_used:1;
@ @<Initialize rule elements@> =
rule->is_used = TRUE;
@ This is the external accessor.
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_rule_is_used_value(struct marpa_g* g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->is_used; }
@ @<Public function prototypes@> =
gboolean marpa_rule_is_used_value(struct marpa_g* g, Marpa_Rule_ID id);

@*0 Rule Boolean: Virtual LHS.
This is for Marpa's "internal semantics".
When Marpa rewrites rules, it does so in a way invisible to
the user's semantics.
It does this by marking rules so that it can reassemble
the results of rewritten rules to appear "as if"
they were the result of evaluating the original,
un-rewritten rule.
\par
All Marpa's rewrites allow the rewritten rules to be
"dummied up" to look like the originals.
That this must be possible for any rewrite was one of
Marpa's design criteria.
It was an especially non-negotiable criteria, because
almost the only reason for parsing a grammar is to apply the
semantics specified for the original grammar.
@<Bit aligned rule elements@> = unsigned int is_virtual_lhs:1;
@ @<Initialize rule elements@> =
rule->is_virtual_lhs = FALSE;
@ The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_rule_is_virtual_lhs_value(struct marpa_g* g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->is_virtual_lhs; }
@ @<Public function prototypes@> =
gboolean marpa_rule_is_virtual_lhs_value(struct marpa_g* g, Marpa_Rule_ID id);

@*0 Rule Boolean: Virtual RHS.
@<Bit aligned rule elements@> = unsigned int is_virtual_rhs:1;
@ @<Initialize rule elements@> =
rule->is_virtual_rhs = FALSE;
@ The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_rule_is_virtual_rhs_value(struct marpa_g* g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->is_virtual_rhs; }
@ @<Public function prototypes@> =
gboolean marpa_rule_is_virtual_rhs_value(struct marpa_g* g, Marpa_Rule_ID id);

@*0 Rule Callbacks.
The user can define a callback
(with argument) which is invoked whenever a rule
is created.
@ Function pointer declarations are
hard to type and impossible to read.
This typedef localizes the damage.
@<Callback typedefs@> =
typedef void (Marpa_Rule_Callback)(struct marpa_g *g, Marpa_Rule_ID id);
@ @<Pointer aligned grammar elements@> =
    Marpa_Rule_Callback* rule_callback;
    void *rule_callback_arg;
@ @<Function definitions@> =
void marpa_rule_callback_set(struct marpa_g *g, Marpa_Rule_Callback*cb)
{ g->rule_callback = cb; }
@ @<Public function prototypes@> =
void marpa_rule_callback_set(struct marpa_g *g, Marpa_Rule_Callback*cb);
@ @<Function definitions@> =
void marpa_rule_callback_arg_set(struct marpa_g *g, void *cb_arg)
{ g->rule_callback_arg = cb_arg; }
@ @<Public function prototypes@> =
void marpa_rule_callback_arg_set(struct marpa_g *g, void *cb_arg);
@ @<Function definitions@> =
void* marpa_rule_callback_arg_peek(struct marpa_g *g)
{ return g->rule_callback_arg; }
@ @<Public function prototypes@> =
void* marpa_rule_callback_arg_peek(struct marpa_g *g);
@ Do the rule callback.
@<Function definitions@> =
static inline rule_callback(struct marpa_g *g, Marpa_Rule_ID id)
{ Marpa_Rule_Callback* cb = g->rule_callback;
if (cb) { (*cb)(g, id); } }
@ @<Private function prototypes@> =
static inline rule_callback(struct marpa_g *g, Marpa_Rule_ID id);

@*0 Rule Original.
In many cases, Marpa will rewrite a rule.
If this rule is the result of a rewriting, this element contains
the ID of the original rule.
@ @<Int aligned rule elements@> = Marpa_Rule_ID original;
@ @<Initialize rule elements@> = rule->original = -1;
@ @<Function definitions@> =
Marpa_Rule_ID marpa_rule_original(struct marpa_g *g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->original; }

@*0 Rule Real Symbol Count.
This is another data element used for the "internal semantics" --
the logic to reassemble results of rewritten rules so that they
look as if they came from the original, un-rewritten rules.
The value of this field is meaningful if and only if
the rule has a virtual rhs or a virtual lhs.
@ @<Int aligned rule elements@> = gint real_symbol_count;
@ @<Initialize rule elements@> = rule->real_symbol_count = 0;
@ @<Function definitions@> =
gint marpa_real_symbol_count(struct marpa_g *g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->real_symbol_count; }

@*0 Semantic Equivalents.
@<Bit aligned rule elements@> = unsigned int is_semantic_equivalent:1;
@ @<Initialize rule elements@> =
rule->is_semantic_equivalent = FALSE;
@ Semantic equivalence arises out of Marpa's rewritings.
When a rule is rewritten,
some (but not all!) of the resulting rules have the
same semantics as the original rule.
It is this "original rule" that |semantic_equivalent()| returns.

If this rule is the semantic equivalent of another rule,
this external accessor returns the "original rule".
Otherwise it returns -1.
@<Function definitions@> =
Marpa_Rule_ID marpa_rule_semantic_equivalent_value(struct marpa_g* g, Marpa_Rule_ID id)
{
struct marpa_rule* rewrite_rule = rule_id2p(g, id);
return rewrite_rule->is_semantic_equivalent ? rewrite_rule->original : -1; }
@ @<Public function prototypes@> =
Marpa_Rule_ID marpa_rule_semantic_equivalent_value(struct marpa_g* g, Marpa_Rule_ID id);

@ @<Return -1 if |rule_id| is invalide@> =
if (!rule_is_valid(g, rule_id)) {
    context_int_add(g, "rule_id", rule_id);
    g->error = "invalid rule id";
    return -1;
}

@** Precomputing the Grammar.
Marpa's logic divides roughly into three pieces -- grammar precomputation,
the actual parsing of input tokens,
and semantic evaluation.
Precomputing the grammar is complex enought to divide into several
stages of its own, which are 
covered in the next few
sections.
This section describes the top-level method for precomputation,
which is external.

@<Function definitions@> =
struct marpa_g* marpa_precompute(struct marpa_g* g)
{
     if (!census(g)) return NULL;
     if (!CHAF_rewrite(g)) return NULL;
     return g;
}
@ @<Public function prototypes@> =
struct marpa_g* marpa_precompute(struct marpa_g* g);

@** The Grammar Census.

@*0 Implementation: Inacessible and Unproductive Rules.
The textbooks say that,
in order to automatically {\bf eliminate} inaccessible and unproductive
productions from a grammar, you have to first eliminate the
unproductive productions, {\bf then} the inaccessible ones.

In practice, this advice does not seem very helpful.
Imagine the (quite possible) case
of an unproductive start symbol.
Following the
correct procedure for automatically cleaning the grammar, I would
have to regard the start symbol and its productions as eliminated
and therefore go on to report every other production and symbol as
inaccessible.  Almost certainly all these inaccessiblity reports,
while theoretically correct, would be irrelevant.
What the user probably wants to
is to make the start symbol productive.

In |libmarpa|,
inaccessibility is determined based on the assumption that
unproductive symbols will be make productive somehow,
and not eliminated.
The downside of this choice is that, in a few uncommon cases,
a user relying entirely
on the Marpa::XS warnings to clean up his grammar will have to go through
more than a single pass of the diagnostics.
(As of this writing, I personally have yet to encounter such a case.)
The upside is that in the more frequent cases, the user is spared
a lot of useless diagnostics.

@<Function definitions@> =
static inline struct marpa_g* census(struct marpa_g* g)
{
    @<Declare census variables@>@;
    @<Fail for empty grammar@>@;
    @<Fail if already precomputed@>@;
    @<Fail if bad start symbol@>@;
    @<Census LHS symbols@>@;
    @<Census terminals@>@;
    if (have_marked_terminals) {
	@<Fatal if LHS terminal when not allowed@>@;
    } else {
	@<Fatal if empty rule and unmarked terminals@>;
	if (g->is_lhs_terminal_ok) {
	    @<Mark all symbols terminal@>@;
	} else {
	    @<Mark non-LHS symbols terminal@>@;
	}
    }
    @<Census nullable symbols@>@;
    @<Census productive symbols@>@;
    @<Check that start symbol is productive@>@;
    @<Calculate reach matrix@>@;
    @<Census accessible symbols@>@;
    @<Census nulling symbols@>@;
    @<Free Boolean vectors@>@;
    @<Free Boolean matrixes@>@;
    g->is_precomputed = TRUE;
    return g;
}
@ @<Public function prototypes@> =
static inline struct marpa_g* census(struct marpa_g* g);
@ @<Declare census variables@> =
gint pre_rewrite_rule_count = g->rules->len;
gint pre_rewrite_symbol_count = g->symbols->len;

@ @<Fail for empty grammar@> =
if (g->rules->len <= 0) { g->error = "no rules"; return NULL; }
@ The upper layers have a lot of latitude with this one.
There's no harm done, so the upper layers can simply ignore this one.
On the other hand, the upper layer may see this as a sign of a major
logic error, and treat it as a fatal error.
Anything in between these two extremes is also possible.
@<Fail if already precomputed@> =
if (g->is_precomputed) { g->error = "precomputed"; return NULL; }
@ Loop over the rules, producing bit vector of LHS symbols, and of
symbols which are the LHS of empty rules.
While at it, set a flag to indicate if there are empty rules.

@ @<Fail if bad start symbol@> =
if (original_start_symbol_id < 0) {
    g->error = "no start symbol";
    return NULL;
}
if (!symbol_is_valid(g, original_start_symbol_id)) {
    context_int_add(g, "symbol_id", original_start_symbol_id);
    g->error = "invalid start symbol";
    return NULL;
}
original_start_symbol = symbol_id2p(g, original_start_symbol_id);
if (original_start_symbol->lhs->len <= 0) {
    context_int_add(g, "symbol_id", original_start_symbol_id);
    g->error = "start symbol not on LHS";
    return NULL;
}
@ @<Declare census variables@> =
Marpa_Symbol_ID original_start_symbol_id = g->start_symbol;
struct marpa_symbol* original_start_symbol;

@ @<Census LHS symbols@> =
{ Marpa_Rule_ID rule_id;
lhs_v = bv_create(pre_rewrite_symbol_count);
empty_lhs_v = bv_shadow(lhs_v);
for (rule_id = 0; rule_id < pre_rewrite_rule_count; rule_id++) {
    struct marpa_rule* rule = rule_id2p(g, rule_id);
    Marpa_Symbol_ID lhs_id = lhs_symbol_id(rule);
    bv_bit_set(lhs_v, lhs_id);
    if (rule->length <= 0) {
	bv_bit_set(empty_lhs_v, lhs_id);
	have_empty_rule = 1;
    }
}
}
@ Loop over the symbols, producing the boolean vector of symbols
already marked as terminal,
and a flag which indicates if there are any.
@<Census terminals@> =
{ Marpa_Symbol_ID symbol_id;
terminal_v = bv_create(pre_rewrite_symbol_count);
for (symbol_id = 0; symbol_id < pre_rewrite_symbol_count; symbol_id++) {
    struct marpa_symbol* symbol = symbol_id2p(g, symbol_id);
    if (symbol->is_terminal) {
	bv_bit_set(terminal_v, symbol_id);
	have_marked_terminals = 1;
    }
} }
@ @<Free Boolean vectors@> =
bv_free(terminal_v);
@ @<Declare census variables@> =
Bit_Vector terminal_v;
gboolean have_marked_terminals = 0;

@ @<Fatal if empty rule and unmarked terminals@> =
if (have_empty_rule && g->is_lhs_terminal_ok) {
     g->error = "empty rule and unmarked terminals";
    return NULL;
}
@ Any optimization should be for the non-error case, in which
there are no LHS terminals, and the entire list of symbols must
be scanned to discover this.
It is faster to stop scanning symbols on the first error, if there is
an error, but when that happens it is a fatal error,
and for that, this code is already plenty fast enough.
@<Fatal if LHS terminal when not allowed@> = 
if (!g->is_lhs_terminal_ok) {
    gboolean have_bad_lhs = 0;
    gint start = 0;
    gint min, max;
    Bit_Vector bad_lhs_v = bv_clone(terminal_v);
    bv_and(bad_lhs_v, bad_lhs_v, lhs_v);
    while ( bv_scan(bad_lhs_v, start, &min, &max) ) {
	gint i;
	for (i = min; i <= max; i++) {
	    context_int_add(g, "symbol_id", i);
	    message(g, "lhs is terminal");
	}
        start = max+2;
	have_bad_lhs = 1;
    }
    bv_free(bad_lhs_v);
    if (have_bad_lhs) {
        g->error = "lhs is terminal";
	return NULL;
    }
}

@ @<Mark all symbols terminal@> =
{ Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for (symbol_id = 0; symbol_id < g->symbols->len; symbol_id++)
{ symbol_id2p(g, symbol_id)->is_terminal = 1; } }
@ @<Mark non-LHS symbols terminal@> = 
{ gint start = 0;
gint min, max;
bv_not(terminal_v, lhs_v);
while ( bv_scan(terminal_v, start, &min, &max) ) {
    gint symbol_id;
    for (symbol_id = min; symbol_id <= max; symbol_id++) {
     symbol_id2p(g, symbol_id)->is_terminal = 1;
    }
    start = max+2;
}
}
@ @<Free Boolean vectors@> =
bv_free(lhs_v);
bv_free(empty_lhs_v);
@ @<Declare census variables@> =
Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule = 0;

@ @<Census nullable symbols@> = 
nullable_v = bv_clone(empty_lhs_v);
rhs_closure(g, nullable_v);
{ gint min, max, start, symbol_id;
gint counted_nullables = 0;
    for ( start = 0; bv_scan(nullable_v, start, &min, &max); start = max+2 ) {
	for (symbol_id = min; symbol_id <= max; symbol_id++) {
	    struct marpa_symbol *symbol = symbol_id2p(g, symbol_id);
	    if (symbol->is_counted) {
		context_int_add(g, "symbol_id", symbol_id);
		message(g, "counted nullable");
		counted_nullables++;
	    }
	    symbol->is_nullable = 1;
} }
if (counted_nullables) {
    g->error = "counted nullable";
    return NULL;
}
}
@ @<Declare census variables@> =
Bit_Vector nullable_v;
@ @<Free Boolean vectors@> =
bv_free(nullable_v);

@ @<Census productive symbols@> = 
productive_v = bv_shadow(nullable_v);
bv_or(productive_v, nullable_v, terminal_v);
rhs_closure(g, productive_v);
{ gint min, max, start, symbol_id;
    for ( start = 0; bv_scan(productive_v, start, &min, &max); start = max+2 ) {
	for (symbol_id = min; symbol_id <= max; symbol_id++) {
	    struct marpa_symbol *symbol = symbol_id2p(g, symbol_id);
	    symbol->is_productive = 1;
} }
}
@ @<Check that start symbol is productive@> =
if (!bv_bit_test(productive_v, g->start_symbol))
{
    context_int_add(g, "symbol_id", g->start_symbol);
    g->error = "unproductive start symbol";
    return NULL;
}
@ @<Declare census variables@> =
Bit_Vector productive_v;
@ @<Free Boolean vectors@> =
bv_free(productive_v);

@ The reach matrix is the an $n\times n$ matrix,
where $n$ is the number of symbols.
Bit $(i,j)$ is set in the reach matrix if and only if
symbol $i$ can reach symbol $j$.
\par
This logic could be put earlier, and a child array
for each rule could be efficiently calculated during
the initialization for the calculation of the reach
matrix.
A rule-child array is a list of the rule's RHS symbols,
in sequence and without duplicates.
There are places were traversing a rule-child array,
instead of the rhs, would be more efficient.
At this point,
however, it is not clear whether use of a rule-child array
is not a pointless or even counter-productive optimization.
It would only make a difference in grammars
where many of the right hand sides repeat symbols.
@<Calculate reach matrix@> =
Bit_Matrix reach_matrix
    = matrix_create(pre_rewrite_symbol_count, pre_rewrite_symbol_count);
{ gint symbol_id, no_of_symbols = symbol_count(g);
for (symbol_id = 0; symbol_id < no_of_symbols; symbol_id++) {
     matrix_bit_set(reach_matrix, symbol_id, symbol_id);
} }
{ gint rule_id, no_of_rules = rule_count(g);
for (rule_id = 0; rule_id < no_of_rules; rule_id++) {
     struct marpa_rule* rule = rule_id2p(g, rule_id);
     Marpa_Symbol_ID lhs_id = lhs_symbol_id(rule);
     gint rhs_ix, rule_length = rule->length;
     for (rhs_ix = 0; rhs_ix < rule_length; rhs_ix++) {
	 matrix_bit_set(reach_matrix, lhs_id, rhs_symbol_id(rule, rhs_ix));
} } }
transitive_closure(reach_matrix);
@ @<Free Boolean matrixes@> =
matrix_free(reach_matrix);

@ @<Census accessible symbols@> = 
accessible_v = matrix_row(reach_matrix, original_start_symbol_id);
{ gint min, max, start, symbol_id;
    for ( start = 0; bv_scan(accessible_v, start, &min, &max); start = max+2 ) {
	for (symbol_id = min; symbol_id <= max; symbol_id++) {
	    struct marpa_symbol *symbol = symbol_id2p(g, symbol_id);
	    symbol->is_accessible = 1;
} }
}
@ |accessible_v| is a pointer into the |reach_matrix|.
Therefore there is no code to free it.
@<Declare census variables@> =
Bit_Vector accessible_v;

@ A symbol is nulling if and only if it is a productive symbol which does not
reach a terminal symbol.
@<Census nulling symbols@> = 
{ Bit_Vector reaches_terminal_v = bv_shadow(terminal_v);
gint min, max, start;
for ( start = 0; bv_scan(productive_v, start, &min, &max); start = max+2 ) {
	Marpa_Symbol_ID productive_id;
	for (productive_id = min; productive_id <= max; productive_id++) {
	    bv_and(reaches_terminal_v, terminal_v, matrix_row(reach_matrix, productive_id));
	    if (bv_is_empty(reaches_terminal_v)) symbol_id2p(g, productive_id)->is_nulling=1;
} }
bv_free(reaches_terminal_v); }

@** Rewriting the Grammar.

Marpa rewrites its grammars in two ways:
\li Nullable symbols have been a difficulty for Earley implementations
since day zero.
Aycock and Horspool came up with a solution to this problem,
part of which involved rewriting the grammar to eliminate
all proper nullables.
Marpa's CHAF rewrite is built on the work on Aycock and
Horspool.
\li Many approaches to parsing first augment the grammar with
a new start symbol and start rule.  Marpa is no exception.

@ In |CHAF_rewrite|, a |rule_count| is taken before the loop over
the grammar's rules, even though rules are added in the loop.
This is not an error.
The CHAF rewrite is not recursive -- the new rules it creates
are not themselves subject to CHAF rewrite.
And rule ID's increase by one each time,
so that all the new
rules will have ID's after |rule_count|.
@ @<Function definitions@> =
static inline struct marpa_g* CHAF_rewrite(struct marpa_g* g)
{
    @<CHAF rewrite declarations@>@;
    @<CHAF rewrite allocations@>@;
    no_of_rules = rule_count(g);
    for (rule_id = 0; rule_id < no_of_rules; rule_id++) {
         struct marpa_rule* rule = rule_id2p(g, rule_id);
	 @<Mark and skip unused rules@>@;
	 @<Calculate rule statistics and alias proper nullables@>@;
	 /* If there is no proper nullable in this rule, we are done */
	 if (rule_data[0].next_proper_nullable == -1) goto NEXT_RULE;
	 /* TO BE CONTINUED ... */
	 NEXT_RULE: ;
    }
    @<CHAF rewrite deallocations@>@;
    return g;
}
@ @<Private function prototypes@> =
static inline struct marpa_g* CHAF_rewrite(struct marpa_g* g);
@ @<CHAF rewrite declarations@> =
Marpa_Rule_ID rule_id;
struct rule_data {
     gint next_proper_nullable;
     Marpa_Symbol_ID proper_last_factor;
     Marpa_Symbol_ID nulling_last_factor;
} *rule_data;
gint no_of_rules;
@ @<CHAF rewrite allocations@> =
rule_data = g_new(struct rule_data, g->max_rule_length);
@ @<CHAF rewrite deallocations@> = g_free(rule_data);

@ @<Mark and skip unused rules@> =
if (!rule->is_used) { goto NEXT_RULE; }
if (rule_is_nulling(g, rule)) { rule->is_used = 0; goto NEXT_RULE; }
if (!rule_is_accessible(g, rule)) { rule->is_used = 0; goto NEXT_RULE; }
if (!rule_is_productive(g, rule)) { rule->is_used = 0; goto NEXT_RULE; }

@ @<Calculate rule statistics and alias proper nullables@> = {;}

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
@<Function definitions@> =
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

@** Boolean Vectors.
Marpa's boolean vectors are adapted from
Steffen Beyer's Bit-Vector package on CPAN.
This is a combined Perl package and C library for handling
bit vectors.
Someone looking for a bit vector package would do best
to look at Steffen's first.
|libmarpa|'s boolean vectors are tightly tied in
with its own needs and environment.
@<Private typedefs@> =
typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word* Bit_Vector;
@ Some defines and constants
@d BV_BITS(bv) *(bv-3)
@d BV_SIZE(bv) *(bv-2)
@d BV_MASK(bv) *(bv-1)
@<Private global variables@> =
static const int bv_wordbits = sizeof(Bit_Vector_Word)*8u;
static const int bv_modmask = sizeof(Bit_Vector_Word)*8u-1u;
static const int bv_hiddenwords = 3;
static const int bv_lsb = 1u;
static const int bv_msb = (1u << (sizeof(Bit_Vector_Word)*8u-1u));

@ Given a number of bits, compute the size.
@<Function definitions@> =
static inline guint bv_bits_to_size(gint bits)
{
    return (bits+bv_modmask)/bv_wordbits;
}
@ @<Private function prototypes@> =
static inline guint bv_bits_to_size(gint bits);
@ Given a number of bits, compute the unused-bit mask.
@<Function definitions@> =
static inline bv_bits_to_unused_mask(gint bits)
{
    guint mask = bits & bv_modmask;
    if (mask) mask = (guint) ~(~0uL << mask); else mask = (guint) ~0uL;
    return(mask);
}
@ @<Private function prototypes@> =
static inline bv_bits_to_unused_mask(gint bits);

@*0 Create a Boolean Vector.
Always start with an all-zero vector.
Note this code is a bit tricky ---
the pointer returned is to the data.
This is offset from the |g_malloc|'d space,
by |bv_hiddenwords|.
@<Function definitions@> =
static inline Bit_Vector bv_create(gint bits)
{
    guint size = bv_bits_to_size(bits);
    guint bytes = (size + bv_hiddenwords) << sizeof(guint);
    guint* addr = (Bit_Vector) g_malloc0((size_t) bytes);
    *addr++ = bits;
    *addr++ = size;
    *addr++ = bv_bits_to_unused_mask(bits);
    return addr;
}
@ @<Private function prototypes@> =
static inline Bit_Vector bv_create(gint bits);

@*0 Shadow a Boolean Vector.
Create another vector the same size as the original, but with
all bits unset.
@<Function definitions@> =
static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
    return bv_create(BV_BITS(bv));
}
@ @<Private function prototypes@> =
static inline Bit_Vector bv_shadow(Bit_Vector bv);

@*0 Clone a Boolean Vector.
Given a boolean vector, creates a new vector which is
an exact duplicate.
This call allocates a new vector, which must be |g_free|'d.
@<Function definitions@> =
Bit_Vector bv_clone(Bit_Vector bv)
{
    guint  bits;
    Bit_Vector twin;
    guint *p_twin;
    bits = BV_BITS(bv);
    p_twin = twin = bv_create(bits);
    if (bits > 0)
    {
        gint count = BV_SIZE(bv);
	while (count--) *p_twin++ = *bv++;
    }
    return(twin);
}
@ @<Private function prototypes@> =
Bit_Vector bv_clone(Bit_Vector bv);

@*0 Free a Boolean Vector.
@<Function definitions@> =
static inline void bv_free(Bit_Vector vector) {
    vector -= bv_hiddenwords;
    g_free(vector);
}
@ @<Private function prototypes@> =
static inline void bv_free(Bit_Vector vector);

@*0 The Number of Bytes in a Boolean Vector.
@<Function definitions@> =
static inline gint bv_bytes(Bit_Vector bv) {
    return (BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
@ @<Private function prototypes@> =
static inline gint bv_bytes(Bit_Vector bv);

@*0 Fill a Boolean Vector.
@<Function definitions@> =
static inline void bv_fill(Bit_Vector bv)
{
    guint size = BV_SIZE(bv);
    if (size <= 0) return;
    while (size--) *bv++ = ~0u;
    *(--bv) &= BV_MASK(bv);
}
@ @<Private function prototypes@> =
static inline void bv_fill(Bit_Vector bv);

@*0 Set a Boolean Vector Bit.
@ @<Function definitions@> =
static inline void bv_bit_set(Bit_Vector vector, gint bit) {
    *(vector+(bit/bv_wordbits)) |= (bv_lsb << (bit%bv_wordbits));
}
@ @<Private function prototypes@> =
static inline void bv_bit_set(Bit_Vector vector, gint bit);

@*0 Clear a Boolean Vector Bit.
@<Function definitions@> =
static inline void bv_bit_clear(Bit_Vector vector, gint bit) {
    *(vector+(bit/bv_wordbits)) &= ~ (bv_lsb << (bit%bv_wordbits));
}
@ @<Private function prototypes@> =
static inline void bv_bit_clear(Bit_Vector vector, gint bit);

@*0 Test a Boolean Vector Bit.
@<Function definitions@> =
static inline gboolean bv_bit_test(Bit_Vector vector, gint bit) {
    return (*(vector+(bit/bv_wordbits)) & (bv_lsb << (bit%bv_wordbits))) != 0u;
}
@ @<Private function prototypes@> =
static inline gboolean bv_bit_test(Bit_Vector vector, gint bit);

@*0 Set a Boolean Vector to all Ones.
@*0 Test a Boolean Vector for all Zeroes.
@<Function definitions@> =
gboolean bv_is_empty(Bit_Vector addr)
{
    guint  size = BV_SIZE(addr);
    gboolean r = TRUE;
    if (size > 0) {
        *(addr+size-1) &= BV_MASK(addr);
        while (r && (size-- > 0)) r = ( *addr++ == 0 );
    }
    return(r);
}
@ @<Private function prototypes@> =
gboolean bv_is_empty(Bit_Vector addr);

@*0 Bitwise-negate a Boolean Vector.
@<Function definitions@>=
static inline void bv_not(Bit_Vector X, Bit_Vector Y)
{
    guint size = BV_SIZE(X);
    guint mask = BV_MASK(X);
    while (size-- > 0) *X++ = ~*Y++;
    *(--X) &= mask;
}
@ @<Private function prototypes@> =
static inline void bv_not(Bit_Vector X, Bit_Vector Y);

@*0 Bitwise-and a Boolean Vector.
@<Function definitions@>=
static inline void bv_and(Bit_Vector X, Bit_Vector Y, Bit_Vector Z)
{
    guint size = BV_SIZE(X);
    guint mask = BV_MASK(X);
    while (size-- > 0) *X++ = *Y++ & *Z++;
    *(--X) &= mask;
}
@ @<Private function prototypes@> =
static inline void bv_and(Bit_Vector X, Bit_Vector Y, Bit_Vector Z);

@*0 Bitwise-or a Boolean Vector.
@<Function definitions@>=
static inline void bv_or(Bit_Vector X, Bit_Vector Y, Bit_Vector Z)
{
    guint size = BV_SIZE(X);
    guint mask = BV_MASK(X);
    while (size-- > 0) *X++ = *Y++ | *Z++;
    *(--X) &= mask;
}
@ @<Private function prototypes@> =
static inline void bv_or(Bit_Vector X, Bit_Vector Y, Bit_Vector Z);

@*0 Scan a Boolean Vector.
@<Function definitions@>=
gboolean bv_scan(Bit_Vector bv, gint start,
                                    gint* min, gint* max)
{
    guint  size = BV_SIZE(bv);
    guint  mask = BV_MASK(bv);
    guint  offset;
    guint  bitmask;
    guint  value;
    gboolean empty;

    if (size == 0) return FALSE;
    if (start >= BV_BITS(bv)) return FALSE;
    *min = start;
    *max = start;
    offset = start / bv_wordbits;
    *(bv+size-1) &= mask;
    bv += offset;
    size -= offset;
    bitmask = 1 << (start & bv_modmask);
    mask = ~ (bitmask | (bitmask - 1));
    value = *bv++;
    if ((value & bitmask) == 0)
    {
        value &= mask;
        if (value == 0)
        {
            offset++;
            empty = TRUE;
            while (empty && (--size > 0))
            {
                if ((value = *bv++)) empty = FALSE; else offset++;
            }
            if (empty) return FALSE;
        }
        start = offset * bv_wordbits;
        bitmask = bv_lsb;
        mask = value;
        while (!(mask & bv_lsb))
        {
            bitmask <<= 1;
            mask >>= 1;
            start++;
        }
        mask = ~ (bitmask | (bitmask - 1));
        *min = start;
        *max = start;
    }
    value = ~ value;
    value &= mask;
    if (value == 0)
    {
        offset++;
        empty = TRUE;
        while (empty && (--size > 0))
        {
            if ((value = ~ *bv++)) empty = FALSE; else offset++;
        }
        if (empty) value = bv_lsb;
    }
    start = offset * bv_wordbits;
    while (! (value & bv_lsb))
    {
        value >>= 1;
        start++;
    }
    *max = --start;
    return TRUE;
}
@ @<Private function prototypes@> =
gboolean BitVector_scan(Bit_Vector bv, gint start,
  gint* min, gint* max);

@*0 The RHS Closure of a Vector.
Despite the fact that they are actually tied closely to their
use in |libmarpa|, most of the logic of boolean vectors has
a "pure math" appearance.
This routine has a direct connection with the grammar.
\par
Several properties of symbols that need to be determined
have the property that, if
all the symbols on the RHS of any rule have that property,
so does its LHS symbol.
@ The RHS closure looks a lot like the transitive closure,
but there are several major differences.
The biggest difference is that
the RHS closure deals with properties and takes a {\bf vector} to another
vector;
the transitive closure is for a relation and takes a transition {\bf matrix}
to another transition matrix.
@ There are two properties of the RHS closure to note.
First, it is reflexive.
Any symbol in a set is in the RHS closure of that set.
@ Second, the RHS closure is vacuously true.
For any RHS closure property,
every symbol which is on the LHS of an empty rule has that property.
This means the RHS closure operation can only be used for
properties which can meaningfully be regarded as vacuously
true.
In |libmarpa|, two important symbol properties are
RHS clousure properties:
the property of being productive,
and the property of being nullable.

@*0 Produce the RHS Closure of a Vector.
This routine takes a symbol vector and a grammar,
and turns the original vector into the RHS closure of that vector.
The orignal vector is destroyed.
\par
If I decide rules should have a unique right hand symbol list,
this is one place to use it.
Duplicate symbols on the RHS are visited uselessly.
@<Function definitions@> =
static void rhs_closure(struct marpa_g* g, Bit_Vector bv)
{
      gint min, max, start = 0;
      FSTACK_DEFINE(stack, Marpa_Symbol_ID);
      Marpa_Symbol_ID *top_of_stack = NULL;
      FSTACK_INIT(stack, Marpa_Symbol_ID, symbol_count(g));
	while ( bv_scan(bv, start, &min, &max) ) {
    gint symbol_id;
    for (symbol_id = min; symbol_id <= max; symbol_id++) {
        *(FSTACK_PUSH(stack)) = symbol_id;
    }
    start = max+2;
    }
    while (top_of_stack = FSTACK_POP(stack)) {
	gint rule_ix;
	GArray* rules = symbol_id2p(g, *top_of_stack)->rhs;
	for (rule_ix = 0; rule_ix < rules->len; rule_ix++) {
	     Marpa_Rule_ID rule_id = g_array_index(rules, Marpa_Rule_ID, rule_ix);
	     struct marpa_rule* rule = rule_id2p(g, rule_id);
	     gint rule_length;
	     gint rh_ix;
	     Marpa_Symbol_ID lhs_id = lhs_symbol_id(rule);
	     if (bv_bit_test(bv, lhs_id)) goto NEXT_RULE;
	     rule_length = rule->length;
	     for (rh_ix = 0; rh_ix < rule_length; rh_ix++) {
		 if (!bv_bit_test(bv, rhs_symbol_id(rule, rh_ix))) goto NEXT_RULE;
	     }
	     /* If we are here, the bits for the RHS symbols are all
	      * set, but the one for the LHS symbol is not.
	      */
	      bv_bit_set(bv, lhs_id);
	     *(FSTACK_PUSH(stack)) = lhs_id;
	     NEXT_RULE: ;
	}
    }
      FSTACK_DESTROY(stack);
}
@ @<Private function prototypes@> =
static void rhs_closure(struct marpa_g* g, Bit_Vector bv);

@** Boolean Matrixes.
Marpa's Boolean matrixes are implemented differently
from the matrixes in
Steffen Beyer's Bit-Vector package on CPAN,
but like Beyer's matrixes are build on that package.
Beyer's matrixes are a single Boolean vector
which special routines index by row and column.
Marpa's matrixes are arrays of vectors.

Since there are "hidden words" before the data
in each vectors, Marpa must repeat these for each
row of a vector.  Consequences:
\li Marpa matrixes use a few extra bytes per row of space.
\li Marpa's matrix pointers cannot be used as vectors.
\li Marpa's rows {\bf can} be used as vectors.
\li Marpa's matrix pointers point to the beginning of
the allocated space.  |Bit_Vector| pointers use trickery
and include "hidden words" before the pointer.
@ Note that |typedef|'s for |Bit_Matrix|
are |Bit_Vector| identical.
@<Private typedefs@> =
typedef Bit_Vector_Word* Bit_Matrix;

@*0 Create a Boolean Matrix.
@ Here the pointer returned is the actual start of the
|g_malloc|'d space.
This is {\bf not} the case with vectors, whose pointer is offset for
the "hidden words".
@<Function definitions@> =
static inline Bit_Matrix matrix_create(gint rows, gint columns)
{
    guint bv_data_words = bv_bits_to_size(columns);
    guint row_bytes = (bv_data_words + bv_hiddenwords) * sizeof(Bit_Vector_Word);
    guint bv_mask = bv_bits_to_unused_mask(columns);
    Bit_Vector_Word* matrix_addr = g_malloc0((size_t)(row_bytes * rows));
    gint row;
    for (row = 0; row < rows; row++) {
	gint row_start = row*(bv_data_words+bv_hiddenwords);
	matrix_addr[row_start] = columns;
	matrix_addr[row_start+1] = bv_data_words;
	matrix_addr[row_start+2] = bv_mask;
    }
    return matrix_addr;
}
@ @<Private function prototypes@> =
static inline Bit_Matrix matrix_create(gint rows, gint columns);

@*0 Free a Boolean Matrix.
@<Function definitions@> =
static inline void matrix_free(Bit_Matrix matrix) {
    g_free(matrix);
}
@ @<Private function prototypes@> =
static inline void matrix_free(Bit_Matrix matrix);

@*0 Find the Number of Columns in a Boolean Matrix.
The column count returned is for the first row.
It is assumed that 
all rows have the same number of columns.
Note that, in this implementation, the matrix has no
idea internally of how many rows it has.
@<Function definitions@> =
static inline gint matrix_columns(Bit_Matrix matrix) {
    Bit_Vector row0 = matrix+bv_hiddenwords;
     return BV_BITS(row0);
}
@ @<Private function prototypes@> =
static inline gint matrix_columns(Bit_Matrix matrix);

@*0 Find a Row of a Boolean Matrix.
Here's where the slight extra overhead of repeating
identical "hidden word" data for each row of a matrix
pays off.
This simply returns a pointer into the matrix.
This is adequate if the data is not changed.
If it is changed, the vector should be cloned.
There is a bit of arithmetic, to deal with the
hidden words offset.
@<Function definitions@> =
static inline Bit_Vector matrix_row(Bit_Matrix matrix, gint row) {
    Bit_Vector row0 = matrix+bv_hiddenwords;
    guint words_per_row = BV_SIZE(row0)+bv_hiddenwords;
    return row0 + row*words_per_row;
}
@ @<Private function prototypes@> =
static inline Bit_Vector matrix_row(Bit_Matrix matrix, gint row);

@*0 Set a Boolean Matrix Bit.
@ @<Function definitions@> =
static inline void matrix_bit_set(Bit_Matrix matrix, gint row, gint column) {
    Bit_Vector vector = matrix_row(matrix, row);
    bv_bit_set(vector, column);
}
@ @<Private function prototypes@> =
static inline void matrix_bit_set(Bit_Matrix matrix, gint row, gint column);

@*0 Clear a Boolean Matrix Bit.
@ @<Function definitions@> =
static inline void matrix_bit_clear(Bit_Matrix matrix, gint row, gint column) {
    Bit_Vector vector = matrix_row(matrix, row);
    bv_bit_clear(vector, column);
}
@ @<Private function prototypes@> =
static inline void matrix_bit_clear(Bit_Matrix matrix, gint row, gint column);

@*0 Test a Boolean Matrix Bit.
@ @<Function definitions@> =
static inline gboolean matrix_bit_test(Bit_Matrix matrix, gint row, gint column) {
    Bit_Vector vector = matrix_row(matrix, row);
    return bv_bit_test(vector, column);
}
@ @<Private function prototypes@> =
static inline gboolean matrix_bit_test(Bit_Matrix matrix, gint row, gint column);

@*0 Produce the Transitive Closure of a Boolean Matrix.
This routine takes a matrix representing a relation
and produces a matrix that represents the transitive closure
of the relation.
The matrix is assumed to be square.
The input matrix will be destroyed.
@<Function definitions@> =
static void transitive_closure(Bit_Matrix matrix)
{
      gint size = matrix_columns(matrix);
      struct transition { gint from, to; };
      DSTACK_DEFINE(stack, struct transition);
      struct transition* top_of_stack = NULL;
      gint row;
      DSTACK_INIT(stack, struct transition);
      for (row = 0; row < size; row++) {
          gint min, max, start;
	  Bit_Vector row_vector = matrix_row(matrix, row);
	for ( start = 0; bv_scan(row_vector, start, &min, &max); start = max+2 ) {
	    gint column;
	    for (column = min; column <= max; column++) {
		struct transition *t = DSTACK_PUSH(stack, struct transition);
		t->from = row;
		t->to = column;
    } } }
    while (top_of_stack = DSTACK_POP(stack, struct transition)) {
	gint old_from = top_of_stack->from;
	gint old_to = top_of_stack->to;
	gint new_ix;
	for (new_ix = 0; new_ix < size; new_ix++) {
	     /* Optimizations based on reuse of the same row are
	       probably best left to the compiler's optimizer.
	      */
	     if (!matrix_bit_test(matrix, new_ix, old_to) && 
	     matrix_bit_test(matrix, new_ix, old_from)) {
		 struct transition *t = (DSTACK_PUSH(stack, struct transition));
		  matrix_bit_set(matrix, new_ix, old_to);
		 t->from = new_ix;
		 t->to = old_to;
		}
	     if (!matrix_bit_test(matrix, old_from, new_ix) && 
	     matrix_bit_test(matrix, old_to, new_ix)) {
		 struct transition *t = (DSTACK_PUSH(stack, struct transition));
		  matrix_bit_set(matrix, old_from, new_ix);
		 t->from = old_from;
		 t->to = new_ix;
		}
	}
    }
      DSTACK_DESTROY(stack);
}
@ @<Private function prototypes@> =
static void transitive_closure(Bit_Matrix matrix);

@** Fixed Size Stacks.
|libmarpa| uses stacks and worklists extensively.
Often a reasonable maximum size is known when they are
set up, in which case they can be made very fast.
\par
The interface is somewhat hackish.
This data structure is intended for use in localized contexts,
and not for global data structures.
In particular, care must be used in the placement of the |FSTACK_DEFINE|.
@d FSTACK_DEFINE(name, type) struct { gint ix; type* base; } name;
@d FSTACK_INIT(name, type, n) ((name.ix = 0), (name.base = g_new(type, n)))
@d FSTACK_PUSH(name) (name.base+name.ix++)
@d FSTACK_POP(name) (--name.ix < 0 ? NULL : name.base+name.ix)
@d FSTACK_DESTROY(name) (g_free(name.base))

@** Dynamic Stacks.
|libmarpa| uses stacks and worklists extensively.
This stack interface resizes itself dynamically.
There are two disadvantages.

\li There is more overhead ---
overflow must be checked for with each push,
and the resizings, while fast, do take time.

\li The stack may be moved after any |DSTACK_PUSH|
operation, making all pointers into it invalid.
Data must be retrieved from the stack before the
next |DSTACK_PUSH|.
\par
As with the fixed stacks,
the interface is somewhat hackish.
This data structure is intended for use in localized contexts,
and not for global data structures.
In particular, be careful where you put the |DSTACK_DEFINE|.
It expands to a struct declaration and must go where such
a declaration is legal and useful.

At this point |DSTACK_INITIAL_SIZE| is ridiculously small,
to test the logic.
It should be raised, perhaps to 1024.
Also, it may be good to allow a size parameter for |DSTACK_INIT|.

@d DSTACK_INITIAL_SIZE 2
@d DSTACK_DEFINE(this, type) struct dstack this;
@d DSTACK_INIT(this, type)
  ((this.ix = 0), (this.size = DSTACK_INITIAL_SIZE),
  (this.base = g_new(type, DSTACK_INITIAL_SIZE)))
@d DSTACK_PUSH(this, type)
    ((this.ix >= this.size ? dstack_resize(&this, sizeof(type)) : 0),
     ((type *)this.base+this.ix++))
@d DSTACK_POP(this, type) (--this.ix, this.ix < 0 ? NULL : (type*)this.base+this.ix)
@d DSTACK_DESTROY(this) (g_free(this.base))

@ @<Private structures@> =
struct dstack { gint ix; gint size; gpointer base; };
@ @<Function definitions@> =
static inline gpointer dstack_resize(struct dstack* this, gsize type_bytes) {
    this->size *= 2;
    this->base = g_realloc(this->base, this->size*type_bytes);
    return this->base;
}
@ @<Private function prototypes@> =
static inline gpointer dstack_resize(struct dstack* this, gsize type_size);

@** Messages and Logging.
@ Fallback and system Message Logging.
The main messaging system for |libmarpa| relies on callbacks
to upper layers.
But there are many cases in which it is not appropriate
to rely on the upper layers.
These cases include
serious internal problems,
memory allocation failures,
and debugging.

\par As a fallback messaging and logging system,
|libmarpa| uses |glib|'s Message Logging framework.
When the messsage domain is
under |libmarpa|'s control,
Marpa sets the domain to |"Marpa"|.
In many cases, such as memory allocation failures,
the domain will be as set by |glib|.
@ Set the Logging Domain
@<Logging domain@> =
#undef G_LOG_DOMAIN@/
#define G_LOG_DOMAIN "Marpa"@/

@*0 Message callbacks.
The user can define a callback
(with argument) which is invoked whenever |libmarpa|
has a message for the upper layers.
Note a lot of strings are used for convenience
in these messages.
These should be considered "cookies", 
as is they were file name or variables names.
They should not be regarded as part of the user
interface, even if some default or fallback routines
may sometimes expose them to the user.
And they should
not be subject to internationalization or localization.

These message cookies are always null-terminated in
the 7-bit ASCII character set.
This is a lowest common denominator, and is not a choice
binding on the upper layers,
which may use one of the Unicode encoding or anything
else.
Cookies often are mnemonics in the English language,
but this should not be regarded
as a reason to subject them to translation ---
at least not unless you are also translating the variable
names and file names.

The intent is to have all internationalization,
localization and string encoding issues dealt with
by the upper layers.
@<Public typedefs@> =
typedef const gchar* Marpa_Message_ID;
@ Function pointer declarations are
hard to type and impossible to read.
This typedef localizes the damage.
@<Callback typedefs@> =
typedef void (Marpa_Message_Callback)(struct marpa_g *g, Marpa_Message_ID id);
@ @<Pointer aligned grammar elements@> =
    Marpa_Message_Callback* message_callback;
    void *message_callback_arg;
@ @<Function definitions@> =
void marpa_message_callback_set(struct marpa_g *g, Marpa_Message_Callback*cb)
{ g->message_callback = cb; }
void marpa_message_callback_arg_set(struct marpa_g *g, void *cb_arg)
{ g->message_callback_arg = cb_arg; }
void* marpa_message_callback_arg_peek(struct marpa_g *g)
{ return g->message_callback_arg; }
@ @<Public function prototypes@> =
void marpa_message_callback_set(struct marpa_g *g, Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g *g, void *cb_arg);
void* marpa_message_callback_arg_peek(struct marpa_g *g);
@ Do the message callback.
@<Function definitions@> =
static inline message(struct marpa_g *g, Marpa_Message_ID id)
{ Marpa_Message_Callback* cb = g->message_callback;
if (cb) { (*cb)(g, id); } }
@ @<Private function prototypes@> =
static inline message(struct marpa_g *g, Marpa_Message_ID id);

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

@** Templates.

@*0 Simple Lists.

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
The output files are not source files,
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
#pragma GCC diagnostic warning "-Wmissing-declarations"
#pragma GCC diagnostic warning "-Wconversion"

#include "config.h"
#include "marpa.h"
@h
@<Logging domain@>@;
@<Private typedefs@>@;
@<Private global variables@>@;
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

