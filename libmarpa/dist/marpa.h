/*1224:*/
#line 11015 "./marpa.w"

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

/*:1224*//*1225:*/
#line 11039 "./marpa.w"

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
/*:41*//*599:*/
#line 5198 "./marpa.w"

struct marpa_r;
/*:599*/
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
/*:444*//*489:*/
#line 3784 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:489*//*608:*/
#line 5256 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:608*//*615:*/
#line 5282 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:615*//*703:*/
#line 5758 "./marpa.w"
typedef gint Marpa_Earleme;
/*:703*//*705:*/
#line 5762 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:705*//*734:*/
#line 5983 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:734*//*1195:*/
#line 10821 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1195*/
#line 650 "./marpa.w"

/*209:*/
#line 1465 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:209*//*319:*/
#line 2218 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:319*//*1197:*/
#line 10828 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1197*//*1205:*/
#line 10863 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1205*/
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

/*:345*//*458:*/
#line 3512 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:458*//*460:*/
#line 3523 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:460*//*462:*/
#line 3534 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:462*//*464:*/
#line 3545 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:464*//*466:*/
#line 3555 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:466*//*514:*/
#line 3954 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:514*//*516:*/
#line 3967 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:516*//*517:*/
#line 3970 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:517*//*520:*/
#line 4005 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:520*//*522:*/
#line 4015 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:522*//*527:*/
#line 4079 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:527*//*592:*/
#line 5129 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:592*//*595:*/
#line 5163 "./marpa.w"

/*:595*//*596:*/
#line 5164 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:596*//*602:*/
#line 5209 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:602*//*605:*/
#line 5241 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:605*//*612:*/
#line 5262 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:612*//*618:*/
#line 5297 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:618*//*624:*/
#line 5325 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:624*//*630:*/
#line 5347 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:630*//*632:*/
#line 5353 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:632*//*636:*/
#line 5374 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:636*//*655:*/
#line 5467 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:655*//*670:*/
#line 5575 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:670*//*673:*/
#line 5595 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:673*//*676:*/
#line 5614 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:676*//*690:*/
#line 5696 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:690*//*699:*/
#line 5732 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:699*//*720:*/
#line 5865 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:720*//*722:*/
#line 5880 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:722*//*724:*/
#line 5898 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:724*//*727:*/
#line 5923 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:727*//*757:*/
#line 6231 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:757*//*761:*/
#line 6304 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:761*//*764:*/
#line 6343 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:764*//*796:*/
#line 6689 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:796*//*799:*/
#line 6727 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:799*//*801:*/
#line 6760 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:801*//*840:*/
#line 7181 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:840*//*844:*/
#line 7226 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:844*//*847:*/
#line 7258 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:847*//*851:*/
#line 7302 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:851*//*854:*/
#line 7336 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:854*//*858:*/
#line 7383 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:858*//*864:*/
#line 7440 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:864*//*867:*/
#line 7477 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:867*//*870:*/
#line 7519 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:870*//*872:*/
#line 7558 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:872*//*891:*/
#line 7743 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:891*//*899:*/
#line 7827 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:899*//*917:*/
#line 7967 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:917*//*972:*/
#line 8739 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:972*//*1014:*/
#line 9050 "./marpa.w"

gint marpa_eval_setup(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1014*//*1035:*/
#line 9460 "./marpa.w"

gint marpa_eval_clear(struct marpa_r*r);
/*:1035*//*1201:*/
#line 10843 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1201*//*1209:*/
#line 10880 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1209*/
#line 653 "./marpa.w"


/*:40*/
#line 11044 "./marpa.w"

#endif __MARPA_H__

/*:1225*/
