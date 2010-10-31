/*171:*/
#line 1364 "./marpa.w"

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
/*
 * DO NOT EDIT DIRECTLY
 * This file is written by ctangle
 * It is not intended to be modified directly
 */

/*17:*/
#line 382 "./marpa.w"


#include <glib.h> 
#include <stdio.h> 

/*:17*//*23:*/
#line 431 "./marpa.w"


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


/*8:*/
#line 136 "./marpa.w"

#define MARPA_SHIM 

/*:8*/
#line 451 "./marpa.w"


#define MARPA_CAT(a, b)  a ## b 

/*173:*/
#line 1428 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:173*/
#line 455 "./marpa.w"


/*53:*/
#line 613 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:53*//*126:*/
#line 965 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:126*/
#line 457 "./marpa.w"

/*25:*/
#line 478 "./marpa.w"


struct marpa_g{
/*30:*/
#line 503 "./marpa.w"
GArray*symbols;
/*:30*//*40:*/
#line 551 "./marpa.w"
GArray*rules;
/*:40*/
#line 481 "./marpa.w"

};

/*:25*//*48:*/
#line 588 "./marpa.w"

struct marpa_r{
int dummy;
};

/*:48*//*149:*/
#line 1114 "./marpa.w"

struct marpa_earley_item{
int dummy;
};
/*:149*/
#line 458 "./marpa.w"

/*22:*/
#line 419 "./marpa.w"


void marpa_version(int*version);

/*:22*//*27:*/
#line 491 "./marpa.w"

void marpa_g_init(struct marpa_g*g);

/*:27*//*29:*/
#line 497 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g);

/*:29*//*34:*/
#line 514 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:34*//*44:*/
#line 562 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:44*//*50:*/
#line 605 "./marpa.w"

void marpa_r_init(struct marpa_r*recce);
/*:50*//*52:*/
#line 609 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce);

/*:52*//*57:*/
#line 639 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:57*//*67:*/
#line 675 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID id);
/*:67*//*70:*/
#line 684 "./marpa.w"

void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:70*//*75:*/
#line 707 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID id);
/*:75*//*78:*/
#line 716 "./marpa.w"

void marpa_symbol_rhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:78*//*82:*/
#line 734 "./marpa.w"

gboolean marpa_symbol_is_accessible_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:82*//*84:*/
#line 741 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:84*//*88:*/
#line 760 "./marpa.w"

gboolean marpa_symbol_is_nullable_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:88*//*90:*/
#line 767 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:90*//*94:*/
#line 785 "./marpa.w"

gboolean marpa_symbol_is_nulling_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:94*//*96:*/
#line 792 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:96*//*100:*/
#line 810 "./marpa.w"

gboolean marpa_symbol_is_terminal_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:100*//*102:*/
#line 817 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:102*//*106:*/
#line 836 "./marpa.w"

gboolean marpa_symbol_is_productive_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:106*//*108:*/
#line 843 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:108*//*113:*/
#line 866 "./marpa.w"

gboolean marpa_symbol_is_start_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:113*//*115:*/
#line 872 "./marpa.w"

void marpa_symbol_is_start_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:115*//*120:*/
#line 901 "./marpa.w"

struct marpa_symbol*marpa_symbol_proper_alias_value(struct marpa_symbol*symbol);
/*:120*//*123:*/
#line 922 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:123*//*125:*/
#line 957 "./marpa.w"


struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:125*//*130:*/
#line 1003 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);

/*:130*//*140:*/
#line 1053 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g*g,Marpa_Rule_ID rule_id);
Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id);
gsize marpa_rule_length_value(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:140*//*146:*/
#line 1077 "./marpa.w"

gboolean marpa_rule_is_accessible_value(struct marpa_g*g,Marpa_Rule_ID id);
/*:146*//*148:*/
#line 1084 "./marpa.w"


void marpa_rule_is_accessible_set(struct marpa_g*g,Marpa_Rule_ID id,gboolean value);


/*:148*//*151:*/
#line 1124 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void);
/*:151*//*153:*/
#line 1130 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item);
/*:153*//*159:*/
#line 1178 "./marpa.w"

const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro);

/*:159*/
#line 459 "./marpa.w"


#if MARPA_CAN_INLINE || defined MARPA_STANDALONE

/*172:*/
#line 1392 "./marpa.w"


/*:172*/
#line 463 "./marpa.w"


#endif

#endif

/*:23*//*174:*/
#line 1441 "./marpa.w"


/*:174*/
#line 1387 "./marpa.w"


/*:171*/
