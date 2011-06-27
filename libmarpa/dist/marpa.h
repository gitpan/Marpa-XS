/*1284:*/
#line 11896 "./marpa.w"

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

/*:1284*//*1285:*/
#line 11920 "./marpa.w"

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
/*:43*//*607:*/
#line 5319 "./marpa.w"

struct marpa_r;
/*:607*/
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
#line 3903 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:497*//*616:*/
#line 5378 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:616*//*623:*/
#line 5404 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:623*//*711:*/
#line 5879 "./marpa.w"
typedef gint Marpa_Earleme;
/*:711*//*713:*/
#line 5883 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:713*//*742:*/
#line 6102 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:742*//*1019:*/
#line 9170 "./marpa.w"

typedef gint Marpa_Or_Node_ID;

/*:1019*//*1253:*/
#line 11643 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1253*/
#line 669 "./marpa.w"

/*210:*/
#line 1485 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:210*//*317:*/
#line 2256 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:317*//*1255:*/
#line 11650 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1255*//*1263:*/
#line 11685 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1263*/
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
/*:469*//*471:*/
#line 3642 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:471*//*473:*/
#line 3653 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:473*//*475:*/
#line 3663 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:475*//*522:*/
#line 4072 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:522*//*524:*/
#line 4085 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:524*//*525:*/
#line 4088 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:525*//*528:*/
#line 4123 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:528*//*530:*/
#line 4133 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:530*//*535:*/
#line 4197 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:535*//*600:*/
#line 5250 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:600*//*603:*/
#line 5284 "./marpa.w"

/*:603*//*604:*/
#line 5285 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:604*//*610:*/
#line 5330 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:610*//*613:*/
#line 5363 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:613*//*620:*/
#line 5384 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:620*//*626:*/
#line 5418 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:626*//*632:*/
#line 5446 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:632*//*638:*/
#line 5468 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:638*//*640:*/
#line 5474 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:640*//*644:*/
#line 5495 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:644*//*663:*/
#line 5588 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:663*//*678:*/
#line 5696 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:678*//*681:*/
#line 5716 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:681*//*684:*/
#line 5735 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:684*//*698:*/
#line 5817 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:698*//*707:*/
#line 5853 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:707*//*728:*/
#line 5984 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:728*//*730:*/
#line 5999 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:730*//*732:*/
#line 6017 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:732*//*735:*/
#line 6042 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:735*//*765:*/
#line 6352 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:765*//*769:*/
#line 6425 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:769*//*772:*/
#line 6464 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:772*//*804:*/
#line 6810 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:804*//*807:*/
#line 6848 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:807*//*809:*/
#line 6881 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:809*//*848:*/
#line 7302 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:848*//*852:*/
#line 7347 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:852*//*855:*/
#line 7379 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:855*//*859:*/
#line 7423 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:859*//*862:*/
#line 7457 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:862*//*866:*/
#line 7504 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:866*//*872:*/
#line 7561 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:872*//*875:*/
#line 7598 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:875*//*878:*/
#line 7640 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:878*//*880:*/
#line 7679 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:880*//*899:*/
#line 7864 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:899*//*907:*/
#line 7948 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:907*//*925:*/
#line 8088 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:925*//*980:*/
#line 8867 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:980*//*1048:*/
#line 9331 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1048*//*1091:*/
#line 10230 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1091*//*1259:*/
#line 11665 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1259*//*1267:*/
#line 11702 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1267*/
#line 672 "./marpa.w"


/*:42*/
#line 11925 "./marpa.w"

#endif __MARPA_H__

/*:1285*/
