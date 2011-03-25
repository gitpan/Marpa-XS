/*1079:*/
#line 9620 "./marpa.w"

/*
 * Copyright 2011 Jeffrey Kegler
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

/*:1079*//*1080:*/
#line 9643 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1070:*/
#line 9549 "./marpa.w"

#define MARPA_DEBUG  0 
#if MARPA_DEBUG
#define G_DEBUG1(a)  g_debug((a)) 
#define G_DEBUG2(a, b)  g_debug((a),(b)) 
#define G_DEBUG3(a, b, c)  g_debug((a),(b),(c)) 
#define G_DEBUG4(a, b, c, d)  g_debug((a),(b),(c),(d)) 
#else 
#define G_DEBUG1(a) 
#define G_DEBUG2(a, b) 
#define G_DEBUG3(a, b, c) 
#define G_DEBUG4(a, b, c, d) 
#endif

/*:1070*/
#line 9646 "./marpa.w"

#define SYM_Count_of_G(g) ((g) ->symbols->len)  \

#define SYM_by_ID(g,id) (g_array_index((g) ->symbols,struct symbol*,(id) ) )  \

#define Size_of_G(g) ((g) ->t_size) 
#define LV_Size_of_G(g) ((g) ->t_size) 
#define SYMBOL_LHS_RULE_COUNT(symbol) ((symbol) ->lhs->len) 
#define SYM_is_Terminal(symbol) ((symbol) ->is_terminal) 
#define SYMID_is_Terminal(g,id) (SYM_is_Terminal(SYM_by_ID((g) ,(id) ) ) ) 
#define LV_SYMID_is_Terminal(g,id) SYMID_is_Terminal((g) ,(id) ) 
#define LHS_ID_of_PRD(production) ((production) ->symbols[0])  \

#define ID_of_RULE(rule) ((rule) ->t_id) 
#define RULE_is_Start(rule) ((rule) ->t_is_start) 
#define Position_of_AIM(aim) ((aim) ->t_position) 
#define LV_Position_of_AIM(aim) Position_of_AIM(aim) 
#define Sort_Key_of_AIM(aim) ((aim) ->t_sort_key) 
#define LV_Sort_Key_of_AIM(aim) Sort_Key_of_AIM(aim) 
#define AIM_by_ID(g,id) ((g) ->AHFA_items+(id) )  \

#define Postdot_SYMID_of_AIM(item) ((item) ->t_postdot) 
#define LV_Postdot_SYMID_of_AIM(item) Postdot_SYMID_of_AIM(item) 
#define AIM_is_Completion(aim) (Postdot_SYMID_of_AIM(aim) <0) 
#define AIM_has_Completed_Start_Rule(aim)  \
(AIM_is_Completion(aim) &&RULE_is_Start(RULE_of_AIM(aim) ) ) 
#define RULE_of_AIM(item) ((item) ->t_production) 
#define LV_RULE_of_AIM(item) RULE_of_AIM(item) 
#define LHS_ID_of_AIM(item) (LHS_ID_of_PRD(RULE_of_AIM(item) ) )  \

#define AHFA_by_ID(id) (g->t_AHFA+(id) ) 
#define Complete_SYMIDARY_of_AHFA(state) ((state) ->t_complete_symbols) 
#define Complete_SYM_Count_of_AHFA(state) ((state) ->t_complete_symbol_count) 
#define AHFA_has_Completed_Start_Rule(ahfa) ((ahfa) ->t_has_completed_start_rule) 
#define AHFA_Count_of_G(g) ((g) ->t_AHFA_len) 
#define LV_AHFA_Count_of_G(g) ((g) ->t_AHFA_len) 
#define ID_of_AHFA(state) ((state) ->t_key.t_id)  \

#define Postdot_SYM_Count_of_AHFA(state) ((state) ->t_postdot_sym_count) 
#define LV_Postdot_SYM_Count_of_AHFA(state) Postdot_SYM_Count_of_AHFA(state) 
#define Postdot_SYMID_Ary_of_AHFA(state) ((state) ->t_postdot_symid_ary) 
#define LV_Postdot_SYMID_Ary_of_AHFA(state) Postdot_SYMID_Ary_of_AHFA(state) 
#define Empty_Transition_of_AHFA(state) ((state) ->t_empty_transition) 
#define Leo_LHS_ID_of_AHFA(state) ((state) ->t_leo_lhs_sym) 
#define LV_Leo_LHS_ID_of_AHFA(state) Leo_LHS_ID_of_AHFA(state) 
#define AHFA_is_Leo_Completion(state) (Leo_LHS_ID_of_AHFA(state) >=0) 
#define To_AHFA_of_AHFA_by_SYMID(from_ahfa,id) ((from_ahfa) ->t_to_ahfa_ary[id]) 
#define To_AHFA_of_EIM_by_SYMID(eim,id) To_AHFA_of_AHFA_by_SYMID(AHFA_of_EIM(eim) ,(id) )  \

#define G_of_R(r) ((r) ->t_grammar) 
#define Current_ES_Iter_of_R(r) ((r) ->t_current_earley_set_iter) 
#define LV_Current_ES_Iter_of_R(r) Current_ES_Iter_of_R(r) 
#define ES_of_ES_Iter(iter)  \
((ES) g_sequence_get(iter) ) 
#define Current_ES_of_R(r)  \
(ES_of_ES_Iter(Current_ES_Iter_of_R(r) ) ) 
#define Earleme_of_ES_Iter(iter) ID_of_ES(ES_of_ES_Iter(iter) ) 
#define Current_Earleme(r) (Earleme_of_ES_Iter(Current_ES_Iter_of_R(r) ) ) 
#define DEFAULT_EIM_WARNING_THRESHOLD (100) 
#define Furthest_Earleme(r) ((r) ->t_furthest_earleme) 
#define LV_Furthest_Earleme(r) Furthest_Earleme(r) 
#define EARLEME_THRESHOLD (G_MAXINT/4) 
#define EIM_Sequence_of_ES(set) ((set) ->t_eims) 
#define EIM_Count_of_ES(set) ((set) ->t_eim_count) 
#define Postdot_SYM_Count_of_ES(set) ((set) ->t_postdot_sym_count) 
#define First_PIM_of_ES_by_SYMID(set,symid) (first_pim_of_es_by_symid((set) ,(symid) ) ) 
#define PIM_SYM_P_of_ES_by_SYMID(set,symid) (pim_sym_p_find((set) ,(symid) ) ) 
#define ID_of_ES(set) ((set) ->t_key.t_id) 
#define Earleme_of_ES(set) ID_of_ES(set)  \

#define Earley_Set_by_ID(r,id) (earley_set_by_id((r) ,(id) ) ) 
#define EIM_FATAL_THRESHOLD (G_MAXINT/4) 
#define Complete_SYMIDARY_of_EIM(item)  \
Complete_SYMIDARY_of_AHFA(AHFA_of_EIM(item) ) 
#define Complete_SYM_Count_of_EIM(item)  \
Complete_SYM_Count_of_AHFA(AHFA_of_EIM(item) ) 
#define Leo_LHS_ID_of_EIM(eim) Leo_LHS_ID_of_AHFA(AHFA_of_EIM(eim) ) 
#define Earley_Item_is_Completion(item)  \
(Complete_SYM_Count_of_EIM(item) > 0) 
#define ES_of_EIM(item) ((item) ->t_set) 
#define Earleme_of_EIM(item) ID_of_ES(ES_of_EIM(item) )  \

#define AHFAID_of_EIM(item) (ID_of_AHFA(AHFA_of_EIM(item) ) ) 
#define AHFA_of_EIM(item) ((item) ->t_key.t_state)  \

#define Origin_ID_of_EIM(item) (ID_of_ES(Origin_of_EIM(item) ) ) 
#define Origin_of_EIM(item) ((item) ->t_key.t_origin)  \

#define NO_SOURCE (0U) 
#define SOURCE_IS_TOKEN (1U) 
#define SOURCE_IS_COMPLETION (2U) 
#define SOURCE_IS_LEO (3U) 
#define SOURCE_IS_AMBIGUOUS (4U) 
#define Source_Type_of_EIM(item) ((item) ->t_source_type) 
#define Earley_Item_has_No_Source(item) ((item) ->t_source_type==NO_SOURCE) 
#define Earley_Item_has_Token_Source(item) ((item) ->t_source_type==SOURCE_IS_TOKEN) 
#define Earley_Item_has_Complete_Source(item) ((item) ->t_source_type==SOURCE_IS_COMPLETION) 
#define Earley_Item_has_Leo_Source(item) ((item) ->t_source_type==SOURCE_IS_LEO) 
#define Earley_Item_is_Ambiguous(item) ((item) ->t_source_type==SOURCE_IS_AMBIGUOUS) 
#define EIM_is_Leo_Expanded(eim) ((eim) ->t_is_leo_expanded) 
#define LV_EIM_is_Leo_Expanded(eim) EIM_is_Leo_Expanded(eim) 
#define Next_PIM_of_EIX(eix) ((eix) ->t_next) 
#define LV_Next_PIM_of_EIX(eix) Next_PIM_of_EIX(eix) 
#define EIM_of_EIX(eix) ((eix) ->t_earley_item) 
#define LV_EIM_of_EIX(eix) EIM_of_EIX(eix) 
#define Postdot_SYMID_of_EIX(eix) ((eix) ->t_postdot_symid) 
#define LV_Postdot_SYMID_of_EIX(eix) Postdot_SYMID_of_EIX(eix) 
#define EIX_of_LIM(lim) ((EIX) (lim) ) 
#define Postdot_SYMID_of_LIM(leo) (Postdot_SYMID_of_EIX(EIX_of_LIM(leo) ) ) 
#define LV_Postdot_SYMID_of_LIM(leo) Postdot_SYMID_of_LIM(leo) 
#define Next_PIM_of_LIM(leo) (Next_PIM_of_EIX(EIX_of_LIM(leo) ) ) 
#define LV_Next_PIM_of_LIM(leo) Next_PIM_of_LIM(leo) 
#define Origin_of_LIM(leo) ((leo) ->t_origin) 
#define LV_Origin_of_LIM(leo) Origin_of_LIM(leo) 
#define Top_AHFA_of_LIM(leo) ((leo) ->t_top_ahfa) 
#define LV_Top_AHFA_of_LIM(leo) Top_AHFA_of_LIM(leo) 
#define Predecessor_LIM_of_LIM(leo) ((leo) ->t_predecessor) 
#define LV_Predecessor_LIM_of_LIM(leo) Predecessor_LIM_of_LIM(leo) 
#define Base_EIM_of_LIM(leo) ((leo) ->t_base) 
#define LV_Base_EIM_of_LIM(leo) Base_EIM_of_LIM(leo) 
#define ES_of_LIM(leo) ((leo) ->t_set) 
#define LV_ES_of_LIM(leo) ES_of_LIM(leo) 
#define Earleme_of_LIM(lim) ID_of_ES(ES_of_LIM(lim) ) 
#define LIM_of_PIM(pim) ((LIM) (pim) ) 
#define EIX_of_PIM(pim) ((EIX) (pim) ) 
#define Postdot_SYMID_of_PIM(pim) (Postdot_SYMID_of_EIX(EIX_of_PIM(pim) ) ) 
#define LV_Postdot_SYMID_of_PIM(pim) Postdot_SYMID_of_PIM(pim) 
#define EIM_of_PIM(pim) (EIM_of_EIX(EIX_of_PIM(pim) ) ) 
#define LV_EIM_of_PIM(pim) EIM_of_PIM(pim) 
#define Next_PIM_of_PIM(pim) (Next_PIM_of_EIX(EIX_of_PIM(pim) ) ) 
#define LV_Next_PIM_of_PIM(pim) Next_PIM_of_PIM(pim)  \

#define PIM_of_LIM(pim) ((PIM) (pim) ) 
#define PIM_is_LIM(pim) (EIM_of_EIX(EIX_of_PIM(pim) ) ==NULL) 
#define Symbol_ID_of_Postdot_Item(postdot) ((postdot) ->earley.transition_symid)  \

#define Next_SRCL_of_SRCL(link) ((link) ->t_next) 
#define LV_Next_SRCL_of_SRCL(link) Next_SRCL_of_SRCL(link) 
#define SRCD_of_SRCL(link) ((link) ->t_source) 
#define SRCD_of_EIM(eim) ((eim) ->t_container.t_unique) 
#define Predecessor_of_SRCD(srcd) ((srcd) .t_predecessor) 
#define Predecessor_of_SRC(source) Predecessor_of_SRCD(*(source) ) 
#define Predecessor_of_EIM(item) Predecessor_of_SRCD(SRCD_of_EIM(item) ) 
#define Predecessor_of_SRCL(link) Predecessor_of_SRCD(SRCD_of_SRCL(link) ) 
#define LV_Predecessor_of_SRCL(link) Predecessor_of_SRCL(link) 
#define Cause_of_SRCD(srcd) ((srcd) .t_cause) 
#define Cause_of_SRC(source) Cause_of_SRCD(*(source) ) 
#define Cause_of_EIM(item) Cause_of_SRCD(SRCD_of_EIM(item) ) 
#define Cause_of_SRCL(link) Cause_of_SRCD(SRCD_of_SRCL(link) ) 
#define Token_Value_of_SRCD(srcd) ((srcd) .t_cause) 
#define Token_Value_of_SRC(source) Token_Value_of_SRCD(*(source) ) 
#define Token_Value_of_EIM(item) Token_Value_of_SRCD(SRCD_of_EIM(item) ) 
#define Token_Value_of_SRCL(link) Token_Value_of_SRCD(SRCD_of_SRCL(link) ) 
#define LV_Token_Value_of_SRCL(link) Token_Value_of_SRCL(link) 
#define Symbol_ID_of_SRCD(srcd) ((srcd) .t_symbol_id) 
#define Symbol_ID_of_SRC(source) Symbol_ID_of_SRCD(*(source) ) 
#define Symbol_ID_of_SRCL(link) Symbol_ID_of_SRCD(SRCD_of_SRCL(link) ) 
#define LV_Symbol_ID_of_SRCL(link) Symbol_ID_of_SRCL(link)  \

#define Cause_AHFA_State_ID_of_SRC(source)  \
AHFAID_of_EIM((EIM) Cause_of_SRC(source) ) 
#define Leo_Transition_Symbol_ID_of_SRC(leo_source)  \
Postdot_SYMID_of_LIM((LIM) Predecessor_of_SRC(leo_source) )  \

#define First_Completion_Link_of_EIM(item) ((item) ->t_container.t_ambiguous.t_completion) 
#define LV_First_Completion_Link_of_EIM(item) First_Completion_Link_of_EIM(item) 
#define First_Token_Link_of_EIM(item) ((item) ->t_container.t_ambiguous.t_token) 
#define LV_First_Token_Link_of_EIM(item) First_Token_Link_of_EIM(item) 
#define First_Leo_SRCL_of_EIM(item) ((item) ->t_container.t_ambiguous.t_leo) 
#define LV_First_Leo_SRCL_of_EIM(item) First_Leo_SRCL_of_EIM(item)  \

#define LIM_is_Populated(leo) (Origin_of_LIM(leo) !=NULL) 
#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DECLARE(name,type) struct{gint ix;type*base;}name;
#define FSTACK_INIT(name,type,n) ((name.ix= 0) ,(name.base= g_new(type,n) ) ) 
#define FSTACK_PUSH(name) (name.base+name.ix++) 
#define FSTACK_POP(name) (--name.ix<0?NULL:name.base+name.ix) 
#define FSTACK_DESTROY(name) (g_free(name.base) )  \

#define DSTACK_DECLARE(this) struct dstack this
#define DSTACK_INIT(this,type,initial_size)  \
(((this) .t_ix= 0) , \
((this) .t_base= g_new(type,((this) .t_capacity= (initial_size) ) ) ) )  \

#define DSTACK_ZERO_INIT(this)  \
(((this) .t_ix= (this) .t_capacity= 0) ,((this) .t_base= NULL) )  \

#define DSTACK_REINIT(this) ((this) .t_ix= 0) 
#define DSTACK_PUSH(this,type)  \
(((this) .t_ix>=(this) .t_capacity?dstack_resize(&(this) ,sizeof(type) ) :0) , \
((type*) (this) .t_base+(this) .t_ix++) ) 
#define DSTACK_POP(this,type)  \
(--(this) .t_ix, \
(this) .t_ix<0?NULL:(type*) (this) .t_base+(this) .t_ix) 
#define DSTACK_BASE(this,type) ((type*) (this) .t_base) 
#define DSTACK_LENGTH(this) ((this) .t_ix)  \

#define STOLEN_DSTACK_DATA_FREE(data) ((data) &&(g_free(data) ,1) ) 
#define DSTACK_DESTROY(this) STOLEN_DSTACK_DATA_FREE(this.t_base)  \

#define DQUEUE_DECLARE(this) struct dqueue this
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

#define FATAL_FLAG (0x1u) 
#define CONTEXT_FLAG (0x2u) 
#define R_ERROR(message) (r_error(r,(message) ,0u) ) 
#define R_ERROR_CXT(message) (r_error(r,(message) ,CONTEXT_FLAG) ) 
#define R_FATAL(message) (r_error(r,(message) ,FATAL_FLAG) ) 
#define R_FATAL_CXT(message) (r_error(r,(message) ,CONTEXT_FLAG|FATAL_FLAG) ) 

#line 9647 "./marpa.w"

#include "marpa_obs.h"
/*1052:*/
#line 9443 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1052*/
#line 9649 "./marpa.w"

/*482:*/
#line 3782 "./marpa.w"
struct s_AHFA_state;
/*:482*//*664:*/
#line 5429 "./marpa.w"
struct s_earley_set;
/*:664*//*696:*/
#line 5717 "./marpa.w"
struct s_earley_item;
/*:696*/
#line 9650 "./marpa.w"

/*44:*/
#line 679 "./marpa.w"

typedef struct marpa_g*GRAMMAR;
typedef const struct marpa_g*GRAMMARC;

/*:44*//*215:*/
#line 1527 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:215*//*442:*/
#line 3466 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;

/*:442*//*484:*/
#line 3802 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:484*//*564:*/
#line 4912 "./marpa.w"
typedef struct marpa_r*RECCE;
/*:564*//*666:*/
#line 5449 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;

/*:666*//*697:*/
#line 5718 "./marpa.w"

typedef struct s_earley_item EIMD;
typedef EIMD*EIM;

/*:697*//*769:*/
#line 6537 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:769*//*771:*/
#line 6547 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:771*//*929:*/
#line 8391 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:929*//*981:*/
#line 8821 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:981*/
#line 9651 "./marpa.w"

/*30:*/
#line 559 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:30*//*52:*/
#line 712 "./marpa.w"
static gint next_grammar_id= 1;
/*:52*//*573:*/
#line 4963 "./marpa.w"
static gint next_recce_id= 1;
/*:573*//*930:*/
#line 8398 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:930*/
#line 9652 "./marpa.w"

/*1007:*/
#line 9047 "./marpa.w"

struct dstack{gint t_ix;gint t_capacity;gpointer t_base;};
/*:1007*/
#line 9653 "./marpa.w"

/*43:*/
#line 673 "./marpa.w"
struct marpa_g{
/*56:*/
#line 725 "./marpa.w"
GArray*symbols;
/*:56*//*66:*/
#line 773 "./marpa.w"
GArray*rules;
/*:66*//*104:*/
#line 955 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:104*//*107:*/
#line 968 "./marpa.w"
GHashTable*context;
/*:107*//*122:*/
#line 1061 "./marpa.w"

struct obstack obs;
struct obstack obs_tricky;
/*:122*//*126:*/
#line 1083 "./marpa.w"
Marpa_Error_ID error;
/*:126*//*207:*/
#line 1491 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
gpointer symbol_callback_arg;
/*:207*//*319:*/
#line 2244 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
gpointer rule_callback_arg;
/*:319*//*443:*/
#line 3475 "./marpa.w"

AIM AHFA_items;
AIM*AHFA_items_by_rule;
/*:443*//*485:*/
#line 3806 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:485*//*1056:*/
#line 9485 "./marpa.w"

Marpa_G_Message_Callback*message_callback;
gpointer message_callback_arg;
/*:1056*/
#line 674 "./marpa.w"

/*50:*/
#line 710 "./marpa.w"
gint t_id;
/*:50*//*78:*/
#line 830 "./marpa.w"
Marpa_Symbol_ID start_symid;
/*:78*//*85:*/
#line 877 "./marpa.w"
int t_size;
/*:85*//*88:*/
#line 890 "./marpa.w"
guint max_rule_length;
/*:88*//*444:*/
#line 3478 "./marpa.w"

guint no_of_items;
/*:444*//*486:*/
#line 3810 "./marpa.w"
gint t_AHFA_len;
/*:486*/
#line 675 "./marpa.w"

/*90:*/
#line 895 "./marpa.w"
unsigned int is_precomputed:1;
/*:90*//*94:*/
#line 906 "./marpa.w"
unsigned int has_loop:1;
/*:94*//*98:*/
#line 921 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:98*/
#line 676 "./marpa.w"

};
typedef struct marpa_g GRAMMARD;
/*:43*//*132:*/
#line 1101 "./marpa.w"

struct symbol{
/*140:*/
#line 1153 "./marpa.w"
GArray*lhs;
/*:140*//*147:*/
#line 1183 "./marpa.w"
GArray*rhs;
/*:147*//*194:*/
#line 1383 "./marpa.w"

struct symbol*alias;
/*:194*/
#line 1103 "./marpa.w"

/*138:*/
#line 1144 "./marpa.w"
Marpa_Symbol_ID t_id;
/*:138*/
#line 1104 "./marpa.w"

/*154:*/
#line 1204 "./marpa.w"
unsigned int is_accessible:1;
/*:154*//*160:*/
#line 1230 "./marpa.w"
unsigned int is_counted:1;
/*:160*//*164:*/
#line 1248 "./marpa.w"
unsigned int is_nullable:1;
/*:164*//*170:*/
#line 1273 "./marpa.w"
unsigned int is_nulling:1;
/*:170*//*176:*/
#line 1300 "./marpa.w"
unsigned int is_terminal:1;
/*:176*//*182:*/
#line 1329 "./marpa.w"
unsigned int is_productive:1;
/*:182*//*188:*/
#line 1354 "./marpa.w"
unsigned int is_start:1;
/*:188*//*193:*/
#line 1380 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:193*/
#line 1105 "./marpa.w"

};
typedef struct symbol*SYM;
typedef gint SYMID;

/*:132*//*214:*/
#line 1521 "./marpa.w"

struct s_rule{
/*244:*/
#line 1909 "./marpa.w"
guint length;
/*:244*//*264:*/
#line 1988 "./marpa.w"
Marpa_Rule_ID t_id;
/*:264*//*309:*/
#line 2206 "./marpa.w"
gint virtual_start;
/*:309*//*313:*/
#line 2222 "./marpa.w"
gint virtual_end;
/*:313*//*330:*/
#line 2279 "./marpa.w"
Marpa_Rule_ID original;
/*:330*//*335:*/
#line 2293 "./marpa.w"
guint real_symbol_count;
/*:335*/
#line 1523 "./marpa.w"

/*267:*/
#line 2000 "./marpa.w"
unsigned int is_discard:1;
/*:267*//*281:*/
#line 2084 "./marpa.w"
unsigned int is_loop:1;
/*:281*//*286:*/
#line 2105 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:286*//*293:*/
#line 2135 "./marpa.w"
unsigned int is_used:1;
/*:293*//*297:*/
#line 2151 "./marpa.w"
unsigned int t_is_start:1;
/*:297*//*301:*/
#line 2181 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:301*//*305:*/
#line 2192 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:305*//*339:*/
#line 2302 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:339*/
#line 1524 "./marpa.w"

/*245:*/
#line 1912 "./marpa.w"
Marpa_Symbol_ID symbols[1];

/*:245*/
#line 1525 "./marpa.w"

};
/*:214*//*441:*/
#line 3459 "./marpa.w"

struct s_AHFA_item{
Marpa_AHFA_Item_ID t_sort_key;
RULE t_production;
/*450:*/
#line 3501 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:450*/
#line 3463 "./marpa.w"

gint t_position;
};
/*:441*//*483:*/
#line 3783 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
AIM*t_items;
struct s_AHFA_state*t_empty_transition;
AHFA*t_to_ahfa_ary;
SYMID*t_complete_symbols;
/*496:*/
#line 3864 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:496*/
#line 3793 "./marpa.w"

/*497:*/
#line 3865 "./marpa.w"
guint t_postdot_sym_count;

/*:497*//*520:*/
#line 4075 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:520*/
#line 3794 "./marpa.w"

guint t_item_count;
guint t_complete_symbol_count;
guint t_is_predict:1;
guint t_has_completed_start_rule:1;
};
typedef struct s_AHFA_state AHFAD;

/*:483*//*565:*/
#line 4913 "./marpa.w"
struct marpa_r{
/*578:*/
#line 4974 "./marpa.w"
const struct marpa_g*t_grammar;

/*:578*//*584:*/
#line 5002 "./marpa.w"

GSequence*earley_sets;
/*:584*//*587:*/
#line 5014 "./marpa.w"

GSequenceIter*t_current_earley_set_iter;
/*:587*//*600:*/
#line 5066 "./marpa.w"
DSTACK_DECLARE(completion_stack);

/*:600*//*601:*/
#line 5078 "./marpa.w"
gpointer*t_sym_workarea;
/*:601*//*604:*/
#line 5092 "./marpa.w"
gpointer*t_workarea2;
/*:604*//*607:*/
#line 5112 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:607*//*611:*/
#line 5138 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:611*//*639:*/
#line 5316 "./marpa.w"
GHashTable*context;
/*:639*//*650:*/
#line 5371 "./marpa.w"
struct obstack obs;
/*:650*//*654:*/
#line 5385 "./marpa.w"

Marpa_Error_ID t_error;
Marpa_Error_ID t_fatal_error;
/*:654*//*681:*/
#line 5601 "./marpa.w"

GSequenceIter*t_trace_earley_set_iter;
struct s_earley_set*t_trace_earley_set;
/*:681*//*716:*/
#line 5901 "./marpa.w"

GSequenceIter*t_trace_earley_item_iter;
EIM t_trace_earley_item;
/*:716*//*752:*/
#line 6337 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:752*//*794:*/
#line 6830 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:794*//*1064:*/
#line 9520 "./marpa.w"

Marpa_R_Message_Callback*message_callback;
gpointer message_callback_arg;
/*:1064*/
#line 4914 "./marpa.w"

/*571:*/
#line 4961 "./marpa.w"
gint t_id;
/*:571*//*580:*/
#line 4987 "./marpa.w"

Marpa_Phase t_phase;
/*:580*//*590:*/
#line 5024 "./marpa.w"
guint earley_item_warning_threshold;
/*:590*//*596:*/
#line 5052 "./marpa.w"
Marpa_Earleme t_furthest_earleme;
/*:596*/
#line 4915 "./marpa.w"

/*617:*/
#line 5175 "./marpa.w"
unsigned int t_is_trace_earley_sets:1;
/*:617*//*631:*/
#line 5261 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:631*//*637:*/
#line 5301 "./marpa.w"

unsigned int t_is_leo_expanding:1;
/*:637*//*795:*/
#line 6833 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:795*/
#line 4916 "./marpa.w"

};

/*:565*//*665:*/
#line 5436 "./marpa.w"

struct s_earley_set_key{
Marpa_Earleme t_id;
};
typedef struct s_earley_set_key ESKD;
typedef ESKD*ESK;
struct s_earley_set{
ESKD t_key;
GSequence*t_eims;
union u_postdot_item**t_postdot_ary;
gint t_postdot_sym_count;
guint t_eim_count;
};
/*:665*//*730:*/
#line 6089 "./marpa.w"

union u_postdot_item;
struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIXD;
typedef EIXD*EIX;

/*:730*//*732:*/
#line 6128 "./marpa.w"

struct s_leo_item;
struct s_leo_item{
EIXD t_earley_ix;
ES t_origin;
AHFA t_top_ahfa;
struct s_leo_item*t_predecessor;
EIM t_base;
ES t_set;
};
typedef struct s_leo_item LIMD;
typedef LIMD*LIM;

/*:732*//*745:*/
#line 6274 "./marpa.w"

union u_postdot_item{
LIMD t_leo;
EIXD t_earley;
};
typedef union u_postdot_item*PIM;

/*:745*//*1011:*/
#line 9081 "./marpa.w"

struct dqueue{gint current;struct dstack s;};

/*:1011*/
#line 9654 "./marpa.w"

/*770:*/
#line 6540 "./marpa.w"

struct s_source{
gpointer t_predecessor;
gpointer t_cause;
SYMID t_symbol_id;
};

/*:770*//*772:*/
#line 6550 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:772*//*773:*/
#line 6556 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:773*//*774:*/
#line 6563 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:774*/
#line 9655 "./marpa.w"

/*698:*/
#line 5722 "./marpa.w"

struct s_earley_item_key{
AHFA t_state;
ES t_origin;
};
typedef struct s_earley_item_key EIKD;
typedef EIKD*EIK;
struct s_earley_item{
EIKD t_key;
ES t_set;
union u_source_container t_container;
/*712:*/
#line 5861 "./marpa.w"

unsigned int t_source_type:3;

/*:712*//*713:*/
#line 5872 "./marpa.w"

unsigned int t_is_leo_expanded:1;

/*:713*/
#line 5733 "./marpa.w"

};

/*:698*/
#line 9656 "./marpa.w"

/*65:*/
#line 766 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid);

/*:65*//*72:*/
#line 793 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g);

/*:72*//*74:*/
#line 801 "./marpa.w"

static inline RULE
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id);

/*:74*//*77:*/
#line 825 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:77*//*115:*/
#line 1019 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:115*//*117:*/
#line 1031 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:117*//*119:*/
#line 1040 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g);

/*:119*//*134:*/
#line 1131 "./marpa.w"

static inline
struct symbol*symbol_new(struct marpa_g*g);
/*:134*//*137:*/
#line 1140 "./marpa.w"

static inline void symbol_free(struct symbol*symbol);

/*:137*//*146:*/
#line 1174 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id);

/*:146*//*153:*/
#line 1200 "./marpa.w"
static inline
void symbol_rhs_add(struct symbol*symbol,Marpa_Rule_ID rule_id);

/*:153*//*191:*/
#line 1367 "./marpa.w"

static inline
gint symbol_is_start(struct symbol*symbol);
/*:191*//*197:*/
#line 1408 "./marpa.w"

static inline struct symbol*symbol_proper_alias(struct symbol*symbol);
/*:197*//*200:*/
#line 1436 "./marpa.w"

static inline struct symbol*symbol_null_alias(struct symbol*symbol);
/*:200*//*203:*/
#line 1475 "./marpa.w"

static inline
struct symbol*symbol_alias_create(struct marpa_g*g,
struct symbol*symbol);
/*:203*//*212:*/
#line 1515 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:212*//*217:*/
#line 1536 "./marpa.w"

static inline guint rule_sizeof(guint length);

/*:217*//*221:*/
#line 1561 "./marpa.w"

static
RULE rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:221*//*237:*/
#line 1790 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length);

/*:237*//*249:*/
#line 1934 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
/*:249*//*253:*/
#line 1946 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule);
/*:253*//*257:*/
#line 1962 "./marpa.w"

static inline gsize rule_length_get(RULE rule);
/*:257*//*263:*/
#line 1981 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symid(RULE rule,guint rh_index);

/*:263*//*274:*/
#line 2049 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule);
/*:274*//*278:*/
#line 2073 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule);
/*:278*//*292:*/
#line 2131 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,RULE rule);

/*:292*//*328:*/
#line 2272 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:328*//*347:*/
#line 2411 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:347*//*384:*/
#line 2762 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:384*//*423:*/
#line 3129 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:423*//*426:*/
#line 3150 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:426*//*434:*/
#line 3275 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:434*//*463:*/
#line 3567 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:463*//*465:*/
#line 3594 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:465*//*472:*/
#line 3663 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:472*//*492:*/
#line 3840 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id);

/*:492*//*495:*/
#line 3855 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const AHFA state,guint item_ix);

/*:495*//*525:*/
#line 4129 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);

/*:525*//*527:*/
#line 4161 "./marpa.w"

static void create_AHFA_states(struct marpa_g*g);

/*:527*//*539:*/
#line 4547 "./marpa.w"

static inline AHFA assign_AHFA_state(
AHFA state_p,GSequence*duplicates);

/*:539*//*551:*/
#line 4721 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:551*//*555:*/
#line 4830 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
struct dqueue*states_p,
GSequence*duplicates
);

/*:555*//*558:*/
#line 4877 "./marpa.w"
static inline
AHFA*to_ahfa_array_new(struct marpa_g*g);
/*:558*//*561:*/
#line 4895 "./marpa.w"
static inline
void AHFA_transition_add(AHFA from_ahfa,SYMID symid,AHFA to_ahfa);

/*:561*//*643:*/
#line 5337 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint value);
/*:643*//*645:*/
#line 5349 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*value);

/*:645*//*647:*/
#line 5358 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r);

/*:647*//*667:*/
#line 5454 "./marpa.w"

static inline ES earley_set_new(struct marpa_r*r,
Marpa_Earleme id);
/*:667*//*669:*/
#line 5473 "./marpa.w"

static inline GSequenceIter*later_earley_set_assign(
struct marpa_r*r,Marpa_Earleme sought_earleme,
ES*set_p);
/*:669*//*675:*/
#line 5550 "./marpa.w"

static inline void earley_set_free(gpointer p);

/*:675*//*677:*/
#line 5565 "./marpa.w"

static gint earley_set_cmp(
gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);

/*:677*//*680:*/
#line 5590 "./marpa.w"

static inline ES earley_set_by_id(struct marpa_r*r,Marpa_Earleme earleme);

/*:680*//*699:*/
#line 5742 "./marpa.w"

static inline EIM earley_item_new(struct marpa_r*r,
ES set,EIKD key);
/*:699*//*701:*/
#line 5758 "./marpa.w"

static inline EIM earley_item_assign(struct marpa_r*r,
ES set,
ES origin,
AHFA state);
/*:701*//*708:*/
#line 5831 "./marpa.w"

static gint own_earley_item_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);
static inline gint earley_item_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);

/*:708*//*714:*/
#line 5875 "./marpa.w"

static const char*invalid_source_type_message(guint type);
/*:714*//*726:*/
#line 6050 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r);
/*:726*//*728:*/
#line 6059 "./marpa.w"

Marpa_Earleme marpa_earley_item_origin(struct marpa_r*r);
/*:728*//*734:*/
#line 6146 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r);
/*:734*//*737:*/
#line 6187 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r);
/*:737*//*739:*/
#line 6208 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r);
/*:739*//*748:*/
#line 6290 "./marpa.w"

static inline PIM*pim_sym_p_find(ES set,SYMID symid);
/*:748*//*750:*/
#line 6322 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid);
/*:750*//*761:*/
#line 6465 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r);
/*:761*//*779:*/
#line 6633 "./marpa.w"
static inline void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
SYMID token_id,
gpointer value);

/*:779*//*780:*/
#line 6640 "./marpa.w"
static inline void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause);
/*:780*//*787:*/
#line 6752 "./marpa.w"
static inline void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause);

/*:787*//*790:*/
#line 6793 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item);

/*:790*//*820:*/
#line 7088 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r);
/*:820*//*876:*/
#line 7743 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES set);
/*:876*//*906:*/
#line 8166 "./marpa.w"

gint leo_completion_expand(RECCE r,EIM leo_completion);
/*:906*//*932:*/
#line 8411 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:932*//*934:*/
#line 8421 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:934*//*936:*/
#line 8441 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);

/*:936*//*938:*/
#line 8452 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:938*//*940:*/
#line 8471 "./marpa.w"

static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from);

/*:940*//*942:*/
#line 8484 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:942*//*944:*/
#line 8494 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:944*//*946:*/
#line 8502 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:946*//*948:*/
#line 8515 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:948*//*950:*/
#line 8519 "./marpa.w"

static inline void bv_clear(Bit_Vector bv);
/*:950*//*954:*/
#line 8534 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:954*//*956:*/
#line 8542 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:956*//*958:*/
#line 8550 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:958*//*961:*/
#line 8567 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:961*//*963:*/
#line 8580 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:963*//*965:*/
#line 8592 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:965*//*967:*/
#line 8604 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:967*//*969:*/
#line 8616 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:969*//*971:*/
#line 8690 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:971*//*973:*/
#line 8708 "./marpa.w"

static inline guint bv_count(Bit_Vector v);

/*:973*//*979:*/
#line 8797 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:979*//*984:*/
#line 8845 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:984*//*986:*/
#line 8853 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:986*//*988:*/
#line 8867 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:988*//*990:*/
#line 8885 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:990*//*993:*/
#line 8894 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:993*//*996:*/
#line 8903 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:996*//*999:*/
#line 8912 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:999*//*1001:*/
#line 8965 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:1001*//*1009:*/
#line 9055 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:1009*//*1015:*/
#line 9122 "./marpa.w"

static inline GSequenceIter*sequence_find(GSequence*sequence,void*key,
GCompareDataFunc compare,gboolean*match);

/*:1015*//*1049:*/
#line 9410 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags);
/*:1049*//*1061:*/
#line 9512 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id);

/*:1061*//*1069:*/
#line 9541 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id);

/*:1069*//*1071:*/
#line 9566 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*eim_tag(gchar*buffer,EIM eim);
#endif
/*:1071*//*1073:*/
#line 9585 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim);
#endif
/*:1073*/
#line 9657 "./marpa.w"

/*63:*/
#line 750 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symid,
struct symbol*symbol)
{
g_array_insert_val(g->symbols,(unsigned)symid,symbol);
}

/*:63*//*75:*/
#line 807 "./marpa.w"

static inline
void marpa_g_rule_add(
struct marpa_g*g,
Marpa_Rule_ID rule_id,
RULE rule)
{
g_array_insert_val(g->rules,(unsigned)rule_id,rule);
LV_Size_of_G(g)+= 1+rule->length;
g->max_rule_length= MAX(rule->length,g->max_rule_length);
}

/*:75*/
#line 9658 "./marpa.w"

/*31:*/
#line 566 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:31*//*45:*/
#line 683 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*53:*/
#line 713 "./marpa.w"

g->t_id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:53*//*57:*/
#line 726 "./marpa.w"

g->symbols= g_array_new(FALSE,FALSE,sizeof(struct symbol*));
/*:57*//*67:*/
#line 774 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:67*//*79:*/
#line 831 "./marpa.w"

g->start_symid= -1;
/*:79*//*86:*/
#line 878 "./marpa.w"

LV_Size_of_G(g)= 0;

/*:86*//*89:*/
#line 891 "./marpa.w"

g->max_rule_length= 0;

/*:89*//*91:*/
#line 896 "./marpa.w"

g->is_precomputed= FALSE;
/*:91*//*95:*/
#line 907 "./marpa.w"

g->has_loop= FALSE;
/*:95*//*99:*/
#line 922 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:99*//*105:*/
#line 956 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:105*//*108:*/
#line 969 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:108*//*123:*/
#line 1064 "./marpa.w"

obstack_init(&g->obs);
obstack_init(&g->obs_tricky);
/*:123*//*127:*/
#line 1084 "./marpa.w"

g->error= NULL;
/*:127*//*208:*/
#line 1494 "./marpa.w"

g->symbol_callback_arg= NULL;
g->symbol_callback= NULL;
/*:208*//*320:*/
#line 2247 "./marpa.w"

g->rule_callback_arg= NULL;
g->rule_callback= NULL;
/*:320*//*446:*/
#line 3483 "./marpa.w"

g->AHFA_items= NULL;
g->AHFA_items_by_rule= NULL;
/*:446*//*487:*/
#line 3811 "./marpa.w"

g->t_AHFA= NULL;
LV_AHFA_Count_of_G(g)= 0;
/*:487*//*1057:*/
#line 9488 "./marpa.w"

g->message_callback_arg= NULL;
g->message_callback= NULL;
/*:1057*/
#line 686 "./marpa.w"

return g;}
/*:45*//*47:*/
#line 691 "./marpa.w"

void marpa_g_free(struct marpa_g*g)
{/*58:*/
#line 728 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->symbols->len;id++)
{symbol_free(SYM_by_ID(g,id));}}
g_array_free(g->symbols,TRUE);

/*:58*//*68:*/
#line 776 "./marpa.w"

g_array_free(g->rules,TRUE);

/*:68*//*106:*/
#line 957 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:106*//*109:*/
#line 971 "./marpa.w"
g_hash_table_destroy(g->context);

/*:109*//*124:*/
#line 1067 "./marpa.w"

obstack_free(&g->obs,NULL);
obstack_free(&g->obs_tricky,NULL);

/*:124*//*447:*/
#line 3486 "./marpa.w"

if(g->AHFA_items){g_free(g->AHFA_items);};
if(g->AHFA_items_by_rule){g_free(g->AHFA_items_by_rule);};

/*:447*//*488:*/
#line 3815 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_by_ID(id);
/*489:*/
#line 3825 "./marpa.w"
{
AHFA*ahfa_transition_array= ahfa_state->t_to_ahfa_ary;
if(ahfa_transition_array)g_free(ahfa_state->t_to_ahfa_ary);
}

/*:489*/
#line 3819 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:488*/
#line 693 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:47*//*54:*/
#line 715 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->t_id;}
/*:54*//*59:*/
#line 736 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:59*//*64:*/
#line 761 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid){
return symid>=0&&(guint)symid<g->symbols->len;
}
/*:64*//*69:*/
#line 782 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:69*//*71:*/
#line 789 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g){
return g->rules->len;
}
/*:71*//*73:*/
#line 797 "./marpa.w"

static inline RULE
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id)
{return g_array_index(g->rules,RULE,id);}
/*:73*//*76:*/
#line 820 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_id>=0&&(guint)rule_id<g->rules->len;
}
/*:76*//*80:*/
#line 834 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->start_symid;}
/*:80*//*82:*/
#line 841 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1029:*/
#line 9262 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1029*/
#line 844 "./marpa.w"

if(g->is_precomputed){
g_context_clear(g);
g->error= "precomputed";
return failure_indicator;
}
/*1033:*/
#line 9278 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1033*/
#line 850 "./marpa.w"

g->start_symid= symid;
return TRUE;
}
/*:82*//*92:*/
#line 899 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{return g->is_precomputed;}
/*:92*//*96:*/
#line 910 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->has_loop;}
/*:96*//*100:*/
#line 925 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:100*//*102:*/
#line 932 "./marpa.w"

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
/*:102*//*114:*/
#line 1010 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:114*//*116:*/
#line 1022 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:116*//*118:*/
#line 1037 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:118*//*120:*/
#line 1043 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:120*//*129:*/
#line 1092 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g)
{return g->error?g->error:"unknown error";}
/*:129*//*133:*/
#line 1110 "./marpa.w"

static inline struct symbol*
symbol_new(struct marpa_g*g)
{
struct symbol*symbol= g_malloc(sizeof(struct symbol));
/*139:*/
#line 1145 "./marpa.w"
symbol->t_id= g->symbols->len;

/*:139*//*141:*/
#line 1154 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:141*//*148:*/
#line 1184 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:148*//*155:*/
#line 1205 "./marpa.w"

symbol->is_accessible= FALSE;
/*:155*//*161:*/
#line 1231 "./marpa.w"

symbol->is_counted= FALSE;
/*:161*//*165:*/
#line 1249 "./marpa.w"

symbol->is_nullable= FALSE;
/*:165*//*171:*/
#line 1274 "./marpa.w"

symbol->is_nulling= FALSE;
/*:171*//*177:*/
#line 1301 "./marpa.w"

symbol->is_terminal= FALSE;
/*:177*//*183:*/
#line 1330 "./marpa.w"

symbol->is_productive= FALSE;
/*:183*//*189:*/
#line 1355 "./marpa.w"
symbol->is_start= FALSE;
/*:189*//*195:*/
#line 1385 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:195*/
#line 1115 "./marpa.w"

{
Marpa_Symbol_ID id= symbol->t_id;
g_symbol_add(g,id,symbol);
}
return symbol;
}

Marpa_Symbol_ID
marpa_symbol_new(struct marpa_g*g)
{
Marpa_Symbol_ID id= symbol_new(g)->t_id;
symbol_callback(g,id);
return id;
}

/*:133*//*136:*/
#line 1137 "./marpa.w"

static inline void symbol_free(struct symbol*symbol)
{/*142:*/
#line 1156 "./marpa.w"

g_array_free(symbol->lhs,TRUE);
/*:142*//*149:*/
#line 1186 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:149*/
#line 1139 "./marpa.w"
g_free(symbol);}
/*:136*//*143:*/
#line 1161 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1030:*/
#line 9264 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1030*/
#line 1163 "./marpa.w"

/*1033:*/
#line 9278 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1033*/
#line 1164 "./marpa.w"

return SYM_by_ID(g,symid)->lhs;}
/*:143*//*145:*/
#line 1168 "./marpa.w"
static inline
void symbol_lhs_add(struct symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id)
{symbol_lhs_add(SYM_by_ID(g,symid),rule_id);}
/*:145*//*150:*/
#line 1190 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1030:*/
#line 9264 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1030*/
#line 1192 "./marpa.w"

/*1033:*/
#line 9278 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1033*/
#line 1193 "./marpa.w"

return SYM_by_ID(g,symid)->rhs;}
/*:150*//*152:*/
#line 1197 "./marpa.w"
static inline
void symbol_rhs_add(struct symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
/*:152*//*156:*/
#line 1215 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->is_accessible;}
/*:156*//*158:*/
#line 1221 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->is_accessible= value;}
/*:158*//*162:*/
#line 1241 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->is_counted;}
/*:162*//*166:*/
#line 1259 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->is_nullable;}
/*:166*//*168:*/
#line 1265 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->is_nullable= value;}
/*:168*//*172:*/
#line 1284 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 1286 "./marpa.w"

/*1033:*/
#line 9278 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1033*/
#line 1287 "./marpa.w"

return SYM_by_ID(g,symid)->is_nulling;}
/*:172*//*174:*/
#line 1292 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->is_nulling= value;}
/*:174*//*178:*/
#line 1314 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYMID_is_Terminal(g,id);}
/*:178*//*180:*/
#line 1320 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{LV_SYMID_is_Terminal(g,id)= value;}
/*:180*//*184:*/
#line 1340 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->is_productive;}
/*:184*//*186:*/
#line 1346 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->is_productive= value?1:0;}
/*:186*//*190:*/
#line 1358 "./marpa.w"

static inline
gint symbol_is_start(struct symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 1363 "./marpa.w"

/*1033:*/
#line 9278 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1033*/
#line 1364 "./marpa.w"

return symbol_is_start(SYM_by_ID(g,symid));
}
/*:190*//*196:*/
#line 1394 "./marpa.w"

static inline
struct symbol*symbol_proper_alias(struct symbol*symbol)
{return symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
struct symbol*symbol;
struct symbol*proper_alias;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 1402 "./marpa.w"

/*1033:*/
#line 9278 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1033*/
#line 1403 "./marpa.w"

symbol= SYM_by_ID(g,symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->t_id;
}
/*:196*//*199:*/
#line 1417 "./marpa.w"

static inline
struct symbol*symbol_null_alias(struct symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
struct symbol*symbol;
struct symbol*alias;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 1425 "./marpa.w"

/*1033:*/
#line 9278 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1033*/
#line 1426 "./marpa.w"

symbol= SYM_by_ID(g,symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
g_context_int_add(g,"symid",symid);
g->error= "no alias";
return-1;
}
return alias->t_id;
}
/*:199*//*202:*/
#line 1450 "./marpa.w"
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
alias_id= symbol_alias_create(g,SYM_by_ID(g,original_id))->t_id;
symbol_callback(g,alias_id);
return alias_id;}
/*:202*//*209:*/
#line 1497 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->symbol_callback_arg= cb_arg;}
gpointer marpa_symbol_callback_arg(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:209*//*211:*/
#line 1511 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:211*//*216:*/
#line 1532 "./marpa.w"

static inline guint rule_sizeof(guint length){
return sizeof(struct s_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:216*//*220:*/
#line 1546 "./marpa.w"

static
RULE rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
/*1030:*/
#line 9264 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1030*/
#line 1551 "./marpa.w"

RULE rule;
/*246:*/
#line 1914 "./marpa.w"

{
SYMID symid= lhs;
/*1033:*/
#line 9278 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1033*/
#line 1917 "./marpa.w"

}
{guint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1033:*/
#line 9278 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1033*/
#line 1922 "./marpa.w"

}
}

/*:246*/
#line 1553 "./marpa.w"

rule= obstack_alloc(&g->obs,rule_sizeof(length));
/*247:*/
#line 1926 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{guint i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:247*/
#line 1555 "./marpa.w"

/*265:*/
#line 1989 "./marpa.w"
rule->t_id= g->rules->len;

/*:265*//*268:*/
#line 2001 "./marpa.w"

rule->is_discard= FALSE;
/*:268*//*282:*/
#line 2085 "./marpa.w"

rule->is_loop= FALSE;
/*:282*//*287:*/
#line 2106 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:287*//*294:*/
#line 2136 "./marpa.w"

rule->is_used= TRUE;
/*:294*//*298:*/
#line 2152 "./marpa.w"

rule->t_is_start= FALSE;
/*:298*//*302:*/
#line 2182 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:302*//*306:*/
#line 2193 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:306*//*310:*/
#line 2207 "./marpa.w"
rule->virtual_start= -1;
/*:310*//*314:*/
#line 2223 "./marpa.w"
rule->virtual_end= -1;
/*:314*//*331:*/
#line 2280 "./marpa.w"
rule->original= -1;
/*:331*//*336:*/
#line 2294 "./marpa.w"
rule->real_symbol_count= 0;
/*:336*//*340:*/
#line 2303 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:340*/
#line 1556 "./marpa.w"

marpa_g_rule_add(g,rule->t_id,rule);
/*239:*/
#line 1807 "./marpa.w"

symbol_lhs_add(SYM_by_ID(g,rule->symbols[0]),rule->t_id);
if(rule->length> 0){
gint rh_list_ix;
const guint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*243:*/
#line 1874 "./marpa.w"

{

gint rhs_ix= (gint)rule->length-1;
rh_symbol_list[0]= rhs_symid(rule,(unsigned)rhs_ix);
rh_symbol_list_length= 1;
rhs_ix--;
for(;rhs_ix>=0;rhs_ix--){
gint higher_ix;
Marpa_Symbol_ID new_symid= rhs_symid(rule,(unsigned)rhs_ix);
gint next_highest_ix= rh_symbol_list_length-1;
while(next_highest_ix>=0){
Marpa_Symbol_ID current_symid= rh_symbol_list[next_highest_ix];
if(current_symid==new_symid)goto ignore_this_symbol;
if(current_symid<new_symid)break;
next_highest_ix--;
}

for(higher_ix= rh_symbol_list_length-1;
higher_ix> next_highest_ix;
higher_ix--){
rh_symbol_list[higher_ix+1]= rh_symbol_list[higher_ix];
}

rh_symbol_list[next_highest_ix+1]= new_symid;
rh_symbol_list_length++;
ignore_this_symbol:;
}
}

/*:243*/
#line 1815 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(g,rh_symbol_list[rh_list_ix]),
rule->t_id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:239*/
#line 1558 "./marpa.w"

return rule;
}
/*:220*//*222:*/
#line 1566 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
Marpa_Rule_ID rule_id;
RULE rule;
if(is_rule_duplicate(g,lhs,rhs,length)==TRUE){
g->error= (Marpa_Error_ID)"duplicate rule";
return-1;
}
rule= rule_start(g,lhs,rhs,length);
if(!rule){return-1;}
rule_id= rule->t_id;
rule_callback(g,rule_id);
return rule_id;
}

/*:222*//*223:*/
#line 1583 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 1588 "./marpa.w"

Marpa_Rule_ID original_rule_id;
RULE original_rule;
Marpa_Symbol_ID internal_lhs_id,*temp_rhs;
if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE){
g_context_clear(g);
g->error= (Marpa_Error_ID)"duplicate rule";
return failure_indicator;
}

/*225:*/
#line 1619 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){
g_context_clear(g);
g->error= "internal_error";
return failure_indicator;
}
original_rule->is_used= 0;
original_rule_id= original_rule->t_id;
rule_callback(g,original_rule_id);

/*:225*/
#line 1598 "./marpa.w"

/*226:*/
#line 1630 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g_context_clear(g);
g_context_int_add(g,"symid",separator_id);
g->error= "bad separator";
return failure_indicator;
}

/*:226*/
#line 1599 "./marpa.w"

/*227:*/
#line 1638 "./marpa.w"

SYM_by_ID(g,rhs_id)->is_counted= 1;
if(separator_id>=0){SYM_by_ID(g,separator_id)->is_counted= 1;}
/*:227*/
#line 1600 "./marpa.w"

if(min==0){/*228:*/
#line 1641 "./marpa.w"

{RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1038:*/
#line 9313 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1038*/
#line 1643 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->t_id);
}
/*:228*/
#line 1601 "./marpa.w"
}
min= 1;
/*229:*/
#line 1648 "./marpa.w"

internal_lhs_id= symbol_new(g)->t_id;
symbol_callback(g,internal_lhs_id);
/*:229*/
#line 1603 "./marpa.w"

/*230:*/
#line 1662 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:230*/
#line 1604 "./marpa.w"

/*232:*/
#line 1665 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1038:*/
#line 9313 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1038*/
#line 1669 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->t_id);
}
/*:232*/
#line 1605 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*233:*/
#line 1678 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1038:*/
#line 9313 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1038*/
#line 1683 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->t_id);
}
/*:233*/
#line 1607 "./marpa.w"

}
/*234:*/
#line 1695 "./marpa.w"

{RULE rule;
guint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1038:*/
#line 9313 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1038*/
#line 1705 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->t_id);
}
/*:234*/
#line 1609 "./marpa.w"

/*235:*/
#line 1710 "./marpa.w"

{RULE rule;
guint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1038:*/
#line 9313 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1038*/
#line 1717 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->t_id);
}

/*:235*/
#line 1610 "./marpa.w"

/*231:*/
#line 1664 "./marpa.w"
g_free(temp_rhs);
/*:231*/
#line 1611 "./marpa.w"

return original_rule_id;
}
/*:223*//*236:*/
#line 1766 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length)
{
guint ix;
struct symbol*lhs= SYM_by_ID(g,lhs_id);
GArray*same_lhs_array= lhs->lhs;
guint same_lhs_count= same_lhs_array->len;
for(ix= 0;ix<same_lhs_count;ix++){
Marpa_Rule_ID same_lhs_rule_id= ((Marpa_Rule_ID*)(same_lhs_array->data))[ix];
guint rhs_position;
RULE rule= rule_id2p(g,same_lhs_rule_id);
if(rule->length!=length){goto RULE_IS_NOT_DUPLICATE;}
for(rhs_position= 0;rhs_position<rule->length;rhs_position++){
if(rhs_symid(rule,rhs_position)!=rhs_ids[rhs_position]){
goto RULE_IS_NOT_DUPLICATE;
}
}
return TRUE;
RULE_IS_NOT_DUPLICATE:;
}
return FALSE;
}
/*:236*//*248:*/
#line 1931 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule){
return rule->symbols[0];}
/*:248*//*250:*/
#line 1936 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 1938 "./marpa.w"

/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 1939 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:250*//*252:*/
#line 1943 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule){
return rule->symbols+1;}
/*:252*//*254:*/
#line 1948 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix){
RULE rule;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 1951 "./marpa.w"

/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 1952 "./marpa.w"

rule= rule_id2p(g,rule_id);
if(rule->length<=ix)return-1;
return rhs_symid(rule,ix);
}
/*:254*//*256:*/
#line 1959 "./marpa.w"

static inline gsize rule_length_get(RULE rule){
return rule->length;}
/*:256*//*258:*/
#line 1964 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 1966 "./marpa.w"

/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 1967 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:258*//*262:*/
#line 1976 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symid(RULE rule,guint rh_index){
return rule->symbols[rh_index+1];
}
/*:262*//*269:*/
#line 2003 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:269*//*273:*/
#line 2036 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_PRD(rule);
return SYM_by_ID(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 2043 "./marpa.w"

RULE rule;
/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 2045 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:273*//*277:*/
#line 2056 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symid(rule,rh_ix);
if(!SYM_by_ID(g,rhs_id)->is_productive)return FALSE;
}
return TRUE;}
gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 2067 "./marpa.w"

RULE rule;
/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 2069 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:277*//*283:*/
#line 2089 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 2092 "./marpa.w"

/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 2093 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:283*//*288:*/
#line 2110 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 2113 "./marpa.w"

/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 2114 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:288*//*291:*/
#line 2122 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,RULE rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symid(rule,rh_ix);
if(!SYM_by_ID(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:291*//*295:*/
#line 2140 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 2143 "./marpa.w"

/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 2144 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:295*//*299:*/
#line 2156 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 2159 "./marpa.w"

/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 2160 "./marpa.w"

return rule_id2p(g,rule_id)->t_is_start;}
/*:299*//*303:*/
#line 2185 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:303*//*307:*/
#line 2196 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:307*//*311:*/
#line 2208 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 2211 "./marpa.w"

/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 2212 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_start;
}
/*:311*//*315:*/
#line 2224 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 2227 "./marpa.w"

/*1034:*/
#line 9285 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1034*/
#line 2228 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_end;
}
/*:315*//*321:*/
#line 2250 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:321*//*323:*/
#line 2255 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:323*//*325:*/
#line 2260 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:325*//*327:*/
#line 2268 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:327*//*332:*/
#line 2281 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}
/*:332*//*337:*/
#line 2295 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}
/*:337*//*341:*/
#line 2314 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
RULE rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:341*//*343:*/
#line 2333 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
if(!census(g))return NULL;
if(!CHAF_rewrite(g))return NULL;
if(!g_augment(g))return NULL;
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*562:*/
#line 4899 "./marpa.w"
{
gint symbol_count= SYM_Count_of_G(g);
gint symid;
Bit_Vector bv_is_terminal= bv_create((guint)symbol_count);
g->t_bv_symid_is_terminal= bv_is_terminal;
for(symid= 0;symid<symbol_count;symid++){
if(!SYMID_is_Terminal(g,symid))continue;
bv_bit_set(bv_is_terminal,(guint)symid);
}
}

/*:562*/
#line 2342 "./marpa.w"

return g;
}
/*:343*//*346:*/
#line 2380 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*1030:*/
#line 9264 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1030*/
#line 2383 "./marpa.w"

/*348:*/
#line 2413 "./marpa.w"

guint pre_rewrite_rule_count= g->rules->len;
guint pre_rewrite_symbol_count= g->symbols->len;

/*:348*//*353:*/
#line 2450 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->start_symid;
struct symbol*original_start_symbol;

/*:353*//*357:*/
#line 2489 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:357*//*363:*/
#line 2548 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:363*//*365:*/
#line 2575 "./marpa.w"

Bit_Vector nullable_v;
/*:365*//*369:*/
#line 2601 "./marpa.w"

Bit_Vector productive_v;
/*:369*//*372:*/
#line 2642 "./marpa.w"
Bit_Matrix reach_matrix;
/*:372*//*375:*/
#line 2660 "./marpa.w"

Bit_Vector accessible_v;

/*:375*/
#line 2384 "./marpa.w"

/*349:*/
#line 2417 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:349*/
#line 2385 "./marpa.w"

/*350:*/
#line 2424 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:350*/
#line 2386 "./marpa.w"

/*352:*/
#line 2430 "./marpa.w"

if(original_start_symid<0){
g_context_clear(g);
g->error= "no start symbol";
return failure_indicator;
}
if(!symbol_is_valid(g,original_start_symid)){
g_context_clear(g);
g_context_int_add(g,"symid",original_start_symid);
g->error= "invalid start symbol";
return failure_indicator;
}
original_start_symbol= SYM_by_ID(g,original_start_symid);
if(original_start_symbol->lhs->len<=0){
g_context_clear(g);
g_context_int_add(g,"symid",original_start_symid);
g->error= "start symbol not on LHS";
return failure_indicator;
}

/*:352*/
#line 2387 "./marpa.w"

/*354:*/
#line 2454 "./marpa.w"

{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;
rule_id<(Marpa_Rule_ID)pre_rewrite_rule_count;
rule_id++){
RULE rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_PRD(rule);
bv_bit_set(lhs_v,(guint)lhs_id);
if(rule->length<=0){
bv_bit_set(empty_lhs_v,(guint)lhs_id);
have_empty_rule= 1;
}
}
}
/*:354*/
#line 2388 "./marpa.w"

/*355:*/
#line 2473 "./marpa.w"

{Marpa_Symbol_ID symid;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symid= 0;
symid<(Marpa_Symbol_ID)pre_rewrite_symbol_count;
symid++){
struct symbol*symbol= SYM_by_ID(g,symid);
if(SYM_is_Terminal(symbol)){
bv_bit_set(terminal_v,(guint)symid);
have_marked_terminals= 1;
}
}}
/*:355*/
#line 2389 "./marpa.w"

if(have_marked_terminals){
/*359:*/
#line 2504 "./marpa.w"

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
g_context_int_add(g,"symid",i);
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

/*:359*/
#line 2391 "./marpa.w"

}else{
/*358:*/
#line 2493 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:358*/
#line 2393 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*360:*/
#line 2528 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->symbols->len;symid++)
{LV_SYMID_is_Terminal(g,symid)= 1;}}
/*:360*/
#line 2395 "./marpa.w"

}else{
/*361:*/
#line 2533 "./marpa.w"

{guint start= 0;
guint min,max;
bv_not(terminal_v,lhs_v);
while(bv_scan(terminal_v,start,&min,&max)){
Marpa_Symbol_ID symid;
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
LV_SYMID_is_Terminal(g,symid)= 1;
}
start= max+2;
}
}
/*:361*/
#line 2397 "./marpa.w"

}
}
/*364:*/
#line 2553 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
struct symbol*symbol= SYM_by_ID(g,symid);
if(symbol->is_counted){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
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
/*:364*/
#line 2400 "./marpa.w"

/*367:*/
#line 2580 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
struct symbol*symbol= SYM_by_ID(g,symid);
symbol->is_productive= 1;
}}
}
/*:367*/
#line 2401 "./marpa.w"

/*368:*/
#line 2594 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->start_symid))
{
g_context_int_add(g,"symid",g->start_symid);
g->error= "unproductive start symbol";
return NULL;
}
/*:368*/
#line 2402 "./marpa.w"

/*371:*/
#line 2624 "./marpa.w"

reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{guint symid,no_of_symbols= SYM_Count_of_G(g);
for(symid= 0;symid<no_of_symbols;symid++){
matrix_bit_set(reach_matrix,symid,symid);
}}
{Marpa_Rule_ID rule_id;
guint no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_PRD(rule);
guint rhs_ix,rule_length= rule->length;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,
(guint)lhs_id,(guint)rhs_symid(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:371*/
#line 2403 "./marpa.w"

/*374:*/
#line 2646 "./marpa.w"

accessible_v= matrix_row(reach_matrix,(guint)original_start_symid);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
struct symbol*symbol= SYM_by_ID(g,symid);
symbol->is_accessible= 1;
}}
}
/*:374*/
#line 2404 "./marpa.w"

/*376:*/
#line 2665 "./marpa.w"

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
SYM_by_ID(g,productive_id)->is_nulling= 1;
}
}
bv_free(reaches_terminal_v);
}

/*:376*/
#line 2405 "./marpa.w"

/*356:*/
#line 2485 "./marpa.w"

bv_free(terminal_v);
/*:356*//*362:*/
#line 2545 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:362*//*366:*/
#line 2577 "./marpa.w"

bv_free(nullable_v);

/*:366*//*370:*/
#line 2603 "./marpa.w"

bv_free(productive_v);

/*:370*/
#line 2406 "./marpa.w"

/*373:*/
#line 2643 "./marpa.w"

matrix_free(reach_matrix);

/*:373*/
#line 2407 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:346*//*383:*/
#line 2741 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*385:*/
#line 2764 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:385*//*389:*/
#line 2815 "./marpa.w"

guint factor_count;
guint*factor_positions;
/*:389*//*394:*/
#line 2864 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:394*/
#line 2744 "./marpa.w"

/*390:*/
#line 2818 "./marpa.w"

factor_positions= g_new(guint,g->max_rule_length);
/*:390*//*395:*/
#line 2867 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:395*/
#line 2745 "./marpa.w"

/*387:*/
#line 2776 "./marpa.w"

{gint no_of_symbols= SYM_Count_of_G(g);
Marpa_Symbol_ID symid;
for(symid= 0;symid<no_of_symbols;symid++){
struct symbol*symbol= SYM_by_ID(g,symid);
struct symbol*alias;
if(!symbol->is_nullable)continue;
if(symbol->is_nulling)continue;
if(!symbol->is_accessible)continue;
if(!symbol->is_productive)continue;
if(symbol_null_alias(symbol))continue;
alias= symbol_alias_create(g,symbol);
symbol_callback(g,alias->t_id);
}}

/*:387*/
#line 2746 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= rule_id2p(g,rule_id);
guint rule_length= rule->length;
guint nullable_suffix_ix= 0;
/*386:*/
#line 2768 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:386*/
#line 2752 "./marpa.w"

/*388:*/
#line 2799 "./marpa.w"

{guint rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= rhs_symid(rule,rhs_ix);
struct symbol*symbol= SYM_by_ID(g,symid);
if(symbol->is_nulling)continue;
if(symbol_null_alias(symbol)){

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}}
/*:388*/
#line 2753 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*392:*/
#line 2824 "./marpa.w"

rule->is_used= 0;
{guint unprocessed_factor_count;

guint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_PRD(rule);
guint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*398:*/
#line 2877 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symid;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*393:*/
#line 2843 "./marpa.w"
{
struct symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symid= chaf_virtual_symbol->t_id;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",LHS_ID_of_PRD(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symid);
}

/*:393*/
#line 2885 "./marpa.w"

/*399:*/
#line 2904 "./marpa.w"

{
guint remaining_rhs_length,piece_rhs_length;
/*400:*/
#line 2916 "./marpa.w"

{
guint real_symbol_count= piece_end-piece_start+1;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
remaining_rhs[piece_rhs_length]= 
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
}
{RULE chaf_rule;
guint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 2928 "./marpa.w"

}

/*:400*/
#line 2907 "./marpa.w"
;
/*401:*/
#line 2931 "./marpa.w"

{guint chaf_rule_length= rule->length-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;
remaining_rhs_length++){
Marpa_Symbol_ID original_id= rhs_symid(rule,piece_start+remaining_rhs_length);
struct symbol*alias= symbol_null_alias(SYM_by_ID(g,original_id));
remaining_rhs[remaining_rhs_length]= alias?alias->t_id:original_id;
}}
{RULE chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 2943 "./marpa.w"

}

/*:401*/
#line 2908 "./marpa.w"
;
/*402:*/
#line 2948 "./marpa.w"
{
Marpa_Symbol_ID proper_id= rhs_symid(rule,first_factor_position);
struct symbol*alias= symbol_null_alias(SYM_by_ID(g,proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
alias->t_id;
}
{RULE chaf_rule;
guint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 2958 "./marpa.w"

}

/*:402*/
#line 2909 "./marpa.w"
;
/*403:*/
#line 2967 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 2972 "./marpa.w"

}

/*:403*/
#line 2910 "./marpa.w"
;
}

/*:399*/
#line 2886 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*393:*/
#line 2843 "./marpa.w"
{
struct symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symid= chaf_virtual_symbol->t_id;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",LHS_ID_of_PRD(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symid);
}

/*:393*/
#line 2891 "./marpa.w"

/*405:*/
#line 2977 "./marpa.w"
{
guint piece_rhs_length;
RULE chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:405*//*406:*/
#line 2986 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 2992 "./marpa.w"


/*:406*//*407:*/
#line 2995 "./marpa.w"

second_factor_proper_id= rhs_symid(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 3000 "./marpa.w"


/*:407*//*408:*/
#line 3003 "./marpa.w"

first_factor_proper_id= rhs_symid(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 3009 "./marpa.w"


/*:408*//*409:*/
#line 3012 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 3015 "./marpa.w"


/*:409*//*410:*/
#line 3018 "./marpa.w"
}

/*:410*/
#line 2892 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:398*/
#line 2835 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*411:*/
#line 3022 "./marpa.w"
{
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
guint second_factor_piece_position= second_factor_position-piece_start;
guint real_symbol_count;
guint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:411*//*412:*/
#line 3036 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 3041 "./marpa.w"


/*:412*//*413:*/
#line 3044 "./marpa.w"

second_factor_proper_id= rhs_symid(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 3049 "./marpa.w"


/*:413*//*414:*/
#line 3052 "./marpa.w"

first_factor_proper_id= rhs_symid(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 3058 "./marpa.w"


/*:414*//*415:*/
#line 3062 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 3066 "./marpa.w"

}

/*:415*//*416:*/
#line 3070 "./marpa.w"
}

/*:416*/
#line 2838 "./marpa.w"

}else{
/*417:*/
#line 3073 "./marpa.w"
{
guint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
guint real_symbol_count;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:417*//*418:*/
#line 3084 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 3089 "./marpa.w"


/*:418*//*419:*/
#line 3093 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symid(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*421:*/
#line 3109 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:421*/
#line 3099 "./marpa.w"

}

/*:419*//*420:*/
#line 3103 "./marpa.w"
}

/*:420*/
#line 2840 "./marpa.w"

}}

/*:392*/
#line 2756 "./marpa.w"

NEXT_RULE:;
}
/*391:*/
#line 2820 "./marpa.w"

g_free(factor_positions);

/*:391*//*396:*/
#line 2870 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:396*/
#line 2759 "./marpa.w"

return g;
}
/*:383*//*422:*/
#line 3123 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct symbol*alias= symbol_null_alias(SYM_by_ID(g,proper_id));
return alias->t_id;
}
/*:422*//*425:*/
#line 3137 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct symbol*proper_old_start= NULL;
struct symbol*nulling_old_start= NULL;
struct symbol*proper_new_start= NULL;
struct symbol*old_start= SYM_by_ID(g,g->start_symid);
/*427:*/
#line 3153 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:427*/
#line 3145 "./marpa.w"

if(proper_old_start){/*428:*/
#line 3163 "./marpa.w"
{
RULE new_start_rule;
proper_old_start->is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= proper_new_start->t_id;
g->start_symid= proper_new_start_id;
proper_new_start->is_accessible= TRUE;
proper_new_start->is_productive= TRUE;
proper_new_start->is_start= TRUE;
g_context_clear(g);
g_context_int_add(g,"old_start_id",old_start->t_id);
symbol_callback(g,proper_new_start_id);
new_start_rule= rule_start(g,proper_new_start_id,&old_start->t_id,1);
new_start_rule->t_is_start= 1;
new_start_rule->is_virtual_lhs= 1;
new_start_rule->real_symbol_count= 1;
new_start_rule->is_used= TRUE;
rule_callback(g,new_start_rule->t_id);
}

/*:428*/
#line 3146 "./marpa.w"
}
if(nulling_old_start){/*429:*/
#line 3187 "./marpa.w"
{
Marpa_Symbol_ID nulling_new_start_id;
RULE new_start_rule;
struct symbol*nulling_new_start;
if(proper_new_start){
nulling_new_start= symbol_alias_create(g,proper_new_start);
nulling_new_start_id= nulling_new_start->t_id;
}else{
nulling_new_start= symbol_new(g);
nulling_new_start_id= nulling_new_start->t_id;
g->start_symid= nulling_new_start_id;
nulling_new_start->is_nulling= TRUE;
nulling_new_start->is_nullable= TRUE;
nulling_new_start->is_productive= TRUE;
nulling_new_start->is_accessible= TRUE;
}
nulling_new_start->is_start= TRUE;
g_context_clear(g);
g_context_int_add(g,"old_start_id",old_start->t_id);
symbol_callback(g,nulling_new_start_id);
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
new_start_rule->t_is_start= 1;
new_start_rule->is_virtual_lhs= 1;
new_start_rule->real_symbol_count= 1;
new_start_rule->is_used= TRUE;
rule_callback(g,new_start_rule->t_id);
}

/*:429*/
#line 3147 "./marpa.w"
}
return g;
}
/*:425*//*433:*/
#line 3261 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{guint no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*435:*/
#line 3284 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID proper_id;
guint rhs_ix,rule_length;
if(!rule->is_used)continue;
rule_length= rule->length;
proper_id= -1;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= rhs_symid(rule,rhs_ix);
struct symbol*symbol= SYM_by_ID(g,symid);
if(symbol->is_nullable)continue;
if(proper_id>=0)goto NEXT_RULE;

proper_id= symid;
}

if(proper_id<0)continue;

{struct symbol*rhs_symbol= SYM_by_ID(g,proper_id);
GArray*lhs_rules= rhs_symbol->lhs;
guint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,(guint)rule_id,
(guint)g_array_index(lhs_rules,Marpa_Rule_ID,ix));
}}
NEXT_RULE:;
}}

/*:435*/
#line 3268 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*436:*/
#line 3323 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule;
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

/*:436*/
#line 3270 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*437:*/
#line 3344 "./marpa.w"

g_context_clear(g);
g_context_int_add(g,"loop_rule_count",loop_rule_count);
grammar_message(g,"loop rule tally");

/*:437*/
#line 3272 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:433*//*452:*/
#line 3509 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 3511 "./marpa.w"

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 3512 "./marpa.w"

return g->no_of_items;
}
/*:452*//*454:*/
#line 3518 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 3521 "./marpa.w"

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 3522 "./marpa.w"

/*1035:*/
#line 9292 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:1035*/
#line 3523 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(g,item_id))->t_id;
}
/*:454*//*456:*/
#line 3529 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 3532 "./marpa.w"

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 3533 "./marpa.w"

/*1035:*/
#line 9292 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:1035*/
#line 3534 "./marpa.w"

return Position_of_AIM(AIM_by_ID(g,item_id));
}
/*:456*//*458:*/
#line 3540 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 3543 "./marpa.w"

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 3544 "./marpa.w"

/*1035:*/
#line 9292 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:1035*/
#line 3545 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(g,item_id));
}
/*:458*//*460:*/
#line 3550 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 3553 "./marpa.w"

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 3554 "./marpa.w"

/*1035:*/
#line 9292 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:1035*/
#line 3555 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(g,item_id));
}
/*:460*//*462:*/
#line 3562 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<(Marpa_AHFA_Item_ID)g->no_of_items&&item_id>=0;
}
/*:462*//*464:*/
#line 3577 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
Marpa_Rule_ID rule_id;
guint no_of_items;
guint no_of_rules= rule_count(g);
AIM base_item= g_new(struct s_AHFA_item,Size_of_G(g));
AIM current_item= base_item;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
/*466:*/
#line 3597 "./marpa.w"

guint rhs_ix;
RULE rule= rule_id2p(g,rule_id);
if(!rule->is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->length;rhs_ix++){
/*467:*/
#line 3609 "./marpa.w"

Marpa_Symbol_ID rh_symid= rhs_symid(rule,rhs_ix);
struct symbol*symbol= SYM_by_ID(g,rh_symid);
if(symbol->is_nullable)goto NEXT_RH_SYMBOL;
LV_Sort_Key_of_AIM(current_item)= current_item-base_item;
LV_Postdot_SYMID_of_AIM(current_item)= rh_symid;
LV_RULE_of_AIM(current_item)= rule;
LV_Position_of_AIM(current_item)= rhs_ix;

/*:467*/
#line 3602 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*468:*/
#line 3618 "./marpa.w"

LV_Sort_Key_of_AIM(current_item)= current_item-base_item;
LV_Postdot_SYMID_of_AIM(current_item)= -1;
LV_Position_of_AIM(current_item)= -1;
LV_RULE_of_AIM(current_item)= rule;

/*:468*/
#line 3606 "./marpa.w"

current_item++;

/*:466*/
#line 3586 "./marpa.w"

NEXT_RULE:;
}
no_of_items= g->no_of_items= current_item-base_item;
g->AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*469:*/
#line 3629 "./marpa.w"
{
AIM*items_by_rule= g_new0(AIM,no_of_rules);

AIM items= g->AHFA_items;
Marpa_Rule_ID highest_found_rule_id= -1;

Marpa_AHFA_Item_ID item_id;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){
AIM item= items+item_id;
Marpa_Rule_ID rule_id_for_item= LV_RULE_of_AIM(item)->t_id;
if(rule_id_for_item<=highest_found_rule_id)continue;
items_by_rule[rule_id_for_item]= item;
highest_found_rule_id= rule_id_for_item;
}
g->AHFA_items_by_rule= items_by_rule;
}

/*:469*/
#line 3591 "./marpa.w"

/*473:*/
#line 3666 "./marpa.w"
{Marpa_AHFA_Item_ID item_id;
AIM*sort_array= g_new(struct s_AHFA_item*,no_of_items);
AIM items= g->AHFA_items;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){



sort_array[item_id]= items+item_id;
}
g_qsort_with_data(sort_array,
(gint)no_of_items,sizeof(AIM),cmp_by_AHFA_item_id,(gpointer)NULL);
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){
LV_Sort_Key_of_AIM(sort_array[item_id])= item_id;
}
g_free(sort_array);}

/*:473*/
#line 3592 "./marpa.w"

}
/*:464*//*471:*/
#line 3650 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED){
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
gint a_postdot= Postdot_SYMID_of_AIM(a);
gint b_postdot= Postdot_SYMID_of_AIM(b);
if(a_postdot==b_postdot)
return Sort_Key_of_AIM(a)-Sort_Key_of_AIM(b);
if(a_postdot<0)return 1;
if(b_postdot<0)return-1;
return a_postdot-b_postdot;
}
/*:471*//*491:*/
#line 3835 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id){
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}
/*:491*//*494:*/
#line 3850 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const AHFA state,guint item_ix){
return state->t_items[item_ix]-g->AHFA_items;
}
/*:494*//*498:*/
#line 3868 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return AHFA_Count_of_G(g);
}
/*:498*//*500:*/
#line 3875 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 3878 "./marpa.w"

AHFA state;
/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 3880 "./marpa.w"

/*1036:*/
#line 9299 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1036*/
#line 3881 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
return state->t_item_count;
}
/*:500*//*502:*/
#line 3888 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
guint item_ix){
AHFA state;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 3893 "./marpa.w"

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 3894 "./marpa.w"

/*1036:*/
#line 9299 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1036*/
#line 3895 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
if(item_ix>=state->t_item_count){
g_context_clear(g);
g_context_int_add(g,"item_ix",(gint)item_ix);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid state item ix";
return failure_indicator;
}
return AHFA_state_item_ix2id(g,state,item_ix);
}
/*:502*//*510:*/
#line 3945 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 3950 "./marpa.w"

AHFA from_ahfa_state;
AHFA*to_ahfa_array;
SYMID symid;
gint symbol_count;

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 3956 "./marpa.w"

/*1036:*/
#line 9299 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1036*/
#line 3957 "./marpa.w"

/*1037:*/
#line 9306 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
g_context_clear(g);
g_context_int_add(g,"expected size",sizeof(gint));
g->error= "garray size mismatch";
return failure_indicator;
}
/*:1037*/
#line 3958 "./marpa.w"

from_ahfa_state= AHFA_by_ID(AHFA_state_id);
to_ahfa_array= from_ahfa_state->t_to_ahfa_ary;
symbol_count= SYM_Count_of_G(g);
g_array_set_size(result,0);
for(symid= 0;symid<symbol_count;symid++){
AHFA to_ahfa_state= to_ahfa_array[symid];
if(!to_ahfa_state)continue;

G_DEBUG3("symid=%d to_ahfa_state=%p",symid,to_ahfa_state);

g_array_append_val(result,symid);
g_array_append_val(result,ID_of_AHFA(to_ahfa_state));
}
return result->len;
}

/*:510*//*512:*/
#line 3979 "./marpa.w"

AHFAID marpa_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 3984 "./marpa.w"

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 3985 "./marpa.w"

/*1036:*/
#line 9299 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1036*/
#line 3986 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}
/*:512*//*514:*/
#line 3997 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 4001 "./marpa.w"

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 4002 "./marpa.w"

/*1036:*/
#line 9299 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1036*/
#line 4003 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
return state->t_is_predict;
}
/*:514*//*518:*/
#line 4037 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
const gint no_completed_start_rule= -1;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 4041 "./marpa.w"

AHFA state;
/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 4043 "./marpa.w"

/*1036:*/
#line 9299 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1036*/
#line 4044 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
if(AHFA_has_Completed_Start_Rule(state)){
const gint ahfa_item_count= state->t_item_count;
const AIM*ahfa_items= state->t_items;
gint ahfa_ix;
for(ahfa_ix= 0;ahfa_ix<ahfa_item_count;ahfa_ix++)
{
const AIM ahfa_item= ahfa_items[ahfa_ix];
if(AIM_is_Completion(ahfa_item))
{
const RULE rule= RULE_of_AIM(ahfa_item);
if(RULE_is_Start(rule))
return ID_of_RULE(rule);
}
}
/*1038:*/
#line 9313 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1038*/
#line 4060 "./marpa.w"

}
return no_completed_start_rule;
}

/*:518*//*522:*/
#line 4079 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 4082 "./marpa.w"

AHFA state;
/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 4084 "./marpa.w"

/*1036:*/
#line 9299 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1036*/
#line 4085 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:522*//*524:*/
#line 4106 "./marpa.w"

static gint AHFA_state_cmp(
gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED)
{
guint i;
AIM*items_a;
AIM*items_b;
const AHFA state_a= (AHFA)ap;
const AHFA state_b= (AHFA)bp;
guint length= state_a->t_item_count;
gint subkey= length-state_b->t_item_count;
if(subkey)return subkey;
if(length!=state_b->t_item_count)return FALSE;
items_a= state_a->t_items;
items_b= state_b->t_items;
for(i= 0;i<length;i++){
subkey= Sort_Key_of_AIM(items_a[i])-Sort_Key_of_AIM(items_b[i]);
if(subkey)return subkey;
}
return 0;
}
/*:524*//*526:*/
#line 4134 "./marpa.w"

static
void create_AHFA_states(struct marpa_g*g){
AHFA p_working_state;
const guint initial_no_of_states= 2*Size_of_G(g);
AIM AHFA_item_0_p= g->AHFA_items;
guint no_of_symbols= SYM_Count_of_G(g);
guint no_of_rules= rule_count(g);
Bit_Matrix prediction_matrix;
RULE*rule_by_sort_key= g_new(RULE,no_of_rules);
GSequence*duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
/*529:*/
#line 4196 "./marpa.w"
{guint item_id;
guint no_of_items_in_grammar= g->no_of_items;
duplicates= g_sequence_new(NULL);
singleton_duplicates= g_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++){
singleton_duplicates[item_id]= NULL;
}}
/*:529*/
#line 4147 "./marpa.w"

DQUEUE_INIT(states,AHFAD,initial_no_of_states);
/*545:*/
#line 4608 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= matrix_create(no_of_symbols,no_of_symbols);
/*546:*/
#line 4616 "./marpa.w"

{Marpa_Rule_ID rule_id;
Marpa_Symbol_ID symid;
AIM*items_by_rule= g->AHFA_items_by_rule;
for(symid= 0;symid<(Marpa_Symbol_ID)no_of_symbols;symid++){

struct symbol*symbol= SYM_by_ID(g,symid);
if(!SYMBOL_LHS_RULE_COUNT(symbol))continue;
matrix_bit_set(symbol_by_symbol_matrix,
(guint)symid,(guint)symid);
}
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
Marpa_Symbol_ID from,to;
AIM item= items_by_rule[rule_id];

RULE rule;
if(!item)continue;
rule= item->t_production;
from= LHS_ID_of_PRD(rule);
to= Postdot_SYMID_of_AIM(item);
if(to<0)continue;

matrix_bit_set(symbol_by_symbol_matrix,
(guint)from,(guint)to);
}}

/*:546*/
#line 4610 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*547:*/
#line 4648 "./marpa.w"
{
AIM*items_by_rule= g->AHFA_items_by_rule;
Marpa_Symbol_ID from_symid;
guint*sort_key_by_rule_id= g_new(guint,no_of_rules);
guint no_of_predictable_rules= 0;
/*548:*/
#line 4678 "./marpa.w"

{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++)
{
AIM item= items_by_rule[rule_id];
SYMID postdot;
if(!item)
goto NOT_A_PREDICTABLE_RULE;
postdot= Postdot_SYMID_of_AIM(item);
if(postdot<0)
goto NOT_A_PREDICTABLE_RULE;
sort_key_by_rule_id[rule_id]= postdot;
no_of_predictable_rules++;
continue;
NOT_A_PREDICTABLE_RULE:
sort_key_by_rule_id[rule_id]= G_MAXINT;
}
}

/*:548*/
#line 4654 "./marpa.w"

/*549:*/
#line 4698 "./marpa.w"

{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
rule_by_sort_key[rule_id]= rule_id2p(g,rule_id);
}
g_qsort_with_data(rule_by_sort_key,(gint)no_of_rules,
sizeof(RULE),cmp_by_rule_sort_key,
(gpointer)sort_key_by_rule_id);
}

/*:549*/
#line 4655 "./marpa.w"

/*552:*/
#line 4728 "./marpa.w"
{
guint sort_key;
for(sort_key= 0;sort_key<no_of_rules;sort_key++){
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}}

/*:552*/
#line 4656 "./marpa.w"

/*553:*/
#line 4735 "./marpa.w"

{
prediction_matrix= matrix_create(no_of_symbols,no_of_predictable_rules);
for(from_symid= 0;from_symid<(Marpa_Symbol_ID)no_of_symbols;
from_symid++)
{

guint min,max,start;
for(start= 0;
bv_scan(matrix_row
(symbol_by_symbol_matrix,(guint)from_symid),start,
&min,&max);start= max+2)
{
Marpa_Symbol_ID to_symid;
for(to_symid= min;to_symid<=(Marpa_Symbol_ID)max;
to_symid++)
{

struct symbol*to_symbol= SYM_by_ID(g,to_symid);
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

matrix_bit_set(prediction_matrix,(guint)from_symid,
sort_key);

}
}
}
}
}

/*:553*/
#line 4657 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:547*/
#line 4612 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:545*/
#line 4149 "./marpa.w"

/*531:*/
#line 4207 "./marpa.w"
{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFAD);
Marpa_Rule_ID start_rule_id;
AIM start_item;
struct symbol*start_symbol= SYM_by_ID(g,g->start_symid);
struct symbol*start_alias
= symbol_null_alias(start_symbol);
gint no_of_items_in_new_state= start_alias?2:1;
AIM*item_list
= obstack_alloc(&g->obs,no_of_items_in_new_state*sizeof(AIM));
start_rule_id= g_array_index(start_symbol->lhs,Marpa_Rule_ID,0);

start_item= g->AHFA_items_by_rule[start_rule_id];

item_list[0]= start_item;
if(start_alias){
Marpa_Rule_ID alias_rule_id
= g_array_index(start_alias->lhs,Marpa_Rule_ID,0);


item_list[1]= g->AHFA_items_by_rule[alias_rule_id];
}
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= no_of_items_in_new_state;
p_initial_state->t_key.t_id= 0;
p_initial_state->t_is_predict= 0;
LV_Leo_LHS_ID_of_AHFA(p_initial_state)= -1;
p_initial_state->t_to_ahfa_ary= to_ahfa_array_new(g);
p_initial_state->t_empty_transition= NULL;
if(start_symbol->is_nulling)
{
p_initial_state->t_complete_symbol_count= 1;
p_initial_state->t_has_completed_start_rule= 1;
p_initial_state->t_complete_symbols= 
obstack_alloc(&g->obs,sizeof(SYMID));
*(p_initial_state->t_complete_symbols)= g->start_symid;
LV_Postdot_SYM_Count_of_AHFA(p_initial_state)= 0;
}
else
{
SYMID*postdot_symbol_ids;
LV_Postdot_SYM_Count_of_AHFA(p_initial_state)= 1;
postdot_symbol_ids= LV_Postdot_SYMID_Ary_of_AHFA(p_initial_state)= 
obstack_alloc(&g->obs,sizeof(SYMID));
*postdot_symbol_ids= Postdot_SYMID_of_AIM(start_item);
if(start_alias)
{
p_initial_state->t_complete_symbol_count= 1;
p_initial_state->t_has_completed_start_rule= 1;
p_initial_state->t_complete_symbols= 
obstack_alloc(&g->obs,sizeof(SYMID));
*(p_initial_state->t_complete_symbols)= 
LHS_ID_of_PRD(rule_id2p(g,start_rule_id));
}
else
{
p_initial_state->t_complete_symbol_count= 0;
p_initial_state->t_has_completed_start_rule= 0;
}
p_initial_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(guint)
Postdot_SYMID_of_AIM(start_item)),
rule_by_sort_key,&states,duplicates);
}
}

/*:531*/
#line 4150 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFAD))){
/*528:*/
#line 4164 "./marpa.w"
{
guint no_of_items= p_working_state->t_item_count;
guint current_item_ix= 0;
AIM*item_list;
Marpa_Symbol_ID working_symbol;
item_list= p_working_state->t_items;
working_symbol= Postdot_SYMID_of_AIM(item_list[0]);

if(working_symbol<0)goto NEXT_AHFA_STATE;

while(1){
guint first_working_item_ix= current_item_ix;
guint no_of_items_in_new_state;
for(current_item_ix++;
current_item_ix<no_of_items;
current_item_ix++){
if(Postdot_SYMID_of_AIM(item_list[current_item_ix])!=working_symbol)break;
}
no_of_items_in_new_state= current_item_ix-first_working_item_ix;
if(no_of_items_in_new_state==1){
/*533:*/
#line 4305 "./marpa.w"
{
AHFA p_new_state;
AIM*new_state_item_list;
AIM single_item_p= item_list[first_working_item_ix];
Marpa_AHFA_Item_ID single_item_id;
Marpa_Symbol_ID postdot;
single_item_p++;
single_item_id= single_item_p-AHFA_item_0_p;
p_new_state= singleton_duplicates[single_item_id];
if(p_new_state)
{
AHFA_transition_add(p_working_state,working_symbol,p_new_state);
goto NEXT_WORKING_SYMBOL;
}
p_new_state= DQUEUE_PUSH(states,AHFAD);

singleton_duplicates[single_item_id]= p_new_state;
new_state_item_list= p_new_state->t_items= 
obstack_alloc(&g->obs,sizeof(AIM));
new_state_item_list[0]= single_item_p;
p_new_state->t_item_count= 1;
p_new_state->t_is_predict= 0;
if(AIM_has_Completed_Start_Rule(single_item_p)){
p_new_state->t_has_completed_start_rule= 1;
}else{
p_new_state->t_has_completed_start_rule= 0;
}
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFAD);
p_new_state->t_to_ahfa_ary= to_ahfa_array_new(g);
AHFA_transition_add(p_working_state,working_symbol,p_new_state);
postdot= Postdot_SYMID_of_AIM(single_item_p);
if(postdot>=0)
{
p_new_state->t_complete_symbol_count= 0;
p_new_state->t_postdot_sym_count= 1;
p_new_state->t_postdot_symid_ary= 
obstack_alloc(&g->obs,sizeof(SYMID));
*(p_new_state->t_postdot_symid_ary)= postdot;


p_new_state->t_empty_transition= 
create_predicted_AHFA_state(g,
matrix_row(prediction_matrix,
(guint)postdot),
rule_by_sort_key,&states,duplicates);
}
else
{
SYMID lhs_id;
p_new_state->t_complete_symbol_count= 1;
p_new_state->t_complete_symbols= 
obstack_alloc(&g->obs,sizeof(SYMID));
lhs_id= LHS_ID_of_PRD(single_item_p->t_production);
*(p_new_state->t_complete_symbols)= lhs_id;
p_new_state->t_postdot_sym_count= 0;
p_new_state->t_empty_transition= NULL;
/*535:*/
#line 4395 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(g,predot_symid))
> 0)
{
LV_Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:535*/
#line 4363 "./marpa.w"

}
}

/*:533*/
#line 4184 "./marpa.w"

}else{
/*536:*/
#line 4420 "./marpa.w"
{
AHFA p_new_state;
guint predecessor_ix;
guint no_of_new_items_so_far= 0;
AIM*item_list_for_new_state;
AHFA queued_AHFA_state;
p_new_state= DQUEUE_PUSH(states,AHFAD);
item_list_for_new_state= p_new_state->t_items= obstack_alloc(&g->obs_tricky,
no_of_items_in_new_state*sizeof(AIM));
p_new_state->t_item_count= no_of_items_in_new_state;
for(predecessor_ix= first_working_item_ix;
predecessor_ix<current_item_ix;predecessor_ix++)
{
gint pre_insertion_point_ix= no_of_new_items_so_far-1;
AIM new_item_p= item_list[predecessor_ix]+1;
while(pre_insertion_point_ix>=0)
{
AIM*current_item_pp= 
item_list_for_new_state+pre_insertion_point_ix;
if(Sort_Key_of_AIM(new_item_p)>=
Sort_Key_of_AIM(*current_item_pp))
break;
*(current_item_pp+1)= *current_item_pp;
pre_insertion_point_ix--;
}
item_list_for_new_state[pre_insertion_point_ix+1]= new_item_p;
no_of_new_items_so_far++;
}
queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state)
{

(void)DQUEUE_POP(states,AHFAD);
obstack_free(&g->obs_tricky,item_list_for_new_state);
AHFA_transition_add(p_working_state,working_symbol,queued_AHFA_state);


goto NEXT_WORKING_SYMBOL;
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFAD);
p_new_state->t_is_predict= 0;
p_new_state->t_has_completed_start_rule= 0;
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
p_new_state->t_to_ahfa_ary= to_ahfa_array_new(g);
/*537:*/
#line 4471 "./marpa.w"

{
guint symbol_count= SYM_Count_of_G(g);
guint item_ix;
guint no_of_postdot_symbols;
guint no_of_complete_symbols;
Bit_Vector complete_v= bv_create(symbol_count);
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_for_new_state[item_ix];
Marpa_Symbol_ID postdot= Postdot_SYMID_of_AIM(item);
if(postdot<0)
{
bv_bit_set(complete_v,(guint)LHS_ID_of_PRD(item->t_production));
}
else
{
bv_bit_set(postdot_v,(guint)postdot);
}
}
if((no_of_postdot_symbols= p_new_state->t_postdot_sym_count= 
bv_count(postdot_v)))
{
guint min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->t_postdot_symid_ary= 
obstack_alloc(&g->obs,
no_of_postdot_symbols*sizeof(SYMID));
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
if((no_of_complete_symbols= p_new_state->t_complete_symbol_count= 
bv_count(complete_v)))
{
guint min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->t_complete_symbols= 
obstack_alloc(&g->obs,
no_of_complete_symbols*sizeof(SYMID));
for(start= 0;bv_scan(complete_v,start,&min,&max);start= max+2)
{
Marpa_Symbol_ID complete_symbol;
for(complete_symbol= (Marpa_Symbol_ID)min;
complete_symbol<=(Marpa_Symbol_ID)max;complete_symbol++)
{
*p_symbol++= complete_symbol;
}
}
}
bv_free(postdot_v);
bv_free(complete_v);
}

/*:537*/
#line 4465 "./marpa.w"

AHFA_transition_add(p_working_state,working_symbol,p_new_state);
/*540:*/
#line 4552 "./marpa.w"
{
guint item_ix;
Marpa_Symbol_ID postdot= -1;
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++){
postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot>=0)break;
}
p_new_state->t_empty_transition= NULL;
if(postdot>=0){
Bit_Vector predicted_rule_vector
= bv_shadow(matrix_row(prediction_matrix,(guint)postdot));
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++){

postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot<0)continue;
bv_or_assign(predicted_rule_vector,
matrix_row(prediction_matrix,(guint)postdot));
}
p_new_state->t_empty_transition= create_predicted_AHFA_state(g,
predicted_rule_vector,
rule_by_sort_key,
&states,
duplicates);
}}

/*:540*/
#line 4468 "./marpa.w"

}

/*:536*/
#line 4186 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:528*/
#line 4152 "./marpa.w"

}
g->t_AHFA= DQUEUE_BASE(states,AHFAD);

LV_AHFA_Count_of_G(g)= DQUEUE_END(states);
g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*530:*/
#line 4203 "./marpa.w"

g_free(singleton_duplicates);
g_sequence_free(duplicates);

/*:530*/
#line 4159 "./marpa.w"

}
/*:526*//*538:*/
#line 4536 "./marpa.w"

static inline AHFA
assign_AHFA_state(AHFA state_p,GSequence*duplicates)
{
gboolean match= FALSE;
GSequenceIter*iter= 
sequence_find(duplicates,state_p,AHFA_state_cmp,&match);
if(match)return g_sequence_get(iter);
g_sequence_insert_before(iter,state_p);
return NULL;
}
/*:538*//*550:*/
#line 4708 "./marpa.w"
static gint
cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data){
RULE a= *(RULE*)ap;
RULE b= *(RULE*)bp;
guint*sort_key_by_rule_id= (guint*)user_data;
Marpa_Rule_ID a_id= a->t_id;
Marpa_Rule_ID b_id= b->t_id;
guint sort_key_a= sort_key_by_rule_id[a_id];
guint sort_key_b= sort_key_by_rule_id[b_id];
if(sort_key_a==sort_key_b)return a_id-b_id;
return sort_key_a-sort_key_b;
}
/*:550*//*554:*/
#line 4775 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
struct dqueue*states_p,
GSequence*duplicates
){
AIM*item_list_for_new_state;
AHFA p_new_state;
guint item_list_ix= 0;
guint no_of_items_in_new_state= bv_count(prediction_rule_vector);
if(no_of_items_in_new_state==0)return NULL;
item_list_for_new_state= obstack_alloc(&g->obs,
no_of_items_in_new_state*sizeof(AIM));
{
guint start,min,max;
for(start= 0;bv_scan(prediction_rule_vector,start,&min,&max);
start= max+2)
{
guint rule_sort_key;
for(rule_sort_key= min;rule_sort_key<=max;rule_sort_key++)
{

RULE rule= rule_by_sort_key[rule_sort_key];
item_list_for_new_state[item_list_ix++]= 
g->AHFA_items_by_rule[rule->t_id];
}
}
}
p_new_state= DQUEUE_PUSH((*states_p),AHFAD);
p_new_state->t_items= item_list_for_new_state;
p_new_state->t_item_count= no_of_items_in_new_state;
{AHFA queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);



if(queued_AHFA_state){
(void)DQUEUE_POP((*states_p),AHFAD);
obstack_free(&g->obs,item_list_for_new_state);
return queued_AHFA_state;
}
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE((*states_p),AHFAD);
p_new_state->t_is_predict= 1;
p_new_state->t_has_completed_start_rule= 0;
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
p_new_state->t_empty_transition= NULL;
p_new_state->t_to_ahfa_ary= to_ahfa_array_new(g);
p_new_state->t_complete_symbol_count= 0;
/*556:*/
#line 4840 "./marpa.w"

{
guint symbol_count= SYM_Count_of_G(g);
guint item_ix;
guint no_of_postdot_symbols;
Bit_Vector postdot_v= bv_create(symbol_count);
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{
AIM item= item_list_for_new_state[item_ix];
SYMID postdot= Postdot_SYMID_of_AIM(item);
if(postdot>=0)
bv_bit_set(postdot_v,(guint)postdot);
}
if((no_of_postdot_symbols= p_new_state->t_postdot_sym_count= 
bv_count(postdot_v)))
{
guint min,max,start;
Marpa_Symbol_ID*p_symbol= p_new_state->t_postdot_symid_ary= 
obstack_alloc(&g->obs,
no_of_postdot_symbols*sizeof(SYMID));
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

/*:556*/
#line 4827 "./marpa.w"

return p_new_state;
}
/*:554*//*559:*/
#line 4879 "./marpa.w"
static inline
AHFA*to_ahfa_array_new(struct marpa_g*g){
gint symbol_count= SYM_Count_of_G(g);
gint symid= 0;
AHFA*new_to_ahfa_array= g_malloc(symbol_count*sizeof(AHFA));
while(symid<symbol_count)new_to_ahfa_array[symid++]= NULL;


return new_to_ahfa_array;
}

/*:559*//*560:*/
#line 4890 "./marpa.w"
static inline
void AHFA_transition_add(AHFA from_ahfa,SYMID symid,AHFA to_ahfa)
{
from_ahfa->t_to_ahfa_ary[symid]= to_ahfa;
}
/*:560*//*566:*/
#line 4924 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g)
{struct marpa_r*r;
/*1030:*/
#line 9264 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1030*/
#line 4927 "./marpa.w"

/*1032:*/
#line 9272 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1032*/
#line 4928 "./marpa.w"

r= g_slice_new(struct marpa_r);
r->t_grammar= g;
/*651:*/
#line 5372 "./marpa.w"
obstack_init(&r->obs);
/*:651*/
#line 4931 "./marpa.w"

/*574:*/
#line 4964 "./marpa.w"

r->t_id= g_atomic_int_exchange_and_add(&next_recce_id,1);
/*:574*//*581:*/
#line 4989 "./marpa.w"

r->t_phase= initial_phase;
/*:581*//*585:*/
#line 5004 "./marpa.w"

r->earley_sets= g_sequence_new(earley_set_free);
/*:585*//*591:*/
#line 5025 "./marpa.w"

r->earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,g->no_of_items*2);
/*:591*//*597:*/
#line 5053 "./marpa.w"
r->t_furthest_earleme= 0;
/*:597*//*602:*/
#line 5079 "./marpa.w"
r->t_sym_workarea= NULL;
/*:602*//*605:*/
#line 5093 "./marpa.w"
r->t_workarea2= NULL;
/*:605*//*608:*/
#line 5116 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:608*//*612:*/
#line 5139 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:612*//*618:*/
#line 5176 "./marpa.w"

r->t_is_trace_earley_sets= FALSE;
/*:618*//*632:*/
#line 5264 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:632*//*638:*/
#line 5303 "./marpa.w"

r->t_is_leo_expanding= 0;

/*:638*//*640:*/
#line 5317 "./marpa.w"

r->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:640*//*655:*/
#line 5388 "./marpa.w"

r->t_error= NULL;
r->t_fatal_error= NULL;
/*:655*//*682:*/
#line 5604 "./marpa.w"

r->t_trace_earley_set_iter= NULL;
r->t_trace_earley_set= NULL;
/*:682*//*717:*/
#line 5904 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;
/*:717*//*753:*/
#line 6340 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:753*//*796:*/
#line 6835 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:796*//*861:*/
#line 7563 "./marpa.w"
DSTACK_ZERO_INIT(r->completion_stack);
/*:861*//*1065:*/
#line 9523 "./marpa.w"

r->message_callback_arg= NULL;
r->message_callback= NULL;
/*:1065*/
#line 4932 "./marpa.w"

return r;}
/*:566*//*568:*/
#line 4937 "./marpa.w"

void marpa_r_free(struct marpa_r*r)
{
/*586:*/
#line 5006 "./marpa.w"

g_sequence_free(r->earley_sets);

/*:586*//*641:*/
#line 5319 "./marpa.w"
g_hash_table_destroy(r->context);

/*:641*//*863:*/
#line 7571 "./marpa.w"
DSTACK_DESTROY(r->completion_stack);
/*:863*/
#line 4940 "./marpa.w"

if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*610:*/
#line 5125 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:610*//*614:*/
#line 5142 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:614*/
#line 4943 "./marpa.w"

/*652:*/
#line 5373 "./marpa.w"
obstack_free(&r->obs,NULL);

/*:652*/
#line 4944 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:568*//*575:*/
#line 4966 "./marpa.w"

gint marpa_r_id(struct marpa_r*r){return r->t_id;}
/*:575*//*583:*/
#line 4993 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r)
{return r->t_phase;}

/*:583*//*589:*/
#line 5018 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r)
{return Current_Earleme(r);}

/*:589*//*593:*/
#line 5029 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r)
{return r->earley_item_warning_threshold;}

/*:593*//*595:*/
#line 5037 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold)
{
r->earley_item_warning_threshold= threshold==0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:595*//*599:*/
#line 5056 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme(r);}

/*:599*//*616:*/
#line 5154 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 5157 "./marpa.w"

guint min,max,start;
/*1045:*/
#line 9359 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
r_context_clear(r);
r_context_int_add(r,"expected size",sizeof(gint));
R_ERROR_CXT("garray size mismatch");
return failure_indicator;
}
/*:1045*/
#line 5159 "./marpa.w"

g_array_set_size(result,0);
for(start= 0;bv_scan(r->t_bv_symid_is_expected,start,&min,&max);
start= max+2)
{
gint symid;
for(symid= (gint)min;symid<=(gint)max;symid++)
{
g_array_append_val(result,symid);
}
}
return(gint)result->len;
}

/*:616*//*620:*/
#line 5183 "./marpa.w"

gboolean marpa_is_trace_earley_sets(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 5186 "./marpa.w"

/*1043:*/
#line 9347 "./marpa.w"

if(r->t_phase==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1043*/
#line 5187 "./marpa.w"

return r->t_is_trace_earley_sets?1:0;
}
/*:620*//*621:*/
#line 5192 "./marpa.w"

gboolean marpa_is_trace_earley_sets_set(
struct marpa_r*r,gboolean value)
{
/*1029:*/
#line 9262 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1029*/
#line 5196 "./marpa.w"

/*1043:*/
#line 9347 "./marpa.w"

if(r->t_phase==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1043*/
#line 5197 "./marpa.w"

r->t_is_trace_earley_sets= value;
return TRUE;
}
/*:621*//*634:*/
#line 5272 "./marpa.w"

gint marpa_is_use_leo(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 5275 "./marpa.w"

/*1043:*/
#line 9347 "./marpa.w"

if(r->t_phase==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1043*/
#line 5276 "./marpa.w"

return r->t_use_leo_flag?1:0;
}
/*:634*//*635:*/
#line 5281 "./marpa.w"

gboolean marpa_is_use_leo_set(
struct marpa_r*r,gboolean value)
{
/*1029:*/
#line 9262 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1029*/
#line 5285 "./marpa.w"

/*1043:*/
#line 9347 "./marpa.w"

if(r->t_phase==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1043*/
#line 5286 "./marpa.w"

r->t_use_leo_flag= value;
return TRUE;
}
/*:635*//*642:*/
#line 5328 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(r->context,(gpointer)key,value);
}
/*:642*//*644:*/
#line 5340 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(r->context,(gpointer)key,value);
}
/*:644*//*646:*/
#line 5355 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r){
g_hash_table_remove_all(r->context);}
/*:646*//*648:*/
#line 5361 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key)
{return g_hash_table_lookup(r->context,key);}
/*:648*//*657:*/
#line 5397 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r)
{return r->t_error?r->t_error:"unknown error";}
/*:657*//*668:*/
#line 5457 "./marpa.w"

static inline ES
earley_set_new(struct marpa_r*r,Marpa_Earleme id)
{
ESKD key;
ES set;
set= obstack_alloc(&r->obs,sizeof(*set));
key.t_id= id;
set->t_key= key;
set->t_eims= g_sequence_new(NULL);
set->t_postdot_ary= NULL;
set->t_postdot_sym_count= 0;
set->t_eim_count= 0;
return set;
}

/*:668*//*673:*/
#line 5514 "./marpa.w"

static inline GSequenceIter*later_earley_set_assign(
struct marpa_r*r,Marpa_Earleme sought_earleme,
ES*set_p)
{
GSequenceIter*iter= g_sequence_iter_next(Current_ES_Iter_of_R(r));
for(;;){
Marpa_Earleme found_earleme;
ES found_set;
if(g_sequence_iter_is_end(iter)){
LV_Furthest_Earleme(r)= sought_earleme;
break;
}
found_set= g_sequence_get(iter);
found_earleme= Earleme_of_ES(found_set);
G_DEBUG3("later_earley_set_assign, sought=%d, found=%d",sought_earleme,found_earleme);
if(sought_earleme==found_earleme){
*set_p= found_set;
return iter;
}
if(sought_earleme<found_earleme){
break;
}
iter= g_sequence_iter_next(iter);
}
*set_p= earley_set_new(r,sought_earleme);
return g_sequence_insert_before(iter,*set_p);
}

/*:673*//*674:*/
#line 5544 "./marpa.w"

static inline void earley_set_free(gpointer p){
GSequence*sequence;
ES set= p;
if((sequence= set->t_eims))g_sequence_free(sequence);
}
/*:674*//*676:*/
#line 5554 "./marpa.w"

static gint
earley_set_cmp(
gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED)
{
const struct s_earley_set_key*set_key_a= ap;
const struct s_earley_set_key*set_key_b= bp;
return set_key_a->t_id-set_key_b->t_id;
}
/*:676*//*679:*/
#line 5577 "./marpa.w"

static inline ES
earley_set_by_id(struct marpa_r*r,Marpa_Earleme earleme)
{
GSequenceIter*iter;
ESKD key;
gboolean match= FALSE;
key.t_id= earleme;
iter= sequence_find(r->earley_sets,&key,
earley_set_cmp,
&match);
return match?(ES)g_sequence_get(iter):NULL;
}
/*:679*//*685:*/
#line 5621 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earleme id)
{
GSequenceIter*iter;
gboolean match= FALSE;
ESKD key;
ES set;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 5629 "./marpa.w"

/*1040:*/
#line 9327 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1040*/
#line 5630 "./marpa.w"

trace_earley_item_clear(r);
key.t_id= id;
iter= sequence_find(r->earley_sets,&key,earley_set_cmp,&match);
if(g_sequence_iter_is_end(iter)){
/*686:*/
#line 5643 "./marpa.w"

r->t_trace_earley_set_iter= NULL;
r->t_trace_earley_set= NULL;

/*:686*/
#line 5635 "./marpa.w"

return-1;
}
r->t_trace_earley_set_iter= iter;
set= r->t_trace_earley_set= g_sequence_get(iter);
return Earleme_of_ES(set);
}

/*:685*//*688:*/
#line 5649 "./marpa.w"

Marpa_Earleme marpa_trace_earleme(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 5652 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1040:*/
#line 9327 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1040*/
#line 5654 "./marpa.w"

if(!trace_earley_set){
R_ERROR("no trace es");
return failure_indicator;
}
return ID_of_ES(trace_earley_set);
}

/*:688*//*690:*/
#line 5667 "./marpa.w"

gint marpa_current_earley_set_size(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 5670 "./marpa.w"

/*1040:*/
#line 9327 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1040*/
#line 5671 "./marpa.w"

/*1043:*/
#line 9347 "./marpa.w"

if(r->t_phase==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1043*/
#line 5672 "./marpa.w"

return EIM_Count_of_ES(Current_ES_of_R(r));
}

/*:690*//*700:*/
#line 5745 "./marpa.w"

static inline EIM earley_item_new(struct marpa_r*r,
ES set,EIKD key)
{
EIM new_item;
new_item= obstack_alloc(&r->obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_set= set;
new_item->t_source_type= NO_SOURCE;
LV_EIM_is_Leo_Expanded(new_item)= 1;
return new_item;
}

/*:700*//*702:*/
#line 5764 "./marpa.w"

static inline EIM earley_item_assign(struct marpa_r*r,
ES set,
ES origin,
AHFA state)
{
/*1030:*/
#line 9264 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1030*/
#line 5770 "./marpa.w"

EIM new_item;
guint count;
GSequenceIter*iter;
gboolean match= FALSE;
EIKD key;
key.t_origin= origin;
key.t_state= state;

iter= sequence_find
(set->t_eims,&key,own_earley_item_cmp,&match);
if(match)return(EIM)g_sequence_get(iter);
count= ++set->t_eim_count;
/*703:*/
#line 5791 "./marpa.w"

if(count>=r->earley_item_warning_threshold)
{
if(G_UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
r_context_clear(r);
R_FATAL("eim count exceeds fatal threshold");
return failure_indicator;
}
if(!r->t_is_leo_expanding){
r_context_clear(r);
r_message(r,"earley item count exceeds threshold");
}
}

/*:703*/
#line 5783 "./marpa.w"

new_item= earley_item_new(r,set,key);
g_sequence_insert_before(iter,new_item);
return new_item;
}

/*:702*//*707:*/
#line 5823 "./marpa.w"

static gint
own_earley_item_cmp(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED)
/*706:*/
#line 5813 "./marpa.w"

{
const struct s_earley_item*eim_a= ap;
const struct s_earley_item*eim_b= bp;
gint subkey= 
AHFAID_of_EIM(eim_a)-
AHFAID_of_EIM(eim_b);
if(subkey)return subkey;
return Origin_ID_of_EIM(eim_a)-Origin_ID_of_EIM(eim_b);
}
/*:706*/
#line 5827 "./marpa.w"

static inline gint earley_item_cmp(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED)
/*706:*/
#line 5813 "./marpa.w"

{
const struct s_earley_item*eim_a= ap;
const struct s_earley_item*eim_b= bp;
gint subkey= 
AHFAID_of_EIM(eim_a)-
AHFAID_of_EIM(eim_b);
if(subkey)return subkey;
return Origin_ID_of_EIM(eim_a)-Origin_ID_of_EIM(eim_b);
}
/*:706*/
#line 5830 "./marpa.w"

/*:707*//*715:*/
#line 5879 "./marpa.w"

static const char*invalid_source_type_message(guint type){
switch(type){
case NO_SOURCE:
return"invalid source type: none";
case SOURCE_IS_TOKEN:
return"invalid source type: token";
case SOURCE_IS_COMPLETION:
return"invalid source type: completion";
case SOURCE_IS_LEO:
return"invalid source type: leo";
case SOURCE_IS_AMBIGUOUS:
return"invalid source type: ambiguous";
}
return"unknown source type";
}

/*:715*//*720:*/
#line 5927 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earleme origin_id,
Marpa_AHFA_State_ID state_id)
{
const gint no_match= -1;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 5934 "./marpa.w"

GSequenceIter*iter;
gboolean match= FALSE;
ES current_set= r->t_trace_earley_set;
ES origin_set;
EIM item;
EIKD item_key;
GRAMMARC g= G_of_R(r);
/*1040:*/
#line 9327 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1040*/
#line 5942 "./marpa.w"

trace_source_link_clear(r);
if(!current_set){
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 5945 "./marpa.w"

R_ERROR("no trace es");
return failure_indicator;
}
origin_set= Earley_Set_by_ID(r,origin_id);
if(!origin_set){
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 5951 "./marpa.w"

R_ERROR("origin es not found");
return failure_indicator;
}
item_key.t_state= AHFA_by_ID(state_id);
item_key.t_origin= origin_set;
iter= sequence_find
(current_set->t_eims,&item_key,own_earley_item_cmp,&match);
if(!match){
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 5960 "./marpa.w"

return no_match;
}
r->t_trace_earley_item_iter= iter;
item= r->t_trace_earley_item= g_sequence_get(iter);
return AHFAID_of_EIM(item);
}

/*:720*//*722:*/
#line 5979 "./marpa.w"

Marpa_AHFA_State_ID
marpa_first_earley_item_trace(struct marpa_r*r)
{
GSequenceIter*iter;
ES current_set= r->t_trace_earley_set;
EIM item;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 5986 "./marpa.w"

/*1040:*/
#line 9327 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1040*/
#line 5987 "./marpa.w"

trace_source_link_clear(r);
if(!current_set){
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 5990 "./marpa.w"

R_ERROR("no trace earley set");
return failure_indicator;
}
iter= g_sequence_get_begin_iter(current_set->t_eims);
if(g_sequence_iter_is_end(iter)){
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 5996 "./marpa.w"

return-1;
}
r->t_trace_earley_item_iter= iter;
item= r->t_trace_earley_item= g_sequence_get(iter);
return AHFAID_of_EIM(item);
}

/*:722*//*724:*/
#line 6016 "./marpa.w"

AHFAID
marpa_next_earley_item_trace(struct marpa_r*r)
{
GSequenceIter*iter;
EIM item;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6022 "./marpa.w"

/*1040:*/
#line 9327 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1040*/
#line 6023 "./marpa.w"

trace_source_link_clear(r);
iter= r->t_trace_earley_item_iter;
if(!iter){
R_ERROR("no eim iter");
return failure_indicator;
}
iter= g_sequence_iter_next(iter);
if(g_sequence_iter_is_end(iter)){
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 6032 "./marpa.w"

return-1;
}
r->t_trace_earley_item_iter= iter;
item= r->t_trace_earley_item= g_sequence_get(iter);
return AHFAID_of_EIM(item);
}

/*:724*//*727:*/
#line 6052 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r)
{
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 6055 "./marpa.w"

trace_source_link_clear(r);
}

/*:727*//*729:*/
#line 6061 "./marpa.w"

Marpa_Earleme marpa_earley_item_origin(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6064 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1040:*/
#line 9327 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1040*/
#line 6066 "./marpa.w"

if(!item){
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 6068 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return Origin_ID_of_EIM(item);
}

/*:729*//*735:*/
#line 6148 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6152 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6155 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item)){
R_ERROR("pim is not lim");
return failure_indicator;
}
predecessor_leo_item= Predecessor_LIM_of_LIM(LIM_of_PIM(postdot_item));
if(!predecessor_leo_item)return no_predecessor;
return Postdot_SYMID_of_LIM(predecessor_leo_item);
}

Marpa_Earleme marpa_leo_base_origin(struct marpa_r*r);
/*:735*//*736:*/
#line 6170 "./marpa.w"

Marpa_Earleme marpa_leo_base_origin(struct marpa_r*r)
{
const Marpa_Earleme pim_is_not_a_leo_item= -1;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6174 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6177 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_ID_of_EIM(base_earley_item);
}

/*:736*//*738:*/
#line 6189 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r)
{
const Marpa_Earleme pim_is_not_a_leo_item= -1;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6193 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6196 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:738*//*743:*/
#line 6232 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r)
{
const Marpa_Earleme pim_is_not_a_leo_item= -1;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6236 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6238 "./marpa.w"

if(!postdot_item)
{
R_ERROR("no trace pim");
return failure_indicator;
}
if(!EIM_of_PIM(postdot_item))
{
const LIM leo_item= LIM_of_PIM(postdot_item);
const EIM base_earley_item= Base_EIM_of_LIM(leo_item);
const SYMID postdot_symbol= Postdot_SYMID_of_LIM(leo_item);
const AHFA to_ahfa= To_AHFA_of_EIM_by_SYMID(base_earley_item,postdot_symbol);
return ID_of_AHFA(to_ahfa);
}
return pim_is_not_a_leo_item;
}


/*:743*//*749:*/
#line 6302 "./marpa.w"

static inline PIM*
pim_sym_p_find(ES set,SYMID symid)
{
gint lo= 0;
gint hi= Postdot_SYM_Count_of_ES(set)-1;
PIM*postdot_array= set->t_postdot_ary;
while(hi>=lo){
gint trial= (hi+lo)/2;
PIM trial_pim= postdot_array[trial];
SYMID trial_symid= Postdot_SYMID_of_PIM(trial_pim);
if(trial_symid==symid)return postdot_array+trial;
if(trial_symid<symid){
lo= trial+1;
}else{
hi= trial-1;
}
}
return NULL;
}
/*:749*//*751:*/
#line 6324 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:751*//*755:*/
#line 6358 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6363 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*756:*/
#line 6382 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:756*/
#line 6367 "./marpa.w"

/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6368 "./marpa.w"

/*1044:*/
#line 9352 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
r_context_clear(r);
r_context_int_add(r,"symid",symid);
R_ERROR_CXT("invalid symid");
return failure_indicator;
}
/*:1044*/
#line 6369 "./marpa.w"

if(!current_es){
R_ERROR("no pim");
return failure_indicator;
}
pim_sym_p= PIM_SYM_P_of_ES_by_SYMID(current_es,symid);
pim= *pim_sym_p;
if(!pim)return-1;
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return symid;
}

/*:755*//*758:*/
#line 6395 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6399 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*756:*/
#line 6382 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:756*/
#line 6403 "./marpa.w"

/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6404 "./marpa.w"

if(!current_earley_set){
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 6406 "./marpa.w"

R_ERROR("no trace es");
return failure_indicator;
}
if(current_earley_set->t_postdot_sym_count<=0)return-1;
pim_sym_p= current_earley_set->t_postdot_ary+0;
pim= pim_sym_p[0];
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return Postdot_SYMID_of_PIM(pim);
}

/*:758*//*760:*/
#line 6428 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6433 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;

pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*756:*/
#line 6382 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:756*/
#line 6440 "./marpa.w"

if(!pim_sym_p||!pim){
R_ERROR("no trace pim");
return failure_indicator;
}
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6445 "./marpa.w"

if(!current_set){
R_ERROR("no trace es");
return failure_indicator;
}
pim= Next_PIM_of_PIM(pim);
if(!pim){

pim_sym_p++;
if(pim_sym_p-current_set->t_postdot_ary
>=current_set->t_postdot_sym_count){
return no_more_postdot_symbols;
}
pim= *pim_sym_p;
}
r->t_trace_pim_sym_p= pim_sym_p;
r->t_trace_postdot_item= pim;
return Postdot_SYMID_of_PIM(pim);
}

/*:760*//*762:*/
#line 6467 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6470 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6472 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:762*//*778:*/
#line 6604 "./marpa.w"
static inline
void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
SYMID token_id,
gpointer value)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_EIM(item);
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_EIM(item)= SOURCE_IS_TOKEN;
item->t_container.t_unique.t_predecessor= predecessor;
item->t_container.t_unique.t_cause= value;
item->t_container.t_unique.t_symbol_id= token_id;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->obs,sizeof(*new_link));
new_link->t_next= First_Token_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
new_link->t_source.t_cause= value;
new_link->t_source.t_symbol_id= token_id;
LV_First_Token_Link_of_EIM(item)= new_link;
}
/*:778*//*785:*/
#line 6694 "./marpa.w"
static inline
void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_EIM(item);
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_EIM(item)= SOURCE_IS_COMPLETION;
item->t_container.t_unique.t_predecessor= predecessor;
item->t_container.t_unique.t_cause= cause;
item->t_container.t_unique.t_symbol_id= -1;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->obs,sizeof(*new_link));
new_link->t_next= First_Completion_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
new_link->t_source.t_cause= cause;
new_link->t_source.t_symbol_id= -1;
LV_First_Completion_Link_of_EIM(item)= new_link;
}

/*:785*//*786:*/
#line 6723 "./marpa.w"
static inline
void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_EIM(item);
LV_EIM_is_Leo_Expanded(item)= 0;
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_EIM(item)= SOURCE_IS_LEO;
item->t_container.t_unique.t_predecessor= predecessor;
item->t_container.t_unique.t_cause= cause;
item->t_container.t_unique.t_symbol_id= -1;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->obs,sizeof(*new_link));
new_link->t_next= First_Leo_SRCL_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
new_link->t_source.t_cause= cause;
new_link->t_source.t_symbol_id= -1;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
}
/*:786*//*789:*/
#line 6778 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*791:*/
#line 6796 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= new_link;
}

/*:791*/
#line 6785 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*792:*/
#line 6805 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= new_link;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:792*/
#line 6787 "./marpa.w"

return;
case SOURCE_IS_LEO:/*793:*/
#line 6814 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:793*/
#line 6789 "./marpa.w"

return;
}
}
/*:789*//*799:*/
#line 6848 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6851 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6855 "./marpa.w"

/*818:*/
#line 7079 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:818*/
#line 6856 "./marpa.w"

source_type= Source_Type_of_EIM(item);
switch(source_type)
{
case SOURCE_IS_TOKEN:
r->t_trace_source_type= SOURCE_IS_TOKEN;
source= &(item->t_container.t_unique);
r->t_trace_source= source;
r->t_trace_next_source_link= NULL;
return Symbol_ID_of_SRC(source);
case SOURCE_IS_AMBIGUOUS:
{
SRCL full_link= 
First_Token_Link_of_EIM(item);
if(full_link)
{
r->t_trace_source_type= SOURCE_IS_TOKEN;
r->t_trace_next_source_link= Next_SRCL_of_SRCL(full_link);
r->t_trace_source= &(full_link->t_source);
return Symbol_ID_of_SRCL(full_link);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:799*//*803:*/
#line 6893 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6896 "./marpa.w"

SRCL full_link;
EIM item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6899 "./marpa.w"

/*818:*/
#line 7079 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:818*/
#line 6900 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_TOKEN){
trace_source_link_clear(r);
R_ERROR("not tracing token links");
return failure_indicator;
}
if(!r->t_trace_next_source_link){
trace_source_link_clear(r);
return-1;
}
full_link= r->t_trace_next_source_link;
r->t_trace_next_source_link= Next_SRCL_of_SRCL(full_link);
r->t_trace_source= &(full_link->t_source);
return Symbol_ID_of_SRCL(full_link);
}

/*:803*//*806:*/
#line 6925 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6928 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6932 "./marpa.w"

/*818:*/
#line 7079 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:818*/
#line 6933 "./marpa.w"

switch((source_type= Source_Type_of_EIM(item)))
{
case SOURCE_IS_COMPLETION:
r->t_trace_source_type= SOURCE_IS_COMPLETION;
source= &(item->t_container.t_unique);
r->t_trace_source= source;
r->t_trace_next_source_link= NULL;
return Cause_AHFA_State_ID_of_SRC(source);
case SOURCE_IS_AMBIGUOUS:
{
SRCL completion_link= First_Completion_Link_of_EIM(item);
if(completion_link)
{
source= &(completion_link->t_source);
r->t_trace_source_type= SOURCE_IS_COMPLETION;
r->t_trace_next_source_link= Next_SRCL_of_SRCL(completion_link);
r->t_trace_source= source;
return Cause_AHFA_State_ID_of_SRC(source);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:806*//*810:*/
#line 6969 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 6972 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 6976 "./marpa.w"

/*818:*/
#line 7079 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:818*/
#line 6977 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_COMPLETION){
trace_source_link_clear(r);
R_ERROR("not tracing completion links");
return failure_indicator;
}
if(!r->t_trace_next_source_link){
trace_source_link_clear(r);
return-1;
}
completion_link= r->t_trace_next_source_link;
r->t_trace_next_source_link= Next_SRCL_of_SRCL(r->t_trace_next_source_link);
source= &(completion_link->t_source);
r->t_trace_source= source;
return Cause_AHFA_State_ID_of_SRC(source);
}

/*:810*//*813:*/
#line 7003 "./marpa.w"

Marpa_Symbol_ID
marpa_first_leo_link_trace(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 7007 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 7011 "./marpa.w"

/*818:*/
#line 7079 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:818*/
#line 7012 "./marpa.w"

switch((source_type= Source_Type_of_EIM(item)))
{
case SOURCE_IS_LEO:
r->t_trace_source_type= SOURCE_IS_LEO;
source= &(item->t_container.t_unique);
r->t_trace_source= source;
r->t_trace_next_source_link= NULL;
return Cause_AHFA_State_ID_of_SRC(source);
case SOURCE_IS_AMBIGUOUS:
{
SRCL full_link= 
First_Leo_SRCL_of_EIM(item);
if(full_link)
{
source= &(full_link->t_source);
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_next_source_link= (SRCL)
Next_SRCL_of_SRCL(full_link);
r->t_trace_source= source;
return Cause_AHFA_State_ID_of_SRC(source);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:813*//*817:*/
#line 7050 "./marpa.w"

Marpa_Symbol_ID
marpa_next_leo_link_trace(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 7054 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 7058 "./marpa.w"

/*818:*/
#line 7079 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:818*/
#line 7059 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_LEO)
{
trace_source_link_clear(r);
R_ERROR("not tracing leo links");
return failure_indicator;
}
if(!r->t_trace_next_source_link)
{
trace_source_link_clear(r);
return-1;
}
full_link= r->t_trace_next_source_link;
source= &(full_link->t_source);
r->t_trace_source= source;
r->t_trace_next_source_link= 
Next_SRCL_of_SRCL(r->t_trace_next_source_link);
return Cause_AHFA_State_ID_of_SRC(source);
}

/*:817*//*821:*/
#line 7090 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r){
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:821*//*823:*/
#line 7107 "./marpa.w"

AHFAID marpa_source_predecessor_state(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 7110 "./marpa.w"

guint source_type;
SRC source;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 7113 "./marpa.w"

source_type= r->t_trace_source_type;
/*832:*/
#line 7249 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:832*/
#line 7115 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:{
EIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return-1;
return AHFAID_of_EIM(predecessor);
}
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:823*//*826:*/
#line 7144 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 7147 "./marpa.w"

guint source_type;
SRC source;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 7150 "./marpa.w"

source_type= r->t_trace_source_type;
/*832:*/
#line 7249 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:832*/
#line 7152 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_Symbol_ID_of_SRC(source);
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:826*//*829:*/
#line 7191 "./marpa.w"

Marpa_Earleme marpa_source_middle(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 7194 "./marpa.w"

const Marpa_Earleme no_predecessor= -1;
guint source_type;
SRC source;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 7198 "./marpa.w"

source_type= r->t_trace_source_type;
/*832:*/
#line 7249 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:832*/
#line 7200 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
{
LIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return no_predecessor;
return
Earleme_of_EIM(Base_EIM_of_LIM(predecessor));
}
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:
{
EIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return no_predecessor;
return Earleme_of_EIM(predecessor);
}
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:829*//*831:*/
#line 7232 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p)
{
/*1029:*/
#line 9262 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1029*/
#line 7235 "./marpa.w"

guint source_type;
SRC source;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 7238 "./marpa.w"

source_type= r->t_trace_source_type;
/*832:*/
#line 7249 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:832*/
#line 7240 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
*value_p= Token_Value_of_SRC(source);
return TRUE;
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:831*//*833:*/
#line 7257 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
AHFA state;
GRAMMARC g= G_of_R(r);
const gint symbol_count_of_g= SYM_Count_of_G(g);
GSequenceIter*current_iter;
/*1029:*/
#line 9262 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1029*/
#line 7265 "./marpa.w"

/*1039:*/
#line 9322 "./marpa.w"

if(r->t_phase!=initial_phase){
R_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1039*/
#line 7266 "./marpa.w"

/*606:*/
#line 5094 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*603:*/
#line 5080 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:603*/
#line 5097 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:606*/
#line 7267 "./marpa.w"

/*609:*/
#line 5120 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:609*//*613:*/
#line 5140 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:613*/
#line 7268 "./marpa.w"

set0= earley_set_new(r,0);
LV_Current_ES_Iter_of_R(r)= g_sequence_prepend(r->earley_sets,set0);
current_iter= Current_ES_Iter_of_R(r);
state= AHFA_by_ID(0);
item= earley_item_assign(r,set0,set0,state);
state= Empty_Transition_of_AHFA(state);
if(state){
item= earley_item_assign(r,set0,set0,state);
}
r->t_phase= active_phase;
/*862:*/
#line 7568 "./marpa.w"

DSTACK_INIT(r->completion_stack,EIM,
MAX(1024,r->earley_item_warning_threshold));
/*:862*/
#line 7279 "./marpa.w"

postdot_items_create(r,set0);
r->t_is_using_leo= r->t_use_leo_flag;
return TRUE;
}
/*:833*//*842:*/
#line 7344 "./marpa.w"

gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length){
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 7347 "./marpa.w"

const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
/*843:*/
#line 7365 "./marpa.w"

ES current_earley_set;
Marpa_Earleme current_earleme= Current_Earleme(r);
PIM working_pim;
EIM postdot_earley_item;
Marpa_Earleme target_earleme;
ES target_earley_set;
EIM target_earley_item= NULL;
AHFA target_AHFA_state;
const struct marpa_g*g= G_of_R(r);
struct symbol*token= SYM_by_ID(g,token_id);

/*:843*/
#line 7350 "./marpa.w"

/*844:*/
#line 7377 "./marpa.w"

/*1041:*/
#line 9332 "./marpa.w"

if(r->t_phase!=active_phase){
R_ERROR("recce not active");
return failure_indicator;
}
/*:1041*/
#line 7378 "./marpa.w"

if(!SYM_is_Terminal(token)){
R_ERROR("token is not a terminal");
return failure_indicator;
}
if(length<=0){
R_ERROR("token length negative or zero");
return failure_indicator;
}
if(length>=EARLEME_THRESHOLD){
R_ERROR("token too long");
return failure_indicator;
}

/*:844*/
#line 7351 "./marpa.w"

/*845:*/
#line 7392 "./marpa.w"

target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
r_context_clear(r);
r_context_int_add(r,"target_earleme",target_earleme);
R_ERROR_CXT("parse too long");
return failure_indicator;
}

/*:845*/
#line 7352 "./marpa.w"

/*846:*/
#line 7408 "./marpa.w"

current_earley_set= Current_ES_of_R(r);
working_pim= First_PIM_of_ES_by_SYMID(current_earley_set,token_id);
if(!working_pim)
return unexpected_token_indicator;
postdot_earley_item= EIM_of_PIM(working_pim);
if(!postdot_earley_item)
{



working_pim= Next_PIM_of_PIM(working_pim);
postdot_earley_item= EIM_of_PIM(working_pim);
}
later_earley_set_assign(r,target_earleme,&target_earley_set);

/*:846*/
#line 7353 "./marpa.w"

/*847:*/
#line 7424 "./marpa.w"
{
target_AHFA_state
= To_AHFA_of_EIM_by_SYMID(postdot_earley_item,token_id);
target_earley_item= earley_item_assign(r,target_earley_set,
Origin_of_EIM(postdot_earley_item),
target_AHFA_state);
}

/*:847*/
#line 7354 "./marpa.w"

/*859:*/
#line 7535 "./marpa.w"

if(Earley_Item_has_Token_Source(target_earley_item)){
if(!earley_item_cmp
(postdot_earley_item,
Predecessor_of_EIM(target_earley_item),NULL))
{
return duplicate_token_indicator;
}
}else if(Earley_Item_is_Ambiguous(target_earley_item)){
SRCL link= 
First_Token_Link_of_EIM(target_earley_item);
while(link)
{
if(!earley_item_cmp
(postdot_earley_item,Predecessor_of_SRCL(link),NULL))
{
return duplicate_token_indicator;
}
link= Next_SRCL_of_SRCL(link);
}
}

/*:859*/
#line 7355 "./marpa.w"

for(;;){
/*848:*/
#line 7432 "./marpa.w"

token_link_add(r,target_earley_item,postdot_earley_item,
token_id,value);

/*:848*/
#line 7357 "./marpa.w"

/*849:*/
#line 7436 "./marpa.w"
{
AHFA target_AHFA_prediction_state= 
Empty_Transition_of_AHFA(target_AHFA_state);
if(target_AHFA_prediction_state)
{
earley_item_assign(r,target_earley_set,target_earley_set,
target_AHFA_prediction_state);
}
}

/*:849*/
#line 7358 "./marpa.w"

/*850:*/
#line 7446 "./marpa.w"

working_pim= Next_PIM_of_PIM(working_pim);
if(!working_pim){
return current_earleme;
}
postdot_earley_item= EIM_of_PIM(working_pim);


/*:850*/
#line 7359 "./marpa.w"

/*847:*/
#line 7424 "./marpa.w"
{
target_AHFA_state
= To_AHFA_of_EIM_by_SYMID(postdot_earley_item,token_id);
target_earley_item= earley_item_assign(r,target_earley_set,
Origin_of_EIM(postdot_earley_item),
target_AHFA_state);
}

/*:847*/
#line 7360 "./marpa.w"

}
return current_earleme;
}

/*:842*//*866:*/
#line 7591 "./marpa.w"

Marpa_Earleme
marpa_earleme_complete(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 7595 "./marpa.w"

Marpa_Earleme new_current_earleme;
EIM*cause_p;
ES current_earley_set;
gint count_of_expected_terminals;
/*867:*/
#line 7619 "./marpa.w"
{
ES dummy;
GSequenceIter*current_earley_set_iter= Current_ES_Iter_of_R(r);
new_current_earleme
= Earleme_of_ES_Iter(current_earley_set_iter)+1;
if(new_current_earleme> Furthest_Earleme(r))
{
r->t_phase= exhausted_phase;
R_ERROR("parse exhausted");
return failure_indicator;
}
current_earley_set_iter
= LV_Current_ES_Iter_of_R(r)
= later_earley_set_assign(r,new_current_earleme,&dummy);
current_earley_set= g_sequence_get(current_earley_set_iter);
G_DEBUG3("%d: Initialized a new current earley set: %d",
__LINE__,ID_of_ES(current_earley_set));
}

/*:867*/
#line 7600 "./marpa.w"

/*868:*/
#line 7638 "./marpa.w"
{
GSequence*earley_item_sequence
= EIM_Sequence_of_ES(current_earley_set);
GSequenceIter*earley_item_iter;
DSTACK_REINIT(r->completion_stack);
for(earley_item_iter= 
g_sequence_get_begin_iter(earley_item_sequence);
!g_sequence_iter_is_end(earley_item_iter);
earley_item_iter= g_sequence_iter_next(earley_item_iter))
{
EIM*tos;
EIM item;
item= g_sequence_get(earley_item_iter);
if(!Earley_Item_is_Completion(item))
continue;
tos= DSTACK_PUSH(r->completion_stack,EIM);
*tos= item;
}
}

/*:868*/
#line 7601 "./marpa.w"

while((cause_p= DSTACK_POP(r->completion_stack,EIM))){
EIM cause= *cause_p;
/*869:*/
#line 7660 "./marpa.w"
{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDARY_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++){
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*870:*/
#line 7671 "./marpa.w"

{
PIM postdot_item;
for(postdot_item= First_PIM_of_ES_by_SYMID(middle,complete_symbol);
postdot_item;postdot_item= Next_PIM_of_PIM(postdot_item))
{
EIM predecessor= EIM_of_PIM(postdot_item);
EIM effect;
AHFA effect_AHFA_state;
if(predecessor)
{
/*871:*/
#line 7694 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*872:*/
#line 7710 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->completion_stack,EIM);
*tos= effect;
}

/*:872*/
#line 7703 "./marpa.w"

}
/*873:*/
#line 7715 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:873*/
#line 7705 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:871*/
#line 7682 "./marpa.w"

}
else
{
/*874:*/
#line 7725 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*872:*/
#line 7710 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->completion_stack,EIM);
*tos= effect;
}

/*:872*/
#line 7734 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:874*/
#line 7686 "./marpa.w"

break;


}
}
}

/*:870*/
#line 7667 "./marpa.w"

}
}

/*:869*/
#line 7604 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&ID_of_ES(current_earley_set)>=Furthest_Earleme(r))
{


r->t_phase= exhausted_phase;
}
return count_of_expected_terminals;
}

/*:866*//*878:*/
#line 7759 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES current_earley_set)
{
gpointer*const pim_workarea= r->t_sym_workarea;
GRAMMARC g= G_of_R(r);
GSequence*earley_item_sequence= EIM_Sequence_of_ES(current_earley_set);
Marpa_Earleme current_earley_set_id= ID_of_ES(current_earley_set);
GSequenceIter*earley_item_iter;
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
G_DEBUG2("postdot_items_create, set=%d",ID_of_ES(current_earley_set));
/*879:*/
#line 7784 "./marpa.w"

for(earley_item_iter= 
g_sequence_get_begin_iter(earley_item_sequence);
!g_sequence_iter_is_end(earley_item_iter);
earley_item_iter= g_sequence_iter_next(earley_item_iter))
{
EIM item= g_sequence_get(earley_item_iter);
AHFA state= AHFA_of_EIM(item);
gint symbol_ix;
gint postdot_symbol_count= Postdot_SYM_Count_of_AHFA(state);
Marpa_Symbol_ID*postdot_symbols= 
Postdot_SYMID_Ary_of_AHFA(state);
for(symbol_ix= 0;symbol_ix<postdot_symbol_count;symbol_ix++)
{
PIM old_pim= NULL;
PIM new_pim;
Marpa_Symbol_ID symid;
new_pim= obstack_alloc(&r->obs,sizeof(EIXD));
symid= postdot_symbols[symbol_ix];
LV_Postdot_SYMID_of_PIM(new_pim)= symid;
LV_EIM_of_PIM(new_pim)= item;
if(bv_bit_test(bv_pim_symbols,(guint)symid))
old_pim= pim_workarea[symid];
if(old_pim){
LV_Next_PIM_of_PIM(new_pim)= old_pim;
}else{
LV_Next_PIM_of_PIM(new_pim)= NULL;
current_earley_set->t_postdot_sym_count++;
}
pim_workarea[symid]= new_pim;
bv_bit_set(bv_pim_symbols,(guint)symid);
}
}

/*:879*/
#line 7773 "./marpa.w"

if(r->t_is_using_leo){
/*881:*/
#line 7828 "./marpa.w"
{
guint min,max,start;
for(start= 0;bv_scan(bv_pim_symbols,start,&min,&max);start= max+2){
SYMID symid;
for(symid= (SYMID)min;symid<=(SYMID)max;symid++){
PIM this_pim= pim_workarea[symid];
EIM leo_base;
AHFA base_to_ahfa;
if(Next_PIM_of_PIM(this_pim))continue;


leo_base= EIM_of_PIM(this_pim);
base_to_ahfa= To_AHFA_of_EIM_by_SYMID(leo_base,symid);
if(!AHFA_is_Leo_Completion(base_to_ahfa))continue;
/*882:*/
#line 7853 "./marpa.w"
{
LIM new_lim;
new_lim= obstack_alloc(&r->obs,sizeof(*new_lim));
LV_Postdot_SYMID_of_LIM(new_lim)= symid;
LV_EIM_of_PIM(new_lim)= NULL;
LV_Predecessor_LIM_of_LIM(new_lim)= NULL;
LV_Origin_of_LIM(new_lim)= NULL;
LV_Top_AHFA_of_LIM(new_lim)= base_to_ahfa;
LV_Base_EIM_of_LIM(new_lim)= leo_base;
LV_ES_of_LIM(new_lim)= current_earley_set;
LV_Next_PIM_of_LIM(new_lim)= this_pim;
pim_workarea[symid]= new_lim;
bv_bit_set(bv_lim_symbols,(guint)symid);
}

/*:882*/
#line 7842 "./marpa.w"

}
}
}

/*:881*/
#line 7775 "./marpa.w"

/*891:*/
#line 7937 "./marpa.w"
{
const Bit_Vector bv_ok_for_chain= r->t_bv_sym3;
guint min,max,start;

bv_copy(bv_ok_for_chain,bv_lim_symbols);
for(start= 0;bv_scan(bv_lim_symbols,start,&min,&max);
start= max+2)
{

SYMID main_loop_symbol_id;
for(main_loop_symbol_id= (SYMID)min;
main_loop_symbol_id<=(SYMID)max;
main_loop_symbol_id++)
{
LIM predecessor_lim;
LIM lim_to_process= pim_workarea[main_loop_symbol_id];
if(LIM_is_Populated(lim_to_process))continue;

/*894:*/
#line 7996 "./marpa.w"
{
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
const ES predecessor_set= Origin_of_EIM(base_eim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const SYMID predecessor_transition_symbol= Leo_LHS_ID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(ID_of_ES(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_ES_by_SYMID(predecessor_set,predecessor_transition_symbol);
}else{
predecessor_pim= pim_workarea[predecessor_transition_symbol];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:894*/
#line 7955 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*900:*/
#line 8088 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:900*/
#line 7957 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*902:*/
#line 8107 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
}

/*:902*/
#line 7963 "./marpa.w"

continue;
}
/*895:*/
#line 8011 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*898:*/
#line 8032 "./marpa.w"
{
SYMID postdot_symid_of_lim_to_process
= Postdot_SYMID_of_LIM(lim_to_process);
lim_chain_ix= 0;
lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);
bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);


while(1){
lim_to_process= predecessor_lim;






postdot_symid_of_lim_to_process= Postdot_SYMID_of_LIM(lim_to_process);
if(!bv_bit_test(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process)){





break;
}

/*894:*/
#line 7996 "./marpa.w"
{
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
const ES predecessor_set= Origin_of_EIM(base_eim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const SYMID predecessor_transition_symbol= Leo_LHS_ID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(ID_of_ES(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_ES_by_SYMID(predecessor_set,predecessor_transition_symbol);
}else{
predecessor_pim= pim_workarea[predecessor_transition_symbol];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:894*/
#line 8058 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:898*/
#line 8014 "./marpa.w"

/*899:*/
#line 8077 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*900:*/
#line 8088 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:900*/
#line 8081 "./marpa.w"

}else{
/*902:*/
#line 8107 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
}

/*:902*/
#line 8083 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:899*/
#line 8015 "./marpa.w"

}

/*:895*/
#line 7966 "./marpa.w"

}
}
}

/*:891*/
#line 7776 "./marpa.w"

}
/*903:*/
#line 8112 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= obstack_alloc(&r->obs,
current_earley_set->t_postdot_sym_count*sizeof(PIM));
guint min,max,start;
gint postdot_array_ix= 0;
for(start= 0;bv_scan(bv_pim_symbols,start,&min,&max);start= max+2){
SYMID symid;
for(symid= (SYMID)min;symid<=(SYMID)max;symid++){
PIM this_pim= pim_workarea[symid];
if(this_pim)postdot_array[postdot_array_ix++]= this_pim;
}
}
}

/*:903*/
#line 7778 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:878*//*907:*/
#line 8168 "./marpa.w"

gint leo_completion_expand(RECCE r,EIM leo_completion)
{
gint leo_path_lengths= 0;
const ES earley_set_of_this_path= ES_of_EIM(leo_completion);
LIM this_lim= NULL;
EIM previous_eim_on_this_path= NULL;
SRCL next_leo_link= NULL;
if(EIM_is_Leo_Expanded(leo_completion))return 0;

LV_EIM_is_Leo_Expanded(leo_completion)= 1;
switch(Source_Type_of_EIM(leo_completion)){
case SOURCE_IS_AMBIGUOUS:{
const SRCL leo_link= First_Leo_SRCL_of_EIM(leo_completion);
if(!leo_link)return 0;
/*908:*/
#line 8214 "./marpa.w"
{
this_lim= Predecessor_of_SRCL(leo_link);
previous_eim_on_this_path= Cause_of_SRCL(leo_link);
leo_path_lengths+= 2;

}

/*:908*/
#line 8183 "./marpa.w"

next_leo_link= Next_SRCL_of_SRCL(leo_link);
}
break;
case SOURCE_IS_LEO:
this_lim= Predecessor_of_EIM(leo_completion);
previous_eim_on_this_path= Cause_of_EIM(leo_completion);
leo_path_lengths+= 2;

break;
}
if(!this_lim)return 0;

r->t_is_leo_expanding= 1;


for(;;){
/*909:*/
#line 8221 "./marpa.w"
{
LIM next_lim;
while((next_lim= Predecessor_LIM_of_LIM(this_lim))){
/*910:*/
#line 8235 "./marpa.w"

{
const EIM base_eim_of_this_lim= Base_EIM_of_LIM(this_lim);
const SYMID postdot_symbol_of_this_lim= Postdot_SYMID_of_LIM(this_lim);
EIM new_eim_for_this_path= 
earley_item_assign(r,earley_set_of_this_path,
ES_of_LIM(next_lim),
To_AHFA_of_EIM_by_SYMID(base_eim_of_this_lim,
postdot_symbol_of_this_lim));
leo_path_lengths++;
completion_link_add(r,new_eim_for_this_path,
base_eim_of_this_lim,
previous_eim_on_this_path);
previous_eim_on_this_path= new_eim_for_this_path;
}

/*:910*/
#line 8224 "./marpa.w"

this_lim= next_lim;
}
completion_link_add(r,leo_completion,Base_EIM_of_LIM(this_lim),previous_eim_on_this_path);



}

/*:909*/
#line 8200 "./marpa.w"

if(!next_leo_link)break;
{
const SRCL leo_link= next_leo_link;
next_leo_link= Next_SRCL_of_SRCL(leo_link);
/*908:*/
#line 8214 "./marpa.w"
{
this_lim= Predecessor_of_SRCL(leo_link);
previous_eim_on_this_path= Cause_of_SRCL(leo_link);
leo_path_lengths+= 2;

}

/*:908*/
#line 8205 "./marpa.w"

}
}
r->t_is_leo_expanding= 0;


return leo_path_lengths;
}

/*:907*//*914:*/
#line 8267 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r)
{
/*1031:*/
#line 9267 "./marpa.w"
const int failure_indicator= -2;

/*:1031*/
#line 8270 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1042:*/
#line 9337 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1042*/
#line 8272 "./marpa.w"

if(!item){
/*725:*/
#line 6046 "./marpa.w"

r->t_trace_earley_item_iter= NULL;
r->t_trace_earley_item= NULL;

/*:725*/
#line 8274 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return leo_completion_expand(r,item);
}

/*:914*//*931:*/
#line 8406 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:931*//*933:*/
#line 8414 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:933*//*935:*/
#line 8430 "./marpa.w"

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
/*:935*//*937:*/
#line 8447 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:937*//*939:*/
#line 8459 "./marpa.w"
static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from)
{
guint*p_to= bv_to;
const guint bits= BV_BITS(bv_to);
if(bits> 0)
{
gint count= BV_SIZE(bv_to);
while(count--)*p_to++= *bv_from++;
}
return(bv_to);
}
/*:939*//*941:*/
#line 8479 "./marpa.w"
static inline
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}
/*:941*//*943:*/
#line 8489 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:943*//*945:*/
#line 8498 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:945*//*947:*/
#line 8506 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:947*//*951:*/
#line 8521 "./marpa.w"

static inline void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:951*//*953:*/
#line 8530 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:953*//*955:*/
#line 8538 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:955*//*957:*/
#line 8546 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:957*//*960:*/
#line 8555 "./marpa.w"

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
/*:960*//*962:*/
#line 8572 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:962*//*964:*/
#line 8584 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:964*//*966:*/
#line 8596 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:966*//*968:*/
#line 8608 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:968*//*970:*/
#line 8620 "./marpa.w"

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
/*:970*//*972:*/
#line 8696 "./marpa.w"

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
/*:972*//*978:*/
#line 8750 "./marpa.w"

static void
rhs_closure(struct marpa_g*g,Bit_Vector bv)
{
guint min,max,start= 0;
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_DECLARE(stack,Marpa_Symbol_ID);
FSTACK_INIT(stack,Marpa_Symbol_ID,SYM_Count_of_G(g));
while(bv_scan(bv,start,&min,&max))
{
guint symid;
for(symid= min;symid<=max;symid++)
{
*(FSTACK_PUSH(stack))= symid;
}
start= max+2;
}
while((top_of_stack= FSTACK_POP(stack)))
{
guint rule_ix;
GArray*rules= SYM_by_ID(g,*top_of_stack)->rhs;
for(rule_ix= 0;rule_ix<rules->len;rule_ix++)
{
Marpa_Rule_ID rule_id= 
g_array_index(rules,Marpa_Rule_ID,rule_ix);
RULE rule= rule_id2p(g,rule_id);
guint rule_length;
guint rh_ix;
Marpa_Symbol_ID lhs_id= LHS_ID_of_PRD(rule);
if(bv_bit_test(bv,(guint)lhs_id))
goto NEXT_RULE;
rule_length= rule->length;
for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test(bv,(guint)rhs_symid(rule,rh_ix)))
goto NEXT_RULE;
}



bv_bit_set(bv,(guint)lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}
/*:978*//*983:*/
#line 8829 "./marpa.w"

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
/*:983*//*985:*/
#line 8849 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:985*//*987:*/
#line 8862 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:987*//*989:*/
#line 8879 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:989*//*992:*/
#line 8889 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:992*//*995:*/
#line 8898 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:995*//*998:*/
#line 8907 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:998*//*1000:*/
#line 8921 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix)
{
struct transition{guint from,to;}*top_of_stack= NULL;
guint size= matrix_columns(matrix);
guint row;
DSTACK_DECLARE(stack);
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
/*:1000*//*1008:*/
#line 9049 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}
/*:1008*//*1014:*/
#line 9107 "./marpa.w"

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
/*:1014*//*1050:*/
#line 9417 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags){
if(!(flags&CONTEXT_FLAG))r_context_clear(r);
r->t_error= message;
if(flags&FATAL_FLAG)r->t_fatal_error= r->t_error;
r_message(r,message);
}

/*:1050*//*1058:*/
#line 9491 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->message_callback_arg= cb_arg;}
gpointer marpa_g_message_callback_arg(struct marpa_g*g)
{return g->message_callback_arg;}
/*:1058*//*1060:*/
#line 9508 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_G_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:1060*//*1066:*/
#line 9526 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb)
{r->message_callback= cb;}
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg)
{r->message_callback_arg= cb_arg;}
gpointer marpa_r_message_callback_arg(struct marpa_r*r)
{return r->message_callback_arg;}
/*:1066*//*1068:*/
#line 9537 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id)
{Marpa_R_Message_Callback*cb= r->message_callback;
if(cb){(*cb)(r,id);}}
/*:1068*//*1072:*/
#line 9571 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
eim_tag(gchar*buffer,EIM eim)
{
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_EIM(eim),Origin_ID_of_EIM(eim),Earleme_of_EIM(eim));
return buffer;
}
#endif

/*:1072*//*1074:*/
#line 9592 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_SYMID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}
#endif

/*:1074*/
#line 9659 "./marpa.w"


/*:1080*/
