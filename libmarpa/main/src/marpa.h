/*43:*/
#line 615 "./marpa.w"

/*41:*/
#line 582 "./marpa.w"

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

/*:41*/
#line 616 "./marpa.w"

/*3:*/
#line 69 "./marpa.w"


#include <glib.h> 
#include <obstack.h> 
#include <stdio.h> 

/*:3*//*9:*/
#line 123 "./marpa.w"


#ifndef __MARPA_H__
#define __MARPA_H__ 

#include "glib.h" 

GLIB_VAR const guint marpa_major_version;
GLIB_VAR const guint marpa_minor_version;
GLIB_VAR const guint marpa_micro_version;
GLIB_VAR const guint marpa_interface_age;
GLIB_VAR const guint marpa_binary_age;

#define MARPA_CHECK_VERSION(major,minor,micro)  \
     (MARPA_MAJOR_VERSION >  (major) \
         || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION >  (minor)) \
         || (MARPA_MAJOR_VERSION == (major) && MARPA_MINOR_VERSION == (minor) \
          && MARPA_MICRO_VERSION >= (micro)))


/*13:*/
#line 186 "./marpa.w"


#define MARPA_DEVELOPMENT_PHASE 1

/*:13*/
#line 143 "./marpa.w"

/*16:*/
#line 206 "./marpa.w"


struct marpa_r{
struct obstack stack;
#ifdef MARPA_DEVELOPMENT_PHASE
void*SV;
#endif 
};

/*:16*/
#line 144 "./marpa.w"

/*15:*/
#line 196 "./marpa.w"


struct marpa_symbol{
#ifdef MARPA_DEVELOPMENT_PHASE
void*SV;
#endif 
};

/*:15*//*21:*/
#line 289 "./marpa.w"


struct marpa_earley_item{
struct marpa_token_link*token_links;
struct marpa_cause_link*cause_links;
void*leo_links;
#ifdef MARPA_DEVELOPMENT_PHASE
void*SV;
#endif 
};

/*:21*/
#line 145 "./marpa.w"

/*8:*/
#line 111 "./marpa.w"


void marpa_version(int*version);

/*:8*//*18:*/
#line 233 "./marpa.w"


void marpa_r_init(struct marpa_r*recce);

/*:18*//*20:*/
#line 248 "./marpa.w"


void marpa_r_destroy(struct marpa_r*recce);

/*:20*//*36:*/
#line 499 "./marpa.w"

const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro);

/*:36*/
#line 146 "./marpa.w"

/*23:*/
#line 323 "./marpa.w"


struct marpa_earley_item*marpa_earley_item_new(struct marpa_r*recce);

/*:23*//*27:*/
#line 368 "./marpa.w"


void
marpa_token_link_add(
struct marpa_r*recce,
struct marpa_earley_item*item,
struct marpa_symbol*symbol,
struct marpa_earley_item*predecessor,
void*value
);

/*:27*//*30:*/
#line 412 "./marpa.w"


void
marpa_cause_link_add(
struct marpa_r*recce,
struct marpa_earley_item*item,
struct marpa_earley_item*predecessor,
struct marpa_earley_item*cause
);

/*:30*/
#line 147 "./marpa.w"


#endif

/*:9*/
#line 617 "./marpa.w"


/*:43*/
