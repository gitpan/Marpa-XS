/*589:*/
#line 4573 "./marpa.w"

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
#define DQUEUE_ADD(this,type) DSTACK_PUSH(this.s,type) 
#define DQUEUE_NEXT(this,type)  \
(this.current>=DSTACK_LENGTH(this.s) ?NULL:(DSTACK_BASE(this.s,type) ) +this.current++) 
#define DQUEUE_BASE(this,type) DSTACK_BASE(this.s,type) 
#define DQUEUE_END(this) DSTACK_LENGTH(this.s) 
#define STOLEN_DQUEUE_DATA_FREE(data) STOLEN_DSTACK_DATA_FREE(data)  \

#define obstack_chunk_alloc g_malloc
#define obstack_chunk_free g_free \


#line 4598 "./marpa.w"

#include "marpa_obs.h"
/*575:*/
#line 4444 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:575*/
#line 4600 "./marpa.w"

/*478:*/
#line 3619 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:478*//*521:*/
#line 3990 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:521*/
#line 4601 "./marpa.w"

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
/*:29*//*479:*/
#line 3626 "./marpa.w"

static const int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const int bv_hiddenwords= 3;
static const int bv_lsb= 1u;
static const int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:479*/
#line 4602 "./marpa.w"

/*542:*/
#line 4142 "./marpa.w"

struct p_array{gint len;void**data;};
/*:542*//*545:*/
#line 4161 "./marpa.w"

struct dp_array{struct p_array pa;gint size;};
/*:545*/
#line 4603 "./marpa.w"

/*21:*/
#line 444 "./marpa.w"
struct marpa_g{
/*33:*/
#line 494 "./marpa.w"
GArray*symbols;
/*:33*//*45:*/
#line 550 "./marpa.w"
GArray*rules;
/*:45*//*83:*/
#line 730 "./marpa.w"
GHashTable*context;
/*:83*//*98:*/
#line 815 "./marpa.w"
struct obstack obs;
/*:98*//*102:*/
#line 831 "./marpa.w"
Marpa_Error_ID error;
/*:102*//*189:*/
#line 1257 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
void*symbol_callback_arg;
/*:189*//*296:*/
#line 1957 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
void*rule_callback_arg;
/*:296*//*418:*/
#line 3155 "./marpa.w"

struct AHFA_item*AHFA_items;
struct AHFA_item**AHFA_items_by_rule;
/*:418*//*447:*/
#line 3380 "./marpa.w"
struct AHFA_state*AHFA;
/*:447*//*578:*/
#line 4484 "./marpa.w"

Marpa_Message_Callback*message_callback;
void*message_callback_arg;
/*:578*/
#line 445 "./marpa.w"

/*27:*/
#line 477 "./marpa.w"
int id;
/*:27*//*57:*/
#line 606 "./marpa.w"
Marpa_Symbol_ID start_symbol_id;
/*:57*//*64:*/
#line 653 "./marpa.w"
int size;
/*:64*//*67:*/
#line 666 "./marpa.w"
guint max_rule_length;
/*:67*//*419:*/
#line 3158 "./marpa.w"

guint no_of_items;
/*:419*//*448:*/
#line 3381 "./marpa.w"
gint AHFA_len;
/*:448*/
#line 446 "./marpa.w"

/*69:*/
#line 671 "./marpa.w"
unsigned int is_precomputed:1;
/*:69*//*73:*/
#line 682 "./marpa.w"
unsigned int has_loop:1;
/*:73*//*77:*/
#line 697 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:77*/
#line 447 "./marpa.w"

};

/*:21*//*113:*/
#line 878 "./marpa.w"

struct marpa_symbol{
/*122:*/
#line 923 "./marpa.w"
GArray*lhs;
/*:122*//*129:*/
#line 952 "./marpa.w"
GArray*rhs;
/*:129*//*176:*/
#line 1149 "./marpa.w"

struct marpa_symbol*alias;
/*:176*/
#line 880 "./marpa.w"

/*120:*/
#line 915 "./marpa.w"
Marpa_Symbol_ID id;
/*:120*/
#line 881 "./marpa.w"

/*136:*/
#line 973 "./marpa.w"
unsigned int is_accessible:1;
/*:136*//*142:*/
#line 999 "./marpa.w"
unsigned int is_counted:1;
/*:142*//*146:*/
#line 1017 "./marpa.w"
unsigned int is_nullable:1;
/*:146*//*152:*/
#line 1042 "./marpa.w"
unsigned int is_nulling:1;
/*:152*//*158:*/
#line 1069 "./marpa.w"
unsigned int is_terminal:1;
/*:158*//*164:*/
#line 1095 "./marpa.w"
unsigned int is_productive:1;
/*:164*//*170:*/
#line 1120 "./marpa.w"
unsigned int is_start:1;
/*:170*//*175:*/
#line 1146 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:175*/
#line 882 "./marpa.w"

};

/*:113*//*195:*/
#line 1284 "./marpa.w"

struct marpa_rule{
/*229:*/
#line 1669 "./marpa.w"
guint length;
/*:229*//*249:*/
#line 1736 "./marpa.w"
Marpa_Rule_ID id;
/*:249*//*290:*/
#line 1938 "./marpa.w"
gint virtual_start;
/*:290*//*292:*/
#line 1945 "./marpa.w"
gint virtual_end;
/*:292*//*306:*/
#line 1989 "./marpa.w"
Marpa_Rule_ID original;
/*:306*//*311:*/
#line 2003 "./marpa.w"
guint real_symbol_count;
/*:311*/
#line 1286 "./marpa.w"

/*252:*/
#line 1748 "./marpa.w"
unsigned int is_discard:1;
/*:252*//*266:*/
#line 1832 "./marpa.w"
unsigned int is_loop:1;
/*:266*//*271:*/
#line 1853 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:271*//*278:*/
#line 1883 "./marpa.w"
unsigned int is_used:1;
/*:278*//*282:*/
#line 1913 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:282*//*286:*/
#line 1924 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:286*//*315:*/
#line 2012 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:315*/
#line 1287 "./marpa.w"

/*230:*/
#line 1672 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:230*/
#line 1288 "./marpa.w"

};
/*:195*//*417:*/
#line 3142 "./marpa.w"

struct AHFA_item{
Marpa_Symbol_ID postdot;

Marpa_AHFA_Item_ID sort_key;
struct marpa_rule*rule;
gint position;
};
/*:417*//*446:*/
#line 3374 "./marpa.w"

struct AHFA_state{
struct AHFA_item**items;
guint item_count;
unsigned int is_reset:1;
};
/*:446*//*559:*/
#line 4257 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:559*//*562:*/
#line 4287 "./marpa.w"

struct dqueue{gint current;struct dstack s;};

/*:562*/
#line 4604 "./marpa.w"

/*39:*/
#line 513 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g);

/*:39*//*41:*/
#line 521 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id);

/*:41*//*44:*/
#line 543 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:44*//*51:*/
#line 569 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g);

/*:51*//*53:*/
#line 577 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id);

/*:53*//*56:*/
#line 601 "./marpa.w"

static inline gint rule_is_valid(
struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:56*//*91:*/
#line 781 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:91*//*93:*/
#line 793 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:93*//*95:*/
#line 802 "./marpa.w"

static inline void context_clear(struct marpa_g*g);

/*:95*//*115:*/
#line 899 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:115*//*119:*/
#line 911 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol);

/*:119*//*128:*/
#line 943 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:128*//*135:*/
#line 969 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);

/*:135*//*173:*/
#line 1133 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol);
/*:173*//*179:*/
#line 1174 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol);
/*:179*//*182:*/
#line 1202 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol);
/*:182*//*185:*/
#line 1241 "./marpa.w"

static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
/*:185*//*193:*/
#line 1278 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:193*//*197:*/
#line 1294 "./marpa.w"

static inline guint rule_sizeof(guint length);

/*:197*//*201:*/
#line 1318 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:201*//*218:*/
#line 1537 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length);

/*:218*//*228:*/
#line 1661 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule);

/*:228*//*234:*/
#line 1686 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:234*//*238:*/
#line 1698 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:238*//*242:*/
#line 1710 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:242*//*246:*/
#line 1723 "./marpa.w"

static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule*rule);
/*:246*//*248:*/
#line 1730 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,guint rh_index);

/*:248*//*259:*/
#line 1797 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule);
/*:259*//*263:*/
#line 1821 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule);
/*:263*//*277:*/
#line 1879 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule);

/*:277*//*304:*/
#line 1982 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:304*//*323:*/
#line 2119 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:323*//*360:*/
#line 2458 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:360*//*399:*/
#line 2825 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:399*//*402:*/
#line 2846 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:402*//*410:*/
#line 2963 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:410*//*422:*/
#line 3173 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:422*//*434:*/
#line 3236 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:434*//*436:*/
#line 3263 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:436*//*443:*/
#line 3329 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:443*//*451:*/
#line 3389 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:451*//*453:*/
#line 3399 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:453*//*455:*/
#line 3415 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix);

/*:455*//*465:*/
#line 3493 "./marpa.w"

static inline void create_AHFA_states(struct marpa_g*g);

/*:465*//*481:*/
#line 3639 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:481*//*483:*/
#line 3649 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:483*//*485:*/
#line 3669 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);

/*:485*//*487:*/
#line 3680 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:487*//*489:*/
#line 3702 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:489*//*491:*/
#line 3712 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:491*//*493:*/
#line 3720 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:493*//*495:*/
#line 3733 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:495*//*498:*/
#line 3741 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:498*//*500:*/
#line 3749 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:500*//*502:*/
#line 3757 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:502*//*505:*/
#line 3774 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:505*//*507:*/
#line 3787 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:507*//*509:*/
#line 3799 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:509*//*511:*/
#line 3811 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:511*//*513:*/
#line 3885 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:513*//*519:*/
#line 3967 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:519*//*524:*/
#line 4014 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:524*//*526:*/
#line 4022 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:526*//*528:*/
#line 4036 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:528*//*530:*/
#line 4054 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:530*//*533:*/
#line 4063 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:533*//*536:*/
#line 4072 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:536*//*539:*/
#line 4081 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:539*//*541:*/
#line 4134 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:541*//*544:*/
#line 4149 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa);

/*:544*//*547:*/
#line 4166 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size);
/*:547*//*549:*/
#line 4172 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa);
/*:549*//*551:*/
#line 4179 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size);
/*:551*//*553:*/
#line 4186 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p);
/*:553*//*555:*/
#line 4199 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa);


/*:555*//*561:*/
#line 4265 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:561*//*582:*/
#line 4505 "./marpa.w"

static inline void message(struct marpa_g*g,Marpa_Message_ID id);

/*:582*/
#line 4605 "./marpa.w"

/*42:*/
#line 527 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symbol_id,
struct marpa_symbol*symbol)
{
g_array_insert_val(g->symbols,(unsigned)symbol_id,symbol);
}

/*:42*//*54:*/
#line 583 "./marpa.w"

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
#line 4606 "./marpa.w"

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
#line 551 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(struct marpa_rule*));
/*:46*//*58:*/
#line 607 "./marpa.w"

g->start_symbol_id= -1;
/*:58*//*65:*/
#line 654 "./marpa.w"

g->size= 0;

/*:65*//*68:*/
#line 667 "./marpa.w"

g->max_rule_length= 0;

/*:68*//*70:*/
#line 672 "./marpa.w"

g->is_precomputed= FALSE;
/*:70*//*74:*/
#line 683 "./marpa.w"

g->has_loop= FALSE;
/*:74*//*78:*/
#line 698 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:78*//*84:*/
#line 731 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:84*//*99:*/
#line 816 "./marpa.w"
obstack_init(&g->obs);
/*:99*//*103:*/
#line 832 "./marpa.w"

g->error= 0;
/*:103*/
#line 453 "./marpa.w"

return g;}
/*:22*//*24:*/
#line 458 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g)
{/*35:*/
#line 497 "./marpa.w"
g_array_free(g->symbols,TRUE);

/*:35*//*47:*/
#line 553 "./marpa.w"
g_array_free(g->rules,TRUE);

/*:47*//*85:*/
#line 733 "./marpa.w"
g_hash_table_destroy(g->context);

/*:85*//*100:*/
#line 817 "./marpa.w"
obstack_free(&g->obs,NULL);

/*:100*//*117:*/
#line 905 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->symbols->len;id++)
{marpa_symbol_free(symbol_id2p(g,id));}}
/*:117*//*226:*/
#line 1652 "./marpa.w"

{Marpa_Rule_ID id;for(id= 0;id<(Marpa_Rule_ID)g->rules->len;id++)
{marpa_rule_free(rule_id2p(g,id));}}
/*:226*//*420:*/
#line 3163 "./marpa.w"
if(g->AHFA_items){
g_free(g->AHFA_items_by_rule);
g_free(g->AHFA_items);
};

/*:420*//*449:*/
#line 3382 "./marpa.w"
if(g->AHFA){STOLEN_DQUEUE_DATA_FREE(g->AHFA);}

/*:449*/
#line 460 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:24*//*31:*/
#line 482 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->id;}
/*:31*//*36:*/
#line 502 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:36*//*38:*/
#line 509 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g){
return g->symbols->len;
}
/*:38*//*40:*/
#line 517 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id)
{return g_array_index(g->symbols,struct marpa_symbol*,id);}
/*:40*//*43:*/
#line 538 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id){
return symbol_id>=0&&(guint)symbol_id<g->symbols->len;
}
/*:43*//*48:*/
#line 558 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:48*//*50:*/
#line 565 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g){
return g->rules->len;
}
/*:50*//*52:*/
#line 573 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id)
{return g_array_index(g->rules,struct marpa_rule*,id);}
/*:52*//*55:*/
#line 596 "./marpa.w"

static inline gint rule_is_valid(
struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_id>=0&&(guint)rule_id<g->rules->len;
}
/*:55*//*59:*/
#line 610 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->start_symbol_id;}
/*:59*//*61:*/
#line 617 "./marpa.w"

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
#line 675 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{return g->is_precomputed;}
/*:71*//*75:*/
#line 686 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->has_loop;}
/*:75*//*79:*/
#line 701 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:79*//*81:*/
#line 708 "./marpa.w"

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
#line 772 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:90*//*92:*/
#line 784 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:92*//*94:*/
#line 799 "./marpa.w"

static inline void context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:94*//*96:*/
#line 805 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:96*//*105:*/
#line 840 "./marpa.w"

Marpa_Error_ID marpa_error(const struct marpa_g*g)
{return g->error?g->error:"unknown error";}
/*:105*//*108:*/
#line 854 "./marpa.w"

void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

return;

}

/*:108*//*110:*/
#line 870 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce G_GNUC_UNUSED){}
/*:110*//*114:*/
#line 885 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*121:*/
#line 916 "./marpa.w"
symbol->id= g->symbols->len;

/*:121*//*123:*/
#line 924 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:123*//*130:*/
#line 953 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:130*//*137:*/
#line 974 "./marpa.w"

symbol->is_accessible= FALSE;
/*:137*//*143:*/
#line 1000 "./marpa.w"

symbol->is_counted= FALSE;
/*:143*//*147:*/
#line 1018 "./marpa.w"

symbol->is_nullable= FALSE;
/*:147*//*153:*/
#line 1043 "./marpa.w"

symbol->is_nulling= FALSE;
/*:153*//*159:*/
#line 1070 "./marpa.w"

symbol->is_terminal= FALSE;
/*:159*//*165:*/
#line 1096 "./marpa.w"

symbol->is_productive= FALSE;
/*:165*//*171:*/
#line 1121 "./marpa.w"
symbol->is_start= FALSE;
/*:171*//*177:*/
#line 1151 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:177*/
#line 889 "./marpa.w"

{Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);}
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;}

/*:114*//*118:*/
#line 908 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol)
{/*124:*/
#line 926 "./marpa.w"
g_array_free(symbol->lhs,TRUE);
/*:124*//*131:*/
#line 955 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:131*/
#line 910 "./marpa.w"
g_free(symbol);}
/*:118*//*125:*/
#line 930 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*566:*/
#line 4385 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:566*/
#line 932 "./marpa.w"

/*570:*/
#line 4397 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:570*/
#line 933 "./marpa.w"

return symbol_id2p(g,symbol_id)->lhs;}
/*:125*//*127:*/
#line 937 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:127*//*132:*/
#line 959 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*566:*/
#line 4385 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:566*/
#line 961 "./marpa.w"

/*570:*/
#line 4397 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:570*/
#line 962 "./marpa.w"

return symbol_id2p(g,symbol_id)->rhs;}
/*:132*//*134:*/
#line 966 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
/*:134*//*138:*/
#line 984 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:138*//*140:*/
#line 990 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:140*//*144:*/
#line 1010 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:144*//*148:*/
#line 1028 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:148*//*150:*/
#line 1034 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:150*//*154:*/
#line 1053 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1055 "./marpa.w"

/*570:*/
#line 4397 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:570*/
#line 1056 "./marpa.w"

return symbol_id2p(g,symbol_id)->is_nulling;}
/*:154*//*156:*/
#line 1061 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:156*//*160:*/
#line 1080 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:160*//*162:*/
#line 1086 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:162*//*166:*/
#line 1106 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:166*//*168:*/
#line 1112 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value;}
/*:168*//*172:*/
#line 1124 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1129 "./marpa.w"

/*570:*/
#line 4397 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:570*/
#line 1130 "./marpa.w"

return symbol_is_start(symbol_id2p(g,symbol_id));
}
/*:172*//*178:*/
#line 1160 "./marpa.w"

static inline
struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol)
{return symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*proper_alias;
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1168 "./marpa.w"

/*570:*/
#line 4397 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:570*/
#line 1169 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->id;
}
/*:178*//*181:*/
#line 1183 "./marpa.w"

static inline
struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*alias;
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1191 "./marpa.w"

/*570:*/
#line 4397 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:570*/
#line 1192 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
alias= symbol_null_alias(symbol);
if(alias==NULL){
context_int_add(g,"symbol_id",symbol_id);
g->error= "no alias";
return-1;
}
return alias->id;
}
/*:181*//*184:*/
#line 1216 "./marpa.w"
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
/*:184*//*190:*/
#line 1260 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->symbol_callback_arg= cb_arg;}
void*marpa_symbol_callback_arg(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:190*//*192:*/
#line 1274 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:192*//*196:*/
#line 1290 "./marpa.w"

static inline guint rule_sizeof(guint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:196*//*200:*/
#line 1304 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
struct marpa_rule*rule;
/*231:*/
#line 1673 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{guint rh_index;for(rh_index= 0;rh_index<length;rh_index++){
if(!symbol_is_valid(g,rhs[rh_index])){return NULL;}
}}
/*:231*/
#line 1310 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*232:*/
#line 1678 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{guint i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:232*/
#line 1312 "./marpa.w"

/*250:*/
#line 1737 "./marpa.w"
rule->id= g->rules->len;

/*:250*//*253:*/
#line 1749 "./marpa.w"

rule->is_discard= FALSE;
/*:253*//*267:*/
#line 1833 "./marpa.w"

rule->is_loop= FALSE;
/*:267*//*272:*/
#line 1854 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:272*//*279:*/
#line 1884 "./marpa.w"

rule->is_used= TRUE;
/*:279*//*283:*/
#line 1914 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:283*//*287:*/
#line 1925 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:287*//*291:*/
#line 1939 "./marpa.w"
rule->virtual_start= -1;

/*:291*//*293:*/
#line 1946 "./marpa.w"
rule->virtual_end= -1;

/*:293*//*307:*/
#line 1990 "./marpa.w"
rule->original= -1;
/*:307*//*312:*/
#line 2004 "./marpa.w"
rule->real_symbol_count= 0;
/*:312*//*316:*/
#line 2013 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:316*/
#line 1313 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*220:*/
#line 1554 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const guint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*224:*/
#line 1621 "./marpa.w"

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
#line 1562 "./marpa.w"

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
#line 1315 "./marpa.w"

return rule;
}
/*:200*//*202:*/
#line 1323 "./marpa.w"

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
#line 1340 "./marpa.w"

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
#line 1375 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*205:*/
#line 1373 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1377 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:206*/
#line 1353 "./marpa.w"

/*207:*/
#line 1381 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:207*/
#line 1354 "./marpa.w"

/*208:*/
#line 1385 "./marpa.w"

symbol_id2p(g,rhs_id)->is_counted= 1;
if(separator_id>=0){symbol_id2p(g,separator_id)->is_counted= 1;}
/*:208*/
#line 1355 "./marpa.w"

if(min==0){/*209:*/
#line 1388 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*205:*/
#line 1373 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1390 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:209*/
#line 1356 "./marpa.w"
}
min= 1;
/*210:*/
#line 1395 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:210*/
#line 1358 "./marpa.w"

/*211:*/
#line 1409 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:211*/
#line 1359 "./marpa.w"

/*213:*/
#line 1412 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*205:*/
#line 1373 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1416 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:213*/
#line 1360 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*214:*/
#line 1425 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*205:*/
#line 1373 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1430 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:214*/
#line 1362 "./marpa.w"

}
/*215:*/
#line 1442 "./marpa.w"

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
#line 1373 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1452 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:215*/
#line 1364 "./marpa.w"

/*216:*/
#line 1457 "./marpa.w"

{struct marpa_rule*rule;
guint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*205:*/
#line 1373 "./marpa.w"
g->error= "internal_error";return-1;
/*:205*/
#line 1464 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:216*/
#line 1365 "./marpa.w"

/*212:*/
#line 1411 "./marpa.w"
g_free(temp_rhs);
/*:212*/
#line 1366 "./marpa.w"

return original_rule_id;
}
/*:203*//*217:*/
#line 1513 "./marpa.w"

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
/*:217*//*227:*/
#line 1656 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule)
{

g_free(rule);}
/*:227*//*233:*/
#line 1683 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
/*:233*//*235:*/
#line 1688 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1690 "./marpa.w"

/*571:*/
#line 4404 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:571*/
#line 1691 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:235*//*237:*/
#line 1695 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:237*//*239:*/
#line 1700 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*566:*/
#line 4385 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:566*/
#line 1702 "./marpa.w"

/*571:*/
#line 4404 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:571*/
#line 1703 "./marpa.w"

return rule_rhs_get(rule_id2p(g,rule_id));}
/*:239*//*241:*/
#line 1707 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:241*//*243:*/
#line 1712 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1714 "./marpa.w"

/*571:*/
#line 4404 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:571*/
#line 1715 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:243*//*245:*/
#line 1720 "./marpa.w"

static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule*rule){return rule->symbols[0];}
/*:245*//*247:*/
#line 1725 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,guint rh_index){
return rule->symbols[rh_index+1];
}
/*:247*//*254:*/
#line 1751 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:254*//*258:*/
#line 1784 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule)
{
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
return symbol_id2p(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1791 "./marpa.w"

struct marpa_rule*rule;
/*571:*/
#line 4404 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:571*/
#line 1793 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:258*//*262:*/
#line 1804 "./marpa.w"

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
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1815 "./marpa.w"

struct marpa_rule*rule;
/*571:*/
#line 4404 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:571*/
#line 1817 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:262*//*268:*/
#line 1837 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1840 "./marpa.w"

/*571:*/
#line 4404 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:571*/
#line 1841 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:268*//*273:*/
#line 1858 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1861 "./marpa.w"

/*571:*/
#line 4404 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:571*/
#line 1862 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:273*//*276:*/
#line 1870 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:276*//*280:*/
#line 1888 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 1891 "./marpa.w"

/*571:*/
#line 4404 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:571*/
#line 1892 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:280*//*284:*/
#line 1917 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:284*//*288:*/
#line 1928 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:288*//*297:*/
#line 1960 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:297*//*299:*/
#line 1965 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:299*//*301:*/
#line 1970 "./marpa.w"

void*marpa_rule_callback_arg(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:301*//*303:*/
#line 1978 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:303*//*308:*/
#line 1991 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}
/*:308*//*313:*/
#line 2005 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}
/*:313*//*317:*/
#line 2024 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:317*//*319:*/
#line 2043 "./marpa.w"

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
/*:319*//*322:*/
#line 2089 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*324:*/
#line 2121 "./marpa.w"

guint pre_rewrite_rule_count= g->rules->len;
guint pre_rewrite_symbol_count= g->symbols->len;

/*:324*//*329:*/
#line 2154 "./marpa.w"

Marpa_Symbol_ID original_start_symbol_id= g->start_symbol_id;
struct marpa_symbol*original_start_symbol;

/*:329*//*333:*/
#line 2191 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:333*//*339:*/
#line 2250 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:339*//*341:*/
#line 2277 "./marpa.w"

Bit_Vector nullable_v;
/*:341*//*345:*/
#line 2303 "./marpa.w"

Bit_Vector productive_v;
/*:345*//*348:*/
#line 2344 "./marpa.w"
Bit_Matrix reach_matrix;
/*:348*//*351:*/
#line 2362 "./marpa.w"

Bit_Vector accessible_v;

/*:351*/
#line 2092 "./marpa.w"

/*325:*/
#line 2125 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:325*/
#line 2093 "./marpa.w"

/*326:*/
#line 2132 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:326*/
#line 2094 "./marpa.w"

/*328:*/
#line 2138 "./marpa.w"

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
/*:328*/
#line 2095 "./marpa.w"

/*330:*/
#line 2158 "./marpa.w"

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
/*:330*/
#line 2096 "./marpa.w"

/*331:*/
#line 2177 "./marpa.w"

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
/*:331*/
#line 2097 "./marpa.w"

if(have_marked_terminals){
/*335:*/
#line 2206 "./marpa.w"

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

/*:335*/
#line 2099 "./marpa.w"

}else{
/*334:*/
#line 2195 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:334*/
#line 2101 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*336:*/
#line 2230 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<(Marpa_Symbol_ID)g->symbols->len;symbol_id++)
{symbol_id2p(g,symbol_id)->is_terminal= 1;}}
/*:336*/
#line 2103 "./marpa.w"

}else{
/*337:*/
#line 2235 "./marpa.w"

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
/*:337*/
#line 2105 "./marpa.w"

}
}
/*340:*/
#line 2255 "./marpa.w"

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
/*:340*/
#line 2108 "./marpa.w"

/*343:*/
#line 2282 "./marpa.w"

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
/*:343*/
#line 2109 "./marpa.w"

/*344:*/
#line 2296 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->start_symbol_id))
{
context_int_add(g,"symbol_id",g->start_symbol_id);
g->error= "unproductive start symbol";
return NULL;
}
/*:344*/
#line 2110 "./marpa.w"

/*347:*/
#line 2326 "./marpa.w"

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
/*:347*/
#line 2111 "./marpa.w"

/*350:*/
#line 2348 "./marpa.w"

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
/*:350*/
#line 2112 "./marpa.w"

/*352:*/
#line 2367 "./marpa.w"

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

/*:352*/
#line 2113 "./marpa.w"

/*332:*/
#line 2189 "./marpa.w"

bv_free(terminal_v);
/*:332*//*338:*/
#line 2247 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:338*//*342:*/
#line 2279 "./marpa.w"

bv_free(nullable_v);

/*:342*//*346:*/
#line 2305 "./marpa.w"

bv_free(productive_v);

/*:346*/
#line 2114 "./marpa.w"

/*349:*/
#line 2345 "./marpa.w"

matrix_free(reach_matrix);

/*:349*/
#line 2115 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:322*//*359:*/
#line 2437 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*361:*/
#line 2460 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:361*//*365:*/
#line 2511 "./marpa.w"

guint factor_count;
guint*factor_positions;
/*:365*//*370:*/
#line 2560 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:370*/
#line 2440 "./marpa.w"

/*366:*/
#line 2514 "./marpa.w"

factor_positions= g_new(guint,g->max_rule_length);
/*:366*//*371:*/
#line 2563 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:371*/
#line 2441 "./marpa.w"

/*363:*/
#line 2472 "./marpa.w"

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

/*:363*/
#line 2442 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
guint rule_length= rule->length;
guint nullable_suffix_ix= 0;
/*362:*/
#line 2464 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:362*/
#line 2448 "./marpa.w"

/*364:*/
#line 2495 "./marpa.w"

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
/*:364*/
#line 2449 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*368:*/
#line 2520 "./marpa.w"

rule->is_used= 0;
{guint unprocessed_factor_count;

guint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= lhs_symbol_id(rule);
guint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*374:*/
#line 2573 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symbol_id;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*369:*/
#line 2539 "./marpa.w"
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

/*:369*/
#line 2581 "./marpa.w"

/*375:*/
#line 2600 "./marpa.w"

{
guint remaining_rhs_length,piece_rhs_length;
/*376:*/
#line 2612 "./marpa.w"

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
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2624 "./marpa.w"

}

/*:376*/
#line 2603 "./marpa.w"
;
/*377:*/
#line 2627 "./marpa.w"

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
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2639 "./marpa.w"

}

/*:377*/
#line 2604 "./marpa.w"
;
/*378:*/
#line 2644 "./marpa.w"
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
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2654 "./marpa.w"

}

/*:378*/
#line 2605 "./marpa.w"
;
/*379:*/
#line 2663 "./marpa.w"

if(piece_start<nullable_suffix_ix){
struct marpa_rule*chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2668 "./marpa.w"

}

/*:379*/
#line 2606 "./marpa.w"
;
}

/*:375*/
#line 2582 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*369:*/
#line 2539 "./marpa.w"
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

/*:369*/
#line 2587 "./marpa.w"

/*381:*/
#line 2673 "./marpa.w"
{
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:381*//*382:*/
#line 2682 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2688 "./marpa.w"


/*:382*//*383:*/
#line 2691 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2696 "./marpa.w"


/*:383*//*384:*/
#line 2699 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2705 "./marpa.w"


/*:384*//*385:*/
#line 2708 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2711 "./marpa.w"


/*:385*//*386:*/
#line 2714 "./marpa.w"
}

/*:386*/
#line 2588 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symbol_id;
piece_start= piece_end+1;

/*:374*/
#line 2531 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*387:*/
#line 2718 "./marpa.w"
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

/*:387*//*388:*/
#line 2732 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2737 "./marpa.w"


/*:388*//*389:*/
#line 2740 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2745 "./marpa.w"


/*:389*//*390:*/
#line 2748 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2754 "./marpa.w"


/*:390*//*391:*/
#line 2758 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2762 "./marpa.w"

}

/*:391*//*392:*/
#line 2766 "./marpa.w"
}

/*:392*/
#line 2534 "./marpa.w"

}else{
/*393:*/
#line 2769 "./marpa.w"
{
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
guint real_symbol_count;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:393*//*394:*/
#line 2780 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2785 "./marpa.w"


/*:394*//*395:*/
#line 2789 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*397:*/
#line 2805 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:397*/
#line 2795 "./marpa.w"

}

/*:395*//*396:*/
#line 2799 "./marpa.w"
}

/*:396*/
#line 2536 "./marpa.w"

}}

/*:368*/
#line 2452 "./marpa.w"

NEXT_RULE:;
}
/*367:*/
#line 2516 "./marpa.w"

g_free(factor_positions);

/*:367*//*372:*/
#line 2566 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:372*/
#line 2455 "./marpa.w"

return g;
}
/*:359*//*398:*/
#line 2819 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
return alias->id;
}
/*:398*//*401:*/
#line 2833 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct marpa_symbol*proper_old_start= NULL;
struct marpa_symbol*nulling_old_start= NULL;
struct marpa_symbol*proper_new_start= NULL;
struct marpa_symbol*old_start= symbol_id2p(g,g->start_symbol_id);
/*403:*/
#line 2849 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:403*/
#line 2841 "./marpa.w"

if(proper_old_start){/*404:*/
#line 2859 "./marpa.w"
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

/*:404*/
#line 2842 "./marpa.w"
}
if(nulling_old_start){/*405:*/
#line 2882 "./marpa.w"
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

/*:405*/
#line 2843 "./marpa.w"
}
return g;
}
/*:401*//*409:*/
#line 2949 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{guint no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*411:*/
#line 2972 "./marpa.w"
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

/*:411*/
#line 2956 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*412:*/
#line 3011 "./marpa.w"
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

/*:412*/
#line 2958 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*413:*/
#line 3032 "./marpa.w"

context_clear(g);
context_int_add(g,"loop_rule_count",loop_rule_count);
message(g,"loop rule tally");

/*:413*/
#line 2960 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:409*//*421:*/
#line 3168 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return g->AHFA_items+item_id;
}
/*:421*//*423:*/
#line 3178 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 3180 "./marpa.w"

/*569:*/
#line 4391 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:569*/
#line 3181 "./marpa.w"

return g->no_of_items;
}
/*:423*//*425:*/
#line 3187 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 3190 "./marpa.w"

/*569:*/
#line 4391 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:569*/
#line 3191 "./marpa.w"

/*572:*/
#line 4411 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:572*/
#line 3192 "./marpa.w"

return item_id2p(g,item_id)->rule->id;
}
/*:425*//*427:*/
#line 3198 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*568:*/
#line 4389 "./marpa.w"
const int failure_indicator= -2;

/*:568*/
#line 3201 "./marpa.w"

/*569:*/
#line 4391 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:569*/
#line 3202 "./marpa.w"

/*572:*/
#line 4411 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:572*/
#line 3203 "./marpa.w"

return item_id2p(g,item_id)->position;
}
/*:427*//*429:*/
#line 3209 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*568:*/
#line 4389 "./marpa.w"
const int failure_indicator= -2;

/*:568*/
#line 3212 "./marpa.w"

/*569:*/
#line 4391 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:569*/
#line 3213 "./marpa.w"

/*572:*/
#line 4411 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:572*/
#line 3214 "./marpa.w"

return item_id2p(g,item_id)->postdot;
}
/*:429*//*431:*/
#line 3219 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 3222 "./marpa.w"

/*569:*/
#line 4391 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:569*/
#line 3223 "./marpa.w"

/*572:*/
#line 4411 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:572*/
#line 3224 "./marpa.w"

return item_id2p(g,item_id)->sort_key;
}
/*:431*//*433:*/
#line 3231 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<(Marpa_AHFA_Item_ID)g->no_of_items&&item_id>=0;
}
/*:433*//*435:*/
#line 3246 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
Marpa_Rule_ID rule_id;
guint no_of_items;
guint no_of_rules= rule_count(g);
struct AHFA_item*base_item= g_new(struct AHFA_item,g->size);
struct AHFA_item*current_item= base_item;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
/*437:*/
#line 3266 "./marpa.w"

guint rhs_ix;
struct marpa_rule*rule= rule_id2p(g,rule_id);
if(!rule->is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->length;rhs_ix++){
/*438:*/
#line 3278 "./marpa.w"

Marpa_Symbol_ID rh_symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,rh_symbol_id);
if(symbol->is_nullable)goto NEXT_RH_SYMBOL;
current_item->sort_key= current_item-base_item;
current_item->postdot= rh_symbol_id;
current_item->rule= rule;
current_item->position= rhs_ix;

/*:438*/
#line 3271 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*439:*/
#line 3287 "./marpa.w"

current_item->sort_key= current_item-base_item;
current_item->postdot= current_item->position= -1;
current_item->rule= rule;

/*:439*/
#line 3275 "./marpa.w"

current_item++;

/*:437*/
#line 3255 "./marpa.w"

NEXT_RULE:;
}
no_of_items= g->no_of_items= current_item-base_item;
g->AHFA_items= g_renew(struct AHFA_item,base_item,no_of_items);
/*440:*/
#line 3297 "./marpa.w"
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
g->AHFA_items_by_rule= items_by_rule;}

/*:440*/
#line 3260 "./marpa.w"

/*444:*/
#line 3332 "./marpa.w"
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

/*:444*/
#line 3261 "./marpa.w"

}
/*:435*//*442:*/
#line 3317 "./marpa.w"

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
/*:442*//*450:*/
#line 3385 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{return g->AHFA+AHFA_state_id;}
/*:450*//*452:*/
#line 3394 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id){
return AHFA_state_id<g->AHFA_len&&AHFA_state_id>=0;
}
/*:452*//*454:*/
#line 3410 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix){
return state->items[item_ix]-g->AHFA_items;
}
/*:454*//*456:*/
#line 3420 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return g->AHFA_len;
}
/*:456*//*458:*/
#line 3427 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 3430 "./marpa.w"

struct AHFA_state*state;
/*569:*/
#line 4391 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:569*/
#line 3432 "./marpa.w"

/*573:*/
#line 4418 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:573*/
#line 3433 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->item_count;
}
/*:458*//*460:*/
#line 3440 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix){
struct AHFA_state*state;
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 3445 "./marpa.w"

/*569:*/
#line 4391 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:569*/
#line 3446 "./marpa.w"

/*573:*/
#line 4418 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:573*/
#line 3447 "./marpa.w"

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
/*:460*//*462:*/
#line 3463 "./marpa.w"

gint marpa_AHFA_state_is_reset(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
/*567:*/
#line 4387 "./marpa.w"
const int failure_indicator= -1;
/*:567*/
#line 3467 "./marpa.w"

/*569:*/
#line 4391 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:569*/
#line 3468 "./marpa.w"

/*573:*/
#line 4418 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:573*/
#line 3469 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->is_reset;
}
/*:462*//*464:*/
#line 3477 "./marpa.w"

static inline
void create_AHFA_states(struct marpa_g*g){
const gint initial_no_of_states= 2*g->size;
struct AHFA_state*p_state;
DQUEUE_DEFINE(states);
DQUEUE_INIT(states,struct AHFA_state,initial_no_of_states);
p_state= DQUEUE_ADD(states,struct AHFA_state);
/*466:*/
#line 3496 "./marpa.w"
{
Marpa_Rule_ID start_rule_id;
struct marpa_symbol*start_symbol= symbol_id2p(g,g->start_symbol_id);
struct marpa_symbol*start_alias
= symbol_null_alias(start_symbol);
gint no_of_items_in_state= start_alias?2:1;
struct AHFA_item**item_list
= obstack_alloc(&g->obs,no_of_items_in_state*sizeof(struct AHFA_item*));
start_rule_id= g_array_index(start_symbol->lhs,Marpa_Rule_ID,0);

item_list[0]= g->AHFA_items_by_rule[start_rule_id];

if(start_alias){
Marpa_Rule_ID alias_rule_id
= g_array_index(start_alias->lhs,Marpa_Rule_ID,0);


item_list[1]= g->AHFA_items_by_rule[alias_rule_id];
}
p_state->items= item_list;
p_state->item_count= no_of_items_in_state;
}

/*:466*/
#line 3485 "./marpa.w"

while((p_state= DQUEUE_NEXT(states,struct AHFA_state))){
/*467:*/
#line 3519 "./marpa.w"
{
guint no_of_items= p_state->item_count;
Marpa_AHFA_Item_ID current_item= 0;
struct AHFA_item**items= p_state->items;
Marpa_Symbol_ID work_symbol= items[0]->postdot;

if(work_symbol==-1)goto NEXT_AHFA_STATE;

while(1){
guint first_item_for_working_symbol= current_item;
for(current_item++;
current_item<(Marpa_AHFA_Item_ID)no_of_items;
current_item++){
if(items[current_item]->postdot!=work_symbol)break;
}
switch(current_item-first_item_for_working_symbol){
case 1:/*468:*/
#line 3553 "./marpa.w"
{;}
/*:468*/
#line 3535 "./marpa.w"

break;
case 2:/*469:*/
#line 3554 "./marpa.w"
{;}
/*:469*/
#line 3537 "./marpa.w"

break;
default:/*470:*/
#line 3555 "./marpa.w"
{;}

/*:470*/
#line 3539 "./marpa.w"

}



/*471:*/
#line 3561 "./marpa.w"
;

/*:471*/
#line 3544 "./marpa.w"


if(current_item>=(Marpa_AHFA_Item_ID)no_of_items)break;
work_symbol= items[current_item]->postdot;
if(work_symbol==-1)break;
}
NEXT_AHFA_STATE:;
}

/*:467*/
#line 3487 "./marpa.w"

}
g->AHFA= DQUEUE_BASE(states,struct AHFA_state);

g->AHFA_len= DQUEUE_END(states);
}
/*:464*//*473:*/
#line 3593 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:473*//*475:*/
#line 3601 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:475*//*480:*/
#line 3634 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:480*//*482:*/
#line 3642 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:482*//*484:*/
#line 3658 "./marpa.w"

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
/*:484*//*486:*/
#line 3675 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:486*//*488:*/
#line 3687 "./marpa.w"
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
/*:488*//*490:*/
#line 3707 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:490*//*492:*/
#line 3716 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:492*//*494:*/
#line 3724 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:494*//*497:*/
#line 3737 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:497*//*499:*/
#line 3745 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:499*//*501:*/
#line 3753 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:501*//*504:*/
#line 3762 "./marpa.w"

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
/*:504*//*506:*/
#line 3779 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:506*//*508:*/
#line 3791 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:508*//*510:*/
#line 3803 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:510*//*512:*/
#line 3815 "./marpa.w"

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
bitmask= 1<<(start&bv_modmask);
mask= ~(bitmask|(bitmask-1));
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
/*:512*//*518:*/
#line 3929 "./marpa.w"

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
/*:518*//*523:*/
#line 3998 "./marpa.w"

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
/*:523*//*525:*/
#line 4018 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:525*//*527:*/
#line 4031 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:527*//*529:*/
#line 4048 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:529*//*532:*/
#line 4058 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:532*//*535:*/
#line 4067 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:535*//*538:*/
#line 4076 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:538*//*540:*/
#line 4090 "./marpa.w"

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
/*:540*//*543:*/
#line 4144 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa){
void*data= pa->data;
if(data)g_free(data);
}
/*:543*//*546:*/
#line 4163 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size){
dpa->pa.len= 0;dpa->size= size;dpa->pa.data= g_new(void*,size);}
/*:546*//*548:*/
#line 4168 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa){
p_array_destroy(&(dpa->pa));
}
/*:548*//*550:*/
#line 4174 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size){
dpa->pa.data= g_renew(void*,dpa->pa.data,new_size);
dpa->size= new_size;
}
/*:550*//*552:*/
#line 4181 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p){
if(dpa->pa.len>=dpa->size)dp_array_resize(dpa,dpa->size*2);
dpa->pa.data[dpa->pa.len++]= p;
}
/*:552*//*554:*/
#line 4190 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa){
gint len= pa->len= dpa->pa.len;
if(G_UNLIKELY(len>=dpa->size)){
pa->data= dpa->pa.data;
return;
}
pa->data= g_renew(void*,dpa->pa.data,len);
}
/*:554*//*560:*/
#line 4259 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:560*//*579:*/
#line 4487 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->message_callback_arg= cb_arg;}
void*marpa_message_callback_arg(struct marpa_g*g)
{return g->message_callback_arg;}
/*:579*//*581:*/
#line 4501 "./marpa.w"

static inline void message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:581*/
#line 4607 "./marpa.w"





/*:589*/
