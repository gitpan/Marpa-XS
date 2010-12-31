/*647:*/
#line 5391 "./marpa.w"

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

#include "config.h"
#include "marpa.h"
#define SYMBOL_LHS_RULE_COUNT(symbol) ((symbol) ->lhs->len) 
#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DEFINE(name,type) struct{gint ix;type*base;}name;
#define FSTACK_INIT(name,type,n) ((name.ix= 0) ,(name.base= g_new(type,n) ) ) 
#define FSTACK_PUSH(name) (name.base+name.ix++) 
#define FSTACK_POP(name) (--name.ix<0?NULL:name.base+name.ix) 
#define FSTACK_DESTROY(name) (g_free(name.base) )  \

#define DSTACK_DEFINE(this) struct dstack this;
#define DSTACK_INIT(this,type,initial_size)  \
((this.ix= 0) , \
(this.base= g_new(type,(this.size= (initial_size) ) ) ) ) 
#define DSTACK_PUSH(this,type)  \
((this.ix>=this.size?dstack_resize(&this,sizeof(type) ) :0) , \
((type*) this.base+this.ix++) ) 
#define DSTACK_POP(this,type) (--this.ix,this.ix<0?NULL:(type*) this.base+this.ix) 
#define DSTACK_BASE(this,type) ((type*) this.base) 
#define DSTACK_LENGTH(this) (this.ix)  \

#define STOLEN_DSTACK_DATA_FREE(data) g_free(data) 
#define DSTACK_DESTROY(this) STOLEN_DSTACK_DATA_FREE(this.base)  \

#define DQUEUE_DEFINE(this) struct dqueue this;
#define DQUEUE_INIT(this,type,initial_size)  \
((this.current= 0) ,DSTACK_INIT(this.s,type,initial_size) ) 
#define DQUEUE_PUSH(this,type) DSTACK_PUSH(this.s,type) 
#define DQUEUE_POP(this,type) DSTACK_POP(this.s,type) 
#define DQUEUE_NEXT(this,type)  \
(this.current>=DSTACK_LENGTH(this.s) ?NULL:(DSTACK_BASE(this.s,type) ) +this.current++) 
#define DQUEUE_BASE(this,type) DSTACK_BASE(this.s,type) 
#define DQUEUE_END(this) DSTACK_LENGTH(this.s) 
#define STOLEN_DQUEUE_DATA_FREE(data) STOLEN_DSTACK_DATA_FREE(data)  \

#define bjenkins_rot(x,k) (((x) <<(k) ) |((x) >>(32-(k) ) ) )  \

#define bjenkins_mix(a,b,c)  \
{ \
a-= c;a^= bjenkins_rot(c,4) ;c+= b; \
b-= a;b^= bjenkins_rot(a,6) ;a+= c; \
c-= b;c^= bjenkins_rot(b,8) ;b+= a; \
a-= c;a^= bjenkins_rot(c,16) ;c+= b; \
b-= a;b^= bjenkins_rot(a,19) ;a+= c; \
c-= b;c^= bjenkins_rot(b,4) ;b+= a; \
} \

#define bjenkins_final(a,b,c)  \
{ \
c^= b;c-= bjenkins_rot(b,14) ; \
a^= c;a-= bjenkins_rot(c,11) ; \
b^= a;b-= bjenkins_rot(a,25) ; \
c^= b;c-= bjenkins_rot(b,16) ; \
a^= c;a-= bjenkins_rot(c,4) ; \
b^= a;b-= bjenkins_rot(a,14) ; \
c^= b;c-= bjenkins_rot(b,24) ; \
} \

#define obstack_chunk_alloc g_malloc
#define obstack_chunk_free g_free \


#line 5416 "./marpa.w"

#include "marpa_obs.h"
/*632:*/
#line 5259 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:632*/
#line 5418 "./marpa.w"

/*531:*/
#line 4349 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:531*//*576:*/
#line 4732 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:576*/
#line 5419 "./marpa.w"

/*16:*/
#line 392 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:16*//*29:*/
#line 479 "./marpa.w"
static gint next_grammar_id= 1;
/*:29*//*532:*/
#line 4356 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:532*/
#line 5420 "./marpa.w"

/*597:*/
#line 4884 "./marpa.w"

struct p_array{gint len;void**data;};
/*:597*//*600:*/
#line 4903 "./marpa.w"

struct dp_array{struct p_array pa;gint size;};
/*:600*/
#line 5421 "./marpa.w"

/*21:*/
#line 444 "./marpa.w"
struct marpa_g{
/*33:*/
#line 494 "./marpa.w"
GArray*symbols;
/*:33*//*45:*/
#line 553 "./marpa.w"
GArray*rules;
/*:45*//*83:*/
#line 736 "./marpa.w"
GHashTable*context;
/*:83*//*98:*/
#line 821 "./marpa.w"
struct obstack obs;
/*:98*//*102:*/
#line 837 "./marpa.w"
Marpa_Error_ID error;
/*:102*//*188:*/
#line 1262 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
void*symbol_callback_arg;
/*:188*//*299:*/
#line 1980 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
void*rule_callback_arg;
/*:299*//*422:*/
#line 3181 "./marpa.w"

struct AHFA_item*AHFA_items;
struct AHFA_item**AHFA_items_by_rule;
/*:422*//*460:*/
#line 3483 "./marpa.w"
struct AHFA_state*AHFA;
/*:460*//*635:*/
#line 5299 "./marpa.w"

Marpa_Message_Callback*message_callback;
void*message_callback_arg;
/*:635*/
#line 445 "./marpa.w"

/*27:*/
#line 477 "./marpa.w"
int id;
/*:27*//*57:*/
#line 612 "./marpa.w"
Marpa_Symbol_ID start_symbol_id;
/*:57*//*64:*/
#line 659 "./marpa.w"
int size;
/*:64*//*67:*/
#line 672 "./marpa.w"
guint max_rule_length;
/*:67*//*423:*/
#line 3184 "./marpa.w"

guint no_of_items;
/*:423*//*461:*/
#line 3484 "./marpa.w"
gint AHFA_len;
/*:461*/
#line 446 "./marpa.w"

/*69:*/
#line 677 "./marpa.w"
unsigned int is_precomputed:1;
/*:69*//*73:*/
#line 688 "./marpa.w"
unsigned int has_loop:1;
/*:73*//*77:*/
#line 703 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:77*/
#line 447 "./marpa.w"

};

/*:21*//*113:*/
#line 884 "./marpa.w"

struct marpa_symbol{
/*121:*/
#line 927 "./marpa.w"
GArray*lhs;
/*:121*//*128:*/
#line 957 "./marpa.w"
GArray*rhs;
/*:128*//*175:*/
#line 1154 "./marpa.w"

struct marpa_symbol*alias;
/*:175*/
#line 886 "./marpa.w"

/*119:*/
#line 918 "./marpa.w"
Marpa_Symbol_ID id;
/*:119*/
#line 887 "./marpa.w"

/*135:*/
#line 978 "./marpa.w"
unsigned int is_accessible:1;
/*:135*//*141:*/
#line 1004 "./marpa.w"
unsigned int is_counted:1;
/*:141*//*145:*/
#line 1022 "./marpa.w"
unsigned int is_nullable:1;
/*:145*//*151:*/
#line 1047 "./marpa.w"
unsigned int is_nulling:1;
/*:151*//*157:*/
#line 1074 "./marpa.w"
unsigned int is_terminal:1;
/*:157*//*163:*/
#line 1100 "./marpa.w"
unsigned int is_productive:1;
/*:163*//*169:*/
#line 1125 "./marpa.w"
unsigned int is_start:1;
/*:169*//*174:*/
#line 1151 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:174*/
#line 888 "./marpa.w"

};

/*:113*//*195:*/
#line 1292 "./marpa.w"

struct marpa_rule{
/*228:*/
#line 1673 "./marpa.w"
guint length;
/*:228*//*248:*/
#line 1740 "./marpa.w"
Marpa_Rule_ID id;
/*:248*//*289:*/
#line 1942 "./marpa.w"
gint virtual_start;
/*:289*//*293:*/
#line 1958 "./marpa.w"
gint virtual_end;
/*:293*//*310:*/
#line 2015 "./marpa.w"
Marpa_Rule_ID original;
/*:310*//*315:*/
#line 2029 "./marpa.w"
guint real_symbol_count;
/*:315*/
#line 1294 "./marpa.w"

/*251:*/
#line 1752 "./marpa.w"
unsigned int is_discard:1;
/*:251*//*265:*/
#line 1836 "./marpa.w"
unsigned int is_loop:1;
/*:265*//*270:*/
#line 1857 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:270*//*277:*/
#line 1887 "./marpa.w"
unsigned int is_used:1;
/*:277*//*281:*/
#line 1917 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:281*//*285:*/
#line 1928 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:285*//*319:*/
#line 2038 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:319*/
#line 1295 "./marpa.w"

/*229:*/
#line 1676 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:229*/
#line 1296 "./marpa.w"

};
/*:195*//*421:*/
#line 3168 "./marpa.w"

struct AHFA_item{
Marpa_Symbol_ID postdot;

Marpa_AHFA_Item_ID sort_key;
struct marpa_rule*rule;
gint position;
};
/*:421*//*459:*/
#line 3473 "./marpa.w"

struct AHFA_state{
struct AHFA_item**items;
Marpa_AHFA_State_ID id;
guint item_count;
struct AHFA_state*empty_transition;
GSequence*transitions;
unsigned int is_predict:1;
unsigned int is_leo_completion:1;
};
/*:459*//*520:*/
#line 4260 "./marpa.w"

struct AHFA_transition{
Marpa_Symbol_ID symbol;
Marpa_AHFA_State_ID to;
};

/*:520*//*614:*/
#line 4999 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:614*//*617:*/
#line 5030 "./marpa.w"

struct dqueue{gint current;struct dstack s;};

/*:617*/
#line 5422 "./marpa.w"

/*39:*/
#line 516 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g);

/*:39*//*41:*/
#line 524 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id);

/*:41*//*44:*/
#line 546 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:44*//*51:*/
#line 575 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g);

/*:51*//*53:*/
#line 583 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id);

/*:53*//*56:*/
#line 607 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:56*//*91:*/
#line 787 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:91*//*93:*/
#line 799 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:93*//*95:*/
#line 808 "./marpa.w"

static inline void context_clear(struct marpa_g*g);

/*:95*//*115:*/
#line 905 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:115*//*118:*/
#line 914 "./marpa.w"

static inline void symbol_free(struct marpa_symbol*symbol);

/*:118*//*127:*/
#line 948 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:127*//*134:*/
#line 974 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);

/*:134*//*172:*/
#line 1138 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol);
/*:172*//*178:*/
#line 1179 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol);
/*:178*//*181:*/
#line 1207 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol);
/*:181*//*184:*/
#line 1246 "./marpa.w"

static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
/*:184*//*193:*/
#line 1286 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:193*//*197:*/
#line 1302 "./marpa.w"

static inline guint rule_sizeof(guint length);

/*:197*//*201:*/
#line 1326 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:201*//*218:*/
#line 1545 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length);

/*:218*//*227:*/
#line 1665 "./marpa.w"

static inline void rule_free(struct marpa_rule*rule);

/*:227*//*233:*/
#line 1690 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:233*//*237:*/
#line 1702 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:237*//*241:*/
#line 1714 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:241*//*245:*/
#line 1727 "./marpa.w"

static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule*rule);
/*:245*//*247:*/
#line 1734 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,guint rh_index);

/*:247*//*258:*/
#line 1801 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule);
/*:258*//*262:*/
#line 1825 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule);
/*:262*//*276:*/
#line 1883 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule);

/*:276*//*308:*/
#line 2008 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:308*//*327:*/
#line 2145 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:327*//*364:*/
#line 2484 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:364*//*403:*/
#line 2851 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:403*//*406:*/
#line 2872 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:406*//*414:*/
#line 2989 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:414*//*428:*/
#line 3201 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:428*//*440:*/
#line 3264 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:440*//*442:*/
#line 3291 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:442*//*449:*/
#line 3358 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:449*//*465:*/
#line 3504 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:465*//*467:*/
#line 3514 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:467*//*469:*/
#line 3530 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix);

/*:469*//*489:*/
#line 3717 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);

/*:489*//*491:*/
#line 3749 "./marpa.w"

static void create_AHFA_states(struct marpa_g*g);

/*:491*//*502:*/
#line 3985 "./marpa.w"

static inline struct AHFA_state*assign_AHFA_state(
struct AHFA_state*state_p,GSequence*duplicates);

/*:502*//*514:*/
#line 4154 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:514*//*518:*/
#line 4248 "./marpa.w"

static struct AHFA_state*
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
struct marpa_rule**rule_by_sort_key,
struct dqueue*states_p,
GSequence*duplicates
);

/*:518*//*522:*/
#line 4276 "./marpa.w"
static
gint cmp_AHFA_transition(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:522*//*524:*/
#line 4288 "./marpa.w"
static inline void
AHFA_transition_add(struct marpa_g*g,
struct AHFA_state*from,Marpa_Symbol_ID symbol,struct AHFA_state*to);


/*:524*//*534:*/
#line 4369 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:534*//*536:*/
#line 4379 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:536*//*538:*/
#line 4399 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);

/*:538*//*540:*/
#line 4410 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:540*//*542:*/
#line 4432 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:542*//*544:*/
#line 4442 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:544*//*546:*/
#line 4450 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:546*//*548:*/
#line 4463 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:548*//*551:*/
#line 4471 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:551*//*553:*/
#line 4479 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:553*//*555:*/
#line 4487 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:555*//*558:*/
#line 4504 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:558*//*560:*/
#line 4517 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:560*//*562:*/
#line 4529 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:562*//*564:*/
#line 4541 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:564*//*566:*/
#line 4553 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:566*//*568:*/
#line 4627 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:568*//*574:*/
#line 4709 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:574*//*579:*/
#line 4756 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:579*//*581:*/
#line 4764 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:581*//*583:*/
#line 4778 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:583*//*585:*/
#line 4796 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:585*//*588:*/
#line 4805 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:588*//*591:*/
#line 4814 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:591*//*594:*/
#line 4823 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:594*//*596:*/
#line 4876 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:596*//*599:*/
#line 4891 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa);

/*:599*//*602:*/
#line 4908 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size);
/*:602*//*604:*/
#line 4914 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa);
/*:604*//*606:*/
#line 4921 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size);
/*:606*//*608:*/
#line 4928 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p);
/*:608*//*610:*/
#line 4941 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa);


/*:610*//*616:*/
#line 5007 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:616*//*640:*/
#line 5323 "./marpa.w"

static inline void message(struct marpa_g*g,Marpa_Message_ID id);

/*:640*/
#line 5423 "./marpa.w"

/*42:*/
#line 530 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symbol_id,
struct marpa_symbol*symbol)
{
g_array_insert_val(g->symbols,(unsigned)symbol_id,symbol);
}

/*:42*//*54:*/
#line 589 "./marpa.w"

static inline
void marpa_g_rule_add(
struct marpa_g*g,
Marpa_Rule_ID rule_id,
struct marpa_rule*rule)
{
g_array_insert_val(g->rules,(unsigned)rule_id,rule);
g->size+= 1+rule->length;
g->max_rule_length= MAX(rule->length,g->max_rule_length);
}

/*:54*/
#line 5424 "./marpa.w"

/*17:*/
#line 399 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:17*//*22:*/
#line 450 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*30:*/
#line 480 "./marpa.w"

g->id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:30*//*34:*/
#line 495 "./marpa.w"

g->symbols= g_array_new(FALSE,FALSE,sizeof(struct marpa_symbol*));
/*:34*//*46:*/
#line 554 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(struct marpa_rule*));
/*:46*//*58:*/
#line 613 "./marpa.w"

g->start_symbol_id= -1;
/*:58*//*65:*/
#line 660 "./marpa.w"

g->size= 0;

/*:65*//*68:*/
#line 673 "./marpa.w"

g->max_rule_length= 0;

/*:68*//*70:*/
#line 678 "./marpa.w"

g->is_precomputed= FALSE;
/*:70*//*74:*/
#line 689 "./marpa.w"

g->has_loop= FALSE;
/*:74*//*78:*/
#line 704 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:78*//*84:*/
#line 737 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:84*//*99:*/
#line 822 "./marpa.w"
obstack_init(&g->obs);
/*:99*//*103:*/
#line 838 "./marpa.w"

g->error= NULL;
/*:103*//*189:*/
#line 1265 "./marpa.w"

g->symbol_callback_arg= NULL;
g->symbol_callback= NULL;
/*:189*//*300:*/
#line 1983 "./marpa.w"

g->rule_callback_arg= NULL;
g->rule_callback= NULL;
/*:300*//*425:*/
#line 3189 "./marpa.w"

g->AHFA_items= NULL;
g->AHFA_items_by_rule= NULL;
/*:425*//*462:*/
#line 3485 "./marpa.w"

g->AHFA= NULL;
g->AHFA_len= 0;
/*:462*//*636:*/
#line 5302 "./marpa.w"

g->message_callback_arg= NULL;
g->message_callback= NULL;
/*:636*/
#line 453 "./marpa.w"

return g;}
/*:22*//*24:*/
#line 458 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g)
{/*35:*/
#line 497 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->symbols->len;id++)
{symbol_free(symbol_id2p(g,id));}}
g_array_free(g->symbols,TRUE);

/*:35*//*47:*/
#line 556 "./marpa.w"

{Marpa_Rule_ID id;for(id= 0;id<(Marpa_Rule_ID)g->rules->len;id++)
{rule_free(rule_id2p(g,id));}}
g_array_free(g->rules,TRUE);

/*:47*//*85:*/
#line 739 "./marpa.w"
g_hash_table_destroy(g->context);

/*:85*//*100:*/
#line 823 "./marpa.w"
obstack_free(&g->obs,NULL);

/*:100*//*426:*/
#line 3192 "./marpa.w"

if(g->AHFA_items){g_free(g->AHFA_items);};
if(g->AHFA_items_by_rule){g_free(g->AHFA_items_by_rule);};

/*:426*//*463:*/
#line 3488 "./marpa.w"
if(g->AHFA){
Marpa_AHFA_State_ID id;
for(id= 0;id<g->AHFA_len;id++){
GSequence*transitions_for_this_state= g->AHFA[id].transitions;
if(transitions_for_this_state){
g_sequence_free(transitions_for_this_state);
}
}
STOLEN_DQUEUE_DATA_FREE(g->AHFA);
}

/*:463*/
#line 460 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:24*//*31:*/
#line 482 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->id;}
/*:31*//*36:*/
#line 505 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:36*//*38:*/
#line 512 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g){
return g->symbols->len;
}
/*:38*//*40:*/
#line 520 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id)
{return g_array_index(g->symbols,struct marpa_symbol*,id);}
/*:40*//*43:*/
#line 541 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id){
return symbol_id>=0&&(guint)symbol_id<g->symbols->len;
}
/*:43*//*48:*/
#line 564 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:48*//*50:*/
#line 571 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g){
return g->rules->len;
}
/*:50*//*52:*/
#line 579 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id)
{return g_array_index(g->rules,struct marpa_rule*,id);}
/*:52*//*55:*/
#line 602 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_id>=0&&(guint)rule_id<g->rules->len;
}
/*:55*//*59:*/
#line 616 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->start_symbol_id;}
/*:59*//*61:*/
#line 623 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id)
{
if(g->is_precomputed){
g->error= "precomputed";
return FALSE;
}
if(!symbol_is_valid(g,id)){
g->error= "invalid start symbol";
return FALSE;
}
g->start_symbol_id= id;
return TRUE;
}
/*:61*//*71:*/
#line 681 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{return g->is_precomputed;}
/*:71*//*75:*/
#line 692 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->has_loop;}
/*:75*//*79:*/
#line 707 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:79*//*81:*/
#line 714 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(
struct marpa_g*g,gboolean value)
{
if(g->is_precomputed){
g->error= "precomputed";
return FALSE;
}
g->is_lhs_terminal_ok= value;
return TRUE;
}
/*:81*//*90:*/
#line 778 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:90*//*92:*/
#line 790 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:92*//*94:*/
#line 805 "./marpa.w"

static inline void context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:94*//*96:*/
#line 811 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:96*//*105:*/
#line 846 "./marpa.w"

Marpa_Error_ID marpa_error(const struct marpa_g*g)
{return g->error?g->error:"unknown error";}
/*:105*//*108:*/
#line 860 "./marpa.w"

void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

return;

}

/*:108*//*110:*/
#line 876 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce G_GNUC_UNUSED){}
/*:110*//*114:*/
#line 891 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*120:*/
#line 919 "./marpa.w"
symbol->id= g->symbols->len;

/*:120*//*122:*/
#line 928 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:122*//*129:*/
#line 958 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:129*//*136:*/
#line 979 "./marpa.w"

symbol->is_accessible= FALSE;
/*:136*//*142:*/
#line 1005 "./marpa.w"

symbol->is_counted= FALSE;
/*:142*//*146:*/
#line 1023 "./marpa.w"

symbol->is_nullable= FALSE;
/*:146*//*152:*/
#line 1048 "./marpa.w"

symbol->is_nulling= FALSE;
/*:152*//*158:*/
#line 1075 "./marpa.w"

symbol->is_terminal= FALSE;
/*:158*//*164:*/
#line 1101 "./marpa.w"

symbol->is_productive= FALSE;
/*:164*//*170:*/
#line 1126 "./marpa.w"
symbol->is_start= FALSE;
/*:170*//*176:*/
#line 1156 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:176*/
#line 895 "./marpa.w"

{Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);}
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;}

/*:114*//*117:*/
#line 911 "./marpa.w"

static inline void symbol_free(struct marpa_symbol*symbol)
{/*123:*/
#line 930 "./marpa.w"

g_array_free(symbol->lhs,TRUE);
/*:123*//*130:*/
#line 960 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:130*/
#line 913 "./marpa.w"
g_free(symbol);}
/*:117*//*124:*/
#line 935 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*623:*/
#line 5200 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:623*/
#line 937 "./marpa.w"

/*627:*/
#line 5212 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:627*/
#line 938 "./marpa.w"

return symbol_id2p(g,symbol_id)->lhs;}
/*:124*//*126:*/
#line 942 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:126*//*131:*/
#line 964 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*623:*/
#line 5200 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:623*/
#line 966 "./marpa.w"

/*627:*/
#line 5212 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:627*/
#line 967 "./marpa.w"

return symbol_id2p(g,symbol_id)->rhs;}
/*:131*//*133:*/
#line 971 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
/*:133*//*137:*/
#line 989 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:137*//*139:*/
#line 995 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:139*//*143:*/
#line 1015 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:143*//*147:*/
#line 1033 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:147*//*149:*/
#line 1039 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:149*//*153:*/
#line 1058 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1060 "./marpa.w"

/*627:*/
#line 5212 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:627*/
#line 1061 "./marpa.w"

return symbol_id2p(g,symbol_id)->is_nulling;}
/*:153*//*155:*/
#line 1066 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:155*//*159:*/
#line 1085 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:159*//*161:*/
#line 1091 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:161*//*165:*/
#line 1111 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:165*//*167:*/
#line 1117 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value?1:0;}
/*:167*//*171:*/
#line 1129 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1134 "./marpa.w"

/*627:*/
#line 5212 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:627*/
#line 1135 "./marpa.w"

return symbol_is_start(symbol_id2p(g,symbol_id));
}
/*:171*//*177:*/
#line 1165 "./marpa.w"

static inline
struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol)
{return symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*proper_alias;
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1173 "./marpa.w"

/*627:*/
#line 5212 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:627*/
#line 1174 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->id;
}
/*:177*//*180:*/
#line 1188 "./marpa.w"

static inline
struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*alias;
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1196 "./marpa.w"

/*627:*/
#line 5212 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:627*/
#line 1197 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
alias= symbol_null_alias(symbol);
if(alias==NULL){
context_int_add(g,"symbol_id",symbol_id);
g->error= "no alias";
return-1;
}
return alias->id;
}
/*:180*//*183:*/
#line 1221 "./marpa.w"
static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol)
{
struct marpa_symbol*alias= symbol_new(g);
symbol->is_proper_alias= TRUE;
symbol->is_nulling= FALSE;
symbol->is_nullable= FALSE;
symbol->alias= alias;
alias->is_nulling_alias= TRUE;
alias->is_nulling= TRUE;
alias->is_nullable= TRUE;
alias->is_productive= TRUE;
alias->is_accessible= symbol->is_accessible;
alias->alias= symbol;
return alias;
}
Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID original_id)
{Marpa_Symbol_ID alias_id;
if(original_id<0){return-1;}
if((guint)original_id>=g->symbols->len){return-1;}
alias_id= symbol_alias_create(g,symbol_id2p(g,original_id))->id;
symbol_callback(g,alias_id);
return alias_id;}
/*:183*//*190:*/
#line 1268 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->symbol_callback_arg= cb_arg;}
void*marpa_symbol_callback_arg(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:190*//*192:*/
#line 1282 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:192*//*196:*/
#line 1298 "./marpa.w"

static inline guint rule_sizeof(guint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:196*//*200:*/
#line 1312 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
struct marpa_rule*rule;
/*230:*/
#line 1677 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{guint rh_index;for(rh_index= 0;rh_index<length;rh_index++){
if(!symbol_is_valid(g,rhs[rh_index])){return NULL;}
}}
/*:230*/
#line 1318 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*231:*/
#line 1682 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{guint i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:231*/
#line 1320 "./marpa.w"

/*249:*/
#line 1741 "./marpa.w"
rule->id= g->rules->len;

/*:249*//*252:*/
#line 1753 "./marpa.w"

rule->is_discard= FALSE;
/*:252*//*266:*/
#line 1837 "./marpa.w"

rule->is_loop= FALSE;
/*:266*//*271:*/
#line 1858 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:271*//*278:*/
#line 1888 "./marpa.w"

rule->is_used= TRUE;
/*:278*//*282:*/
#line 1918 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:282*//*286:*/
#line 1929 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:286*//*290:*/
#line 1943 "./marpa.w"
rule->virtual_start= -1;
/*:290*//*294:*/
#line 1959 "./marpa.w"
rule->virtual_end= -1;
/*:294*//*311:*/
#line 2016 "./marpa.w"
rule->original= -1;
/*:311*//*316:*/
#line 2030 "./marpa.w"
rule->real_symbol_count= 0;
/*:316*//*320:*/
#line 2039 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:320*/
#line 1321 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*220:*/
#line 1562 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const guint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*224:*/
#line 1629 "./marpa.w"

{

gint rhs_ix= (gint)rule->length-1;
rh_symbol_list[0]= rhs_symbol_id(rule,(unsigned)rhs_ix);
rh_symbol_list_length= 1;
rhs_ix--;
for(;rhs_ix>=0;rhs_ix--){
gint higher_ix;
Marpa_Symbol_ID new_symbol_id= rhs_symbol_id(rule,(unsigned)rhs_ix);
gint next_highest_ix= rh_symbol_list_length-1;
while(next_highest_ix>=0){
Marpa_Symbol_ID current_symbol_id= rh_symbol_list[next_highest_ix];
if(current_symbol_id==new_symbol_id)goto ignore_this_symbol;
if(current_symbol_id<new_symbol_id)break;
next_highest_ix--;
}

for(higher_ix= rh_symbol_list_length-1;
higher_ix> next_highest_ix;
higher_ix--){
rh_symbol_list[higher_ix+1]= rh_symbol_list[higher_ix];
}

rh_symbol_list[next_highest_ix+1]= new_symbol_id;
rh_symbol_list_length++;
ignore_this_symbol:;
}
}

/*:224*/
#line 1570 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
symbol_id2p(g,rh_symbol_list[rh_list_ix]),
rule->id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:220*/
#line 1323 "./marpa.w"

return rule;
}
/*:200*//*202:*/
#line 1331 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
Marpa_Rule_ID rule_id;
struct marpa_rule*rule;
if(is_rule_duplicate(g,lhs,rhs,length)==TRUE){
g->error= (Marpa_Error_ID)"duplicate rule";
return-1;
}
rule= rule_start(g,lhs,rhs,length);
if(!rule){return-1;}
rule_id= rule->id;
rule_callback(g,rule_id);
return rule_id;
}

/*:202*//*203:*/
#line 1348 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags)
{
Marpa_Rule_ID original_rule_id;
struct marpa_rule*original_rule;
Marpa_Symbol_ID internal_lhs_id,*temp_rhs;
if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE){
g->error= (Marpa_Error_ID)"duplicate rule";
return-1;
}

/*206:*/
#line 1383 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*205:*/
#line 1381 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1385 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:206*/
#line 1361 "./marpa.w"

/*207:*/
#line 1389 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:207*/
#line 1362 "./marpa.w"

/*208:*/
#line 1393 "./marpa.w"

symbol_id2p(g,rhs_id)->is_counted= 1;
if(separator_id>=0){symbol_id2p(g,separator_id)->is_counted= 1;}
/*:208*/
#line 1363 "./marpa.w"

if(min==0){/*209:*/
#line 1396 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*205:*/
#line 1381 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1398 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:209*/
#line 1364 "./marpa.w"
}
min= 1;
/*210:*/
#line 1403 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:210*/
#line 1366 "./marpa.w"

/*211:*/
#line 1417 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:211*/
#line 1367 "./marpa.w"

/*213:*/
#line 1420 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*205:*/
#line 1381 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1424 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:213*/
#line 1368 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*214:*/
#line 1433 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*205:*/
#line 1381 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1438 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:214*/
#line 1370 "./marpa.w"

}
/*215:*/
#line 1450 "./marpa.w"

{struct marpa_rule*rule;
guint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*205:*/
#line 1381 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1460 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:215*/
#line 1372 "./marpa.w"

/*216:*/
#line 1465 "./marpa.w"

{struct marpa_rule*rule;
guint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*205:*/
#line 1381 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1472 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:216*/
#line 1373 "./marpa.w"

/*212:*/
#line 1419 "./marpa.w"
g_free(temp_rhs);
/*:212*/
#line 1374 "./marpa.w"

return original_rule_id;
}
/*:203*//*217:*/
#line 1521 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length)
{
guint ix;
struct marpa_symbol*lhs= symbol_id2p(g,lhs_id);
GArray*same_lhs_array= lhs->lhs;
guint same_lhs_count= same_lhs_array->len;
for(ix= 0;ix<same_lhs_count;ix++){
Marpa_Rule_ID same_lhs_rule_id= ((Marpa_Rule_ID*)(same_lhs_array->data))[ix];
guint rhs_position;
struct marpa_rule*rule= rule_id2p(g,same_lhs_rule_id);
if(rule->length!=length){goto RULE_IS_NOT_DUPLICATE;}
for(rhs_position= 0;rhs_position<rule->length;rhs_position++){
if(rhs_symbol_id(rule,rhs_position)!=rhs_ids[rhs_position]){
goto RULE_IS_NOT_DUPLICATE;
}
}
return TRUE;
RULE_IS_NOT_DUPLICATE:;
}
return FALSE;
}
/*:217*//*226:*/
#line 1661 "./marpa.w"

static inline void rule_free(struct marpa_rule*rule)
{
g_free(rule);}
/*:226*//*232:*/
#line 1687 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
/*:232*//*234:*/
#line 1692 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1694 "./marpa.w"

/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1695 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:234*//*236:*/
#line 1699 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:236*//*238:*/
#line 1704 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*623:*/
#line 5200 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:623*/
#line 1706 "./marpa.w"

/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1707 "./marpa.w"

return rule_rhs_get(rule_id2p(g,rule_id));}
/*:238*//*240:*/
#line 1711 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:240*//*242:*/
#line 1716 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1718 "./marpa.w"

/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1719 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:242*//*244:*/
#line 1724 "./marpa.w"

static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule*rule){return rule->symbols[0];}
/*:244*//*246:*/
#line 1729 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,guint rh_index){
return rule->symbols[rh_index+1];
}
/*:246*//*253:*/
#line 1755 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:253*//*257:*/
#line 1788 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule)
{
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
return symbol_id2p(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1795 "./marpa.w"

struct marpa_rule*rule;
/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1797 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:257*//*261:*/
#line 1808 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_productive)return FALSE;
}
return TRUE;}
gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1819 "./marpa.w"

struct marpa_rule*rule;
/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1821 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:261*//*267:*/
#line 1841 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1844 "./marpa.w"

/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1845 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:267*//*272:*/
#line 1862 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1865 "./marpa.w"

/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1866 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:272*//*275:*/
#line 1874 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:275*//*279:*/
#line 1892 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 1895 "./marpa.w"

/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1896 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:279*//*283:*/
#line 1921 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:283*//*287:*/
#line 1932 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:287*//*291:*/
#line 1944 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*625:*/
#line 5204 "./marpa.w"
const int failure_indicator= -2;

/*:625*/
#line 1947 "./marpa.w"

/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1948 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_start;
}
/*:291*//*295:*/
#line 1960 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*625:*/
#line 5204 "./marpa.w"
const int failure_indicator= -2;

/*:625*/
#line 1963 "./marpa.w"

/*628:*/
#line 5219 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:628*/
#line 1964 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_end;
}
/*:295*//*301:*/
#line 1986 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:301*//*303:*/
#line 1991 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:303*//*305:*/
#line 1996 "./marpa.w"

void*marpa_rule_callback_arg(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:305*//*307:*/
#line 2004 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:307*//*312:*/
#line 2017 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}
/*:312*//*317:*/
#line 2031 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}
/*:317*//*321:*/
#line 2050 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:321*//*323:*/
#line 2069 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
if(!census(g))return NULL;
if(!CHAF_rewrite(g))return NULL;
if(!g_augment(g))return NULL;
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
return g;
}
/*:323*//*326:*/
#line 2115 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*328:*/
#line 2147 "./marpa.w"

guint pre_rewrite_rule_count= g->rules->len;
guint pre_rewrite_symbol_count= g->symbols->len;

/*:328*//*333:*/
#line 2180 "./marpa.w"

Marpa_Symbol_ID original_start_symbol_id= g->start_symbol_id;
struct marpa_symbol*original_start_symbol;

/*:333*//*337:*/
#line 2217 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:337*//*343:*/
#line 2276 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:343*//*345:*/
#line 2303 "./marpa.w"

Bit_Vector nullable_v;
/*:345*//*349:*/
#line 2329 "./marpa.w"

Bit_Vector productive_v;
/*:349*//*352:*/
#line 2370 "./marpa.w"
Bit_Matrix reach_matrix;
/*:352*//*355:*/
#line 2388 "./marpa.w"

Bit_Vector accessible_v;

/*:355*/
#line 2118 "./marpa.w"

/*329:*/
#line 2151 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:329*/
#line 2119 "./marpa.w"

/*330:*/
#line 2158 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:330*/
#line 2120 "./marpa.w"

/*332:*/
#line 2164 "./marpa.w"

if(original_start_symbol_id<0){
g->error= "no start symbol";
return NULL;
}
if(!symbol_is_valid(g,original_start_symbol_id)){
context_int_add(g,"symbol_id",original_start_symbol_id);
g->error= "invalid start symbol";
return NULL;
}
original_start_symbol= symbol_id2p(g,original_start_symbol_id);
if(original_start_symbol->lhs->len<=0){
context_int_add(g,"symbol_id",original_start_symbol_id);
g->error= "start symbol not on LHS";
return NULL;
}
/*:332*/
#line 2121 "./marpa.w"

/*334:*/
#line 2184 "./marpa.w"

{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;
rule_id<(Marpa_Rule_ID)pre_rewrite_rule_count;
rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
bv_bit_set(lhs_v,(guint)lhs_id);
if(rule->length<=0){
bv_bit_set(empty_lhs_v,(guint)lhs_id);
have_empty_rule= 1;
}
}
}
/*:334*/
#line 2122 "./marpa.w"

/*335:*/
#line 2203 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symbol_id= 0;
symbol_id<(Marpa_Symbol_ID)pre_rewrite_symbol_count;
symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_terminal){
bv_bit_set(terminal_v,(guint)symbol_id);
have_marked_terminals= 1;
}
}}
/*:335*/
#line 2123 "./marpa.w"

if(have_marked_terminals){
/*339:*/
#line 2232 "./marpa.w"

if(!g->is_lhs_terminal_ok){
gboolean have_bad_lhs= 0;
guint start= 0;
guint min,max;
Bit_Vector bad_lhs_v= bv_clone(terminal_v);
bv_and(bad_lhs_v,bad_lhs_v,lhs_v);
while(bv_scan(bad_lhs_v,start,&min,&max)){
Marpa_Symbol_ID i;
for(i= (Marpa_Symbol_ID)min;i<=(Marpa_Symbol_ID)max;i++){
context_clear(g);
context_int_add(g,"symbol_id",i);
message(g,"lhs is terminal");
}
start= max+2;
have_bad_lhs= 1;
}
bv_free(bad_lhs_v);
if(have_bad_lhs){
g->error= "lhs is terminal";
return NULL;
}
}

/*:339*/
#line 2125 "./marpa.w"

}else{
/*338:*/
#line 2221 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:338*/
#line 2127 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*340:*/
#line 2256 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<(Marpa_Symbol_ID)g->symbols->len;symbol_id++)
{symbol_id2p(g,symbol_id)->is_terminal= 1;}}
/*:340*/
#line 2129 "./marpa.w"

}else{
/*341:*/
#line 2261 "./marpa.w"

{guint start= 0;
guint min,max;
bv_not(terminal_v,lhs_v);
while(bv_scan(terminal_v,start,&min,&max)){
Marpa_Symbol_ID symbol_id;
for(symbol_id= (Marpa_Symbol_ID)min;symbol_id<=(Marpa_Symbol_ID)max;symbol_id++){
symbol_id2p(g,symbol_id)->is_terminal= 1;
}
start= max+2;
}
}
/*:341*/
#line 2131 "./marpa.w"

}
}
/*344:*/
#line 2281 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{guint min,max,start;
Marpa_Symbol_ID symbol_id;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symbol_id= (Marpa_Symbol_ID)min;symbol_id<=(Marpa_Symbol_ID)max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_counted){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
message(g,"counted nullable");
counted_nullables++;
}
symbol->is_nullable= 1;
}}
if(counted_nullables){
g->error= "counted nullable";
return NULL;
}
}
/*:344*/
#line 2134 "./marpa.w"

/*347:*/
#line 2308 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{guint min,max,start;
Marpa_Symbol_ID symbol_id;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symbol_id= (Marpa_Symbol_ID)min;
symbol_id<=(Marpa_Symbol_ID)max;
symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
symbol->is_productive= 1;
}}
}
/*:347*/
#line 2135 "./marpa.w"

/*348:*/
#line 2322 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->start_symbol_id))
{
context_int_add(g,"symbol_id",g->start_symbol_id);
g->error= "unproductive start symbol";
return NULL;
}
/*:348*/
#line 2136 "./marpa.w"

/*351:*/
#line 2352 "./marpa.w"

reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{guint symbol_id,no_of_symbols= symbol_count(g);
for(symbol_id= 0;symbol_id<no_of_symbols;symbol_id++){
matrix_bit_set(reach_matrix,symbol_id,symbol_id);
}}
{Marpa_Rule_ID rule_id;
guint no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
guint rhs_ix,rule_length= rule->length;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,
(guint)lhs_id,(guint)rhs_symbol_id(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:351*/
#line 2137 "./marpa.w"

/*354:*/
#line 2374 "./marpa.w"

accessible_v= matrix_row(reach_matrix,(guint)original_start_symbol_id);
{guint min,max,start;
Marpa_Symbol_ID symbol_id;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symbol_id= (Marpa_Symbol_ID)min;
symbol_id<=(Marpa_Symbol_ID)max;
symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
symbol->is_accessible= 1;
}}
}
/*:354*/
#line 2138 "./marpa.w"

/*356:*/
#line 2393 "./marpa.w"

{Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
guint min,max,start;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
Marpa_Symbol_ID productive_id;
for(productive_id= (Marpa_Symbol_ID)min;
productive_id<=(Marpa_Symbol_ID)max;
productive_id++){
bv_and(reaches_terminal_v,terminal_v,matrix_row(reach_matrix,(guint)productive_id));
if(bv_is_empty(reaches_terminal_v))symbol_id2p(g,productive_id)->is_nulling= 1;
}}
bv_free(reaches_terminal_v);}

/*:356*/
#line 2139 "./marpa.w"

/*336:*/
#line 2215 "./marpa.w"

bv_free(terminal_v);
/*:336*//*342:*/
#line 2273 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:342*//*346:*/
#line 2305 "./marpa.w"

bv_free(nullable_v);

/*:346*//*350:*/
#line 2331 "./marpa.w"

bv_free(productive_v);

/*:350*/
#line 2140 "./marpa.w"

/*353:*/
#line 2371 "./marpa.w"

matrix_free(reach_matrix);

/*:353*/
#line 2141 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:326*//*363:*/
#line 2463 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*365:*/
#line 2486 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:365*//*369:*/
#line 2537 "./marpa.w"

guint factor_count;
guint*factor_positions;
/*:369*//*374:*/
#line 2586 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:374*/
#line 2466 "./marpa.w"

/*370:*/
#line 2540 "./marpa.w"

factor_positions= g_new(guint,g->max_rule_length);
/*:370*//*375:*/
#line 2589 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:375*/
#line 2467 "./marpa.w"

/*367:*/
#line 2498 "./marpa.w"

{gint no_of_symbols= symbol_count(g);
Marpa_Symbol_ID symbol_id;
for(symbol_id= 0;symbol_id<no_of_symbols;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
struct marpa_symbol*alias;
if(!symbol->is_nullable)continue;
if(symbol->is_nulling)continue;
if(!symbol->is_accessible)continue;
if(!symbol->is_productive)continue;
if(symbol_null_alias(symbol))continue;
alias= symbol_alias_create(g,symbol);
symbol_callback(g,alias->id);
}}

/*:367*/
#line 2468 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
guint rule_length= rule->length;
guint nullable_suffix_ix= 0;
/*366:*/
#line 2490 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:366*/
#line 2474 "./marpa.w"

/*368:*/
#line 2521 "./marpa.w"

{guint rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_nulling)continue;
if(symbol_null_alias(symbol)){

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}}
/*:368*/
#line 2475 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*372:*/
#line 2546 "./marpa.w"

rule->is_used= 0;
{guint unprocessed_factor_count;

guint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= lhs_symbol_id(rule);
guint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*378:*/
#line 2599 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symbol_id;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*373:*/
#line 2565 "./marpa.w"
{
struct marpa_symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
context_clear(g);
context_int_add(g,"rule_id",rule_id);
context_int_add(g,"lhs_id",lhs_symbol_id(rule));
context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:373*/
#line 2607 "./marpa.w"

/*379:*/
#line 2626 "./marpa.w"

{
guint remaining_rhs_length,piece_rhs_length;
/*380:*/
#line 2638 "./marpa.w"

{
guint real_symbol_count= piece_end-piece_start+1;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
remaining_rhs[piece_rhs_length]= 
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
}
{struct marpa_rule*chaf_rule;
guint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2650 "./marpa.w"

}

/*:380*/
#line 2629 "./marpa.w"
;
/*381:*/
#line 2653 "./marpa.w"

{guint chaf_rule_length= rule->length-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;
remaining_rhs_length++){
Marpa_Symbol_ID original_id= rhs_symbol_id(rule,piece_start+remaining_rhs_length);
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,original_id));
remaining_rhs[remaining_rhs_length]= alias?alias->id:original_id;
}}
{struct marpa_rule*chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2665 "./marpa.w"

}

/*:381*/
#line 2630 "./marpa.w"
;
/*382:*/
#line 2670 "./marpa.w"
{
Marpa_Symbol_ID proper_id= rhs_symbol_id(rule,first_factor_position);
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
alias->id;
}
{struct marpa_rule*chaf_rule;
guint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2680 "./marpa.w"

}

/*:382*/
#line 2631 "./marpa.w"
;
/*383:*/
#line 2689 "./marpa.w"

if(piece_start<nullable_suffix_ix){
struct marpa_rule*chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2694 "./marpa.w"

}

/*:383*/
#line 2632 "./marpa.w"
;
}

/*:379*/
#line 2608 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*373:*/
#line 2565 "./marpa.w"
{
struct marpa_symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
context_clear(g);
context_int_add(g,"rule_id",rule_id);
context_int_add(g,"lhs_id",lhs_symbol_id(rule));
context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:373*/
#line 2613 "./marpa.w"

/*385:*/
#line 2699 "./marpa.w"
{
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:385*//*386:*/
#line 2708 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2714 "./marpa.w"


/*:386*//*387:*/
#line 2717 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2722 "./marpa.w"


/*:387*//*388:*/
#line 2725 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2731 "./marpa.w"


/*:388*//*389:*/
#line 2734 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2737 "./marpa.w"


/*:389*//*390:*/
#line 2740 "./marpa.w"
}

/*:390*/
#line 2614 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symbol_id;
piece_start= piece_end+1;

/*:378*/
#line 2557 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*391:*/
#line 2744 "./marpa.w"
{
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
guint second_factor_piece_position= second_factor_position-piece_start;
guint real_symbol_count;
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:391*//*392:*/
#line 2758 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2763 "./marpa.w"


/*:392*//*393:*/
#line 2766 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2771 "./marpa.w"


/*:393*//*394:*/
#line 2774 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2780 "./marpa.w"


/*:394*//*395:*/
#line 2784 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2788 "./marpa.w"

}

/*:395*//*396:*/
#line 2792 "./marpa.w"
}

/*:396*/
#line 2560 "./marpa.w"

}else{
/*397:*/
#line 2795 "./marpa.w"
{
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
guint real_symbol_count;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:397*//*398:*/
#line 2806 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2811 "./marpa.w"


/*:398*//*399:*/
#line 2815 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*401:*/
#line 2831 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:401*/
#line 2821 "./marpa.w"

}

/*:399*//*400:*/
#line 2825 "./marpa.w"
}

/*:400*/
#line 2562 "./marpa.w"

}}

/*:372*/
#line 2478 "./marpa.w"

NEXT_RULE:;
}
/*371:*/
#line 2542 "./marpa.w"

g_free(factor_positions);

/*:371*//*376:*/
#line 2592 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:376*/
#line 2481 "./marpa.w"

return g;
}
/*:363*//*402:*/
#line 2845 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
return alias->id;
}
/*:402*//*405:*/
#line 2859 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct marpa_symbol*proper_old_start= NULL;
struct marpa_symbol*nulling_old_start= NULL;
struct marpa_symbol*proper_new_start= NULL;
struct marpa_symbol*old_start= symbol_id2p(g,g->start_symbol_id);
/*407:*/
#line 2875 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:407*/
#line 2867 "./marpa.w"

if(proper_old_start){/*408:*/
#line 2885 "./marpa.w"
{
struct marpa_rule*new_start_rule;
proper_old_start->is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= proper_new_start->id;
g->start_symbol_id= proper_new_start_id;
proper_new_start->is_accessible= TRUE;
proper_new_start->is_productive= TRUE;
proper_new_start->is_start= TRUE;
context_clear(g);
context_int_add(g,"old_start_id",old_start->id);
symbol_callback(g,proper_new_start_id);
new_start_rule= rule_start(g,proper_new_start_id,&old_start->id,1);
new_start_rule->is_virtual_lhs= 1;
new_start_rule->real_symbol_count= 1;
new_start_rule->is_used= TRUE;
rule_callback(g,new_start_rule->id);
}

/*:408*/
#line 2868 "./marpa.w"
}
if(nulling_old_start){/*409:*/
#line 2908 "./marpa.w"
{
Marpa_Symbol_ID nulling_new_start_id;
struct marpa_rule*new_start_rule;
struct marpa_symbol*nulling_new_start;
if(proper_new_start){
nulling_new_start= symbol_alias_create(g,proper_new_start);
nulling_new_start_id= nulling_new_start->id;
}else{
nulling_new_start= symbol_new(g);
nulling_new_start_id= nulling_new_start->id;
g->start_symbol_id= nulling_new_start_id;
nulling_new_start->is_nulling= TRUE;
nulling_new_start->is_nullable= TRUE;
nulling_new_start->is_productive= TRUE;
nulling_new_start->is_accessible= TRUE;
}
nulling_new_start->is_start= TRUE;
context_clear(g);
context_int_add(g,"old_start_id",old_start->id);
symbol_callback(g,nulling_new_start_id);
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
new_start_rule->is_virtual_lhs= 1;
new_start_rule->real_symbol_count= 1;
new_start_rule->is_used= TRUE;
rule_callback(g,new_start_rule->id);
}

/*:409*/
#line 2869 "./marpa.w"
}
return g;
}
/*:405*//*413:*/
#line 2975 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{guint no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*415:*/
#line 2998 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID proper_id;
guint rhs_ix,rule_length;
if(!rule->is_used)continue;
rule_length= rule->length;
proper_id= -1;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_nullable)continue;
if(proper_id>=0)goto NEXT_RULE;

proper_id= symbol_id;
}

if(proper_id<0)continue;

{struct marpa_symbol*rhs_symbol= symbol_id2p(g,proper_id);
GArray*lhs_rules= rhs_symbol->lhs;
guint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,(guint)rule_id,
(guint)g_array_index(lhs_rules,Marpa_Rule_ID,ix));
}}
NEXT_RULE:;
}}

/*:415*/
#line 2982 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*416:*/
#line 3037 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
struct marpa_rule*rule;
if(!matrix_bit_test(unit_transition_matrix,(guint)rule_id,(guint)rule_id))
continue;
loop_rule_count++;
rule= rule_id2p(g,rule_id);
rule->is_loop= TRUE;
rule->is_virtual_loop= rule->virtual_start<0||!rule->is_virtual_rhs;
context_clear(g);
context_int_add(g,"rule_id",rule_id);
message(g,"loop rule");
}}

/*:416*/
#line 2984 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*417:*/
#line 3058 "./marpa.w"

context_clear(g);
context_int_add(g,"loop_rule_count",loop_rule_count);
message(g,"loop rule tally");

/*:417*/
#line 2986 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:413*//*427:*/
#line 3196 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return g->AHFA_items+item_id;
}
/*:427*//*429:*/
#line 3206 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 3208 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3209 "./marpa.w"

return g->no_of_items;
}
/*:429*//*431:*/
#line 3215 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 3218 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3219 "./marpa.w"

/*629:*/
#line 5226 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:629*/
#line 3220 "./marpa.w"

return item_id2p(g,item_id)->rule->id;
}
/*:431*//*433:*/
#line 3226 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*625:*/
#line 5204 "./marpa.w"
const int failure_indicator= -2;

/*:625*/
#line 3229 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3230 "./marpa.w"

/*629:*/
#line 5226 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:629*/
#line 3231 "./marpa.w"

return item_id2p(g,item_id)->position;
}
/*:433*//*435:*/
#line 3237 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*625:*/
#line 5204 "./marpa.w"
const int failure_indicator= -2;

/*:625*/
#line 3240 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3241 "./marpa.w"

/*629:*/
#line 5226 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:629*/
#line 3242 "./marpa.w"

return item_id2p(g,item_id)->postdot;
}
/*:435*//*437:*/
#line 3247 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 3250 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3251 "./marpa.w"

/*629:*/
#line 5226 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:629*/
#line 3252 "./marpa.w"

return item_id2p(g,item_id)->sort_key;
}
/*:437*//*439:*/
#line 3259 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<(Marpa_AHFA_Item_ID)g->no_of_items&&item_id>=0;
}
/*:439*//*441:*/
#line 3274 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
Marpa_Rule_ID rule_id;
guint no_of_items;
guint no_of_rules= rule_count(g);
struct AHFA_item*base_item= g_new(struct AHFA_item,g->size);
struct AHFA_item*current_item= base_item;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
/*443:*/
#line 3294 "./marpa.w"

guint rhs_ix;
struct marpa_rule*rule= rule_id2p(g,rule_id);
if(!rule->is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->length;rhs_ix++){
/*444:*/
#line 3306 "./marpa.w"

Marpa_Symbol_ID rh_symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,rh_symbol_id);
if(symbol->is_nullable)goto NEXT_RH_SYMBOL;
current_item->sort_key= current_item-base_item;
current_item->postdot= rh_symbol_id;
current_item->rule= rule;
current_item->position= rhs_ix;

/*:444*/
#line 3299 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*445:*/
#line 3315 "./marpa.w"

current_item->sort_key= current_item-base_item;
current_item->postdot= current_item->position= -1;
current_item->rule= rule;

/*:445*/
#line 3303 "./marpa.w"

current_item++;

/*:443*/
#line 3283 "./marpa.w"

NEXT_RULE:;
}
no_of_items= g->no_of_items= current_item-base_item;
g->AHFA_items= g_renew(struct AHFA_item,base_item,no_of_items);
/*446:*/
#line 3325 "./marpa.w"
{
struct AHFA_item**items_by_rule= g_new0(struct AHFA_item*,no_of_rules);

struct AHFA_item*items= g->AHFA_items;
Marpa_Rule_ID highest_found_rule_id= -1;

Marpa_AHFA_Item_ID item_id;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){
struct AHFA_item*item= items+item_id;
Marpa_Rule_ID rule_id_for_item= item->rule->id;
if(rule_id_for_item<=highest_found_rule_id)continue;
items_by_rule[rule_id_for_item]= item;
highest_found_rule_id= rule_id_for_item;
}
g->AHFA_items_by_rule= items_by_rule;
}

/*:446*/
#line 3288 "./marpa.w"

/*450:*/
#line 3361 "./marpa.w"
{Marpa_AHFA_Item_ID item_id;
struct AHFA_item**sort_array= g_new(struct AHFA_item*,no_of_items);
struct AHFA_item*items= g->AHFA_items;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){



sort_array[item_id]= items+item_id;
}
g_qsort_with_data(sort_array,
(gint)no_of_items,sizeof(struct AHFA_item*),cmp_by_AHFA_item_id,(gpointer)NULL);
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){
sort_array[item_id]->sort_key= item_id;
}
g_free(sort_array);}

/*:450*/
#line 3289 "./marpa.w"

}
/*:441*//*448:*/
#line 3346 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED){
struct AHFA_item*a= *(struct AHFA_item**)ap;
struct AHFA_item*b= *(struct AHFA_item**)bp;
gint a_postdot= a->postdot;
gint b_postdot= b->postdot;
if(a_postdot==b_postdot)return a->sort_key-b->sort_key;
if(a_postdot<0)return 1;
if(b_postdot<0)return-1;
return a_postdot-b_postdot;
}
/*:448*//*464:*/
#line 3500 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{return g->AHFA+AHFA_state_id;}
/*:464*//*466:*/
#line 3509 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id){
return AHFA_state_id<g->AHFA_len&&AHFA_state_id>=0;
}
/*:466*//*468:*/
#line 3525 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix){
return state->items[item_ix]-g->AHFA_items;
}
/*:468*//*470:*/
#line 3535 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return g->AHFA_len;
}
/*:470*//*472:*/
#line 3542 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 3545 "./marpa.w"

struct AHFA_state*state;
/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3547 "./marpa.w"

/*630:*/
#line 5233 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:630*/
#line 3548 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->item_count;
}
/*:472*//*474:*/
#line 3555 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix){
struct AHFA_state*state;
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 3560 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3561 "./marpa.w"

/*630:*/
#line 5233 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:630*/
#line 3562 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
if(item_ix>=state->item_count){
context_clear(g);
context_int_add(g,"item_ix",(gint)item_ix);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid state item ix";
return failure_indicator;
}
return AHFA_state_item_ix2id(g,state,item_ix);
}
/*:474*//*476:*/
#line 3578 "./marpa.w"

gint
marpa_AHFA_state_transition_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 3581 "./marpa.w"

struct AHFA_state*state;
/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3583 "./marpa.w"

/*630:*/
#line 5233 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:630*/
#line 3584 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return g_sequence_get_length(state->transitions);
}
/*:476*//*479:*/
#line 3605 "./marpa.w"

struct marpa_AHFA_transition*marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
struct marpa_AHFA_transition*buffer){
GSequence*transitions;
GSequenceIter*iter;
GSequenceIter*end;
struct marpa_AHFA_transition*p_buffer= buffer;
/*623:*/
#line 5200 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:623*/
#line 3613 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3614 "./marpa.w"

/*630:*/
#line 5233 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:630*/
#line 3615 "./marpa.w"

transitions= AHFA_state_id2p(g,AHFA_state_id)->transitions;
end= g_sequence_get_end_iter(transitions);
for(iter= g_sequence_get_begin_iter(transitions);
!g_sequence_iter_is_end(iter);
iter= g_sequence_iter_next(iter)){
struct AHFA_transition*internal= g_sequence_get(iter);
p_buffer->symbol= internal->symbol;
p_buffer->to= internal->to;
p_buffer++;
}
return buffer;
}
/*:479*//*481:*/
#line 3634 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
struct AHFA_state*empty_transition_state;
/*625:*/
#line 5204 "./marpa.w"
const int failure_indicator= -2;

/*:625*/
#line 3639 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3640 "./marpa.w"

/*630:*/
#line 5233 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:630*/
#line 3641 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
empty_transition_state= state->empty_transition;
if(empty_transition_state)return empty_transition_state->id;
return-1;
}
/*:481*//*483:*/
#line 3651 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 3655 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3656 "./marpa.w"

/*630:*/
#line 5233 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:630*/
#line 3657 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->is_predict;
}
/*:483*//*485:*/
#line 3665 "./marpa.w"

gint marpa_AHFA_state_is_leo_completion(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
/*624:*/
#line 5202 "./marpa.w"
const int failure_indicator= -1;
/*:624*/
#line 3669 "./marpa.w"

/*626:*/
#line 5206 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:626*/
#line 3670 "./marpa.w"

/*630:*/
#line 5233 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:630*/
#line 3671 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->is_leo_completion;
}
/*:485*//*488:*/
#line 3694 "./marpa.w"

static gint AHFA_state_cmp(
gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED)
{
guint i;
struct AHFA_item**items_a;
struct AHFA_item**items_b;
const struct AHFA_state*state_a= (struct AHFA_state*)ap;
const struct AHFA_state*state_b= (struct AHFA_state*)bp;
guint length= state_a->item_count;
gint subkey= length-state_b->item_count;
if(subkey)return subkey;
if(length!=state_b->item_count)return FALSE;
items_a= state_a->items;
items_b= state_b->items;
for(i= 0;i<length;i++){
subkey= items_a[i]->sort_key-items_b[i]->sort_key;
if(subkey)return subkey;
}
return 0;
}
/*:488*//*490:*/
#line 3722 "./marpa.w"

static
void create_AHFA_states(struct marpa_g*g){
struct AHFA_state*p_working_state;
const guint initial_no_of_states= 2*g->size;
struct AHFA_item*AHFA_item_0_p= g->AHFA_items;
guint no_of_symbols= symbol_count(g);
guint no_of_rules= rule_count(g);
Bit_Matrix prediction_matrix;
struct marpa_rule**rule_by_sort_key= g_new(struct marpa_rule*,no_of_rules);
GSequence*duplicates;
struct AHFA_state**singleton_duplicates;
DQUEUE_DEFINE(states);
/*493:*/
#line 3784 "./marpa.w"
{guint item_id;
guint no_of_items_in_grammar= g->no_of_items;
duplicates= g_sequence_new(NULL);
singleton_duplicates= g_new(struct AHFA_state*,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++){
singleton_duplicates[item_id]= NULL;
}}
/*:493*/
#line 3735 "./marpa.w"

DQUEUE_INIT(states,struct AHFA_state,initial_no_of_states);
/*508:*/
#line 4046 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= matrix_create(no_of_symbols,no_of_symbols);
/*509:*/
#line 4054 "./marpa.w"

{Marpa_Rule_ID rule_id;
Marpa_Symbol_ID symbol_id;
struct AHFA_item**items_by_rule= g->AHFA_items_by_rule;
for(symbol_id= 0;symbol_id<(Marpa_Symbol_ID)no_of_symbols;symbol_id++){

struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(!SYMBOL_LHS_RULE_COUNT(symbol))continue;
matrix_bit_set(symbol_by_symbol_matrix,
(guint)symbol_id,(guint)symbol_id);
}
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
Marpa_Symbol_ID from,to;
struct AHFA_item*item= items_by_rule[rule_id];

struct marpa_rule*rule;
if(!item)continue;
rule= item->rule;
from= lhs_symbol_id(rule);
to= item->postdot;
if(to<0)continue;

matrix_bit_set(symbol_by_symbol_matrix,
(guint)from,(guint)to);
}}

/*:509*/
#line 4048 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*510:*/
#line 4086 "./marpa.w"
{
struct AHFA_item**items_by_rule= g->AHFA_items_by_rule;
Marpa_Symbol_ID from_symbol_id;
guint*sort_key_by_rule_id= g_new(guint,no_of_rules);
guint no_of_predictable_rules= 0;
/*511:*/
#line 4116 "./marpa.w"

{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
struct AHFA_item*item= items_by_rule[rule_id];
Marpa_Symbol_ID postdot;
if(!item)goto NOT_A_PREDICTABLE_RULE;
postdot= item->postdot;
if(postdot<0)goto NOT_A_PREDICTABLE_RULE;
sort_key_by_rule_id[rule_id]= postdot;
no_of_predictable_rules++;
continue;
NOT_A_PREDICTABLE_RULE:
sort_key_by_rule_id[rule_id]= G_MAXINT;
}}

/*:511*/
#line 4092 "./marpa.w"

/*512:*/
#line 4131 "./marpa.w"

{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
rule_by_sort_key[rule_id]= rule_id2p(g,rule_id);
}
g_qsort_with_data(rule_by_sort_key,(gint)no_of_rules,
sizeof(struct marpa_rule*),cmp_by_rule_sort_key,
(gpointer)sort_key_by_rule_id);
}

/*:512*/
#line 4093 "./marpa.w"

/*515:*/
#line 4161 "./marpa.w"
{
guint sort_key;
for(sort_key= 0;sort_key<no_of_rules;sort_key++){
struct marpa_rule*rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->id]= sort_key;
}}

/*:515*/
#line 4094 "./marpa.w"

/*516:*/
#line 4168 "./marpa.w"
{
prediction_matrix= matrix_create(no_of_symbols,no_of_predictable_rules);
for(from_symbol_id= 0;from_symbol_id<(Marpa_Symbol_ID)no_of_symbols;from_symbol_id++){

guint min,max,start;
for(start= 0;bv_scan(
matrix_row(symbol_by_symbol_matrix,(guint)from_symbol_id),
start,&min,&max);
start= max+2
){
Marpa_Symbol_ID to_symbol_id;
for(to_symbol_id= min;to_symbol_id<=(Marpa_Symbol_ID)max;to_symbol_id++){

struct marpa_symbol*to_symbol= symbol_id2p(g,to_symbol_id);
GArray*lhs_rules= to_symbol->lhs;
guint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){

Marpa_Rule_ID rule_with_this_lhs_symbol= g_array_index(lhs_rules,Marpa_Rule_ID,ix);
guint sort_key= sort_key_by_rule_id[rule_with_this_lhs_symbol];
if(sort_key>=no_of_predictable_rules)continue;

matrix_bit_set(prediction_matrix,(guint)from_symbol_id,sort_key);

}}}}}

/*:516*/
#line 4095 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:510*/
#line 4050 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:508*/
#line 3737 "./marpa.w"

/*495:*/
#line 3795 "./marpa.w"
{
struct AHFA_state*p_initial_state= DQUEUE_PUSH(states,struct AHFA_state);
Marpa_Rule_ID start_rule_id;
struct AHFA_item*start_item;
struct marpa_symbol*start_symbol= symbol_id2p(g,g->start_symbol_id);
struct marpa_symbol*start_alias
= symbol_null_alias(start_symbol);
gint no_of_items_in_state= start_alias?2:1;
struct AHFA_item**item_list
= obstack_alloc(&g->obs,no_of_items_in_state*sizeof(struct AHFA_item*));
start_rule_id= g_array_index(start_symbol->lhs,Marpa_Rule_ID,0);

start_item= g->AHFA_items_by_rule[start_rule_id];

item_list[0]= start_item;
if(start_alias){
Marpa_Rule_ID alias_rule_id
= g_array_index(start_alias->lhs,Marpa_Rule_ID,0);


item_list[1]= g->AHFA_items_by_rule[alias_rule_id];
}
p_initial_state->items= item_list;
p_initial_state->item_count= no_of_items_in_state;
p_initial_state->id= 0;
p_initial_state->is_predict= 0;
p_initial_state->is_leo_completion= 0;
p_initial_state->transitions= g_sequence_new(NULL);
p_initial_state->empty_transition= NULL;
if(!start_symbol->is_nulling){
p_initial_state->empty_transition
= create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(guint)start_item->postdot),
rule_by_sort_key,
&states,
duplicates);
}
}

/*:495*/
#line 3738 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,struct AHFA_state))){
/*492:*/
#line 3752 "./marpa.w"
{
guint no_of_items= p_working_state->item_count;
guint current_item_ix= 0;
struct AHFA_item**item_list;
Marpa_Symbol_ID working_symbol;
item_list= p_working_state->items;
working_symbol= item_list[0]->postdot;

if(working_symbol==-1)goto NEXT_AHFA_STATE;

while(1){
guint first_working_item_ix= current_item_ix;
guint no_of_items_in_new_state;
for(current_item_ix++;
current_item_ix<no_of_items;
current_item_ix++){
if(item_list[current_item_ix]->postdot!=working_symbol)break;
}
no_of_items_in_new_state= current_item_ix-first_working_item_ix;
if(no_of_items_in_new_state==1){
/*497:*/
#line 3836 "./marpa.w"
{
struct AHFA_state*p_new_state;
struct AHFA_item**new_state_item_list;
struct AHFA_item*single_item_p= item_list[first_working_item_ix];
Marpa_AHFA_Item_ID single_item_id;
Marpa_Symbol_ID postdot;
single_item_p++;
single_item_id= single_item_p-AHFA_item_0_p;
p_new_state= singleton_duplicates[single_item_id];
if(p_new_state){
AHFA_transition_add(g,p_working_state,working_symbol,p_new_state);
goto NEXT_WORKING_SYMBOL;
}
p_new_state= DQUEUE_PUSH(states,struct AHFA_state);

singleton_duplicates[single_item_id]= p_new_state;
new_state_item_list= p_new_state->items= obstack_alloc(&g->obs,sizeof(struct AHFA_item*));
new_state_item_list[0]= single_item_p;
p_new_state->item_count= 1;
p_new_state->is_predict= 0;
p_new_state->id= p_new_state-DQUEUE_BASE(states,struct AHFA_state);
p_new_state->transitions= g_sequence_new(NULL);
AHFA_transition_add(g,p_working_state,working_symbol,p_new_state);
postdot= single_item_p->postdot;
if(postdot>=0){
p_new_state->is_leo_completion= 0;


p_new_state->empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,(guint)postdot),
rule_by_sort_key,
&states,
duplicates);
}else{
p_new_state->empty_transition= NULL;
/*499:*/
#line 3900 "./marpa.w"
{
Marpa_Symbol_ID previous_nonnulling_symbol_id= single_item_p[-1].postdot;
p_new_state->is_leo_completion
= SYMBOL_LHS_RULE_COUNT(
symbol_id2p(g,previous_nonnulling_symbol_id)
)> 0;
}

/*:499*/
#line 3872 "./marpa.w"

}
}

/*:497*/
#line 3772 "./marpa.w"

}else{
/*500:*/
#line 3923 "./marpa.w"
{
struct AHFA_state*p_new_state;
guint predecessor_ix;
guint no_of_new_items_so_far= 0;
struct AHFA_item**item_list_for_new_state;
struct AHFA_state*queued_AHFA_state;
p_new_state= DQUEUE_PUSH(states,struct AHFA_state);
item_list_for_new_state= p_new_state->items= obstack_alloc(&g->obs,
no_of_items_in_new_state*sizeof(struct AHFA_item*));
p_new_state->item_count= no_of_items_in_new_state;
for(predecessor_ix= first_working_item_ix;
predecessor_ix<current_item_ix;
predecessor_ix++){
gint pre_insertion_point_ix= no_of_new_items_so_far-1;
struct AHFA_item*new_item_p= item_list[predecessor_ix]+1;
while(pre_insertion_point_ix>=0){
struct AHFA_item**current_item_pp= item_list_for_new_state+pre_insertion_point_ix;
if(new_item_p->sort_key>=(*current_item_pp)->sort_key)break;
*(current_item_pp+1)= *current_item_pp;
pre_insertion_point_ix--;
}
item_list_for_new_state[pre_insertion_point_ix+1]= new_item_p;
no_of_new_items_so_far++;
}
queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state){

(void)DQUEUE_POP(states,struct AHFA_state);
obstack_free(&g->obs,item_list_for_new_state);
AHFA_transition_add(g,p_working_state,working_symbol,queued_AHFA_state);


goto NEXT_WORKING_SYMBOL;
}

p_new_state->id= p_new_state-DQUEUE_BASE(states,struct AHFA_state);
p_new_state->is_predict= 0;
p_new_state->is_leo_completion= 0;
p_new_state->transitions= g_sequence_new(NULL);
AHFA_transition_add(g,p_working_state,working_symbol,p_new_state);
/*503:*/
#line 3990 "./marpa.w"
{
guint item_ix;
Marpa_Symbol_ID postdot= -1;
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++){
postdot= item_list_for_new_state[item_ix]->postdot;
if(postdot>=0)break;
}
p_new_state->empty_transition= NULL;
if(postdot>=0){
Bit_Vector predicted_rule_vector
= bv_shadow(matrix_row(prediction_matrix,(guint)postdot));
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++){

postdot= item_list_for_new_state[item_ix]->postdot;
if(postdot<0)continue;
bv_or_assign(predicted_rule_vector,
matrix_row(prediction_matrix,(guint)postdot));
}
p_new_state->empty_transition= create_predicted_AHFA_state(g,
predicted_rule_vector,
rule_by_sort_key,
&states,
duplicates);
}}

/*:503*/
#line 3964 "./marpa.w"

}

/*:500*/
#line 3774 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= item_list[current_item_ix]->postdot;
if(working_symbol==-1)break;
}
NEXT_AHFA_STATE:;
}

/*:492*/
#line 3740 "./marpa.w"

}
g->AHFA= DQUEUE_BASE(states,struct AHFA_state);

g->AHFA_len= DQUEUE_END(states);
g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*494:*/
#line 3791 "./marpa.w"

g_free(singleton_duplicates);
g_sequence_free(duplicates);

/*:494*/
#line 3747 "./marpa.w"

}
/*:490*//*501:*/
#line 3970 "./marpa.w"

static inline struct AHFA_state*assign_AHFA_state(
struct AHFA_state*state_p,GSequence*duplicates){
GSequenceIter*insertion_point
= g_sequence_search(duplicates,state_p,AHFA_state_cmp,NULL);
if(!g_sequence_iter_is_begin(insertion_point)){


struct AHFA_state*prev_state
= g_sequence_get(g_sequence_iter_prev(insertion_point));
if(!AHFA_state_cmp(prev_state,state_p,NULL))return prev_state;
}
g_sequence_insert_before(insertion_point,state_p);
return NULL;
}
/*:501*//*513:*/
#line 4141 "./marpa.w"
static gint
cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data){
struct marpa_rule*a= *(struct marpa_rule**)ap;
struct marpa_rule*b= *(struct marpa_rule**)bp;
guint*sort_key_by_rule_id= (guint*)user_data;
Marpa_Rule_ID a_id= a->id;
Marpa_Rule_ID b_id= b->id;
guint sort_key_a= sort_key_by_rule_id[a_id];
guint sort_key_b= sort_key_by_rule_id[b_id];
if(sort_key_a==sort_key_b)return a_id-b_id;
return sort_key_a-sort_key_b;
}
/*:513*//*517:*/
#line 4194 "./marpa.w"

static struct AHFA_state*
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
struct marpa_rule**rule_by_sort_key,
struct dqueue*states_p,
GSequence*duplicates
){
guint start,min,max;
struct AHFA_item**item_list;
struct AHFA_state*p_new_state;
guint item_list_ix= 0;
guint no_of_items_in_state= 0;
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2
){
no_of_items_in_state+= max-min+1;
}
if(no_of_items_in_state==0)return NULL;
item_list= obstack_alloc(&g->obs,no_of_items_in_state*sizeof(struct AHFA_item*));
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2
){
guint rule_sort_key;
for(rule_sort_key= min;
rule_sort_key<=max;
rule_sort_key++){

struct marpa_rule*rule= rule_by_sort_key[rule_sort_key];
item_list[item_list_ix++]= g->AHFA_items_by_rule[rule->id];
}
}
p_new_state= DQUEUE_PUSH((*states_p),struct AHFA_state);
p_new_state->items= item_list;
p_new_state->item_count= no_of_items_in_state;
{struct AHFA_state*queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);



if(queued_AHFA_state){
(void)DQUEUE_POP((*states_p),struct AHFA_state);
obstack_free(&g->obs,item_list);
return queued_AHFA_state;
}
}

p_new_state->id= p_new_state-DQUEUE_BASE((*states_p),struct AHFA_state);
p_new_state->is_predict= 1;
p_new_state->is_leo_completion= 0;
p_new_state->empty_transition= NULL;
p_new_state->transitions= g_sequence_new(NULL);
return p_new_state;
}
/*:517*//*521:*/
#line 4266 "./marpa.w"
static
gint cmp_AHFA_transition(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED){
gint subkey;
const struct AHFA_transition*a= ap;
const struct AHFA_transition*b= bp;
subkey= a->symbol-b->symbol;
if(subkey)return subkey;
return a->to-b->to;
}
/*:521*//*523:*/
#line 4280 "./marpa.w"
static inline
void AHFA_transition_add(struct marpa_g*g,
struct AHFA_state*from,Marpa_Symbol_ID symbol,struct AHFA_state*to){
struct AHFA_transition*transition= obstack_alloc(&g->obs,sizeof(struct AHFA_transition));
transition->symbol= symbol;
transition->to= to->id;
g_sequence_insert_sorted(from->transitions,transition,cmp_AHFA_transition,NULL);
}
/*:523*//*526:*/
#line 4323 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:526*//*528:*/
#line 4331 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:528*//*533:*/
#line 4364 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:533*//*535:*/
#line 4372 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:535*//*537:*/
#line 4388 "./marpa.w"

static inline Bit_Vector bv_create(guint bits)
{
guint size= bv_bits_to_size(bits);
guint bytes= (size+bv_hiddenwords)<<sizeof(guint);
guint*addr= (Bit_Vector)g_malloc0((size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}
/*:537*//*539:*/
#line 4405 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:539*//*541:*/
#line 4417 "./marpa.w"
static inline
Bit_Vector bv_clone(Bit_Vector bv)
{
guint bits;
Bit_Vector twin;
guint*p_twin;
bits= BV_BITS(bv);
p_twin= twin= bv_create(bits);
if(bits> 0)
{
gint count= BV_SIZE(bv);
while(count--)*p_twin++= *bv++;
}
return(twin);
}
/*:541*//*543:*/
#line 4437 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:543*//*545:*/
#line 4446 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:545*//*547:*/
#line 4454 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:547*//*550:*/
#line 4467 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:550*//*552:*/
#line 4475 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:552*//*554:*/
#line 4483 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:554*//*557:*/
#line 4492 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr)
{
guint size= BV_SIZE(addr);
gboolean r= TRUE;
if(size> 0){
*(addr+size-1)&= BV_MASK(addr);
while(r&&(size--> 0))r= (*addr++==0);
}
return(r);
}
/*:557*//*559:*/
#line 4509 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:559*//*561:*/
#line 4521 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:561*//*563:*/
#line 4533 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:563*//*565:*/
#line 4545 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:565*//*567:*/
#line 4557 "./marpa.w"

static inline
gboolean bv_scan(Bit_Vector bv,guint start,
guint*min,guint*max)
{
guint size= BV_SIZE(bv);
guint mask= BV_MASK(bv);
guint offset;
guint bitmask;
guint value;
gboolean empty;

if(size==0)return FALSE;
if(start>=BV_BITS(bv))return FALSE;
*min= start;
*max= start;
offset= start/bv_wordbits;
*(bv+size-1)&= mask;
bv+= offset;
size-= offset;
bitmask= (guint)1<<(start&bv_modmask);
mask= ~(bitmask|(bitmask-(guint)1));
value= *bv++;
if((value&bitmask)==0)
{
value&= mask;
if(value==0)
{
offset++;
empty= TRUE;
while(empty&&(--size> 0))
{
if((value= *bv++))empty= FALSE;else offset++;
}
if(empty)return FALSE;
}
start= offset*bv_wordbits;
bitmask= bv_lsb;
mask= value;
while(!(mask&bv_lsb))
{
bitmask<<= 1;
mask>>= 1;
start++;
}
mask= ~(bitmask|(bitmask-1));
*min= start;
*max= start;
}
value= ~value;
value&= mask;
if(value==0)
{
offset++;
empty= TRUE;
while(empty&&(--size> 0))
{
if((value= ~*bv++))empty= FALSE;else offset++;
}
if(empty)value= bv_lsb;
}
start= offset*bv_wordbits;
while(!(value&bv_lsb))
{
value>>= 1;
start++;
}
*max= --start;
return TRUE;
}
/*:567*//*573:*/
#line 4671 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv)
{
guint min,max,start= 0;
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_DEFINE(stack,Marpa_Symbol_ID);
FSTACK_INIT(stack,Marpa_Symbol_ID,symbol_count(g));
while(bv_scan(bv,start,&min,&max)){
guint symbol_id;
for(symbol_id= min;symbol_id<=max;symbol_id++){
*(FSTACK_PUSH(stack))= symbol_id;
}
start= max+2;
}
while((top_of_stack= FSTACK_POP(stack))){
guint rule_ix;
GArray*rules= symbol_id2p(g,*top_of_stack)->rhs;
for(rule_ix= 0;rule_ix<rules->len;rule_ix++){
Marpa_Rule_ID rule_id= g_array_index(rules,Marpa_Rule_ID,rule_ix);
struct marpa_rule*rule= rule_id2p(g,rule_id);
guint rule_length;
guint rh_ix;
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
if(bv_bit_test(bv,(guint)lhs_id))goto NEXT_RULE;
rule_length= rule->length;
for(rh_ix= 0;rh_ix<rule_length;rh_ix++){
if(!bv_bit_test(bv,(guint)rhs_symbol_id(rule,rh_ix)))goto NEXT_RULE;
}



bv_bit_set(bv,(guint)lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}
/*:573*//*578:*/
#line 4740 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns)
{
guint bv_data_words= bv_bits_to_size(columns);
guint row_bytes= (bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
guint bv_mask= bv_bits_to_unused_mask(columns);
Bit_Vector_Word*matrix_addr= g_malloc0((size_t)(row_bytes*rows));
guint row;
for(row= 0;row<rows;row++){
guint row_start= row*(bv_data_words+bv_hiddenwords);
matrix_addr[row_start]= columns;
matrix_addr[row_start+1]= bv_data_words;
matrix_addr[row_start+2]= bv_mask;
}
return matrix_addr;
}
/*:578*//*580:*/
#line 4760 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:580*//*582:*/
#line 4773 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:582*//*584:*/
#line 4790 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:584*//*587:*/
#line 4800 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:587*//*590:*/
#line 4809 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:590*//*593:*/
#line 4818 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:593*//*595:*/
#line 4832 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix)
{
struct transition{guint from,to;}*top_of_stack= NULL;
guint size= matrix_columns(matrix);
guint row;
DSTACK_DEFINE(stack);
DSTACK_INIT(stack,struct transition,1024);
for(row= 0;row<size;row++){
guint min,max,start;
Bit_Vector row_vector= matrix_row(matrix,row);
for(start= 0;bv_scan(row_vector,start,&min,&max);start= max+2){
guint column;
for(column= min;column<=max;column++){
struct transition*t= DSTACK_PUSH(stack,struct transition);
t->from= row;
t->to= column;
}}}
while((top_of_stack= DSTACK_POP(stack,struct transition))){
guint old_from= top_of_stack->from;
guint old_to= top_of_stack->to;
guint new_ix;
for(new_ix= 0;new_ix<size;new_ix++){



if(!matrix_bit_test(matrix,new_ix,old_to)&&
matrix_bit_test(matrix,new_ix,old_from)){
struct transition*t= (DSTACK_PUSH(stack,struct transition));
matrix_bit_set(matrix,new_ix,old_to);
t->from= new_ix;
t->to= old_to;
}
if(!matrix_bit_test(matrix,old_from,new_ix)&&
matrix_bit_test(matrix,old_to,new_ix)){
struct transition*t= (DSTACK_PUSH(stack,struct transition));
matrix_bit_set(matrix,old_from,new_ix);
t->from= old_from;
t->to= new_ix;
}
}
}
DSTACK_DESTROY(stack);
}
/*:595*//*598:*/
#line 4886 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa){
void*data= pa->data;
if(data)g_free(data);
}
/*:598*//*601:*/
#line 4905 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size){
dpa->pa.len= 0;dpa->size= size;dpa->pa.data= g_new(void*,size);}
/*:601*//*603:*/
#line 4910 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa){
p_array_destroy(&(dpa->pa));
}
/*:603*//*605:*/
#line 4916 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size){
dpa->pa.data= g_renew(void*,dpa->pa.data,new_size);
dpa->size= new_size;
}
/*:605*//*607:*/
#line 4923 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p){
if(dpa->pa.len>=dpa->size)dp_array_resize(dpa,dpa->size*2);
dpa->pa.data[dpa->pa.len++]= p;
}
/*:607*//*609:*/
#line 4932 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa){
gint len= pa->len= dpa->pa.len;
if(G_UNLIKELY(len>=dpa->size)){
pa->data= dpa->pa.data;
return;
}
pa->data= g_renew(void*,dpa->pa.data,len);
}
/*:609*//*615:*/
#line 5001 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:615*//*637:*/
#line 5305 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->message_callback_arg= cb_arg;}
void*marpa_message_callback_arg(struct marpa_g*g)
{return g->message_callback_arg;}
/*:637*//*639:*/
#line 5319 "./marpa.w"

static inline void message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:639*/
#line 5425 "./marpa.w"





/*:647*/
