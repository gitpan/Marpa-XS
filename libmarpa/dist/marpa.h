/*1250:*/
#line 11299 "./marpa.w"

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

/*:1250*//*1251:*/
#line 11323 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*40:*/
#line 641 "./marpa.w"

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
#line 957 "./marpa.w"

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
/*:110*//*268:*/
#line 2007 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:268*//*273:*/
#line 2040 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:273*/
#line 654 "./marpa.w"

/*41:*/
#line 662 "./marpa.w"
struct marpa_g;
/*:41*//*606:*/
#line 5291 "./marpa.w"

struct marpa_r;
/*:606*/
#line 655 "./marpa.w"

/*50:*/
#line 701 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:50*//*125:*/
#line 1071 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:125*//*131:*/
#line 1090 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:131*//*217:*/
#line 1510 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:217*//*450:*/
#line 3499 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:450*//*496:*/
#line 3874 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:496*//*615:*/
#line 5349 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:615*//*622:*/
#line 5375 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:622*//*710:*/
#line 5851 "./marpa.w"
typedef gint Marpa_Earleme;
/*:710*//*712:*/
#line 5855 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:712*//*741:*/
#line 6074 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:741*//*1221:*/
#line 11105 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1221*/
#line 656 "./marpa.w"

/*210:*/
#line 1478 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:210*//*320:*/
#line 2256 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:320*//*1223:*/
#line 11112 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1223*//*1231:*/
#line 11147 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1231*/
#line 657 "./marpa.w"

/*111:*/
#line 969 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:111*//*112:*/
#line 974 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:112*//*113:*/
#line 979 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:113*/
#line 658 "./marpa.w"

/*39:*/
#line 633 "./marpa.w"

void marpa_version(int*version);

/*:39*//*45:*/
#line 678 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:45*//*47:*/
#line 686 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:47*//*54:*/
#line 707 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:54*//*59:*/
#line 729 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:59*//*69:*/
#line 775 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:69*//*78:*/
#line 814 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:78*//*80:*/
#line 827 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:80*//*90:*/
#line 878 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:90*//*97:*/
#line 896 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:97*//*101:*/
#line 911 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:101*//*103:*/
#line 926 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:103*//*121:*/
#line 1036 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:121*//*130:*/
#line 1085 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:130*//*138:*/
#line 1128 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:138*//*148:*/
#line 1170 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:148*//*155:*/
#line 1200 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:155*//*161:*/
#line 1223 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:161*//*163:*/
#line 1230 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:163*//*167:*/
#line 1249 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:167*//*171:*/
#line 1267 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:171*//*173:*/
#line 1274 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:173*//*177:*/
#line 1294 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:177*//*179:*/
#line 1301 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:179*//*183:*/
#line 1322 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:183*//*185:*/
#line 1329 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:185*//*189:*/
#line 1348 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:189*//*191:*/
#line 1355 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:191*//*196:*/
#line 1375 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:196*//*202:*/
#line 1415 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:202*//*205:*/
#line 1443 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:205*//*214:*/
#line 1493 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:214*//*226:*/
#line 1607 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:226*//*240:*/
#line 1789 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:240*//*253:*/
#line 1950 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:253*//*257:*/
#line 1966 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:257*//*261:*/
#line 1978 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:261*//*272:*/
#line 2015 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:272*//*277:*/
#line 2060 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:277*//*281:*/
#line 2084 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:281*//*286:*/
#line 2104 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:286*//*291:*/
#line 2125 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:291*//*298:*/
#line 2160 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:298*//*302:*/
#line 2176 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:302*//*306:*/
#line 2202 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:306*//*310:*/
#line 2213 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:310*//*314:*/
#line 2229 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:314*//*318:*/
#line 2245 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:318*//*324:*/
#line 2267 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:324*//*326:*/
#line 2272 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:326*//*328:*/
#line 2277 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:328*//*335:*/
#line 2299 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:335*//*340:*/
#line 2313 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:340*//*345:*/
#line 2332 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:345*//*351:*/
#line 2375 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:351*//*466:*/
#line 3591 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:466*//*468:*/
#line 3602 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:468*//*470:*/
#line 3613 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:470*//*472:*/
#line 3624 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:472*//*474:*/
#line 3634 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:474*//*521:*/
#line 4043 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:521*//*523:*/
#line 4056 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:523*//*524:*/
#line 4059 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:524*//*527:*/
#line 4094 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:527*//*529:*/
#line 4104 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:529*//*534:*/
#line 4168 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:534*//*599:*/
#line 5222 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:599*//*602:*/
#line 5256 "./marpa.w"

/*:602*//*603:*/
#line 5257 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:603*//*609:*/
#line 5302 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:609*//*612:*/
#line 5334 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:612*//*619:*/
#line 5355 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:619*//*625:*/
#line 5390 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:625*//*631:*/
#line 5418 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:631*//*637:*/
#line 5440 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:637*//*639:*/
#line 5446 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:639*//*643:*/
#line 5467 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:643*//*662:*/
#line 5560 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:662*//*677:*/
#line 5668 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:677*//*680:*/
#line 5688 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:680*//*683:*/
#line 5707 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:683*//*697:*/
#line 5789 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:697*//*706:*/
#line 5825 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:706*//*727:*/
#line 5956 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:727*//*729:*/
#line 5971 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:729*//*731:*/
#line 5989 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:731*//*734:*/
#line 6014 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:734*//*764:*/
#line 6322 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:764*//*768:*/
#line 6395 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:768*//*771:*/
#line 6434 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:771*//*803:*/
#line 6780 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:803*//*806:*/
#line 6818 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:806*//*808:*/
#line 6851 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:808*//*847:*/
#line 7272 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:847*//*851:*/
#line 7317 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:851*//*854:*/
#line 7349 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:854*//*858:*/
#line 7393 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:858*//*861:*/
#line 7427 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:861*//*865:*/
#line 7474 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:865*//*871:*/
#line 7531 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:871*//*874:*/
#line 7568 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:874*//*877:*/
#line 7610 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:877*//*879:*/
#line 7649 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:879*//*898:*/
#line 7834 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:898*//*906:*/
#line 7918 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:906*//*924:*/
#line 8058 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:924*//*979:*/
#line 8831 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:979*//*1035:*/
#line 9243 "./marpa.w"

gint marpa_eval_setup(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1035*//*1059:*/
#line 9719 "./marpa.w"

gint marpa_eval_clear(struct marpa_r*r);
/*:1059*//*1227:*/
#line 11127 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1227*//*1235:*/
#line 11164 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1235*/
#line 659 "./marpa.w"


/*:40*/
#line 11328 "./marpa.w"

#endif __MARPA_H__

/*:1251*/
