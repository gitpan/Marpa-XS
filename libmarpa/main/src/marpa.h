/*518:*/
#line 4001 "./marpa.w"

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

/*15:*/
#line 392 "./marpa.w"

#include <glib.h> 
#include <stdio.h> 
/*:15*//*20:*/
#line 416 "./marpa.w"

#ifndef __MARPA_H__
#define __MARPA_H__ 
#include "glib.h" 
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
/*520:*/
#line 4064 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:520*/
#line 432 "./marpa.w"

/*93:*/
#line 780 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:93*//*256:*/
#line 1789 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:256*//*261:*/
#line 1822 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:261*/
#line 433 "./marpa.w"

struct marpa_g;
/*29:*/
#line 486 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:29*//*105:*/
#line 866 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:105*//*116:*/
#line 910 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:116*//*200:*/
#line 1323 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:200*//*497:*/
#line 3753 "./marpa.w"

typedef const gchar*Marpa_Message_ID;
/*:497*/
#line 435 "./marpa.w"

/*192:*/
#line 1281 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:192*//*300:*/
#line 1988 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:300*//*498:*/
#line 3758 "./marpa.w"

typedef void(Marpa_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:498*/
#line 436 "./marpa.w"

/*22:*/
#line 452 "./marpa.w"
struct marpa_g{
/*34:*/
#line 498 "./marpa.w"
GArray*symbols;
/*:34*//*46:*/
#line 554 "./marpa.w"
GArray*rules;
/*:46*//*90:*/
#line 775 "./marpa.w"
GHashTable*context;
/*:90*//*106:*/
#line 868 "./marpa.w"
Marpa_Error_ID error;
/*:106*//*193:*/
#line 1283 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
void*symbol_callback_arg;
/*:193*//*301:*/
#line 1990 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
void*rule_callback_arg;
/*:301*//*499:*/
#line 3760 "./marpa.w"

Marpa_Message_Callback*message_callback;
void*message_callback_arg;
/*:499*/
#line 453 "./marpa.w"

/*28:*/
#line 485 "./marpa.w"
int id;
/*:28*//*58:*/
#line 610 "./marpa.w"
Marpa_Symbol_ID start_symbol;
/*:58*//*65:*/
#line 658 "./marpa.w"
int size;
/*:65*//*68:*/
#line 671 "./marpa.w"
int max_rule_length;
/*:68*/
#line 454 "./marpa.w"

/*70:*/
#line 676 "./marpa.w"
unsigned int is_precomputed:1;
/*:70*//*74:*/
#line 687 "./marpa.w"
unsigned int has_loop:1;
/*:74*//*78:*/
#line 702 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:78*//*84:*/
#line 742 "./marpa.w"
unsigned int is_academic:1;
/*:84*/
#line 455 "./marpa.w"

};

/*:22*//*94:*/
#line 788 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:94*//*95:*/
#line 793 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:95*//*96:*/
#line 798 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:96*//*111:*/
#line 885 "./marpa.w"

struct marpa_r{
int dummy;
};

/*:111*//*419:*/
#line 3093 "./marpa.w"

struct marpa_earley_item{
int dummy;
};
/*:419*/
#line 437 "./marpa.w"

/*19:*/
#line 409 "./marpa.w"

void marpa_version(int*version);

/*:19*//*24:*/
#line 465 "./marpa.w"

void marpa_g_init(struct marpa_g*g);

/*:24*//*26:*/
#line 471 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g);

/*:26*//*33:*/
#line 492 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g);

/*:33*//*38:*/
#line 509 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:38*//*50:*/
#line 565 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:50*//*61:*/
#line 617 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g);
/*:61*//*63:*/
#line 636 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:63*//*73:*/
#line 683 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:73*//*77:*/
#line 694 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g);

/*:77*//*81:*/
#line 709 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:81*//*83:*/
#line 724 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:83*//*87:*/
#line 749 "./marpa.w"

gboolean marpa_is_academic(struct marpa_g*g);
/*:87*//*89:*/
#line 764 "./marpa.w"

gboolean marpa_is_academic_set(struct marpa_g*g,gboolean value);

/*:89*//*104:*/
#line 853 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key);

/*:104*//*110:*/
#line 880 "./marpa.w"

Marpa_Error_ID marpa_error(struct marpa_g*g);

/*:110*//*113:*/
#line 902 "./marpa.w"

void marpa_r_init(struct marpa_r*recce);
/*:113*//*115:*/
#line 906 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce);

/*:115*//*120:*/
#line 936 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:120*//*130:*/
#line 968 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:130*//*137:*/
#line 994 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id);
/*:137*//*143:*/
#line 1017 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id);
/*:143*//*145:*/
#line 1024 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:145*//*149:*/
#line 1043 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id);

/*:149*//*153:*/
#line 1061 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id);
/*:153*//*155:*/
#line 1068 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:155*//*159:*/
#line 1087 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:159*//*161:*/
#line 1094 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:161*//*165:*/
#line 1112 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id);
/*:165*//*167:*/
#line 1119 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:167*//*171:*/
#line 1138 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id);
/*:171*//*173:*/
#line 1145 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:173*//*178:*/
#line 1164 "./marpa.w"

gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID id);

/*:178*//*184:*/
#line 1203 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:184*//*187:*/
#line 1230 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:187*//*190:*/
#line 1271 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:190*//*195:*/
#line 1293 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_symbol_callback_arg_peek(struct marpa_g*g);
/*:195*//*208:*/
#line 1410 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:208*//*224:*/
#line 1588 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);

/*:224*//*241:*/
#line 1738 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:241*//*245:*/
#line 1749 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:245*//*249:*/
#line 1760 "./marpa.w"

gsize marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:249*//*260:*/
#line 1797 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:260*//*265:*/
#line 1840 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:265*//*269:*/
#line 1862 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:269*//*274:*/
#line 1880 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:274*//*279:*/
#line 1899 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:279*//*286:*/
#line 1927 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:286*//*290:*/
#line 1953 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:290*//*294:*/
#line 1964 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id);

/*:294*//*303:*/
#line 1996 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:303*//*305:*/
#line 2001 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg);
/*:305*//*307:*/
#line 2006 "./marpa.w"

void*marpa_rule_callback_arg_peek(struct marpa_g*g);
/*:307*//*321:*/
#line 2056 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id);

/*:321*//*325:*/
#line 2097 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:325*//*329:*/
#line 2167 "./marpa.w"

static inline struct marpa_g*census(struct marpa_g*g);
/*:329*//*421:*/
#line 3103 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void);
/*:421*//*423:*/
#line 3109 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item);
/*:423*//*501:*/
#line 3770 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_message_callback_arg_peek(struct marpa_g*g);
/*:501*//*506:*/
#line 3812 "./marpa.w"

const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro);

/*:506*/
#line 438 "./marpa.w"

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE
/*519:*/
#line 4028 "./marpa.w"


/*:519*/
#line 440 "./marpa.w"

#endif
#endif

/*:20*/
#line 4024 "./marpa.w"


/*:518*/
