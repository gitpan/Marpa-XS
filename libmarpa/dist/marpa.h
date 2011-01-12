/*708:*/
#line 5638 "./marpa.w"

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
/*16:*/
#line 370 "./marpa.w"

/*:16*//*21:*/
#line 392 "./marpa.w"

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
/*710:*/
#line 5706 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:710*/
#line 405 "./marpa.w"

/*89:*/
#line 722 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:89*//*248:*/
#line 1706 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:248*//*253:*/
#line 1739 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:253*/
#line 406 "./marpa.w"

/*23:*/
#line 424 "./marpa.w"
struct marpa_g;
/*:23*//*523:*/
#line 4249 "./marpa.w"
struct marpa_r;
/*:523*/
#line 407 "./marpa.w"

/*31:*/
#line 459 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:31*//*104:*/
#line 816 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:104*//*110:*/
#line 834 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:110*//*192:*/
#line 1242 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:192*//*418:*/
#line 3122 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:418*//*456:*/
#line 3404 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:456*//*531:*/
#line 4296 "./marpa.w"
typedef gint Marpa_Recce_ID;
/*:531*//*693:*/
#line 5498 "./marpa.w"

typedef const gchar*Marpa_Message_ID;
/*:693*/
#line 408 "./marpa.w"

/*185:*/
#line 1212 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:185*//*296:*/
#line 1934 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:296*//*694:*/
#line 5503 "./marpa.w"

typedef void(Marpa_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:694*/
#line 409 "./marpa.w"

/*90:*/
#line 730 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:90*//*91:*/
#line 735 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:91*//*92:*/
#line 740 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:92*//*476:*/
#line 3553 "./marpa.w"

struct marpa_AHFA_transition{
Marpa_Symbol_ID symbol;
Marpa_AHFA_State_ID to;
};

/*:476*//*580:*/
#line 4500 "./marpa.w"

struct earley_item{
struct AHFA_state*state;
struct earley_set*origin;
struct earley_set*set;

};
/*:580*/
#line 410 "./marpa.w"

/*20:*/
#line 385 "./marpa.w"

void marpa_version(int*version);

/*:20*//*26:*/
#line 436 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:26*//*28:*/
#line 444 "./marpa.w"

void marpa_g_free(struct marpa_g*g);

/*:28*//*35:*/
#line 465 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:35*//*40:*/
#line 489 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:40*//*52:*/
#line 548 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:52*//*63:*/
#line 600 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:63*//*65:*/
#line 618 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:65*//*75:*/
#line 665 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:75*//*79:*/
#line 676 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:79*//*83:*/
#line 691 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:83*//*85:*/
#line 706 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:85*//*100:*/
#line 795 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key);

/*:100*//*109:*/
#line 830 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g);

/*:109*//*114:*/
#line 860 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:114*//*123:*/
#line 892 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:123*//*130:*/
#line 921 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:130*//*136:*/
#line 944 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:136*//*138:*/
#line 951 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:138*//*142:*/
#line 970 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:142*//*146:*/
#line 988 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:146*//*148:*/
#line 995 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:148*//*152:*/
#line 1015 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:152*//*154:*/
#line 1022 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:154*//*158:*/
#line 1040 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:158*//*160:*/
#line 1047 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:160*//*164:*/
#line 1066 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:164*//*166:*/
#line 1073 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:166*//*171:*/
#line 1093 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:171*//*177:*/
#line 1133 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:177*//*180:*/
#line 1161 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:180*//*183:*/
#line 1202 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:183*//*189:*/
#line 1227 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_symbol_callback_arg(struct marpa_g*g);
/*:189*//*202:*/
#line 1329 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:202*//*217:*/
#line 1502 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:217*//*233:*/
#line 1649 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:233*//*237:*/
#line 1665 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix);
/*:237*//*241:*/
#line 1677 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:241*//*252:*/
#line 1714 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:252*//*257:*/
#line 1759 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:257*//*261:*/
#line 1783 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:261*//*266:*/
#line 1803 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:266*//*271:*/
#line 1824 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:271*//*278:*/
#line 1854 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:278*//*282:*/
#line 1880 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:282*//*286:*/
#line 1891 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:286*//*290:*/
#line 1907 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:290*//*294:*/
#line 1923 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id);


/*:294*//*300:*/
#line 1945 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:300*//*302:*/
#line 1950 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
/*:302*//*304:*/
#line 1955 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g);
/*:304*//*311:*/
#line 1976 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:311*//*316:*/
#line 1990 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:316*//*320:*/
#line 2011 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:320*//*322:*/
#line 2036 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:322*//*428:*/
#line 3168 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:428*//*430:*/
#line 3179 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:430*//*432:*/
#line 3190 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:432*//*434:*/
#line 3201 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:434*//*436:*/
#line 3211 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:436*//*469:*/
#line 3495 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:469*//*471:*/
#line 3508 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:471*//*473:*/
#line 3529 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:473*//*475:*/
#line 3544 "./marpa.w"

gint marpa_AHFA_state_transition_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:475*//*478:*/
#line 3584 "./marpa.w"

struct marpa_AHFA_transition*marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
struct marpa_AHFA_transition*buffer);

/*:478*//*480:*/
#line 3603 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:480*//*482:*/
#line 3617 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:482*//*484:*/
#line 3631 "./marpa.w"

gint marpa_AHFA_state_is_leo_completion(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:484*//*526:*/
#line 4271 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g);

/*:526*//*528:*/
#line 4281 "./marpa.w"

void marpa_r_free(struct marpa_r*r);

/*:528*//*535:*/
#line 4302 "./marpa.w"

gint marpa_recce_id(struct marpa_r*r);

/*:535*//*547:*/
#line 4346 "./marpa.w"

guint marpa_too_many_earley_items(struct marpa_r*r);
/*:547*//*549:*/
#line 4356 "./marpa.w"

gboolean marpa_too_many_earley_items_set(struct marpa_r*r,guint too_many_earley_items);

/*:549*//*553:*/
#line 4368 "./marpa.w"

gboolean marpa_is_trace_earley_sets(struct marpa_r*r);
/*:553*//*555:*/
#line 4379 "./marpa.w"

gboolean marpa_is_trace_earley_sets_set(struct marpa_r*r,gboolean value);

/*:555*//*566:*/
#line 4440 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key);

/*:566*//*575:*/
#line 4473 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r);

/*:575*//*582:*/
#line 4514 "./marpa.w"

static inline struct earley_item*earley_item_new(struct marpa_r*r);

/*:582*//*698:*/
#line 5518 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg);
gpointer marpa_message_callback_arg(struct marpa_g*g);
/*:698*/
#line 411 "./marpa.w"

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE
/*709:*/
#line 5670 "./marpa.w"


/*:709*/
#line 413 "./marpa.w"

#endif

/*:21*/
#line 5665 "./marpa.w"

#endif __MARPA_H__

/*:708*/
