/*1085:*/
#line 9726 "./marpa.w"

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

/*:1085*//*1086:*/
#line 9750 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*29:*/
#line 600 "./marpa.w"

/*:29*//*34:*/
#line 622 "./marpa.w"

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
#line 1016 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:111*//*267:*/
#line 2041 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:267*//*272:*/
#line 2074 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:272*/
#line 635 "./marpa.w"

/*43:*/
#line 715 "./marpa.w"
struct marpa_g;
/*:43*//*565:*/
#line 4949 "./marpa.w"
struct marpa_r;
/*:565*/
#line 636 "./marpa.w"

/*52:*/
#line 754 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:52*//*126:*/
#line 1124 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:126*//*132:*/
#line 1142 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:132*//*214:*/
#line 1562 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:214*//*441:*/
#line 3495 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:441*//*482:*/
#line 3796 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:482*//*574:*/
#line 5000 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:574*//*581:*/
#line 5015 "./marpa.w"

enum enum_phase{
no_such_phase= 0,
initial_phase,
active_phase,
exhausted_phase,
finished_phase,
error_phase
};
typedef enum enum_phase Marpa_Phase;
/*:581*//*661:*/
#line 5464 "./marpa.w"
typedef gint Marpa_Earleme;
/*:661*//*1056:*/
#line 9535 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1056*/
#line 637 "./marpa.w"

/*207:*/
#line 1532 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:207*//*319:*/
#line 2285 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:319*//*1058:*/
#line 9542 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1058*//*1066:*/
#line 9577 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1066*/
#line 638 "./marpa.w"

/*112:*/
#line 1024 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:112*//*113:*/
#line 1029 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:113*//*114:*/
#line 1034 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:114*/
#line 639 "./marpa.w"

/*33:*/
#line 615 "./marpa.w"

void marpa_version(int*version);

/*:33*//*47:*/
#line 731 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:47*//*49:*/
#line 739 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:49*//*56:*/
#line 760 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:56*//*61:*/
#line 782 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:61*//*71:*/
#line 828 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:71*//*82:*/
#line 880 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:82*//*84:*/
#line 897 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:84*//*94:*/
#line 945 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:94*//*98:*/
#line 956 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:98*//*102:*/
#line 971 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:102*//*104:*/
#line 986 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:104*//*122:*/
#line 1089 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:122*//*131:*/
#line 1138 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:131*//*136:*/
#line 1177 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:136*//*145:*/
#line 1209 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:145*//*152:*/
#line 1238 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:152*//*158:*/
#line 1261 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:158*//*160:*/
#line 1268 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:160*//*164:*/
#line 1287 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:164*//*168:*/
#line 1305 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:168*//*170:*/
#line 1312 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:170*//*174:*/
#line 1332 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:174*//*176:*/
#line 1339 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:176*//*180:*/
#line 1360 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:180*//*182:*/
#line 1367 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:182*//*186:*/
#line 1386 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:186*//*188:*/
#line 1393 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:188*//*193:*/
#line 1413 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:193*//*199:*/
#line 1453 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:199*//*202:*/
#line 1481 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:202*//*205:*/
#line 1522 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symid);

/*:205*//*211:*/
#line 1547 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:211*//*225:*/
#line 1657 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:225*//*239:*/
#line 1838 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:239*//*252:*/
#line 1984 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:252*//*256:*/
#line 2000 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:256*//*260:*/
#line 2012 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:260*//*271:*/
#line 2049 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:271*//*276:*/
#line 2094 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:276*//*280:*/
#line 2118 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:280*//*285:*/
#line 2138 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:285*//*290:*/
#line 2159 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:290*//*297:*/
#line 2189 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:297*//*301:*/
#line 2205 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:301*//*305:*/
#line 2231 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:305*//*309:*/
#line 2242 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:309*//*313:*/
#line 2258 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:313*//*317:*/
#line 2274 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:317*//*323:*/
#line 2296 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:323*//*325:*/
#line 2301 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:325*//*327:*/
#line 2306 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:327*//*334:*/
#line 2327 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:334*//*339:*/
#line 2341 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:339*//*343:*/
#line 2362 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:343*//*345:*/
#line 2388 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:345*//*454:*/
#line 3558 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:454*//*456:*/
#line 3569 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:456*//*458:*/
#line 3580 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:458*//*460:*/
#line 3591 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:460*//*462:*/
#line 3601 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:462*//*500:*/
#line 3915 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:500*//*502:*/
#line 3928 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:502*//*504:*/
#line 3949 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:504*//*510:*/
#line 3984 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:510*//*514:*/
#line 4036 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:514*//*516:*/
#line 4050 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:516*//*518:*/
#line 4060 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:518*//*522:*/
#line 4119 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:522*//*569:*/
#line 4972 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);

/*:569*//*571:*/
#line 4985 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:571*//*578:*/
#line 5006 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:578*//*584:*/
#line 5029 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:584*//*590:*/
#line 5061 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:590*//*594:*/
#line 5072 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:594*//*596:*/
#line 5078 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:596*//*600:*/
#line 5099 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:600*//*617:*/
#line 5197 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:617*//*632:*/
#line 5308 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:632*//*635:*/
#line 5328 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:635*//*648:*/
#line 5402 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:648*//*657:*/
#line 5438 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:657*//*686:*/
#line 5673 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earleme id);
/*:686*//*689:*/
#line 5696 "./marpa.w"

Marpa_Earleme marpa_trace_earleme(struct marpa_r*r);
/*:689*//*691:*/
#line 5714 "./marpa.w"

gint marpa_current_earley_set_size(struct marpa_r*r);
/*:691*//*721:*/
#line 5985 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earleme origin_id,
Marpa_AHFA_State_ID state_id);
/*:721*//*723:*/
#line 6035 "./marpa.w"

Marpa_AHFA_State_ID
marpa_first_earley_item_trace(struct marpa_r*r);
/*:723*//*725:*/
#line 6069 "./marpa.w"

Marpa_AHFA_State_ID
marpa_next_earley_item_trace(struct marpa_r*r);
/*:725*//*755:*/
#line 6396 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:755*//*758:*/
#line 6434 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:758*//*760:*/
#line 6467 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:760*//*799:*/
#line 6888 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:799*//*803:*/
#line 6933 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:803*//*806:*/
#line 6965 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:806*//*810:*/
#line 7009 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:810*//*813:*/
#line 7043 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:813*//*817:*/
#line 7090 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:817*//*823:*/
#line 7147 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:823*//*826:*/
#line 7184 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:826*//*829:*/
#line 7226 "./marpa.w"

Marpa_Earleme marpa_source_middle(struct marpa_r*r);
/*:829*//*831:*/
#line 7265 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:831*//*835:*/
#line 7325 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);

/*:835*//*842:*/
#line 7375 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);

/*:842*//*866:*/
#line 7630 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:866*//*913:*/
#line 8297 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:913*//*1062:*/
#line 9557 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1062*//*1070:*/
#line 9592 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1070*/
#line 640 "./marpa.w"


/*:34*/
#line 9755 "./marpa.w"

#endif __MARPA_H__

/*:1086*/
