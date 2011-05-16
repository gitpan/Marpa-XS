/*1159:*/
#line 10355 "./marpa.w"

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

/*:1159*//*1160:*/
#line 10379 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include <stdio.h> 
#include <glib.h> 
/*27:*/
#line 590 "./marpa.w"

/*:27*//*32:*/
#line 612 "./marpa.w"

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
#line 1000 "./marpa.w"

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
#line 2040 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:268*//*273:*/
#line 2073 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:273*/
#line 625 "./marpa.w"

/*41:*/
#line 705 "./marpa.w"
struct marpa_g;
/*:41*//*576:*/
#line 4989 "./marpa.w"

struct marpa_r;
typedef struct marpa_r*RECCE;
/*:576*/
#line 626 "./marpa.w"

/*50:*/
#line 744 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:50*//*125:*/
#line 1114 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:125*//*131:*/
#line 1133 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:131*//*215:*/
#line 1558 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:215*//*445:*/
#line 3505 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:445*//*486:*/
#line 3810 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:486*//*584:*/
#line 5046 "./marpa.w"
typedef gint Marpa_Recognizer_ID;
/*:584*//*591:*/
#line 5072 "./marpa.w"

enum enum_phase{
no_such_phase= 0,
initial_phase,
input_phase,
evaluation_phase,
error_phase
};
typedef enum enum_phase Marpa_Phase;
/*:591*//*676:*/
#line 5545 "./marpa.w"
typedef gint Marpa_Earleme;
/*:676*//*678:*/
#line 5549 "./marpa.w"
typedef gint Marpa_Earley_Set_ID;
/*:678*//*705:*/
#line 5753 "./marpa.w"
typedef gint Marpa_Earley_Item_ID;
/*:705*//*1130:*/
#line 10161 "./marpa.w"

typedef const gchar*Marpa_Message_ID;

/*:1130*/
#line 627 "./marpa.w"

/*208:*/
#line 1527 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:208*//*320:*/
#line 2284 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:320*//*1132:*/
#line 10168 "./marpa.w"

typedef void(Marpa_G_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:1132*//*1140:*/
#line 10203 "./marpa.w"

typedef void(Marpa_R_Message_Callback)(struct marpa_r*r,Marpa_Message_ID id);
/*:1140*/
#line 628 "./marpa.w"

/*111:*/
#line 1012 "./marpa.w"

struct marpa_context_int_value{
gint t_type;
gint t_data;
};
/*:111*//*112:*/
#line 1017 "./marpa.w"

struct marpa_context_const_value{
gint t_type;
const gchar*t_data;
};
/*:112*//*113:*/
#line 1022 "./marpa.w"

union marpa_context_value{
gint t_type;
struct marpa_context_int_value t_int_value;
struct marpa_context_const_value t_const_value;
};

/*:113*/
#line 629 "./marpa.w"

/*31:*/
#line 605 "./marpa.w"

void marpa_version(int*version);

/*:31*//*45:*/
#line 721 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:45*//*47:*/
#line 729 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:47*//*54:*/
#line 750 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:54*//*59:*/
#line 772 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:59*//*69:*/
#line 818 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:69*//*78:*/
#line 857 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:78*//*80:*/
#line 870 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:80*//*90:*/
#line 921 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g);
/*:90*//*97:*/
#line 939 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:97*//*101:*/
#line 954 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:101*//*103:*/
#line 969 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:103*//*121:*/
#line 1079 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:121*//*130:*/
#line 1128 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:130*//*136:*/
#line 1164 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);
/*:136*//*146:*/
#line 1204 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:146*//*153:*/
#line 1233 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid);
/*:153*//*159:*/
#line 1256 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:159*//*161:*/
#line 1263 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:161*//*165:*/
#line 1282 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:165*//*169:*/
#line 1300 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:169*//*171:*/
#line 1307 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:171*//*175:*/
#line 1327 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:175*//*177:*/
#line 1334 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:177*//*181:*/
#line 1355 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:181*//*183:*/
#line 1362 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:183*//*187:*/
#line 1381 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:187*//*189:*/
#line 1388 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:189*//*194:*/
#line 1408 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:194*//*200:*/
#line 1448 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:200*//*203:*/
#line 1476 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid);

/*:203*//*206:*/
#line 1517 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symid);

/*:206*//*212:*/
#line 1542 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:212*//*226:*/
#line 1656 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:226*//*240:*/
#line 1837 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:240*//*253:*/
#line 1983 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:253*//*257:*/
#line 1999 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:257*//*261:*/
#line 2011 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:261*//*272:*/
#line 2048 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:272*//*277:*/
#line 2093 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:277*//*281:*/
#line 2117 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:281*//*286:*/
#line 2137 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:286*//*291:*/
#line 2158 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:291*//*298:*/
#line 2188 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:298*//*302:*/
#line 2204 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:302*//*306:*/
#line 2230 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:306*//*310:*/
#line 2241 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:310*//*314:*/
#line 2257 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:314*//*318:*/
#line 2273 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:318*//*324:*/
#line 2295 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:324*//*326:*/
#line 2300 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:326*//*328:*/
#line 2305 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:328*//*335:*/
#line 2326 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:335*//*340:*/
#line 2340 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:340*//*344:*/
#line 2361 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:344*//*346:*/
#line 2387 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:346*//*458:*/
#line 3572 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:458*//*460:*/
#line 3583 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:460*//*462:*/
#line 3594 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:462*//*464:*/
#line 3605 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:464*//*466:*/
#line 3615 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:466*//*510:*/
#line 3954 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:510*//*512:*/
#line 3967 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:512*//*514:*/
#line 3988 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:514*//*520:*/
#line 4023 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result);
/*:520*//*524:*/
#line 4072 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:524*//*526:*/
#line 4086 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:526*//*528:*/
#line 4096 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:528*//*533:*/
#line 4159 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);
/*:533*//*578:*/
#line 4999 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g);
/*:578*//*581:*/
#line 5031 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:581*//*588:*/
#line 5052 "./marpa.w"

gint marpa_r_id(struct marpa_r*r);

/*:588*//*594:*/
#line 5087 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r);
/*:594*//*600:*/
#line 5115 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r);
/*:600*//*606:*/
#line 5137 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r);
/*:606*//*608:*/
#line 5143 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold);
/*:608*//*612:*/
#line 5164 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r);
/*:612*//*628:*/
#line 5254 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result);
/*:628*//*643:*/
#line 5362 "./marpa.w"

gboolean marpa_is_use_leo(struct marpa_r*r);
/*:643*//*646:*/
#line 5382 "./marpa.w"

gboolean marpa_is_use_leo_set(struct marpa_r*r,gboolean value);

/*:646*//*649:*/
#line 5401 "./marpa.w"

gboolean marpa_is_exhausted(struct marpa_r*r);
/*:649*//*663:*/
#line 5483 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:663*//*672:*/
#line 5519 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:672*//*693:*/
#line 5652 "./marpa.w"

Marpa_Earleme marpa_trace_earleme(struct marpa_r*r);
/*:693*//*695:*/
#line 5675 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:695*//*698:*/
#line 5701 "./marpa.w"

gint marpa_current_earley_set_size(struct marpa_r*r);
/*:698*//*728:*/
#line 5993 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id);
/*:728*//*732:*/
#line 6066 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id);
/*:732*//*735:*/
#line 6105 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Item_ID item_id);
/*:735*//*767:*/
#line 6451 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid);
/*:767*//*770:*/
#line 6489 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r);
/*:770*//*772:*/
#line 6522 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r);
/*:772*//*811:*/
#line 6943 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r);
/*:811*//*815:*/
#line 6988 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r);
/*:815*//*818:*/
#line 7020 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r);
/*:818*//*822:*/
#line 7064 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r);
/*:822*//*825:*/
#line 7098 "./marpa.w"

Marpa_Symbol_ID marpa_first_leo_link_trace(struct marpa_r*r);
/*:825*//*829:*/
#line 7145 "./marpa.w"

Marpa_Symbol_ID marpa_next_leo_link_trace(struct marpa_r*r);
/*:829*//*835:*/
#line 7202 "./marpa.w"

Marpa_AHFA_State_ID marpa_source_predecessor_state(struct marpa_r*r);
/*:835*//*838:*/
#line 7239 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r);
/*:838*//*841:*/
#line 7281 "./marpa.w"

Marpa_Earleme marpa_source_middle(struct marpa_r*r);
/*:841*//*843:*/
#line 7320 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p);
/*:843*//*862:*/
#line 7505 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r);
/*:862*//*870:*/
#line 7589 "./marpa.w"
gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length);
/*:870*//*888:*/
#line 7729 "./marpa.w"

Marpa_Earleme marpa_earleme_complete(struct marpa_r*r);
/*:888*//*943:*/
#line 8501 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r);
/*:943*//*963:*/
#line 8661 "./marpa.w"

gint marpa_eval_setup(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal);
/*:963*//*973:*/
#line 8816 "./marpa.w"

gint marpa_eval_clear(struct marpa_r*r);
/*:973*//*1136:*/
#line 10183 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb);
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_g_message_callback_arg(struct marpa_g*g);
/*:1136*//*1144:*/
#line 10220 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb);
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg);
gpointer marpa_r_message_callback_arg(struct marpa_r*r);
/*:1144*/
#line 630 "./marpa.w"


/*:32*/
#line 10384 "./marpa.w"

#endif __MARPA_H__

/*:1160*/
