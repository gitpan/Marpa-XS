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

typedef struct marpa_r Recognizer;
typedef struct marpa_earley_item Earley_Item;

MODULE = Marpa::XS        PACKAGE = Marpa::XS::Internal  PREFIX = marpa_

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

MODULE = Marpa::XS        PACKAGE = Marpa::XS::Internal::R_C  PREFIX = marpa_r

Recognizer *
new( class, non_c_sv )
    char * class;
    SV *non_c_sv;
PREINIT:
    const char *recognizer_class_name = "Marpa::XS::Recognizer";
    Recognizer *recce;
    SV *sv;
PPCODE:
    # g_debug("%s", "Calling Recognizer Constructor");
    Newxz( recce, 1, Recognizer );
    marpa_r_init( recce );

    # refcount not adjusted -- I assume C struct will
    # be destroyed with its parent struct
    if (! sv_isa(non_c_sv, recognizer_class_name)) {
        g_debug("Recognizer_C->new parent arg is not in class %s",
            recognizer_class_name);
    }
    recce->SV = non_c_sv;
    sv = sv_newmortal();
    sv_setref_pv(sv, "Marpa::XS::Internal::R_C", (void*)recce);
    XPUSHs(sv);

void
DESTROY( recce )
    Recognizer *recce
CODE:
    marpa_r_destroy( recce );
    Safefree( recce );

MODULE = Marpa::XS  PACKAGE = Marpa::XS::Internal::Earley_Item_C  PREFIX = marpa_earley_item

Earley_Item *
new( class, recce, non_c_sv )
    char * class;
    Recognizer * recce;
    SV *non_c_sv;
PREINIT:
    const char *earley_item_class_name = "Marpa::XS::Internal::Earley_Item";
    Earley_Item* item;
    SV* sv;
PPCODE:
    item = marpa_earley_item_new( recce );

    # refcount not adjusted -- I assume C struct will
    # be destroyed with its parent struct
    if (! sv_isa(non_c_sv, earley_item_class_name)) {
        g_debug("Earley_Item_C->new parent arg is not in class %s",
            earley_item_class_name);
    }
    item->SV = non_c_sv;
    sv = sv_newmortal();
    sv_setref_pv(sv, "Marpa::XS::Internal::Earley_Item_C", (void*)item);
    XPUSHs(sv);

# No destructor -- memory for Earley items
# is freed with the Recognizer

BOOT:
    gperl_handle_logs_for(G_LOG_DOMAIN);
