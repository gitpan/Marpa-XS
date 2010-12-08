/*579:*/
#line 4452 "./marpa.w"

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

#pragma GCC diagnostic warning "-Wall"
#pragma GCC diagnostic warning "-Wextra"
#pragma GCC diagnostic warning "-Wpointer-arith"
#pragma GCC diagnostic warning "-Wstrict-prototypes"
#pragma GCC diagnostic warning "-Wwrite-strings"
#pragma GCC diagnostic warning "-Wdeclaration-after-statement"
#pragma GCC diagnostic warning "-Wshadow"
#pragma GCC diagnostic warning "-Winline"
#pragma GCC diagnostic warning "-Wmissing-declarations"
#pragma GCC diagnostic warning "-Wconversion"

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


#line 4488 "./marpa.w"

#include "marpa_obs.h"
/*565:*/
#line 4325 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:565*/
#line 4490 "./marpa.w"

/*470:*/
#line 3514 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:470*//*513:*/
#line 3884 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:513*/
#line 4491 "./marpa.w"

/*16:*/
#line 389 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:16*//*29:*/
#line 476 "./marpa.w"
static gint next_grammar_id= 1;
/*:29*//*471:*/
#line 3521 "./marpa.w"

static const int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const int bv_hiddenwords= 3;
static const int bv_lsb= 1u;
static const int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:471*/
#line 4492 "./marpa.w"

/*534:*/
#line 4037 "./marpa.w"

struct p_array{gint len;void**data;};
/*:534*//*537:*/
#line 4056 "./marpa.w"

struct dp_array{struct p_array pa;gint size;};
/*:537*/
#line 4493 "./marpa.w"

/*21:*/
#line 441 "./marpa.w"
struct marpa_g{
/*33:*/
#line 491 "./marpa.w"
GArray*symbols;
/*:33*//*45:*/
#line 547 "./marpa.w"
GArray*rules;
/*:45*//*89:*/
#line 768 "./marpa.w"
GHashTable*context;
/*:89*//*104:*/
#line 853 "./marpa.w"
struct obstack obs;
/*:104*//*108:*/
#line 869 "./marpa.w"
Marpa_Error_ID error;
/*:108*//*195:*/
#line 1290 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
void*symbol_callback_arg;
/*:195*//*302:*/
#line 1984 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
void*rule_callback_arg;
/*:302*//*425:*/
#line 3180 "./marpa.w"

struct AHFA_item*AHFA_items;
struct AHFA_item**AHFA_items_by_rule;
/*:425*//*453:*/
#line 3393 "./marpa.w"
struct AHFA_state*AHFA;
/*:453*//*568:*/
#line 4365 "./marpa.w"

Marpa_Message_Callback*message_callback;
void*message_callback_arg;
/*:568*/
#line 442 "./marpa.w"

/*27:*/
#line 474 "./marpa.w"
int id;
/*:27*//*57:*/
#line 603 "./marpa.w"
Marpa_Symbol_ID start_symbol;
/*:57*//*64:*/
#line 651 "./marpa.w"
int size;
/*:64*//*67:*/
#line 664 "./marpa.w"
int max_rule_length;
/*:67*//*424:*/
#line 3178 "./marpa.w"

gint no_of_items;
/*:424*//*454:*/
#line 3394 "./marpa.w"
gint AHFA_len;
/*:454*/
#line 443 "./marpa.w"

/*69:*/
#line 669 "./marpa.w"
unsigned int is_precomputed:1;
/*:69*//*73:*/
#line 680 "./marpa.w"
unsigned int has_loop:1;
/*:73*//*77:*/
#line 695 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:77*//*83:*/
#line 735 "./marpa.w"
unsigned int is_academic:1;
/*:83*/
#line 444 "./marpa.w"

};

/*:21*//*119:*/
#line 913 "./marpa.w"

struct marpa_symbol{
/*128:*/
#line 958 "./marpa.w"
GArray*lhs;
/*:128*//*135:*/
#line 985 "./marpa.w"
GArray*rhs;
/*:135*//*182:*/
#line 1182 "./marpa.w"

struct marpa_symbol*alias;
/*:182*/
#line 915 "./marpa.w"

/*126:*/
#line 950 "./marpa.w"
Marpa_Symbol_ID id;
/*:126*/
#line 916 "./marpa.w"

/*142:*/
#line 1006 "./marpa.w"
unsigned int is_accessible:1;
/*:142*//*148:*/
#line 1032 "./marpa.w"
unsigned int is_counted:1;
/*:148*//*152:*/
#line 1050 "./marpa.w"
unsigned int is_nullable:1;
/*:152*//*158:*/
#line 1075 "./marpa.w"
unsigned int is_nulling:1;
/*:158*//*164:*/
#line 1102 "./marpa.w"
unsigned int is_terminal:1;
/*:164*//*170:*/
#line 1128 "./marpa.w"
unsigned int is_productive:1;
/*:170*//*176:*/
#line 1153 "./marpa.w"
unsigned int is_start:1;
/*:176*//*181:*/
#line 1179 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:181*/
#line 917 "./marpa.w"

};

/*:119*//*201:*/
#line 1315 "./marpa.w"

struct marpa_rule{
/*235:*/
#line 1709 "./marpa.w"
gsize length;
/*:235*/
#line 1317 "./marpa.w"

/*255:*/
#line 1773 "./marpa.w"
Marpa_Rule_ID id;
/*:255*//*296:*/
#line 1965 "./marpa.w"
gint virtual_start;
/*:296*//*298:*/
#line 1972 "./marpa.w"
gint virtual_end;
/*:298*//*312:*/
#line 2014 "./marpa.w"
Marpa_Rule_ID original;
/*:312*//*316:*/
#line 2026 "./marpa.w"
gint real_symbol_count;
/*:316*/
#line 1318 "./marpa.w"

/*258:*/
#line 1785 "./marpa.w"
unsigned int is_discard:1;
/*:258*//*272:*/
#line 1865 "./marpa.w"
unsigned int is_loop:1;
/*:272*//*277:*/
#line 1884 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:277*//*284:*/
#line 1912 "./marpa.w"
unsigned int is_used:1;
/*:284*//*288:*/
#line 1940 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:288*//*292:*/
#line 1951 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:292*//*319:*/
#line 2033 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:319*/
#line 1319 "./marpa.w"

/*236:*/
#line 1712 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:236*/
#line 1320 "./marpa.w"

};
/*:201*//*423:*/
#line 3165 "./marpa.w"

struct AHFA_item{
Marpa_Symbol_ID postdot;

Marpa_AHFA_Item_ID sort_key;
struct marpa_rule*rule;
gint position;
};
/*:423*//*452:*/
#line 3387 "./marpa.w"

struct AHFA_state{
struct AHFA_item*items;
gint item_count;
unsigned int is_reset:1;
};
/*:452*//*551:*/
#line 4152 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:551*//*554:*/
#line 4182 "./marpa.w"

struct dqueue{gint current;struct dstack s;};

/*:554*/
#line 4494 "./marpa.w"

/*39:*/
#line 510 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g);

/*:39*//*41:*/
#line 518 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id);

/*:41*//*44:*/
#line 540 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:44*//*51:*/
#line 566 "./marpa.w"

static inline gint rule_count(struct marpa_g*g);

/*:51*//*53:*/
#line 574 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id);

/*:53*//*56:*/
#line 598 "./marpa.w"

static inline gint rule_is_valid(
struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:56*//*97:*/
#line 819 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:97*//*99:*/
#line 831 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:99*//*101:*/
#line 840 "./marpa.w"

static inline void context_clear(struct marpa_g*g);

/*:101*//*121:*/
#line 934 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:121*//*125:*/
#line 946 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol);

/*:125*//*134:*/
#line 977 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);

/*:134*//*141:*/
#line 1002 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);

/*:141*//*179:*/
#line 1166 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol);
/*:179*//*185:*/
#line 1207 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol);
/*:185*//*188:*/
#line 1235 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol);
/*:188*//*191:*/
#line 1274 "./marpa.w"

static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
/*:191*//*199:*/
#line 1309 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:199*//*203:*/
#line 1326 "./marpa.w"

static inline gsize rule_sizeof(gint length);

/*:203*//*206:*/
#line 1349 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);

/*:206*//*223:*/
#line 1573 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length);

/*:223*//*224:*/
#line 1578 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:224*//*234:*/
#line 1701 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule);

/*:234*//*240:*/
#line 1726 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:240*//*244:*/
#line 1737 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:244*//*248:*/
#line 1748 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:248*//*252:*/
#line 1760 "./marpa.w"

static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule*rule);
/*:252*//*254:*/
#line 1767 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,gint index);

/*:254*//*265:*/
#line 1832 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule);
/*:265*//*269:*/
#line 1854 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule);
/*:269*//*283:*/
#line 1908 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule);

/*:283*//*310:*/
#line 2007 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:310*//*330:*/
#line 2162 "./marpa.w"

static inline struct marpa_g*census(struct marpa_g*g);
/*:330*//*366:*/
#line 2483 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:366*//*405:*/
#line 2852 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:405*//*408:*/
#line 2873 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:408*//*416:*/
#line 2990 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:416*//*428:*/
#line 3196 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:428*//*440:*/
#line 3258 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:440*//*442:*/
#line 3285 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:442*//*449:*/
#line 3345 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:449*//*457:*/
#line 3413 "./marpa.w"

static inline void create_AHFA_states(struct marpa_g*g);

/*:457*//*473:*/
#line 3534 "./marpa.w"

static inline guint bv_bits_to_size(gint bits);
/*:473*//*475:*/
#line 3544 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits);

/*:475*//*477:*/
#line 3564 "./marpa.w"

static inline Bit_Vector bv_create(gint bits);

/*:477*//*479:*/
#line 3575 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:479*//*481:*/
#line 3597 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:481*//*483:*/
#line 3607 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:483*//*485:*/
#line 3615 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:485*//*487:*/
#line 3627 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:487*//*490:*/
#line 3635 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit);

/*:490*//*492:*/
#line 3643 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit);

/*:492*//*494:*/
#line 3651 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit);

/*:494*//*497:*/
#line 3668 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:497*//*499:*/
#line 3681 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:499*//*501:*/
#line 3693 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:501*//*503:*/
#line 3705 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:503*//*505:*/
#line 3779 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,gint start,gint*min,gint*max);

/*:505*//*511:*/
#line 3861 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:511*//*516:*/
#line 3908 "./marpa.w"

static inline Bit_Matrix matrix_create(gint rows,gint columns);

/*:516*//*518:*/
#line 3916 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:518*//*520:*/
#line 3930 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:520*//*522:*/
#line 3948 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,gint row);

/*:522*//*525:*/
#line 3957 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,gint row,gint column);

/*:525*//*528:*/
#line 3966 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,gint row,gint column);

/*:528*//*531:*/
#line 3975 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,gint row,gint column);

/*:531*//*533:*/
#line 4029 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:533*//*536:*/
#line 4044 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa);

/*:536*//*539:*/
#line 4061 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size);
/*:539*//*541:*/
#line 4067 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa);
/*:541*//*543:*/
#line 4074 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size);
/*:543*//*545:*/
#line 4081 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p);
/*:545*//*547:*/
#line 4094 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa);


/*:547*//*553:*/
#line 4160 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:553*//*572:*/
#line 4384 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id);

/*:572*/
#line 4495 "./marpa.w"

/*42:*/
#line 524 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symbol_id,
struct marpa_symbol*symbol)
{
g_array_insert_val(g->symbols,symbol_id,symbol);
}

/*:42*//*54:*/
#line 580 "./marpa.w"

static inline
void marpa_g_rule_add(
struct marpa_g*g,
Marpa_Rule_ID rule_id,
struct marpa_rule*rule)
{
g_array_insert_val(g->rules,rule_id,rule);
g->size+= 1+rule->length;
g->max_rule_length= MAX(rule->length,g->max_rule_length);
}

/*:54*/
#line 4496 "./marpa.w"

/*17:*/
#line 396 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:17*//*22:*/
#line 447 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*30:*/
#line 477 "./marpa.w"

g->id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:30*//*34:*/
#line 492 "./marpa.w"

g->symbols= g_array_new(FALSE,FALSE,sizeof(struct marpa_symbol*));
/*:34*//*46:*/
#line 548 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(struct marpa_rule*));
/*:46*//*58:*/
#line 604 "./marpa.w"

g->start_symbol= -1;
/*:58*//*65:*/
#line 652 "./marpa.w"

g->size= 0;

/*:65*//*68:*/
#line 665 "./marpa.w"

g->max_rule_length= 0;

/*:68*//*70:*/
#line 670 "./marpa.w"

g->is_precomputed= FALSE;
/*:70*//*74:*/
#line 681 "./marpa.w"

g->has_loop= FALSE;
/*:74*//*78:*/
#line 696 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:78*//*84:*/
#line 736 "./marpa.w"

g->is_academic= FALSE;
/*:84*//*90:*/
#line 769 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:90*//*105:*/
#line 854 "./marpa.w"
obstack_init(&g->obs);
/*:105*//*109:*/
#line 870 "./marpa.w"

g->error= 0;
/*:109*/
#line 450 "./marpa.w"

return g;}
/*:22*//*24:*/
#line 455 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g)
{/*35:*/
#line 494 "./marpa.w"
g_array_free(g->symbols,TRUE);

/*:35*//*47:*/
#line 550 "./marpa.w"
g_array_free(g->rules,TRUE);

/*:47*//*91:*/
#line 771 "./marpa.w"
g_hash_table_destroy(g->context);

/*:91*//*106:*/
#line 855 "./marpa.w"
obstack_free(&g->obs,NULL);

/*:106*//*123:*/
#line 940 "./marpa.w"

{int id;for(id= 0;id<g->symbols->len;id++)
{marpa_symbol_free(symbol_id2p(g,id));}}
/*:123*//*232:*/
#line 1692 "./marpa.w"

{int id;for(id= 0;id<g->rules->len;id++)
{marpa_rule_free(rule_id2p(g,id));}}
/*:232*//*426:*/
#line 3186 "./marpa.w"
if(g->AHFA_items){
g_free(g->AHFA_items_by_rule);
g_free(g->AHFA_items);
};

/*:426*//*455:*/
#line 3395 "./marpa.w"
if(g->AHFA){STOLEN_DQUEUE_DATA_FREE(g->AHFA);}

/*:455*/
#line 457 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:24*//*31:*/
#line 479 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->id;}
/*:31*//*36:*/
#line 499 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:36*//*38:*/
#line 506 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g){
return g->symbols->len;
}
/*:38*//*40:*/
#line 514 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id)
{return g_array_index(g->symbols,struct marpa_symbol*,id);}
/*:40*//*43:*/
#line 535 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id){
return symbol_id<g->symbols->len&&symbol_id>=0;
}
/*:43*//*48:*/
#line 555 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:48*//*50:*/
#line 562 "./marpa.w"

static inline gint rule_count(struct marpa_g*g){
return g->rules->len;
}
/*:50*//*52:*/
#line 570 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id)
{return g_array_index(g->rules,struct marpa_rule*,id);}
/*:52*//*55:*/
#line 593 "./marpa.w"

static inline gint rule_is_valid(
struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_id<g->rules->len&&rule_id>=0;
}
/*:55*//*59:*/
#line 607 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->start_symbol;}
/*:59*//*61:*/
#line 614 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id)
{
struct marpa_symbol*start;
if(g->is_precomputed){
g->error= "precomputed";
return FALSE;
}
if(!symbol_is_valid(g,id)){
g->error= "invalid start symbol";
return FALSE;
}
g->start_symbol= id;
return TRUE;
}
/*:61*//*71:*/
#line 673 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{return g->is_precomputed;}
/*:71*//*75:*/
#line 684 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->has_loop;}
/*:75*//*79:*/
#line 699 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:79*//*81:*/
#line 706 "./marpa.w"

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
/*:81*//*85:*/
#line 739 "./marpa.w"

gboolean marpa_is_academic(struct marpa_g*g)
{return g->is_academic;}
/*:85*//*87:*/
#line 746 "./marpa.w"

gboolean marpa_is_academic_set(
struct marpa_g*g,gboolean value)
{
if(g->is_precomputed){
g->error= "precomputed";
return FALSE;
}
g->is_academic= value;
return TRUE;
}
/*:87*//*96:*/
#line 810 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:96*//*98:*/
#line 822 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:98*//*100:*/
#line 837 "./marpa.w"

static inline void context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:100*//*102:*/
#line 843 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:102*//*111:*/
#line 878 "./marpa.w"

Marpa_Error_ID marpa_error(struct marpa_g*g)
{return g->error?:"unknown error";}
/*:111*//*114:*/
#line 892 "./marpa.w"

void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

return;

}

/*:114*//*116:*/
#line 905 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce){}
/*:116*//*120:*/
#line 920 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*127:*/
#line 951 "./marpa.w"
symbol->id= g->symbols->len;

/*:127*//*129:*/
#line 959 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:129*//*136:*/
#line 986 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:136*//*143:*/
#line 1007 "./marpa.w"

symbol->is_accessible= FALSE;
/*:143*//*149:*/
#line 1033 "./marpa.w"

symbol->is_counted= FALSE;
/*:149*//*153:*/
#line 1051 "./marpa.w"

symbol->is_nullable= FALSE;
/*:153*//*159:*/
#line 1076 "./marpa.w"

symbol->is_nulling= FALSE;
/*:159*//*165:*/
#line 1103 "./marpa.w"

symbol->is_terminal= FALSE;
/*:165*//*171:*/
#line 1129 "./marpa.w"

symbol->is_productive= FALSE;
/*:171*//*177:*/
#line 1154 "./marpa.w"
symbol->is_start= FALSE;
/*:177*//*183:*/
#line 1184 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:183*/
#line 924 "./marpa.w"

{Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);}
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;}

/*:120*//*124:*/
#line 943 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol)
{/*130:*/
#line 961 "./marpa.w"
g_array_free(symbol->lhs,TRUE);
/*:130*//*137:*/
#line 988 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:137*/
#line 945 "./marpa.w"
g_free(symbol);}
/*:124*//*131:*/
#line 965 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*558:*/
#line 4280 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:558*/
#line 967 "./marpa.w"

/*562:*/
#line 4292 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:562*/
#line 968 "./marpa.w"

return symbol_id2p(g,symbol_id)->lhs;}
/*:131*//*133:*/
#line 972 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:133*//*138:*/
#line 992 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*558:*/
#line 4280 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:558*/
#line 994 "./marpa.w"

/*562:*/
#line 4292 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:562*/
#line 995 "./marpa.w"

return symbol_id2p(g,symbol_id)->rhs;}
/*:138*//*140:*/
#line 999 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
/*:140*//*144:*/
#line 1017 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:144*//*146:*/
#line 1023 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:146*//*150:*/
#line 1043 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:150*//*154:*/
#line 1061 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:154*//*156:*/
#line 1067 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:156*//*160:*/
#line 1086 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*559:*/
#line 4282 "./marpa.w"
const int failure_indicator= -1;
/*:559*/
#line 1088 "./marpa.w"

/*562:*/
#line 4292 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:562*/
#line 1089 "./marpa.w"

return symbol_id2p(g,symbol_id)->is_nulling;}
/*:160*//*162:*/
#line 1094 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:162*//*166:*/
#line 1113 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:166*//*168:*/
#line 1119 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:168*//*172:*/
#line 1139 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:172*//*174:*/
#line 1145 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value;}
/*:174*//*178:*/
#line 1157 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*559:*/
#line 4282 "./marpa.w"
const int failure_indicator= -1;
/*:559*/
#line 1162 "./marpa.w"

/*562:*/
#line 4292 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:562*/
#line 1163 "./marpa.w"

return symbol_is_start(symbol_id2p(g,symbol_id));
}
/*:178*//*184:*/
#line 1193 "./marpa.w"

static inline
struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol)
{return symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*proper_alias;
/*559:*/
#line 4282 "./marpa.w"
const int failure_indicator= -1;
/*:559*/
#line 1201 "./marpa.w"

/*562:*/
#line 4292 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:562*/
#line 1202 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->id;
}
/*:184*//*187:*/
#line 1216 "./marpa.w"

static inline
struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*alias;
/*559:*/
#line 4282 "./marpa.w"
const int failure_indicator= -1;
/*:559*/
#line 1224 "./marpa.w"

/*562:*/
#line 4292 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:562*/
#line 1225 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
alias= symbol_null_alias(symbol);
if(alias==NULL){
context_int_add(g,"symbol_id",symbol_id);
g->error= "no alias";
return-1;
}
return alias->id;
}
/*:187*//*190:*/
#line 1249 "./marpa.w"
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
if(original_id>=g->symbols->len){return-1;}
alias_id= symbol_alias_create(g,symbol_id2p(g,original_id))->id;
symbol_callback(g,alias_id);
return alias_id;}
/*:190*//*196:*/
#line 1293 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->symbol_callback_arg= cb_arg;}
void*marpa_symbol_callback_arg(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:196*//*198:*/
#line 1305 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:198*//*202:*/
#line 1322 "./marpa.w"

static inline gsize rule_sizeof(gint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:202*//*205:*/
#line 1334 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
int i;
struct marpa_rule*rule;
/*237:*/
#line 1713 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{int i;for(i= 0;i<length;i++){
if(!symbol_is_valid(g,rhs[i])){return NULL;}
}}
/*:237*/
#line 1341 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*238:*/
#line 1718 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{int i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:238*/
#line 1343 "./marpa.w"

/*256:*/
#line 1774 "./marpa.w"
rule->id= g->rules->len;

/*:256*//*259:*/
#line 1786 "./marpa.w"

rule->is_discard= FALSE;
/*:259*//*273:*/
#line 1866 "./marpa.w"

rule->is_loop= FALSE;
/*:273*//*278:*/
#line 1885 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:278*//*285:*/
#line 1913 "./marpa.w"

rule->is_used= TRUE;
/*:285*//*289:*/
#line 1941 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:289*//*293:*/
#line 1952 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:293*//*297:*/
#line 1966 "./marpa.w"
rule->virtual_start= -1;

/*:297*//*299:*/
#line 1973 "./marpa.w"
rule->virtual_end= -1;

/*:299*//*313:*/
#line 2015 "./marpa.w"
rule->original= -1;
/*:313*//*317:*/
#line 2027 "./marpa.w"
rule->real_symbol_count= 0;
/*:317*//*320:*/
#line 2034 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:320*/
#line 1344 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*226:*/
#line 1594 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const gint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*230:*/
#line 1661 "./marpa.w"

{

gint rhs_ix= rule->length-1;
rh_symbol_list[0]= rhs_symbol_id(rule,rhs_ix);
rh_symbol_list_length= 1;
rhs_ix--;
for(;rhs_ix>=0;rhs_ix--){
gint higher_ix;
Marpa_Symbol_ID new_symbol_id= rhs_symbol_id(rule,rhs_ix);
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

/*:230*/
#line 1602 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
symbol_id2p(g,rh_symbol_list[rh_list_ix]),
rule->id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:226*/
#line 1346 "./marpa.w"

return rule;
}
/*:205*//*207:*/
#line 1354 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
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

/*:207*//*208:*/
#line 1371 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags)
{
Marpa_Rule_ID original_rule_id;
struct marpa_rule*original_rule;
Marpa_Symbol_ID internal_lhs_id,*temp_rhs;
if(min<0){
g->error= (Marpa_Error_ID)"bad min";
return-1;
}
if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE){
g->error= (Marpa_Error_ID)"duplicate rule";
return-1;
}

/*211:*/
#line 1410 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*210:*/
#line 1408 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1412 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:211*/
#line 1388 "./marpa.w"

/*212:*/
#line 1416 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:212*/
#line 1389 "./marpa.w"

/*213:*/
#line 1420 "./marpa.w"

symbol_id2p(g,rhs_id)->is_counted= 1;
if(separator_id>=0){symbol_id2p(g,separator_id)->is_counted= 1;}
/*:213*/
#line 1390 "./marpa.w"

if(min==0){/*214:*/
#line 1423 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*210:*/
#line 1408 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1425 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:214*/
#line 1391 "./marpa.w"
}
min= 1;
/*215:*/
#line 1430 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:215*/
#line 1393 "./marpa.w"

/*216:*/
#line 1444 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:216*/
#line 1394 "./marpa.w"

/*218:*/
#line 1447 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*210:*/
#line 1408 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1451 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:218*/
#line 1395 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*219:*/
#line 1460 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*210:*/
#line 1408 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1465 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:219*/
#line 1397 "./marpa.w"

}
/*220:*/
#line 1477 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*210:*/
#line 1408 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1487 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:220*/
#line 1399 "./marpa.w"

/*221:*/
#line 1492 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*210:*/
#line 1408 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1499 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:221*/
#line 1400 "./marpa.w"

/*217:*/
#line 1446 "./marpa.w"
g_free(temp_rhs);
/*:217*/
#line 1401 "./marpa.w"

return original_rule_id;
}
/*:208*//*222:*/
#line 1549 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length)
{
gint ix;
struct marpa_symbol*lhs= symbol_id2p(g,lhs_id);
GArray*same_lhs_array= lhs->lhs;
gint same_lhs_count= same_lhs_array->len;
for(ix= 0;ix<same_lhs_count;ix++){
Marpa_Rule_ID same_lhs_rule_id= ((Marpa_Rule_ID*)(same_lhs_array->data))[ix];
gint rhs_position;
struct marpa_rule*rule= rule_id2p(g,same_lhs_rule_id);
if(rule->length!=length){goto rule_is_not_duplicate;}
for(rhs_position= 0;rhs_position<rule->length;rhs_position++){
if(rhs_symbol_id(rule,rhs_position)!=rhs_ids[rhs_position]){
goto rule_is_not_duplicate;
}
}
return TRUE;
rule_is_not_duplicate:;
}
return FALSE;
}
/*:222*//*233:*/
#line 1696 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule)
{

g_free(rule);}
/*:233*//*239:*/
#line 1723 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
/*:239*//*241:*/
#line 1728 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*323:*/
#line 2053 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:323*/
#line 1730 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:241*//*243:*/
#line 1734 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:243*//*245:*/
#line 1739 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*324:*/
#line 2060 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return NULL;
}

/*:324*/
#line 1741 "./marpa.w"

return rule_rhs_get(rule_id2p(g,rule_id));}
/*:245*//*247:*/
#line 1745 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:247*//*249:*/
#line 1750 "./marpa.w"

gsize marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*323:*/
#line 2053 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:323*/
#line 1752 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:249*//*251:*/
#line 1757 "./marpa.w"

static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule*rule){return rule->symbols[0];}
/*:251*//*253:*/
#line 1762 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,gint index){
return rule->symbols[index+1];
}
/*:253*//*260:*/
#line 1788 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:260*//*264:*/
#line 1821 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule)
{
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
return symbol_id2p(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{struct marpa_rule*rule;
/*323:*/
#line 2053 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:323*/
#line 1828 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:264*//*268:*/
#line 1839 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_productive)return FALSE;
}
return TRUE;}
gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{struct marpa_rule*rule;
/*323:*/
#line 2053 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:323*/
#line 1850 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:268*//*274:*/
#line 1870 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{/*323:*/
#line 2053 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:323*/
#line 1872 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:274*//*279:*/
#line 1889 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{/*323:*/
#line 2053 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:323*/
#line 1891 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:279*//*282:*/
#line 1899 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:282*//*286:*/
#line 1917 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{/*323:*/
#line 2053 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:323*/
#line 1919 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:286*//*290:*/
#line 1944 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:290*//*294:*/
#line 1955 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:294*//*303:*/
#line 1987 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:303*//*305:*/
#line 1992 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:305*//*307:*/
#line 1997 "./marpa.w"

void*marpa_rule_callback_arg(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:307*//*309:*/
#line 2003 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:309*//*314:*/
#line 2016 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}

/*:314*//*318:*/
#line 2028 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}

/*:318*//*321:*/
#line 2045 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:321*//*325:*/
#line 2078 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
if(!census(g))return NULL;
if(!g->is_academic){
if(!CHAF_rewrite(g))return NULL;
if(!g_augment(g))return NULL;
loop_detect(g);
}else{
/*327:*/
#line 2095 "./marpa.w"

Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<g->rules->len;rule_id++)
{rule_id2p(g,rule_id)->is_used= 1;}

/*:327*/
#line 2087 "./marpa.w"

}
create_AHFA_items(g);
return g;
}
/*:325*//*329:*/
#line 2132 "./marpa.w"

static inline struct marpa_g*census(struct marpa_g*g)
{
/*331:*/
#line 2164 "./marpa.w"

gint pre_rewrite_rule_count= g->rules->len;
gint pre_rewrite_symbol_count= g->symbols->len;

/*:331*//*336:*/
#line 2197 "./marpa.w"

Marpa_Symbol_ID original_start_symbol_id= g->start_symbol;
struct marpa_symbol*original_start_symbol;

/*:336*//*340:*/
#line 2230 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:340*//*346:*/
#line 2288 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:346*//*348:*/
#line 2313 "./marpa.w"

Bit_Vector nullable_v;
/*:348*//*352:*/
#line 2336 "./marpa.w"

Bit_Vector productive_v;
/*:352*//*357:*/
#line 2389 "./marpa.w"

Bit_Vector accessible_v;

/*:357*/
#line 2135 "./marpa.w"

/*332:*/
#line 2168 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:332*/
#line 2136 "./marpa.w"

/*333:*/
#line 2175 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:333*/
#line 2137 "./marpa.w"

/*335:*/
#line 2181 "./marpa.w"

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
/*:335*/
#line 2138 "./marpa.w"

/*337:*/
#line 2201 "./marpa.w"

{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;rule_id<pre_rewrite_rule_count;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
bv_bit_set(lhs_v,lhs_id);
if(rule->length<=0){
bv_bit_set(empty_lhs_v,lhs_id);
have_empty_rule= 1;
}
}
}
/*:337*/
#line 2139 "./marpa.w"

/*338:*/
#line 2218 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symbol_id= 0;symbol_id<pre_rewrite_symbol_count;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_terminal){
bv_bit_set(terminal_v,symbol_id);
have_marked_terminals= 1;
}
}}
/*:338*/
#line 2140 "./marpa.w"

if(have_marked_terminals){
/*342:*/
#line 2245 "./marpa.w"

if(!g->is_lhs_terminal_ok){
gboolean have_bad_lhs= 0;
gint start= 0;
gint min,max;
Bit_Vector bad_lhs_v= bv_clone(terminal_v);
bv_and(bad_lhs_v,bad_lhs_v,lhs_v);
while(bv_scan(bad_lhs_v,start,&min,&max)){
gint i;
for(i= min;i<=max;i++){
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

/*:342*/
#line 2142 "./marpa.w"

}else{
/*341:*/
#line 2234 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:341*/
#line 2144 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*343:*/
#line 2268 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<g->symbols->len;symbol_id++)
{symbol_id2p(g,symbol_id)->is_terminal= 1;}}
/*:343*/
#line 2146 "./marpa.w"

}else{
/*344:*/
#line 2273 "./marpa.w"

{gint start= 0;
gint min,max;
bv_not(terminal_v,lhs_v);
while(bv_scan(terminal_v,start,&min,&max)){
gint symbol_id;
for(symbol_id= min;symbol_id<=max;symbol_id++){
symbol_id2p(g,symbol_id)->is_terminal= 1;
}
start= max+2;
}
}
/*:344*/
#line 2148 "./marpa.w"

}
}
/*347:*/
#line 2293 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{gint min,max,start,symbol_id;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symbol_id= min;symbol_id<=max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_counted){
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
/*:347*/
#line 2151 "./marpa.w"

/*350:*/
#line 2318 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{gint min,max,start,symbol_id;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symbol_id= min;symbol_id<=max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
symbol->is_productive= 1;
}}
}
/*:350*/
#line 2152 "./marpa.w"

/*351:*/
#line 2329 "./marpa.w"

if(!bv_bit_test(productive_v,g->start_symbol))
{
context_int_add(g,"symbol_id",g->start_symbol);
g->error= "unproductive start symbol";
return NULL;
}
/*:351*/
#line 2153 "./marpa.w"

/*354:*/
#line 2359 "./marpa.w"

Bit_Matrix reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{gint symbol_id,no_of_symbols= symbol_count(g);
for(symbol_id= 0;symbol_id<no_of_symbols;symbol_id++){
matrix_bit_set(reach_matrix,symbol_id,symbol_id);
}}
{gint rule_id,no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
gint rhs_ix,rule_length= rule->length;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,lhs_id,rhs_symbol_id(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:354*/
#line 2154 "./marpa.w"

/*356:*/
#line 2378 "./marpa.w"

accessible_v= matrix_row(reach_matrix,original_start_symbol_id);
{gint min,max,start,symbol_id;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symbol_id= min;symbol_id<=max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
symbol->is_accessible= 1;
}}
}
/*:356*/
#line 2155 "./marpa.w"

/*358:*/
#line 2394 "./marpa.w"

{Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
gint min,max,start;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
Marpa_Symbol_ID productive_id;
for(productive_id= min;productive_id<=max;productive_id++){
bv_and(reaches_terminal_v,terminal_v,matrix_row(reach_matrix,productive_id));
if(bv_is_empty(reaches_terminal_v))symbol_id2p(g,productive_id)->is_nulling= 1;
}}
bv_free(reaches_terminal_v);}

/*:358*/
#line 2156 "./marpa.w"

/*339:*/
#line 2228 "./marpa.w"

bv_free(terminal_v);
/*:339*//*345:*/
#line 2285 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:345*//*349:*/
#line 2315 "./marpa.w"

bv_free(nullable_v);

/*:349*//*353:*/
#line 2338 "./marpa.w"

bv_free(productive_v);

/*:353*/
#line 2157 "./marpa.w"

/*355:*/
#line 2375 "./marpa.w"

matrix_free(reach_matrix);

/*:355*/
#line 2158 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:329*//*365:*/
#line 2462 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*367:*/
#line 2485 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:367*//*371:*/
#line 2536 "./marpa.w"

gint factor_count;
gint*factor_positions;
/*:371*//*376:*/
#line 2585 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:376*/
#line 2465 "./marpa.w"

/*372:*/
#line 2539 "./marpa.w"

factor_positions= g_new(gint,g->max_rule_length);
/*:372*//*377:*/
#line 2588 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:377*/
#line 2466 "./marpa.w"

/*369:*/
#line 2497 "./marpa.w"

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

/*:369*/
#line 2467 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
gint rule_length= rule->length;
gint nullable_suffix_ix= 0;
/*368:*/
#line 2489 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:368*/
#line 2473 "./marpa.w"

/*370:*/
#line 2520 "./marpa.w"

{gint rhs_ix;
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
/*:370*/
#line 2474 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*374:*/
#line 2545 "./marpa.w"

rule->is_used= 0;
{gint unprocessed_factor_count;

gint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= lhs_symbol_id(rule);
gint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*380:*/
#line 2598 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symbol_id;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*375:*/
#line 2564 "./marpa.w"
{
struct marpa_symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
context_clear(g);
context_int_add(g,"rule_id",rule_id);
context_int_add(g,"lhs_id",lhs_symbol_id(rule));
context_int_add(g,"virtual_end",piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:375*/
#line 2606 "./marpa.w"

/*381:*/
#line 2625 "./marpa.w"

{
gint remaining_rhs_length,piece_rhs_length;
/*382:*/
#line 2637 "./marpa.w"

{
gint real_symbol_count= piece_end-piece_start+1;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
remaining_rhs[piece_rhs_length]= 
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
}
{struct marpa_rule*chaf_rule;
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2649 "./marpa.w"

}

/*:382*/
#line 2628 "./marpa.w"
;
/*383:*/
#line 2652 "./marpa.w"

{gint piece_rhs_ix;
gint chaf_rule_length= rule->length-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;
remaining_rhs_length++){
Marpa_Symbol_ID original_id= rhs_symbol_id(rule,piece_start+remaining_rhs_length);
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,original_id));
remaining_rhs[remaining_rhs_length]= alias?alias->id:original_id;
}}
{struct marpa_rule*chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2665 "./marpa.w"

}

/*:383*/
#line 2629 "./marpa.w"
;
/*384:*/
#line 2670 "./marpa.w"
{
Marpa_Symbol_ID proper_id= rhs_symbol_id(rule,first_factor_position);
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
gint first_factor_piece_position= first_factor_position-piece_start;
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
alias->id;
}
{struct marpa_rule*chaf_rule;
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2681 "./marpa.w"

}

/*:384*/
#line 2630 "./marpa.w"
;
/*385:*/
#line 2690 "./marpa.w"

if(piece_start<nullable_suffix_ix){
struct marpa_rule*chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2695 "./marpa.w"

}

/*:385*/
#line 2631 "./marpa.w"
;
}

/*:381*/
#line 2607 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*375:*/
#line 2564 "./marpa.w"
{
struct marpa_symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
context_clear(g);
context_int_add(g,"rule_id",rule_id);
context_int_add(g,"lhs_id",lhs_symbol_id(rule));
context_int_add(g,"virtual_end",piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:375*/
#line 2612 "./marpa.w"

/*387:*/
#line 2700 "./marpa.w"
{
gint piece_rhs_length;
struct marpa_rule*chaf_rule;
gint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:387*//*388:*/
#line 2709 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2715 "./marpa.w"


/*:388*//*389:*/
#line 2718 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2723 "./marpa.w"


/*:389*//*390:*/
#line 2726 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2732 "./marpa.w"


/*:390*//*391:*/
#line 2735 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2738 "./marpa.w"


/*:391*//*392:*/
#line 2741 "./marpa.w"
}

/*:392*/
#line 2613 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symbol_id;
piece_start= piece_end+1;

/*:380*/
#line 2556 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*393:*/
#line 2745 "./marpa.w"
{
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
gint second_factor_piece_position= second_factor_position-piece_start;
gint real_symbol_count;
gint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:393*//*394:*/
#line 2759 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2764 "./marpa.w"


/*:394*//*395:*/
#line 2767 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2772 "./marpa.w"


/*:395*//*396:*/
#line 2775 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2781 "./marpa.w"


/*:396*//*397:*/
#line 2785 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2789 "./marpa.w"

}

/*:397*//*398:*/
#line 2793 "./marpa.w"
}

/*:398*/
#line 2559 "./marpa.w"

}else{
/*399:*/
#line 2796 "./marpa.w"
{
gint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
gint real_symbol_count;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:399*//*400:*/
#line 2807 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2812 "./marpa.w"


/*:400*//*401:*/
#line 2816 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*403:*/
#line 2832 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:403*/
#line 2822 "./marpa.w"

}

/*:401*//*402:*/
#line 2826 "./marpa.w"
}

/*:402*/
#line 2561 "./marpa.w"

}}

/*:374*/
#line 2477 "./marpa.w"

NEXT_RULE:;
}
/*373:*/
#line 2541 "./marpa.w"

g_free(factor_positions);

/*:373*//*378:*/
#line 2591 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:378*/
#line 2480 "./marpa.w"

return g;
}
/*:365*//*404:*/
#line 2846 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
return alias->id;
}
/*:404*//*407:*/
#line 2860 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct marpa_symbol*proper_old_start= NULL;
struct marpa_symbol*nulling_old_start= NULL;
struct marpa_symbol*proper_new_start= NULL;
struct marpa_symbol*old_start= symbol_id2p(g,g->start_symbol);
/*409:*/
#line 2876 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:409*/
#line 2868 "./marpa.w"

if(proper_old_start){/*410:*/
#line 2886 "./marpa.w"
{
struct marpa_rule*new_start_rule;
proper_old_start->is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= proper_new_start->id;
g->start_symbol= proper_new_start_id;
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

/*:410*/
#line 2869 "./marpa.w"
}
if(nulling_old_start){/*411:*/
#line 2909 "./marpa.w"
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
g->start_symbol= nulling_new_start_id;
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

/*:411*/
#line 2870 "./marpa.w"
}
return g;
}
/*:407*//*415:*/
#line 2976 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{gint rule_id,no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*417:*/
#line 2999 "./marpa.w"

for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID proper_id;
Marpa_Symbol_ID lhs_id;
gint rhs_ix,rule_length;
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
gint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,rule_id,
g_array_index(lhs_rules,Marpa_Rule_ID,ix));
}}
NEXT_RULE:;
}

/*:417*/
#line 2983 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*418:*/
#line 3038 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule;
if(!matrix_bit_test(unit_transition_matrix,rule_id,rule_id))continue;
loop_rule_count++;
rule= rule_id2p(g,rule_id);
rule->is_loop= TRUE;
rule->is_virtual_loop= rule->virtual_start<0||!rule->is_virtual_rhs;
context_clear(g);
context_int_add(g,"rule_id",rule_id);
message(g,"loop rule");
}}

/*:418*/
#line 2985 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*419:*/
#line 3058 "./marpa.w"

context_clear(g);
context_int_add(g,"loop_rule_count",loop_rule_count);
message(g,"loop rule tally");

/*:419*/
#line 2987 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:415*//*427:*/
#line 3191 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return g->AHFA_items+item_id;
}
/*:427*//*429:*/
#line 3201 "./marpa.w"

gint marpa_AHFA_item_count(struct marpa_g*g){
/*559:*/
#line 4282 "./marpa.w"
const int failure_indicator= -1;
/*:559*/
#line 3203 "./marpa.w"

/*561:*/
#line 4286 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:561*/
#line 3204 "./marpa.w"

return g->no_of_items;
}
/*:429*//*431:*/
#line 3209 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*559:*/
#line 4282 "./marpa.w"
const int failure_indicator= -1;
/*:559*/
#line 3212 "./marpa.w"

/*561:*/
#line 4286 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:561*/
#line 3213 "./marpa.w"

/*563:*/
#line 4299 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}

/*:563*/
#line 3214 "./marpa.w"

return item_id2p(g,item_id)->rule->id;
}
/*:431*//*433:*/
#line 3220 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*560:*/
#line 4284 "./marpa.w"
const int failure_indicator= -2;

/*:560*/
#line 3223 "./marpa.w"

/*561:*/
#line 4286 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:561*/
#line 3224 "./marpa.w"

/*563:*/
#line 4299 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}

/*:563*/
#line 3225 "./marpa.w"

return item_id2p(g,item_id)->rule->id;
}
/*:433*//*435:*/
#line 3231 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*560:*/
#line 4284 "./marpa.w"
const int failure_indicator= -2;

/*:560*/
#line 3234 "./marpa.w"

/*561:*/
#line 4286 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:561*/
#line 3235 "./marpa.w"

/*563:*/
#line 4299 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}

/*:563*/
#line 3236 "./marpa.w"

return item_id2p(g,item_id)->postdot;
}
/*:435*//*437:*/
#line 3241 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*559:*/
#line 4282 "./marpa.w"
const int failure_indicator= -1;
/*:559*/
#line 3244 "./marpa.w"

/*561:*/
#line 4286 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:561*/
#line 3245 "./marpa.w"

/*563:*/
#line 4299 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}

/*:563*/
#line 3246 "./marpa.w"

return item_id2p(g,item_id)->sort_key;
}
/*:437*//*439:*/
#line 3253 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<g->no_of_items&&item_id>=0;
}
/*:439*//*441:*/
#line 3268 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
gint rule_id;
gint no_of_items;
gint no_of_rules= rule_count(g);
struct AHFA_item*base_item= g_new(struct AHFA_item,g->size);
struct AHFA_item*current_item= base_item;
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
/*443:*/
#line 3288 "./marpa.w"

struct AHFA_item*items_for_rule;
gint rhs_ix;
struct marpa_rule*rule= rule_id2p(g,rule_id);
if(!rule->is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->length;rhs_ix++){
/*444:*/
#line 3301 "./marpa.w"

Marpa_Symbol_ID rh_symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,rh_symbol_id);
if(symbol->is_nullable)goto NEXT_RH_SYMBOL;
current_item->sort_key= current_item-base_item;
current_item->postdot= rh_symbol_id;
current_item->rule= rule;
current_item->position= rhs_ix;

/*:444*/
#line 3294 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*445:*/
#line 3310 "./marpa.w"

current_item->sort_key= current_item-base_item;
current_item->postdot= current_item->position= -1;
current_item->rule= rule;

/*:445*/
#line 3298 "./marpa.w"

current_item++;

/*:443*/
#line 3277 "./marpa.w"

NEXT_RULE:;
}
no_of_items= g->no_of_items= current_item-base_item;
g->AHFA_items= g_renew(struct AHFA_item,base_item,no_of_items);
/*446:*/
#line 3320 "./marpa.w"
{
struct AHFA_item**items_by_rule= g_new0(struct AHFA_item*,no_of_rules);

struct AHFA_item*items= g->AHFA_items;
Marpa_Rule_ID found_rule_id= -1;

Marpa_AHFA_Item_ID item_id;
for(item_id= 0;item_id<no_of_items;item_id++){
struct AHFA_item*item= items+item_id;
Marpa_Rule_ID rule_id= item->rule->id;
if(rule_id<=found_rule_id)continue;
items_by_rule[rule_id]= item;
found_rule_id= rule_id;
}
g->AHFA_items_by_rule= items_by_rule;}

/*:446*/
#line 3282 "./marpa.w"

/*450:*/
#line 3348 "./marpa.w"
{gint item_id;
struct AHFA_item**sort_array= g_new(struct AHFA_item*,no_of_items);
struct AHFA_item*items= g->AHFA_items;
for(item_id= 0;item_id<no_of_items;item_id++){



sort_array[item_id]= items+item_id;
}
g_qsort_with_data(sort_array,
no_of_items,sizeof(struct AHFA_item*),cmp_by_AHFA_item_id,(gpointer)NULL);
for(item_id= 0;item_id<no_of_items;item_id++){
sort_array[item_id]->sort_key= item_id;
}
g_free(sort_array);}

/*:450*/
#line 3283 "./marpa.w"

}
/*:441*//*448:*/
#line 3339 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data){
return((struct AHFA_item*)a)->postdot-((struct AHFA_item*)b)->postdot
||((struct AHFA_item*)a)->sort_key-((struct AHFA_item*)b)->sort_key;
}
/*:448*//*456:*/
#line 3397 "./marpa.w"

static inline
void create_AHFA_states(struct marpa_g*g){
DQUEUE_DEFINE(states);
const gint initial_no_of_states= 2*g->size;
struct AHFA_state state;
struct AHFA_state*p_state;
DQUEUE_INIT(states,struct AHFA_state,initial_no_of_states);
p_state= DQUEUE_ADD(states,struct AHFA_state);
/*458:*/
#line 3416 "./marpa.w"
{;}

/*:458*/
#line 3406 "./marpa.w"

while(p_state= DQUEUE_NEXT(states,struct AHFA_state)){
/*459:*/
#line 3418 "./marpa.w"
{
gint no_of_items= state.item_count;
gint current_item= 0;
struct AHFA_item*items= state.items;
Marpa_Symbol_ID work_symbol= items[0].postdot;

if(work_symbol==-1)goto NEXT_AHFA_STATE;

while(1){
gint first_item_for_working_symbol= current_item;
for(current_item++;current_item<no_of_items;current_item++){
if(items[current_item].postdot==work_symbol)break;
}
switch(current_item-first_item_for_working_symbol){
case 1:/*460:*/
#line 3448 "./marpa.w"
{;}
/*:460*/
#line 3432 "./marpa.w"

case 2:/*461:*/
#line 3449 "./marpa.w"
{;}
/*:461*/
#line 3433 "./marpa.w"

default:/*462:*/
#line 3450 "./marpa.w"
{;}

/*:462*/
#line 3434 "./marpa.w"

}



/*463:*/
#line 3456 "./marpa.w"
;

/*:463*/
#line 3439 "./marpa.w"


if(current_item>=no_of_items)break;
work_symbol= items[current_item].postdot;
if(work_symbol==-1)break;
}
NEXT_AHFA_STATE:;
}

/*:459*/
#line 3408 "./marpa.w"

}
g->AHFA= DQUEUE_BASE(states,struct AHFA_state);
g->AHFA_len= DQUEUE_END(states);
}
/*:456*//*465:*/
#line 3488 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:465*//*467:*/
#line 3496 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:467*//*472:*/
#line 3529 "./marpa.w"

static inline guint bv_bits_to_size(gint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:472*//*474:*/
#line 3537 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:474*//*476:*/
#line 3553 "./marpa.w"

static inline Bit_Vector bv_create(gint bits)
{
guint size= bv_bits_to_size(bits);
guint bytes= (size+bv_hiddenwords)<<sizeof(guint);
guint*addr= (Bit_Vector)g_malloc0((size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}
/*:476*//*478:*/
#line 3570 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:478*//*480:*/
#line 3582 "./marpa.w"
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
/*:480*//*482:*/
#line 3602 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:482*//*484:*/
#line 3611 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:484*//*486:*/
#line 3619 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
*(--bv)&= BV_MASK(bv);
}
/*:486*//*489:*/
#line 3631 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:489*//*491:*/
#line 3639 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:491*//*493:*/
#line 3647 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:493*//*496:*/
#line 3656 "./marpa.w"

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
/*:496*//*498:*/
#line 3673 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:498*//*500:*/
#line 3685 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:500*//*502:*/
#line 3697 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:502*//*504:*/
#line 3709 "./marpa.w"

static inline
gboolean bv_scan(Bit_Vector bv,gint start,
gint*min,gint*max)
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
/*:504*//*510:*/
#line 3823 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv)
{
gint min,max,start= 0;
FSTACK_DEFINE(stack,Marpa_Symbol_ID);
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_INIT(stack,Marpa_Symbol_ID,symbol_count(g));
while(bv_scan(bv,start,&min,&max)){
gint symbol_id;
for(symbol_id= min;symbol_id<=max;symbol_id++){
*(FSTACK_PUSH(stack))= symbol_id;
}
start= max+2;
}
while(top_of_stack= FSTACK_POP(stack)){
gint rule_ix;
GArray*rules= symbol_id2p(g,*top_of_stack)->rhs;
for(rule_ix= 0;rule_ix<rules->len;rule_ix++){
Marpa_Rule_ID rule_id= g_array_index(rules,Marpa_Rule_ID,rule_ix);
struct marpa_rule*rule= rule_id2p(g,rule_id);
gint rule_length;
gint rh_ix;
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
if(bv_bit_test(bv,lhs_id))goto NEXT_RULE;
rule_length= rule->length;
for(rh_ix= 0;rh_ix<rule_length;rh_ix++){
if(!bv_bit_test(bv,rhs_symbol_id(rule,rh_ix)))goto NEXT_RULE;
}



bv_bit_set(bv,lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}
/*:510*//*515:*/
#line 3892 "./marpa.w"

static inline Bit_Matrix matrix_create(gint rows,gint columns)
{
guint bv_data_words= bv_bits_to_size(columns);
guint row_bytes= (bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
guint bv_mask= bv_bits_to_unused_mask(columns);
Bit_Vector_Word*matrix_addr= g_malloc0((size_t)(row_bytes*rows));
gint row;
for(row= 0;row<rows;row++){
gint row_start= row*(bv_data_words+bv_hiddenwords);
matrix_addr[row_start]= columns;
matrix_addr[row_start+1]= bv_data_words;
matrix_addr[row_start+2]= bv_mask;
}
return matrix_addr;
}
/*:515*//*517:*/
#line 3912 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:517*//*519:*/
#line 3925 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:519*//*521:*/
#line 3942 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,gint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:521*//*524:*/
#line 3952 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:524*//*527:*/
#line 3961 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:527*//*530:*/
#line 3970 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:530*//*532:*/
#line 3984 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix)
{
gint size= matrix_columns(matrix);
struct transition{gint from,to;};
DSTACK_DEFINE(stack);
struct transition*top_of_stack= NULL;
gint row;
DSTACK_INIT(stack,struct transition,1024);
for(row= 0;row<size;row++){
gint min,max,start;
Bit_Vector row_vector= matrix_row(matrix,row);
for(start= 0;bv_scan(row_vector,start,&min,&max);start= max+2){
gint column;
for(column= min;column<=max;column++){
struct transition*t= DSTACK_PUSH(stack,struct transition);
t->from= row;
t->to= column;
}}}
while(top_of_stack= DSTACK_POP(stack,struct transition)){
gint old_from= top_of_stack->from;
gint old_to= top_of_stack->to;
gint new_ix;
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
/*:532*//*535:*/
#line 4039 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa){
void*data= pa->data;
if(data)g_free(data);
}
/*:535*//*538:*/
#line 4058 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size){
dpa->pa.len= 0;dpa->size= size;dpa->pa.data= g_new(void*,size);}
/*:538*//*540:*/
#line 4063 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa){
p_array_destroy(&(dpa->pa));
}
/*:540*//*542:*/
#line 4069 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size){
dpa->pa.data= g_renew(void*,dpa->pa.data,new_size);
dpa->size= new_size;
}
/*:542*//*544:*/
#line 4076 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p){
if(dpa->pa.len>=dpa->size)dp_array_resize(dpa,dpa->size*2);
dpa->pa.data[dpa->pa.len++]= p;
}
/*:544*//*546:*/
#line 4085 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa){
gint len= pa->len= dpa->pa.len;
if(G_UNLIKELY(len>=dpa->size)){
pa->data= dpa->pa.data;
return;
}
pa->data= g_renew(void*,dpa->pa.data,len);
}
/*:546*//*552:*/
#line 4154 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:552*//*569:*/
#line 4368 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->message_callback_arg= cb_arg;}
void*marpa_message_callback_arg(struct marpa_g*g)
{return g->message_callback_arg;}
/*:569*//*571:*/
#line 4380 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:571*/
#line 4497 "./marpa.w"





/*:579*/
