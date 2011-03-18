/*1075:*/
#line 9593 "./marpa.w"

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

/*:1075*//*1076:*/
#line 9617 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*28:*/
#line 557 "./marpa.w"

/*:28*//*33:*/
#line 579 "./marpa.w"

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
#line 973 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:110*//*266:*/
#line 1998 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:266*//*271:*/
#line 2031 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:271*/
#line 592 "./marpa.w"

/*42:*/
#line 672 "./marpa.w"
struct marpa_g;
/*:42*//*566:*/
#line 4941 "./marpa.w"
struct marpa_r;
/*:566*/
#line 593 "./marpa.w"

/*51:*/
#line 711 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:51*//*125:*/
#line 1081 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:125*//*131:*/
#line 1099 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:131*//*213:*/
#line 1519 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:213*//*440:*/
#line 3452 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:440*//*481:*/
#line 3753 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:481*//*575:*/
#line 4992 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:575*//*582:*/
#line 5007 "./marpa.w"

enum enum_phase{
no_such_phase= 0,
initial_phase,
active_phase,
exhausted_phase,
finished_phase,
error_phase
};
typedef enum enum_phase Marpa_Phase;
/*:582*//*663:*/
#line 5428 "./marpa.w"
typedef gint Marpa_Earleme;

/*:663*//*1046:*/
#line 9402 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1046*/
#line 594 "./marpa.w"

/*206:*/
#line 1489 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:206*//*318:*/
#line 2242 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:318*//*1048:*/
#line 9409 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1048*//*1056:*/
#line 9444 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1056*/
#line 595 "./marpa.w"

/*111:*/
#line 981 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:111*//*112:*/
#line 986 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:112*//*113:*/
#line 991 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:113*//*511:*/
#line 3964 "./marpa.w"

struct marpa_AHFA_transition{
Marpa_Symbol_ID marpa_transition_symbol;
Marpa_AHFA_State_ID marpa_to_ahfa_state_id;
};

/*:511*/
#line 596 "./marpa.w"

/*32:*/
#line 572 "./marpa.w"

void marpa_version(int*version);

/*:32*//*46:*/
#line 688 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:46*//*48:*/
#line 696 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:48*//*55:*/
#line 717 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:55*//*60:*/
#line 739 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:60*//*70:*/
#line 785 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:70*//*81:*/
#line 837 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:81*//*83:*/
#line 854 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:83*//*93:*/
#line 902 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:93*//*97:*/
#line 913 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:97*//*101:*/
#line 928 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:101*//*103:*/
#line 943 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:103*//*121:*/
#line 1046 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:121*//*130:*/
#line 1095 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:130*//*135:*/
#line 1134 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:135*//*144:*/
#line 1166 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:144*//*151:*/
#line 1195 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:151*//*157:*/
#line 1218 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:157*//*159:*/
#line 1225 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:159*//*163:*/
#line 1244 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:163*//*167:*/
#line 1262 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:167*//*169:*/
#line 1269 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:169*//*173:*/
#line 1289 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:173*//*175:*/
#line 1296 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:175*//*179:*/
#line 1317 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:179*//*181:*/
#line 1324 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:181*//*185:*/
#line 1343 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:185*//*187:*/
#line 1350 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:187*//*192:*/
#line 1370 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:192*//*198:*/
#line 1410 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:198*//*201:*/
#line 1438 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:201*//*204:*/
#line 1479 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symid);

/*:204*//*210:*/
#line 1504 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:210*//*224:*/
#line 1614 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:224*//*238:*/
#line 1795 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:238*//*251:*/
#line 1941 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:251*//*255:*/
#line 1957 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:255*//*259:*/
#line 1969 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:259*//*270:*/
#line 2006 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:270*//*275:*/
#line 2051 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:275*//*279:*/
#line 2075 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:279*//*284:*/
#line 2095 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:284*//*289:*/
#line 2116 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:289*//*296:*/
#line 2146 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:296*//*300:*/
#line 2162 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:300*//*304:*/
#line 2188 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:304*//*308:*/
#line 2199 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:308*//*312:*/
#line 2215 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:312*//*316:*/
#line 2231 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:316*//*322:*/
#line 2253 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:322*//*324:*/
#line 2258 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:324*//*326:*/
#line 2263 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:326*//*333:*/
#line 2284 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:333*//*338:*/
#line 2298 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:338*//*342:*/
#line 2319 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:342*//*344:*/
#line 2345 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:344*//*453:*/
#line 3515 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:453*//*455:*/
#line 3526 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:455*//*457:*/
#line 3537 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:457*//*459:*/
#line 3548 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:459*//*461:*/
#line 3558 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:461*//*499:*/
#line 3872 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:499*//*501:*/
#line 3885 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:501*//*503:*/
#line 3906 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:503*//*505:*/
#line 3929 "./marpa.w"

gint marpa_AHFA_state_transition_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:505*//*513:*/
#line 4000 "./marpa.w"

struct marpa_AHFA_transition*marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
struct marpa_AHFA_transition*buffer);

/*:513*//*516:*/
#line 4023 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:516*//*518:*/
#line 4037 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:518*//*520:*/
#line 4047 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:520*//*524:*/
#line 4106 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:524*//*570:*/
#line 4964 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);

/*:570*//*572:*/
#line 4977 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:572*//*579:*/
#line 4998 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:579*//*585:*/
#line 5021 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:585*//*591:*/
#line 5046 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:591*//*595:*/
#line 5057 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:595*//*597:*/
#line 5063 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:597*//*601:*/
#line 5084 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:601*//*620:*/
#line 5183 "./marpa.w"

gboolean marpa_is_trace_earley_sets(struct marpa_r*r);
/*:620*//*623:*/
#line 5203 "./marpa.w"

gboolean marpa_is_trace_earley_sets_set(struct marpa_r*r,gboolean value);

/*:623*//*634:*/
#line 5272 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:634*//*637:*/
#line 5292 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:637*//*650:*/
#line 5366 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:650*//*659:*/
#line 5402 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:659*//*685:*/
#line 5620 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earleme id);
/*:685*//*688:*/
#line 5649 "./marpa.w"

Marpa_Earleme marpa_trace_earleme(struct marpa_r*r);
/*:688*//*690:*/
#line 5667 "./marpa.w"

gint marpa_current_earley_set_size(struct marpa_r*r);
/*:690*//*720:*/
#line 5924 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earleme origin_id,
Marpa_AHFA_State_ID state_id);
/*:720*//*722:*/
#line 5978 "./marpa.w"

Marpa_AHFA_State_ID
marpa_first_earley_item_trace(struct marpa_r*r);
/*:722*//*724:*/
#line 6015 "./marpa.w"

Marpa_AHFA_State_ID
marpa_next_earley_item_trace(struct marpa_r*r);
/*:724*//*750:*/
#line 6305 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:750*//*753:*/
#line 6343 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:753*//*755:*/
#line 6376 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:755*//*794:*/
#line 6797 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:794*//*798:*/
#line 6842 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:798*//*801:*/
#line 6874 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:801*//*805:*/
#line 6918 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:805*//*808:*/
#line 6952 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:808*//*812:*/
#line 6999 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:812*//*818:*/
#line 7056 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:818*//*821:*/
#line 7093 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:821*//*824:*/
#line 7135 "./marpa.w"

Marpa_Earleme marpa_source_middle(struct marpa_r*r);
/*:824*//*826:*/
#line 7174 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:826*//*830:*/
#line 7235 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);

/*:830*//*837:*/
#line 7285 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);

/*:837*//*861:*/
#line 7553 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);

/*:861*//*907:*/
#line 8199 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:907*//*1052:*/
#line 9424 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1052*//*1060:*/
#line 9459 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1060*/
#line 597 "./marpa.w"


/*:33*/
#line 9622 "./marpa.w"

#endif __MARPA_H__

/*:1076*/
