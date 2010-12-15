/*609:*/
#line 4861 "./marpa.w"

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


#line 4886 "./marpa.w"

#include "marpa_obs.h"
/*594:*/
#line 4729 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:594*/
#line 4888 "./marpa.w"

/*495:*/
#line 3831 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:495*//*538:*/
#line 4202 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:538*/
#line 4889 "./marpa.w"

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
/*:29*//*496:*/
#line 3838 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:496*/
#line 4890 "./marpa.w"

/*559:*/
#line 4354 "./marpa.w"

struct p_array{gint len;void**data;};
/*:559*//*562:*/
#line 4373 "./marpa.w"

struct dp_array{struct p_array pa;gint size;};
/*:562*/
#line 4891 "./marpa.w"

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
/*:189*//*297:*/
#line 1960 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
void*rule_callback_arg;
/*:297*//*420:*/
#line 3161 "./marpa.w"

struct AHFA_item*AHFA_items;
struct AHFA_item**AHFA_items_by_rule;
/*:420*//*454:*/
#line 3439 "./marpa.w"
struct AHFA_state*AHFA;
/*:454*//*597:*/
#line 4769 "./marpa.w"

Marpa_Message_Callback*message_callback;
void*message_callback_arg;
/*:597*/
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
/*:67*//*421:*/
#line 3164 "./marpa.w"

guint no_of_items;
/*:421*//*455:*/
#line 3440 "./marpa.w"
gint AHFA_len;
/*:455*/
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

/*:113*//*196:*/
#line 1287 "./marpa.w"

struct marpa_rule{
/*230:*/
#line 1672 "./marpa.w"
guint length;
/*:230*//*250:*/
#line 1739 "./marpa.w"
Marpa_Rule_ID id;
/*:250*//*291:*/
#line 1941 "./marpa.w"
gint virtual_start;
/*:291*//*293:*/
#line 1948 "./marpa.w"
gint virtual_end;
/*:293*//*308:*/
#line 1995 "./marpa.w"
Marpa_Rule_ID original;
/*:308*//*313:*/
#line 2009 "./marpa.w"
guint real_symbol_count;
/*:313*/
#line 1289 "./marpa.w"

/*253:*/
#line 1751 "./marpa.w"
unsigned int is_discard:1;
/*:253*//*267:*/
#line 1835 "./marpa.w"
unsigned int is_loop:1;
/*:267*//*272:*/
#line 1856 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:272*//*279:*/
#line 1886 "./marpa.w"
unsigned int is_used:1;
/*:279*//*283:*/
#line 1916 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:283*//*287:*/
#line 1927 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:287*//*317:*/
#line 2018 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:317*/
#line 1290 "./marpa.w"

/*231:*/
#line 1675 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:231*/
#line 1291 "./marpa.w"

};
/*:196*//*419:*/
#line 3148 "./marpa.w"

struct AHFA_item{
Marpa_Symbol_ID postdot;

Marpa_AHFA_Item_ID sort_key;
struct marpa_rule*rule;
gint position;
};
/*:419*//*453:*/
#line 3429 "./marpa.w"

struct AHFA_state{
struct AHFA_item**items;
union{
Marpa_AHFA_State_ID id;
guint hash;
}id;
guint item_count;
unsigned int is_predict:1;
};
/*:453*//*576:*/
#line 4469 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:576*//*579:*/
#line 4500 "./marpa.w"

struct dqueue{gint current;struct dstack s;};

/*:579*/
#line 4892 "./marpa.w"

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
/*:185*//*194:*/
#line 1281 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:194*//*198:*/
#line 1297 "./marpa.w"

static inline guint rule_sizeof(guint length);

/*:198*//*202:*/
#line 1321 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:202*//*219:*/
#line 1540 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length);

/*:219*//*229:*/
#line 1664 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule);

/*:229*//*235:*/
#line 1689 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:235*//*239:*/
#line 1701 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:239*//*243:*/
#line 1713 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:243*//*247:*/
#line 1726 "./marpa.w"

static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule*rule);
/*:247*//*249:*/
#line 1733 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,guint rh_index);

/*:249*//*260:*/
#line 1800 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule);
/*:260*//*264:*/
#line 1824 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule);
/*:264*//*278:*/
#line 1882 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule);

/*:278*//*306:*/
#line 1988 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:306*//*325:*/
#line 2125 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:325*//*362:*/
#line 2464 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:362*//*401:*/
#line 2831 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:401*//*404:*/
#line 2852 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:404*//*412:*/
#line 2969 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:412*//*424:*/
#line 3179 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:424*//*436:*/
#line 3242 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:436*//*438:*/
#line 3269 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:438*//*445:*/
#line 3336 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:445*//*458:*/
#line 3448 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:458*//*460:*/
#line 3458 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:460*//*462:*/
#line 3474 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix);

/*:462*//*472:*/
#line 3547 "./marpa.w"

static inline guint AHFA_state_hash_compute(struct AHFA_state*p);

/*:472*//*474:*/
#line 3555 "./marpa.w"

static guint AHFA_state_hash(gconstpointer p);

/*:474*//*476:*/
#line 3575 "./marpa.w"

static gboolean AHFA_state_eq(gconstpointer a,gconstpointer b);

/*:476*//*478:*/
#line 3604 "./marpa.w"

static void create_AHFA_states(struct marpa_g*g);

/*:478*//*498:*/
#line 3851 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:498*//*500:*/
#line 3861 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:500*//*502:*/
#line 3881 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);

/*:502*//*504:*/
#line 3892 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:504*//*506:*/
#line 3914 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:506*//*508:*/
#line 3924 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:508*//*510:*/
#line 3932 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:510*//*512:*/
#line 3945 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:512*//*515:*/
#line 3953 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:515*//*517:*/
#line 3961 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:517*//*519:*/
#line 3969 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:519*//*522:*/
#line 3986 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:522*//*524:*/
#line 3999 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:524*//*526:*/
#line 4011 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:526*//*528:*/
#line 4023 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:528*//*530:*/
#line 4097 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:530*//*536:*/
#line 4179 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:536*//*541:*/
#line 4226 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:541*//*543:*/
#line 4234 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:543*//*545:*/
#line 4248 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:545*//*547:*/
#line 4266 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:547*//*550:*/
#line 4275 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:550*//*553:*/
#line 4284 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:553*//*556:*/
#line 4293 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:556*//*558:*/
#line 4346 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:558*//*561:*/
#line 4361 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa);

/*:561*//*564:*/
#line 4378 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size);
/*:564*//*566:*/
#line 4384 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa);
/*:566*//*568:*/
#line 4391 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size);
/*:568*//*570:*/
#line 4398 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p);
/*:570*//*572:*/
#line 4411 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa);


/*:572*//*578:*/
#line 4477 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:578*//*602:*/
#line 4793 "./marpa.w"

static inline void message(struct marpa_g*g,Marpa_Message_ID id);

/*:602*/
#line 4893 "./marpa.w"

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
#line 4894 "./marpa.w"

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
/*:103*//*190:*/
#line 1260 "./marpa.w"

g->symbol_callback_arg= NULL;
g->symbol_callback= NULL;
/*:190*//*298:*/
#line 1963 "./marpa.w"

g->rule_callback_arg= NULL;
g->rule_callback= NULL;
/*:298*//*598:*/
#line 4772 "./marpa.w"

g->message_callback_arg= NULL;
g->message_callback= NULL;
/*:598*/
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
/*:117*//*227:*/
#line 1655 "./marpa.w"

{Marpa_Rule_ID id;for(id= 0;id<(Marpa_Rule_ID)g->rules->len;id++)
{marpa_rule_free(rule_id2p(g,id));}}
/*:227*//*422:*/
#line 3169 "./marpa.w"
if(g->AHFA_items){
g_free(g->AHFA_items_by_rule);
g_free(g->AHFA_items);
};

/*:422*//*456:*/
#line 3441 "./marpa.w"
if(g->AHFA){STOLEN_DQUEUE_DATA_FREE(g->AHFA);}

/*:456*/
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
{/*585:*/
#line 4670 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:585*/
#line 932 "./marpa.w"

/*589:*/
#line 4682 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:589*/
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
{/*585:*/
#line 4670 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:585*/
#line 961 "./marpa.w"

/*589:*/
#line 4682 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:589*/
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
{/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1055 "./marpa.w"

/*589:*/
#line 4682 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:589*/
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
{symbol_id2p(g,id)->is_productive= value?1:0;}
/*:168*//*172:*/
#line 1124 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1129 "./marpa.w"

/*589:*/
#line 4682 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:589*/
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
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1168 "./marpa.w"

/*589:*/
#line 4682 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:589*/
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
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1191 "./marpa.w"

/*589:*/
#line 4682 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:589*/
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
/*:184*//*191:*/
#line 1263 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->symbol_callback_arg= cb_arg;}
void*marpa_symbol_callback_arg(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:191*//*193:*/
#line 1277 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:193*//*197:*/
#line 1293 "./marpa.w"

static inline guint rule_sizeof(guint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:197*//*201:*/
#line 1307 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
struct marpa_rule*rule;
/*232:*/
#line 1676 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{guint rh_index;for(rh_index= 0;rh_index<length;rh_index++){
if(!symbol_is_valid(g,rhs[rh_index])){return NULL;}
}}
/*:232*/
#line 1313 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*233:*/
#line 1681 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{guint i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:233*/
#line 1315 "./marpa.w"

/*251:*/
#line 1740 "./marpa.w"
rule->id= g->rules->len;

/*:251*//*254:*/
#line 1752 "./marpa.w"

rule->is_discard= FALSE;
/*:254*//*268:*/
#line 1836 "./marpa.w"

rule->is_loop= FALSE;
/*:268*//*273:*/
#line 1857 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:273*//*280:*/
#line 1887 "./marpa.w"

rule->is_used= TRUE;
/*:280*//*284:*/
#line 1917 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:284*//*288:*/
#line 1928 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:288*//*292:*/
#line 1942 "./marpa.w"
rule->virtual_start= -1;

/*:292*//*294:*/
#line 1949 "./marpa.w"
rule->virtual_end= -1;

/*:294*//*309:*/
#line 1996 "./marpa.w"
rule->original= -1;
/*:309*//*314:*/
#line 2010 "./marpa.w"
rule->real_symbol_count= 0;
/*:314*//*318:*/
#line 2019 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:318*/
#line 1316 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*221:*/
#line 1557 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const guint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*225:*/
#line 1624 "./marpa.w"

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

/*:225*/
#line 1565 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
symbol_id2p(g,rh_symbol_list[rh_list_ix]),
rule->id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:221*/
#line 1318 "./marpa.w"

return rule;
}
/*:201*//*203:*/
#line 1326 "./marpa.w"

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

/*:203*//*204:*/
#line 1343 "./marpa.w"

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

/*207:*/
#line 1378 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*206:*/
#line 1376 "./marpa.w"
g->error= "internal_error";return-1;
/*:206*/
#line 1380 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:207*/
#line 1356 "./marpa.w"

/*208:*/
#line 1384 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:208*/
#line 1357 "./marpa.w"

/*209:*/
#line 1388 "./marpa.w"

symbol_id2p(g,rhs_id)->is_counted= 1;
if(separator_id>=0){symbol_id2p(g,separator_id)->is_counted= 1;}
/*:209*/
#line 1358 "./marpa.w"

if(min==0){/*210:*/
#line 1391 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*206:*/
#line 1376 "./marpa.w"
g->error= "internal_error";return-1;
/*:206*/
#line 1393 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:210*/
#line 1359 "./marpa.w"
}
min= 1;
/*211:*/
#line 1398 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:211*/
#line 1361 "./marpa.w"

/*212:*/
#line 1412 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:212*/
#line 1362 "./marpa.w"

/*214:*/
#line 1415 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*206:*/
#line 1376 "./marpa.w"
g->error= "internal_error";return-1;
/*:206*/
#line 1419 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:214*/
#line 1363 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*215:*/
#line 1428 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*206:*/
#line 1376 "./marpa.w"
g->error= "internal_error";return-1;
/*:206*/
#line 1433 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:215*/
#line 1365 "./marpa.w"

}
/*216:*/
#line 1445 "./marpa.w"

{struct marpa_rule*rule;
guint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*206:*/
#line 1376 "./marpa.w"
g->error= "internal_error";return-1;
/*:206*/
#line 1455 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:216*/
#line 1367 "./marpa.w"

/*217:*/
#line 1460 "./marpa.w"

{struct marpa_rule*rule;
guint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*206:*/
#line 1376 "./marpa.w"
g->error= "internal_error";return-1;
/*:206*/
#line 1467 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:217*/
#line 1368 "./marpa.w"

/*213:*/
#line 1414 "./marpa.w"
g_free(temp_rhs);
/*:213*/
#line 1369 "./marpa.w"

return original_rule_id;
}
/*:204*//*218:*/
#line 1516 "./marpa.w"

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
/*:218*//*228:*/
#line 1659 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule)
{

g_free(rule);}
/*:228*//*234:*/
#line 1686 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
/*:234*//*236:*/
#line 1691 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1693 "./marpa.w"

/*590:*/
#line 4689 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:590*/
#line 1694 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:236*//*238:*/
#line 1698 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:238*//*240:*/
#line 1703 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*585:*/
#line 4670 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:585*/
#line 1705 "./marpa.w"

/*590:*/
#line 4689 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:590*/
#line 1706 "./marpa.w"

return rule_rhs_get(rule_id2p(g,rule_id));}
/*:240*//*242:*/
#line 1710 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:242*//*244:*/
#line 1715 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1717 "./marpa.w"

/*590:*/
#line 4689 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:590*/
#line 1718 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:244*//*246:*/
#line 1723 "./marpa.w"

static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule*rule){return rule->symbols[0];}
/*:246*//*248:*/
#line 1728 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,guint rh_index){
return rule->symbols[rh_index+1];
}
/*:248*//*255:*/
#line 1754 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:255*//*259:*/
#line 1787 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule)
{
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
return symbol_id2p(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1794 "./marpa.w"

struct marpa_rule*rule;
/*590:*/
#line 4689 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:590*/
#line 1796 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:259*//*263:*/
#line 1807 "./marpa.w"

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
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1818 "./marpa.w"

struct marpa_rule*rule;
/*590:*/
#line 4689 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:590*/
#line 1820 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:263*//*269:*/
#line 1840 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1843 "./marpa.w"

/*590:*/
#line 4689 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:590*/
#line 1844 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:269*//*274:*/
#line 1861 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1864 "./marpa.w"

/*590:*/
#line 4689 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:590*/
#line 1865 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:274*//*277:*/
#line 1873 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:277*//*281:*/
#line 1891 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 1894 "./marpa.w"

/*590:*/
#line 4689 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_clear(g);
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:590*/
#line 1895 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:281*//*285:*/
#line 1920 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:285*//*289:*/
#line 1931 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:289*//*299:*/
#line 1966 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:299*//*301:*/
#line 1971 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:301*//*303:*/
#line 1976 "./marpa.w"

void*marpa_rule_callback_arg(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:303*//*305:*/
#line 1984 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:305*//*310:*/
#line 1997 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}
/*:310*//*315:*/
#line 2011 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}
/*:315*//*319:*/
#line 2030 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:319*//*321:*/
#line 2049 "./marpa.w"

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
/*:321*//*324:*/
#line 2095 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*326:*/
#line 2127 "./marpa.w"

guint pre_rewrite_rule_count= g->rules->len;
guint pre_rewrite_symbol_count= g->symbols->len;

/*:326*//*331:*/
#line 2160 "./marpa.w"

Marpa_Symbol_ID original_start_symbol_id= g->start_symbol_id;
struct marpa_symbol*original_start_symbol;

/*:331*//*335:*/
#line 2197 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:335*//*341:*/
#line 2256 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:341*//*343:*/
#line 2283 "./marpa.w"

Bit_Vector nullable_v;
/*:343*//*347:*/
#line 2309 "./marpa.w"

Bit_Vector productive_v;
/*:347*//*350:*/
#line 2350 "./marpa.w"
Bit_Matrix reach_matrix;
/*:350*//*353:*/
#line 2368 "./marpa.w"

Bit_Vector accessible_v;

/*:353*/
#line 2098 "./marpa.w"

/*327:*/
#line 2131 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:327*/
#line 2099 "./marpa.w"

/*328:*/
#line 2138 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:328*/
#line 2100 "./marpa.w"

/*330:*/
#line 2144 "./marpa.w"

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
/*:330*/
#line 2101 "./marpa.w"

/*332:*/
#line 2164 "./marpa.w"

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
/*:332*/
#line 2102 "./marpa.w"

/*333:*/
#line 2183 "./marpa.w"

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
/*:333*/
#line 2103 "./marpa.w"

if(have_marked_terminals){
/*337:*/
#line 2212 "./marpa.w"

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

/*:337*/
#line 2105 "./marpa.w"

}else{
/*336:*/
#line 2201 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:336*/
#line 2107 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*338:*/
#line 2236 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<(Marpa_Symbol_ID)g->symbols->len;symbol_id++)
{symbol_id2p(g,symbol_id)->is_terminal= 1;}}
/*:338*/
#line 2109 "./marpa.w"

}else{
/*339:*/
#line 2241 "./marpa.w"

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
/*:339*/
#line 2111 "./marpa.w"

}
}
/*342:*/
#line 2261 "./marpa.w"

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
/*:342*/
#line 2114 "./marpa.w"

/*345:*/
#line 2288 "./marpa.w"

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
/*:345*/
#line 2115 "./marpa.w"

/*346:*/
#line 2302 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->start_symbol_id))
{
context_int_add(g,"symbol_id",g->start_symbol_id);
g->error= "unproductive start symbol";
return NULL;
}
/*:346*/
#line 2116 "./marpa.w"

/*349:*/
#line 2332 "./marpa.w"

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
/*:349*/
#line 2117 "./marpa.w"

/*352:*/
#line 2354 "./marpa.w"

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
/*:352*/
#line 2118 "./marpa.w"

/*354:*/
#line 2373 "./marpa.w"

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

/*:354*/
#line 2119 "./marpa.w"

/*334:*/
#line 2195 "./marpa.w"

bv_free(terminal_v);
/*:334*//*340:*/
#line 2253 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:340*//*344:*/
#line 2285 "./marpa.w"

bv_free(nullable_v);

/*:344*//*348:*/
#line 2311 "./marpa.w"

bv_free(productive_v);

/*:348*/
#line 2120 "./marpa.w"

/*351:*/
#line 2351 "./marpa.w"

matrix_free(reach_matrix);

/*:351*/
#line 2121 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:324*//*361:*/
#line 2443 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*363:*/
#line 2466 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:363*//*367:*/
#line 2517 "./marpa.w"

guint factor_count;
guint*factor_positions;
/*:367*//*372:*/
#line 2566 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:372*/
#line 2446 "./marpa.w"

/*368:*/
#line 2520 "./marpa.w"

factor_positions= g_new(guint,g->max_rule_length);
/*:368*//*373:*/
#line 2569 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:373*/
#line 2447 "./marpa.w"

/*365:*/
#line 2478 "./marpa.w"

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

/*:365*/
#line 2448 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
guint rule_length= rule->length;
guint nullable_suffix_ix= 0;
/*364:*/
#line 2470 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:364*/
#line 2454 "./marpa.w"

/*366:*/
#line 2501 "./marpa.w"

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
/*:366*/
#line 2455 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*370:*/
#line 2526 "./marpa.w"

rule->is_used= 0;
{guint unprocessed_factor_count;

guint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= lhs_symbol_id(rule);
guint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*376:*/
#line 2579 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symbol_id;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*371:*/
#line 2545 "./marpa.w"
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

/*:371*/
#line 2587 "./marpa.w"

/*377:*/
#line 2606 "./marpa.w"

{
guint remaining_rhs_length,piece_rhs_length;
/*378:*/
#line 2618 "./marpa.w"

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
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2630 "./marpa.w"

}

/*:378*/
#line 2609 "./marpa.w"
;
/*379:*/
#line 2633 "./marpa.w"

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
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2645 "./marpa.w"

}

/*:379*/
#line 2610 "./marpa.w"
;
/*380:*/
#line 2650 "./marpa.w"
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
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2660 "./marpa.w"

}

/*:380*/
#line 2611 "./marpa.w"
;
/*381:*/
#line 2669 "./marpa.w"

if(piece_start<nullable_suffix_ix){
struct marpa_rule*chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2674 "./marpa.w"

}

/*:381*/
#line 2612 "./marpa.w"
;
}

/*:377*/
#line 2588 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*371:*/
#line 2545 "./marpa.w"
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

/*:371*/
#line 2593 "./marpa.w"

/*383:*/
#line 2679 "./marpa.w"
{
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:383*//*384:*/
#line 2688 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2694 "./marpa.w"


/*:384*//*385:*/
#line 2697 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2702 "./marpa.w"


/*:385*//*386:*/
#line 2705 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2711 "./marpa.w"


/*:386*//*387:*/
#line 2714 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2717 "./marpa.w"


/*:387*//*388:*/
#line 2720 "./marpa.w"
}

/*:388*/
#line 2594 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symbol_id;
piece_start= piece_end+1;

/*:376*/
#line 2537 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*389:*/
#line 2724 "./marpa.w"
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

/*:389*//*390:*/
#line 2738 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2743 "./marpa.w"


/*:390*//*391:*/
#line 2746 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2751 "./marpa.w"


/*:391*//*392:*/
#line 2754 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2760 "./marpa.w"


/*:392*//*393:*/
#line 2764 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2768 "./marpa.w"

}

/*:393*//*394:*/
#line 2772 "./marpa.w"
}

/*:394*/
#line 2540 "./marpa.w"

}else{
/*395:*/
#line 2775 "./marpa.w"
{
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
guint real_symbol_count;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:395*//*396:*/
#line 2786 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2791 "./marpa.w"


/*:396*//*397:*/
#line 2795 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2811 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:399*/
#line 2801 "./marpa.w"

}

/*:397*//*398:*/
#line 2805 "./marpa.w"
}

/*:398*/
#line 2542 "./marpa.w"

}}

/*:370*/
#line 2458 "./marpa.w"

NEXT_RULE:;
}
/*369:*/
#line 2522 "./marpa.w"

g_free(factor_positions);

/*:369*//*374:*/
#line 2572 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:374*/
#line 2461 "./marpa.w"

return g;
}
/*:361*//*400:*/
#line 2825 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
return alias->id;
}
/*:400*//*403:*/
#line 2839 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct marpa_symbol*proper_old_start= NULL;
struct marpa_symbol*nulling_old_start= NULL;
struct marpa_symbol*proper_new_start= NULL;
struct marpa_symbol*old_start= symbol_id2p(g,g->start_symbol_id);
/*405:*/
#line 2855 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:405*/
#line 2847 "./marpa.w"

if(proper_old_start){/*406:*/
#line 2865 "./marpa.w"
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

/*:406*/
#line 2848 "./marpa.w"
}
if(nulling_old_start){/*407:*/
#line 2888 "./marpa.w"
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

/*:407*/
#line 2849 "./marpa.w"
}
return g;
}
/*:403*//*411:*/
#line 2955 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{guint no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*413:*/
#line 2978 "./marpa.w"
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

/*:413*/
#line 2962 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*414:*/
#line 3017 "./marpa.w"
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

/*:414*/
#line 2964 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*415:*/
#line 3038 "./marpa.w"

context_clear(g);
context_int_add(g,"loop_rule_count",loop_rule_count);
message(g,"loop rule tally");

/*:415*/
#line 2966 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:411*//*423:*/
#line 3174 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return g->AHFA_items+item_id;
}
/*:423*//*425:*/
#line 3184 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 3186 "./marpa.w"

/*588:*/
#line 4676 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:588*/
#line 3187 "./marpa.w"

return g->no_of_items;
}
/*:425*//*427:*/
#line 3193 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 3196 "./marpa.w"

/*588:*/
#line 4676 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:588*/
#line 3197 "./marpa.w"

/*591:*/
#line 4696 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:591*/
#line 3198 "./marpa.w"

return item_id2p(g,item_id)->rule->id;
}
/*:427*//*429:*/
#line 3204 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*587:*/
#line 4674 "./marpa.w"
const int failure_indicator= -2;

/*:587*/
#line 3207 "./marpa.w"

/*588:*/
#line 4676 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:588*/
#line 3208 "./marpa.w"

/*591:*/
#line 4696 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:591*/
#line 3209 "./marpa.w"

return item_id2p(g,item_id)->position;
}
/*:429*//*431:*/
#line 3215 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*587:*/
#line 4674 "./marpa.w"
const int failure_indicator= -2;

/*:587*/
#line 3218 "./marpa.w"

/*588:*/
#line 4676 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:588*/
#line 3219 "./marpa.w"

/*591:*/
#line 4696 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:591*/
#line 3220 "./marpa.w"

return item_id2p(g,item_id)->postdot;
}
/*:431*//*433:*/
#line 3225 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 3228 "./marpa.w"

/*588:*/
#line 4676 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:588*/
#line 3229 "./marpa.w"

/*591:*/
#line 4696 "./marpa.w"

if(!item_is_valid(g,item_id)){
context_clear(g);
context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:591*/
#line 3230 "./marpa.w"

return item_id2p(g,item_id)->sort_key;
}
/*:433*//*435:*/
#line 3237 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<(Marpa_AHFA_Item_ID)g->no_of_items&&item_id>=0;
}
/*:435*//*437:*/
#line 3252 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
Marpa_Rule_ID rule_id;
guint no_of_items;
guint no_of_rules= rule_count(g);
struct AHFA_item*base_item= g_new(struct AHFA_item,g->size);
struct AHFA_item*current_item= base_item;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
/*439:*/
#line 3272 "./marpa.w"

guint rhs_ix;
struct marpa_rule*rule= rule_id2p(g,rule_id);
if(!rule->is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->length;rhs_ix++){
/*440:*/
#line 3284 "./marpa.w"

Marpa_Symbol_ID rh_symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,rh_symbol_id);
if(symbol->is_nullable)goto NEXT_RH_SYMBOL;
current_item->sort_key= current_item-base_item;
current_item->postdot= rh_symbol_id;
current_item->rule= rule;
current_item->position= rhs_ix;

/*:440*/
#line 3277 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*441:*/
#line 3293 "./marpa.w"

current_item->sort_key= current_item-base_item;
current_item->postdot= current_item->position= -1;
current_item->rule= rule;

/*:441*/
#line 3281 "./marpa.w"

current_item++;

/*:439*/
#line 3261 "./marpa.w"

NEXT_RULE:;
}
no_of_items= g->no_of_items= current_item-base_item;
g->AHFA_items= g_renew(struct AHFA_item,base_item,no_of_items);
/*442:*/
#line 3303 "./marpa.w"
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

/*:442*/
#line 3266 "./marpa.w"

/*446:*/
#line 3339 "./marpa.w"
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

/*:446*/
#line 3267 "./marpa.w"

}
/*:437*//*444:*/
#line 3324 "./marpa.w"

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
/*:444*//*457:*/
#line 3444 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{return g->AHFA+AHFA_state_id;}
/*:457*//*459:*/
#line 3453 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id){
return AHFA_state_id<g->AHFA_len&&AHFA_state_id>=0;
}
/*:459*//*461:*/
#line 3469 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix){
return state->items[item_ix]-g->AHFA_items;
}
/*:461*//*463:*/
#line 3479 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return g->AHFA_len;
}
/*:463*//*465:*/
#line 3486 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 3489 "./marpa.w"

struct AHFA_state*state;
/*588:*/
#line 4676 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:588*/
#line 3491 "./marpa.w"

/*592:*/
#line 4703 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:592*/
#line 3492 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->item_count;
}
/*:465*//*467:*/
#line 3499 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix){
struct AHFA_state*state;
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 3504 "./marpa.w"

/*588:*/
#line 4676 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:588*/
#line 3505 "./marpa.w"

/*592:*/
#line 4703 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:592*/
#line 3506 "./marpa.w"

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
/*:467*//*469:*/
#line 3522 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
/*586:*/
#line 4672 "./marpa.w"
const int failure_indicator= -1;
/*:586*/
#line 3526 "./marpa.w"

/*588:*/
#line 4676 "./marpa.w"

if(!g->is_precomputed){
context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:588*/
#line 3527 "./marpa.w"

/*592:*/
#line 4703 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
context_clear(g);
context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:592*/
#line 3528 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->is_predict;
}
/*:469*//*471:*/
#line 3537 "./marpa.w"

#define TEMPLATE_KEY_TYPE  struct AHFA_item**  
#define TEMPLATE_KEY_LENGTH(state_p) ((state_p)->item_count)
#define TEMPLATE_KEY_INIT(state_p) ((state_p)->items)
#define TEMPLATE_KEY_VALUE(item_p, ix)  ((item_p)[ix]->sort_key) 
#define TEMPLATE_KEY_INC(item_p, inc)  ((item_p)+= (inc)) 
static inline guint AHFA_state_hash_compute(struct AHFA_state*p){
/*580:*/
#line 4533 "./marpa.w"

guint32 a,b,c;
gsize length= TEMPLATE_KEY_LENGTH(p);
TEMPLATE_KEY_TYPE k= TEMPLATE_KEY_INIT(p);


a= b= c= 0xdeadbeef+(((guint32)length)<<2);

while(length> 3)
{
a+= TEMPLATE_KEY_VALUE(k,0);
b+= TEMPLATE_KEY_VALUE(k,1);
c+= TEMPLATE_KEY_VALUE(k,2);
bjenkins_mix(a,b,c);
length-= 3;
TEMPLATE_KEY_INC(k,3);
}

switch(length)
{


case 3:c+= TEMPLATE_KEY_VALUE(k,2);
case 2:b+= TEMPLATE_KEY_VALUE(k,1);
case 1:a+= TEMPLATE_KEY_VALUE(k,0);
bjenkins_final(a,b,c);
case 0:
break;
}
return c;

/*:580*/
#line 3544 "./marpa.w"

}
/*581:*/
#line 4564 "./marpa.w"

#undef TEMPLATE_KEY_TYPE
#undef TEMPLATE_KEY_INIT
#undef TEMPLATE_KEY_VALUE
#undef TEMPLATE_KEY_LENGTH
#undef TEMPLATE_KEY_INC

/*:581*/
#line 3546 "./marpa.w"

/*:471*//*473:*/
#line 3551 "./marpa.w"

static guint AHFA_state_hash(gconstpointer p){
return((struct AHFA_state*)p)->id.hash;
}
/*:473*//*475:*/
#line 3558 "./marpa.w"

static gboolean AHFA_state_eq(gconstpointer ap,gconstpointer bp)
{
guint i,length;
struct AHFA_item**items_a;
struct AHFA_item**items_b;
const struct AHFA_state*state_a= (struct AHFA_state*)ap;
const struct AHFA_state*state_b= (struct AHFA_state*)bp;
length= state_a->item_count;
if(length!=state_b->item_count)return FALSE;
items_a= state_a->items;
items_b= state_b->items;
for(i= 0;i<length;i++){
if(items_a[i]->sort_key!=items_b[i]->sort_key)return FALSE;
}
return TRUE;
}
/*:475*//*477:*/
#line 3579 "./marpa.w"

static
void create_AHFA_states(struct marpa_g*g){
const guint initial_no_of_states= 2*g->size;
guint no_of_symbols= symbol_count(g);
guint no_of_rules= rule_count(g);
GHashTable*duplicates= g_hash_table_new(AHFA_state_hash,AHFA_state_eq);
struct AHFA_state**singleton_duplicates= g_new0(struct AHFA_state*,g->no_of_items);
Bit_Matrix prediction_matrix= matrix_create(no_of_symbols,no_of_rules);
struct AHFA_state*p_state;
DQUEUE_DEFINE(states);
DQUEUE_INIT(states,struct AHFA_state,initial_no_of_states);
p_state= DQUEUE_PUSH(states,struct AHFA_state);
/*479:*/
#line 3613 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= matrix_create(no_of_symbols,no_of_symbols);
/*480:*/
#line 3621 "./marpa.w"

{Marpa_Rule_ID rule_id;
struct AHFA_item**items_by_rule= g->AHFA_items_by_rule;
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

/*:480*/
#line 3615 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*481:*/
#line 3645 "./marpa.w"
{
struct AHFA_item**items_by_rule= g->AHFA_items_by_rule;
Marpa_Symbol_ID from_symbol_id;
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
if(!items_by_rule[rule_with_this_lhs_symbol])continue;

matrix_bit_set(prediction_matrix,(guint)from_symbol_id,
(guint)rule_with_this_lhs_symbol);

}}}}}

/*:481*/
#line 3617 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:479*/
#line 3592 "./marpa.w"

/*482:*/
#line 3672 "./marpa.w"
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
p_state->is_predict= 0;
if(!start_symbol->is_nulling){
/*483:*/
#line 3699 "./marpa.w"

Bit_Vector prediction_rule_vector
= matrix_row(prediction_matrix,(guint)g->start_symbol_id);
guint start,min,max;
guint item_list_ix= 0;
no_of_items_in_state= 0;
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2
){
no_of_items_in_state+= max-min+1;}
item_list= obstack_alloc(&g->obs,no_of_items_in_state*sizeof(struct AHFA_item*));
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2
){
Marpa_Symbol_ID predicted_rule_id;
for(predicted_rule_id= min;
predicted_rule_id<=(Marpa_Rule_ID)max;
predicted_rule_id++){

item_list[item_list_ix++]= g->AHFA_items_by_rule[predicted_rule_id];
}
}
p_state= DQUEUE_PUSH(states,struct AHFA_state);
p_state->items= item_list;
p_state->item_count= no_of_items_in_state;
p_state->is_predict= 1;
p_state->id.hash= AHFA_state_hash_compute(p_state);
g_hash_table_insert(duplicates,p_state,p_state);


/*:483*/
#line 3695 "./marpa.w"

}
}

/*:482*/
#line 3593 "./marpa.w"

while((p_state= DQUEUE_NEXT(states,struct AHFA_state))){
/*484:*/
#line 3729 "./marpa.w"
{
guint no_of_items= p_state->item_count;
Marpa_AHFA_Item_ID current_item= 0;
struct AHFA_item**item_list;
Marpa_Symbol_ID work_symbol;
item_list= p_state->items;
work_symbol= item_list[0]->postdot;

if(work_symbol==-1)goto NEXT_AHFA_STATE;

while(1){
Marpa_AHFA_Item_ID first_item_for_working_symbol= current_item;
for(current_item++;
current_item<(Marpa_AHFA_Item_ID)no_of_items;
current_item++){
if(item_list[current_item]->postdot!=work_symbol)break;
}
switch(current_item-first_item_for_working_symbol){
case 1:/*485:*/
#line 3765 "./marpa.w"
{;}
/*:485*/
#line 3747 "./marpa.w"

break;
case 2:/*486:*/
#line 3766 "./marpa.w"
{;}
/*:486*/
#line 3749 "./marpa.w"

break;
default:/*487:*/
#line 3767 "./marpa.w"
{;}

/*:487*/
#line 3751 "./marpa.w"

}



/*488:*/
#line 3773 "./marpa.w"
;

/*:488*/
#line 3756 "./marpa.w"


if(current_item>=(Marpa_AHFA_Item_ID)no_of_items)break;
work_symbol= item_list[current_item]->postdot;
if(work_symbol==-1)break;
}
NEXT_AHFA_STATE:;
}

/*:484*/
#line 3595 "./marpa.w"

}
g->AHFA= DQUEUE_BASE(states,struct AHFA_state);

g->AHFA_len= DQUEUE_END(states);
matrix_free(prediction_matrix);
g_free(singleton_duplicates);
g_hash_table_destroy(duplicates);
}
/*:477*//*490:*/
#line 3805 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:490*//*492:*/
#line 3813 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:492*//*497:*/
#line 3846 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:497*//*499:*/
#line 3854 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:499*//*501:*/
#line 3870 "./marpa.w"

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
/*:501*//*503:*/
#line 3887 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:503*//*505:*/
#line 3899 "./marpa.w"
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
/*:505*//*507:*/
#line 3919 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:507*//*509:*/
#line 3928 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:509*//*511:*/
#line 3936 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:511*//*514:*/
#line 3949 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:514*//*516:*/
#line 3957 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:516*//*518:*/
#line 3965 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:518*//*521:*/
#line 3974 "./marpa.w"

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
/*:521*//*523:*/
#line 3991 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:523*//*525:*/
#line 4003 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:525*//*527:*/
#line 4015 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:527*//*529:*/
#line 4027 "./marpa.w"

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
/*:529*//*535:*/
#line 4141 "./marpa.w"

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
/*:535*//*540:*/
#line 4210 "./marpa.w"

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
/*:540*//*542:*/
#line 4230 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:542*//*544:*/
#line 4243 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:544*//*546:*/
#line 4260 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:546*//*549:*/
#line 4270 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:549*//*552:*/
#line 4279 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:552*//*555:*/
#line 4288 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:555*//*557:*/
#line 4302 "./marpa.w"

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
/*:557*//*560:*/
#line 4356 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa){
void*data= pa->data;
if(data)g_free(data);
}
/*:560*//*563:*/
#line 4375 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size){
dpa->pa.len= 0;dpa->size= size;dpa->pa.data= g_new(void*,size);}
/*:563*//*565:*/
#line 4380 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa){
p_array_destroy(&(dpa->pa));
}
/*:565*//*567:*/
#line 4386 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size){
dpa->pa.data= g_renew(void*,dpa->pa.data,new_size);
dpa->size= new_size;
}
/*:567*//*569:*/
#line 4393 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,void*p){
if(dpa->pa.len>=dpa->size)dp_array_resize(dpa,dpa->size*2);
dpa->pa.data[dpa->pa.len++]= p;
}
/*:569*//*571:*/
#line 4402 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa){
gint len= pa->len= dpa->pa.len;
if(G_UNLIKELY(len>=dpa->size)){
pa->data= dpa->pa.data;
return;
}
pa->data= g_renew(void*,dpa->pa.data,len);
}
/*:571*//*577:*/
#line 4471 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:577*//*599:*/
#line 4775 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->message_callback_arg= cb_arg;}
void*marpa_message_callback_arg(struct marpa_g*g)
{return g->message_callback_arg;}
/*:599*//*601:*/
#line 4789 "./marpa.w"

static inline void message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:601*/
#line 4895 "./marpa.w"





/*:609*/
