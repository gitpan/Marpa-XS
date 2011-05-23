/*1216:*/
#line 10823 "./marpa.w"

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

/*:1216*//*1217:*/
#line 10847 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*40:*/
#line 635 "./marpa.w"

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
/*110:*/
#line 951 "./marpa.w"

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
/*:110*//*267:*/
#line 1974 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:267*//*272:*/
#line 2007 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:272*/
#line 648 "./marpa.w"

/*41:*/
#line 656 "./marpa.w"
struct marpa_g;
/*:41*//*596:*/
#line 5111 "./marpa.w"

struct marpa_r;
/*:596*/
#line 649 "./marpa.w"

/*50:*/
#line 695 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:50*//*125:*/
#line 1065 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:125*//*131:*/
#line 1084 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:131*//*216:*/
#line 1497 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:216*//*444:*/
#line 3440 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:444*//*485:*/
#line 3745 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:485*//*605:*/
#line 5169 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:605*//*612:*/
#line 5195 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:612*//*700:*/
#line 5671 "./marpa.w"
typedef gint Marpa_Earleme;
/*:700*//*702:*/
#line 5675 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:702*//*731:*/
#line 5896 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:731*//*1187:*/
#line 10629 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1187*/
#line 650 "./marpa.w"

/*209:*/
#line 1465 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:209*//*319:*/
#line 2218 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:319*//*1189:*/
#line 10636 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1189*//*1197:*/
#line 10671 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1197*/
#line 651 "./marpa.w"

/*111:*/
#line 963 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:111*//*112:*/
#line 968 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:112*//*113:*/
#line 973 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:113*/
#line 652 "./marpa.w"

/*39:*/
#line 627 "./marpa.w"

void marpa_version(int*version);

/*:39*//*45:*/
#line 672 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:45*//*47:*/
#line 680 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:47*//*54:*/
#line 701 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:54*//*59:*/
#line 723 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:59*//*69:*/
#line 769 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:69*//*78:*/
#line 808 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:78*//*80:*/
#line 821 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:80*//*90:*/
#line 872 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:90*//*97:*/
#line 890 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:97*//*101:*/
#line 905 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:101*//*103:*/
#line 920 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:103*//*121:*/
#line 1030 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:121*//*130:*/
#line 1079 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:130*//*137:*/
#line 1116 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:137*//*147:*/
#line 1158 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:147*//*154:*/
#line 1187 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:154*//*160:*/
#line 1210 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:160*//*162:*/
#line 1217 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:162*//*166:*/
#line 1236 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:166*//*170:*/
#line 1254 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:170*//*172:*/
#line 1261 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:172*//*176:*/
#line 1281 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:176*//*178:*/
#line 1288 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:178*//*182:*/
#line 1309 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:182*//*184:*/
#line 1316 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:184*//*188:*/
#line 1335 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:188*//*190:*/
#line 1342 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:190*//*195:*/
#line 1362 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:195*//*201:*/
#line 1402 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:201*//*204:*/
#line 1430 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:204*//*213:*/
#line 1480 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:213*//*225:*/
#line 1590 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:225*//*239:*/
#line 1771 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:239*//*252:*/
#line 1917 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:252*//*256:*/
#line 1933 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:256*//*260:*/
#line 1945 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:260*//*271:*/
#line 1982 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:271*//*276:*/
#line 2027 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:276*//*280:*/
#line 2051 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:280*//*285:*/
#line 2071 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:285*//*290:*/
#line 2092 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:290*//*297:*/
#line 2122 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:297*//*301:*/
#line 2138 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:301*//*305:*/
#line 2164 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:305*//*309:*/
#line 2175 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:309*//*313:*/
#line 2191 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:313*//*317:*/
#line 2207 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:317*//*323:*/
#line 2229 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:323*//*325:*/
#line 2234 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:325*//*327:*/
#line 2239 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:327*//*334:*/
#line 2261 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:334*//*339:*/
#line 2275 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:339*//*343:*/
#line 2296 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:343*//*345:*/
#line 2322 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:345*//*457:*/
#line 3507 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:457*//*459:*/
#line 3518 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:459*//*461:*/
#line 3529 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:461*//*463:*/
#line 3540 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:463*//*465:*/
#line 3550 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:465*//*511:*/
#line 3896 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:511*//*513:*/
#line 3909 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:513*//*515:*/
#line 3930 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:515*//*517:*/
#line 3945 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:517*//*519:*/
#line 3955 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:519*//*524:*/
#line 4019 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:524*//*589:*/
#line 5042 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:589*//*592:*/
#line 5076 "./marpa.w"

/*:592*//*593:*/
#line 5077 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:593*//*599:*/
#line 5122 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:599*//*602:*/
#line 5154 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:602*//*609:*/
#line 5175 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:609*//*615:*/
#line 5210 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:615*//*621:*/
#line 5238 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:621*//*627:*/
#line 5260 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:627*//*629:*/
#line 5266 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:629*//*633:*/
#line 5287 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:633*//*652:*/
#line 5380 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:652*//*667:*/
#line 5488 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:667*//*670:*/
#line 5508 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:670*//*673:*/
#line 5527 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:673*//*687:*/
#line 5609 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:687*//*696:*/
#line 5645 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:696*//*717:*/
#line 5778 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:717*//*719:*/
#line 5793 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:719*//*721:*/
#line 5811 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:721*//*724:*/
#line 5836 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:724*//*754:*/
#line 6142 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:754*//*758:*/
#line 6215 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:758*//*761:*/
#line 6254 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:761*//*793:*/
#line 6600 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:793*//*796:*/
#line 6638 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:796*//*798:*/
#line 6671 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:798*//*837:*/
#line 7092 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:837*//*841:*/
#line 7137 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:841*//*844:*/
#line 7169 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:844*//*848:*/
#line 7213 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:848*//*851:*/
#line 7247 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:851*//*855:*/
#line 7294 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:855*//*861:*/
#line 7351 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:861*//*864:*/
#line 7388 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:864*//*867:*/
#line 7430 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:867*//*869:*/
#line 7469 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:869*//*888:*/
#line 7654 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:888*//*896:*/
#line 7738 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:896*//*914:*/
#line 7878 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:914*//*969:*/
#line 8650 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:969*//*1008:*/
#line 8936 "./marpa.w"

gint marpa_eval_setup(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1008*//*1027:*/
#line 9268 "./marpa.w"

gint marpa_eval_clear(struct marpa_r*r);
/*:1027*//*1193:*/
#line 10651 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1193*//*1201:*/
#line 10688 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1201*/
#line 653 "./marpa.w"


/*:40*/
#line 10852 "./marpa.w"

#endif __MARPA_H__

/*:1217*/
