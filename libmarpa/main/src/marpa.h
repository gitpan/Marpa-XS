/*580:*/
#line 4503 "./marpa.w"

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

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*14:*/
#line 387 "./marpa.w"

/*:14*//*19:*/
#line 409 "./marpa.w"

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
/*582:*/
#line 4571 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:582*/
#line 422 "./marpa.w"

/*92:*/
#line 773 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:92*//*257:*/
#line 1783 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:257*//*262:*/
#line 1816 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:262*/
#line 423 "./marpa.w"

struct marpa_g;
/*28:*/
#line 475 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:28*//*107:*/
#line 867 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:107*//*118:*/
#line 911 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:118*//*200:*/
#line 1313 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:200*//*422:*/
#line 3163 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:422*//*566:*/
#line 4358 "./marpa.w"

typedef const gchar*Marpa_Message_ID;
/*:566*/
#line 425 "./marpa.w"

/*194:*/
#line 1288 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:194*//*301:*/
#line 1982 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:301*//*567:*/
#line 4363 "./marpa.w"

typedef void(Marpa_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:567*/
#line 426 "./marpa.w"

/*93:*/
#line 781 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:93*//*94:*/
#line 786 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:94*//*95:*/
#line 791 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:95*//*113:*/
#line 886 "./marpa.w"

struct marpa_r{
int dummy;
};

/*:113*//*464:*/
#line 3483 "./marpa.w"

struct marpa_earley_item{
int dummy;
};
/*:464*/
#line 427 "./marpa.w"

/*18:*/
#line 402 "./marpa.w"

void marpa_version(int*version);

/*:18*//*23:*/
#line 452 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:23*//*25:*/
#line 460 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g);

/*:25*//*32:*/
#line 481 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:32*//*37:*/
#line 502 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:37*//*49:*/
#line 558 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:49*//*60:*/
#line 610 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:60*//*62:*/
#line 629 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:62*//*72:*/
#line 676 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:72*//*76:*/
#line 687 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:76*//*80:*/
#line 702 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:80*//*82:*/
#line 717 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:82*//*86:*/
#line 742 "./marpa.w"

gboolean marpa_is_academic(struct marpa_g*g);
/*:86*//*88:*/
#line 757 "./marpa.w"

gboolean marpa_is_academic_set(struct marpa_g*g,gboolean value);

/*:88*//*103:*/
#line 846 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key);

/*:103*//*112:*/
#line 881 "./marpa.w"

Marpa_Error_ID marpa_error(struct marpa_g*g);

/*:112*//*115:*/
#line 903 "./marpa.w"

void marpa_r_init(struct marpa_r*recce);
/*:115*//*117:*/
#line 907 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce);

/*:117*//*122:*/
#line 937 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:122*//*132:*/
#line 970 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:132*//*139:*/
#line 997 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:139*//*145:*/
#line 1020 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:145*//*147:*/
#line 1027 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:147*//*151:*/
#line 1046 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:151*//*155:*/
#line 1064 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:155*//*157:*/
#line 1071 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:157*//*161:*/
#line 1091 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:161*//*163:*/
#line 1098 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:163*//*167:*/
#line 1116 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:167*//*169:*/
#line 1123 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:169*//*173:*/
#line 1142 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:173*//*175:*/
#line 1149 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:175*//*180:*/
#line 1169 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:180*//*186:*/
#line 1209 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:186*//*189:*/
#line 1237 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:189*//*192:*/
#line 1278 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:192*//*197:*/
#line 1300 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_symbol_callback_arg(struct marpa_g*g);
/*:197*//*209:*/
#line 1404 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:209*//*225:*/
#line 1582 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);

/*:225*//*242:*/
#line 1732 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:242*//*246:*/
#line 1743 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:246*//*250:*/
#line 1754 "./marpa.w"

gsize marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:250*//*261:*/
#line 1791 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:261*//*266:*/
#line 1834 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:266*//*270:*/
#line 1856 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:270*//*275:*/
#line 1874 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:275*//*280:*/
#line 1893 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:280*//*287:*/
#line 1921 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:287*//*291:*/
#line 1947 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:291*//*295:*/
#line 1958 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:295*//*304:*/
#line 1990 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:304*//*306:*/
#line 1995 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg);
/*:306*//*308:*/
#line 2000 "./marpa.w"

void*marpa_rule_callback_arg(struct marpa_g*g);
/*:308*//*322:*/
#line 2050 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:322*//*326:*/
#line 2092 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:326*//*430:*/
#line 3207 "./marpa.w"

gint marpa_AHFA_item_count(struct marpa_g*g);
/*:430*//*432:*/
#line 3217 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:432*//*434:*/
#line 3228 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:434*//*436:*/
#line 3239 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:436*//*438:*/
#line 3249 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:438*//*466:*/
#line 3493 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void);
/*:466*//*468:*/
#line 3499 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item);
/*:468*//*570:*/
#line 4375 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_message_callback_arg(struct marpa_g*g);
/*:570*/
#line 428 "./marpa.w"

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE
/*581:*/
#line 4535 "./marpa.w"


/*:581*/
#line 430 "./marpa.w"

#endif

/*:19*/
#line 4530 "./marpa.w"

#endif __MARPA_H__

/*:580*/
