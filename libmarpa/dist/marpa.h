/*1412:*/
#line 13414 "./marpa.w"

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

/*:1412*//*1413:*/
#line 13438 "./marpa.w"

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
/*:44*//*614:*/
#line 5394 "./marpa.w"

struct marpa_r;
/*:614*/
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
/*:223*//*457:*/
#line 3578 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:457*//*503:*/
#line 3966 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:503*//*623:*/
#line 5454 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:623*//*630:*/
#line 5480 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:630*//*718:*/
#line 5955 "./marpa.w"
typedef gint Marpa_Earleme;
/*:718*//*720:*/
#line 5959 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:720*//*750:*/
#line 6179 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:750*//*1031:*/
#line 9463 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:1031*//*1095:*/
#line 10386 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:1095*//*1203:*/
#line 11634 "./marpa.w"

typedef gint Marpa_Fork_ID;
/*:1203*//*1381:*/
#line 13158 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1381*/
#line 693 "./marpa.w"

/*216:*/
#line 1526 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:216*//*323:*/
#line 2296 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:323*//*1383:*/
#line 13165 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1383*//*1391:*/
#line 13200 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1391*/
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

/*:343*//*348:*/
#line 2372 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:348*//*358:*/
#line 2454 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:358*//*473:*/
#line 3671 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:473*//*475:*/
#line 3682 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:475*//*476:*/
#line 3686 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:476*//*478:*/
#line 3698 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:478*//*480:*/
#line 3709 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:480*//*528:*/
#line 4135 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:528*//*530:*/
#line 4148 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:530*//*531:*/
#line 4151 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:531*//*534:*/
#line 4186 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:534*//*536:*/
#line 4196 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:536*//*541:*/
#line 4260 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:541*//*607:*/
#line 5325 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:607*//*610:*/
#line 5359 "./marpa.w"

/*:610*//*611:*/
#line 5360 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:611*//*617:*/
#line 5405 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:617*//*620:*/
#line 5439 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:620*//*627:*/
#line 5460 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:627*//*633:*/
#line 5494 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:633*//*639:*/
#line 5522 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:639*//*645:*/
#line 5544 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:645*//*647:*/
#line 5550 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:647*//*651:*/
#line 5571 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:651*//*670:*/
#line 5664 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:670*//*685:*/
#line 5772 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:685*//*688:*/
#line 5792 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:688*//*691:*/
#line 5811 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:691*//*705:*/
#line 5893 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:705*//*714:*/
#line 5929 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:714*//*736:*/
#line 6061 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:736*//*738:*/
#line 6076 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:738*//*740:*/
#line 6094 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:740*//*743:*/
#line 6119 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:743*//*772:*/
#line 6415 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:772*//*776:*/
#line 6488 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:776*//*779:*/
#line 6527 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:779*//*811:*/
#line 6872 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:811*//*814:*/
#line 6910 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:814*//*816:*/
#line 6943 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:816*//*855:*/
#line 7356 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:855*//*859:*/
#line 7401 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:859*//*862:*/
#line 7433 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:862*//*866:*/
#line 7477 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:866*//*869:*/
#line 7511 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:869*//*873:*/
#line 7558 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:873*//*879:*/
#line 7615 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:879*//*881:*/
#line 7657 "./marpa.w"

Marpa_Symbol_ID marpa_source_token(struct marpa_r*r,gpointer*value_p);
/*:881*//*884:*/
#line 7690 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:884*//*887:*/
#line 7732 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:887*//*916:*/
#line 8038 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:916*//*924:*/
#line 8122 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length);
/*:924*//*942:*/
#line 8268 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:942*//*1124:*/
#line 10627 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1124*//*1140:*/
#line 10872 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1140*//*1181:*/
#line 11325 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r);
/*:1181*//*1195:*/
#line 11446 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length);
/*:1195*//*1201:*/
#line 11576 "./marpa.w"

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix);
/*:1201*//*1387:*/
#line 13180 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1387*//*1395:*/
#line 13217 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1395*/
#line 696 "./marpa.w"


/*:43*/
#line 13443 "./marpa.w"

#endif __MARPA_H__

/*:1413*/
