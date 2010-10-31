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

MODULE = Marpa::XS        PACKAGE = Marpa::XS::Internal PREFIX=marpa_

PROTOTYPES: DISABLE

const char *
marpa_check_version (required_major, required_minor, required_micro)
    unsigned int required_major
    unsigned int required_minor
    unsigned int required_micro

void
marpa_version()
PPCODE:
{
   int version[3];
   marpa_version(version);
   EXTEND(SP, 3);
   mPUSHi( version[0] );
   mPUSHi( version[1] );
   mPUSHi( version[2] );
}

void
marpa_error(string)
     char * string
CODE:
     g_error("%s", string);

void
marpa_warning(string)
     char * string
CODE:
     g_warning("%s", string);

void
marpa_debug(string)
     char * string
CODE:
     g_debug("%s", string);

MODULE = Marpa::XS        PACKAGE = Marpa::XS::Internal::G_C

Grammar *
new( class, non_c_sv )
    char * class;
PREINIT:
    Grammar *grammar;
    SV *sv;
PPCODE:
    Newxz( grammar, 1, Grammar );
    marpa_g_init( grammar );
    sv = sv_newmortal();
    sv_setref_pv(sv, grammar_c_class_name, (void*)grammar);
    XPUSHs(sv);

void
DESTROY( grammar )
    Grammar *grammar;
CODE:
    marpa_g_destroy( grammar );
    Safefree( grammar );

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
symbol_lhs_add( g, symbol_id, rule_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
    Marpa_Rule_ID rule_id;
PPCODE:
    marpa_symbol_lhs_add( g, symbol_id, rule_id );

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

void
symbol_rhs_add( g, symbol_id, rule_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
    Marpa_Rule_ID rule_id;
PPCODE:
    marpa_symbol_rhs_add( g, symbol_id, rule_id );

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
    { gboolean boolean = marpa_symbol_is_accessible_value( g, symbol_id );
    XPUSHs( sv_2mortal( newSViv(boolean) ) );
    }

void
symbol_is_counted_set( g, symbol_id, boolean )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
    marpa_symbol_is_counted_set( g, symbol_id, (boolean ? TRUE : FALSE));

void
symbol_is_counted( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gboolean boolean = marpa_symbol_is_counted_value( g, symbol_id );
    XPUSHs( sv_2mortal( newSViv(boolean) ) );
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
    { gboolean boolean = marpa_symbol_is_nullable_value( g, symbol_id );
    XPUSHs( sv_2mortal( newSViv(boolean) ) );
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
    { gboolean boolean = marpa_symbol_is_nulling_value( g, symbol_id );
    XPUSHs( sv_2mortal( newSViv(boolean) ) );
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
    { gboolean boolean = marpa_symbol_is_terminal_value( g, symbol_id );
    XPUSHs( sv_2mortal( newSViv(boolean) ) );
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
    { gboolean boolean = marpa_symbol_is_productive_value( g, symbol_id );
    XPUSHs( sv_2mortal( newSViv(boolean) ) );
    }

void
symbol_is_start_set( g, symbol_id, boolean )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
    int boolean;
PPCODE:
    marpa_symbol_is_start_set( g, symbol_id, (boolean ? TRUE : FALSE));

void
symbol_is_start( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
PPCODE:
    { gboolean boolean = marpa_symbol_is_start_value( g, symbol_id );
    XPUSHs( sv_2mortal( newSViv(boolean) ) );
    }

Marpa_Symbol_ID
symbol_null_alias( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
CODE:
    RETVAL = marpa_symbol_null_alias_value(g, symbol_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

Marpa_Symbol_ID
symbol_proper_alias( g, symbol_id )
    Grammar *g;
    Marpa_Symbol_ID symbol_id;
CODE:
    RETVAL = marpa_symbol_proper_alias_value(g, symbol_id);
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

Marpa_Symbol_ID
rule_lhs( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
CODE:
    RETVAL = marpa_rule_lhs_value(g, rule_id);
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
    length = marpa_rule_length_value(g, rule_id);
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
    RETVAL = marpa_rule_length_value(g, rule_id);
    if (RETVAL < 0) { XSRETURN_UNDEF; }
OUTPUT:
    RETVAL

void
rule_is_accessible_set( g, rule_id, boolean )
    Grammar *g;
    Marpa_Rule_ID rule_id;
    int boolean;
PPCODE:
    marpa_rule_is_accessible_set( g, rule_id, (boolean ? TRUE : FALSE));

void
rule_is_accessible( g, rule_id )
    Grammar *g;
    Marpa_Rule_ID rule_id;
PPCODE:
    { gboolean boolean = marpa_rule_is_accessible_value( g, rule_id );
    XPUSHs( sv_2mortal( newSViv(boolean) ) );
    }

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
