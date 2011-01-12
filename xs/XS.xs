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

#include "config.h"
#include "marpa.h"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

typedef struct marpa_g Grammar;
typedef struct {
     struct marpa_r *r;
     SV *g_sv;
} Recce;

static const char grammar_c_class_name[] = "Marpa::XS::Internal::G_C";
static const char recce_c_class_name[] = "Marpa::XS::Internal::R_C";

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
    marpa_g_free( grammar );

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

Marpa_Symbol_ID
rule_rhs( g, rule_id, ix )
    Grammar *g;
    Marpa_Rule_ID rule_id;
    unsigned int ix;
CODE:
    RETVAL = marpa_rule_rh_symbol(g, rule_id, ix);
    if (RETVAL < -1) { croak("Invalid call rule_rhs(%d, %u)", rule_id, ix); }
    if (RETVAL == -1) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

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

int
rule_virtual_start( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_virtual_start( g, rule_id );
    if (RETVAL == -2) { croak("Invalid rule %d", rule_id); }
OUTPUT:
    RETVAL

int
rule_virtual_end( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_virtual_end( g, rule_id );
    if (RETVAL == -2) { croak("Invalid rule %d", rule_id); }
OUTPUT:
    RETVAL

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

 # In scalar context, returns the count
void
AHFA_state_transitions( g, AHFA_state_id )
    Grammar *g;
    Marpa_AHFA_State_ID AHFA_state_id;
PPCODE:
    { gint count = marpa_AHFA_state_transition_count(g, AHFA_state_id);
    if (count < 0) { croak("Invalid AHFA state %d", AHFA_state_id); }
    if (GIMME == G_ARRAY) {
        guint transition_ix;
	struct marpa_AHFA_transition* transitions;
        EXTEND(SP, count*2);
	Newx( transitions, count, struct marpa_AHFA_transition );
	marpa_AHFA_state_transitions(g, AHFA_state_id, transitions);
        for (transition_ix = 0; transition_ix < count; transition_ix++) {
            PUSHs( sv_2mortal( newSViv(transitions[transition_ix].symbol) ) );
            PUSHs( sv_2mortal( newSViv(transitions[transition_ix].to) ) );
        }
	Safefree( transitions );
    } else {
        XPUSHs( sv_2mortal( newSViv(count) ) );
    }
    }

 # -1 is a valid return value, and -2 indicates an error
Marpa_AHFA_State_ID
AHFA_state_empty_transition( g, AHFA_state_id )
    Grammar *g;
    Marpa_AHFA_State_ID AHFA_state_id;
CODE:
    RETVAL = marpa_AHFA_state_empty_transition(g, AHFA_state_id);
    if (RETVAL <= -2) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

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
AHFA_state_is_leo_completion( g, AHFA_state_id )
    Grammar *g;
    Marpa_AHFA_State_ID AHFA_state_id;
PPCODE:
    { gint result = marpa_AHFA_state_is_leo_completion( g, AHFA_state_id );
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
    value = marpa_g_context_value(g, key);
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
    RETVAL = (gchar*)marpa_g_error(g);
OUTPUT:
    RETVAL

void precompute( g )
    Grammar *g;
PPCODE:
    if  (marpa_precompute(g)) { XSRETURN_YES; }
    XSRETURN_NO;

MODULE = Marpa::XS        PACKAGE = Marpa::XS::Internal::R_C

void
new( class, g_sv )
    char * class;
    SV *g_sv;
PREINIT:
    Grammar *g;
    IV tmp;
    SV *sv;
    Recce *wrapper;
    struct marpa_r* r;
PPCODE:
    if (! sv_isa(g_sv, grammar_c_class_name)) {
        g_debug("Marpa::Recognizer::new grammar arg is not in class %s",
            grammar_c_class_name);
    }
    tmp = SvIV((SV*)SvRV(g_sv));
    g = INT2PTR(Grammar *, tmp);
    r = marpa_r_new(g);
    if (!r) { XSRETURN_UNDEF; }
    Newx( wrapper, 1, Recce );
    wrapper->r = r;
    wrapper->g_sv = g_sv;
    SvREFCNT_inc(g_sv);
    sv = sv_newmortal();
    sv_setref_pv(sv, recce_c_class_name, (void*)wrapper);
    XPUSHs(sv);

void
DESTROY( wrapper )
    Recce *wrapper;
PREINIT:
    SV *g_sv;
    struct marpa_r *r;
CODE:
    g_sv = wrapper->g_sv;
    r = wrapper->r;
    marpa_r_free( r );
    SvREFCNT_dec(g_sv);
    Safefree( wrapper );

void
too_many_earley_items_set( wrapper, too_many_earley_items )
    Recce *wrapper;
    unsigned int too_many_earley_items;
PPCODE:
    { gboolean result = marpa_too_many_earley_items_set(wrapper->r, too_many_earley_items);
    if (result) XSRETURN_YES;
    }
    XSRETURN_NO;

void
too_many_earley_items( wrapper )
    Recce *wrapper;
PPCODE:
    { guint too_many_earley_items = marpa_too_many_earley_items( wrapper->r );
    XPUSHs( sv_2mortal( newSViv(too_many_earley_items) ) );
    }

BOOT:
    gperl_handle_logs_for(G_LOG_DOMAIN);
