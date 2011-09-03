/*1411:*/
#line 13412 "./marpa.w"

/*
 * Copyright 2011 Jeffrey Kegler
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

/*:1411*//*1412:*/
#line 13436 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*43:*/
#line 678 "./marpa.w"

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
/*117:*/
#line 1008 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->t_type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->t_type == MARPA_CONTEXT_INT \
    ? ((struct marpa_context_int_value*)v)->t_data \
    : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->t_type == MARPA_CONTEXT_CONST \
    ? ((struct marpa_context_const_value*)v)->t_data \
    : NULL) 
/*:117*//*271:*/
#line 2047 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:271*//*276:*/
#line 2080 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:276*/
#line 691 "./marpa.w"

/*44:*/
#line 699 "./marpa.w"
struct marpa_g;
/*:44*//*613:*/
#line 5392 "./marpa.w"

struct marpa_r;
/*:613*/
#line 692 "./marpa.w"

/*53:*/
#line 738 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:53*//*132:*/
#line 1122 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:132*//*138:*/
#line 1141 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:138*//*223:*/
#line 1558 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:223*//*456:*/
#line 3576 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:456*//*502:*/
#line 3964 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:502*//*622:*/
#line 5452 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:622*//*629:*/
#line 5478 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:629*//*717:*/
#line 5953 "./marpa.w"
typedef gint Marpa_Earleme;
/*:717*//*719:*/
#line 5957 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:719*//*749:*/
#line 6177 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:749*//*1030:*/
#line 9461 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:1030*//*1094:*/
#line 10384 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:1094*//*1202:*/
#line 11632 "./marpa.w"

typedef gint Marpa_Fork_ID;
/*:1202*//*1380:*/
#line 13156 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1380*/
#line 693 "./marpa.w"

/*216:*/
#line 1526 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:216*//*323:*/
#line 2296 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:323*//*1382:*/
#line 13163 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1382*//*1390:*/
#line 13198 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1390*/
#line 694 "./marpa.w"

/*118:*/
#line 1020 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:118*//*119:*/
#line 1025 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:119*//*120:*/
#line 1030 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:120*/
#line 695 "./marpa.w"

/*42:*/
#line 670 "./marpa.w"

void marpa_version(int*version);

/*:42*//*48:*/
#line 715 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:48*//*50:*/
#line 723 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:50*//*57:*/
#line 744 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:57*//*62:*/
#line 766 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:62*//*72:*/
#line 813 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:72*//*78:*/
#line 842 "./marpa.w"

gpointer marpa_default_value(struct marpa_g*g);
/*:78*//*80:*/
#line 847 "./marpa.w"

gboolean marpa_default_value_set(struct marpa_g*g,gpointer default_value);
/*:80*//*85:*/
#line 865 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:85*//*87:*/
#line 878 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:87*//*97:*/
#line 929 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:97*//*104:*/
#line 947 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:104*//*108:*/
#line 962 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:108*//*110:*/
#line 977 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:110*//*128:*/
#line 1087 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:128*//*137:*/
#line 1136 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:137*//*144:*/
#line 1176 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:144*//*154:*/
#line 1218 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:154*//*161:*/
#line 1248 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:161*//*167:*/
#line 1271 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:167*//*169:*/
#line 1278 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:169*//*173:*/
#line 1297 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:173*//*177:*/
#line 1315 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:177*//*179:*/
#line 1322 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:179*//*183:*/
#line 1343 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:183*//*185:*/
#line 1350 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:185*//*189:*/
#line 1370 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:189*//*191:*/
#line 1377 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:191*//*195:*/
#line 1396 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:195*//*197:*/
#line 1403 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:197*//*202:*/
#line 1423 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:202*//*208:*/
#line 1463 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:208*//*211:*/
#line 1491 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:211*//*220:*/
#line 1541 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:220*//*232:*/
#line 1655 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:232*//*246:*/
#line 1836 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:246*//*259:*/
#line 1997 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:259*//*263:*/
#line 2013 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:263*//*267:*/
#line 2025 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:267*//*275:*/
#line 2055 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:275*//*280:*/
#line 2100 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:280*//*284:*/
#line 2124 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:284*//*289:*/
#line 2144 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:289*//*294:*/
#line 2165 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:294*//*301:*/
#line 2200 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:301*//*305:*/
#line 2216 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:305*//*309:*/
#line 2242 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:309*//*313:*/
#line 2253 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:313*//*317:*/
#line 2269 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:317*//*321:*/
#line 2285 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:321*//*327:*/
#line 2307 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:327*//*329:*/
#line 2312 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:329*//*331:*/
#line 2317 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:331*//*338:*/
#line 2339 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:338*//*343:*/
#line 2353 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:343*//*347:*/
#line 2369 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:347*//*357:*/
#line 2452 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:357*//*472:*/
#line 3669 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:472*//*474:*/
#line 3680 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:474*//*475:*/
#line 3684 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:475*//*477:*/
#line 3696 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:477*//*479:*/
#line 3707 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:479*//*527:*/
#line 4133 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:527*//*529:*/
#line 4146 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:529*//*530:*/
#line 4149 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:530*//*533:*/
#line 4184 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:533*//*535:*/
#line 4194 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:535*//*540:*/
#line 4258 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:540*//*606:*/
#line 5323 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:606*//*609:*/
#line 5357 "./marpa.w"

/*:609*//*610:*/
#line 5358 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:610*//*616:*/
#line 5403 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:616*//*619:*/
#line 5437 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:619*//*626:*/
#line 5458 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:626*//*632:*/
#line 5492 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:632*//*638:*/
#line 5520 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:638*//*644:*/
#line 5542 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:644*//*646:*/
#line 5548 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:646*//*650:*/
#line 5569 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:650*//*669:*/
#line 5662 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:669*//*684:*/
#line 5770 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:684*//*687:*/
#line 5790 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:687*//*690:*/
#line 5809 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:690*//*704:*/
#line 5891 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:704*//*713:*/
#line 5927 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:713*//*735:*/
#line 6059 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:735*//*737:*/
#line 6074 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:737*//*739:*/
#line 6092 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:739*//*742:*/
#line 6117 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:742*//*771:*/
#line 6413 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:771*//*775:*/
#line 6486 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:775*//*778:*/
#line 6525 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:778*//*810:*/
#line 6870 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:810*//*813:*/
#line 6908 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:813*//*815:*/
#line 6941 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:815*//*854:*/
#line 7354 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:854*//*858:*/
#line 7399 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:858*//*861:*/
#line 7431 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:861*//*865:*/
#line 7475 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:865*//*868:*/
#line 7509 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:868*//*872:*/
#line 7556 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:872*//*878:*/
#line 7613 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:878*//*880:*/
#line 7655 "./marpa.w"

Marpa_Symbol_ID marpa_source_token(struct marpa_r*r,gpointer*value_p);
/*:880*//*883:*/
#line 7688 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:883*//*886:*/
#line 7730 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:886*//*915:*/
#line 8036 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:915*//*923:*/
#line 8120 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length);
/*:923*//*941:*/
#line 8266 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:941*//*1123:*/
#line 10625 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1123*//*1139:*/
#line 10870 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1139*//*1180:*/
#line 11323 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r);
/*:1180*//*1194:*/
#line 11444 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length);
/*:1194*//*1200:*/
#line 11574 "./marpa.w"

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix);
/*:1200*//*1386:*/
#line 13178 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1386*//*1394:*/
#line 13215 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1394*/
#line 696 "./marpa.w"


/*:43*/
#line 13441 "./marpa.w"

#endif __MARPA_H__

/*:1412*/
