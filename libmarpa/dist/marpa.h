/*1115:*/
#line 9963 "./marpa.w"

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

/*:1115*//*1116:*/
#line 9987 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*27:*/
#line 589 "./marpa.w"

/*:27*//*32:*/
#line 611 "./marpa.w"

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
#line 1002 "./marpa.w"

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
#line 2037 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:268*//*273:*/
#line 2070 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:273*/
#line 624 "./marpa.w"

/*41:*/
#line 704 "./marpa.w"
struct marpa_g;
/*:41*//*566:*/
#line 4945 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*RECCE;
/*:566*/
#line 625 "./marpa.w"

/*50:*/
#line 743 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:50*//*125:*/
#line 1116 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:125*//*131:*/
#line 1134 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:131*//*215:*/
#line 1558 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:215*//*442:*/
#line 3491 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:442*//*483:*/
#line 3795 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:483*//*574:*/
#line 5002 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:574*//*581:*/
#line 5018 "./marpa.w"

enum enum_phase{
no_such_phase= 0,
initial_phase,
active_phase,
exhausted_phase,
finished_phase,
error_phase
};
typedef enum enum_phase Marpa_Phase;
/*:581*//*663:*/
#line 5480 "./marpa.w"
typedef gint Marpa_Earleme;
/*:663*//*1086:*/
#line 9769 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1086*/
#line 626 "./marpa.w"

/*208:*/
#line 1528 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:208*//*320:*/
#line 2281 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:320*//*1088:*/
#line 9776 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1088*//*1096:*/
#line 9811 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1096*/
#line 627 "./marpa.w"

/*111:*/
#line 1014 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:111*//*112:*/
#line 1019 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:112*//*113:*/
#line 1024 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:113*/
#line 628 "./marpa.w"

/*31:*/
#line 604 "./marpa.w"

void marpa_version(int*version);

/*:31*//*45:*/
#line 720 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:45*//*47:*/
#line 728 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:47*//*54:*/
#line 749 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:54*//*59:*/
#line 771 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:59*//*69:*/
#line 817 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:69*//*80:*/
#line 869 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:80*//*82:*/
#line 882 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:82*//*90:*/
#line 923 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:90*//*97:*/
#line 941 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:97*//*101:*/
#line 956 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:101*//*103:*/
#line 971 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:103*//*121:*/
#line 1081 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:121*//*130:*/
#line 1130 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:130*//*136:*/
#line 1165 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:136*//*146:*/
#line 1205 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:146*//*153:*/
#line 1234 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:153*//*159:*/
#line 1257 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:159*//*161:*/
#line 1264 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:161*//*165:*/
#line 1283 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:165*//*169:*/
#line 1301 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:169*//*171:*/
#line 1308 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:171*//*175:*/
#line 1328 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:175*//*177:*/
#line 1335 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:177*//*181:*/
#line 1356 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:181*//*183:*/
#line 1363 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:183*//*187:*/
#line 1382 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:187*//*189:*/
#line 1389 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:189*//*194:*/
#line 1409 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:194*//*200:*/
#line 1449 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:200*//*203:*/
#line 1477 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:203*//*206:*/
#line 1518 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symid);

/*:206*//*212:*/
#line 1543 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:212*//*226:*/
#line 1653 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:226*//*240:*/
#line 1834 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:240*//*253:*/
#line 1980 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:253*//*257:*/
#line 1996 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:257*//*261:*/
#line 2008 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:261*//*272:*/
#line 2045 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:272*//*277:*/
#line 2090 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:277*//*281:*/
#line 2114 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:281*//*286:*/
#line 2134 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:286*//*291:*/
#line 2155 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:291*//*298:*/
#line 2185 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:298*//*302:*/
#line 2201 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:302*//*306:*/
#line 2227 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:306*//*310:*/
#line 2238 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:310*//*314:*/
#line 2254 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:314*//*318:*/
#line 2270 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:318*//*324:*/
#line 2292 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:324*//*326:*/
#line 2297 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:326*//*328:*/
#line 2302 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:328*//*335:*/
#line 2323 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:335*//*340:*/
#line 2337 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:340*//*344:*/
#line 2358 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:344*//*346:*/
#line 2384 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:346*//*455:*/
#line 3557 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:455*//*457:*/
#line 3568 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:457*//*459:*/
#line 3579 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:459*//*461:*/
#line 3590 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:461*//*463:*/
#line 3600 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:463*//*501:*/
#line 3914 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:501*//*503:*/
#line 3927 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:503*//*505:*/
#line 3948 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:505*//*511:*/
#line 3983 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:511*//*515:*/
#line 4032 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:515*//*517:*/
#line 4046 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:517*//*519:*/
#line 4056 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:519*//*523:*/
#line 4115 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:523*//*568:*/
#line 4955 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:568*//*571:*/
#line 4987 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:571*//*578:*/
#line 5008 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:578*//*584:*/
#line 5032 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:584*//*590:*/
#line 5062 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:590*//*596:*/
#line 5084 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:596*//*598:*/
#line 5090 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:598*//*602:*/
#line 5111 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:602*//*619:*/
#line 5209 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:619*//*634:*/
#line 5323 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:634*//*637:*/
#line 5343 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:637*//*650:*/
#line 5418 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:650*//*659:*/
#line 5454 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:659*//*680:*/
#line 5610 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earleme id);
/*:680*//*683:*/
#line 5633 "./marpa.w"

Marpa_Earleme marpa_trace_earleme(struct marpa_r*r);
/*:683*//*685:*/
#line 5651 "./marpa.w"

gint marpa_current_earley_set_size(struct marpa_r*r);
/*:685*//*716:*/
#line 5941 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earleme origin_id,
Marpa_AHFA_State_ID state_id);
/*:716*//*718:*/
#line 5991 "./marpa.w"

Marpa_AHFA_State_ID
marpa_first_earley_item_trace(struct marpa_r*r);
/*:718*//*720:*/
#line 6025 "./marpa.w"

Marpa_AHFA_State_ID
marpa_next_earley_item_trace(struct marpa_r*r);
/*:720*//*750:*/
#line 6352 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:750*//*753:*/
#line 6390 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:753*//*755:*/
#line 6423 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:755*//*794:*/
#line 6844 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:794*//*798:*/
#line 6889 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:798*//*801:*/
#line 6921 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:801*//*805:*/
#line 6965 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:805*//*808:*/
#line 6999 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:808*//*812:*/
#line 7046 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:812*//*818:*/
#line 7103 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:818*//*821:*/
#line 7140 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:821*//*824:*/
#line 7182 "./marpa.w"

Marpa_Earleme marpa_source_middle(struct marpa_r*r);
/*:824*//*826:*/
#line 7221 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:826*//*845:*/
#line 7408 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:845*//*853:*/
#line 7491 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:853*//*864:*/
#line 7609 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:864*//*915:*/
#line 8325 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:915*//*1092:*/
#line 9791 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1092*//*1100:*/
#line 9828 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1100*/
#line 629 "./marpa.w"


/*:32*/
#line 9992 "./marpa.w"

#endif __MARPA_H__

/*:1116*/
