/*590:*/
#line 4613 "./marpa.w"

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
#line 390 "./marpa.w"

/*:14*//*19:*/
#line 412 "./marpa.w"

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
/*592:*/
#line 4681 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:592*/
#line 425 "./marpa.w"

/*86:*/
#line 735 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:86*//*251:*/
#line 1746 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:251*//*256:*/
#line 1779 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:256*/
#line 426 "./marpa.w"

struct marpa_g;
/*28:*/
#line 478 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:28*//*101:*/
#line 829 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:101*//*112:*/
#line 876 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:112*//*194:*/
#line 1282 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:194*//*416:*/
#line 3140 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:416*//*445:*/
#line 3349 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:445*//*576:*/
#line 4477 "./marpa.w"

typedef const gchar*Marpa_Message_ID;
/*:576*/
#line 428 "./marpa.w"

/*188:*/
#line 1255 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:188*//*295:*/
#line 1955 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:295*//*577:*/
#line 4482 "./marpa.w"

typedef void(Marpa_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:577*/
#line 429 "./marpa.w"

/*87:*/
#line 743 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:87*//*88:*/
#line 748 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:88*//*89:*/
#line 753 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:89*//*107:*/
#line 848 "./marpa.w"

struct marpa_r{
int dummy;
};

/*:107*//*472:*/
#line 3588 "./marpa.w"

struct marpa_earley_item{
int dummy;
};
/*:472*/
#line 430 "./marpa.w"

/*18:*/
#line 405 "./marpa.w"

void marpa_version(int*version);

/*:18*//*23:*/
#line 455 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:23*//*25:*/
#line 463 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g);

/*:25*//*32:*/
#line 484 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:32*//*37:*/
#line 505 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:37*//*49:*/
#line 561 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:49*//*60:*/
#line 613 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:60*//*62:*/
#line 631 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:62*//*72:*/
#line 678 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:72*//*76:*/
#line 689 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:76*//*80:*/
#line 704 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:80*//*82:*/
#line 719 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:82*//*97:*/
#line 808 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key);

/*:97*//*106:*/
#line 843 "./marpa.w"

Marpa_Error_ID marpa_error(const struct marpa_g*g);

/*:106*//*109:*/
#line 865 "./marpa.w"

void marpa_r_init(struct marpa_r*recce);

/*:109*//*111:*/
#line 872 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce);

/*:111*//*116:*/
#line 902 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:116*//*126:*/
#line 935 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:126*//*133:*/
#line 964 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:133*//*139:*/
#line 987 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:139*//*141:*/
#line 994 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:141*//*145:*/
#line 1013 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:145*//*149:*/
#line 1031 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:149*//*151:*/
#line 1038 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:151*//*155:*/
#line 1058 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:155*//*157:*/
#line 1065 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:157*//*161:*/
#line 1083 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:161*//*163:*/
#line 1090 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:163*//*167:*/
#line 1109 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:167*//*169:*/
#line 1116 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:169*//*174:*/
#line 1136 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:174*//*180:*/
#line 1176 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:180*//*183:*/
#line 1204 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:183*//*186:*/
#line 1245 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:186*//*191:*/
#line 1267 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_symbol_callback_arg(struct marpa_g*g);
/*:191*//*204:*/
#line 1369 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:204*//*219:*/
#line 1542 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:219*//*236:*/
#line 1693 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:236*//*240:*/
#line 1705 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:240*//*244:*/
#line 1717 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:244*//*255:*/
#line 1754 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:255*//*260:*/
#line 1799 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:260*//*264:*/
#line 1823 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:264*//*269:*/
#line 1843 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:269*//*274:*/
#line 1864 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:274*//*281:*/
#line 1894 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:281*//*285:*/
#line 1920 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:285*//*289:*/
#line 1931 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:289*//*298:*/
#line 1963 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:298*//*300:*/
#line 1968 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg);
/*:300*//*302:*/
#line 1973 "./marpa.w"

void*marpa_rule_callback_arg(struct marpa_g*g);
/*:302*//*309:*/
#line 1994 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:309*//*314:*/
#line 2008 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:314*//*318:*/
#line 2029 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:318*//*320:*/
#line 2054 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:320*//*424:*/
#line 3184 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:424*//*426:*/
#line 3195 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:426*//*428:*/
#line 3206 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:428*//*430:*/
#line 3217 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:430*//*432:*/
#line 3227 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:432*//*457:*/
#line 3424 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:457*//*459:*/
#line 3437 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:459*//*461:*/
#line 3458 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:461*//*463:*/
#line 3473 "./marpa.w"

gint marpa_AHFA_state_is_reset(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:463*//*474:*/
#line 3598 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void);
/*:474*//*476:*/
#line 3604 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item);
/*:476*//*580:*/
#line 4494 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_message_callback_arg(struct marpa_g*g);
/*:580*/
#line 431 "./marpa.w"

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE
/*591:*/
#line 4645 "./marpa.w"


/*:591*/
#line 433 "./marpa.w"

#endif

/*:19*/
#line 4640 "./marpa.w"

#endif __MARPA_H__

/*:590*/
