/*1286:*/
#line 11966 "./marpa.w"

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

/*:1286*//*1287:*/
#line 11990 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*42:*/
#line 654 "./marpa.w"

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
#line 963 "./marpa.w"

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
/*:110*//*265:*/
#line 2007 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:265*//*270:*/
#line 2040 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:270*/
#line 667 "./marpa.w"

/*43:*/
#line 675 "./marpa.w"
struct marpa_g;
/*:43*//*608:*/
#line 5334 "./marpa.w"

struct marpa_r;
/*:608*/
#line 668 "./marpa.w"

/*52:*/
#line 714 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:52*//*125:*/
#line 1077 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:125*//*131:*/
#line 1096 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:131*//*217:*/
#line 1517 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:217*//*451:*/
#line 3528 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:451*//*497:*/
#line 3906 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:497*//*617:*/
#line 5393 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:617*//*624:*/
#line 5419 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:624*//*712:*/
#line 5894 "./marpa.w"
typedef gint Marpa_Earleme;
/*:712*//*714:*/
#line 5898 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:714*//*743:*/
#line 6117 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:743*//*1038:*/
#line 9619 "./marpa.w"

typedef gint Marpa_Or_Node_ID;

/*:1038*//*1255:*/
#line 11713 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1255*/
#line 669 "./marpa.w"

/*210:*/
#line 1485 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:210*//*317:*/
#line 2256 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:317*//*1257:*/
#line 11720 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1257*//*1265:*/
#line 11755 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1265*/
#line 670 "./marpa.w"

/*111:*/
#line 975 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:111*//*112:*/
#line 980 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:112*//*113:*/
#line 985 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:113*/
#line 671 "./marpa.w"

/*41:*/
#line 646 "./marpa.w"

void marpa_version(int*version);

/*:41*//*47:*/
#line 691 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:47*//*49:*/
#line 699 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:49*//*56:*/
#line 720 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:56*//*61:*/
#line 742 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:61*//*71:*/
#line 789 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:71*//*78:*/
#line 820 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:78*//*80:*/
#line 833 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:80*//*90:*/
#line 884 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:90*//*97:*/
#line 902 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:97*//*101:*/
#line 917 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:101*//*103:*/
#line 932 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:103*//*121:*/
#line 1042 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:121*//*130:*/
#line 1091 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:130*//*138:*/
#line 1134 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:138*//*148:*/
#line 1176 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:148*//*155:*/
#line 1206 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:155*//*161:*/
#line 1229 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:161*//*163:*/
#line 1236 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:163*//*167:*/
#line 1255 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:167*//*171:*/
#line 1273 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:171*//*173:*/
#line 1280 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:173*//*177:*/
#line 1301 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:177*//*179:*/
#line 1308 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:179*//*183:*/
#line 1329 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:183*//*185:*/
#line 1336 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:185*//*189:*/
#line 1355 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:189*//*191:*/
#line 1362 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:191*//*196:*/
#line 1382 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:196*//*202:*/
#line 1422 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:202*//*205:*/
#line 1450 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:205*//*214:*/
#line 1500 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:214*//*226:*/
#line 1614 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:226*//*240:*/
#line 1796 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:240*//*253:*/
#line 1957 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:253*//*257:*/
#line 1973 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:257*//*261:*/
#line 1985 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:261*//*269:*/
#line 2015 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:269*//*274:*/
#line 2060 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:274*//*278:*/
#line 2084 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:278*//*283:*/
#line 2104 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:283*//*288:*/
#line 2125 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:288*//*295:*/
#line 2160 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:295*//*299:*/
#line 2176 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:299*//*303:*/
#line 2202 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:303*//*307:*/
#line 2213 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:307*//*311:*/
#line 2229 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:311*//*315:*/
#line 2245 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:315*//*321:*/
#line 2267 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:321*//*323:*/
#line 2272 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:323*//*325:*/
#line 2277 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:325*//*332:*/
#line 2299 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:332*//*337:*/
#line 2313 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:337*//*342:*/
#line 2332 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:342*//*352:*/
#line 2404 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:352*//*467:*/
#line 3620 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:467*//*469:*/
#line 3631 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:469*//*470:*/
#line 3635 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:470*//*472:*/
#line 3647 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:472*//*474:*/
#line 3658 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:474*//*522:*/
#line 4075 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:522*//*524:*/
#line 4088 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:524*//*525:*/
#line 4091 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:525*//*528:*/
#line 4126 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:528*//*530:*/
#line 4136 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:530*//*535:*/
#line 4200 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:535*//*601:*/
#line 5265 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:601*//*604:*/
#line 5299 "./marpa.w"

/*:604*//*605:*/
#line 5300 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:605*//*611:*/
#line 5345 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:611*//*614:*/
#line 5378 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:614*//*621:*/
#line 5399 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:621*//*627:*/
#line 5433 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:627*//*633:*/
#line 5461 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:633*//*639:*/
#line 5483 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:639*//*641:*/
#line 5489 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:641*//*645:*/
#line 5510 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:645*//*664:*/
#line 5603 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:664*//*679:*/
#line 5711 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:679*//*682:*/
#line 5731 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:682*//*685:*/
#line 5750 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:685*//*699:*/
#line 5832 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:699*//*708:*/
#line 5868 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:708*//*729:*/
#line 5999 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:729*//*731:*/
#line 6014 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:731*//*733:*/
#line 6032 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:733*//*736:*/
#line 6057 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:736*//*766:*/
#line 6367 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:766*//*770:*/
#line 6440 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:770*//*773:*/
#line 6479 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:773*//*805:*/
#line 6824 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:805*//*808:*/
#line 6862 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:808*//*810:*/
#line 6895 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:810*//*849:*/
#line 7316 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:849*//*853:*/
#line 7361 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:853*//*856:*/
#line 7393 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:856*//*860:*/
#line 7437 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:860*//*863:*/
#line 7471 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:863*//*867:*/
#line 7518 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:867*//*873:*/
#line 7575 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:873*//*876:*/
#line 7612 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:876*//*879:*/
#line 7654 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:879*//*881:*/
#line 7693 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:881*//*900:*/
#line 7878 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:900*//*908:*/
#line 7962 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:908*//*926:*/
#line 8102 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:926*//*981:*/
#line 8881 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:981*//*1077:*/
#line 10084 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1077*//*1092:*/
#line 10293 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1092*//*1261:*/
#line 11735 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1261*//*1269:*/
#line 11772 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1269*/
#line 672 "./marpa.w"


/*:42*/
#line 11995 "./marpa.w"

#endif __MARPA_H__

/*:1287*/
