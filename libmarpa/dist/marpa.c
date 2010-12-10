/*583:*/
#line 4514 "./marpa.w"

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


#line 4550 "./marpa.w"

#include "marpa_obs.h"
/*569:*/
#line 4387 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:569*/
#line 4552 "./marpa.w"

/*473:*/
#line 3569 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:473*//*516:*/
#line 3939 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:516*/
#line 4553 "./marpa.w"

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
/*:29*//*474:*/
#line 3576 "./marpa.w"

static const int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const int bv_hiddenwords= 3;
static const int bv_lsb= 1u;
static const int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:474*/
#line 4554 "./marpa.w"

/*537:*/
#line 4092 "./marpa.w"

struct p_array{gint len;void**data;};
/*:537*//*540:*/
#line 4111 "./marpa.w"

struct dp_array{struct p_array pa;gint size;};
/*:540*/
#line 4555 "./marpa.w"

/*21:*/
#line 441 "./marpa.w"
struct marpa_g{
/*33:*/
#line 491 "./marpa.w"
GArray*symbols;
/*:33*//*45:*/
#line 547 "./marpa.w"
GArray*rules;
/*:45*//*83:*/
#line 728 "./marpa.w"
GHashTable*context;
/*:83*//*98:*/
#line 813 "./marpa.w"
struct obstack obs;
/*:98*//*102:*/
#line 829 "./marpa.w"
Marpa_Error_ID error;
/*:102*//*189:*/
#line 1250 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
void*symbol_callback_arg;
/*:189*//*296:*/
#line 1944 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
void*rule_callback_arg;
/*:296*//*418:*/
#line 3132 "./marpa.w"

struct AHFA_item*AHFA_items;
struct AHFA_item**AHFA_items_by_rule;
/*:418*//*446:*/
#line 3355 "./marpa.w"
struct AHFA_state*AHFA;
/*:446*//*572:*/
#line 4427 "./marpa.w"

Marpa_Message_Callback*message_callback;
void*message_callback_arg;
/*:572*/
#line 442 "./marpa.w"

/*27:*/
#line 474 "./marpa.w"
int id;
/*:27*//*57:*/
#line 603 "./marpa.w"
Marpa_Symbol_ID start_symbol_id;
/*:57*//*64:*/
#line 651 "./marpa.w"
int size;
/*:64*//*67:*/
#line 664 "./marpa.w"
int max_rule_length;
/*:67*//*417:*/
#line 3130 "./marpa.w"

gint no_of_items;
/*:417*//*447:*/
#line 3356 "./marpa.w"
gint AHFA_len;
/*:447*/
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
/*:77*/
#line 444 "./marpa.w"

};

/*:21*//*113:*/
#line 873 "./marpa.w"

struct marpa_symbol{
/*122:*/
#line 918 "./marpa.w"
GArray*lhs;
/*:122*//*129:*/
#line 945 "./marpa.w"
GArray*rhs;
/*:129*//*176:*/
#line 1142 "./marpa.w"

struct marpa_symbol*alias;
/*:176*/
#line 875 "./marpa.w"

/*120:*/
#line 910 "./marpa.w"
Marpa_Symbol_ID id;
/*:120*/
#line 876 "./marpa.w"

/*136:*/
#line 966 "./marpa.w"
unsigned int is_accessible:1;
/*:136*//*142:*/
#line 992 "./marpa.w"
unsigned int is_counted:1;
/*:142*//*146:*/
#line 1010 "./marpa.w"
unsigned int is_nullable:1;
/*:146*//*152:*/
#line 1035 "./marpa.w"
unsigned int is_nulling:1;
/*:152*//*158:*/
#line 1062 "./marpa.w"
unsigned int is_terminal:1;
/*:158*//*164:*/
#line 1088 "./marpa.w"
unsigned int is_productive:1;
/*:164*//*170:*/
#line 1113 "./marpa.w"
unsigned int is_start:1;
/*:170*//*175:*/
#line 1139 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:175*/
#line 877 "./marpa.w"

};

/*:113*//*195:*/
#line 1275 "./marpa.w"

struct marpa_rule{
/*229:*/
#line 1669 "./marpa.w"
gsize length;
/*:229*/
#line 1277 "./marpa.w"

/*249:*/
#line 1733 "./marpa.w"
Marpa_Rule_ID id;
/*:249*//*290:*/
#line 1925 "./marpa.w"
gint virtual_start;
/*:290*//*292:*/
#line 1932 "./marpa.w"
gint virtual_end;
/*:292*//*306:*/
#line 1974 "./marpa.w"
Marpa_Rule_ID original;
/*:306*//*310:*/
#line 1986 "./marpa.w"
gint real_symbol_count;
/*:310*/
#line 1278 "./marpa.w"

/*252:*/
#line 1745 "./marpa.w"
unsigned int is_discard:1;
/*:252*//*266:*/
#line 1825 "./marpa.w"
unsigned int is_loop:1;
/*:266*//*271:*/
#line 1844 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:271*//*278:*/
#line 1872 "./marpa.w"
unsigned int is_used:1;
/*:278*//*282:*/
#line 1900 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:282*//*286:*/
#line 1911 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:286*//*313:*/
#line 1993 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:313*/
#line 1279 "./marpa.w"

/*230:*/
#line 1672 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:230*/
#line 1280 "./marpa.w"

};
/*:195*//*416:*/
#line 3117 "./marpa.w"

struct AHFA_item{
Marpa_Symbol_ID postdot;

Marpa_AHFA_Item_ID sort_key;
struct marpa_rule*rule;
gint position;
};
/*:416*//*445:*/
#line 3349 "./marpa.w"

struct AHFA_state{
struct AHFA_item**items;
gint item_count;
unsigned int is_reset:1;
};
/*:445*//*554:*/
#line 4207 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:554*//*557:*/
#line 4237 "./marpa.w"

struct dqueue{gint current;struct dstack s;};

/*:557*/
#line 4556 "./marpa.w"

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

/*:56*//*91:*/
#line 779 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:91*//*93:*/
#line 791 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:93*//*95:*/
#line 800 "./marpa.w"

static inline void context_clear(struct marpa_g*g);

/*:95*//*115:*/
#line 894 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:115*//*119:*/
#line 906 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol);

/*:119*//*128:*/
#line 937 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);

/*:128*//*135:*/
#line 962 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);

/*:135*//*173:*/
#line 1126 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol);
/*:173*//*179:*/
#line 1167 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol);
/*:179*//*182:*/
#line 1195 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol);
/*:182*//*185:*/
#line 1234 "./marpa.w"

static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
/*:185*//*193:*/
#line 1269 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:193*//*197:*/
#line 1286 "./marpa.w"

static inline gsize rule_sizeof(gint length);

/*:197*//*200:*/
#line 1309 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);

/*:200*//*217:*/
#line 1533 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length);

/*:217*//*218:*/
#line 1538 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:218*//*228:*/
#line 1661 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule);

/*:228*//*234:*/
#line 1686 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:234*//*238:*/
#line 1697 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:238*//*242:*/
#line 1708 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:242*//*246:*/
#line 1720 "./marpa.w"

static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule*rule);
/*:246*//*248:*/
#line 1727 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,gint index);

/*:248*//*259:*/
#line 1792 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule);
/*:259*//*263:*/
#line 1814 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule);
/*:263*//*277:*/
#line 1868 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule);

/*:277*//*304:*/
#line 1967 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:304*//*323:*/
#line 2114 "./marpa.w"

static inline struct marpa_g*census(struct marpa_g*g);
/*:323*//*359:*/
#line 2435 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:359*//*398:*/
#line 2804 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:398*//*401:*/
#line 2825 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:401*//*409:*/
#line 2942 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:409*//*421:*/
#line 3148 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:421*//*433:*/
#line 3210 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:433*//*435:*/
#line 3237 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:435*//*442:*/
#line 3304 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:442*//*450:*/
#line 3364 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:450*//*452:*/
#line 3374 "./marpa.w"

static inline gint AHFA_state_is_valid(
struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:452*//*460:*/
#line 3445 "./marpa.w"

static inline void create_AHFA_states(struct marpa_g*g);

/*:460*//*476:*/
#line 3589 "./marpa.w"

static inline guint bv_bits_to_size(gint bits);
/*:476*//*478:*/
#line 3599 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits);

/*:478*//*480:*/
#line 3619 "./marpa.w"

static inline Bit_Vector bv_create(gint bits);

/*:480*//*482:*/
#line 3630 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:482*//*484:*/
#line 3652 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:484*//*486:*/
#line 3662 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:486*//*488:*/
#line 3670 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:488*//*490:*/
#line 3682 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:490*//*493:*/
#line 3690 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit);

/*:493*//*495:*/
#line 3698 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit);

/*:495*//*497:*/
#line 3706 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit);

/*:497*//*500:*/
#line 3723 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:500*//*502:*/
#line 3736 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:502*//*504:*/
#line 3748 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:504*//*506:*/
#line 3760 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:506*//*508:*/
#line 3834 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,gint start,gint*min,gint*max);

/*:508*//*514:*/
#line 3916 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:514*//*519:*/
#line 3963 "./marpa.w"

static inline Bit_Matrix matrix_create(gint rows,gint columns);

/*:519*//*521:*/
#line 3971 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:521*//*523:*/
#line 3985 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:523*//*525:*/
#line 4003 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,gint row);

/*:525*//*528:*/
#line 4012 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,gint row,gint column);

/*:528*//*531:*/
#line 4021 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,gint row,gint column);

/*:531*//*534:*/
#line 4030 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,gint row,gint column);

/*:534*//*536:*/
#line 4084 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:536*//*539:*/
#line 4099 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa);

/*:539*//*542:*/
#line 4116 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size);
/*:542*//*544:*/
#line 4122 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa);
/*:544*//*546:*/
#line 4129 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size);
/*:546*//*548:*/
#line 4136 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p);
/*:548*//*550:*/
#line 4149 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa);


/*:550*//*556:*/
#line 4215 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:556*//*576:*/
#line 4446 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id);

/*:576*/
#line 4557 "./marpa.w"

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
#line 4558 "./marpa.w"

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

g->start_symbol_id= -1;
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
#line 729 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:84*//*99:*/
#line 814 "./marpa.w"
obstack_init(&g->obs);
/*:99*//*103:*/
#line 830 "./marpa.w"

g->error= 0;
/*:103*/
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

/*:47*//*85:*/
#line 731 "./marpa.w"
g_hash_table_destroy(g->context);

/*:85*//*100:*/
#line 815 "./marpa.w"
obstack_free(&g->obs,NULL);

/*:100*//*117:*/
#line 900 "./marpa.w"

{int id;for(id= 0;id<g->symbols->len;id++)
{marpa_symbol_free(symbol_id2p(g,id));}}
/*:117*//*226:*/
#line 1652 "./marpa.w"

{int id;for(id= 0;id<g->rules->len;id++)
{marpa_rule_free(rule_id2p(g,id));}}
/*:226*//*419:*/
#line 3138 "./marpa.w"
if(g->AHFA_items){
g_free(g->AHFA_items_by_rule);
g_free(g->AHFA_items);
};

/*:419*//*448:*/
#line 3357 "./marpa.w"
if(g->AHFA){STOLEN_DQUEUE_DATA_FREE(g->AHFA);}

/*:448*/
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
{return g->start_symbol_id;}
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
g->start_symbol_id= id;
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
/*:81*//*90:*/
#line 770 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:90*//*92:*/
#line 782 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:92*//*94:*/
#line 797 "./marpa.w"

static inline void context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:94*//*96:*/
#line 803 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:96*//*105:*/
#line 838 "./marpa.w"

Marpa_Error_ID marpa_error(struct marpa_g*g)
{return g->error?:"unknown error";}
/*:105*//*108:*/
#line 852 "./marpa.w"

void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

return;

}

/*:108*//*110:*/
#line 865 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce){}
/*:110*//*114:*/
#line 880 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*121:*/
#line 911 "./marpa.w"
symbol->id= g->symbols->len;

/*:121*//*123:*/
#line 919 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:123*//*130:*/
#line 946 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:130*//*137:*/
#line 967 "./marpa.w"

symbol->is_accessible= FALSE;
/*:137*//*143:*/
#line 993 "./marpa.w"

symbol->is_counted= FALSE;
/*:143*//*147:*/
#line 1011 "./marpa.w"

symbol->is_nullable= FALSE;
/*:147*//*153:*/
#line 1036 "./marpa.w"

symbol->is_nulling= FALSE;
/*:153*//*159:*/
#line 1063 "./marpa.w"

symbol->is_terminal= FALSE;
/*:159*//*165:*/
#line 1089 "./marpa.w"

symbol->is_productive= FALSE;
/*:165*//*171:*/
#line 1114 "./marpa.w"
symbol->is_start= FALSE;
/*:171*//*177:*/
#line 1144 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:177*/
#line 884 "./marpa.w"

{Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);}
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;}

/*:114*//*118:*/
#line 903 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol)
{/*124:*/
#line 921 "./marpa.w"
g_array_free(symbol->lhs,TRUE);
/*:124*//*131:*/
#line 948 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:131*/
#line 905 "./marpa.w"
g_free(symbol);}
/*:118*//*125:*/
#line 925 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*561:*/
#line 4335 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:561*/
#line 927 "./marpa.w"

/*565:*/
#line 4347 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:565*/
#line 928 "./marpa.w"

return symbol_id2p(g,symbol_id)->lhs;}
/*:125*//*127:*/
#line 932 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:127*//*132:*/
#line 952 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*561:*/
#line 4335 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:561*/
#line 954 "./marpa.w"

/*565:*/
#line 4347 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:565*/
#line 955 "./marpa.w"

return symbol_id2p(g,symbol_id)->rhs;}
/*:132*//*134:*/
#line 959 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
/*:134*//*138:*/
#line 977 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:138*//*140:*/
#line 983 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:140*//*144:*/
#line 1003 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:144*//*148:*/
#line 1021 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:148*//*150:*/
#line 1027 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:150*//*154:*/
#line 1046 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 1048 "./marpa.w"

/*565:*/
#line 4347 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:565*/
#line 1049 "./marpa.w"

return symbol_id2p(g,symbol_id)->is_nulling;}
/*:154*//*156:*/
#line 1054 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:156*//*160:*/
#line 1073 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:160*//*162:*/
#line 1079 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:162*//*166:*/
#line 1099 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:166*//*168:*/
#line 1105 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value;}
/*:168*//*172:*/
#line 1117 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 1122 "./marpa.w"

/*565:*/
#line 4347 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:565*/
#line 1123 "./marpa.w"

return symbol_is_start(symbol_id2p(g,symbol_id));
}
/*:172*//*178:*/
#line 1153 "./marpa.w"

static inline
struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol)
{return symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*proper_alias;
/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 1161 "./marpa.w"

/*565:*/
#line 4347 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:565*/
#line 1162 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->id;
}
/*:178*//*181:*/
#line 1176 "./marpa.w"

static inline
struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*alias;
/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 1184 "./marpa.w"

/*565:*/
#line 4347 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:565*/
#line 1185 "./marpa.w"

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
#line 1209 "./marpa.w"
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
/*:184*//*190:*/
#line 1253 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->symbol_callback_arg= cb_arg;}
void*marpa_symbol_callback_arg(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:190*//*192:*/
#line 1265 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:192*//*196:*/
#line 1282 "./marpa.w"

static inline gsize rule_sizeof(gint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:196*//*199:*/
#line 1294 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
int i;
struct marpa_rule*rule;
/*231:*/
#line 1673 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{int i;for(i= 0;i<length;i++){
if(!symbol_is_valid(g,rhs[i])){return NULL;}
}}
/*:231*/
#line 1301 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*232:*/
#line 1678 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{int i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:232*/
#line 1303 "./marpa.w"

/*250:*/
#line 1734 "./marpa.w"
rule->id= g->rules->len;

/*:250*//*253:*/
#line 1746 "./marpa.w"

rule->is_discard= FALSE;
/*:253*//*267:*/
#line 1826 "./marpa.w"

rule->is_loop= FALSE;
/*:267*//*272:*/
#line 1845 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:272*//*279:*/
#line 1873 "./marpa.w"

rule->is_used= TRUE;
/*:279*//*283:*/
#line 1901 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:283*//*287:*/
#line 1912 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:287*//*291:*/
#line 1926 "./marpa.w"
rule->virtual_start= -1;

/*:291*//*293:*/
#line 1933 "./marpa.w"
rule->virtual_end= -1;

/*:293*//*307:*/
#line 1975 "./marpa.w"
rule->original= -1;
/*:307*//*311:*/
#line 1987 "./marpa.w"
rule->real_symbol_count= 0;
/*:311*//*314:*/
#line 1994 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:314*/
#line 1304 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*220:*/
#line 1554 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const gint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*224:*/
#line 1621 "./marpa.w"

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
#line 1306 "./marpa.w"

return rule;
}
/*:199*//*201:*/
#line 1314 "./marpa.w"

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

/*:201*//*202:*/
#line 1331 "./marpa.w"

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

/*205:*/
#line 1370 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*204:*/
#line 1368 "./marpa.w"
g->error= "internal_error";return-1;
/*:204*/
#line 1372 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:205*/
#line 1348 "./marpa.w"

/*206:*/
#line 1376 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:206*/
#line 1349 "./marpa.w"

/*207:*/
#line 1380 "./marpa.w"

symbol_id2p(g,rhs_id)->is_counted= 1;
if(separator_id>=0){symbol_id2p(g,separator_id)->is_counted= 1;}
/*:207*/
#line 1350 "./marpa.w"

if(min==0){/*208:*/
#line 1383 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*204:*/
#line 1368 "./marpa.w"
g->error= "internal_error";return-1;
/*:204*/
#line 1385 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:208*/
#line 1351 "./marpa.w"
}
min= 1;
/*209:*/
#line 1390 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:209*/
#line 1353 "./marpa.w"

/*210:*/
#line 1404 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:210*/
#line 1354 "./marpa.w"

/*212:*/
#line 1407 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*204:*/
#line 1368 "./marpa.w"
g->error= "internal_error";return-1;
/*:204*/
#line 1411 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:212*/
#line 1355 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*213:*/
#line 1420 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*204:*/
#line 1368 "./marpa.w"
g->error= "internal_error";return-1;
/*:204*/
#line 1425 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:213*/
#line 1357 "./marpa.w"

}
/*214:*/
#line 1437 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*204:*/
#line 1368 "./marpa.w"
g->error= "internal_error";return-1;
/*:204*/
#line 1447 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:214*/
#line 1359 "./marpa.w"

/*215:*/
#line 1452 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*204:*/
#line 1368 "./marpa.w"
g->error= "internal_error";return-1;
/*:204*/
#line 1459 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:215*/
#line 1360 "./marpa.w"

/*211:*/
#line 1406 "./marpa.w"
g_free(temp_rhs);
/*:211*/
#line 1361 "./marpa.w"

return original_rule_id;
}
/*:202*//*216:*/
#line 1509 "./marpa.w"

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
/*:216*//*227:*/
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
/*317:*/
#line 2013 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:317*/
#line 1690 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:235*//*237:*/
#line 1694 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:237*//*239:*/
#line 1699 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*318:*/
#line 2020 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return NULL;
}

/*:318*/
#line 1701 "./marpa.w"

return rule_rhs_get(rule_id2p(g,rule_id));}
/*:239*//*241:*/
#line 1705 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:241*//*243:*/
#line 1710 "./marpa.w"

gsize marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*317:*/
#line 2013 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:317*/
#line 1712 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:243*//*245:*/
#line 1717 "./marpa.w"

static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule*rule){return rule->symbols[0];}
/*:245*//*247:*/
#line 1722 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,gint index){
return rule->symbols[index+1];
}
/*:247*//*254:*/
#line 1748 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:254*//*258:*/
#line 1781 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule)
{
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
return symbol_id2p(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{struct marpa_rule*rule;
/*317:*/
#line 2013 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:317*/
#line 1788 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:258*//*262:*/
#line 1799 "./marpa.w"

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
/*317:*/
#line 2013 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:317*/
#line 1810 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:262*//*268:*/
#line 1830 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{/*317:*/
#line 2013 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:317*/
#line 1832 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:268*//*273:*/
#line 1849 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{/*317:*/
#line 2013 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:317*/
#line 1851 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:273*//*276:*/
#line 1859 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:276*//*280:*/
#line 1877 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{/*317:*/
#line 2013 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:317*/
#line 1879 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:280*//*284:*/
#line 1904 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:284*//*288:*/
#line 1915 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:288*//*297:*/
#line 1947 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:297*//*299:*/
#line 1952 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:299*//*301:*/
#line 1957 "./marpa.w"

void*marpa_rule_callback_arg(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:301*//*303:*/
#line 1963 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:303*//*308:*/
#line 1976 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}

/*:308*//*312:*/
#line 1988 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}

/*:312*//*315:*/
#line 2005 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:315*//*319:*/
#line 2038 "./marpa.w"

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
#line 2084 "./marpa.w"

static inline struct marpa_g*census(struct marpa_g*g)
{
/*324:*/
#line 2116 "./marpa.w"

gint pre_rewrite_rule_count= g->rules->len;
gint pre_rewrite_symbol_count= g->symbols->len;

/*:324*//*329:*/
#line 2149 "./marpa.w"

Marpa_Symbol_ID original_start_symbol_id= g->start_symbol_id;
struct marpa_symbol*original_start_symbol;

/*:329*//*333:*/
#line 2182 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:333*//*339:*/
#line 2240 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:339*//*341:*/
#line 2265 "./marpa.w"

Bit_Vector nullable_v;
/*:341*//*345:*/
#line 2288 "./marpa.w"

Bit_Vector productive_v;
/*:345*//*350:*/
#line 2341 "./marpa.w"

Bit_Vector accessible_v;

/*:350*/
#line 2087 "./marpa.w"

/*325:*/
#line 2120 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:325*/
#line 2088 "./marpa.w"

/*326:*/
#line 2127 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:326*/
#line 2089 "./marpa.w"

/*328:*/
#line 2133 "./marpa.w"

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
#line 2090 "./marpa.w"

/*330:*/
#line 2153 "./marpa.w"

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
/*:330*/
#line 2091 "./marpa.w"

/*331:*/
#line 2170 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symbol_id= 0;symbol_id<pre_rewrite_symbol_count;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_terminal){
bv_bit_set(terminal_v,symbol_id);
have_marked_terminals= 1;
}
}}
/*:331*/
#line 2092 "./marpa.w"

if(have_marked_terminals){
/*335:*/
#line 2197 "./marpa.w"

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

/*:335*/
#line 2094 "./marpa.w"

}else{
/*334:*/
#line 2186 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:334*/
#line 2096 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*336:*/
#line 2220 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<g->symbols->len;symbol_id++)
{symbol_id2p(g,symbol_id)->is_terminal= 1;}}
/*:336*/
#line 2098 "./marpa.w"

}else{
/*337:*/
#line 2225 "./marpa.w"

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
/*:337*/
#line 2100 "./marpa.w"

}
}
/*340:*/
#line 2245 "./marpa.w"

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
/*:340*/
#line 2103 "./marpa.w"

/*343:*/
#line 2270 "./marpa.w"

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
/*:343*/
#line 2104 "./marpa.w"

/*344:*/
#line 2281 "./marpa.w"

if(!bv_bit_test(productive_v,g->start_symbol_id))
{
context_int_add(g,"symbol_id",g->start_symbol_id);
g->error= "unproductive start symbol";
return NULL;
}
/*:344*/
#line 2105 "./marpa.w"

/*347:*/
#line 2311 "./marpa.w"

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
/*:347*/
#line 2106 "./marpa.w"

/*349:*/
#line 2330 "./marpa.w"

accessible_v= matrix_row(reach_matrix,original_start_symbol_id);
{gint min,max,start,symbol_id;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symbol_id= min;symbol_id<=max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
symbol->is_accessible= 1;
}}
}
/*:349*/
#line 2107 "./marpa.w"

/*351:*/
#line 2346 "./marpa.w"

{Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
gint min,max,start;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
Marpa_Symbol_ID productive_id;
for(productive_id= min;productive_id<=max;productive_id++){
bv_and(reaches_terminal_v,terminal_v,matrix_row(reach_matrix,productive_id));
if(bv_is_empty(reaches_terminal_v))symbol_id2p(g,productive_id)->is_nulling= 1;
}}
bv_free(reaches_terminal_v);}

/*:351*/
#line 2108 "./marpa.w"

/*332:*/
#line 2180 "./marpa.w"

bv_free(terminal_v);
/*:332*//*338:*/
#line 2237 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:338*//*342:*/
#line 2267 "./marpa.w"

bv_free(nullable_v);

/*:342*//*346:*/
#line 2290 "./marpa.w"

bv_free(productive_v);

/*:346*/
#line 2109 "./marpa.w"

/*348:*/
#line 2327 "./marpa.w"

matrix_free(reach_matrix);

/*:348*/
#line 2110 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:322*//*358:*/
#line 2414 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*360:*/
#line 2437 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:360*//*364:*/
#line 2488 "./marpa.w"

gint factor_count;
gint*factor_positions;
/*:364*//*369:*/
#line 2537 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:369*/
#line 2417 "./marpa.w"

/*365:*/
#line 2491 "./marpa.w"

factor_positions= g_new(gint,g->max_rule_length);
/*:365*//*370:*/
#line 2540 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:370*/
#line 2418 "./marpa.w"

/*362:*/
#line 2449 "./marpa.w"

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

/*:362*/
#line 2419 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
gint rule_length= rule->length;
gint nullable_suffix_ix= 0;
/*361:*/
#line 2441 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:361*/
#line 2425 "./marpa.w"

/*363:*/
#line 2472 "./marpa.w"

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
/*:363*/
#line 2426 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*367:*/
#line 2497 "./marpa.w"

rule->is_used= 0;
{gint unprocessed_factor_count;

gint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= lhs_symbol_id(rule);
gint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*373:*/
#line 2550 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symbol_id;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*368:*/
#line 2516 "./marpa.w"
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

/*:368*/
#line 2558 "./marpa.w"

/*374:*/
#line 2577 "./marpa.w"

{
gint remaining_rhs_length,piece_rhs_length;
/*375:*/
#line 2589 "./marpa.w"

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
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2601 "./marpa.w"

}

/*:375*/
#line 2580 "./marpa.w"
;
/*376:*/
#line 2604 "./marpa.w"

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
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2617 "./marpa.w"

}

/*:376*/
#line 2581 "./marpa.w"
;
/*377:*/
#line 2622 "./marpa.w"
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
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2633 "./marpa.w"

}

/*:377*/
#line 2582 "./marpa.w"
;
/*378:*/
#line 2642 "./marpa.w"

if(piece_start<nullable_suffix_ix){
struct marpa_rule*chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2647 "./marpa.w"

}

/*:378*/
#line 2583 "./marpa.w"
;
}

/*:374*/
#line 2559 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*368:*/
#line 2516 "./marpa.w"
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

/*:368*/
#line 2564 "./marpa.w"

/*380:*/
#line 2652 "./marpa.w"
{
gint piece_rhs_length;
struct marpa_rule*chaf_rule;
gint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:380*//*381:*/
#line 2661 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2667 "./marpa.w"


/*:381*//*382:*/
#line 2670 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2675 "./marpa.w"


/*:382*//*383:*/
#line 2678 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2684 "./marpa.w"


/*:383*//*384:*/
#line 2687 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2690 "./marpa.w"


/*:384*//*385:*/
#line 2693 "./marpa.w"
}

/*:385*/
#line 2565 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symbol_id;
piece_start= piece_end+1;

/*:373*/
#line 2508 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*386:*/
#line 2697 "./marpa.w"
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

/*:386*//*387:*/
#line 2711 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2716 "./marpa.w"


/*:387*//*388:*/
#line 2719 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2724 "./marpa.w"


/*:388*//*389:*/
#line 2727 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2733 "./marpa.w"


/*:389*//*390:*/
#line 2737 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2741 "./marpa.w"

}

/*:390*//*391:*/
#line 2745 "./marpa.w"
}

/*:391*/
#line 2511 "./marpa.w"

}else{
/*392:*/
#line 2748 "./marpa.w"
{
gint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
gint real_symbol_count;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:392*//*393:*/
#line 2759 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2764 "./marpa.w"


/*:393*//*394:*/
#line 2768 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*396:*/
#line 2784 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:396*/
#line 2774 "./marpa.w"

}

/*:394*//*395:*/
#line 2778 "./marpa.w"
}

/*:395*/
#line 2513 "./marpa.w"

}}

/*:367*/
#line 2429 "./marpa.w"

NEXT_RULE:;
}
/*366:*/
#line 2493 "./marpa.w"

g_free(factor_positions);

/*:366*//*371:*/
#line 2543 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:371*/
#line 2432 "./marpa.w"

return g;
}
/*:358*//*397:*/
#line 2798 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
return alias->id;
}
/*:397*//*400:*/
#line 2812 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct marpa_symbol*proper_old_start= NULL;
struct marpa_symbol*nulling_old_start= NULL;
struct marpa_symbol*proper_new_start= NULL;
struct marpa_symbol*old_start= symbol_id2p(g,g->start_symbol_id);
/*402:*/
#line 2828 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:402*/
#line 2820 "./marpa.w"

if(proper_old_start){/*403:*/
#line 2838 "./marpa.w"
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

/*:403*/
#line 2821 "./marpa.w"
}
if(nulling_old_start){/*404:*/
#line 2861 "./marpa.w"
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

/*:404*/
#line 2822 "./marpa.w"
}
return g;
}
/*:400*//*408:*/
#line 2928 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{gint rule_id,no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*410:*/
#line 2951 "./marpa.w"

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

/*:410*/
#line 2935 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*411:*/
#line 2990 "./marpa.w"
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

/*:411*/
#line 2937 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*412:*/
#line 3010 "./marpa.w"

context_clear(g);
context_int_add(g,"loop_rule_count",loop_rule_count);
message(g,"loop rule tally");

/*:412*/
#line 2939 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:408*//*420:*/
#line 3143 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return g->AHFA_items+item_id;
}
/*:420*//*422:*/
#line 3153 "./marpa.w"

gint marpa_AHFA_item_count(struct marpa_g*g){
/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 3155 "./marpa.w"

/*564:*/
#line 4341 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:564*/
#line 3156 "./marpa.w"

return g->no_of_items;
}
/*:422*//*424:*/
#line 3161 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 3164 "./marpa.w"

/*564:*/
#line 4341 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:564*/
#line 3165 "./marpa.w"

/*566:*/
#line 4354 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:566*/
#line 3166 "./marpa.w"

return item_id2p(g,item_id)->rule->id;
}
/*:424*//*426:*/
#line 3172 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*563:*/
#line 4339 "./marpa.w"
const int failure_indicator= -2;

/*:563*/
#line 3175 "./marpa.w"

/*564:*/
#line 4341 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:564*/
#line 3176 "./marpa.w"

/*566:*/
#line 4354 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:566*/
#line 3177 "./marpa.w"

return item_id2p(g,item_id)->position;
}
/*:426*//*428:*/
#line 3183 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*563:*/
#line 4339 "./marpa.w"
const int failure_indicator= -2;

/*:563*/
#line 3186 "./marpa.w"

/*564:*/
#line 4341 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:564*/
#line 3187 "./marpa.w"

/*566:*/
#line 4354 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:566*/
#line 3188 "./marpa.w"

return item_id2p(g,item_id)->postdot;
}
/*:428*//*430:*/
#line 3193 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 3196 "./marpa.w"

/*564:*/
#line 4341 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:564*/
#line 3197 "./marpa.w"

/*566:*/
#line 4354 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:566*/
#line 3198 "./marpa.w"

return item_id2p(g,item_id)->sort_key;
}
/*:430*//*432:*/
#line 3205 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<g->no_of_items&&item_id>=0;
}
/*:432*//*434:*/
#line 3220 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
gint rule_id;
gint no_of_items;
gint no_of_rules= rule_count(g);
struct AHFA_item*base_item= g_new(struct AHFA_item,g->size);
struct AHFA_item*current_item= base_item;
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
/*436:*/
#line 3240 "./marpa.w"

struct AHFA_item*items_for_rule;
gint rhs_ix;
struct marpa_rule*rule= rule_id2p(g,rule_id);
if(!rule->is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->length;rhs_ix++){
/*437:*/
#line 3253 "./marpa.w"

Marpa_Symbol_ID rh_symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,rh_symbol_id);
if(symbol->is_nullable)goto NEXT_RH_SYMBOL;
current_item->sort_key= current_item-base_item;
current_item->postdot= rh_symbol_id;
current_item->rule= rule;
current_item->position= rhs_ix;

/*:437*/
#line 3246 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*438:*/
#line 3262 "./marpa.w"

current_item->sort_key= current_item-base_item;
current_item->postdot= current_item->position= -1;
current_item->rule= rule;

/*:438*/
#line 3250 "./marpa.w"

current_item++;

/*:436*/
#line 3229 "./marpa.w"

NEXT_RULE:;
}
no_of_items= g->no_of_items= current_item-base_item;
g->AHFA_items= g_renew(struct AHFA_item,base_item,no_of_items);
/*439:*/
#line 3272 "./marpa.w"
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

/*:439*/
#line 3234 "./marpa.w"

/*443:*/
#line 3307 "./marpa.w"
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

/*:443*/
#line 3235 "./marpa.w"

}
/*:434*//*441:*/
#line 3292 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer ap,
gconstpointer bp,gpointer user_data){
struct AHFA_item*a= *(struct AHFA_item**)ap;
struct AHFA_item*b= *(struct AHFA_item**)bp;
gint a_postdot= a->postdot;
gint b_postdot= b->postdot;
if(a_postdot==b_postdot)return a->sort_key-b->sort_key;
if(a_postdot<0)return 1;
if(b_postdot<0)return-1;
return a_postdot-b_postdot;
}
/*:441*//*449:*/
#line 3360 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{return g->AHFA+AHFA_state_id;};
/*:449*//*451:*/
#line 3369 "./marpa.w"

static inline gint AHFA_state_is_valid(
struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id){
return AHFA_state_id<g->AHFA_len&&AHFA_state_id>=0;
}
/*:451*//*453:*/
#line 3379 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 3382 "./marpa.w"

struct AHFA_state*state;
/*564:*/
#line 4341 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:564*/
#line 3384 "./marpa.w"

/*567:*/
#line 4361 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:567*/
#line 3385 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->item_count;
}
/*:453*//*455:*/
#line 3392 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
gint item_ix){
struct AHFA_state*state;
/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 3397 "./marpa.w"

/*564:*/
#line 4341 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:564*/
#line 3398 "./marpa.w"

/*567:*/
#line 4361 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:567*/
#line 3399 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
if(item_ix<0||item_ix>=state->item_count){
context_clear(g);
context_int_add(g,"item_ix",item_ix);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid state item ix";
return failure_indicator;
}
return state_item_ix2id(state,item_ix);
}
/*:455*//*457:*/
#line 3415 "./marpa.w"

gint marpa_AHFA_state_is_reset(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
/*562:*/
#line 4337 "./marpa.w"
const int failure_indicator= -1;
/*:562*/
#line 3419 "./marpa.w"

/*564:*/
#line 4341 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:564*/
#line 3420 "./marpa.w"

/*567:*/
#line 4361 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:567*/
#line 3421 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->is_reset;
}
/*:457*//*459:*/
#line 3429 "./marpa.w"

static inline
void create_AHFA_states(struct marpa_g*g){
DQUEUE_DEFINE(states);
const gint initial_no_of_states= 2*g->size;
struct AHFA_state state;
struct AHFA_state*p_state;
DQUEUE_INIT(states,struct AHFA_state,initial_no_of_states);
p_state= DQUEUE_ADD(states,struct AHFA_state);
/*461:*/
#line 3448 "./marpa.w"
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

/*:461*/
#line 3438 "./marpa.w"

while(p_state= DQUEUE_NEXT(states,struct AHFA_state)){
/*462:*/
#line 3471 "./marpa.w"
{
gint no_of_items= p_state->item_count;
gint current_item= 0;
struct AHFA_item**items= p_state->items;
Marpa_Symbol_ID work_symbol= items[0]->postdot;

if(work_symbol==-1)goto NEXT_AHFA_STATE;

while(1){
gint first_item_for_working_symbol= current_item;
for(current_item++;current_item<no_of_items;current_item++){
if(items[current_item]->postdot==work_symbol)break;
}
switch(current_item-first_item_for_working_symbol){
case 1:/*463:*/
#line 3503 "./marpa.w"
{;}
/*:463*/
#line 3485 "./marpa.w"

break;
case 2:/*464:*/
#line 3504 "./marpa.w"
{;}
/*:464*/
#line 3487 "./marpa.w"

break;
default:/*465:*/
#line 3505 "./marpa.w"
{;}

/*:465*/
#line 3489 "./marpa.w"

}



/*466:*/
#line 3511 "./marpa.w"
;

/*:466*/
#line 3494 "./marpa.w"


if(current_item>=no_of_items)break;
work_symbol= items[current_item]->postdot;
if(work_symbol==-1)break;
}
NEXT_AHFA_STATE:;
}

/*:462*/
#line 3440 "./marpa.w"

}
g->AHFA= DQUEUE_BASE(states,struct AHFA_state);
g->AHFA_len= DQUEUE_END(states);
}
/*:459*//*468:*/
#line 3543 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:468*//*470:*/
#line 3551 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:470*//*475:*/
#line 3584 "./marpa.w"

static inline guint bv_bits_to_size(gint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:475*//*477:*/
#line 3592 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:477*//*479:*/
#line 3608 "./marpa.w"

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
/*:479*//*481:*/
#line 3625 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:481*//*483:*/
#line 3637 "./marpa.w"
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
/*:483*//*485:*/
#line 3657 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:485*//*487:*/
#line 3666 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:487*//*489:*/
#line 3674 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
*(--bv)&= BV_MASK(bv);
}
/*:489*//*492:*/
#line 3686 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:492*//*494:*/
#line 3694 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:494*//*496:*/
#line 3702 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:496*//*499:*/
#line 3711 "./marpa.w"

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
/*:499*//*501:*/
#line 3728 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:501*//*503:*/
#line 3740 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:503*//*505:*/
#line 3752 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:505*//*507:*/
#line 3764 "./marpa.w"

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
/*:507*//*513:*/
#line 3878 "./marpa.w"

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
/*:513*//*518:*/
#line 3947 "./marpa.w"

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
/*:518*//*520:*/
#line 3967 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:520*//*522:*/
#line 3980 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:522*//*524:*/
#line 3997 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,gint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:524*//*527:*/
#line 4007 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:527*//*530:*/
#line 4016 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:530*//*533:*/
#line 4025 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:533*//*535:*/
#line 4039 "./marpa.w"

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
/*:535*//*538:*/
#line 4094 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa){
void*data= pa->data;
if(data)g_free(data);
}
/*:538*//*541:*/
#line 4113 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size){
dpa->pa.len= 0;dpa->size= size;dpa->pa.data= g_new(void*,size);}
/*:541*//*543:*/
#line 4118 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa){
p_array_destroy(&(dpa->pa));
}
/*:543*//*545:*/
#line 4124 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size){
dpa->pa.data= g_renew(void*,dpa->pa.data,new_size);
dpa->size= new_size;
}
/*:545*//*547:*/
#line 4131 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p){
if(dpa->pa.len>=dpa->size)dp_array_resize(dpa,dpa->size*2);
dpa->pa.data[dpa->pa.len++]= p;
}
/*:547*//*549:*/
#line 4140 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa){
gint len= pa->len= dpa->pa.len;
if(G_UNLIKELY(len>=dpa->size)){
pa->data= dpa->pa.data;
return;
}
pa->data= g_renew(void*,dpa->pa.data,len);
}
/*:549*//*555:*/
#line 4209 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:555*//*573:*/
#line 4430 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->message_callback_arg= cb_arg;}
void*marpa_message_callback_arg(struct marpa_g*g)
{return g->message_callback_arg;}
/*:573*//*575:*/
#line 4442 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:575*/
#line 4559 "./marpa.w"





/*:583*/
