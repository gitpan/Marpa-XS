/*1097:*/
#line 9796 "./marpa.w"

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

/*:1097*//*1098:*/
#line 9820 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*27:*/
#line 586 "./marpa.w"

/*:27*//*32:*/
#line 608 "./marpa.w"

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
/*109:*/
#line 1002 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:109*//*265:*/
#line 2027 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:265*//*270:*/
#line 2060 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:270*/
#line 621 "./marpa.w"

/*41:*/
#line 701 "./marpa.w"
struct marpa_g;
/*:41*//*563:*/
#line 4935 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*RECCE;
/*:563*/
#line 622 "./marpa.w"

/*50:*/
#line 740 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:50*//*124:*/
#line 1110 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:124*//*130:*/
#line 1128 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:130*//*212:*/
#line 1548 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:212*//*439:*/
#line 3481 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:439*//*480:*/
#line 3785 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:480*//*571:*/
#line 4988 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:571*//*578:*/
#line 5004 "./marpa.w"

enum enum_phase{
no_such_phase= 0,
initial_phase,
active_phase,
exhausted_phase,
finished_phase,
error_phase
};
typedef enum enum_phase Marpa_Phase;
/*:578*//*658:*/
#line 5451 "./marpa.w"
typedef gint Marpa_Earleme;
/*:658*//*1068:*/
#line 9604 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1068*/
#line 623 "./marpa.w"

/*205:*/
#line 1518 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:205*//*317:*/
#line 2271 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:317*//*1070:*/
#line 9611 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1070*//*1078:*/
#line 9646 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1078*/
#line 624 "./marpa.w"

/*110:*/
#line 1010 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:110*//*111:*/
#line 1015 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:111*//*112:*/
#line 1020 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:112*/
#line 625 "./marpa.w"

/*31:*/
#line 601 "./marpa.w"

void marpa_version(int*version);

/*:31*//*45:*/
#line 717 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:45*//*47:*/
#line 725 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:47*//*54:*/
#line 746 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:54*//*59:*/
#line 768 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:59*//*69:*/
#line 814 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:69*//*80:*/
#line 866 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:80*//*82:*/
#line 883 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:82*//*92:*/
#line 931 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:92*//*96:*/
#line 942 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:96*//*100:*/
#line 957 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:100*//*102:*/
#line 972 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:102*//*120:*/
#line 1075 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:120*//*129:*/
#line 1124 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:129*//*134:*/
#line 1163 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:134*//*143:*/
#line 1195 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:143*//*150:*/
#line 1224 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:150*//*156:*/
#line 1247 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:156*//*158:*/
#line 1254 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:158*//*162:*/
#line 1273 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:162*//*166:*/
#line 1291 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:166*//*168:*/
#line 1298 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:168*//*172:*/
#line 1318 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:172*//*174:*/
#line 1325 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:174*//*178:*/
#line 1346 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:178*//*180:*/
#line 1353 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:180*//*184:*/
#line 1372 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:184*//*186:*/
#line 1379 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:186*//*191:*/
#line 1399 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:191*//*197:*/
#line 1439 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:197*//*200:*/
#line 1467 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:200*//*203:*/
#line 1508 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symid);

/*:203*//*209:*/
#line 1533 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:209*//*223:*/
#line 1643 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:223*//*237:*/
#line 1824 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:237*//*250:*/
#line 1970 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:250*//*254:*/
#line 1986 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:254*//*258:*/
#line 1998 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:258*//*269:*/
#line 2035 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:269*//*274:*/
#line 2080 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:274*//*278:*/
#line 2104 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:278*//*283:*/
#line 2124 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:283*//*288:*/
#line 2145 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:288*//*295:*/
#line 2175 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:295*//*299:*/
#line 2191 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:299*//*303:*/
#line 2217 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:303*//*307:*/
#line 2228 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:307*//*311:*/
#line 2244 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:311*//*315:*/
#line 2260 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:315*//*321:*/
#line 2282 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:321*//*323:*/
#line 2287 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:323*//*325:*/
#line 2292 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:325*//*332:*/
#line 2313 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:332*//*337:*/
#line 2327 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:337*//*341:*/
#line 2348 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:341*//*343:*/
#line 2374 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:343*//*452:*/
#line 3547 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:452*//*454:*/
#line 3558 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:454*//*456:*/
#line 3569 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:456*//*458:*/
#line 3580 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:458*//*460:*/
#line 3590 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:460*//*498:*/
#line 3904 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:498*//*500:*/
#line 3917 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:500*//*502:*/
#line 3938 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:502*//*508:*/
#line 3973 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:508*//*512:*/
#line 4022 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:512*//*514:*/
#line 4036 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:514*//*516:*/
#line 4046 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:516*//*520:*/
#line 4105 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:520*//*566:*/
#line 4960 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);

/*:566*//*568:*/
#line 4973 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:568*//*575:*/
#line 4994 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:575*//*581:*/
#line 5018 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:581*//*587:*/
#line 5045 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:587*//*591:*/
#line 5056 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:591*//*593:*/
#line 5062 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:593*//*597:*/
#line 5083 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:597*//*614:*/
#line 5181 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:614*//*629:*/
#line 5295 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:629*//*632:*/
#line 5315 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:632*//*645:*/
#line 5389 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:645*//*654:*/
#line 5425 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:654*//*680:*/
#line 5645 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earleme id);
/*:680*//*683:*/
#line 5668 "./marpa.w"

Marpa_Earleme marpa_trace_earleme(struct marpa_r*r);
/*:683*//*685:*/
#line 5686 "./marpa.w"

gint marpa_current_earley_set_size(struct marpa_r*r);
/*:685*//*714:*/
#line 5946 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earleme origin_id,
Marpa_AHFA_State_ID state_id);
/*:714*//*716:*/
#line 5996 "./marpa.w"

Marpa_AHFA_State_ID
marpa_first_earley_item_trace(struct marpa_r*r);
/*:716*//*718:*/
#line 6030 "./marpa.w"

Marpa_AHFA_State_ID
marpa_next_earley_item_trace(struct marpa_r*r);
/*:718*//*748:*/
#line 6357 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:748*//*751:*/
#line 6395 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:751*//*753:*/
#line 6428 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:753*//*792:*/
#line 6849 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:792*//*796:*/
#line 6894 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:796*//*799:*/
#line 6926 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:799*//*803:*/
#line 6970 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:803*//*806:*/
#line 7004 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:806*//*810:*/
#line 7051 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:810*//*816:*/
#line 7108 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:816*//*819:*/
#line 7145 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:819*//*822:*/
#line 7187 "./marpa.w"

Marpa_Earleme marpa_source_middle(struct marpa_r*r);
/*:822*//*824:*/
#line 7226 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:824*//*828:*/
#line 7286 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);

/*:828*//*835:*/
#line 7336 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);

/*:835*//*859:*/
#line 7591 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:859*//*906:*/
#line 8248 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:906*//*1074:*/
#line 9626 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1074*//*1082:*/
#line 9661 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1082*/
#line 626 "./marpa.w"


/*:32*/
#line 9825 "./marpa.w"

#endif __MARPA_H__

/*:1098*/
