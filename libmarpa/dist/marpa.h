/*1286:*/
#line 11884 "./marpa.w"

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
#line 11908 "./marpa.w"

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
/*112:*/
#line 970 "./marpa.w"

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
/*:112*//*267:*/
#line 2014 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:267*//*272:*/
#line 2047 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:272*/
#line 667 "./marpa.w"

/*43:*/
#line 675 "./marpa.w"
struct marpa_g;
/*:43*//*609:*/
#line 5326 "./marpa.w"

struct marpa_r;
/*:609*/
#line 668 "./marpa.w"

/*52:*/
#line 714 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:52*//*127:*/
#line 1084 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:127*//*133:*/
#line 1103 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:133*//*219:*/
#line 1524 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:219*//*453:*/
#line 3535 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:453*//*499:*/
#line 3910 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:499*//*618:*/
#line 5384 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:618*//*625:*/
#line 5410 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:625*//*713:*/
#line 5886 "./marpa.w"
typedef gint Marpa_Earleme;
/*:713*//*715:*/
#line 5890 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:715*//*744:*/
#line 6109 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:744*//*1021:*/
#line 9177 "./marpa.w"

typedef gint Marpa_Or_Node_ID;

/*:1021*//*1255:*/
#line 11631 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1255*/
#line 669 "./marpa.w"

/*212:*/
#line 1492 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:212*//*319:*/
#line 2263 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:319*//*1257:*/
#line 11638 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1257*//*1265:*/
#line 11673 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1265*/
#line 670 "./marpa.w"

/*113:*/
#line 982 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:113*//*114:*/
#line 987 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:114*//*115:*/
#line 992 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:115*/
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
#line 788 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:71*//*80:*/
#line 827 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:80*//*82:*/
#line 840 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:82*//*92:*/
#line 891 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:92*//*99:*/
#line 909 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:99*//*103:*/
#line 924 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:103*//*105:*/
#line 939 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:105*//*123:*/
#line 1049 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:123*//*132:*/
#line 1098 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:132*//*140:*/
#line 1141 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:140*//*150:*/
#line 1183 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:150*//*157:*/
#line 1213 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:157*//*163:*/
#line 1236 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:163*//*165:*/
#line 1243 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:165*//*169:*/
#line 1262 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:169*//*173:*/
#line 1280 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:173*//*175:*/
#line 1287 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:175*//*179:*/
#line 1308 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:179*//*181:*/
#line 1315 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:181*//*185:*/
#line 1336 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:185*//*187:*/
#line 1343 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:187*//*191:*/
#line 1362 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:191*//*193:*/
#line 1369 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:193*//*198:*/
#line 1389 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:198*//*204:*/
#line 1429 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:204*//*207:*/
#line 1457 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:207*//*216:*/
#line 1507 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:216*//*228:*/
#line 1621 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:228*//*242:*/
#line 1803 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:242*//*255:*/
#line 1964 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:255*//*259:*/
#line 1980 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:259*//*263:*/
#line 1992 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:263*//*271:*/
#line 2022 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:271*//*276:*/
#line 2067 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:276*//*280:*/
#line 2091 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:280*//*285:*/
#line 2111 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:285*//*290:*/
#line 2132 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:290*//*297:*/
#line 2167 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:297*//*301:*/
#line 2183 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:301*//*305:*/
#line 2209 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:305*//*309:*/
#line 2220 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:309*//*313:*/
#line 2236 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:313*//*317:*/
#line 2252 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:317*//*323:*/
#line 2274 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:323*//*325:*/
#line 2279 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:325*//*327:*/
#line 2284 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:327*//*334:*/
#line 2306 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:334*//*339:*/
#line 2320 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:339*//*344:*/
#line 2339 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:344*//*354:*/
#line 2411 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:354*//*469:*/
#line 3627 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:469*//*471:*/
#line 3638 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:471*//*473:*/
#line 3649 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:473*//*475:*/
#line 3660 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:475*//*477:*/
#line 3670 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:477*//*524:*/
#line 4079 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:524*//*526:*/
#line 4092 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:526*//*527:*/
#line 4095 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:527*//*530:*/
#line 4130 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:530*//*532:*/
#line 4140 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:532*//*537:*/
#line 4204 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:537*//*602:*/
#line 5257 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:602*//*605:*/
#line 5291 "./marpa.w"

/*:605*//*606:*/
#line 5292 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:606*//*612:*/
#line 5337 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:612*//*615:*/
#line 5369 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:615*//*622:*/
#line 5390 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:622*//*628:*/
#line 5425 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:628*//*634:*/
#line 5453 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:634*//*640:*/
#line 5475 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:640*//*642:*/
#line 5481 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:642*//*646:*/
#line 5502 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:646*//*665:*/
#line 5595 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:665*//*680:*/
#line 5703 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:680*//*683:*/
#line 5723 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:683*//*686:*/
#line 5742 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:686*//*700:*/
#line 5824 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:700*//*709:*/
#line 5860 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:709*//*730:*/
#line 5991 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:730*//*732:*/
#line 6006 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:732*//*734:*/
#line 6024 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:734*//*737:*/
#line 6049 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:737*//*767:*/
#line 6359 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:767*//*771:*/
#line 6432 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:771*//*774:*/
#line 6471 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:774*//*806:*/
#line 6817 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:806*//*809:*/
#line 6855 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:809*//*811:*/
#line 6888 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:811*//*850:*/
#line 7309 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:850*//*854:*/
#line 7354 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:854*//*857:*/
#line 7386 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:857*//*861:*/
#line 7430 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:861*//*864:*/
#line 7464 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:864*//*868:*/
#line 7511 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:868*//*874:*/
#line 7568 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:874*//*877:*/
#line 7605 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:877*//*880:*/
#line 7647 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:880*//*882:*/
#line 7686 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:882*//*901:*/
#line 7871 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:901*//*909:*/
#line 7955 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:909*//*927:*/
#line 8095 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:927*//*982:*/
#line 8874 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:982*//*1050:*/
#line 9337 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1050*//*1093:*/
#line 10222 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1093*//*1261:*/
#line 11653 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1261*//*1269:*/
#line 11690 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1269*/
#line 672 "./marpa.w"


/*:42*/
#line 11913 "./marpa.w"

#endif __MARPA_H__

/*:1287*/
