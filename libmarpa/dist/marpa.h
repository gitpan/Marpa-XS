/*1394:*/
#line 13200 "./marpa.w"

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

/*:1394*//*1395:*/
#line 13224 "./marpa.w"

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
#line 2029 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:266*//*271:*/
#line 2062 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:271*/
#line 691 "./marpa.w"

/*44:*/
#line 699 "./marpa.w"
struct marpa_g;
/*:44*//*609:*/
#line 5376 "./marpa.w"

struct marpa_r;
/*:609*/
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
#line 1540 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:218*//*452:*/
#line 3560 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:452*//*498:*/
#line 3948 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:498*//*618:*/
#line 5434 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:618*//*625:*/
#line 5460 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:625*//*713:*/
#line 5935 "./marpa.w"
typedef gint Marpa_Earleme;
/*:713*//*715:*/
#line 5939 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:715*//*745:*/
#line 6159 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:745*//*1014:*/
#line 9283 "./marpa.w"

typedef gint Marpa_Or_Node_ID;
/*:1014*//*1078:*/
#line 10204 "./marpa.w"

typedef gint Marpa_And_Node_ID;
/*:1078*//*1184:*/
#line 11414 "./marpa.w"

typedef gint Marpa_Fork_ID;
/*:1184*//*1363:*/
#line 12944 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1363*/
#line 693 "./marpa.w"

/*211:*/
#line 1508 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:211*//*318:*/
#line 2278 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:318*//*1365:*/
#line 12951 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1365*//*1373:*/
#line 12986 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1373*/
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
#line 1352 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:184*//*186:*/
#line 1359 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:186*//*190:*/
#line 1378 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:190*//*192:*/
#line 1385 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:192*//*197:*/
#line 1405 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:197*//*203:*/
#line 1445 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:203*//*206:*/
#line 1473 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:206*//*215:*/
#line 1523 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:215*//*227:*/
#line 1637 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:227*//*241:*/
#line 1818 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:241*//*254:*/
#line 1979 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:254*//*258:*/
#line 1995 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:258*//*262:*/
#line 2007 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:262*//*270:*/
#line 2037 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:270*//*275:*/
#line 2082 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:275*//*279:*/
#line 2106 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:279*//*284:*/
#line 2126 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:284*//*289:*/
#line 2147 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:289*//*296:*/
#line 2182 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:296*//*300:*/
#line 2198 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:300*//*304:*/
#line 2224 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:304*//*308:*/
#line 2235 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:308*//*312:*/
#line 2251 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:312*//*316:*/
#line 2267 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:316*//*322:*/
#line 2289 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:322*//*324:*/
#line 2294 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:324*//*326:*/
#line 2299 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:326*//*333:*/
#line 2321 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:333*//*338:*/
#line 2335 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:338*//*343:*/
#line 2354 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:343*//*353:*/
#line 2436 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:353*//*468:*/
#line 3653 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:468*//*470:*/
#line 3664 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:470*//*471:*/
#line 3668 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:471*//*473:*/
#line 3680 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:473*//*475:*/
#line 3691 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:475*//*523:*/
#line 4117 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:523*//*525:*/
#line 4130 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:525*//*526:*/
#line 4133 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:526*//*529:*/
#line 4168 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:529*//*531:*/
#line 4178 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:531*//*536:*/
#line 4242 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:536*//*602:*/
#line 5307 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:602*//*605:*/
#line 5341 "./marpa.w"

/*:605*//*606:*/
#line 5342 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:606*//*612:*/
#line 5387 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:612*//*615:*/
#line 5419 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:615*//*622:*/
#line 5440 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:622*//*628:*/
#line 5474 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:628*//*634:*/
#line 5502 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:634*//*640:*/
#line 5524 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:640*//*642:*/
#line 5530 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:642*//*646:*/
#line 5551 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:646*//*665:*/
#line 5644 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:665*//*680:*/
#line 5752 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:680*//*683:*/
#line 5772 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:683*//*686:*/
#line 5791 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:686*//*700:*/
#line 5873 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:700*//*709:*/
#line 5909 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:709*//*731:*/
#line 6041 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:731*//*733:*/
#line 6056 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:733*//*735:*/
#line 6074 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:735*//*738:*/
#line 6099 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:738*//*767:*/
#line 6395 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:767*//*771:*/
#line 6468 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:771*//*774:*/
#line 6507 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:774*//*806:*/
#line 6852 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:806*//*809:*/
#line 6890 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:809*//*811:*/
#line 6923 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:811*//*850:*/
#line 7332 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:850*//*854:*/
#line 7377 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:854*//*857:*/
#line 7409 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:857*//*861:*/
#line 7453 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:861*//*864:*/
#line 7487 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:864*//*868:*/
#line 7534 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:868*//*874:*/
#line 7591 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:874*//*877:*/
#line 7628 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:877*//*880:*/
#line 7670 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:880*//*899:*/
#line 7864 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:899*//*907:*/
#line 7948 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gint length);
/*:907*//*925:*/
#line 8089 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:925*//*1105:*/
#line 10407 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1105*//*1121:*/
#line 10652 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1121*//*1162:*/
#line 11105 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r);
/*:1162*//*1176:*/
#line 11226 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length);
/*:1176*//*1182:*/
#line 11356 "./marpa.w"

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix);
/*:1182*//*1369:*/
#line 12966 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1369*//*1377:*/
#line 13003 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1377*/
#line 696 "./marpa.w"


/*:43*/
#line 13229 "./marpa.w"

#endif __MARPA_H__

/*:1395*/
