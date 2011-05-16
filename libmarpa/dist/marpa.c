/*1156:*/
#line 10307 "./marpa.w"

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

/*:1156*//*1157:*/
#line 10330 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1147:*/
#line 10236 "./marpa.w"

#define MARPA_DEBUG  0 
#if MARPA_DEBUG
#define MARPA_DEBUG1(a)  g_debug((a)) 
#define MARPA_DEBUG2(a, b)  g_debug((a),(b)) 
#define MARPA_DEBUG3(a, b, c)  g_debug((a),(b),(c)) 
#define MARPA_DEBUG4(a, b, c, d)  g_debug((a),(b),(c),(d)) 
#else 
#define MARPA_DEBUG1(a) 
#define MARPA_DEBUG2(a, b) 
#define MARPA_DEBUG3(a, b, c) 
#define MARPA_DEBUG4(a, b, c, d) 
#endif

/*:1147*/
#line 10333 "./marpa.w"

#define SYM_Count_of_G(g) ((g) ->t_symbols->len)  \

#define SYM_by_ID(g,id) (g_array_index((g) ->t_symbols,SYM,(id) ) )  \

#define RULE_by_ID(g,id) (g_array_index((g) ->t_rules,RULE,(id) ) )  \

#define RULEID_of_G_is_Valid(g,rule_id)  \
((rule_id) >=0&&(guint) (rule_id) <(g) ->t_rules->len)  \

#define Size_of_G(g) ((g) ->t_size) 
#define LV_Size_of_G(g) ((g) ->t_size) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define Context_of_G(g) ((g) ->t_context) 
#define SYMBOL_LHS_RULE_COUNT(symbol) ((symbol) ->t_lhs->len) 
#define SYM_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
#define SYMID_is_Terminal(g,id) (SYM_is_Terminal(SYM_by_ID((g) ,(id) ) ) ) 
#define LV_SYMID_is_Terminal(g,id) SYMID_is_Terminal((g) ,(id) ) 
#define LHS_ID_of_PRD(production) ((production) ->t_symbols[0])  \

#define ID_of_RULE(rule) ((rule) ->t_id) 
#define RULE_is_Start(rule) ((rule) ->t_is_start) 
#define Position_of_AIM(aim) ((aim) ->t_position) 
#define LV_Position_of_AIM(aim) Position_of_AIM(aim) 
#define Sort_Key_of_AIM(aim) ((aim) ->t_sort_key) 
#define LV_Sort_Key_of_AIM(aim) Sort_Key_of_AIM(aim) 
#define AIM_Count_of_G(g) ((g) ->t_aim_count) 
#define LV_AIM_Count_of_G(g) AIM_Count_of_G(g) 
#define AIM_by_ID(g,id) ((g) ->t_AHFA_items+(id) )  \

#define Postdot_SYMID_of_AIM(item) ((item) ->t_postdot) 
#define LV_Postdot_SYMID_of_AIM(item) Postdot_SYMID_of_AIM(item) 
#define AIM_is_Completion(aim) (Postdot_SYMID_of_AIM(aim) <0) 
#define AIM_has_Completed_Start_Rule(aim)  \
(AIM_is_Completion(aim) &&RULE_is_Start(RULE_of_AIM(aim) ) ) 
#define RULE_of_AIM(item) ((item) ->t_production) 
#define RULEID_of_AIM(item) ID_of_RULE(RULE_of_AIM(item) ) 
#define LV_RULE_of_AIM(item) RULE_of_AIM(item) 
#define LHS_ID_of_AIM(item) (LHS_ID_of_PRD(RULE_of_AIM(item) ) )  \

#define AHFA_by_ID(id) (g->t_AHFA+(id) ) 
#define Complete_SYMIDARY_of_AHFA(state) ((state) ->t_complete_symbols) 
#define Complete_SYM_Count_of_AHFA(state) ((state) ->t_complete_symbol_count) 
#define AHFA_has_Completed_Start_Rule(ahfa) ((ahfa) ->t_has_completed_start_rule) 
#define AIM_Count_of_AHFA(ahfa) ((ahfa) ->t_item_count) 
#define LV_AIM_Count_of_AHFA(ahfa) AIM_Count_of_AHFA(ahfa) 
#define AIMs_of_AHFA(ahfa) ((ahfa) ->t_items) 
#define LV_AIMs_of_AHFA(ahfa) AIMs_of_AHFA(ahfa) 
#define AHFA_is_Predicted(ahfa) ((ahfa) ->t_is_predict) 
#define LV_AHFA_is_Predicted(ahfa) AHFA_is_Predicted(ahfa) 
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
#define AHFA_Count_of_R(r) AHFA_Count_of_G(G_of_R(r) ) 
#define Phase_of_R(r) ((r) ->t_phase) 
#define LV_Phase_of_R(r) Phase_of_R(r) 
#define First_ES_of_R(r) ((r) ->t_first_earley_set) 
#define LV_First_ES_of_R(r) First_ES_of_R(r) 
#define Latest_ES_of_R(r) ((r) ->t_latest_earley_set) 
#define LV_Latest_ES_of_R(r) Latest_ES_of_R(r) 
#define Current_Earleme_of_R(r) ((r) ->t_current_earleme) 
#define LV_Current_Earleme_of_R(r) (Current_Earleme_of_R(r) ) 
#define Current_ES_of_R(r) current_es_of_r(r) 
#define DEFAULT_EIM_WARNING_THRESHOLD (100) 
#define Furthest_Earleme_of_R(r) ((r) ->t_furthest_earleme) 
#define LV_Furthest_Earleme_of_R(r) Furthest_Earleme_of_R(r) 
#define R_is_Exhausted(r) ((r) ->t_is_exhausted) 
#define LV_R_is_Exhausted(r) R_is_Exhausted(r) 
#define Context_of_R(r) ((r) ->t_context) 
#define EARLEME_THRESHOLD (G_MAXINT/4) 
#define Next_ES_of_ES(set) ((set) ->t_next_earley_set) 
#define LV_Next_ES_of_ES(set) Next_ES_of_ES(set) 
#define Postdot_SYM_Count_of_ES(set) ((set) ->t_postdot_sym_count) 
#define First_PIM_of_ES_by_SYMID(set,symid) (first_pim_of_es_by_symid((set) ,(symid) ) ) 
#define PIM_SYM_P_of_ES_by_SYMID(set,symid) (pim_sym_p_find((set) ,(symid) ) ) 
#define EIM_Count_of_ES(set) ((set) ->t_eim_count) 
#define LV_EIM_Count_of_ES(set) EIM_Count_of_ES(set) 
#define EIMs_of_ES(set) ((set) ->t_earley_items) 
#define LV_EIMs_of_ES(set) EIMs_of_ES(set) 
#define ES_Count_of_R(r) ((r) ->t_earley_set_count) 
#define Ord_of_ES(set) ((set) ->t_ordinal) 
#define ES_Ord_is_Valid(r,ordinal)  \
((ordinal) >=0&&(ordinal) <ES_Count_of_R(r) ) 
#define Earleme_of_ES(set) ((set) ->t_key.t_earleme)  \

#define EIM_FATAL_THRESHOLD (G_MAXINT/4) 
#define Complete_SYMIDARY_of_EIM(item)  \
Complete_SYMIDARY_of_AHFA(AHFA_of_EIM(item) ) 
#define Complete_SYM_Count_of_EIM(item)  \
Complete_SYM_Count_of_AHFA(AHFA_of_EIM(item) ) 
#define Leo_LHS_ID_of_EIM(eim) Leo_LHS_ID_of_AHFA(AHFA_of_EIM(eim) ) 
#define Earley_Item_is_Completion(item)  \
(Complete_SYM_Count_of_EIM(item) > 0) 
#define ES_of_EIM(item) ((item) ->t_key.t_set) 
#define Ord_of_EIM(item) ((item) ->t_ordinal) 
#define LV_Ord_of_EIM(item) Ord_of_EIM(item) 
#define Earleme_of_EIM(item) Earleme_of_ES(ES_of_EIM(item) ) 
#define AHFAID_of_EIM(item) (ID_of_AHFA(AHFA_of_EIM(item) ) ) 
#define AHFA_of_EIM(item) ((item) ->t_key.t_state) 
#define Origin_Earleme_of_EIM(item) (Earleme_of_ES(Origin_of_EIM(item) ) ) 
#define Origin_of_EIM(item) ((item) ->t_key.t_origin) 
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
#define Chain_Length_of_LIM(leo) ((leo) ->t_chain_length) 
#define LV_Chain_Length_of_LIM(leo) Chain_Length_of_LIM(leo) 
#define Earleme_of_LIM(lim) Earleme_of_ES(ES_of_LIM(lim) ) 
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
#define Symbol_ID_of_Postdot_Item(postdot) ((postdot) ->t_earley.transition_symid)  \

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

#define Token_ID_of_ALT(alt) ((alt) ->t_token_id) 
#define Token_Value_of_ALT(alt) ((alt) ->t_token_value) 
#define Start_ES_of_ALT(alt) ((alt) ->t_start_earley_set) 
#define Start_Earleme_of_ALT(alt) Earleme_of_ES(Start_ES_of_ALT(alt) ) 
#define End_Earleme_of_ALT(alt) ((alt) ->t_end_earleme) 
#define INITIAL_ALTERNATIVES_CAPACITY 1
#define Work_EIMs_of_R(r) DSTACK_BASE((r) ->t_eim_work_stack,EIM) 
#define Work_EIM_Count_of_R(r) DSTACK_LENGTH((r) ->t_eim_work_stack) 
#define WORK_EIMS_CLEAR(r) DSTACK_CLEAR((r) ->t_eim_work_stack) 
#define WORK_EIM_PUSH(r) DSTACK_PUSH((r) ->t_eim_work_stack,EIM) 
#define P_ES_of_R_by_Ord(r,ord) DSTACK_INDEX((r) ->t_earley_set_stack,ES,(ord) ) 
#define ES_of_R_by_Ord(r,ord) (*P_ES_of_R_by_Ord((r) ,(ord) ) ) 
#define LIM_is_Populated(leo) (Origin_of_LIM(leo) !=NULL) 
#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DECLARE(name,type) struct{gint t_count;type*t_base;}name;
#define FSTACK_INIT(name,type,n) ((name.t_count= 0) ,(name.t_base= g_new(type,n) ) ) 
#define FSTACK_PUSH(name) (name.t_base+name.t_count++) 
#define FSTACK_POP(name) (name.t_count<=0?NULL:name.t_base+(--name.t_count) ) 
#define FSTACK_DESTROY(name) (g_free(name.t_base) )  \

#define DSTACK_DECLARE(this) struct s_dstack this
#define DSTACK_INIT(this,type,initial_size)  \
(((this) .t_count= 0) , \
((this) .t_base= g_new(type,((this) .t_capacity= (initial_size) ) ) ) )  \

#define DSTACK_IS_INITIALIZED(this) ((this) .t_base) 
#define DSTACK_ZERO_INIT(this)  \
(((this) .t_count= (this) .t_capacity= 0) ,((this) .t_base= NULL) )  \

#define DSTACK_CLEAR(this) ((this) .t_count= 0) 
#define DSTACK_PUSH(this,type)  \
(((this) .t_count>=(this) .t_capacity?dstack_resize(&(this) ,sizeof(type) ) :0) , \
((type*) (this) .t_base+(this) .t_count++) ) 
#define DSTACK_POP(this,type) ((this) .t_count<=0?NULL: \
((type*) (this) .t_base+(--(this) .t_count) ) ) 
#define DSTACK_INDEX(this,type,ix) (DSTACK_BASE((this) ,type) +(ix) ) 
#define DSTACK_TOP(this,type) (DSTACK_LENGTH(this) <=0 \
?NULL \
:DSTACK_INDEX((this) ,type,DSTACK_LENGTH(this) -1) ) 
#define DSTACK_BASE(this,type) ((type*) (this) .t_base) 
#define DSTACK_LENGTH(this) ((this) .t_count)  \

#define STOLEN_DSTACK_DATA_FREE(data) ((data) &&(g_free(data) ,1) ) 
#define DSTACK_DESTROY(this) STOLEN_DSTACK_DATA_FREE(this.t_base)  \

#define DQUEUE_DECLARE(this) struct s_dqueue this
#define DQUEUE_INIT(this,type,initial_size)  \
((this.t_current= 0) ,DSTACK_INIT(this.t_stack,type,initial_size) ) 
#define DQUEUE_PUSH(this,type) DSTACK_PUSH(this.t_stack,type) 
#define DQUEUE_POP(this,type) DSTACK_POP(this.t_stack,type) 
#define DQUEUE_NEXT(this,type) (this.t_current>=DSTACK_LENGTH(this.t_stack)  \
?NULL \
:(DSTACK_BASE(this.t_stack,type) ) +this.t_current++) 
#define DQUEUE_BASE(this,type) DSTACK_BASE(this.t_stack,type) 
#define DQUEUE_END(this) DSTACK_LENGTH(this.t_stack) 
#define STOLEN_DQUEUE_DATA_FREE(data) STOLEN_DSTACK_DATA_FREE(data)  \

#define Sizeof_PSL(psar)  \
(sizeof(PSL_Object) +(psar->t_psl_length-1) *sizeof(gpointer) ) 
#define PSL_Datum(psl,i) ((psl) ->t_data[(i) ]) 
#define LV_PSL_Datum(psl,i) PSL_Datum((psl) ,(i) ) 
#define Dot_PSAR_of_R(r) (&(r) ->t_dot_psar_object) 
#define Dot_PSL_of_ES(es) ((es) ->t_dot_psl) 
#define LV_Dot_PSL_of_ES(es) Dot_PSL_of_ES(es) 
#define obstack_chunk_alloc g_malloc
#define obstack_chunk_free g_free \

#define FATAL_FLAG (0x1u) 
#define CONTEXT_FLAG (0x2u) 
#define R_ERROR(message) (r_error(r,(message) ,0u) ) 
#define R_ERROR_CXT(message) (r_error(r,(message) ,CONTEXT_FLAG) ) 
#define R_FATAL(message) (r_error(r,(message) ,FATAL_FLAG) ) 
#define R_FATAL_CXT(message) (r_error(r,(message) ,CONTEXT_FLAG|FATAL_FLAG) ) 
#define Message_Callback_of_R(r) ((r) ->t_message_callback) 
#define Message_Callback_Arg_of_R(r) ((r) ->t_message_callback_arg) 

#line 10334 "./marpa.w"

#include "marpa_obs.h"
/*1129:*/
#line 10128 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1129*/
#line 10336 "./marpa.w"

/*132:*/
#line 1135 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:132*//*487:*/
#line 3839 "./marpa.w"
struct s_AHFA_state;
/*:487*//*679:*/
#line 5555 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:679*//*706:*/
#line 5765 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:706*//*742:*/
#line 6190 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:742*//*745:*/
#line 6233 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:745*//*846:*/
#line 7356 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:846*//*1056:*/
#line 9525 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1056*//*1060:*/
#line 9560 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1060*//*1065:*/
#line 9604 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1065*//*1067:*/
#line 9620 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1067*/
#line 10337 "./marpa.w"

/*43:*/
#line 712 "./marpa.w"

typedef struct marpa_g*GRAMMAR;
typedef const struct marpa_g*GRAMMAR_Const;

/*:43*//*217:*/
#line 1569 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:217*//*447:*/
#line 3519 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;

/*:447*//*495:*/
#line 3884 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:495*//*677:*/
#line 5546 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:677*//*782:*/
#line 6634 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:782*//*784:*/
#line 6644 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:784*//*975:*/
#line 8839 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:975*//*1029:*/
#line 9295 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1029*/
#line 10338 "./marpa.w"

/*29:*/
#line 592 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:29*//*51:*/
#line 745 "./marpa.w"
static gint next_grammar_id= 1;
/*:51*//*585:*/
#line 5047 "./marpa.w"
static gint next_recce_id= 1;
/*:585*//*976:*/
#line 8846 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:976*/
#line 10339 "./marpa.w"

/*1057:*/
#line 9528 "./marpa.w"

struct s_dstack{gint t_count;gint t_capacity;gpointer t_base;};
/*:1057*/
#line 10340 "./marpa.w"

/*42:*/
#line 706 "./marpa.w"
struct marpa_g{
/*55:*/
#line 758 "./marpa.w"
GArray*t_symbols;
/*:55*//*65:*/
#line 806 "./marpa.w"
GArray*t_rules;
/*:65*//*104:*/
#line 981 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:104*//*107:*/
#line 995 "./marpa.w"
GHashTable*t_context;
/*:107*//*122:*/
#line 1094 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:122*//*126:*/
#line 1116 "./marpa.w"
Marpa_Error_ID t_error;
/*:126*//*209:*/
#line 1529 "./marpa.w"

Marpa_Symbol_Callback*t_symbol_callback;
gpointer t_symbol_callback_arg;
/*:209*//*321:*/
#line 2286 "./marpa.w"

Marpa_Rule_Callback*t_rule_callback;
gpointer t_rule_callback_arg;
/*:321*//*448:*/
#line 3528 "./marpa.w"

AIM t_AHFA_items;
AIM*t_AHFA_items_by_rule;
/*:448*//*496:*/
#line 3888 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:496*//*1133:*/
#line 10170 "./marpa.w"

Marpa_G_Message_Callback*t_message_callback;
gpointer t_message_callback_arg;
/*:1133*/
#line 707 "./marpa.w"

/*49:*/
#line 743 "./marpa.w"
gint t_id;
/*:49*//*75:*/
#line 851 "./marpa.w"
Marpa_Symbol_ID t_start_symid;
/*:75*//*81:*/
#line 876 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:81*//*84:*/
#line 903 "./marpa.w"
int t_size;
/*:84*//*87:*/
#line 916 "./marpa.w"
guint t_max_rule_length;
/*:87*//*449:*/
#line 3534 "./marpa.w"

guint t_aim_count;
/*:449*//*497:*/
#line 3892 "./marpa.w"
gint t_AHFA_len;
/*:497*/
#line 708 "./marpa.w"

/*91:*/
#line 924 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:91*//*94:*/
#line 932 "./marpa.w"
unsigned int t_has_loop:1;
/*:94*//*98:*/
#line 947 "./marpa.w"
unsigned int t_is_lhs_terminal_ok:1;
/*:98*/
#line 709 "./marpa.w"

};
typedef struct marpa_g GRAMMARD;
/*:42*//*133:*/
#line 1139 "./marpa.w"

struct s_symbol{
/*142:*/
#line 1191 "./marpa.w"
GArray*t_lhs;
/*:142*//*149:*/
#line 1221 "./marpa.w"
GArray*t_rhs;
/*:149*//*196:*/
#line 1421 "./marpa.w"

struct s_symbol*t_alias;
/*:196*/
#line 1141 "./marpa.w"

/*140:*/
#line 1182 "./marpa.w"
Marpa_Symbol_ID t_id;
/*:140*/
#line 1142 "./marpa.w"

/*156:*/
#line 1242 "./marpa.w"
unsigned int t_is_accessible:1;
/*:156*//*162:*/
#line 1268 "./marpa.w"
unsigned int t_is_counted:1;
/*:162*//*166:*/
#line 1286 "./marpa.w"
unsigned int t_is_nullable:1;
/*:166*//*172:*/
#line 1311 "./marpa.w"
unsigned int t_is_nulling:1;
/*:172*//*178:*/
#line 1338 "./marpa.w"
unsigned int t_is_terminal:1;
/*:178*//*184:*/
#line 1367 "./marpa.w"
unsigned int t_is_productive:1;
/*:184*//*190:*/
#line 1392 "./marpa.w"
unsigned int t_is_start:1;
/*:190*//*195:*/
#line 1418 "./marpa.w"

unsigned int t_is_proper_alias:1;
unsigned int t_is_nulling_alias:1;
/*:195*/
#line 1143 "./marpa.w"

};
typedef struct s_symbol SYM_Object;
typedef gint SYMID;

/*:133*//*216:*/
#line 1560 "./marpa.w"

struct s_rule{
/*246:*/
#line 1951 "./marpa.w"
guint t_length;
/*:246*//*266:*/
#line 2030 "./marpa.w"
Marpa_Rule_ID t_id;
/*:266*//*311:*/
#line 2248 "./marpa.w"
gint t_virtual_start;
/*:311*//*315:*/
#line 2264 "./marpa.w"
gint t_virtual_end;
/*:315*//*332:*/
#line 2321 "./marpa.w"
Marpa_Rule_ID t_original;
/*:332*//*337:*/
#line 2335 "./marpa.w"
guint t_real_symbol_count;
/*:337*/
#line 1562 "./marpa.w"

/*269:*/
#line 2042 "./marpa.w"
unsigned int t_is_discard:1;
/*:269*//*283:*/
#line 2126 "./marpa.w"
unsigned int t_is_loop:1;
/*:283*//*288:*/
#line 2147 "./marpa.w"
unsigned int t_is_virtual_loop:1;
/*:288*//*295:*/
#line 2177 "./marpa.w"
unsigned int t_is_used:1;
/*:295*//*299:*/
#line 2193 "./marpa.w"
unsigned int t_is_start:1;
/*:299*//*303:*/
#line 2223 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:303*//*307:*/
#line 2234 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:307*//*341:*/
#line 2344 "./marpa.w"
unsigned int t_is_semantic_equivalent:1;
/*:341*/
#line 1563 "./marpa.w"

/*247:*/
#line 1954 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:247*/
#line 1564 "./marpa.w"

};
/*:216*//*446:*/
#line 3512 "./marpa.w"

struct s_AHFA_item{
Marpa_AHFA_Item_ID t_sort_key;
RULE t_production;
/*455:*/
#line 3557 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:455*/
#line 3516 "./marpa.w"

gint t_position;
};
/*:446*//*488:*/
#line 3840 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
AHFA*t_to_ahfa_ary;
SYMID*t_complete_symbols;
/*492:*/
#line 3864 "./marpa.w"

AIM*t_items;

/*:492*//*507:*/
#line 3946 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:507*/
#line 3849 "./marpa.w"

/*491:*/
#line 3860 "./marpa.w"

guint t_item_count;
/*:491*//*508:*/
#line 3947 "./marpa.w"
guint t_postdot_sym_count;

/*:508*//*532:*/
#line 4158 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:532*/
#line 3850 "./marpa.w"

guint t_complete_symbol_count;
guint t_has_completed_start_rule:1;
/*494:*/
#line 3881 "./marpa.w"

guint t_is_predict:1;

/*:494*/
#line 3853 "./marpa.w"

};
typedef struct s_AHFA_state AHFAD;

/*:488*//*680:*/
#line 5561 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:680*//*681:*/
#line 5566 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
gint t_postdot_sym_count;
/*682:*/
#line 5579 "./marpa.w"

gint t_eim_count;
/*:682*//*684:*/
#line 5594 "./marpa.w"

gint t_ordinal;
/*:684*/
#line 5570 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*683:*/
#line 5583 "./marpa.w"

EIM*t_earley_items;

/*:683*//*1076:*/
#line 9688 "./marpa.w"

PSL t_dot_psl;
/*:1076*/
#line 5573 "./marpa.w"

};

/*:681*//*743:*/
#line 6194 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:743*//*746:*/
#line 6236 "./marpa.w"

struct s_leo_item{
EIX_Object t_earley_ix;
ES t_origin;
AHFA t_top_ahfa;
LIM t_predecessor;
EIM t_base;
ES t_set;
gint t_chain_length;
};
typedef struct s_leo_item LIM_Object;

/*:746*//*759:*/
#line 6381 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:759*//*847:*/
#line 7366 "./marpa.w"

struct s_alternative{
SYMID t_token_id;
void*t_token_value;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:847*//*1061:*/
#line 9563 "./marpa.w"

struct s_dqueue{gint t_current;struct s_dstack t_stack;};

/*:1061*//*1066:*/
#line 9611 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
gpointer t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1066*//*1068:*/
#line 9635 "./marpa.w"

struct s_per_earley_set_arena{
guint t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1068*/
#line 10341 "./marpa.w"

/*577:*/
#line 4992 "./marpa.w"

struct marpa_r{
/*590:*/
#line 5059 "./marpa.w"
const struct marpa_g*t_grammar;

/*:590*//*596:*/
#line 5096 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:596*//*614:*/
#line 5180 "./marpa.w"
gpointer*t_sym_workarea;
/*:614*//*617:*/
#line 5194 "./marpa.w"
gpointer*t_workarea2;
/*:617*//*620:*/
#line 5214 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:620*//*624:*/
#line 5240 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:624*//*631:*/
#line 5290 "./marpa.w"

GTree*t_earley_item_tree;
/*:631*//*653:*/
#line 5435 "./marpa.w"
GHashTable*t_context;
/*:653*//*664:*/
#line 5490 "./marpa.w"
struct obstack t_obs;
/*:664*//*668:*/
#line 5504 "./marpa.w"

Marpa_Error_ID t_error;
Marpa_Error_ID t_fatal_error;
/*:668*//*691:*/
#line 5647 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:691*//*724:*/
#line 5973 "./marpa.w"

EIM t_trace_earley_item;
/*:724*//*765:*/
#line 6434 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:765*//*807:*/
#line 6927 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:807*//*848:*/
#line 7375 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:848*//*876:*/
#line 7684 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:876*//*880:*/
#line 7696 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:880*//*884:*/
#line 7708 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:884*//*1069:*/
#line 9643 "./marpa.w"

struct s_per_earley_set_arena t_dot_psar_object;
/*:1069*//*1141:*/
#line 10207 "./marpa.w"

Marpa_R_Message_Callback*t_message_callback;
gpointer t_message_callback_arg;
/*:1141*/
#line 4994 "./marpa.w"

/*583:*/
#line 5045 "./marpa.w"
gint t_id;
/*:583*//*592:*/
#line 5083 "./marpa.w"

Marpa_Phase t_phase;
/*:592*//*604:*/
#line 5134 "./marpa.w"
guint t_earley_item_warning_threshold;
/*:604*//*610:*/
#line 5162 "./marpa.w"
Marpa_Earleme t_furthest_earleme;
/*:610*//*685:*/
#line 5598 "./marpa.w"

gint t_earley_set_count;
/*:685*/
#line 4995 "./marpa.w"

/*641:*/
#line 5353 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:641*//*647:*/
#line 5396 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:647*//*651:*/
#line 5419 "./marpa.w"

unsigned int t_is_leo_expanding:1;
/*:651*//*808:*/
#line 6930 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:808*/
#line 4996 "./marpa.w"

};

/*:577*/
#line 10342 "./marpa.w"

/*783:*/
#line 6637 "./marpa.w"

struct s_source{
gpointer t_predecessor;
gpointer t_cause;
SYMID t_symbol_id;
};

/*:783*//*785:*/
#line 6647 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:785*//*786:*/
#line 6653 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:786*//*787:*/
#line 6660 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:787*/
#line 10343 "./marpa.w"

/*707:*/
#line 5771 "./marpa.w"

struct s_earley_item_key{
AHFA t_state;
ES t_origin;
ES t_set;
};
typedef struct s_earley_item_key EIK_Object;
struct s_earley_item{
EIK_Object t_key;
union u_source_container t_container;
gint t_ordinal;
/*720:*/
#line 5933 "./marpa.w"

unsigned int t_source_type:3;

/*:720*//*721:*/
#line 5944 "./marpa.w"

unsigned int t_is_leo_expanded:1;

/*:721*/
#line 5782 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:707*/
#line 10344 "./marpa.w"

/*64:*/
#line 799 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid);

/*:64*//*71:*/
#line 826 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g);

/*:71*//*115:*/
#line 1051 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:115*//*117:*/
#line 1064 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:117*//*119:*/
#line 1073 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g);

/*:119*//*134:*/
#line 1148 "./marpa.w"

static inline
SYM symbol_new(struct marpa_g*g);
/*:134*//*139:*/
#line 1178 "./marpa.w"

static inline void symbol_free(SYM symbol);

/*:139*//*148:*/
#line 1212 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id);

/*:148*//*155:*/
#line 1238 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id);

/*:155*//*193:*/
#line 1405 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol);
/*:193*//*199:*/
#line 1446 "./marpa.w"

static inline SYM symbol_proper_alias(SYM symbol);
/*:199*//*202:*/
#line 1474 "./marpa.w"

static inline SYM symbol_null_alias(SYM symbol);
/*:202*//*205:*/
#line 1513 "./marpa.w"

static inline
SYM symbol_alias_create(struct marpa_g*g,
SYM symbol);
/*:205*//*214:*/
#line 1553 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:214*//*219:*/
#line 1578 "./marpa.w"

static inline guint rule_sizeof(guint length);

/*:219*//*223:*/
#line 1603 "./marpa.w"

static
RULE rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length);

/*:223*//*239:*/
#line 1832 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length);

/*:239*//*251:*/
#line 1976 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
/*:251*//*255:*/
#line 1988 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule);
/*:255*//*259:*/
#line 2004 "./marpa.w"

static inline gsize rule_length_get(RULE rule);
/*:259*//*265:*/
#line 2023 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symid(RULE rule,guint rh_index);

/*:265*//*276:*/
#line 2091 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule);
/*:276*//*280:*/
#line 2115 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule);
/*:280*//*294:*/
#line 2173 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,RULE rule);

/*:294*//*330:*/
#line 2314 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:330*//*349:*/
#line 2453 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:349*//*386:*/
#line 2804 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:386*//*425:*/
#line 3171 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:425*//*428:*/
#line 3192 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:428*//*436:*/
#line 3322 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:436*//*468:*/
#line 3624 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id);

/*:468*//*470:*/
#line 3651 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:470*//*477:*/
#line 3720 "./marpa.w"

static gint cmp_by_AHFA_item_id(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:477*//*503:*/
#line 3922 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id);

/*:503*//*506:*/
#line 3937 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const AHFA state,guint item_ix);

/*:506*//*536:*/
#line 4189 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b);
/*:536*//*539:*/
#line 4242 "./marpa.w"

static void create_AHFA_states(struct marpa_g*g);

/*:539*//*551:*/
#line 4617 "./marpa.w"

static inline AHFA assign_AHFA_state(
AHFA state_p,GTree*duplicates);
/*:551*//*564:*/
#line 4800 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:564*//*567:*/
#line 4854 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
);
/*:567*//*571:*/
#line 4955 "./marpa.w"
static inline
AHFA*to_ahfa_array_new(struct marpa_g*g);
/*:571*//*574:*/
#line 4973 "./marpa.w"
static inline
void AHFA_transition_add(AHFA from_ahfa,SYMID symid,AHFA to_ahfa);

/*:574*//*602:*/
#line 5122 "./marpa.w"

static inline ES current_es_of_r(RECCE r);
/*:602*//*657:*/
#line 5456 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint value);
/*:657*//*659:*/
#line 5468 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*value);

/*:659*//*661:*/
#line 5477 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r);

/*:661*//*687:*/
#line 5604 "./marpa.w"

static inline ES earley_set_new(RECCE r,EARLEME id);
/*:687*//*708:*/
#line 5792 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key);
/*:708*//*710:*/
#line 5817 "./marpa.w"

static inline
EIM old_earley_item_assign(const RECCE r,const ES set,const ES origin,const AHFA state);
/*:710*//*712:*/
#line 5834 "./marpa.w"

static inline
EIM earley_item_assign(const RECCE r,const ES set,const ES origin,const AHFA state);
/*:712*//*716:*/
#line 5893 "./marpa.w"

static inline gint trace_earley_item_cmp(gconstpointer ap,gconstpointer bp);
/*:716*//*718:*/
#line 5904 "./marpa.w"

static inline gint earley_item_cmp(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED);
/*:718*//*722:*/
#line 5947 "./marpa.w"

static const char*invalid_source_type_message(guint type);
/*:722*//*738:*/
#line 6151 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r);
/*:738*//*740:*/
#line 6160 "./marpa.w"

Marpa_Earleme marpa_earley_item_origin(struct marpa_r*r);
/*:740*//*748:*/
#line 6253 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r);
/*:748*//*751:*/
#line 6294 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r);
/*:751*//*753:*/
#line 6315 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r);
/*:753*//*761:*/
#line 6397 "./marpa.w"

static inline PIM*pim_sym_p_find(ES set,SYMID symid);
/*:761*//*763:*/
#line 6419 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid);
/*:763*//*774:*/
#line 6562 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r);
/*:774*//*792:*/
#line 6730 "./marpa.w"
static inline void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
SYMID token_id,
gpointer value);

/*:792*//*793:*/
#line 6737 "./marpa.w"
static inline void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause);
/*:793*//*800:*/
#line 6849 "./marpa.w"
static inline void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause);

/*:800*//*803:*/
#line 6890 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item);

/*:803*//*833:*/
#line 7185 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r);
/*:833*//*851:*/
#line 7388 "./marpa.w"

static inline gint alternative_insertion_point(RECCE r,ALT new_alternative);
/*:851*//*853:*/
#line 7425 "./marpa.w"

static inline void alternative_set(
ALT alternative,ES start,EARLEME end,SYMID token_id,gpointer value);
/*:853*//*855:*/
#line 7443 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b);
/*:855*//*857:*/
#line 7467 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme);
/*:857*//*859:*/
#line 7484 "./marpa.w"

static inline gint alternative_insert(RECCE r,ALT alternative);
/*:859*//*902:*/
#line 7931 "./marpa.w"

static inline void earley_set_update_items(RECCE r,ES set);
/*:902*//*904:*/
#line 7955 "./marpa.w"

static inline void r_update_earley_sets(RECCE r);
/*:904*//*907:*/
#line 7981 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES set);
/*:907*//*937:*/
#line 8407 "./marpa.w"

static gint leo_completion_expand(RECCE r,EIM leo_completion);
/*:937*//*978:*/
#line 8859 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:978*//*980:*/
#line 8869 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:980*//*981:*/
#line 8873 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);
/*:981*//*983:*/
#line 8893 "./marpa.w"

static inline Bit_Vector bv_obs_create(struct obstack*obs,guint bits);
/*:983*//*986:*/
#line 8926 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:986*//*988:*/
#line 8945 "./marpa.w"

static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from);

/*:988*//*990:*/
#line 8958 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:990*//*992:*/
#line 8968 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:992*//*994:*/
#line 8976 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:994*//*996:*/
#line 8989 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:996*//*998:*/
#line 8993 "./marpa.w"

static inline void bv_clear(Bit_Vector bv);
/*:998*//*1002:*/
#line 9008 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:1002*//*1004:*/
#line 9016 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:1004*//*1006:*/
#line 9024 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:1006*//*1009:*/
#line 9041 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:1009*//*1011:*/
#line 9054 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:1011*//*1013:*/
#line 9066 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1013*//*1015:*/
#line 9078 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1015*//*1017:*/
#line 9090 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:1017*//*1019:*/
#line 9164 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:1019*//*1021:*/
#line 9182 "./marpa.w"

static inline guint bv_count(Bit_Vector v);

/*:1021*//*1027:*/
#line 9271 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:1027*//*1032:*/
#line 9319 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:1032*//*1034:*/
#line 9327 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:1034*//*1036:*/
#line 9341 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:1036*//*1038:*/
#line 9359 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:1038*//*1041:*/
#line 9368 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:1041*//*1044:*/
#line 9377 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:1044*//*1047:*/
#line 9386 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:1047*//*1049:*/
#line 9439 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:1049*//*1059:*/
#line 9536 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_size);

/*:1059*//*1072:*/
#line 9649 "./marpa.w"

static inline void psar_init(const RECCE r,const PSAR psar);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
/*:1072*//*1078:*/
#line 9700 "./marpa.w"

static inline void psar_reset(const PSAR psar);
/*:1078*//*1080:*/
#line 9719 "./marpa.w"

static inline void psar_dealloc(const PSAR psar);
/*:1080*//*1082:*/
#line 9739 "./marpa.w"

static inline void psl_dealloc(const PSAR psar,const PSL psl);
/*:1082*//*1086:*/
#line 9771 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar);
/*:1086*//*1089:*/
#line 9787 "./marpa.w"

static inline PSL psl_alloc(const PSAR psar);
/*:1089*//*1126:*/
#line 10095 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags);
/*:1126*//*1138:*/
#line 10197 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id);

/*:1138*//*1146:*/
#line 10228 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id);

/*:1146*//*1148:*/
#line 10253 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*eim_tag(gchar*buffer,EIM eim);
#endif
/*:1148*//*1150:*/
#line 10272 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim);
#endif
/*:1150*/
#line 10345 "./marpa.w"

/*62:*/
#line 783 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symid,
SYM symbol)
{
g_array_insert_val(g->t_symbols,(unsigned)symid,symbol);
}

/*:62*//*73:*/
#line 834 "./marpa.w"

static inline
void rule_add(
struct marpa_g*g,
RULEID rule_id,
RULE rule)
{
g_array_insert_val(g->t_rules,(unsigned)rule_id,rule);
LV_Size_of_G(g)+= 1+rule->t_length;
g->t_max_rule_length= MAX(rule->t_length,g->t_max_rule_length);
}

/*:73*/
#line 10346 "./marpa.w"

/*30:*/
#line 599 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:30*//*44:*/
#line 716 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*52:*/
#line 746 "./marpa.w"

g->t_id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:52*//*56:*/
#line 759 "./marpa.w"

g->t_symbols= g_array_new(FALSE,FALSE,sizeof(SYM));
/*:56*//*66:*/
#line 807 "./marpa.w"

g->t_rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:66*//*76:*/
#line 852 "./marpa.w"

g->t_start_symid= -1;
/*:76*//*82:*/
#line 879 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;

/*:82*//*85:*/
#line 904 "./marpa.w"

LV_Size_of_G(g)= 0;

/*:85*//*88:*/
#line 917 "./marpa.w"

g->t_max_rule_length= 0;

/*:88*//*92:*/
#line 925 "./marpa.w"

g->t_is_precomputed= FALSE;
/*:92*//*95:*/
#line 933 "./marpa.w"

g->t_has_loop= FALSE;
/*:95*//*99:*/
#line 948 "./marpa.w"

g->t_is_lhs_terminal_ok= TRUE;
/*:99*//*105:*/
#line 982 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:105*//*108:*/
#line 996 "./marpa.w"

g->t_context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:108*//*123:*/
#line 1097 "./marpa.w"

obstack_init(&g->t_obs);
obstack_init(&g->t_obs_tricky);
/*:123*//*127:*/
#line 1117 "./marpa.w"

g->t_error= NULL;
/*:127*//*210:*/
#line 1532 "./marpa.w"

g->t_symbol_callback_arg= NULL;
g->t_symbol_callback= NULL;
/*:210*//*322:*/
#line 2289 "./marpa.w"

g->t_rule_callback_arg= NULL;
g->t_rule_callback= NULL;
/*:322*//*451:*/
#line 3539 "./marpa.w"

g->t_AHFA_items= NULL;
g->t_AHFA_items_by_rule= NULL;
/*:451*//*498:*/
#line 3893 "./marpa.w"

g->t_AHFA= NULL;
LV_AHFA_Count_of_G(g)= 0;
/*:498*//*1134:*/
#line 10173 "./marpa.w"

g->t_message_callback_arg= NULL;
g->t_message_callback= NULL;
/*:1134*/
#line 719 "./marpa.w"

return g;}
/*:44*//*46:*/
#line 724 "./marpa.w"

void marpa_g_free(struct marpa_g*g)
{/*57:*/
#line 761 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->t_symbols->len;id++)
{symbol_free(SYM_by_ID(g,id));}}
g_array_free(g->t_symbols,TRUE);

/*:57*//*67:*/
#line 809 "./marpa.w"

g_array_free(g->t_rules,TRUE);

/*:67*//*106:*/
#line 983 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:106*//*109:*/
#line 998 "./marpa.w"
g_hash_table_destroy(Context_of_G(g));

/*:109*//*124:*/
#line 1100 "./marpa.w"

obstack_free(&g->t_obs,NULL);
obstack_free(&g->t_obs_tricky,NULL);

/*:124*//*452:*/
#line 3542 "./marpa.w"

if(g->t_AHFA_items){g_free(g->t_AHFA_items);};
if(g->t_AHFA_items_by_rule){g_free(g->t_AHFA_items_by_rule);};

/*:452*//*499:*/
#line 3897 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_by_ID(id);
/*500:*/
#line 3907 "./marpa.w"
{
AHFA*ahfa_transition_array= ahfa_state->t_to_ahfa_ary;
if(ahfa_transition_array)g_free(ahfa_state->t_to_ahfa_ary);
}

/*:500*/
#line 3901 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:499*/
#line 726 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:46*//*53:*/
#line 748 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->t_id;}
/*:53*//*58:*/
#line 769 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->t_symbols;}
/*:58*//*63:*/
#line 794 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid){
return symid>=0&&(guint)symid<g->t_symbols->len;
}
/*:63*//*68:*/
#line 815 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->t_rules;}
/*:68*//*70:*/
#line 822 "./marpa.w"

static inline gint rule_count(const struct marpa_g*g){
return g->t_rules->len;
}
/*:70*//*77:*/
#line 854 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->t_start_symid;}
/*:77*//*79:*/
#line 861 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1104:*/
#line 9937 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1104*/
#line 864 "./marpa.w"

/*1107:*/
#line 9947 "./marpa.w"

if(G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar precomputed";
return failure_indicator;
}
/*:1107*/
#line 865 "./marpa.w"

/*1109:*/
#line 9959 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1109*/
#line 866 "./marpa.w"

g->t_start_symid= symid;
return TRUE;
}
/*:79*//*93:*/
#line 927 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g)
{return G_is_Precomputed(g);}

/*:93*//*96:*/
#line 936 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->t_has_loop;}
/*:96*//*100:*/
#line 951 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->t_is_lhs_terminal_ok;}
/*:100*//*102:*/
#line 958 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok_set(
struct marpa_g*g,gboolean value)
{
if(G_is_Precomputed(g)){
g->t_error= "precomputed";
return FALSE;
}
g->t_is_lhs_terminal_ok= value;
return TRUE;
}
/*:102*//*114:*/
#line 1041 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value
= g_new(struct marpa_context_int_value,1);
value->t_type= MARPA_CONTEXT_INT;
value->t_data= payload;
g_hash_table_insert(Context_of_G(g),(gpointer)key,value);
}
/*:114*//*116:*/
#line 1054 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value
= g_new(struct marpa_context_const_value,1);
value->t_type= MARPA_CONTEXT_CONST;
value->t_data= payload;
g_hash_table_insert(Context_of_G(g),(gpointer)key,value);
}
/*:116*//*118:*/
#line 1070 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g){
g_hash_table_remove_all(Context_of_G(g));}
/*:118*//*120:*/
#line 1076 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(Context_of_G(g),key);}
/*:120*//*129:*/
#line 1125 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g)
{return g->t_error?g->t_error:"unknown error";}
/*:129*//*135:*/
#line 1151 "./marpa.w"

static inline SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= g_malloc(sizeof(SYM_Object));
/*141:*/
#line 1183 "./marpa.w"
symbol->t_id= g->t_symbols->len;

/*:141*//*143:*/
#line 1192 "./marpa.w"

symbol->t_lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:143*//*150:*/
#line 1222 "./marpa.w"

symbol->t_rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:150*//*157:*/
#line 1243 "./marpa.w"

symbol->t_is_accessible= FALSE;
/*:157*//*163:*/
#line 1269 "./marpa.w"

symbol->t_is_counted= FALSE;
/*:163*//*167:*/
#line 1287 "./marpa.w"

symbol->t_is_nullable= FALSE;
/*:167*//*173:*/
#line 1312 "./marpa.w"

symbol->t_is_nulling= FALSE;
/*:173*//*179:*/
#line 1339 "./marpa.w"

symbol->t_is_terminal= FALSE;
/*:179*//*185:*/
#line 1368 "./marpa.w"

symbol->t_is_productive= FALSE;
/*:185*//*191:*/
#line 1393 "./marpa.w"
symbol->t_is_start= FALSE;
/*:191*//*197:*/
#line 1423 "./marpa.w"

symbol->t_is_proper_alias= FALSE;
symbol->t_is_nulling_alias= FALSE;
symbol->t_alias= NULL;

/*:197*/
#line 1156 "./marpa.w"

{
Marpa_Symbol_ID id= symbol->t_id;
g_symbol_add(g,id,symbol);
}
return symbol;
}

/*:135*//*137:*/
#line 1166 "./marpa.w"

Marpa_Symbol_ID
marpa_symbol_new(struct marpa_g*g)
{
Marpa_Symbol_ID id= symbol_new(g)->t_id;
symbol_callback(g,id);
return id;
}

/*:137*//*138:*/
#line 1175 "./marpa.w"

static inline void symbol_free(SYM symbol)
{/*144:*/
#line 1194 "./marpa.w"

g_array_free(symbol->t_lhs,TRUE);
/*:144*//*151:*/
#line 1224 "./marpa.w"
g_array_free(symbol->t_rhs,TRUE);
/*:151*/
#line 1177 "./marpa.w"
g_free(symbol);}
/*:138*//*145:*/
#line 1199 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1105:*/
#line 9939 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1105*/
#line 1201 "./marpa.w"

/*1109:*/
#line 9959 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1109*/
#line 1202 "./marpa.w"

return SYM_by_ID(g,symid)->t_lhs;}
/*:145*//*147:*/
#line 1206 "./marpa.w"
static inline
void symbol_lhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id)
{symbol_lhs_add(SYM_by_ID(g,symid),rule_id);}
/*:147*//*152:*/
#line 1228 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1105:*/
#line 9939 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1105*/
#line 1230 "./marpa.w"

/*1109:*/
#line 9959 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1109*/
#line 1231 "./marpa.w"

return SYM_by_ID(g,symid)->t_rhs;}
/*:152*//*154:*/
#line 1235 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_rhs,rule_id);}
/*:154*//*158:*/
#line 1253 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->t_is_accessible;}
/*:158*//*160:*/
#line 1259 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->t_is_accessible= value;}
/*:160*//*164:*/
#line 1279 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->t_is_counted;}
/*:164*//*168:*/
#line 1297 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->t_is_nullable;}
/*:168*//*170:*/
#line 1303 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->t_is_nullable= value;}
/*:170*//*174:*/
#line 1322 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 1324 "./marpa.w"

/*1109:*/
#line 9959 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1109*/
#line 1325 "./marpa.w"

return SYM_by_ID(g,symid)->t_is_nulling;}
/*:174*//*176:*/
#line 1330 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->t_is_nulling= value;}
/*:176*//*180:*/
#line 1352 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYMID_is_Terminal(g,id);}
/*:180*//*182:*/
#line 1358 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{LV_SYMID_is_Terminal(g,id)= value;}
/*:182*//*186:*/
#line 1378 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->t_is_productive;}
/*:186*//*188:*/
#line 1384 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->t_is_productive= value?1:0;}
/*:188*//*192:*/
#line 1396 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol)
{return symbol->t_is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 1401 "./marpa.w"

/*1109:*/
#line 9959 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1109*/
#line 1402 "./marpa.w"

return symbol_is_start(SYM_by_ID(g,symid));
}
/*:192*//*198:*/
#line 1432 "./marpa.w"

static inline
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 1440 "./marpa.w"

/*1109:*/
#line 9959 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1109*/
#line 1441 "./marpa.w"

symbol= SYM_by_ID(g,symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->t_id;
}
/*:198*//*201:*/
#line 1455 "./marpa.w"

static inline
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 1463 "./marpa.w"

/*1109:*/
#line 9959 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1109*/
#line 1464 "./marpa.w"

symbol= SYM_by_ID(g,symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
g_context_int_add(g,"symid",symid);
g->t_error= "no alias";
return-1;
}
return alias->t_id;
}
/*:201*//*204:*/
#line 1488 "./marpa.w"
static inline
SYM symbol_alias_create(struct marpa_g*g,
SYM symbol)
{
SYM alias= symbol_new(g);
symbol->t_is_proper_alias= TRUE;
symbol->t_is_nulling= FALSE;
symbol->t_is_nullable= FALSE;
symbol->t_alias= alias;
alias->t_is_nulling_alias= TRUE;
alias->t_is_nulling= TRUE;
alias->t_is_nullable= TRUE;
alias->t_is_productive= TRUE;
alias->t_is_accessible= symbol->t_is_accessible;
alias->t_alias= symbol;
return alias;
}
Marpa_Symbol_ID marpa_symbol_alias_create(
struct marpa_g*g,Marpa_Symbol_ID original_id)
{Marpa_Symbol_ID alias_id;
if(original_id<0){return-1;}
if((guint)original_id>=g->t_symbols->len){return-1;}
alias_id= symbol_alias_create(g,SYM_by_ID(g,original_id))->t_id;
symbol_callback(g,alias_id);
return alias_id;}
/*:204*//*211:*/
#line 1535 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->t_symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->t_symbol_callback_arg= cb_arg;}
gpointer marpa_symbol_callback_arg(struct marpa_g*g)
{return g->t_symbol_callback_arg;}
/*:211*//*213:*/
#line 1549 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->t_symbol_callback;
if(cb){(*cb)(g,id);}}
/*:213*//*218:*/
#line 1574 "./marpa.w"

static inline guint rule_sizeof(guint length){
return sizeof(struct s_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:218*//*222:*/
#line 1588 "./marpa.w"

static
RULE rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
/*1105:*/
#line 9939 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1105*/
#line 1593 "./marpa.w"

RULE rule;
/*248:*/
#line 1956 "./marpa.w"

{
SYMID symid= lhs;
/*1109:*/
#line 9959 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1109*/
#line 1959 "./marpa.w"

}
{guint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1109:*/
#line 9959 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1109*/
#line 1964 "./marpa.w"

}
}

/*:248*/
#line 1595 "./marpa.w"

rule= obstack_alloc(&g->t_obs,rule_sizeof(length));
/*249:*/
#line 1968 "./marpa.w"

rule->t_length= length;
rule->t_symbols[0]= lhs;
{guint i;for(i= 0;i<length;i++){
rule->t_symbols[i+1]= rhs[i];}}
/*:249*/
#line 1597 "./marpa.w"

/*267:*/
#line 2031 "./marpa.w"
rule->t_id= g->t_rules->len;

/*:267*//*270:*/
#line 2043 "./marpa.w"

rule->t_is_discard= FALSE;
/*:270*//*284:*/
#line 2127 "./marpa.w"

rule->t_is_loop= FALSE;
/*:284*//*289:*/
#line 2148 "./marpa.w"

rule->t_is_virtual_loop= FALSE;
/*:289*//*296:*/
#line 2178 "./marpa.w"

rule->t_is_used= TRUE;
/*:296*//*300:*/
#line 2194 "./marpa.w"

rule->t_is_start= FALSE;
/*:300*//*304:*/
#line 2224 "./marpa.w"

rule->t_is_virtual_lhs= FALSE;
/*:304*//*308:*/
#line 2235 "./marpa.w"

rule->t_is_virtual_rhs= FALSE;
/*:308*//*312:*/
#line 2249 "./marpa.w"
rule->t_virtual_start= -1;
/*:312*//*316:*/
#line 2265 "./marpa.w"
rule->t_virtual_end= -1;
/*:316*//*333:*/
#line 2322 "./marpa.w"
rule->t_original= -1;
/*:333*//*338:*/
#line 2336 "./marpa.w"
rule->t_real_symbol_count= 0;
/*:338*//*342:*/
#line 2345 "./marpa.w"

rule->t_is_semantic_equivalent= FALSE;
/*:342*/
#line 1598 "./marpa.w"

rule_add(g,rule->t_id,rule);
/*241:*/
#line 1849 "./marpa.w"

symbol_lhs_add(SYM_by_ID(g,rule->t_symbols[0]),rule->t_id);
if(rule->t_length> 0){
gint rh_list_ix;
const guint alloc_size= rule->t_length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*245:*/
#line 1916 "./marpa.w"

{

gint rhs_ix= (gint)rule->t_length-1;
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

/*:245*/
#line 1857 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(g,rh_symbol_list[rh_list_ix]),
rule->t_id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:241*/
#line 1600 "./marpa.w"

return rule;
}
/*:222*//*224:*/
#line 1608 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
{
Marpa_Rule_ID rule_id;
RULE rule;
if(is_rule_duplicate(g,lhs,rhs,length)==TRUE){
g->t_error= (Marpa_Error_ID)"duplicate rule";
return-1;
}
rule= rule_start(g,lhs,rhs,length);
if(!rule){return-1;}
rule_id= rule->t_id;
rule_callback(g,rule_id);
return rule_id;
}

/*:224*//*225:*/
#line 1625 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 1630 "./marpa.w"

Marpa_Rule_ID original_rule_id;
RULE original_rule;
Marpa_Symbol_ID internal_lhs_id,*temp_rhs;
if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE){
g_context_clear(g);
g->t_error= (Marpa_Error_ID)"duplicate rule";
return failure_indicator;
}

/*227:*/
#line 1661 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){
g_context_clear(g);
g->t_error= "internal_error";
return failure_indicator;
}
original_rule->t_is_used= 0;
original_rule_id= original_rule->t_id;
rule_callback(g,original_rule_id);

/*:227*/
#line 1640 "./marpa.w"

/*228:*/
#line 1672 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g_context_clear(g);
g_context_int_add(g,"symid",separator_id);
g->t_error= "bad separator";
return failure_indicator;
}

/*:228*/
#line 1641 "./marpa.w"

/*229:*/
#line 1680 "./marpa.w"

SYM_by_ID(g,rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(g,separator_id)->t_is_counted= 1;}
/*:229*/
#line 1642 "./marpa.w"

if(min==0){/*230:*/
#line 1683 "./marpa.w"

{RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1114:*/
#line 9994 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1114*/
#line 1685 "./marpa.w"
}
rule->t_is_semantic_equivalent= TRUE;
rule->t_original= original_rule_id;
rule_callback(g,rule->t_id);
}
/*:230*/
#line 1643 "./marpa.w"
}
min= 1;
/*231:*/
#line 1690 "./marpa.w"

internal_lhs_id= symbol_new(g)->t_id;
symbol_callback(g,internal_lhs_id);
/*:231*/
#line 1645 "./marpa.w"

/*232:*/
#line 1704 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:232*/
#line 1646 "./marpa.w"

/*234:*/
#line 1707 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1114:*/
#line 9994 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1114*/
#line 1711 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;

rule->t_is_virtual_rhs= TRUE;
rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->t_id);
}
/*:234*/
#line 1647 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*235:*/
#line 1720 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1114:*/
#line 9994 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1114*/
#line 1725 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;
rule->t_is_virtual_rhs= TRUE;
rule->t_real_symbol_count= 1;
rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->t_id);
}
/*:235*/
#line 1649 "./marpa.w"

}
/*236:*/
#line 1737 "./marpa.w"

{RULE rule;
guint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1114:*/
#line 9994 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1114*/
#line 1747 "./marpa.w"
}
rule->t_is_virtual_lhs= TRUE;
rule->t_real_symbol_count= rhs_ix;
rule_callback(g,rule->t_id);
}
/*:236*/
#line 1651 "./marpa.w"

/*237:*/
#line 1752 "./marpa.w"

{RULE rule;
guint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1114:*/
#line 9994 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1114*/
#line 1759 "./marpa.w"
}
rule->t_is_virtual_lhs= TRUE;
rule->t_is_virtual_rhs= TRUE;
rule->t_real_symbol_count= rhs_ix-1;
rule_callback(g,rule->t_id);
}

/*:237*/
#line 1652 "./marpa.w"

/*233:*/
#line 1706 "./marpa.w"
g_free(temp_rhs);
/*:233*/
#line 1653 "./marpa.w"

return original_rule_id;
}
/*:225*//*238:*/
#line 1808 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length)
{
guint ix;
SYM lhs= SYM_by_ID(g,lhs_id);
GArray*same_lhs_array= lhs->t_lhs;
guint same_lhs_count= same_lhs_array->len;
for(ix= 0;ix<same_lhs_count;ix++){
RULEID same_lhs_rule_id= ((RULEID*)(same_lhs_array->data))[ix];
guint rhs_position;
RULE rule= RULE_by_ID(g,same_lhs_rule_id);
if(rule->t_length!=length){goto RULE_IS_NOT_DUPLICATE;}
for(rhs_position= 0;rhs_position<rule->t_length;rhs_position++){
if(rhs_symid(rule,rhs_position)!=rhs_ids[rhs_position]){
goto RULE_IS_NOT_DUPLICATE;
}
}
return TRUE;
RULE_IS_NOT_DUPLICATE:;
}
return FALSE;
}
/*:238*//*250:*/
#line 1973 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule){
return rule->t_symbols[0];}
/*:250*//*252:*/
#line 1978 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 1980 "./marpa.w"

/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 1981 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));}
/*:252*//*254:*/
#line 1985 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule){
return rule->t_symbols+1;}
/*:254*//*256:*/
#line 1990 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix){
RULE rule;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 1993 "./marpa.w"

/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 1994 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(rule->t_length<=ix)return-1;
return rhs_symid(rule,ix);
}
/*:256*//*258:*/
#line 2001 "./marpa.w"

static inline gsize rule_length_get(RULE rule){
return rule->t_length;}
/*:258*//*260:*/
#line 2006 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 2008 "./marpa.w"

/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 2009 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}
/*:260*//*264:*/
#line 2018 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symid(RULE rule,guint rh_index){
return rule->t_symbols[rh_index+1];
}
/*:264*//*271:*/
#line 2045 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_discard;}
/*:271*//*275:*/
#line 2078 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_PRD(rule);
return SYM_by_ID(g,lhs_id)->t_is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 2085 "./marpa.w"

RULE rule;
/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 2087 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:275*//*279:*/
#line 2098 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->t_length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symid(rule,rh_ix);
if(!SYM_by_ID(g,rhs_id)->t_is_productive)return FALSE;
}
return TRUE;}
gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 2109 "./marpa.w"

RULE rule;
/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 2111 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}
/*:279*//*285:*/
#line 2131 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 2134 "./marpa.w"

/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 2135 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}
/*:285*//*290:*/
#line 2152 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 2155 "./marpa.w"

/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 2156 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;}
/*:290*//*293:*/
#line 2164 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,RULE rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<rule->t_length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symid(rule,rh_ix);
if(!SYM_by_ID(g,rhs_id)->t_is_nulling)return FALSE;
}
return TRUE;}
/*:293*//*297:*/
#line 2182 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 2185 "./marpa.w"

/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 2186 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_used;}
/*:297*//*301:*/
#line 2198 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 2201 "./marpa.w"

/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 2202 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_start;}
/*:301*//*305:*/
#line 2227 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_virtual_lhs;}
/*:305*//*309:*/
#line 2238 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_virtual_rhs;}
/*:309*//*313:*/
#line 2250 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 2253 "./marpa.w"

/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 2254 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}
/*:313*//*317:*/
#line 2266 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 2269 "./marpa.w"

/*1110:*/
#line 9966 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1110*/
#line 2270 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}
/*:317*//*323:*/
#line 2292 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->t_rule_callback= cb;}
/*:323*//*325:*/
#line 2297 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->t_rule_callback_arg= cb_arg;}
/*:325*//*327:*/
#line 2302 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g)
{return g->t_rule_callback_arg;}
/*:327*//*329:*/
#line 2310 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->t_rule_callback;
if(cb){(*cb)(g,id);}}
/*:329*//*334:*/
#line 2323 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_original;}
/*:334*//*339:*/
#line 2337 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_real_symbol_count;}
/*:339*//*343:*/
#line 2356 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
RULE rewrite_rule= RULE_by_ID(g,id);
return rewrite_rule->t_is_semantic_equivalent?rewrite_rule->t_original:-1;}
/*:343*//*345:*/
#line 2375 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
if(!census(g))return NULL;
if(!CHAF_rewrite(g))return NULL;
if(!g_augment(g))return NULL;
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*575:*/
#line 4977 "./marpa.w"
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

/*:575*/
#line 2384 "./marpa.w"

return g;
}
/*:345*//*348:*/
#line 2422 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*1105:*/
#line 9939 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1105*/
#line 2425 "./marpa.w"

/*350:*/
#line 2455 "./marpa.w"

guint pre_rewrite_rule_count= g->t_rules->len;
guint pre_rewrite_symbol_count= g->t_symbols->len;

/*:350*//*355:*/
#line 2492 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_start_symid;
SYM original_start_symbol;

/*:355*//*359:*/
#line 2531 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:359*//*365:*/
#line 2590 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:365*//*367:*/
#line 2617 "./marpa.w"

Bit_Vector nullable_v;
/*:367*//*371:*/
#line 2643 "./marpa.w"

Bit_Vector productive_v;
/*:371*//*374:*/
#line 2684 "./marpa.w"
Bit_Matrix reach_matrix;
/*:374*//*377:*/
#line 2702 "./marpa.w"

Bit_Vector accessible_v;

/*:377*/
#line 2426 "./marpa.w"

/*351:*/
#line 2459 "./marpa.w"

if(g->t_rules->len<=0){g->t_error= "no rules";return NULL;}
/*:351*/
#line 2427 "./marpa.w"

/*352:*/
#line 2466 "./marpa.w"

if(G_is_Precomputed(g)){g->t_error= "precomputed";return NULL;}
/*:352*/
#line 2428 "./marpa.w"

/*354:*/
#line 2472 "./marpa.w"

if(original_start_symid<0){
g_context_clear(g);
g->t_error= "no start symbol";
return failure_indicator;
}
if(!symbol_is_valid(g,original_start_symid)){
g_context_clear(g);
g_context_int_add(g,"symid",original_start_symid);
g->t_error= "invalid start symbol";
return failure_indicator;
}
original_start_symbol= SYM_by_ID(g,original_start_symid);
if(original_start_symbol->t_lhs->len<=0){
g_context_clear(g);
g_context_int_add(g,"symid",original_start_symid);
g->t_error= "start symbol not on LHS";
return failure_indicator;
}

/*:354*/
#line 2429 "./marpa.w"

/*356:*/
#line 2496 "./marpa.w"

{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;
rule_id<(Marpa_Rule_ID)pre_rewrite_rule_count;
rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_PRD(rule);
bv_bit_set(lhs_v,(guint)lhs_id);
if(rule->t_length<=0){
bv_bit_set(empty_lhs_v,(guint)lhs_id);
have_empty_rule= 1;
}
}
}
/*:356*/
#line 2430 "./marpa.w"

/*357:*/
#line 2515 "./marpa.w"

{Marpa_Symbol_ID symid;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symid= 0;
symid<(Marpa_Symbol_ID)pre_rewrite_symbol_count;
symid++){
SYM symbol= SYM_by_ID(g,symid);
if(SYM_is_Terminal(symbol)){
bv_bit_set(terminal_v,(guint)symid);
have_marked_terminals= 1;
}
}}
/*:357*/
#line 2431 "./marpa.w"

if(have_marked_terminals){
/*361:*/
#line 2546 "./marpa.w"

if(!g->t_is_lhs_terminal_ok){
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
g->t_error= "lhs is terminal";
return NULL;
}
}

/*:361*/
#line 2433 "./marpa.w"

}else{
/*360:*/
#line 2535 "./marpa.w"

if(have_empty_rule&&g->t_is_lhs_terminal_ok){
g->t_error= "empty rule and unmarked terminals";
return NULL;
}
/*:360*/
#line 2435 "./marpa.w"
;
if(g->t_is_lhs_terminal_ok){
/*362:*/
#line 2570 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->t_symbols->len;symid++)
{LV_SYMID_is_Terminal(g,symid)= 1;}}
/*:362*/
#line 2437 "./marpa.w"

}else{
/*363:*/
#line 2575 "./marpa.w"

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
/*:363*/
#line 2439 "./marpa.w"

}
}
/*366:*/
#line 2595 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
SYM symbol= SYM_by_ID(g,symid);
if(symbol->t_is_counted){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
grammar_message(g,"counted nullable");
counted_nullables++;
}
symbol->t_is_nullable= 1;
}}
if(counted_nullables){
g->t_error= "counted nullable";
return NULL;
}
}
/*:366*/
#line 2442 "./marpa.w"

/*369:*/
#line 2622 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(g,symid);
symbol->t_is_productive= 1;
}}
}
/*:369*/
#line 2443 "./marpa.w"

/*370:*/
#line 2636 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->t_start_symid))
{
g_context_int_add(g,"symid",g->t_start_symid);
g->t_error= "unproductive start symbol";
return NULL;
}
/*:370*/
#line 2444 "./marpa.w"

/*373:*/
#line 2666 "./marpa.w"

reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{guint symid,no_of_symbols= SYM_Count_of_G(g);
for(symid= 0;symid<no_of_symbols;symid++){
matrix_bit_set(reach_matrix,symid,symid);
}}
{Marpa_Rule_ID rule_id;
guint no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_PRD(rule);
guint rhs_ix,rule_length= rule->t_length;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,
(guint)lhs_id,(guint)rhs_symid(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:373*/
#line 2445 "./marpa.w"

/*376:*/
#line 2688 "./marpa.w"

accessible_v= matrix_row(reach_matrix,(guint)original_start_symid);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(g,symid);
symbol->t_is_accessible= 1;
}}
}
/*:376*/
#line 2446 "./marpa.w"

/*378:*/
#line 2707 "./marpa.w"

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
SYM_by_ID(g,productive_id)->t_is_nulling= 1;
}
}
bv_free(reaches_terminal_v);
}

/*:378*/
#line 2447 "./marpa.w"

/*358:*/
#line 2527 "./marpa.w"

bv_free(terminal_v);
/*:358*//*364:*/
#line 2587 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:364*//*368:*/
#line 2619 "./marpa.w"

bv_free(nullable_v);

/*:368*//*372:*/
#line 2645 "./marpa.w"

bv_free(productive_v);

/*:372*/
#line 2448 "./marpa.w"

/*375:*/
#line 2685 "./marpa.w"

matrix_free(reach_matrix);

/*:375*/
#line 2449 "./marpa.w"

g->t_is_precomputed= TRUE;
return g;
}
/*:348*//*385:*/
#line 2783 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*387:*/
#line 2806 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:387*//*391:*/
#line 2857 "./marpa.w"

guint factor_count;
guint*factor_positions;
/*:391*//*396:*/
#line 2906 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:396*/
#line 2786 "./marpa.w"

/*392:*/
#line 2860 "./marpa.w"

factor_positions= g_new(guint,g->t_max_rule_length);
/*:392*//*397:*/
#line 2909 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:397*/
#line 2787 "./marpa.w"

/*389:*/
#line 2818 "./marpa.w"

{gint no_of_symbols= SYM_Count_of_G(g);
Marpa_Symbol_ID symid;
for(symid= 0;symid<no_of_symbols;symid++){
SYM symbol= SYM_by_ID(g,symid);
SYM alias;
if(!symbol->t_is_nullable)continue;
if(symbol->t_is_nulling)continue;
if(!symbol->t_is_accessible)continue;
if(!symbol->t_is_productive)continue;
if(symbol_null_alias(symbol))continue;
alias= symbol_alias_create(g,symbol);
symbol_callback(g,alias->t_id);
}}

/*:389*/
#line 2788 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
guint rule_length= rule->t_length;
guint nullable_suffix_ix= 0;
/*388:*/
#line 2810 "./marpa.w"

if(!rule->t_is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->t_is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->t_is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->t_is_used= 0;goto NEXT_RULE;}

/*:388*/
#line 2794 "./marpa.w"

/*390:*/
#line 2841 "./marpa.w"

{guint rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= rhs_symid(rule,rhs_ix);
SYM symbol= SYM_by_ID(g,symid);
if(symbol->t_is_nulling)continue;
if(symbol_null_alias(symbol)){

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}}
/*:390*/
#line 2795 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*394:*/
#line 2866 "./marpa.w"

rule->t_is_used= 0;
{guint unprocessed_factor_count;

guint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_PRD(rule);
guint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*400:*/
#line 2919 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symid;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*395:*/
#line 2885 "./marpa.w"
{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= chaf_virtual_symbol->t_id;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",LHS_ID_of_PRD(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symid);
}

/*:395*/
#line 2927 "./marpa.w"

/*401:*/
#line 2946 "./marpa.w"

{
guint remaining_rhs_length,piece_rhs_length;
/*402:*/
#line 2958 "./marpa.w"

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
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 2970 "./marpa.w"

}

/*:402*/
#line 2949 "./marpa.w"
;
/*403:*/
#line 2973 "./marpa.w"

{guint chaf_rule_length= rule->t_length-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;
remaining_rhs_length++){
Marpa_Symbol_ID original_id= rhs_symid(rule,piece_start+remaining_rhs_length);
SYM alias= symbol_null_alias(SYM_by_ID(g,original_id));
remaining_rhs[remaining_rhs_length]= alias?alias->t_id:original_id;
}}
{RULE chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 2985 "./marpa.w"

}

/*:403*/
#line 2950 "./marpa.w"
;
/*404:*/
#line 2990 "./marpa.w"
{
Marpa_Symbol_ID proper_id= rhs_symid(rule,first_factor_position);
SYM alias= symbol_null_alias(SYM_by_ID(g,proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
alias->t_id;
}
{RULE chaf_rule;
guint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3000 "./marpa.w"

}

/*:404*/
#line 2951 "./marpa.w"
;
/*405:*/
#line 3009 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3014 "./marpa.w"

}

/*:405*/
#line 2952 "./marpa.w"
;
}

/*:401*/
#line 2928 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*395:*/
#line 2885 "./marpa.w"
{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= chaf_virtual_symbol->t_id;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",LHS_ID_of_PRD(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symid);
}

/*:395*/
#line 2933 "./marpa.w"

/*407:*/
#line 3019 "./marpa.w"
{
guint piece_rhs_length;
RULE chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:407*//*408:*/
#line 3028 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3034 "./marpa.w"


/*:408*//*409:*/
#line 3037 "./marpa.w"

second_factor_proper_id= rhs_symid(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3042 "./marpa.w"


/*:409*//*410:*/
#line 3045 "./marpa.w"

first_factor_proper_id= rhs_symid(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3051 "./marpa.w"


/*:410*//*411:*/
#line 3054 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3057 "./marpa.w"


/*:411*//*412:*/
#line 3060 "./marpa.w"
}

/*:412*/
#line 2934 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:400*/
#line 2877 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*413:*/
#line 3064 "./marpa.w"
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
piece_end= rule->t_length-1;
real_symbol_count= piece_end-piece_start+1;

/*:413*//*414:*/
#line 3078 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3083 "./marpa.w"


/*:414*//*415:*/
#line 3086 "./marpa.w"

second_factor_proper_id= rhs_symid(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3091 "./marpa.w"


/*:415*//*416:*/
#line 3094 "./marpa.w"

first_factor_proper_id= rhs_symid(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3100 "./marpa.w"


/*:416*//*417:*/
#line 3104 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3108 "./marpa.w"

}

/*:417*//*418:*/
#line 3112 "./marpa.w"
}

/*:418*/
#line 2880 "./marpa.w"

}else{
/*419:*/
#line 3115 "./marpa.w"
{
guint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
guint real_symbol_count;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->t_length-1;
real_symbol_count= piece_end-piece_start+1;

/*:419*//*420:*/
#line 3126 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symid(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3131 "./marpa.w"


/*:420*//*421:*/
#line 3135 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symid(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3151 "./marpa.w"

chaf_rule->t_is_used= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= chaf_rule->t_length> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3141 "./marpa.w"

}

/*:421*//*422:*/
#line 3145 "./marpa.w"
}

/*:422*/
#line 2882 "./marpa.w"

}}

/*:394*/
#line 2798 "./marpa.w"

NEXT_RULE:;
}
/*393:*/
#line 2862 "./marpa.w"

g_free(factor_positions);

/*:393*//*398:*/
#line 2912 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:398*/
#line 2801 "./marpa.w"

return g;
}
/*:385*//*424:*/
#line 3165 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
SYM alias= symbol_null_alias(SYM_by_ID(g,proper_id));
return alias->t_id;
}
/*:424*//*427:*/
#line 3179 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g,g->t_start_symid);
/*429:*/
#line 3195 "./marpa.w"

if(old_start->t_is_nulling){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:429*/
#line 3187 "./marpa.w"

if(proper_old_start){/*430:*/
#line 3205 "./marpa.w"
{
RULE new_start_rule;
proper_old_start->t_is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= proper_new_start->t_id;
g->t_start_symid= proper_new_start_id;
proper_new_start->t_is_accessible= TRUE;
proper_new_start->t_is_productive= TRUE;
proper_new_start->t_is_start= TRUE;
g_context_clear(g);
g_context_int_add(g,"old_start_id",old_start->t_id);
symbol_callback(g,proper_new_start_id);
new_start_rule= rule_start(g,proper_new_start_id,&old_start->t_id,1);
new_start_rule->t_is_start= 1;
new_start_rule->t_is_virtual_lhs= 1;
new_start_rule->t_real_symbol_count= 1;
new_start_rule->t_is_used= TRUE;
g->t_proper_start_rule= new_start_rule;
rule_callback(g,new_start_rule->t_id);
}

/*:430*/
#line 3188 "./marpa.w"
}
if(nulling_old_start){/*431:*/
#line 3230 "./marpa.w"
{
Marpa_Symbol_ID nulling_new_start_id;
RULE new_start_rule;
SYM nulling_new_start;
if(proper_new_start)
{
nulling_new_start= symbol_alias_create(g,proper_new_start);
nulling_new_start_id= nulling_new_start->t_id;
}
else
{
nulling_new_start= symbol_new(g);
nulling_new_start_id= nulling_new_start->t_id;
g->t_start_symid= nulling_new_start_id;
nulling_new_start->t_is_nulling= TRUE;
nulling_new_start->t_is_nullable= TRUE;
nulling_new_start->t_is_productive= TRUE;
nulling_new_start->t_is_accessible= TRUE;
}
nulling_new_start->t_is_start= TRUE;
g_context_clear(g);
g_context_int_add(g,"old_start_id",old_start->t_id);
symbol_callback(g,nulling_new_start_id);
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
new_start_rule->t_is_start= 1;
new_start_rule->t_is_virtual_lhs= 1;
new_start_rule->t_real_symbol_count= 1;
new_start_rule->t_is_used= TRUE;
g->t_null_start_rule= new_start_rule;
rule_callback(g,new_start_rule->t_id);
}

/*:431*/
#line 3189 "./marpa.w"
}
return g;
}
/*:427*//*435:*/
#line 3308 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{guint no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*437:*/
#line 3331 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID proper_id;
guint rhs_ix,rule_length;
if(!rule->t_is_used)continue;
rule_length= rule->t_length;
proper_id= -1;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= rhs_symid(rule,rhs_ix);
SYM symbol= SYM_by_ID(g,symid);
if(symbol->t_is_nullable)continue;
if(proper_id>=0)goto NEXT_RULE;

proper_id= symid;
}

if(proper_id<0)continue;

{SYM rhs_symbol= SYM_by_ID(g,proper_id);
GArray*lhs_rules= rhs_symbol->t_lhs;
guint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,(guint)rule_id,
(guint)g_array_index(lhs_rules,Marpa_Rule_ID,ix));
}}
NEXT_RULE:;
}}

/*:437*/
#line 3315 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*438:*/
#line 3370 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule;
if(!matrix_bit_test(unit_transition_matrix,(guint)rule_id,(guint)rule_id))
continue;
loop_rule_count++;
rule= RULE_by_ID(g,rule_id);
rule->t_is_loop= TRUE;
rule->t_is_virtual_loop= rule->t_virtual_start<0||!rule->t_is_virtual_rhs;
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
grammar_message(g,"loop rule");
}}

/*:438*/
#line 3317 "./marpa.w"

if(loop_rule_count)g->t_has_loop= TRUE;
/*439:*/
#line 3391 "./marpa.w"

g_context_clear(g);
g_context_int_add(g,"loop_rule_count",loop_rule_count);
grammar_message(g,"loop rule tally");

/*:439*/
#line 3319 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:435*//*457:*/
#line 3566 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 3568 "./marpa.w"

/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 3569 "./marpa.w"

return AIM_Count_of_G(g);
}
/*:457*//*459:*/
#line 3575 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 3578 "./marpa.w"

/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 3579 "./marpa.w"

/*1111:*/
#line 9973 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1111*/
#line 3580 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(g,item_id))->t_id;
}
/*:459*//*461:*/
#line 3586 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 3589 "./marpa.w"

/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 3590 "./marpa.w"

/*1111:*/
#line 9973 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1111*/
#line 3591 "./marpa.w"

return Position_of_AIM(AIM_by_ID(g,item_id));
}
/*:461*//*463:*/
#line 3597 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 3600 "./marpa.w"

/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 3601 "./marpa.w"

/*1111:*/
#line 9973 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1111*/
#line 3602 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(g,item_id));
}
/*:463*//*465:*/
#line 3607 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 3610 "./marpa.w"

/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 3611 "./marpa.w"

/*1111:*/
#line 9973 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1111*/
#line 3612 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(g,item_id));
}
/*:465*//*467:*/
#line 3619 "./marpa.w"

static inline gboolean item_is_valid(
const struct marpa_g*g,Marpa_AHFA_Item_ID item_id){
return item_id<(Marpa_AHFA_Item_ID)AIM_Count_of_G(g)&&item_id>=0;
}
/*:467*//*469:*/
#line 3634 "./marpa.w"

static inline
void create_AHFA_items(struct marpa_g*g){
Marpa_Rule_ID rule_id;
guint no_of_items;
guint no_of_rules= rule_count(g);
AIM base_item= g_new(struct s_AHFA_item,Size_of_G(g));
AIM current_item= base_item;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
/*471:*/
#line 3654 "./marpa.w"

guint rhs_ix;
RULE rule= RULE_by_ID(g,rule_id);
if(!rule->t_is_used)goto NEXT_RULE;
for(rhs_ix= 0;rhs_ix<rule->t_length;rhs_ix++){
/*472:*/
#line 3666 "./marpa.w"

Marpa_Symbol_ID rh_symid= rhs_symid(rule,rhs_ix);
SYM symbol= SYM_by_ID(g,rh_symid);
if(symbol->t_is_nullable)goto NEXT_RH_SYMBOL;
LV_Sort_Key_of_AIM(current_item)= current_item-base_item;
LV_Postdot_SYMID_of_AIM(current_item)= rh_symid;
LV_RULE_of_AIM(current_item)= rule;
LV_Position_of_AIM(current_item)= rhs_ix;

/*:472*/
#line 3659 "./marpa.w"

current_item++;
NEXT_RH_SYMBOL:;
}
/*473:*/
#line 3675 "./marpa.w"

LV_Sort_Key_of_AIM(current_item)= current_item-base_item;
LV_Postdot_SYMID_of_AIM(current_item)= -1;
LV_Position_of_AIM(current_item)= -1;
LV_RULE_of_AIM(current_item)= rule;

/*:473*/
#line 3663 "./marpa.w"

current_item++;

/*:471*/
#line 3643 "./marpa.w"

NEXT_RULE:;
}
no_of_items= LV_AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*474:*/
#line 3686 "./marpa.w"
{
AIM*items_by_rule= g_new0(AIM,no_of_rules);

AIM items= g->t_AHFA_items;
Marpa_Rule_ID highest_found_rule_id= -1;

Marpa_AHFA_Item_ID item_id;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){
AIM item= items+item_id;
Marpa_Rule_ID rule_id_for_item= LV_RULE_of_AIM(item)->t_id;
if(rule_id_for_item<=highest_found_rule_id)continue;
items_by_rule[rule_id_for_item]= item;
highest_found_rule_id= rule_id_for_item;
}
g->t_AHFA_items_by_rule= items_by_rule;
}

/*:474*/
#line 3648 "./marpa.w"

/*478:*/
#line 3723 "./marpa.w"
{Marpa_AHFA_Item_ID item_id;
AIM*sort_array= g_new(struct s_AHFA_item*,no_of_items);
AIM items= g->t_AHFA_items;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){



sort_array[item_id]= items+item_id;
}
g_qsort_with_data(sort_array,
(gint)no_of_items,sizeof(AIM),cmp_by_AHFA_item_id,(gpointer)NULL);
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){
LV_Sort_Key_of_AIM(sort_array[item_id])= item_id;
}
g_free(sort_array);}

/*:478*/
#line 3649 "./marpa.w"

}
/*:469*//*476:*/
#line 3707 "./marpa.w"

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
/*:476*//*502:*/
#line 3917 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id){
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}
/*:502*//*505:*/
#line 3932 "./marpa.w"

static inline Marpa_AHFA_Item_ID AHFA_state_item_ix2id(
const struct marpa_g*g,const AHFA state,guint item_ix){
return state->t_items[item_ix]-g->t_AHFA_items;
}
/*:505*//*509:*/
#line 3950 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return AHFA_Count_of_G(g);
}
/*:509*//*511:*/
#line 3957 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 3960 "./marpa.w"

AHFA state;
/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 3962 "./marpa.w"

/*1112:*/
#line 9980 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1112*/
#line 3963 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
return state->t_item_count;
}
/*:511*//*513:*/
#line 3970 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
guint item_ix){
AHFA state;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 3975 "./marpa.w"

/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 3976 "./marpa.w"

/*1112:*/
#line 9980 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1112*/
#line 3977 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
if(item_ix>=state->t_item_count){
g_context_clear(g);
g_context_int_add(g,"item_ix",(gint)item_ix);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid state item ix";
return failure_indicator;
}
return AHFA_state_item_ix2id(g,state,item_ix);
}
/*:513*//*521:*/
#line 4027 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 4032 "./marpa.w"

AHFA from_ahfa_state;
AHFA*to_ahfa_array;
SYMID symid;
gint symbol_count;

/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 4038 "./marpa.w"

/*1112:*/
#line 9980 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1112*/
#line 4039 "./marpa.w"

/*1113:*/
#line 9987 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
g_context_clear(g);
g_context_int_add(g,"expected size",sizeof(gint));
g->t_error= "garray size mismatch";
return failure_indicator;
}
/*:1113*/
#line 4040 "./marpa.w"

from_ahfa_state= AHFA_by_ID(AHFA_state_id);
to_ahfa_array= from_ahfa_state->t_to_ahfa_ary;
symbol_count= SYM_Count_of_G(g);
g_array_set_size(result,0);
for(symid= 0;symid<symbol_count;symid++){
AHFA to_ahfa_state= to_ahfa_array[symid];
if(!to_ahfa_state)continue;
g_array_append_val(result,symid);
g_array_append_val(result,ID_of_AHFA(to_ahfa_state));
}
return result->len;
}

/*:521*//*523:*/
#line 4058 "./marpa.w"

AHFAID marpa_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 4063 "./marpa.w"

/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 4064 "./marpa.w"

/*1112:*/
#line 9980 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1112*/
#line 4065 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}
/*:523*//*525:*/
#line 4076 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 4080 "./marpa.w"

/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 4081 "./marpa.w"

/*1112:*/
#line 9980 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1112*/
#line 4082 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
return AHFA_is_Predicted(state);
}
/*:525*//*530:*/
#line 4120 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
const gint no_completed_start_rule= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 4124 "./marpa.w"

AHFA state;
/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 4126 "./marpa.w"

/*1112:*/
#line 9980 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1112*/
#line 4127 "./marpa.w"

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
/*1114:*/
#line 9994 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1114*/
#line 4143 "./marpa.w"

}
return no_completed_start_rule;
}

/*:530*//*534:*/
#line 4162 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 4165 "./marpa.w"

AHFA state;
/*1108:*/
#line 9953 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1108*/
#line 4167 "./marpa.w"

/*1112:*/
#line 9980 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1112*/
#line 4168 "./marpa.w"

state= AHFA_by_ID(AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:534*//*537:*/
#line 4191 "./marpa.w"

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

/*:537*//*538:*/
#line 4215 "./marpa.w"

static
void create_AHFA_states(struct marpa_g*g){
AHFA p_working_state;
const guint initial_no_of_states= 2*Size_of_G(g);
AIM AHFA_item_0_p= g->t_AHFA_items;
guint no_of_symbols= SYM_Count_of_G(g);
guint no_of_rules= rule_count(g);
Bit_Matrix prediction_matrix;
RULE*rule_by_sort_key= g_new(RULE,no_of_rules);
GTree*duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
/*541:*/
#line 4277 "./marpa.w"
{guint item_id;
guint no_of_items_in_grammar= AIM_Count_of_G(g);
duplicates= g_tree_new(AHFA_state_cmp);
singleton_duplicates= g_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++){
singleton_duplicates[item_id]= NULL;
}}
/*:541*/
#line 4228 "./marpa.w"

DQUEUE_INIT(states,AHFAD,initial_no_of_states);
/*558:*/
#line 4687 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= matrix_create(no_of_symbols,no_of_symbols);
/*559:*/
#line 4695 "./marpa.w"

{Marpa_Rule_ID rule_id;
Marpa_Symbol_ID symid;
AIM*items_by_rule= g->t_AHFA_items_by_rule;
for(symid= 0;symid<(Marpa_Symbol_ID)no_of_symbols;symid++){

SYM symbol= SYM_by_ID(g,symid);
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

/*:559*/
#line 4689 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*560:*/
#line 4727 "./marpa.w"
{
AIM*items_by_rule= g->t_AHFA_items_by_rule;
Marpa_Symbol_ID from_symid;
guint*sort_key_by_rule_id= g_new(guint,no_of_rules);
guint no_of_predictable_rules= 0;
/*561:*/
#line 4757 "./marpa.w"

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

/*:561*/
#line 4733 "./marpa.w"

/*562:*/
#line 4777 "./marpa.w"

{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
rule_by_sort_key[rule_id]= RULE_by_ID(g,rule_id);
}
g_qsort_with_data(rule_by_sort_key,(gint)no_of_rules,
sizeof(RULE),cmp_by_rule_sort_key,
(gpointer)sort_key_by_rule_id);
}

/*:562*/
#line 4734 "./marpa.w"

/*565:*/
#line 4807 "./marpa.w"
{
guint sort_key;
for(sort_key= 0;sort_key<no_of_rules;sort_key++){
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}}

/*:565*/
#line 4735 "./marpa.w"

/*566:*/
#line 4814 "./marpa.w"

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

SYM to_symbol= SYM_by_ID(g,to_symid);
GArray*lhs_rules= to_symbol->t_lhs;
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

/*:566*/
#line 4736 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:560*/
#line 4691 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:558*/
#line 4230 "./marpa.w"

/*543:*/
#line 4288 "./marpa.w"
{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFAD);
Marpa_Rule_ID start_rule_id;
AIM start_item;
SYM start_symbol= SYM_by_ID(g,g->t_start_symid);
SYM start_alias
= symbol_null_alias(start_symbol);
gint no_of_items_in_new_state= start_alias?2:1;
AIM*item_list
= obstack_alloc(&g->t_obs,no_of_items_in_new_state*sizeof(AIM));
start_rule_id= g_array_index(start_symbol->t_lhs,Marpa_Rule_ID,0);

start_item= g->t_AHFA_items_by_rule[start_rule_id];

item_list[0]= start_item;
if(start_alias){
Marpa_Rule_ID alias_rule_id
= g_array_index(start_alias->t_lhs,Marpa_Rule_ID,0);


item_list[1]= g->t_AHFA_items_by_rule[alias_rule_id];
}
p_initial_state->t_items= item_list;
p_initial_state->t_item_count= no_of_items_in_new_state;
p_initial_state->t_key.t_id= 0;
LV_AHFA_is_Predicted(p_initial_state)= 0;
LV_Leo_LHS_ID_of_AHFA(p_initial_state)= -1;
p_initial_state->t_to_ahfa_ary= to_ahfa_array_new(g);
p_initial_state->t_empty_transition= NULL;
if(start_symbol->t_is_nulling)
{
p_initial_state->t_complete_symbol_count= 1;
p_initial_state->t_has_completed_start_rule= 1;
p_initial_state->t_complete_symbols= 
obstack_alloc(&g->t_obs,sizeof(SYMID));
*(p_initial_state->t_complete_symbols)= g->t_start_symid;
LV_Postdot_SYM_Count_of_AHFA(p_initial_state)= 0;
}
else
{
SYMID*postdot_symbol_ids;
LV_Postdot_SYM_Count_of_AHFA(p_initial_state)= 1;
postdot_symbol_ids= LV_Postdot_SYMID_Ary_of_AHFA(p_initial_state)= 
obstack_alloc(&g->t_obs,sizeof(SYMID));
*postdot_symbol_ids= Postdot_SYMID_of_AIM(start_item);
if(start_alias)
{
p_initial_state->t_complete_symbol_count= 1;
p_initial_state->t_has_completed_start_rule= 1;
p_initial_state->t_complete_symbols= 
obstack_alloc(&g->t_obs,sizeof(SYMID));
*(p_initial_state->t_complete_symbols)= 
LHS_ID_of_PRD(RULE_by_ID(g,start_rule_id));
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

/*:543*/
#line 4231 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFAD))){
/*540:*/
#line 4245 "./marpa.w"
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
/*545:*/
#line 4386 "./marpa.w"
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
obstack_alloc(&g->t_obs,sizeof(AIM));
new_state_item_list[0]= single_item_p;
p_new_state->t_item_count= 1;
LV_AHFA_is_Predicted(p_new_state)= 0;
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
obstack_alloc(&g->t_obs,sizeof(SYMID));
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
obstack_alloc(&g->t_obs,sizeof(SYMID));
lhs_id= LHS_ID_of_PRD(single_item_p->t_production);
*(p_new_state->t_complete_symbols)= lhs_id;
p_new_state->t_postdot_sym_count= 0;
p_new_state->t_empty_transition= NULL;
/*547:*/
#line 4476 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(g,predot_symid))
> 0)
{
LV_Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:547*/
#line 4444 "./marpa.w"

}
}

/*:545*/
#line 4265 "./marpa.w"

}else{
/*548:*/
#line 4501 "./marpa.w"
{
AHFA p_new_state;
guint predecessor_ix;
guint no_of_new_items_so_far= 0;
AIM*item_list_for_new_state;
AHFA queued_AHFA_state;
p_new_state= DQUEUE_PUSH(states,AHFAD);
item_list_for_new_state= p_new_state->t_items= obstack_alloc(&g->t_obs_tricky,
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
obstack_free(&g->t_obs_tricky,item_list_for_new_state);
AHFA_transition_add(p_working_state,working_symbol,queued_AHFA_state);


goto NEXT_WORKING_SYMBOL;
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFAD);
LV_AHFA_is_Predicted(p_new_state)= 0;
p_new_state->t_has_completed_start_rule= 0;
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
p_new_state->t_to_ahfa_ary= to_ahfa_array_new(g);
/*549:*/
#line 4552 "./marpa.w"

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
obstack_alloc(&g->t_obs,
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
obstack_alloc(&g->t_obs,
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

/*:549*/
#line 4546 "./marpa.w"

AHFA_transition_add(p_working_state,working_symbol,p_new_state);
/*553:*/
#line 4631 "./marpa.w"
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

/*:553*/
#line 4549 "./marpa.w"

}

/*:548*/
#line 4267 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:540*/
#line 4233 "./marpa.w"

}
g->t_AHFA= DQUEUE_BASE(states,AHFAD);

LV_AHFA_Count_of_G(g)= DQUEUE_END(states);
g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*542:*/
#line 4284 "./marpa.w"

g_free(singleton_duplicates);
g_tree_destroy(duplicates);

/*:542*/
#line 4240 "./marpa.w"

}
/*:538*//*552:*/
#line 4620 "./marpa.w"

static inline AHFA
assign_AHFA_state(AHFA sought_state,GTree*duplicates)
{
const AHFA state_found= g_tree_lookup(duplicates,sought_state);
if(state_found)return state_found;
g_tree_insert(duplicates,sought_state,sought_state);
return NULL;
}

/*:552*//*563:*/
#line 4787 "./marpa.w"
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
/*:563*//*568:*/
#line 4863 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
){
AIM*item_list_for_new_state;
AHFA p_new_state;
guint item_list_ix= 0;
guint no_of_items_in_new_state= bv_count(prediction_rule_vector);
if(no_of_items_in_new_state==0)return NULL;
item_list_for_new_state= obstack_alloc(&g->t_obs,
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
g->t_AHFA_items_by_rule[rule->t_id];
}
}
}
p_new_state= DQUEUE_PUSH((*states_p),AHFAD);
p_new_state->t_items= item_list_for_new_state;
p_new_state->t_item_count= no_of_items_in_new_state;
{AHFA queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state){


(void)DQUEUE_POP((*states_p),AHFAD);
obstack_free(&g->t_obs,item_list_for_new_state);
return queued_AHFA_state;
}
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE((*states_p),AHFAD);
LV_AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_has_completed_start_rule= 0;
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
p_new_state->t_empty_transition= NULL;
p_new_state->t_to_ahfa_ary= to_ahfa_array_new(g);
p_new_state->t_complete_symbol_count= 0;
/*569:*/
#line 4918 "./marpa.w"

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
obstack_alloc(&g->t_obs,
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

/*:569*/
#line 4914 "./marpa.w"

return p_new_state;
}

/*:568*//*572:*/
#line 4957 "./marpa.w"
static inline
AHFA*to_ahfa_array_new(struct marpa_g*g){
gint symbol_count= SYM_Count_of_G(g);
gint symid= 0;
AHFA*new_to_ahfa_array= g_malloc(symbol_count*sizeof(AHFA));
while(symid<symbol_count)new_to_ahfa_array[symid++]= NULL;


return new_to_ahfa_array;
}

/*:572*//*573:*/
#line 4968 "./marpa.w"
static inline
void AHFA_transition_add(AHFA from_ahfa,SYMID symid,AHFA to_ahfa)
{
from_ahfa->t_to_ahfa_ary[symid]= to_ahfa;
}
/*:573*//*579:*/
#line 5007 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g)
{RECCE r;
/*1105:*/
#line 9939 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1105*/
#line 5010 "./marpa.w"

r= g_slice_new(struct marpa_r);
r->t_grammar= g;
/*665:*/
#line 5491 "./marpa.w"
obstack_init(&r->t_obs);
/*:665*/
#line 5013 "./marpa.w"

/*586:*/
#line 5048 "./marpa.w"

r->t_id= g_atomic_int_exchange_and_add(&next_recce_id,1);
/*:586*//*593:*/
#line 5085 "./marpa.w"

LV_Phase_of_R(r)= initial_phase;
/*:593*//*597:*/
#line 5100 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;
/*:597*//*605:*/
#line 5135 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:605*//*611:*/
#line 5163 "./marpa.w"
r->t_furthest_earleme= 0;
/*:611*//*615:*/
#line 5181 "./marpa.w"
r->t_sym_workarea= NULL;
/*:615*//*618:*/
#line 5195 "./marpa.w"
r->t_workarea2= NULL;
/*:618*//*621:*/
#line 5218 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:621*//*625:*/
#line 5241 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:625*//*632:*/
#line 5293 "./marpa.w"

r->t_earley_item_tree= g_tree_new(trace_earley_item_cmp);

/*:632*//*642:*/
#line 5356 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:642*//*648:*/
#line 5397 "./marpa.w"
r->t_is_exhausted= 0;
/*:648*//*652:*/
#line 5421 "./marpa.w"

r->t_is_leo_expanding= 0;

/*:652*//*654:*/
#line 5436 "./marpa.w"

r->t_context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:654*//*669:*/
#line 5507 "./marpa.w"

r->t_error= NULL;
r->t_fatal_error= NULL;
/*:669*//*686:*/
#line 5600 "./marpa.w"

r->t_earley_set_count= 0;

/*:686*//*692:*/
#line 5649 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:692*//*725:*/
#line 5975 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:725*//*766:*/
#line 6437 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:766*//*809:*/
#line 6932 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:809*//*849:*/
#line 7381 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:849*//*877:*/
#line 7685 "./marpa.w"
DSTACK_ZERO_INIT(r->t_eim_work_stack);
/*:877*//*881:*/
#line 7697 "./marpa.w"
DSTACK_ZERO_INIT(r->t_completion_stack);
/*:881*//*885:*/
#line 7709 "./marpa.w"
DSTACK_ZERO_INIT(r->t_earley_set_stack);
/*:885*//*1070:*/
#line 9645 "./marpa.w"

psar_init(r,Dot_PSAR_of_R(r));
/*:1070*//*1142:*/
#line 10210 "./marpa.w"

r->t_message_callback_arg= NULL;
r->t_message_callback= NULL;
/*:1142*/
#line 5014 "./marpa.w"

if(!G_is_Precomputed(g)){
R_ERROR("grammar not precomputed");
return failure_indicator;
}
return r;}

/*:579*//*580:*/
#line 5021 "./marpa.w"

void marpa_r_free(struct marpa_r*r)
{
/*598:*/
#line 5104 "./marpa.w"

{
if(r->t_earley_item_tree)
g_tree_destroy(r->t_earley_item_tree);
}

/*:598*//*655:*/
#line 5438 "./marpa.w"
g_hash_table_destroy(Context_of_R(r));

/*:655*//*689:*/
#line 5626 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
if(EIMs_of_ES(set))
g_free(EIMs_of_ES(set));
}
}

/*:689*//*850:*/
#line 7383 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:850*//*879:*/
#line 7690 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:879*//*883:*/
#line 7702 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:883*//*886:*/
#line 7710 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:886*//*1071:*/
#line 9647 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1071*/
#line 5024 "./marpa.w"

if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*623:*/
#line 5227 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:623*//*627:*/
#line 5244 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:627*/
#line 5027 "./marpa.w"

/*666:*/
#line 5492 "./marpa.w"
obstack_free(&r->t_obs,NULL);

/*:666*/
#line 5028 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:580*//*587:*/
#line 5050 "./marpa.w"

gint marpa_r_id(struct marpa_r*r){return r->t_id;}
/*:587*//*595:*/
#line 5089 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r)
{return Phase_of_R(r);}

/*:595*//*601:*/
#line 5117 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:601*//*603:*/
#line 5124 "./marpa.w"

static inline ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:603*//*607:*/
#line 5139 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:607*//*609:*/
#line 5147 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold)
{
r->t_earley_item_warning_threshold= threshold==0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:609*//*613:*/
#line 5166 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:613*//*629:*/
#line 5256 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 5259 "./marpa.w"

guint min,max,start;
/*1122:*/
#line 10044 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
r_context_clear(r);
r_context_int_add(r,"expected size",sizeof(gint));
R_ERROR_CXT("garray size mismatch");
return failure_indicator;
}
/*:1122*/
#line 5261 "./marpa.w"

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

/*:629*//*644:*/
#line 5364 "./marpa.w"

gint marpa_is_use_leo(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 5367 "./marpa.w"

/*1120:*/
#line 10032 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1120*/
#line 5368 "./marpa.w"

return r->t_use_leo_flag?1:0;
}
/*:644*//*645:*/
#line 5373 "./marpa.w"

gboolean marpa_is_use_leo_set(
struct marpa_r*r,gboolean value)
{
/*1104:*/
#line 9937 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1104*/
#line 5377 "./marpa.w"

/*1120:*/
#line 10032 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1120*/
#line 5378 "./marpa.w"

r->t_use_leo_flag= value;
return TRUE;
}
/*:645*//*650:*/
#line 5403 "./marpa.w"

gint marpa_is_exhausted(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 5406 "./marpa.w"

/*1120:*/
#line 10032 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1120*/
#line 5407 "./marpa.w"

return r->t_is_exhausted?1:0;
}

/*:650*//*656:*/
#line 5447 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->t_type= MARPA_CONTEXT_INT;
value->t_data= payload;
g_hash_table_insert(Context_of_R(r),(gpointer)key,value);
}
/*:656*//*658:*/
#line 5459 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->t_type= MARPA_CONTEXT_CONST;
value->t_data= payload;
g_hash_table_insert(Context_of_R(r),(gpointer)key,value);
}
/*:658*//*660:*/
#line 5474 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r){
g_hash_table_remove_all(Context_of_R(r));}
/*:660*//*662:*/
#line 5480 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key)
{return g_hash_table_lookup(Context_of_R(r),key);}
/*:662*//*671:*/
#line 5516 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r)
{return r->t_error?r->t_error:"unknown error";}
/*:671*//*688:*/
#line 5606 "./marpa.w"

static inline ES
earley_set_new(RECCE r,EARLEME id)
{
ESK_Object key;
ES set;
set= obstack_alloc(&r->t_obs,sizeof(*set));
key.t_earleme= id;
set->t_key= key;
set->t_postdot_ary= NULL;
set->t_postdot_sym_count= 0;
LV_EIM_Count_of_ES(set)= 0;
set->t_ordinal= r->t_earley_set_count++;
LV_EIMs_of_ES(set)= NULL;
LV_Next_ES_of_ES(set)= NULL;
/*1077:*/
#line 9690 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1077*/
#line 5621 "./marpa.w"

return set;
}

/*:688*//*694:*/
#line 5654 "./marpa.w"

Marpa_Earleme marpa_trace_earleme(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 5657 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1116:*/
#line 10008 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1116*/
#line 5659 "./marpa.w"

if(!trace_earley_set){
R_ERROR("no trace es");
return failure_indicator;
}
return Earleme_of_ES(trace_earley_set);
}

/*:694*//*696:*/
#line 5677 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const gint es_does_not_exist= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 5681 "./marpa.w"

ES*earley_set_p;
/*1116:*/
#line 10008 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1116*/
#line 5683 "./marpa.w"

/*1120:*/
#line 10032 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1120*/
#line 5684 "./marpa.w"

if(set_id<0){
R_ERROR("invalid es ordinal");
return failure_indicator;
}
r_update_earley_sets(r);
if(set_id>=DSTACK_LENGTH(r->t_earley_set_stack)){
return es_does_not_exist;
}
earley_set_p= P_ES_of_R_by_Ord(r,set_id);
return Earleme_of_ES(*earley_set_p);
}

/*:696*//*699:*/
#line 5703 "./marpa.w"

gint marpa_current_earley_set_size(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 5706 "./marpa.w"

/*1116:*/
#line 10008 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1116*/
#line 5707 "./marpa.w"

/*1120:*/
#line 10032 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1120*/
#line 5708 "./marpa.w"

return EIM_Count_of_ES(Current_ES_of_R(r));
}

/*:699*//*709:*/
#line 5795 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1105:*/
#line 9939 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1105*/
#line 5799 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const guint count= ++LV_EIM_Count_of_ES(set);
/*714:*/
#line 5869 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
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

/*:714*/
#line 5804 "./marpa.w"

new_item= obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
LV_Ord_of_EIM(new_item)= count-1;
LV_EIM_is_Leo_Expanded(new_item)= 1;

top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
g_tree_insert(r->t_earley_item_tree,new_item,new_item);
return new_item;
}

/*:709*//*711:*/
#line 5820 "./marpa.w"

static inline EIM old_earley_item_assign(
const RECCE r,const ES set,const ES origin,const AHFA state)
{
EIM item;
EIK_Object key;
key.t_origin= origin;
key.t_state= state;
key.t_set= set;
item= g_tree_lookup(r->t_earley_item_tree,&key);
if(item)return item;
return earley_item_create(r,key);
}

/*:711*//*713:*/
#line 5837 "./marpa.w"

static inline EIM
earley_item_assign(const RECCE r,const ES set,const ES origin,
const AHFA state)
{
EIK_Object key;
EIM eim;
PSL psl;
AHFAID ahfa_id= ID_of_AHFA(state);
PSL*psl_owner= &Dot_PSL_of_ES(origin);
if(!*psl_owner)
{
psl_claim(psl_owner,Dot_PSAR_of_R(r));
}
psl= *psl_owner;
eim= PSL_Datum(psl,ahfa_id);
if(eim
&&Earleme_of_EIM(eim)==Earleme_of_ES(set)
&&Earleme_of_ES(Origin_of_EIM(eim))==Earleme_of_ES(origin))
{
return eim;
}
key.t_origin= origin;
key.t_state= state;
key.t_set= set;
eim= earley_item_create(r,key);
LV_PSL_Datum(psl,ahfa_id)= eim;
return eim;
}

/*:713*//*717:*/
#line 5895 "./marpa.w"

static inline gint trace_earley_item_cmp(gconstpointer ap,gconstpointer bp)
{
const EIM_Object*eim_a= ap;
const EIM_Object*eim_b= bp;
gint subkey= Earleme_of_EIM(eim_a)-Earleme_of_EIM(eim_b);
if(subkey)return subkey;
return earley_item_cmp(ap,bp,0);
}
/*:717*//*719:*/
#line 5908 "./marpa.w"

static inline gint earley_item_cmp(gconstpointer ap,
gconstpointer bp,gpointer user_data G_GNUC_UNUSED)
{
const struct s_earley_item*eim_a= ap;
const struct s_earley_item*eim_b= bp;
gint subkey= 
AHFAID_of_EIM(eim_a)-
AHFAID_of_EIM(eim_b);
if(subkey)return subkey;
return Origin_Earleme_of_EIM(eim_a)-Origin_Earleme_of_EIM(eim_b);
}

/*:719*//*723:*/
#line 5951 "./marpa.w"

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

/*:723*//*729:*/
#line 5998 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id)
{
const gint no_match= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6005 "./marpa.w"

ES current_set= r->t_trace_earley_set;
ES origin_set;
EIM item;
EIK_Object item_key;
GRAMMAR_Const g= G_of_R(r);
/*1116:*/
#line 10008 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1116*/
#line 6011 "./marpa.w"

trace_source_link_clear(r);
if(!current_set){
/*737:*/
#line 6148 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:737*/
#line 6014 "./marpa.w"

R_ERROR("no trace es");
return failure_indicator;
}
if(origin_set_id<0){
R_ERROR("invalid es ordinal");
return failure_indicator;
}
r_update_earley_sets(r);
if(origin_set_id>=DSTACK_LENGTH(r->t_earley_set_stack)){
R_ERROR("origin es does not exist");
return failure_indicator;
}
origin_set= ES_of_R_by_Ord(r,origin_set_id);
if(!origin_set){
/*737:*/
#line 6148 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:737*/
#line 6029 "./marpa.w"

R_ERROR("origin es not found");
return failure_indicator;
}
item_key.t_state= AHFA_by_ID(state_id);
item_key.t_origin= origin_set;
item_key.t_set= current_set;
item= r->t_trace_earley_item= g_tree_lookup(r->t_earley_item_tree,&item_key);
if(!item){
/*737:*/
#line 6148 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:737*/
#line 6038 "./marpa.w"

return no_match;
}
return AHFAID_of_EIM(item);
}

/*:729*//*733:*/
#line 6069 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const gint es_does_not_exist= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6075 "./marpa.w"

/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6076 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*734:*/
#line 6099 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*769:*/
#line 6479 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:769*/
#line 6102 "./marpa.w"

}

/*:734*/
#line 6083 "./marpa.w"

if(set_id<0)
{
R_ERROR("invalid es ordinal");
return failure_indicator;
}
r_update_earley_sets(r);
if(set_id>=DSTACK_LENGTH(r->t_earley_set_stack))
{
return es_does_not_exist;
}
earley_set= ES_of_R_by_Ord(r,set_id);
r->t_trace_earley_set= earley_set;
return Earleme_of_ES(earley_set);
}

/*:733*//*736:*/
#line 6109 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const gint eim_does_not_exist= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6114 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6118 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*734:*/
#line 6099 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*769:*/
#line 6479 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:769*/
#line 6102 "./marpa.w"

}

/*:734*/
#line 6122 "./marpa.w"

R_ERROR("no trace es");
return failure_indicator;
}
trace_earley_item_clear(r);
if(item_id<0)
{
R_ERROR("invalid eim ordinal");
return failure_indicator;
}
if(item_id>=EIM_Count_of_ES(trace_earley_set))
{
return eim_does_not_exist;
}
earley_items= EIMs_of_ES(trace_earley_set);
earley_item= earley_items[item_id];
r->t_trace_earley_item= earley_item;
return AHFAID_of_EIM(earley_item);
}

/*:736*//*739:*/
#line 6153 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r)
{
/*737:*/
#line 6148 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:737*/
#line 6156 "./marpa.w"

trace_source_link_clear(r);
}

/*:739*//*741:*/
#line 6162 "./marpa.w"

Marpa_Earleme marpa_earley_item_origin(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6165 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1116:*/
#line 10008 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1116*/
#line 6167 "./marpa.w"

if(!item){
/*737:*/
#line 6148 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:737*/
#line 6169 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return Origin_Earleme_of_EIM(item);
}

/*:741*//*749:*/
#line 6255 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6259 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6262 "./marpa.w"

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
/*:749*//*750:*/
#line 6277 "./marpa.w"

Marpa_Earleme marpa_leo_base_origin(struct marpa_r*r)
{
const Marpa_Earleme pim_is_not_a_leo_item= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6281 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6284 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Earleme_of_EIM(base_earley_item);
}

/*:750*//*752:*/
#line 6296 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r)
{
const Marpa_Earleme pim_is_not_a_leo_item= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6300 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6303 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:752*//*757:*/
#line 6339 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r)
{
const Marpa_Earleme pim_is_not_a_leo_item= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6343 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6345 "./marpa.w"

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


/*:757*//*762:*/
#line 6399 "./marpa.w"

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
/*:762*//*764:*/
#line 6421 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:764*//*768:*/
#line 6455 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6460 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*769:*/
#line 6479 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:769*/
#line 6464 "./marpa.w"

/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6465 "./marpa.w"

/*1121:*/
#line 10037 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
r_context_clear(r);
r_context_int_add(r,"symid",symid);
R_ERROR_CXT("invalid symid");
return failure_indicator;
}
/*:1121*/
#line 6466 "./marpa.w"

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

/*:768*//*771:*/
#line 6492 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6496 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*769:*/
#line 6479 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:769*/
#line 6500 "./marpa.w"

/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6501 "./marpa.w"

if(!current_earley_set){
/*737:*/
#line 6148 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:737*/
#line 6503 "./marpa.w"

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

/*:771*//*773:*/
#line 6525 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6530 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;

pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*769:*/
#line 6479 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:769*/
#line 6537 "./marpa.w"

if(!pim_sym_p||!pim){
R_ERROR("no trace pim");
return failure_indicator;
}
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6542 "./marpa.w"

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

/*:773*//*775:*/
#line 6564 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6567 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6569 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:775*//*791:*/
#line 6701 "./marpa.w"
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
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Token_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
new_link->t_source.t_cause= value;
new_link->t_source.t_symbol_id= token_id;
LV_First_Token_Link_of_EIM(item)= new_link;
}
/*:791*//*798:*/
#line 6791 "./marpa.w"
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
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Completion_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
new_link->t_source.t_cause= cause;
new_link->t_source.t_symbol_id= -1;
LV_First_Completion_Link_of_EIM(item)= new_link;
}

/*:798*//*799:*/
#line 6820 "./marpa.w"
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
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Leo_SRCL_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
new_link->t_source.t_cause= cause;
new_link->t_source.t_symbol_id= -1;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
}
/*:799*//*802:*/
#line 6875 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
unsigned int previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*804:*/
#line 6893 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= new_link;
}

/*:804*/
#line 6882 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*805:*/
#line 6902 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= new_link;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:805*/
#line 6884 "./marpa.w"

return;
case SOURCE_IS_LEO:/*806:*/
#line 6911 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:806*/
#line 6886 "./marpa.w"

return;
}
}
/*:802*//*812:*/
#line 6945 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6948 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6952 "./marpa.w"

/*831:*/
#line 7176 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:831*/
#line 6953 "./marpa.w"

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

/*:812*//*816:*/
#line 6990 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 6993 "./marpa.w"

SRCL full_link;
EIM item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 6996 "./marpa.w"

/*831:*/
#line 7176 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:831*/
#line 6997 "./marpa.w"

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

/*:816*//*819:*/
#line 7022 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 7025 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 7029 "./marpa.w"

/*831:*/
#line 7176 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:831*/
#line 7030 "./marpa.w"

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

/*:819*//*823:*/
#line 7066 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 7069 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 7073 "./marpa.w"

/*831:*/
#line 7176 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:831*/
#line 7074 "./marpa.w"

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

/*:823*//*826:*/
#line 7100 "./marpa.w"

Marpa_Symbol_ID
marpa_first_leo_link_trace(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 7104 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 7108 "./marpa.w"

/*831:*/
#line 7176 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:831*/
#line 7109 "./marpa.w"

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

/*:826*//*830:*/
#line 7147 "./marpa.w"

Marpa_Symbol_ID
marpa_next_leo_link_trace(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 7151 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 7155 "./marpa.w"

/*831:*/
#line 7176 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:831*/
#line 7156 "./marpa.w"

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

/*:830*//*834:*/
#line 7187 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r){
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:834*//*836:*/
#line 7204 "./marpa.w"

AHFAID marpa_source_predecessor_state(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 7207 "./marpa.w"

guint source_type;
SRC source;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 7210 "./marpa.w"

source_type= r->t_trace_source_type;
/*845:*/
#line 7346 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:845*/
#line 7212 "./marpa.w"

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

/*:836*//*839:*/
#line 7241 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 7244 "./marpa.w"

guint source_type;
SRC source;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 7247 "./marpa.w"

source_type= r->t_trace_source_type;
/*845:*/
#line 7346 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:845*/
#line 7249 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_Symbol_ID_of_SRC(source);
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:839*//*842:*/
#line 7288 "./marpa.w"

Marpa_Earleme marpa_source_middle(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 7291 "./marpa.w"

const Marpa_Earleme no_predecessor= -1;
guint source_type;
SRC source;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 7295 "./marpa.w"

source_type= r->t_trace_source_type;
/*845:*/
#line 7346 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:845*/
#line 7297 "./marpa.w"

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

/*:842*//*844:*/
#line 7329 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p)
{
/*1104:*/
#line 9937 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1104*/
#line 7332 "./marpa.w"

guint source_type;
SRC source;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 7335 "./marpa.w"

source_type= r->t_trace_source_type;
/*845:*/
#line 7346 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:845*/
#line 7337 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
*value_p= Token_Value_of_SRC(source);
return TRUE;
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:844*//*852:*/
#line 7391 "./marpa.w"

static inline gint
alternative_insertion_point(RECCE r,ALT new_alternative)
{
DSTACK alternatives= &r->t_alternatives;
ALT alternative;
gint hi= DSTACK_LENGTH(*alternatives)-1;
gint lo= 0;
gint trial;

if(hi<0)
return 0;
alternative= DSTACK_BASE(*alternatives,ALT_Object);
for(;;)
{
gint outcome;
trial= lo+(hi-lo)/2;
outcome= alternative_cmp(new_alternative,alternative+trial);
if(outcome==0)
return-1;
if(outcome> 0)
{
lo= trial+1;
}
else
{
hi= trial-1;
}
if(hi<lo)
return outcome> 0?trial+1:trial;
}
}

/*:852*//*854:*/
#line 7428 "./marpa.w"

static inline void alternative_set(
ALT alternative,ES start,EARLEME end,SYMID token_id,gpointer value)
{
alternative->t_token_id= token_id;
alternative->t_token_value= value;
alternative->t_start_earley_set= start;
alternative->t_end_earleme= end;
}

/*:854*//*856:*/
#line 7451 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b){
gint subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= Token_ID_of_ALT(a)-Token_ID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:856*//*858:*/
#line 7469 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:858*//*860:*/
#line 7486 "./marpa.w"

static inline gint alternative_insert(RECCE r,ALT new_alternative)
{
ALT top_of_stack,base_of_stack;
DSTACK alternatives= &r->t_alternatives;
gint ix;
gint insertion_point= alternative_insertion_point(r,new_alternative);
if(insertion_point<0)
return insertion_point;
top_of_stack= DSTACK_PUSH(*alternatives,ALT_Object);
base_of_stack= DSTACK_BASE(*alternatives,ALT_Object);
for(ix= top_of_stack-base_of_stack;ix> insertion_point;ix--){
base_of_stack[ix]= base_of_stack[ix-1];
}
base_of_stack[insertion_point]= *new_alternative;
return insertion_point;
}

/*:860*//*863:*/
#line 7506 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
GRAMMAR_Const g= G_of_R(r);
const gint symbol_count_of_g= SYM_Count_of_G(g);
/*1104:*/
#line 9937 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1104*/
#line 7514 "./marpa.w"

/*1115:*/
#line 10003 "./marpa.w"

if(Phase_of_R(r)!=initial_phase){
R_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1115*/
#line 7515 "./marpa.w"

/*619:*/
#line 5196 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*616:*/
#line 5182 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:616*/
#line 5199 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:619*/
#line 7516 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*622:*/
#line 5222 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:622*//*626:*/
#line 5242 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:626*/
#line 7518 "./marpa.w"

/*878:*/
#line 7686 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT(r->t_eim_work_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:878*//*882:*/
#line 7698 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT(r->t_completion_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:882*/
#line 7519 "./marpa.w"

LV_Phase_of_R(r)= input_phase;
LV_Current_Earleme_of_R(r)= 0;
set0= earley_set_new(r,0);
LV_Latest_ES_of_R(r)= set0;
LV_First_ES_of_R(r)= set0;
state= AHFA_by_ID(0);
key.t_origin= set0;
key.t_state= state;
key.t_set= set0;
item= earley_item_create(r,key);
state= Empty_Transition_of_AHFA(state);
if(state){
key.t_state= state;
item= earley_item_create(r,key);
}
postdot_items_create(r,set0);
earley_set_update_items(r,set0);
r->t_is_using_leo= r->t_use_leo_flag;
return TRUE;
}

/*:863*//*871:*/
#line 7591 "./marpa.w"

gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*token_value,gint length){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 7594 "./marpa.w"

const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1118:*/
#line 10018 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_ERROR("recce not in input phase");
return failure_indicator;
}
/*:1118*/
#line 7600 "./marpa.w"

/*1117:*/
#line 10013 "./marpa.w"

if(R_is_Exhausted(r)){
R_ERROR("recce exhausted");
return failure_indicator;
}
/*:1117*/
#line 7601 "./marpa.w"

/*872:*/
#line 7609 "./marpa.w"
{
const SYM_Const token= SYM_by_ID(G_of_R(r),token_id);
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
}

/*:872*/
#line 7602 "./marpa.w"

/*874:*/
#line 7642 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:874*/
#line 7603 "./marpa.w"

/*873:*/
#line 7625 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
r_context_clear(r);
r_context_int_add(r,"target_earleme",target_earleme);
R_ERROR_CXT("parse too long");
return failure_indicator;
}
}

/*:873*/
#line 7604 "./marpa.w"

/*875:*/
#line 7665 "./marpa.w"

{
ALT_Object alternative;
if(Furthest_Earleme_of_R(r)<target_earleme)
LV_Furthest_Earleme_of_R(r)= target_earleme;
alternative_set(&alternative,
current_earley_set,target_earleme,token_id,token_value);
if(alternative_insert(r,&alternative)<0)
return duplicate_token_indicator;
}

/*:875*/
#line 7605 "./marpa.w"

return current_earleme;
}

/*:871*//*889:*/
#line 7731 "./marpa.w"

Marpa_Earleme
marpa_earleme_complete(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 7735 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
gint count_of_expected_terminals;
bv_clear(r->t_bv_symid_is_expected);
/*890:*/
#line 7764 "./marpa.w"
{
current_earleme= ++(LV_Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
LV_R_is_Exhausted(r)= 1;
R_ERROR("parse exhausted");
return failure_indicator;
}
}

/*:890*/
#line 7741 "./marpa.w"

/*892:*/
#line 7789 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:892*/
#line 7742 "./marpa.w"

/*891:*/
#line 7776 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
LV_Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
LV_Latest_ES_of_R(r)= current_earley_set;
}

/*:891*/
#line 7743 "./marpa.w"

/*893:*/
#line 7795 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*894:*/
#line 7802 "./marpa.w"

{
ES start_earley_set= Start_ES_of_ALT(alternative);
SYMID token_id= Token_ID_of_ALT(alternative);
PIM pim= First_PIM_of_ES_by_SYMID(start_earley_set,token_id);
for(;pim;pim= Next_PIM_of_PIM(pim)){
AHFA scanned_AHFA,prediction_AHFA;
EIM scanned_earley_item;
EIM predecessor= EIM_of_PIM(pim);
if(!predecessor)
continue;
scanned_AHFA= To_AHFA_of_EIM_by_SYMID(predecessor,token_id);
scanned_earley_item= earley_item_assign(r,
current_earley_set,
Origin_of_EIM(predecessor),
scanned_AHFA);
token_link_add(r,scanned_earley_item,predecessor,token_id,
Token_Value_of_ALT(alternative));
prediction_AHFA= Empty_Transition_of_AHFA(scanned_AHFA);
if(!prediction_AHFA)continue;
scanned_earley_item= earley_item_assign(r,
current_earley_set,
current_earley_set,
prediction_AHFA);
}
}

/*:894*/
#line 7799 "./marpa.w"

}

/*:893*/
#line 7744 "./marpa.w"

/*895:*/
#line 7829 "./marpa.w"
{
EIM*work_earley_items= DSTACK_BASE(r->t_eim_work_stack,EIM);
gint no_of_work_earley_items= DSTACK_LENGTH(r->t_eim_work_stack);
gint ix;
DSTACK_CLEAR(r->t_completion_stack);
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
EIM earley_item= work_earley_items[ix];
EIM*tos;
if(!Earley_Item_is_Completion(earley_item))
continue;
tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= earley_item;
}
}

/*:895*/
#line 7745 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*896:*/
#line 7848 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDARY_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*897:*/
#line 7861 "./marpa.w"

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
/*898:*/
#line 7884 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*899:*/
#line 7900 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:899*/
#line 7893 "./marpa.w"

}
/*900:*/
#line 7907 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:900*/
#line 7895 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:898*/
#line 7872 "./marpa.w"

}
else
{
/*901:*/
#line 7917 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*899:*/
#line 7900 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:899*/
#line 7926 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:901*/
#line 7876 "./marpa.w"

break;


}
}
}

/*:897*/
#line 7857 "./marpa.w"

}
}

/*:896*/
#line 7748 "./marpa.w"

}
postdot_items_create(r,current_earley_set);

count_of_expected_terminals= bv_count(r->t_bv_symid_is_expected);
if(count_of_expected_terminals<=0
&&Earleme_of_ES(current_earley_set)>=Furthest_Earleme_of_R(r))
{


LV_R_is_Exhausted(r)= 1;
}
earley_set_update_items(r,current_earley_set);
return count_of_expected_terminals;
}

/*:889*//*903:*/
#line 7933 "./marpa.w"

static inline void earley_set_update_items(RECCE r,ES set){
EIM*working_earley_items;
EIM*finished_earley_items;
gint working_earley_item_count;
gint i;
if(!EIMs_of_ES(set)){
EIMs_of_ES(set)= g_new(EIM,EIM_Count_of_ES(set));
}else{
EIMs_of_ES(set)= g_renew(EIM,EIMs_of_ES(set),EIM_Count_of_ES(set));
}
finished_earley_items= EIMs_of_ES(set);
working_earley_items= Work_EIMs_of_R(r);
working_earley_item_count= Work_EIM_Count_of_R(r);
for(i= 0;i<working_earley_item_count;i++){
EIM earley_item= working_earley_items[i];
gint ordinal= Ord_of_EIM(earley_item);
finished_earley_items[ordinal]= earley_item;
}
WORK_EIMS_CLEAR(r);
}

/*:903*//*905:*/
#line 7959 "./marpa.w"

static inline void r_update_earley_sets(RECCE r){
ES set;
ES first_unstacked_earley_set;
if(!DSTACK_IS_INITIALIZED(r->t_earley_set_stack)){
first_unstacked_earley_set= First_ES_of_R(r);
DSTACK_INIT(r->t_earley_set_stack,ES,
MAX(1024,ES_Count_of_R(r)));
}else{
ES*top_of_stack= DSTACK_TOP(r->t_earley_set_stack,ES);
first_unstacked_earley_set= Next_ES_of_ES(*top_of_stack);
}
for(set= first_unstacked_earley_set;set;set= Next_ES_of_ES(set)){
ES*top_of_stack= DSTACK_PUSH(r->t_earley_set_stack,ES);
(*top_of_stack)= set;
}
}

/*:905*//*909:*/
#line 7997 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES current_earley_set)
{
gpointer*const pim_workarea= r->t_sym_workarea;
GRAMMAR_Const g= G_of_R(r);
Marpa_Earleme current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*910:*/
#line 8019 "./marpa.w"
{
EIM*work_earley_items= DSTACK_BASE(r->t_eim_work_stack,EIM);
gint no_of_work_earley_items= DSTACK_LENGTH(r->t_eim_work_stack);
gint ix;
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
EIM earley_item= work_earley_items[ix];
AHFA state= AHFA_of_EIM(earley_item);
gint symbol_ix;
gint postdot_symbol_count= Postdot_SYM_Count_of_AHFA(state);
Marpa_Symbol_ID*postdot_symbols= 
Postdot_SYMID_Ary_of_AHFA(state);
for(symbol_ix= 0;symbol_ix<postdot_symbol_count;symbol_ix++)
{
PIM old_pim= NULL;
PIM new_pim;
Marpa_Symbol_ID symid;
new_pim= obstack_alloc(&r->t_obs,sizeof(EIX_Object));
symid= postdot_symbols[symbol_ix];
LV_Postdot_SYMID_of_PIM(new_pim)= symid;
LV_EIM_of_PIM(new_pim)= earley_item;
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
}

/*:910*/
#line 8008 "./marpa.w"

if(r->t_is_using_leo){
/*912:*/
#line 8065 "./marpa.w"
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
/*913:*/
#line 8090 "./marpa.w"
{
LIM new_lim;
new_lim= obstack_alloc(&r->t_obs,sizeof(*new_lim));
LV_Postdot_SYMID_of_LIM(new_lim)= symid;
LV_EIM_of_PIM(new_lim)= NULL;
LV_Predecessor_LIM_of_LIM(new_lim)= NULL;
LV_Origin_of_LIM(new_lim)= NULL;
LV_Chain_Length_of_LIM(new_lim)= -1;
LV_Top_AHFA_of_LIM(new_lim)= base_to_ahfa;
LV_Base_EIM_of_LIM(new_lim)= leo_base;
LV_ES_of_LIM(new_lim)= current_earley_set;
LV_Next_PIM_of_LIM(new_lim)= this_pim;
pim_workarea[symid]= new_lim;
bv_bit_set(bv_lim_symbols,(guint)symid);
}

/*:913*/
#line 8079 "./marpa.w"

}
}
}

/*:912*/
#line 8010 "./marpa.w"

/*922:*/
#line 8175 "./marpa.w"
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

/*925:*/
#line 8234 "./marpa.w"
{
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
const ES predecessor_set= Origin_of_EIM(base_eim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const SYMID predecessor_transition_symbol= Leo_LHS_ID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Earleme_of_ES(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_ES_by_SYMID(predecessor_set,predecessor_transition_symbol);
}else{
predecessor_pim= pim_workarea[predecessor_transition_symbol];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:925*/
#line 8193 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*931:*/
#line 8326 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:931*/
#line 8195 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*933:*/
#line 8347 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
LV_Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:933*/
#line 8201 "./marpa.w"

continue;
}
/*926:*/
#line 8249 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*929:*/
#line 8270 "./marpa.w"
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

/*925:*/
#line 8234 "./marpa.w"
{
const EIM base_eim= Base_EIM_of_LIM(lim_to_process);
const ES predecessor_set= Origin_of_EIM(base_eim);
const AHFA base_to_ahfa= Top_AHFA_of_LIM(lim_to_process);
const SYMID predecessor_transition_symbol= Leo_LHS_ID_of_AHFA(base_to_ahfa);
PIM predecessor_pim;
if(Earleme_of_ES(predecessor_set)<current_earley_set_id){
predecessor_pim
= First_PIM_of_ES_by_SYMID(predecessor_set,predecessor_transition_symbol);
}else{
predecessor_pim= pim_workarea[predecessor_transition_symbol];
}
predecessor_lim= PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:925*/
#line 8296 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:929*/
#line 8252 "./marpa.w"

/*930:*/
#line 8315 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*931:*/
#line 8326 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:931*/
#line 8319 "./marpa.w"

}else{
/*933:*/
#line 8347 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
LV_Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:933*/
#line 8321 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:930*/
#line 8253 "./marpa.w"

}

/*:926*/
#line 8204 "./marpa.w"

}
}
}

/*:922*/
#line 8011 "./marpa.w"

}
/*934:*/
#line 8353 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= obstack_alloc(&r->t_obs,
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

/*:934*/
#line 8013 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:909*//*938:*/
#line 8409 "./marpa.w"

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
/*939:*/
#line 8456 "./marpa.w"
{
this_lim= Predecessor_of_SRCL(leo_link);
previous_eim_on_this_path= Cause_of_SRCL(leo_link);
leo_path_lengths+= 2;

}

/*:939*/
#line 8424 "./marpa.w"

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
/*940:*/
#line 8463 "./marpa.w"
{
LIM next_lim;
while((next_lim= Predecessor_LIM_of_LIM(this_lim))){
/*941:*/
#line 8477 "./marpa.w"

{
const EIM base_eim_of_this_lim= Base_EIM_of_LIM(this_lim);
const SYMID postdot_symbol_of_this_lim= Postdot_SYMID_of_LIM(this_lim);
EIM new_eim_for_this_path= 
old_earley_item_assign(r,earley_set_of_this_path,
ES_of_LIM(next_lim),
To_AHFA_of_EIM_by_SYMID(base_eim_of_this_lim,
postdot_symbol_of_this_lim));
leo_path_lengths++;
completion_link_add(r,new_eim_for_this_path,
base_eim_of_this_lim,
previous_eim_on_this_path);
previous_eim_on_this_path= new_eim_for_this_path;
}

/*:941*/
#line 8466 "./marpa.w"

this_lim= next_lim;
}
completion_link_add(r,leo_completion,Base_EIM_of_LIM(this_lim),previous_eim_on_this_path);



}

/*:940*/
#line 8441 "./marpa.w"

if(!next_leo_link)break;
{
const SRCL leo_link= next_leo_link;
next_leo_link= Next_SRCL_of_SRCL(leo_link);
/*939:*/
#line 8456 "./marpa.w"
{
this_lim= Predecessor_of_SRCL(leo_link);
previous_eim_on_this_path= Cause_of_SRCL(leo_link);
leo_path_lengths+= 2;

}

/*:939*/
#line 8446 "./marpa.w"

}
}
earley_set_update_items(r,earley_set_of_this_path);
r->t_is_leo_expanding= 0;


return leo_path_lengths;
}

/*:938*//*945:*/
#line 8509 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r)
{
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 8512 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1119:*/
#line 10023 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1119*/
#line 8514 "./marpa.w"

if(!item){
/*737:*/
#line 6148 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:737*/
#line 8516 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return leo_completion_expand(r,item);
}

/*:945*//*964:*/
#line 8663 "./marpa.w"

gint marpa_eval_setup(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal){
const gint no_parse= -1;
/*965:*/
#line 8681 "./marpa.w"

/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 8682 "./marpa.w"

const GRAMMAR_Const g= G_of_R(r);
ES end_of_parse_es;
RULE completed_start_rule;
EIM start_eim= NULL;
struct s_per_es_data{
Bit_Vector was_earley_item_stacked;
};
struct s_per_es_data*per_es_data= NULL;
struct obstack bocage_setup_obs;

/*:965*/
#line 8666 "./marpa.w"

r_update_earley_sets(r);
obstack_init(&bocage_setup_obs);
/*966:*/
#line 8694 "./marpa.w"

{
EARLEME end_of_parse_earleme;
/*1120:*/
#line 10032 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1120*/
#line 8697 "./marpa.w"

switch(Phase_of_R(r))
{
default:
R_ERROR("recce not evaluation-ready");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

if(ordinal==-1)
{
end_of_parse_es= Current_ES_of_R(r);
}
else
{
if(!ES_Ord_is_Valid(r,ordinal))
{
R_ERROR("invalid es ordinal");
return failure_indicator;
}
end_of_parse_es= ES_of_R_by_Ord(r,ordinal);
}

if(!end_of_parse_es)
return no_parse;
end_of_parse_earleme= Earleme_of_ES(end_of_parse_es);
if(rule_id==-1){
completed_start_rule= 
end_of_parse_earleme?g->t_proper_start_rule:g->t_null_start_rule;
if(!completed_start_rule)
return no_parse;
}else{
if(!RULEID_of_G_is_Valid(g,rule_id))
{
R_ERROR("invalid rule id");
return failure_indicator;
}
completed_start_rule= RULE_by_ID(g,rule_id);
}
}

/*:966*/
#line 8670 "./marpa.w"

/*972:*/
#line 8790 "./marpa.w"

{
gint eim_ix;
EIM*const earley_items= EIMs_of_ES(end_of_parse_es);
const RULEID sought_rule_id= ID_of_RULE(completed_start_rule);
const gint earley_item_count= EIM_Count_of_ES(end_of_parse_es);
for(eim_ix= 0;eim_ix<earley_item_count;eim_ix++){
const EIM earley_item= earley_items[eim_ix];
const AHFA ahfa_state= AHFA_of_EIM(earley_item);
if(Origin_Earleme_of_EIM(earley_item)> 0)continue;
if(!AHFA_is_Predicted(ahfa_state)){
gint aim_ix;
AIM*const ahfa_items= AIMs_of_AHFA(ahfa_state);
const gint ahfa_item_count= AIM_Count_of_AHFA(ahfa_state);
for(aim_ix= 0;aim_ix<ahfa_item_count;aim_ix++){
const AIM ahfa_item= ahfa_items[aim_ix];
if(RULEID_of_AIM(ahfa_item)==sought_rule_id){
start_eim= earley_item;
break;
}
}
}
if(start_eim)break;
}
}

/*:972*/
#line 8671 "./marpa.w"

LV_Phase_of_R(r)= evaluation_phase;
obstack_init(&bocage_setup_obs);
/*967:*/
#line 8740 "./marpa.w"

{
guint ix;
guint total_earley_items_in_parse= 0;
guint earley_set_count= ES_Count_of_R(r);
per_es_data= 
obstack_alloc(&bocage_setup_obs,
sizeof(struct s_per_es_data)*earley_set_count);
for(ix= 0;ix<earley_set_count;ix++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,ix);
const guint item_count= EIM_Count_of_ES(earley_set);
total_earley_items_in_parse+= item_count;
per_es_data[ix].was_earley_item_stacked= 
bv_obs_create(&bocage_setup_obs,item_count);
}
}

/*:967*/
#line 8674 "./marpa.w"

/*968:*/
#line 8758 "./marpa.w"
{
;
}

/*:968*/
#line 8675 "./marpa.w"

/*969:*/
#line 8762 "./marpa.w"
{
;
}

/*:969*/
#line 8676 "./marpa.w"

obstack_free(&bocage_setup_obs,NULL);
return 1;
}

/*:964*//*974:*/
#line 8818 "./marpa.w"

gint marpa_eval_clear(struct marpa_r*r){
/*1106:*/
#line 9942 "./marpa.w"
const int failure_indicator= -2;

/*:1106*/
#line 8820 "./marpa.w"

/*1120:*/
#line 10032 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1120*/
#line 8821 "./marpa.w"

if(Phase_of_R(r)!=evaluation_phase){
R_ERROR("recce not being evaluated");
return failure_indicator;
}
LV_Phase_of_R(r)= input_phase;
return 1;
}

/*:974*//*977:*/
#line 8854 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:977*//*979:*/
#line 8862 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:979*//*982:*/
#line 8880 "./marpa.w"

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

/*:982*//*984:*/
#line 8900 "./marpa.w"

static inline Bit_Vector
bv_obs_create(struct obstack*obs,guint bits)
{
guint size= bv_bits_to_size(bits);
guint bytes= (size+bv_hiddenwords)<<sizeof(guint);
guint*addr= (Bit_Vector)obstack_alloc(obs,(size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
if(size> 0){
Bit_Vector bv= addr;
while(size--)*bv++= 0u;
}
return addr;
}


/*:984*//*985:*/
#line 8921 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:985*//*987:*/
#line 8933 "./marpa.w"
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
/*:987*//*989:*/
#line 8953 "./marpa.w"
static inline
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}
/*:989*//*991:*/
#line 8963 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:991*//*993:*/
#line 8972 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:993*//*995:*/
#line 8980 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:995*//*999:*/
#line 8995 "./marpa.w"

static inline void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:999*//*1001:*/
#line 9004 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:1001*//*1003:*/
#line 9012 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:1003*//*1005:*/
#line 9020 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:1005*//*1008:*/
#line 9029 "./marpa.w"

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
/*:1008*//*1010:*/
#line 9046 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:1010*//*1012:*/
#line 9058 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:1012*//*1014:*/
#line 9070 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:1014*//*1016:*/
#line 9082 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:1016*//*1018:*/
#line 9094 "./marpa.w"

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
/*:1018*//*1020:*/
#line 9170 "./marpa.w"

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
/*:1020*//*1026:*/
#line 9224 "./marpa.w"

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
GArray*rules= SYM_by_ID(g,*top_of_stack)->t_rhs;
for(rule_ix= 0;rule_ix<rules->len;rule_ix++)
{
Marpa_Rule_ID rule_id= 
g_array_index(rules,Marpa_Rule_ID,rule_ix);
RULE rule= RULE_by_ID(g,rule_id);
guint rule_length;
guint rh_ix;
Marpa_Symbol_ID lhs_id= LHS_ID_of_PRD(rule);
if(bv_bit_test(bv,(guint)lhs_id))
goto NEXT_RULE;
rule_length= rule->t_length;
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
/*:1026*//*1031:*/
#line 9303 "./marpa.w"

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
/*:1031*//*1033:*/
#line 9323 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:1033*//*1035:*/
#line 9336 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:1035*//*1037:*/
#line 9353 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:1037*//*1040:*/
#line 9363 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:1040*//*1043:*/
#line 9372 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:1043*//*1046:*/
#line 9381 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:1046*//*1048:*/
#line 9395 "./marpa.w"

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
/*:1048*//*1058:*/
#line 9530 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_bytes){
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}
/*:1058*//*1073:*/
#line 9653 "./marpa.w"

static inline void
psar_init(const RECCE r,const PSAR psar)
{
psar->t_psl_length= AHFA_Count_of_R(r);
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1073*//*1074:*/
#line 9660 "./marpa.w"

static inline void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl){
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
if(owner)*owner= NULL;
g_slice_free1(Sizeof_PSL(psar),psl);
psl= next_psl;
}
}
/*:1074*//*1075:*/
#line 9672 "./marpa.w"

static inline PSL psl_new(const PSAR psar){
guint i;
PSL new_psl= g_slice_alloc(Sizeof_PSL(psar));
new_psl->t_next= NULL;
new_psl->t_prev= NULL;
new_psl->t_owner= NULL;
for(i= 0;i<psar->t_psl_length;i++){
LV_PSL_Datum(new_psl,i)= NULL;
}
return new_psl;
}
/*:1075*//*1079:*/
#line 9702 "./marpa.w"

static inline void psar_reset(const PSAR psar){
PSL psl= psar->t_first_psl;
while(psl&&psl->t_owner){
guint i;
for(i= 0;i<psar->t_psl_length;i++){
LV_PSL_Datum(psl,i)= NULL;
}
psl= psl->t_next;
}
psar_dealloc(psar);
}

/*:1079*//*1081:*/
#line 9721 "./marpa.w"

static inline void psar_dealloc(const PSAR psar){
PSL psl= psar->t_first_psl;
while(psl){
PSL*owner= psl->t_owner;
if(!owner)break;
(*owner)= NULL;
psl->t_owner= NULL;
psl= psl->t_next;
}
psar->t_first_free_psl= psar->t_first_psl;
}


/*:1081*//*1083:*/
#line 9741 "./marpa.w"

static inline void psl_dealloc(const PSAR psar,const PSL psl){
if(!psl)return;
(*psl->t_owner)= NULL;
psl->t_owner= NULL;
/*1084:*/
#line 9749 "./marpa.w"
{
if(!psl->t_prev){
psar->t_first_psl= psar->t_first_psl->t_next;
psar->t_first_psl->t_prev= NULL;
}else{
psl->t_prev->t_next= psl->t_next;

psl->t_next->t_prev= psl->t_prev;
}
}
/*:1084*/
#line 9746 "./marpa.w"

/*1085:*/
#line 9759 "./marpa.w"
{
PSL first_free= psar->t_first_free_psl;
psl->t_next= first_free->t_next;
psl->t_prev= first_free;
first_free->t_next= psl;
}
/*:1085*/
#line 9747 "./marpa.w"

}
/*:1083*//*1087:*/
#line 9774 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar){
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1087*//*1090:*/
#line 9789 "./marpa.w"

static inline PSL psl_alloc(const PSAR psar){
PSL free_psl= psar->t_first_free_psl;
PSL next_psl= free_psl->t_next;
if(!next_psl){
next_psl= free_psl->t_next= psl_new(psar);
next_psl->t_prev= free_psl;
}
psar->t_first_free_psl= next_psl;
return free_psl;
}

/*:1090*//*1127:*/
#line 10102 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags){
if(!(flags&CONTEXT_FLAG))r_context_clear(r);
r->t_error= message;
if(flags&FATAL_FLAG)r->t_fatal_error= r->t_error;
r_message(r,message);
}

/*:1127*//*1135:*/
#line 10176 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb)
{g->t_message_callback= cb;}
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->t_message_callback_arg= cb_arg;}
gpointer marpa_g_message_callback_arg(struct marpa_g*g)
{return g->t_message_callback_arg;}
/*:1135*//*1137:*/
#line 10193 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_G_Message_Callback*cb= g->t_message_callback;
if(cb){(*cb)(g,id);}}
/*:1137*//*1143:*/
#line 10213 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb)
{r->t_message_callback= cb;}
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg)
{r->t_message_callback_arg= cb_arg;}
gpointer marpa_r_message_callback_arg(struct marpa_r*r)
{return Message_Callback_Arg_of_R(r);}
/*:1143*//*1145:*/
#line 10224 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id)
{Marpa_R_Message_Callback*cb= Message_Callback_of_R(r);
if(cb){(*cb)(r,id);}}
/*:1145*//*1149:*/
#line 10258 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
eim_tag(gchar*buffer,EIM eim)
{
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_EIM(eim),Origin_Earleme_of_EIM(eim),Earleme_of_EIM(eim));
return buffer;
}
#endif

/*:1149*//*1151:*/
#line 10279 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_SYMID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}
#endif

/*:1151*/
#line 10347 "./marpa.w"


/*:1157*/
