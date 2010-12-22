/*639:*/
#line 5277 "./marpa.w"

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
/*14:*/
#line 390 "./marpa.w"

/*:14*//*19:*/
#line 412 "./marpa.w"

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
/*641:*/
#line 5345 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:641*/
#line 425 "./marpa.w"

/*86:*/
#line 741 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:86*//*250:*/
#line 1750 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:250*//*255:*/
#line 1783 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:255*/
#line 426 "./marpa.w"

struct marpa_g;
/*28:*/
#line 478 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:28*//*101:*/
#line 835 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:101*//*112:*/
#line 882 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:112*//*194:*/
#line 1290 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:194*//*416:*/
#line 3147 "./marpa.w"

typedef gint Marpa_AHFA_Item_ID;
/*:416*//*454:*/
#line 3429 "./marpa.w"

typedef gint Marpa_AHFA_State_ID;

/*:454*//*624:*/
#line 5138 "./marpa.w"

typedef const gchar*Marpa_Message_ID;
/*:624*/
#line 428 "./marpa.w"

/*187:*/
#line 1260 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:187*//*294:*/
#line 1959 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:294*//*625:*/
#line 5143 "./marpa.w"

typedef void(Marpa_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:625*/
#line 429 "./marpa.w"

/*87:*/
#line 749 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:87*//*88:*/
#line 754 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:88*//*89:*/
#line 759 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:89*//*107:*/
#line 854 "./marpa.w"

struct marpa_r{
int dummy;
};

/*:107*//*516:*/
#line 4164 "./marpa.w"

struct marpa_earley_item{
int dummy;
};
/*:516*/
#line 430 "./marpa.w"

/*18:*/
#line 405 "./marpa.w"

void marpa_version(int*version);

/*:18*//*23:*/
#line 455 "./marpa.w"

struct marpa_g*marpa_g_new(void);

/*:23*//*25:*/
#line 463 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g);

/*:25*//*32:*/
#line 484 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:32*//*37:*/
#line 508 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:37*//*49:*/
#line 567 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:49*//*60:*/
#line 619 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:60*//*62:*/
#line 637 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:62*//*72:*/
#line 684 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:72*//*76:*/
#line 695 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:76*//*80:*/
#line 710 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:80*//*82:*/
#line 725 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:82*//*97:*/
#line 814 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key);

/*:97*//*106:*/
#line 849 "./marpa.w"

Marpa_Error_ID marpa_error(const struct marpa_g*g);

/*:106*//*109:*/
#line 871 "./marpa.w"

void marpa_r_init(struct marpa_r*recce);

/*:109*//*111:*/
#line 878 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce);

/*:111*//*116:*/
#line 908 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:116*//*125:*/
#line 940 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:125*//*132:*/
#line 969 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:132*//*138:*/
#line 992 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:138*//*140:*/
#line 999 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:140*//*144:*/
#line 1018 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:144*//*148:*/
#line 1036 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:148*//*150:*/
#line 1043 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:150*//*154:*/
#line 1063 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:154*//*156:*/
#line 1070 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:156*//*160:*/
#line 1088 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:160*//*162:*/
#line 1095 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:162*//*166:*/
#line 1114 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:166*//*168:*/
#line 1121 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:168*//*173:*/
#line 1141 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:173*//*179:*/
#line 1181 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:179*//*182:*/
#line 1209 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:182*//*185:*/
#line 1250 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:185*//*191:*/
#line 1275 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_symbol_callback_arg(struct marpa_g*g);
/*:191*//*204:*/
#line 1377 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags);
/*:204*//*219:*/
#line 1550 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:219*//*235:*/
#line 1697 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:235*//*239:*/
#line 1709 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:239*//*243:*/
#line 1721 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:243*//*254:*/
#line 1758 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:254*//*259:*/
#line 1803 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:259*//*263:*/
#line 1827 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:263*//*268:*/
#line 1847 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:268*//*273:*/
#line 1868 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:273*//*280:*/
#line 1898 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:280*//*284:*/
#line 1924 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:284*//*288:*/
#line 1935 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:288*//*298:*/
#line 1970 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:298*//*300:*/
#line 1975 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg);
/*:300*//*302:*/
#line 1980 "./marpa.w"

void*marpa_rule_callback_arg(struct marpa_g*g);
/*:302*//*309:*/
#line 2001 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id);

/*:309*//*314:*/
#line 2015 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id);

/*:314*//*318:*/
#line 2036 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:318*//*320:*/
#line 2061 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:320*//*426:*/
#line 3193 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g);

/*:426*//*428:*/
#line 3204 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:428*//*430:*/
#line 3215 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:430*//*432:*/
#line 3226 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);
/*:432*//*434:*/
#line 3236 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:434*//*467:*/
#line 3511 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g);

/*:467*//*469:*/
#line 3524 "./marpa.w"

gint marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:469*//*471:*/
#line 3545 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix);

/*:471*//*473:*/
#line 3560 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:473*//*475:*/
#line 3574 "./marpa.w"

gint marpa_AHFA_state_is_leo_completion(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id);

/*:475*//*518:*/
#line 4174 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void);
/*:518*//*520:*/
#line 4180 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item);
/*:520*//*629:*/
#line 5158 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_message_callback_arg(struct marpa_g*g);
/*:629*/
#line 431 "./marpa.w"

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE
/*640:*/
#line 5309 "./marpa.w"


/*:640*/
#line 433 "./marpa.w"

#endif

/*:19*/
#line 5304 "./marpa.w"

#endif __MARPA_H__

/*:639*/
