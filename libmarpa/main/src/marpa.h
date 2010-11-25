/*451:*/
#line 3353 "./marpa.w"

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
/*453:*/
#line 3416 "./marpa.w"

#ifdef MARPA_STANDALONE
#define MARPA_PUBLIC_INLINE
#elif defined (__GNUC__)
#define MARPA_PUBLIC_INLINE static __inline __attribute__ ((unused))
#elif MARPA_CAN_INLINE
#define MARPA_PUBLIC_INLINE static inline
#else
#define MARPA_PUBLIC_INLINE
#endif

/*:453*/
#line 432 "./marpa.w"

/*89:*/
#line 769 "./marpa.w"

#define MARPA_CONTEXT_INT 1
#define MARPA_CONTEXT_CONST 2
#define MARPA_IS_CONTEXT_INT(v)   ((v)->type == MARPA_CONTEXT_INT) 
#define MARPA_CONTEXT_INT_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_INT ? ((struct marpa_context_int_value*)v)->data : G_MININT) 
#define MARPA_CONTEXT_STRING_VALUE(v)  \
 ((v)->type == MARPA_CONTEXT_CONST ? ((struct marpa_context_const_value*)v)->data : NULL) 
/*:89*//*257:*/
#line 1808 "./marpa.w"

#define MARPA_KEEP_SEPARATION  0x1
/*:257*//*262:*/
#line 1841 "./marpa.w"

#define MARPA_PROPER_SEPARATION  0x2

/*:262*/
#line 433 "./marpa.w"

struct marpa_g;
/*29:*/
#line 486 "./marpa.w"
typedef gint Marpa_Grammar_ID;
/*:29*//*101:*/
#line 855 "./marpa.w"

typedef const gchar*Marpa_Error_ID;
/*:101*//*112:*/
#line 899 "./marpa.w"

typedef gint Marpa_Symbol_ID;
/*:112*//*199:*/
#line 1324 "./marpa.w"

typedef gint Marpa_Rule_ID;
/*:199*//*430:*/
#line 3105 "./marpa.w"

typedef const gchar*Marpa_Message_ID;
/*:430*/
#line 435 "./marpa.w"

/*192:*/
#line 1291 "./marpa.w"

typedef void(Marpa_Symbol_Callback)(struct marpa_g*g,Marpa_Symbol_ID id);
/*:192*//*287:*/
#line 1955 "./marpa.w"

typedef void(Marpa_Rule_Callback)(struct marpa_g*g,Marpa_Rule_ID id);
/*:287*//*431:*/
#line 3110 "./marpa.w"

typedef void(Marpa_Message_Callback)(struct marpa_g*g,Marpa_Message_ID id);
/*:431*/
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
/*:46*//*86:*/
#line 764 "./marpa.w"
GHashTable*context;
/*:86*//*102:*/
#line 857 "./marpa.w"
Marpa_Error_ID error;
/*:102*//*193:*/
#line 1293 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
void*symbol_callback_arg;
/*:193*//*288:*/
#line 1957 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
void*rule_callback_arg;
/*:288*//*432:*/
#line 3112 "./marpa.w"

Marpa_Message_Callback*message_callback;
void*message_callback_arg;
/*:432*/
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
#line 691 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:74*//*80:*/
#line 731 "./marpa.w"
unsigned int is_academic:1;
/*:80*/
#line 455 "./marpa.w"

};

/*:22*//*90:*/
#line 777 "./marpa.w"

struct marpa_context_int_value{
gint type;
gint data;
};
/*:90*//*91:*/
#line 782 "./marpa.w"

struct marpa_context_const_value{
gint type;
const gchar*data;
};
/*:91*//*92:*/
#line 787 "./marpa.w"

union marpa_context_value{
gint type;
struct marpa_context_int_value int_value;
struct marpa_context_const_value const_value;
};

/*:92*//*107:*/
#line 874 "./marpa.w"

struct marpa_r{
int dummy;
};

/*:107*//*352:*/
#line 2445 "./marpa.w"

struct marpa_earley_item{
int dummy;
};
/*:352*/
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

gint marpa_grammar_id_value(struct marpa_g*g);

/*:33*//*38:*/
#line 509 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g);

/*:38*//*50:*/
#line 565 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g);

/*:50*//*61:*/
#line 617 "./marpa.w"

gboolean marpa_start_symbol(struct marpa_g*g);
/*:61*//*63:*/
#line 636 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id);

/*:63*//*73:*/
#line 683 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g);

/*:73*//*77:*/
#line 698 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g);
/*:77*//*79:*/
#line 713 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(struct marpa_g*g,gboolean value);

/*:79*//*83:*/
#line 738 "./marpa.w"

gboolean marpa_is_academic(struct marpa_g*g);
/*:83*//*85:*/
#line 753 "./marpa.w"

gboolean marpa_is_academic_set(struct marpa_g*g,gboolean value);

/*:85*//*100:*/
#line 842 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key);

/*:100*//*106:*/
#line 869 "./marpa.w"

Marpa_Error_ID marpa_error_value(struct marpa_g*g);

/*:106*//*109:*/
#line 891 "./marpa.w"

void marpa_r_init(struct marpa_r*recce);
/*:109*//*111:*/
#line 895 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce);

/*:111*//*116:*/
#line 925 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g);

/*:116*//*126:*/
#line 961 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID id);
/*:126*//*129:*/
#line 970 "./marpa.w"

void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:129*//*134:*/
#line 993 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID id);
/*:134*//*137:*/
#line 1002 "./marpa.w"

void marpa_symbol_rhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:137*//*141:*/
#line 1020 "./marpa.w"

gboolean marpa_symbol_is_accessible_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:141*//*143:*/
#line 1027 "./marpa.w"


void marpa_symbol_is_accessible_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:143*//*147:*/
#line 1046 "./marpa.w"

gboolean marpa_symbol_is_counted_value(struct marpa_g*g,Marpa_Symbol_ID id);

/*:147*//*151:*/
#line 1064 "./marpa.w"

gboolean marpa_symbol_is_nullable_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:151*//*153:*/
#line 1071 "./marpa.w"

void marpa_symbol_is_nullable_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:153*//*157:*/
#line 1090 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID id);
/*:157*//*159:*/
#line 1097 "./marpa.w"

void marpa_symbol_is_nulling_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:159*//*163:*/
#line 1115 "./marpa.w"

gboolean marpa_symbol_is_terminal_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:163*//*165:*/
#line 1122 "./marpa.w"

void marpa_symbol_is_terminal_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);


/*:165*//*169:*/
#line 1141 "./marpa.w"

gboolean marpa_symbol_is_productive_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:169*//*171:*/
#line 1148 "./marpa.w"

void marpa_symbol_is_productive_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:171*//*176:*/
#line 1172 "./marpa.w"

gboolean marpa_symbol_is_start_value(struct marpa_g*g,Marpa_Symbol_ID id);
/*:176*//*178:*/
#line 1178 "./marpa.w"

void marpa_symbol_is_start_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value);

/*:178*//*184:*/
#line 1218 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_proper_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:184*//*187:*/
#line 1240 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_null_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:187*//*190:*/
#line 1281 "./marpa.w"

Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:190*//*195:*/
#line 1303 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb);
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_symbol_callback_arg_peek(struct marpa_g*g);
/*:195*//*209:*/
#line 1429 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags);
/*:209*//*225:*/
#line 1607 "./marpa.w"

Marpa_Rule_ID marpa_rule_start_shim(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
void marpa_rule_complete_shim(struct marpa_g*g,Marpa_Rule_ID id);
Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);

/*:225*//*242:*/
#line 1759 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:242*//*246:*/
#line 1769 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id);
/*:246*//*250:*/
#line 1779 "./marpa.w"

gsize marpa_rule_length_value(struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:250*//*261:*/
#line 1816 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id);

/*:261*//*266:*/
#line 1859 "./marpa.w"

gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id);

/*:266*//*270:*/
#line 1881 "./marpa.w"

gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id);

/*:270*//*277:*/
#line 1908 "./marpa.w"

gboolean marpa_rule_is_used_value(struct marpa_g*g,Marpa_Rule_ID id);

/*:277*//*281:*/
#line 1934 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs_value(struct marpa_g*g,Marpa_Rule_ID id);

/*:281*//*285:*/
#line 1945 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs_value(struct marpa_g*g,Marpa_Rule_ID id);

/*:285*//*290:*/
#line 1963 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb);
/*:290*//*292:*/
#line 1968 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg);
/*:292*//*294:*/
#line 1973 "./marpa.w"

void*marpa_rule_callback_arg_peek(struct marpa_g*g);
/*:294*//*308:*/
#line 2023 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent_value(struct marpa_g*g,Marpa_Rule_ID id);

/*:308*//*311:*/
#line 2051 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g);

/*:311*//*314:*/
#line 2116 "./marpa.w"

static inline struct marpa_g*census(struct marpa_g*g);
/*:314*//*354:*/
#line 2455 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void);
/*:354*//*356:*/
#line 2461 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item);
/*:356*//*434:*/
#line 3122 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb);
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg);
void*marpa_message_callback_arg_peek(struct marpa_g*g);
/*:434*//*439:*/
#line 3164 "./marpa.w"

const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro);

/*:439*/
#line 438 "./marpa.w"

#if MARPA_CAN_INLINE || defined MARPA_STANDALONE
/*452:*/
#line 3380 "./marpa.w"


/*:452*/
#line 440 "./marpa.w"

#endif
#endif

/*:20*/
#line 3376 "./marpa.w"


/*:451*/
