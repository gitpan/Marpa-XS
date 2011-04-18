/*1082:*/
#line 9679 "./marpa.w"

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

/*:1082*//*1083:*/
#line 9702 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1073:*/
#line 9608 "./marpa.w"

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

/*:1073*/
#line 9705 "./marpa.w"

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
#define First_ES_of_R(r) ((r) ->t_first_earley_set) 
#define LV_First_ES_of_R(r) First_ES_of_R(r) 
#define Current_ES_of_R(r) ((r) ->t_current_earley_set) 
#define LV_Current_ES_of_R(r) Current_ES_of_R(r) 
#define Current_Earleme(r) (ID_of_ES(Current_ES_of_R(r) ) ) 
#define DEFAULT_EIM_WARNING_THRESHOLD (100) 
#define Furthest_Earleme(r) ((r) ->t_furthest_earleme) 
#define LV_Furthest_Earleme(r) Furthest_Earleme(r) 
#define EARLEME_THRESHOLD (G_MAXINT/4) 
#define EIM_Sequence_of_ES(set) ((set) ->t_eims) 
#define EIM_Count_of_ES(set) ((set) ->t_eim_count) 
#define Next_ES_of_ES(set) ((set) ->t_next_earley_set) 
#define LV_Next_ES_of_ES(set) Next_ES_of_ES(set) 
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
#define ES_of_EIM(item) ((item) ->t_key.t_set) 
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

#line 9706 "./marpa.w"

#include "marpa_obs.h"
/*1055:*/
#line 9502 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1055*/
#line 9708 "./marpa.w"

/*483:*/
#line 3825 "./marpa.w"
struct s_AHFA_state;
/*:483*//*664:*/
#line 5468 "./marpa.w"
struct s_earley_set;
/*:664*//*698:*/
#line 5766 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:698*/
#line 9709 "./marpa.w"

/*45:*/
#line 722 "./marpa.w"

typedef struct marpa_g*GRAMMAR;
typedef const struct marpa_g*GRAMMARC;

/*:45*//*216:*/
#line 1570 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:216*//*443:*/
#line 3509 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;

/*:443*//*485:*/
#line 3845 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:485*//*566:*/
#line 4950 "./marpa.w"
typedef struct marpa_r*RECCE;
/*:566*//*662:*/
#line 5465 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:662*//*666:*/
#line 5492 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;

/*:666*//*770:*/
#line 6579 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:770*//*772:*/
#line 6589 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:772*//*932:*/
#line 8450 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:932*//*984:*/
#line 8880 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:984*/
#line 9710 "./marpa.w"

/*31:*/
#line 602 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:31*//*53:*/
#line 755 "./marpa.w"
static gint next_grammar_id= 1;
/*:53*//*575:*/
#line 5001 "./marpa.w"
static gint next_recce_id= 1;
/*:575*//*933:*/
#line 8457 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:933*/
#line 9711 "./marpa.w"

/*1010:*/
#line 9106 "./marpa.w"

struct dstack{gint t_ix;gint t_capacity;gpointer t_base;};
/*:1010*/
#line 9712 "./marpa.w"

/*44:*/
#line 716 "./marpa.w"
struct marpa_g{
/*57:*/
#line 768 "./marpa.w"
GArray*symbols;
/*:57*//*67:*/
#line 816 "./marpa.w"
GArray*rules;
/*:67*//*105:*/
#line 998 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:105*//*108:*/
#line 1011 "./marpa.w"
GHashTable*context;
/*:108*//*123:*/
#line 1104 "./marpa.w"

struct obstack obs;
struct obstack obs_tricky;
/*:123*//*127:*/
#line 1126 "./marpa.w"
Marpa_Error_ID error;
/*:127*//*208:*/
#line 1534 "./marpa.w"

Marpa_Symbol_Callback*symbol_callback;
gpointer symbol_callback_arg;
/*:208*//*320:*/
#line 2287 "./marpa.w"

Marpa_Rule_Callback*rule_callback;
gpointer rule_callback_arg;
/*:320*//*444:*/
#line 3518 "./marpa.w"

AIM AHFA_items;
AIM*AHFA_items_by_rule;
/*:444*//*486:*/
#line 3849 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:486*//*1059:*/
#line 9544 "./marpa.w"

Marpa_G_Message_Callback*message_callback;
gpointer message_callback_arg;
/*:1059*/
#line 717 "./marpa.w"

/*51:*/
#line 753 "./marpa.w"
gint t_id;
/*:51*//*79:*/
#line 873 "./marpa.w"
Marpa_Symbol_ID start_symid;
/*:79*//*86:*/
#line 920 "./marpa.w"
int t_size;
/*:86*//*89:*/
#line 933 "./marpa.w"
guint max_rule_length;
/*:89*//*445:*/
#line 3521 "./marpa.w"

guint no_of_items;
/*:445*//*487:*/
#line 3853 "./marpa.w"
gint t_AHFA_len;
/*:487*/
#line 718 "./marpa.w"

/*91:*/
#line 938 "./marpa.w"
unsigned int is_precomputed:1;
/*:91*//*95:*/
#line 949 "./marpa.w"
unsigned int has_loop:1;
/*:95*//*99:*/
#line 964 "./marpa.w"
unsigned int is_lhs_terminal_ok:1;
/*:99*/
#line 719 "./marpa.w"

};
typedef struct marpa_g GRAMMARD;
/*:44*//*133:*/
#line 1144 "./marpa.w"

struct symbol{
/*141:*/
#line 1196 "./marpa.w"
GArray*lhs;
/*:141*//*148:*/
#line 1226 "./marpa.w"
GArray*rhs;
/*:148*//*195:*/
#line 1426 "./marpa.w"

struct symbol*alias;
/*:195*/
#line 1146 "./marpa.w"

/*139:*/
#line 1187 "./marpa.w"
Marpa_Symbol_ID t_id;
/*:139*/
#line 1147 "./marpa.w"

/*155:*/
#line 1247 "./marpa.w"
unsigned int is_accessible:1;
/*:155*//*161:*/
#line 1273 "./marpa.w"
unsigned int is_counted:1;
/*:161*//*165:*/
#line 1291 "./marpa.w"
unsigned int is_nullable:1;
/*:165*//*171:*/
#line 1316 "./marpa.w"
unsigned int is_nulling:1;
/*:171*//*177:*/
#line 1343 "./marpa.w"
unsigned int is_terminal:1;
/*:177*//*183:*/
#line 1372 "./marpa.w"
unsigned int is_productive:1;
/*:183*//*189:*/
#line 1397 "./marpa.w"
unsigned int is_start:1;
/*:189*//*194:*/
#line 1423 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:194*/
#line 1148 "./marpa.w"

};
typedef struct symbol*SYM;
typedef gint SYMID;

/*:133*//*215:*/
#line 1564 "./marpa.w"

struct s_rule{
/*245:*/
#line 1952 "./marpa.w"
guint length;
/*:245*//*265:*/
#line 2031 "./marpa.w"
Marpa_Rule_ID t_id;
/*:265*//*310:*/
#line 2249 "./marpa.w"
gint virtual_start;
/*:310*//*314:*/
#line 2265 "./marpa.w"
gint virtual_end;
/*:314*//*331:*/
#line 2322 "./marpa.w"
Marpa_Rule_ID original;
/*:331*//*336:*/
#line 2336 "./marpa.w"
guint real_symbol_count;
/*:336*/
#line 1566 "./marpa.w"

/*268:*/
#line 2043 "./marpa.w"
unsigned int is_discard:1;
/*:268*//*282:*/
#line 2127 "./marpa.w"
unsigned int is_loop:1;
/*:282*//*287:*/
#line 2148 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:287*//*294:*/
#line 2178 "./marpa.w"
unsigned int is_used:1;
/*:294*//*298:*/
#line 2194 "./marpa.w"
unsigned int t_is_start:1;
/*:298*//*302:*/
#line 2224 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:302*//*306:*/
#line 2235 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:306*//*340:*/
#line 2345 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:340*/
#line 1567 "./marpa.w"

/*246:*/
#line 1955 "./marpa.w"
Marpa_Symbol_ID symbols[1];

/*:246*/
#line 1568 "./marpa.w"

};
/*:215*//*442:*/
#line 3502 "./marpa.w"

struct s_AHFA_item{
Marpa_AHFA_Item_ID t_sort_key;
RULE t_production;
/*451:*/
#line 3544 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:451*/
#line 3506 "./marpa.w"

gint t_position;
};
/*:442*//*484:*/
#line 3826 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
AIM*t_items;
struct s_AHFA_state*t_empty_transition;
AHFA*t_to_ahfa_ary;
SYMID*t_complete_symbols;
/*497:*/
#line 3907 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:497*/
#line 3836 "./marpa.w"

/*498:*/
#line 3908 "./marpa.w"
guint t_postdot_sym_count;

/*:498*//*521:*/
#line 4118 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:521*/
#line 3837 "./marpa.w"

guint t_item_count;
guint t_complete_symbol_count;
guint t_is_predict:1;
guint t_has_completed_start_rule:1;
};
typedef struct s_AHFA_state AHFAD;

/*:484*//*567:*/
#line 4951 "./marpa.w"
struct marpa_r{
/*580:*/
#line 5012 "./marpa.w"
const struct marpa_g*t_grammar;

/*:580*//*586:*/
#line 5038 "./marpa.w"

ES t_first_earley_set;
ES t_current_earley_set;
/*:586*//*602:*/
#line 5111 "./marpa.w"
DSTACK_DECLARE(completion_stack);

/*:602*//*603:*/
#line 5123 "./marpa.w"
gpointer*t_sym_workarea;
/*:603*//*606:*/
#line 5137 "./marpa.w"
gpointer*t_workarea2;
/*:606*//*609:*/
#line 5157 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:609*//*613:*/
#line 5183 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:613*//*620:*/
#line 5234 "./marpa.w"

GTree*t_earley_sets;
GTree*t_earley_items;
/*:620*//*638:*/
#line 5354 "./marpa.w"
GHashTable*context;
/*:638*//*649:*/
#line 5409 "./marpa.w"
struct obstack obs;
/*:649*//*653:*/
#line 5423 "./marpa.w"

Marpa_Error_ID t_error;
Marpa_Error_ID t_fatal_error;
/*:653*//*683:*/
#line 5656 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:683*//*718:*/
#line 5966 "./marpa.w"

EIM t_trace_earley_item;
/*:718*//*753:*/
#line 6379 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:753*//*795:*/
#line 6872 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:795*//*1067:*/
#line 9579 "./marpa.w"

Marpa_R_Message_Callback*message_callback;
gpointer message_callback_arg;
/*:1067*/
#line 4952 "./marpa.w"

/*573:*/
#line 4999 "./marpa.w"
gint t_id;
/*:573*//*582:*/
#line 5025 "./marpa.w"

Marpa_Phase t_phase;
/*:582*//*592:*/
#line 5069 "./marpa.w"
guint earley_item_warning_threshold;
/*:592*//*598:*/
#line 5097 "./marpa.w"
Marpa_Earleme t_furthest_earleme;
/*:598*/
#line 4953 "./marpa.w"

/*619:*/
#line 5233 "./marpa.w"
unsigned int t_is_tracing:1;
/*:619*//*630:*/
#line 5299 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:630*//*636:*/
#line 5339 "./marpa.w"

unsigned int t_is_leo_expanding:1;
/*:636*//*796:*/
#line 6875 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:796*/
#line 4954 "./marpa.w"

};

/*:567*//*665:*/
#line 5477 "./marpa.w"

struct s_earley_set_key{
EARLEME t_id;
};
typedef struct s_earley_set_key ESK_Object;
typedef ESK_Object*ESK;
struct s_earley_set{
ESK_Object t_key;
GSequence*t_eims;
EIM t_earley_items;
union u_postdot_item**t_postdot_ary;
gint t_postdot_sym_count;
guint t_eim_count;
struct s_earley_set*t_next_earley_set;
};
/*:665*//*732:*/
#line 6141 "./marpa.w"

union u_postdot_item;
struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIXD;
typedef EIXD*EIX;

/*:732*//*734:*/
#line 6180 "./marpa.w"

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

/*:734*//*747:*/
#line 6326 "./marpa.w"

union u_postdot_item{
LIMD t_leo;
EIXD t_earley;
};
typedef union u_postdot_item*PIM;

/*:747*//*1014:*/
#line 9140 "./marpa.w"

struct dqueue{gint current;struct dstack s;};

/*:1014*/
#line 9713 "./marpa.w"

/*771:*/
#line 6582 "./marpa.w"

struct s_source{
gpointer t_predecessor;
gpointer t_cause;
SYMID t_symbol_id;
};

/*:771*//*773:*/
#line 6592 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:773*//*774:*/
#line 6598 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:774*//*775:*/
#line 6605 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:775*/
#line 9714 "./marpa.w"

/*699:*/
#line 5772 "./marpa.w"

struct s_earley_item_key{
AHFA t_state;
ES t_origin;
ES t_set;
};
typedef struct s_earley_item_key EIK_Object;
struct s_earley_item{
EIK_Object t_key;
struct s_earley_item*t_next;
union u_source_container t_container;
/*714:*/
#line 5926 "./marpa.w"

unsigned int t_source_type:3;

/*:714*//*715:*/
#line 5937 "./marpa.w"

unsigned int t_is_leo_expanded:1;

/*:715*/
#line 5783 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:699*/
#line 9715 "./marpa.w"

/*66:*/
#line 809 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid);

/*:66*//*73:*/
#line 836 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g);

/*:73*//*75:*/
#line 844 "./marpa.w"

static inline RULE
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id);

/*:75*//*78:*/
#line 868 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:78*//*116:*/
#line 1062 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:116*//*118:*/
#line 1074 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:118*//*120:*/
#line 1083 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g);

/*:120*//*135:*/
#line 1174 "./marpa.w"

static inline
struct symbol*symbol_new(struct marpa_g*g);
/*:135*//*138:*/
#line 1183 "./marpa.w"

static inline void symbol_free(struct symbol*symbol);

/*:138*//*147:*/
#line 1217 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id);

/*:147*//*154:*/
#line 1243 "./marpa.w"
static inline
void symbol_rhs_add(struct symbol*symbol,Marpa_Rule_ID rule_id);

/*:154*//*192:*/
#line 1410 "./marpa.w"

static inline
gint symbol_is_start(struct symbol*symbol);
/*:192*//*198:*/
#line 1451 "./marpa.w"

static inline struct symbol*symbol_proper_alias(struct symbol*symbol);
/*:198*//*201:*/
#line 1479 "./marpa.w"

static inline struct symbol*symbol_null_alias(struct symbol*symbol);
/*:201*//*204:*/
#line 1518 "./marpa.w"

static inline
struct symbol*symbol_alias_create(struct marpa_g*g,
struct symbol*symbol);
/*:204*//*213:*/
#line 1558 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:213*//*218:*/
#line 1579 "./marpa.w"

static inline guint rule_sizeof(guint length);

/*:218*//*222:*/
#line 1604 "./marpa.w"

static
RULE rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:222*//*238:*/
#line 1833 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length);

/*:238*//*250:*/
#line 1977 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
/*:250*//*254:*/
#line 1989 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule);
/*:254*//*258:*/
#line 2005 "./marpa.w"

static inline gsize rule_length_get(RULE rule);
/*:258*//*264:*/
#line 2024 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symid(RULE rule,guint rh_index);

/*:264*//*275:*/
#line 2092 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule);
/*:275*//*279:*/
#line 2116 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule);
/*:279*//*293:*/
#line 2174 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,RULE rule);

/*:293*//*329:*/
#line 2315 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:329*//*348:*/
#line 2454 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:348*//*385:*/
#line 2805 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:385*//*424:*/
#line 3172 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:424*//*427:*/
#line 3193 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:427*//*435:*/
#line 3318 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:435*//*464:*/
#line 3610 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:464*//*466:*/
#line 3637 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:466*//*473:*/
#line 3706 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:473*//*493:*/
#line 3883 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id);

/*:493*//*496:*/
#line 3898 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const AHFA state,guint item_ix);

/*:496*//*525:*/
#line 4149 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b);
/*:525*//*528:*/
#line 4202 "./marpa.w"

static void create_AHFA_states(struct marpa_g*g);

/*:528*//*540:*/
#line 4577 "./marpa.w"

static inline AHFA assign_AHFA_state(
AHFA state_p,GTree*duplicates);
/*:540*//*553:*/
#line 4760 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:553*//*556:*/
#line 4814 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
struct dqueue*states_p,
GTree*duplicates
);
/*:556*//*560:*/
#line 4915 "./marpa.w"
static inline
AHFA*to_ahfa_array_new(struct marpa_g*g);
/*:560*//*563:*/
#line 4933 "./marpa.w"
static inline
void AHFA_transition_add(AHFA from_ahfa,SYMID symid,AHFA to_ahfa);

/*:563*//*642:*/
#line 5375 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint value);
/*:642*//*644:*/
#line 5387 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*value);

/*:644*//*646:*/
#line 5396 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r);

/*:646*//*667:*/
#line 5497 "./marpa.w"

static inline ES earley_set_new(RECCE r,Marpa_Earleme id);
/*:667*//*669:*/
#line 5520 "./marpa.w"

static inline ES later_earley_set_assign(RECCE r,Marpa_Earleme sought_earleme);
/*:669*//*675:*/
#line 5594 "./marpa.w"

static inline void earley_set_free(ES set);

/*:675*//*677:*/
#line 5606 "./marpa.w"

static gint earley_set_cmp(gconstpointer a,gconstpointer b);

/*:677*//*679:*/
#line 5616 "./marpa.w"

static inline ES earley_set_by_id(struct marpa_r*r,Marpa_Earleme earleme);
/*:679*//*681:*/
#line 5630 "./marpa.w"

static void r_tracing_start(RECCE r);
/*:681*//*700:*/
#line 5793 "./marpa.w"

static inline EIM earley_item_new(RECCE r,
EIK_Object key);
/*:700*//*702:*/
#line 5815 "./marpa.w"

static inline
EIM earley_item_assign(RECCE r,ES set,ES origin,AHFA state);
/*:702*//*710:*/
#line 5895 "./marpa.w"

static gint own_earley_item_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);
static inline gint earley_item_cmp(gconstpointer a,gconstpointer b,
gpointer user_data G_GNUC_UNUSED);
static inline gint trace_earley_item_cmp(gconstpointer a,gconstpointer b);

/*:710*//*716:*/
#line 5940 "./marpa.w"

static const char*invalid_source_type_message(guint type);
/*:716*//*728:*/
#line 6102 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r);
/*:728*//*730:*/
#line 6111 "./marpa.w"

Marpa_Earleme marpa_earley_item_origin(struct marpa_r*r);
/*:730*//*736:*/
#line 6198 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r);
/*:736*//*739:*/
#line 6239 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r);
/*:739*//*741:*/
#line 6260 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r);
/*:741*//*749:*/
#line 6342 "./marpa.w"

static inline PIM*pim_sym_p_find(ES set,SYMID symid);
/*:749*//*751:*/
#line 6364 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid);
/*:751*//*762:*/
#line 6507 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r);
/*:762*//*780:*/
#line 6675 "./marpa.w"
static inline void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
SYMID token_id,
gpointer value);

/*:780*//*781:*/
#line 6682 "./marpa.w"
static inline void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause);
/*:781*//*788:*/
#line 6794 "./marpa.w"
static inline void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause);

/*:788*//*791:*/
#line 6835 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item);

/*:791*//*821:*/
#line 7130 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r);
/*:821*//*877:*/
#line 7781 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES set);
/*:877*//*907:*/
#line 8204 "./marpa.w"

static gint leo_completion_expand(RECCE r,EIM leo_completion);
/*:907*//*935:*/
#line 8470 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:935*//*937:*/
#line 8480 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:937*//*939:*/
#line 8500 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);

/*:939*//*941:*/
#line 8511 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:941*//*943:*/
#line 8530 "./marpa.w"

static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from);

/*:943*//*945:*/
#line 8543 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:945*//*947:*/
#line 8553 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:947*//*949:*/
#line 8561 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:949*//*951:*/
#line 8574 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:951*//*953:*/
#line 8578 "./marpa.w"

static inline void bv_clear(Bit_Vector bv);
/*:953*//*957:*/
#line 8593 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:957*//*959:*/
#line 8601 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:959*//*961:*/
#line 8609 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:961*//*964:*/
#line 8626 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:964*//*966:*/
#line 8639 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:966*//*968:*/
#line 8651 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:968*//*970:*/
#line 8663 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:970*//*972:*/
#line 8675 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:972*//*974:*/
#line 8749 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:974*//*976:*/
#line 8767 "./marpa.w"

static inline guint bv_count(Bit_Vector v);

/*:976*//*982:*/
#line 8856 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:982*//*987:*/
#line 8904 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:987*//*989:*/
#line 8912 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:989*//*991:*/
#line 8926 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:991*//*993:*/
#line 8944 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:993*//*996:*/
#line 8953 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:996*//*999:*/
#line 8962 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:999*//*1002:*/
#line 8971 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:1002*//*1004:*/
#line 9024 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:1004*//*1012:*/
#line 9114 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:1012*//*1018:*/
#line 9181 "./marpa.w"

static inline GSequenceIter*sequence_find(GSequence*sequence,void*key,
GCompareDataFunc compare,gboolean*match);

/*:1018*//*1052:*/
#line 9469 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags);
/*:1052*//*1064:*/
#line 9571 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id);

/*:1064*//*1072:*/
#line 9600 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id);

/*:1072*//*1074:*/
#line 9625 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*eim_tag(gchar*buffer,EIM eim);
#endif
/*:1074*//*1076:*/
#line 9644 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim);
#endif
/*:1076*/
#line 9716 "./marpa.w"

/*64:*/
#line 793 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symid,
struct symbol*symbol)
{
g_array_insert_val(g->symbols,(unsigned)symid,symbol);
}

/*:64*//*76:*/
#line 850 "./marpa.w"

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

/*:76*/
#line 9717 "./marpa.w"

/*32:*/
#line 609 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:32*//*46:*/
#line 726 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*54:*/
#line 756 "./marpa.w"

g->t_id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:54*//*58:*/
#line 769 "./marpa.w"

g->symbols= g_array_new(FALSE,FALSE,sizeof(struct symbol*));
/*:58*//*68:*/
#line 817 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:68*//*80:*/
#line 874 "./marpa.w"

g->start_symid= -1;
/*:80*//*87:*/
#line 921 "./marpa.w"

LV_Size_of_G(g)= 0;

/*:87*//*90:*/
#line 934 "./marpa.w"

g->max_rule_length= 0;

/*:90*//*92:*/
#line 939 "./marpa.w"

g->is_precomputed= FALSE;
/*:92*//*96:*/
#line 950 "./marpa.w"

g->has_loop= FALSE;
/*:96*//*100:*/
#line 965 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:100*//*106:*/
#line 999 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:106*//*109:*/
#line 1012 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:109*//*124:*/
#line 1107 "./marpa.w"

obstack_init(&g->obs);
obstack_init(&g->obs_tricky);
/*:124*//*128:*/
#line 1127 "./marpa.w"

g->error= NULL;
/*:128*//*209:*/
#line 1537 "./marpa.w"

g->symbol_callback_arg= NULL;
g->symbol_callback= NULL;
/*:209*//*321:*/
#line 2290 "./marpa.w"

g->rule_callback_arg= NULL;
g->rule_callback= NULL;
/*:321*//*447:*/
#line 3526 "./marpa.w"

g->AHFA_items= NULL;
g->AHFA_items_by_rule= NULL;
/*:447*//*488:*/
#line 3854 "./marpa.w"

g->t_AHFA= NULL;
LV_AHFA_Count_of_G(g)= 0;
/*:488*//*1060:*/
#line 9547 "./marpa.w"

g->message_callback_arg= NULL;
g->message_callback= NULL;
/*:1060*/
#line 729 "./marpa.w"

return g;}
/*:46*//*48:*/
#line 734 "./marpa.w"

void marpa_g_free(struct marpa_g*g)
{/*59:*/
#line 771 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->symbols->len;id++)
{symbol_free(SYM_by_ID(g,id));}}
g_array_free(g->symbols,TRUE);

/*:59*//*69:*/
#line 819 "./marpa.w"

g_array_free(g->rules,TRUE);

/*:69*//*107:*/
#line 1000 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:107*//*110:*/
#line 1014 "./marpa.w"
g_hash_table_destroy(g->context);

/*:110*//*125:*/
#line 1110 "./marpa.w"

obstack_free(&g->obs,NULL);
obstack_free(&g->obs_tricky,NULL);

/*:125*//*448:*/
#line 3529 "./marpa.w"

if(g->AHFA_items){g_free(g->AHFA_items);};
if(g->AHFA_items_by_rule){g_free(g->AHFA_items_by_rule);};

/*:448*//*489:*/
#line 3858 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_by_ID(id);
/*490:*/
#line 3868 "./marpa.w"
{
AHFA*ahfa_transition_array= ahfa_state->t_to_ahfa_ary;
if(ahfa_transition_array)g_free(ahfa_state->t_to_ahfa_ary);
}

/*:490*/
#line 3862 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:489*/
#line 736 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:48*//*55:*/
#line 758 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->t_id;}
/*:55*//*60:*/
#line 779 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:60*//*65:*/
#line 804 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid){
return symid>=0&&(guint)symid<g->symbols->len;
}
/*:65*//*70:*/
#line 825 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:70*//*72:*/
#line 832 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g){
return g->rules->len;
}
/*:72*//*74:*/
#line 840 "./marpa.w"

static inline RULE
rule_id2p(const struct marpa_g*g,Marpa_Rule_ID id)
{return g_array_index(g->rules,RULE,id);}
/*:74*//*77:*/
#line 863 "./marpa.w"

static inline gint rule_is_valid(
const struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_id>=0&&(guint)rule_id<g->rules->len;
}
/*:77*//*81:*/
#line 877 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->start_symid;}
/*:81*//*83:*/
#line 884 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1032:*/
#line 9321 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1032*/
#line 887 "./marpa.w"

if(g->is_precomputed){
g_context_clear(g);
g->error= "precomputed";
return failure_indicator;
}
/*1036:*/
#line 9337 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1036*/
#line 893 "./marpa.w"

g->start_symid= symid;
return TRUE;
}
/*:83*//*93:*/
#line 942 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{return g->is_precomputed;}
/*:93*//*97:*/
#line 953 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->has_loop;}
/*:97*//*101:*/
#line 968 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:101*//*103:*/
#line 975 "./marpa.w"

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
/*:103*//*115:*/
#line 1053 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:115*//*117:*/
#line 1065 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:117*//*119:*/
#line 1080 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:119*//*121:*/
#line 1086 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:121*//*130:*/
#line 1135 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g)
{return g->error?g->error:"unknown error";}
/*:130*//*134:*/
#line 1153 "./marpa.w"

static inline struct symbol*
symbol_new(struct marpa_g*g)
{
struct symbol*symbol= g_malloc(sizeof(struct symbol));
/*140:*/
#line 1188 "./marpa.w"
symbol->t_id= g->symbols->len;

/*:140*//*142:*/
#line 1197 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:142*//*149:*/
#line 1227 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:149*//*156:*/
#line 1248 "./marpa.w"

symbol->is_accessible= FALSE;
/*:156*//*162:*/
#line 1274 "./marpa.w"

symbol->is_counted= FALSE;
/*:162*//*166:*/
#line 1292 "./marpa.w"

symbol->is_nullable= FALSE;
/*:166*//*172:*/
#line 1317 "./marpa.w"

symbol->is_nulling= FALSE;
/*:172*//*178:*/
#line 1344 "./marpa.w"

symbol->is_terminal= FALSE;
/*:178*//*184:*/
#line 1373 "./marpa.w"

symbol->is_productive= FALSE;
/*:184*//*190:*/
#line 1398 "./marpa.w"
symbol->is_start= FALSE;
/*:190*//*196:*/
#line 1428 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:196*/
#line 1158 "./marpa.w"

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

/*:134*//*137:*/
#line 1180 "./marpa.w"

static inline void symbol_free(struct symbol*symbol)
{/*143:*/
#line 1199 "./marpa.w"

g_array_free(symbol->lhs,TRUE);
/*:143*//*150:*/
#line 1229 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:150*/
#line 1182 "./marpa.w"
g_free(symbol);}
/*:137*//*144:*/
#line 1204 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1033:*/
#line 9323 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1033*/
#line 1206 "./marpa.w"

/*1036:*/
#line 9337 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1036*/
#line 1207 "./marpa.w"

return SYM_by_ID(g,symid)->lhs;}
/*:144*//*146:*/
#line 1211 "./marpa.w"
static inline
void symbol_lhs_add(struct symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id)
{symbol_lhs_add(SYM_by_ID(g,symid),rule_id);}
/*:146*//*151:*/
#line 1233 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1033:*/
#line 9323 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1033*/
#line 1235 "./marpa.w"

/*1036:*/
#line 9337 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1036*/
#line 1236 "./marpa.w"

return SYM_by_ID(g,symid)->rhs;}
/*:151*//*153:*/
#line 1240 "./marpa.w"
static inline
void symbol_rhs_add(struct symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
/*:153*//*157:*/
#line 1258 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->is_accessible;}
/*:157*//*159:*/
#line 1264 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->is_accessible= value;}
/*:159*//*163:*/
#line 1284 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->is_counted;}
/*:163*//*167:*/
#line 1302 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->is_nullable;}
/*:167*//*169:*/
#line 1308 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->is_nullable= value;}
/*:169*//*173:*/
#line 1327 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 1329 "./marpa.w"

/*1036:*/
#line 9337 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1036*/
#line 1330 "./marpa.w"

return SYM_by_ID(g,symid)->is_nulling;}
/*:173*//*175:*/
#line 1335 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->is_nulling= value;}
/*:175*//*179:*/
#line 1357 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYMID_is_Terminal(g,id);}
/*:179*//*181:*/
#line 1363 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{LV_SYMID_is_Terminal(g,id)= value;}
/*:181*//*185:*/
#line 1383 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->is_productive;}
/*:185*//*187:*/
#line 1389 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->is_productive= value?1:0;}
/*:187*//*191:*/
#line 1401 "./marpa.w"

static inline
gint symbol_is_start(struct symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 1406 "./marpa.w"

/*1036:*/
#line 9337 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1036*/
#line 1407 "./marpa.w"

return symbol_is_start(SYM_by_ID(g,symid));
}
/*:191*//*197:*/
#line 1437 "./marpa.w"

static inline
struct symbol*symbol_proper_alias(struct symbol*symbol)
{return symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
struct symbol*symbol;
struct symbol*proper_alias;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 1445 "./marpa.w"

/*1036:*/
#line 9337 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1036*/
#line 1446 "./marpa.w"

symbol= SYM_by_ID(g,symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->t_id;
}
/*:197*//*200:*/
#line 1460 "./marpa.w"

static inline
struct symbol*symbol_null_alias(struct symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
struct symbol*symbol;
struct symbol*alias;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 1468 "./marpa.w"

/*1036:*/
#line 9337 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1036*/
#line 1469 "./marpa.w"

symbol= SYM_by_ID(g,symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
g_context_int_add(g,"symid",symid);
g->error= "no alias";
return-1;
}
return alias->t_id;
}
/*:200*//*203:*/
#line 1493 "./marpa.w"
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
/*:203*//*210:*/
#line 1540 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->symbol_callback_arg= cb_arg;}
gpointer marpa_symbol_callback_arg(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:210*//*212:*/
#line 1554 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:212*//*217:*/
#line 1575 "./marpa.w"

static inline guint rule_sizeof(guint length){
return sizeof(struct s_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:217*//*221:*/
#line 1589 "./marpa.w"

static
RULE rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
/*1033:*/
#line 9323 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1033*/
#line 1594 "./marpa.w"

RULE rule;
/*247:*/
#line 1957 "./marpa.w"

{
SYMID symid= lhs;
/*1036:*/
#line 9337 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1036*/
#line 1960 "./marpa.w"

}
{guint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1036:*/
#line 9337 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->error= "invalid symbol id";
return failure_indicator;
}
/*:1036*/
#line 1965 "./marpa.w"

}
}

/*:247*/
#line 1596 "./marpa.w"

rule= obstack_alloc(&g->obs,rule_sizeof(length));
/*248:*/
#line 1969 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{guint i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:248*/
#line 1598 "./marpa.w"

/*266:*/
#line 2032 "./marpa.w"
rule->t_id= g->rules->len;

/*:266*//*269:*/
#line 2044 "./marpa.w"

rule->is_discard= FALSE;
/*:269*//*283:*/
#line 2128 "./marpa.w"

rule->is_loop= FALSE;
/*:283*//*288:*/
#line 2149 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:288*//*295:*/
#line 2179 "./marpa.w"

rule->is_used= TRUE;
/*:295*//*299:*/
#line 2195 "./marpa.w"

rule->t_is_start= FALSE;
/*:299*//*303:*/
#line 2225 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:303*//*307:*/
#line 2236 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:307*//*311:*/
#line 2250 "./marpa.w"
rule->virtual_start= -1;
/*:311*//*315:*/
#line 2266 "./marpa.w"
rule->virtual_end= -1;
/*:315*//*332:*/
#line 2323 "./marpa.w"
rule->original= -1;
/*:332*//*337:*/
#line 2337 "./marpa.w"
rule->real_symbol_count= 0;
/*:337*//*341:*/
#line 2346 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:341*/
#line 1599 "./marpa.w"

marpa_g_rule_add(g,rule->t_id,rule);
/*240:*/
#line 1850 "./marpa.w"

symbol_lhs_add(SYM_by_ID(g,rule->symbols[0]),rule->t_id);
if(rule->length> 0){
gint rh_list_ix;
const guint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*244:*/
#line 1917 "./marpa.w"

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

/*:244*/
#line 1858 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(g,rh_symbol_list[rh_list_ix]),
rule->t_id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:240*/
#line 1601 "./marpa.w"

return rule;
}
/*:221*//*223:*/
#line 1609 "./marpa.w"

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

/*:223*//*224:*/
#line 1626 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 1631 "./marpa.w"

Marpa_Rule_ID original_rule_id;
RULE original_rule;
Marpa_Symbol_ID internal_lhs_id,*temp_rhs;
if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE){
g_context_clear(g);
g->error= (Marpa_Error_ID)"duplicate rule";
return failure_indicator;
}

/*226:*/
#line 1662 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){
g_context_clear(g);
g->error= "internal_error";
return failure_indicator;
}
original_rule->is_used= 0;
original_rule_id= original_rule->t_id;
rule_callback(g,original_rule_id);

/*:226*/
#line 1641 "./marpa.w"

/*227:*/
#line 1673 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g_context_clear(g);
g_context_int_add(g,"symid",separator_id);
g->error= "bad separator";
return failure_indicator;
}

/*:227*/
#line 1642 "./marpa.w"

/*228:*/
#line 1681 "./marpa.w"

SYM_by_ID(g,rhs_id)->is_counted= 1;
if(separator_id>=0){SYM_by_ID(g,separator_id)->is_counted= 1;}
/*:228*/
#line 1643 "./marpa.w"

if(min==0){/*229:*/
#line 1684 "./marpa.w"

{RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1041:*/
#line 9372 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1041*/
#line 1686 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->t_id);
}
/*:229*/
#line 1644 "./marpa.w"
}
min= 1;
/*230:*/
#line 1691 "./marpa.w"

internal_lhs_id= symbol_new(g)->t_id;
symbol_callback(g,internal_lhs_id);
/*:230*/
#line 1646 "./marpa.w"

/*231:*/
#line 1705 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:231*/
#line 1647 "./marpa.w"

/*233:*/
#line 1708 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1041:*/
#line 9372 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1041*/
#line 1712 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->t_id);
}
/*:233*/
#line 1648 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*234:*/
#line 1721 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1041:*/
#line 9372 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1041*/
#line 1726 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->t_id);
}
/*:234*/
#line 1650 "./marpa.w"

}
/*235:*/
#line 1738 "./marpa.w"

{RULE rule;
guint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1041:*/
#line 9372 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1041*/
#line 1748 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->t_id);
}
/*:235*/
#line 1652 "./marpa.w"

/*236:*/
#line 1753 "./marpa.w"

{RULE rule;
guint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1041:*/
#line 9372 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1041*/
#line 1760 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->t_id);
}

/*:236*/
#line 1653 "./marpa.w"

/*232:*/
#line 1707 "./marpa.w"
g_free(temp_rhs);
/*:232*/
#line 1654 "./marpa.w"

return original_rule_id;
}
/*:224*//*237:*/
#line 1809 "./marpa.w"

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
/*:237*//*249:*/
#line 1974 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule){
return rule->symbols[0];}
/*:249*//*251:*/
#line 1979 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 1981 "./marpa.w"

/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 1982 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:251*//*253:*/
#line 1986 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule){
return rule->symbols+1;}
/*:253*//*255:*/
#line 1991 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix){
RULE rule;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 1994 "./marpa.w"

/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 1995 "./marpa.w"

rule= rule_id2p(g,rule_id);
if(rule->length<=ix)return-1;
return rhs_symid(rule,ix);
}
/*:255*//*257:*/
#line 2002 "./marpa.w"

static inline gsize rule_length_get(RULE rule){
return rule->length;}
/*:257*//*259:*/
#line 2007 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 2009 "./marpa.w"

/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 2010 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:259*//*263:*/
#line 2019 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symid(RULE rule,guint rh_index){
return rule->symbols[rh_index+1];
}
/*:263*//*270:*/
#line 2046 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:270*//*274:*/
#line 2079 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_PRD(rule);
return SYM_by_ID(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 2086 "./marpa.w"

RULE rule;
/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 2088 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:274*//*278:*/
#line 2099 "./marpa.w"

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
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 2110 "./marpa.w"

RULE rule;
/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 2112 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:278*//*284:*/
#line 2132 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 2135 "./marpa.w"

/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 2136 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:284*//*289:*/
#line 2153 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 2156 "./marpa.w"

/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 2157 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:289*//*292:*/
#line 2165 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,RULE rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symid(rule,rh_ix);
if(!SYM_by_ID(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:292*//*296:*/
#line 2183 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 2186 "./marpa.w"

/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 2187 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:296*//*300:*/
#line 2199 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 2202 "./marpa.w"

/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 2203 "./marpa.w"

return rule_id2p(g,rule_id)->t_is_start;}
/*:300*//*304:*/
#line 2228 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:304*//*308:*/
#line 2239 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:308*//*312:*/
#line 2251 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 2254 "./marpa.w"

/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 2255 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_start;
}
/*:312*//*316:*/
#line 2267 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 2270 "./marpa.w"

/*1037:*/
#line 9344 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return failure_indicator;
}
/*:1037*/
#line 2271 "./marpa.w"

return rule_id2p(g,rule_id)->virtual_end;
}
/*:316*//*322:*/
#line 2293 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:322*//*324:*/
#line 2298 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:324*//*326:*/
#line 2303 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:326*//*328:*/
#line 2311 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:328*//*333:*/
#line 2324 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}
/*:333*//*338:*/
#line 2338 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}
/*:338*//*342:*/
#line 2357 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
RULE rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:342*//*344:*/
#line 2376 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
if(!census(g))return NULL;
if(!CHAF_rewrite(g))return NULL;
if(!g_augment(g))return NULL;
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*564:*/
#line 4937 "./marpa.w"
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

/*:564*/
#line 2385 "./marpa.w"

return g;
}
/*:344*//*347:*/
#line 2423 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*1033:*/
#line 9323 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1033*/
#line 2426 "./marpa.w"

/*349:*/
#line 2456 "./marpa.w"

guint pre_rewrite_rule_count= g->rules->len;
guint pre_rewrite_symbol_count= g->symbols->len;

/*:349*//*354:*/
#line 2493 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->start_symid;
struct symbol*original_start_symbol;

/*:354*//*358:*/
#line 2532 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:358*//*364:*/
#line 2591 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:364*//*366:*/
#line 2618 "./marpa.w"

Bit_Vector nullable_v;
/*:366*//*370:*/
#line 2644 "./marpa.w"

Bit_Vector productive_v;
/*:370*//*373:*/
#line 2685 "./marpa.w"
Bit_Matrix reach_matrix;
/*:373*//*376:*/
#line 2703 "./marpa.w"

Bit_Vector accessible_v;

/*:376*/
#line 2427 "./marpa.w"

/*350:*/
#line 2460 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:350*/
#line 2428 "./marpa.w"

/*351:*/
#line 2467 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:351*/
#line 2429 "./marpa.w"

/*353:*/
#line 2473 "./marpa.w"

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

/*:353*/
#line 2430 "./marpa.w"

/*355:*/
#line 2497 "./marpa.w"

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
/*:355*/
#line 2431 "./marpa.w"

/*356:*/
#line 2516 "./marpa.w"

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
/*:356*/
#line 2432 "./marpa.w"

if(have_marked_terminals){
/*360:*/
#line 2547 "./marpa.w"

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

/*:360*/
#line 2434 "./marpa.w"

}else{
/*359:*/
#line 2536 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:359*/
#line 2436 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*361:*/
#line 2571 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->symbols->len;symid++)
{LV_SYMID_is_Terminal(g,symid)= 1;}}
/*:361*/
#line 2438 "./marpa.w"

}else{
/*362:*/
#line 2576 "./marpa.w"

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
/*:362*/
#line 2440 "./marpa.w"

}
}
/*365:*/
#line 2596 "./marpa.w"

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
/*:365*/
#line 2443 "./marpa.w"

/*368:*/
#line 2623 "./marpa.w"

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
/*:368*/
#line 2444 "./marpa.w"

/*369:*/
#line 2637 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->start_symid))
{
g_context_int_add(g,"symid",g->start_symid);
g->error= "unproductive start symbol";
return NULL;
}
/*:369*/
#line 2445 "./marpa.w"

/*372:*/
#line 2667 "./marpa.w"

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
/*:372*/
#line 2446 "./marpa.w"

/*375:*/
#line 2689 "./marpa.w"

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
/*:375*/
#line 2447 "./marpa.w"

/*377:*/
#line 2708 "./marpa.w"

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

/*:377*/
#line 2448 "./marpa.w"

/*357:*/
#line 2528 "./marpa.w"

bv_free(terminal_v);
/*:357*//*363:*/
#line 2588 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:363*//*367:*/
#line 2620 "./marpa.w"

bv_free(nullable_v);

/*:367*//*371:*/
#line 2646 "./marpa.w"

bv_free(productive_v);

/*:371*/
#line 2449 "./marpa.w"

/*374:*/
#line 2686 "./marpa.w"

matrix_free(reach_matrix);

/*:374*/
#line 2450 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:347*//*384:*/
#line 2784 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*386:*/
#line 2807 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:386*//*390:*/
#line 2858 "./marpa.w"

guint factor_count;
guint*factor_positions;
/*:390*//*395:*/
#line 2907 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:395*/
#line 2787 "./marpa.w"

/*391:*/
#line 2861 "./marpa.w"

factor_positions= g_new(guint,g->max_rule_length);
/*:391*//*396:*/
#line 2910 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:396*/
#line 2788 "./marpa.w"

/*388:*/
#line 2819 "./marpa.w"

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

/*:388*/
#line 2789 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= rule_id2p(g,rule_id);
guint rule_length= rule->length;
guint nullable_suffix_ix= 0;
/*387:*/
#line 2811 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:387*/
#line 2795 "./marpa.w"

/*389:*/
#line 2842 "./marpa.w"

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
/*:389*/
#line 2796 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*393:*/
#line 2867 "./marpa.w"

rule->is_used= 0;
{guint unprocessed_factor_count;

guint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_PRD(rule);
guint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*399:*/
#line 2920 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symid;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*394:*/
#line 2886 "./marpa.w"
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

/*:394*/
#line 2928 "./marpa.w"

/*400:*/
#line 2947 "./marpa.w"

{
guint remaining_rhs_length,piece_rhs_length;
/*401:*/
#line 2959 "./marpa.w"

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
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 2971 "./marpa.w"

}

/*:401*/
#line 2950 "./marpa.w"
;
/*402:*/
#line 2974 "./marpa.w"

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
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 2986 "./marpa.w"

}

/*:402*/
#line 2951 "./marpa.w"
;
/*403:*/
#line 2991 "./marpa.w"
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
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3001 "./marpa.w"

}

/*:403*/
#line 2952 "./marpa.w"
;
/*404:*/
#line 3010 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3015 "./marpa.w"

}

/*:404*/
#line 2953 "./marpa.w"
;
}

/*:400*/
#line 2929 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*394:*/
#line 2886 "./marpa.w"
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

/*:394*/
#line 2934 "./marpa.w"

/*406:*/
#line 3020 "./marpa.w"
{
guint piece_rhs_length;
RULE chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:406*//*407:*/
#line 3029 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3035 "./marpa.w"


/*:407*//*408:*/
#line 3038 "./marpa.w"

second_factor_proper_id= rhs_symid(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3043 "./marpa.w"


/*:408*//*409:*/
#line 3046 "./marpa.w"

first_factor_proper_id= rhs_symid(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3052 "./marpa.w"


/*:409*//*410:*/
#line 3055 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3058 "./marpa.w"


/*:410*//*411:*/
#line 3061 "./marpa.w"
}

/*:411*/
#line 2935 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:399*/
#line 2878 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*412:*/
#line 3065 "./marpa.w"
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

/*:412*//*413:*/
#line 3079 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3084 "./marpa.w"


/*:413*//*414:*/
#line 3087 "./marpa.w"

second_factor_proper_id= rhs_symid(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3092 "./marpa.w"


/*:414*//*415:*/
#line 3095 "./marpa.w"

first_factor_proper_id= rhs_symid(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3101 "./marpa.w"


/*:415*//*416:*/
#line 3105 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3109 "./marpa.w"

}

/*:416*//*417:*/
#line 3113 "./marpa.w"
}

/*:417*/
#line 2881 "./marpa.w"

}else{
/*418:*/
#line 3116 "./marpa.w"
{
guint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
guint real_symbol_count;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:418*//*419:*/
#line 3127 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3132 "./marpa.w"


/*:419*//*420:*/
#line 3136 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symid(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*422:*/
#line 3152 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:422*/
#line 3142 "./marpa.w"

}

/*:420*//*421:*/
#line 3146 "./marpa.w"
}

/*:421*/
#line 2883 "./marpa.w"

}}

/*:393*/
#line 2799 "./marpa.w"

NEXT_RULE:;
}
/*392:*/
#line 2863 "./marpa.w"

g_free(factor_positions);

/*:392*//*397:*/
#line 2913 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:397*/
#line 2802 "./marpa.w"

return g;
}
/*:384*//*423:*/
#line 3166 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct symbol*alias= symbol_null_alias(SYM_by_ID(g,proper_id));
return alias->t_id;
}
/*:423*//*426:*/
#line 3180 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct symbol*proper_old_start= NULL;
struct symbol*nulling_old_start= NULL;
struct symbol*proper_new_start= NULL;
struct symbol*old_start= SYM_by_ID(g,g->start_symid);
/*428:*/
#line 3196 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:428*/
#line 3188 "./marpa.w"

if(proper_old_start){/*429:*/
#line 3206 "./marpa.w"
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

/*:429*/
#line 3189 "./marpa.w"
}
if(nulling_old_start){/*430:*/
#line 3230 "./marpa.w"
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

/*:430*/
#line 3190 "./marpa.w"
}
return g;
}
/*:426*//*434:*/
#line 3304 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{guint no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*436:*/
#line 3327 "./marpa.w"
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

/*:436*/
#line 3311 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*437:*/
#line 3366 "./marpa.w"
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

/*:437*/
#line 3313 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*438:*/
#line 3387 "./marpa.w"

g_context_clear(g);
g_context_int_add(g,"loop_rule_count",loop_rule_count);
grammar_message(g,"loop rule tally");

/*:438*/
#line 3315 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:434*//*453:*/
#line 3552 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 3554 "./marpa.w"

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 3555 "./marpa.w"

return g->no_of_items;
}
/*:453*//*455:*/
#line 3561 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 3564 "./marpa.w"

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 3565 "./marpa.w"

/*1038:*/
#line 9351 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:1038*/
#line 3566 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(g,item_id))->t_id;
}
/*:455*//*457:*/
#line 3572 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 3575 "./marpa.w"

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 3576 "./marpa.w"

/*1038:*/
#line 9351 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:1038*/
#line 3577 "./marpa.w"

return Position_of_AIM(AIM_by_ID(g,item_id));
}
/*:457*//*459:*/
#line 3583 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 3586 "./marpa.w"

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 3587 "./marpa.w"

/*1038:*/
#line 9351 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:1038*/
#line 3588 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(g,item_id));
}
/*:459*//*461:*/
#line 3593 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 3596 "./marpa.w"

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 3597 "./marpa.w"

/*1038:*/
#line 9351 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->error= "invalid item id";
return failure_indicator;
}
/*:1038*/
#line 3598 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(g,item_id));
}
/*:461*//*463:*/
#line 3605 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<(Marpa_AHFA_Item_ID)g->no_of_items&&item_id>=0;
}
/*:463*//*465:*/
#line 3620 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
Marpa_Rule_ID rule_id;
guint no_of_items;
guint no_of_rules= rule_count(g);
AIM base_item= g_new(struct s_AHFA_item,Size_of_G(g));
AIM current_item= base_item;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
/*467:*/
#line 3640 "./marpa.w"

guint rhs_ix;
RULE rule= rule_id2p(g,rule_id);
if(!rule->is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->length;rhs_ix++){
/*468:*/
#line 3652 "./marpa.w"

Marpa_Symbol_ID rh_symid= rhs_symid(rule,rhs_ix);
struct symbol*symbol= SYM_by_ID(g,rh_symid);
if(symbol->is_nullable)goto NEXT_RH_SYMBOL;
LV_Sort_Key_of_AIM(current_item)= current_item-base_item;
LV_Postdot_SYMID_of_AIM(current_item)= rh_symid;
LV_RULE_of_AIM(current_item)= rule;
LV_Position_of_AIM(current_item)= rhs_ix;

/*:468*/
#line 3645 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*469:*/
#line 3661 "./marpa.w"

LV_Sort_Key_of_AIM(current_item)= current_item-base_item;
LV_Postdot_SYMID_of_AIM(current_item)= -1;
LV_Position_of_AIM(current_item)= -1;
LV_RULE_of_AIM(current_item)= rule;

/*:469*/
#line 3649 "./marpa.w"

current_item++;

/*:467*/
#line 3629 "./marpa.w"

NEXT_RULE:;
}
no_of_items= g->no_of_items= current_item-base_item;
g->AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*470:*/
#line 3672 "./marpa.w"
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

/*:470*/
#line 3634 "./marpa.w"

/*474:*/
#line 3709 "./marpa.w"
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

/*:474*/
#line 3635 "./marpa.w"

}
/*:465*//*472:*/
#line 3693 "./marpa.w"

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
/*:472*//*492:*/
#line 3878 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id){
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}
/*:492*//*495:*/
#line 3893 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const AHFA state,guint item_ix){
return state->t_items[item_ix]-g->AHFA_items;
}
/*:495*//*499:*/
#line 3911 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return AHFA_Count_of_G(g);
}
/*:499*//*501:*/
#line 3918 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 3921 "./marpa.w"

AHFA state;
/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 3923 "./marpa.w"

/*1039:*/
#line 9358 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1039*/
#line 3924 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
return state->t_item_count;
}
/*:501*//*503:*/
#line 3931 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
guint item_ix){
AHFA state;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 3936 "./marpa.w"

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 3937 "./marpa.w"

/*1039:*/
#line 9358 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1039*/
#line 3938 "./marpa.w"

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
/*:503*//*511:*/
#line 3988 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 3993 "./marpa.w"

AHFA from_ahfa_state;
AHFA*to_ahfa_array;
SYMID symid;
gint symbol_count;

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 3999 "./marpa.w"

/*1039:*/
#line 9358 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1039*/
#line 4000 "./marpa.w"

/*1040:*/
#line 9365 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
g_context_clear(g);
g_context_int_add(g,"expected size",sizeof(gint));
g->error= "garray size mismatch";
return failure_indicator;
}
/*:1040*/
#line 4001 "./marpa.w"

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

/*:511*//*513:*/
#line 4022 "./marpa.w"

AHFAID marpa_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 4027 "./marpa.w"

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 4028 "./marpa.w"

/*1039:*/
#line 9358 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1039*/
#line 4029 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}
/*:513*//*515:*/
#line 4040 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 4044 "./marpa.w"

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 4045 "./marpa.w"

/*1039:*/
#line 9358 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1039*/
#line 4046 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
return state->t_is_predict;
}
/*:515*//*519:*/
#line 4080 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
const gint no_completed_start_rule= -1;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 4084 "./marpa.w"

AHFA state;
/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 4086 "./marpa.w"

/*1039:*/
#line 9358 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1039*/
#line 4087 "./marpa.w"

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
/*1041:*/
#line 9372 "./marpa.w"
{
g_context_clear(g);
g->error= "internal error";
return failure_indicator;
}

/*:1041*/
#line 4103 "./marpa.w"

}
return no_completed_start_rule;
}

/*:519*//*523:*/
#line 4122 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 4125 "./marpa.w"

AHFA state;
/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 4127 "./marpa.w"

/*1039:*/
#line 9358 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->error= "invalid AHFA state id";
return failure_indicator;
}
/*:1039*/
#line 4128 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:523*//*526:*/
#line 4151 "./marpa.w"

static gint AHFA_state_cmp(
gconstpointer ap,
gconstpointer bp)
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

/*:526*//*527:*/
#line 4175 "./marpa.w"

static
void create_AHFA_states(struct marpa_g*g){
AHFA p_working_state;
const guint initial_no_of_states= 2*Size_of_G(g);
AIM AHFA_item_0_p= g->AHFA_items;
guint no_of_symbols= SYM_Count_of_G(g);
guint no_of_rules= rule_count(g);
Bit_Matrix prediction_matrix;
RULE*rule_by_sort_key= g_new(RULE,no_of_rules);
GTree*duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
/*530:*/
#line 4237 "./marpa.w"
{guint item_id;
guint no_of_items_in_grammar= g->no_of_items;
duplicates= g_tree_new(AHFA_state_cmp);
singleton_duplicates= g_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++){
singleton_duplicates[item_id]= NULL;
}}
/*:530*/
#line 4188 "./marpa.w"

DQUEUE_INIT(states,AHFAD,initial_no_of_states);
/*547:*/
#line 4647 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= matrix_create(no_of_symbols,no_of_symbols);
/*548:*/
#line 4655 "./marpa.w"

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

/*:548*/
#line 4649 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*549:*/
#line 4687 "./marpa.w"
{
AIM*items_by_rule= g->AHFA_items_by_rule;
Marpa_Symbol_ID from_symid;
guint*sort_key_by_rule_id= g_new(guint,no_of_rules);
guint no_of_predictable_rules= 0;
/*550:*/
#line 4717 "./marpa.w"

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

/*:550*/
#line 4693 "./marpa.w"

/*551:*/
#line 4737 "./marpa.w"

{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
rule_by_sort_key[rule_id]= rule_id2p(g,rule_id);
}
g_qsort_with_data(rule_by_sort_key,(gint)no_of_rules,
sizeof(RULE),cmp_by_rule_sort_key,
(gpointer)sort_key_by_rule_id);
}

/*:551*/
#line 4694 "./marpa.w"

/*554:*/
#line 4767 "./marpa.w"
{
guint sort_key;
for(sort_key= 0;sort_key<no_of_rules;sort_key++){
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}}

/*:554*/
#line 4695 "./marpa.w"

/*555:*/
#line 4774 "./marpa.w"

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

/*:555*/
#line 4696 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:549*/
#line 4651 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:547*/
#line 4190 "./marpa.w"

/*532:*/
#line 4248 "./marpa.w"
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

/*:532*/
#line 4191 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFAD))){
/*529:*/
#line 4205 "./marpa.w"
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
/*534:*/
#line 4346 "./marpa.w"
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
/*536:*/
#line 4436 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(g,predot_symid))
> 0)
{
LV_Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:536*/
#line 4404 "./marpa.w"

}
}

/*:534*/
#line 4225 "./marpa.w"

}else{
/*537:*/
#line 4461 "./marpa.w"
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
/*538:*/
#line 4512 "./marpa.w"

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

/*:538*/
#line 4506 "./marpa.w"

AHFA_transition_add(p_working_state,working_symbol,p_new_state);
/*542:*/
#line 4591 "./marpa.w"
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

/*:542*/
#line 4509 "./marpa.w"

}

/*:537*/
#line 4227 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:529*/
#line 4193 "./marpa.w"

}
g->t_AHFA= DQUEUE_BASE(states,AHFAD);

LV_AHFA_Count_of_G(g)= DQUEUE_END(states);
g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*531:*/
#line 4244 "./marpa.w"

g_free(singleton_duplicates);
g_tree_destroy(duplicates);

/*:531*/
#line 4200 "./marpa.w"

}
/*:527*//*541:*/
#line 4580 "./marpa.w"

static inline AHFA
assign_AHFA_state(AHFA sought_state,GTree*duplicates)
{
const AHFA state_found= g_tree_lookup(duplicates,sought_state);
if(state_found)return state_found;
g_tree_insert(duplicates,sought_state,sought_state);
return NULL;
}

/*:541*//*552:*/
#line 4747 "./marpa.w"
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
/*:552*//*557:*/
#line 4823 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
struct dqueue*states_p,
GTree*duplicates
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
/*558:*/
#line 4878 "./marpa.w"

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

/*:558*/
#line 4874 "./marpa.w"

return p_new_state;
}

/*:557*//*561:*/
#line 4917 "./marpa.w"
static inline
AHFA*to_ahfa_array_new(struct marpa_g*g){
gint symbol_count= SYM_Count_of_G(g);
gint symid= 0;
AHFA*new_to_ahfa_array= g_malloc(symbol_count*sizeof(AHFA));
while(symid<symbol_count)new_to_ahfa_array[symid++]= NULL;


return new_to_ahfa_array;
}

/*:561*//*562:*/
#line 4928 "./marpa.w"
static inline
void AHFA_transition_add(AHFA from_ahfa,SYMID symid,AHFA to_ahfa)
{
from_ahfa->t_to_ahfa_ary[symid]= to_ahfa;
}
/*:562*//*568:*/
#line 4962 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g)
{struct marpa_r*r;
/*1033:*/
#line 9323 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1033*/
#line 4965 "./marpa.w"

/*1035:*/
#line 9331 "./marpa.w"

if(!g->is_precomputed){
g_context_clear(g);
g->error= "grammar not precomputed";
return failure_indicator;
}
/*:1035*/
#line 4966 "./marpa.w"

r= g_slice_new(struct marpa_r);
r->t_grammar= g;
/*650:*/
#line 5410 "./marpa.w"
obstack_init(&r->obs);
/*:650*/
#line 4969 "./marpa.w"

/*576:*/
#line 5002 "./marpa.w"

r->t_id= g_atomic_int_exchange_and_add(&next_recce_id,1);
/*:576*//*583:*/
#line 5027 "./marpa.w"

r->t_phase= initial_phase;
/*:583*//*587:*/
#line 5041 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_current_earley_set= NULL;
/*:587*//*593:*/
#line 5070 "./marpa.w"

r->earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,g->no_of_items*2);
/*:593*//*599:*/
#line 5098 "./marpa.w"
r->t_furthest_earleme= 0;
/*:599*//*604:*/
#line 5124 "./marpa.w"
r->t_sym_workarea= NULL;
/*:604*//*607:*/
#line 5138 "./marpa.w"
r->t_workarea2= NULL;
/*:607*//*610:*/
#line 5161 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:610*//*614:*/
#line 5184 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:614*//*621:*/
#line 5237 "./marpa.w"

r->t_is_tracing= FALSE;
r->t_earley_sets= g_tree_new(earley_set_cmp);
r->t_earley_items= g_tree_new(trace_earley_item_cmp);

/*:621*//*631:*/
#line 5302 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:631*//*637:*/
#line 5341 "./marpa.w"

r->t_is_leo_expanding= 0;

/*:637*//*639:*/
#line 5355 "./marpa.w"

r->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:639*//*654:*/
#line 5426 "./marpa.w"

r->t_error= NULL;
r->t_fatal_error= NULL;
/*:654*//*684:*/
#line 5658 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:684*//*719:*/
#line 5968 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:719*//*754:*/
#line 6382 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:754*//*797:*/
#line 6877 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:797*//*862:*/
#line 7604 "./marpa.w"
DSTACK_ZERO_INIT(r->completion_stack);
/*:862*//*1068:*/
#line 9582 "./marpa.w"

r->message_callback_arg= NULL;
r->message_callback= NULL;
/*:1068*/
#line 4970 "./marpa.w"

return r;}
/*:568*//*570:*/
#line 4975 "./marpa.w"

void marpa_r_free(struct marpa_r*r)
{
/*588:*/
#line 5044 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
earley_set_free(set);
}
if(r->t_earley_sets)
g_tree_destroy(r->t_earley_sets);
if(r->t_earley_items)
g_tree_destroy(r->t_earley_items);
}

/*:588*//*640:*/
#line 5357 "./marpa.w"
g_hash_table_destroy(r->context);

/*:640*//*864:*/
#line 7612 "./marpa.w"
DSTACK_DESTROY(r->completion_stack);
/*:864*/
#line 4978 "./marpa.w"

if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*612:*/
#line 5170 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:612*//*616:*/
#line 5187 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:616*/
#line 4981 "./marpa.w"

/*651:*/
#line 5411 "./marpa.w"
obstack_free(&r->obs,NULL);

/*:651*/
#line 4982 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:570*//*577:*/
#line 5004 "./marpa.w"

gint marpa_r_id(struct marpa_r*r){return r->t_id;}
/*:577*//*585:*/
#line 5031 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r)
{return r->t_phase;}

/*:585*//*591:*/
#line 5063 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r)
{return Current_Earleme(r);}

/*:591*//*595:*/
#line 5074 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r)
{return r->earley_item_warning_threshold;}

/*:595*//*597:*/
#line 5082 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold)
{
r->earley_item_warning_threshold= threshold==0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:597*//*601:*/
#line 5101 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme(r);}

/*:601*//*618:*/
#line 5199 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 5202 "./marpa.w"

guint min,max,start;
/*1048:*/
#line 9418 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
r_context_clear(r);
r_context_int_add(r,"expected size",sizeof(gint));
R_ERROR_CXT("garray size mismatch");
return failure_indicator;
}
/*:1048*/
#line 5204 "./marpa.w"

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

/*:618*//*633:*/
#line 5310 "./marpa.w"

gint marpa_is_use_leo(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 5313 "./marpa.w"

/*1046:*/
#line 9406 "./marpa.w"

if(r->t_phase==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1046*/
#line 5314 "./marpa.w"

return r->t_use_leo_flag?1:0;
}
/*:633*//*634:*/
#line 5319 "./marpa.w"

gboolean marpa_is_use_leo_set(
struct marpa_r*r,gboolean value)
{
/*1032:*/
#line 9321 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1032*/
#line 5323 "./marpa.w"

/*1046:*/
#line 9406 "./marpa.w"

if(r->t_phase==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1046*/
#line 5324 "./marpa.w"

r->t_use_leo_flag= value;
return TRUE;
}
/*:634*//*641:*/
#line 5366 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(r->context,(gpointer)key,value);
}
/*:641*//*643:*/
#line 5378 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(r->context,(gpointer)key,value);
}
/*:643*//*645:*/
#line 5393 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r){
g_hash_table_remove_all(r->context);}
/*:645*//*647:*/
#line 5399 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key)
{return g_hash_table_lookup(r->context,key);}
/*:647*//*656:*/
#line 5435 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r)
{return r->t_error?r->t_error:"unknown error";}
/*:656*//*668:*/
#line 5499 "./marpa.w"

static inline ES
earley_set_new(RECCE r,Marpa_Earleme id)
{
ESK_Object key;
ES set;
set= obstack_alloc(&r->obs,sizeof(*set));
key.t_id= id;
set->t_key= key;
set->t_eims= g_sequence_new(NULL);
set->t_earley_items= NULL;
set->t_postdot_ary= NULL;
set->t_postdot_sym_count= 0;
set->t_eim_count= 0;
LV_Next_ES_of_ES(set)= NULL;
if(r->t_is_tracing){
g_tree_insert(r->t_earley_sets,set,set);
}
return set;
}

/*:668*//*673:*/
#line 5560 "./marpa.w"

static inline ES later_earley_set_assign(RECCE r,Marpa_Earleme sought_earleme)
{
ES new_earley_set;
ES last_found_earley_set= Current_ES_of_R(r);
ES found_earley_set= Next_ES_of_ES(last_found_earley_set);
for(;;){
Marpa_Earleme found_earleme;
if(!found_earley_set){
LV_Furthest_Earleme(r)= sought_earleme;
break;
}
found_earleme= Earleme_of_ES(found_earley_set);
G_DEBUG3("later_earley_set_assign, sought=%d, found=%d",sought_earleme,found_earleme);
if(sought_earleme==found_earleme)return found_earley_set;
if(sought_earleme<found_earleme)break;
last_found_earley_set= found_earley_set;
found_earley_set= Next_ES_of_ES(last_found_earley_set);
}
new_earley_set= earley_set_new(r,sought_earleme);
LV_Next_ES_of_ES(last_found_earley_set)= new_earley_set;
LV_Next_ES_of_ES(new_earley_set)= found_earley_set;
return new_earley_set;
}

/*:673*//*674:*/
#line 5586 "./marpa.w"

static inline void
earley_set_free(ES set)
{
GSequence*sequence= set->t_eims;
if(sequence)
g_sequence_free(sequence);
}
/*:674*//*676:*/
#line 5598 "./marpa.w"

static gint
earley_set_cmp(gconstpointer ap,gconstpointer bp)
{
const struct s_earley_set_key*set_key_a= ap;
const struct s_earley_set_key*set_key_b= bp;
return set_key_a->t_id-set_key_b->t_id;
}
/*:676*//*680:*/
#line 5618 "./marpa.w"

static inline ES
earley_set_by_id(RECCE r,Marpa_Earleme earleme)
{
ESK_Object key;
if(!r->t_is_tracing)r_tracing_start(r);
key.t_id= earleme;
return g_tree_lookup(r->t_earley_sets,&key);
}

/*:680*//*682:*/
#line 5632 "./marpa.w"

static void r_tracing_start(RECCE r){
ES set;
GTree*es_tree= r->t_earley_sets;
GTree*eim_tree= r->t_earley_items;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
EIM eim;
g_tree_insert(es_tree,set,set);
for(eim= set->t_earley_items;eim;eim= eim->t_next){
g_tree_insert(eim_tree,eim,eim);
}
}
r->t_is_tracing= 1;
}

/*:682*//*687:*/
#line 5676 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earleme id)
{
ES set;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 5681 "./marpa.w"

/*1043:*/
#line 9386 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1043*/
#line 5682 "./marpa.w"

trace_earley_item_clear(r);
set= Earley_Set_by_ID(r,id);
if(!set){
/*688:*/
#line 5693 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:688*/
#line 5686 "./marpa.w"

return-1;
}
r->t_trace_earley_set= set;
return Earleme_of_ES(set);
}

/*:687*//*690:*/
#line 5698 "./marpa.w"

Marpa_Earleme marpa_trace_earleme(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 5701 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1043:*/
#line 9386 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1043*/
#line 5703 "./marpa.w"

if(!trace_earley_set){
R_ERROR("no trace es");
return failure_indicator;
}
return ID_of_ES(trace_earley_set);
}

/*:690*//*692:*/
#line 5716 "./marpa.w"

gint marpa_current_earley_set_size(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 5719 "./marpa.w"

/*1043:*/
#line 9386 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1043*/
#line 5720 "./marpa.w"

/*1046:*/
#line 9406 "./marpa.w"

if(r->t_phase==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1046*/
#line 5721 "./marpa.w"

return EIM_Count_of_ES(Current_ES_of_R(r));
}

/*:692*//*701:*/
#line 5796 "./marpa.w"

static inline EIM earley_item_new(RECCE r,
EIK_Object key)
{
EIM new_item;
ES set;
new_item= obstack_alloc(&r->obs,sizeof(*new_item));
new_item->t_key= key;
set= ES_of_EIM(new_item);
new_item->t_source_type= NO_SOURCE;
new_item->t_next= set->t_earley_items;
set->t_earley_items= new_item;
LV_EIM_is_Leo_Expanded(new_item)= 1;
if(r->t_is_tracing){
g_tree_insert(r->t_earley_items,new_item,new_item);
}
return new_item;
}

/*:701*//*703:*/
#line 5819 "./marpa.w"

static inline EIM earley_item_assign(RECCE r,ES set,ES origin,AHFA state)
{
/*1033:*/
#line 9323 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1033*/
#line 5822 "./marpa.w"

EIM new_item;
guint count;
GSequenceIter*iter;
gboolean match= FALSE;
EIK_Object key;
key.t_origin= origin;
key.t_state= state;
key.t_set= set;

iter= sequence_find
(set->t_eims,&key,own_earley_item_cmp,&match);
if(match)return(EIM)g_sequence_get(iter);
count= ++set->t_eim_count;
/*704:*/
#line 5844 "./marpa.w"

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

/*:704*/
#line 5836 "./marpa.w"

new_item= earley_item_new(r,key);
g_sequence_insert_before(iter,new_item);
return new_item;
}

/*:703*//*708:*/
#line 5878 "./marpa.w"

static inline gint trace_earley_item_cmp(gconstpointer ap,gconstpointer bp)
{
const EIM_Object*eim_a= ap;
const EIM_Object*eim_b= bp;
gint subkey= Earleme_of_EIM(eim_a)-Earleme_of_EIM(eim_b);
if(subkey)return subkey;
return earley_item_cmp(ap,bp,0);
}
/*:708*//*709:*/
#line 5887 "./marpa.w"

static gint
own_earley_item_cmp(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED)
/*707:*/
#line 5866 "./marpa.w"

{
const struct s_earley_item*eim_a= ap;
const struct s_earley_item*eim_b= bp;
gint subkey= 
AHFAID_of_EIM(eim_a)-
AHFAID_of_EIM(eim_b);
if(subkey)return subkey;
return Origin_ID_of_EIM(eim_a)-Origin_ID_of_EIM(eim_b);
}
/*:707*/
#line 5891 "./marpa.w"

static inline gint earley_item_cmp(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED)
/*707:*/
#line 5866 "./marpa.w"

{
const struct s_earley_item*eim_a= ap;
const struct s_earley_item*eim_b= bp;
gint subkey= 
AHFAID_of_EIM(eim_a)-
AHFAID_of_EIM(eim_b);
if(subkey)return subkey;
return Origin_ID_of_EIM(eim_a)-Origin_ID_of_EIM(eim_b);
}
/*:707*/
#line 5894 "./marpa.w"

/*:709*//*717:*/
#line 5944 "./marpa.w"

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

/*:717*//*722:*/
#line 5990 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,
Marpa_Earleme origin_id,
Marpa_AHFA_State_ID state_id)
{
const gint no_match= -1;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 5997 "./marpa.w"

ES current_set= r->t_trace_earley_set;
ES origin_set;
EIM item;
EIK_Object item_key;
GRAMMARC g= G_of_R(r);
/*1043:*/
#line 9386 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1043*/
#line 6003 "./marpa.w"

trace_source_link_clear(r);
if(!current_set){
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 6006 "./marpa.w"

R_ERROR("no trace es");
return failure_indicator;
}
origin_set= Earley_Set_by_ID(r,origin_id);
if(!origin_set){
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 6012 "./marpa.w"

R_ERROR("origin es not found");
return failure_indicator;
}
item_key.t_state= AHFA_by_ID(state_id);
item_key.t_origin= origin_set;
item_key.t_set= current_set;
item= r->t_trace_earley_item= g_tree_lookup(r->t_earley_items,&item_key);
if(!item){
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 6021 "./marpa.w"

return no_match;
}
return AHFAID_of_EIM(item);
}

/*:722*//*724:*/
#line 6038 "./marpa.w"

Marpa_AHFA_State_ID
marpa_first_earley_item_trace(struct marpa_r*r)
{
ES current_set= r->t_trace_earley_set;
EIM item;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6044 "./marpa.w"

/*1043:*/
#line 9386 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1043*/
#line 6045 "./marpa.w"

trace_source_link_clear(r);
if(!current_set){
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 6048 "./marpa.w"

R_ERROR("no trace earley set");
return failure_indicator;
}
item= r->t_trace_earley_item= current_set->t_earley_items;
if(!item){
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 6054 "./marpa.w"

return-1;
}
return AHFAID_of_EIM(item);
}

/*:724*//*726:*/
#line 6072 "./marpa.w"

AHFAID
marpa_next_earley_item_trace(struct marpa_r*r)
{
EIM item= r->t_trace_earley_item;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6077 "./marpa.w"

/*1043:*/
#line 9386 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1043*/
#line 6078 "./marpa.w"

trace_source_link_clear(r);
if(!item){
R_ERROR("no trace eim");
return failure_indicator;
}
item= item->t_next;
if(!item){
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 6086 "./marpa.w"

return-1;
}
r->t_trace_earley_item= item;
return AHFAID_of_EIM(item);
}

/*:726*//*729:*/
#line 6104 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r)
{
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 6107 "./marpa.w"

trace_source_link_clear(r);
}

/*:729*//*731:*/
#line 6113 "./marpa.w"

Marpa_Earleme marpa_earley_item_origin(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6116 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1043:*/
#line 9386 "./marpa.w"

if(r->t_phase==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1043*/
#line 6118 "./marpa.w"

if(!item){
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 6120 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return Origin_ID_of_EIM(item);
}

/*:731*//*737:*/
#line 6200 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6204 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6207 "./marpa.w"

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
/*:737*//*738:*/
#line 6222 "./marpa.w"

Marpa_Earleme marpa_leo_base_origin(struct marpa_r*r)
{
const Marpa_Earleme pim_is_not_a_leo_item= -1;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6226 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6229 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_ID_of_EIM(base_earley_item);
}

/*:738*//*740:*/
#line 6241 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r)
{
const Marpa_Earleme pim_is_not_a_leo_item= -1;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6245 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6248 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:740*//*745:*/
#line 6284 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r)
{
const Marpa_Earleme pim_is_not_a_leo_item= -1;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6288 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6290 "./marpa.w"

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


/*:745*//*750:*/
#line 6344 "./marpa.w"

static inline PIM*
pim_sym_p_find(ES set,SYMID symid)
{
gint lo= 0;
gint hi= Postdot_SYM_Count_of_ES(set)-1;
PIM*postdot_array= set->t_postdot_ary;
while(hi>=lo){
gint trial= lo+(hi-lo)/2;
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
/*:750*//*752:*/
#line 6366 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:752*//*756:*/
#line 6400 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6405 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*757:*/
#line 6424 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:757*/
#line 6409 "./marpa.w"

/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6410 "./marpa.w"

/*1047:*/
#line 9411 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
r_context_clear(r);
r_context_int_add(r,"symid",symid);
R_ERROR_CXT("invalid symid");
return failure_indicator;
}
/*:1047*/
#line 6411 "./marpa.w"

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

/*:756*//*759:*/
#line 6437 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6441 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*757:*/
#line 6424 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:757*/
#line 6445 "./marpa.w"

/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6446 "./marpa.w"

if(!current_earley_set){
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 6448 "./marpa.w"

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

/*:759*//*761:*/
#line 6470 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6475 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;

pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*757:*/
#line 6424 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:757*/
#line 6482 "./marpa.w"

if(!pim_sym_p||!pim){
R_ERROR("no trace pim");
return failure_indicator;
}
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6487 "./marpa.w"

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

/*:761*//*763:*/
#line 6509 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6512 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6514 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:763*//*779:*/
#line 6646 "./marpa.w"
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
/*:779*//*786:*/
#line 6736 "./marpa.w"
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

/*:786*//*787:*/
#line 6765 "./marpa.w"
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
/*:787*//*790:*/
#line 6820 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*792:*/
#line 6838 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= new_link;
}

/*:792*/
#line 6827 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*793:*/
#line 6847 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= new_link;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:793*/
#line 6829 "./marpa.w"

return;
case SOURCE_IS_LEO:/*794:*/
#line 6856 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:794*/
#line 6831 "./marpa.w"

return;
}
}
/*:790*//*800:*/
#line 6890 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6893 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6897 "./marpa.w"

/*819:*/
#line 7121 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:819*/
#line 6898 "./marpa.w"

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

/*:800*//*804:*/
#line 6935 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6938 "./marpa.w"

SRCL full_link;
EIM item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6941 "./marpa.w"

/*819:*/
#line 7121 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:819*/
#line 6942 "./marpa.w"

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

/*:804*//*807:*/
#line 6967 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 6970 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 6974 "./marpa.w"

/*819:*/
#line 7121 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:819*/
#line 6975 "./marpa.w"

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

/*:807*//*811:*/
#line 7011 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 7014 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 7018 "./marpa.w"

/*819:*/
#line 7121 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:819*/
#line 7019 "./marpa.w"

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

/*:811*//*814:*/
#line 7045 "./marpa.w"

Marpa_Symbol_ID
marpa_first_leo_link_trace(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 7049 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 7053 "./marpa.w"

/*819:*/
#line 7121 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:819*/
#line 7054 "./marpa.w"

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

/*:814*//*818:*/
#line 7092 "./marpa.w"

Marpa_Symbol_ID
marpa_next_leo_link_trace(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 7096 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 7100 "./marpa.w"

/*819:*/
#line 7121 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:819*/
#line 7101 "./marpa.w"

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

/*:818*//*822:*/
#line 7132 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r){
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:822*//*824:*/
#line 7149 "./marpa.w"

AHFAID marpa_source_predecessor_state(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 7152 "./marpa.w"

guint source_type;
SRC source;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 7155 "./marpa.w"

source_type= r->t_trace_source_type;
/*833:*/
#line 7291 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:833*/
#line 7157 "./marpa.w"

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

/*:824*//*827:*/
#line 7186 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 7189 "./marpa.w"

guint source_type;
SRC source;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 7192 "./marpa.w"

source_type= r->t_trace_source_type;
/*833:*/
#line 7291 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:833*/
#line 7194 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_Symbol_ID_of_SRC(source);
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:827*//*830:*/
#line 7233 "./marpa.w"

Marpa_Earleme marpa_source_middle(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 7236 "./marpa.w"

const Marpa_Earleme no_predecessor= -1;
guint source_type;
SRC source;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 7240 "./marpa.w"

source_type= r->t_trace_source_type;
/*833:*/
#line 7291 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:833*/
#line 7242 "./marpa.w"

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

/*:830*//*832:*/
#line 7274 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p)
{
/*1032:*/
#line 9321 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1032*/
#line 7277 "./marpa.w"

guint source_type;
SRC source;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 7280 "./marpa.w"

source_type= r->t_trace_source_type;
/*833:*/
#line 7291 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:833*/
#line 7282 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
*value_p= Token_Value_of_SRC(source);
return TRUE;
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:832*//*834:*/
#line 7299 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
AHFA state;
GRAMMARC g= G_of_R(r);
const gint symbol_count_of_g= SYM_Count_of_G(g);
/*1032:*/
#line 9321 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1032*/
#line 7306 "./marpa.w"

/*1042:*/
#line 9381 "./marpa.w"

if(r->t_phase!=initial_phase){
R_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1042*/
#line 7307 "./marpa.w"

/*608:*/
#line 5139 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*605:*/
#line 5125 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:605*/
#line 5142 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:608*/
#line 7308 "./marpa.w"

/*611:*/
#line 5165 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:611*//*615:*/
#line 5185 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:615*/
#line 7309 "./marpa.w"

set0= earley_set_new(r,0);
LV_Current_ES_of_R(r)= set0;
LV_First_ES_of_R(r)= set0;
state= AHFA_by_ID(0);
item= earley_item_assign(r,set0,set0,state);
state= Empty_Transition_of_AHFA(state);
if(state){
item= earley_item_assign(r,set0,set0,state);
}
r->t_phase= active_phase;
/*863:*/
#line 7609 "./marpa.w"

DSTACK_INIT(r->completion_stack,EIM,
MAX(1024,r->earley_item_warning_threshold));
/*:863*/
#line 7320 "./marpa.w"

postdot_items_create(r,set0);
r->t_is_using_leo= r->t_use_leo_flag;
return TRUE;
}
/*:834*//*843:*/
#line 7385 "./marpa.w"

gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*value,gint length){
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 7388 "./marpa.w"

const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
/*844:*/
#line 7406 "./marpa.w"

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

/*:844*/
#line 7391 "./marpa.w"

/*845:*/
#line 7418 "./marpa.w"

/*1044:*/
#line 9391 "./marpa.w"

if(r->t_phase!=active_phase){
R_ERROR("recce not active");
return failure_indicator;
}
/*:1044*/
#line 7419 "./marpa.w"

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

/*:845*/
#line 7392 "./marpa.w"

/*846:*/
#line 7433 "./marpa.w"

target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
r_context_clear(r);
r_context_int_add(r,"target_earleme",target_earleme);
R_ERROR_CXT("parse too long");
return failure_indicator;
}

/*:846*/
#line 7393 "./marpa.w"

/*847:*/
#line 7449 "./marpa.w"

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
target_earley_set= later_earley_set_assign(r,target_earleme);

/*:847*/
#line 7394 "./marpa.w"

/*848:*/
#line 7465 "./marpa.w"
{
target_AHFA_state
= To_AHFA_of_EIM_by_SYMID(postdot_earley_item,token_id);
target_earley_item= earley_item_assign(r,target_earley_set,
Origin_of_EIM(postdot_earley_item),
target_AHFA_state);
}

/*:848*/
#line 7395 "./marpa.w"

/*860:*/
#line 7576 "./marpa.w"

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

/*:860*/
#line 7396 "./marpa.w"

for(;;){
/*849:*/
#line 7473 "./marpa.w"

token_link_add(r,target_earley_item,postdot_earley_item,
token_id,value);

/*:849*/
#line 7398 "./marpa.w"

/*850:*/
#line 7477 "./marpa.w"
{
AHFA target_AHFA_prediction_state= 
Empty_Transition_of_AHFA(target_AHFA_state);
if(target_AHFA_prediction_state)
{
earley_item_assign(r,target_earley_set,target_earley_set,
target_AHFA_prediction_state);
}
}

/*:850*/
#line 7399 "./marpa.w"

/*851:*/
#line 7487 "./marpa.w"

working_pim= Next_PIM_of_PIM(working_pim);
if(!working_pim){
return current_earleme;
}
postdot_earley_item= EIM_of_PIM(working_pim);


/*:851*/
#line 7400 "./marpa.w"

/*848:*/
#line 7465 "./marpa.w"
{
target_AHFA_state
= To_AHFA_of_EIM_by_SYMID(postdot_earley_item,token_id);
target_earley_item= earley_item_assign(r,target_earley_set,
Origin_of_EIM(postdot_earley_item),
target_AHFA_state);
}

/*:848*/
#line 7401 "./marpa.w"

}
return current_earleme;
}

/*:843*//*867:*/
#line 7632 "./marpa.w"

Marpa_Earleme
marpa_earleme_complete(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 7636 "./marpa.w"

Marpa_Earleme new_current_earleme;
EIM*cause_p;
ES current_earley_set;
gint count_of_expected_terminals;
/*868:*/
#line 7660 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
new_current_earleme
= Earleme_of_ES(current_earley_set)+1;
if(new_current_earleme> Furthest_Earleme(r))
{
r->t_phase= exhausted_phase;
R_ERROR("parse exhausted");
return failure_indicator;
}
current_earley_set= later_earley_set_assign(r,new_current_earleme);
LV_Current_ES_of_R(r)= current_earley_set;
G_DEBUG3("%d: Initialized a new current earley set: %d",
__LINE__,ID_of_ES(current_earley_set));
}

/*:868*/
#line 7641 "./marpa.w"

/*869:*/
#line 7676 "./marpa.w"
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

/*:869*/
#line 7642 "./marpa.w"

while((cause_p= DSTACK_POP(r->completion_stack,EIM))){
EIM cause= *cause_p;
/*870:*/
#line 7698 "./marpa.w"
{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDARY_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++){
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*871:*/
#line 7709 "./marpa.w"

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
/*872:*/
#line 7732 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*873:*/
#line 7748 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->completion_stack,EIM);
*tos= effect;
}

/*:873*/
#line 7741 "./marpa.w"

}
/*874:*/
#line 7753 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:874*/
#line 7743 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:872*/
#line 7720 "./marpa.w"

}
else
{
/*875:*/
#line 7763 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*873:*/
#line 7748 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->completion_stack,EIM);
*tos= effect;
}

/*:873*/
#line 7772 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:875*/
#line 7724 "./marpa.w"

break;


}
}
}

/*:871*/
#line 7705 "./marpa.w"

}
}

/*:870*/
#line 7645 "./marpa.w"

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

/*:867*//*879:*/
#line 7797 "./marpa.w"

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
/*880:*/
#line 7822 "./marpa.w"

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

/*:880*/
#line 7811 "./marpa.w"

if(r->t_is_using_leo){
/*882:*/
#line 7866 "./marpa.w"
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
/*883:*/
#line 7891 "./marpa.w"
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

/*:883*/
#line 7880 "./marpa.w"

}
}
}

/*:882*/
#line 7813 "./marpa.w"

/*892:*/
#line 7975 "./marpa.w"
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

/*895:*/
#line 8034 "./marpa.w"
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

/*:895*/
#line 7993 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*901:*/
#line 8126 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:901*/
#line 7995 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*903:*/
#line 8145 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
}

/*:903*/
#line 8001 "./marpa.w"

continue;
}
/*896:*/
#line 8049 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*899:*/
#line 8070 "./marpa.w"
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

/*895:*/
#line 8034 "./marpa.w"
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

/*:895*/
#line 8096 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:899*/
#line 8052 "./marpa.w"

/*900:*/
#line 8115 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*901:*/
#line 8126 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:901*/
#line 8119 "./marpa.w"

}else{
/*903:*/
#line 8145 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
}

/*:903*/
#line 8121 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:900*/
#line 8053 "./marpa.w"

}

/*:896*/
#line 8004 "./marpa.w"

}
}
}

/*:892*/
#line 7814 "./marpa.w"

}
/*904:*/
#line 8150 "./marpa.w"
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

/*:904*/
#line 7816 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:879*//*908:*/
#line 8206 "./marpa.w"

static gint leo_completion_expand(RECCE r,EIM leo_completion)
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
/*909:*/
#line 8252 "./marpa.w"
{
this_lim= Predecessor_of_SRCL(leo_link);
previous_eim_on_this_path= Cause_of_SRCL(leo_link);
leo_path_lengths+= 2;

}

/*:909*/
#line 8221 "./marpa.w"

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
/*910:*/
#line 8259 "./marpa.w"
{
LIM next_lim;
while((next_lim= Predecessor_LIM_of_LIM(this_lim))){
/*911:*/
#line 8273 "./marpa.w"

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

/*:911*/
#line 8262 "./marpa.w"

this_lim= next_lim;
}
completion_link_add(r,leo_completion,Base_EIM_of_LIM(this_lim),previous_eim_on_this_path);



}

/*:910*/
#line 8238 "./marpa.w"

if(!next_leo_link)break;
{
const SRCL leo_link= next_leo_link;
next_leo_link= Next_SRCL_of_SRCL(leo_link);
/*909:*/
#line 8252 "./marpa.w"
{
this_lim= Predecessor_of_SRCL(leo_link);
previous_eim_on_this_path= Cause_of_SRCL(leo_link);
leo_path_lengths+= 2;

}

/*:909*/
#line 8243 "./marpa.w"

}
}
r->t_is_leo_expanding= 0;


return leo_path_lengths;
}

/*:908*//*915:*/
#line 8305 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r)
{
/*1034:*/
#line 9326 "./marpa.w"
const int failure_indicator= -2;

/*:1034*/
#line 8308 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1045:*/
#line 9396 "./marpa.w"

switch(r->t_phase){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case active_phase:
case exhausted_phase:
case finished_phase:
break;
}
/*:1045*/
#line 8310 "./marpa.w"

if(!item){
/*727:*/
#line 6099 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:727*/
#line 8312 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return leo_completion_expand(r,item);
}

/*:915*//*934:*/
#line 8465 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:934*//*936:*/
#line 8473 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:936*//*938:*/
#line 8489 "./marpa.w"

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
/*:938*//*940:*/
#line 8506 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:940*//*942:*/
#line 8518 "./marpa.w"
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
/*:942*//*944:*/
#line 8538 "./marpa.w"
static inline
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}
/*:944*//*946:*/
#line 8548 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:946*//*948:*/
#line 8557 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:948*//*950:*/
#line 8565 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:950*//*954:*/
#line 8580 "./marpa.w"

static inline void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:954*//*956:*/
#line 8589 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:956*//*958:*/
#line 8597 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:958*//*960:*/
#line 8605 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:960*//*963:*/
#line 8614 "./marpa.w"

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
/*:963*//*965:*/
#line 8631 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:965*//*967:*/
#line 8643 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:967*//*969:*/
#line 8655 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:969*//*971:*/
#line 8667 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:971*//*973:*/
#line 8679 "./marpa.w"

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
/*:973*//*975:*/
#line 8755 "./marpa.w"

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
/*:975*//*981:*/
#line 8809 "./marpa.w"

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
/*:981*//*986:*/
#line 8888 "./marpa.w"

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
/*:986*//*988:*/
#line 8908 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:988*//*990:*/
#line 8921 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:990*//*992:*/
#line 8938 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:992*//*995:*/
#line 8948 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:995*//*998:*/
#line 8957 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:998*//*1001:*/
#line 8966 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:1001*//*1003:*/
#line 8980 "./marpa.w"

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
/*:1003*//*1011:*/
#line 9108 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}
/*:1011*//*1017:*/
#line 9166 "./marpa.w"

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
/*:1017*//*1053:*/
#line 9476 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags){
if(!(flags&CONTEXT_FLAG))r_context_clear(r);
r->t_error= message;
if(flags&FATAL_FLAG)r->t_fatal_error= r->t_error;
r_message(r,message);
}

/*:1053*//*1061:*/
#line 9550 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->message_callback_arg= cb_arg;}
gpointer marpa_g_message_callback_arg(struct marpa_g*g)
{return g->message_callback_arg;}
/*:1061*//*1063:*/
#line 9567 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_G_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:1063*//*1069:*/
#line 9585 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb)
{r->message_callback= cb;}
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg)
{r->message_callback_arg= cb_arg;}
gpointer marpa_r_message_callback_arg(struct marpa_r*r)
{return r->message_callback_arg;}
/*:1069*//*1071:*/
#line 9596 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id)
{Marpa_R_Message_Callback*cb= r->message_callback;
if(cb){(*cb)(r,id);}}
/*:1071*//*1075:*/
#line 9630 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
eim_tag(gchar*buffer,EIM eim)
{
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_EIM(eim),Origin_ID_of_EIM(eim),Earleme_of_EIM(eim));
return buffer;
}
#endif

/*:1075*//*1077:*/
#line 9651 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_SYMID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}
#endif

/*:1077*/
#line 9718 "./marpa.w"


/*:1083*/
