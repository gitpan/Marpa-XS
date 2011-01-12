/*707:*/
#line 5597 "./marpa.w"

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
#define DEFAULT_TOO_MANY_EARLEY_ITEMS (100) 
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


#line 5622 "./marpa.w"

#include "marpa_obs.h"
/*692:*/
#line 5465 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:692*/
#line 5624 "./marpa.w"

/*576:*/
#line 4477 "./marpa.w"
struct earley_set;
/*:576*/
#line 5625 "./marpa.w"

/*585:*/
#line 4536 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:585*//*630:*/
#line 4919 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:630*/
#line 5626 "./marpa.w"

/*18:*/
#line 372 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:18*//*32:*/
#line 460 "./marpa.w"
static gint next_grammar_id= 1;
/*:32*//*532:*/
#line 4297 "./marpa.w"
static gint next_recce_id= 1;
/*:532*//*586:*/
#line 4543 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:586*/
#line 5627 "./marpa.w"

/*651:*/
#line 5071 "./marpa.w"

struct p_array{gint len;gpointer*data;};
/*:651*//*654:*/
#line 5090 "./marpa.w"

struct dp_array{struct p_array pa;gint size;};
/*:654*/
#line 5628 "./marpa.w"

/*24:*/
#line 425 "./marpa.w"
struct marpa_g{
/*36:*/
#line 475 "./marpa.w"
GArray*symbols;
/*:36*//*48:*/
#line 534 "./marpa.w"
GArray*rules;
/*:48*//*86:*/
#line 717 "./marpa.w"
GHashTable*context;
/*:86*//*101:*/
#line 802 "./marpa.w"
struct obstack obs;
/*:101*//*105:*/
#line 818 "./marpa.w"
Marpa_Error_ID error;
/*:105*//*186:*/
#line 1214 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
gpointer symbol_callback_arg;
/*:186*//*297:*/
#line 1936 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
gpointer rule_callback_arg;
/*:297*//*420:*/
#line 3137 "./marpa.w"

struct AHFA_item*AHFA_items;
struct AHFA_item**AHFA_items_by_rule;
/*:420*//*458:*/
#line 3439 "./marpa.w"
struct AHFA_state*AHFA;
/*:458*//*695:*/
#line 5505 "./marpa.w"

Marpa_Message_Callback*message_callback;
gpointer message_callback_arg;
/*:695*/
#line 426 "./marpa.w"

/*30:*/
#line 458 "./marpa.w"
int id;
/*:30*//*60:*/
#line 593 "./marpa.w"
Marpa_Symbol_ID start_symbol_id;
/*:60*//*67:*/
#line 640 "./marpa.w"
int size;
/*:67*//*70:*/
#line 653 "./marpa.w"
guint max_rule_length;
/*:70*//*421:*/
#line 3140 "./marpa.w"

guint no_of_items;
/*:421*//*459:*/
#line 3440 "./marpa.w"
gint AHFA_len;
/*:459*/
#line 427 "./marpa.w"

/*72:*/
#line 658 "./marpa.w"
unsigned int is_precomputed:1;
/*:72*//*76:*/
#line 669 "./marpa.w"
unsigned int has_loop:1;
/*:76*//*80:*/
#line 684 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:80*/
#line 428 "./marpa.w"

};

/*:24*//*111:*/
#line 836 "./marpa.w"

struct marpa_symbol{
/*119:*/
#line 879 "./marpa.w"
GArray*lhs;
/*:119*//*126:*/
#line 909 "./marpa.w"
GArray*rhs;
/*:126*//*173:*/
#line 1106 "./marpa.w"

struct marpa_symbol*alias;
/*:173*/
#line 838 "./marpa.w"

/*117:*/
#line 870 "./marpa.w"
Marpa_Symbol_ID id;
/*:117*/
#line 839 "./marpa.w"

/*133:*/
#line 930 "./marpa.w"
unsigned int is_accessible:1;
/*:133*//*139:*/
#line 956 "./marpa.w"
unsigned int is_counted:1;
/*:139*//*143:*/
#line 974 "./marpa.w"
unsigned int is_nullable:1;
/*:143*//*149:*/
#line 999 "./marpa.w"
unsigned int is_nulling:1;
/*:149*//*155:*/
#line 1026 "./marpa.w"
unsigned int is_terminal:1;
/*:155*//*161:*/
#line 1052 "./marpa.w"
unsigned int is_productive:1;
/*:161*//*167:*/
#line 1077 "./marpa.w"
unsigned int is_start:1;
/*:167*//*172:*/
#line 1103 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:172*/
#line 840 "./marpa.w"

};

/*:111*//*193:*/
#line 1244 "./marpa.w"

struct marpa_rule{
/*226:*/
#line 1625 "./marpa.w"
guint length;
/*:226*//*246:*/
#line 1696 "./marpa.w"
Marpa_Rule_ID id;
/*:246*//*287:*/
#line 1898 "./marpa.w"
gint virtual_start;
/*:287*//*291:*/
#line 1914 "./marpa.w"
gint virtual_end;
/*:291*//*308:*/
#line 1971 "./marpa.w"
Marpa_Rule_ID original;
/*:308*//*313:*/
#line 1985 "./marpa.w"
guint real_symbol_count;
/*:313*/
#line 1246 "./marpa.w"

/*249:*/
#line 1708 "./marpa.w"
unsigned int is_discard:1;
/*:249*//*263:*/
#line 1792 "./marpa.w"
unsigned int is_loop:1;
/*:263*//*268:*/
#line 1813 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:268*//*275:*/
#line 1843 "./marpa.w"
unsigned int is_used:1;
/*:275*//*279:*/
#line 1873 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:279*//*283:*/
#line 1884 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:283*//*317:*/
#line 1994 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:317*/
#line 1247 "./marpa.w"

/*227:*/
#line 1628 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:227*/
#line 1248 "./marpa.w"

};
/*:193*//*419:*/
#line 3124 "./marpa.w"

struct AHFA_item{
Marpa_Symbol_ID postdot;

Marpa_AHFA_Item_ID sort_key;
struct marpa_rule*rule;
gint position;
};
/*:419*//*457:*/
#line 3429 "./marpa.w"

struct AHFA_state{
struct AHFA_item**items;
Marpa_AHFA_State_ID id;
guint item_count;
struct AHFA_state*empty_transition;
GSequence*transitions;
unsigned int is_predict:1;
unsigned int is_leo_completion:1;
};
/*:457*//*518:*/
#line 4216 "./marpa.w"

struct AHFA_transition{
Marpa_Symbol_ID symbol;
Marpa_AHFA_State_ID to;
};

/*:518*//*524:*/
#line 4250 "./marpa.w"
struct marpa_r{
/*537:*/
#line 4307 "./marpa.w"
const struct marpa_g*grammar;

/*:537*//*540:*/
#line 4323 "./marpa.w"

struct earley_set*initial;
struct earley_set*current;
struct earley_set*furthest;
/*:540*//*556:*/
#line 4392 "./marpa.w"
GHashTable*context;
/*:556*//*567:*/
#line 4447 "./marpa.w"
struct obstack obs;
/*:567*//*571:*/
#line 4461 "./marpa.w"
Marpa_Error_ID error;
/*:571*/
#line 4251 "./marpa.w"

/*530:*/
#line 4295 "./marpa.w"
int id;
/*:530*//*538:*/
#line 4310 "./marpa.w"

enum{
no_such_phase= 0,
initial_phase,
active_phase,
exhausted_phase,
finished_phase,
error_phase
}phase;
/*:538*//*544:*/
#line 4339 "./marpa.w"
guint too_many_earley_items;
/*:544*/
#line 4252 "./marpa.w"

/*550:*/
#line 4361 "./marpa.w"
unsigned int is_trace_earley_sets:1;
/*:550*/
#line 4253 "./marpa.w"

};

/*:524*//*577:*/
#line 4478 "./marpa.w"

struct earley_set{
gint id;
GSequence*earley_items;
};

/*:577*//*668:*/
#line 5186 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:668*//*671:*/
#line 5217 "./marpa.w"

struct dqueue{gint current;struct dstack s;};

/*:671*/
#line 5629 "./marpa.w"

/*42:*/
#line 497 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g);

/*:42*//*44:*/
#line 505 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id);

/*:44*//*47:*/
#line 527 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:47*//*54:*/
#line 556 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g);

/*:54*//*56:*/
#line 564 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id);

/*:56*//*59:*/
#line 588 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:59*//*94:*/
#line 768 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:94*//*96:*/
#line 780 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:96*//*98:*/
#line 789 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g);

/*:98*//*113:*/
#line 857 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:113*//*116:*/
#line 866 "./marpa.w"

static inline void symbol_free(struct marpa_symbol*symbol);

/*:116*//*125:*/
#line 900 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:125*//*132:*/
#line 926 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);

/*:132*//*170:*/
#line 1090 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol);
/*:170*//*176:*/
#line 1131 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol);
/*:176*//*179:*/
#line 1159 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol);
/*:179*//*182:*/
#line 1198 "./marpa.w"

static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
/*:182*//*191:*/
#line 1238 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:191*//*195:*/
#line 1254 "./marpa.w"

static inline guint rule_sizeof(guint length);

/*:195*//*199:*/
#line 1278 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:199*//*216:*/
#line 1497 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length);

/*:216*//*225:*/
#line 1617 "./marpa.w"

static inline void rule_free(struct marpa_rule*rule);

/*:225*//*231:*/
#line 1642 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:231*//*235:*/
#line 1654 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:235*//*239:*/
#line 1670 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:239*//*243:*/
#line 1683 "./marpa.w"

static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule*rule);
/*:243*//*245:*/
#line 1690 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,guint rh_index);

/*:245*//*256:*/
#line 1757 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule);
/*:256*//*260:*/
#line 1781 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule);
/*:260*//*274:*/
#line 1839 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule);

/*:274*//*306:*/
#line 1964 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:306*//*325:*/
#line 2101 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:325*//*362:*/
#line 2440 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:362*//*401:*/
#line 2807 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:401*//*404:*/
#line 2828 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:404*//*412:*/
#line 2945 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:412*//*426:*/
#line 3157 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:426*//*438:*/
#line 3220 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:438*//*440:*/
#line 3247 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:440*//*447:*/
#line 3314 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:447*//*463:*/
#line 3460 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:463*//*465:*/
#line 3470 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:465*//*467:*/
#line 3486 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix);

/*:467*//*487:*/
#line 3673 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);

/*:487*//*489:*/
#line 3705 "./marpa.w"

static void create_AHFA_states(struct marpa_g*g);

/*:489*//*500:*/
#line 3941 "./marpa.w"

static inline struct AHFA_state*assign_AHFA_state(
struct AHFA_state*state_p,GSequence*duplicates);

/*:500*//*512:*/
#line 4110 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:512*//*516:*/
#line 4204 "./marpa.w"

static struct AHFA_state*
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
struct marpa_rule**rule_by_sort_key,
struct dqueue*states_p,
GSequence*duplicates
);

/*:516*//*520:*/
#line 4232 "./marpa.w"
static
gint cmp_AHFA_transition(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:520*//*522:*/
#line 4244 "./marpa.w"
static inline void
AHFA_transition_add(struct marpa_g*g,
struct AHFA_state*from,Marpa_Symbol_ID symbol,struct AHFA_state*to);

/*:522*//*543:*/
#line 4334 "./marpa.w"

static inline void earley_sets_free(struct earley_set*initial);

/*:543*//*560:*/
#line 4413 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint value);
/*:560*//*562:*/
#line 4425 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*value);

/*:562*//*564:*/
#line 4434 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r);

/*:564*//*588:*/
#line 4556 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:588*//*590:*/
#line 4566 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:590*//*592:*/
#line 4586 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);

/*:592*//*594:*/
#line 4597 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:594*//*596:*/
#line 4619 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:596*//*598:*/
#line 4629 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:598*//*600:*/
#line 4637 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:600*//*602:*/
#line 4650 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:602*//*605:*/
#line 4658 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:605*//*607:*/
#line 4666 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:607*//*609:*/
#line 4674 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:609*//*612:*/
#line 4691 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:612*//*614:*/
#line 4704 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:614*//*616:*/
#line 4716 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:616*//*618:*/
#line 4728 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:618*//*620:*/
#line 4740 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:620*//*622:*/
#line 4814 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:622*//*628:*/
#line 4896 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:628*//*633:*/
#line 4943 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:633*//*635:*/
#line 4951 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:635*//*637:*/
#line 4965 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:637*//*639:*/
#line 4983 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:639*//*642:*/
#line 4992 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:642*//*645:*/
#line 5001 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:645*//*648:*/
#line 5010 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:648*//*650:*/
#line 5063 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:650*//*653:*/
#line 5078 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa);

/*:653*//*656:*/
#line 5095 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size);
/*:656*//*658:*/
#line 5101 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa);
/*:658*//*660:*/
#line 5108 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size);
/*:660*//*662:*/
#line 5115 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,gpointer p);
/*:662*//*664:*/
#line 5128 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa);


/*:664*//*670:*/
#line 5194 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:670*//*700:*/
#line 5529 "./marpa.w"

static inline void message(struct marpa_g*g,Marpa_Message_ID id);

/*:700*/
#line 5630 "./marpa.w"

/*45:*/
#line 511 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symbol_id,
struct marpa_symbol*symbol)
{
g_array_insert_val(g->symbols,(unsigned)symbol_id,symbol);
}

/*:45*//*57:*/
#line 570 "./marpa.w"

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

/*:57*/
#line 5631 "./marpa.w"

/*19:*/
#line 379 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:19*//*25:*/
#line 431 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*33:*/
#line 461 "./marpa.w"

g->id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:33*//*37:*/
#line 476 "./marpa.w"

g->symbols= g_array_new(FALSE,FALSE,sizeof(struct marpa_symbol*));
/*:37*//*49:*/
#line 535 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(struct marpa_rule*));
/*:49*//*61:*/
#line 594 "./marpa.w"

g->start_symbol_id= -1;
/*:61*//*68:*/
#line 641 "./marpa.w"

g->size= 0;

/*:68*//*71:*/
#line 654 "./marpa.w"

g->max_rule_length= 0;

/*:71*//*73:*/
#line 659 "./marpa.w"

g->is_precomputed= FALSE;
/*:73*//*77:*/
#line 670 "./marpa.w"

g->has_loop= FALSE;
/*:77*//*81:*/
#line 685 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:81*//*87:*/
#line 718 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:87*//*102:*/
#line 803 "./marpa.w"
obstack_init(&g->obs);
/*:102*//*106:*/
#line 819 "./marpa.w"

g->error= NULL;
/*:106*//*187:*/
#line 1217 "./marpa.w"

g->symbol_callback_arg= NULL;
g->symbol_callback= NULL;
/*:187*//*298:*/
#line 1939 "./marpa.w"

g->rule_callback_arg= NULL;
g->rule_callback= NULL;
/*:298*//*423:*/
#line 3145 "./marpa.w"

g->AHFA_items= NULL;
g->AHFA_items_by_rule= NULL;
/*:423*//*460:*/
#line 3441 "./marpa.w"

g->AHFA= NULL;
g->AHFA_len= 0;
/*:460*//*696:*/
#line 5508 "./marpa.w"

g->message_callback_arg= NULL;
g->message_callback= NULL;
/*:696*/
#line 434 "./marpa.w"

return g;}
/*:25*//*27:*/
#line 439 "./marpa.w"

void marpa_g_free(struct marpa_g*g)
{/*38:*/
#line 478 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->symbols->len;id++)
{symbol_free(symbol_id2p(g,id));}}
g_array_free(g->symbols,TRUE);

/*:38*//*50:*/
#line 537 "./marpa.w"

{Marpa_Rule_ID id;for(id= 0;id<(Marpa_Rule_ID)g->rules->len;id++)
{rule_free(rule_id2p(g,id));}}
g_array_free(g->rules,TRUE);

/*:50*//*88:*/
#line 720 "./marpa.w"
g_hash_table_destroy(g->context);

/*:88*//*103:*/
#line 804 "./marpa.w"
obstack_free(&g->obs,NULL);

/*:103*//*424:*/
#line 3148 "./marpa.w"

if(g->AHFA_items){g_free(g->AHFA_items);};
if(g->AHFA_items_by_rule){g_free(g->AHFA_items_by_rule);};

/*:424*//*461:*/
#line 3444 "./marpa.w"
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

/*:461*/
#line 441 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:27*//*34:*/
#line 463 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->id;}
/*:34*//*39:*/
#line 486 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:39*//*41:*/
#line 493 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g){
return g->symbols->len;
}
/*:41*//*43:*/
#line 501 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id)
{return g_array_index(g->symbols,struct marpa_symbol*,id);}
/*:43*//*46:*/
#line 522 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id){
return symbol_id>=0&&(guint)symbol_id<g->symbols->len;
}
/*:46*//*51:*/
#line 545 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:51*//*53:*/
#line 552 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g){
return g->rules->len;
}
/*:53*//*55:*/
#line 560 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id)
{return g_array_index(g->rules,struct marpa_rule*,id);}
/*:55*//*58:*/
#line 583 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_id>=0&&(guint)rule_id<g->rules->len;
}
/*:58*//*62:*/
#line 597 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->start_symbol_id;}
/*:62*//*64:*/
#line 604 "./marpa.w"

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
/*:64*//*74:*/
#line 662 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{return g->is_precomputed;}
/*:74*//*78:*/
#line 673 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->has_loop;}
/*:78*//*82:*/
#line 688 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:82*//*84:*/
#line 695 "./marpa.w"

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
/*:84*//*93:*/
#line 759 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:93*//*95:*/
#line 771 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:95*//*97:*/
#line 786 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:97*//*99:*/
#line 792 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:99*//*108:*/
#line 827 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g)
{return g->error?g->error:"unknown error";}
/*:108*//*112:*/
#line 843 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*118:*/
#line 871 "./marpa.w"
symbol->id= g->symbols->len;

/*:118*//*120:*/
#line 880 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:120*//*127:*/
#line 910 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:127*//*134:*/
#line 931 "./marpa.w"

symbol->is_accessible= FALSE;
/*:134*//*140:*/
#line 957 "./marpa.w"

symbol->is_counted= FALSE;
/*:140*//*144:*/
#line 975 "./marpa.w"

symbol->is_nullable= FALSE;
/*:144*//*150:*/
#line 1000 "./marpa.w"

symbol->is_nulling= FALSE;
/*:150*//*156:*/
#line 1027 "./marpa.w"

symbol->is_terminal= FALSE;
/*:156*//*162:*/
#line 1053 "./marpa.w"

symbol->is_productive= FALSE;
/*:162*//*168:*/
#line 1078 "./marpa.w"
symbol->is_start= FALSE;
/*:168*//*174:*/
#line 1108 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:174*/
#line 847 "./marpa.w"

{Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);}
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;}

/*:112*//*115:*/
#line 863 "./marpa.w"

static inline void symbol_free(struct marpa_symbol*symbol)
{/*121:*/
#line 882 "./marpa.w"

g_array_free(symbol->lhs,TRUE);
/*:121*//*128:*/
#line 912 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:128*/
#line 865 "./marpa.w"
g_free(symbol);}
/*:115*//*122:*/
#line 887 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*683:*/
#line 5403 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:683*/
#line 889 "./marpa.w"

/*687:*/
#line 5418 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:687*/
#line 890 "./marpa.w"

return symbol_id2p(g,symbol_id)->lhs;}
/*:122*//*124:*/
#line 894 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:124*//*129:*/
#line 916 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*683:*/
#line 5403 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:683*/
#line 918 "./marpa.w"

/*687:*/
#line 5418 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:687*/
#line 919 "./marpa.w"

return symbol_id2p(g,symbol_id)->rhs;}
/*:129*//*131:*/
#line 923 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
/*:131*//*135:*/
#line 941 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:135*//*137:*/
#line 947 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:137*//*141:*/
#line 967 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:141*//*145:*/
#line 985 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:145*//*147:*/
#line 991 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:147*//*151:*/
#line 1010 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1012 "./marpa.w"

/*687:*/
#line 5418 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:687*/
#line 1013 "./marpa.w"

return symbol_id2p(g,symbol_id)->is_nulling;}
/*:151*//*153:*/
#line 1018 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:153*//*157:*/
#line 1037 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:157*//*159:*/
#line 1043 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:159*//*163:*/
#line 1063 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:163*//*165:*/
#line 1069 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value?1:0;}
/*:165*//*169:*/
#line 1081 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1086 "./marpa.w"

/*687:*/
#line 5418 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:687*/
#line 1087 "./marpa.w"

return symbol_is_start(symbol_id2p(g,symbol_id));
}
/*:169*//*175:*/
#line 1117 "./marpa.w"

static inline
struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol)
{return symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*proper_alias;
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1125 "./marpa.w"

/*687:*/
#line 5418 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:687*/
#line 1126 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->id;
}
/*:175*//*178:*/
#line 1140 "./marpa.w"

static inline
struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*alias;
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1148 "./marpa.w"

/*687:*/
#line 5418 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:687*/
#line 1149 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
alias= symbol_null_alias(symbol);
if(alias==NULL){
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "no alias";
return-1;
}
return alias->id;
}
/*:178*//*181:*/
#line 1173 "./marpa.w"
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
/*:181*//*188:*/
#line 1220 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->symbol_callback_arg= cb_arg;}
gpointer marpa_symbol_callback_arg(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:188*//*190:*/
#line 1234 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:190*//*194:*/
#line 1250 "./marpa.w"

static inline guint rule_sizeof(guint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:194*//*198:*/
#line 1264 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
struct marpa_rule*rule;
/*228:*/
#line 1629 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{guint rh_index;for(rh_index= 0;rh_index<length;rh_index++){
if(!symbol_is_valid(g,rhs[rh_index])){return NULL;}
}}
/*:228*/
#line 1270 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*229:*/
#line 1634 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{guint i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:229*/
#line 1272 "./marpa.w"

/*247:*/
#line 1697 "./marpa.w"
rule->id= g->rules->len;

/*:247*//*250:*/
#line 1709 "./marpa.w"

rule->is_discard= FALSE;
/*:250*//*264:*/
#line 1793 "./marpa.w"

rule->is_loop= FALSE;
/*:264*//*269:*/
#line 1814 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:269*//*276:*/
#line 1844 "./marpa.w"

rule->is_used= TRUE;
/*:276*//*280:*/
#line 1874 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:280*//*284:*/
#line 1885 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:284*//*288:*/
#line 1899 "./marpa.w"
rule->virtual_start= -1;
/*:288*//*292:*/
#line 1915 "./marpa.w"
rule->virtual_end= -1;
/*:292*//*309:*/
#line 1972 "./marpa.w"
rule->original= -1;
/*:309*//*314:*/
#line 1986 "./marpa.w"
rule->real_symbol_count= 0;
/*:314*//*318:*/
#line 1995 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:318*/
#line 1273 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*218:*/
#line 1514 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const guint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*222:*/
#line 1581 "./marpa.w"

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

/*:222*/
#line 1522 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
symbol_id2p(g,rh_symbol_list[rh_list_ix]),
rule->id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:218*/
#line 1275 "./marpa.w"

return rule;
}
/*:198*//*200:*/
#line 1283 "./marpa.w"

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

/*:200*//*201:*/
#line 1300 "./marpa.w"

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

/*204:*/
#line 1335 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*203:*/
#line 1333 "./marpa.w"
g->error= "internal_error";return-1;
/*:203*/
#line 1337 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:204*/
#line 1313 "./marpa.w"

/*205:*/
#line 1341 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:205*/
#line 1314 "./marpa.w"

/*206:*/
#line 1345 "./marpa.w"

symbol_id2p(g,rhs_id)->is_counted= 1;
if(separator_id>=0){symbol_id2p(g,separator_id)->is_counted= 1;}
/*:206*/
#line 1315 "./marpa.w"

if(min==0){/*207:*/
#line 1348 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*203:*/
#line 1333 "./marpa.w"
g->error= "internal_error";return-1;
/*:203*/
#line 1350 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:207*/
#line 1316 "./marpa.w"
}
min= 1;
/*208:*/
#line 1355 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:208*/
#line 1318 "./marpa.w"

/*209:*/
#line 1369 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:209*/
#line 1319 "./marpa.w"

/*211:*/
#line 1372 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*203:*/
#line 1333 "./marpa.w"
g->error= "internal_error";return-1;
/*:203*/
#line 1376 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:211*/
#line 1320 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*212:*/
#line 1385 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*203:*/
#line 1333 "./marpa.w"
g->error= "internal_error";return-1;
/*:203*/
#line 1390 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:212*/
#line 1322 "./marpa.w"

}
/*213:*/
#line 1402 "./marpa.w"

{struct marpa_rule*rule;
guint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*203:*/
#line 1333 "./marpa.w"
g->error= "internal_error";return-1;
/*:203*/
#line 1412 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:213*/
#line 1324 "./marpa.w"

/*214:*/
#line 1417 "./marpa.w"

{struct marpa_rule*rule;
guint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*203:*/
#line 1333 "./marpa.w"
g->error= "internal_error";return-1;
/*:203*/
#line 1424 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:214*/
#line 1325 "./marpa.w"

/*210:*/
#line 1371 "./marpa.w"
g_free(temp_rhs);
/*:210*/
#line 1326 "./marpa.w"

return original_rule_id;
}
/*:201*//*215:*/
#line 1473 "./marpa.w"

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
/*:215*//*224:*/
#line 1613 "./marpa.w"

static inline void rule_free(struct marpa_rule*rule)
{
g_free(rule);}
/*:224*//*230:*/
#line 1639 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
/*:230*//*232:*/
#line 1644 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1646 "./marpa.w"

/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1647 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:232*//*234:*/
#line 1651 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:234*//*236:*/
#line 1656 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix){
struct marpa_rule*rule;
/*685:*/
#line 5407 "./marpa.w"
const int failure_indicator= -2;

/*:685*/
#line 1659 "./marpa.w"

/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1660 "./marpa.w"

rule= rule_id2p(g,rule_id);
if(rule->length<=ix)return-1;
return rhs_symbol_id(rule,ix);
}
/*:236*//*238:*/
#line 1667 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:238*//*240:*/
#line 1672 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1674 "./marpa.w"

/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1675 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:240*//*242:*/
#line 1680 "./marpa.w"

static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule*rule){return rule->symbols[0];}
/*:242*//*244:*/
#line 1685 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,guint rh_index){
return rule->symbols[rh_index+1];
}
/*:244*//*251:*/
#line 1711 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:251*//*255:*/
#line 1744 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule)
{
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
return symbol_id2p(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1751 "./marpa.w"

struct marpa_rule*rule;
/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1753 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:255*//*259:*/
#line 1764 "./marpa.w"

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
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1775 "./marpa.w"

struct marpa_rule*rule;
/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1777 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:259*//*265:*/
#line 1797 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1800 "./marpa.w"

/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1801 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:265*//*270:*/
#line 1818 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1821 "./marpa.w"

/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1822 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:270*//*273:*/
#line 1830 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:273*//*277:*/
#line 1848 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 1851 "./marpa.w"

/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1852 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:277*//*281:*/
#line 1877 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:281*//*285:*/
#line 1888 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:285*//*289:*/
#line 1900 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*685:*/
#line 5407 "./marpa.w"
const int failure_indicator= -2;

/*:685*/
#line 1903 "./marpa.w"

/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1904 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_start;
}
/*:289*//*293:*/
#line 1916 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*685:*/
#line 5407 "./marpa.w"
const int failure_indicator= -2;

/*:685*/
#line 1919 "./marpa.w"

/*688:*/
#line 5425 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:688*/
#line 1920 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_end;
}
/*:293*//*299:*/
#line 1942 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:299*//*301:*/
#line 1947 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:301*//*303:*/
#line 1952 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:303*//*305:*/
#line 1960 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:305*//*310:*/
#line 1973 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}
/*:310*//*315:*/
#line 1987 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}
/*:315*//*319:*/
#line 2006 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:319*//*321:*/
#line 2025 "./marpa.w"

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
#line 2071 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*326:*/
#line 2103 "./marpa.w"

guint pre_rewrite_rule_count= g->rules->len;
guint pre_rewrite_symbol_count= g->symbols->len;

/*:326*//*331:*/
#line 2136 "./marpa.w"

Marpa_Symbol_ID original_start_symbol_id= g->start_symbol_id;
struct marpa_symbol*original_start_symbol;

/*:331*//*335:*/
#line 2173 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:335*//*341:*/
#line 2232 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:341*//*343:*/
#line 2259 "./marpa.w"

Bit_Vector nullable_v;
/*:343*//*347:*/
#line 2285 "./marpa.w"

Bit_Vector productive_v;
/*:347*//*350:*/
#line 2326 "./marpa.w"
Bit_Matrix reach_matrix;
/*:350*//*353:*/
#line 2344 "./marpa.w"

Bit_Vector accessible_v;

/*:353*/
#line 2074 "./marpa.w"

/*327:*/
#line 2107 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:327*/
#line 2075 "./marpa.w"

/*328:*/
#line 2114 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:328*/
#line 2076 "./marpa.w"

/*330:*/
#line 2120 "./marpa.w"

if(original_start_symbol_id<0){
g->error= "no start symbol";
return NULL;
}
if(!symbol_is_valid(g,original_start_symbol_id)){
g_context_int_add(g,"symbol_id",original_start_symbol_id);
g->error= "invalid start symbol";
return NULL;
}
original_start_symbol= symbol_id2p(g,original_start_symbol_id);
if(original_start_symbol->lhs->len<=0){
g_context_int_add(g,"symbol_id",original_start_symbol_id);
g->error= "start symbol not on LHS";
return NULL;
}
/*:330*/
#line 2077 "./marpa.w"

/*332:*/
#line 2140 "./marpa.w"

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
#line 2078 "./marpa.w"

/*333:*/
#line 2159 "./marpa.w"

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
#line 2079 "./marpa.w"

if(have_marked_terminals){
/*337:*/
#line 2188 "./marpa.w"

if(!g->is_lhs_terminal_ok){
gboolean have_bad_lhs= 0;
guint start= 0;
guint min,max;
Bit_Vector bad_lhs_v= bv_clone(terminal_v);
bv_and(bad_lhs_v,bad_lhs_v,lhs_v);
while(bv_scan(bad_lhs_v,start,&min,&max)){
Marpa_Symbol_ID i;
for(i= (Marpa_Symbol_ID)min;i<=(Marpa_Symbol_ID)max;i++){
g_context_clear(g);
g_context_int_add(g,"symbol_id",i);
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
#line 2081 "./marpa.w"

}else{
/*336:*/
#line 2177 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:336*/
#line 2083 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*338:*/
#line 2212 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<(Marpa_Symbol_ID)g->symbols->len;symbol_id++)
{symbol_id2p(g,symbol_id)->is_terminal= 1;}}
/*:338*/
#line 2085 "./marpa.w"

}else{
/*339:*/
#line 2217 "./marpa.w"

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
#line 2087 "./marpa.w"

}
}
/*342:*/
#line 2237 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{guint min,max,start;
Marpa_Symbol_ID symbol_id;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symbol_id= (Marpa_Symbol_ID)min;symbol_id<=(Marpa_Symbol_ID)max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_counted){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
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
#line 2090 "./marpa.w"

/*345:*/
#line 2264 "./marpa.w"

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
#line 2091 "./marpa.w"

/*346:*/
#line 2278 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->start_symbol_id))
{
g_context_int_add(g,"symbol_id",g->start_symbol_id);
g->error= "unproductive start symbol";
return NULL;
}
/*:346*/
#line 2092 "./marpa.w"

/*349:*/
#line 2308 "./marpa.w"

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
#line 2093 "./marpa.w"

/*352:*/
#line 2330 "./marpa.w"

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
#line 2094 "./marpa.w"

/*354:*/
#line 2349 "./marpa.w"

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
#line 2095 "./marpa.w"

/*334:*/
#line 2171 "./marpa.w"

bv_free(terminal_v);
/*:334*//*340:*/
#line 2229 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:340*//*344:*/
#line 2261 "./marpa.w"

bv_free(nullable_v);

/*:344*//*348:*/
#line 2287 "./marpa.w"

bv_free(productive_v);

/*:348*/
#line 2096 "./marpa.w"

/*351:*/
#line 2327 "./marpa.w"

matrix_free(reach_matrix);

/*:351*/
#line 2097 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:324*//*361:*/
#line 2419 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*363:*/
#line 2442 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:363*//*367:*/
#line 2493 "./marpa.w"

guint factor_count;
guint*factor_positions;
/*:367*//*372:*/
#line 2542 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:372*/
#line 2422 "./marpa.w"

/*368:*/
#line 2496 "./marpa.w"

factor_positions= g_new(guint,g->max_rule_length);
/*:368*//*373:*/
#line 2545 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:373*/
#line 2423 "./marpa.w"

/*365:*/
#line 2454 "./marpa.w"

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
#line 2424 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
guint rule_length= rule->length;
guint nullable_suffix_ix= 0;
/*364:*/
#line 2446 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:364*/
#line 2430 "./marpa.w"

/*366:*/
#line 2477 "./marpa.w"

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
#line 2431 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*370:*/
#line 2502 "./marpa.w"

rule->is_used= 0;
{guint unprocessed_factor_count;

guint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= lhs_symbol_id(rule);
guint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*376:*/
#line 2555 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symbol_id;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*371:*/
#line 2521 "./marpa.w"
{
struct marpa_symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",lhs_symbol_id(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:371*/
#line 2563 "./marpa.w"

/*377:*/
#line 2582 "./marpa.w"

{
guint remaining_rhs_length,piece_rhs_length;
/*378:*/
#line 2594 "./marpa.w"

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
#line 2787 "./marpa.w"

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
#line 2606 "./marpa.w"

}

/*:378*/
#line 2585 "./marpa.w"
;
/*379:*/
#line 2609 "./marpa.w"

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
#line 2787 "./marpa.w"

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
#line 2621 "./marpa.w"

}

/*:379*/
#line 2586 "./marpa.w"
;
/*380:*/
#line 2626 "./marpa.w"
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
#line 2787 "./marpa.w"

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
#line 2636 "./marpa.w"

}

/*:380*/
#line 2587 "./marpa.w"
;
/*381:*/
#line 2645 "./marpa.w"

if(piece_start<nullable_suffix_ix){
struct marpa_rule*chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2650 "./marpa.w"

}

/*:381*/
#line 2588 "./marpa.w"
;
}

/*:377*/
#line 2564 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*371:*/
#line 2521 "./marpa.w"
{
struct marpa_symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",lhs_symbol_id(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:371*/
#line 2569 "./marpa.w"

/*383:*/
#line 2655 "./marpa.w"
{
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:383*//*384:*/
#line 2664 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2670 "./marpa.w"


/*:384*//*385:*/
#line 2673 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2678 "./marpa.w"


/*:385*//*386:*/
#line 2681 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2687 "./marpa.w"


/*:386*//*387:*/
#line 2690 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2693 "./marpa.w"


/*:387*//*388:*/
#line 2696 "./marpa.w"
}

/*:388*/
#line 2570 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symbol_id;
piece_start= piece_end+1;

/*:376*/
#line 2513 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*389:*/
#line 2700 "./marpa.w"
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
#line 2714 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2719 "./marpa.w"


/*:390*//*391:*/
#line 2722 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2727 "./marpa.w"


/*:391*//*392:*/
#line 2730 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2736 "./marpa.w"


/*:392*//*393:*/
#line 2740 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2744 "./marpa.w"

}

/*:393*//*394:*/
#line 2748 "./marpa.w"
}

/*:394*/
#line 2516 "./marpa.w"

}else{
/*395:*/
#line 2751 "./marpa.w"
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
#line 2762 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2767 "./marpa.w"


/*:396*//*397:*/
#line 2771 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*399:*/
#line 2787 "./marpa.w"

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
#line 2777 "./marpa.w"

}

/*:397*//*398:*/
#line 2781 "./marpa.w"
}

/*:398*/
#line 2518 "./marpa.w"

}}

/*:370*/
#line 2434 "./marpa.w"

NEXT_RULE:;
}
/*369:*/
#line 2498 "./marpa.w"

g_free(factor_positions);

/*:369*//*374:*/
#line 2548 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:374*/
#line 2437 "./marpa.w"

return g;
}
/*:361*//*400:*/
#line 2801 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
return alias->id;
}
/*:400*//*403:*/
#line 2815 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct marpa_symbol*proper_old_start= NULL;
struct marpa_symbol*nulling_old_start= NULL;
struct marpa_symbol*proper_new_start= NULL;
struct marpa_symbol*old_start= symbol_id2p(g,g->start_symbol_id);
/*405:*/
#line 2831 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:405*/
#line 2823 "./marpa.w"

if(proper_old_start){/*406:*/
#line 2841 "./marpa.w"
{
struct marpa_rule*new_start_rule;
proper_old_start->is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= proper_new_start->id;
g->start_symbol_id= proper_new_start_id;
proper_new_start->is_accessible= TRUE;
proper_new_start->is_productive= TRUE;
proper_new_start->is_start= TRUE;
g_context_clear(g);
g_context_int_add(g,"old_start_id",old_start->id);
symbol_callback(g,proper_new_start_id);
new_start_rule= rule_start(g,proper_new_start_id,&old_start->id,1);
new_start_rule->is_virtual_lhs= 1;
new_start_rule->real_symbol_count= 1;
new_start_rule->is_used= TRUE;
rule_callback(g,new_start_rule->id);
}

/*:406*/
#line 2824 "./marpa.w"
}
if(nulling_old_start){/*407:*/
#line 2864 "./marpa.w"
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
g_context_clear(g);
g_context_int_add(g,"old_start_id",old_start->id);
symbol_callback(g,nulling_new_start_id);
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
new_start_rule->is_virtual_lhs= 1;
new_start_rule->real_symbol_count= 1;
new_start_rule->is_used= TRUE;
rule_callback(g,new_start_rule->id);
}

/*:407*/
#line 2825 "./marpa.w"
}
return g;
}
/*:403*//*411:*/
#line 2931 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{guint no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*413:*/
#line 2954 "./marpa.w"
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
#line 2938 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*414:*/
#line 2993 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
struct marpa_rule*rule;
if(!matrix_bit_test(unit_transition_matrix,(guint)rule_id,(guint)rule_id))
continue;
loop_rule_count++;
rule= rule_id2p(g,rule_id);
rule->is_loop= TRUE;
rule->is_virtual_loop= rule->virtual_start<0||!rule->is_virtual_rhs;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
message(g,"loop rule");
}}

/*:414*/
#line 2940 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*415:*/
#line 3014 "./marpa.w"

g_context_clear(g);
g_context_int_add(g,"loop_rule_count",loop_rule_count);
message(g,"loop rule tally");

/*:415*/
#line 2942 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:411*//*425:*/
#line 3152 "./marpa.w"

static inline struct AHFA_item*
item_id2p(struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return g->AHFA_items+item_id;
}
/*:425*//*427:*/
#line 3162 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 3164 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3165 "./marpa.w"

return g->no_of_items;
}
/*:427*//*429:*/
#line 3171 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 3174 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3175 "./marpa.w"

/*689:*/
#line 5432 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:689*/
#line 3176 "./marpa.w"

return item_id2p(g,item_id)->rule->id;
}
/*:429*//*431:*/
#line 3182 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*685:*/
#line 5407 "./marpa.w"
const int failure_indicator= -2;

/*:685*/
#line 3185 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3186 "./marpa.w"

/*689:*/
#line 5432 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:689*/
#line 3187 "./marpa.w"

return item_id2p(g,item_id)->position;
}
/*:431*//*433:*/
#line 3193 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*685:*/
#line 5407 "./marpa.w"
const int failure_indicator= -2;

/*:685*/
#line 3196 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3197 "./marpa.w"

/*689:*/
#line 5432 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:689*/
#line 3198 "./marpa.w"

return item_id2p(g,item_id)->postdot;
}
/*:433*//*435:*/
#line 3203 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 3206 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3207 "./marpa.w"

/*689:*/
#line 5432 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:689*/
#line 3208 "./marpa.w"

return item_id2p(g,item_id)->sort_key;
}
/*:435*//*437:*/
#line 3215 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<(Marpa_AHFA_Item_ID)g->no_of_items&&item_id>=0;
}
/*:437*//*439:*/
#line 3230 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
Marpa_Rule_ID rule_id;
guint no_of_items;
guint no_of_rules= rule_count(g);
struct AHFA_item*base_item= g_new(struct AHFA_item,g->size);
struct AHFA_item*current_item= base_item;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
/*441:*/
#line 3250 "./marpa.w"

guint rhs_ix;
struct marpa_rule*rule= rule_id2p(g,rule_id);
if(!rule->is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->length;rhs_ix++){
/*442:*/
#line 3262 "./marpa.w"

Marpa_Symbol_ID rh_symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,rh_symbol_id);
if(symbol->is_nullable)goto NEXT_RH_SYMBOL;
current_item->sort_key= current_item-base_item;
current_item->postdot= rh_symbol_id;
current_item->rule= rule;
current_item->position= rhs_ix;

/*:442*/
#line 3255 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*443:*/
#line 3271 "./marpa.w"

current_item->sort_key= current_item-base_item;
current_item->postdot= current_item->position= -1;
current_item->rule= rule;

/*:443*/
#line 3259 "./marpa.w"

current_item++;

/*:441*/
#line 3239 "./marpa.w"

NEXT_RULE:;
}
no_of_items= g->no_of_items= current_item-base_item;
g->AHFA_items= g_renew(struct AHFA_item,base_item,no_of_items);
/*444:*/
#line 3281 "./marpa.w"
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

/*:444*/
#line 3244 "./marpa.w"

/*448:*/
#line 3317 "./marpa.w"
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

/*:448*/
#line 3245 "./marpa.w"

}
/*:439*//*446:*/
#line 3302 "./marpa.w"

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
/*:446*//*462:*/
#line 3456 "./marpa.w"

static inline struct AHFA_state*
AHFA_state_id2p(const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{return g->AHFA+AHFA_state_id;}
/*:462*//*464:*/
#line 3465 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id){
return AHFA_state_id<g->AHFA_len&&AHFA_state_id>=0;
}
/*:464*//*466:*/
#line 3481 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix){
return state->items[item_ix]-g->AHFA_items;
}
/*:466*//*468:*/
#line 3491 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return g->AHFA_len;
}
/*:468*//*470:*/
#line 3498 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 3501 "./marpa.w"

struct AHFA_state*state;
/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3503 "./marpa.w"

/*690:*/
#line 5439 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:690*/
#line 3504 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->item_count;
}
/*:470*//*472:*/
#line 3511 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix){
struct AHFA_state*state;
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 3516 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3517 "./marpa.w"

/*690:*/
#line 5439 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:690*/
#line 3518 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
if(item_ix>=state->item_count){
g_context_clear(g);
g_context_int_add(g,"item_ix",(gint)item_ix);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid state item ix";
return failure_indicator;
}
return AHFA_state_item_ix2id(g,state,item_ix);
}
/*:472*//*474:*/
#line 3534 "./marpa.w"

gint
marpa_AHFA_state_transition_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 3537 "./marpa.w"

struct AHFA_state*state;
/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3539 "./marpa.w"

/*690:*/
#line 5439 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:690*/
#line 3540 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return g_sequence_get_length(state->transitions);
}
/*:474*//*477:*/
#line 3561 "./marpa.w"

struct marpa_AHFA_transition*marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
struct marpa_AHFA_transition*buffer){
GSequence*transitions;
GSequenceIter*iter;
GSequenceIter*end;
struct marpa_AHFA_transition*p_buffer= buffer;
/*683:*/
#line 5403 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:683*/
#line 3569 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3570 "./marpa.w"

/*690:*/
#line 5439 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:690*/
#line 3571 "./marpa.w"

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
/*:477*//*479:*/
#line 3590 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
struct AHFA_state*empty_transition_state;
/*685:*/
#line 5407 "./marpa.w"
const int failure_indicator= -2;

/*:685*/
#line 3595 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3596 "./marpa.w"

/*690:*/
#line 5439 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:690*/
#line 3597 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
empty_transition_state= state->empty_transition;
if(empty_transition_state)return empty_transition_state->id;
return-1;
}
/*:479*//*481:*/
#line 3607 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 3611 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3612 "./marpa.w"

/*690:*/
#line 5439 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:690*/
#line 3613 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->is_predict;
}
/*:481*//*483:*/
#line 3621 "./marpa.w"

gint marpa_AHFA_state_is_leo_completion(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
/*684:*/
#line 5405 "./marpa.w"
const int failure_indicator= -1;
/*:684*/
#line 3625 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 3626 "./marpa.w"

/*690:*/
#line 5439 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:690*/
#line 3627 "./marpa.w"

state= AHFA_state_id2p(g,AHFA_state_id);
return state->is_leo_completion;
}
/*:483*//*486:*/
#line 3650 "./marpa.w"

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
/*:486*//*488:*/
#line 3678 "./marpa.w"

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
/*491:*/
#line 3740 "./marpa.w"
{guint item_id;
guint no_of_items_in_grammar= g->no_of_items;
duplicates= g_sequence_new(NULL);
singleton_duplicates= g_new(struct AHFA_state*,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++){
singleton_duplicates[item_id]= NULL;
}}
/*:491*/
#line 3691 "./marpa.w"

DQUEUE_INIT(states,struct AHFA_state,initial_no_of_states);
/*506:*/
#line 4002 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= matrix_create(no_of_symbols,no_of_symbols);
/*507:*/
#line 4010 "./marpa.w"

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

/*:507*/
#line 4004 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*508:*/
#line 4042 "./marpa.w"
{
struct AHFA_item**items_by_rule= g->AHFA_items_by_rule;
Marpa_Symbol_ID from_symbol_id;
guint*sort_key_by_rule_id= g_new(guint,no_of_rules);
guint no_of_predictable_rules= 0;
/*509:*/
#line 4072 "./marpa.w"

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

/*:509*/
#line 4048 "./marpa.w"

/*510:*/
#line 4087 "./marpa.w"

{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
rule_by_sort_key[rule_id]= rule_id2p(g,rule_id);
}
g_qsort_with_data(rule_by_sort_key,(gint)no_of_rules,
sizeof(struct marpa_rule*),cmp_by_rule_sort_key,
(gpointer)sort_key_by_rule_id);
}

/*:510*/
#line 4049 "./marpa.w"

/*513:*/
#line 4117 "./marpa.w"
{
guint sort_key;
for(sort_key= 0;sort_key<no_of_rules;sort_key++){
struct marpa_rule*rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->id]= sort_key;
}}

/*:513*/
#line 4050 "./marpa.w"

/*514:*/
#line 4124 "./marpa.w"
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

/*:514*/
#line 4051 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:508*/
#line 4006 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:506*/
#line 3693 "./marpa.w"

/*493:*/
#line 3751 "./marpa.w"
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

/*:493*/
#line 3694 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,struct AHFA_state))){
/*490:*/
#line 3708 "./marpa.w"
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
/*495:*/
#line 3792 "./marpa.w"
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
/*497:*/
#line 3856 "./marpa.w"
{
Marpa_Symbol_ID previous_nonnulling_symbol_id= single_item_p[-1].postdot;
p_new_state->is_leo_completion
= SYMBOL_LHS_RULE_COUNT(
symbol_id2p(g,previous_nonnulling_symbol_id)
)> 0;
}

/*:497*/
#line 3828 "./marpa.w"

}
}

/*:495*/
#line 3728 "./marpa.w"

}else{
/*498:*/
#line 3879 "./marpa.w"
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
/*501:*/
#line 3946 "./marpa.w"
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

/*:501*/
#line 3920 "./marpa.w"

}

/*:498*/
#line 3730 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= item_list[current_item_ix]->postdot;
if(working_symbol==-1)break;
}
NEXT_AHFA_STATE:;
}

/*:490*/
#line 3696 "./marpa.w"

}
g->AHFA= DQUEUE_BASE(states,struct AHFA_state);

g->AHFA_len= DQUEUE_END(states);
g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*492:*/
#line 3747 "./marpa.w"

g_free(singleton_duplicates);
g_sequence_free(duplicates);

/*:492*/
#line 3703 "./marpa.w"

}
/*:488*//*499:*/
#line 3926 "./marpa.w"

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
/*:499*//*511:*/
#line 4097 "./marpa.w"
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
/*:511*//*515:*/
#line 4150 "./marpa.w"

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
/*:515*//*519:*/
#line 4222 "./marpa.w"
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
/*:519*//*521:*/
#line 4236 "./marpa.w"
static inline
void AHFA_transition_add(struct marpa_g*g,
struct AHFA_state*from,Marpa_Symbol_ID symbol,struct AHFA_state*to){
struct AHFA_transition*transition= obstack_alloc(&g->obs,sizeof(struct AHFA_transition));
transition->symbol= symbol;
transition->to= to->id;
g_sequence_insert_sorted(from->transitions,transition,cmp_AHFA_transition,NULL);
}
/*:521*//*525:*/
#line 4261 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g)
{struct marpa_r*r;
/*683:*/
#line 5403 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:683*/
#line 4264 "./marpa.w"

/*686:*/
#line 5412 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:686*/
#line 4265 "./marpa.w"

r= g_slice_new(struct marpa_r);
r->grammar= g;
/*568:*/
#line 4448 "./marpa.w"
obstack_init(&r->obs);
/*:568*/
#line 4268 "./marpa.w"

/*533:*/
#line 4298 "./marpa.w"

r->id= g_atomic_int_exchange_and_add(&next_recce_id,1);
/*:533*//*539:*/
#line 4319 "./marpa.w"

r->phase= initial_phase;

/*:539*//*545:*/
#line 4340 "./marpa.w"

r->too_many_earley_items= MAX(DEFAULT_TOO_MANY_EARLEY_ITEMS,g->no_of_items*2);
/*:545*//*551:*/
#line 4362 "./marpa.w"

r->is_trace_earley_sets= FALSE;
/*:551*//*557:*/
#line 4393 "./marpa.w"

r->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:557*//*572:*/
#line 4462 "./marpa.w"

r->error= NULL;
/*:572*/
#line 4269 "./marpa.w"

return r;}
/*:525*//*527:*/
#line 4274 "./marpa.w"

void marpa_r_free(struct marpa_r*r)
{
/*541:*/
#line 4328 "./marpa.w"

if(r->initial)earley_sets_free(r->initial);
/*:541*//*558:*/
#line 4395 "./marpa.w"
g_hash_table_destroy(r->context);

/*:558*/
#line 4277 "./marpa.w"

/*569:*/
#line 4449 "./marpa.w"
obstack_free(&r->obs,NULL);

/*:569*/
#line 4278 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:527*//*534:*/
#line 4300 "./marpa.w"

gint marpa_recce_id(struct marpa_r*r){return r->id;}
/*:534*//*542:*/
#line 4330 "./marpa.w"

static inline void earley_sets_free(struct earley_set*initial){
g_debug("Not yet implemented");
}
/*:542*//*546:*/
#line 4343 "./marpa.w"

guint marpa_too_many_earley_items(struct marpa_r*r)
{return r->too_many_earley_items;}
/*:546*//*548:*/
#line 4350 "./marpa.w"

gboolean marpa_too_many_earley_items_set(struct marpa_r*r,guint too_many_earley_items)
{
r->too_many_earley_items= too_many_earley_items;
return TRUE;
}
/*:548*//*552:*/
#line 4365 "./marpa.w"

gboolean marpa_is_trace_earley_sets(struct marpa_r*r)
{return r->is_trace_earley_sets;}
/*:552*//*554:*/
#line 4372 "./marpa.w"

gboolean marpa_is_trace_earley_sets_set(
struct marpa_r*r,gboolean value)
{
r->is_trace_earley_sets= value;
return TRUE;
}
/*:554*//*559:*/
#line 4404 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(r->context,(gpointer)key,value);
}
/*:559*//*561:*/
#line 4416 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(r->context,(gpointer)key,value);
}
/*:561*//*563:*/
#line 4431 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r){
g_hash_table_remove_all(r->context);}
/*:563*//*565:*/
#line 4437 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key)
{return g_hash_table_lookup(r->context,key);}
/*:565*//*574:*/
#line 4470 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r)
{return r->error?r->error:"unknown error";}
/*:574*//*581:*/
#line 4508 "./marpa.w"

static inline struct earley_item*earley_item_new(struct marpa_r*r)
{struct earley_item*item= 
obstack_alloc(&r->obs,sizeof(struct earley_item*));
return item;
}
/*:581*//*587:*/
#line 4551 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:587*//*589:*/
#line 4559 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:589*//*591:*/
#line 4575 "./marpa.w"

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
/*:591*//*593:*/
#line 4592 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:593*//*595:*/
#line 4604 "./marpa.w"
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
/*:595*//*597:*/
#line 4624 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:597*//*599:*/
#line 4633 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:599*//*601:*/
#line 4641 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:601*//*604:*/
#line 4654 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:604*//*606:*/
#line 4662 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:606*//*608:*/
#line 4670 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:608*//*611:*/
#line 4679 "./marpa.w"

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
/*:611*//*613:*/
#line 4696 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:613*//*615:*/
#line 4708 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:615*//*617:*/
#line 4720 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:617*//*619:*/
#line 4732 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:619*//*621:*/
#line 4744 "./marpa.w"

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
/*:621*//*627:*/
#line 4858 "./marpa.w"

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
/*:627*//*632:*/
#line 4927 "./marpa.w"

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
/*:632*//*634:*/
#line 4947 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:634*//*636:*/
#line 4960 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:636*//*638:*/
#line 4977 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:638*//*641:*/
#line 4987 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:641*//*644:*/
#line 4996 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:644*//*647:*/
#line 5005 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:647*//*649:*/
#line 5019 "./marpa.w"

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
/*:649*//*652:*/
#line 5073 "./marpa.w"

static inline void p_array_destroy(struct p_array*pa){
gpointer data= pa->data;
if(data)g_free(data);
}
/*:652*//*655:*/
#line 5092 "./marpa.w"

static inline void dp_array_init(struct dp_array*dpa,gint size){
dpa->pa.len= 0;dpa->size= size;dpa->pa.data= g_new(gpointer,size);}
/*:655*//*657:*/
#line 5097 "./marpa.w"

static inline void dp_array_destroy(struct dp_array*dpa){
p_array_destroy(&(dpa->pa));
}
/*:657*//*659:*/
#line 5103 "./marpa.w"

static inline void dp_array_resize(struct dp_array*dpa,gint new_size){
dpa->pa.data= g_renew(gpointer,dpa->pa.data,new_size);
dpa->size= new_size;
}
/*:659*//*661:*/
#line 5110 "./marpa.w"

static inline void dp_array_append(struct dp_array*dpa,gpointer p){
if(dpa->pa.len>=dpa->size)dp_array_resize(dpa,dpa->size*2);
dpa->pa.data[dpa->pa.len++]= p;
}
/*:661*//*663:*/
#line 5119 "./marpa.w"

static inline void dp_array_freeze(struct dp_array*dpa,struct p_array*pa){
gint len= pa->len= dpa->pa.len;
if(G_UNLIKELY(len>=dpa->size)){
pa->data= dpa->pa.data;
return;
}
pa->data= g_renew(gpointer,dpa->pa.data,len);
}
/*:663*//*669:*/
#line 5188 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:669*//*697:*/
#line 5511 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->message_callback_arg= cb_arg;}
gpointer marpa_message_callback_arg(struct marpa_g*g)
{return g->message_callback_arg;}
/*:697*//*699:*/
#line 5525 "./marpa.w"

static inline void message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:699*/
#line 5632 "./marpa.w"





/*:707*/
