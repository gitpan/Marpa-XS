/*1435:*/
#line 13741 "./marpa.w"

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

/*:1435*//*1436:*/
#line 13765 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*43:*/
#line 679 "./marpa.w"

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
#line 1009 "./marpa.w"

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
/*:117*//*272:*/
#line 2047 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:272*//*277:*/
#line 2080 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:277*/
#line 692 "./marpa.w"

/*44:*/
#line 700 "./marpa.w"
struct marpa_g;
/*:44*//*614:*/
#line 5411 "./marpa.w"

struct marpa_r;
/*:614*/
#line 693 "./marpa.w"

/*53:*/
#line 739 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:53*//*132:*/
#line 1123 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:132*//*138:*/
#line 1142 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:138*//*223:*/
#line 1559 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:223*//*457:*/
#line 3595 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:457*//*503:*/
#line 3983 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:503*//*623:*/
#line 5471 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:623*//*630:*/
#line 5497 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:630*//*718:*/
#line 5972 "./marpa.w"
typedef gint Marpa_Earleme;
/*:718*//*720:*/
#line 5976 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:720*//*750:*/
#line 6196 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:750*//*1031:*/
#line 9480 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:1031*//*1095:*/
#line 10403 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:1095*//*1205:*/
#line 11664 "./marpa.w"

typedef gint Marpa_Fork_ID;
/*:1205*//*1404:*/
#line 13485 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1404*/
#line 694 "./marpa.w"

/*216:*/
#line 1527 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:216*//*324:*/
#line 2303 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:324*//*1406:*/
#line 13492 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1406*//*1414:*/
#line 13527 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1414*/
#line 695 "./marpa.w"

/*118:*/
#line 1021 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:118*//*119:*/
#line 1026 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:119*//*120:*/
#line 1031 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:120*//*1226:*/
#line 11824 "./marpa.w"

struct marpa_event{
Marpa_Symbol_ID marpa_token_id;
gpointer marpa_value;
Marpa_Rule_ID marpa_rule_id;
gint marpa_arg_0;
gint marpa_arg_n;
};
typedef struct marpa_event Marpa_Event;
/*:1226*/
#line 696 "./marpa.w"

/*42:*/
#line 671 "./marpa.w"

void marpa_version(int*version);

/*:42*//*48:*/
#line 716 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:48*//*50:*/
#line 724 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:50*//*57:*/
#line 745 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:57*//*62:*/
#line 767 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:62*//*72:*/
#line 814 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:72*//*78:*/
#line 843 "./marpa.w"

gpointer marpa_default_value(struct marpa_g*g);
/*:78*//*80:*/
#line 848 "./marpa.w"

gboolean marpa_default_value_set(struct marpa_g*g,gpointer default_value);
/*:80*//*85:*/
#line 866 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:85*//*87:*/
#line 879 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:87*//*97:*/
#line 930 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:97*//*104:*/
#line 948 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:104*//*108:*/
#line 963 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:108*//*110:*/
#line 978 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:110*//*128:*/
#line 1088 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:128*//*137:*/
#line 1137 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:137*//*144:*/
#line 1177 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:144*//*154:*/
#line 1219 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:154*//*161:*/
#line 1249 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:161*//*167:*/
#line 1272 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:167*//*169:*/
#line 1279 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:169*//*173:*/
#line 1298 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:173*//*177:*/
#line 1316 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:177*//*179:*/
#line 1323 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:179*//*183:*/
#line 1344 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:183*//*185:*/
#line 1351 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:185*//*189:*/
#line 1371 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:189*//*191:*/
#line 1378 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:191*//*195:*/
#line 1397 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:195*//*197:*/
#line 1404 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:197*//*202:*/
#line 1424 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:202*//*208:*/
#line 1464 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:208*//*211:*/
#line 1492 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:211*//*220:*/
#line 1542 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:220*//*230:*/
#line 1604 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:230*//*232:*/
#line 1628 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:232*//*260:*/
#line 1997 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:260*//*263:*/
#line 2004 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix);
/*:263*//*268:*/
#line 2025 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:268*//*276:*/
#line 2055 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:276*//*281:*/
#line 2100 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:281*//*285:*/
#line 2124 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:285*//*290:*/
#line 2144 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:290*//*295:*/
#line 2165 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:295*//*302:*/
#line 2200 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:302*//*306:*/
#line 2216 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:306*//*310:*/
#line 2246 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:310*//*314:*/
#line 2261 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:314*//*318:*/
#line 2277 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:318*//*322:*/
#line 2293 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:322*//*328:*/
#line 2314 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:328*//*330:*/
#line 2319 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:330*//*332:*/
#line 2324 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:332*//*339:*/
#line 2350 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:339*//*343:*/
#line 2362 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:343*//*348:*/
#line 2385 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:348*//*358:*/
#line 2471 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:358*//*473:*/
#line 3688 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:473*//*475:*/
#line 3699 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:475*//*476:*/
#line 3703 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:476*//*478:*/
#line 3715 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:478*//*480:*/
#line 3726 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:480*//*528:*/
#line 4152 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:528*//*530:*/
#line 4165 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:530*//*531:*/
#line 4168 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:531*//*534:*/
#line 4203 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:534*//*536:*/
#line 4213 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:536*//*541:*/
#line 4277 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:541*//*607:*/
#line 5342 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:607*//*610:*/
#line 5376 "./marpa.w"

/*:610*//*611:*/
#line 5377 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:611*//*617:*/
#line 5422 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:617*//*620:*/
#line 5456 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:620*//*627:*/
#line 5477 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:627*//*633:*/
#line 5511 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:633*//*639:*/
#line 5539 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:639*//*645:*/
#line 5561 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:645*//*647:*/
#line 5567 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:647*//*651:*/
#line 5588 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:651*//*670:*/
#line 5681 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:670*//*685:*/
#line 5789 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:685*//*688:*/
#line 5809 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:688*//*691:*/
#line 5828 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:691*//*705:*/
#line 5910 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:705*//*714:*/
#line 5946 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:714*//*736:*/
#line 6078 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:736*//*738:*/
#line 6093 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:738*//*740:*/
#line 6111 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:740*//*743:*/
#line 6136 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:743*//*772:*/
#line 6432 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:772*//*776:*/
#line 6505 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:776*//*779:*/
#line 6544 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:779*//*811:*/
#line 6889 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:811*//*814:*/
#line 6927 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:814*//*816:*/
#line 6960 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:816*//*855:*/
#line 7373 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:855*//*859:*/
#line 7418 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:859*//*862:*/
#line 7450 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:862*//*866:*/
#line 7494 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:866*//*869:*/
#line 7528 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:869*//*873:*/
#line 7575 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:873*//*879:*/
#line 7632 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:879*//*881:*/
#line 7674 "./marpa.w"

Marpa_Symbol_ID marpa_source_token(struct marpa_r*r,gpointer*value_p);
/*:881*//*884:*/
#line 7707 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:884*//*887:*/
#line 7749 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:887*//*916:*/
#line 8055 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:916*//*924:*/
#line 8139 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length);
/*:924*//*942:*/
#line 8285 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:942*//*1113:*/
#line 10581 "./marpa.w"

Marpa_Symbol_ID marpa_and_node_token(struct marpa_r*r,
Marpa_And_Node_ID and_node_id,gpointer*value_p);
/*:1113*//*1126:*/
#line 10650 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1126*//*1142:*/
#line 10895 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1142*//*1183:*/
#line 11355 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r);
/*:1183*//*1197:*/
#line 11476 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length);
/*:1197*//*1203:*/
#line 11606 "./marpa.w"

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix);
/*:1203*//*1239:*/
#line 11989 "./marpa.w"

gint marpa_val_trace(struct marpa_r*r,gint flag);
/*:1239*//*1241:*/
#line 12003 "./marpa.w"

Marpa_Fork_ID marpa_val_fork(struct marpa_r*r);
/*:1241*//*1243:*/
#line 12016 "./marpa.w"

Marpa_Fork_ID marpa_val_event(struct marpa_r*r,Marpa_Event*event);
/*:1243*//*1410:*/
#line 13507 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1410*//*1418:*/
#line 13544 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1418*/
#line 697 "./marpa.w"


/*:43*/
#line 13770 "./marpa.w"

#endif __MARPA_H__

/*:1436*/
