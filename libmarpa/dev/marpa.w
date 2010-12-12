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
@s gpointer int
@s gconstpointer int
@s guint int
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

@<Body of public header file@> =
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

@ Marpa Global Setup

Marpa does no global initialization at the moment.
I'll try to keep it that way.
If I can't, I will need to deal with the issue
of thread safety.

@** Grammar Objects.
@<Private structures@> = struct marpa_g {
@<Widely aligned grammar elements@>@/
@<Int aligned grammar elements@>@/
@<Bit aligned grammar elements@>@/
};

@ @<Function definitions@> =
struct marpa_g* marpa_g_new( void)
{ struct marpa_g* g = g_slice_new(struct marpa_g);
    @<Initialize grammar elements@>@;
   return g; }
@ @<Public function prototypes@> =
struct marpa_g* marpa_g_new(void);

@ @<Function definitions@> =
void marpa_g_destroy(struct marpa_g *g)
{ @<Destroy grammar elements@>@;
g_slice_free(struct marpa_g, g);
}
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
gint marpa_grammar_id(struct marpa_g* g) { return g->id; }
@ @<Public function prototypes@> =
gint marpa_grammar_id(struct marpa_g* g);

@*0 The Grammar's Symbol List.
\rightskip 0pt plus 3em
This lists the symbols for the grammar,
with their
|Marpa_Symbol_ID| as the index.

\rightskip 0pt
@<Widely aligned grammar elements@> = GArray* symbols;
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
    g_array_insert_val(g->symbols, (unsigned)symbol_id, symbol);
}

@ Check that symbol is in valid range.
@<Function definitions@> =
static inline gint symbol_is_valid(
struct marpa_g *g, Marpa_Symbol_ID symbol_id) {
return symbol_id >= 0 && (guint)symbol_id < g->symbols->len;
}
@ @<Private function prototypes@> =
static inline gint symbol_is_valid(
struct marpa_g *g, Marpa_Symbol_ID symbol_id);

@*0 The Grammar's Rule List.
This lists the rules for the grammar,
with their |Marpa_Rule_ID| as the index.
@<Widely aligned grammar elements@> = GArray* rules;
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
static inline gint rule_count(const struct marpa_g* g) {
   return g->rules->len;
}
@ @<Private function prototypes@> =
static inline gint rule_count(const struct marpa_g* g);

@ Internal accessor to find a rule by its id.
@<Function definitions@> =
static inline struct marpa_rule*
rule_id2p(const struct marpa_g* g, Marpa_Rule_ID id)
{ return g_array_index(g->rules, struct marpa_rule*, id); }
@ @<Private function prototypes@> =
static inline struct marpa_rule*
rule_id2p(const struct marpa_g* g, Marpa_Rule_ID id);

@ Adds the rule to the list of rules kept by the Grammar
object.
@<Private inline functions@> =
static inline
void marpa_g_rule_add(
    struct marpa_g *g,
    Marpa_Rule_ID rule_id,
    struct marpa_rule*rule)
{
    g_array_insert_val(g->rules, (unsigned)rule_id, rule);
    g->size += 1 + rule->length;
    g->max_rule_length = MAX(rule->length, g->max_rule_length);
}

@ Check that rule is in valid range.
@<Function definitions@> =
static inline gint rule_is_valid(
struct marpa_g *g, Marpa_Rule_ID rule_id) {
return rule_id >= 0 && (guint)rule_id < g->rules->len;
}
@ @<Private function prototypes@> =
static inline gint rule_is_valid(
struct marpa_g *g, Marpa_Rule_ID rule_id);

@*0 Grammar Start Symbol.
@<Int aligned grammar elements@> = Marpa_Symbol_ID start_symbol_id;
@ @<Initialize grammar elements@> =
g->start_symbol_id = -1;
@ The internal accessor would be trivial, so there is none.
@<Function definitions@> =
Marpa_Symbol_ID marpa_start_symbol(struct marpa_g* g)
{ return g->start_symbol_id; }
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_start_symbol(struct marpa_g* g);
@ Returns |TRUE| on success,
|FALSE| on failure.
@<Function definitions@> =
gboolean marpa_start_symbol_set(struct marpa_g*g, Marpa_Symbol_ID id)
{
    if (g->is_precomputed) {
        g->error = "precomputed";
	return FALSE;
    }
    if (!symbol_is_valid(g, id)) {
        g->error = "invalid start symbol";
	return FALSE;
    }
    g->start_symbol_id = id;
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
@ @<Int aligned grammar elements@> = guint max_rule_length;
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

@*0 Grammar Boolean: Has Loop.
@<Bit aligned grammar elements@> = unsigned int has_loop:1;
@ @<Initialize grammar elements@> =
g->has_loop = FALSE;
@ The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_has_loop(struct marpa_g* g)
{ return g->has_loop; }
@ @<Public function prototypes@> =
gboolean marpa_has_loop(struct marpa_g* g);

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

@*0 The Grammar's Context.
The "context" is a hash of miscellaneous data,
by keyword.
It is so called because its purpose is to 
provide callbacks with "context" ---
data about
|libmarpa|'s state which is not conveniently
available in other forms.
@<Widely aligned grammar elements@> = GHashTable* context;
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

@*0 The Grammar's Obstack.
Create an obstack with the lifetime of the grammar.
This is a very efficient way of allocating memory which won't be
resized and which will have the same lifetime as the grammar.
@<Widely aligned grammar elements@> = struct obstack obs;
@ @<Initialize grammar elements@> = obstack_init(&g->obs);
@ @<Destroy grammar elements@> = obstack_free(&g->obs, NULL);

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
@ @<Widely aligned grammar elements@> = Marpa_Error_ID error;
@ @<Initialize grammar elements@> =
g->error = 0;
@ There is no destructor.
The error strings are assummed to be
{\bf not} error messages, but "cookies".
These cookies are constants residing in static memory
(which may be read-only depending on implementation).
They cannot and should not be de-allocated.
@ @<Function definitions@> =
Marpa_Error_ID marpa_error(const struct marpa_g* g)
{ return g->error ? g->error : "unknown error"; }
@ @<Public function prototypes@> =
Marpa_Error_ID marpa_error(const struct marpa_g* g);

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

@ This function is probably going to become 
|marpa_r_free()|.
@<Function definitions@> =
void marpa_r_destroy(struct marpa_r *recce G_GNUC_UNUSED) { }
@ @<Public function prototypes@> =
void marpa_r_destroy(struct marpa_r *recce);

@** Symbol Objects.
@<Public typedefs@> =
typedef gint Marpa_Symbol_ID;
@ @<Private structures@> =
struct marpa_symbol {
    @<Widely aligned symbol elements@>@/
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
{  Marpa_Symbol_ID id; for (id = 0; id < (Marpa_Symbol_ID)g->symbols->len; id++)
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
@<Widely aligned symbol elements@> = GArray* lhs;
@ @<Initialize symbol elements@> =
symbol->lhs = g_array_new(FALSE, FALSE, sizeof(Marpa_Rule_ID));
@ @<Free symbol elements@> = g_array_free(symbol->lhs, TRUE);
@ The trace accessor returns the GArray.
It remains "owned" by the Grammar,
and must not be freed or modified.
@<Function definitions@> = 
GArray *marpa_symbol_lhs_peek(struct marpa_g* g, Marpa_Symbol_ID symbol_id)
{ @<Return |NULL| on failure@>@;
@<Fail if |symbol_id| is invalid@>@;
return symbol_id2p(g, symbol_id)->lhs; }
@ @<Public function prototypes@> =
GArray *marpa_symbol_lhs_peek(struct marpa_g* g, Marpa_Symbol_ID symbol_id);
@ @<Function definitions@> = static inline
void symbol_lhs_add(struct marpa_symbol*symbol, Marpa_Rule_ID rule_id)
{ g_array_append_val(symbol->lhs, rule_id); }
void
marpa_symbol_lhs_add(struct marpa_g*g, Marpa_Symbol_ID symbol_id, Marpa_Rule_ID rule_id)
{ symbol_lhs_add(symbol_id2p(g, symbol_id), rule_id); }
@ @<Private function prototypes@> =
void
marpa_symbol_lhs_add(struct marpa_g*g, Marpa_Symbol_ID symbol_id, Marpa_Rule_ID rule_id);

@*0 Symbol RHS Rules Element.
This tracks the rules for which this symbol is the RHS.
It is an optimization --- the same information could be found
by scanning the rules every time this information is needed.
The implementation is a |GArray|.
@<Widely aligned symbol elements@> = GArray* rhs;
@ @<Initialize symbol elements@> =
symbol->rhs = g_array_new(FALSE, FALSE, sizeof(Marpa_Rule_ID));
@ @<Free symbol elements@> = g_array_free(symbol->rhs, TRUE);
@ The trace accessor returns the GArray.
It remains "owned" by the Grammar,
and must not be freed or modified.
@<Function definitions@> = 
GArray *marpa_symbol_rhs_peek(struct marpa_g* g, Marpa_Symbol_ID symbol_id)
{ @<Return |NULL| on failure@>@;
@<Fail if |symbol_id| is invalid@>@;
return symbol_id2p(g, symbol_id)->rhs; }
@ @<Public function prototypes@> =
GArray *marpa_symbol_rhs_peek(struct marpa_g* g, Marpa_Symbol_ID symbol_id);
@ @<Function definitions@> = static inline
void symbol_rhs_add(struct marpa_symbol*symbol, Marpa_Rule_ID rule_id)
{ g_array_append_val(symbol->rhs, rule_id); }
@ @<Private function prototypes@> = static inline
void symbol_rhs_add(struct marpa_symbol*symbol, Marpa_Rule_ID rule_id);

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
gboolean marpa_symbol_is_accessible(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_accessible; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_accessible(struct marpa_g* g, Marpa_Symbol_ID id);
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
gboolean marpa_symbol_is_counted(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_counted; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_counted(struct marpa_g* g, Marpa_Symbol_ID id);

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
gboolean marpa_symbol_is_nullable(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_nullable; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_nullable(struct marpa_g* g, Marpa_Symbol_ID id);
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
{ @<Return |-1| on failure@>@;
@<Fail if |symbol_id| is invalid@>@;
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
gboolean marpa_symbol_is_terminal(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_terminal; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_terminal(struct marpa_g* g, Marpa_Symbol_ID id);
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
gboolean marpa_symbol_is_productive(struct marpa_g* g, Marpa_Symbol_ID id)
{ return symbol_id2p(g, id)->is_productive; }
@ @<Public function prototypes@> =
gboolean marpa_symbol_is_productive(struct marpa_g* g, Marpa_Symbol_ID id);
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
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
static inline
gint symbol_is_start(struct marpa_symbol* symbol)
{ return symbol->is_start; }
gint marpa_symbol_is_start( struct marpa_g*g, Marpa_Symbol_ID symbol_id) 
{ @<Return |-1| on failure@>@;
@<Fail if |symbol_id| is invalid@>@;
   return symbol_is_start(symbol_id2p(g, symbol_id));
}
@ @<Private function prototypes@> =
static inline
gint symbol_is_start(struct marpa_symbol* symbol);
@ @<Public function prototypes@> =
gint marpa_symbol_is_start( struct marpa_g*g, Marpa_Symbol_ID id);

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
@ @<Widely aligned symbol elements@> =
struct marpa_symbol* alias;
@ @<Initialize symbol elements@> =
symbol->is_proper_alias = FALSE;
symbol->is_nulling_alias = FALSE;
symbol->alias = NULL;

@ Proper Alias Trace Accessor:
If this symbol is a nulling symbol
with a proper alias, returns the proper alias.
Otherwise, returns |NULL|.
@<Function definitions@> =
static inline
struct marpa_symbol* symbol_proper_alias(struct marpa_symbol* symbol)
{ return symbol->is_nulling_alias ? symbol->alias : NULL; }
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g* g, Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol* symbol;
struct marpa_symbol* proper_alias;
@<Return |-1| on failure@>@;
@<Fail if |symbol_id| is invalid@>@;
symbol = symbol_id2p(g, symbol_id);
proper_alias = symbol_proper_alias(symbol);
return proper_alias == NULL ? -1 : proper_alias->id;
}
@ @<Private function prototypes@> =
static inline struct marpa_symbol* symbol_proper_alias(struct marpa_symbol* symbol);
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g* g, Marpa_Symbol_ID symbol_id);

@ Nulling Alias Trace Accessor:
If this symbol is a proper (non-nullable) symbol
with a nulling alias, returns the nulling alias.
Otherwise, returns |NULL|.
@<Function definitions@> =
static inline
struct marpa_symbol* symbol_null_alias(struct marpa_symbol* symbol)
{ return symbol->is_proper_alias ? symbol->alias : NULL; }
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g* g, Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol* symbol;
struct marpa_symbol* alias;
@<Return |-1| on failure@>@;
@<Fail if |symbol_id| is invalid@>@;
symbol = symbol_id2p(g, symbol_id);
alias = symbol_null_alias(symbol);
if (alias == NULL) {
    context_int_add(g, "symbol_id", symbol_id);
    g->error = "no alias";
    return -1;
}
return alias->id;
}
@ @<Private function prototypes@> =
static inline struct marpa_symbol* symbol_null_alias(struct marpa_symbol* symbol);
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g* g, Marpa_Symbol_ID symbol_id);

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
    if ((guint)original_id >= g->symbols->len) { return -1; }
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
@ @<Widely aligned grammar elements@> =
    Marpa_Symbol_Callback* symbol_callback;
    void *symbol_callback_arg;
@ @<Function definitions@> =
void marpa_symbol_callback_set(struct marpa_g *g, Marpa_Symbol_Callback*cb)
{ g->symbol_callback = cb; }
void marpa_symbol_callback_arg_set(struct marpa_g *g, void *cb_arg)
{ g->symbol_callback_arg = cb_arg; }
void* marpa_symbol_callback_arg(struct marpa_g *g)
{ return g->symbol_callback_arg; }
@ @<Public function prototypes@> =
void marpa_symbol_callback_set(struct marpa_g *g, Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g *g, void *cb_arg);
void* marpa_symbol_callback_arg(struct marpa_g *g);
@ Do the symbol callback.
@^To Do@>  To Do: Deal with the possibility of leaking memory if the callback
never returns, but the grammar is destroyed.
@<Function definitions@> =
static inline void symbol_callback(struct marpa_g *g, Marpa_Symbol_ID id)
{ Marpa_Symbol_Callback* cb = g->symbol_callback;
if (cb) { (*cb)(g, id); } }
@ @<Private function prototypes@> =
static inline void symbol_callback(struct marpa_g *g, Marpa_Symbol_ID id);

@** Rule Objects.
@<Public typedefs@> =
typedef gint Marpa_Rule_ID;
@ @<Private structures@> =
struct marpa_rule {
    @<Int aligned rule elements@>@/
    @<Bit aligned rule elements@>@/
    @<Final rule elements@>@/
};
@ @<Function definitions@> =
static inline guint rule_sizeof(guint length) {
return sizeof(struct marpa_rule) + length*sizeof(Marpa_Symbol_ID);
}
@ @<Private function prototypes@> =
static inline guint rule_sizeof(guint length);

@*0 Rule Construction.
@ Set up the basic data.
This logic is intended to be common to all individual rules.
The name comes from the idea that this logic "starts"
the initialization of a rule.
@ GCC complains about inlining |rule_start| -- it is
not a tiny function, and it is repeated often.
@<Function definitions@> =
static
struct marpa_rule* rule_start(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, guint length)
{
    struct marpa_rule* rule;
    @<Return |NULL| on invalid rule symbols@>@/
    rule = g_malloc(rule_sizeof(length));
    @<Initialize rule symbols@>@/
    @<Initialize rule elements@>@/
    marpa_g_rule_add(g, rule->id, rule);
    @<Add this rule to the symbol rule lists@>
   return rule;
}
@ @<Private function prototypes@> =
static
struct marpa_rule* rule_start(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, guint length);

@ @<Function definitions@> =
Marpa_Rule_ID marpa_rule_new(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, guint length)
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
guint min, gint flags )
{
    Marpa_Rule_ID original_rule_id;
    struct marpa_rule* original_rule;
    Marpa_Symbol_ID internal_lhs_id, *temp_rhs;@;
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
guint min, gint flags );
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
guint rhs_ix, i;
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
guint rhs_ix = 0;
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
@<Function definitions@> =
static inline
gboolean is_rule_duplicate(struct marpa_g* g,
Marpa_Symbol_ID lhs_id, Marpa_Symbol_ID* rhs_ids, guint length)
{
    guint ix;
    struct marpa_symbol* lhs = symbol_id2p(g, lhs_id);
    GArray* same_lhs_array = lhs->lhs;
    guint same_lhs_count = same_lhs_array->len;
    for (ix = 0; ix < same_lhs_count; ix++) {
	Marpa_Rule_ID same_lhs_rule_id = ((Marpa_Rule_ID *)(same_lhs_array->data))[ix];
	guint rhs_position;
	struct marpa_rule* rule = rule_id2p(g, same_lhs_rule_id);
	if (rule->length != length) { goto RULE_IS_NOT_DUPLICATE; }
	for (rhs_position = 0; rhs_position < rule->length; rhs_position++) {
	    if (rhs_symbol_id(rule, rhs_position) != rhs_ids[rhs_position]) {
	        goto RULE_IS_NOT_DUPLICATE;
	    }
	}
	return TRUE; /* This rule duplicates the new one */
	RULE_IS_NOT_DUPLICATE: ;
    }
    return FALSE; /* No duplicate rules were found */
}
@ @<Private function prototypes@> =
static inline
gboolean is_rule_duplicate(struct marpa_g* g,
Marpa_Symbol_ID lhs_id, Marpa_Symbol_ID* rhs_ids, guint length);

@ @<Public function prototypes@> =
Marpa_Rule_ID marpa_rule_new(struct marpa_g *g,
Marpa_Symbol_ID lhs, Marpa_Symbol_ID *rhs, guint length);

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
	const guint alloc_size = rule->length*sizeof( Marpa_Symbol_ID);
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
gint rhs_ix = (gint)rule->length-1;
rh_symbol_list[0] = rhs_symbol_id(rule, (unsigned)rhs_ix);
rh_symbol_list_length = 1;
rhs_ix--;
for (; rhs_ix >= 0; rhs_ix--) {
    gint higher_ix;
    Marpa_Symbol_ID new_symbol_id = rhs_symbol_id(rule, (unsigned)rhs_ix);
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
{  Marpa_Rule_ID id; for (id = 0; id < (Marpa_Rule_ID)g->rules->len; id++)
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
@<Int aligned rule elements@> = guint length;
@ The symbols come at the end of the |marpa_rule| structure,
so that they can be variable length.
@<Final rule elements@> = Marpa_Symbol_ID symbols[1];
@ @<Return |NULL| on invalid rule symbols@> =
if (!symbol_is_valid(g, lhs)) { return NULL; }
{ guint rh_index; for (rh_index = 0; rh_index<length; rh_index++) {
    if (!symbol_is_valid(g, rhs[rh_index])) { return NULL; }
} }
@ @<Initialize rule symbols@> =
rule->length = length;
rule->symbols[0] = lhs;
{ guint i; for (i = 0; i<length; i++) {
    rule->symbols[i+1] = rhs[i]; } }
@ @<Function definitions@> =
static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule *rule) {
    return rule->symbols[0]; }
@ @<Private function prototypes@> =
static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule *rule);
@ @<Function definitions@> =
Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g *g, Marpa_Rule_ID rule_id) {
    @<Return |-1| on failure@>@;
    @<Fail if |rule_id| is invalid@>@;
    return rule_lhs_get(rule_id2p(g, rule_id)); }
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g *g, Marpa_Rule_ID rule_id);
@ @<Function definitions@> =
static inline Marpa_Symbol_ID* rule_rhs_get(struct marpa_rule *rule) {
    return rule->symbols+1; }
@ @<Private function prototypes@> =
static inline Marpa_Symbol_ID* rule_rhs_get(struct marpa_rule *rule);
@ @<Function definitions@> =
Marpa_Symbol_ID* marpa_rule_rhs_peek(struct marpa_g *g, Marpa_Rule_ID rule_id) {
    @<Return |NULL| on failure@>@;
    @<Fail if |rule_id| is invalid@>@;
    return rule_rhs_get(rule_id2p(g, rule_id)); }
@ @<Public function prototypes@> =
Marpa_Symbol_ID* marpa_rule_rhs_peek(struct marpa_g *g, Marpa_Rule_ID rule_id);
@ @<Function definitions@> =
static inline gsize rule_length_get(struct marpa_rule *rule) {
    return rule->length; }
@ @<Private function prototypes@> =
static inline gsize rule_length_get(struct marpa_rule *rule);
@ @<Function definitions@> =
gint marpa_rule_length(struct marpa_g *g, Marpa_Rule_ID rule_id) {
    @<Return |-1| on failure@>@;
    @<Fail if |rule_id| is invalid@>@;
    return rule_length_get(rule_id2p(g, rule_id)); }
@ @<Public function prototypes@> =
gint marpa_rule_length(struct marpa_g *g, Marpa_Rule_ID rule_id);

@ @<Function definitions@> =
static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule* rule) { return rule->symbols[0]; }
@ @<Private function prototypes@> =
static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule* rule);
@ @<Function definitions@> =
static inline Marpa_Symbol_ID
    rhs_symbol_id(struct marpa_rule* rule, guint rh_index) {
	return rule->symbols[rh_index+1];
    }
@ @<Private function prototypes@> =
static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule* rule, guint rh_index);

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
{
    @<Return |-1| on failure@>@;
struct marpa_rule* rule;
    @<Fail if |rule_id| is invalid@>@;
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
guint rh_ix;
for (rh_ix = 0; rh_ix < rule->length; rh_ix++) {
   Marpa_Symbol_ID rhs_id = rhs_symbol_id(rule, rh_ix);
   if ( !symbol_id2p(g, rhs_id)->is_productive ) return FALSE;
}
return TRUE; }
gint marpa_rule_is_productive(struct marpa_g* g, Marpa_Rule_ID rule_id)
{
    @<Return |-1| on failure@>@;
struct marpa_rule* rule;
    @<Fail if |rule_id| is invalid@>@;
rule = rule_id2p(g, rule_id);
return rule_is_productive(g, rule);
}
@ @<Private function prototypes@> =
static inline gint rule_is_productive(struct marpa_g* g, struct marpa_rule* rule);
@ @<Public function prototypes@> =
gint marpa_rule_is_productive(struct marpa_g* g, Marpa_Rule_ID id);

@*0 Loop Rule.
@ A rule is a loop rule if it non-trivially
produces the string of length one
which consists only of its LHS symbol.
"Non-trivially" means the zero-step derivation does not count -- the
derivation must have at least one step.
@<Bit aligned rule elements@> = unsigned int is_loop:1;
@ @<Initialize rule elements@> =
rule->is_loop = FALSE;
@ This is the external accessor.
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gint marpa_rule_is_loop(struct marpa_g* g, Marpa_Rule_ID rule_id)
{
    @<Return |-1| on failure@>@;
    @<Fail if |rule_id| is invalid@>@;
return rule_id2p(g, rule_id)->is_loop; }
@ @<Public function prototypes@> =
gint marpa_rule_is_loop(struct marpa_g* g, Marpa_Rule_ID rule_id);

@*0 Virtual Loop Rule.
@ When dealing with rules which result from the CHAF rewrite,
it is convenient to recognize the "loop rule" property as belonging
to only one of the pieces.
The "virtual loop rule" property exists for this purpose.
All virtual loop rules are loop rules,
but not vice versa.
@<Bit aligned rule elements@> = unsigned int is_virtual_loop:1;
@ @<Initialize rule elements@> =
rule->is_virtual_loop = FALSE;
@ This is the external accessor.
The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gint marpa_rule_is_virtual_loop(struct marpa_g* g, Marpa_Rule_ID rule_id)
{
    @<Return |-1| on failure@>@;
    @<Fail if |rule_id| is invalid@>@;
return rule_id2p(g, rule_id)->is_virtual_loop; }
@ @<Public function prototypes@> =
gint marpa_rule_is_virtual_loop(struct marpa_g* g, Marpa_Rule_ID rule_id);

@*0 Nulling Rules.
@ A rule is nulling if every symbol on its RHS is nulling.
Note that this can be vacuously true --- an empty rule is nulling.
@<Function definitions@> =
static inline gint rule_is_nulling(struct marpa_g* g, struct marpa_rule* rule)
{
guint rh_ix;
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
gint marpa_rule_is_used(struct marpa_g* g, Marpa_Rule_ID rule_id)
{
    @<Return |-1| on failure@>@;
    @<Fail if |rule_id| is invalid@>@;
return rule_id2p(g, rule_id)->is_used; }
@ @<Public function prototypes@> =
gint marpa_rule_is_used(struct marpa_g* g, Marpa_Rule_ID rule_id);

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
gboolean marpa_rule_is_virtual_lhs(struct marpa_g* g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->is_virtual_lhs; }
@ @<Public function prototypes@> =
gboolean marpa_rule_is_virtual_lhs(struct marpa_g* g, Marpa_Rule_ID id);

@*0 Rule Boolean: Virtual RHS.
@<Bit aligned rule elements@> = unsigned int is_virtual_rhs:1;
@ @<Initialize rule elements@> =
rule->is_virtual_rhs = FALSE;
@ The internal accessor would be trivial, so there is none.
@<Function definitions@> =
gboolean marpa_rule_is_virtual_rhs(struct marpa_g* g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->is_virtual_rhs; }
@ @<Public function prototypes@> =
gboolean marpa_rule_is_virtual_rhs(struct marpa_g* g, Marpa_Rule_ID id);

@*0 Virtual Start Position.
For a virtual rule,
this is the RHS position in the original rule
where this one starts.
@<Int aligned rule elements@> = gint virtual_start;
@ @<Initialize rule elements@> = rule->virtual_start = -1;

@*0 Virtual End Position.
For a virtual rule,
this is the RHS position in the original rule
at which this one ends.
@<Int aligned rule elements@> = gint virtual_end;
@ @<Initialize rule elements@> = rule->virtual_end = -1;

@*0 Rule Callbacks.
The user can define a callback
(with argument) which is invoked whenever a rule
is created.
@ Function pointer declarations are
hard to type and impossible to read.
This typedef localizes the damage.
@<Callback typedefs@> =
typedef void (Marpa_Rule_Callback)(struct marpa_g *g, Marpa_Rule_ID id);
@ @<Widely aligned grammar elements@> =
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
void* marpa_rule_callback_arg(struct marpa_g *g)
{ return g->rule_callback_arg; }
@ @<Public function prototypes@> =
void* marpa_rule_callback_arg(struct marpa_g *g);
@ Do the rule callback.
@^To Do@>  To Do: Deal with the possibility of leaking memory if the callback
never returns, but the grammar is destroyed.
@<Function definitions@> =
static inline void rule_callback(struct marpa_g *g, Marpa_Rule_ID id)
{ Marpa_Rule_Callback* cb = g->rule_callback;
if (cb) { (*cb)(g, id); } }
@ @<Private function prototypes@> =
static inline void rule_callback(struct marpa_g *g, Marpa_Rule_ID id);

@*0 Rule Original.
In many cases, Marpa will rewrite a rule.
If this rule is the result of a rewriting, this element contains
the ID of the original rule.
@ @<Int aligned rule elements@> = Marpa_Rule_ID original;
@ @<Initialize rule elements@> = rule->original = -1;
@ @<Function definitions@> =
Marpa_Rule_ID marpa_rule_original(const struct marpa_g *g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->original; }
@ @<Public function prototypes@> =
Marpa_Rule_ID marpa_rule_original(const struct marpa_g *g, Marpa_Rule_ID id);

@*0 Rule Real Symbol Count.
This is another data element used for the "internal semantics" --
the logic to reassemble results of rewritten rules so that they
look as if they came from the original, un-rewritten rules.
The value of this field is meaningful if and only if
the rule has a virtual rhs or a virtual lhs.
@ @<Int aligned rule elements@> = guint real_symbol_count;
@ @<Initialize rule elements@> = rule->real_symbol_count = 0;
@ @<Function definitions@> =
guint marpa_real_symbol_count(const struct marpa_g *g, Marpa_Rule_ID id)
{ return rule_id2p(g, id)->real_symbol_count; }
@ @<Public function prototypes@> =
guint marpa_real_symbol_count(const struct marpa_g *g, Marpa_Rule_ID id);

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
Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g* g, Marpa_Rule_ID id)
{
struct marpa_rule* rewrite_rule = rule_id2p(g, id);
return rewrite_rule->is_semantic_equivalent ? rewrite_rule->original : -1; }
@ @<Public function prototypes@> =
Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g* g, Marpa_Rule_ID id);

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
     if (!g_augment(g)) return NULL;
    loop_detect(g);
    create_AHFA_items(g);
    create_AHFA_states(g);
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
static struct marpa_g* census(struct marpa_g* g)
{
    @<Declare census variables@>@;
    @<Return |NULL| if  empty grammar@>@;
    @<Return |NULL| if already precomputed@>@;
    @<Return |NULL| if bad start symbol@>@;
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
@ @<Private function prototypes@> =
static struct marpa_g* census(struct marpa_g* g);
@ @<Declare census variables@> =
guint pre_rewrite_rule_count = g->rules->len;
guint pre_rewrite_symbol_count = g->symbols->len;

@ @<Return |NULL| if empty grammar@> =
if (g->rules->len <= 0) { g->error = "no rules"; return NULL; }
@ The upper layers have a lot of latitude with this one.
There's no harm done, so the upper layers can simply ignore this one.
On the other hand, the upper layer may see this as a sign of a major
logic error, and treat it as a fatal error.
Anything in between these two extremes is also possible.
@<Return |NULL| if already precomputed@> =
if (g->is_precomputed) { g->error = "precomputed"; return NULL; }
@ Loop over the rules, producing bit vector of LHS symbols, and of
symbols which are the LHS of empty rules.
While at it, set a flag to indicate if there are empty rules.

@ @<Return |NULL| if bad start symbol@> =
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
Marpa_Symbol_ID original_start_symbol_id = g->start_symbol_id;
struct marpa_symbol* original_start_symbol;

@ @<Census LHS symbols@> =
{ Marpa_Rule_ID rule_id;
lhs_v = bv_create(pre_rewrite_symbol_count);
empty_lhs_v = bv_shadow(lhs_v);
for (rule_id = 0;
	rule_id < (Marpa_Rule_ID)pre_rewrite_rule_count;
	rule_id++) {
    struct marpa_rule* rule = rule_id2p(g, rule_id);
    Marpa_Symbol_ID lhs_id = lhs_symbol_id(rule);
    bv_bit_set(lhs_v, (guint)lhs_id);
    if (rule->length <= 0) {
	bv_bit_set(empty_lhs_v, (guint)lhs_id);
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
for (symbol_id = 0;
	symbol_id < (Marpa_Symbol_ID)pre_rewrite_symbol_count;
	symbol_id++) {
    struct marpa_symbol* symbol = symbol_id2p(g, symbol_id);
    if (symbol->is_terminal) {
	bv_bit_set(terminal_v, (guint)symbol_id);
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
    guint start = 0;
    guint min, max;
    Bit_Vector bad_lhs_v = bv_clone(terminal_v);
    bv_and(bad_lhs_v, bad_lhs_v, lhs_v);
    while ( bv_scan(bad_lhs_v, start, &min, &max) ) {
	Marpa_Symbol_ID i;
	for (i = (Marpa_Symbol_ID)min; i <= (Marpa_Symbol_ID)max; i++) {
	    context_clear(g);
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
for (symbol_id = 0; symbol_id < (Marpa_Symbol_ID)g->symbols->len; symbol_id++)
{ symbol_id2p(g, symbol_id)->is_terminal = 1; } }
@ @<Mark non-LHS symbols terminal@> = 
{ guint start = 0;
guint min, max;
bv_not(terminal_v, lhs_v);
while ( bv_scan(terminal_v, start, &min, &max) ) {
    Marpa_Symbol_ID symbol_id;
    for (symbol_id = (Marpa_Symbol_ID)min; symbol_id <= (Marpa_Symbol_ID)max; symbol_id++) {
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
{ guint min, max, start;
Marpa_Symbol_ID symbol_id;
gint counted_nullables = 0;
    for ( start = 0; bv_scan(nullable_v, start, &min, &max); start = max+2 ) {
	for (symbol_id = (Marpa_Symbol_ID)min; symbol_id <= (Marpa_Symbol_ID)max; symbol_id++) {
	    struct marpa_symbol *symbol = symbol_id2p(g, symbol_id);
	    if (symbol->is_counted) {
		context_clear(g);
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
{ guint min, max, start;
Marpa_Symbol_ID symbol_id;
    for ( start = 0; bv_scan(productive_v, start, &min, &max); start = max+2 ) {
	for (symbol_id = (Marpa_Symbol_ID)min;
		symbol_id <= (Marpa_Symbol_ID)max;
		symbol_id++) {
	    struct marpa_symbol *symbol = symbol_id2p(g, symbol_id);
	    symbol->is_productive = 1;
} }
}
@ @<Check that start symbol is productive@> =
if (!bv_bit_test(productive_v, (guint)g->start_symbol_id))
{
    context_int_add(g, "symbol_id", g->start_symbol_id);
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
reach_matrix
    = matrix_create(pre_rewrite_symbol_count, pre_rewrite_symbol_count);
{ guint symbol_id, no_of_symbols = symbol_count(g);
for (symbol_id = 0; symbol_id < no_of_symbols; symbol_id++) {
     matrix_bit_set(reach_matrix, symbol_id, symbol_id);
} }
{ Marpa_Rule_ID rule_id;
guint no_of_rules = rule_count(g);
for (rule_id = 0; rule_id < (Marpa_Rule_ID)no_of_rules; rule_id++) {
     struct marpa_rule* rule = rule_id2p(g, rule_id);
     Marpa_Symbol_ID lhs_id = lhs_symbol_id(rule);
     guint rhs_ix, rule_length = rule->length;
     for (rhs_ix = 0; rhs_ix < rule_length; rhs_ix++) {
	 matrix_bit_set(reach_matrix,
	     (guint)lhs_id, (guint)rhs_symbol_id(rule, rhs_ix));
} } }
transitive_closure(reach_matrix);
@ @<Declare census variables@> = Bit_Matrix reach_matrix;
@ @<Free Boolean matrixes@> =
matrix_free(reach_matrix);

@ @<Census accessible symbols@> = 
accessible_v = matrix_row(reach_matrix, (guint)original_start_symbol_id);
{ guint min, max, start;
Marpa_Symbol_ID symbol_id;
    for ( start = 0; bv_scan(accessible_v, start, &min, &max); start = max+2 ) {
	for (symbol_id = (Marpa_Symbol_ID)min;
		symbol_id <= (Marpa_Symbol_ID)max;
		symbol_id++) {
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
guint min, max, start;
for ( start = 0; bv_scan(productive_v, start, &min, &max); start = max+2 ) {
	Marpa_Symbol_ID productive_id;
	for (productive_id = (Marpa_Symbol_ID)min;
		productive_id <= (Marpa_Symbol_ID)max;
		productive_id++) {
	    bv_and(reaches_terminal_v, terminal_v, matrix_row(reach_matrix, (guint)productive_id));
	    if (bv_is_empty(reaches_terminal_v)) symbol_id2p(g, productive_id)->is_nulling=1;
} }
bv_free(reaches_terminal_v); }

@** The CHAF Rewrite.

Nullable symbols have been a difficulty for Earley implementations
since day zero.
Aycock and Horspool came up with a solution to this problem,
part of which involved rewriting the grammar to eliminate
all proper nullables.
Marpa's CHAF rewrite is built on the work of Aycock and
Horspool.

Marpa's CHAF rewrite is one of its two rewrites of the BNF.
The other
adds a new start symbol to the grammar.

@ The rewrite strategy for Marpa is new to it.
It is an elaboration on the one developed by Aycock and Horspool.
The basic idea behind Aycock and Horspool's NNF was to elimnate
proper nullables by replacing the rules with variants which
used only nulling and non-nulling symbols.
These had to be created for every possible combination
of nulling and non-nulling symbols.
This meant that the number of NNF rules was
potentially exponential
in the length of rule of the original grammar.

@ Marpa's CHAF (Chomsky-Horspool-Aycock Form) eliminates
the problem of exponential explosion by first breaking rules
up into pieces, each piece containing no more than two proper nullables.
The number of rewritten rules in CHAF in linear in the length of
the original rule.

@ The CHAF rewrite affects only rules with proper nullables.
In this context, the proper nullables are called "factors".
Each piece of the original rule is rewritten into up to four
"factored pieces".
When there are two proper nullables, the potential CHAF rules
are
\li The PP rule:  Both factors are replaced with non-nulling symbols.
\li The PN rule:  The first factor is replaced with a non-nulling symbol,
and the second factor is replaced with a nulling symbol.
\li The NP rule: The first factor is replaced with a nulling symbol,
and the second factor is replaced with a non-nulling symbol.
\li The NN rule: Both factors are replaced with nulling symbols.

@ Sometimes the CHAF piece will have only one factor.  A one-factor
piece is rewritten into at most two factored pieces:
\li The P rule:  The factor is replaced with a non-nulling symbol.
\li The N rule:  The factor is replaced with a nulling symbol.

@ In |CHAF_rewrite|, a |rule_count| is taken before the loop over
the grammar's rules, even though rules are added in the loop.
This is not an error.
The CHAF rewrite is not recursive -- the new rules it creates
are not themselves subject to CHAF rewrite.
And rule ID's increase by one each time,
so that all the new
rules will have ID's equal to or greater than |no_of_rules|.
@ @<Function definitions@> =
static inline struct marpa_g* CHAF_rewrite(struct marpa_g* g)
{
    @<CHAF rewrite declarations@>@;
    @<CHAF rewrite allocations@>@;
     @<Alias proper nullables@>@;
    no_of_rules = rule_count(g);
    for (rule_id = 0; rule_id < no_of_rules; rule_id++) {
         struct marpa_rule* rule = rule_id2p(g, rule_id);
	 guint rule_length = rule->length;
	 guint nullable_suffix_ix = 0;
	 @<Mark and skip unused rules@>@;
	 @<Calculate CHAF rule statistics@>@;
	 /* If there is no proper nullable in this rule, we are done */
	 if (factor_count <= 0) goto NEXT_RULE;
	 @<Factor the rule into CHAF rules@>@;
	 NEXT_RULE: ;
    }
    @<CHAF rewrite deallocations@>@;
    return g;
}
@ @<Private function prototypes@> =
static inline struct marpa_g* CHAF_rewrite(struct marpa_g* g);
@ @<CHAF rewrite declarations@> =
Marpa_Rule_ID rule_id;
gint no_of_rules;

@ @<Mark and skip unused rules@> =
if (!rule->is_used) { goto NEXT_RULE; }
if (rule_is_nulling(g, rule)) { rule->is_used = 0; goto NEXT_RULE; }
if (!rule_is_accessible(g, rule)) { rule->is_used = 0; goto NEXT_RULE; }
if (!rule_is_productive(g, rule)) { rule->is_used = 0; goto NEXT_RULE; }

@ For every accessible and productive proper nullable which
is not already aliased, alias it.
@<Alias proper nullables@> =
{ gint no_of_symbols = symbol_count(g);
Marpa_Symbol_ID symbol_id;
for (symbol_id = 0; symbol_id < no_of_symbols; symbol_id++) {
     struct marpa_symbol* symbol = symbol_id2p(g, symbol_id);
     struct marpa_symbol* alias;
     if (!symbol->is_nullable) continue;
     if (symbol->is_nulling) continue;
     if (!symbol->is_accessible) continue;
     if (!symbol->is_productive) continue;
     if (symbol_null_alias(symbol)) continue;
    alias = symbol_alias_create(g, symbol);
    symbol_callback(g, alias->id);
} }

@*0 Compute Statistics Needed to Rewrite the Rule.
The term
"factor" is used to mean an instance of a proper nullable
symbol on the RHS of a rule.
This comes from the idea that replacing the proper nullables
with proper symbols and nulling symbols "factors" pieces
of the rule being rewritten (the original rule)
into multiple CHAF rules.
@<Calculate CHAF rule statistics@> =
{ guint rhs_ix;
factor_count = 0;
for (rhs_ix = 0; rhs_ix < rule_length; rhs_ix++) {
     Marpa_Symbol_ID symbol_id = rhs_symbol_id(rule, rhs_ix);
     struct marpa_symbol* symbol = symbol_id2p(g, symbol_id);
     if (symbol->is_nulling) continue; /* Do nothing for nulling symbols */
     if (symbol_null_alias(symbol)) {
     /* If a proper nullable, record its position */
	 factor_positions[factor_count++] = rhs_ix;
	 continue;
    }@#
     nullable_suffix_ix = rhs_ix+1;
/* If not a nullable symbol, move forward the index
 of the nullable suffix location */
} }
@ @<CHAF rewrite declarations@> =
guint factor_count;
guint* factor_positions;
@ @<CHAF rewrite allocations@> =
factor_positions = g_new(guint, g->max_rule_length);
@ @<CHAF rewrite deallocations@> =
g_free(factor_positions);

@*0 Divide the Rule into Pieces.
@<Factor the rule into CHAF rules@> =
rule->is_used = 0; /* Mark the original rule unused */
{ guint unprocessed_factor_count; /* The number of proper nullables for which CHAF rules have
yet to be written */
guint factor_position_ix = 0; /* Current index into the list of factors */
Marpa_Symbol_ID current_lhs_id = lhs_symbol_id(rule);
guint piece_end, piece_start = 0; /* The positions, in the original rule, where
the new (virtual) rule starts and ends */
for (unprocessed_factor_count = factor_count - factor_position_ix;
unprocessed_factor_count >= 3;
unprocessed_factor_count = factor_count - factor_position_ix) {
    @<Add non-final CHAF rules@>@;
}
if (unprocessed_factor_count == 2) {
	@<Add final CHAF rules for two factors@>@;
} else {
	@<Add final CHAF rules for one factor@>@;
} }

@ @<Create a CHAF virtual symbol@> = {
    struct marpa_symbol* chaf_virtual_symbol = symbol_new(g);
    chaf_virtual_symbol->is_accessible = 1;
    chaf_virtual_symbol->is_productive = 1;
    chaf_virtual_symbol_id = chaf_virtual_symbol->id;
    context_clear(g);
    context_int_add(g, "rule_id", rule_id);
    context_int_add(g, "lhs_id", lhs_symbol_id(rule));
    context_int_add(g, "virtual_end", (gint)piece_end);
    symbol_callback(g, chaf_virtual_symbol_id);
}

@*0 Temporary buffers for the CHAF right hand sides.
Two temporary buffers are used in factoring out CHAF rules.
|piece_rhs| is for the normal case, where only the symbols
of the current piece are on the RHS.
In certain cases, where the remainder of the rule is nulling,
further factoring is unnecessary and the CHAF rewrite simply
finishes out the rule with nulling symbols.
In such cases, the RHS is built in the
|remaining_rhs| buffer.
@<CHAF rewrite declarations@> =
Marpa_Symbol_ID* piece_rhs;
Marpa_Symbol_ID* remaining_rhs;
@ @<CHAF rewrite allocations@> =
piece_rhs = g_new(Marpa_Symbol_ID, g->max_rule_length);
remaining_rhs = g_new(Marpa_Symbol_ID, g->max_rule_length);
@ @<CHAF rewrite deallocations@> =
g_free(piece_rhs);
g_free(remaining_rhs);

@*0 Factor A Non-Final Piece.
@ As long as we have more than 3 unprocessed factors, we are working on a non-final
rule.
@<Add non-final CHAF rules@> =
    Marpa_Symbol_ID chaf_virtual_symbol_id;
    guint first_factor_position = factor_positions[factor_position_ix];
    guint first_factor_piece_position = first_factor_position - piece_start;
    guint second_factor_position = factor_positions[factor_position_ix+1];
    if (second_factor_position >= nullable_suffix_ix) {
	piece_end = second_factor_position-1;
        /* The last factor is in the nullable suffix, so the virtual RHS must be nullable */
	@<Create a CHAF virtual symbol@>@;
	@<Add CHAF rules for nullable continuation@>@;
	factor_position_ix++;
    } else {
	gint second_factor_piece_position = second_factor_position - piece_start;
	piece_end = second_factor_position;
	@<Create a CHAF virtual symbol@>@;
	@<Add CHAF rules for proper continuation@>@;
	factor_position_ix += 2;
    }
    current_lhs_id = chaf_virtual_symbol_id;
    piece_start = piece_end+1;

@*0 Add CHAF Rules for Nullable Continuations.
For a piece that has a nullable continuation,
the virtual RHS counts
as one of the two allowed proper nullables.
That means the piece must
end before the second proper nullable (or factor).
@<Add CHAF rules for nullable continuation@> =
{
    guint remaining_rhs_length, piece_rhs_length;
    @<Add PP CHAF rule for nullable continuation@>;
    @<Add PN CHAF rule for nullable continuation@>;
    @<Add NP CHAF rule for nullable continuation@>;
    @<Add NN CHAF rule for nullable continuation@>;
}

@ Note that since the first part of |remaining_rhs| is exactly the same
as the first part of |piece_rhs| so we copy it here in preparation
for the PN rule.
@<Add PP CHAF rule for nullable continuation@> =
{
guint real_symbol_count = piece_end - piece_start + 1;
for (piece_rhs_length = 0; piece_rhs_length < real_symbol_count; piece_rhs_length++) {
   remaining_rhs[piece_rhs_length] =
   piece_rhs[piece_rhs_length] = rhs_symbol_id(rule, piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++] = chaf_virtual_symbol_id;
}
{ struct marpa_rule* chaf_rule;
    guint real_symbol_count = piece_rhs_length - 1;
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;
}

@ @<Add PN CHAF rule for nullable continuation@> =
{ guint chaf_rule_length = rule->length - piece_start;
for (remaining_rhs_length=piece_rhs_length-1 ;
	remaining_rhs_length < chaf_rule_length;
	remaining_rhs_length++) {
    Marpa_Symbol_ID original_id = rhs_symbol_id(rule, piece_start+remaining_rhs_length);
    struct marpa_symbol* alias = symbol_null_alias(symbol_id2p(g, original_id));
    remaining_rhs[remaining_rhs_length] = alias ? alias->id : original_id;
} }
{ struct marpa_rule* chaf_rule;
    guint real_symbol_count = remaining_rhs_length;
    chaf_rule = rule_start(g, current_lhs_id, remaining_rhs, remaining_rhs_length);
    @<Set CHAF rule flags and call back@>@;
}

@ Note, while we have the nulling alias for the first factor,
|remaining_rhs| is altered to be ready for the NN rule.
@<Add NP CHAF rule for nullable continuation@> = {
    Marpa_Symbol_ID proper_id = rhs_symbol_id(rule, first_factor_position);
    struct marpa_symbol* alias = symbol_null_alias(symbol_id2p(g, proper_id));
    remaining_rhs[first_factor_piece_position] =
	piece_rhs[first_factor_piece_position] =
	alias->id;
}
{ struct marpa_rule* chaf_rule;
 guint real_symbol_count = piece_rhs_length-1;
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;
}

@ If this piece is nullable (|piece_start| at or
after |nullable_suffix_ix|), we don't add an NN choice,
because nulling both factors makes the entire piece nulling,
and nulling rules cannot be fed directly to
the Marpa parse engine.
Note that |remaining_rhs| was altered above.
@<Add NN CHAF rule for nullable continuation@> =
if (piece_start < nullable_suffix_ix) {
 struct marpa_rule* chaf_rule;
 guint real_symbol_count = remaining_rhs_length;
    chaf_rule = rule_start(g, current_lhs_id, remaining_rhs, remaining_rhs_length);
    @<Set CHAF rule flags and call back@>@;
}

@*0 Add CHAF Rules for Proper Continuations.
@ Open block and declarations.
@<Add CHAF rules for proper continuation@> = {
    guint piece_rhs_length;
struct marpa_rule* chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id, second_factor_proper_id,
	first_factor_alias_id, second_factor_alias_id;
real_symbol_count = piece_end - piece_start + 1;

@ The PP Rule.
@<Add CHAF rules for proper continuation@> = 
    for (piece_rhs_length = 0; piece_rhs_length < real_symbol_count; piece_rhs_length++) {
	piece_rhs[piece_rhs_length] = rhs_symbol_id(rule, piece_start+piece_rhs_length);
    }
    piece_rhs[piece_rhs_length++] = chaf_virtual_symbol_id;
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;

@ The PN Rule.
@<Add CHAF rules for proper continuation@> = 
    second_factor_proper_id = rhs_symbol_id(rule, second_factor_position);
    piece_rhs[second_factor_piece_position]
	= second_factor_alias_id = alias_by_id(g, second_factor_proper_id);
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;

@ The NP Rule.
@<Add CHAF rules for proper continuation@> = 
    first_factor_proper_id = rhs_symbol_id(rule, first_factor_position);
    piece_rhs[first_factor_piece_position]
	= first_factor_alias_id = alias_by_id(g, first_factor_proper_id);
    piece_rhs[second_factor_piece_position] = second_factor_proper_id;
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;

@ The NN Rule.
@<Add CHAF rules for proper continuation@> = 
    piece_rhs[second_factor_piece_position] = second_factor_alias_id;
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;

@ Close the block
@<Add CHAF rules for proper continuation@> = }

@*0 Add Final CHAF Rules for Two Factors.
Open block, declarations and setup.
@<Add final CHAF rules for two factors@> = {
guint first_factor_position = factor_positions[factor_position_ix];
guint first_factor_piece_position = first_factor_position - piece_start;
guint second_factor_position = factor_positions[factor_position_ix+1];
guint second_factor_piece_position = second_factor_position - piece_start;
guint real_symbol_count;
guint piece_rhs_length;
struct marpa_rule* chaf_rule;
Marpa_Symbol_ID first_factor_proper_id, second_factor_proper_id,
	first_factor_alias_id, second_factor_alias_id;
piece_end = rule->length-1;
real_symbol_count = piece_end - piece_start + 1;

@ The PP Rule.
@<Add final CHAF rules for two factors@> = 
    for (piece_rhs_length = 0; piece_rhs_length < real_symbol_count; piece_rhs_length++) {
	piece_rhs[piece_rhs_length] = rhs_symbol_id(rule, piece_start+piece_rhs_length);
    }
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;

@ The PN Rule.
@<Add final CHAF rules for two factors@> =
    second_factor_proper_id = rhs_symbol_id(rule, second_factor_position);
    piece_rhs[second_factor_piece_position]
	= second_factor_alias_id = alias_by_id(g, second_factor_proper_id);
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;

@ The NP Rule.
@<Add final CHAF rules for two factors@> =
    first_factor_proper_id = rhs_symbol_id(rule, first_factor_position);
    piece_rhs[first_factor_piece_position]
	= first_factor_alias_id = alias_by_id(g, first_factor_proper_id);
    piece_rhs[second_factor_piece_position] = second_factor_proper_id;
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;

@ The NN Rule.  This is added only if it would not turn this into
a nulling rule.
@<Add final CHAF rules for two factors@> =
if (piece_start < nullable_suffix_ix) {
    piece_rhs[second_factor_piece_position] = second_factor_alias_id;
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;
}

@ Close the block
@<Add final CHAF rules for two factors@> = }

@*0 Add Final CHAF Rules for One Factor.
@<Add final CHAF rules for one factor@> = {
guint piece_rhs_length;
struct marpa_rule* chaf_rule;
Marpa_Symbol_ID first_factor_proper_id, first_factor_alias_id;
guint real_symbol_count;
guint first_factor_position = factor_positions[factor_position_ix];
guint first_factor_piece_position = factor_positions[factor_position_ix] - piece_start;
piece_end = rule->length-1;
real_symbol_count = piece_end - piece_start + 1;

@ The P Rule.
@<Add final CHAF rules for one factor@> = 
    for (piece_rhs_length = 0; piece_rhs_length < real_symbol_count; piece_rhs_length++) {
	piece_rhs[piece_rhs_length] = rhs_symbol_id(rule, piece_start+piece_rhs_length);
    }
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;

@ The N Rule.  This is added only if it would not turn this into
a nulling rule.
@<Add final CHAF rules for one factor@> =
if (piece_start < nullable_suffix_ix) {
    first_factor_proper_id = rhs_symbol_id(rule, first_factor_position);
    first_factor_alias_id = alias_by_id(g, first_factor_proper_id);
    piece_rhs[first_factor_piece_position] = first_factor_alias_id;
    chaf_rule = rule_start(g, current_lhs_id, piece_rhs, piece_rhs_length);
    @<Set CHAF rule flags and call back@>@;
}

@ Close the block
@<Add final CHAF rules for one factor@> = }

@ Some of the code for adding CHAF rules is common to
them all.
This include the setting of many of the elements of the 
rule structure, and performing the call back.
@<Set CHAF rule flags and call back@> =
chaf_rule->is_used = 1;
chaf_rule->original = rule_id;
chaf_rule->is_virtual_lhs = piece_start > 0;
chaf_rule->is_semantic_equivalent = !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs = chaf_rule->length > real_symbol_count;
chaf_rule->virtual_start = piece_start;
chaf_rule->virtual_end = piece_start + real_symbol_count - 1;
chaf_rule->real_symbol_count = real_symbol_count;
    rule_callback(g, chaf_rule->id);

@ This utility routine translates a proper symbol id to a nulling symbol ID.
It is assumed that the caller has ensured that
|proper_id| is valid and that an alias actually exists.
@<Function definitions@> =
static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g* g, Marpa_Symbol_ID proper_id) {
     struct marpa_symbol* alias = symbol_null_alias(symbol_id2p(g, proper_id));
     return alias->id;
}
@ @<Private function prototypes@> =
static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g* g, Marpa_Symbol_ID proper_id);

@** Adding a New Start Symbol.
This is such a common rewrite that it has a special name
in the literature --- it is called "augmenting the grammar".

@ @<Function definitions@> =
static inline
struct marpa_g* g_augment(struct marpa_g* g) {
    Marpa_Symbol_ID proper_new_start_id = -1;
    struct marpa_symbol* proper_old_start = NULL;
    struct marpa_symbol* nulling_old_start = NULL;
    struct marpa_symbol* proper_new_start = NULL;
    struct marpa_symbol* old_start = symbol_id2p(g, g->start_symbol_id);
    @<Find and classify the old start symbols@>@;
    if (proper_old_start) { @<Set up a new proper start rule@> }
    if (nulling_old_start) { @<Set up a new nulling start rule@> }
    return g;
}
@ @<Private function prototypes@> =
static inline struct marpa_g* g_augment(struct marpa_g* g);

@ @<Find and classify the old start symbols@> =
if (old_start->is_nulling) {
   old_start->is_accessible = 0;
    nulling_old_start = old_start;
} else {
    proper_old_start = old_start;
    nulling_old_start = symbol_null_alias(old_start);
}
old_start->is_start = 0;

@ @<Set up a new proper start rule@> = {
struct marpa_rule* new_start_rule;
proper_old_start->is_start = 0;
proper_new_start = symbol_new(g);
proper_new_start_id = proper_new_start->id;
g->start_symbol_id = proper_new_start_id;
proper_new_start->is_accessible = TRUE;
proper_new_start->is_productive = TRUE;
proper_new_start->is_start = TRUE;
context_clear(g);
context_int_add(g, "old_start_id", old_start->id);
symbol_callback(g, proper_new_start_id);
new_start_rule = rule_start(g, proper_new_start_id, &old_start->id, 1);
new_start_rule->is_virtual_lhs = 1;
new_start_rule->real_symbol_count = 1;
new_start_rule->is_used = TRUE;
    rule_callback(g, new_start_rule->id);
}

@ Set up the new nulling start rule, if the old start symbol was
nulling or had a null alias.  A new nulling start symbol
must be created.  It is an alias of the new proper start symbol,
if there is one.  Otherwise it is a new, nulling, symbol.
@<Set up a new nulling start rule@> = {
Marpa_Symbol_ID nulling_new_start_id;
struct marpa_rule* new_start_rule;
struct marpa_symbol* nulling_new_start;
if (proper_new_start) { /* There are two start symbols */
    nulling_new_start = symbol_alias_create(g, proper_new_start);
    nulling_new_start_id = nulling_new_start->id;
} else { /* The only start symbol is a nulling symbol */
    nulling_new_start = symbol_new(g);
    nulling_new_start_id = nulling_new_start->id;
    g->start_symbol_id = nulling_new_start_id;
    nulling_new_start->is_nulling = TRUE;
    nulling_new_start->is_nullable = TRUE;
    nulling_new_start->is_productive = TRUE;
    nulling_new_start->is_accessible = TRUE;
}
nulling_new_start->is_start = TRUE;
context_clear(g);
context_int_add(g, "old_start_id", old_start->id);
symbol_callback(g, nulling_new_start_id);
new_start_rule = rule_start(g, nulling_new_start_id, 0, 0);
new_start_rule->is_virtual_lhs = 1;
new_start_rule->real_symbol_count = 1;
new_start_rule->is_used = TRUE;
    rule_callback(g, new_start_rule->id);
}

@** Loops.
Loops are rules which non-trivially derive their own LHS.
More precisely, a rule is a loop if and only if it
non-trivially derives a string which contains its LHS symbol
and is of length 1.
In my experience,
and according to Grune and Jacobs 2008 (pp. 48-49),
loops are never of practical use.

@ Marpa allows loops, for two reasons.
Because Marpa handles all context-free grammars,
it is very easy to know beforehand whether Marpa can
handle a particular grammar.
If you can write a grammar in BNF, then Marpa can handle it ---
it's that simple.
To make this claim, Marpa must be able to handle grammars
with loops.

Second, a user's user drafts of a grammar might contain cycles.
A parser generator which did not handle them would force
the user's first order of business to be removing them.

@ The grammar precomputations and the recognition
phase have been set up so that
loops are a complete non-issue --- they are dealt with like
any other situation, without additional overhead.
However, loops do impose overhead and require special
handling in the evaluation phase.
It is unlikely that a user will want to leave one in
a production grammar.

@ Marpa detects all loops during its grammar
precomputation.
|libmarpa| assumes that parsing will go through as usual,
with the loops.
But it enables the upper layers to make other choices
by passing a message for every symbol involved in a
loop,
as well as a final message with the count of looping symbols.

@<Function definitions@> =
static inline
void loop_detect(struct marpa_g* g)
{ guint no_of_rules = rule_count(g);
gint loop_rule_count = 0;
Bit_Matrix unit_transition_matrix
    = matrix_create( no_of_rules , no_of_rules);
@<Mark direct unit transitions in |unit_transition_matrix|@>@;
transitive_closure(unit_transition_matrix);
@<Mark loop rules@>@;
if (loop_rule_count) g->has_loop = TRUE;
@<Report loop rule count@>@;
matrix_free(unit_transition_matrix);
}
@ @<Private function prototypes@> =
static inline
void loop_detect(struct marpa_g* g);

@ Note that direct transitions are marked in advance,
but not trivial ones.
That is, bit |(x,x)| is not set |TRUE| in advance.
In other words, for this purpose,
unit transitions are not in general reflexive.
@<Mark direct unit transitions in |unit_transition_matrix|@> = {
Marpa_Rule_ID rule_id;
for (rule_id = 0; rule_id < (Marpa_Rule_ID)no_of_rules; rule_id++) {
     struct marpa_rule* rule = rule_id2p(g, rule_id);
     Marpa_Symbol_ID proper_id;
     guint rhs_ix, rule_length;
     if (!rule->is_used) continue;
     rule_length = rule->length;
     proper_id = -1;
     for (rhs_ix = 0; rhs_ix < rule_length; rhs_ix++) {
	 Marpa_Symbol_ID symbol_id = rhs_symbol_id(rule, rhs_ix);
	 struct marpa_symbol* symbol = symbol_id2p(g, symbol_id);
	 if (symbol->is_nullable) continue; /* After the CHAF rewrite, nullable $\E$ nulling */
	 if (proper_id >= 0) goto NEXT_RULE; /* More
	     than one proper symbol -- not a unit rule */
	 proper_id = symbol_id;
    }
    @#
    if (proper_id < 0) continue; /* A
	nulling start rule is allowed, so there may be no proper symbol */
     { struct marpa_symbol* rhs_symbol = symbol_id2p(g, proper_id);
     GArray* lhs_rules = rhs_symbol->lhs;
     guint ix, no_of_lhs_rules = lhs_rules->len;
     for (ix = 0; ix < no_of_lhs_rules; ix++) {
	 /* Direct loops ($A \RA A$) only need the $(rule_id, rule_id)$ bit set,
	    but it is not clear that it is a win to special case them. */
	 matrix_bit_set(unit_transition_matrix, (guint)rule_id,
	     (guint)g_array_index(lhs_rules, Marpa_Rule_ID, ix));
     } }
     NEXT_RULE: ;
} }

@ Virtual loop rule are loop rules from the virtual point of view.
When CHAF rules, which are rewritten into multiple pieces,
it is inconvenient to see each piece as a loop rule.
Therefore only certain of CHAF pieces that are loop rules
are regarded as virtual loop rules.
All non-CHAF rules are virtual loop rules including,
at this point, sequence rules.
@<Mark loop rules@> = { Marpa_Rule_ID rule_id;
for (rule_id = 0; rule_id < (Marpa_Rule_ID)no_of_rules; rule_id++) {
    struct marpa_rule* rule;
    if (!matrix_bit_test(unit_transition_matrix, (guint)rule_id, (guint)rule_id))
	continue;
    loop_rule_count++;
    rule = rule_id2p(g, rule_id);
    rule->is_loop = TRUE;
    rule->is_virtual_loop = rule->virtual_start < 0 || !rule->is_virtual_rhs;
    context_clear(g);
    context_int_add(g, "rule_id", rule_id);
    message(g, "loop rule");
} }

@ The higher layers can differ greatly in their treatment
of loop rules.  It is perfectly reasonable for a higher layer to treat a loop
rule as a fatal error.
It is also reasonable for a higher layer to always silently allow them.
There are lots of possibilities in between these two extremes.
To assist the upper layers, the reporting is very thorough ---
there is not just a message for each loop rule, but also a final tally.
@<Report loop rule count@> =
context_clear(g);
context_int_add(g, "loop_rule_count", loop_rule_count);
message(g, "loop rule tally");

@** The Aycock-Horspool Finite Automata.

@*0 Some Statistics on AHFA states.
For Perl's grammar, the kernel states range in size from 1 to 20 items,
but the numbers are heavily skewed toward the low
end.  Here are the item counts that appear, with the percent of the total
kernel AHFA states with that item count in parentheses.
in parentheses:
1   (67.05\%);
2   (25.67\%);
3   (2.87\%);
4   (2.68\%);
5   (0.19\%);
6   (0.38\%);
7   (0.19\%);
8   (0.57\%);
9   (0.19\%); and
20   (0.19\%).
As can be seen, well over 90\% of the total kernel states have
just one or two items.
For the HTML grammars I used, the totals are even more lopsided:
80.96\% of all kernel states have only 1 item.
All the others (19.04\%) have 2 items.

The number of non-kernel states tends to be much more
evently distributed.
It also tends to be much larger, and
the average for practical grammars may be $O(s)$,
where $s$ is the size of the grammar.
This is the same as the theoretical worst case.

Here are the number of items for non-kernel states for the Perl grammar.
The number of states with that item count in is parentheses:
1 item (3),
2 items (5),
3 items (4),
4 items (3),
5 items (1),
6 items (2),
7 items (2),
64 items (1),
71 items (1),
77 items (1),
79 items (1),
81 items (1),
83 items (1),
85 items (1),
88 items (1),
90 items (1),
98 items (1),
100 items (1),
102 items (1),
104 items (1),
106 items (1),
108 items (1),
111 items (1),
116 items (1),
127 items (1),
129 items (1),
132 items (1),
135 items (1),
136 items (1),
137 items (1),
141 items (1),
142 items (4),
143 items (2),
144 items (1),
149 items (1),
151 items (1),
156 items (1),
157 items (1),
220 items (1),
224 items (1),
225 items (1).
And here is the same data for some grammar of HTML:
1 item (95),
2 items (95),
4 items (95),
11 items (181),
14 items (181),
15 items (294),
16 items (112),
18 items (349),
19 items (120),
20 items (190),
21 items (63),
22 items (22),
24 items (8),
25 items (16),
26 items (16),
28 items (2),
29 items (16).


@** AHFA Items.
AHFA states are sets of AHFA items.
AHFA items are named by analogy with LR(0) items.
LR(0) items play the same role in the LR(0) automaton that
AHFA items play in the AHFA ---
the states of the automata correspond to sets of the items.
Also like LR(0) items,
each AHFA items correponds one-to-one to a duple,
the duple being a a rule and a position in that rule.
@<Public typedefs@> =
typedef gint Marpa_AHFA_Item_ID;
@ @<Private structures@> =
struct AHFA_item {
    Marpa_Symbol_ID postdot; /* The symbol after the dot, -1
       for a completion */
    Marpa_AHFA_Item_ID sort_key;
    struct marpa_rule* rule;
    gint position; /* position in the RHS, -1 for a completion */
};
@ A pointer to two lists of AHFA items.
The one list contains the AHFA items themselves, in
AHFA item ID order.
The other is indexed by rule ID, and contains a pointer to
the first AHFA item for that rule.
@<Widely aligned grammar elements@> =
   struct AHFA_item* AHFA_items;
   struct AHFA_item** AHFA_items_by_rule;
@ @<Int aligned grammar elements@> =
   guint no_of_items;
@ The space is allocated during precomputation.
Because the grammar may be destroyed before precomputation,
I test that |g->AHFA_items| is non-zero.
@<Destroy grammar elements@> = if (g->AHFA_items) {
g_free(g->AHFA_items_by_rule);
g_free(g->AHFA_items);
};

@ @<Function definitions@> =
static inline struct AHFA_item* 
item_id2p(struct marpa_g* g, Marpa_AHFA_Item_ID item_id) {
    return g->AHFA_items+item_id;
}
@ @<Private function prototypes@> =
static inline struct AHFA_item*
item_id2p(struct marpa_g* g, Marpa_AHFA_Item_ID item_id);

@*0 AHFA Item External Accessors.
@<Function definitions@> =
guint marpa_AHFA_item_count(struct marpa_g* g) {
    @<Return |-1| on failure@>@/
    @<Fail if not precomputed@>@/
    return g->no_of_items;
}
@ @<Public function prototypes@> =
guint marpa_AHFA_item_count(struct marpa_g* g);

@ @<Function definitions@> =
Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g* g,
	Marpa_AHFA_Item_ID item_id) {
    @<Return |-1| on failure@>@/
    @<Fail if not precomputed@>@/
    @<Fail if |item_id| is invalid@>@/
    return item_id2p(g, item_id)->rule->id;
}
@ @<Public function prototypes@> =
Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g* g, Marpa_AHFA_Item_ID item_id);
@ |-1| is the value for completions, so |-2| is the failure indicator.
@<Function definitions@> =
gint marpa_AHFA_item_position(struct marpa_g* g,
	Marpa_AHFA_Item_ID item_id) {
    @<Return |-2| on failure@>@/
    @<Fail if not precomputed@>@/
    @<Fail if |item_id| is invalid@>@/
    return item_id2p(g, item_id)->position;
}
@ @<Public function prototypes@> =
gint marpa_AHFA_item_position(struct marpa_g* g, Marpa_AHFA_Item_ID item_id);
@ |-1| is the value for completions, so |-2| is the failure indicator.
@<Function definitions@> =
Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g* g,
	Marpa_AHFA_Item_ID item_id) {
    @<Return |-2| on failure@>@/
    @<Fail if not precomputed@>@/
    @<Fail if |item_id| is invalid@>@/
    return item_id2p(g, item_id)->postdot;
}
@ @<Public function prototypes@> =
Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g* g, Marpa_AHFA_Item_ID item_id);
@ @<Function definitions@> =
gint marpa_AHFA_item_sort_key(struct marpa_g* g,
	Marpa_AHFA_Item_ID item_id) {
    @<Return |-1| on failure@>@/
    @<Fail if not precomputed@>@/
    @<Fail if |item_id| is invalid@>@/
    return item_id2p(g, item_id)->sort_key;
}
@ @<Public function prototypes@> =
gint marpa_AHFA_item_sort_key(struct marpa_g* g, Marpa_AHFA_Item_ID item_id);

@ Check that symbol is in valid range.
@<Function definitions@> =
static inline gboolean item_is_valid(
const struct marpa_g *g, Marpa_AHFA_Item_ID item_id) {
return item_id < (Marpa_AHFA_Item_ID)g->no_of_items && item_id >= 0;
}
@ @<Private function prototypes@> =
static inline gboolean item_is_valid(
const struct marpa_g *g, Marpa_AHFA_Item_ID item_id);

@ I do not use a |DSTACK| because I can initially size the
item stack to |g->size|, which is a reasonable allocation,
but guaranteed to be greater than
or equal to the final numbers of items.
That means that I can avoid the overhead of checking the array
size when adding each new AHFA item.
@<Function definitions@> =
static inline
void create_AHFA_items(struct marpa_g* g) {
    Marpa_Rule_ID rule_id;
    guint no_of_items;
    guint no_of_rules = rule_count(g);
    struct AHFA_item* base_item = g_new(struct AHFA_item, g->size);
    struct AHFA_item* current_item = base_item;
    for (rule_id = 0; rule_id < (Marpa_Rule_ID)no_of_rules; rule_id++) {
	@<Create the AHFA items for a rule@>@;
	NEXT_RULE: ;
    }
    no_of_items = g->no_of_items = current_item - base_item;
    g->AHFA_items = g_renew(struct AHFA_item, base_item, no_of_items);
    @<Set up the items-by-rule list@>@;
    @<Set up the AHFA item ids@>@;
}
@ @<Private function prototypes@> =
static inline void create_AHFA_items(struct marpa_g* g);

@ @<Create the AHFA items for a rule@> =
guint rhs_ix;
struct marpa_rule* rule = rule_id2p(g, rule_id);
if (!rule->is_used) goto NEXT_RULE;
for (rhs_ix = 0; rhs_ix < rule->length; rhs_ix++) {
     @<Create an AHFA item for a precompletion@>@;
     current_item++;
     NEXT_RH_SYMBOL: ;
}
@<Create an AHFA item for a completion@>@;
current_item++;

@ @<Create an AHFA item for a precompletion@> =
Marpa_Symbol_ID rh_symbol_id = rhs_symbol_id(rule, rhs_ix);
struct marpa_symbol* symbol = symbol_id2p(g, rh_symbol_id);
if (symbol->is_nullable) goto NEXT_RH_SYMBOL;
current_item->sort_key = current_item - base_item;
current_item->postdot = rh_symbol_id;
current_item->rule = rule;
current_item->position = rhs_ix;

@ @<Create an AHFA item for a completion@> =
current_item->sort_key = current_item - base_item;
current_item->postdot = current_item->position = -1;
current_item->rule = rule;

@ This is done after creating the AHFA items, because in
theory the |g_renew| might have moved them.
This is not likely since the |g_renew| shortened the array,
but if you are hoping for portability,
you want to follow the rules.
@<Set up the items-by-rule list@> = {
struct AHFA_item** items_by_rule = g_new0(struct AHFA_item *, no_of_rules); /* Must be
zeroed because not all entries will be populated */
struct AHFA_item* items = g->AHFA_items;
Marpa_Rule_ID highest_found_rule_id = -1; /* The highest ID of a rule whose AHFA items
    have been found */
Marpa_AHFA_Item_ID item_id;
for (item_id = 0; item_id < (Marpa_AHFA_Item_ID)no_of_items; item_id++) {
     struct AHFA_item* item = items+item_id;
     Marpa_Rule_ID rule_id_for_item = item->rule->id;
     if (rule_id_for_item <= highest_found_rule_id) continue;
     items_by_rule[rule_id_for_item] = item;
     highest_found_rule_id = rule_id_for_item;
}
g->AHFA_items_by_rule = items_by_rule; }

@ The AHFA items were created with a temporary ID which sorts them
by rule, then by position within that rule.  We need one that sort the AHFA items
by (from major to minor) postdot symbol, then rule, then position.
A postdot symbol of $-1$ should sort high.
@ @<Function definitions@> =
static gint cmp_by_AHFA_item_id (gconstpointer ap,
	gconstpointer bp, gpointer user_data G_GNUC_UNUSED) {
    struct AHFA_item *a = *(struct AHFA_item**)ap;
    struct AHFA_item *b = *(struct AHFA_item**)bp;
    gint a_postdot = a->postdot;
    gint b_postdot = b->postdot;
    if (a_postdot == b_postdot) return a->sort_key - b->sort_key ;@#
    if (a_postdot < 0) return 1;
    if (b_postdot < 0) return -1;
    return a_postdot-b_postdot;
}
@ @<Private function prototypes@> =
static gint cmp_by_AHFA_item_id (gconstpointer a,
	gconstpointer b, gpointer user_data);
@ @<Set up the AHFA item ids@> = { Marpa_AHFA_Item_ID item_id;
struct AHFA_item** sort_array = g_new(struct AHFA_item*, no_of_items);
struct AHFA_item* items = g->AHFA_items;
for (item_id = 0; item_id < (Marpa_AHFA_Item_ID)no_of_items; item_id++) {
    /* Create an array of pointers to the old items,
      in order to sort them
      */
    sort_array[item_id] = items+item_id; 
}
g_qsort_with_data(sort_array,
    (gint)no_of_items, sizeof(struct AHFA_item*), cmp_by_AHFA_item_id, (gpointer)NULL);
for (item_id = 0; item_id < (Marpa_AHFA_Item_ID)no_of_items; item_id++) {
    sort_array[item_id]->sort_key = item_id;
}
g_free(sort_array); }

@** AHFA States.
@<Public typedefs@> =
typedef gint Marpa_AHFA_State_ID;

@ {\bf Estimating the number of AHFA States}: Based on the numbers given previously
for Perl and HTML,
$2s$ is a good high-ball estimate of the number of AHFA states for
grammars of practical interest,
where $s$ is the size of the grammar.
I come up with this as follows.

Let the size of an AHFA state be the number of AHFA items it contains.
\li It is impossible for the number of AHFA items to greater than
the size of the grammar.
\li It is impossible for the number of kernel states of size 1
to be greater than the number of AHFA items.
\li The number of kernel states of size 2 or greater
will typically be half the number of kernel states of size 1,
or less.
\li The number of non-kernel states will typically be
considerably less than half the number of kernel states.

The three possibilities just enumerated exhaust the possibilities for AHFA states.
The total is $s/2 + s/2 + s$, or $2s$.
Typically, the number of AHFA states should be less than this estimate.

@<Private structures@> =
struct AHFA_state {
    struct AHFA_item** items;
    guint item_count;
    unsigned int is_reset:1;
};
@ @<Widely aligned grammar elements@> = struct AHFA_state* AHFA;
@ @<Int aligned grammar elements@> = gint AHFA_len;
@ @<Destroy grammar elements@> = if (g->AHFA) { STOLEN_DQUEUE_DATA_FREE(g->AHFA); }

@ Internal accessor to find an AHFA state by its id.
@<Function definitions@> =
static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g* g, Marpa_AHFA_State_ID AHFA_state_id)
{ return g->AHFA+AHFA_state_id; }
@ @<Private function prototypes@> =
static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g* g, Marpa_AHFA_State_ID AHFA_state_id);

@ Check that symbol is in valid range.
@<Function definitions@> =
static inline gint AHFA_state_id_is_valid(
const struct marpa_g *g, Marpa_AHFA_State_ID AHFA_state_id) {
return AHFA_state_id < g->AHFA_len && AHFA_state_id >= 0;
}
@ @<Private function prototypes@> =
static inline gint AHFA_state_id_is_valid(
const struct marpa_g *g, Marpa_AHFA_State_ID AHFA_state_id);

@ Given an AHFA state
and an index into the array of items for an AHFA state,
return the |AHFA_Item_ID|.
\rightskip 0pt plus 3em
The caller must ensure that
the index is in range.\par
\rightskip 0pt
@<Function definitions@> =
static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g *g, const struct AHFA_state* state, guint item_ix) {
   return state->items[item_ix] - g->AHFA_items;
}
@ @<Private function prototypes@> =
static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g *g, const struct AHFA_state* state, guint item_ix);

@*0 AHFA State External Accessors.
@<Function definitions@> =
guint marpa_AHFA_state_count(struct marpa_g* g) {
    return g->AHFA_len;
}
@ @<Public function prototypes@> =
guint marpa_AHFA_state_count(struct marpa_g* g);

@ @<Function definitions@> =
gint
marpa_AHFA_state_item_count(struct marpa_g* g, Marpa_AHFA_State_ID AHFA_state_id)
{ @<Return |-1| on failure@>@/
    struct AHFA_state* state;
    @<Fail if not precomputed@>@/
    @<Fail if |AHFA_state_id| is invalid@>@/
    state = AHFA_state_id2p(g, AHFA_state_id);
    return state->item_count;
}
@ @<Public function prototypes@> =
gint marpa_AHFA_state_item_count(struct marpa_g* g, Marpa_AHFA_State_ID AHFA_state_id);

@ @<Function definitions@> =
Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g* g,
     Marpa_AHFA_State_ID AHFA_state_id,
	guint item_ix) {
    struct AHFA_state* state;
    @<Return |-1| on failure@>@/
    @<Fail if not precomputed@>@/
    @<Fail if |AHFA_state_id| is invalid@>@/
    state = AHFA_state_id2p(g, AHFA_state_id);
    if (item_ix >= state->item_count) {
	context_clear(g);
	context_int_add(g, "item_ix", (gint)item_ix);
	context_int_add(g, "AHFA_state_id", AHFA_state_id);
	g->error = "invalid state item ix";
	return failure_indicator;
    }
    return AHFA_state_item_ix2id(g, state, item_ix);
}
@ @<Public function prototypes@> =
Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g* g,
     Marpa_AHFA_State_ID AHFA_state_id,
	guint item_ix);

@ @<Function definitions@> =
gint marpa_AHFA_state_is_reset(struct marpa_g* g,
	Marpa_AHFA_State_ID AHFA_state_id) {
    struct AHFA_state* state;
    @<Return |-1| on failure@>@/
    @<Fail if not precomputed@>@/
    @<Fail if |AHFA_state_id| is invalid@>@/
    state = AHFA_state_id2p(g, AHFA_state_id);
    return state->is_reset;
}
@ @<Public function prototypes@> =
gint marpa_AHFA_state_is_reset(struct marpa_g* g,
	Marpa_AHFA_State_ID AHFA_state_id);

@ @<Function definitions@> =
static inline
void create_AHFA_states(struct marpa_g* g) {
   const gint initial_no_of_states = 2*g->size;
   struct AHFA_state* p_state;
   DQUEUE_DEFINE(states);
   DQUEUE_INIT(states, struct AHFA_state, initial_no_of_states);@/
   p_state = DQUEUE_ADD(states, struct AHFA_state);@/
   @<Construct initial AHFA state@>@/
   while ((p_state = DQUEUE_NEXT(states, struct AHFA_state))) {
       @<Process an AHFA state from the working stack@>@;@/
   }
   g->AHFA = DQUEUE_BASE(states, struct AHFA_state); /* "Steals"
       the |DQUEUE|'s data */
   g->AHFA_len = DQUEUE_END(states);
}
@ @<Private function prototypes@> =
static inline void create_AHFA_states(struct marpa_g* g);

@ @<Construct initial AHFA state@> = {
   Marpa_Rule_ID start_rule_id;
   struct marpa_symbol* start_symbol = symbol_id2p(g, g->start_symbol_id);
   struct marpa_symbol* start_alias
       = symbol_null_alias(start_symbol);
    gint no_of_items_in_state = start_alias ? 2 : 1;
    struct AHFA_item ** item_list
	= obstack_alloc(&g->obs, no_of_items_in_state*sizeof(struct AHFA_item*));
    start_rule_id = g_array_index(start_symbol->lhs, Marpa_Rule_ID, 0); /* The start rule
	is the unique rule that has the start symbol as its LHS */
    item_list[0] = g->AHFA_items_by_rule[start_rule_id]; /* The start item is the
       initial item for the start rule */
    if (start_alias) {
       Marpa_Rule_ID alias_rule_id
	    = g_array_index(start_alias->lhs, Marpa_Rule_ID, 0); /* Start alias
	    rule is the unique rule that has
	   the start alias as its LHS */
	item_list[1] = g->AHFA_items_by_rule[alias_rule_id];
    }
    p_state->items = item_list;
    p_state->item_count = no_of_items_in_state;
}

@ @<Process an AHFA state from the working stack@> = {
guint no_of_items = p_state->item_count;
Marpa_AHFA_Item_ID current_item=0;
struct AHFA_item **items = p_state->items;
Marpa_Symbol_ID work_symbol = items[0]->postdot; /*
    Every AHFA has at least one item */
if (work_symbol == -1) goto NEXT_AHFA_STATE; /*
    All items in this state are completions */
    while (1) { /* Loop over all items for this state */
	guint first_item_for_working_symbol = current_item;
	for (current_item++;
		current_item < (Marpa_AHFA_Item_ID)no_of_items;
		current_item++) {
	    if (items[current_item]->postdot != work_symbol) break;
	}
	switch (current_item - first_item_for_working_symbol) {
	    case 1: @<Start a 1-item AHFA kernel state@>@;
	    break;
	    case 2: @<Start a 2-item AHFA kernel state@>@;
	    break;
	    default: @<Start an AHFA kernel state with 2+ items@>@/
	}
	/* $v_k$ will not be empty here */@/
	/* If $v_k$ is not new, next symbol */@/
	/* Add $v_k$ */@/
	@<Compute non-kernel state@>@/
	/* If $v_NK$ is not empty and is new, add it */@/
	if (current_item >= (Marpa_AHFA_Item_ID)no_of_items) break;
	work_symbol = items[current_item]->postdot;
	if (work_symbol == -1) break;
    }@#
NEXT_AHFA_STATE: ;
}

@ @<Start a 1-item AHFA kernel state@> = {;}
@ @<Start a 2-item AHFA kernel state@> = {;}
@ @<Start an AHFA kernel state with 2+ items@> = {;}

@ This can be done with a pass over the items in $v_k$.
For each post-dot symbol in that state, or the transitive closure of the
epsilon transitions into a rule vector.
The items in $v_NK$ will be the initial items of those rules.
@<Compute non-kernel state@> = ;

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
static inline guint bv_bits_to_size(guint bits)
{
    return (bits+bv_modmask)/bv_wordbits;
}
@ @<Private function prototypes@> =
static inline guint bv_bits_to_size(guint bits);
@ Given a number of bits, compute the unused-bit mask.
@<Function definitions@> =
static inline guint bv_bits_to_unused_mask(guint bits)
{
    guint mask = bits & bv_modmask;
    if (mask) mask = (guint) ~(~0uL << mask); else mask = (guint) ~0uL;
    return(mask);
}
@ @<Private function prototypes@> =
static inline guint bv_bits_to_unused_mask(guint bits);

@*0 Create a Boolean Vector.
Always start with an all-zero vector.
Note this code is a bit tricky ---
the pointer returned is to the data.
This is offset from the |g_malloc|'d space,
by |bv_hiddenwords|.
@<Function definitions@> =
static inline Bit_Vector bv_create(guint bits)
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
static inline Bit_Vector bv_create(guint bits);

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
@<Function definitions@> = static inline
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
static inline
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
    --bv;
    *bv &= BV_MASK(bv);
}
@ @<Private function prototypes@> =
static inline void bv_fill(Bit_Vector bv);

@*0 Set a Boolean Vector Bit.
@ @<Function definitions@> =
static inline void bv_bit_set(Bit_Vector vector, guint bit) {
    *(vector+(bit/bv_wordbits)) |= (bv_lsb << (bit%bv_wordbits));
}
@ @<Private function prototypes@> =
static inline void bv_bit_set(Bit_Vector vector, guint bit);

@*0 Clear a Boolean Vector Bit.
@<Function definitions@> =
static inline void bv_bit_clear(Bit_Vector vector, guint bit) {
    *(vector+(bit/bv_wordbits)) &= ~ (bv_lsb << (bit%bv_wordbits));
}
@ @<Private function prototypes@> =
static inline void bv_bit_clear(Bit_Vector vector, guint bit);

@*0 Test a Boolean Vector Bit.
@<Function definitions@> =
static inline gboolean bv_bit_test(Bit_Vector vector, guint bit) {
    return (*(vector+(bit/bv_wordbits)) & (bv_lsb << (bit%bv_wordbits))) != 0u;
}
@ @<Private function prototypes@> =
static inline gboolean bv_bit_test(Bit_Vector vector, guint bit);

@*0 Set a Boolean Vector to all Ones.
@*0 Test a Boolean Vector for all Zeroes.
@<Function definitions@> =
static inline
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
static inline
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
static inline
gboolean bv_scan(Bit_Vector bv, guint start,
                                    guint* min, guint* max)
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
static inline
gboolean bv_scan(
    Bit_Vector bv, guint start, guint* min, guint* max);

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
      guint min, max, start = 0;
      Marpa_Symbol_ID *top_of_stack = NULL;
      FSTACK_DEFINE(stack, Marpa_Symbol_ID);
      FSTACK_INIT(stack, Marpa_Symbol_ID, symbol_count(g));
	while ( bv_scan(bv, start, &min, &max) ) {
    guint symbol_id;
    for (symbol_id = min; symbol_id <= max; symbol_id++) {
        *(FSTACK_PUSH(stack)) = symbol_id;
    }
    start = max+2;
    }
    while ((top_of_stack = FSTACK_POP(stack))) {
	guint rule_ix;
	GArray* rules = symbol_id2p(g, *top_of_stack)->rhs;
	for (rule_ix = 0; rule_ix < rules->len; rule_ix++) {
	     Marpa_Rule_ID rule_id = g_array_index(rules, Marpa_Rule_ID, rule_ix);
	     struct marpa_rule* rule = rule_id2p(g, rule_id);
	     guint rule_length;
	     guint rh_ix;
	     Marpa_Symbol_ID lhs_id = lhs_symbol_id(rule);
	     if (bv_bit_test(bv, (guint)lhs_id)) goto NEXT_RULE;
	     rule_length = rule->length;
	     for (rh_ix = 0; rh_ix < rule_length; rh_ix++) {
		 if (!bv_bit_test(bv, (guint)rhs_symbol_id(rule, rh_ix))) goto NEXT_RULE;
	     }
	     /* If we are here, the bits for the RHS symbols are all
	      * set, but the one for the LHS symbol is not.
	      */
	      bv_bit_set(bv, (guint)lhs_id);
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
static inline Bit_Matrix matrix_create(guint rows, guint columns)
{
    guint bv_data_words = bv_bits_to_size(columns);
    guint row_bytes = (bv_data_words + bv_hiddenwords) * sizeof(Bit_Vector_Word);
    guint bv_mask = bv_bits_to_unused_mask(columns);
    Bit_Vector_Word* matrix_addr = g_malloc0((size_t)(row_bytes * rows));
    guint row;
    for (row = 0; row < rows; row++) {
	guint row_start = row*(bv_data_words+bv_hiddenwords);
	matrix_addr[row_start] = columns;
	matrix_addr[row_start+1] = bv_data_words;
	matrix_addr[row_start+2] = bv_mask;
    }
    return matrix_addr;
}
@ @<Private function prototypes@> =
static inline Bit_Matrix matrix_create(guint rows, guint columns);

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
static inline Bit_Vector matrix_row(Bit_Matrix matrix, guint row) {
    Bit_Vector row0 = matrix+bv_hiddenwords;
    guint words_per_row = BV_SIZE(row0)+bv_hiddenwords;
    return row0 + row*words_per_row;
}
@ @<Private function prototypes@> =
static inline Bit_Vector matrix_row(Bit_Matrix matrix, guint row);

@*0 Set a Boolean Matrix Bit.
@ @<Function definitions@> =
static inline void matrix_bit_set(Bit_Matrix matrix, guint row, guint column) {
    Bit_Vector vector = matrix_row(matrix, row);
    bv_bit_set(vector, column);
}
@ @<Private function prototypes@> =
static inline void matrix_bit_set(Bit_Matrix matrix, guint row, guint column);

@*0 Clear a Boolean Matrix Bit.
@ @<Function definitions@> =
static inline void matrix_bit_clear(Bit_Matrix matrix, guint row, guint column) {
    Bit_Vector vector = matrix_row(matrix, row);
    bv_bit_clear(vector, column);
}
@ @<Private function prototypes@> =
static inline void matrix_bit_clear(Bit_Matrix matrix, guint row, guint column);

@*0 Test a Boolean Matrix Bit.
@ @<Function definitions@> =
static inline gboolean matrix_bit_test(Bit_Matrix matrix, guint row, guint column) {
    Bit_Vector vector = matrix_row(matrix, row);
    return bv_bit_test(vector, column);
}
@ @<Private function prototypes@> =
static inline gboolean matrix_bit_test(Bit_Matrix matrix, guint row, guint column);

@*0 Produce the Transitive Closure of a Boolean Matrix.
This routine takes a matrix representing a relation
and produces a matrix that represents the transitive closure
of the relation.
The matrix is assumed to be square.
The input matrix will be destroyed.
@<Function definitions@> =
static void transitive_closure(Bit_Matrix matrix)
{
      struct transition { guint from, to; } * top_of_stack = NULL;
      guint size = matrix_columns(matrix);
      guint row;
      DSTACK_DEFINE(stack);
      DSTACK_INIT(stack, struct transition, 1024);
      for (row = 0; row < size; row++) {
          guint min, max, start;
	  Bit_Vector row_vector = matrix_row(matrix, row);
	for ( start = 0; bv_scan(row_vector, start, &min, &max); start = max+2 ) {
	    guint column;
	    for (column = min; column <= max; column++) {
		struct transition *t = DSTACK_PUSH(stack, struct transition);
		t->from = row;
		t->to = column;
    } } }
    while ((top_of_stack = DSTACK_POP(stack, struct transition))) {
	guint old_from = top_of_stack->from;
	guint old_to = top_of_stack->to;
	guint new_ix;
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

@** Pointer Arrays.
Pointer arrays can exist on their own,
or as part of a dynamic pointer array.
When considered on their own,
they are fixed in size.
@<ADT structures@> =
struct p_array { gint len; void **data; };
@ @<Function definitions@> =
static inline void p_array_destroy(struct p_array* pa) {
    void *data = pa->data;
    if (data) g_free(data);
}
@ @<Private function prototypes@> =
static inline void p_array_destroy(struct p_array* pa);

@** Dynamic Pointer Arrays.
In this variation of dynamic arrays, only pointers are allowed
and sizes are expected to be large.
Adding to the array may cause it to move,
invalidating all addresses taken from it.
Once the array is "frozen",
addresses within it are stable
and addresses of items within it may be expected to
stay valid.
@<ADT structures@> =
struct dp_array { struct p_array pa; gint size; };
@ @<Function definitions@> =
static inline void dp_array_init(struct dp_array* dpa, gint size) {
dpa->pa.len = 0; dpa->size = size; dpa->pa.data = g_new(void *, size); }
@ @<Private function prototypes@> =
static inline void dp_array_init(struct dp_array* dpa, gint size);
@ @<Function definitions@> =
static inline void dp_array_destroy(struct dp_array* dpa) {
    p_array_destroy(&(dpa->pa));
}
@ @<Private function prototypes@> =
static inline void dp_array_destroy(struct dp_array* dpa);
@ @<Function definitions@> =
static inline void dp_array_resize(struct dp_array *dpa, gint new_size) {
   dpa->pa.data = g_renew(void*, dpa->pa.data, new_size);
   dpa->size = new_size;
}
@ @<Private function prototypes@> =
static inline void dp_array_resize(struct dp_array *dpa, gint new_size);
@ @<Function definitions@> =
static inline void dp_array_append(struct dp_array *dpa, void *p) {
     if (dpa->pa.len >= dpa->size) dp_array_resize(dpa, dpa->size*2);
     dpa->pa.data[dpa->pa.len++] = p;
}
@ @<Private function prototypes@> =
static inline void dp_array_append(struct dp_array *dpa, void *p);
@ Copies a dynamic pointer array to a pointer array, giving it a final
resizing.
@<Function definitions@> =
static inline void dp_array_freeze(struct dp_array *dpa, struct p_array* pa) {
    gint len = pa->len = dpa->pa.len;
    if (G_UNLIKELY(len >= dpa->size)) {
       pa->data = dpa->pa.data;
       return;
    }
   pa->data = g_renew(void*, dpa->pa.data, len);
}
@ @<Private function prototypes@> =
static inline void dp_array_freeze(struct dp_array *dpa, struct p_array* pa);


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

@d DSTACK_DEFINE(this) struct dstack this;
@d DSTACK_INIT(this, type, initial_size)
  ((this.ix = 0),
  (this.base = g_new(type, (this.size = (initial_size)))))
@d DSTACK_PUSH(this, type)
    ((this.ix >= this.size ? dstack_resize(&this, sizeof(type)) : 0),
     ((type *)this.base+this.ix++))
@d DSTACK_POP(this, type) (--this.ix, this.ix < 0 ? NULL : (type*)this.base+this.ix)
@d DSTACK_BASE(this, type) ((type *)this.base)
@d DSTACK_LENGTH(this) (this.ix)

@ |DSTACK|'s often have their data "stolen", by other containers.
These |STOLEN_DSTACK_DATA_FREE| macro allows the "thief" container to abstract
slightly from the knowledge of how to deallocate the data it now "owns".
@d STOLEN_DSTACK_DATA_FREE(data) g_free(data)
@d DSTACK_DESTROY(this) STOLEN_DSTACK_DATA_FREE(this.base)

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

@** Dynamic Queues.
This is simply a dynamic stack extended with a second
index.
These is no destructor at this point, because so far all uses
of this let another container "steal" the data from this one.
When one exists, it will simply call the dynamic stack destructor.
Instead I define a destructor for the "thief" container to use
when it needs to free the data.

@d DQUEUE_DEFINE(this) struct dqueue this;
@d DQUEUE_INIT(this, type, initial_size)
    ((this.current=0), DSTACK_INIT(this.s, type, initial_size))
@d DQUEUE_ADD(this, type) DSTACK_PUSH(this.s, type)
@d DQUEUE_NEXT(this, type)
    (this.current >= DSTACK_LENGTH(this.s) ? NULL : (DSTACK_BASE(this.s, type))+this.current++)
@d DQUEUE_BASE(this, type) DSTACK_BASE(this.s, type)
@d DQUEUE_END(this) DSTACK_LENGTH(this.s)
@d STOLEN_DQUEUE_DATA_FREE(data) STOLEN_DSTACK_DATA_FREE(data)

@<Private structures@> =
struct dqueue { gint current; struct dstack s; };

@** Memory Allocation.
|libmarpa| uses |g_malloc|, either directly or indirectly.
Indirect use of |g_malloc| comes via obstacks and |g_slice|,
both of which are more efficient, but limit the ability to resize
and/or control the lifetime of the memory.
It should be noted that system libraries used by |libmarpa| may
also allocate memory, using their own methods.
\par
Obstacks are particularly useful for |libmarpa|.
Much of the memory allocated in |libmarpa| is
\li In individual allocations less than 4K, often considerable less.
\li Once created, are kept for the entire life of the either the grammar or the recognizer.
\li Once created, is never resized.
For these, obstacks are perfect.
|libmarpa|'s grammar has an obstacks.
Small allocations needed for the lifetime of the grammar
are allocated on these as the grammar object is built.
All these allocations are are conveniently and quickly deallocated when
the grammar's obstack is destroyed along with its parent grammar.
@d obstack_chunk_alloc g_malloc
@d obstack_chunk_free g_free

@*0 Why the obstacks are renamed.
Regretfully, I realized I simply could not simply include the
GNU obstacks, because of three obstacles.
First, the error handling is not thread-safe.  In fact,
since it relies on a global error handler, it is not even
safe for use by multiple libraries within one thread.
The obstack "error handling" consisted of exactly one
"out of memory" message, which Marpa will never use because
it uses |g_malloc|.
Removing the error handling was far easier than leaving it
in.

Second, the unneeded features of obstacks were causing
complications.
The GNU obtacks had a complex set of |ifdef|'s intended
to allow the same code to be part of GNU libc,
or not part of it, and the portability aspect of these
was daunting.
That lone error message was dragging in
GNU's internationalization.
(|libmarpa| avoids internationalization by leaving all
messaging and naming to the higher layers.)
It was much easier to rip out these features, than to
deal with the issues, especially the portability
issues, that they raised.

Third, if I did choose to try to use GNU obstacks in its
original form, |libmarpa| would have to deal with issues
of interposing identical function names in the linking process.
I aim at portability, even to systems that I have no
direct access to.
This is, of course, a real challenge when
it comes to debugging.
It was not cheering to think of the prospect
of multiple
libraries with obstack functions being resolved by the linkers
of widely different systems.
If, for example, a function that I intended to be used was not the
one linked, the bug would usually be a silent one.

Porting to systems with no native obstack meant that I was
already in the business of maintaining my own obstacks code,
whether I liked it or not.
So I decided to create a version which eliminated the unnecessary
but problematic features,
and to deal with namespace issues by having its own names
for external functions.

Renaming the GNU code because of modifications of minor
technical complexity is a rather ugly solution.
But for the above reasons, I feel forced into it.

@** External Failure Reports.
Most of
|libmarpa|'s external functions return failure under
one or more circumstances --- for
example, they may have been called incorrectly.
Many of the external routines share failure logic in
common.
I found it convenient to gather much of this logic here.
|g| is assumed to be the value of the relevant grammar,
when one is required.

External routines will often differ in the exact value
they return on failure.
Routines returning a pointer may return a |NULL|.
Routines returning a
|Marpa_Symbol_ID| may return a |-1|.
When -1 is a legitimate value, the routine may return a |-2|.
For this reason, the logic in this section expects |failure_indication|
to be set in the scope in which it is used.

@ Routines returning pointers often use |NULL| as the failure indicator.
@<Return |NULL| on failure@> = const gpointer failure_indicator = NULL;
@ Routines returning integers often use |-1| as the failure indicator.
@<Return |-1| on failure@> = const int failure_indicator = -1;
@ Sometimes |-1| is a valid return value for an external accessor.
@<Return |-2| on failure@> = const int failure_indicator = -2;

@ @<Fail if not precomputed@> =
if (!g->is_precomputed) {
    context_clear(g);
    g->error = "grammar not precomputed";
    return failure_indicator;
}
@ @<Fail if |symbol_id| is invalid@> =
if (!symbol_is_valid(g, symbol_id)) {
    context_clear(g);
    context_int_add(g, "symbol_id", symbol_id);
    g->error = "invalid symbol id";
    return failure_indicator;
}
@ @<Fail if |rule_id| is invalid@> =
if (!rule_is_valid(g, rule_id)) {
    context_clear(g);
    context_int_add(g, "rule_id", rule_id);
    g->error = "invalid rule id";
    return failure_indicator;
}
@ @<Fail if |item_id| is invalid@> =
if (!item_is_valid(g, item_id)) {
    context_clear(g);
    context_int_add(g, "item_id", item_id);
    g->error = "invalid item id";
    return failure_indicator;
}
@ @<Fail if |AHFA_state_id| is invalid@> =
if (!AHFA_state_id_is_valid(g, AHFA_state_id)) {
    context_clear(g);
    context_int_add(g, "AHFA_state_id", AHFA_state_id);
    g->error = "invalid AHFA state id";
    return failure_indicator;
}

@** Messages and Logging.
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
@ @<Widely aligned grammar elements@> =
    Marpa_Message_Callback* message_callback;
    void *message_callback_arg;
@ @<Function definitions@> =
void marpa_message_callback_set(struct marpa_g *g, Marpa_Message_Callback*cb)
{ g->message_callback = cb; }
void marpa_message_callback_arg_set(struct marpa_g *g, void *cb_arg)
{ g->message_callback_arg = cb_arg; }
void* marpa_message_callback_arg(struct marpa_g *g)
{ return g->message_callback_arg; }
@ @<Public function prototypes@> =
void marpa_message_callback_set(struct marpa_g *g, Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g *g, void *cb_arg);
void* marpa_message_callback_arg(struct marpa_g *g);
@ Do the message callback.
@^To Do@> To Do: Deal with the possibility of leaking memory when the
callback never returns.
@<Function definitions@> =
static inline void message(struct marpa_g *g, Marpa_Message_ID id)
{ Marpa_Message_Callback* cb = g->message_callback;
if (cb) { (*cb)(g, id); } }
@ @<Private function prototypes@> =
static inline void message(struct marpa_g *g, Marpa_Message_ID id);

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

#include "config.h"
#include "marpa.h"
@h
#include "marpa_obs.h"
@<Logging domain@>@;
@<Private typedefs@>@;
@<Private global variables@>@;
@<ADT structures@>@;
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

#ifndef __MARPA_H__
#define __MARPA_H__ @/
#include <stdio.h>
#include <glib.h>
@<Body of public header file@>
#endif __MARPA_H__

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

