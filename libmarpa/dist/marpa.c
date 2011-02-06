/*835:*/
#line 6894 "./marpa.w"

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
#define Symbol_Count_of_G(g) ((g) ->symbols->len)  \

#define Symbol_by_ID(g,id) (g_array_index((g) ->symbols,struct symbol*,(id) ) )  \

#define SYMBOL_LHS_RULE_COUNT(symbol) ((symbol) ->lhs->len) 
#define Symbol_is_Terminal(symbol) ((symbol) ->is_terminal) 
#define Symbol_is_Terminal_by_ID(g,id) (Symbol_is_Terminal(Symbol_by_ID((g) ,(id) ) ) ) 
#define LHS_Symbol_ID_of_Rule(rule) ((rule) ->symbols[0])  \

#define AHFA_Item_by_ID(g,id) ((g) ->AHFA_items+(id) )  \

#define LHS_Symbol_ID_of_AHFA_Item(item) LHS_ID_of_Rule(Rule_of_AHFA_Item(item) )  \

#define Postdot_Symbol_ID_of_AHFA_Item(item) ((item) ->postdot) 
#define Rule_of_AHFA_Item(item) ((item) ->rule)  \

#define ID_of_AHFA_State(state) ((state) ->key.id)  \

#define AHFA_State_of_G_by_ID(g,id) ((g) ->AHFA+(id) ) 
#define AHFA_State_of_R_by_ID(r,id) AHFA_State_of_G_by_ID(G_of_R(r) ,(id) )  \

#define Postdot_Symbol_Count_of_AHFA_State(state) ((state) ->no_of_postdot_symbols) 
#define Postdot_Symbol_ID_Array_of_AHFA_State(state) ((state) ->postdot_symbols) 
#define To_State_of_Earley_Item_and_Symbol_ID(item,id)  \
(to_state_find(AHFA_State_of_Earley_Item(item) ,(id) ) ) 
#define Empty_Transition_of_AHFA_State(state) ((state) ->empty_transition) 
#define Symbol_ID_of_AHFA_Transition(transition) ((transition) ->key.symbol_id) 
#define To_State_of_AHFA_Transition(transition) ((transition) ->to_state) 
#define To_State_ID_of_AHFA_Transition(transition)  \
(ID_of_AHFA_State(To_State_of_AHFA_Transition(transition) ) ) 
#define G_of_R(r) ((r) ->grammar) 
#define Current_Earley_Set_Iter_of_R(r) ((r) ->current_iter) 
#define LV_Current_Earley_Set_Iter_of_R(r) Current_Earley_Set_Iter_of_R(r) 
#define Earley_Set_of_Earley_Set_Iter(iter)  \
((struct earley_set*) g_sequence_get(iter) ) 
#define Current_Earley_Set_of_R(r)  \
(Earley_Set_of_Earley_Set_Iter(Current_Earley_Set_Iter_of_R(r) ) ) 
#define Earleme_of_Earley_Set_Iter(iter) ID_of_Earley_Set(Earley_Set_of_Earley_Set_Iter(iter) ) 
#define Current_Earleme_of_R(r) (Earleme_of_Earley_Set_Iter(Current_Earley_Set_Iter_of_R(r) ) ) 
#define DEFAULT_EARLEY_ITEM_WARNING_THRESHOLD (100) 
#define Furthest_Earleme_of_R(r) ((r) ->furthest_earleme) 
#define LV_Furthest_Earleme_of_R(r) Furthest_Earleme_of_R(r) 
#define EARLEME_THRESHOLD (G_MAXINT/4) 
#define ID_of_Earley_Set(set) ((set) ->key.id) 
#define Earleme_of_Earley_Set(set) ID_of_Earley_Set(set)  \

#define Earley_Set_by_ID(r,id) (earley_set_by_id((r) ,(id) ) ) 
#define EARLEY_ITEM_FATAL_THRESHOLD (G_MAXINT/4)  \

#define AHFA_State_ID_of_Earley_Item(item) (ID_of_AHFA_State(AHFA_State_of_Earley_Item(item) ) ) 
#define AHFA_State_of_Earley_Item(item) ((item) ->key.state)  \

#define Origin_ID_of_Earley_Item(item) (ID_of_Earley_Set(Origin_of_Earley_Item(item) ) ) 
#define Origin_of_Earley_Item(item) ((item) ->key.origin)  \

#define NO_SOURCE (0U) 
#define SOURCE_IS_TOKEN (1U) 
#define SOURCE_IS_LEO_TOKEN (2U) 
#define SOURCE_IS_COMPLETION (3U) 
#define SOURCE_IS_LEO_COMPLETION (4U) 
#define SOURCE_IS_AMBIGUOUS (5U) 
#define Source_Type_of_Earley_Item(item) ((item) ->source_type) 
#define Item_has_No_Source(item) ((item) ->source_type==NO_SOURCE) 
#define Item_has_Token_Source(item) ((item) ->source_type==SOURCE_IS_TOKEN) 
#define Item_has_Leo_Token_Source(item) ((item) ->source_type==SOURCE_IS_LEO_TOKEN) 
#define Item_has_Completed_Source(item) ((item) ->source_type==SOURCE_IS_COMPLETION) 
#define Item_has_Leo_Completed_Source(item) ((item) ->source_type==SOURCE_IS_LEO_COMPLETION) 
#define Item_is_Ambiguous(item) ((item) ->source_type==SOURCE_IS_AMBIGUOUS) 
#define Earley_Item_of_Postdot_Item(postdot) ((postdot) ->earley.earley_item)  \

#define Symbol_ID_of_Postdot_Item(postdot) ((postdot) ->earley.postdot_symbol_id)  \

#define Next_Link_of_Source_Link(link) ((link) ->next) 
#define Predecessor_of_Earley_Item(item) ((item) ->sourcing.brief.predecessor) 
#define Predecessor_of_Source_Link(link) (((struct brief_source_link*) (link) ) ->source.predecessor) 
#define Token_ID_of_Earley_Item(item) ((item) ->sourcing.full.token_id) 
#define Token_ID_of_Source_Link(link) (((struct full_source_link*) (link) ) ->token_id) 
#define Cause_of_Earley_Item(item) ((item) ->sourcing.brief.cause) 
#define Cause_of_Source_Link(link) (((struct brief_source_link*) (link) ) ->source.cause) 
#define First_Completion_Link_of_Earley_Item(item) ((item) ->sourcing.ambiguous.completion) 
#define First_Token_Link_of_Earley_Item(item) ((item) ->sourcing.ambiguous.token) 
#define First_Leo_Link_of_Earley_Item(item) ((item) ->sourcing.ambiguous.leo)  \

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

#define obstack_chunk_alloc g_malloc
#define obstack_chunk_free g_free \


#line 6919 "./marpa.w"

#include "marpa_obs.h"
/*815:*/
#line 6777 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:815*/
#line 6921 "./marpa.w"

/*606:*/
#line 4820 "./marpa.w"
struct earley_set;
/*:606*//*660:*/
#line 5332 "./marpa.w"
union source_link;
/*:660*/
#line 6922 "./marpa.w"

/*714:*/
#line 5889 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:714*//*761:*/
#line 6297 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:761*/
#line 6923 "./marpa.w"

/*21:*/
#line 395 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:21*//*42:*/
#line 544 "./marpa.w"
static gint next_grammar_id= 1;
/*:42*//*556:*/
#line 4603 "./marpa.w"
static gint next_recce_id= 1;
/*:556*//*715:*/
#line 5896 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:715*/
#line 6924 "./marpa.w"

/*34:*/
#line 509 "./marpa.w"
struct marpa_g{
/*46:*/
#line 557 "./marpa.w"
GArray*symbols;
/*:46*//*56:*/
#line 606 "./marpa.w"
GArray*rules;
/*:56*//*94:*/
#line 789 "./marpa.w"
GHashTable*context;
/*:94*//*109:*/
#line 874 "./marpa.w"
struct obstack obs;
/*:109*//*113:*/
#line 890 "./marpa.w"
Marpa_Error_ID error;
/*:113*//*194:*/
#line 1295 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
gpointer symbol_callback_arg;
/*:194*//*305:*/
#line 2016 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
gpointer rule_callback_arg;
/*:305*//*428:*/
#line 3222 "./marpa.w"

struct AHFA_item*AHFA_items;
struct AHFA_item**AHFA_items_by_rule;
/*:428*//*469:*/
#line 3537 "./marpa.w"
struct AHFA_state*AHFA;
/*:469*//*819:*/
#line 6819 "./marpa.w"

Marpa_G_Message_Callback*message_callback;
gpointer message_callback_arg;
/*:819*/
#line 510 "./marpa.w"

/*40:*/
#line 542 "./marpa.w"
int id;
/*:40*//*68:*/
#line 665 "./marpa.w"
Marpa_Symbol_ID start_symbol_id;
/*:68*//*75:*/
#line 712 "./marpa.w"
int size;
/*:75*//*78:*/
#line 725 "./marpa.w"
guint max_rule_length;
/*:78*//*429:*/
#line 3225 "./marpa.w"

guint no_of_items;
/*:429*//*470:*/
#line 3538 "./marpa.w"
gint AHFA_len;
/*:470*/
#line 511 "./marpa.w"

/*80:*/
#line 730 "./marpa.w"
unsigned int is_precomputed:1;
/*:80*//*84:*/
#line 741 "./marpa.w"
unsigned int has_loop:1;
/*:84*//*88:*/
#line 756 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:88*/
#line 512 "./marpa.w"

};

/*:34*//*119:*/
#line 908 "./marpa.w"

struct symbol{
/*127:*/
#line 958 "./marpa.w"
GArray*lhs;
/*:127*//*134:*/
#line 988 "./marpa.w"
GArray*rhs;
/*:134*//*181:*/
#line 1187 "./marpa.w"

struct symbol*alias;
/*:181*/
#line 910 "./marpa.w"

/*125:*/
#line 949 "./marpa.w"
Marpa_Symbol_ID id;
/*:125*/
#line 911 "./marpa.w"

/*141:*/
#line 1009 "./marpa.w"
unsigned int is_accessible:1;
/*:141*//*147:*/
#line 1035 "./marpa.w"
unsigned int is_counted:1;
/*:147*//*151:*/
#line 1053 "./marpa.w"
unsigned int is_nullable:1;
/*:151*//*157:*/
#line 1078 "./marpa.w"
unsigned int is_nulling:1;
/*:157*//*163:*/
#line 1105 "./marpa.w"
unsigned int is_terminal:1;
/*:163*//*169:*/
#line 1133 "./marpa.w"
unsigned int is_productive:1;
/*:169*//*175:*/
#line 1158 "./marpa.w"
unsigned int is_start:1;
/*:175*//*180:*/
#line 1184 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:180*/
#line 912 "./marpa.w"

};

/*:119*//*201:*/
#line 1325 "./marpa.w"

struct marpa_rule{
/*234:*/
#line 1706 "./marpa.w"
guint length;
/*:234*//*254:*/
#line 1776 "./marpa.w"
Marpa_Rule_ID id;
/*:254*//*295:*/
#line 1978 "./marpa.w"
gint virtual_start;
/*:295*//*299:*/
#line 1994 "./marpa.w"
gint virtual_end;
/*:299*//*316:*/
#line 2051 "./marpa.w"
Marpa_Rule_ID original;
/*:316*//*321:*/
#line 2065 "./marpa.w"
guint real_symbol_count;
/*:321*/
#line 1327 "./marpa.w"

/*257:*/
#line 1788 "./marpa.w"
unsigned int is_discard:1;
/*:257*//*271:*/
#line 1872 "./marpa.w"
unsigned int is_loop:1;
/*:271*//*276:*/
#line 1893 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:276*//*283:*/
#line 1923 "./marpa.w"
unsigned int is_used:1;
/*:283*//*287:*/
#line 1953 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:287*//*291:*/
#line 1964 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:291*//*325:*/
#line 2074 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:325*/
#line 1328 "./marpa.w"

/*235:*/
#line 1709 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:235*/
#line 1329 "./marpa.w"

};
/*:201*//*427:*/
#line 3210 "./marpa.w"

struct AHFA_item{
Marpa_AHFA_Item_ID sort_key;
struct marpa_rule*rule;
/*436:*/
#line 3247 "./marpa.w"
Marpa_Symbol_ID postdot;

/*:436*/
#line 3214 "./marpa.w"

gint position;
};
/*:427*//*468:*/
#line 3520 "./marpa.w"

struct AHFA_state_key{
Marpa_AHFA_State_ID id;
};
struct AHFA_state{
struct AHFA_state_key key;
struct AHFA_item**items;
struct AHFA_state*empty_transition;
GSequence*transitions;
Marpa_Symbol_ID*completed_symbols;
/*481:*/
#line 3592 "./marpa.w"
Marpa_Symbol_ID*postdot_symbols;
/*:481*/
#line 3530 "./marpa.w"

/*482:*/
#line 3593 "./marpa.w"
guint no_of_postdot_symbols;

/*:482*/
#line 3531 "./marpa.w"

guint item_count;
guint no_of_completed_symbols;
unsigned int is_predict:1;
unsigned int is_leo_completion:1;
};
/*:468*//*542:*/
#line 4520 "./marpa.w"

struct AHFA_transition_key{
Marpa_Symbol_ID symbol_id;
};
struct AHFA_transition{
struct AHFA_transition_key key;
struct AHFA_state*to_state;
};

/*:542*//*548:*/
#line 4556 "./marpa.w"
struct marpa_r{
/*561:*/
#line 4614 "./marpa.w"
const struct marpa_g*grammar;

/*:561*//*564:*/
#line 4638 "./marpa.w"

GSequence*earley_sets;
GSequenceIter*current_iter;
/*:564*//*581:*/
#line 4712 "./marpa.w"
GHashTable*context;
/*:581*//*592:*/
#line 4767 "./marpa.w"
struct obstack obs;
/*:592*//*596:*/
#line 4781 "./marpa.w"
Marpa_Error_ID error;
/*:596*//*827:*/
#line 6854 "./marpa.w"

Marpa_R_Message_Callback*message_callback;
gpointer message_callback_arg;
/*:827*/
#line 4557 "./marpa.w"

/*554:*/
#line 4601 "./marpa.w"
int id;
/*:554*//*562:*/
#line 4617 "./marpa.w"

enum{
no_such_phase= 0,
initial_phase,
active_phase,
exhausted_phase,
finished_phase,
error_phase
}phase;
/*:562*//*567:*/
#line 4648 "./marpa.w"
guint earley_item_warning_threshold;
/*:567*//*573:*/
#line 4676 "./marpa.w"
Marpa_Earleme furthest_earleme;
/*:573*/
#line 4558 "./marpa.w"

/*575:*/
#line 4681 "./marpa.w"
unsigned int is_trace_earley_sets:1;
/*:575*/
#line 4559 "./marpa.w"

};

/*:548*//*607:*/
#line 4821 "./marpa.w"

struct earley_set_key{
Marpa_Earleme id;
};
struct earley_set{
struct earley_set_key key;
GSequence*earley_items;
GSequence*postdot;
/*617:*/
#line 4918 "./marpa.w"
guint earley_item_count;
/*:617*/
#line 4829 "./marpa.w"

};

/*:607*//*645:*/
#line 5177 "./marpa.w"

struct leo_item;
struct earley_ix{
Marpa_Symbol_ID postdot_symbol_id;
struct earley_item*earley_item;
};
struct leo_item{
struct earley_ix earley_ix;
struct earley_set*origin;
struct AHFA*top_to_state;
struct leo_item*predecessor;
struct earley_item*base;
struct earley_set*set;
};

/*:645*//*646:*/
#line 5196 "./marpa.w"

union postdot_item{
struct leo_item leo;
struct earley_ix earley;
};
/*:646*//*785:*/
#line 6500 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:785*//*788:*/
#line 6531 "./marpa.w"

struct dqueue{gint current;struct dstack s;};

/*:788*/
#line 6925 "./marpa.w"

/*661:*/
#line 5333 "./marpa.w"

struct brief_source{
void*predecessor;
void*cause;
};
struct full_source{
struct brief_source links;
Marpa_Symbol_ID token_id;
};
struct brief_source_link{
union source_link*next;
struct brief_source source;
};
struct full_source_link{
union source_link*next;
struct full_source source;
};
union source_link{
union source_link*next;
struct brief_source_link brief;
struct full_source_link full;
};
struct ambiguous_source{
struct full_source_link*leo;
struct full_source_link*token;
struct brief_source_link*completion;
};
union sourcing{
struct ambiguous_source ambiguous;
struct brief_source brief;
struct full_source full;
};

/*:661*/
#line 6926 "./marpa.w"

/*623:*/
#line 4955 "./marpa.w"

struct earley_item_key{
struct AHFA_state*state;
struct earley_set*origin;
};
struct earley_item{
struct earley_item_key key;
struct earley_set*set;
union sourcing sourcing;
/*638:*/
#line 5090 "./marpa.w"

unsigned int source_type:3;

/*:638*/
#line 4964 "./marpa.w"

};
/*:623*/
#line 6927 "./marpa.w"

/*55:*/
#line 598 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:55*//*62:*/
#line 628 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g);

/*:62*//*64:*/
#line 636 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id);

/*:64*//*67:*/
#line 660 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:67*//*102:*/
#line 840 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:102*//*104:*/
#line 852 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:104*//*106:*/
#line 861 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g);

/*:106*//*121:*/
#line 936 "./marpa.w"

static inline
struct symbol*symbol_new(struct marpa_g*g);
/*:121*//*124:*/
#line 945 "./marpa.w"

static inline void symbol_free(struct symbol*symbol);

/*:124*//*133:*/
#line 979 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id);

/*:133*//*140:*/
#line 1005 "./marpa.w"
static inline
void symbol_rhs_add(struct symbol*symbol,Marpa_Rule_ID rule_id);

/*:140*//*178:*/
#line 1171 "./marpa.w"

static inline
gint symbol_is_start(struct symbol*symbol);
/*:178*//*184:*/
#line 1212 "./marpa.w"

static inline struct symbol*symbol_proper_alias(struct symbol*symbol);
/*:184*//*187:*/
#line 1240 "./marpa.w"

static inline struct symbol*symbol_null_alias(struct symbol*symbol);
/*:187*//*190:*/
#line 1279 "./marpa.w"

static inline
struct symbol*symbol_alias_create(struct marpa_g*g,
struct symbol*symbol);
/*:190*//*199:*/
#line 1319 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:199*//*203:*/
#line 1335 "./marpa.w"

static inline guint rule_sizeof(guint length);

/*:203*//*207:*/
#line 1359 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:207*//*224:*/
#line 1578 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length);

/*:224*//*233:*/
#line 1698 "./marpa.w"

static inline void rule_free(struct marpa_rule*rule);

/*:233*//*239:*/
#line 1723 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:239*//*243:*/
#line 1735 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:243*//*247:*/
#line 1751 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:247*//*253:*/
#line 1770 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,guint rh_index);

/*:253*//*264:*/
#line 1837 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule);
/*:264*//*268:*/
#line 1861 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule);
/*:268*//*282:*/
#line 1919 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule);

/*:282*//*314:*/
#line 2044 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:314*//*333:*/
#line 2181 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:333*//*370:*/
#line 2526 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:370*//*409:*/
#line 2893 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:409*//*412:*/
#line 2914 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:412*//*420:*/
#line 3031 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:420*//*449:*/
#line 3311 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:449*//*451:*/
#line 3338 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:451*//*458:*/
#line 3405 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:458*//*477:*/
#line 3570 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id);

/*:477*//*480:*/
#line 3585 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix);

/*:480*//*509:*/
#line 3832 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);

/*:509*//*511:*/
#line 3864 "./marpa.w"

static void create_AHFA_states(struct marpa_g*g);

/*:511*//*523:*/
#line 4195 "./marpa.w"

static inline struct AHFA_state*assign_AHFA_state(
struct AHFA_state*state_p,GSequence*duplicates);

/*:523*//*535:*/
#line 4364 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:535*//*539:*/
#line 4472 "./marpa.w"

static struct AHFA_state*
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
struct marpa_rule**rule_by_sort_key,
struct dqueue*states_p,
GSequence*duplicates
);

/*:539*//*544:*/
#line 4538 "./marpa.w"
static
gint AHFA_transition_cmp(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:544*//*546:*/
#line 4550 "./marpa.w"
static inline void
AHFA_transition_add(struct marpa_g*g,
struct AHFA_state*from,Marpa_Symbol_ID symbol,struct AHFA_state*to);

/*:546*//*585:*/
#line 4733 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint value);
/*:585*//*587:*/
#line 4745 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*value);

/*:587*//*589:*/
#line 4754 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r);

/*:589*//*609:*/
#line 4859 "./marpa.w"

static inline struct earley_set*earley_set_new(struct marpa_r*r,
Marpa_Earleme id);
static inline GSequenceIter*earley_set_assign(struct marpa_r*r,
Marpa_Earleme id);

/*:609*//*611:*/
#line 4873 "./marpa.w"

static inline void earley_set_free(gpointer p);

/*:611*//*613:*/
#line 4888 "./marpa.w"

static gint earley_set_cmp(gconstpointer a,gconstpointer b,gpointer user_data G_GNUC_UNUSED);

/*:613*//*616:*/
#line 4911 "./marpa.w"

static inline struct earley_set*earley_set_by_id(struct marpa_r*r,Marpa_Earleme earleme);

/*:616*//*625:*/
#line 4982 "./marpa.w"

static inline struct earley_item*earley_item_new(struct marpa_r*r,
struct earley_set*set,struct earley_item_key key);
/*:625*//*627:*/
#line 4995 "./marpa.w"

static inline struct earley_item*earley_item_assign(struct marpa_r*r,
struct earley_set*set,
struct earley_set*origin,
struct AHFA_state*state);
/*:627*//*629:*/
#line 5028 "./marpa.w"

static inline struct earley_item*earley_item_assign_by_key(struct marpa_r*r,
struct earley_set*set,
struct earley_item_key
key);

/*:629*//*634:*/
#line 5060 "./marpa.w"

static gint own_earley_item_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);
static inline gint earley_item_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);

/*:634*//*649:*/
#line 5232 "./marpa.w"
static gint
postdot_item_cmp(gconstpointer ap,gconstpointer bp,
gpointer user_data G_GNUC_UNUSED);

/*:649*//*664:*/
#line 5405 "./marpa.w"
static inline void
token_link_add(struct marpa_r*r,
struct earley_item*item,
struct earley_item*predecessor,
gpointer value,Marpa_Symbol_ID token_id);

/*:664*//*667:*/
#line 5448 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,struct earley_item*item);

/*:667*//*693:*/
#line 5692 "./marpa.w"

static inline GSequenceIter*earley_iter_later_assign(
struct marpa_r*r,Marpa_Earleme sought_earleme,
struct earley_set**set_p);

/*:693*//*709:*/
#line 5841 "./marpa.w"

static inline GSequenceIter*first_postdot_item_find(struct earley_set*set,
Marpa_Symbol_ID
symbol_id);
static gint postdot_symbol_cmp(gconstpointer ap,gconstpointer bp,
gpointer user_data G_GNUC_UNUSED);

/*:709*//*717:*/
#line 5909 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:717*//*719:*/
#line 5919 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:719*//*721:*/
#line 5939 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);

/*:721*//*723:*/
#line 5950 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:723*//*725:*/
#line 5972 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:725*//*727:*/
#line 5982 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:727*//*729:*/
#line 5990 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:729*//*731:*/
#line 6003 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:731*//*734:*/
#line 6011 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:734*//*736:*/
#line 6019 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:736*//*738:*/
#line 6027 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:738*//*741:*/
#line 6044 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:741*//*743:*/
#line 6057 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:743*//*745:*/
#line 6069 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:745*//*747:*/
#line 6081 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:747*//*749:*/
#line 6093 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:749*//*751:*/
#line 6167 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:751*//*753:*/
#line 6185 "./marpa.w"

static inline guint bv_count(Bit_Vector v);

/*:753*//*759:*/
#line 6274 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:759*//*764:*/
#line 6321 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:764*//*766:*/
#line 6329 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:766*//*768:*/
#line 6343 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:768*//*770:*/
#line 6361 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:770*//*773:*/
#line 6370 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:773*//*776:*/
#line 6379 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:776*//*779:*/
#line 6388 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:779*//*781:*/
#line 6441 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:781*//*787:*/
#line 6508 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:787*//*792:*/
#line 6572 "./marpa.w"

static inline GSequenceIter*sequence_find(GSequence*sequence,void*key,
GCompareDataFunc compare,gboolean*match);

/*:792*//*824:*/
#line 6846 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id);

/*:824*//*832:*/
#line 6875 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id);

/*:832*/
#line 6928 "./marpa.w"

/*53:*/
#line 582 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symbol_id,
struct symbol*symbol)
{
g_array_insert_val(g->symbols,(unsigned)symbol_id,symbol);
}

/*:53*//*65:*/
#line 642 "./marpa.w"

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

/*:65*/
#line 6929 "./marpa.w"

/*22:*/
#line 402 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:22*//*35:*/
#line 515 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*43:*/
#line 545 "./marpa.w"

g->id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:43*//*47:*/
#line 558 "./marpa.w"

g->symbols= g_array_new(FALSE,FALSE,sizeof(struct symbol*));
/*:47*//*57:*/
#line 607 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(struct marpa_rule*));
/*:57*//*69:*/
#line 666 "./marpa.w"

g->start_symbol_id= -1;
/*:69*//*76:*/
#line 713 "./marpa.w"

g->size= 0;

/*:76*//*79:*/
#line 726 "./marpa.w"

g->max_rule_length= 0;

/*:79*//*81:*/
#line 731 "./marpa.w"

g->is_precomputed= FALSE;
/*:81*//*85:*/
#line 742 "./marpa.w"

g->has_loop= FALSE;
/*:85*//*89:*/
#line 757 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:89*//*95:*/
#line 790 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:95*//*110:*/
#line 875 "./marpa.w"
obstack_init(&g->obs);
/*:110*//*114:*/
#line 891 "./marpa.w"

g->error= NULL;
/*:114*//*195:*/
#line 1298 "./marpa.w"

g->symbol_callback_arg= NULL;
g->symbol_callback= NULL;
/*:195*//*306:*/
#line 2019 "./marpa.w"

g->rule_callback_arg= NULL;
g->rule_callback= NULL;
/*:306*//*431:*/
#line 3230 "./marpa.w"

g->AHFA_items= NULL;
g->AHFA_items_by_rule= NULL;
/*:431*//*471:*/
#line 3539 "./marpa.w"

g->AHFA= NULL;
g->AHFA_len= 0;
/*:471*//*820:*/
#line 6822 "./marpa.w"

g->message_callback_arg= NULL;
g->message_callback= NULL;
/*:820*/
#line 518 "./marpa.w"

return g;}
/*:35*//*37:*/
#line 523 "./marpa.w"

void marpa_g_free(struct marpa_g*g)
{/*48:*/
#line 560 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->symbols->len;id++)
{symbol_free(Symbol_by_ID(g,id));}}
g_array_free(g->symbols,TRUE);

/*:48*//*58:*/
#line 609 "./marpa.w"

{Marpa_Rule_ID id;for(id= 0;id<(Marpa_Rule_ID)g->rules->len;id++)
{rule_free(rule_id2p(g,id));}}
g_array_free(g->rules,TRUE);

/*:58*//*96:*/
#line 792 "./marpa.w"
g_hash_table_destroy(g->context);

/*:96*//*111:*/
#line 876 "./marpa.w"
obstack_free(&g->obs,NULL);

/*:111*//*432:*/
#line 3233 "./marpa.w"

if(g->AHFA_items){g_free(g->AHFA_items);};
if(g->AHFA_items_by_rule){g_free(g->AHFA_items_by_rule);};

/*:432*//*472:*/
#line 3543 "./marpa.w"
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

/*:472*/
#line 525 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:37*//*44:*/
#line 547 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->id;}
/*:44*//*49:*/
#line 568 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:49*//*54:*/
#line 593 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id){
return symbol_id>=0&&(guint)symbol_id<g->symbols->len;
}
/*:54*//*59:*/
#line 617 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:59*//*61:*/
#line 624 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g){
return g->rules->len;
}
/*:61*//*63:*/
#line 632 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id)
{return g_array_index(g->rules,struct marpa_rule*,id);}
/*:63*//*66:*/
#line 655 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_id>=0&&(guint)rule_id<g->rules->len;
}
/*:66*//*70:*/
#line 669 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->start_symbol_id;}
/*:70*//*72:*/
#line 676 "./marpa.w"

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
/*:72*//*82:*/
#line 734 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{return g->is_precomputed;}
/*:82*//*86:*/
#line 745 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->has_loop;}
/*:86*//*90:*/
#line 760 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:90*//*92:*/
#line 767 "./marpa.w"

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
/*:92*//*101:*/
#line 831 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:101*//*103:*/
#line 843 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:103*//*105:*/
#line 858 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:105*//*107:*/
#line 864 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:107*//*116:*/
#line 899 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g)
{return g->error?g->error:"unknown error";}
/*:116*//*120:*/
#line 915 "./marpa.w"

static inline struct symbol*
symbol_new(struct marpa_g*g)
{
struct symbol*symbol= g_malloc(sizeof(struct symbol));
/*126:*/
#line 950 "./marpa.w"
symbol->id= g->symbols->len;

/*:126*//*128:*/
#line 959 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:128*//*135:*/
#line 989 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:135*//*142:*/
#line 1010 "./marpa.w"

symbol->is_accessible= FALSE;
/*:142*//*148:*/
#line 1036 "./marpa.w"

symbol->is_counted= FALSE;
/*:148*//*152:*/
#line 1054 "./marpa.w"

symbol->is_nullable= FALSE;
/*:152*//*158:*/
#line 1079 "./marpa.w"

symbol->is_nulling= FALSE;
/*:158*//*164:*/
#line 1106 "./marpa.w"

symbol->is_terminal= FALSE;
/*:164*//*170:*/
#line 1134 "./marpa.w"

symbol->is_productive= FALSE;
/*:170*//*176:*/
#line 1159 "./marpa.w"
symbol->is_start= FALSE;
/*:176*//*182:*/
#line 1189 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:182*/
#line 920 "./marpa.w"

{
Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);
}
return symbol;
}

Marpa_Symbol_ID
marpa_symbol_new(struct marpa_g*g)
{
Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;
}

/*:120*//*123:*/
#line 942 "./marpa.w"

static inline void symbol_free(struct symbol*symbol)
{/*129:*/
#line 961 "./marpa.w"

g_array_free(symbol->lhs,TRUE);
/*:129*//*136:*/
#line 991 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:136*/
#line 944 "./marpa.w"
g_free(symbol);}
/*:123*//*130:*/
#line 966 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*803:*/
#line 6693 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:803*/
#line 968 "./marpa.w"

/*807:*/
#line 6708 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:807*/
#line 969 "./marpa.w"

return Symbol_by_ID(g,symbol_id)->lhs;}
/*:130*//*132:*/
#line 973 "./marpa.w"
static inline
void symbol_lhs_add(struct symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(Symbol_by_ID(g,symbol_id),rule_id);}
/*:132*//*137:*/
#line 995 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*803:*/
#line 6693 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:803*/
#line 997 "./marpa.w"

/*807:*/
#line 6708 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:807*/
#line 998 "./marpa.w"

return Symbol_by_ID(g,symbol_id)->rhs;}
/*:137*//*139:*/
#line 1002 "./marpa.w"
static inline
void symbol_rhs_add(struct symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
/*:139*//*143:*/
#line 1020 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return Symbol_by_ID(g,id)->is_accessible;}
/*:143*//*145:*/
#line 1026 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{Symbol_by_ID(g,id)->is_accessible= value;}
/*:145*//*149:*/
#line 1046 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return Symbol_by_ID(g,id)->is_counted;}
/*:149*//*153:*/
#line 1064 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return Symbol_by_ID(g,id)->is_nullable;}
/*:153*//*155:*/
#line 1070 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{Symbol_by_ID(g,id)->is_nullable= value;}
/*:155*//*159:*/
#line 1089 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1091 "./marpa.w"

/*807:*/
#line 6708 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:807*/
#line 1092 "./marpa.w"

return Symbol_by_ID(g,symbol_id)->is_nulling;}
/*:159*//*161:*/
#line 1097 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{Symbol_by_ID(g,id)->is_nulling= value;}
/*:161*//*165:*/
#line 1118 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return Symbol_is_Terminal_by_ID(g,id);}
/*:165*//*167:*/
#line 1124 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{Symbol_is_Terminal_by_ID(g,id)= value;}
/*:167*//*171:*/
#line 1144 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return Symbol_by_ID(g,id)->is_productive;}
/*:171*//*173:*/
#line 1150 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{Symbol_by_ID(g,id)->is_productive= value?1:0;}
/*:173*//*177:*/
#line 1162 "./marpa.w"

static inline
gint symbol_is_start(struct symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1167 "./marpa.w"

/*807:*/
#line 6708 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:807*/
#line 1168 "./marpa.w"

return symbol_is_start(Symbol_by_ID(g,symbol_id));
}
/*:177*//*183:*/
#line 1198 "./marpa.w"

static inline
struct symbol*symbol_proper_alias(struct symbol*symbol)
{return symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct symbol*symbol;
struct symbol*proper_alias;
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1206 "./marpa.w"

/*807:*/
#line 6708 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:807*/
#line 1207 "./marpa.w"

symbol= Symbol_by_ID(g,symbol_id);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->id;
}
/*:183*//*186:*/
#line 1221 "./marpa.w"

static inline
struct symbol*symbol_null_alias(struct symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct symbol*symbol;
struct symbol*alias;
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1229 "./marpa.w"

/*807:*/
#line 6708 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:807*/
#line 1230 "./marpa.w"

symbol= Symbol_by_ID(g,symbol_id);
alias= symbol_null_alias(symbol);
if(alias==NULL){
g_context_int_add(g,"symbol_id",symbol_id);
g->error= "no alias";
return-1;
}
return alias->id;
}
/*:186*//*189:*/
#line 1254 "./marpa.w"
static inline
struct symbol*symbol_alias_create(struct marpa_g*g,
struct symbol*symbol)
{
struct symbol*alias= symbol_new(g);
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
alias_id= symbol_alias_create(g,Symbol_by_ID(g,original_id))->id;
symbol_callback(g,alias_id);
return alias_id;}
/*:189*//*196:*/
#line 1301 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->symbol_callback_arg= cb_arg;}
gpointer marpa_symbol_callback_arg(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:196*//*198:*/
#line 1315 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:198*//*202:*/
#line 1331 "./marpa.w"

static inline guint rule_sizeof(guint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:202*//*206:*/
#line 1345 "./marpa.w"

static
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
struct marpa_rule*rule;
/*236:*/
#line 1710 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{guint rh_index;for(rh_index= 0;rh_index<length;rh_index++){
if(!symbol_is_valid(g,rhs[rh_index])){return NULL;}
}}
/*:236*/
#line 1351 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*237:*/
#line 1715 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{guint i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:237*/
#line 1353 "./marpa.w"

/*255:*/
#line 1777 "./marpa.w"
rule->id= g->rules->len;

/*:255*//*258:*/
#line 1789 "./marpa.w"

rule->is_discard= FALSE;
/*:258*//*272:*/
#line 1873 "./marpa.w"

rule->is_loop= FALSE;
/*:272*//*277:*/
#line 1894 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:277*//*284:*/
#line 1924 "./marpa.w"

rule->is_used= TRUE;
/*:284*//*288:*/
#line 1954 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:288*//*292:*/
#line 1965 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:292*//*296:*/
#line 1979 "./marpa.w"
rule->virtual_start= -1;
/*:296*//*300:*/
#line 1995 "./marpa.w"
rule->virtual_end= -1;
/*:300*//*317:*/
#line 2052 "./marpa.w"
rule->original= -1;
/*:317*//*322:*/
#line 2066 "./marpa.w"
rule->real_symbol_count= 0;
/*:322*//*326:*/
#line 2075 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:326*/
#line 1354 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*226:*/
#line 1595 "./marpa.w"

symbol_lhs_add(Symbol_by_ID(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const guint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*230:*/
#line 1662 "./marpa.w"

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

/*:230*/
#line 1603 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
Symbol_by_ID(g,rh_symbol_list[rh_list_ix]),
rule->id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:226*/
#line 1356 "./marpa.w"

return rule;
}
/*:206*//*208:*/
#line 1364 "./marpa.w"

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

/*:208*//*209:*/
#line 1381 "./marpa.w"

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

/*212:*/
#line 1416 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*211:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:211*/
#line 1418 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:212*/
#line 1394 "./marpa.w"

/*213:*/
#line 1422 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:213*/
#line 1395 "./marpa.w"

/*214:*/
#line 1426 "./marpa.w"

Symbol_by_ID(g,rhs_id)->is_counted= 1;
if(separator_id>=0){Symbol_by_ID(g,separator_id)->is_counted= 1;}
/*:214*/
#line 1396 "./marpa.w"

if(min==0){/*215:*/
#line 1429 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*211:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:211*/
#line 1431 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:215*/
#line 1397 "./marpa.w"
}
min= 1;
/*216:*/
#line 1436 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:216*/
#line 1399 "./marpa.w"

/*217:*/
#line 1450 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:217*/
#line 1400 "./marpa.w"

/*219:*/
#line 1453 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*211:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:211*/
#line 1457 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:219*/
#line 1401 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*220:*/
#line 1466 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*211:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:211*/
#line 1471 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:220*/
#line 1403 "./marpa.w"

}
/*221:*/
#line 1483 "./marpa.w"

{struct marpa_rule*rule;
guint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*211:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:211*/
#line 1493 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:221*/
#line 1405 "./marpa.w"

/*222:*/
#line 1498 "./marpa.w"

{struct marpa_rule*rule;
guint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*211:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:211*/
#line 1505 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:222*/
#line 1406 "./marpa.w"

/*218:*/
#line 1452 "./marpa.w"
g_free(temp_rhs);
/*:218*/
#line 1407 "./marpa.w"

return original_rule_id;
}
/*:209*//*223:*/
#line 1554 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length)
{
guint ix;
struct symbol*lhs= Symbol_by_ID(g,lhs_id);
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
/*:223*//*232:*/
#line 1694 "./marpa.w"

static inline void rule_free(struct marpa_rule*rule)
{
g_free(rule);}
/*:232*//*238:*/
#line 1720 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
/*:238*//*240:*/
#line 1725 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1727 "./marpa.w"

/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 1728 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:240*//*242:*/
#line 1732 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:242*//*244:*/
#line 1737 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix){
struct marpa_rule*rule;
/*805:*/
#line 6697 "./marpa.w"
const int failure_indicator= -2;

/*:805*/
#line 1740 "./marpa.w"

/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 1741 "./marpa.w"

rule= rule_id2p(g,rule_id);
if(rule->length<=ix)return-1;
return rhs_symbol_id(rule,ix);
}
/*:244*//*246:*/
#line 1748 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:246*//*248:*/
#line 1753 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1755 "./marpa.w"

/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 1756 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:248*//*252:*/
#line 1765 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,guint rh_index){
return rule->symbols[rh_index+1];
}
/*:252*//*259:*/
#line 1791 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:259*//*263:*/
#line 1824 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule)
{
Marpa_Symbol_ID lhs_id= LHS_Symbol_ID_of_Rule(rule);
return Symbol_by_ID(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1831 "./marpa.w"

struct marpa_rule*rule;
/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 1833 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:263*//*267:*/
#line 1844 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!Symbol_by_ID(g,rhs_id)->is_productive)return FALSE;
}
return TRUE;}
gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1855 "./marpa.w"

struct marpa_rule*rule;
/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 1857 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:267*//*273:*/
#line 1877 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1880 "./marpa.w"

/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 1881 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:273*//*278:*/
#line 1898 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1901 "./marpa.w"

/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 1902 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:278*//*281:*/
#line 1910 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!Symbol_by_ID(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:281*//*285:*/
#line 1928 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 1931 "./marpa.w"

/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 1932 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:285*//*289:*/
#line 1957 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:289*//*293:*/
#line 1968 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:293*//*297:*/
#line 1980 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*805:*/
#line 6697 "./marpa.w"
const int failure_indicator= -2;

/*:805*/
#line 1983 "./marpa.w"

/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 1984 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_start;
}
/*:297*//*301:*/
#line 1996 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*805:*/
#line 6697 "./marpa.w"
const int failure_indicator= -2;

/*:805*/
#line 1999 "./marpa.w"

/*808:*/
#line 6715 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:808*/
#line 2000 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_end;
}
/*:301*//*307:*/
#line 2022 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:307*//*309:*/
#line 2027 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:309*//*311:*/
#line 2032 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:311*//*313:*/
#line 2040 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:313*//*318:*/
#line 2053 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}
/*:318*//*323:*/
#line 2067 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}
/*:323*//*327:*/
#line 2086 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:327*//*329:*/
#line 2105 "./marpa.w"

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
/*:329*//*332:*/
#line 2151 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*334:*/
#line 2183 "./marpa.w"

guint pre_rewrite_rule_count= g->rules->len;
guint pre_rewrite_symbol_count= g->symbols->len;

/*:334*//*339:*/
#line 2216 "./marpa.w"

Marpa_Symbol_ID original_start_symbol_id= g->start_symbol_id;
struct symbol*original_start_symbol;

/*:339*//*343:*/
#line 2253 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:343*//*349:*/
#line 2312 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:349*//*351:*/
#line 2339 "./marpa.w"

Bit_Vector nullable_v;
/*:351*//*355:*/
#line 2365 "./marpa.w"

Bit_Vector productive_v;
/*:355*//*358:*/
#line 2406 "./marpa.w"
Bit_Matrix reach_matrix;
/*:358*//*361:*/
#line 2424 "./marpa.w"

Bit_Vector accessible_v;

/*:361*/
#line 2154 "./marpa.w"

/*335:*/
#line 2187 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:335*/
#line 2155 "./marpa.w"

/*336:*/
#line 2194 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:336*/
#line 2156 "./marpa.w"

/*338:*/
#line 2200 "./marpa.w"

if(original_start_symbol_id<0){
g->error= "no start symbol";
return NULL;
}
if(!symbol_is_valid(g,original_start_symbol_id)){
g_context_int_add(g,"symbol_id",original_start_symbol_id);
g->error= "invalid start symbol";
return NULL;
}
original_start_symbol= Symbol_by_ID(g,original_start_symbol_id);
if(original_start_symbol->lhs->len<=0){
g_context_int_add(g,"symbol_id",original_start_symbol_id);
g->error= "start symbol not on LHS";
return NULL;
}
/*:338*/
#line 2157 "./marpa.w"

/*340:*/
#line 2220 "./marpa.w"

{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;
rule_id<(Marpa_Rule_ID)pre_rewrite_rule_count;
rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_Symbol_ID_of_Rule(rule);
bv_bit_set(lhs_v,(guint)lhs_id);
if(rule->length<=0){
bv_bit_set(empty_lhs_v,(guint)lhs_id);
have_empty_rule= 1;
}
}
}
/*:340*/
#line 2158 "./marpa.w"

/*341:*/
#line 2239 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symbol_id= 0;
symbol_id<(Marpa_Symbol_ID)pre_rewrite_symbol_count;
symbol_id++){
struct symbol*symbol= Symbol_by_ID(g,symbol_id);
if(Symbol_is_Terminal(symbol)){
bv_bit_set(terminal_v,(guint)symbol_id);
have_marked_terminals= 1;
}
}}
/*:341*/
#line 2159 "./marpa.w"

if(have_marked_terminals){
/*345:*/
#line 2268 "./marpa.w"

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
grammar_message(g,"lhs is terminal");
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

/*:345*/
#line 2161 "./marpa.w"

}else{
/*344:*/
#line 2257 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:344*/
#line 2163 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*346:*/
#line 2292 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<(Marpa_Symbol_ID)g->symbols->len;symbol_id++)
{Symbol_is_Terminal_by_ID(g,symbol_id)= 1;}}
/*:346*/
#line 2165 "./marpa.w"

}else{
/*347:*/
#line 2297 "./marpa.w"

{guint start= 0;
guint min,max;
bv_not(terminal_v,lhs_v);
while(bv_scan(terminal_v,start,&min,&max)){
Marpa_Symbol_ID symbol_id;
for(symbol_id= (Marpa_Symbol_ID)min;symbol_id<=(Marpa_Symbol_ID)max;symbol_id++){
Symbol_is_Terminal_by_ID(g,symbol_id)= 1;
}
start= max+2;
}
}
/*:347*/
#line 2167 "./marpa.w"

}
}
/*350:*/
#line 2317 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{guint min,max,start;
Marpa_Symbol_ID symbol_id;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symbol_id= (Marpa_Symbol_ID)min;symbol_id<=(Marpa_Symbol_ID)max;symbol_id++){
struct symbol*symbol= Symbol_by_ID(g,symbol_id);
if(symbol->is_counted){
g_context_clear(g);
g_context_int_add(g,"symbol_id",symbol_id);
grammar_message(g,"counted nullable");
counted_nullables++;
}
symbol->is_nullable= 1;
}}
if(counted_nullables){
g->error= "counted nullable";
return NULL;
}
}
/*:350*/
#line 2170 "./marpa.w"

/*353:*/
#line 2344 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{guint min,max,start;
Marpa_Symbol_ID symbol_id;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symbol_id= (Marpa_Symbol_ID)min;
symbol_id<=(Marpa_Symbol_ID)max;
symbol_id++){
struct symbol*symbol= Symbol_by_ID(g,symbol_id);
symbol->is_productive= 1;
}}
}
/*:353*/
#line 2171 "./marpa.w"

/*354:*/
#line 2358 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->start_symbol_id))
{
g_context_int_add(g,"symbol_id",g->start_symbol_id);
g->error= "unproductive start symbol";
return NULL;
}
/*:354*/
#line 2172 "./marpa.w"

/*357:*/
#line 2388 "./marpa.w"

reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{guint symbol_id,no_of_symbols= Symbol_Count_of_G(g);
for(symbol_id= 0;symbol_id<no_of_symbols;symbol_id++){
matrix_bit_set(reach_matrix,symbol_id,symbol_id);
}}
{Marpa_Rule_ID rule_id;
guint no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_Symbol_ID_of_Rule(rule);
guint rhs_ix,rule_length= rule->length;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,
(guint)lhs_id,(guint)rhs_symbol_id(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:357*/
#line 2173 "./marpa.w"

/*360:*/
#line 2410 "./marpa.w"

accessible_v= matrix_row(reach_matrix,(guint)original_start_symbol_id);
{guint min,max,start;
Marpa_Symbol_ID symbol_id;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symbol_id= (Marpa_Symbol_ID)min;
symbol_id<=(Marpa_Symbol_ID)max;
symbol_id++){
struct symbol*symbol= Symbol_by_ID(g,symbol_id);
symbol->is_accessible= 1;
}}
}
/*:360*/
#line 2174 "./marpa.w"

/*362:*/
#line 2429 "./marpa.w"

{
Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
guint min,max,start;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID productive_id;
for(productive_id= (Marpa_Symbol_ID)min;
productive_id<=(Marpa_Symbol_ID)max;productive_id++)
{
bv_and(reaches_terminal_v,terminal_v,
matrix_row(reach_matrix,(guint)productive_id));
if(bv_is_empty(reaches_terminal_v))
Symbol_by_ID(g,productive_id)->is_nulling= 1;
}
}
bv_free(reaches_terminal_v);
}

/*:362*/
#line 2175 "./marpa.w"

/*342:*/
#line 2251 "./marpa.w"

bv_free(terminal_v);
/*:342*//*348:*/
#line 2309 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:348*//*352:*/
#line 2341 "./marpa.w"

bv_free(nullable_v);

/*:352*//*356:*/
#line 2367 "./marpa.w"

bv_free(productive_v);

/*:356*/
#line 2176 "./marpa.w"

/*359:*/
#line 2407 "./marpa.w"

matrix_free(reach_matrix);

/*:359*/
#line 2177 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:332*//*369:*/
#line 2505 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*371:*/
#line 2528 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:371*//*375:*/
#line 2579 "./marpa.w"

guint factor_count;
guint*factor_positions;
/*:375*//*380:*/
#line 2628 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:380*/
#line 2508 "./marpa.w"

/*376:*/
#line 2582 "./marpa.w"

factor_positions= g_new(guint,g->max_rule_length);
/*:376*//*381:*/
#line 2631 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:381*/
#line 2509 "./marpa.w"

/*373:*/
#line 2540 "./marpa.w"

{gint no_of_symbols= Symbol_Count_of_G(g);
Marpa_Symbol_ID symbol_id;
for(symbol_id= 0;symbol_id<no_of_symbols;symbol_id++){
struct symbol*symbol= Symbol_by_ID(g,symbol_id);
struct symbol*alias;
if(!symbol->is_nullable)continue;
if(symbol->is_nulling)continue;
if(!symbol->is_accessible)continue;
if(!symbol->is_productive)continue;
if(symbol_null_alias(symbol))continue;
alias= symbol_alias_create(g,symbol);
symbol_callback(g,alias->id);
}}

/*:373*/
#line 2510 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
guint rule_length= rule->length;
guint nullable_suffix_ix= 0;
/*372:*/
#line 2532 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:372*/
#line 2516 "./marpa.w"

/*374:*/
#line 2563 "./marpa.w"

{guint rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symbol_id= rhs_symbol_id(rule,rhs_ix);
struct symbol*symbol= Symbol_by_ID(g,symbol_id);
if(symbol->is_nulling)continue;
if(symbol_null_alias(symbol)){

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}}
/*:374*/
#line 2517 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*378:*/
#line 2588 "./marpa.w"

rule->is_used= 0;
{guint unprocessed_factor_count;

guint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_Symbol_ID_of_Rule(rule);
guint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*384:*/
#line 2641 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symbol_id;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*379:*/
#line 2607 "./marpa.w"
{
struct symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",LHS_Symbol_ID_of_Rule(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:379*/
#line 2649 "./marpa.w"

/*385:*/
#line 2668 "./marpa.w"

{
guint remaining_rhs_length,piece_rhs_length;
/*386:*/
#line 2680 "./marpa.w"

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
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2692 "./marpa.w"

}

/*:386*/
#line 2671 "./marpa.w"
;
/*387:*/
#line 2695 "./marpa.w"

{guint chaf_rule_length= rule->length-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;
remaining_rhs_length++){
Marpa_Symbol_ID original_id= rhs_symbol_id(rule,piece_start+remaining_rhs_length);
struct symbol*alias= symbol_null_alias(Symbol_by_ID(g,original_id));
remaining_rhs[remaining_rhs_length]= alias?alias->id:original_id;
}}
{struct marpa_rule*chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2707 "./marpa.w"

}

/*:387*/
#line 2672 "./marpa.w"
;
/*388:*/
#line 2712 "./marpa.w"
{
Marpa_Symbol_ID proper_id= rhs_symbol_id(rule,first_factor_position);
struct symbol*alias= symbol_null_alias(Symbol_by_ID(g,proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
alias->id;
}
{struct marpa_rule*chaf_rule;
guint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2722 "./marpa.w"

}

/*:388*/
#line 2673 "./marpa.w"
;
/*389:*/
#line 2731 "./marpa.w"

if(piece_start<nullable_suffix_ix){
struct marpa_rule*chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2736 "./marpa.w"

}

/*:389*/
#line 2674 "./marpa.w"
;
}

/*:385*/
#line 2650 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*379:*/
#line 2607 "./marpa.w"
{
struct symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",LHS_Symbol_ID_of_Rule(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:379*/
#line 2655 "./marpa.w"

/*391:*/
#line 2741 "./marpa.w"
{
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:391*//*392:*/
#line 2750 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2756 "./marpa.w"


/*:392*//*393:*/
#line 2759 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2764 "./marpa.w"


/*:393*//*394:*/
#line 2767 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2773 "./marpa.w"


/*:394*//*395:*/
#line 2776 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2779 "./marpa.w"


/*:395*//*396:*/
#line 2782 "./marpa.w"
}

/*:396*/
#line 2656 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symbol_id;
piece_start= piece_end+1;

/*:384*/
#line 2599 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*397:*/
#line 2786 "./marpa.w"
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

/*:397*//*398:*/
#line 2800 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2805 "./marpa.w"


/*:398*//*399:*/
#line 2808 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2813 "./marpa.w"


/*:399*//*400:*/
#line 2816 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2822 "./marpa.w"


/*:400*//*401:*/
#line 2826 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2830 "./marpa.w"

}

/*:401*//*402:*/
#line 2834 "./marpa.w"
}

/*:402*/
#line 2602 "./marpa.w"

}else{
/*403:*/
#line 2837 "./marpa.w"
{
guint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
guint real_symbol_count;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:403*//*404:*/
#line 2848 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2853 "./marpa.w"


/*:404*//*405:*/
#line 2857 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*407:*/
#line 2873 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:407*/
#line 2863 "./marpa.w"

}

/*:405*//*406:*/
#line 2867 "./marpa.w"
}

/*:406*/
#line 2604 "./marpa.w"

}}

/*:378*/
#line 2520 "./marpa.w"

NEXT_RULE:;
}
/*377:*/
#line 2584 "./marpa.w"

g_free(factor_positions);

/*:377*//*382:*/
#line 2634 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:382*/
#line 2523 "./marpa.w"

return g;
}
/*:369*//*408:*/
#line 2887 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct symbol*alias= symbol_null_alias(Symbol_by_ID(g,proper_id));
return alias->id;
}
/*:408*//*411:*/
#line 2901 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct symbol*proper_old_start= NULL;
struct symbol*nulling_old_start= NULL;
struct symbol*proper_new_start= NULL;
struct symbol*old_start= Symbol_by_ID(g,g->start_symbol_id);
/*413:*/
#line 2917 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:413*/
#line 2909 "./marpa.w"

if(proper_old_start){/*414:*/
#line 2927 "./marpa.w"
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

/*:414*/
#line 2910 "./marpa.w"
}
if(nulling_old_start){/*415:*/
#line 2950 "./marpa.w"
{
Marpa_Symbol_ID nulling_new_start_id;
struct marpa_rule*new_start_rule;
struct symbol*nulling_new_start;
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

/*:415*/
#line 2911 "./marpa.w"
}
return g;
}
/*:411*//*419:*/
#line 3017 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{guint no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*421:*/
#line 3040 "./marpa.w"
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
struct symbol*symbol= Symbol_by_ID(g,symbol_id);
if(symbol->is_nullable)continue;
if(proper_id>=0)goto NEXT_RULE;

proper_id= symbol_id;
}

if(proper_id<0)continue;

{struct symbol*rhs_symbol= Symbol_by_ID(g,proper_id);
GArray*lhs_rules= rhs_symbol->lhs;
guint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,(guint)rule_id,
(guint)g_array_index(lhs_rules,Marpa_Rule_ID,ix));
}}
NEXT_RULE:;
}}

/*:421*/
#line 3024 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*422:*/
#line 3079 "./marpa.w"
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
grammar_message(g,"loop rule");
}}

/*:422*/
#line 3026 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*423:*/
#line 3100 "./marpa.w"

g_context_clear(g);
g_context_int_add(g,"loop_rule_count",loop_rule_count);
grammar_message(g,"loop rule tally");

/*:423*/
#line 3028 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:419*//*438:*/
#line 3253 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 3255 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3256 "./marpa.w"

return g->no_of_items;
}
/*:438*//*440:*/
#line 3262 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 3265 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3266 "./marpa.w"

/*809:*/
#line 6722 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:809*/
#line 3267 "./marpa.w"

return AHFA_Item_by_ID(g,item_id)->rule->id;
}
/*:440*//*442:*/
#line 3273 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*805:*/
#line 6697 "./marpa.w"
const int failure_indicator= -2;

/*:805*/
#line 3276 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3277 "./marpa.w"

/*809:*/
#line 6722 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:809*/
#line 3278 "./marpa.w"

return AHFA_Item_by_ID(g,item_id)->position;
}
/*:442*//*444:*/
#line 3284 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*805:*/
#line 6697 "./marpa.w"
const int failure_indicator= -2;

/*:805*/
#line 3287 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3288 "./marpa.w"

/*809:*/
#line 6722 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:809*/
#line 3289 "./marpa.w"

return AHFA_Item_by_ID(g,item_id)->postdot;
}
/*:444*//*446:*/
#line 3294 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 3297 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3298 "./marpa.w"

/*809:*/
#line 6722 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:809*/
#line 3299 "./marpa.w"

return AHFA_Item_by_ID(g,item_id)->sort_key;
}
/*:446*//*448:*/
#line 3306 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<(Marpa_AHFA_Item_ID)g->no_of_items&&item_id>=0;
}
/*:448*//*450:*/
#line 3321 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
Marpa_Rule_ID rule_id;
guint no_of_items;
guint no_of_rules= rule_count(g);
struct AHFA_item*base_item= g_new(struct AHFA_item,g->size);
struct AHFA_item*current_item= base_item;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
/*452:*/
#line 3341 "./marpa.w"

guint rhs_ix;
struct marpa_rule*rule= rule_id2p(g,rule_id);
if(!rule->is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->length;rhs_ix++){
/*453:*/
#line 3353 "./marpa.w"

Marpa_Symbol_ID rh_symbol_id= rhs_symbol_id(rule,rhs_ix);
struct symbol*symbol= Symbol_by_ID(g,rh_symbol_id);
if(symbol->is_nullable)goto NEXT_RH_SYMBOL;
current_item->sort_key= current_item-base_item;
current_item->postdot= rh_symbol_id;
current_item->rule= rule;
current_item->position= rhs_ix;

/*:453*/
#line 3346 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*454:*/
#line 3362 "./marpa.w"

current_item->sort_key= current_item-base_item;
current_item->postdot= current_item->position= -1;
current_item->rule= rule;

/*:454*/
#line 3350 "./marpa.w"

current_item++;

/*:452*/
#line 3330 "./marpa.w"

NEXT_RULE:;
}
no_of_items= g->no_of_items= current_item-base_item;
g->AHFA_items= g_renew(struct AHFA_item,base_item,no_of_items);
/*455:*/
#line 3372 "./marpa.w"
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

/*:455*/
#line 3335 "./marpa.w"

/*459:*/
#line 3408 "./marpa.w"
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

/*:459*/
#line 3336 "./marpa.w"

}
/*:450*//*457:*/
#line 3393 "./marpa.w"

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
/*:457*//*476:*/
#line 3565 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id){
return AHFA_state_id<g->AHFA_len&&AHFA_state_id>=0;
}
/*:476*//*479:*/
#line 3580 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const struct AHFA_state*state,guint item_ix){
return state->items[item_ix]-g->AHFA_items;
}
/*:479*//*483:*/
#line 3596 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return g->AHFA_len;
}
/*:483*//*485:*/
#line 3603 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 3606 "./marpa.w"

struct AHFA_state*state;
/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3608 "./marpa.w"

/*810:*/
#line 6729 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:810*/
#line 3609 "./marpa.w"

state= AHFA_State_of_G_by_ID(g,AHFA_state_id);
return state->item_count;
}
/*:485*//*487:*/
#line 3616 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
guint item_ix){
struct AHFA_state*state;
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 3621 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3622 "./marpa.w"

/*810:*/
#line 6729 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:810*/
#line 3623 "./marpa.w"

state= AHFA_State_of_G_by_ID(g,AHFA_state_id);
if(item_ix>=state->item_count){
g_context_clear(g);
g_context_int_add(g,"item_ix",(gint)item_ix);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid state item ix";
return failure_indicator;
}
return AHFA_state_item_ix2id(g,state,item_ix);
}
/*:487*//*489:*/
#line 3639 "./marpa.w"

gint
marpa_AHFA_state_transition_count(struct marpa_g*g,Marpa_AHFA_State_ID AHFA_state_id)
{/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 3642 "./marpa.w"

struct AHFA_state*state;
/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3644 "./marpa.w"

/*810:*/
#line 6729 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:810*/
#line 3645 "./marpa.w"

state= AHFA_State_of_G_by_ID(g,AHFA_state_id);
return g_sequence_get_length(state->transitions);
}
/*:489*//*495:*/
#line 3683 "./marpa.w"

static inline struct AHFA_state*
to_state_find(struct AHFA_state*state,Marpa_Symbol_ID symbol_id)
{
gboolean match= FALSE;
GSequenceIter*found_iter;
struct AHFA_transition_key key;
key.symbol_id= symbol_id;
found_iter= 
sequence_find(state->transitions,&key,AHFA_transition_cmp,&match);
if(!match)return NULL;
return To_State_of_AHFA_Transition((struct AHFA_transition*)
g_sequence_get(found_iter));
}
/*:495*//*498:*/
#line 3715 "./marpa.w"

struct marpa_AHFA_transition*marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
struct marpa_AHFA_transition*buffer){
GSequence*transitions;
GSequenceIter*iter;
GSequenceIter*end;
struct marpa_AHFA_transition*p_buffer= buffer;
/*803:*/
#line 6693 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:803*/
#line 3723 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3724 "./marpa.w"

/*810:*/
#line 6729 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:810*/
#line 3725 "./marpa.w"

transitions= AHFA_State_of_G_by_ID(g,AHFA_state_id)->transitions;
end= g_sequence_get_end_iter(transitions);
for(iter= g_sequence_get_begin_iter(transitions);
!g_sequence_iter_is_end(iter);
iter= g_sequence_iter_next(iter)){
struct AHFA_transition*internal= g_sequence_get(iter);
p_buffer->symbol= Symbol_ID_of_AHFA_Transition(internal);
p_buffer->to= To_State_ID_of_AHFA_Transition(internal);
p_buffer++;
}
return buffer;
}
/*:498*//*501:*/
#line 3747 "./marpa.w"

Marpa_AHFA_State_ID marpa_AHFA_state_empty_transition(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
struct AHFA_state*empty_transition_state;
/*805:*/
#line 6697 "./marpa.w"
const int failure_indicator= -2;

/*:805*/
#line 3752 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3753 "./marpa.w"

/*810:*/
#line 6729 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:810*/
#line 3754 "./marpa.w"

state= AHFA_State_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA_State(state);
if(empty_transition_state)
return ID_of_AHFA_State(empty_transition_state);
return-1;
}
/*:501*//*503:*/
#line 3765 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 3769 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3770 "./marpa.w"

/*810:*/
#line 6729 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:810*/
#line 3771 "./marpa.w"

state= AHFA_State_of_G_by_ID(g,AHFA_state_id);
return state->is_predict;
}
/*:503*//*505:*/
#line 3779 "./marpa.w"

gint marpa_AHFA_state_is_leo_completion(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
struct AHFA_state*state;
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 3783 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 3784 "./marpa.w"

/*810:*/
#line 6729 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}

/*:810*/
#line 3785 "./marpa.w"

state= AHFA_State_of_G_by_ID(g,AHFA_state_id);
return state->is_leo_completion;
}
/*:505*//*508:*/
#line 3809 "./marpa.w"

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
/*:508*//*510:*/
#line 3837 "./marpa.w"

static
void create_AHFA_states(struct marpa_g*g){
struct AHFA_state*p_working_state;
const guint initial_no_of_states= 2*g->size;
struct AHFA_item*AHFA_item_0_p= g->AHFA_items;
guint no_of_symbols= Symbol_Count_of_G(g);
guint no_of_rules= rule_count(g);
Bit_Matrix prediction_matrix;
struct marpa_rule**rule_by_sort_key= g_new(struct marpa_rule*,no_of_rules);
GSequence*duplicates;
struct AHFA_state**singleton_duplicates;
DQUEUE_DEFINE(states);
/*513:*/
#line 3899 "./marpa.w"
{guint item_id;
guint no_of_items_in_grammar= g->no_of_items;
duplicates= g_sequence_new(NULL);
singleton_duplicates= g_new(struct AHFA_state*,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++){
singleton_duplicates[item_id]= NULL;
}}
/*:513*/
#line 3850 "./marpa.w"

DQUEUE_INIT(states,struct AHFA_state,initial_no_of_states);
/*529:*/
#line 4256 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= matrix_create(no_of_symbols,no_of_symbols);
/*530:*/
#line 4264 "./marpa.w"

{Marpa_Rule_ID rule_id;
Marpa_Symbol_ID symbol_id;
struct AHFA_item**items_by_rule= g->AHFA_items_by_rule;
for(symbol_id= 0;symbol_id<(Marpa_Symbol_ID)no_of_symbols;symbol_id++){

struct symbol*symbol= Symbol_by_ID(g,symbol_id);
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
from= LHS_Symbol_ID_of_Rule(rule);
to= item->postdot;
if(to<0)continue;

matrix_bit_set(symbol_by_symbol_matrix,
(guint)from,(guint)to);
}}

/*:530*/
#line 4258 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*531:*/
#line 4296 "./marpa.w"
{
struct AHFA_item**items_by_rule= g->AHFA_items_by_rule;
Marpa_Symbol_ID from_symbol_id;
guint*sort_key_by_rule_id= g_new(guint,no_of_rules);
guint no_of_predictable_rules= 0;
/*532:*/
#line 4326 "./marpa.w"

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

/*:532*/
#line 4302 "./marpa.w"

/*533:*/
#line 4341 "./marpa.w"

{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
rule_by_sort_key[rule_id]= rule_id2p(g,rule_id);
}
g_qsort_with_data(rule_by_sort_key,(gint)no_of_rules,
sizeof(struct marpa_rule*),cmp_by_rule_sort_key,
(gpointer)sort_key_by_rule_id);
}

/*:533*/
#line 4303 "./marpa.w"

/*536:*/
#line 4371 "./marpa.w"
{
guint sort_key;
for(sort_key= 0;sort_key<no_of_rules;sort_key++){
struct marpa_rule*rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->id]= sort_key;
}}

/*:536*/
#line 4304 "./marpa.w"

/*537:*/
#line 4378 "./marpa.w"

{
prediction_matrix= matrix_create(no_of_symbols,no_of_predictable_rules);
for(from_symbol_id= 0;from_symbol_id<(Marpa_Symbol_ID)no_of_symbols;
from_symbol_id++)
{

guint min,max,start;
for(start= 0;
bv_scan(matrix_row
(symbol_by_symbol_matrix,(guint)from_symbol_id),start,
&min,&max);start= max+2)
{
Marpa_Symbol_ID to_symbol_id;
for(to_symbol_id= min;to_symbol_id<=(Marpa_Symbol_ID)max;
to_symbol_id++)
{

struct symbol*to_symbol= Symbol_by_ID(g,to_symbol_id);
GArray*lhs_rules= to_symbol->lhs;
guint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++)
{

Marpa_Rule_ID rule_with_this_lhs_symbol= 
g_array_index(lhs_rules,Marpa_Rule_ID,ix);
guint sort_key= 
sort_key_by_rule_id[rule_with_this_lhs_symbol];
if(sort_key>=no_of_predictable_rules)
continue;

matrix_bit_set(prediction_matrix,(guint)from_symbol_id,
sort_key);

}
}
}
}
}

/*:537*/
#line 4305 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:531*/
#line 4260 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:529*/
#line 3852 "./marpa.w"

/*515:*/
#line 3910 "./marpa.w"
{
struct AHFA_state*p_initial_state= DQUEUE_PUSH(states,struct AHFA_state);
Marpa_Rule_ID start_rule_id;
struct AHFA_item*start_item;
struct symbol*start_symbol= Symbol_by_ID(g,g->start_symbol_id);
struct symbol*start_alias
= symbol_null_alias(start_symbol);
gint no_of_items_in_new_state= start_alias?2:1;
struct AHFA_item**item_list
= obstack_alloc(&g->obs,no_of_items_in_new_state*sizeof(struct AHFA_item*));
start_rule_id= g_array_index(start_symbol->lhs,Marpa_Rule_ID,0);

start_item= g->AHFA_items_by_rule[start_rule_id];

item_list[0]= start_item;
if(start_alias){
Marpa_Rule_ID alias_rule_id
= g_array_index(start_alias->lhs,Marpa_Rule_ID,0);


item_list[1]= g->AHFA_items_by_rule[alias_rule_id];
}
p_initial_state->items= item_list;
p_initial_state->item_count= no_of_items_in_new_state;
p_initial_state->key.id= 0;
p_initial_state->is_predict= 0;
p_initial_state->is_leo_completion= 0;
p_initial_state->transitions= g_sequence_new(NULL);
p_initial_state->empty_transition= NULL;
if(start_symbol->is_nulling)
{
p_initial_state->no_of_completed_symbols= 1;
p_initial_state->completed_symbols= 
obstack_alloc(&g->obs,sizeof(Marpa_Symbol_ID));
*(p_initial_state->completed_symbols)= g->start_symbol_id;
p_initial_state->no_of_postdot_symbols= 0;
}
else
{
p_initial_state->no_of_postdot_symbols= 1;
p_initial_state->postdot_symbols= 
obstack_alloc(&g->obs,sizeof(Marpa_Symbol_ID));
*(p_initial_state->postdot_symbols)= start_item->postdot;
if(start_alias)
{
p_initial_state->no_of_completed_symbols= 1;
p_initial_state->completed_symbols= 
obstack_alloc(&g->obs,sizeof(Marpa_Symbol_ID));
*(p_initial_state->completed_symbols)= 
LHS_Symbol_ID_of_Rule(rule_id2p(g,start_rule_id));
}
else
{
p_initial_state->no_of_completed_symbols= 0;
}
p_initial_state->empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(guint)start_item->postdot),
rule_by_sort_key,&states,duplicates);
}
}

/*:515*/
#line 3853 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,struct AHFA_state))){
/*512:*/
#line 3867 "./marpa.w"
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
/*517:*/
#line 3975 "./marpa.w"
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
p_new_state->key.id= p_new_state-DQUEUE_BASE(states,struct AHFA_state);
p_new_state->transitions= g_sequence_new(NULL);
AHFA_transition_add(g,p_working_state,working_symbol,p_new_state);
postdot= single_item_p->postdot;
if(postdot>=0){
p_new_state->is_leo_completion= 0;
p_new_state->no_of_postdot_symbols= 1;
p_new_state->postdot_symbols= 
obstack_alloc(&g->obs,sizeof(Marpa_Symbol_ID));
*(p_new_state->postdot_symbols)= postdot;


p_new_state->empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,(guint)postdot),
rule_by_sort_key,
&states,
duplicates);
}else{
p_new_state->no_of_completed_symbols= 1;
p_new_state->completed_symbols= 
obstack_alloc(&g->obs,sizeof(Marpa_Symbol_ID));
*(p_new_state->completed_symbols)= 
LHS_Symbol_ID_of_Rule(single_item_p->rule);
p_new_state->no_of_postdot_symbols= 0;
p_new_state->empty_transition= NULL;
/*519:*/
#line 4051 "./marpa.w"
{
Marpa_Symbol_ID previous_nonnulling_symbol_id= single_item_p[-1].postdot;
p_new_state->is_leo_completion
= SYMBOL_LHS_RULE_COUNT(
Symbol_by_ID(g,previous_nonnulling_symbol_id)
)> 0;
}

/*:519*/
#line 4021 "./marpa.w"

}
}

/*:517*/
#line 3887 "./marpa.w"

}else{
/*520:*/
#line 4074 "./marpa.w"
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

p_new_state->key.id= p_new_state-DQUEUE_BASE(states,struct AHFA_state);
p_new_state->is_predict= 0;
p_new_state->is_leo_completion= 0;
p_new_state->transitions= g_sequence_new(NULL);
/*521:*/
#line 4119 "./marpa.w"

{
guint symbol_count= Symbol_Count_of_G(g);
guint item_ix;
guint no_of_postdot_symbols;
guint no_of_completed_symbols;
Bit_Vector completed_v= bv_create(symbol_count);
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
struct AHFA_item*item= item_list_for_new_state[item_ix];
Marpa_Symbol_ID postdot= Postdot_Symbol_ID_of_AHFA_Item(item);
if(postdot<0)
{
bv_bit_set(postdot_v,(guint)LHS_Symbol_ID_of_Rule(item->rule));
}
else
{
bv_bit_set(completed_v,(guint)postdot);
}
}
if((no_of_postdot_symbols= p_new_state->no_of_postdot_symbols= 
bv_count(postdot_v)))
{
guint min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->postdot_symbols= 
obstack_alloc(&g->obs,
no_of_postdot_symbols*sizeof(Marpa_Symbol_ID));
for(start= 0;bv_scan(postdot_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID postdot;
for(postdot= (Marpa_Symbol_ID)min;
postdot<=(Marpa_Symbol_ID)max;postdot++)
{
*p_symbol++= postdot;
}
}
}
if((no_of_completed_symbols= p_new_state->no_of_completed_symbols= 
bv_count(completed_v)))
{
guint min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->completed_symbols= 
obstack_alloc(&g->obs,
no_of_completed_symbols*sizeof(Marpa_Symbol_ID));
for(start= 0;bv_scan(completed_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID completed_symbol;
for(completed_symbol= (Marpa_Symbol_ID)min;
completed_symbol<=(Marpa_Symbol_ID)max;completed_symbol++)
{
*p_symbol++= completed_symbol;
}
}
}
bv_free(postdot_v);
bv_free(completed_v);
}

/*:521*/
#line 4113 "./marpa.w"

AHFA_transition_add(g,p_working_state,working_symbol,p_new_state);
/*524:*/
#line 4200 "./marpa.w"
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

/*:524*/
#line 4116 "./marpa.w"

}

/*:520*/
#line 3889 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= item_list[current_item_ix]->postdot;
if(working_symbol==-1)break;
}
NEXT_AHFA_STATE:;
}

/*:512*/
#line 3855 "./marpa.w"

}
g->AHFA= DQUEUE_BASE(states,struct AHFA_state);

g->AHFA_len= DQUEUE_END(states);
g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*514:*/
#line 3906 "./marpa.w"

g_free(singleton_duplicates);
g_sequence_free(duplicates);

/*:514*/
#line 3862 "./marpa.w"

}
/*:510*//*522:*/
#line 4184 "./marpa.w"

static inline struct AHFA_state*
assign_AHFA_state(struct AHFA_state*state_p,GSequence*duplicates)
{
gboolean match= FALSE;
GSequenceIter*iter= 
sequence_find(duplicates,state_p,AHFA_state_cmp,&match);
if(match)return g_sequence_get(iter);
g_sequence_insert_before(iter,state_p);
return NULL;
}
/*:522*//*534:*/
#line 4351 "./marpa.w"
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
/*:534*//*538:*/
#line 4418 "./marpa.w"

static struct AHFA_state*
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
struct marpa_rule**rule_by_sort_key,
struct dqueue*states_p,
GSequence*duplicates
){
struct AHFA_item**item_list_for_new_state;
struct AHFA_state*p_new_state;
guint item_list_ix= 0;
guint no_of_items_in_new_state= bv_count(prediction_rule_vector);
if(no_of_items_in_new_state==0)return NULL;
item_list_for_new_state= obstack_alloc(&g->obs,
no_of_items_in_new_state*sizeof(struct AHFA_item*));
{
guint start,min,max;
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2)
{
guint rule_sort_key;
for(rule_sort_key= min;rule_sort_key<=max;rule_sort_key++)
{

struct marpa_rule*rule= rule_by_sort_key[rule_sort_key];
item_list_for_new_state[item_list_ix++]= 
g->AHFA_items_by_rule[rule->id];
}
}
}
p_new_state= DQUEUE_PUSH((*states_p),struct AHFA_state);
p_new_state->items= item_list_for_new_state;
p_new_state->item_count= no_of_items_in_new_state;
{struct AHFA_state*queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);



if(queued_AHFA_state){
(void)DQUEUE_POP((*states_p),struct AHFA_state);
obstack_free(&g->obs,item_list_for_new_state);
return queued_AHFA_state;
}
}

p_new_state->key.id= p_new_state-DQUEUE_BASE((*states_p),struct AHFA_state);
p_new_state->is_predict= 1;
p_new_state->is_leo_completion= 0;
p_new_state->empty_transition= NULL;
p_new_state->transitions= g_sequence_new(NULL);
p_new_state->no_of_completed_symbols= 0;
/*540:*/
#line 4482 "./marpa.w"

{
guint symbol_count= Symbol_Count_of_G(g);
guint item_ix;
guint no_of_postdot_symbols;
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
struct AHFA_item*item= item_list_for_new_state[item_ix];
Marpa_Symbol_ID postdot= Postdot_Symbol_ID_of_AHFA_Item(item);
if(postdot>=0)
bv_bit_set(postdot_v,(guint)postdot);
}
if((no_of_postdot_symbols= p_new_state->no_of_postdot_symbols= 
bv_count(postdot_v)))
{
guint min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->postdot_symbols= 
obstack_alloc(&g->obs,
no_of_postdot_symbols*sizeof(Marpa_Symbol_ID));
for(start= 0;bv_scan(postdot_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID postdot;
for(postdot= (Marpa_Symbol_ID)min;
postdot<=(Marpa_Symbol_ID)max;postdot++)
{
*p_symbol++= postdot;
}
}
}
bv_free(postdot_v);
}

/*:540*/
#line 4469 "./marpa.w"

return p_new_state;
}
/*:538*//*543:*/
#line 4529 "./marpa.w"
static
gint
AHFA_transition_cmp(gconstpointer ap,gconstpointer bp,
gpointer user_data G_GNUC_UNUSED)
{
const struct AHFA_transition*a= ap;
const struct AHFA_transition*b= bp;
return Symbol_ID_of_AHFA_Transition(a)-Symbol_ID_of_AHFA_Transition(b);
}
/*:543*//*545:*/
#line 4542 "./marpa.w"
static inline
void AHFA_transition_add(struct marpa_g*g,
struct AHFA_state*from,Marpa_Symbol_ID symbol,struct AHFA_state*to){
struct AHFA_transition*transition= obstack_alloc(&g->obs,sizeof(struct AHFA_transition));
transition->key.symbol_id= symbol;
transition->to_state= to;
g_sequence_insert_sorted(from->transitions,transition,AHFA_transition_cmp,NULL);
}
/*:545*//*549:*/
#line 4567 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g)
{struct marpa_r*r;
/*803:*/
#line 6693 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:803*/
#line 4570 "./marpa.w"

/*806:*/
#line 6702 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:806*/
#line 4571 "./marpa.w"

r= g_slice_new(struct marpa_r);
r->grammar= g;
/*593:*/
#line 4768 "./marpa.w"
obstack_init(&r->obs);
/*:593*/
#line 4574 "./marpa.w"

/*557:*/
#line 4604 "./marpa.w"

r->id= g_atomic_int_exchange_and_add(&next_recce_id,1);
/*:557*//*563:*/
#line 4626 "./marpa.w"

r->phase= initial_phase;

/*:563*//*565:*/
#line 4641 "./marpa.w"

r->earley_sets= g_sequence_new(earley_set_free);
/*:565*//*568:*/
#line 4649 "./marpa.w"

r->earley_item_warning_threshold= MAX(DEFAULT_EARLEY_ITEM_WARNING_THRESHOLD,g->no_of_items*2);
/*:568*//*574:*/
#line 4677 "./marpa.w"
r->furthest_earleme= 0;

/*:574*//*576:*/
#line 4682 "./marpa.w"

r->is_trace_earley_sets= FALSE;
/*:576*//*582:*/
#line 4713 "./marpa.w"

r->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:582*//*597:*/
#line 4782 "./marpa.w"

r->error= NULL;
/*:597*//*828:*/
#line 6857 "./marpa.w"

r->message_callback_arg= NULL;
r->message_callback= NULL;
/*:828*/
#line 4575 "./marpa.w"

return r;}
/*:549*//*551:*/
#line 4580 "./marpa.w"

void marpa_r_free(struct marpa_r*r)
{
/*566:*/
#line 4643 "./marpa.w"

g_sequence_free(r->earley_sets);

/*:566*//*583:*/
#line 4715 "./marpa.w"
g_hash_table_destroy(r->context);

/*:583*/
#line 4583 "./marpa.w"

/*594:*/
#line 4769 "./marpa.w"
obstack_free(&r->obs,NULL);

/*:594*/
#line 4584 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:551*//*558:*/
#line 4606 "./marpa.w"

gint marpa_r_id(struct marpa_r*r){return r->id;}
/*:558*//*569:*/
#line 4652 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r)
{return r->earley_item_warning_threshold;}
/*:569*//*571:*/
#line 4659 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold)
{
r->earley_item_warning_threshold= threshold==0?EARLEY_ITEM_FATAL_THRESHOLD:threshold;
return TRUE;
}
/*:571*//*577:*/
#line 4685 "./marpa.w"

gboolean marpa_is_trace_earley_sets(struct marpa_r*r)
{return r->is_trace_earley_sets;}
/*:577*//*579:*/
#line 4692 "./marpa.w"

gboolean marpa_is_trace_earley_sets_set(
struct marpa_r*r,gboolean value)
{
r->is_trace_earley_sets= value;
return TRUE;
}
/*:579*//*584:*/
#line 4724 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(r->context,(gpointer)key,value);
}
/*:584*//*586:*/
#line 4736 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(r->context,(gpointer)key,value);
}
/*:586*//*588:*/
#line 4751 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r){
g_hash_table_remove_all(r->context);}
/*:588*//*590:*/
#line 4757 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key)
{return g_hash_table_lookup(r->context,key);}
/*:590*//*599:*/
#line 4790 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r)
{return r->error?r->error:"unknown error";}
/*:599*//*608:*/
#line 4833 "./marpa.w"

static inline struct earley_set*
earley_set_new(struct marpa_r*r,Marpa_Earleme id)
{
struct earley_set_key key;
struct earley_set*set= obstack_alloc(&r->obs,sizeof(struct earley_set));
key.id= id;
set->key= key;
set->earley_items= g_sequence_new(NULL);
set->postdot= g_sequence_new(NULL);
/*618:*/
#line 4919 "./marpa.w"
set->earley_item_count= 0;

/*:618*/
#line 4843 "./marpa.w"

return set;
}
static inline GSequenceIter*
earley_set_assign(struct marpa_r*r,Marpa_Earleme id)
{
struct earley_set*set;
struct earley_set_key key;
gboolean match= FALSE;
GSequenceIter*iter;
key.id= id;
iter= sequence_find(r->earley_sets,&key,earley_set_cmp,&match);
if(match)return iter;
set= earley_set_new(r,id);
return g_sequence_insert_before(iter,set);
}
/*:608*//*610:*/
#line 4866 "./marpa.w"

static inline void earley_set_free(gpointer p){
GSequence*sequence;
struct earley_set*set= p;
if((sequence= set->earley_items))g_sequence_free(sequence);
if((sequence= set->postdot))g_sequence_free(sequence);
}
/*:610*//*612:*/
#line 4877 "./marpa.w"

static gint
earley_set_cmp(
gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED)
{
const struct earley_set_key*set_key_a= ap;
const struct earley_set_key*set_key_b= bp;
return set_key_a->id-set_key_b->id;
}
/*:612*//*615:*/
#line 4898 "./marpa.w"

static inline struct earley_set*
earley_set_by_id(struct marpa_r*r,Marpa_Earleme earleme)
{
GSequenceIter*iter;
struct earley_set_key key;
gboolean match= FALSE;
key.id= earleme;
iter= sequence_find(r->earley_sets,&key,
earley_set_cmp,
&match);
return match?(struct earley_set*)g_sequence_get(iter):NULL;
}
/*:615*//*624:*/
#line 4972 "./marpa.w"

static inline struct earley_item*earley_item_new(struct marpa_r*r,
struct earley_set*set,struct earley_item_key key)
{
struct earley_item*new_item= obstack_alloc(&r->obs,sizeof(struct earley_item));
new_item->key= key;
new_item->set= set;
new_item->source_type= NO_SOURCE;
return new_item;
}
/*:624*//*626:*/
#line 4985 "./marpa.w"

static inline struct earley_item*earley_item_assign(
struct marpa_r*r,struct earley_set*set,
struct earley_set*origin,struct AHFA_state*state)
{
struct earley_item_key key;
key.origin= origin;
key.state= state;
return earley_item_assign_by_key(r,set,key);
}
/*:626*//*628:*/
#line 5000 "./marpa.w"

static inline struct earley_item*earley_item_assign_by_key(
struct marpa_r*r,struct earley_set*set,
struct earley_item_key key)
{
struct earley_item*new_item;
GSequenceIter*iter;
guint count= set->earley_item_count++;
if(count>=r->earley_item_warning_threshold)
{
r_context_clear(r);
if(count>=EARLEY_ITEM_FATAL_THRESHOLD)
{
r->error= "earley items more than fatal threshold";
return NULL;
}
r_message(r,"earley item count exceeds threshold");
}
{
gboolean match= FALSE;
iter= sequence_find
(set->earley_items,&key,own_earley_item_cmp,&match);
if(match)return(struct earley_item*)g_sequence_get(iter);
}
new_item= earley_item_new(r,set,key);
g_sequence_insert_before(iter,new_item);
return new_item;
}
/*:628*//*633:*/
#line 5052 "./marpa.w"

static gint
own_earley_item_cmp(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED)
/*632:*/
#line 5041 "./marpa.w"

{
const struct earley_item*item_a= ap;
const struct earley_item*item_b= bp;
gint subkey= 
AHFA_State_ID_of_Earley_Item(item_a)-
AHFA_State_ID_of_Earley_Item(item_b);
if(subkey)
return subkey;
return Origin_ID_of_Earley_Item(item_a)-Origin_ID_of_Earley_Item(item_b);
}
/*:632*/
#line 5056 "./marpa.w"

static inline gint earley_item_cmp(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED)
/*632:*/
#line 5041 "./marpa.w"

{
const struct earley_item*item_a= ap;
const struct earley_item*item_b= bp;
gint subkey= 
AHFA_State_ID_of_Earley_Item(item_a)-
AHFA_State_ID_of_Earley_Item(item_b);
if(subkey)
return subkey;
return Origin_ID_of_Earley_Item(item_a)-Origin_ID_of_Earley_Item(item_b);
}
/*:632*/
#line 5059 "./marpa.w"

/*:633*//*640:*/
#line 5110 "./marpa.w"

gint
marpa_earley_item_count(struct marpa_r*r,Marpa_Earleme earleme)
{/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 5113 "./marpa.w"

struct earley_set*set;
/*812:*/
#line 6746 "./marpa.w"

if(r->phase==initial_phase){
r_context_clear(r);
r->error= "initial recce phase";
return failure_indicator;
}
/*:812*/
#line 5115 "./marpa.w"

set= Earley_Set_by_ID(r,earleme);
if(!set)return 0;
return g_sequence_get_length(set->earley_items);
}
/*:640*//*643:*/
#line 5141 "./marpa.w"

struct marpa_earley_item*
marpa_earley_items(struct marpa_r*r,
Marpa_Earleme earleme,struct marpa_earley_item*buffer)
{
struct earley_set*set;
GSequence*items;
GSequenceIter*iter;
struct marpa_earley_item*p_buffer= buffer;
/*803:*/
#line 6693 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:803*/
#line 5150 "./marpa.w"

/*812:*/
#line 6746 "./marpa.w"

if(r->phase==initial_phase){
r_context_clear(r);
r->error= "initial recce phase";
return failure_indicator;
}
/*:812*/
#line 5151 "./marpa.w"

set= Earley_Set_by_ID(r,earleme);
if(!set)
return buffer;
items= set->earley_items;
for(iter= g_sequence_get_begin_iter(items);
!g_sequence_iter_is_end(iter);iter= g_sequence_iter_next(iter))
{
struct earley_item*internal= g_sequence_get(iter);
p_buffer->state= AHFA_State_ID_of_Earley_Item(internal);
p_buffer->origin= Origin_ID_of_Earley_Item(internal);
p_buffer++;
}
return buffer;
}
/*:643*//*648:*/
#line 5202 "./marpa.w"

static gint
postdot_item_cmp(gconstpointer ap,gconstpointer bp,
gpointer user_data G_GNUC_UNUSED)
{
const struct earley_ix*a= ap;
const struct earley_ix*b= bp;
struct earley_item*earley_item_a;
struct earley_item*earley_item_b;
{
gint subkey= a->postdot_symbol_id-b->postdot_symbol_id;
if(subkey)return subkey;
}
earley_item_a= a->earley_item;
earley_item_b= b->earley_item;
if(earley_item_a&&earley_item_b){
gint origin_a,origin_b;
gint state_a= (gint)AHFA_State_of_Earley_Item(earley_item_a);
gint state_b= (gint)AHFA_State_of_Earley_Item(earley_item_b);
gint subkey= state_a-state_b;
if(subkey)
return subkey;
origin_a= (gint)Origin_of_Earley_Item(earley_item_a);
origin_b= (gint)Origin_of_Earley_Item(earley_item_b);
subkey= origin_a-origin_b;
if(subkey)
return subkey;
}
return(earley_item_a?1:0)-(earley_item_b?1:0);
}
/*:648*//*653:*/
#line 5247 "./marpa.w"

static inline void postdot_items_create(
struct marpa_r*r,struct earley_set*set,
struct earley_item*item
)
{
struct earley_ix*new_item;
struct AHFA_state*state= AHFA_State_of_Earley_Item(item);
gint symbol_ix;
gint postdot_symbol_count= Postdot_Symbol_Count_of_AHFA_State(state);
Marpa_Symbol_ID*postdot_symbols= 
Postdot_Symbol_ID_Array_of_AHFA_State(state);
for(symbol_ix= 0;symbol_ix<postdot_symbol_count;symbol_ix++){
new_item= obstack_alloc(&r->obs,sizeof(struct earley_ix));
new_item->postdot_symbol_id= postdot_symbols[symbol_ix];
new_item->earley_item= item;
g_sequence_insert_sorted(set->postdot,new_item,postdot_item_cmp,NULL);
}
}

/*:653*//*663:*/
#line 5377 "./marpa.w"
static inline
void
token_link_add(struct marpa_r*r,
struct earley_item*item,
struct earley_item*predecessor,
gpointer value,Marpa_Symbol_ID token_id)
{
struct full_source_link*new_link;
unsigned int previous_source_type= Source_Type_of_Earley_Item(item);
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_Earley_Item(item)= SOURCE_IS_TOKEN;
item->sourcing.full.links.predecessor= predecessor;
item->sourcing.full.links.cause= value;
item->sourcing.full.token_id= token_id;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->obs,sizeof(struct full_source_link));
new_link->next= (union source_link*)First_Token_Link_of_Earley_Item(item);
new_link->source.links.predecessor= predecessor;
new_link->source.links.cause= value;
new_link->source.token_id= token_id;
First_Token_Link_of_Earley_Item(item)= new_link;
}
/*:663*//*666:*/
#line 5431 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,struct earley_item*item)
{
unsigned int previous_source_type= Source_Type_of_Earley_Item(item);
Source_Type_of_Earley_Item(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*668:*/
#line 5451 "./marpa.w"
{
struct full_source_link*new_link= 
obstack_alloc(&r->obs,sizeof(struct full_source_link));
new_link->next= NULL;
new_link->source= item->sourcing.full;
First_Leo_Link_of_Earley_Item(item)= NULL;
First_Completion_Link_of_Earley_Item(item)= NULL;
First_Token_Link_of_Earley_Item(item)= new_link;
}

/*:668*/
#line 5438 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*669:*/
#line 5461 "./marpa.w"
{
struct brief_source_link*new_link= 
obstack_alloc(&r->obs,sizeof(struct brief_source_link));
new_link->next= NULL;
new_link->source= item->sourcing.brief;
First_Leo_Link_of_Earley_Item(item)= NULL;
First_Completion_Link_of_Earley_Item(item)= new_link;
First_Token_Link_of_Earley_Item(item)= NULL;
}

/*:669*/
#line 5440 "./marpa.w"

return;
case SOURCE_IS_LEO_TOKEN:/*670:*/
#line 5471 "./marpa.w"
{
struct full_source_link*new_link= 
obstack_alloc(&r->obs,sizeof(struct full_source_link));
new_link->next= NULL;
new_link->source= item->sourcing.full;
First_Leo_Link_of_Earley_Item(item)= new_link;
First_Completion_Link_of_Earley_Item(item)= NULL;
First_Token_Link_of_Earley_Item(item)= NULL;
}

/*:670*/
#line 5442 "./marpa.w"

return;
case SOURCE_IS_LEO_COMPLETION:/*671:*/
#line 5485 "./marpa.w"
{
struct full_source_link*new_link= 
obstack_alloc(&r->obs,sizeof(struct full_source_link));
new_link->next= NULL;
new_link->source.links= item->sourcing.brief;
new_link->source.token_id= -1;
First_Leo_Link_of_Earley_Item(item)= new_link;
First_Completion_Link_of_Earley_Item(item)= NULL;
First_Token_Link_of_Earley_Item(item)= NULL;
}

/*:671*/
#line 5444 "./marpa.w"

return;
}
}
/*:666*//*672:*/
#line 5497 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r)
{
struct earley_set*set0;
struct earley_item*item;
struct AHFA_state*state;
GSequenceIter*current_iter;
/*802:*/
#line 6691 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:802*/
#line 5503 "./marpa.w"

/*811:*/
#line 6740 "./marpa.w"

if(r->phase!=initial_phase){
r_context_clear(r);
r->error= "not initial recce phase";
return failure_indicator;
}
/*:811*/
#line 5504 "./marpa.w"

current_iter= r->current_iter= earley_set_assign(r,0);
set0= g_sequence_get(current_iter);
state= AHFA_State_of_R_by_ID(r,0);
item= earley_item_assign(r,set0,set0,state);
if(!item)return FALSE;
postdot_items_create(r,set0,item);
state= Empty_Transition_of_AHFA_State(state);
if(state){
item= earley_item_assign(r,set0,set0,state);
if(!item)return FALSE;
postdot_items_create(r,set0,item);
}
r->phase= active_phase;
return TRUE;
}
/*:672*//*677:*/
#line 5545 "./marpa.w"
/*678:*/
#line 5546 "./marpa.w"

gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length)
/*:678*//*679:*/
#line 5549 "./marpa.w"

{
Marpa_Earleme target_earleme;
GSequenceIter*working_postdot_iter= NULL;
union postdot_item*working_postdot_item;
struct earley_item*postdot_earley_item;
struct earley_set*current_earley_set;
struct earley_set*target_earley_set;
struct earley_item*target_earley_item= NULL;
const struct marpa_g*g= G_of_R(r);
struct symbol*token= Symbol_by_ID(g,token_id);
/*805:*/
#line 6697 "./marpa.w"
const int failure_indicator= -2;

/*:805*/
#line 5560 "./marpa.w"

/*:679*//*680:*/
#line 5561 "./marpa.w"

/*813:*/
#line 6752 "./marpa.w"

if(r->phase!=active_phase){
r_context_clear(r);
r->error= "recce not active";
return failure_indicator;
}

/*:813*/
#line 5562 "./marpa.w"

if(!Symbol_is_Terminal(token)){
r_context_clear(r);
r->error= "token is not a terminal";
return failure_indicator;
}
/*:680*//*681:*/
#line 5568 "./marpa.w"

if(length<=0){
r_context_clear(r);
r->error= "token length negative or zero";
return failure_indicator;
}
if(length>=EARLEME_THRESHOLD){
r_context_clear(r);
r->error= "token too long";
return failure_indicator;
}
/*:681*//*682:*/
#line 5579 "./marpa.w"

target_earleme= Current_Earleme_of_R(r)+length;
if(target_earleme>=EARLEME_THRESHOLD){
r_context_clear(r);
r_context_int_add(r,"target_earleme",target_earleme);
r->error= "parse too long";
return failure_indicator;
}
/*:682*//*683:*/
#line 5587 "./marpa.w"

LV_Furthest_Earleme_of_R(r)= MAX(target_earleme,Furthest_Earleme_of_R(r));
current_earley_set= Current_Earley_Set_of_R(r);
working_postdot_iter= first_postdot_item_find(current_earley_set,token_id);
if(!working_postdot_iter)return-1;
/*:683*//*684:*/
#line 5592 "./marpa.w"


working_postdot_item= g_sequence_get(working_postdot_iter);
postdot_earley_item= Earley_Item_of_Postdot_Item(working_postdot_item);
earley_iter_later_assign(r,target_earleme,&target_earley_set);
if(!postdot_earley_item){
/*694:*/
#line 5697 "./marpa.w"
{;}
/*:694*/
#line 5598 "./marpa.w"

if(target_earley_item){
/*695:*/
#line 5698 "./marpa.w"
{;}
/*:695*/
#line 5600 "./marpa.w"

goto RETURN_SUCCESS;
}else{
/*696:*/
#line 5699 "./marpa.w"
{;}
/*:696*/
#line 5603 "./marpa.w"

goto RETURN_SUCCESS;
}
}
/*:684*//*685:*/
#line 5607 "./marpa.w"

target_earley_item= 
earley_item_assign(r,target_earley_set,
Origin_of_Earley_Item(postdot_earley_item),
To_State_of_Earley_Item_and_Symbol_ID
(postdot_earley_item,token_id));
/*705:*/
#line 5779 "./marpa.w"

if(Item_has_Token_Source(target_earley_item)){
if(!earley_item_cmp
(postdot_earley_item,
Predecessor_of_Earley_Item(target_earley_item),NULL))
{
r->error= "duplicate token";
return failure_indicator;
}
}else if(Item_is_Ambiguous(target_earley_item)){
struct full_source_link*link= 
First_Token_Link_of_Earley_Item(target_earley_item);
while(link)
{
if(!earley_item_cmp
(postdot_earley_item,Predecessor_of_Source_Link(link),NULL))
{
r->error= "duplicate token";
return failure_indicator;
}
link= (struct full_source_link*)Next_Link_of_Source_Link(link);
}
}

/*:705*/
#line 5613 "./marpa.w"

/*:685*//*686:*/
#line 5614 "./marpa.w"

for(;;){
token_link_add(r,target_earley_item,postdot_earley_item,value,token_id);
/*706:*/
#line 5803 "./marpa.w"
{;}

/*:706*/
#line 5617 "./marpa.w"

working_postdot_iter= g_sequence_iter_next(working_postdot_iter);
if(g_sequence_iter_is_end(working_postdot_iter))goto RETURN_SUCCESS;

working_postdot_item= g_sequence_get(working_postdot_iter);
if(token_id!=Symbol_ID_of_Postdot_Item(working_postdot_item))goto RETURN_SUCCESS;
postdot_earley_item= Earley_Item_of_Postdot_Item(working_postdot_item);
/*697:*/
#line 5700 "./marpa.w"
{;}

/*:697*/
#line 5624 "./marpa.w"

}
/*:686*//*687:*/
#line 5626 "./marpa.w"

RETURN_SUCCESS:;
return ID_of_Earley_Set(current_earley_set);
}
/*:687*/
#line 5545 "./marpa.w"

/*:677*//*692:*/
#line 5670 "./marpa.w"

static inline GSequenceIter*earley_iter_later_assign(
struct marpa_r*r,Marpa_Earleme sought_earleme,
struct earley_set**set_p)
{
GSequenceIter*iter;
for(iter= g_sequence_iter_next(Current_Earley_Set_Iter_of_R(r));
!g_sequence_iter_is_end(iter);
iter= g_sequence_iter_next(iter)
){
Marpa_Earleme found_earleme;
struct earley_set*found_set= g_sequence_get(iter);
found_earleme= Earleme_of_Earley_Set(found_set);
if(sought_earleme==found_earleme){
*set_p= found_set;
return iter;
}
if(sought_earleme> found_earleme)break;
}
*set_p= earley_set_new(r,sought_earleme);
return g_sequence_insert_before(iter,*set_p);
}
/*:692*//*708:*/
#line 5817 "./marpa.w"

static inline GSequenceIter*
first_postdot_item_find(struct earley_set*set,Marpa_Symbol_ID symbol_id)
{
struct earley_ix*found_ix;
struct earley_ix search_ix;
GSequenceIter*first_item_for_symbol;
search_ix.postdot_symbol_id= symbol_id-1;
first_item_for_symbol= g_sequence_search(set->postdot,
&search_ix,
postdot_symbol_cmp,NULL);
if(g_sequence_iter_is_end(first_item_for_symbol))return NULL;
found_ix= g_sequence_get(first_item_for_symbol);
return(found_ix->postdot_symbol_id==
symbol_id)?first_item_for_symbol:NULL;
}
static gint
postdot_symbol_cmp(gconstpointer ap,gconstpointer bp,
gpointer user_data G_GNUC_UNUSED)
{
const struct earley_ix*a= ap;
const struct earley_ix*b= bp;
return a->postdot_symbol_id-b->postdot_symbol_id;
}
/*:708*//*710:*/
#line 5849 "./marpa.w"

Marpa_Earleme
earleme_complete(struct marpa_r*r)
{
struct earley_set*dummy;
GSequenceIter*current_earley_set_iter= Current_Earley_Set_Iter_of_R(r);
/*804:*/
#line 6695 "./marpa.w"
const int failure_indicator= -1;
/*:804*/
#line 5855 "./marpa.w"

Marpa_Earleme new_current_earleme= 
Earleme_of_Earley_Set_Iter(current_earley_set_iter)+1;
if(new_current_earleme> Furthest_Earleme_of_R(r))
{
r->error= "parse exhausted";
return failure_indicator;
}
LV_Current_Earley_Set_Iter_of_R(r)= earley_iter_later_assign(r,
new_current_earleme,&dummy);
return new_current_earleme;
}
/*:710*//*716:*/
#line 5904 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:716*//*718:*/
#line 5912 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:718*//*720:*/
#line 5928 "./marpa.w"

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
/*:720*//*722:*/
#line 5945 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:722*//*724:*/
#line 5957 "./marpa.w"
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
/*:724*//*726:*/
#line 5977 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:726*//*728:*/
#line 5986 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:728*//*730:*/
#line 5994 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:730*//*733:*/
#line 6007 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:733*//*735:*/
#line 6015 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:735*//*737:*/
#line 6023 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:737*//*740:*/
#line 6032 "./marpa.w"

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
/*:740*//*742:*/
#line 6049 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:742*//*744:*/
#line 6061 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:744*//*746:*/
#line 6073 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:746*//*748:*/
#line 6085 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:748*//*750:*/
#line 6097 "./marpa.w"

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
/*:750*//*752:*/
#line 6173 "./marpa.w"

static inline guint
bv_count(Bit_Vector v)
{
guint start,min,max;
guint count= 0;
for(start= 0;bv_scan(v,start,&min,&max);start= max+2)
{
count+= max-min+1;
}
return count;
}
/*:752*//*758:*/
#line 6227 "./marpa.w"

static void
rhs_closure(struct marpa_g*g,Bit_Vector bv)
{
guint min,max,start= 0;
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_DEFINE(stack,Marpa_Symbol_ID);
FSTACK_INIT(stack,Marpa_Symbol_ID,Symbol_Count_of_G(g));
while(bv_scan(bv,start,&min,&max))
{
guint symbol_id;
for(symbol_id= min;symbol_id<=max;symbol_id++)
{
*(FSTACK_PUSH(stack))= symbol_id;
}
start= max+2;
}
while((top_of_stack= FSTACK_POP(stack)))
{
guint rule_ix;
GArray*rules= Symbol_by_ID(g,*top_of_stack)->rhs;
for(rule_ix= 0;rule_ix<rules->len;rule_ix++)
{
Marpa_Rule_ID rule_id= 
g_array_index(rules,Marpa_Rule_ID,rule_ix);
struct marpa_rule*rule= rule_id2p(g,rule_id);
guint rule_length;
guint rh_ix;
Marpa_Symbol_ID lhs_id= LHS_Symbol_ID_of_Rule(rule);
if(bv_bit_test(bv,(guint)lhs_id))
goto NEXT_RULE;
rule_length= rule->length;
for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test(bv,(guint)rhs_symbol_id(rule,rh_ix)))
goto NEXT_RULE;
}



bv_bit_set(bv,(guint)lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}
/*:758*//*763:*/
#line 6305 "./marpa.w"

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
/*:763*//*765:*/
#line 6325 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:765*//*767:*/
#line 6338 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:767*//*769:*/
#line 6355 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:769*//*772:*/
#line 6365 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:772*//*775:*/
#line 6374 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:775*//*778:*/
#line 6383 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:778*//*780:*/
#line 6397 "./marpa.w"

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
/*:780*//*786:*/
#line 6502 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:786*//*791:*/
#line 6557 "./marpa.w"

static inline GSequenceIter*
sequence_find(GSequence*sequence,
void*key,GCompareDataFunc compare,gboolean*match)
{
void*data= NULL;
GSequenceIter*found;
GSequenceIter*insertion_point= 
g_sequence_search(sequence,key,compare,NULL);
if(g_sequence_iter_is_begin(insertion_point))
return insertion_point;
found= g_sequence_iter_prev(insertion_point);
data= g_sequence_get(found);
return(*match= !compare(data,key,NULL))?found:insertion_point;
}
/*:791*//*821:*/
#line 6825 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->message_callback_arg= cb_arg;}
gpointer marpa_g_message_callback_arg(struct marpa_g*g)
{return g->message_callback_arg;}
/*:821*//*823:*/
#line 6842 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_G_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:823*//*829:*/
#line 6860 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb)
{r->message_callback= cb;}
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg)
{r->message_callback_arg= cb_arg;}
gpointer marpa_r_message_callback_arg(struct marpa_r*r)
{return r->message_callback_arg;}
/*:829*//*831:*/
#line 6871 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id)
{Marpa_R_Message_Callback*cb= r->message_callback;
if(cb){(*cb)(r,id);}}
/*:831*/
#line 6930 "./marpa.w"





/*:835*/
