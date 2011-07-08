/*1302:*/
#line 12177 "./marpa.w"

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

/*:1302*//*1303:*/
#line 12201 "./marpa.w"

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
/*111:*/
#line 987 "./marpa.w"

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
/*:111*//*266:*/
#line 2031 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:266*//*271:*/
#line 2064 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:271*/
#line 691 "./marpa.w"

/*44:*/
#line 699 "./marpa.w"
struct marpa_g;
/*:44*//*608:*/
#line 5362 "./marpa.w"

struct marpa_r;
/*:608*/
#line 692 "./marpa.w"

/*53:*/
#line 738 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:53*//*126:*/
#line 1101 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:126*//*132:*/
#line 1120 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:132*//*218:*/
#line 1541 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:218*//*451:*/
#line 3556 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:451*//*497:*/
#line 3934 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:497*//*617:*/
#line 5421 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:617*//*624:*/
#line 5447 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:624*//*712:*/
#line 5922 "./marpa.w"
typedef gint Marpa_Earleme;
/*:712*//*714:*/
#line 5926 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:714*//*743:*/
#line 6145 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:743*//*1025:*/
#line 9489 "./marpa.w"

typedef gint Marpa_Or_Node_ID;

/*:1025*//*1271:*/
#line 11922 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1271*/
#line 693 "./marpa.w"

/*211:*/
#line 1509 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:211*//*318:*/
#line 2280 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:318*//*1273:*/
#line 11929 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1273*//*1281:*/
#line 11964 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1281*/
#line 694 "./marpa.w"

/*112:*/
#line 999 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:112*//*113:*/
#line 1004 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:113*//*114:*/
#line 1009 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:114*/
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

/*:72*//*79:*/
#line 844 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:79*//*81:*/
#line 857 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:81*//*91:*/
#line 908 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:91*//*98:*/
#line 926 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:98*//*102:*/
#line 941 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:102*//*104:*/
#line 956 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:104*//*122:*/
#line 1066 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:122*//*131:*/
#line 1115 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:131*//*139:*/
#line 1158 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:139*//*149:*/
#line 1200 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:149*//*156:*/
#line 1230 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:156*//*162:*/
#line 1253 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:162*//*164:*/
#line 1260 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:164*//*168:*/
#line 1279 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:168*//*172:*/
#line 1297 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:172*//*174:*/
#line 1304 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:174*//*178:*/
#line 1325 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:178*//*180:*/
#line 1332 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:180*//*184:*/
#line 1353 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:184*//*186:*/
#line 1360 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:186*//*190:*/
#line 1379 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:190*//*192:*/
#line 1386 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:192*//*197:*/
#line 1406 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:197*//*203:*/
#line 1446 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:203*//*206:*/
#line 1474 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:206*//*215:*/
#line 1524 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:215*//*227:*/
#line 1638 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:227*//*241:*/
#line 1820 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:241*//*254:*/
#line 1981 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:254*//*258:*/
#line 1997 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:258*//*262:*/
#line 2009 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:262*//*270:*/
#line 2039 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:270*//*275:*/
#line 2084 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:275*//*279:*/
#line 2108 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:279*//*284:*/
#line 2128 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:284*//*289:*/
#line 2149 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:289*//*296:*/
#line 2184 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:296*//*300:*/
#line 2200 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:300*//*304:*/
#line 2226 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:304*//*308:*/
#line 2237 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:308*//*312:*/
#line 2253 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:312*//*316:*/
#line 2269 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:316*//*322:*/
#line 2291 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:322*//*324:*/
#line 2296 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:324*//*326:*/
#line 2301 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:326*//*333:*/
#line 2323 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:333*//*338:*/
#line 2337 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:338*//*343:*/
#line 2356 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:343*//*352:*/
#line 2432 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:352*//*467:*/
#line 3648 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:467*//*469:*/
#line 3659 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:469*//*470:*/
#line 3663 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:470*//*472:*/
#line 3675 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:472*//*474:*/
#line 3686 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:474*//*522:*/
#line 4103 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:522*//*524:*/
#line 4116 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:524*//*525:*/
#line 4119 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:525*//*528:*/
#line 4154 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:528*//*530:*/
#line 4164 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:530*//*535:*/
#line 4228 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:535*//*601:*/
#line 5293 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:601*//*604:*/
#line 5327 "./marpa.w"

/*:604*//*605:*/
#line 5328 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:605*//*611:*/
#line 5373 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:611*//*614:*/
#line 5406 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:614*//*621:*/
#line 5427 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:621*//*627:*/
#line 5461 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:627*//*633:*/
#line 5489 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:633*//*639:*/
#line 5511 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:639*//*641:*/
#line 5517 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:641*//*645:*/
#line 5538 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:645*//*664:*/
#line 5631 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:664*//*679:*/
#line 5739 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:679*//*682:*/
#line 5759 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:682*//*685:*/
#line 5778 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:685*//*699:*/
#line 5860 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:699*//*708:*/
#line 5896 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:708*//*729:*/
#line 6027 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:729*//*731:*/
#line 6042 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:731*//*733:*/
#line 6060 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:733*//*736:*/
#line 6085 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:736*//*766:*/
#line 6395 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:766*//*770:*/
#line 6468 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:770*//*773:*/
#line 6507 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:773*//*805:*/
#line 6852 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:805*//*808:*/
#line 6890 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:808*//*810:*/
#line 6923 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:810*//*849:*/
#line 7344 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:849*//*853:*/
#line 7389 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:853*//*856:*/
#line 7421 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:856*//*860:*/
#line 7465 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:860*//*863:*/
#line 7499 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:863*//*867:*/
#line 7546 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:867*//*873:*/
#line 7603 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:873*//*876:*/
#line 7640 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:876*//*879:*/
#line 7682 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:879*//*881:*/
#line 7721 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:881*//*900:*/
#line 7906 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:900*//*908:*/
#line 7990 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:908*//*926:*/
#line 8130 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:926*//*981:*/
#line 8909 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:981*//*1093:*/
#line 10291 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1093*//*1108:*/
#line 10501 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1108*//*1277:*/
#line 11944 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1277*//*1285:*/
#line 11981 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1285*/
#line 696 "./marpa.w"


/*:43*/
#line 12206 "./marpa.w"

#endif __MARPA_H__

/*:1303*/
