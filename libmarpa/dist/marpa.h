/*836:*/
#line 6936 "./marpa.w"

/*
 * Copyright 2010 Jeffrey Kegler
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

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*19:*/
#line 393 "./marpa.w"

/*:19*//*24:*/
#line 415 "./marpa.w"

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
/*97:*/
#line 794 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:97*//*256:*/
#line 1786 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:256*//*261:*/
#line 1819 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:261*/
#line 428 "./marpa.w"

/*33:*/
#line 508 "./marpa.w"
struct marpa_g;
/*:33*//*547:*/
#line 4555 "./marpa.w"
struct marpa_r;
/*:547*/
#line 429 "./marpa.w"

/*41:*/
#line 543 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:41*//*112:*/
#line 888 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:112*//*118:*/
#line 906 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:118*//*200:*/
#line 1323 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:200*//*426:*/
#line 3208 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:426*//*467:*/
#line 3495 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:467*//*555:*/
#line 4602 "./marpa.w"
typedef gint Marpa_Recce_ID;
/*:555*//*604:*/
#line 4817 "./marpa.w"
typedef gint Marpa_Earleme;

/*:604*//*816:*/
#line 6810 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:816*/
#line 430 "./marpa.w"

/*193:*/
#line 1293 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:193*//*304:*/
#line 2014 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:304*//*818:*/
#line 6817 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:818*//*826:*/
#line 6852 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:826*/
#line 431 "./marpa.w"

/*98:*/
#line 802 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:98*//*99:*/
#line 807 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:99*//*100:*/
#line 812 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:100*//*497:*/
#line 3705 "./marpa.w"

struct marpa_AHFA_transition{
Marpa_Symbol_ID symbol;
Marpa_AHFA_State_ID to;
};

/*:497*//*642:*/
#line 5125 "./marpa.w"

struct marpa_earley_item{
Marpa_AHFA_State_ID state;
Marpa_Earleme origin;
};

/*:642*/
#line 432 "./marpa.w"

/*23:*/
#line 408 "./marpa.w"

void marpa_version(int*version);

/*:23*//*36:*/
#line 520 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:36*//*38:*/
#line 528 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:38*//*45:*/
#line 549 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:45*//*50:*/
#line 571 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:50*//*60:*/
#line 620 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:60*//*71:*/
#line 672 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:71*//*73:*/
#line 690 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:73*//*83:*/
#line 737 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:83*//*87:*/
#line 748 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:87*//*91:*/
#line 763 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:91*//*93:*/
#line 778 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:93*//*108:*/
#line 867 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:108*//*117:*/
#line 902 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:117*//*122:*/
#line 939 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:122*//*131:*/
#line 971 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:131*//*138:*/
#line 1000 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:138*//*144:*/
#line 1023 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:144*//*146:*/
#line 1030 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:146*//*150:*/
#line 1049 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:150*//*154:*/
#line 1067 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:154*//*156:*/
#line 1074 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:156*//*160:*/
#line 1094 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:160*//*162:*/
#line 1101 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:162*//*166:*/
#line 1121 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:166*//*168:*/
#line 1128 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:168*//*172:*/
#line 1147 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:172*//*174:*/
#line 1154 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:174*//*179:*/
#line 1174 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:179*//*185:*/
#line 1214 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:185*//*188:*/
#line 1242 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:188*//*191:*/
#line 1283 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:191*//*197:*/
#line 1308 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:197*//*210:*/
#line 1410 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:210*//*225:*/
#line 1583 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:225*//*241:*/
#line 1730 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:241*//*245:*/
#line 1746 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:245*//*249:*/
#line 1758 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:249*//*260:*/
#line 1794 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:260*//*265:*/
#line 1839 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:265*//*269:*/
#line 1863 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:269*//*274:*/
#line 1883 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:274*//*279:*/
#line 1904 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:279*//*286:*/
#line 1934 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:286*//*290:*/
#line 1960 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:290*//*294:*/
#line 1971 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:294*//*298:*/
#line 1987 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:298*//*302:*/
#line 2003 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:302*//*308:*/
#line 2025 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:308*//*310:*/
#line 2030 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:310*//*312:*/
#line 2035 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:312*//*319:*/
#line 2056 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:319*//*324:*/
#line 2070 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:324*//*328:*/
#line 2091 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:328*//*330:*/
#line 2116 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:330*//*439:*/
#line 3259 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:439*//*441:*/
#line 3270 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:441*//*443:*/
#line 3281 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:443*//*445:*/
#line 3292 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:445*//*447:*/
#line 3302 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:447*//*484:*/
#line 3600 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:484*//*486:*/
#line 3613 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:486*//*488:*/
#line 3634 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:488*//*490:*/
#line 3649 "./marpa.w"

gint marpa_AHFA_state_transition_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:490*//*496:*/
#line 3697 "./marpa.w"

struct AHFA_state;
static inline struct AHFA_state*to_state_find(
struct AHFA_state*state,
Marpa_Symbol_ID symbol_id);

/*:496*//*499:*/
#line 3738 "./marpa.w"

struct marpa_AHFA_transition*marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
struct marpa_AHFA_transition*buffer);

/*:499*//*502:*/
#line 3761 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:502*//*504:*/
#line 3775 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:504*//*506:*/
#line 3789 "./marpa.w"

gint marpa_AHFA_state_is_leo_completion(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:506*//*550:*/
#line 4577 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);

/*:550*//*552:*/
#line 4587 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:552*//*559:*/
#line 4608 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:559*//*570:*/
#line 4655 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:570*//*572:*/
#line 4665 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);

/*:572*//*578:*/
#line 4688 "./marpa.w"

gboolean marpa_is_trace_earley_sets(struct marpa_r*r);
/*:578*//*580:*/
#line 4699 "./marpa.w"

gboolean marpa_is_trace_earley_sets_set(struct marpa_r*r,gboolean value);

/*:580*//*591:*/
#line 4760 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:591*//*600:*/
#line 4793 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:600*//*641:*/
#line 5120 "./marpa.w"

gint marpa_earley_item_count(struct marpa_r*r,Marpa_Earleme earleme);

/*:641*//*644:*/
#line 5166 "./marpa.w"

struct marpa_earley_item*marpa_earley_items(struct marpa_r*r,
Marpa_Earleme earleme,
struct marpa_earley_item*buffer
);

/*:644*//*673:*/
#line 5520 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);

/*:673*//*688:*/
#line 5630 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);

/*:688*//*711:*/
#line 5867 "./marpa.w"

Marpa_Earleme earleme_complete(struct marpa_r*r);

/*:711*//*822:*/
#line 6832 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:822*//*830:*/
#line 6867 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:830*/
#line 433 "./marpa.w"


/*:24*/
#line 6963 "./marpa.w"

#endif __MARPA_H__

/*:836*/
