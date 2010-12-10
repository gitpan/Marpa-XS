/*584:*/
#line 4565 "./marpa.w"

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
/*586:*/
#line 4633 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:586*/
#line 422 "./marpa.w"

/*86:*/
#line 733 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:86*//*251:*/
#line 1743 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:251*//*256:*/
#line 1776 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:256*/
#line 423 "./marpa.w"

struct marpa_g;
/*28:*/
#line 475 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:28*//*101:*/
#line 827 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:101*//*112:*/
#line 871 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:112*//*194:*/
#line 1273 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:194*//*415:*/
#line 3115 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:415*//*444:*/
#line 3324 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:444*//*570:*/
#line 4420 "./marpa.w"

typedef const gchar*Marpa_Message_ID;
/*:570*/
#line 425 "./marpa.w"

/*188:*/
#line 1248 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:188*//*295:*/
#line 1942 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:295*//*571:*/
#line 4425 "./marpa.w"

typedef void(Marpa_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:571*/
#line 426 "./marpa.w"

/*87:*/
#line 741 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:87*//*88:*/
#line 746 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:88*//*89:*/
#line 751 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:89*//*107:*/
#line 846 "./marpa.w"

struct marpa_r{
int dummy;
};

/*:107*//*467:*/
#line 3538 "./marpa.w"

struct marpa_earley_item{
int dummy;
};
/*:467*/
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

/*:82*//*97:*/
#line 806 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key);

/*:97*//*106:*/
#line 841 "./marpa.w"

Marpa_Error_ID marpa_error(struct marpa_g*g);

/*:106*//*109:*/
#line 863 "./marpa.w"

void marpa_r_init(struct marpa_r*recce);
/*:109*//*111:*/
#line 867 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce);

/*:111*//*116:*/
#line 897 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:116*//*126:*/
#line 930 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:126*//*133:*/
#line 957 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:133*//*139:*/
#line 980 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:139*//*141:*/
#line 987 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:141*//*145:*/
#line 1006 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:145*//*149:*/
#line 1024 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:149*//*151:*/
#line 1031 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:151*//*155:*/
#line 1051 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:155*//*157:*/
#line 1058 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:157*//*161:*/
#line 1076 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:161*//*163:*/
#line 1083 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:163*//*167:*/
#line 1102 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:167*//*169:*/
#line 1109 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:169*//*174:*/
#line 1129 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:174*//*180:*/
#line 1169 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:180*//*183:*/
#line 1197 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:183*//*186:*/
#line 1238 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:186*//*191:*/
#line 1260 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_symbol_callback_arg(struct marpa_g*g);
/*:191*//*203:*/
#line 1364 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:203*//*219:*/
#line 1542 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);

/*:219*//*236:*/
#line 1692 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:236*//*240:*/
#line 1703 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:240*//*244:*/
#line 1714 "./marpa.w"

gsize marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:244*//*255:*/
#line 1751 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:255*//*260:*/
#line 1794 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:260*//*264:*/
#line 1816 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:264*//*269:*/
#line 1834 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:269*//*274:*/
#line 1853 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:274*//*281:*/
#line 1881 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:281*//*285:*/
#line 1907 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:285*//*289:*/
#line 1918 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:289*//*298:*/
#line 1950 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:298*//*300:*/
#line 1955 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg);
/*:300*//*302:*/
#line 1960 "./marpa.w"

void*marpa_rule_callback_arg(struct marpa_g*g);
/*:302*//*316:*/
#line 2010 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:316*//*320:*/
#line 2049 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:320*//*423:*/
#line 3159 "./marpa.w"

gint marpa_AHFA_item_count(struct marpa_g*g);
/*:423*//*425:*/
#line 3169 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:425*//*427:*/
#line 3180 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:427*//*429:*/
#line 3191 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:429*//*431:*/
#line 3201 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:431*//*454:*/
#line 3389 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:454*//*456:*/
#line 3410 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
gint item_ix);

/*:456*//*458:*/
#line 3425 "./marpa.w"

gint marpa_AHFA_state_is_reset(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:458*//*469:*/
#line 3548 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void);
/*:469*//*471:*/
#line 3554 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item);
/*:471*//*574:*/
#line 4437 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_message_callback_arg(struct marpa_g*g);
/*:574*/
#line 428 "./marpa.w"

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE
/*585:*/
#line 4597 "./marpa.w"


/*:585*/
#line 430 "./marpa.w"

#endif

/*:19*/
#line 4592 "./marpa.w"

#endif __MARPA_H__

/*:584*/
