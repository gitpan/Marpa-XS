/*1274:*/
#line 11636 "./marpa.w"

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

/*:1274*//*1275:*/
#line 11660 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*41:*/
#line 644 "./marpa.w"

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
#line 960 "./marpa.w"

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
/*:111*//*269:*/
#line 2010 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:269*//*274:*/
#line 2043 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:274*/
#line 657 "./marpa.w"

/*42:*/
#line 665 "./marpa.w"
struct marpa_g;
/*:42*//*611:*/
#line 5323 "./marpa.w"

struct marpa_r;
/*:611*/
#line 658 "./marpa.w"

/*51:*/
#line 704 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:51*//*126:*/
#line 1074 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:126*//*132:*/
#line 1093 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:132*//*218:*/
#line 1513 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:218*//*455:*/
#line 3531 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:455*//*501:*/
#line 3906 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:501*//*620:*/
#line 5381 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:620*//*627:*/
#line 5407 "./marpa.w"

enum marpa_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum marpa_phase Marpa_Phase;
/*:627*//*715:*/
#line 5883 "./marpa.w"
typedef gint Marpa_Earleme;
/*:715*//*717:*/
#line 5887 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:717*//*746:*/
#line 6106 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:746*//*1245:*/
#line 11425 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1245*/
#line 659 "./marpa.w"

/*211:*/
#line 1481 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:211*//*321:*/
#line 2259 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:321*//*1247:*/
#line 11432 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1247*//*1255:*/
#line 11467 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1255*/
#line 660 "./marpa.w"

/*112:*/
#line 972 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:112*//*113:*/
#line 977 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:113*//*114:*/
#line 982 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:114*/
#line 661 "./marpa.w"

/*40:*/
#line 636 "./marpa.w"

void marpa_version(int*version);

/*:40*//*46:*/
#line 681 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:46*//*48:*/
#line 689 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:48*//*55:*/
#line 710 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:55*//*60:*/
#line 732 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:60*//*70:*/
#line 778 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:70*//*79:*/
#line 817 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:79*//*81:*/
#line 830 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:81*//*91:*/
#line 881 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:91*//*98:*/
#line 899 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:98*//*102:*/
#line 914 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:102*//*104:*/
#line 929 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:104*//*122:*/
#line 1039 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:122*//*131:*/
#line 1088 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:131*//*139:*/
#line 1131 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:139*//*149:*/
#line 1173 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:149*//*156:*/
#line 1203 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:156*//*162:*/
#line 1226 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:162*//*164:*/
#line 1233 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:164*//*168:*/
#line 1252 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:168*//*172:*/
#line 1270 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:172*//*174:*/
#line 1277 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:174*//*178:*/
#line 1297 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:178*//*180:*/
#line 1304 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:180*//*184:*/
#line 1325 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:184*//*186:*/
#line 1332 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:186*//*190:*/
#line 1351 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:190*//*192:*/
#line 1358 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:192*//*197:*/
#line 1378 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:197*//*203:*/
#line 1418 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:203*//*206:*/
#line 1446 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:206*//*215:*/
#line 1496 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:215*//*227:*/
#line 1610 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:227*//*241:*/
#line 1792 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:241*//*254:*/
#line 1953 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:254*//*258:*/
#line 1969 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:258*//*262:*/
#line 1981 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:262*//*273:*/
#line 2018 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:273*//*278:*/
#line 2063 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:278*//*282:*/
#line 2087 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:282*//*287:*/
#line 2107 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:287*//*292:*/
#line 2128 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:292*//*299:*/
#line 2163 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:299*//*303:*/
#line 2179 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:303*//*307:*/
#line 2205 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:307*//*311:*/
#line 2216 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:311*//*315:*/
#line 2232 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:315*//*319:*/
#line 2248 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:319*//*325:*/
#line 2270 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:325*//*327:*/
#line 2275 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:327*//*329:*/
#line 2280 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:329*//*336:*/
#line 2302 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:336*//*341:*/
#line 2316 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:341*//*346:*/
#line 2335 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);
/*:346*//*356:*/
#line 2407 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:356*//*471:*/
#line 3623 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:471*//*473:*/
#line 3634 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:473*//*475:*/
#line 3645 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:475*//*477:*/
#line 3656 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:477*//*479:*/
#line 3666 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:479*//*526:*/
#line 4075 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:526*//*528:*/
#line 4088 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:528*//*529:*/
#line 4091 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);
/*:529*//*532:*/
#line 4126 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:532*//*534:*/
#line 4136 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:534*//*539:*/
#line 4200 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:539*//*604:*/
#line 5254 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:604*//*607:*/
#line 5288 "./marpa.w"

/*:607*//*608:*/
#line 5289 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:608*//*614:*/
#line 5334 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:614*//*617:*/
#line 5366 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:617*//*624:*/
#line 5387 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:624*//*630:*/
#line 5422 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:630*//*636:*/
#line 5450 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:636*//*642:*/
#line 5472 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:642*//*644:*/
#line 5478 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:644*//*648:*/
#line 5499 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:648*//*667:*/
#line 5592 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:667*//*682:*/
#line 5700 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:682*//*685:*/
#line 5720 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:685*//*688:*/
#line 5739 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:688*//*702:*/
#line 5821 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:702*//*711:*/
#line 5857 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:711*//*732:*/
#line 5988 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r);
/*:732*//*734:*/
#line 6003 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r);
/*:734*//*736:*/
#line 6021 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:736*//*739:*/
#line 6046 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:739*//*769:*/
#line 6353 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:769*//*773:*/
#line 6426 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:773*//*776:*/
#line 6465 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:776*//*808:*/
#line 6811 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:808*//*811:*/
#line 6849 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:811*//*813:*/
#line 6882 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:813*//*852:*/
#line 7303 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:852*//*856:*/
#line 7348 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:856*//*859:*/
#line 7380 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:859*//*863:*/
#line 7424 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:863*//*866:*/
#line 7458 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:866*//*870:*/
#line 7505 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:870*//*876:*/
#line 7562 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:876*//*879:*/
#line 7599 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:879*//*882:*/
#line 7641 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r);
/*:882*//*884:*/
#line 7680 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:884*//*903:*/
#line 7865 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:903*//*911:*/
#line 7949 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:911*//*929:*/
#line 8089 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:929*//*984:*/
#line 8867 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:984*//*1049:*/
#line 9320 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:1049*//*1082:*/
#line 10028 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r);
/*:1082*//*1251:*/
#line 11447 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1251*//*1259:*/
#line 11484 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1259*/
#line 662 "./marpa.w"


/*:41*/
#line 11665 "./marpa.w"

#endif __MARPA_H__

/*:1275*/
