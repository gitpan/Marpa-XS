/*204:*/
#line 1571 "./marpa.w"

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
#line 385 "./marpa.w"

#include <glib.h> 
#include <stdio.h> 
/*:17*//*22:*/
#line 409 "./marpa.w"

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
#line 139 "./marpa.w"

#define MARPA_SHIM 

/*:8*/
#line 424 "./marpa.w"

#define MARPA_CAT(a, b)  a ## b 
/*206:*/
#line 1634 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:206*/
#line 426 "./marpa.w"

struct marpa_g;
/*31:*/
#line 477 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:31*//*59:*/
#line 600 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:59*//*154:*/
#line 1053 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:154*/
#line 428 "./marpa.w"

/*141:*/
#line 998 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:141*//*148:*/
#line 1028 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:148*/
#line 429 "./marpa.w"

/*24:*/
#line 445 "./marpa.w"
struct marpa_g{
/*36:*/
#line 490 "./marpa.w"
GArray*symbols;
/*:36*//*46:*/
#line 538 "./marpa.w"
GArray*rules;
/*:46*//*142:*/
#line 1000 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
void*symbol_callback_arg;
/*:142*//*149:*/
#line 1030 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
void*rule_callback_arg;
/*:149*/
#line 446 "./marpa.w"

/*30:*/
#line 476 "./marpa.w"
int id;
/*:30*/
#line 447 "./marpa.w"

};

/*:24*//*54:*/
#line 575 "./marpa.w"

struct marpa_r{
int dummy;
};

/*:54*//*182:*/
#line 1321 "./marpa.w"

struct marpa_earley_item{
int dummy;
};
/*:182*/
#line 430 "./marpa.w"

/*21:*/
#line 402 "./marpa.w"

void marpa_version(int*version);

/*:21*//*26:*/
#line 457 "./marpa.w"

void marpa_g_init(struct marpa_g*g);

/*:26*//*28:*/
#line 463 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g);

/*:28*//*35:*/
#line 483 "./marpa.w"

gint marpa_grammar_id_value(struct marpa_g*g);

/*:35*//*40:*/
#line 501 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:40*//*50:*/
#line 549 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:50*//*56:*/
#line 592 "./marpa.w"

void marpa_r_init(struct marpa_r*recce);
/*:56*//*58:*/
#line 596 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce);

/*:58*//*63:*/
#line 626 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:63*//*73:*/
#line 662 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID id);
/*:73*//*76:*/
#line 671 "./marpa.w"

void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:76*//*81:*/
#line 694 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID id);
/*:81*//*84:*/
#line 703 "./marpa.w"

void marpa_symbol_rhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:84*//*88:*/
#line 721 "./marpa.w"

gboolean marpa_symbol_is_accessible_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:88*//*90:*/
#line 728 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:90*//*94:*/
#line 747 "./marpa.w"

gboolean marpa_symbol_is_counted_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:94*//*96:*/
#line 754 "./marpa.w"


void marpa_symbol_is_counted_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:96*//*100:*/
#line 773 "./marpa.w"

gboolean marpa_symbol_is_nullable_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:100*//*102:*/
#line 780 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:102*//*106:*/
#line 798 "./marpa.w"

gboolean marpa_symbol_is_nulling_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:106*//*108:*/
#line 805 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:108*//*112:*/
#line 823 "./marpa.w"

gboolean marpa_symbol_is_terminal_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:112*//*114:*/
#line 830 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:114*//*118:*/
#line 849 "./marpa.w"

gboolean marpa_symbol_is_productive_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:118*//*120:*/
#line 856 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:120*//*125:*/
#line 879 "./marpa.w"

gboolean marpa_symbol_is_start_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:125*//*127:*/
#line 885 "./marpa.w"

void marpa_symbol_is_start_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:127*//*133:*/
#line 925 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:133*//*136:*/
#line 947 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:136*//*139:*/
#line 988 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:139*//*144:*/
#line 1010 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_symbol_callback_arg_peek(struct marpa_g*g);
/*:144*//*151:*/
#line 1040 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_rule_callback_arg_peek(struct marpa_g*g);
/*:151*//*158:*/
#line 1099 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
void marpa_rule_complete(struct marpa_g*g,Marpa_Rule_ID id);

/*:158*//*173:*/
#line 1260 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g*g,Marpa_Rule_ID rule_id);
Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id);
gsize marpa_rule_length_value(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:173*//*179:*/
#line 1284 "./marpa.w"

gboolean marpa_rule_is_accessible_value(struct marpa_g*g,Marpa_Rule_ID id);
/*:179*//*181:*/
#line 1291 "./marpa.w"


void marpa_rule_is_accessible_set(struct marpa_g*g,Marpa_Rule_ID id,gboolean value);


/*:181*//*184:*/
#line 1331 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void);
/*:184*//*186:*/
#line 1337 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item);
/*:186*//*192:*/
#line 1385 "./marpa.w"

const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro);

/*:192*/
#line 431 "./marpa.w"

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE
/*205:*/
#line 1598 "./marpa.w"


/*:205*/
#line 433 "./marpa.w"

#endif
#endif

/*:22*/
#line 1594 "./marpa.w"


/*:204*/
