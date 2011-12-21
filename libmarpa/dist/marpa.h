/*1413:*/
#line 13602 "./marpa.w"

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

/*:1413*//*1414:*/
#line 13626 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*39:*/
#line 651 "./marpa.w"

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
/*113:*/
#line 981 "./marpa.w"

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
/*:113*//*260:*/
#line 1988 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:260*//*265:*/
#line 2021 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:265*/
#line 664 "./marpa.w"

/*40:*/
#line 672 "./marpa.w"
struct marpa_g;
/*:40*//*602:*/
#line 5358 "./marpa.w"

struct marpa_r;
/*:602*/
#line 665 "./marpa.w"

/*49:*/
#line 711 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:49*//*128:*/
#line 1095 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:128*//*134:*/
#line 1114 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:134*//*211:*/
#line 1500 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:211*//*445:*/
#line 3536 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:445*//*491:*/
#line 3924 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:491*//*611:*/
#line 5418 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:611*//*619:*/
#line 5450 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:619*//*702:*/
#line 5889 "./marpa.w"
typedef gint Marpa_Earleme;
/*:702*//*704:*/
#line 5893 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:704*//*734:*/
#line 6113 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:734*//*1007:*/
#line 9290 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:1007*//*1071:*/
#line 10213 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:1071*//*1181:*/
#line 11482 "./marpa.w"

typedef gint Marpa_Fork_ID;
/*:1181*//*1380:*/
#line 13303 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1380*/
#line 666 "./marpa.w"

/*204:*/
#line 1468 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:204*//*312:*/
#line 2244 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:312*//*1382:*/
#line 13310 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1382*//*1390:*/
#line 13345 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1390*/
#line 667 "./marpa.w"

/*114:*/
#line 993 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:114*//*115:*/
#line 998 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:115*//*116:*/
#line 1003 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:116*//*1202:*/
#line 11642 "./marpa.w"

struct marpa_event{
Marpa_Symbol_ID marpa_token_id;
gpointer marpa_value;
Marpa_Rule_ID marpa_rule_id;
gint marpa_arg_0;
gint marpa_arg_n;
};
typedef struct marpa_event Marpa_Event;
/*:1202*/
#line 668 "./marpa.w"

/*38:*/
#line 643 "./marpa.w"

void marpa_version(int*version);

/*:38*//*44:*/
#line 688 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:44*//*46:*/
#line 696 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:46*//*53:*/
#line 717 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:53*//*58:*/
#line 739 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:58*//*68:*/
#line 786 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:68*//*74:*/
#line 815 "./marpa.w"

gpointer marpa_default_value(struct marpa_g*g);
/*:74*//*76:*/
#line 820 "./marpa.w"

gboolean marpa_default_value_set(struct marpa_g*g,gpointer default_value);
/*:76*//*81:*/
#line 838 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:81*//*83:*/
#line 851 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:83*//*93:*/
#line 902 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:93*//*100:*/
#line 920 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:100*//*104:*/
#line 935 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:104*//*106:*/
#line 950 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:106*//*124:*/
#line 1060 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:124*//*133:*/
#line 1109 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:133*//*140:*/
#line 1149 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:140*//*150:*/
#line 1191 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:150*//*157:*/
#line 1221 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:157*//*163:*/
#line 1244 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);

/*:163*//*167:*/
#line 1262 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:167*//*171:*/
#line 1280 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);

/*:171*//*175:*/
#line 1301 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);

/*:175*//*179:*/
#line 1321 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:179*//*181:*/
#line 1327 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:181*//*185:*/
#line 1345 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);

/*:185*//*190:*/
#line 1365 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:190*//*196:*/
#line 1405 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:196*//*199:*/
#line 1433 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:199*//*208:*/
#line 1483 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:208*//*218:*/
#line 1545 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:218*//*220:*/
#line 1569 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:220*//*248:*/
#line 1938 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:248*//*251:*/
#line 1945 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix);
/*:251*//*256:*/
#line 1966 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:256*//*264:*/
#line 1996 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:264*//*269:*/
#line 2041 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:269*//*273:*/
#line 2065 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:273*//*278:*/
#line 2085 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:278*//*283:*/
#line 2106 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:283*//*290:*/
#line 2141 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:290*//*294:*/
#line 2157 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:294*//*298:*/
#line 2187 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:298*//*302:*/
#line 2202 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:302*//*306:*/
#line 2218 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:306*//*310:*/
#line 2234 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:310*//*316:*/
#line 2255 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:316*//*318:*/
#line 2260 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:318*//*320:*/
#line 2265 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:320*//*327:*/
#line 2291 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:327*//*331:*/
#line 2303 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:331*//*336:*/
#line 2326 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:336*//*346:*/
#line 2412 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:346*//*461:*/
#line 3629 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:461*//*463:*/
#line 3640 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:463*//*464:*/
#line 3644 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:464*//*466:*/
#line 3656 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:466*//*468:*/
#line 3667 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:468*//*516:*/
#line 4093 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:516*//*518:*/
#line 4106 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:518*//*519:*/
#line 4109 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:519*//*522:*/
#line 4144 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:522*//*524:*/
#line 4154 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:524*//*529:*/
#line 4218 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:529*//*595:*/
#line 5289 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:595*//*598:*/
#line 5323 "./marpa.w"

/*:598*//*599:*/
#line 5324 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:599*//*605:*/
#line 5369 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);
/*:605*//*608:*/
#line 5403 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:608*//*615:*/
#line 5424 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:615*//*622:*/
#line 5464 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:622*//*627:*/
#line 5487 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:627*//*633:*/
#line 5509 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:633*//*635:*/
#line 5515 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:635*//*639:*/
#line 5536 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:639*//*658:*/
#line 5629 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:658*//*671:*/
#line 5718 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:671*//*674:*/
#line 5739 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:674*//*677:*/
#line 5758 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:677*//*689:*/
#line 5827 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:689*//*698:*/
#line 5863 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:698*//*720:*/
#line 5995 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:720*//*722:*/
#line 6010 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:722*//*724:*/
#line 6028 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:724*//*727:*/
#line 6053 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:727*//*752:*/
#line 6314 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:752*//*755:*/
#line 6353 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:755*//*787:*/
#line 6698 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:787*//*790:*/
#line 6736 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:790*//*792:*/
#line 6769 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:792*//*831:*/
#line 7182 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:831*//*835:*/
#line 7227 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:835*//*838:*/
#line 7259 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:838*//*842:*/
#line 7303 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:842*//*845:*/
#line 7337 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:845*//*849:*/
#line 7384 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:849*//*855:*/
#line 7441 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:855*//*857:*/
#line 7483 "./marpa.w"

Marpa_Symbol_ID marpa_source_token(struct marpa_r*r,gpointer*value_p);
/*:857*//*860:*/
#line 7516 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:860*//*863:*/
#line 7558 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:863*//*892:*/
#line 7864 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:892*//*900:*/
#line 7948 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length);
/*:900*//*918:*/
#line 8094 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:918*//*1089:*/
#line 10391 "./marpa.w"

Marpa_Symbol_ID marpa_and_node_token(struct marpa_r*r,
Marpa_And_Node_ID and_node_id,gpointer*value_p);
/*:1089*//*1103:*/
#line 10467 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1103*//*1118:*/
#line 10710 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1118*//*1144:*/
#line 10921 "./marpa.w"

int marpa_tree_new(struct marpa_r*r);
/*:1144*//*1159:*/
#line 11173 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r);
/*:1159*//*1173:*/
#line 11294 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length);
/*:1173*//*1179:*/
#line 11424 "./marpa.w"

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix);
/*:1179*//*1208:*/
#line 11709 "./marpa.w"

int marpa_val_new(struct marpa_r*r);
/*:1208*//*1215:*/
#line 11807 "./marpa.w"

gint marpa_val_trace(struct marpa_r*r,gint flag);
/*:1215*//*1217:*/
#line 11821 "./marpa.w"

Marpa_Fork_ID marpa_val_fork(struct marpa_r*r);
/*:1217*//*1219:*/
#line 11834 "./marpa.w"

Marpa_Fork_ID marpa_val_event(struct marpa_r*r,Marpa_Event*event);
/*:1219*//*1386:*/
#line 13325 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1386*//*1394:*/
#line 13362 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1394*/
#line 669 "./marpa.w"


/*:39*/
#line 13631 "./marpa.w"

#endif __MARPA_H__

/*:1414*/
