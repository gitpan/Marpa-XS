/*
 * Copyright 2010 Jeffrey Kegler
 * This file is part of Marpa::XS.  Marpa::XS is free software: you can
 * redistribute it and/or modify it under the terms of the GNU Lesser
 * General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Marpa::XS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser
 * General Public License along with Marpa::XS.  If not, see
 * http://www.gnu.org/licenses/.
 */

#include <gperl.h>

#pragma GCC diagnostic warning "-Wall"
#pragma GCC diagnostic warning "-Wextra"
#pragma GCC diagnostic warning "-Wpointer-arith"
#pragma GCC diagnostic warning "-Wstrict-prototypes"
#pragma GCC diagnostic warning "-Wwrite-strings"
#pragma GCC diagnostic warning "-Wdeclaration-after-statement"
#pragma GCC diagnostic warning "-Wshadow"
#pragma GCC diagnostic ignored "-Wformat-security"

#include "config.h"
#include "marpa.h"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

typedef struct marpa_r Recognizer;
typedef struct marpa_earley_item Earley_Item;
typedef struct marpa_g Grammar;
typedef struct marpa_rule Rule;

/* "cookie" structures are private to the
 * XS logic
 */
typedef struct {
     Recognizer *recce;
     SV *g_sv;
} Recce_C;

static const char grammar_class_name[] = "Marpa::XS::Grammar";
static const char grammar_c_class_name[] = "Marpa::XS::Internal::G_C";
static const char symbol_class_name[] = "Marpa::XS::Internal::Symbol";
static const char rule_class_name[] = "Marpa::XS::Internal::Rule";
static const char recognizer_class_name[] = "Marpa::XS::Recognizer";
static const char recce_c_class_name[] = "Marpa::XS::Internal::R_C";
static const char earley_item_class_name[] = "Marpa::XS::Internal::Earley_Item";

static inline Grammar* grammar_sv2c (SV *g_sv)
{
    IV tmp = SvIV((SV*)SvRV(g_sv));
    return INT2PTR(Grammar *, tmp);
}

static void
xs_message_callback(Grammar *g, Marpa_Message_ID id)
{
    SV* cb = marpa_message_callback_arg(g);
    if (!cb) return;
    if (!SvOK(cb)) return;
    {
    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSViv( marpa_grammar_id(g))));
    XPUSHs(sv_2mortal(newSVpv(id, 0)));
    PUTBACK;
    call_sv(cb, G_DISCARD);
    FREETMPS;
    LEAVE;
    }
}

static void
xs_rule_callback(Grammar *g, Marpa_Rule_ID id)
{
    SV* cb = marpa_rule_callback_arg(g);
    if (!cb) return;
    if (!SvOK(cb)) return;
    {
    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSViv( marpa_grammar_id(g))));
    XPUSHs(sv_2mortal(newSViv(id)));
    PUTBACK;
    call_sv(cb, G_DISCARD);
    FREETMPS;
    LEAVE;
    }
}

static void
xs_symbol_callback(Grammar *g, Marpa_Symbol_ID id)
{
    SV* cb = marpa_symbol_callback_arg(g);
    if (!cb) return;
    if (!SvOK(cb)) return;
    {
    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSViv( marpa_grammar_id(g))));
    XPUSHs(sv_2mortal(newSViv(id)));
    PUTBACK;
    call_sv(cb, G_DISCARD);
    FREETMPS;
    LEAVE;
    }
}

static inline SV* recce_wrap( Recognizer* recce, SV* g_sv)
{
    Recce_C *recce_c;
    HV * const stash = gv_stashpv(recce_c_class_name, GV_ADD);
    SV* sv = newSV(sizeof(*recce_c));
    SV *rv = newRV_noinc(sv);
    SvPOK_only(sv);
    sv_bless(rv, stash);
    recce_c = (Recce_C*)SvPVX(sv);
    recce_c->g_sv = g_sv;
    SvREFCNT_inc(g_sv);
    recce_c->recce = recce;
    return rv;
}

MODULE = Marpa::XS        PACKAGE = Marpa::XS

PROTOTYPES: DISABLE

void
version()
PPCODE:
{
   int version[3];
   marpa_version(version);
   EXTEND(SP, 3);
   mPUSHi( version[0] );
   mPUSHi( version[1] );
   mPUSHi( version[2] );
}

MODULE = Marpa::XS        PACKAGE = Marpa::XS::Internal::G_C

Grammar *
new( class, non_c_sv )
    char * class;
PREINIT:
    Grammar *grammar;
    SV *sv;
PPCODE:
    grammar = marpa_g_new();
    marpa_message_callback_set( grammar, &xs_message_callback );
    marpa_rule_callback_set( grammar, &xs_rule_callback );
    marpa_symbol_callback_set( grammar, &xs_symbol_callback );
    sv = sv_newmortal();
    sv_setref_pv(sv, grammar_c_class_name, (void*)grammar);
    XPUSHs(sv);

void
DESTROY( grammar )
    Grammar *grammar;
CODE:
    {
       SV *sv = marpa_message_callback_arg(grammar);
	marpa_message_callback_arg_set( grammar, NULL );
       if (sv) {
       SvREFCNT_dec(sv);
       }
    }
    {
       SV *sv = marpa_rule_callback_arg(grammar);
	marpa_rule_callback_arg_set( grammar, NULL );
       if (sv) { 
        SvREFCNT_dec(sv); }
    }
    {
       SV *sv = marpa_symbol_callback_arg(grammar);
	marpa_symbol_callback_arg_set( grammar, NULL );
       if (sv) {
       SvREFCNT_dec(sv); }
    }
    marpa_g_destroy( grammar );

 # Note the Perl callback closure
 # is, in the libmarpa context, the *ARGUMENT* of the callback,
 # not the callback itself.
 # The libmarpa callback is a wrapper
 # that calls the Perl closure.
void
message_callback_set( g, sv )
    Grammar *g;
    SV *sv;
PPCODE:
    {
       SV *old_sv = marpa_message_callback_arg(g);
       if (old_sv) {
       SvREFCNT_dec(old_sv); }
    }
    marpa_message_callback_arg_set( g, sv );
    SvREFCNT_inc(sv);

void
rule_callback_set( g, sv )
    Grammar *g;
    SV *sv;
PPCODE:
    {
       SV *old_sv = marpa_rule_callback_arg(g);
       if (old_sv) {
       SvREFCNT_dec(old_sv); }
    }
    marpa_rule_callback_arg_set( g, sv );
    SvREFCNT_inc(sv);

void
symbol_callback_set( g, sv )
    Grammar *g;
    SV *sv;
PPCODE:
    {
       SV *old_sv = marpa_symbol_callback_arg(g);
       if (old_sv) {
       SvREFCNT_dec(old_sv); }
    }
    marpa_symbol_callback_arg_set( g, sv );
    SvREFCNT_inc(sv);

Marpa_Grammar_ID
id( g )
    Grammar *g;
CODE:
    RETVAL = marpa_grammar_id(g);
OUTPUT:
    RETVAL

void
start_symbol_set( g, id )
    Grammar *g;
    Marpa_Symbol_ID id;
PPCODE:
    { gboolean result = marpa_start_symbol_set(g, id);
    if (result) XSRETURN_YES;
    }
    XSRETURN_NO;

void
start_symbol( g )
    Grammar *g;
PPCODE:
    { Marpa_Symbol_ID id = marpa_start_symbol( g );
    if (id < 0) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(id) ) );
    }

void
is_precomputed( g )
    Grammar *g;
PPCODE:
    { gint boolean = marpa_is_precomputed( g );
    if (boolean) XSRETURN_YES;
    XSRETURN_NO;
    }

void
has_loop( g )
    Grammar *g;
PPCODE:
    { gint boolean = marpa_has_loop( g );
    if (boolean) XSRETURN_YES;
    XSRETURN_NO;
    }

void
is_lhs_terminal_ok_set( g, boolean )
    Grammar *g;
    int boolean;
PPCODE:
    { gboolean result = marpa_is_lhs_terminal_ok_set(
	g, (boolean ? TRUE : FALSE));
    if (result) XSRETURN_YES;
    }
    XSRETURN_NO;

void
is_lhs_terminal_ok( g )
    Grammar *g;
PPCODE:
    { gboolean boolean = marpa_is_lhs_terminal_ok( g );
    if (boolean) XSRETURN_YES;
    XSRETURN_NO;
    }

Marpa_Symbol_ID
symbol_new( g )
    Grammar *g;
CODE:
    RETVAL = marpa_symbol_new(g);
OUTPUT:
    RETVAL

Marpa_Symbol_ID
symbol_alias( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
CODE:
    RETVAL = marpa_symbol_alias_create(g, symbol_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

void
symbol_lhs_rule_ids( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { GArray *rule_id_array = marpa_symbol_lhs_peek( g, symbol_id );
    guint len = rule_id_array->len;
    Marpa_Rule_ID* rule_ids = (Marpa_Rule_ID*)rule_id_array->data;
    if (GIMME == G_ARRAY) {
        int i;
        EXTEND(SP, len);
        for (i = 0; i < len; i++) {
            PUSHs( sv_2mortal( newSViv(rule_ids[i]) ) );
        }
    } else {
        XPUSHs( sv_2mortal( newSViv(len) ) );
    }
    }

 # In scalar context, returns the RHS length
void
symbol_rhs_rule_ids( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { GArray *rule_id_array = marpa_symbol_rhs_peek( g, symbol_id );
    guint len = rule_id_array->len;
    Marpa_Rule_ID* rule_ids = (Marpa_Rule_ID*)rule_id_array->data;
    if (GIMME == G_ARRAY) {
        int i;
        EXTEND(SP, len);
        for (i = 0; i < len; i++) {
            PUSHs( sv_2mortal( newSViv(rule_ids[i]) ) );
        }
    } else {
        XPUSHs( sv_2mortal( newSViv(len) ) );
    }
    }

void
symbol_is_accessible_set( g, symbol_id, boolean )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
    marpa_symbol_is_accessible_set( g, symbol_id, (boolean ? TRUE : FALSE));

void
symbol_is_accessible( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gboolean boolean = marpa_symbol_is_accessible( g, symbol_id );
    if (boolean) XSRETURN_YES;
    XSRETURN_NO;
    }

void
symbol_is_counted( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gboolean boolean = marpa_symbol_is_counted( g, symbol_id );
    if (boolean) XSRETURN_YES;
    XSRETURN_NO;
    }

void
symbol_is_nullable_set( g, symbol_id, boolean )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
    marpa_symbol_is_nullable_set( g, symbol_id, (boolean ? TRUE : FALSE));

void
symbol_is_nullable( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gboolean boolean = marpa_symbol_is_nullable( g, symbol_id );
    if (boolean) XSRETURN_YES;
    XSRETURN_NO;
    }

void
symbol_is_nulling_set( g, symbol_id, boolean )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
    marpa_symbol_is_nulling_set( g, symbol_id, (boolean ? TRUE : FALSE));

void
symbol_is_nulling( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gint result = marpa_symbol_is_nulling( g, symbol_id );
    if (result == -1) { croak("Invalid symbol %d", symbol_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
symbol_is_terminal_set( g, symbol_id, boolean )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
    marpa_symbol_is_terminal_set( g, symbol_id, (boolean ? TRUE : FALSE));

void
symbol_is_terminal( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gint result = marpa_symbol_is_terminal( g, symbol_id );
    if (result == -1) { croak("Invalid symbol %d", symbol_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
symbol_is_productive_set( g, symbol_id, boolean )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
    marpa_symbol_is_productive_set( g, symbol_id, (boolean ? TRUE : FALSE));

void
symbol_is_productive( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gint result = marpa_symbol_is_productive( g, symbol_id );
    if (result == -1) { croak("Invalid symbol %d", symbol_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
symbol_is_start( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gint result = marpa_symbol_is_start( g, symbol_id );
    if (result == -1) { croak("Invalid symbol %d", symbol_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

Marpa_Symbol_ID
symbol_null_alias( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
CODE:
    RETVAL = marpa_symbol_null_alias(g, symbol_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

Marpa_Symbol_ID
symbol_proper_alias( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
CODE:
    RETVAL = marpa_symbol_proper_alias(g, symbol_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

 # Rules

Marpa_Rule_ID
rule_new( g, lhs, rhs_av )
    Grammar *g;
    Marpa_Symbol_ID lhs;
    AV *rhs_av;
PREINIT:
    int length;
    Marpa_Symbol_ID* rhs;
    Marpa_Rule_ID new_rule_id;
PPCODE:
    length = av_len(rhs_av)+1;
    if (length <= 0) {
        rhs = (Marpa_Symbol_ID*)NULL;
    } else {
	int i;
        Newx(rhs, length, Marpa_Symbol_ID);
	for (i = 0; i < length; i++) {
	    SV** elem = av_fetch(rhs_av, i, 0);
	    if (elem == NULL) {
		Safefree(rhs);
	        XSRETURN_UNDEF;
	    } else {
	        rhs[i] = SvIV(*elem);
	    }
	}
    }
    new_rule_id = marpa_rule_new(g, lhs, rhs, length);
    Safefree(rhs);
    if (new_rule_id < 0) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(new_rule_id) ) );

 # This function invalidates any current iteration on
 # the hash args.  This seesm to be the way things are
 # done in Perl -- in particular there seems to be no
 # easy way to  prevent that.
Marpa_Rule_ID
sequence_new( g, lhs, rhs, args )
    Grammar *g;
    Marpa_Symbol_ID lhs;
    Marpa_Symbol_ID rhs;
    HV *args;
PREINIT:
    Marpa_Rule_ID new_rule_id;
    Marpa_Symbol_ID separator = -1;
    guint min = 1;
    gint flags = 0;
PPCODE:
    if (args) {
	I32 retlen;
	char* key;
	SV* arg_value;
	hv_iterinit(args);
	while (arg_value = hv_iternextsv(args, &key, &retlen) ) {
	    if ((*key == 'k') && strnEQ(key, "keep", retlen)) {
		if (SvTRUE(arg_value)) flags |= MARPA_KEEP_SEPARATION;
		continue;
	    }
	    if ((*key == 'm') && strnEQ(key, "min", retlen)) {
		gint raw_min = SvIV(arg_value);
		if (raw_min < 0) {
		    croak("sequence_new(): min cannot be less than 0");
		}
		min = raw_min;
		continue;
	    }
	    if ((*key == 'p') && strnEQ(key, "proper", retlen)) {
		if (SvTRUE(arg_value)) flags |= MARPA_PROPER_SEPARATION;
		continue;
	    }
	    if ((*key == 's') && strnEQ(key, "separator", retlen)) {
		separator = SvIV(arg_value);
		continue;
	    }
	    croak("unknown argument to sequence_new(): %.*s", retlen, key);
	}
    }
    new_rule_id = marpa_sequence_new(g, lhs, rhs, separator, min, flags );
    if (new_rule_id < 0) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(new_rule_id) ) );

Marpa_Symbol_ID
rule_lhs( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_rule_lhs(g, rule_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

void
rule_rhs( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PREINIT:
    int i;
    gsize length;
    Marpa_Symbol_ID* rhs;
PPCODE:
    length = marpa_rule_length(g, rule_id);
    if (length < 0) {
       XSRETURN_UNDEF;
    }
    if (length == 0) {
       XSRETURN_EMPTY;
    }
    rhs = marpa_rule_rhs_peek( g, rule_id );
    if (rhs == NULL) {
       XSRETURN_UNDEF;
    }
    EXTEND(SP, length);
    for (i = 0; i < length; i++) {
	PUSHs( sv_2mortal( newSViv(rhs[i]) ) );
    }

int
rule_length( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_rule_length(g, rule_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

void
rule_is_accessible( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gint result = marpa_rule_is_accessible( g, rule_id );
    if (result == -1) { croak("Invalid rule %d", rule_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
rule_is_productive( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gint result = marpa_rule_is_productive( g, rule_id );
    if (result == -1) { croak("Invalid rule %d", rule_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
rule_is_loop( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gint result = marpa_rule_is_loop( g, rule_id );
    if (result == -1) { croak("Invalid rule %d", rule_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
rule_is_virtual_loop( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gint result = marpa_rule_is_virtual_loop( g, rule_id );
    if (result == -1) { croak("Invalid rule %d", rule_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
rule_is_used( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gint result = marpa_rule_is_used( g, rule_id );
    if (result == -1) { croak("Invalid rule %d", rule_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
rule_is_proper_separation( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gint result = marpa_rule_is_proper_separation( g, rule_id );
    if (result == -1) { croak("Invalid rule %d", rule_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
rule_is_discard_separation( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gint result = marpa_rule_is_discard_separation( g, rule_id );
    if (result == -1) { croak("Invalid rule %d", rule_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
rule_is_virtual_lhs( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gint result = marpa_rule_is_virtual_lhs( g, rule_id );
    if (result == -1) { croak("Invalid rule %d", rule_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
rule_is_virtual_rhs( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gint result = marpa_rule_is_virtual_rhs( g, rule_id );
    if (result == -1) { croak("Invalid rule %d", rule_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

Marpa_Rule_ID
real_symbol_count( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_real_symbol_count(g, rule_id);
OUTPUT:
    RETVAL

Marpa_Rule_ID
rule_original( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_rule_original(g, rule_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

Marpa_Rule_ID
semantic_equivalent( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_rule_semantic_equivalent(g, rule_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

int
AHFA_item_count( g )
    Grammar *g;
CODE:
    RETVAL = marpa_AHFA_item_count(g );
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

Marpa_Rule_ID
AHFA_item_rule( g, item_id )
    Grammar *g;
    Marpa_AHFA_Item_ID item_id;
CODE:
    RETVAL = marpa_AHFA_item_rule(g, item_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

 # -1 is a valid return value, so -2 indicates an error
int
AHFA_item_position( g, item_id )
    Grammar *g;
    Marpa_AHFA_Item_ID item_id;
CODE:
    RETVAL = marpa_AHFA_item_position(g, item_id);
    if (RETVAL <= -2) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

int
AHFA_item_sort_key( g, item_id )
    Grammar *g;
    Marpa_AHFA_Item_ID item_id;
CODE:
    RETVAL = marpa_AHFA_item_sort_key(g, item_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

 # -1 is a valid return value, and -2 indicates an error
Marpa_Symbol_ID
AHFA_item_postdot( g, item_id )
    Grammar *g;
    Marpa_AHFA_Item_ID item_id;
CODE:
    RETVAL = marpa_AHFA_item_postdot(g, item_id);
    if (RETVAL <= -2) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

int
AHFA_state_count( g )
    Grammar *g;
CODE:
    RETVAL = marpa_AHFA_state_count(g );
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

 # In scalar context, returns the count
void
AHFA_state_items( g, AHFA_state_id )
    Grammar *g;
    Marpa_AHFA_State_ID AHFA_state_id;
PPCODE:
    { gint count = marpa_AHFA_state_item_count(g, AHFA_state_id);
    if (count < 0) { croak("Invalid AHFA state %d", AHFA_state_id); }
    if (GIMME == G_ARRAY) {
        guint item_ix;
        EXTEND(SP, count);
        for (item_ix = 0; item_ix < count; item_ix++) {
	    Marpa_AHFA_Item_ID item_id
		= marpa_AHFA_state_item(g, AHFA_state_id, item_ix);
            PUSHs( sv_2mortal( newSViv(item_id) ) );
        }
    } else {
        XPUSHs( sv_2mortal( newSViv(count) ) );
    }
    }

void
AHFA_state_is_predict( g, AHFA_state_id )
    Grammar *g;
    Marpa_AHFA_State_ID AHFA_state_id;
PPCODE:
    { gint result = marpa_AHFA_state_is_predict( g, AHFA_state_id );
    if (result == -1) { croak("Invalid AHFA state %d", AHFA_state_id); }
    if (result) XSRETURN_YES;
    XSRETURN_NO;
    }

void
context( g, key )
    Grammar *g;
    char *key;
PREINIT:
    union marpa_context_value* value;
    const char *string;
PPCODE:
    value = marpa_context_value_look(g, key);
    if (!value) {
	XSRETURN_UNDEF;
    }
    string = MARPA_CONTEXT_STRING_VALUE(value);
    if (string) {
	XPUSHs( sv_2mortal( newSVpv( string, 0 ) ) );
	goto finished;
    }
    if (MARPA_IS_CONTEXT_INT(value)) {
	gint payload = MARPA_CONTEXT_INT_VALUE(value);
	XPUSHs( sv_2mortal( newSViv( payload ) ) );
    } else { XSRETURN_UNDEF; }
    finished: ;

char *error( g )
    Grammar *g;
CODE:
    RETVAL = (gchar*)marpa_error(g);
OUTPUT:
    RETVAL

void precompute( g )
    Grammar *g;
PPCODE:
    if  (marpa_precompute(g)) { XSRETURN_YES; }
    XSRETURN_NO;

MODULE = Marpa::XS        PACKAGE = Marpa::XS::Internal::R_C

Recce_C *
new( class, g_sv )
    char * class;
    SV *g_sv;
PREINIT:
    Recognizer *recce;
    SV *rv;
PPCODE:
    Newxz( recce, 1, Recognizer );
    marpa_r_init( recce );
    if (! sv_isa(g_sv, grammar_c_class_name)) {
        g_debug("Recognizer_C->new grammar arg is not in class %s",
            grammar_c_class_name);
    }
    rv = recce_wrap(recce, g_sv);
    sv_2mortal(rv);
    XPUSHs(rv);

void
DESTROY( recce_c )
    Recce_C *recce_c;
PREINIT:
    SV *g_sv;
    Recognizer *recce;
CODE:
    g_sv = recce_c->g_sv;
    recce = recce_c->recce;
    marpa_r_destroy( recce );
    SvREFCNT_dec(g_sv);
    Safefree( recce );

MODULE = Marpa::XS  PACKAGE = Marpa::XS::Internal::Earley_Item_C

# Constructor

Earley_Item *
new( class, recce_c )
    char * class;
    Recce_C * recce_c;
PREINIT:
    Earley_Item* item;
    SV* sv;
PPCODE:
    {
    item = marpa_earley_item_new( );
    sv = sv_newmortal();
    sv_setref_pv(sv, "Marpa::XS::Internal::Earley_Item_C", (void*)item);
    XPUSHs(sv);
    }

void
DESTROY( item )
    Earley_Item *item;
CODE:
    marpa_earley_item_free( item );

BOOT:
    gperl_handle_logs_for(G_LOG_DOMAIN);
