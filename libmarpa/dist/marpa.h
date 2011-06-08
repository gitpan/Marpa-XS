/*1266:*/
#line 11507 "./marpa.w"

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

/*:1266*//*1267:*/
#line 11531 "./marpa.w"

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
/*:41*//*610:*/
#line 5319 "./marpa.w"

struct marpa_r;
/*:610*/
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
/*:217*//*454:*/
#line 3527 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:454*//*500:*/
#line 3902 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:500*//*619:*/
#line 5377 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:619*//*626:*/
#line 5403 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:626*//*714:*/
#line 5879 "./marpa.w"
typedef gint Marpa_Earleme;
/*:714*//*716:*/
#line 5883 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:716*//*745:*/
#line 6102 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:745*//*1237:*/
#line 11296 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1237*/
#line 656 "./marpa.w"

/*210:*/
#line 1478 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:210*//*320:*/
#line 2256 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:320*//*1239:*/
#line 11303 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1239*//*1247:*/
#line 11338 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1247*/
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
/*:345*//*355:*/
#line 2403 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:355*//*470:*/
#line 3619 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:470*//*472:*/
#line 3630 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:472*//*474:*/
#line 3641 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:474*//*476:*/
#line 3652 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:476*//*478:*/
#line 3662 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:478*//*525:*/
#line 4071 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:525*//*527:*/
#line 4084 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:527*//*528:*/
#line 4087 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:528*//*531:*/
#line 4122 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:531*//*533:*/
#line 4132 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:533*//*538:*/
#line 4196 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:538*//*603:*/
#line 5250 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:603*//*606:*/
#line 5284 "./marpa.w"

/*:606*//*607:*/
#line 5285 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:607*//*613:*/
#line 5330 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:613*//*616:*/
#line 5362 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:616*//*623:*/
#line 5383 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:623*//*629:*/
#line 5418 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:629*//*635:*/
#line 5446 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:635*//*641:*/
#line 5468 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:641*//*643:*/
#line 5474 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:643*//*647:*/
#line 5495 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:647*//*666:*/
#line 5588 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:666*//*681:*/
#line 5696 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:681*//*684:*/
#line 5716 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:684*//*687:*/
#line 5735 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:687*//*701:*/
#line 5817 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:701*//*710:*/
#line 5853 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:710*//*731:*/
#line 5984 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:731*//*733:*/
#line 5999 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:733*//*735:*/
#line 6017 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:735*//*738:*/
#line 6042 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:738*//*768:*/
#line 6349 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:768*//*772:*/
#line 6422 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:772*//*775:*/
#line 6461 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:775*//*807:*/
#line 6807 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:807*//*810:*/
#line 6845 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:810*//*812:*/
#line 6878 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:812*//*851:*/
#line 7299 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:851*//*855:*/
#line 7344 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:855*//*858:*/
#line 7376 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:858*//*862:*/
#line 7420 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:862*//*865:*/
#line 7454 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:865*//*869:*/
#line 7501 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:869*//*875:*/
#line 7558 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:875*//*878:*/
#line 7595 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:878*//*881:*/
#line 7637 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:881*//*883:*/
#line 7676 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:883*//*902:*/
#line 7861 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:902*//*910:*/
#line 7945 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:910*//*928:*/
#line 8085 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:928*//*983:*/
#line 8863 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:983*//*1047:*/
#line 9321 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1047*//*1075:*/
#line 9906 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1075*//*1243:*/
#line 11318 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1243*//*1251:*/
#line 11355 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1251*/
#line 659 "./marpa.w"


/*:40*/
#line 11536 "./marpa.w"

#endif __MARPA_H__

/*:1267*/
