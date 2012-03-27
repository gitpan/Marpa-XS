/*1410:*/
#line 13551 "./marpa.w"

/*
 * Copyright 2012 Jeffrey Kegler
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

/*:1410*//*1411:*/
#line 13574 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1397:*/
#line 13382 "./marpa.w"

#define MARPA_DEBUG  0 
#define MARPA_ENABLE_ASSERT  0 
#if MARPA_DEBUG
#define MARPA_DEBUG1(a)  g_debug((a)); 
#define MARPA_DEBUG2(a, b)  g_debug((a),(b)); 
#define MARPA_DEBUG3(a, b, c)  g_debug((a),(b),(c)); 
#define MARPA_DEBUG4(a, b, c, d)  g_debug((a),(b),(c),(d)); 
#define MARPA_DEBUG5(a, b, c, d, e)  g_debug((a),(b),(c),(d),(e)); 
#define MARPA_ASSERT(expr) do { if G_LIKELY (expr) ; else \
       g_error ("%s: assertion failed %s", G_STRLOC, #expr); } while (0);
#else 
#define MARPA_DEBUG1(a) 
#define MARPA_DEBUG2(a, b) 
#define MARPA_DEBUG3(a, b, c) 
#define MARPA_DEBUG4(a, b, c, d) 
#define MARPA_DEBUG5(a, b, c, d, e) 
#define MARPA_ASSERT(exp) 
#endif

#if MARPA_ENABLE_ASSERT
#undef MARPA_ASSERT
#define MARPA_ASSERT(expr) do { if G_LIKELY (expr) ; else \
       g_error ("%s: assertion failed %s", G_STRLOC, #expr); } while (0);
#endif

/*:1397*/
#line 13577 "./marpa.w"

#define PRIVATE_NOT_INLINE static \

#define SYM_Count_of_G(g) ((g) ->t_symbols->len)  \

#define SYM_by_ID(id) (g_array_index(g->t_symbols,SYM,(id) ) )  \

#define RULE_Count_of_G(g) ((g) ->t_rules->len) 
#define RULE_by_ID(g,id) (g_array_index((g) ->t_rules,RULE,(id) ) )  \

#define RULEID_of_G_is_Valid(g,rule_id)  \
((rule_id) >=0&&(guint) (rule_id) <(g) ->t_rules->len)  \

#define Default_Value_of_G(g) ((g) ->t_default_value) 
#define Size_of_G(g) ((g) ->t_size) 
#define LV_Size_of_G(g) ((g) ->t_size) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define Context_of_G(g) ((g) ->t_context) 
#define ID_of_SYM(sym) ((sym) ->t_symbol_id) 
#define LV_ID_of_SYM(sym) ID_of_SYM(sym) 
#define SYMBOL_LHS_RULE_COUNT(symbol) ((symbol) ->t_lhs->len) 
#define SYM_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define SYM_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
#define SYMID_is_Terminal(id) (SYM_is_Terminal(SYM_by_ID(id) ) ) 
#define MAX_RHS_LENGTH (G_MAXINT>>(2) ) 
#define Length_of_RULE(rule) ((rule) ->t_rhs_length) 
#define LHS_ID_of_RULE(rule) ((rule) ->t_symbols[0]) 
#define RHS_ID_of_RULE(rule,position)  \
((rule) ->t_symbols[(position) +1])  \

#define ID_of_RULE(rule) ((rule) ->t_id) 
#define RULE_is_Used(rule) ((rule) ->t_is_used) 
#define RULE_is_Start(rule) ((rule) ->t_is_start) 
#define RULE_is_Virtual_LHS(rule) ((rule) ->t_is_virtual_lhs) 
#define RULE_is_Virtual_RHS(rule) ((rule) ->t_is_virtual_rhs) 
#define Real_SYM_Count_of_RULE(rule) ((rule) ->t_real_symbol_count) 
#define SYMI_Count_of_G(g) ((g) ->t_symbol_instance_count) 
#define SYMI_of_RULE(rule) ((rule) ->t_symbol_instance_base) 
#define Last_Proper_SYMI_of_RULE(rule) ((rule) ->t_last_proper_symi) 
#define SYMI_of_Completed_RULE(rule)  \
(SYMI_of_RULE(rule) +Length_of_RULE(rule) -1) 
#define SYMI_of_AIM(aim) (symbol_instance_of_ahfa_item_get(aim) ) 
#define Sort_Key_of_AIM(aim) ((aim) ->t_sort_key) 
#define Next_AIM_of_AIM(aim) ((aim) +1) 
#define AIM_by_ID(id) (g->t_AHFA_items+(id) ) 
#define AIM_Count_of_G(g) ((g) ->t_aim_count) 
#define LV_AIM_Count_of_G(g) AIM_Count_of_G(g) 
#define RULE_of_AIM(item) ((item) ->t_rule) 
#define RULEID_of_AIM(item) ID_of_RULE(RULE_of_AIM(item) ) 
#define LHS_ID_of_AIM(item) (LHS_ID_of_RULE(RULE_of_AIM(item) ) ) 
#define Position_of_AIM(aim) ((aim) ->t_position) 
#define Postdot_SYMID_of_AIM(item) ((item) ->t_postdot) 
#define AIM_is_Completion(aim) (Postdot_SYMID_of_AIM(aim) <0) 
#define AIM_has_Completed_Start_Rule(aim)  \
(AIM_is_Completion(aim) &&RULE_is_Start(RULE_of_AIM(aim) ) ) 
#define Null_Count_of_AIM(aim) ((aim) ->t_leading_nulls) 
#define AHFA_of_G_by_ID(g,id) ((g) ->t_AHFA+(id) ) 
#define AHFA_has_Completed_Start_Rule(ahfa) ((ahfa) ->t_has_completed_start_rule) 
#define Complete_SYMIDs_of_AHFA(state) ((state) ->t_complete_symbols) 
#define LV_Complete_SYMIDs_of_AHFA(state) Complete_SYMIDs_of_AHFA(state) 
#define Complete_SYM_Count_of_AHFA(state) ((state) ->t_complete_symbol_count) 
#define LV_Complete_SYM_Count_of_AHFA(state) Complete_SYM_Count_of_AHFA(state) 
#define AIMs_of_AHFA(ahfa) ((ahfa) ->t_items) 
#define AIM_of_AHFA_by_AEX(ahfa,aex) (AIMs_of_AHFA(ahfa) [aex]) 
#define LV_AIMs_of_AHFA(ahfa) AIMs_of_AHFA(ahfa) 
#define AIM_Count_of_AHFA(ahfa) ((ahfa) ->t_item_count) 
#define LV_AIM_Count_of_AHFA(ahfa) AIM_Count_of_AHFA(ahfa) 
#define AEX_of_AHFA_by_AIM(ahfa,aim) aex_of_ahfa_by_aim_get((ahfa) ,(aim) ) 
#define AHFA_is_Predicted(ahfa) ((ahfa) ->t_is_predict) 
#define LV_AHFA_is_Predicted(ahfa) AHFA_is_Predicted(ahfa) 
#define EIM_is_Predicted(eim) AHFA_is_Predicted(AHFA_of_EIM(eim) ) 
#define AHFA_Count_of_G(g) ((g) ->t_AHFA_len) 
#define ID_of_AHFA(state) ((state) ->t_key.t_id)  \

#define Postdot_SYM_Count_of_AHFA(state) ((state) ->t_postdot_sym_count) 
#define LV_Postdot_SYM_Count_of_AHFA(state) Postdot_SYM_Count_of_AHFA(state) 
#define Postdot_SYMID_Ary_of_AHFA(state) ((state) ->t_postdot_symid_ary) 
#define LV_Postdot_SYMID_Ary_of_AHFA(state) Postdot_SYMID_Ary_of_AHFA(state) 
#define AIMID_of_AHFA_by_AEX(g,ahfa,aex)  \
((ahfa) ->t_items[aex]-(g) ->t_AHFA_items) 
#define Leo_LHS_ID_of_AHFA(state) ((state) ->t_leo_lhs_sym) 
#define LV_Leo_LHS_ID_of_AHFA(state) Leo_LHS_ID_of_AHFA(state) 
#define AHFA_is_Leo_Completion(state) (Leo_LHS_ID_of_AHFA(state) >=0) 
#define TRANS_of_AHFA_by_SYMID(from_ahfa,id)  \
(*(TRANSs_of_AHFA(from_ahfa) +(id) ) ) 
#define TRANS_of_EIM_by_SYMID(eim,id) TRANS_of_AHFA_by_SYMID(AHFA_of_EIM(eim) ,(id) ) 
#define To_AHFA_of_TRANS(trans) (to_ahfa_of_transition_get(trans) ) 
#define LV_To_AHFA_of_TRANS(trans) ((trans) ->t_ur.t_to_ahfa) 
#define Completion_Count_of_TRANS(trans)  \
(completion_count_of_transition_get(trans) ) 
#define LV_Completion_Count_of_TRANS(trans) ((trans) ->t_ur.t_completion_count) 
#define To_AHFA_of_AHFA_by_SYMID(from_ahfa,id)  \
(To_AHFA_of_TRANS(TRANS_of_AHFA_by_SYMID((from_ahfa) ,(id) ) ) ) 
#define Completion_Count_of_AHFA_by_SYMID(from_ahfa,id)  \
(Completion_Count_of_TRANS(TRANS_of_AHFA_by_SYMID((from ahfa) ,(id) ) ) ) 
#define To_AHFA_of_EIM_by_SYMID(eim,id) To_AHFA_of_AHFA_by_SYMID(AHFA_of_EIM(eim) ,(id) ) 
#define AEXs_of_TRANS(trans) ((trans) ->t_aex) 
#define Leo_Base_AEX_of_TRANS(trans) ((trans) ->t_leo_base_aex) 
#define TRANSs_of_AHFA(ahfa) ((ahfa) ->t_transitions) 
#define LV_TRANSs_of_AHFA(ahfa) TRANSs_of_AHFA(ahfa) 
#define Empty_Transition_of_AHFA(state) ((state) ->t_empty_transition) 
#define G_of_R(r) ((r) ->t_grammar) 
#define AHFA_Count_of_R(r) AHFA_Count_of_G(G_of_R(r) ) 
#define Phase_of_R(r) ((r) ->t_phase) 
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
#define EIMs_of_ES(set) ((set) ->t_earley_items) 
#define ES_Count_of_R(r) ((r) ->t_earley_set_count) 
#define Ord_of_ES(set) ((set) ->t_ordinal) 
#define ES_Ord_is_Valid(r,ordinal)  \
((ordinal) >=0&&(ordinal) <ES_Count_of_R(r) ) 
#define Earleme_of_ES(set) ((set) ->t_key.t_earleme)  \

#define EIM_FATAL_THRESHOLD (G_MAXINT/4) 
#define Complete_SYMIDs_of_EIM(item)  \
Complete_SYMIDs_of_AHFA(AHFA_of_EIM(item) ) 
#define Complete_SYM_Count_of_EIM(item)  \
Complete_SYM_Count_of_AHFA(AHFA_of_EIM(item) ) 
#define Leo_LHS_ID_of_EIM(eim) Leo_LHS_ID_of_AHFA(AHFA_of_EIM(eim) ) 
#define Earley_Item_is_Completion(item)  \
(Complete_SYM_Count_of_EIM(item) > 0) 
#define ES_of_EIM(item) ((item) ->t_key.t_set) 
#define ES_Ord_of_EIM(item) (Ord_of_ES(ES_of_EIM(item) ) ) 
#define Ord_of_EIM(item) ((item) ->t_ordinal) 
#define Earleme_of_EIM(item) Earleme_of_ES(ES_of_EIM(item) ) 
#define AHFAID_of_EIM(item) (ID_of_AHFA(AHFA_of_EIM(item) ) ) 
#define AHFA_of_EIM(item) ((item) ->t_key.t_state) 
#define AIM_Count_of_EIM(item) (AIM_Count_of_AHFA(AHFA_of_EIM(item) ) ) 
#define Origin_Earleme_of_EIM(item) (Earleme_of_ES(Origin_of_EIM(item) ) ) 
#define Origin_Ord_of_EIM(item) (Ord_of_ES(Origin_of_EIM(item) ) ) 
#define Origin_of_EIM(item) ((item) ->t_key.t_origin) 
#define AIM_of_EIM_by_AEX(eim,aex) AIM_of_AHFA_by_AEX(AHFA_of_EIM(eim) ,(aex) ) 
#define AEX_of_EIM_by_AIM(eim,aim) AEX_of_AHFA_by_AIM(AHFA_of_EIM(eim) ,(aim) ) 
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
#define Next_PIM_of_EIX(eix) ((eix) ->t_next) 
#define LV_Next_PIM_of_EIX(eix) Next_PIM_of_EIX(eix) 
#define EIM_of_EIX(eix) ((eix) ->t_earley_item) 
#define LV_EIM_of_EIX(eix) EIM_of_EIX(eix) 
#define Postdot_SYMID_of_EIX(eix) ((eix) ->t_postdot_symid) 
#define LV_Postdot_SYMID_of_EIX(eix) Postdot_SYMID_of_EIX(eix) 
#define EIX_of_LIM(lim) ((EIX) (lim) ) 
#define Postdot_SYMID_of_LIM(leo) (Postdot_SYMID_of_EIX(EIX_of_LIM(leo) ) ) 
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
#define SYMID_of_Postdot_Item(postdot) ((postdot) ->t_earley.transition_symid)  \

#define Next_SRCL_of_SRCL(link) ((link) ->t_next) 
#define LV_Next_SRCL_of_SRCL(link) Next_SRCL_of_SRCL(link) 
#define Source_of_SRCL(link) ((link) ->t_source) 
#define Source_of_EIM(eim) ((eim) ->t_container.t_unique) 
#define Predecessor_of_Source(srcd) ((srcd) .t_predecessor) 
#define Predecessor_of_SRC(source) Predecessor_of_Source(*(source) ) 
#define Predecessor_of_EIM(item) Predecessor_of_Source(Source_of_EIM(item) ) 
#define Predecessor_of_SRCL(link) Predecessor_of_Source(Source_of_SRCL(link) ) 
#define LV_Predecessor_of_SRCL(link) Predecessor_of_SRCL(link) 
#define Cause_of_Source(srcd) ((srcd) .t_cause.t_completion) 
#define Cause_of_SRC(source) Cause_of_Source(*(source) ) 
#define Cause_of_EIM(item) Cause_of_Source(Source_of_EIM(item) ) 
#define Cause_of_SRCL(link) Cause_of_Source(Source_of_SRCL(link) ) 
#define TOK_of_Source(srcd) ((srcd) .t_cause.t_token) 
#define TOK_of_SRC(source) TOK_of_Source(*(source) ) 
#define TOK_of_EIM(eim) TOK_of_Source(Source_of_EIM(eim) ) 
#define TOK_of_SRCL(link) TOK_of_Source(Source_of_SRCL(link) ) 
#define SYMID_of_Source(srcd) SYMID_of_TOK(TOK_of_Source(srcd) ) 
#define SYMID_of_SRC(source) SYMID_of_Source(*(source) ) 
#define SYMID_of_EIM(eim) SYMID_of_Source(Source_of_EIM(eim) ) 
#define SYMID_of_SRCL(link) SYMID_of_Source(Source_of_SRCL(link) )  \

#define Cause_AHFA_State_ID_of_SRC(source)  \
AHFAID_of_EIM((EIM) Cause_of_SRC(source) ) 
#define Leo_Transition_SYMID_of_SRC(leo_source)  \
Postdot_SYMID_of_LIM((LIM) Predecessor_of_SRC(leo_source) )  \

#define First_Completion_Link_of_EIM(item) ((item) ->t_container.t_ambiguous.t_completion) 
#define LV_First_Completion_Link_of_EIM(item) First_Completion_Link_of_EIM(item) 
#define First_Token_Link_of_EIM(item) ((item) ->t_container.t_ambiguous.t_token) 
#define LV_First_Token_Link_of_EIM(item) First_Token_Link_of_EIM(item) 
#define First_Leo_SRCL_of_EIM(item) ((item) ->t_container.t_ambiguous.t_leo) 
#define LV_First_Leo_SRCL_of_EIM(item) First_Leo_SRCL_of_EIM(item)  \

#define Type_of_TOK(tok) ((tok) ->t_type) 
#define SYMID_of_TOK(tok) ((tok) ->t_symbol_id) 
#define Value_of_TOK(tok) ((tok) ->t_value) 
#define TOK_Obs_of_R(r) (&(r) ->t_token_obs) 
#define TOKs_by_SYMID_of_R(r) ((r) ->t_tokens_by_symid) 
#define TOK_Obs TOK_Obs_of_R(r) 
#define TOK_by_ID_of_R(r,symbol_id) (TOKs_by_SYMID_of_R(r) [symbol_id]) 
#define TOK_of_ALT(alt) ((alt) ->t_token) 
#define SYMID_of_ALT(alt) SYMID_of_TOK(TOK_of_ALT(alt) ) 
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
#define Prev_UR_of_UR(ur) ((ur) ->t_prev) 
#define LV_Prev_UR_of_UR(ur) Prev_UR_of_UR(ur) 
#define Next_UR_of_UR(ur) ((ur) ->t_next) 
#define LV_Next_UR_of_UR(ur) Next_UR_of_UR(ur) 
#define EIM_of_UR(ur) ((ur) ->t_earley_item) 
#define LV_EIM_of_UR(ur) EIM_of_UR(ur) 
#define AEX_of_UR(ur) ((ur) ->t_aex) 
#define LV_AEX_of_UR(ur) AEX_of_UR(ur)  \

#define URS_of_R(r) (&(r) ->t_ur_node_stack) 
#define Set_boolean_in_PSIA_for_initial_nulls(eim,aim) { \
if(Position_of_AIM(aim) > 0) { \
const gint null_count= Null_Count_of_AIM(aim) ; \
if(null_count) { \
AEX aex= AEX_of_EIM_by_AIM((eim) , \
(aim) ) ; \
or_node_estimate+= null_count; \
psia_test_and_set(&bocage_setup_obs,per_es_data, \
(eim) ,aex) ; \
} \
} \
} \

#define DUMMY_OR_NODE -1
#define TOKEN_OR_NODE -2
#define OR_is_Token(or) (Type_of_OR(or) ==TOKEN_OR_NODE) 
#define Position_of_OR(or) ((or) ->t_final.t_position) 
#define Type_of_OR(or) ((or) ->t_final.t_position) 
#define RULE_of_OR(or) ((or) ->t_final.t_rule) 
#define Origin_Ord_of_OR(or) ((or) ->t_final.t_start_set_ordinal) 
#define ID_of_OR(or) ((or) ->t_final.t_id) 
#define ES_Ord_of_OR(or) ((or) ->t_draft.t_end_set_ordinal) 
#define DANDs_of_OR(or) ((or) ->t_draft.t_draft_and_node) 
#define First_ANDID_of_OR(or) ((or) ->t_final.t_first_and_node_id) 
#define AND_Count_of_OR(or) ((or) ->t_final.t_and_node_count) 
#define TOK_of_OR(or) (&(or) ->t_token) 
#define SYMID_of_OR(or) SYMID_of_TOK(TOK_of_OR(or) ) 
#define Value_of_OR(or) Value_of_TOK(TOK_of_OR(or) ) 
#define ORs_of_B(b) ((b) ->t_or_nodes) 
#define OR_of_B_by_ID(b,id) (ORs_of_B(b) [(id) ]) 
#define OR_Count_of_B(b) ((b) ->t_or_node_count) 
#define ANDs_of_B(b) ((b) ->t_and_nodes) 
#define AND_Count_of_B(b) ((b) ->t_and_node_count) 
#define Top_ORID_of_B(b) ((b) ->t_top_or_node_id) 
#define Path_AIM_of_LIM(lim) (base_aim_of_lim(lim) +1) 
#define Base_AIM_of_LIM(lim) (base_aim_of_lim(lim) ) 
#define WHEID_of_SYMID(symid) (rule_count_of_g+(symid) ) 
#define WHEID_of_RULEID(ruleid) (ruleid) 
#define WHEID_of_RULE(rule) WHEID_of_RULEID(ID_of_RULE(rule) ) 
#define WHEID_of_OR(or) ( \
wheid= OR_is_Token(or) ? \
WHEID_of_SYMID(SYMID_of_OR(or) ) : \
WHEID_of_RULE(RULE_of_OR(or) )  \
)  \

#define Next_DAND_of_DAND(dand) ((dand) ->t_next) 
#define Predecessor_OR_of_DAND(dand) ((dand) ->t_predecessor) 
#define Cause_OR_of_DAND(dand) ((dand) ->t_cause) 
#define Move_OR_to_Proper_OR(or_node) { \
while(or_node) { \
DAND draft_and_node= DANDs_of_OR(or_node) ; \
OR predecessor_or; \
if(!draft_and_node) break; \
predecessor_or= Predecessor_OR_of_DAND(draft_and_node) ; \
if(predecessor_or&& \
ES_Ord_of_OR(predecessor_or) !=work_earley_set_ordinal)  \
break; \
or_node= predecessor_or; \
} \
} \

#define Set_OR_from_Ord_and_SYMI(or_node,origin,symbol_instance) { \
const PSL or_psl_at_origin= per_es_data[(origin) ].t_or_psl; \
(or_node) = PSL_Datum(or_psl_at_origin,(symbol_instance) ) ; \
} \

#define Set_OR_from_EIM_and_AEX(psia_or,psia_eim,psia_aex) { \
const EIM psia_earley_item= psia_eim; \
const gint psia_earley_set_ordinal= ES_Ord_of_EIM(psia_earley_item) ; \
OR**const psia_nodes_by_item=  \
per_es_data[psia_earley_set_ordinal].t_aexes_by_item; \
const gint psia_item_ordinal= Ord_of_EIM(psia_earley_item) ; \
OR*const psia_nodes_by_aex= psia_nodes_by_item[psia_item_ordinal]; \
psia_or= psia_nodes_by_aex?psia_nodes_by_aex[psia_aex]:NULL; \
} \

#define OR_of_AND(and) ((and) ->t_current) 
#define Predecessor_OR_of_AND(and) ((and) ->t_predecessor) 
#define Cause_OR_of_AND(and) ((and) ->t_cause) 
#define B_of_R(r) ((r) ->t_bocage) 
#define OBS_of_B(b) ((b) ->t_obs) 
#define TREE_is_Initialized(tree) ((tree) ->t_parse_count>=0) 
#define TREE_is_Exhausted(tree) (TREE_is_Initialized(tree)  \
&&!FSTACK_IS_INITIALIZED((tree) ->t_fork_stack) ) 
#define VAL_of_TREE(tree) (&(tree) ->t_val) 
#define Size_of_TREE(tree) FSTACK_LENGTH((tree) ->t_fork_stack) 
#define FORK_of_TREE_by_IX(tree,fork_id)  \
FSTACK_INDEX((tree) ->t_fork_stack,FORK_Object,fork_id) 
#define TREE_of_RANK(rank) (&(rank) ->t_tree) 
#define OBS_of_RANK(rank) ((rank) ->t_obs) 
#define RANK_of_B(b) (&(b) ->t_rank) 
#define OR_of_FORK(fork) ((fork) ->t_or_node) 
#define Choice_of_FORK(fork) ((fork) ->t_choice) 
#define Parent_of_FORK(fork) ((fork) ->t_parent) 
#define FORK_Cause_is_Ready(fork) ((fork) ->t_is_cause_ready) 
#define FORK_is_Cause(fork) ((fork) ->t_is_cause_of_parent) 
#define FORK_Predecessor_is_Ready(fork) ((fork) ->t_is_predecessor_ready) 
#define FORK_is_Predecessor(fork) ((fork) ->t_is_predecessor_of_parent) 
#define SYMID_of_EVE(eve) ((eve) ->marpa_token_id) 
#define Value_of_EVE(eve) ((eve) ->marpa_value) 
#define RULEID_of_EVE(eve) ((eve) ->marpa_rule_id) 
#define Arg0_of_EVE(eve) ((eve) ->marpa_arg_0) 
#define ArgN_of_EVE(eve) ((eve) ->marpa_arg_n) 
#define VAL_is_Active(val) ((val) ->t_active) 
#define VAL_is_Trace(val) ((val) ->t_trace) 
#define FORK_of_VAL(val) ((val) ->t_fork) 
#define TOS_of_VAL(val) ((val) ->t_tos) 
#define VStack_of_VAL(val) ((val) ->t_virtual_stack) 
#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DECLARE(stack,type) struct{gint t_count;type*t_base;}stack;
#define FSTACK_CLEAR(stack) ((stack) .t_count= 0) 
#define FSTACK_INIT(stack,type,n) (FSTACK_CLEAR(stack) ,((stack) .t_base= g_new(type,n) ) ) 
#define FSTACK_SAFE(stack) ((stack) .t_base= NULL) 
#define FSTACK_BASE(stack,type) ((type*) (stack) .t_base) 
#define FSTACK_INDEX(this,type,ix) (FSTACK_BASE((this) ,type) +(ix) ) 
#define FSTACK_TOP(this,type) (FSTACK_LENGTH(this) <=0 \
?NULL \
:FSTACK_INDEX((this) ,type,FSTACK_LENGTH(this) -1) ) 
#define FSTACK_LENGTH(stack) ((stack) .t_count) 
#define FSTACK_PUSH(stack) ((stack) .t_base+stack.t_count++) 
#define FSTACK_POP(stack) ((stack) .t_count<=0?NULL:(stack) .t_base+(--(stack) .t_count) ) 
#define FSTACK_IS_INITIALIZED(stack) ((stack) .t_base) 
#define FSTACK_DESTROY(stack) (g_free((stack) .t_base) )  \

#define DSTACK_DECLARE(this) struct s_dstack this
#define DSTACK_INIT(this,type,initial_size)  \
(((this) .t_count= 0) , \
((this) .t_base= g_new(type,((this) .t_capacity= (initial_size) ) ) ) )  \

#define DSTACK_IS_INITIALIZED(this) ((this) .t_base) 
#define DSTACK_SAFE(this)  \
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
#define Dot_PSAR_of_R(r) (&(r) ->t_dot_psar_object) 
#define Dot_PSL_of_ES(es) ((es) ->t_dot_psl) 
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
#define MARPA_OFF_DEBUG1(a) 
#define MARPA_OFF_DEBUG2(a,b) 
#define MARPA_OFF_DEBUG3(a,b,c) 
#define MARPA_OFF_DEBUG4(a,b,c,d) 
#define MARPA_OFF_DEBUG5(a,b,c,d,e) 
#define MARPA_OFF_ASSERT(expr) 

#line 13578 "./marpa.w"

#include "marpa_obs.h"
/*1379:*/
#line 13268 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1379*/
#line 13580 "./marpa.w"

/*136:*/
#line 1118 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:136*//*447:*/
#line 3546 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:447*//*492:*/
#line 3951 "./marpa.w"
struct s_AHFA_state;
/*:492*//*579:*/
#line 5192 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:579*//*706:*/
#line 5900 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:706*//*735:*/
#line 6129 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:735*//*762:*/
#line 6438 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:762*//*765:*/
#line 6480 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:765*//*870:*/
#line 7647 "./marpa.w"

struct s_token;
typedef struct s_token*TOK;
/*:870*//*878:*/
#line 7728 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:878*//*980:*/
#line 8875 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:980*//*1016:*/
#line 9354 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:1016*//*1045:*/
#line 9796 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:1045*//*1073:*/
#line 10216 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:1073*//*1094:*/
#line 10421 "./marpa.w"

struct s_bocage;
typedef struct s_bocage*BOC;
/*:1094*//*1106:*/
#line 10512 "./marpa.w"

struct s_bocage_setup_per_es;
/*:1106*//*1138:*/
#line 10855 "./marpa.w"

struct s_tree;
typedef struct s_tree*TREE;
/*:1138*//*1163:*/
#line 11220 "./marpa.w"

struct s_bocage_rank;
typedef struct s_bocage_rank*RANK;
/*:1163*//*1183:*/
#line 11485 "./marpa.w"

struct s_fork;
typedef struct s_fork*FORK;
/*:1183*//*1204:*/
#line 11668 "./marpa.w"

struct s_value;
typedef struct s_value*VAL;
/*:1204*//*1308:*/
#line 12665 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1308*//*1312:*/
#line 12700 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1312*//*1319:*/
#line 12765 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1319*//*1321:*/
#line 12780 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1321*/
#line 13581 "./marpa.w"

/*42:*/
#line 679 "./marpa.w"

typedef struct marpa_g*GRAMMAR;
typedef const struct marpa_g*GRAMMAR_Const;

/*:42*//*135:*/
#line 1116 "./marpa.w"

typedef gint SYMID;
/*:135*//*213:*/
#line 1511 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:213*//*338:*/
#line 2342 "./marpa.w"
typedef gint SYMI;
/*:338*//*504:*/
#line 4037 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:504*//*580:*/
#line 5197 "./marpa.w"
typedef gint AEX;
/*:580*//*603:*/
#line 5360 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:603*//*703:*/
#line 5890 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:703*//*705:*/
#line 5894 "./marpa.w"
typedef Marpa_Earley_Set_ID ESID;
/*:705*//*802:*/
#line 6881 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:802*//*804:*/
#line 6893 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:804*//*1008:*/
#line 9290 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:1008*//*1044:*/
#line 9785 "./marpa.w"

typedef gint WHEID;


/*:1044*//*1072:*/
#line 10213 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:1072*//*1182:*/
#line 11482 "./marpa.w"

typedef Marpa_Fork_ID FORKID;
/*:1182*//*1203:*/
#line 11649 "./marpa.w"

typedef Marpa_Event*EVE;

/*:1203*//*1222:*/
#line 11939 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1222*//*1281:*/
#line 12426 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1281*/
#line 13582 "./marpa.w"

/*36:*/
#line 630 "./marpa.w"

const guint marpa_major_version= MARPA_MAJOR_VERSION;
const guint marpa_minor_version= MARPA_MINOR_VERSION;
const guint marpa_micro_version= MARPA_MICRO_VERSION;
const guint marpa_interface_age= MARPA_INTERFACE_AGE;
const guint marpa_binary_age= MARPA_BINARY_AGE;
/*:36*//*50:*/
#line 712 "./marpa.w"
static gint next_grammar_id= 1;
/*:50*//*612:*/
#line 5419 "./marpa.w"
static gint next_recce_id= 1;
/*:612*//*1022:*/
#line 9408 "./marpa.w"

static const gint dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:1022*//*1223:*/
#line 11946 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1223*/
#line 13583 "./marpa.w"

/*1309:*/
#line 12668 "./marpa.w"

struct s_dstack{gint t_count;gint t_capacity;gpointer t_base;};
/*:1309*/
#line 13584 "./marpa.w"

/*41:*/
#line 673 "./marpa.w"
struct marpa_g{
/*54:*/
#line 725 "./marpa.w"
GArray*t_symbols;
/*:54*//*64:*/
#line 774 "./marpa.w"
GArray*t_rules;
/*:64*//*72:*/
#line 812 "./marpa.w"
gpointer t_default_value;
/*:72*//*107:*/
#line 962 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:107*//*110:*/
#line 976 "./marpa.w"
GHashTable*t_context;
/*:110*//*125:*/
#line 1075 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:125*//*129:*/
#line 1097 "./marpa.w"
Marpa_Error_ID t_error;
/*:129*//*205:*/
#line 1470 "./marpa.w"

Marpa_Symbol_Callback*t_symbol_callback;
gpointer t_symbol_callback_arg;
/*:205*//*313:*/
#line 2246 "./marpa.w"

Marpa_Rule_Callback*t_rule_callback;
gpointer t_rule_callback_arg;
/*:313*//*449:*/
#line 3563 "./marpa.w"

AIM t_AHFA_items;
AIM*t_AHFA_items_by_rule;
/*:449*//*505:*/
#line 4041 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:505*//*1383:*/
#line 13310 "./marpa.w"

Marpa_G_Message_Callback*t_message_callback;
gpointer t_message_callback_arg;
/*:1383*/
#line 674 "./marpa.w"

/*48:*/
#line 710 "./marpa.w"
gint t_id;
/*:48*//*78:*/
#line 832 "./marpa.w"
Marpa_Symbol_ID t_start_symid;
/*:78*//*84:*/
#line 857 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:84*//*87:*/
#line 884 "./marpa.w"
int t_size;
/*:87*//*90:*/
#line 897 "./marpa.w"
gint t_max_rule_length;
/*:90*//*339:*/
#line 2344 "./marpa.w"

gint t_symbol_instance_count;
/*:339*//*450:*/
#line 3569 "./marpa.w"

guint t_aim_count;
/*:450*//*506:*/
#line 4044 "./marpa.w"
gint t_AHFA_len;
/*:506*/
#line 675 "./marpa.w"

/*94:*/
#line 905 "./marpa.w"
guint t_is_precomputed:1;
/*:94*//*97:*/
#line 913 "./marpa.w"
guint t_has_loop:1;
/*:97*//*101:*/
#line 928 "./marpa.w"
guint t_is_lhs_terminal_ok:1;
/*:101*/
#line 676 "./marpa.w"

};
typedef struct marpa_g GRAMMARD;
/*:41*//*137:*/
#line 1125 "./marpa.w"

struct s_symbol{
/*146:*/
#line 1178 "./marpa.w"
GArray*t_lhs;
/*:146*//*153:*/
#line 1208 "./marpa.w"
GArray*t_rhs;
/*:153*//*192:*/
#line 1378 "./marpa.w"

struct s_symbol*t_alias;
/*:192*/
#line 1127 "./marpa.w"

/*144:*/
#line 1169 "./marpa.w"
SYMID t_symbol_id;
/*:144*/
#line 1128 "./marpa.w"

/*160:*/
#line 1230 "./marpa.w"
guint t_is_accessible:1;
/*:160*//*164:*/
#line 1248 "./marpa.w"
guint t_is_counted:1;
/*:164*//*168:*/
#line 1266 "./marpa.w"
guint t_is_nullable:1;
/*:168*//*172:*/
#line 1285 "./marpa.w"
guint t_is_nulling:1;
/*:172*//*176:*/
#line 1305 "./marpa.w"
guint t_is_terminal:1;
/*:176*//*182:*/
#line 1331 "./marpa.w"
guint t_is_productive:1;
/*:182*//*186:*/
#line 1349 "./marpa.w"
guint t_is_start:1;
/*:186*//*191:*/
#line 1375 "./marpa.w"

guint t_is_proper_alias:1;
guint t_is_nulling_alias:1;
/*:191*/
#line 1129 "./marpa.w"

};
typedef struct s_symbol SYM_Object;

/*:137*//*212:*/
#line 1502 "./marpa.w"

struct s_rule{
/*241:*/
#line 1906 "./marpa.w"
gint t_rhs_length;
/*:241*//*258:*/
#line 1978 "./marpa.w"
Marpa_Rule_ID t_id;
/*:258*//*303:*/
#line 2209 "./marpa.w"
gint t_virtual_start;
/*:303*//*307:*/
#line 2225 "./marpa.w"
gint t_virtual_end;
/*:307*//*324:*/
#line 2282 "./marpa.w"
Marpa_Rule_ID t_original;
/*:324*//*329:*/
#line 2301 "./marpa.w"
gint t_real_symbol_count;
/*:329*//*340:*/
#line 2355 "./marpa.w"

gint t_symbol_instance_base;
gint t_last_proper_symi;
/*:340*/
#line 1504 "./marpa.w"

/*261:*/
#line 1990 "./marpa.w"
guint t_is_discard:1;
/*:261*//*275:*/
#line 2074 "./marpa.w"
guint t_is_loop:1;
/*:275*//*280:*/
#line 2095 "./marpa.w"
guint t_is_virtual_loop:1;
/*:280*//*287:*/
#line 2130 "./marpa.w"
guint t_is_used:1;
/*:287*//*291:*/
#line 2146 "./marpa.w"
guint t_is_start:1;
/*:291*//*295:*/
#line 2177 "./marpa.w"
guint t_is_virtual_lhs:1;
/*:295*//*299:*/
#line 2192 "./marpa.w"
guint t_is_virtual_rhs:1;
/*:299*//*333:*/
#line 2314 "./marpa.w"
guint t_is_semantic_equivalent:1;
/*:333*/
#line 1505 "./marpa.w"

/*242:*/
#line 1909 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:242*/
#line 1506 "./marpa.w"

};
/*:212*//*446:*/
#line 3540 "./marpa.w"

struct s_AHFA_item{
gint t_sort_key;
/*456:*/
#line 3595 "./marpa.w"

RULE t_rule;

/*:456*/
#line 3543 "./marpa.w"

/*457:*/
#line 3601 "./marpa.w"

gint t_position;

/*:457*//*458:*/
#line 3610 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:458*//*459:*/
#line 3619 "./marpa.w"

gint t_leading_nulls;

/*:459*/
#line 3544 "./marpa.w"

};
/*:446*//*493:*/
#line 3952 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*496:*/
#line 3973 "./marpa.w"

SYMID*t_complete_symbols;

/*:496*//*498:*/
#line 3983 "./marpa.w"

AIM*t_items;
/*:498*//*513:*/
#line 4085 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:513*//*582:*/
#line 5210 "./marpa.w"

TRANS*t_transitions;
/*:582*/
#line 3959 "./marpa.w"

/*495:*/
#line 3971 "./marpa.w"

guint t_complete_symbol_count;
/*:495*//*499:*/
#line 3985 "./marpa.w"

guint t_item_count;
/*:499*//*514:*/
#line 4086 "./marpa.w"
guint t_postdot_sym_count;

/*:514*//*528:*/
#line 4217 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:528*/
#line 3960 "./marpa.w"

guint t_has_completed_start_rule:1;
/*503:*/
#line 4034 "./marpa.w"

guint t_is_predict:1;

/*:503*/
#line 3962 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:493*//*581:*/
#line 5198 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
gint t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:581*//*707:*/
#line 5906 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:707*//*708:*/
#line 5911 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
gint t_postdot_sym_count;
/*709:*/
#line 5923 "./marpa.w"

gint t_eim_count;
/*:709*//*711:*/
#line 5937 "./marpa.w"

gint t_ordinal;
/*:711*/
#line 5915 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*710:*/
#line 5926 "./marpa.w"

EIM*t_earley_items;

/*:710*//*1330:*/
#line 12855 "./marpa.w"

PSL t_dot_psl;
/*:1330*/
#line 5918 "./marpa.w"

};

/*:708*//*763:*/
#line 6442 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:763*//*766:*/
#line 6483 "./marpa.w"

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

/*:766*//*779:*/
#line 6628 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:779*//*871:*/
#line 7655 "./marpa.w"

struct s_token{
gint t_type;
SYMID t_symbol_id;
gpointer t_value;
};
typedef struct s_token TOK_Object;

/*:871*//*879:*/
#line 7738 "./marpa.w"

struct s_alternative{
TOK t_token;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:879*//*982:*/
#line 8897 "./marpa.w"

struct s_ur_node_stack{
struct obstack t_obs;
UR t_base;
UR t_top;
};
struct s_ur_node{
UR t_prev;
UR t_next;
EIM t_earley_item;
AEX t_aex;
};
/*:982*//*1019:*/
#line 9383 "./marpa.w"

struct s_draft_or_node
{
/*1018:*/
#line 9377 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:1018*/
#line 9386 "./marpa.w"

DAND t_draft_and_node;
};
/*:1019*//*1020:*/
#line 9389 "./marpa.w"

struct s_final_or_node
{
/*1018:*/
#line 9377 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
ORID t_id;
/*:1018*/
#line 9392 "./marpa.w"

gint t_first_and_node_id;
gint t_and_node_count;
};
/*:1020*//*1021:*/
#line 9400 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_token t_token;
};
typedef union u_or_node OR_Object;

/*:1021*//*1046:*/
#line 9803 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:1046*//*1074:*/
#line 10223 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:1074*//*1107:*/
#line 10514 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:1107*//*1139:*/
#line 10871 "./marpa.w"

/*1184:*/
#line 11496 "./marpa.w"

struct s_fork{
OR t_or_node;
gint t_choice;
FORKID t_parent;
guint t_is_cause_ready:1;
guint t_is_predecessor_ready:1;
guint t_is_cause_of_parent:1;
guint t_is_predecessor_of_parent:1;
};
typedef struct s_fork FORK_Object;

/*:1184*/
#line 10872 "./marpa.w"

/*1205:*/
#line 11685 "./marpa.w"

struct s_value{
DSTACK_DECLARE(t_virtual_stack);
FORKID t_fork;
gint t_tos;
guint t_trace:1;
guint t_active:1;
};
typedef struct s_value VAL_Object;

/*:1205*/
#line 10873 "./marpa.w"

struct s_tree{
FSTACK_DECLARE(t_fork_stack,FORK_Object)
FSTACK_DECLARE(t_fork_worklist,gint)
Bit_Vector t_and_node_in_use;
gint t_parse_count;
VAL_Object t_val;
};
typedef struct s_tree TREE_Object;

/*:1139*//*1164:*/
#line 11230 "./marpa.w"

struct s_bocage_rank{
struct obstack t_obs;
Bit_Vector t_and_node_in_use;
ANDID**t_and_node_orderings;
TREE_Object t_tree;
};
typedef struct s_bocage_rank RANK_Object;

/*:1164*//*1313:*/
#line 12703 "./marpa.w"

struct s_dqueue{gint t_current;struct s_dstack t_stack;};

/*:1313*//*1320:*/
#line 12771 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
gpointer t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1320*//*1322:*/
#line 12795 "./marpa.w"

struct s_per_earley_set_arena{
gint t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1322*/
#line 13585 "./marpa.w"

/*604:*/
#line 5362 "./marpa.w"

struct marpa_r{
/*617:*/
#line 5431 "./marpa.w"
const struct marpa_g*t_grammar;

/*:617*//*624:*/
#line 5473 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:624*//*642:*/
#line 5553 "./marpa.w"
gpointer*t_sym_workarea;
/*:642*//*646:*/
#line 5568 "./marpa.w"
gpointer*t_workarea2;
/*:646*//*650:*/
#line 5589 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:650*//*654:*/
#line 5615 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:654*//*679:*/
#line 5779 "./marpa.w"
GHashTable*t_context;
/*:679*//*690:*/
#line 5834 "./marpa.w"
struct obstack t_obs;
/*:690*//*694:*/
#line 5848 "./marpa.w"

Marpa_Error_ID t_error;
Marpa_Error_ID t_fatal_error;
/*:694*//*718:*/
#line 5990 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:718*//*746:*/
#line 6272 "./marpa.w"

EIM t_trace_earley_item;
/*:746*//*785:*/
#line 6681 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:785*//*827:*/
#line 7166 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:827*//*872:*/
#line 7679 "./marpa.w"

struct obstack t_token_obs;
TOK*t_tokens_by_symid;
/*:872*//*880:*/
#line 7746 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:880*//*906:*/
#line 8049 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:906*//*910:*/
#line 8060 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:910*//*914:*/
#line 8071 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:914*//*983:*/
#line 8910 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:983*//*1096:*/
#line 10432 "./marpa.w"

BOC t_bocage;
/*:1096*//*1323:*/
#line 12803 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1323*//*1391:*/
#line 13347 "./marpa.w"

Marpa_R_Message_Callback*t_message_callback;
gpointer t_message_callback_arg;
/*:1391*/
#line 5364 "./marpa.w"

/*610:*/
#line 5417 "./marpa.w"
gint t_id;
/*:610*//*620:*/
#line 5460 "./marpa.w"

Marpa_Phase t_phase;
/*:620*//*631:*/
#line 5506 "./marpa.w"
guint t_earley_item_warning_threshold;
/*:631*//*637:*/
#line 5534 "./marpa.w"
EARLEME t_furthest_earleme;
/*:637*//*712:*/
#line 5941 "./marpa.w"

gint t_earley_set_count;
/*:712*/
#line 5365 "./marpa.w"

/*669:*/
#line 5709 "./marpa.w"

guint t_use_leo_flag:1;
guint t_is_using_leo:1;
/*:669*//*675:*/
#line 5753 "./marpa.w"
guint t_is_exhausted:1;
/*:675*//*828:*/
#line 7169 "./marpa.w"

guint t_trace_source_type:3;
/*:828*/
#line 5366 "./marpa.w"

};

/*:604*/
#line 13586 "./marpa.w"

/*803:*/
#line 6884 "./marpa.w"

struct s_source{
gpointer t_predecessor;
union{
gpointer t_completion;
TOK t_token;
}t_cause;
};

/*:803*//*805:*/
#line 6896 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:805*//*806:*/
#line 6902 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:806*//*807:*/
#line 6909 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:807*/
#line 13587 "./marpa.w"

/*736:*/
#line 6136 "./marpa.w"

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
/*743:*/
#line 6243 "./marpa.w"

guint t_source_type:3;

/*:743*/
#line 6147 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:736*/
#line 13588 "./marpa.w"

/*1095:*/
#line 10424 "./marpa.w"

struct s_bocage{
/*1023:*/
#line 9418 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:1023*//*1098:*/
#line 10440 "./marpa.w"

struct obstack t_obs;
/*:1098*//*1165:*/
#line 11241 "./marpa.w"

RANK_Object t_rank;
/*:1165*/
#line 10426 "./marpa.w"

/*1024:*/
#line 9421 "./marpa.w"

gint t_or_node_count;
gint t_and_node_count;
ORID t_top_or_node_id;

/*:1024*/
#line 10427 "./marpa.w"

/*1099:*/
#line 10442 "./marpa.w"

unsigned int is_obstack_initialized:1;
/*:1099*/
#line 10428 "./marpa.w"

};
typedef struct s_bocage BOC_Object;
/*:1095*/
#line 13589 "./marpa.w"

/*63:*/
#line 766 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid);

/*:63*//*118:*/
#line 1032 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:118*//*120:*/
#line 1045 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:120*//*122:*/
#line 1054 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g);

/*:122*//*138:*/
#line 1133 "./marpa.w"

static inline
SYM symbol_new(struct marpa_g*g);
/*:138*//*143:*/
#line 1163 "./marpa.w"

static inline void symbol_free(SYM symbol);

/*:143*//*152:*/
#line 1199 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id);

/*:152*//*159:*/
#line 1226 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id);

/*:159*//*189:*/
#line 1362 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol);
/*:189*//*195:*/
#line 1403 "./marpa.w"

static inline SYM symbol_proper_alias(SYM symbol);
/*:195*//*198:*/
#line 1431 "./marpa.w"

static inline SYM symbol_null_alias(SYM symbol);
/*:198*//*201:*/
#line 1442 "./marpa.w"

static inline
SYM symbol_alias_create(GRAMMAR g,SYM symbol);
/*:201*//*210:*/
#line 1495 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:210*//*216:*/
#line 1521 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length);
/*:216*//*234:*/
#line 1751 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length);
/*:234*//*246:*/
#line 1931 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
/*:246*//*250:*/
#line 1943 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule);
/*:250*//*254:*/
#line 1959 "./marpa.w"

static inline gsize rule_length_get(RULE rule);
/*:254*//*268:*/
#line 2039 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule);
/*:268*//*272:*/
#line 2063 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule);
/*:272*//*286:*/
#line 2125 "./marpa.w"

static inline gint rule_is_nulling(GRAMMAR g,RULE rule);

/*:286*//*321:*/
#line 2268 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);
/*:321*//*342:*/
#line 2360 "./marpa.w"

static inline gint symbol_instance_of_ahfa_item_get(AIM aim);
/*:342*//*349:*/
#line 2478 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:349*//*386:*/
#line 2829 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:386*//*425:*/
#line 3202 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:425*//*428:*/
#line 3223 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:428*//*436:*/
#line 3353 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:436*//*455:*/
#line 3587 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id);

/*:455*//*472:*/
#line 3708 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:472*//*477:*/
#line 3783 "./marpa.w"

static gint cmp_by_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:477*//*480:*/
#line 3802 "./marpa.w"

static gint cmp_by_postdot_and_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:480*//*500:*/
#line 3989 "./marpa.w"

static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM aim_sought);
/*:500*//*512:*/
#line 4075 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id);


/*:512*//*532:*/
#line 4248 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b);
/*:532*//*535:*/
#line 4274 "./marpa.w"

PRIVATE_NOT_INLINE void create_AHFA_states(struct marpa_g*g);
/*:535*//*554:*/
#line 4784 "./marpa.w"

static inline AHFA assign_AHFA_state(
AHFA state_p,GTree*duplicates);
/*:554*//*567:*/
#line 4981 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:567*//*570:*/
#line 5038 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
);
/*:570*//*583:*/
#line 5212 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition);
/*:583*//*585:*/
#line 5219 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition);
/*:585*//*587:*/
#line 5227 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix);
/*:587*//*589:*/
#line 5240 "./marpa.w"
static inline
TRANS*transitions_new(struct marpa_g*g);
/*:589*//*591:*/
#line 5254 "./marpa.w"

static inline
void transition_add(struct obstack*obstack,AHFA from_ahfa,SYMID symid,AHFA to_ahfa);
/*:591*//*593:*/
#line 5271 "./marpa.w"

static inline
void completion_count_inc(struct obstack*obstack,AHFA from_ahfa,SYMID symid);
/*:593*//*629:*/
#line 5494 "./marpa.w"

static inline ES current_es_of_r(RECCE r);
/*:629*//*683:*/
#line 5800 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint value);
/*:683*//*685:*/
#line 5812 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*value);

/*:685*//*687:*/
#line 5821 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r);

/*:687*//*714:*/
#line 5947 "./marpa.w"

static inline ES earley_set_new(RECCE r,EARLEME id);
/*:714*//*737:*/
#line 6157 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key);
/*:737*//*739:*/
#line 6179 "./marpa.w"

static inline
EIM earley_item_assign(const RECCE r,const ES set,const ES origin,const AHFA state);
/*:739*//*744:*/
#line 6246 "./marpa.w"

static const char*invalid_source_type_message(guint type);
/*:744*//*758:*/
#line 6399 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r);
/*:758*//*760:*/
#line 6408 "./marpa.w"

Marpa_Earley_Set_ID marpa_earley_item_origin(struct marpa_r*r);
/*:760*//*768:*/
#line 6500 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r);
/*:768*//*771:*/
#line 6541 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r);
/*:771*//*773:*/
#line 6562 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r);
/*:773*//*781:*/
#line 6644 "./marpa.w"

static inline PIM*pim_sym_p_find(ES set,SYMID symid);
/*:781*//*783:*/
#line 6666 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid);
/*:783*//*794:*/
#line 6809 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r);
/*:794*//*811:*/
#line 6949 "./marpa.w"
static inline void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
TOK token);
/*:811*//*813:*/
#line 6981 "./marpa.w"
static inline void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause);
/*:813*//*820:*/
#line 7088 "./marpa.w"
static inline void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause);

/*:820*//*823:*/
#line 7129 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item);

/*:823*//*853:*/
#line 7424 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r);
/*:853*//*875:*/
#line 7705 "./marpa.w"

static inline
TOK token_new(struct marpa_r*r,SYMID symbol_id,gpointer value);
/*:875*//*883:*/
#line 7761 "./marpa.w"

static inline gint alternative_insertion_point(RECCE r,ALT new_alternative);
/*:883*//*885:*/
#line 7802 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b);
/*:885*//*887:*/
#line 7826 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme);
/*:887*//*889:*/
#line 7843 "./marpa.w"

static inline gint alternative_insert(RECCE r,ALT alternative);
/*:889*//*932:*/
#line 8297 "./marpa.w"

static inline void earley_set_update_items(RECCE r,ES set);
/*:932*//*934:*/
#line 8321 "./marpa.w"

static inline void r_update_earley_sets(RECCE r);
/*:934*//*937:*/
#line 8347 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES set);
/*:937*//*986:*/
#line 8921 "./marpa.w"

static inline void ur_node_stack_init(URS stack);
/*:986*//*988:*/
#line 8931 "./marpa.w"

static inline void ur_node_stack_reset(URS stack);
/*:988*//*990:*/
#line 8938 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack);
/*:990*//*992:*/
#line 8948 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev);
/*:992*//*994:*/
#line 8959 "./marpa.w"

static inline void ur_node_push(URS stack,EIM earley_item,AEX aex);
/*:994*//*996:*/
#line 8977 "./marpa.w"

static inline UR ur_node_pop(URS stack);
/*:996*//*1001:*/
#line 9074 "./marpa.w"

static inline gint psia_test_and_set(
struct obstack*obs,
struct s_bocage_setup_per_es*per_es_data,
EIM earley_item,
AEX ahfa_element_ix);
/*:1001*//*1038:*/
#line 9677 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base);
/*:1038*//*1040:*/
#line 9691 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item);
/*:1040*//*1047:*/
#line 9811 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause);
/*:1047*//*1050:*/
#line 9837 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause);
/*:1050*//*1078:*/
#line 10276 "./marpa.w"

gint marpa_and_node_count(struct marpa_r*r);
/*:1078*//*1081:*/
#line 10314 "./marpa.w"

gint marpa_and_node_parent(struct marpa_r*r,int and_node_id);
/*:1081*//*1083:*/
#line 10325 "./marpa.w"

gint marpa_and_node_predecessor(struct marpa_r*r,int and_node_id);
/*:1083*//*1085:*/
#line 10341 "./marpa.w"

gint marpa_and_node_cause(struct marpa_r*r,int and_node_id);
/*:1085*//*1087:*/
#line 10357 "./marpa.w"

gint marpa_and_node_symbol(struct marpa_r*r,int and_node_id);
/*:1087*//*1091:*/
#line 10401 "./marpa.w"

SYMID and_node_token(AND and_node,gpointer*value_p);
/*:1091*//*1120:*/
#line 10722 "./marpa.w"

static inline void bocage_destroy(struct marpa_r*r);
/*:1120*//*1124:*/
#line 10765 "./marpa.w"

gint marpa_or_node_set(struct marpa_r*r,int or_node_id);
/*:1124*//*1126:*/
#line 10776 "./marpa.w"

gint marpa_or_node_origin(struct marpa_r*r,int or_node_id);
/*:1126*//*1128:*/
#line 10787 "./marpa.w"

gint marpa_or_node_rule(struct marpa_r*r,int or_node_id);
/*:1128*//*1130:*/
#line 10798 "./marpa.w"

gint marpa_or_node_position(struct marpa_r*r,int or_node_id);
/*:1130*//*1132:*/
#line 10809 "./marpa.w"

gint marpa_or_node_first_and(struct marpa_r*r,int or_node_id);
/*:1132*//*1134:*/
#line 10820 "./marpa.w"

gint marpa_or_node_last_and(struct marpa_r*r,int or_node_id);
/*:1134*//*1136:*/
#line 10832 "./marpa.w"

gint marpa_or_node_and_count(struct marpa_r*r,int or_node_id);
/*:1136*//*1140:*/
#line 10883 "./marpa.w"

static inline void tree_exhaust(TREE tree);
/*:1140*//*1142:*/
#line 10904 "./marpa.w"

static inline void tree_safe(TREE tree);
/*:1142*//*1146:*/
#line 10962 "./marpa.w"

static inline void tree_and_node_claim(TREE tree,ANDID and_node_id);
static inline void tree_and_node_release(TREE tree,ANDID and_node_id);
static inline gint tree_and_node_try(TREE tree,ANDID and_node_id);
/*:1146*//*1153:*/
#line 11117 "./marpa.w"

static inline gint or_node_next_choice(BOC b,TREE tree,OR or_node,gint start_choice);
/*:1153*//*1157:*/
#line 11159 "./marpa.w"

static inline void tree_destroy(TREE tree);
/*:1157*//*1161:*/
#line 11195 "./marpa.w"

gint marpa_tree_size(struct marpa_r*r);
/*:1161*//*1167:*/
#line 11246 "./marpa.w"

static inline void rank_safe(RANK rank);
/*:1167*//*1170:*/
#line 11258 "./marpa.w"

static inline void rank_freeze(RANK rank);
static inline void rank_destroy(RANK rank);
/*:1170*//*1178:*/
#line 11420 "./marpa.w"

static inline ANDID and_order_get(BOC b,OR or_node,gint ix);
/*:1178*//*1187:*/
#line 11542 "./marpa.w"

gint marpa_fork_or_node(struct marpa_r*r,int fork_id);
/*:1187*//*1189:*/
#line 11554 "./marpa.w"

gint marpa_fork_choice(struct marpa_r*r,int fork_id);
/*:1189*//*1191:*/
#line 11574 "./marpa.w"

gint marpa_fork_parent(struct marpa_r*r,int fork_id);
/*:1191*//*1193:*/
#line 11586 "./marpa.w"

gint marpa_fork_cause_is_ready(struct marpa_r*r,int fork_id);
/*:1193*//*1195:*/
#line 11598 "./marpa.w"

gint marpa_fork_predecessor_is_ready(struct marpa_r*r,int fork_id);
/*:1195*//*1197:*/
#line 11610 "./marpa.w"

gint marpa_fork_is_cause(struct marpa_r*r,int fork_id);
/*:1197*//*1199:*/
#line 11622 "./marpa.w"

gint marpa_fork_is_predecessor(struct marpa_r*r,int fork_id);
/*:1199*//*1206:*/
#line 11695 "./marpa.w"

static inline void val_safe(VAL val);
/*:1206*//*1212:*/
#line 11777 "./marpa.w"

static inline void val_destroy(VAL val);
/*:1212*//*1225:*/
#line 11959 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:1225*//*1227:*/
#line 11969 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:1227*//*1228:*/
#line 11973 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);
/*:1228*//*1230:*/
#line 11993 "./marpa.w"

static inline Bit_Vector bv_obs_create(struct obstack*obs,guint bits);
/*:1230*//*1233:*/
#line 12026 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:1233*//*1235:*/
#line 12045 "./marpa.w"

static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from);

/*:1235*//*1237:*/
#line 12058 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:1237*//*1239:*/
#line 12068 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:1239*//*1241:*/
#line 12076 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:1241*//*1243:*/
#line 12089 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:1243*//*1245:*/
#line 12093 "./marpa.w"

static inline void bv_clear(Bit_Vector bv);
/*:1245*//*1247:*/
#line 12109 "./marpa.w"

static inline void bv_over_clear(Bit_Vector bv,guint bit);
/*:1247*//*1251:*/
#line 12123 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:1251*//*1253:*/
#line 12131 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:1253*//*1255:*/
#line 12139 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:1255*//*1257:*/
#line 12144 "./marpa.w"

static inline gboolean bv_bit_test_and_set(Bit_Vector vector,guint bit);
/*:1257*//*1261:*/
#line 12172 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:1261*//*1263:*/
#line 12185 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:1263*//*1265:*/
#line 12197 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1265*//*1267:*/
#line 12209 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1267*//*1269:*/
#line 12221 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:1269*//*1271:*/
#line 12295 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:1271*//*1273:*/
#line 12313 "./marpa.w"

static inline guint bv_count(Bit_Vector v);

/*:1273*//*1279:*/
#line 12402 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:1279*//*1284:*/
#line 12450 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:1284*//*1286:*/
#line 12458 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:1286*//*1288:*/
#line 12472 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:1288*//*1290:*/
#line 12490 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:1290*//*1293:*/
#line 12499 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:1293*//*1296:*/
#line 12508 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:1296*//*1299:*/
#line 12517 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:1299*//*1301:*/
#line 12570 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:1301*//*1311:*/
#line 12676 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_size);

/*:1311*//*1326:*/
#line 12809 "./marpa.w"

static inline void psar_init(const PSAR psar,gint length);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
/*:1326*//*1332:*/
#line 12867 "./marpa.w"

static inline void psar_reset(const PSAR psar);
/*:1332*//*1334:*/
#line 12886 "./marpa.w"

static inline void psar_dealloc(const PSAR psar);
/*:1334*//*1336:*/
#line 12907 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar);
/*:1336*//*1340:*/
#line 12933 "./marpa.w"

static inline PSL psl_alloc(const PSAR psar);
/*:1340*//*1376:*/
#line 13235 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags);
/*:1376*//*1388:*/
#line 13337 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id);

/*:1388*//*1396:*/
#line 13368 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id);

/*:1396*//*1398:*/
#line 13411 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*eim_tag_safe(gchar*buffer,EIM eim);
PRIVATE_NOT_INLINE gchar*eim_tag(EIM eim);
#endif
/*:1398*//*1400:*/
#line 13439 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*lim_tag_safe(gchar*buffer,LIM lim);
PRIVATE_NOT_INLINE gchar*lim_tag(LIM lim);
#endif
/*:1400*//*1402:*/
#line 13469 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*or_tag_safe(gchar*buffer,OR or);
PRIVATE_NOT_INLINE const gchar*or_tag(OR or);
#endif
/*:1402*//*1404:*/
#line 13505 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*aim_tag_safe(gchar*buffer,AIM aim);
PRIVATE_NOT_INLINE const gchar*aim_tag(AIM aim);
#endif
/*:1404*/
#line 13590 "./marpa.w"

/*61:*/
#line 750 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symid,
SYM symbol)
{
g_array_insert_val(g->t_symbols,(unsigned)symid,symbol);
}

/*:61*//*70:*/
#line 794 "./marpa.w"

static inline
void rule_add(
struct marpa_g*g,
RULEID rule_id,
RULE rule)
{
g_array_insert_val(g->t_rules,(unsigned)rule_id,rule);
LV_Size_of_G(g)+= 1+Length_of_RULE(rule);
g->t_max_rule_length= MAX(Length_of_RULE(rule),g->t_max_rule_length);
}

/*:70*/
#line 13591 "./marpa.w"

/*37:*/
#line 637 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:37*//*43:*/
#line 683 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*51:*/
#line 713 "./marpa.w"

g->t_id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:51*//*55:*/
#line 726 "./marpa.w"

g->t_symbols= g_array_new(FALSE,FALSE,sizeof(SYM));
/*:55*//*65:*/
#line 775 "./marpa.w"

g->t_rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:65*//*73:*/
#line 813 "./marpa.w"

Default_Value_of_G(g)= NULL;
/*:73*//*79:*/
#line 833 "./marpa.w"

g->t_start_symid= -1;
/*:79*//*85:*/
#line 860 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;

/*:85*//*88:*/
#line 885 "./marpa.w"

LV_Size_of_G(g)= 0;

/*:88*//*91:*/
#line 898 "./marpa.w"

g->t_max_rule_length= 0;

/*:91*//*95:*/
#line 906 "./marpa.w"

g->t_is_precomputed= FALSE;
/*:95*//*98:*/
#line 914 "./marpa.w"

g->t_has_loop= FALSE;
/*:98*//*102:*/
#line 929 "./marpa.w"

g->t_is_lhs_terminal_ok= TRUE;
/*:102*//*108:*/
#line 963 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:108*//*111:*/
#line 977 "./marpa.w"

g->t_context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:111*//*126:*/
#line 1078 "./marpa.w"

obstack_init(&g->t_obs);
obstack_init(&g->t_obs_tricky);
/*:126*//*130:*/
#line 1098 "./marpa.w"

g->t_error= NULL;
/*:130*//*206:*/
#line 1473 "./marpa.w"

g->t_symbol_callback_arg= NULL;
g->t_symbol_callback= NULL;
/*:206*//*314:*/
#line 2249 "./marpa.w"

g->t_rule_callback_arg= NULL;
g->t_rule_callback= NULL;
/*:314*//*452:*/
#line 3574 "./marpa.w"

g->t_AHFA_items= NULL;
g->t_AHFA_items_by_rule= NULL;
/*:452*//*507:*/
#line 4045 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:507*//*1384:*/
#line 13313 "./marpa.w"

g->t_message_callback_arg= NULL;
g->t_message_callback= NULL;
/*:1384*/
#line 686 "./marpa.w"

return g;}
/*:43*//*45:*/
#line 691 "./marpa.w"

void marpa_g_free(struct marpa_g*g)
{/*56:*/
#line 728 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->t_symbols->len;id++)
{symbol_free(SYM_by_ID(id));}}
g_array_free(g->t_symbols,TRUE);

/*:56*//*66:*/
#line 777 "./marpa.w"

g_array_free(g->t_rules,TRUE);

/*:66*//*109:*/
#line 964 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:109*//*112:*/
#line 979 "./marpa.w"
g_hash_table_destroy(Context_of_G(g));

/*:112*//*127:*/
#line 1081 "./marpa.w"

obstack_free(&g->t_obs,NULL);
obstack_free(&g->t_obs_tricky,NULL);

/*:127*//*453:*/
#line 3577 "./marpa.w"

if(g->t_AHFA_items){g_free(g->t_AHFA_items);};
if(g->t_AHFA_items_by_rule){g_free(g->t_AHFA_items_by_rule);};

/*:453*//*508:*/
#line 4049 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*509:*/
#line 4059 "./marpa.w"
{
TRANS*ahfa_transitions= LV_TRANSs_of_AHFA(ahfa_state);
if(ahfa_transitions)
g_free(TRANSs_of_AHFA(ahfa_state));
}

/*:509*/
#line 4053 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:508*/
#line 693 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:45*//*52:*/
#line 715 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->t_id;}
/*:52*//*57:*/
#line 736 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->t_symbols;}
/*:57*//*62:*/
#line 761 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid){
return symid>=0&&(guint)symid<g->t_symbols->len;
}
/*:62*//*67:*/
#line 783 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->t_rules;}
/*:67*//*75:*/
#line 817 "./marpa.w"

gpointer marpa_default_value(struct marpa_g*g)
{return Default_Value_of_G(g);}
/*:75*//*77:*/
#line 822 "./marpa.w"

gboolean marpa_default_value_set(struct marpa_g*g,gpointer default_value)
{
/*1355:*/
#line 13083 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1355*/
#line 825 "./marpa.w"

/*1358:*/
#line 13093 "./marpa.w"

if(G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar precomputed";
return failure_indicator;
}
/*:1358*/
#line 826 "./marpa.w"

Default_Value_of_G(g)= default_value;
return TRUE;
}

/*:77*//*80:*/
#line 835 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->t_start_symid;}
/*:80*//*82:*/
#line 842 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1355:*/
#line 13083 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1355*/
#line 845 "./marpa.w"

/*1358:*/
#line 13093 "./marpa.w"

if(G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar precomputed";
return failure_indicator;
}
/*:1358*/
#line 846 "./marpa.w"

/*1360:*/
#line 13105 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1360*/
#line 847 "./marpa.w"

g->t_start_symid= symid;
return TRUE;
}
/*:82*//*96:*/
#line 908 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g)
{return G_is_Precomputed(g);}

/*:96*//*99:*/
#line 917 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->t_has_loop;}
/*:99*//*103:*/
#line 932 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->t_is_lhs_terminal_ok;}
/*:103*//*105:*/
#line 939 "./marpa.w"

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
/*:105*//*117:*/
#line 1022 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value
= g_new(struct marpa_context_int_value,1);
value->t_type= MARPA_CONTEXT_INT;
value->t_data= payload;
g_hash_table_insert(Context_of_G(g),(gpointer)key,value);
}
/*:117*//*119:*/
#line 1035 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value
= g_new(struct marpa_context_const_value,1);
value->t_type= MARPA_CONTEXT_CONST;
value->t_data= payload;
g_hash_table_insert(Context_of_G(g),(gpointer)key,value);
}
/*:119*//*121:*/
#line 1051 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g){
g_hash_table_remove_all(Context_of_G(g));}
/*:121*//*123:*/
#line 1057 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(Context_of_G(g),key);}
/*:123*//*132:*/
#line 1106 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g)
{return g->t_error?g->t_error:"unknown error";}
/*:132*//*139:*/
#line 1136 "./marpa.w"

static inline SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= g_malloc(sizeof(SYM_Object));
/*145:*/
#line 1170 "./marpa.w"
LV_ID_of_SYM(symbol)= g->t_symbols->len;

/*:145*//*147:*/
#line 1179 "./marpa.w"

symbol->t_lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:147*//*154:*/
#line 1209 "./marpa.w"

symbol->t_rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:154*//*161:*/
#line 1231 "./marpa.w"

symbol->t_is_accessible= FALSE;
/*:161*//*165:*/
#line 1249 "./marpa.w"

symbol->t_is_counted= FALSE;
/*:165*//*169:*/
#line 1267 "./marpa.w"

symbol->t_is_nullable= FALSE;
/*:169*//*173:*/
#line 1286 "./marpa.w"

symbol->t_is_nulling= FALSE;
/*:173*//*177:*/
#line 1306 "./marpa.w"

symbol->t_is_terminal= FALSE;
/*:177*//*183:*/
#line 1332 "./marpa.w"

symbol->t_is_productive= FALSE;
/*:183*//*187:*/
#line 1350 "./marpa.w"
symbol->t_is_start= FALSE;
/*:187*//*193:*/
#line 1380 "./marpa.w"

symbol->t_is_proper_alias= FALSE;
symbol->t_is_nulling_alias= FALSE;
symbol->t_alias= NULL;

/*:193*/
#line 1141 "./marpa.w"

{
SYMID id= ID_of_SYM(symbol);
g_symbol_add(g,id,symbol);
}
return symbol;
}

/*:139*//*141:*/
#line 1151 "./marpa.w"

Marpa_Symbol_ID
marpa_symbol_new(struct marpa_g*g)
{
SYMID id= ID_of_SYM(symbol_new(g));
symbol_callback(g,id);
return id;
}

/*:141*//*142:*/
#line 1160 "./marpa.w"

static inline void symbol_free(SYM symbol)
{/*148:*/
#line 1181 "./marpa.w"

g_array_free(symbol->t_lhs,TRUE);
/*:148*//*155:*/
#line 1211 "./marpa.w"
g_array_free(symbol->t_rhs,TRUE);

/*:155*/
#line 1162 "./marpa.w"
g_free(symbol);}
/*:142*//*149:*/
#line 1186 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1356:*/
#line 13085 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1356*/
#line 1188 "./marpa.w"

/*1360:*/
#line 13105 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1360*/
#line 1189 "./marpa.w"

return SYM_by_ID(symid)->t_lhs;}
/*:149*//*151:*/
#line 1193 "./marpa.w"
static inline
void symbol_lhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id)
{symbol_lhs_add(SYM_by_ID(symid),rule_id);}
/*:151*//*156:*/
#line 1216 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1356:*/
#line 13085 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1356*/
#line 1218 "./marpa.w"

/*1360:*/
#line 13105 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1360*/
#line 1219 "./marpa.w"

return SYM_by_ID(symid)->t_rhs;}
/*:156*//*158:*/
#line 1223 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_rhs,rule_id);}
/*:158*//*162:*/
#line 1241 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_accessible;}
/*:162*//*166:*/
#line 1259 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_counted;}
/*:166*//*170:*/
#line 1277 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_nullable;}
/*:170*//*174:*/
#line 1296 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 1298 "./marpa.w"

/*1360:*/
#line 13105 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1360*/
#line 1299 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(symid));}
/*:174*//*178:*/
#line 1318 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYMID_is_Terminal(id);}
/*:178*//*180:*/
#line 1323 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYMID_is_Terminal(id)= value;}
/*:180*//*184:*/
#line 1342 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(id)->t_is_productive;}
/*:184*//*188:*/
#line 1353 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol)
{return symbol->t_is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 1358 "./marpa.w"

/*1360:*/
#line 13105 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1360*/
#line 1359 "./marpa.w"

return symbol_is_start(SYM_by_ID(symid));
}
/*:188*//*194:*/
#line 1389 "./marpa.w"

static inline
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 1397 "./marpa.w"

/*1360:*/
#line 13105 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1360*/
#line 1398 "./marpa.w"

symbol= SYM_by_ID(symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}
/*:194*//*197:*/
#line 1412 "./marpa.w"

static inline
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 1420 "./marpa.w"

/*1360:*/
#line 13105 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1360*/
#line 1421 "./marpa.w"

symbol= SYM_by_ID(symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
g_context_int_add(g,"symid",symid);
g->t_error= "no alias";
return-1;
}
return ID_of_SYM(alias);
}
/*:197*//*202:*/
#line 1445 "./marpa.w"
static inline
SYM symbol_alias_create(GRAMMAR g,SYM symbol)
{
SYM alias= symbol_new(g);
symbol->t_is_proper_alias= TRUE;
SYM_is_Nulling(symbol)= FALSE;
symbol->t_is_nullable= FALSE;
symbol->t_alias= alias;
alias->t_is_nulling_alias= TRUE;
SYM_is_Nulling(alias)= TRUE;
alias->t_is_nullable= TRUE;
alias->t_is_productive= TRUE;
alias->t_is_accessible= symbol->t_is_accessible;
alias->t_alias= symbol;
return alias;
}

/*:202*//*207:*/
#line 1476 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->t_symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->t_symbol_callback_arg= cb_arg;}
gpointer marpa_symbol_callback_arg(struct marpa_g*g)
{return g->t_symbol_callback_arg;}
/*:207*//*209:*/
#line 1491 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->t_symbol_callback;
if(cb){(*cb)(g,id);}}
/*:209*//*217:*/
#line 1527 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,gint length)
{
/*1356:*/
#line 13085 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1356*/
#line 1532 "./marpa.w"

RULE rule;
const gint rule_sizeof= G_STRUCT_OFFSET(struct s_rule,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
/*243:*/
#line 1911 "./marpa.w"

{
SYMID symid= lhs;
/*1360:*/
#line 13105 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1360*/
#line 1914 "./marpa.w"

}
{gint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1360:*/
#line 13105 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1360*/
#line 1919 "./marpa.w"

}
}

/*:243*/
#line 1536 "./marpa.w"

rule= obstack_alloc(&g->t_obs,rule_sizeof);
/*244:*/
#line 1923 "./marpa.w"

Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
{gint i;for(i= 0;i<length;i++){
rule->t_symbols[i+1]= rhs[i];}}
/*:244*/
#line 1538 "./marpa.w"

/*259:*/
#line 1979 "./marpa.w"
rule->t_id= g->t_rules->len;

/*:259*//*262:*/
#line 1991 "./marpa.w"

rule->t_is_discard= FALSE;
/*:262*//*276:*/
#line 2075 "./marpa.w"

rule->t_is_loop= FALSE;
/*:276*//*281:*/
#line 2096 "./marpa.w"

rule->t_is_virtual_loop= FALSE;
/*:281*//*288:*/
#line 2131 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:288*//*292:*/
#line 2147 "./marpa.w"

rule->t_is_start= FALSE;
/*:292*//*296:*/
#line 2178 "./marpa.w"

RULE_is_Virtual_LHS(rule)= FALSE;
/*:296*//*300:*/
#line 2193 "./marpa.w"

RULE_is_Virtual_RHS(rule)= FALSE;
/*:300*//*304:*/
#line 2210 "./marpa.w"
rule->t_virtual_start= -1;
/*:304*//*308:*/
#line 2226 "./marpa.w"
rule->t_virtual_end= -1;
/*:308*//*325:*/
#line 2283 "./marpa.w"
rule->t_original= -1;
/*:325*//*330:*/
#line 2302 "./marpa.w"
Real_SYM_Count_of_RULE(rule)= 0;
/*:330*//*334:*/
#line 2315 "./marpa.w"

rule->t_is_semantic_equivalent= FALSE;
/*:334*//*341:*/
#line 2358 "./marpa.w"

Last_Proper_SYMI_of_RULE(rule)= -1;
/*:341*/
#line 1539 "./marpa.w"

rule_add(g,rule->t_id,rule);
/*236:*/
#line 1789 "./marpa.w"

symbol_lhs_add(SYM_by_ID(rule->t_symbols[0]),rule->t_id);
if(Length_of_RULE(rule)> 0){
gint rh_list_ix;
const guint alloc_size= Length_of_RULE(rule)*sizeof(SYMID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*240:*/
#line 1856 "./marpa.w"

{

gint rhs_ix= Length_of_RULE(rule)-1;
rh_symbol_list[0]= RHS_ID_of_RULE(rule,(unsigned)rhs_ix);
rh_symbol_list_length= 1;
rhs_ix--;
for(;rhs_ix>=0;rhs_ix--){
gint higher_ix;
Marpa_Symbol_ID new_symid= RHS_ID_of_RULE(rule,(unsigned)rhs_ix);
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

/*:240*/
#line 1797 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(rh_symbol_list[rh_list_ix]),
rule->t_id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:236*/
#line 1541 "./marpa.w"

return rule;
}

/*:217*//*219:*/
#line 1548 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
Marpa_Rule_ID rule_id;
RULE rule;
if(length> MAX_RHS_LENGTH){
g->t_error= (Marpa_Error_ID)"rhs too long";
return-1;
}
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

/*:219*//*221:*/
#line 1573 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 1578 "./marpa.w"

Marpa_Rule_ID original_rule_id;
RULE original_rule;
Marpa_Symbol_ID internal_lhs_id,*temp_rhs;
if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE){
g_context_clear(g);
g->t_error= (Marpa_Error_ID)"duplicate rule";
return failure_indicator;
}

/*222:*/
#line 1605 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){
g_context_clear(g);
g->t_error= "internal_error";
return failure_indicator;
}
RULE_is_Used(original_rule)= 0;
original_rule_id= original_rule->t_id;
original_rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION)
&&separator_id>=0;
rule_callback(g,original_rule_id);

/*:222*/
#line 1588 "./marpa.w"

/*223:*/
#line 1618 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g_context_clear(g);
g_context_int_add(g,"symid",separator_id);
g->t_error= "bad separator";
return failure_indicator;
}

/*:223*/
#line 1589 "./marpa.w"

/*224:*/
#line 1626 "./marpa.w"

SYM_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(separator_id)->t_is_counted= 1;}
/*:224*/
#line 1590 "./marpa.w"

if(min==0){/*225:*/
#line 1629 "./marpa.w"

{RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1365:*/
#line 13140 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1365*/
#line 1631 "./marpa.w"
}
rule->t_is_semantic_equivalent= TRUE;
rule->t_original= original_rule_id;
rule_callback(g,rule->t_id);
}
/*:225*/
#line 1591 "./marpa.w"
}
min= 1;
/*226:*/
#line 1636 "./marpa.w"

internal_lhs_id= ID_of_SYM(symbol_new(g));
symbol_callback(g,internal_lhs_id);
/*:226*/
#line 1593 "./marpa.w"

/*227:*/
#line 1650 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:227*/
#line 1594 "./marpa.w"

/*229:*/
#line 1653 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1365:*/
#line 13140 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1365*/
#line 1657 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;

RULE_is_Virtual_RHS(rule)= TRUE;
rule_callback(g,rule->t_id);
}
/*:229*/
#line 1595 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*230:*/
#line 1665 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1365:*/
#line 13140 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1365*/
#line 1670 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;
RULE_is_Virtual_RHS(rule)= TRUE;
Real_SYM_Count_of_RULE(rule)= 1;
rule_callback(g,rule->t_id);
}
/*:230*/
#line 1597 "./marpa.w"

}
/*231:*/
#line 1680 "./marpa.w"

{RULE rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1365:*/
#line 13140 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1365*/
#line 1690 "./marpa.w"
}
RULE_is_Virtual_LHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix;
rule_callback(g,rule->t_id);
}
/*:231*/
#line 1599 "./marpa.w"

/*232:*/
#line 1695 "./marpa.w"

{RULE rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1365:*/
#line 13140 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1365*/
#line 1702 "./marpa.w"
}
RULE_is_Virtual_LHS(rule)= 1;
RULE_is_Virtual_RHS(rule)= 1;
Real_SYM_Count_of_RULE(rule)= rhs_ix-1;
rule_callback(g,rule->t_id);
}

/*:232*/
#line 1600 "./marpa.w"

/*228:*/
#line 1652 "./marpa.w"
g_free(temp_rhs);
/*:228*/
#line 1601 "./marpa.w"

return original_rule_id;
}
/*:221*//*235:*/
#line 1755 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length)
{
gint ix;
SYM lhs= SYM_by_ID(lhs_id);
GArray*same_lhs_array= lhs->t_lhs;
gint same_lhs_count= same_lhs_array->len;
for(ix= 0;ix<same_lhs_count;ix++){
RULEID same_lhs_rule_id= ((RULEID*)(same_lhs_array->data))[ix];
gint rhs_position;
RULE rule= RULE_by_ID(g,same_lhs_rule_id);
const gint rule_length= Length_of_RULE(rule);
if(rule_length!=length){goto RULE_IS_NOT_DUPLICATE;}
for(rhs_position= 0;rhs_position<rule_length;rhs_position++){
if(RHS_ID_of_RULE(rule,rhs_position)!=rhs_ids[rhs_position]){
goto RULE_IS_NOT_DUPLICATE;
}
}
return TRUE;
RULE_IS_NOT_DUPLICATE:;
}
return FALSE;
}

/*:235*//*245:*/
#line 1928 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule){
return rule->t_symbols[0];}
/*:245*//*247:*/
#line 1933 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 1935 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 1936 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));}
/*:247*//*249:*/
#line 1940 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule){
return rule->t_symbols+1;}
/*:249*//*252:*/
#line 1947 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,gint ix){
RULE rule;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 1950 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 1951 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:252*//*253:*/
#line 1956 "./marpa.w"

static inline gsize rule_length_get(RULE rule){
return Length_of_RULE(rule);}
/*:253*//*255:*/
#line 1961 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 1963 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 1964 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}
/*:255*//*263:*/
#line 1993 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_discard;}
/*:263*//*267:*/
#line 2026 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(lhs_id)->t_is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2033 "./marpa.w"

RULE rule;
/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2035 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:267*//*271:*/
#line 2046 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++){
Marpa_Symbol_ID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_by_ID(rhs_id)->t_is_productive)return FALSE;
}
return TRUE;}
gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2057 "./marpa.w"

RULE rule;
/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2059 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}
/*:271*//*277:*/
#line 2079 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2082 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2083 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}
/*:277*//*282:*/
#line 2100 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2103 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2104 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;}
/*:282*//*285:*/
#line 2112 "./marpa.w"

static inline gint
rule_is_nulling(GRAMMAR g,RULE rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++)
{
SYMID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_is_Nulling(SYM_by_ID(rhs_id)))
return FALSE;
}
return TRUE;
}
/*:285*//*289:*/
#line 2135 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2138 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2139 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}
/*:289*//*293:*/
#line 2151 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2154 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2155 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_start;}
/*:293*//*297:*/
#line 2181 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2184 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2185 "./marpa.w"

return RULE_is_Virtual_LHS(RULE_by_ID(g,rule_id));}
/*:297*//*301:*/
#line 2196 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2199 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2200 "./marpa.w"

return RULE_is_Virtual_RHS(RULE_by_ID(g,rule_id));}
/*:301*//*305:*/
#line 2211 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2214 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2215 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}
/*:305*//*309:*/
#line 2227 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2230 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2231 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}
/*:309*//*315:*/
#line 2252 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->t_rule_callback= cb;}
/*:315*//*317:*/
#line 2257 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->t_rule_callback_arg= cb_arg;}
/*:317*//*319:*/
#line 2262 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g)
{return g->t_rule_callback_arg;}
/*:319*//*322:*/
#line 2273 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->t_rule_callback;
if(cb){(*cb)(g,id);}}

/*:322*//*326:*/
#line 2284 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2287 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2288 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_original;
}
/*:326*//*332:*/
#line 2305 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2308 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2309 "./marpa.w"

return Real_SYM_Count_of_RULE(RULE_by_ID(g,rule_id));
}

/*:332*//*337:*/
#line 2328 "./marpa.w"

Marpa_Rule_ID
marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
RULE rule;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 2333 "./marpa.w"

/*1361:*/
#line 13112 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1361*/
#line 2334 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(RULE_is_Virtual_LHS(rule))return-1;
if(rule->t_is_semantic_equivalent)return rule->t_original;
return rule_id;
}

/*:337*//*344:*/
#line 2374 "./marpa.w"

static inline gint
symbol_instance_of_ahfa_item_get(AIM aim)
{
gint position= Position_of_AIM(aim);
const gint null_count= Null_Count_of_AIM(aim);
if(position<0||position-null_count> 0){

const RULE rule= RULE_of_AIM(aim);
position= Position_of_AIM(aim-1);
return SYMI_of_RULE(rule)+position;
}
return-1;
}

/*:344*//*345:*/
#line 2400 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
if(!census(g))return NULL;
if(!CHAF_rewrite(g))return NULL;
if(!g_augment(g))return NULL;
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*601:*/
#line 5346 "./marpa.w"
{
gint symbol_count= SYM_Count_of_G(g);
gint symid;
Bit_Vector bv_is_terminal= bv_create((guint)symbol_count);
g->t_bv_symid_is_terminal= bv_is_terminal;
for(symid= 0;symid<symbol_count;symid++){
if(!SYMID_is_Terminal(symid))continue;
bv_bit_set(bv_is_terminal,(guint)symid);
}
}

/*:601*/
#line 2409 "./marpa.w"

return g;
}
/*:345*//*348:*/
#line 2447 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*1356:*/
#line 13085 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1356*/
#line 2450 "./marpa.w"

/*350:*/
#line 2480 "./marpa.w"

guint pre_rewrite_rule_count= g->t_rules->len;
guint pre_rewrite_symbol_count= g->t_symbols->len;

/*:350*//*355:*/
#line 2517 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_start_symid;
SYM original_start_symbol;

/*:355*//*359:*/
#line 2556 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:359*//*365:*/
#line 2615 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:365*//*367:*/
#line 2642 "./marpa.w"

Bit_Vector nullable_v;
/*:367*//*371:*/
#line 2668 "./marpa.w"

Bit_Vector productive_v;
/*:371*//*374:*/
#line 2709 "./marpa.w"
Bit_Matrix reach_matrix;
/*:374*//*377:*/
#line 2727 "./marpa.w"

Bit_Vector accessible_v;

/*:377*/
#line 2451 "./marpa.w"

/*351:*/
#line 2484 "./marpa.w"

if(g->t_rules->len<=0){g->t_error= "no rules";return NULL;}
/*:351*/
#line 2452 "./marpa.w"

/*352:*/
#line 2491 "./marpa.w"

if(G_is_Precomputed(g)){g->t_error= "precomputed";return NULL;}
/*:352*/
#line 2453 "./marpa.w"

/*354:*/
#line 2497 "./marpa.w"

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
original_start_symbol= SYM_by_ID(original_start_symid);
if(original_start_symbol->t_lhs->len<=0){
g_context_clear(g);
g_context_int_add(g,"symid",original_start_symid);
g->t_error= "start symbol not on LHS";
return failure_indicator;
}

/*:354*/
#line 2454 "./marpa.w"

/*356:*/
#line 2521 "./marpa.w"

{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;
rule_id<(Marpa_Rule_ID)pre_rewrite_rule_count;
rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
bv_bit_set(lhs_v,(guint)lhs_id);
if(Length_of_RULE(rule)<=0){
bv_bit_set(empty_lhs_v,(guint)lhs_id);
have_empty_rule= 1;
}
}
}
/*:356*/
#line 2455 "./marpa.w"

/*357:*/
#line 2540 "./marpa.w"

{Marpa_Symbol_ID symid;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symid= 0;
symid<(Marpa_Symbol_ID)pre_rewrite_symbol_count;
symid++){
SYM symbol= SYM_by_ID(symid);
if(SYM_is_Terminal(symbol)){
bv_bit_set(terminal_v,(guint)symid);
have_marked_terminals= 1;
}
}}
/*:357*/
#line 2456 "./marpa.w"

if(have_marked_terminals){
/*361:*/
#line 2571 "./marpa.w"

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
#line 2458 "./marpa.w"

}else{
/*360:*/
#line 2560 "./marpa.w"

if(have_empty_rule&&g->t_is_lhs_terminal_ok){
g->t_error= "empty rule and unmarked terminals";
return NULL;
}
/*:360*/
#line 2460 "./marpa.w"
;
if(g->t_is_lhs_terminal_ok){
/*362:*/
#line 2595 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->t_symbols->len;symid++)
{SYMID_is_Terminal(symid)= 1;}}
/*:362*/
#line 2462 "./marpa.w"

}else{
/*363:*/
#line 2600 "./marpa.w"

{guint start= 0;
guint min,max;
bv_not(terminal_v,lhs_v);
while(bv_scan(terminal_v,start,&min,&max)){
Marpa_Symbol_ID symid;
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
SYMID_is_Terminal(symid)= 1;
}
start= max+2;
}
}
/*:363*/
#line 2464 "./marpa.w"

}
}
/*366:*/
#line 2620 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;symid<=(Marpa_Symbol_ID)max;symid++){
SYM symbol= SYM_by_ID(symid);
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
#line 2467 "./marpa.w"

/*369:*/
#line 2647 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(symid);
symbol->t_is_productive= 1;
}}
}
/*:369*/
#line 2468 "./marpa.w"

/*370:*/
#line 2661 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->t_start_symid))
{
g_context_int_add(g,"symid",g->t_start_symid);
g->t_error= "unproductive start symbol";
return NULL;
}
/*:370*/
#line 2469 "./marpa.w"

/*373:*/
#line 2691 "./marpa.w"

reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{guint symid,no_of_symbols= SYM_Count_of_G(g);
for(symid= 0;symid<no_of_symbols;symid++){
matrix_bit_set(reach_matrix,symid,symid);
}}
{Marpa_Rule_ID rule_id;
guint no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
guint rhs_ix,rule_length= Length_of_RULE(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,
(guint)lhs_id,(guint)RHS_ID_of_RULE(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:373*/
#line 2470 "./marpa.w"

/*376:*/
#line 2713 "./marpa.w"

accessible_v= matrix_row(reach_matrix,(guint)original_start_symid);
{guint min,max,start;
Marpa_Symbol_ID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symid= (Marpa_Symbol_ID)min;
symid<=(Marpa_Symbol_ID)max;
symid++){
SYM symbol= SYM_by_ID(symid);
symbol->t_is_accessible= 1;
}}
}
/*:376*/
#line 2471 "./marpa.w"

/*378:*/
#line 2732 "./marpa.w"

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
SYM_is_Nulling(SYM_by_ID(productive_id))= 1;
}
}
bv_free(reaches_terminal_v);
}

/*:378*/
#line 2472 "./marpa.w"

/*358:*/
#line 2552 "./marpa.w"

bv_free(terminal_v);
/*:358*//*364:*/
#line 2612 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:364*//*368:*/
#line 2644 "./marpa.w"

bv_free(nullable_v);

/*:368*//*372:*/
#line 2670 "./marpa.w"

bv_free(productive_v);

/*:372*/
#line 2473 "./marpa.w"

/*375:*/
#line 2710 "./marpa.w"

matrix_free(reach_matrix);

/*:375*/
#line 2474 "./marpa.w"

g->t_is_precomputed= TRUE;
return g;
}
/*:348*//*385:*/
#line 2808 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*387:*/
#line 2831 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:387*//*391:*/
#line 2882 "./marpa.w"

gint factor_count;
gint*factor_positions;
/*:391*//*396:*/
#line 2931 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:396*/
#line 2811 "./marpa.w"

/*392:*/
#line 2885 "./marpa.w"

factor_positions= g_new(gint,g->t_max_rule_length);
/*:392*//*397:*/
#line 2934 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:397*/
#line 2812 "./marpa.w"

/*389:*/
#line 2843 "./marpa.w"

{gint no_of_symbols= SYM_Count_of_G(g);
Marpa_Symbol_ID symid;
for(symid= 0;symid<no_of_symbols;symid++){
SYM symbol= SYM_by_ID(symid);
SYM alias;
if(!symbol->t_is_nullable)continue;
if(SYM_is_Nulling(symbol))continue;
if(!symbol->t_is_accessible)continue;
if(!symbol->t_is_productive)continue;
if(symbol_null_alias(symbol))continue;
alias= symbol_alias_create(g,symbol);
symbol_callback(g,ID_of_SYM(alias));
}}

/*:389*/
#line 2813 "./marpa.w"

no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const gint rule_length= Length_of_RULE(rule);
gint nullable_suffix_ix= 0;
/*388:*/
#line 2835 "./marpa.w"

if(!RULE_is_Used(rule)){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}

/*:388*/
#line 2819 "./marpa.w"

/*390:*/
#line 2866 "./marpa.w"

{gint rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(symid);
if(SYM_is_Nulling(symbol))continue;
if(symbol_null_alias(symbol)){

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}}
/*:390*/
#line 2820 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*394:*/
#line 2891 "./marpa.w"

RULE_is_Used(rule)= 0;
{gint unprocessed_factor_count;

gint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);
gint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*400:*/
#line 2944 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symid;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*395:*/
#line 2910 "./marpa.w"
{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",LHS_ID_of_RULE(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symid);
}

/*:395*/
#line 2952 "./marpa.w"

/*401:*/
#line 2971 "./marpa.w"

{
gint remaining_rhs_length,piece_rhs_length;
/*402:*/
#line 2983 "./marpa.w"

{
gint real_symbol_count= piece_end-piece_start+1;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
remaining_rhs[piece_rhs_length]= 
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
}
{RULE chaf_rule;
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 2995 "./marpa.w"

}

/*:402*/
#line 2974 "./marpa.w"
;
/*403:*/
#line 2998 "./marpa.w"

{
gint chaf_rule_length= Length_of_RULE(rule)-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;remaining_rhs_length++)
{
Marpa_Symbol_ID original_id= 
RHS_ID_of_RULE(rule,piece_start+remaining_rhs_length);
SYM alias= symbol_null_alias(SYM_by_ID(original_id));
remaining_rhs[remaining_rhs_length]= 
alias?ID_of_SYM(alias):original_id;
}
}
{
RULE chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= 
rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3016 "./marpa.w"

}

/*:403*/
#line 2975 "./marpa.w"
;
/*404:*/
#line 3021 "./marpa.w"
{
Marpa_Symbol_ID proper_id= RHS_ID_of_RULE(rule,first_factor_position);
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
ID_of_SYM(alias);
}
{RULE chaf_rule;
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3031 "./marpa.w"

}

/*:404*/
#line 2976 "./marpa.w"
;
/*405:*/
#line 3040 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3045 "./marpa.w"

}

/*:405*/
#line 2977 "./marpa.w"
;
}

/*:401*/
#line 2953 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*395:*/
#line 2910 "./marpa.w"
{
SYM chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->t_is_accessible= 1;
chaf_virtual_symbol->t_is_productive= 1;
chaf_virtual_symid= ID_of_SYM(chaf_virtual_symbol);
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g_context_int_add(g,"lhs_id",LHS_ID_of_RULE(rule));
g_context_int_add(g,"virtual_end",(gint)piece_end);
symbol_callback(g,chaf_virtual_symid);
}

/*:395*/
#line 2958 "./marpa.w"

/*407:*/
#line 3050 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
gint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:407*//*408:*/
#line 3059 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3065 "./marpa.w"


/*:408*//*409:*/
#line 3068 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3073 "./marpa.w"


/*:409*//*410:*/
#line 3076 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3082 "./marpa.w"


/*:410*//*411:*/
#line 3085 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3088 "./marpa.w"


/*:411*//*412:*/
#line 3091 "./marpa.w"
}

/*:412*/
#line 2959 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:400*/
#line 2902 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*413:*/
#line 3095 "./marpa.w"
{
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
gint second_factor_piece_position= second_factor_position-piece_start;
gint real_symbol_count;
gint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:413*//*414:*/
#line 3109 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3114 "./marpa.w"


/*:414*//*415:*/
#line 3117 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3122 "./marpa.w"


/*:415*//*416:*/
#line 3125 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3131 "./marpa.w"


/*:416*//*417:*/
#line 3135 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3139 "./marpa.w"

}

/*:417*//*418:*/
#line 3143 "./marpa.w"
}

/*:418*/
#line 2905 "./marpa.w"

}else{
/*419:*/
#line 3146 "./marpa.w"
{
gint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
gint real_symbol_count;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:419*//*420:*/
#line 3157 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3162 "./marpa.w"


/*:420*//*421:*/
#line 3166 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*423:*/
#line 3182 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
RULE_is_Virtual_LHS(chaf_rule)= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !RULE_is_Virtual_LHS(chaf_rule);
RULE_is_Virtual_RHS(chaf_rule)= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
Real_SYM_Count_of_RULE(chaf_rule)= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:423*/
#line 3172 "./marpa.w"

}

/*:421*//*422:*/
#line 3176 "./marpa.w"
}

/*:422*/
#line 2907 "./marpa.w"

}}

/*:394*/
#line 2823 "./marpa.w"

NEXT_RULE:;
}
/*393:*/
#line 2887 "./marpa.w"

g_free(factor_positions);

/*:393*//*398:*/
#line 2937 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:398*/
#line 2826 "./marpa.w"

return g;
}
/*:385*//*424:*/
#line 3196 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
SYM alias= symbol_null_alias(SYM_by_ID(proper_id));
return ID_of_SYM(alias);
}
/*:424*//*427:*/
#line 3210 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g->t_start_symid);
/*429:*/
#line 3226 "./marpa.w"

if(SYM_is_Nulling(old_start)){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:429*/
#line 3218 "./marpa.w"

if(proper_old_start){/*430:*/
#line 3236 "./marpa.w"
{
RULE new_start_rule;
proper_old_start->t_is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= ID_of_SYM(proper_new_start);
g->t_start_symid= proper_new_start_id;
proper_new_start->t_is_accessible= TRUE;
proper_new_start->t_is_productive= TRUE;
proper_new_start->t_is_start= TRUE;
g_context_clear(g);
g_context_int_add(g,"old_start_id",ID_of_SYM(old_start));
symbol_callback(g,proper_new_start_id);
new_start_rule= rule_start(g,proper_new_start_id,&LV_ID_of_SYM(old_start),1);
new_start_rule->t_is_start= 1;
RULE_is_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= 1;
g->t_proper_start_rule= new_start_rule;
rule_callback(g,new_start_rule->t_id);
}

/*:430*/
#line 3219 "./marpa.w"
}
if(nulling_old_start){/*431:*/
#line 3261 "./marpa.w"
{
Marpa_Symbol_ID nulling_new_start_id;
RULE new_start_rule;
SYM nulling_new_start;
if(proper_new_start)
{
nulling_new_start= symbol_alias_create(g,proper_new_start);
nulling_new_start_id= ID_of_SYM(nulling_new_start);
}
else
{
nulling_new_start= symbol_new(g);
nulling_new_start_id= ID_of_SYM(nulling_new_start);
g->t_start_symid= nulling_new_start_id;
SYM_is_Nulling(nulling_new_start)= TRUE;
nulling_new_start->t_is_nullable= TRUE;
nulling_new_start->t_is_productive= TRUE;
nulling_new_start->t_is_accessible= TRUE;
}
nulling_new_start->t_is_start= TRUE;
g_context_clear(g);
g_context_int_add(g,"old_start_id",ID_of_SYM(old_start));
symbol_callback(g,nulling_new_start_id);
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
new_start_rule->t_is_start= 1;
RULE_is_Virtual_LHS(new_start_rule)= 1;
Real_SYM_Count_of_RULE(new_start_rule)= 1;
RULE_is_Used(new_start_rule)= TRUE;
g->t_null_start_rule= new_start_rule;
rule_callback(g,new_start_rule->t_id);
}

/*:431*/
#line 3220 "./marpa.w"
}
return g;
}
/*:427*//*435:*/
#line 3339 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{gint no_of_rules= RULE_Count_of_G(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create((guint)no_of_rules,(guint)no_of_rules);
/*437:*/
#line 3362 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID proper_id;
gint rhs_ix,rule_length;
if(!RULE_is_Used(rule))continue;
rule_length= Length_of_RULE(rule);
proper_id= -1;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(symid);
if(symbol->t_is_nullable)continue;
if(proper_id>=0)goto NEXT_RULE;

proper_id= symid;
}

if(proper_id<0)continue;

{SYM rhs_symbol= SYM_by_ID(proper_id);
GArray*lhs_rules= rhs_symbol->t_lhs;
gint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,(guint)rule_id,
(guint)g_array_index(lhs_rules,Marpa_Rule_ID,ix));
}}
NEXT_RULE:;
}}

/*:437*/
#line 3346 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*438:*/
#line 3401 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule;
if(!matrix_bit_test(unit_transition_matrix,(guint)rule_id,(guint)rule_id))
continue;
loop_rule_count++;
rule= RULE_by_ID(g,rule_id);
rule->t_is_loop= TRUE;
rule->t_is_virtual_loop= rule->t_virtual_start<0||!RULE_is_Virtual_RHS(rule);
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
grammar_message(g,"loop rule");
}}

/*:438*/
#line 3348 "./marpa.w"

if(loop_rule_count)g->t_has_loop= TRUE;
/*439:*/
#line 3422 "./marpa.w"

g_context_clear(g);
g_context_int_add(g,"loop_rule_count",loop_rule_count);
grammar_message(g,"loop rule tally");

/*:439*/
#line 3350 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:435*//*454:*/
#line 3582 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id){
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}
/*:454*//*460:*/
#line 3623 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 3625 "./marpa.w"

/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 3626 "./marpa.w"

return AIM_Count_of_G(g);
}
/*:460*//*462:*/
#line 3632 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 3635 "./marpa.w"

/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 3636 "./marpa.w"

/*1362:*/
#line 13119 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1362*/
#line 3637 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(item_id))->t_id;
}
/*:462*//*465:*/
#line 3646 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 3649 "./marpa.w"

/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 3650 "./marpa.w"

/*1362:*/
#line 13119 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1362*/
#line 3651 "./marpa.w"

return Position_of_AIM(AIM_by_ID(item_id));
}

/*:465*//*467:*/
#line 3658 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 3661 "./marpa.w"

/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 3662 "./marpa.w"

/*1362:*/
#line 13119 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1362*/
#line 3663 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(item_id));
}

/*:467*//*469:*/
#line 3669 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 3672 "./marpa.w"

/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 3673 "./marpa.w"

/*1362:*/
#line 13119 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1362*/
#line 3674 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(item_id));
}

/*:469*//*471:*/
#line 3685 "./marpa.w"

static inline
void create_AHFA_items(GRAMMAR g){
RULEID rule_id;
guint no_of_items;
guint no_of_rules= RULE_Count_of_G(g);
AIM base_item= g_new(struct s_AHFA_item,Size_of_G(g));
AIM current_item= base_item;
guint symbol_instance_of_next_rule= 0;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
if(RULE_is_Used(rule)){
/*473:*/
#line 3711 "./marpa.w"

{
gint leading_nulls= 0;
gint rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_RULE(rule);rhs_ix++)
{
SYMID rh_symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(rh_symid);
if(!symbol->t_is_nullable)
{
Last_Proper_SYMI_of_RULE(rule)= symbol_instance_of_next_rule+rhs_ix;
/*474:*/
#line 3735 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:474*/
#line 3722 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*475:*/
#line 3744 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:475*/
#line 3731 "./marpa.w"

current_item++;
}

/*:473*/
#line 3697 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_of_next_rule;
symbol_instance_of_next_rule+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
no_of_items= LV_AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*476:*/
#line 3758 "./marpa.w"

{
AIM*items_by_rule= g_new(AIM,no_of_rules);
AIM items= g->t_AHFA_items;

Marpa_Rule_ID highest_found_rule_id= -1;
Marpa_AHFA_Item_ID item_id;


for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++)
{
items_by_rule[rule_id]= NULL;
}
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
AIM item= items+item_id;
Marpa_Rule_ID rule_id_for_item= RULE_of_AIM(item)->t_id;
if(rule_id_for_item<=highest_found_rule_id)
continue;
items_by_rule[rule_id_for_item]= item;
highest_found_rule_id= rule_id_for_item;
}
g->t_AHFA_items_by_rule= items_by_rule;
}

/*:476*/
#line 3705 "./marpa.w"

/*483:*/
#line 3834 "./marpa.w"

{
Marpa_AHFA_Item_ID item_id;
AIM*sort_array= g_new(struct s_AHFA_item*,no_of_items);
AIM items= g->t_AHFA_items;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
sort_array[item_id]= items+item_id;
}
g_qsort_with_data(sort_array,
(gint)no_of_items,sizeof(AIM),cmp_by_postdot_and_aimid,
(gpointer)NULL);
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++)
{
Sort_Key_of_AIM(sort_array[item_id])= item_id;
}
g_free(sort_array);
}

/*:483*/
#line 3706 "./marpa.w"

}
/*:471*//*479:*/
#line 3793 "./marpa.w"

static gint cmp_by_aimid(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED){
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:479*//*482:*/
#line 3811 "./marpa.w"

static gint cmp_by_postdot_and_aimid(gconstpointer ap,
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

/*:482*//*501:*/
#line 3999 "./marpa.w"

static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM sought_aim)
{
AIM*const aims= AIMs_of_AHFA(ahfa);
gint aim_count= AIM_Count_of_AHFA(ahfa);
gint hi= aim_count-1;
gint lo= 0;
while(hi>=lo){
gint trial_aex= lo+(hi-lo)/2;
AIM trial_aim= aims[trial_aex];
if(trial_aim==sought_aim)return trial_aex;
if(trial_aim<sought_aim){
lo= trial_aex+1;
}else{
hi= trial_aex-1;
}
}
return-1;
}

/*:501*//*511:*/
#line 4070 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id){
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}
/*:511*//*515:*/
#line 4089 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return AHFA_Count_of_G(g);
}
/*:515*//*517:*/
#line 4096 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 4099 "./marpa.w"

AHFA state;
/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 4101 "./marpa.w"

/*1363:*/
#line 13126 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1363*/
#line 4102 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}
/*:517*//*520:*/
#line 4115 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
guint item_ix){
AHFA state;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 4120 "./marpa.w"

/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 4121 "./marpa.w"

/*1363:*/
#line 13126 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1363*/
#line 4122 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
if(item_ix>=state->t_item_count){
g_context_clear(g);
g_context_int_add(g,"item_ix",(gint)item_ix);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid state item ix";
return failure_indicator;
}
return AIMID_of_AHFA_by_AEX(g,state,item_ix);
}

/*:520*//*521:*/
#line 4134 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 4138 "./marpa.w"

/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 4139 "./marpa.w"

/*1363:*/
#line 13126 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1363*/
#line 4140 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}
/*:521*//*526:*/
#line 4179 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
const gint no_completed_start_rule= -1;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 4183 "./marpa.w"

AHFA state;
/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 4185 "./marpa.w"

/*1363:*/
#line 13126 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1363*/
#line 4186 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
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
/*1365:*/
#line 13140 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1365*/
#line 4202 "./marpa.w"

}
return no_completed_start_rule;
}

/*:526*//*530:*/
#line 4221 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 4224 "./marpa.w"

AHFA state;
/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 4226 "./marpa.w"

/*1363:*/
#line 13126 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1363*/
#line 4227 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:530*//*533:*/
#line 4250 "./marpa.w"

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

/*:533*//*536:*/
#line 4276 "./marpa.w"

PRIVATE_NOT_INLINE
void create_AHFA_states(struct marpa_g*g){
/*537:*/
#line 4295 "./marpa.w"

AHFA p_working_state;
const guint initial_no_of_states= 2*Size_of_G(g);
AIM AHFA_item_0_p= g->t_AHFA_items;
const guint symbol_count_of_g= SYM_Count_of_G(g);
const guint rule_count_of_g= RULE_Count_of_G(g);
Bit_Matrix prediction_matrix;
RULE*rule_by_sort_key= g_new(RULE,rule_count_of_g);
GTree*duplicates;
AHFA*singleton_duplicates;
DQUEUE_DECLARE(states);
struct obstack ahfa_work_obs;
gint ahfa_count_of_g;
AHFA ahfas_of_g;

/*:537*/
#line 4279 "./marpa.w"

/*538:*/
#line 4310 "./marpa.w"

/*539:*/
#line 4314 "./marpa.w"

{
guint item_id;
guint no_of_items_in_grammar= AIM_Count_of_G(g);
obstack_init(&ahfa_work_obs);
duplicates= g_tree_new(AHFA_state_cmp);
singleton_duplicates= g_new(AHFA,no_of_items_in_grammar);
for(item_id= 0;item_id<no_of_items_in_grammar;item_id++)
{
singleton_duplicates[item_id]= NULL;
}
}

/*:539*/
#line 4311 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:538*/
#line 4280 "./marpa.w"

/*561:*/
#line 4860 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_create(symbol_count_of_g,symbol_count_of_g);
/*562:*/
#line 4869 "./marpa.w"

{
RULEID rule_id;
SYMID symid;
AIM*items_by_rule= g->t_AHFA_items_by_rule;
for(symid= 0;symid<(SYMID)symbol_count_of_g;symid++)
{

SYM symbol= SYM_by_ID(symid);
if(!SYMBOL_LHS_RULE_COUNT(symbol))
continue;
matrix_bit_set(symbol_by_symbol_matrix,(guint)symid,(guint)symid);
}
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
SYMID from,to;

AIM item= items_by_rule[rule_id];

if(!item)
continue;
from= LHS_ID_of_AIM(item);
to= Postdot_SYMID_of_AIM(item);

if(to<0)
continue;

matrix_bit_set(symbol_by_symbol_matrix,(guint)from,(guint)to);
}
}

/*:562*/
#line 4863 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*563:*/
#line 4906 "./marpa.w"
{
AIM*items_by_rule= g->t_AHFA_items_by_rule;
SYMID from_symid;
guint*sort_key_by_rule_id= g_new(guint,rule_count_of_g);
guint no_of_predictable_rules= 0;
/*564:*/
#line 4936 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
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

/*:564*/
#line 4912 "./marpa.w"

/*565:*/
#line 4956 "./marpa.w"

{
RULEID rule_id;
for(rule_id= 0;rule_id<(RULEID)rule_count_of_g;rule_id++)
{
rule_by_sort_key[rule_id]= RULE_by_ID(g,rule_id);
}
g_qsort_with_data(rule_by_sort_key,(gint)rule_count_of_g,
sizeof(RULE),cmp_by_rule_sort_key,
(gpointer)sort_key_by_rule_id);
}

/*:565*/
#line 4913 "./marpa.w"

/*568:*/
#line 4988 "./marpa.w"

{
guint sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:568*/
#line 4914 "./marpa.w"

/*569:*/
#line 4998 "./marpa.w"

{
prediction_matrix= matrix_create(symbol_count_of_g,no_of_predictable_rules);
for(from_symid= 0;from_symid<(SYMID)symbol_count_of_g;
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

SYM to_symbol= SYM_by_ID(to_symid);
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

/*:569*/
#line 4915 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:563*/
#line 4865 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:561*/
#line 4281 "./marpa.w"

/*546:*/
#line 4448 "./marpa.w"
{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
Marpa_Rule_ID start_rule_id;
AIM start_item;
SYM start_symbol= SYM_by_ID(g->t_start_symid);
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
LV_TRANSs_of_AHFA(p_initial_state)= transitions_new(g);
p_initial_state->t_empty_transition= NULL;
if(SYM_is_Nulling(start_symbol))
{
SYMID*complete_symids= obstack_alloc(&g->t_obs,sizeof(SYMID));
SYMID completed_symbol_id= ID_of_SYM(start_symbol);
*complete_symids= completed_symbol_id;
completion_count_inc(&ahfa_work_obs,p_initial_state,completed_symbol_id);
LV_Complete_SYMIDs_of_AHFA(p_initial_state)= complete_symids;
LV_Complete_SYM_Count_of_AHFA(p_initial_state)= 1;
p_initial_state->t_has_completed_start_rule= 1;
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
SYMID*complete_symids= obstack_alloc(&g->t_obs,sizeof(SYMID));
SYMID completed_symbol_id= ID_of_SYM(start_alias);
*complete_symids= completed_symbol_id;
completion_count_inc(&ahfa_work_obs,p_initial_state,completed_symbol_id);
LV_Complete_SYMIDs_of_AHFA(p_initial_state)= complete_symids;
LV_Complete_SYM_Count_of_AHFA(p_initial_state)= 1;
p_initial_state->t_has_completed_start_rule= 1;
}
else
{
LV_Complete_SYM_Count_of_AHFA(p_initial_state)= 0;
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

/*:546*/
#line 4282 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*540:*/
#line 4327 "./marpa.w"
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
/*548:*/
#line 4549 "./marpa.w"
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
transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
goto NEXT_WORKING_SYMBOL;
}
p_new_state= DQUEUE_PUSH(states,AHFA_Object);

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
p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
LV_TRANSs_of_AHFA(p_new_state)= transitions_new(g);
transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
postdot= Postdot_SYMID_of_AIM(single_item_p);
if(postdot>=0)
{
LV_Complete_SYM_Count_of_AHFA(p_new_state)= 0;
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
SYMID lhs_id= LHS_ID_of_AIM(single_item_p);
SYMID*complete_symids= obstack_alloc(&g->t_obs,sizeof(SYMID));
*complete_symids= lhs_id;
LV_Complete_SYMIDs_of_AHFA(p_new_state)= complete_symids;
completion_count_inc(&ahfa_work_obs,p_new_state,lhs_id);
LV_Complete_SYM_Count_of_AHFA(p_new_state)= 1;
p_new_state->t_postdot_sym_count= 0;
p_new_state->t_empty_transition= NULL;
/*550:*/
#line 4639 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(predot_symid))
> 0)
{
LV_Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:550*/
#line 4607 "./marpa.w"

}
}

/*:548*/
#line 4347 "./marpa.w"

}else{
/*551:*/
#line 4664 "./marpa.w"
{
AHFA p_new_state;
guint predecessor_ix;
guint no_of_new_items_so_far= 0;
AIM*item_list_for_new_state;
AHFA queued_AHFA_state;
p_new_state= DQUEUE_PUSH(states,AHFA_Object);
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

(void)DQUEUE_POP(states,AHFA_Object);
obstack_free(&g->t_obs_tricky,item_list_for_new_state);
transition_add(&ahfa_work_obs,p_working_state,working_symbol,queued_AHFA_state);


goto NEXT_WORKING_SYMBOL;
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE(states,AHFA_Object);
LV_AHFA_is_Predicted(p_new_state)= 0;
p_new_state->t_has_completed_start_rule= 0;
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
LV_TRANSs_of_AHFA(p_new_state)= transitions_new(g);
/*552:*/
#line 4715 "./marpa.w"

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
gint complete_symbol_id= LHS_ID_of_AIM(item);
completion_count_inc(&ahfa_work_obs,p_new_state,complete_symbol_id);
bv_bit_set(complete_v,(guint)complete_symbol_id);
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
if((no_of_complete_symbols= 
LV_Complete_SYM_Count_of_AHFA(p_new_state)= bv_count(complete_v)))
{
guint min,max,start;
SYMID*complete_symids= obstack_alloc(&g->t_obs,
no_of_complete_symbols*
sizeof(SYMID));
SYMID*p_symbol= complete_symids;
LV_Complete_SYMIDs_of_AHFA(p_new_state)= complete_symids;
for(start= 0;bv_scan(complete_v,start,&min,&max);start= max+2)
{
SYMID complete_symbol_id;
for(complete_symbol_id= (SYMID)min;complete_symbol_id<=(SYMID)max;
complete_symbol_id++)
{
*p_symbol++= complete_symbol_id;
}
}
}
bv_free(postdot_v);
bv_free(complete_v);
}

/*:552*/
#line 4709 "./marpa.w"

transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
/*556:*/
#line 4798 "./marpa.w"
{
guint item_ix;
Marpa_Symbol_ID postdot= -1;
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++){
postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot>=0)break;
}
p_new_state->t_empty_transition= NULL;
if(postdot>=0)
{
Bit_Vector predicted_rule_vector
= bv_shadow(matrix_row(prediction_matrix,(guint)postdot));
for(item_ix= 0;item_ix<no_of_items_in_new_state;item_ix++)
{

postdot= Postdot_SYMID_of_AIM(item_list_for_new_state[item_ix]);
if(postdot<0)
continue;
bv_or_assign(predicted_rule_vector,
matrix_row(prediction_matrix,(guint)postdot));
}

p_new_state->t_empty_transition= create_predicted_AHFA_state(g,
predicted_rule_vector,
rule_by_sort_key,
&states,
duplicates);
bv_free(predicted_rule_vector);
}
}

/*:556*/
#line 4712 "./marpa.w"

}

/*:551*/
#line 4349 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:540*/
#line 4284 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*541:*/
#line 4359 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
guint symbol_id;
AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
for(symbol_id= 0;symbol_id<symbol_count_of_g;symbol_id++){
TRANS working_transition= transitions[symbol_id];
if(working_transition){
gint completion_count= Completion_Count_of_TRANS(working_transition);
gint sizeof_transition= 
G_STRUCT_OFFSET(struct s_transition,t_aex)+completion_count*
sizeof(transitions[0]->t_aex[0]);
TRANS new_transition= obstack_alloc(&g->t_obs,sizeof_transition);
LV_To_AHFA_of_TRANS(new_transition)= To_AHFA_of_TRANS(working_transition);
LV_Completion_Count_of_TRANS(new_transition)= 0;
transitions[symbol_id]= new_transition;
}
}
}
}

/*:541*/
#line 4289 "./marpa.w"

/*543:*/
#line 4411 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++)
{
AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
AIM*aims= AIMs_of_AHFA(ahfa);
gint aim_count= AIM_Count_of_AHFA(ahfa);
AEX aex;
g_qsort_with_data(aims,aim_count,sizeof(AIM*),cmp_by_aimid,NULL);
for(aex= 0;aex<aim_count;aex++)
{
AIM ahfa_item= aims[aex];
SYMID postdot= Postdot_SYMID_of_AIM(ahfa_item);
if(postdot>=0)
{
TRANS transition= transitions[postdot];
AHFA to_ahfa= To_AHFA_of_TRANS(transition);
if(!AHFA_is_Leo_Completion(to_ahfa))
continue;
Leo_Base_AEX_of_TRANS(transition)= aex;
}
}
}
}

/*:543*/
#line 4290 "./marpa.w"

/*542:*/
#line 4382 "./marpa.w"

{
gint ahfa_id;
for(ahfa_id= 0;ahfa_id<ahfa_count_of_g;ahfa_id++){
const AHFA ahfa= AHFA_of_G_by_ID(g,ahfa_id);
TRANS*const transitions= TRANSs_of_AHFA(ahfa);
if(Complete_SYM_Count_of_AHFA(ahfa)> 0){
AIM*aims= AIMs_of_AHFA(ahfa);
gint aim_count= AIM_Count_of_AHFA(ahfa);
AEX aex;
for(aex= 0;aex<aim_count;aex++){
AIM ahfa_item= aims[aex];
if(AIM_is_Completion(ahfa_item)){
SYMID completed_symbol_id= LHS_ID_of_AIM(ahfa_item);
TRANS transition= transitions[completed_symbol_id];
AEX*aexes= AEXs_of_TRANS(transition);
gint aex_ix= LV_Completion_Count_of_TRANS(transition)++;
MARPA_OFF_DEBUG4("Added completion aex at %d for ahfa_id=%d sym=%d",
aex_ix,ahfa_id,completed_symbol_id);
aexes[aex_ix]= aex;
}
}
}
}
}

/*:542*/
#line 4291 "./marpa.w"

/*544:*/
#line 4438 "./marpa.w"

g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*545:*/
#line 4444 "./marpa.w"

g_free(singleton_duplicates);
g_tree_destroy(duplicates);

/*:545*/
#line 4441 "./marpa.w"

obstack_free(&ahfa_work_obs,NULL);

/*:544*/
#line 4292 "./marpa.w"

}

/*:536*//*555:*/
#line 4787 "./marpa.w"

static inline AHFA
assign_AHFA_state(AHFA sought_state,GTree*duplicates)
{
const AHFA state_found= g_tree_lookup(duplicates,sought_state);
if(state_found)return state_found;
g_tree_insert(duplicates,sought_state,sought_state);
return NULL;
}

/*:555*//*566:*/
#line 4968 "./marpa.w"
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
/*:566*//*571:*/
#line 5047 "./marpa.w"

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
p_new_state= DQUEUE_PUSH((*states_p),AHFA_Object);
p_new_state->t_items= item_list_for_new_state;
p_new_state->t_item_count= no_of_items_in_new_state;
{AHFA queued_AHFA_state= assign_AHFA_state(p_new_state,duplicates);
if(queued_AHFA_state){


(void)DQUEUE_POP((*states_p),AHFA_Object);
obstack_free(&g->t_obs,item_list_for_new_state);
return queued_AHFA_state;
}
}

p_new_state->t_key.t_id= p_new_state-DQUEUE_BASE((*states_p),AHFA_Object);
LV_AHFA_is_Predicted(p_new_state)= 1;
p_new_state->t_has_completed_start_rule= 0;
LV_Leo_LHS_ID_of_AHFA(p_new_state)= -1;
p_new_state->t_empty_transition= NULL;
LV_TRANSs_of_AHFA(p_new_state)= transitions_new(g);
LV_Complete_SYM_Count_of_AHFA(p_new_state)= 0;
/*572:*/
#line 5102 "./marpa.w"

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

/*:572*/
#line 5098 "./marpa.w"

return p_new_state;
}

/*:571*//*584:*/
#line 5214 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition){
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:584*//*586:*/
#line 5221 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition){
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:586*//*588:*/
#line 5230 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix){
URTRANS transition;
transition= obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:588*//*590:*/
#line 5242 "./marpa.w"
static inline
TRANS*transitions_new(struct marpa_g*g){
gint symbol_count= SYM_Count_of_G(g);
gint symid= 0;
TRANS*transitions;
transitions= g_malloc(symbol_count*sizeof(transitions[0]));
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:590*//*592:*/
#line 5257 "./marpa.w"

static inline
void transition_add(struct obstack*obstack,AHFA from_ahfa,SYMID symid,AHFA to_ahfa)
{
TRANS*transitions= TRANSs_of_AHFA(from_ahfa);
TRANS transition= transitions[symid];
if(!transition){
transitions[symid]= (TRANS)transition_new(obstack,to_ahfa,0);
return;
}
LV_To_AHFA_of_TRANS(transition)= to_ahfa;
return;
}

/*:592*//*594:*/
#line 5274 "./marpa.w"

static inline
void completion_count_inc(struct obstack*obstack,AHFA from_ahfa,SYMID symid)
{
TRANS*transitions= TRANSs_of_AHFA(from_ahfa);
TRANS transition= transitions[symid];
if(!transition){
transitions[symid]= (TRANS)transition_new(obstack,NULL,1);
return;
}
LV_Completion_Count_of_TRANS(transition)++;
return;
}

/*:594*//*596:*/
#line 5293 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 5298 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
gint symbol_count;

/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 5304 "./marpa.w"

/*1363:*/
#line 13126 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1363*/
#line 5305 "./marpa.w"

/*1364:*/
#line 13133 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
g_context_clear(g);
g_context_int_add(g,"expected size",sizeof(gint));
g->t_error= "garray size mismatch";
return failure_indicator;
}
/*:1364*/
#line 5306 "./marpa.w"

from_ahfa_state= AHFA_of_G_by_ID(g,AHFA_state_id);
transitions= TRANSs_of_AHFA(from_ahfa_state);
symbol_count= SYM_Count_of_G(g);
g_array_set_size(result,0);
for(symid= 0;symid<symbol_count;symid++){
AHFA to_ahfa_state= To_AHFA_of_TRANS(transitions[symid]);
if(!to_ahfa_state)continue;
g_array_append_val(result,symid);
g_array_append_val(result,ID_of_AHFA(to_ahfa_state));
}
return result->len;
}

/*:596*//*600:*/
#line 5329 "./marpa.w"

AHFAID marpa_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 5334 "./marpa.w"

/*1359:*/
#line 13099 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1359*/
#line 5335 "./marpa.w"

/*1363:*/
#line 13126 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1363*/
#line 5336 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:600*//*606:*/
#line 5377 "./marpa.w"

struct marpa_r*marpa_r_new(struct marpa_g*g)
{RECCE r;
gint symbol_count_of_g;
/*1356:*/
#line 13085 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1356*/
#line 5381 "./marpa.w"

if(!G_is_Precomputed(g)){
g->t_error= "precomputed";
return failure_indicator;
}
r= g_slice_new(struct marpa_r);
r->t_grammar= g;
symbol_count_of_g= SYM_Count_of_G(g);
/*691:*/
#line 5835 "./marpa.w"
obstack_init(&r->t_obs);
/*:691*/
#line 5389 "./marpa.w"

/*613:*/
#line 5420 "./marpa.w"

r->t_id= g_atomic_int_exchange_and_add(&next_recce_id,1);
/*:613*//*621:*/
#line 5462 "./marpa.w"

Phase_of_R(r)= initial_phase;
/*:621*//*625:*/
#line 5477 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:625*//*632:*/
#line 5507 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:632*//*638:*/
#line 5535 "./marpa.w"
r->t_furthest_earleme= 0;
/*:638*//*643:*/
#line 5554 "./marpa.w"
r->t_sym_workarea= NULL;
/*:643*//*647:*/
#line 5569 "./marpa.w"
r->t_workarea2= NULL;
/*:647*//*651:*/
#line 5593 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:651*//*655:*/
#line 5616 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:655*//*670:*/
#line 5712 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:670*//*676:*/
#line 5754 "./marpa.w"
r->t_is_exhausted= 0;
/*:676*//*680:*/
#line 5780 "./marpa.w"

r->t_context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:680*//*695:*/
#line 5851 "./marpa.w"

r->t_error= NULL;
r->t_fatal_error= NULL;
/*:695*//*713:*/
#line 5943 "./marpa.w"

r->t_earley_set_count= 0;

/*:713*//*719:*/
#line 5992 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:719*//*747:*/
#line 6274 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:747*//*786:*/
#line 6684 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:786*//*829:*/
#line 7171 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:829*//*873:*/
#line 7682 "./marpa.w"

{
gpointer default_value= Default_Value_of_G(g);
gint i;
TOK*tokens_by_symid;
obstack_init(TOK_Obs);
tokens_by_symid= 
obstack_alloc(TOK_Obs,sizeof(TOK)*symbol_count_of_g);
for(i= 0;i<symbol_count_of_g;i++)
{
tokens_by_symid[i]= token_new(r,i,default_value);
}
TOKs_by_SYMID_of_R(r)= tokens_by_symid;
}
/*:873*//*881:*/
#line 7754 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:881*//*907:*/
#line 8050 "./marpa.w"
DSTACK_SAFE(r->t_eim_work_stack);
/*:907*//*911:*/
#line 8061 "./marpa.w"
DSTACK_SAFE(r->t_completion_stack);
/*:911*//*915:*/
#line 8072 "./marpa.w"
DSTACK_SAFE(r->t_earley_set_stack);
/*:915*//*984:*/
#line 8916 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:984*//*1097:*/
#line 10434 "./marpa.w"

B_of_R(r)= NULL;

/*:1097*//*1324:*/
#line 12805 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1324*//*1392:*/
#line 13350 "./marpa.w"

r->t_message_callback_arg= NULL;
r->t_message_callback= NULL;
/*:1392*/
#line 5390 "./marpa.w"

return r;}

/*:606*//*607:*/
#line 5393 "./marpa.w"

void marpa_r_free(struct marpa_r*r)
{
/*681:*/
#line 5782 "./marpa.w"
g_hash_table_destroy(Context_of_R(r));

/*:681*//*716:*/
#line 5969 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
if(EIMs_of_ES(set))
g_free(EIMs_of_ES(set));
}
}

/*:716*//*874:*/
#line 7696 "./marpa.w"

{
TOK*tokens_by_symid= TOKs_by_SYMID_of_R(r);
if(tokens_by_symid){
obstack_free(TOK_Obs,NULL);
TOKs_by_SYMID_of_R(r)= NULL;
}
}

/*:874*//*882:*/
#line 7756 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:882*//*909:*/
#line 8054 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:909*//*913:*/
#line 8065 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:913*//*916:*/
#line 8073 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:916*//*985:*/
#line 8918 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:985*//*1117:*/
#line 10703 "./marpa.w"
bocage_destroy(r);

/*:1117*//*1325:*/
#line 12807 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1325*/
#line 5396 "./marpa.w"

if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*653:*/
#line 5602 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:653*//*657:*/
#line 5619 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:657*/
#line 5399 "./marpa.w"

/*692:*/
#line 5836 "./marpa.w"
obstack_free(&r->t_obs,NULL);

/*:692*/
#line 5400 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:607*//*614:*/
#line 5422 "./marpa.w"

gint marpa_r_id(struct marpa_r*r){return r->t_id;}
/*:614*//*623:*/
#line 5466 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r)
{return Phase_of_R(r);}

/*:623*//*628:*/
#line 5489 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:628*//*630:*/
#line 5496 "./marpa.w"

static inline ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:630*//*634:*/
#line 5511 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:634*//*636:*/
#line 5519 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold)
{
r->t_earley_item_warning_threshold= threshold==0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:636*//*640:*/
#line 5538 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:640*//*659:*/
#line 5631 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 5634 "./marpa.w"

guint min,max,start;
/*1373:*/
#line 13190 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
r_context_clear(r);
r_context_int_add(r,"expected size",sizeof(gint));
R_ERROR_CXT("garray size mismatch");
return failure_indicator;
}

/*:1373*/
#line 5636 "./marpa.w"

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

/*:659*//*672:*/
#line 5720 "./marpa.w"

gint marpa_is_use_leo(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 5723 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 5724 "./marpa.w"

return r->t_use_leo_flag?1:0;
}
/*:672*//*673:*/
#line 5729 "./marpa.w"

gboolean marpa_is_use_leo_set(
struct marpa_r*r,gboolean value)
{
/*1355:*/
#line 13083 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1355*/
#line 5733 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 5734 "./marpa.w"

/*1366:*/
#line 13149 "./marpa.w"

if(Phase_of_R(r)!=initial_phase){
R_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1366*/
#line 5735 "./marpa.w"

r->t_use_leo_flag= value;
return TRUE;
}
/*:673*//*678:*/
#line 5760 "./marpa.w"

gint marpa_is_exhausted(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 5763 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 5764 "./marpa.w"

return r->t_is_exhausted?1:0;
}

/*:678*//*682:*/
#line 5791 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->t_type= MARPA_CONTEXT_INT;
value->t_data= payload;
g_hash_table_insert(Context_of_R(r),(gpointer)key,value);
}
/*:682*//*684:*/
#line 5803 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->t_type= MARPA_CONTEXT_CONST;
value->t_data= payload;
g_hash_table_insert(Context_of_R(r),(gpointer)key,value);
}
/*:684*//*686:*/
#line 5818 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r){
g_hash_table_remove_all(Context_of_R(r));}
/*:686*//*688:*/
#line 5824 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key)
{return g_hash_table_lookup(Context_of_R(r),key);}
/*:688*//*697:*/
#line 5860 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r)
{return r->t_error?r->t_error:"unknown error";}
/*:697*//*715:*/
#line 5949 "./marpa.w"

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
EIM_Count_of_ES(set)= 0;
set->t_ordinal= r->t_earley_set_count++;
EIMs_of_ES(set)= NULL;
LV_Next_ES_of_ES(set)= NULL;
/*1331:*/
#line 12857 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1331*/
#line 5964 "./marpa.w"

return set;
}

/*:715*//*721:*/
#line 5997 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6000 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6002 "./marpa.w"

if(!trace_earley_set){
R_ERROR("no trace es");
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:721*//*723:*/
#line 6012 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6015 "./marpa.w"

/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6016 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:723*//*725:*/
#line 6030 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const gint es_does_not_exist= -1;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6034 "./marpa.w"

ES earley_set;
/*1367:*/
#line 13154 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1367*/
#line 6036 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 6037 "./marpa.w"

if(set_id<0){
R_ERROR("invalid es ordinal");
return failure_indicator;
}
r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
return es_does_not_exist;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return Earleme_of_ES(earley_set);
}

/*:725*//*728:*/
#line 6055 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6058 "./marpa.w"

ES earley_set;
/*1367:*/
#line 13154 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1367*/
#line 6060 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 6061 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
R_ERROR("invalid es ordinal");
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:728*//*738:*/
#line 6160 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1356:*/
#line 13085 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1356*/
#line 6164 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const guint count= ++EIM_Count_of_ES(set);
/*741:*/
#line 6214 "./marpa.w"

if(count>=r->t_earley_item_warning_threshold)
{
if(G_UNLIKELY(count>=EIM_FATAL_THRESHOLD))
{
r_context_clear(r);
R_FATAL("eim count exceeds fatal threshold");
return failure_indicator;
}
r_context_clear(r);
r_message(r,"earley item count exceeds threshold");
}

/*:741*/
#line 6169 "./marpa.w"

new_item= obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
return new_item;
}

/*:738*//*740:*/
#line 6182 "./marpa.w"

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
PSL_Datum(psl,ahfa_id)= eim;
return eim;
}

/*:740*//*745:*/
#line 6250 "./marpa.w"

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

/*:745*//*753:*/
#line 6317 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const gint es_does_not_exist= -1;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6323 "./marpa.w"

/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6324 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*754:*/
#line 6347 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*789:*/
#line 6726 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:789*/
#line 6350 "./marpa.w"

}

/*:754*/
#line 6331 "./marpa.w"

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

/*:753*//*756:*/
#line 6357 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const gint eim_does_not_exist= -1;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6362 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6366 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*754:*/
#line 6347 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*789:*/
#line 6726 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:789*/
#line 6350 "./marpa.w"

}

/*:754*/
#line 6370 "./marpa.w"

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

/*:756*//*759:*/
#line 6401 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r)
{
/*757:*/
#line 6396 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:757*/
#line 6404 "./marpa.w"

trace_source_link_clear(r);
}

/*:759*//*761:*/
#line 6410 "./marpa.w"

Marpa_Earley_Set_ID marpa_earley_item_origin(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6413 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1367:*/
#line 13154 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1367*/
#line 6415 "./marpa.w"

if(!item){
/*757:*/
#line 6396 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:757*/
#line 6417 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:761*//*769:*/
#line 6502 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6506 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6509 "./marpa.w"

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

Marpa_Earley_Set_ID marpa_leo_base_origin(struct marpa_r*r);
/*:769*//*770:*/
#line 6524 "./marpa.w"

Marpa_Earley_Set_ID marpa_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6528 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6531 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:770*//*772:*/
#line 6543 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6547 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6550 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:772*//*777:*/
#line 6586 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6590 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6592 "./marpa.w"

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


/*:777*//*782:*/
#line 6646 "./marpa.w"

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
/*:782*//*784:*/
#line 6668 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:784*//*788:*/
#line 6702 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6707 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*789:*/
#line 6726 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:789*/
#line 6711 "./marpa.w"

/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6712 "./marpa.w"

/*1372:*/
#line 13183 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
r_context_clear(r);
r_context_int_add(r,"symid",symid);
R_ERROR_CXT("invalid symid");
return failure_indicator;
}
/*:1372*/
#line 6713 "./marpa.w"

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

/*:788*//*791:*/
#line 6739 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6743 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*789:*/
#line 6726 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:789*/
#line 6747 "./marpa.w"

/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6748 "./marpa.w"

if(!current_earley_set){
/*757:*/
#line 6396 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:757*/
#line 6750 "./marpa.w"

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

/*:791*//*793:*/
#line 6772 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6777 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;

pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*789:*/
#line 6726 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:789*/
#line 6784 "./marpa.w"

if(!pim_sym_p||!pim){
R_ERROR("no trace pim");
return failure_indicator;
}
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6789 "./marpa.w"

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

/*:793*//*795:*/
#line 6811 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 6814 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 6816 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:795*//*812:*/
#line 6954 "./marpa.w"
static inline
void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
TOK token)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_EIM(item)= SOURCE_IS_TOKEN;
item->t_container.t_unique.t_predecessor= predecessor;
TOK_of_Source(item->t_container.t_unique)= token;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Token_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
TOK_of_Source(new_link->t_source)= token;
LV_First_Token_Link_of_EIM(item)= new_link;
}

/*:812*//*818:*/
#line 7035 "./marpa.w"
static inline
void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_EIM(item)= SOURCE_IS_COMPLETION;
item->t_container.t_unique.t_predecessor= predecessor;
Cause_of_Source(item->t_container.t_unique)= cause;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Completion_Link_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Completion_Link_of_EIM(item)= new_link;
}

/*:818*//*819:*/
#line 7062 "./marpa.w"
static inline
void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
if(previous_source_type==NO_SOURCE)
{
Source_Type_of_EIM(item)= SOURCE_IS_LEO;
item->t_container.t_unique.t_predecessor= predecessor;
Cause_of_Source(item->t_container.t_unique)= cause;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= First_Leo_SRCL_of_EIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
}
/*:819*//*822:*/
#line 7114 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
guint previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*824:*/
#line 7132 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= new_link;
}

/*:824*/
#line 7121 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*825:*/
#line 7141 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= new_link;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:825*/
#line 7123 "./marpa.w"

return;
case SOURCE_IS_LEO:/*826:*/
#line 7150 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:826*/
#line 7125 "./marpa.w"

return;
}
}
/*:822*//*832:*/
#line 7184 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7187 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7191 "./marpa.w"

/*851:*/
#line 7415 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:851*/
#line 7192 "./marpa.w"

source_type= Source_Type_of_EIM(item);
switch(source_type)
{
case SOURCE_IS_TOKEN:
r->t_trace_source_type= SOURCE_IS_TOKEN;
source= &(item->t_container.t_unique);
r->t_trace_source= source;
r->t_trace_next_source_link= NULL;
return SYMID_of_SRC(source);
case SOURCE_IS_AMBIGUOUS:
{
SRCL full_link= 
First_Token_Link_of_EIM(item);
if(full_link)
{
r->t_trace_source_type= SOURCE_IS_TOKEN;
r->t_trace_next_source_link= Next_SRCL_of_SRCL(full_link);
r->t_trace_source= &(full_link->t_source);
return SYMID_of_SRCL(full_link);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:832*//*836:*/
#line 7229 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7232 "./marpa.w"

SRCL full_link;
EIM item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7235 "./marpa.w"

/*851:*/
#line 7415 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:851*/
#line 7236 "./marpa.w"

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
return SYMID_of_SRCL(full_link);
}

/*:836*//*839:*/
#line 7261 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7264 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7268 "./marpa.w"

/*851:*/
#line 7415 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:851*/
#line 7269 "./marpa.w"

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

/*:839*//*843:*/
#line 7305 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7308 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7312 "./marpa.w"

/*851:*/
#line 7415 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:851*/
#line 7313 "./marpa.w"

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

/*:843*//*846:*/
#line 7339 "./marpa.w"

Marpa_Symbol_ID
marpa_first_leo_link_trace(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7343 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7347 "./marpa.w"

/*851:*/
#line 7415 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:851*/
#line 7348 "./marpa.w"

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

/*:846*//*850:*/
#line 7386 "./marpa.w"

Marpa_Symbol_ID
marpa_next_leo_link_trace(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7390 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7394 "./marpa.w"

/*851:*/
#line 7415 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:851*/
#line 7395 "./marpa.w"

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

/*:850*//*854:*/
#line 7426 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r){
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:854*//*856:*/
#line 7443 "./marpa.w"

AHFAID marpa_source_predecessor_state(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7446 "./marpa.w"

guint source_type;
SRC source;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7449 "./marpa.w"

source_type= r->t_trace_source_type;
/*865:*/
#line 7596 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:865*/
#line 7451 "./marpa.w"

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

/*:856*//*858:*/
#line 7485 "./marpa.w"

Marpa_Symbol_ID marpa_source_token(struct marpa_r*r,gpointer*value_p)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7488 "./marpa.w"

guint source_type;
SRC source;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7491 "./marpa.w"

source_type= r->t_trace_source_type;
/*865:*/
#line 7596 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:865*/
#line 7493 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
const TOK token= TOK_of_SRC(source);
if(value_p)*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:858*//*861:*/
#line 7518 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7521 "./marpa.w"

guint source_type;
SRC source;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7524 "./marpa.w"

source_type= r->t_trace_source_type;
/*865:*/
#line 7596 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:865*/
#line 7526 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_SYMID_of_SRC(source);
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:861*//*864:*/
#line 7565 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7568 "./marpa.w"

const EARLEME no_predecessor= -1;
guint source_type;
SRC source;
/*1370:*/
#line 13169 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1370*/
#line 7572 "./marpa.w"

source_type= r->t_trace_source_type;
/*865:*/
#line 7596 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:865*/
#line 7574 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
{
LIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return no_predecessor;
return
ES_Ord_of_EIM(Base_EIM_of_LIM(predecessor));
}
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:
{
EIM predecessor= Predecessor_of_SRC(source);
if(!predecessor)return no_predecessor;
return ES_Ord_of_EIM(predecessor);
}
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:864*//*876:*/
#line 7708 "./marpa.w"

static inline
TOK token_new(struct marpa_r*r,SYMID symbol_id,gpointer value)
{
TOK token;
token= obstack_alloc(TOK_Obs,sizeof(*token));
Type_of_TOK(token)= TOKEN_OR_NODE;
SYMID_of_TOK(token)= symbol_id;
Value_of_TOK(token)= value;
return token;
}

/*:876*//*884:*/
#line 7764 "./marpa.w"

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

/*:884*//*886:*/
#line 7810 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b){
gint subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= SYMID_of_ALT(a)-SYMID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:886*//*888:*/
#line 7828 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:888*//*890:*/
#line 7845 "./marpa.w"

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

/*:890*//*893:*/
#line 7865 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
GRAMMAR_Const g= G_of_R(r);
const gint symbol_count_of_g= SYM_Count_of_G(g);
/*1355:*/
#line 13083 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1355*/
#line 7873 "./marpa.w"

/*1366:*/
#line 13149 "./marpa.w"

if(Phase_of_R(r)!=initial_phase){
R_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1366*/
#line 7874 "./marpa.w"

/*648:*/
#line 5570 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*644:*/
#line 5555 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:644*/
#line 5573 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:648*/
#line 7875 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*652:*/
#line 5597 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:652*//*656:*/
#line 5617 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:656*/
#line 7877 "./marpa.w"

/*908:*/
#line 8051 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT(r->t_eim_work_stack,EIM,1024);
/*:908*//*912:*/
#line 8062 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT(r->t_completion_stack,EIM,1024);
/*:912*/
#line 7878 "./marpa.w"

Phase_of_R(r)= input_phase;
LV_Current_Earleme_of_R(r)= 0;
set0= earley_set_new(r,0);
LV_Latest_ES_of_R(r)= set0;
LV_First_ES_of_R(r)= set0;
state= AHFA_of_G_by_ID(g,0);
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

/*:893*//*901:*/
#line 7950 "./marpa.w"

gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,gpointer value,gint length){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 7953 "./marpa.w"

GRAMMAR_Const g= G_of_R(r);
const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1369:*/
#line 13164 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_ERROR("recce not in input phase");
return failure_indicator;
}
/*:1369*/
#line 7960 "./marpa.w"

/*1368:*/
#line 13159 "./marpa.w"

if(R_is_Exhausted(r)){
R_ERROR("recce exhausted");
return failure_indicator;
}
/*:1368*/
#line 7961 "./marpa.w"

/*902:*/
#line 7969 "./marpa.w"
{
const SYM_Const token= SYM_by_ID(token_id);
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

/*:902*/
#line 7962 "./marpa.w"

/*904:*/
#line 8002 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:904*/
#line 7963 "./marpa.w"

/*903:*/
#line 7985 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
r_context_clear(r);
r_context_int_add(r,"target_earleme",target_earleme);
R_ERROR_CXT("parse too long");
return failure_indicator;
}
}

/*:903*/
#line 7964 "./marpa.w"

/*905:*/
#line 8025 "./marpa.w"

{
TOK token= token_new(r,token_id,value);
ALT_Object alternative;
if(Furthest_Earleme_of_R(r)<target_earleme)
LV_Furthest_Earleme_of_R(r)= target_earleme;
alternative.t_token= token;
alternative.t_start_earley_set= current_earley_set;
alternative.t_end_earleme= target_earleme;
if(alternative_insert(r,&alternative)<0)
{
/*877:*/
#line 7723 "./marpa.w"
obstack_free(TOK_Obs,token);

/*:877*/
#line 8036 "./marpa.w"

return duplicate_token_indicator;
}
}

/*:905*/
#line 7965 "./marpa.w"

return current_earleme;
}

/*:901*//*919:*/
#line 8094 "./marpa.w"

Marpa_Earleme
marpa_earleme_complete(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 8098 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
gint count_of_expected_terminals;
/*1369:*/
#line 13164 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_ERROR("recce not in input phase");
return failure_indicator;
}
/*:1369*/
#line 8103 "./marpa.w"

/*1368:*/
#line 13159 "./marpa.w"

if(R_is_Exhausted(r)){
R_ERROR("recce exhausted");
return failure_indicator;
}
/*:1368*/
#line 8104 "./marpa.w"

psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*920:*/
#line 8130 "./marpa.w"
{
current_earleme= ++(LV_Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
LV_R_is_Exhausted(r)= 1;
R_ERROR("parse exhausted");
return failure_indicator;
}
}

/*:920*/
#line 8107 "./marpa.w"

/*922:*/
#line 8155 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:922*/
#line 8108 "./marpa.w"

/*921:*/
#line 8142 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
LV_Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
LV_Latest_ES_of_R(r)= current_earley_set;
}

/*:921*/
#line 8109 "./marpa.w"

/*923:*/
#line 8161 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*924:*/
#line 8168 "./marpa.w"

{
ES start_earley_set= Start_ES_of_ALT(alternative);
TOK token= TOK_of_ALT(alternative);
SYMID token_id= SYMID_of_TOK(token);
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
token_link_add(r,scanned_earley_item,predecessor,token);
prediction_AHFA= Empty_Transition_of_AHFA(scanned_AHFA);
if(!prediction_AHFA)continue;
scanned_earley_item= earley_item_assign(r,
current_earley_set,
current_earley_set,
prediction_AHFA);
}
}

/*:924*/
#line 8165 "./marpa.w"

}

/*:923*/
#line 8110 "./marpa.w"

/*925:*/
#line 8195 "./marpa.w"
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

/*:925*/
#line 8111 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*926:*/
#line 8214 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*927:*/
#line 8227 "./marpa.w"

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
/*928:*/
#line 8250 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*929:*/
#line 8266 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:929*/
#line 8259 "./marpa.w"

}
/*930:*/
#line 8273 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:930*/
#line 8261 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:928*/
#line 8238 "./marpa.w"

}
else
{
/*931:*/
#line 8283 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*929:*/
#line 8266 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:929*/
#line 8292 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:931*/
#line 8242 "./marpa.w"

break;


}
}
}

/*:927*/
#line 8223 "./marpa.w"

}
}

/*:926*/
#line 8114 "./marpa.w"

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

/*:919*//*933:*/
#line 8299 "./marpa.w"

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

/*:933*//*935:*/
#line 8325 "./marpa.w"

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

/*:935*//*939:*/
#line 8363 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES current_earley_set)
{
gpointer*const pim_workarea= r->t_sym_workarea;
GRAMMAR_Const g= G_of_R(r);
EARLEME current_earley_set_id= Earleme_of_ES(current_earley_set);
Bit_Vector bv_pim_symbols= r->t_bv_sym;
Bit_Vector bv_lim_symbols= r->t_bv_sym2;
bv_clear(bv_pim_symbols);
bv_clear(bv_lim_symbols);
/*940:*/
#line 8385 "./marpa.w"
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

/*:940*/
#line 8374 "./marpa.w"

if(r->t_is_using_leo){
/*942:*/
#line 8431 "./marpa.w"

{
guint min,max,start;
for(start= 0;bv_scan(bv_pim_symbols,start,&min,&max);
start= max+2)
{
SYMID symid;
for(symid= (SYMID)min;symid<=(SYMID)max;symid++)
{
PIM this_pim= pim_workarea[symid];
if(!Next_PIM_of_PIM(this_pim))
{

EIM leo_base= EIM_of_PIM(this_pim);
AHFA base_to_ahfa= To_AHFA_of_EIM_by_SYMID(leo_base,symid);
if(AHFA_is_Leo_Completion(base_to_ahfa))
{
/*943:*/
#line 8461 "./marpa.w"
{
LIM new_lim;
new_lim= obstack_alloc(&r->t_obs,sizeof(*new_lim));
Postdot_SYMID_of_LIM(new_lim)= symid;
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

/*:943*/
#line 8448 "./marpa.w"

}
}
}
}
}

/*:942*/
#line 8376 "./marpa.w"

/*952:*/
#line 8546 "./marpa.w"
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

/*955:*/
#line 8605 "./marpa.w"
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

/*:955*/
#line 8564 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*961:*/
#line 8697 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:961*/
#line 8566 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*963:*/
#line 8718 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
LV_Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:963*/
#line 8572 "./marpa.w"

continue;
}
/*956:*/
#line 8620 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*959:*/
#line 8641 "./marpa.w"
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

/*955:*/
#line 8605 "./marpa.w"
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

/*:955*/
#line 8667 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:959*/
#line 8623 "./marpa.w"

/*960:*/
#line 8686 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*961:*/
#line 8697 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:961*/
#line 8690 "./marpa.w"

}else{
/*963:*/
#line 8718 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
LV_Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:963*/
#line 8692 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:960*/
#line 8624 "./marpa.w"

}

/*:956*/
#line 8575 "./marpa.w"

}
}
}

/*:952*/
#line 8377 "./marpa.w"

}
/*964:*/
#line 8724 "./marpa.w"
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

/*:964*/
#line 8379 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:939*//*987:*/
#line 8923 "./marpa.w"

static inline void ur_node_stack_init(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_init %s",G_STRLOC);
obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:987*//*989:*/
#line 8933 "./marpa.w"

static inline void ur_node_stack_reset(URS stack){
stack->t_top= stack->t_base;
}

/*:989*//*991:*/
#line 8940 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
if(stack->t_base)obstack_free(&stack->t_obs,NULL);
stack->t_base= NULL;
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
}

/*:991*//*993:*/
#line 8950 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev){
UR new_ur_node;
new_ur_node= obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
LV_Next_UR_of_UR(new_ur_node)= 0;
LV_Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:993*//*995:*/
#line 8961 "./marpa.w"

static inline void
ur_node_push(URS stack,EIM earley_item,AEX aex)
{
UR top= stack->t_top;
UR new_top= Next_UR_of_UR(top);
LV_EIM_of_UR(top)= earley_item;
LV_AEX_of_UR(top)= aex;
if(!new_top)
{
new_top= ur_node_new(stack,top);
LV_Next_UR_of_UR(top)= new_top;
}
stack->t_top= new_top;
}

/*:995*//*997:*/
#line 8979 "./marpa.w"

static inline UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:997*//*1002:*/
#line 9080 "./marpa.w"

static inline gint psia_test_and_set(
struct obstack*obs,
struct s_bocage_setup_per_es*per_es_data,
EIM earley_item,
AEX ahfa_element_ix)
{
const gint aim_count_of_item= AIM_Count_of_EIM(earley_item);
const Marpa_Earley_Set_ID set_ordinal= ES_Ord_of_EIM(earley_item);
OR**nodes_by_item= per_es_data[set_ordinal].t_aexes_by_item;
const gint item_ordinal= Ord_of_EIM(earley_item);
OR*nodes_by_aex= nodes_by_item[item_ordinal];
MARPA_ASSERT(ahfa_element_ix<aim_count_of_item)
if(!nodes_by_aex){
AEX aex;
nodes_by_aex= nodes_by_item[item_ordinal]= 
obstack_alloc(obs,aim_count_of_item*sizeof(OR));
for(aex= 0;aex<aim_count_of_item;aex++){
nodes_by_aex[aex]= NULL;
}
}
if(!nodes_by_aex[ahfa_element_ix]){
nodes_by_aex[ahfa_element_ix]= dummy_or_node;
return 0;
}
return 1;
}

/*:1002*//*1039:*/
#line 9679 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:1039*//*1041:*/
#line 9693 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:1041*//*1048:*/
#line 9814 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause);
return draft_and_node;
}

/*:1048*//*1051:*/
#line 9840 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:1051*//*1079:*/
#line 10278 "./marpa.w"

gint marpa_and_node_count(struct marpa_r*r)
{
BOC b= B_of_R(r);
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10282 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10283 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
return AND_Count_of_B(b);
}

/*:1079*//*1082:*/
#line 10316 "./marpa.w"

gint marpa_and_node_parent(struct marpa_r*r,int and_node_id)
{
AND and_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10320 "./marpa.w"

/*1080:*/
#line 10291 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10294 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1080*/
#line 10321 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1082*//*1084:*/
#line 10327 "./marpa.w"

gint marpa_and_node_predecessor(struct marpa_r*r,int and_node_id)
{
AND and_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10331 "./marpa.w"

/*1080:*/
#line 10291 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10294 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1080*/
#line 10332 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1084*//*1086:*/
#line 10343 "./marpa.w"

gint marpa_and_node_cause(struct marpa_r*r,int and_node_id)
{
AND and_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10347 "./marpa.w"

/*1080:*/
#line 10291 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10294 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1080*/
#line 10348 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1086*//*1088:*/
#line 10359 "./marpa.w"

gint marpa_and_node_symbol(struct marpa_r*r,int and_node_id)
{
AND and_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10363 "./marpa.w"

/*1080:*/
#line 10291 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10294 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1080*/
#line 10364 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const SYMID symbol_id= 
OR_is_Token(cause_or)?SYMID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1088*//*1090:*/
#line 10392 "./marpa.w"

Marpa_Symbol_ID marpa_and_node_token(struct marpa_r*r,
Marpa_And_Node_ID and_node_id,gpointer*value_p)
{
AND and_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10397 "./marpa.w"

/*1080:*/
#line 10291 "./marpa.w"
{
BOC b= B_of_R(r);
AND and_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10294 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
and_nodes= ANDs_of_B(b);
if(!and_nodes){
R_ERROR("no and nodes");
return failure_indicator;
}
if(and_node_id<0){
R_ERROR("bad and node id");
return failure_indicator;
}
if(and_node_id>=AND_Count_of_B(b)){
return-1;
}
and_node= and_nodes+and_node_id;
}

/*:1080*/
#line 10398 "./marpa.w"

return and_node_token(and_node,value_p);
}
/*:1090*//*1092:*/
#line 10403 "./marpa.w"

SYMID and_node_token(AND and_node,gpointer*value_p)
{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or))
{
const TOK token= TOK_of_OR(cause_or);
if(value_p)
*value_p= Value_of_TOK(token);
return SYMID_of_TOK(token);
}
return-1;
}

/*:1092*//*1104:*/
#line 10467 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10469 "./marpa.w"

ORID top_or_node_id= failure_indicator;
const gint no_parse= -1;
/*1105:*/
#line 10497 "./marpa.w"

const GRAMMAR_Const g= G_of_R(r);
const gint rule_count_of_g= RULE_Count_of_G(g);
const gint symbol_count_of_g= SYM_Count_of_G(g);
BOC b;
ES end_of_parse_es;
RULE completed_start_rule;
EIM start_eim= NULL;
AIM start_aim= NULL;
AEX start_aex= -1;
struct obstack bocage_setup_obs;
gint total_earley_items_in_parse;
gint or_node_estimate= 0;
const gint earley_set_count_of_r= ES_Count_of_R(r);

/*:1105*//*1108:*/
#line 10520 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:1108*/
#line 10472 "./marpa.w"

r_update_earley_sets(r);
/*1109:*/
#line 10524 "./marpa.w"

{
EARLEME end_of_parse_earleme;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10527 "./marpa.w"

if(B_of_R(r)){
R_ERROR("bocage in use");
return failure_indicator;
}
switch(Phase_of_R(r))
{
default:
R_ERROR("recce not evaluation-ready");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}

MARPA_OFF_DEBUG2("ordinal=%d",ordinal);
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
ordinal= Ord_of_ES(end_of_parse_es);
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
MARPA_OFF_DEBUG2("ordinal=%d",ordinal);
}

/*:1109*/
#line 10475 "./marpa.w"

b= B_of_R(r)= g_slice_new(BOC_Object);
MARPA_DEBUG3("%s new bocage B_of_R=%p",G_STRLOC,B_of_R(r));
/*1025:*/
#line 9426 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;

/*:1025*//*1100:*/
#line 10444 "./marpa.w"

b->is_obstack_initialized= 1;
obstack_init(&OBS_of_B(b));
/*:1100*//*1166:*/
#line 11243 "./marpa.w"

MARPA_DEBUG3("%s rank_safe where b=%p",G_STRLOC,b);
rank_safe(RANK_of_B(b));
/*:1166*/
#line 10478 "./marpa.w"

/*1110:*/
#line 10577 "./marpa.w"

{
if(ordinal==0){
gint rule_length= Length_of_RULE(completed_start_rule);
OR*or_nodes= ORs_of_B(b)= g_new(OR,1);
AND and_nodes= ANDs_of_B(b)= g_new(AND_Object,1);
OR or_node= or_nodes[0]= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ORID null_or_node_id= 0;
Top_ORID_of_B(b)= null_or_node_id;

OR_Count_of_B(b)= 1;
AND_Count_of_B(b)= 1;

RULE_of_OR(or_node)= completed_start_rule;
Position_of_OR(or_node)= rule_length;
Origin_Ord_of_OR(or_node)= 0;
ID_of_OR(or_node)= null_or_node_id;
ES_Ord_of_OR(or_node)= 0;
First_ANDID_of_OR(or_node)= 0;
AND_Count_of_OR(or_node)= 1;

OR_of_AND(and_nodes)= or_node;
Predecessor_OR_of_AND(and_nodes)= NULL;
Cause_OR_of_AND(and_nodes)= 
(OR)TOK_by_ID_of_R(r,RHS_ID_of_RULE(completed_start_rule,rule_length-1));

return null_or_node_id;
}
}

/*:1110*/
#line 10479 "./marpa.w"

/*1114:*/
#line 10660 "./marpa.w"

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
gint aex;
AIM*const ahfa_items= AIMs_of_AHFA(ahfa_state);
const gint ahfa_item_count= AIM_Count_of_AHFA(ahfa_state);
for(aex= 0;aex<ahfa_item_count;aex++){
const AIM ahfa_item= ahfa_items[aex];
if(RULEID_of_AIM(ahfa_item)==sought_rule_id){
start_aim= ahfa_item;
start_eim= earley_item;
start_aex= aex;
break;
}
}
}
if(start_eim)break;
}
}

/*:1114*/
#line 10480 "./marpa.w"

if(!start_eim)goto SOFT_ERROR;
Phase_of_R(r)= evaluation_phase;
obstack_init(&bocage_setup_obs);
/*1111:*/
#line 10608 "./marpa.w"

{
guint ix;
guint earley_set_count= ES_Count_of_R(r);
total_earley_items_in_parse= 0;
per_es_data= 
obstack_alloc(&bocage_setup_obs,
sizeof(struct s_bocage_setup_per_es)*earley_set_count);
for(ix= 0;ix<earley_set_count;ix++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,ix);
const guint item_count= EIM_Count_of_ES(earley_set);
total_earley_items_in_parse+= item_count;
{
struct s_bocage_setup_per_es*per_es= per_es_data+ix;
OR**const per_eim_eixes= per_es->t_aexes_by_item= 
obstack_alloc(&bocage_setup_obs,sizeof(OR*)*item_count);
guint item_ordinal;
per_es->t_or_psl= NULL;
per_es->t_and_psl= NULL;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
per_eim_eixes[item_ordinal]= NULL;
}
}
}
}

/*:1111*/
#line 10484 "./marpa.w"

/*998:*/
#line 8993 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
/*1000:*/
#line 9061 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1000*/
#line 9002 "./marpa.w"

}
while((ur_node= ur_node_pop(ur_node_stack)))
{
const EIM_Const parent_earley_item= EIM_of_UR(ur_node);
const AEX parent_aex= AEX_of_UR(ur_node);
const AIM parent_aim= AIM_of_EIM_by_AEX(parent_earley_item,parent_aex);
MARPA_ASSERT(parent_aim>=AIM_by_ID(1))
const AIM predecessor_aim= parent_aim-1;


guint source_type= Source_Type_of_EIM(parent_earley_item);
MARPA_ASSERT(!EIM_is_Predicted(parent_earley_item))
/*1003:*/
#line 9108 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
switch(source_type)
{
case SOURCE_IS_TOKEN:
predecessor_earley_item= Predecessor_of_EIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Token_Link_of_EIM(parent_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
for(;;)
{
if(predecessor_earley_item)
{
if(EIM_is_Predicted(predecessor_earley_item)){
Set_boolean_in_PSIA_for_initial_nulls(predecessor_earley_item,predecessor_aim);
}else{
const EIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
/*1000:*/
#line 9061 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1000*/
#line 9136 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1003*/
#line 9015 "./marpa.w"

/*1005:*/
#line 9163 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
EIM cause_earley_item= NULL;
const SYMID transition_symbol_id= Postdot_SYMID_of_AIM(predecessor_aim);
switch(source_type)
{
case SOURCE_IS_COMPLETION:
predecessor_earley_item= Predecessor_of_EIM(parent_earley_item);
cause_earley_item= Cause_of_EIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Completion_Link_of_EIM(parent_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
while(cause_earley_item)
{
if(predecessor_earley_item)
{
if(EIM_is_Predicted(predecessor_earley_item))
{
Set_boolean_in_PSIA_for_initial_nulls(predecessor_earley_item,predecessor_aim);
}
else
{
const EIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
/*1000:*/
#line 9061 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1000*/
#line 9199 "./marpa.w"

}
}
{
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
const EIM ur_earley_item= cause_earley_item;
gint ix;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*1000:*/
#line 9061 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1000*/
#line 9212 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1005*/
#line 9016 "./marpa.w"

/*1006:*/
#line 9222 "./marpa.w"

{
SRCL source_link= NULL;
EIM cause_earley_item= NULL;
LIM leo_predecessor= NULL;
switch(source_type)
{
case SOURCE_IS_LEO:
leo_predecessor= Predecessor_of_EIM(parent_earley_item);
cause_earley_item= Cause_of_EIM(parent_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Leo_SRCL_of_EIM(parent_earley_item);
if(source_link)
{
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
while(cause_earley_item)
{
const SYMID transition_symbol_id= Postdot_SYMID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
gint ix;
EIM ur_earley_item= cause_earley_item;
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
/*1000:*/
#line 9061 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1000*/
#line 9255 "./marpa.w"

}
while(leo_predecessor){
SYMID postdot= Postdot_SYMID_of_LIM(leo_predecessor);
EIM leo_base= Base_EIM_of_LIM(leo_predecessor);
TRANS transition= TRANS_of_EIM_by_SYMID(leo_base,postdot);
const AEX ur_aex= Leo_Base_AEX_of_TRANS(transition);
const AIM ur_aim= AIM_of_EIM_by_AEX(leo_base,ur_aex);
ur_earley_item= leo_base;


or_node_estimate+= 1+Null_Count_of_AIM(ur_aim+1);
if(EIM_is_Predicted(ur_earley_item))
{
Set_boolean_in_PSIA_for_initial_nulls(ur_earley_item,ur_aim);
}else{
/*1000:*/
#line 9061 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1000*/
#line 9271 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1006*/
#line 9017 "./marpa.w"

}
/*999:*/
#line 9029 "./marpa.w"
{
const ES first_earley_set= ES_of_R_by_Ord(r,0);
OR**const nodes_by_item= per_es_data[0].t_aexes_by_item;
const EIM*const eims_of_es= EIMs_of_ES(first_earley_set);
const gint item_count= EIM_Count_of_ES(first_earley_set);
gint item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const nodes_by_aex= nodes_by_item[item_ordinal];
if(nodes_by_aex){
const EIM earley_item= eims_of_es[item_ordinal];
const Marpa_AHFA_State_ID ahfa_id= AHFAID_of_EIM(earley_item);

if(ahfa_id)continue;
{
const gint aim_count_of_item= AIM_Count_of_EIM(earley_item);
AEX aex;
for(aex= 0;aex<aim_count_of_item;aex++){
AIM ahfa_item= AIM_of_EIM_by_AEX(earley_item,aex);
if(Position_of_AIM(ahfa_item)==0){


nodes_by_aex[aex]= NULL;
goto FINISHED_UNSET;
}
}
}
}
}
FINISHED_UNSET:;
}

/*:999*/
#line 9019 "./marpa.w"

}

/*:998*/
#line 10485 "./marpa.w"

/*1027:*/
#line 9449 "./marpa.w"

{
PSAR_Object or_per_es_arena;
const PSAR or_psar= &or_per_es_arena;
gint work_earley_set_ordinal;
OR last_or_node= NULL;
ORs_of_B(b)= g_new(OR,or_node_estimate);
psar_init(or_psar,SYMI_Count_of_G(g));
for(work_earley_set_ordinal= 0;
work_earley_set_ordinal<earley_set_count_of_r;
work_earley_set_ordinal++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,work_earley_set_ordinal);
EIM*const eims_of_es= EIMs_of_ES(earley_set);
const gint item_count= EIM_Count_of_ES(earley_set);
PSL this_earley_set_psl;
OR**const nodes_by_item= per_es_data[work_earley_set_ordinal].t_aexes_by_item;
psar_dealloc(or_psar);
#define PSL_ES_ORD work_earley_set_ordinal
#define CLAIMED_PSL this_earley_set_psl
/*1338:*/
#line 12918 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1338*/
#line 9469 "./marpa.w"

/*1028:*/
#line 9477 "./marpa.w"

{
gint item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const work_nodes_by_aex= nodes_by_item[item_ordinal];
if(work_nodes_by_aex){
const EIM work_earley_item= eims_of_es[item_ordinal];
const gint work_ahfa_item_count= AIM_Count_of_EIM(work_earley_item);
AEX work_aex;
const gint work_origin_ordinal= Ord_of_ES(Origin_of_EIM(work_earley_item));
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
if(!work_nodes_by_aex[work_aex])continue;
/*1029:*/
#line 9497 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1338:*/
#line 12918 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1338*/
#line 9507 "./marpa.w"

/*1031:*/
#line 9523 "./marpa.w"

{
MARPA_OFF_DEBUG3("%s ahfa_item_symbol_instance = %d",G_STRLOC,ahfa_item_symbol_instance);
if(ahfa_item_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahfa_item_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahfa_item_symbol_instance);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const RULE rule= RULE_of_AIM(ahfa_item);
/*1032:*/
#line 9553 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1032*/
#line 9534 "./marpa.w"

or_node= last_or_node;
PSL_Datum(or_psl,ahfa_item_symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= Origin_Ord_of_EIM(work_earley_item);
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= rule;
Position_of_OR(or_node)= 
ahfa_item_symbol_instance-SYMI_of_RULE(rule)+1;
DANDs_of_OR(or_node)= NULL;
}
psia_or_node= or_node;
}
}

/*:1031*/
#line 9508 "./marpa.w"

/*1034:*/
#line 9578 "./marpa.w"

{
const gint null_count= Null_Count_of_AIM(ahfa_item);
if(null_count> 0)
{
const RULE rule= RULE_of_AIM(ahfa_item);
const gint symbol_instance_of_rule= SYMI_of_RULE(rule);
const gint first_null_symbol_instance= 
ahfa_item_symbol_instance<0?symbol_instance_of_rule:ahfa_item_symbol_instance+1;
gint i;
for(i= 0;i<null_count;i++)
{
const gint symbol_instance= first_null_symbol_instance+i;
OR or_node= PSL_Datum(or_psl,symbol_instance);
MARPA_OFF_DEBUG3("adding nulling token or-node EIM = %s aex=%d",
eim_tag(work_earley_item),work_aex);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal){
DAND draft_and_node;
const gint rhs_ix= symbol_instance-SYMI_of_RULE(rule);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_ID_of_R(r,RHS_ID_of_RULE(rule,rhs_ix));
/*1032:*/
#line 9553 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1032*/
#line 9599 "./marpa.w"

or_node= PSL_Datum(or_psl,symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= work_origin_ordinal;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= rule;
MARPA_OFF_DEBUG3("Added rule %p to or-node %p",RULE_of_OR(or_node),or_node);
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
draft_and_node= DANDs_of_OR(or_node)= 
draft_and_node_new(&bocage_setup_obs,predecessor,
cause);
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,DANDs_of_OR(or_node));
Next_DAND_of_DAND(draft_and_node)= NULL;
}
psia_or_node= or_node;
}
}
}

/*:1034*/
#line 9509 "./marpa.w"

}


MARPA_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
/*1035:*/
#line 9619 "./marpa.w"
{
SRCL source_link= NULL;
EIM cause_earley_item= NULL;
LIM leo_predecessor= NULL;
switch(Source_Type_of_EIM(work_earley_item))
{
case SOURCE_IS_LEO:
leo_predecessor= Predecessor_of_EIM(work_earley_item);
cause_earley_item= Cause_of_EIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Leo_SRCL_of_EIM(work_earley_item);
if(source_link)
{
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
if(leo_predecessor){
for(;;){
/*1037:*/
#line 9659 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const gint ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const gint symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
/*1042:*/
#line 9704 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1338:*/
#line 12918 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1338*/
#line 9711 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*1032:*/
#line 9553 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1032*/
#line 9715 "./marpa.w"

PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= path_rule;
Position_of_OR(or_node)= 
symbol_instance_of_path_ahfa_item-SYMI_of_RULE(path_rule)+1;
MARPA_OFF_DEBUG3("Created or-node %s at %s",or_tag(or_node),G_STRLOC);
DANDs_of_OR(or_node)= NULL;
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,DANDs_of_OR(or_node));
}
}
}

/*:1042*/
#line 9669 "./marpa.w"

/*1043:*/
#line 9733 "./marpa.w"

{
gint i;
const gint null_count= Null_Count_of_AIM(path_ahfa_item);
for(i= 1;i<=null_count;i++)
{
const gint symbol_instance= symbol_instance_of_path_ahfa_item+i;
OR or_node= PSL_Datum(this_earley_set_psl,symbol_instance);
MARPA_ASSERT(symbol_instance<SYMI_Count_of_G(g))
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
DAND draft_and_node;
const gint rhs_ix= symbol_instance-SYMI_of_RULE(path_rule);
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= (OR)TOK_by_ID_of_R(r,RHS_ID_of_RULE(path_rule,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_RULE(path_rule))
MARPA_ASSERT(symbol_instance>=0)
/*1032:*/
#line 9553 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
ID_of_OR(last_or_node)= or_node_id;
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1032*/
#line 9750 "./marpa.w"

PSL_Datum(this_earley_set_psl,symbol_instance)= or_node= last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= path_rule;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
DANDs_of_OR(or_node)= draft_and_node= 
draft_and_node_new(&bocage_setup_obs,predecessor,cause);
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,
DANDs_of_OR(or_node));
Next_DAND_of_DAND(draft_and_node)= NULL;
}
MARPA_ASSERT(Position_of_OR(or_node)<=
SYMI_of_RULE(path_rule)+Length_of_RULE(path_rule))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_RULE(path_rule))
}
}

/*:1043*/
#line 9670 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:1037*/
#line 9641 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:1035*/
#line 9515 "./marpa.w"

}

/*:1029*/
#line 9491 "./marpa.w"

}
}
}
}

/*:1028*/
#line 9470 "./marpa.w"

/*1052:*/
#line 9850 "./marpa.w"

{
gint item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const nodes_by_aex= nodes_by_item[item_ordinal];
if(nodes_by_aex){
const EIM work_earley_item= eims_of_es[item_ordinal];
const gint work_ahfa_item_count= AIM_Count_of_EIM(work_earley_item);
const gint work_origin_ordinal= Ord_of_ES(Origin_of_EIM(work_earley_item));
AEX work_aex;
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
OR or_node= nodes_by_aex[work_aex];
Move_OR_to_Proper_OR(or_node);
if(or_node){
/*1054:*/
#line 9887 "./marpa.w"

{
guint work_source_type= Source_Type_of_EIM(work_earley_item);
const AIM work_ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
MARPA_ASSERT(work_ahfa_item>=AIM_by_ID(1))
const AIM work_predecessor_aim= work_ahfa_item-1;
const gint work_symbol_instance= SYMI_of_AIM(work_ahfa_item);
OR work_proper_or_node;
Set_OR_from_Ord_and_SYMI(work_proper_or_node,work_origin_ordinal,
work_symbol_instance);

/*1055:*/
#line 9903 "./marpa.w"
{
SRCL source_link= NULL;
EIM cause_earley_item= NULL;
LIM leo_predecessor= NULL;
switch(Source_Type_of_EIM(work_earley_item))
{
case SOURCE_IS_LEO:
leo_predecessor= Predecessor_of_EIM(work_earley_item);
cause_earley_item= Cause_of_EIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Leo_SRCL_of_EIM(work_earley_item);
if(source_link)
{
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
if(leo_predecessor){
for(;;){
/*1056:*/
#line 9935 "./marpa.w"

{

RULE path_rule= NULL;

RULE previous_path_rule;
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);


OR dand_predecessor;
OR path_or_node;
EIM base_earley_item;
AEX base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*1057:*/
#line 9964 "./marpa.w"

{
if(higher_path_leo_item){
/*1061:*/
#line 10008 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:1061*/
#line 9967 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:1057*/
#line 9950 "./marpa.w"

/*1059:*/
#line 9978 "./marpa.w"

{
const SYMID transition_symbol_id= Postdot_SYMID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
gint ix;
for(ix= 0;ix<aex_count;ix++)
{
const AEX cause_aex= aexes[ix];
OR dand_cause;
Set_OR_from_EIM_and_AEX(dand_cause,cause_earley_item,cause_aex);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:1059*/
#line 9951 "./marpa.w"

previous_path_rule= path_rule;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
Set_OR_from_EIM_and_AEX(dand_predecessor,base_earley_item,base_aex);
/*1057:*/
#line 9964 "./marpa.w"

{
if(higher_path_leo_item){
/*1061:*/
#line 10008 "./marpa.w"

{
gint symbol_instance;
const gint origin_ordinal= Origin_Ord_of_EIM(base_earley_item);
const AIM aim= AIM_of_EIM_by_AEX(base_earley_item,base_aex);
path_rule= RULE_of_AIM(aim);
symbol_instance= Last_Proper_SYMI_of_RULE(path_rule);
Set_OR_from_Ord_and_SYMI(path_or_node,origin_ordinal,symbol_instance);
}

/*:1061*/
#line 9967 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:1057*/
#line 9958 "./marpa.w"

/*1062:*/
#line 10018 "./marpa.w"

{
OR dand_cause;
const SYMI symbol_instance= SYMI_of_Completed_RULE(previous_path_rule);
const gint origin_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
Set_OR_from_Ord_and_SYMI(dand_cause,origin_ordinal,symbol_instance);
draft_and_node_add(&bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}

/*:1062*/
#line 9959 "./marpa.w"

previous_path_rule= path_rule;
}
}

/*:1056*/
#line 9925 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:1055*/
#line 9898 "./marpa.w"

/*1063:*/
#line 10028 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
TOK token= NULL;
switch(work_source_type)
{
case SOURCE_IS_TOKEN:
predecessor_earley_item= Predecessor_of_EIM(work_earley_item);
token= TOK_of_EIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Token_Link_of_EIM(work_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}
while(token)
{
/*1064:*/
#line 10058 "./marpa.w"

{
OR dand_predecessor;
/*1065:*/
#line 10066 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1065*/
#line 10061 "./marpa.w"

draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,(OR)token);
}

/*:1064*/
#line 10050 "./marpa.w"

if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
token= TOK_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1063*/
#line 9899 "./marpa.w"

/*1066:*/
#line 10077 "./marpa.w"

{
SRCL source_link= NULL;
EIM predecessor_earley_item= NULL;
EIM cause_earley_item= NULL;
const SYMID transition_symbol_id= Postdot_SYMID_of_AIM(work_predecessor_aim);
switch(work_source_type)
{
case SOURCE_IS_COMPLETION:
predecessor_earley_item= Predecessor_of_EIM(work_earley_item);
cause_earley_item= Cause_of_EIM(work_earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Completion_Link_of_EIM(work_earley_item);
if(source_link)
{
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
while(cause_earley_item)
{
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
gint ix;
for(ix= 0;ix<aex_count;ix++){
const AEX cause_aex= aexes[ix];
/*1067:*/
#line 10117 "./marpa.w"

{
OR dand_predecessor;
OR dand_cause;
const gint middle_ordinal= Origin_Ord_of_EIM(cause_earley_item);
const AIM cause_ahfa_item= AIM_of_EIM_by_AEX(cause_earley_item,cause_aex);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_RULE(RULE_of_AIM(cause_ahfa_item));
/*1065:*/
#line 10066 "./marpa.w"

{
if(Position_of_AIM(work_predecessor_aim)<1){
dand_predecessor= NULL;
}else{
const AEX predecessor_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,work_predecessor_aim);
Set_OR_from_EIM_and_AEX(dand_predecessor,predecessor_earley_item,predecessor_aex);
}
}

/*:1065*/
#line 10125 "./marpa.w"

Set_OR_from_Ord_and_SYMI(dand_cause,middle_ordinal,cause_symbol_instance);
draft_and_node_add(&bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}

/*:1067*/
#line 10108 "./marpa.w"

}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1066*/
#line 9900 "./marpa.w"

}

/*:1054*/
#line 9865 "./marpa.w"

}
}
}
}
}

/*:1052*/
#line 9471 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= g_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:1027*/
#line 10486 "./marpa.w"

/*1075:*/
#line 10231 "./marpa.w"

{
gint unique_draft_and_node_count= 0;
/*1068:*/
#line 10131 "./marpa.w"

{
OR*const or_nodes_of_b= ORs_of_B(b);
const gint or_node_count_of_b= OR_Count_of_B(b);
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
gint or_node_id= 0;
psar_init(and_psar,rule_count_of_g+symbol_count_of_g);
while(or_node_id<or_node_count_of_b){
const OR work_or_node= or_nodes_of_b[or_node_id];
/*1070:*/
#line 10163 "./marpa.w"

{
DAND dand= DANDs_of_OR(work_or_node);
DAND next_dand= Next_DAND_of_DAND(dand);
ORID work_or_node_id= ID_of_OR(work_or_node);

if(next_dand)
{
gint origin_ordinal= Origin_Ord_of_OR(work_or_node);
psar_dealloc(and_psar);
while(dand)
{
OR psl_or_node;
OR predecessor= Predecessor_OR_of_DAND(dand);
WHEID wheid= WHEID_of_OR(Cause_OR_of_DAND(dand));
const gint middle_ordinal= 
predecessor?ES_Ord_of_OR(predecessor):origin_ordinal;
PSL and_psl;
PSL*psl_owner= &per_es_data[middle_ordinal].t_and_psl;

if(!*psl_owner)psl_claim(psl_owner,and_psar);
and_psl= *psl_owner;
psl_or_node= PSL_Datum(and_psl,wheid);
if(psl_or_node&&ID_of_OR(psl_or_node)==work_or_node_id)
{

Cause_OR_of_DAND(dand)= NULL;
}else{

PSL_Datum(and_psl,wheid)= work_or_node;
unique_draft_and_node_count++;
}
dand= Next_DAND_of_DAND(dand);
}
}else{
unique_draft_and_node_count++;
}
}

/*:1070*/
#line 10141 "./marpa.w"

or_node_id++;
}
psar_destroy(and_psar);
}

/*:1068*/
#line 10234 "./marpa.w"

/*1076:*/
#line 10238 "./marpa.w"

{
const gint or_count_of_b= OR_Count_of_B(b);
gint or_node_id;
gint and_node_id= 0;
const OR*ors_of_b= ORs_of_B(b);
const AND ands_of_b= ANDs_of_B(b)= 
g_new(AND_Object,unique_draft_and_node_count);
for(or_node_id= 0;or_node_id<or_count_of_b;or_node_id++)
{
gint and_count_of_parent_or= 0;
const OR or_node= ors_of_b[or_node_id];
DAND dand= DANDs_of_OR(or_node);
First_ANDID_of_OR(or_node)= and_node_id;
while(dand)
{
const OR cause_or_node= Cause_OR_of_DAND(dand);
if(cause_or_node)
{

const AND and_node= ands_of_b+and_node_id;
OR_of_AND(and_node)= or_node;
Predecessor_OR_of_AND(and_node)= 
Predecessor_OR_of_DAND(dand);
Cause_OR_of_AND(and_node)= cause_or_node;
and_node_id++;
and_count_of_parent_or++;
}
dand= Next_DAND_of_DAND(dand);
}
AND_Count_of_OR(or_node)= and_count_of_parent_or;
}
AND_Count_of_B(b)= and_node_id;
MARPA_ASSERT(and_node_id==unique_draft_and_node_count);
}

/*:1076*/
#line 10235 "./marpa.w"

}

/*:1075*/
#line 10487 "./marpa.w"

/*1115:*/
#line 10688 "./marpa.w"
{
const ESID end_of_parse_ordinal= Ord_of_ES(end_of_parse_es);
OR**const nodes_by_item= per_es_data[end_of_parse_ordinal].t_aexes_by_item;
const gint start_earley_item_ordinal= Ord_of_EIM(start_eim);
OR*const nodes_by_aex= nodes_by_item[start_earley_item_ordinal];
const OR top_or_node= nodes_by_aex[start_aex];
top_or_node_id= ID_of_OR(top_or_node);
}

/*:1115*/
#line 10488 "./marpa.w"

obstack_free(&bocage_setup_obs,NULL);
Top_ORID_of_B(b)= top_or_node_id;
return top_or_node_id;
SOFT_ERROR:;
/*1116:*/
#line 10698 "./marpa.w"

/*1026:*/
#line 9432 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
if(or_nodes)
{
g_free(or_nodes);
ORs_of_B(b)= NULL;
}
if(and_nodes)
{
g_free(and_nodes);
ANDs_of_B(b)= NULL;
}
}

/*:1026*//*1169:*/
#line 11256 "./marpa.w"

rank_destroy(RANK_of_B(b));
/*:1169*/
#line 10699 "./marpa.w"
;
/*1101:*/
#line 10447 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:1101*/
#line 10700 "./marpa.w"
;

/*:1116*/
#line 10493 "./marpa.w"
;
return no_parse;
}

/*:1104*//*1119:*/
#line 10710 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r){
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10712 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10713 "./marpa.w"

if(Phase_of_R(r)==evaluation_phase){

Phase_of_R(r)= input_phase;
}
bocage_destroy(r);
return 1;
}

/*:1119*//*1121:*/
#line 10724 "./marpa.w"

static inline void bocage_destroy(struct marpa_r*r)
{
BOC b= B_of_R(r);
MARPA_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
if(b){
/*1116:*/
#line 10698 "./marpa.w"

/*1026:*/
#line 9432 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);
if(or_nodes)
{
g_free(or_nodes);
ORs_of_B(b)= NULL;
}
if(and_nodes)
{
g_free(and_nodes);
ANDs_of_B(b)= NULL;
}
}

/*:1026*//*1169:*/
#line 11256 "./marpa.w"

rank_destroy(RANK_of_B(b));
/*:1169*/
#line 10699 "./marpa.w"
;
/*1101:*/
#line 10447 "./marpa.w"

if(b->is_obstack_initialized){
obstack_free(&OBS_of_B(b),NULL);
b->is_obstack_initialized= 0;
}

/*:1101*/
#line 10700 "./marpa.w"
;

/*:1116*/
#line 10730 "./marpa.w"
;
g_slice_free(BOC_Object,b);
B_of_R(r)= NULL;
}
MARPA_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
}

/*:1121*//*1125:*/
#line 10767 "./marpa.w"

gint marpa_or_node_set(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10771 "./marpa.w"

/*1123:*/
#line 10740 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10743 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1123*/
#line 10772 "./marpa.w"

return ES_Ord_of_OR(or_node);
}

/*:1125*//*1127:*/
#line 10778 "./marpa.w"

gint marpa_or_node_origin(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10782 "./marpa.w"

/*1123:*/
#line 10740 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10743 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1123*/
#line 10783 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:1127*//*1129:*/
#line 10789 "./marpa.w"

gint marpa_or_node_rule(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10793 "./marpa.w"

/*1123:*/
#line 10740 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10743 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1123*/
#line 10794 "./marpa.w"

return ID_of_RULE(RULE_of_OR(or_node));
}

/*:1129*//*1131:*/
#line 10800 "./marpa.w"

gint marpa_or_node_position(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10804 "./marpa.w"

/*1123:*/
#line 10740 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10743 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1123*/
#line 10805 "./marpa.w"

return Position_of_OR(or_node);
}

/*:1131*//*1133:*/
#line 10811 "./marpa.w"

gint marpa_or_node_first_and(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10815 "./marpa.w"

/*1123:*/
#line 10740 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10743 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1123*/
#line 10816 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:1133*//*1135:*/
#line 10822 "./marpa.w"

gint marpa_or_node_last_and(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10826 "./marpa.w"

/*1123:*/
#line 10740 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10743 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1123*/
#line 10827 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:1135*//*1137:*/
#line 10834 "./marpa.w"

gint marpa_or_node_and_count(struct marpa_r*r,int or_node_id)
{
OR or_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10838 "./marpa.w"

/*1123:*/
#line 10740 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10743 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1123*/
#line 10839 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:1137*//*1141:*/
#line 10885 "./marpa.w"

static inline void tree_exhaust(TREE tree)
{
if(FSTACK_IS_INITIALIZED(tree->t_fork_stack))
{
FSTACK_DESTROY(tree->t_fork_stack);
FSTACK_SAFE(tree->t_fork_stack);
}
if(FSTACK_IS_INITIALIZED(tree->t_fork_worklist))
{
FSTACK_DESTROY(tree->t_fork_worklist);
FSTACK_SAFE(tree->t_fork_worklist);
}
if(tree->t_and_node_in_use){
bv_free(tree->t_and_node_in_use);
tree->t_and_node_in_use= NULL;
}
}

/*:1141*//*1143:*/
#line 10906 "./marpa.w"

static inline void tree_safe(TREE tree)
{
FSTACK_SAFE(tree->t_fork_stack);
FSTACK_SAFE(tree->t_fork_worklist);
tree->t_and_node_in_use= NULL;
tree->t_parse_count= -1;
val_safe(VAL_of_TREE(tree));
}

/*:1143*//*1145:*/
#line 10921 "./marpa.w"

int marpa_tree_new(struct marpa_r*r)
{
BOC b;
TREE tree;
gint first_tree_of_series= 0;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 10927 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10928 "./marpa.w"

/*1156:*/
#line 11150 "./marpa.w"

{
b= B_of_R(r);
if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
}

/*:1156*/
#line 10929 "./marpa.w"

tree= TREE_of_RANK(RANK_of_B(b));
if(TREE_is_Exhausted(tree)){
return-1;
}
val_destroy(VAL_of_TREE(tree));
if(!TREE_is_Initialized(tree))
{
first_tree_of_series= 1;
/*1150:*/
#line 10988 "./marpa.w"

{
ORID top_or_id= Top_ORID_of_B(b);
OR top_or_node= OR_of_B_by_ID(b,top_or_id);
FORK fork;
gint choice;
const gint and_count= AND_Count_of_B(b);
tree->t_parse_count= 0;
tree->t_and_node_in_use= bv_create((guint)and_count);
FSTACK_INIT(tree->t_fork_stack,FORK_Object,and_count);
FSTACK_INIT(tree->t_fork_worklist,gint,and_count);
choice= or_node_next_choice(b,tree,top_or_node,0);


if(choice<0)goto TREE_IS_EXHAUSTED;
fork= FSTACK_PUSH(tree->t_fork_stack);
OR_of_FORK(fork)= top_or_node;
Choice_of_FORK(fork)= choice;
Parent_of_FORK(fork)= -1;
FORK_Cause_is_Ready(fork)= 0;
FORK_is_Cause(fork)= 0;
FORK_Predecessor_is_Ready(fork)= 0;
FORK_is_Predecessor(fork)= 0;
*(FSTACK_PUSH(tree->t_fork_worklist))= 0;
}

/*:1150*/
#line 10940 "./marpa.w"

}
while(1){
const AND ands_of_b= ANDs_of_B(b);
if(!first_tree_of_series){
/*1151:*/
#line 11017 "./marpa.w"
{
while(1){
FORK iteration_candidate= FSTACK_TOP(tree->t_fork_stack,FORK_Object);
gint choice;
if(!iteration_candidate)break;
choice= Choice_of_FORK(iteration_candidate);
MARPA_ASSERT(choice>=0);
{
OR or_node= OR_of_FORK(iteration_candidate);
ANDID and_node_id= and_order_get(b,or_node,choice);
tree_and_node_release(tree,and_node_id);
choice= or_node_next_choice(b,tree,or_node,choice+1);
}
if(choice>=0){





Choice_of_FORK(iteration_candidate)= choice;
FORK_Cause_is_Ready(iteration_candidate)= 0;
FORK_Predecessor_is_Ready(iteration_candidate)= 0;
break;
}
{

const gint parent_fork_ix= Parent_of_FORK(iteration_candidate);
if(parent_fork_ix>=0){
FORK parent_fork= FORK_of_TREE_by_IX(tree,parent_fork_ix);
if(FORK_is_Cause(iteration_candidate)){
FORK_Cause_is_Ready(parent_fork)= 0;
}
if(FORK_is_Predecessor(iteration_candidate)){
FORK_Predecessor_is_Ready(parent_fork)= 0;
}
}


FSTACK_POP(tree->t_fork_stack);
}
}
{
gint stack_length= FSTACK_LENGTH(tree->t_fork_stack);
gint i;
if(stack_length<=0)goto TREE_IS_EXHAUSTED;
FSTACK_CLEAR(tree->t_fork_worklist);
for(i= 0;i<stack_length;i++){
*(FSTACK_PUSH(tree->t_fork_worklist))= i;
}
}
}

/*:1151*/
#line 10945 "./marpa.w"

}
first_tree_of_series= 0;
/*1152:*/
#line 11069 "./marpa.w"
{
while(1){
FORKID*p_work_fork_id;
FORK work_fork;
ANDID work_and_node_id;
AND work_and_node;
OR work_or_node;
OR child_or_node= NULL;
gint choice;
gint child_is_cause= 0;
gint child_is_predecessor= 0;
p_work_fork_id= FSTACK_TOP(tree->t_fork_worklist,FORKID);
if(!p_work_fork_id){
goto TREE_IS_FINISHED;
}
work_fork= FORK_of_TREE_by_IX(tree,*p_work_fork_id);
work_or_node= OR_of_FORK(work_fork);
work_and_node_id= and_order_get(b,work_or_node,Choice_of_FORK(work_fork));
work_and_node= ands_of_b+work_and_node_id;
if(!FORK_Cause_is_Ready(work_fork)){
child_or_node= Cause_OR_of_AND(work_and_node);
if(child_or_node&&OR_is_Token(child_or_node))child_or_node= NULL;
if(child_or_node){
child_is_cause= 1;
}else{
FORK_Cause_is_Ready(work_fork)= 1;
}
}
if(!child_or_node&&!FORK_Predecessor_is_Ready(work_fork)){
child_or_node= Predecessor_OR_of_AND(work_and_node);
if(child_or_node){
child_is_predecessor= 1;
}else{
FORK_Predecessor_is_Ready(work_fork)= 1;
}
}
if(!child_or_node){
FSTACK_POP(tree->t_fork_worklist);
goto NEXT_FORK_ON_WORKLIST;
}
choice= or_node_next_choice(b,tree,child_or_node,0);
if(choice<0)goto NEXT_TREE;
/*1155:*/
#line 11132 "./marpa.w"

{
FORKID new_fork_id= FSTACK_LENGTH(tree->t_fork_stack);
FORK new_fork= FSTACK_PUSH(tree->t_fork_stack);
*(FSTACK_PUSH(tree->t_fork_worklist))= new_fork_id;
Parent_of_FORK(new_fork)= *p_work_fork_id;
Choice_of_FORK(new_fork)= choice;
OR_of_FORK(new_fork)= child_or_node;
FORK_Cause_is_Ready(new_fork)= 0;
if((FORK_is_Cause(new_fork)= child_is_cause)){
FORK_Cause_is_Ready(work_fork)= 1;
}
FORK_Predecessor_is_Ready(new_fork)= 0;
if((FORK_is_Predecessor(new_fork)= child_is_predecessor)){
FORK_Predecessor_is_Ready(work_fork)= 1;
}
}

/*:1155*/
#line 11111 "./marpa.w"
;
NEXT_FORK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1152*/
#line 10948 "./marpa.w"

}
TREE_IS_FINISHED:;
tree->t_parse_count++;
return FSTACK_LENGTH(tree->t_fork_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(tree);
return-1;
}

/*:1145*//*1147:*/
#line 10967 "./marpa.w"

static inline void tree_and_node_claim(TREE tree,ANDID and_node_id)
{
bv_bit_set(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1147*//*1148:*/
#line 10973 "./marpa.w"

static inline void tree_and_node_release(TREE tree,ANDID and_node_id)
{
bv_bit_clear(tree->t_and_node_in_use,(guint)and_node_id);
}
/*:1148*//*1149:*/
#line 10981 "./marpa.w"

static inline gint tree_and_node_try(TREE tree,ANDID and_node_id)
{
return!bv_bit_test_and_set(tree->t_and_node_in_use,(guint)and_node_id);
}

/*:1149*//*1154:*/
#line 11119 "./marpa.w"

static inline gint or_node_next_choice(BOC b,TREE tree,OR or_node,gint start_choice)
{
gint choice= start_choice;
while(1){
ANDID and_node_id= and_order_get(b,or_node,choice);
if(and_node_id<0)return-1;
if(tree_and_node_try(tree,and_node_id))return choice;
choice++;
}
return-1;
}

/*:1154*//*1158:*/
#line 11161 "./marpa.w"

static inline void tree_destroy(TREE tree)
{
tree_exhaust(tree);
tree->t_parse_count= -1;
MARPA_DEBUG4("%s tree=%p parse_count=%d",G_STRLOC,tree,tree->t_parse_count);
}

/*:1158*//*1160:*/
#line 11173 "./marpa.w"

gint marpa_parse_count(struct marpa_r*r)
{
BOC b;
TREE tree;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11178 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11179 "./marpa.w"

b= B_of_R(r);
if(!b){
return-1;
}
tree= TREE_of_RANK(RANK_of_B(b));
MARPA_DEBUG3("%s b=%p",G_STRLOC,b);
MARPA_DEBUG4("%s tree=%p parse_count=%d",G_STRLOC,tree,tree->t_parse_count);
return tree->t_parse_count;
}

/*:1160*//*1162:*/
#line 11197 "./marpa.w"

gint marpa_tree_size(struct marpa_r*r)
{
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11200 "./marpa.w"

BOC b= B_of_R(r);
TREE tree;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11203 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
return-1;
}
return FSTACK_LENGTH(tree->t_fork_stack);
}

/*:1162*//*1168:*/
#line 11248 "./marpa.w"

static inline void rank_safe(RANK rank)
{
rank->t_and_node_in_use= NULL;
rank->t_and_node_orderings= NULL;
tree_safe(TREE_of_RANK(rank));
}

/*:1168*//*1171:*/
#line 11261 "./marpa.w"

static inline void rank_freeze(RANK rank)
{
if(rank->t_and_node_in_use)
{
bv_free(rank->t_and_node_in_use);
rank->t_and_node_in_use= NULL;
}
}
static inline void rank_destroy(RANK rank)
{
tree_destroy(TREE_of_RANK(rank));
rank_freeze(rank);
if(rank->t_and_node_orderings){
rank->t_and_node_orderings= NULL;
obstack_free(&OBS_of_RANK(rank),NULL);
}
}

/*:1171*//*1176:*/
#line 11337 "./marpa.w"

gint marpa_and_order_set(struct marpa_r*r,
Marpa_Or_Node_ID or_node_id,
Marpa_And_Node_ID*and_node_ids,
gint length)
{
OR or_node;
RANK rank;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11345 "./marpa.w"

/*1123:*/
#line 10740 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10743 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1123*/
#line 11346 "./marpa.w"

{BOC b= B_of_R(r);
ANDID**and_node_orderings;
Bit_Vector and_node_in_use;
struct obstack*obs;
ANDID first_and_node_id;
ANDID and_count_of_or;
if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
rank= RANK_of_B(b);
and_node_orderings= rank->t_and_node_orderings;
and_node_in_use= rank->t_and_node_in_use;
obs= &OBS_of_RANK(rank);
if(and_node_orderings&&!and_node_in_use)
{
R_ERROR("ranker frozen");
return failure_indicator;
}
if(!and_node_orderings)
{
gint and_id;
const gint and_count_of_r= AND_Count_of_B(b);
obstack_init(obs);
rank->t_and_node_orderings= 
and_node_orderings= 
obstack_alloc(obs,sizeof(ANDID*)*and_count_of_r);
for(and_id= 0;and_id<and_count_of_r;and_id++)
{
and_node_orderings[and_id]= (ANDID*)NULL;
}
rank->t_and_node_in_use= 
and_node_in_use= bv_create((guint)and_count_of_r);
}
first_and_node_id= First_ANDID_of_OR(or_node);
and_count_of_or= AND_Count_of_OR(or_node);
{
gint and_ix;
for(and_ix= 0;and_ix<length;and_ix++)
{
ANDID and_node_id= and_node_ids[and_ix];
if(and_node_id<first_and_node_id||
and_node_id-first_and_node_id>=and_count_of_or){
R_ERROR("and node not in or node");
return failure_indicator;
}
if(bv_bit_test(and_node_in_use,(guint)and_node_id))
{
R_ERROR("dup and node");
return failure_indicator;
}
bv_bit_set(and_node_in_use,(guint)and_node_id);
}
}
if(and_node_orderings[or_node_id]){
R_ERROR("or node already ordered");
return failure_indicator;
}
{
ANDID*orderings= obstack_alloc(obs,sizeof(ANDID)*(length+1));
gint i;
and_node_orderings[or_node_id]= orderings;
*orderings++= length;
for(i= 0;i<length;i++)
{
*orderings++= and_node_ids[i];
}
}
}
return 1;
}

/*:1176*//*1180:*/
#line 11424 "./marpa.w"

static inline ANDID and_order_get(BOC b,OR or_node,gint ix)
{
RANK rank;
ANDID**and_node_orderings;
if(ix>=AND_Count_of_OR(or_node))
{
return-1;
}
rank= RANK_of_B(b);
and_node_orderings= rank->t_and_node_orderings;
if(and_node_orderings)
{
ORID or_node_id= ID_of_OR(or_node);
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)
{
gint length= ordering[0];
if(ix>=length)
return-1;
return ordering[1+ix];
}
}
return First_ANDID_of_OR(or_node)+ix;
}

Marpa_And_Node_ID marpa_and_order_get(struct marpa_r*r,Marpa_Or_Node_ID or_node_id,gint ix)
{
OR or_node;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11453 "./marpa.w"

/*1123:*/
#line 10740 "./marpa.w"
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 10743 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
or_nodes= ORs_of_B(b);
if(!or_nodes){
R_ERROR("no or nodes");
return failure_indicator;
}
if(or_node_id<0){
R_ERROR("bad or node id");
return failure_indicator;
}
if(or_node_id>=OR_Count_of_B(b)){
return-1;
}
or_node= or_nodes[or_node_id];
}

/*:1123*/
#line 11454 "./marpa.w"

if(ix<0){
R_ERROR("negative and ix");
return failure_indicator;
}
{
BOC b= B_of_R(r);
if(!b)
{
R_ERROR("no bocage");
return failure_indicator;
}
return and_order_get(b,or_node,ix);
}
}

/*:1180*//*1188:*/
#line 11544 "./marpa.w"

gint marpa_fork_or_node(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11548 "./marpa.w"

/*1186:*/
#line 11512 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11516 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1186*/
#line 11549 "./marpa.w"

return ID_of_OR(OR_of_FORK(fork));
}

/*:1188*//*1190:*/
#line 11556 "./marpa.w"

gint marpa_fork_choice(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11560 "./marpa.w"

/*1186:*/
#line 11512 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11516 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1186*/
#line 11561 "./marpa.w"

return Choice_of_FORK(fork);
}

/*:1190*//*1192:*/
#line 11576 "./marpa.w"

gint marpa_fork_parent(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11580 "./marpa.w"

/*1186:*/
#line 11512 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11516 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1186*/
#line 11581 "./marpa.w"

return Parent_of_FORK(fork);
}

/*:1192*//*1194:*/
#line 11588 "./marpa.w"

gint marpa_fork_cause_is_ready(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11592 "./marpa.w"

/*1186:*/
#line 11512 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11516 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1186*/
#line 11593 "./marpa.w"

return FORK_Cause_is_Ready(fork);
}

/*:1194*//*1196:*/
#line 11600 "./marpa.w"

gint marpa_fork_predecessor_is_ready(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11604 "./marpa.w"

/*1186:*/
#line 11512 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11516 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1186*/
#line 11605 "./marpa.w"

return FORK_Predecessor_is_Ready(fork);
}

/*:1196*//*1198:*/
#line 11612 "./marpa.w"

gint marpa_fork_is_cause(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11616 "./marpa.w"

/*1186:*/
#line 11512 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11516 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1186*/
#line 11617 "./marpa.w"

return FORK_is_Cause(fork);
}

/*:1198*//*1200:*/
#line 11624 "./marpa.w"

gint marpa_fork_is_predecessor(struct marpa_r*r,int fork_id)
{
FORK fork;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11628 "./marpa.w"

/*1186:*/
#line 11512 "./marpa.w"
{
FORK base_fork;
BOC b= B_of_R(r);
TREE tree;
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11516 "./marpa.w"

if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
if(!TREE_is_Initialized(tree)){
R_ERROR("tree not initialized");
return failure_indicator;
}
if(TREE_is_Exhausted(tree)){
R_ERROR("bocage iteration exhausted");
return failure_indicator;
}
base_fork= FSTACK_BASE(tree->t_fork_stack,FORK_Object);
if(fork_id<0){
R_ERROR("bad fork id");
return failure_indicator;
}
if(fork_id>=FSTACK_LENGTH(tree->t_fork_stack)){
return-1;
}
fork= base_fork+fork_id;
}

/*:1186*/
#line 11629 "./marpa.w"

return FORK_is_Predecessor(fork);
}

/*:1200*//*1207:*/
#line 11697 "./marpa.w"

static inline void val_safe(VAL val)
{
DSTACK_SAFE(val->t_virtual_stack);
VAL_is_Active(val)= 0;
VAL_is_Trace(val)= 0;
TOS_of_VAL(val)= -1;
FORK_of_VAL(val)= -1;
}

/*:1207*//*1211:*/
#line 11748 "./marpa.w"

int marpa_val_new(struct marpa_r*r)
{
BOC b;
TREE tree;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11753 "./marpa.w"

/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11754 "./marpa.w"

/*1156:*/
#line 11150 "./marpa.w"

{
b= B_of_R(r);
if(!b){
R_ERROR("no bocage");
return failure_indicator;
}
}

/*:1156*/
#line 11755 "./marpa.w"

tree= TREE_of_RANK(RANK_of_B(b));
if(TREE_is_Exhausted(tree)){
return-1;
}
if(!TREE_is_Initialized(tree))
{
R_ERROR("tree not initialized");
return failure_indicator;
}
{
VAL val= VAL_of_TREE(tree);
const gint minimum_stack_size= (8192/sizeof(gint));
const gint initial_stack_size= 
MAX(Size_of_TREE(tree)/1024,minimum_stack_size);
val_destroy(val);
DSTACK_INIT(VStack_of_VAL(val),gint,initial_stack_size);
VAL_is_Active(val)= 1;
}
return 1;
}

/*:1211*//*1213:*/
#line 11779 "./marpa.w"

static inline void val_destroy(VAL val)
{

if(DSTACK_IS_INITIALIZED(val->t_virtual_stack))
{
DSTACK_DESTROY(val->t_virtual_stack);
DSTACK_SAFE(val->t_virtual_stack);
}
val_safe(val);
}

/*:1213*//*1216:*/
#line 11807 "./marpa.w"

gint marpa_val_trace(struct marpa_r*r,gint flag)
{
BOC b;
TREE tree;
VAL val;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11813 "./marpa.w"

/*1214:*/
#line 11792 "./marpa.w"
{
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11793 "./marpa.w"

b= B_of_R(r);
if(!b){
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
val= VAL_of_TREE(tree);
if(!VAL_is_Active(val)){
return failure_indicator;
}
}

/*:1214*/
#line 11814 "./marpa.w"

VAL_is_Trace(val)= flag;
return 1;
}

/*:1216*//*1218:*/
#line 11821 "./marpa.w"

Marpa_Fork_ID marpa_val_fork(struct marpa_r*r)
{
BOC b;
TREE tree;
VAL val;
/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11827 "./marpa.w"

/*1214:*/
#line 11792 "./marpa.w"
{
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11793 "./marpa.w"

b= B_of_R(r);
if(!b){
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
val= VAL_of_TREE(tree);
if(!VAL_is_Active(val)){
return failure_indicator;
}
}

/*:1214*/
#line 11828 "./marpa.w"

return FORK_of_VAL(val);
}

/*:1218*//*1220:*/
#line 11834 "./marpa.w"

Marpa_Fork_ID marpa_val_event(struct marpa_r*r,Marpa_Event*event)
{
BOC b;
TREE tree;
VAL val;
AND and_nodes;
gint semantic_rule_id= -1;
gint token_id= -1;
gpointer token_value= NULL;
gint arg_0= -1;
gint arg_n= -1;
FORKID fork_ix;
gint continue_with_next_fork;


/*1357:*/
#line 13088 "./marpa.w"
const int failure_indicator= -2;

/*:1357*/
#line 11850 "./marpa.w"

/*1214:*/
#line 11792 "./marpa.w"
{
/*1371:*/
#line 13178 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1371*/
#line 11793 "./marpa.w"

b= B_of_R(r);
if(!b){
return failure_indicator;
}
tree= TREE_of_RANK(RANK_of_B(b));
val= VAL_of_TREE(tree);
if(!VAL_is_Active(val)){
return failure_indicator;
}
}

/*:1214*/
#line 11851 "./marpa.w"

and_nodes= ANDs_of_B(b);

arg_0= arg_n= TOS_of_VAL(val);
fork_ix= FORK_of_VAL(val);
if(fork_ix<0){
fork_ix= Size_of_TREE(tree);
}
continue_with_next_fork= !VAL_is_Trace(val);

while(1){
OR or;
RULE fork_rule;
fork_ix--;
if(fork_ix<0)goto RETURN_SOFT_ERROR;
{
ANDID and_node_id;
AND and_node;
const FORK fork= FORK_of_TREE_by_IX(tree,fork_ix);
const gint choice= Choice_of_FORK(fork);
or= OR_of_FORK(fork);
and_node_id= and_order_get(b,or,choice);
and_node= and_nodes+and_node_id;
token_id= and_node_token(and_node,&token_value);
}
if(token_id>=0){
arg_0= ++arg_n;
continue_with_next_fork= 0;
}
fork_rule= RULE_of_OR(or);
if(Position_of_OR(or)==Length_of_RULE(fork_rule)){
gint virtual_rhs= RULE_is_Virtual_RHS(fork_rule);
gint virtual_lhs= RULE_is_Virtual_LHS(fork_rule);
gint real_symbol_count;
const DSTACK virtual_stack= &VStack_of_VAL(val);
if(virtual_lhs){
real_symbol_count= Real_SYM_Count_of_RULE(fork_rule);
if(virtual_rhs){
*(DSTACK_TOP(*virtual_stack,gint))+= real_symbol_count;
}else{
*DSTACK_PUSH(*virtual_stack,gint)= real_symbol_count;
}
goto NEXT_FORK;
}
if(virtual_rhs){
real_symbol_count= Real_SYM_Count_of_RULE(fork_rule);
real_symbol_count+= *DSTACK_POP(*virtual_stack,gint);
}else{
real_symbol_count= Length_of_RULE(fork_rule);
}
arg_0= arg_n-real_symbol_count+1;
semantic_rule_id= 
fork_rule->t_is_semantic_equivalent?
fork_rule->t_original:ID_of_RULE(fork_rule);
continue_with_next_fork= 0;
}
NEXT_FORK:;
if(!continue_with_next_fork)break;
}

/*1221:*/
#line 11920 "./marpa.w"

{
SYMID_of_EVE(event)= token_id;
Value_of_EVE(event)= token_value;
RULEID_of_EVE(event)= semantic_rule_id;
TOS_of_VAL(val)= Arg0_of_EVE(event)= arg_0;
FORK_of_VAL(val)= fork_ix;
ArgN_of_EVE(event)= arg_n;
}

/*:1221*/
#line 11911 "./marpa.w"

return FORK_of_VAL(val);

RETURN_SOFT_ERROR:;
/*1221:*/
#line 11920 "./marpa.w"

{
SYMID_of_EVE(event)= token_id;
Value_of_EVE(event)= token_value;
RULEID_of_EVE(event)= semantic_rule_id;
TOS_of_VAL(val)= Arg0_of_EVE(event)= arg_0;
FORK_of_VAL(val)= fork_ix;
ArgN_of_EVE(event)= arg_n;
}

/*:1221*/
#line 11915 "./marpa.w"

return-1;

}

/*:1220*//*1224:*/
#line 11954 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1224*//*1226:*/
#line 11962 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:1226*//*1229:*/
#line 11980 "./marpa.w"

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

/*:1229*//*1231:*/
#line 12000 "./marpa.w"

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


/*:1231*//*1232:*/
#line 12021 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:1232*//*1234:*/
#line 12033 "./marpa.w"
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
/*:1234*//*1236:*/
#line 12053 "./marpa.w"
static inline
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}
/*:1236*//*1238:*/
#line 12063 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:1238*//*1240:*/
#line 12072 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:1240*//*1242:*/
#line 12080 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:1242*//*1246:*/
#line 12095 "./marpa.w"

static inline void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1246*//*1248:*/
#line 12111 "./marpa.w"

static inline void bv_over_clear(Bit_Vector bv,guint bit)
{
guint length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1248*//*1250:*/
#line 12119 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:1250*//*1252:*/
#line 12127 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:1252*//*1254:*/
#line 12135 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:1254*//*1258:*/
#line 12146 "./marpa.w"

static inline gboolean
bv_bit_test_and_set(Bit_Vector vector,guint bit)
{
Bit_Vector addr= vector+(bit/bv_wordbits);
guint mask= bv_lsb<<(bit%bv_wordbits);
if((*addr&mask)!=0u)
return 1;
*addr|= mask;
return 0;
}

/*:1258*//*1260:*/
#line 12160 "./marpa.w"

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
/*:1260*//*1262:*/
#line 12177 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:1262*//*1264:*/
#line 12189 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:1264*//*1266:*/
#line 12201 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:1266*//*1268:*/
#line 12213 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:1268*//*1270:*/
#line 12225 "./marpa.w"

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
/*:1270*//*1272:*/
#line 12301 "./marpa.w"

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
/*:1272*//*1278:*/
#line 12355 "./marpa.w"

static void
rhs_closure(struct marpa_g*g,Bit_Vector bv)
{
guint min,max,start= 0;
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_DECLARE(stack,Marpa_Symbol_ID)
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
GArray*rules= SYM_by_ID(*top_of_stack)->t_rhs;
for(rule_ix= 0;rule_ix<rules->len;rule_ix++)
{
Marpa_Rule_ID rule_id= 
g_array_index(rules,Marpa_Rule_ID,rule_ix);
RULE rule= RULE_by_ID(g,rule_id);
guint rule_length;
guint rh_ix;
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
if(bv_bit_test(bv,(guint)lhs_id))
goto NEXT_RULE;
rule_length= Length_of_RULE(rule);
for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test(bv,(guint)RHS_ID_of_RULE(rule,rh_ix)))
goto NEXT_RULE;
}



bv_bit_set(bv,(guint)lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}
/*:1278*//*1283:*/
#line 12434 "./marpa.w"

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
/*:1283*//*1285:*/
#line 12454 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:1285*//*1287:*/
#line 12467 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:1287*//*1289:*/
#line 12484 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:1289*//*1292:*/
#line 12494 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:1292*//*1295:*/
#line 12503 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:1295*//*1298:*/
#line 12512 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:1298*//*1300:*/
#line 12526 "./marpa.w"

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
/*:1300*//*1310:*/
#line 12670 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_bytes){
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}
/*:1310*//*1327:*/
#line 12813 "./marpa.w"

static inline void
psar_init(const PSAR psar,gint length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1327*//*1328:*/
#line 12820 "./marpa.w"

static inline void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
MARPA_OFF_DEBUG3("%s psl=%p",G_STRLOC,psl);
while(psl)
{
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
MARPA_OFF_DEBUG3("%s owner=%p",G_STRLOC,owner);
if(owner)
*owner= NULL;
g_slice_free1(Sizeof_PSL(psar),psl);
psl= next_psl;
MARPA_OFF_DEBUG3("%s psl=%p",G_STRLOC,psl);
}
}
/*:1328*//*1329:*/
#line 12837 "./marpa.w"

static inline PSL psl_new(const PSAR psar){
gint i;
PSL new_psl= g_slice_alloc(Sizeof_PSL(psar));
new_psl->t_next= NULL;
new_psl->t_prev= NULL;
new_psl->t_owner= NULL;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(new_psl,i)= NULL;
}
return new_psl;
}
/*:1329*//*1333:*/
#line 12869 "./marpa.w"

static inline void psar_reset(const PSAR psar){
PSL psl= psar->t_first_psl;
while(psl&&psl->t_owner){
gint i;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(psl,i)= NULL;
}
psl= psl->t_next;
}
psar_dealloc(psar);
}

/*:1333*//*1335:*/
#line 12888 "./marpa.w"

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

/*:1335*//*1337:*/
#line 12910 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar){
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1337*//*1341:*/
#line 12935 "./marpa.w"

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

/*:1341*//*1377:*/
#line 13242 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags){
if(!(flags&CONTEXT_FLAG))r_context_clear(r);
r->t_error= message;
if(flags&FATAL_FLAG)r->t_fatal_error= r->t_error;
r_message(r,message);
}

/*:1377*//*1385:*/
#line 13316 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb)
{g->t_message_callback= cb;}
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->t_message_callback_arg= cb_arg;}
gpointer marpa_g_message_callback_arg(struct marpa_g*g)
{return g->t_message_callback_arg;}
/*:1385*//*1387:*/
#line 13333 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_G_Message_Callback*cb= g->t_message_callback;
if(cb){(*cb)(g,id);}}
/*:1387*//*1393:*/
#line 13353 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb)
{r->t_message_callback= cb;}
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg)
{r->t_message_callback_arg= cb_arg;}
gpointer marpa_r_message_callback_arg(struct marpa_r*r)
{return Message_Callback_Arg_of_R(r);}
/*:1393*//*1395:*/
#line 13364 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id)
{Marpa_R_Message_Callback*cb= Message_Callback_of_R(r);
if(cb){(*cb)(r,id);}}
/*:1395*//*1399:*/
#line 13417 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*
eim_tag_safe(gchar*buffer,EIM eim)
{
sprintf(buffer,"S%d@%d-%d",
AHFAID_of_EIM(eim),Origin_Earleme_of_EIM(eim),
Earleme_of_EIM(eim));
return buffer;
}

static char DEBUG_eim_tag_buffer[1000];
PRIVATE_NOT_INLINE gchar*
eim_tag(EIM eim)
{
return eim_tag_safe(DEBUG_eim_tag_buffer,eim);
}
#endif

/*:1399*//*1401:*/
#line 13446 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*
lim_tag_safe(gchar*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_SYMID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}

static char DEBUG_lim_tag_buffer[1000];
PRIVATE_NOT_INLINE gchar*
lim_tag(LIM lim)
{
return lim_tag_safe(DEBUG_lim_tag_buffer,lim);
}
#endif

/*:1401*//*1403:*/
#line 13475 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*
or_tag_safe(gchar*buffer,OR or)
{
if(!or)return"NULL";
if(OR_is_Token(or))return"TOKEN";
if(Type_of_OR(or)==DUMMY_OR_NODE)return"DUMMY";
sprintf(buffer,"R%d:%d@%d-%d",
ID_of_RULE(RULE_of_OR(or)),Position_of_OR(or),
Origin_Ord_of_OR(or),
ES_Ord_of_OR(or));
return buffer;
}

static char DEBUG_or_tag_buffer[1000];
PRIVATE_NOT_INLINE const gchar*
or_tag(OR or)
{
return or_tag_safe(DEBUG_or_tag_buffer,or);
}
#endif

/*:1403*//*1405:*/
#line 13510 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*
aim_tag_safe(gchar*buffer,AIM aim)
{
if(!aim)return"NULL";
const gint aim_position= Position_of_AIM(aim);
if(aim_position>=0){
sprintf(buffer,"R%d@%d",RULEID_of_AIM(aim),Position_of_AIM(aim));
}else{
sprintf(buffer,"R%d@end",RULEID_of_AIM(aim));
}
return buffer;
}

static char DEBUG_aim_tag_buffer[1000];
PRIVATE_NOT_INLINE const gchar*
aim_tag(AIM aim)
{
return aim_tag_safe(DEBUG_aim_tag_buffer,aim);
}
#endif


/*:1405*/
#line 13592 "./marpa.w"


/*:1411*/
