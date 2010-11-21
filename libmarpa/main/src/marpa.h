/*379:*/
#line 2853 "./marpa.w"

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

/*15:*/
#line 392 "./marpa.w"

#include <glib.h> 
#include <stdio.h> 
/*:15*//*20:*/
#line 416 "./marpa.w"

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

#define MARPA_CAT(a, b)  a ## b 
/*381:*/
#line 2916 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:381*/
#line 432 "./marpa.w"

/*67:*/
#line 643 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:67*//*234:*/
#line 1662 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:234*//*239:*/
#line 1695 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:239*/
#line 433 "./marpa.w"

struct marpa_g;
/*29:*/
#line 486 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:29*//*79:*/
#line 730 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:79*//*90:*/
#line 774 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:90*//*176:*/
#line 1189 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:176*//*358:*/
#line 2607 "./marpa.w"

typedef const gchar*Marpa_Message_ID;
/*:358*/
#line 435 "./marpa.w"

/*170:*/
#line 1164 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:170*//*259:*/
#line 1778 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:259*//*359:*/
#line 2612 "./marpa.w"

typedef void(Marpa_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:359*/
#line 436 "./marpa.w"

/*22:*/
#line 452 "./marpa.w"
struct marpa_g{
/*34:*/
#line 498 "./marpa.w"
GArray*symbols;
/*:34*//*46:*/
#line 554 "./marpa.w"
GArray*rules;
/*:46*//*64:*/
#line 638 "./marpa.w"
GHashTable*context;
/*:64*//*80:*/
#line 732 "./marpa.w"
Marpa_Error_ID error;
/*:80*//*171:*/
#line 1166 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
void*symbol_callback_arg;
/*:171*//*260:*/
#line 1780 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
void*rule_callback_arg;
/*:260*//*360:*/
#line 2614 "./marpa.w"

Marpa_Message_Callback*message_callback;
void*message_callback_arg;
/*:360*/
#line 453 "./marpa.w"

/*28:*/
#line 485 "./marpa.w"
int id;
/*:28*/
#line 454 "./marpa.w"

/*54:*/
#line 590 "./marpa.w"
unsigned int is_precomputed:1;
/*:54*//*58:*/
#line 605 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:58*/
#line 455 "./marpa.w"

};

/*:22*//*68:*/
#line 651 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:68*//*69:*/
#line 656 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:69*//*70:*/
#line 661 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:70*//*85:*/
#line 749 "./marpa.w"

struct marpa_r{
int dummy;
};

/*:85*//*304:*/
#line 2123 "./marpa.w"

struct marpa_earley_item{
int dummy;
};
/*:304*/
#line 437 "./marpa.w"

/*19:*/
#line 409 "./marpa.w"

void marpa_version(int*version);

/*:19*//*24:*/
#line 465 "./marpa.w"

void marpa_g_init(struct marpa_g*g);

/*:24*//*26:*/
#line 471 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g);

/*:26*//*33:*/
#line 492 "./marpa.w"

gint marpa_grammar_id_value(struct marpa_g*g);

/*:33*//*38:*/
#line 509 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:38*//*50:*/
#line 565 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:50*//*57:*/
#line 597 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:57*//*61:*/
#line 612 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:61*//*63:*/
#line 627 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:63*//*78:*/
#line 717 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key);

/*:78*//*84:*/
#line 744 "./marpa.w"

Marpa_Error_ID marpa_error_value(struct marpa_g*g);

/*:84*//*87:*/
#line 766 "./marpa.w"

void marpa_r_init(struct marpa_r*recce);
/*:87*//*89:*/
#line 770 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce);

/*:89*//*94:*/
#line 800 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:94*//*104:*/
#line 836 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID id);
/*:104*//*107:*/
#line 845 "./marpa.w"

void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:107*//*112:*/
#line 868 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID id);
/*:112*//*115:*/
#line 877 "./marpa.w"

void marpa_symbol_rhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:115*//*119:*/
#line 895 "./marpa.w"

gboolean marpa_symbol_is_accessible_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:119*//*121:*/
#line 902 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:121*//*125:*/
#line 921 "./marpa.w"

gboolean marpa_symbol_is_counted_value(struct marpa_g*g,Marpa_Symbol_ID id);

/*:125*//*129:*/
#line 939 "./marpa.w"

gboolean marpa_symbol_is_nullable_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:129*//*131:*/
#line 946 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:131*//*135:*/
#line 964 "./marpa.w"

gboolean marpa_symbol_is_nulling_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:135*//*137:*/
#line 971 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:137*//*141:*/
#line 989 "./marpa.w"

gboolean marpa_symbol_is_terminal_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:141*//*143:*/
#line 996 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:143*//*147:*/
#line 1015 "./marpa.w"

gboolean marpa_symbol_is_productive_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:147*//*149:*/
#line 1022 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:149*//*154:*/
#line 1045 "./marpa.w"

gboolean marpa_symbol_is_start_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:154*//*156:*/
#line 1051 "./marpa.w"

void marpa_symbol_is_start_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:156*//*162:*/
#line 1091 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:162*//*165:*/
#line 1113 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:165*//*168:*/
#line 1154 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:168*//*173:*/
#line 1176 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_symbol_callback_arg_peek(struct marpa_g*g);
/*:173*//*186:*/
#line 1294 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:186*//*202:*/
#line 1461 "./marpa.w"

Marpa_Rule_ID marpa_rule_start_shim(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
void marpa_rule_complete_shim(struct marpa_g*g,Marpa_Rule_ID id);
Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);

/*:202*//*219:*/
#line 1613 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:219*//*223:*/
#line 1623 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:223*//*227:*/
#line 1633 "./marpa.w"

gsize marpa_rule_length_value(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:227*//*238:*/
#line 1670 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:238*//*242:*/
#line 1705 "./marpa.w"

gboolean marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:242*//*245:*/
#line 1719 "./marpa.w"

gboolean marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:245*//*249:*/
#line 1731 "./marpa.w"

gboolean marpa_rule_is_used_value(struct marpa_g*g,Marpa_Rule_ID id);

/*:249*//*253:*/
#line 1757 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs_value(struct marpa_g*g,Marpa_Rule_ID id);

/*:253*//*257:*/
#line 1768 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs_value(struct marpa_g*g,Marpa_Rule_ID id);

/*:257*//*262:*/
#line 1786 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:262*//*264:*/
#line 1791 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg);
/*:264*//*266:*/
#line 1796 "./marpa.w"

void*marpa_rule_callback_arg_peek(struct marpa_g*g);
/*:266*//*280:*/
#line 1846 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent_value(struct marpa_g*g,Marpa_Rule_ID id);

/*:280*//*283:*/
#line 1918 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);
/*:283*//*306:*/
#line 2133 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void);
/*:306*//*308:*/
#line 2139 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item);
/*:308*//*362:*/
#line 2624 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_message_callback_arg_peek(struct marpa_g*g);
/*:362*//*367:*/
#line 2666 "./marpa.w"

const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro);

/*:367*/
#line 438 "./marpa.w"

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE
/*380:*/
#line 2880 "./marpa.w"


/*:380*/
#line 440 "./marpa.w"

#endif
#endif

/*:20*/
#line 2876 "./marpa.w"


/*:379*/
