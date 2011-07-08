/*1299:*/
#line 12129 "./marpa.w"

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

/*:1299*//*1300:*/
#line 12152 "./marpa.w"

#include "config.h"
#include "marpa.h"
/*1288:*/
#line 12002 "./marpa.w"

#define MARPA_DEBUG  0 
#define MARPA_ENABLE_ASSERT  0 
#if MARPA_DEBUG
#define MARPA_DEBUG1(a)  g_debug((a)) 
#define MARPA_DEBUG2(a, b)  g_debug((a),(b)) 
#define MARPA_DEBUG3(a, b, c)  g_debug((a),(b),(c)) 
#define MARPA_DEBUG4(a, b, c, d)  g_debug((a),(b),(c),(d)) 
#define MARPA_DEBUG5(a, b, c, d, e)  g_debug((a),(b),(c),(d),(e)) 
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

/*:1288*/
#line 12155 "./marpa.w"

#define PRIVATE_NOT_INLINE static \

#define SYM_Count_of_G(g) ((g) ->t_symbols->len)  \

#define SYM_by_ID(g,id) (g_array_index((g) ->t_symbols,SYM,(id) ) )  \

#define RULE_Count_of_G(g) ((g) ->t_rules->len) 
#define RULE_by_ID(g,id) (g_array_index((g) ->t_rules,RULE,(id) ) )  \

#define RULEID_of_G_is_Valid(g,rule_id)  \
((rule_id) >=0&&(guint) (rule_id) <(g) ->t_rules->len)  \

#define Size_of_G(g) ((g) ->t_size) 
#define LV_Size_of_G(g) ((g) ->t_size) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define Context_of_G(g) ((g) ->t_context) 
#define ID_of_SYM(sym) ((sym) ->t_symbol_id) 
#define LV_ID_of_SYM(sym) ID_of_SYM(sym) 
#define SYMBOL_LHS_RULE_COUNT(symbol) ((symbol) ->t_lhs->len) 
#define SYM_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define SYM_is_Terminal(symbol) ((symbol) ->t_is_terminal) 
#define SYMID_is_Terminal(g,id) (SYM_is_Terminal(SYM_by_ID((g) ,(id) ) ) ) 
#define LV_SYMID_is_Terminal(g,id) SYMID_is_Terminal((g) ,(id) ) 
#define MAX_RHS_LENGTH (G_MAXINT>>(2) ) 
#define Length_of_RULE(rule) ((rule) ->t_rhs_length) 
#define LHS_ID_of_RULE(rule) ((rule) ->t_symbols[0]) 
#define RHS_ID_of_RULE(rule,position)  \
((rule) ->t_symbols[(position) +1])  \

#define ID_of_RULE(rule) ((rule) ->t_id) 
#define RULE_is_Used(rule) ((rule) ->t_is_used) 
#define RULE_is_Start(rule) ((rule) ->t_is_start) 
#define SYMI_Count_of_G(g) ((g) ->t_symbol_instance_count) 
#define SYMI_of_RULE(rule) ((rule) ->t_symbol_instance_base) 
#define SYMI_of_Completed_RULE(rule)  \
(SYMI_of_RULE(rule) +Length_of_RULE(rule) -1) 
#define SYMI_of_AIM(aim) (symbol_instance_of_ahfa_item_get(aim) ) 
#define Sort_Key_of_AIM(aim) ((aim) ->t_sort_key) 
#define AIM_by_ID(g,id) ((g) ->t_AHFA_items+(id) ) 
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
#define EIM_is_Leo_Expanded(eim) ((eim) ->t_is_leo_expanded) 
#define EIM_is_Leo_Expansion(eim) ((eim) ->t_is_leo_expansion) 
#define LV_EIM_is_Leo_Expanded(eim) EIM_is_Leo_Expanded(eim) 
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
#define Symbol_ID_of_Postdot_Item(postdot) ((postdot) ->t_earley.transition_symid)  \

#define Next_SRCL_of_SRCL(link) ((link) ->t_next) 
#define LV_Next_SRCL_of_SRCL(link) Next_SRCL_of_SRCL(link) 
#define Source_of_SRCL(link) ((link) ->t_source) 
#define Source_of_EIM(eim) ((eim) ->t_container.t_unique) 
#define Predecessor_of_Source(srcd) ((srcd) .t_predecessor) 
#define Predecessor_of_SRC(source) Predecessor_of_Source(*(source) ) 
#define Predecessor_of_EIM(item) Predecessor_of_Source(Source_of_EIM(item) ) 
#define Predecessor_of_SRCL(link) Predecessor_of_Source(Source_of_SRCL(link) ) 
#define LV_Predecessor_of_SRCL(link) Predecessor_of_SRCL(link) 
#define Cause_of_Source(srcd) ((srcd) .t_cause) 
#define Cause_of_SRC(source) Cause_of_Source(*(source) ) 
#define Cause_of_EIM(item) Cause_of_Source(Source_of_EIM(item) ) 
#define Cause_of_SRCL(link) Cause_of_Source(Source_of_SRCL(link) ) 
#define Token_Value_of_Source(srcd) ((srcd) .t_cause) 
#define Token_Value_of_SRC(source) Token_Value_of_Source(*(source) ) 
#define Token_Value_of_EIM(item) Token_Value_of_Source(Source_of_EIM(item) ) 
#define Token_Value_of_SRCL(link) Token_Value_of_Source(Source_of_SRCL(link) ) 
#define LV_Token_Value_of_SRCL(link) Token_Value_of_SRCL(link) 
#define Symbol_ID_of_Source(srcd) ((srcd) .t_symbol_id) 
#define Symbol_ID_of_SRC(source) Symbol_ID_of_Source(*(source) ) 
#define Symbol_ID_of_SRCL(link) Symbol_ID_of_Source(Source_of_SRCL(link) ) 
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
#define Prev_UR_of_UR(ur) ((ur) ->t_prev) 
#define LV_Prev_UR_of_UR(ur) Prev_UR_of_UR(ur) 
#define Next_UR_of_UR(ur) ((ur) ->t_next) 
#define LV_Next_UR_of_UR(ur) Next_UR_of_UR(ur) 
#define EIM_of_UR(ur) ((ur) ->t_earley_item) 
#define LV_EIM_of_UR(ur) EIM_of_UR(ur) 
#define AEX_of_UR(ur) ((ur) ->t_aex) 
#define LV_AEX_of_UR(ur) AEX_of_UR(ur)  \

#define URS_of_R(r) (&(r) ->t_ur_node_stack) 
#define DUMMY_OR_NODE -1
#define TOKEN_OR_NODE -2
#define Position_of_OR(or) ((or) ->t_draft.t_position) 
#define Type_of_OR(or) ((or) ->t_draft.t_position) 
#define RULE_of_OR(or) ((or) ->t_draft.t_rule) 
#define Start_ES_Ord_of_OR(or) ((or) ->t_draft.t_start_set_ordinal) 
#define ES_Ord_of_OR(or) ((or) ->t_draft.t_end_set_ordinal) 
#define DANDs_of_OR(or) ((or) ->t_draft.t_draft_and_node) 
#define ORs_of_B(b) ((b) ->t_or_nodes) 
#define OR_Count_of_B(b) ((b) ->t_or_node_count) 
#define Path_AIM_of_LIM(lim) (base_aim_of_lim(lim) +1) 
#define Base_AIM_of_LIM(lim) (base_aim_of_lim(lim) ) 
#define WHEID_of_SYMID(symid) (rule_count_of_g+(symid) ) 
#define WHEID_of_RULEID(ruleid) (ruleid) 
#define Next_DAND_of_DAND(dand) ((dand) ->t_next) 
#define Predecessor_OR_of_DAND(dand) ((dand) ->t_predecessor) 
#define Middle_ES_Ord_of_DAND(dand) ((dand) ->t_middle_ordinal) 
#define WHEID_of_DAND(dand) ((dand) ->t_wheid) 
#define OR_of_AND(and) ((and) ->t_current) 
#define Predecessor_OR_of_AND(and) ((and) ->t_predecessor) 
#define Cause_OR_of_AND(and) ((and) ->t_cause) 
#define B_of_R(r) ((r) ->t_bocage) 
#define OBS_of_B(b) ((b) ->t_obs) 
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

#line 12156 "./marpa.w"

#include "marpa_obs.h"
/*1270:*/
#line 11889 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:1270*/
#line 12158 "./marpa.w"

/*134:*/
#line 1124 "./marpa.w"

struct s_symbol;
typedef struct s_symbol*SYM;
typedef const struct s_symbol*SYM_Const;
/*:134*//*453:*/
#line 3566 "./marpa.w"

struct s_AHFA_item;
typedef struct s_AHFA_item*AIM;
typedef Marpa_AHFA_Item_ID AIMID;

/*:453*//*498:*/
#line 3961 "./marpa.w"
struct s_AHFA_state;
/*:498*//*585:*/
#line 5196 "./marpa.w"

struct s_transition;
typedef struct s_transition*TRANS;
struct s_ur_transition;
typedef struct s_ur_transition*URTRANS;
/*:585*//*715:*/
#line 5932 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*ES;
typedef const struct s_earley_set*ES_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*ESK;
/*:715*//*744:*/
#line 6161 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*EIM;
typedef const struct s_earley_item*EIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*EIK;

/*:744*//*780:*/
#line 6592 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*EIX;
union u_postdot_item;
/*:780*//*783:*/
#line 6634 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:783*//*884:*/
#line 7757 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:884*//*998:*/
#line 9043 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:998*//*1033:*/
#line 9553 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:1033*//*1062:*/
#line 9991 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:1062*//*1083:*/
#line 10247 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:1083*//*1086:*/
#line 10266 "./marpa.w"

struct s_bocage;
typedef struct s_bocage*BOC;
/*:1086*//*1096:*/
#line 10329 "./marpa.w"

struct s_bocage_setup_per_es;
/*:1096*//*1198:*/
#line 11281 "./marpa.w"

struct s_dstack;
typedef struct s_dstack*DSTACK;
/*:1198*//*1202:*/
#line 11316 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1202*//*1209:*/
#line 11381 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1209*//*1211:*/
#line 11396 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1211*/
#line 12159 "./marpa.w"

/*46:*/
#line 706 "./marpa.w"

typedef struct marpa_g*GRAMMAR;
typedef const struct marpa_g*GRAMMAR_Const;

/*:46*//*133:*/
#line 1122 "./marpa.w"

typedef gint SYMID;
/*:133*//*220:*/
#line 1552 "./marpa.w"

struct s_rule;
typedef struct s_rule*RULE;
typedef Marpa_Rule_ID RULEID;

/*:220*//*345:*/
#line 2368 "./marpa.w"
typedef gint SYMI;
/*:345*//*510:*/
#line 4047 "./marpa.w"

typedef struct s_AHFA_state*AHFA;
typedef gint AHFAID;

/*:510*//*586:*/
#line 5201 "./marpa.w"
typedef gint AEX;
/*:586*//*609:*/
#line 5364 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:609*//*713:*/
#line 5923 "./marpa.w"
typedef Marpa_Earleme EARLEME;

/*:713*//*820:*/
#line 7035 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
/*:820*//*822:*/
#line 7045 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:822*//*1061:*/
#line 9978 "./marpa.w"

typedef gint WHEID;

/*:1061*//*1114:*/
#line 10579 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1114*//*1171:*/
#line 11051 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:1171*/
#line 12160 "./marpa.w"

/*40:*/
#line 657 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:40*//*54:*/
#line 739 "./marpa.w"
static gint next_grammar_id= 1;
/*:54*//*618:*/
#line 5422 "./marpa.w"
static gint next_recce_id= 1;
/*:618*//*1039:*/
#line 9597 "./marpa.w"

static const gint dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;
/*:1039*//*1115:*/
#line 10586 "./marpa.w"

static const guint bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const guint bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const guint bv_hiddenwords= 3;
static const guint bv_lsb= 1u;
static const guint bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:1115*/
#line 12161 "./marpa.w"

/*1199:*/
#line 11284 "./marpa.w"

struct s_dstack{gint t_count;gint t_capacity;gpointer t_base;};
/*:1199*/
#line 12162 "./marpa.w"

/*45:*/
#line 700 "./marpa.w"
struct marpa_g{
/*58:*/
#line 752 "./marpa.w"
GArray*t_symbols;
/*:58*//*68:*/
#line 801 "./marpa.w"
GArray*t_rules;
/*:68*//*105:*/
#line 968 "./marpa.w"
Bit_Vector t_bv_symid_is_terminal;
/*:105*//*108:*/
#line 982 "./marpa.w"
GHashTable*t_context;
/*:108*//*123:*/
#line 1081 "./marpa.w"

struct obstack t_obs;
struct obstack t_obs_tricky;
/*:123*//*127:*/
#line 1103 "./marpa.w"
Marpa_Error_ID t_error;
/*:127*//*212:*/
#line 1511 "./marpa.w"

Marpa_Symbol_Callback*t_symbol_callback;
gpointer t_symbol_callback_arg;
/*:212*//*319:*/
#line 2282 "./marpa.w"

Marpa_Rule_Callback*t_rule_callback;
gpointer t_rule_callback_arg;
/*:319*//*455:*/
#line 3582 "./marpa.w"

AIM t_AHFA_items;
AIM*t_AHFA_items_by_rule;
/*:455*//*511:*/
#line 4051 "./marpa.w"
struct s_AHFA_state*t_AHFA;
/*:511*//*1274:*/
#line 11931 "./marpa.w"

Marpa_G_Message_Callback*t_message_callback;
gpointer t_message_callback_arg;
/*:1274*/
#line 701 "./marpa.w"

/*52:*/
#line 737 "./marpa.w"
gint t_id;
/*:52*//*76:*/
#line 838 "./marpa.w"
Marpa_Symbol_ID t_start_symid;
/*:76*//*82:*/
#line 863 "./marpa.w"

RULE t_null_start_rule;
RULE t_proper_start_rule;
/*:82*//*85:*/
#line 890 "./marpa.w"
int t_size;
/*:85*//*88:*/
#line 903 "./marpa.w"
guint t_max_rule_length;
/*:88*//*346:*/
#line 2370 "./marpa.w"

gint t_symbol_instance_count;
/*:346*//*456:*/
#line 3588 "./marpa.w"

guint t_aim_count;
/*:456*//*512:*/
#line 4054 "./marpa.w"
gint t_AHFA_len;
/*:512*/
#line 702 "./marpa.w"

/*92:*/
#line 911 "./marpa.w"
unsigned int t_is_precomputed:1;
/*:92*//*95:*/
#line 919 "./marpa.w"
unsigned int t_has_loop:1;
/*:95*//*99:*/
#line 934 "./marpa.w"
unsigned int t_is_lhs_terminal_ok:1;
/*:99*/
#line 703 "./marpa.w"

};
typedef struct marpa_g GRAMMARD;
/*:45*//*135:*/
#line 1131 "./marpa.w"

struct s_symbol{
gint t_type;
/*145:*/
#line 1187 "./marpa.w"
GArray*t_lhs;
/*:145*//*152:*/
#line 1217 "./marpa.w"
GArray*t_rhs;
/*:152*//*199:*/
#line 1419 "./marpa.w"

struct s_symbol*t_alias;
/*:199*/
#line 1134 "./marpa.w"

/*143:*/
#line 1178 "./marpa.w"
SYMID t_symbol_id;
/*:143*/
#line 1135 "./marpa.w"

/*159:*/
#line 1239 "./marpa.w"
unsigned int t_is_accessible:1;
/*:159*//*165:*/
#line 1265 "./marpa.w"
unsigned int t_is_counted:1;
/*:165*//*169:*/
#line 1283 "./marpa.w"
unsigned int t_is_nullable:1;
/*:169*//*175:*/
#line 1309 "./marpa.w"
unsigned int t_is_nulling:1;
/*:175*//*181:*/
#line 1336 "./marpa.w"
unsigned int t_is_terminal:1;
/*:181*//*187:*/
#line 1365 "./marpa.w"
unsigned int t_is_productive:1;
/*:187*//*193:*/
#line 1390 "./marpa.w"
unsigned int t_is_start:1;
/*:193*//*198:*/
#line 1416 "./marpa.w"

unsigned int t_is_proper_alias:1;
unsigned int t_is_nulling_alias:1;
/*:198*/
#line 1136 "./marpa.w"

};
typedef struct s_symbol SYM_Object;
/*:135*//*219:*/
#line 1543 "./marpa.w"

struct s_rule{
/*247:*/
#line 1949 "./marpa.w"
guint t_rhs_length;
/*:247*//*264:*/
#line 2021 "./marpa.w"
Marpa_Rule_ID t_id;
/*:264*//*309:*/
#line 2244 "./marpa.w"
gint t_virtual_start;
/*:309*//*313:*/
#line 2260 "./marpa.w"
gint t_virtual_end;
/*:313*//*330:*/
#line 2318 "./marpa.w"
Marpa_Rule_ID t_original;
/*:330*//*335:*/
#line 2332 "./marpa.w"
guint t_real_symbol_count;
/*:335*//*347:*/
#line 2377 "./marpa.w"

gint t_symbol_instance_base;
/*:347*/
#line 1545 "./marpa.w"

/*267:*/
#line 2033 "./marpa.w"
unsigned int t_is_discard:1;
/*:267*//*281:*/
#line 2117 "./marpa.w"
unsigned int t_is_loop:1;
/*:281*//*286:*/
#line 2138 "./marpa.w"
unsigned int t_is_virtual_loop:1;
/*:286*//*293:*/
#line 2173 "./marpa.w"
unsigned int t_is_used:1;
/*:293*//*297:*/
#line 2189 "./marpa.w"
unsigned int t_is_start:1;
/*:297*//*301:*/
#line 2219 "./marpa.w"
unsigned int t_is_virtual_lhs:1;
/*:301*//*305:*/
#line 2230 "./marpa.w"
unsigned int t_is_virtual_rhs:1;
/*:305*//*339:*/
#line 2341 "./marpa.w"
unsigned int t_is_semantic_equivalent:1;
/*:339*/
#line 1546 "./marpa.w"

/*248:*/
#line 1952 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];

/*:248*/
#line 1547 "./marpa.w"

};
/*:219*//*452:*/
#line 3560 "./marpa.w"

struct s_AHFA_item{
gint t_sort_key;
/*462:*/
#line 3614 "./marpa.w"

RULE t_rule;

/*:462*/
#line 3563 "./marpa.w"

/*463:*/
#line 3620 "./marpa.w"

gint t_position;

/*:463*//*464:*/
#line 3629 "./marpa.w"
Marpa_Symbol_ID t_postdot;

/*:464*//*465:*/
#line 3638 "./marpa.w"

gint t_leading_nulls;

/*:465*/
#line 3564 "./marpa.w"

};
/*:452*//*499:*/
#line 3962 "./marpa.w"

struct s_AHFA_state_key{
Marpa_AHFA_State_ID t_id;
};
struct s_AHFA_state{
struct s_AHFA_state_key t_key;
struct s_AHFA_state*t_empty_transition;
/*502:*/
#line 3983 "./marpa.w"

SYMID*t_complete_symbols;

/*:502*//*504:*/
#line 3993 "./marpa.w"

AIM*t_items;
/*:504*//*519:*/
#line 4095 "./marpa.w"
Marpa_Symbol_ID*t_postdot_symid_ary;
/*:519*//*588:*/
#line 5214 "./marpa.w"

TRANS*t_transitions;
/*:588*/
#line 3969 "./marpa.w"

/*501:*/
#line 3981 "./marpa.w"

guint t_complete_symbol_count;
/*:501*//*505:*/
#line 3995 "./marpa.w"

guint t_item_count;
/*:505*//*520:*/
#line 4096 "./marpa.w"
guint t_postdot_sym_count;

/*:520*//*534:*/
#line 4227 "./marpa.w"
SYMID t_leo_lhs_sym;
/*:534*/
#line 3970 "./marpa.w"

guint t_has_completed_start_rule:1;
/*509:*/
#line 4044 "./marpa.w"

guint t_is_predict:1;

/*:509*/
#line 3972 "./marpa.w"

};
typedef struct s_AHFA_state AHFA_Object;

/*:499*//*587:*/
#line 5202 "./marpa.w"

struct s_ur_transition{
AHFA t_to_ahfa;
gint t_completion_count;
};
struct s_transition{
struct s_ur_transition t_ur;
AEX t_leo_base_aex;
AEX t_aex[1];
};
/*:587*//*716:*/
#line 5938 "./marpa.w"

struct s_earley_set_key{
EARLEME t_earleme;
};
typedef struct s_earley_set_key ESK_Object;
/*:716*//*717:*/
#line 5943 "./marpa.w"

struct s_earley_set{
ESK_Object t_key;
gint t_postdot_sym_count;
/*718:*/
#line 5955 "./marpa.w"

gint t_eim_count;
/*:718*//*720:*/
#line 5969 "./marpa.w"

gint t_ordinal;
/*:720*/
#line 5947 "./marpa.w"

union u_postdot_item**t_postdot_ary;
ES t_next_earley_set;
/*719:*/
#line 5958 "./marpa.w"

EIM*t_earley_items;

/*:719*//*1220:*/
#line 11469 "./marpa.w"

PSL t_dot_psl;
/*:1220*/
#line 5950 "./marpa.w"

};

/*:717*//*781:*/
#line 6596 "./marpa.w"

struct s_earley_ix{
union u_postdot_item*t_next;
SYMID t_postdot_symid;
EIM t_earley_item;
};
typedef struct s_earley_ix EIX_Object;

/*:781*//*784:*/
#line 6637 "./marpa.w"

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

/*:784*//*797:*/
#line 6782 "./marpa.w"

union u_postdot_item{
LIM_Object t_leo;
EIX_Object t_earley;
};
typedef union u_postdot_item*PIM;

/*:797*//*885:*/
#line 7767 "./marpa.w"

struct s_alternative{
SYMID t_token_id;
void*t_token_value;
ES t_start_earley_set;
EARLEME t_end_earleme;
};
typedef struct s_alternative ALT_Object;

/*:885*//*1000:*/
#line 9065 "./marpa.w"

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
/*:1000*//*1036:*/
#line 9577 "./marpa.w"

struct s_draft_or_node
{
/*1035:*/
#line 9572 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
/*:1035*/
#line 9580 "./marpa.w"

DAND t_draft_and_node;
};
/*:1036*//*1037:*/
#line 9583 "./marpa.w"

struct s_final_or_node
{
/*1035:*/
#line 9572 "./marpa.w"

gint t_position;
gint t_end_set_ordinal;
RULE t_rule;
gint t_start_set_ordinal;
/*:1035*/
#line 9586 "./marpa.w"

gint t_and_node_id;
gint t_and_node_count;
};
/*:1037*//*1038:*/
#line 9590 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
};
typedef union u_or_node OR_Object;

/*:1038*//*1063:*/
#line 9999 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
gint t_middle_ordinal;
WHEID t_wheid;
};
typedef struct s_draft_and_node DAND_Object;

/*:1063*//*1084:*/
#line 10254 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:1084*//*1087:*/
#line 10269 "./marpa.w"

struct s_bocage{
/*1041:*/
#line 9602 "./marpa.w"

OR*t_or_nodes;
gint t_or_node_count;
/*:1041*//*1090:*/
#line 10283 "./marpa.w"

struct obstack t_obs;
/*:1090*/
#line 10271 "./marpa.w"

};
typedef struct s_bocage BOC_Object;
/*:1087*//*1097:*/
#line 10331 "./marpa.w"

struct s_bocage_setup_per_es{
OR**t_aexes_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:1097*//*1203:*/
#line 11319 "./marpa.w"

struct s_dqueue{gint t_current;struct s_dstack t_stack;};

/*:1203*//*1210:*/
#line 11387 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
gpointer t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1210*//*1212:*/
#line 11411 "./marpa.w"

struct s_per_earley_set_arena{
gint t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1212*/
#line 12163 "./marpa.w"

/*610:*/
#line 5366 "./marpa.w"

struct marpa_r{
/*623:*/
#line 5434 "./marpa.w"
const struct marpa_g*t_grammar;

/*:623*//*629:*/
#line 5470 "./marpa.w"

ES t_first_earley_set;
ES t_latest_earley_set;
EARLEME t_current_earleme;
/*:629*//*648:*/
#line 5555 "./marpa.w"
gpointer*t_sym_workarea;
/*:648*//*652:*/
#line 5570 "./marpa.w"
gpointer*t_workarea2;
/*:652*//*656:*/
#line 5591 "./marpa.w"

Bit_Vector t_bv_sym;
Bit_Vector t_bv_sym2;
Bit_Vector t_bv_sym3;
/*:656*//*660:*/
#line 5617 "./marpa.w"
Bit_Vector t_bv_symid_is_expected;
/*:660*//*667:*/
#line 5667 "./marpa.w"

GTree*t_earley_item_tree;
/*:667*//*689:*/
#line 5812 "./marpa.w"
GHashTable*t_context;
/*:689*//*700:*/
#line 5867 "./marpa.w"
struct obstack t_obs;
/*:700*//*704:*/
#line 5881 "./marpa.w"

Marpa_Error_ID t_error;
Marpa_Error_ID t_fatal_error;
/*:704*//*727:*/
#line 6022 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:727*//*762:*/
#line 6373 "./marpa.w"

EIM t_trace_earley_item;
/*:762*//*803:*/
#line 6835 "./marpa.w"

union u_postdot_item**t_trace_pim_sym_p;
union u_postdot_item*t_trace_postdot_item;
/*:803*//*845:*/
#line 7328 "./marpa.w"

SRC t_trace_source;
SRCL t_trace_next_source_link;
/*:845*//*886:*/
#line 7776 "./marpa.w"

DSTACK_DECLARE(t_alternatives);
/*:886*//*914:*/
#line 8085 "./marpa.w"
DSTACK_DECLARE(t_eim_work_stack);
/*:914*//*918:*/
#line 8097 "./marpa.w"
DSTACK_DECLARE(t_completion_stack);
/*:918*//*922:*/
#line 8109 "./marpa.w"
DSTACK_DECLARE(t_earley_set_stack);
/*:922*//*1001:*/
#line 9078 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:1001*//*1088:*/
#line 10275 "./marpa.w"

BOC t_bocage;
/*:1088*//*1213:*/
#line 11419 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1213*//*1282:*/
#line 11968 "./marpa.w"

Marpa_R_Message_Callback*t_message_callback;
gpointer t_message_callback_arg;
/*:1282*/
#line 5368 "./marpa.w"

/*616:*/
#line 5420 "./marpa.w"
gint t_id;
/*:616*//*625:*/
#line 5457 "./marpa.w"

Marpa_Phase t_phase;
/*:625*//*637:*/
#line 5508 "./marpa.w"
guint t_earley_item_warning_threshold;
/*:637*//*643:*/
#line 5536 "./marpa.w"
EARLEME t_furthest_earleme;
/*:643*//*721:*/
#line 5973 "./marpa.w"

gint t_earley_set_count;
/*:721*/
#line 5369 "./marpa.w"

/*677:*/
#line 5730 "./marpa.w"

unsigned int t_use_leo_flag:1;
unsigned int t_is_using_leo:1;
/*:677*//*683:*/
#line 5773 "./marpa.w"
unsigned int t_is_exhausted:1;
/*:683*//*687:*/
#line 5796 "./marpa.w"

unsigned int t_is_leo_expanding:1;
/*:687*//*846:*/
#line 7331 "./marpa.w"

unsigned int t_trace_source_type:3;
/*:846*/
#line 5370 "./marpa.w"

};

/*:610*/
#line 12164 "./marpa.w"

/*821:*/
#line 7038 "./marpa.w"

struct s_source{
gpointer t_predecessor;
gpointer t_cause;
SYMID t_symbol_id;
};

/*:821*//*823:*/
#line 7048 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};

/*:823*//*824:*/
#line 7054 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:824*//*825:*/
#line 7061 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source t_unique;
};

/*:825*/
#line 12165 "./marpa.w"

/*745:*/
#line 6168 "./marpa.w"

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
/*758:*/
#line 6331 "./marpa.w"

unsigned int t_source_type:3;

/*:758*//*759:*/
#line 6343 "./marpa.w"

unsigned int t_is_leo_expanded:1;
unsigned int t_is_leo_expansion:1;

/*:759*/
#line 6179 "./marpa.w"

};
typedef struct s_earley_item EIM_Object;

/*:745*/
#line 12166 "./marpa.w"

/*67:*/
#line 793 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid);

/*:67*//*116:*/
#line 1038 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:116*//*118:*/
#line 1051 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:118*//*120:*/
#line 1060 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g);

/*:120*//*137:*/
#line 1142 "./marpa.w"

static inline
SYM symbol_new(struct marpa_g*g);
/*:137*//*142:*/
#line 1172 "./marpa.w"

static inline void symbol_free(SYM symbol);

/*:142*//*151:*/
#line 1208 "./marpa.w"

void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id);

/*:151*//*158:*/
#line 1235 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id);

/*:158*//*196:*/
#line 1403 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol);
/*:196*//*202:*/
#line 1444 "./marpa.w"

static inline SYM symbol_proper_alias(SYM symbol);
/*:202*//*205:*/
#line 1472 "./marpa.w"

static inline SYM symbol_null_alias(SYM symbol);
/*:205*//*208:*/
#line 1483 "./marpa.w"

static inline
SYM symbol_alias_create(GRAMMAR g,SYM symbol);
/*:208*//*217:*/
#line 1536 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:217*//*223:*/
#line 1562 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,guint length);
/*:223*//*240:*/
#line 1815 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,guint length);

/*:240*//*252:*/
#line 1974 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
/*:252*//*256:*/
#line 1986 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule);
/*:256*//*260:*/
#line 2002 "./marpa.w"

static inline gsize rule_length_get(RULE rule);
/*:260*//*274:*/
#line 2082 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule);
/*:274*//*278:*/
#line 2106 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule);
/*:278*//*292:*/
#line 2168 "./marpa.w"

static inline gint rule_is_nulling(GRAMMAR g,RULE rule);

/*:292*//*327:*/
#line 2304 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id);
/*:327*//*348:*/
#line 2380 "./marpa.w"

static inline gint symbol_instance_of_ahfa_item_get(AIM aim);
/*:348*//*355:*/
#line 2498 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g);
/*:355*//*392:*/
#line 2849 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:392*//*431:*/
#line 3222 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:431*//*434:*/
#line 3243 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:434*//*442:*/
#line 3373 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:442*//*461:*/
#line 3606 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id);

/*:461*//*478:*/
#line 3727 "./marpa.w"

static inline void create_AHFA_items(struct marpa_g*g);

/*:478*//*483:*/
#line 3793 "./marpa.w"

static gint cmp_by_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:483*//*486:*/
#line 3812 "./marpa.w"

static gint cmp_by_postdot_and_aimid(gconstpointer a,
gconstpointer b,gpointer user_data);
/*:486*//*506:*/
#line 3999 "./marpa.w"

static inline AEX aex_of_ahfa_by_aim_get(AHFA ahfa,AIM aim_sought);
/*:506*//*518:*/
#line 4085 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id);


/*:518*//*538:*/
#line 4258 "./marpa.w"

static gint AHFA_state_cmp(gconstpointer a,gconstpointer b);
/*:538*//*541:*/
#line 4284 "./marpa.w"

PRIVATE_NOT_INLINE void create_AHFA_states(struct marpa_g*g);
/*:541*//*560:*/
#line 4794 "./marpa.w"

static inline AHFA assign_AHFA_state(
AHFA state_p,GTree*duplicates);
/*:560*//*573:*/
#line 4985 "./marpa.w"
static
gint cmp_by_rule_sort_key(gconstpointer ap,
gconstpointer bp,gpointer user_data);

/*:573*//*576:*/
#line 5042 "./marpa.w"

static AHFA
create_predicted_AHFA_state(
struct marpa_g*g,
Bit_Vector prediction_rule_vector,
RULE*rule_by_sort_key,
DQUEUE states_p,
GTree*duplicates
);
/*:576*//*589:*/
#line 5216 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition);
/*:589*//*591:*/
#line 5223 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition);
/*:591*//*593:*/
#line 5231 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix);
/*:593*//*595:*/
#line 5244 "./marpa.w"
static inline
TRANS*transitions_new(struct marpa_g*g);
/*:595*//*597:*/
#line 5258 "./marpa.w"

static inline
void transition_add(struct obstack*obstack,AHFA from_ahfa,SYMID symid,AHFA to_ahfa);
/*:597*//*599:*/
#line 5275 "./marpa.w"

static inline
void completion_count_inc(struct obstack*obstack,AHFA from_ahfa,SYMID symid);
/*:599*//*635:*/
#line 5496 "./marpa.w"

static inline ES current_es_of_r(RECCE r);
/*:635*//*693:*/
#line 5833 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint value);
/*:693*//*695:*/
#line 5845 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*value);

/*:695*//*697:*/
#line 5854 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r);

/*:697*//*723:*/
#line 5979 "./marpa.w"

static inline ES earley_set_new(RECCE r,EARLEME id);
/*:723*//*746:*/
#line 6189 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key);
/*:746*//*748:*/
#line 6215 "./marpa.w"

static inline
EIM old_earley_item_assign(const RECCE r,const ES set,const ES origin,const AHFA state);
/*:748*//*750:*/
#line 6232 "./marpa.w"

static inline
EIM earley_item_assign(const RECCE r,const ES set,const ES origin,const AHFA state);
/*:750*//*754:*/
#line 6291 "./marpa.w"

static inline gint trace_earley_item_cmp(gconstpointer ap,gconstpointer bp);
/*:754*//*756:*/
#line 6302 "./marpa.w"

static inline gint earley_item_cmp(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED);
/*:756*//*760:*/
#line 6347 "./marpa.w"

static const char*invalid_source_type_message(guint type);
/*:760*//*776:*/
#line 6553 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r);
/*:776*//*778:*/
#line 6562 "./marpa.w"

Marpa_Earley_Set_ID marpa_earley_item_origin(struct marpa_r*r);
/*:778*//*786:*/
#line 6654 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r);
/*:786*//*789:*/
#line 6695 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r);
/*:789*//*791:*/
#line 6716 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r);
/*:791*//*799:*/
#line 6798 "./marpa.w"

static inline PIM*pim_sym_p_find(ES set,SYMID symid);
/*:799*//*801:*/
#line 6820 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid);
/*:801*//*812:*/
#line 6963 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r);
/*:812*//*830:*/
#line 7131 "./marpa.w"
static inline void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
SYMID token_id,
gpointer value);

/*:830*//*831:*/
#line 7138 "./marpa.w"
static inline void
completion_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
EIM cause);
/*:831*//*838:*/
#line 7250 "./marpa.w"
static inline void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause);

/*:838*//*841:*/
#line 7291 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item);

/*:841*//*871:*/
#line 7586 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r);
/*:871*//*889:*/
#line 7789 "./marpa.w"

static inline gint alternative_insertion_point(RECCE r,ALT new_alternative);
/*:889*//*891:*/
#line 7826 "./marpa.w"

static inline void alternative_set(
ALT alternative,ES start,EARLEME end,SYMID token_id,gpointer value);
/*:891*//*893:*/
#line 7844 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b);
/*:893*//*895:*/
#line 7868 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme);
/*:895*//*897:*/
#line 7885 "./marpa.w"

static inline gint alternative_insert(RECCE r,ALT alternative);
/*:897*//*940:*/
#line 8333 "./marpa.w"

static inline void earley_set_update_items(RECCE r,ES set);
/*:940*//*942:*/
#line 8357 "./marpa.w"

static inline void r_update_earley_sets(RECCE r);
/*:942*//*945:*/
#line 8383 "./marpa.w"

static void
postdot_items_create(struct marpa_r*r,ES set);
/*:945*//*975:*/
#line 8814 "./marpa.w"

static gint leo_completion_expand(RECCE r,EIM leo_completion);
/*:975*//*1004:*/
#line 9089 "./marpa.w"

static inline void ur_node_stack_init(URS stack);
/*:1004*//*1006:*/
#line 9099 "./marpa.w"

static inline void ur_node_stack_reset(URS stack);
/*:1006*//*1008:*/
#line 9106 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack);
/*:1008*//*1010:*/
#line 9116 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev);
/*:1010*//*1012:*/
#line 9127 "./marpa.w"

static inline void ur_node_push(URS stack,EIM earley_item,AEX aex);
/*:1012*//*1014:*/
#line 9145 "./marpa.w"

static inline UR ur_node_pop(URS stack);
/*:1014*//*1019:*/
#line 9251 "./marpa.w"

static inline gint psia_test_and_set(
struct obstack*obs,
struct s_bocage_setup_per_es*per_es_data,
EIM earley_item,
AEX ahfa_element_ix);
/*:1019*//*1055:*/
#line 9872 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base);
/*:1055*//*1057:*/
#line 9886 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item);
/*:1057*//*1064:*/
#line 10008 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,gint middle,WHEID wheid);
/*:1064*//*1067:*/
#line 10035 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,gint middle,WHEID wheid);
/*:1067*//*1112:*/
#line 10528 "./marpa.w"

gint marpa_or_node(struct marpa_r*r,int or_node_id,int*or_data);
/*:1112*//*1117:*/
#line 10599 "./marpa.w"

static inline guint bv_bits_to_size(guint bits);
/*:1117*//*1119:*/
#line 10609 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits);

/*:1119*//*1120:*/
#line 10613 "./marpa.w"

static inline Bit_Vector bv_create(guint bits);
/*:1120*//*1122:*/
#line 10633 "./marpa.w"

static inline Bit_Vector bv_obs_create(struct obstack*obs,guint bits);
/*:1122*//*1125:*/
#line 10666 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:1125*//*1127:*/
#line 10685 "./marpa.w"

static inline
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from);

/*:1127*//*1129:*/
#line 10698 "./marpa.w"

static inline
Bit_Vector bv_clone(Bit_Vector bv);

/*:1129*//*1131:*/
#line 10708 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:1131*//*1133:*/
#line 10716 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:1133*//*1135:*/
#line 10729 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:1135*//*1137:*/
#line 10733 "./marpa.w"

static inline void bv_clear(Bit_Vector bv);
/*:1137*//*1141:*/
#line 10748 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit);

/*:1141*//*1143:*/
#line 10756 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit);

/*:1143*//*1145:*/
#line 10764 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit);

/*:1145*//*1147:*/
#line 10769 "./marpa.w"

static inline gboolean bv_bit_test_and_set(Bit_Vector vector,guint bit);
/*:1147*//*1151:*/
#line 10797 "./marpa.w"

static inline
gboolean bv_is_empty(Bit_Vector addr);

/*:1151*//*1153:*/
#line 10810 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:1153*//*1155:*/
#line 10822 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1155*//*1157:*/
#line 10834 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:1157*//*1159:*/
#line 10846 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y);

/*:1159*//*1161:*/
#line 10920 "./marpa.w"

static inline
gboolean bv_scan(
Bit_Vector bv,guint start,guint*min,guint*max);

/*:1161*//*1163:*/
#line 10938 "./marpa.w"

static inline guint bv_count(Bit_Vector v);

/*:1163*//*1169:*/
#line 11027 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:1169*//*1174:*/
#line 11075 "./marpa.w"

static inline Bit_Matrix matrix_create(guint rows,guint columns);

/*:1174*//*1176:*/
#line 11083 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:1176*//*1178:*/
#line 11097 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:1178*//*1180:*/
#line 11115 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row);

/*:1180*//*1183:*/
#line 11124 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column);

/*:1183*//*1186:*/
#line 11133 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column);

/*:1186*//*1189:*/
#line 11142 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column);

/*:1189*//*1191:*/
#line 11195 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:1191*//*1201:*/
#line 11292 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_size);

/*:1201*//*1216:*/
#line 11425 "./marpa.w"

static inline void psar_init(const PSAR psar,gint length);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
/*:1216*//*1222:*/
#line 11481 "./marpa.w"

static inline void psar_reset(const PSAR psar);
/*:1222*//*1224:*/
#line 11500 "./marpa.w"

static inline void psar_dealloc(const PSAR psar);
/*:1224*//*1226:*/
#line 11521 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar);
/*:1226*//*1230:*/
#line 11548 "./marpa.w"

static inline PSL psl_alloc(const PSAR psar);
/*:1230*//*1267:*/
#line 11856 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags);
/*:1267*//*1279:*/
#line 11958 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id);

/*:1279*//*1287:*/
#line 11989 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id);

/*:1287*//*1289:*/
#line 12031 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE gchar*eim_tag_safe(gchar*buffer,EIM eim);
PRIVATE_NOT_INLINE gchar*eim_tag(EIM eim);
#endif
/*:1289*//*1291:*/
#line 12059 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim);
#endif
/*:1291*//*1293:*/
#line 12082 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*or_tag_safe(gchar*buffer,OR or);
PRIVATE_NOT_INLINE const gchar*or_tag(OR or);
#endif
/*:1293*/
#line 12167 "./marpa.w"

/*65:*/
#line 777 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symid,
SYM symbol)
{
g_array_insert_val(g->t_symbols,(unsigned)symid,symbol);
}

/*:65*//*74:*/
#line 821 "./marpa.w"

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

/*:74*/
#line 12168 "./marpa.w"

/*41:*/
#line 664 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:41*//*47:*/
#line 710 "./marpa.w"

struct marpa_g*marpa_g_new(void)
{struct marpa_g*g= g_slice_new(struct marpa_g);
/*55:*/
#line 740 "./marpa.w"

g->t_id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:55*//*59:*/
#line 753 "./marpa.w"

g->t_symbols= g_array_new(FALSE,FALSE,sizeof(SYM));
/*:59*//*69:*/
#line 802 "./marpa.w"

g->t_rules= g_array_new(FALSE,FALSE,sizeof(RULE));
/*:69*//*77:*/
#line 839 "./marpa.w"

g->t_start_symid= -1;
/*:77*//*83:*/
#line 866 "./marpa.w"

g->t_null_start_rule= NULL;
g->t_proper_start_rule= NULL;

/*:83*//*86:*/
#line 891 "./marpa.w"

LV_Size_of_G(g)= 0;

/*:86*//*89:*/
#line 904 "./marpa.w"

g->t_max_rule_length= 0;

/*:89*//*93:*/
#line 912 "./marpa.w"

g->t_is_precomputed= FALSE;
/*:93*//*96:*/
#line 920 "./marpa.w"

g->t_has_loop= FALSE;
/*:96*//*100:*/
#line 935 "./marpa.w"

g->t_is_lhs_terminal_ok= TRUE;
/*:100*//*106:*/
#line 969 "./marpa.w"
g->t_bv_symid_is_terminal= NULL;
/*:106*//*109:*/
#line 983 "./marpa.w"

g->t_context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:109*//*124:*/
#line 1084 "./marpa.w"

obstack_init(&g->t_obs);
obstack_init(&g->t_obs_tricky);
/*:124*//*128:*/
#line 1104 "./marpa.w"

g->t_error= NULL;
/*:128*//*213:*/
#line 1514 "./marpa.w"

g->t_symbol_callback_arg= NULL;
g->t_symbol_callback= NULL;
/*:213*//*320:*/
#line 2285 "./marpa.w"

g->t_rule_callback_arg= NULL;
g->t_rule_callback= NULL;
/*:320*//*458:*/
#line 3593 "./marpa.w"

g->t_AHFA_items= NULL;
g->t_AHFA_items_by_rule= NULL;
/*:458*//*513:*/
#line 4055 "./marpa.w"

g->t_AHFA= NULL;
AHFA_Count_of_G(g)= 0;
/*:513*//*1275:*/
#line 11934 "./marpa.w"

g->t_message_callback_arg= NULL;
g->t_message_callback= NULL;
/*:1275*/
#line 713 "./marpa.w"

return g;}
/*:47*//*49:*/
#line 718 "./marpa.w"

void marpa_g_free(struct marpa_g*g)
{/*60:*/
#line 755 "./marpa.w"

{Marpa_Symbol_ID id;for(id= 0;id<(Marpa_Symbol_ID)g->t_symbols->len;id++)
{symbol_free(SYM_by_ID(g,id));}}
g_array_free(g->t_symbols,TRUE);

/*:60*//*70:*/
#line 804 "./marpa.w"

g_array_free(g->t_rules,TRUE);

/*:70*//*107:*/
#line 970 "./marpa.w"

if(g->t_bv_symid_is_terminal){bv_free(g->t_bv_symid_is_terminal);}

/*:107*//*110:*/
#line 985 "./marpa.w"
g_hash_table_destroy(Context_of_G(g));

/*:110*//*125:*/
#line 1087 "./marpa.w"

obstack_free(&g->t_obs,NULL);
obstack_free(&g->t_obs_tricky,NULL);

/*:125*//*459:*/
#line 3596 "./marpa.w"

if(g->t_AHFA_items){g_free(g->t_AHFA_items);};
if(g->t_AHFA_items_by_rule){g_free(g->t_AHFA_items_by_rule);};

/*:459*//*514:*/
#line 4059 "./marpa.w"
if(g->t_AHFA){
AHFAID id;
for(id= 0;id<AHFA_Count_of_G(g);id++){
AHFA ahfa_state= AHFA_of_G_by_ID(g,id);
/*515:*/
#line 4069 "./marpa.w"
{
TRANS*ahfa_transitions= LV_TRANSs_of_AHFA(ahfa_state);
if(ahfa_transitions)
g_free(TRANSs_of_AHFA(ahfa_state));
}

/*:515*/
#line 4063 "./marpa.w"

}
STOLEN_DQUEUE_DATA_FREE(g->t_AHFA);
}

/*:514*/
#line 720 "./marpa.w"

g_slice_free(struct marpa_g,g);
}
/*:49*//*56:*/
#line 742 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->t_id;}
/*:56*//*61:*/
#line 763 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->t_symbols;}
/*:61*//*66:*/
#line 788 "./marpa.w"

static inline gint symbol_is_valid(
const struct marpa_g*g,const Marpa_Symbol_ID symid){
return symid>=0&&(guint)symid<g->t_symbols->len;
}
/*:66*//*71:*/
#line 810 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->t_rules;}
/*:71*//*78:*/
#line 841 "./marpa.w"

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
{return g->t_start_symid;}
/*:78*//*80:*/
#line 848 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID symid)
{
/*1245:*/
#line 11698 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1245*/
#line 851 "./marpa.w"

/*1248:*/
#line 11708 "./marpa.w"

if(G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar precomputed";
return failure_indicator;
}
/*:1248*/
#line 852 "./marpa.w"

/*1250:*/
#line 11720 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1250*/
#line 853 "./marpa.w"

g->t_start_symid= symid;
return TRUE;
}
/*:80*//*94:*/
#line 914 "./marpa.w"

gboolean marpa_is_precomputed(const struct marpa_g*const g)
{return G_is_Precomputed(g);}

/*:94*//*97:*/
#line 923 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->t_has_loop;}
/*:97*//*101:*/
#line 938 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->t_is_lhs_terminal_ok;}
/*:101*//*103:*/
#line 945 "./marpa.w"

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
/*:103*//*115:*/
#line 1028 "./marpa.w"

static inline
void g_context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value
= g_new(struct marpa_context_int_value,1);
value->t_type= MARPA_CONTEXT_INT;
value->t_data= payload;
g_hash_table_insert(Context_of_G(g),(gpointer)key,value);
}
/*:115*//*117:*/
#line 1041 "./marpa.w"

static inline
void context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value
= g_new(struct marpa_context_const_value,1);
value->t_type= MARPA_CONTEXT_CONST;
value->t_data= payload;
g_hash_table_insert(Context_of_G(g),(gpointer)key,value);
}
/*:117*//*119:*/
#line 1057 "./marpa.w"

static inline void g_context_clear(struct marpa_g*g){
g_hash_table_remove_all(Context_of_G(g));}
/*:119*//*121:*/
#line 1063 "./marpa.w"

union marpa_context_value*marpa_g_context_value(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(Context_of_G(g),key);}
/*:121*//*130:*/
#line 1112 "./marpa.w"

Marpa_Error_ID marpa_g_error(const struct marpa_g*g)
{return g->t_error?g->t_error:"unknown error";}
/*:130*//*138:*/
#line 1145 "./marpa.w"

static inline SYM
symbol_new(struct marpa_g*g)
{
SYM symbol= g_malloc(sizeof(SYM_Object));
/*136:*/
#line 1139 "./marpa.w"

(symbol)->t_type= TOKEN_OR_NODE;

/*:136*//*144:*/
#line 1179 "./marpa.w"
LV_ID_of_SYM(symbol)= g->t_symbols->len;

/*:144*//*146:*/
#line 1188 "./marpa.w"

symbol->t_lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:146*//*153:*/
#line 1218 "./marpa.w"

symbol->t_rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:153*//*160:*/
#line 1240 "./marpa.w"

symbol->t_is_accessible= FALSE;
/*:160*//*166:*/
#line 1266 "./marpa.w"

symbol->t_is_counted= FALSE;
/*:166*//*170:*/
#line 1284 "./marpa.w"

symbol->t_is_nullable= FALSE;
/*:170*//*176:*/
#line 1310 "./marpa.w"

symbol->t_is_nulling= FALSE;
/*:176*//*182:*/
#line 1337 "./marpa.w"

symbol->t_is_terminal= FALSE;
/*:182*//*188:*/
#line 1366 "./marpa.w"

symbol->t_is_productive= FALSE;
/*:188*//*194:*/
#line 1391 "./marpa.w"
symbol->t_is_start= FALSE;
/*:194*//*200:*/
#line 1421 "./marpa.w"

symbol->t_is_proper_alias= FALSE;
symbol->t_is_nulling_alias= FALSE;
symbol->t_alias= NULL;

/*:200*/
#line 1150 "./marpa.w"

{
SYMID id= ID_of_SYM(symbol);
g_symbol_add(g,id,symbol);
}
return symbol;
}

/*:138*//*140:*/
#line 1160 "./marpa.w"

Marpa_Symbol_ID
marpa_symbol_new(struct marpa_g*g)
{
SYMID id= ID_of_SYM(symbol_new(g));
symbol_callback(g,id);
return id;
}

/*:140*//*141:*/
#line 1169 "./marpa.w"

static inline void symbol_free(SYM symbol)
{/*147:*/
#line 1190 "./marpa.w"

g_array_free(symbol->t_lhs,TRUE);
/*:147*//*154:*/
#line 1220 "./marpa.w"
g_array_free(symbol->t_rhs,TRUE);

/*:154*/
#line 1171 "./marpa.w"
g_free(symbol);}
/*:141*//*148:*/
#line 1195 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1246:*/
#line 11700 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1246*/
#line 1197 "./marpa.w"

/*1250:*/
#line 11720 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1250*/
#line 1198 "./marpa.w"

return SYM_by_ID(g,symid)->t_lhs;}
/*:148*//*150:*/
#line 1202 "./marpa.w"
static inline
void symbol_lhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_lhs,rule_id);}
void
marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symid,Marpa_Rule_ID rule_id)
{symbol_lhs_add(SYM_by_ID(g,symid),rule_id);}
/*:150*//*155:*/
#line 1225 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1246:*/
#line 11700 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1246*/
#line 1227 "./marpa.w"

/*1250:*/
#line 11720 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1250*/
#line 1228 "./marpa.w"

return SYM_by_ID(g,symid)->t_rhs;}
/*:155*//*157:*/
#line 1232 "./marpa.w"
static inline
void symbol_rhs_add(SYM symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->t_rhs,rule_id);}
/*:157*//*161:*/
#line 1250 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->t_is_accessible;}
/*:161*//*163:*/
#line 1256 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->t_is_accessible= value;}
/*:163*//*167:*/
#line 1276 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->t_is_counted;}
/*:167*//*171:*/
#line 1294 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->t_is_nullable;}
/*:171*//*173:*/
#line 1300 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->t_is_nullable= value;}
/*:173*//*177:*/
#line 1320 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 1322 "./marpa.w"

/*1250:*/
#line 11720 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1250*/
#line 1323 "./marpa.w"

return SYM_is_Nulling(SYM_by_ID(g,symid));}
/*:177*//*179:*/
#line 1328 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_is_Nulling(SYM_by_ID(g,id))= value;}
/*:179*//*183:*/
#line 1350 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYMID_is_Terminal(g,id);}
/*:183*//*185:*/
#line 1356 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{LV_SYMID_is_Terminal(g,id)= value;}
/*:185*//*189:*/
#line 1376 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return SYM_by_ID(g,id)->t_is_productive;}
/*:189*//*191:*/
#line 1382 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{SYM_by_ID(g,id)->t_is_productive= value?1:0;}
/*:191*//*195:*/
#line 1394 "./marpa.w"

static inline
gint symbol_is_start(SYM symbol)
{return symbol->t_is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symid)
{/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 1399 "./marpa.w"

/*1250:*/
#line 11720 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1250*/
#line 1400 "./marpa.w"

return symbol_is_start(SYM_by_ID(g,symid));
}
/*:195*//*201:*/
#line 1430 "./marpa.w"

static inline
SYM symbol_proper_alias(SYM symbol)
{return symbol->t_is_nulling_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM proper_alias;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 1438 "./marpa.w"

/*1250:*/
#line 11720 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1250*/
#line 1439 "./marpa.w"

symbol= SYM_by_ID(g,symid);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:ID_of_SYM(proper_alias);
}
/*:201*//*204:*/
#line 1453 "./marpa.w"

static inline
SYM symbol_null_alias(SYM symbol)
{return symbol->t_is_proper_alias?symbol->t_alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symid)
{
SYM symbol;
SYM alias;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 1461 "./marpa.w"

/*1250:*/
#line 11720 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1250*/
#line 1462 "./marpa.w"

symbol= SYM_by_ID(g,symid);
alias= symbol_null_alias(symbol);
if(alias==NULL){
g_context_int_add(g,"symid",symid);
g->t_error= "no alias";
return-1;
}
return ID_of_SYM(alias);
}
/*:204*//*209:*/
#line 1486 "./marpa.w"
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

/*:209*//*214:*/
#line 1517 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->t_symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->t_symbol_callback_arg= cb_arg;}
gpointer marpa_symbol_callback_arg(struct marpa_g*g)
{return g->t_symbol_callback_arg;}
/*:214*//*216:*/
#line 1532 "./marpa.w"

static inline void symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->t_symbol_callback;
if(cb){(*cb)(g,id);}}
/*:216*//*224:*/
#line 1568 "./marpa.w"

PRIVATE_NOT_INLINE
RULE rule_start(GRAMMAR g,
SYMID lhs,SYMID*rhs,guint length)
{
/*1246:*/
#line 11700 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1246*/
#line 1573 "./marpa.w"

RULE rule;
const gint rule_sizeof= G_STRUCT_OFFSET(struct s_rule,t_symbols)+
(length+1)*sizeof(rule->t_symbols[0]);
/*249:*/
#line 1954 "./marpa.w"

{
SYMID symid= lhs;
/*1250:*/
#line 11720 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1250*/
#line 1957 "./marpa.w"

}
{guint rh_index;
for(rh_index= 0;rh_index<length;rh_index++){
SYMID symid= rhs[rh_index];
/*1250:*/
#line 11720 "./marpa.w"

if(!symbol_is_valid(g,symid)){
g_context_clear(g);
g_context_int_add(g,"symid",symid);
g->t_error= "invalid symbol id";
return failure_indicator;
}
/*:1250*/
#line 1962 "./marpa.w"

}
}

/*:249*/
#line 1577 "./marpa.w"

rule= obstack_alloc(&g->t_obs,rule_sizeof);
/*250:*/
#line 1966 "./marpa.w"

Length_of_RULE(rule)= length;
rule->t_symbols[0]= lhs;
{guint i;for(i= 0;i<length;i++){
rule->t_symbols[i+1]= rhs[i];}}
/*:250*/
#line 1579 "./marpa.w"

/*265:*/
#line 2022 "./marpa.w"
rule->t_id= g->t_rules->len;

/*:265*//*268:*/
#line 2034 "./marpa.w"

rule->t_is_discard= FALSE;
/*:268*//*282:*/
#line 2118 "./marpa.w"

rule->t_is_loop= FALSE;
/*:282*//*287:*/
#line 2139 "./marpa.w"

rule->t_is_virtual_loop= FALSE;
/*:287*//*294:*/
#line 2174 "./marpa.w"

RULE_is_Used(rule)= 1;
/*:294*//*298:*/
#line 2190 "./marpa.w"

rule->t_is_start= FALSE;
/*:298*//*302:*/
#line 2220 "./marpa.w"

rule->t_is_virtual_lhs= FALSE;
/*:302*//*306:*/
#line 2231 "./marpa.w"

rule->t_is_virtual_rhs= FALSE;
/*:306*//*310:*/
#line 2245 "./marpa.w"
rule->t_virtual_start= -1;
/*:310*//*314:*/
#line 2261 "./marpa.w"
rule->t_virtual_end= -1;
/*:314*//*331:*/
#line 2319 "./marpa.w"
rule->t_original= -1;
/*:331*//*336:*/
#line 2333 "./marpa.w"
rule->t_real_symbol_count= 0;
/*:336*//*340:*/
#line 2342 "./marpa.w"

rule->t_is_semantic_equivalent= FALSE;
/*:340*/
#line 1580 "./marpa.w"

rule_add(g,rule->t_id,rule);
/*242:*/
#line 1832 "./marpa.w"

symbol_lhs_add(SYM_by_ID(g,rule->t_symbols[0]),rule->t_id);
if(Length_of_RULE(rule)> 0){
gint rh_list_ix;
const guint alloc_size= Length_of_RULE(rule)*sizeof(SYMID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*246:*/
#line 1899 "./marpa.w"

{

gint rhs_ix= (gint)Length_of_RULE(rule)-1;
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

/*:246*/
#line 1840 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
SYM_by_ID(g,rh_symbol_list[rh_list_ix]),
rule->t_id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:242*/
#line 1582 "./marpa.w"

return rule;
}

/*:224*//*225:*/
#line 1586 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,guint length)
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

/*:225*//*226:*/
#line 1607 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
guint min,gint flags)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 1612 "./marpa.w"

Marpa_Rule_ID original_rule_id;
RULE original_rule;
Marpa_Symbol_ID internal_lhs_id,*temp_rhs;
if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE){
g_context_clear(g);
g->t_error= (Marpa_Error_ID)"duplicate rule";
return failure_indicator;
}

/*228:*/
#line 1643 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){
g_context_clear(g);
g->t_error= "internal_error";
return failure_indicator;
}
RULE_is_Used(original_rule)= 0;
original_rule_id= original_rule->t_id;
rule_callback(g,original_rule_id);

/*:228*/
#line 1622 "./marpa.w"

/*229:*/
#line 1654 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g_context_clear(g);
g_context_int_add(g,"symid",separator_id);
g->t_error= "bad separator";
return failure_indicator;
}

/*:229*/
#line 1623 "./marpa.w"

/*230:*/
#line 1662 "./marpa.w"

SYM_by_ID(g,rhs_id)->t_is_counted= 1;
if(separator_id>=0){SYM_by_ID(g,separator_id)->t_is_counted= 1;}
/*:230*/
#line 1624 "./marpa.w"

if(min==0){/*231:*/
#line 1665 "./marpa.w"

{RULE rule= rule_start(g,lhs_id,0,0);
if(!rule){/*1255:*/
#line 11755 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1255*/
#line 1667 "./marpa.w"
}
rule->t_is_semantic_equivalent= TRUE;
rule->t_original= original_rule_id;
rule_callback(g,rule->t_id);
}
/*:231*/
#line 1625 "./marpa.w"
}
min= 1;
/*232:*/
#line 1672 "./marpa.w"

internal_lhs_id= ID_of_SYM(symbol_new(g));
symbol_callback(g,internal_lhs_id);
/*:232*/
#line 1627 "./marpa.w"

/*233:*/
#line 1686 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:233*/
#line 1628 "./marpa.w"

/*235:*/
#line 1689 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*1255:*/
#line 11755 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1255*/
#line 1693 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;

rule->t_is_virtual_rhs= TRUE;
rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->t_id);
}
/*:235*/
#line 1629 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*236:*/
#line 1702 "./marpa.w"

{RULE rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*1255:*/
#line 11755 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1255*/
#line 1707 "./marpa.w"
}
rule->t_original= original_rule_id;
rule->t_is_semantic_equivalent= TRUE;
rule->t_is_virtual_rhs= TRUE;
rule->t_real_symbol_count= 1;
rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->t_id);
}
/*:236*/
#line 1631 "./marpa.w"

}
/*237:*/
#line 1719 "./marpa.w"

{RULE rule;
guint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1255:*/
#line 11755 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1255*/
#line 1729 "./marpa.w"
}
rule->t_is_virtual_lhs= TRUE;
rule->t_real_symbol_count= rhs_ix;
rule_callback(g,rule->t_id);
}
/*:237*/
#line 1633 "./marpa.w"

/*238:*/
#line 1734 "./marpa.w"

{RULE rule;
guint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*1255:*/
#line 11755 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1255*/
#line 1741 "./marpa.w"
}
rule->t_is_virtual_lhs= TRUE;
rule->t_is_virtual_rhs= TRUE;
rule->t_real_symbol_count= rhs_ix-1;
rule_callback(g,rule->t_id);
}

/*:238*/
#line 1634 "./marpa.w"

/*234:*/
#line 1688 "./marpa.w"
g_free(temp_rhs);
/*:234*/
#line 1635 "./marpa.w"

return original_rule_id;
}
/*:226*//*239:*/
#line 1790 "./marpa.w"

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
const guint rule_length= Length_of_RULE(rule);
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
/*:239*//*251:*/
#line 1971 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(RULE rule){
return rule->t_symbols[0];}
/*:251*//*253:*/
#line 1976 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 1978 "./marpa.w"

/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 1979 "./marpa.w"

return rule_lhs_get(RULE_by_ID(g,rule_id));}
/*:253*//*255:*/
#line 1983 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(RULE rule){
return rule->t_symbols+1;}
/*:255*//*257:*/
#line 1988 "./marpa.w"

Marpa_Symbol_ID marpa_rule_rh_symbol(struct marpa_g*g,Marpa_Rule_ID rule_id,guint ix){
RULE rule;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 1991 "./marpa.w"

/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 1992 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
if(Length_of_RULE(rule)<=ix)return-1;
return RHS_ID_of_RULE(rule,ix);
}
/*:257*//*259:*/
#line 1999 "./marpa.w"

static inline gsize rule_length_get(RULE rule){
return Length_of_RULE(rule);}
/*:259*//*261:*/
#line 2004 "./marpa.w"

gint marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 2006 "./marpa.w"

/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 2007 "./marpa.w"

return rule_length_get(RULE_by_ID(g,rule_id));}
/*:261*//*269:*/
#line 2036 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_discard;}
/*:269*//*273:*/
#line 2069 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,RULE rule)
{
Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
return SYM_by_ID(g,lhs_id)->t_is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 2076 "./marpa.w"

RULE rule;
/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 2078 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:273*//*277:*/
#line 2089 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,RULE rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++){
Marpa_Symbol_ID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_by_ID(g,rhs_id)->t_is_productive)return FALSE;
}
return TRUE;}
gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 2100 "./marpa.w"

RULE rule;
/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 2102 "./marpa.w"

rule= RULE_by_ID(g,rule_id);
return rule_is_productive(g,rule);
}
/*:277*//*283:*/
#line 2122 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 2125 "./marpa.w"

/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 2126 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_loop;}
/*:283*//*288:*/
#line 2143 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 2146 "./marpa.w"

/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 2147 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_virtual_loop;}
/*:288*//*291:*/
#line 2155 "./marpa.w"

static inline gint
rule_is_nulling(GRAMMAR g,RULE rule)
{
guint rh_ix;
for(rh_ix= 0;rh_ix<Length_of_RULE(rule);rh_ix++)
{
SYMID rhs_id= RHS_ID_of_RULE(rule,rh_ix);
if(!SYM_is_Nulling(SYM_by_ID(g,rhs_id)))
return FALSE;
}
return TRUE;
}
/*:291*//*295:*/
#line 2178 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 2181 "./marpa.w"

/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 2182 "./marpa.w"

return RULE_is_Used(RULE_by_ID(g,rule_id));}
/*:295*//*299:*/
#line 2194 "./marpa.w"

gint marpa_rule_is_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 2197 "./marpa.w"

/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 2198 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_is_start;}
/*:299*//*303:*/
#line 2223 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_virtual_lhs;}
/*:303*//*307:*/
#line 2234 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_is_virtual_rhs;}
/*:307*//*311:*/
#line 2246 "./marpa.w"

guint marpa_virtual_start(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 2249 "./marpa.w"

/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 2250 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_start;
}
/*:311*//*315:*/
#line 2262 "./marpa.w"

guint marpa_virtual_end(struct marpa_g*g,Marpa_Rule_ID rule_id)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 2265 "./marpa.w"

/*1251:*/
#line 11727 "./marpa.w"

if(!RULEID_of_G_is_Valid(g,rule_id)){
g_context_clear(g);
g_context_int_add(g,"rule_id",rule_id);
g->t_error= "invalid rule id";
return failure_indicator;
}
/*:1251*/
#line 2266 "./marpa.w"

return RULE_by_ID(g,rule_id)->t_virtual_end;
}
/*:315*//*321:*/
#line 2288 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->t_rule_callback= cb;}
/*:321*//*323:*/
#line 2293 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->t_rule_callback_arg= cb_arg;}
/*:323*//*325:*/
#line 2298 "./marpa.w"

gpointer marpa_rule_callback_arg(struct marpa_g*g)
{return g->t_rule_callback_arg;}
/*:325*//*328:*/
#line 2309 "./marpa.w"

static inline void rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->t_rule_callback;
if(cb){(*cb)(g,id);}}

/*:328*//*332:*/
#line 2320 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(const struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_original;}
/*:332*//*337:*/
#line 2334 "./marpa.w"

guint marpa_real_symbol_count(const struct marpa_g*g,Marpa_Rule_ID id)
{return RULE_by_ID(g,id)->t_real_symbol_count;}
/*:337*//*344:*/
#line 2358 "./marpa.w"

Marpa_Rule_ID
marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
RULE rewrite_rule= RULE_by_ID(g,id);
return rewrite_rule->t_is_semantic_equivalent?rewrite_rule->
t_original:-1;
}

/*:344*//*350:*/
#line 2394 "./marpa.w"

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

/*:350*//*351:*/
#line 2420 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
if(!census(g))return NULL;
if(!CHAF_rewrite(g))return NULL;
if(!g_augment(g))return NULL;
loop_detect(g);
create_AHFA_items(g);
create_AHFA_states(g);
/*607:*/
#line 5350 "./marpa.w"
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

/*:607*/
#line 2429 "./marpa.w"

return g;
}
/*:351*//*354:*/
#line 2467 "./marpa.w"

static struct marpa_g*census(struct marpa_g*g)
{
/*1246:*/
#line 11700 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1246*/
#line 2470 "./marpa.w"

/*356:*/
#line 2500 "./marpa.w"

guint pre_rewrite_rule_count= g->t_rules->len;
guint pre_rewrite_symbol_count= g->t_symbols->len;

/*:356*//*361:*/
#line 2537 "./marpa.w"

Marpa_Symbol_ID original_start_symid= g->t_start_symid;
SYM original_start_symbol;

/*:361*//*365:*/
#line 2576 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:365*//*371:*/
#line 2635 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:371*//*373:*/
#line 2662 "./marpa.w"

Bit_Vector nullable_v;
/*:373*//*377:*/
#line 2688 "./marpa.w"

Bit_Vector productive_v;
/*:377*//*380:*/
#line 2729 "./marpa.w"
Bit_Matrix reach_matrix;
/*:380*//*383:*/
#line 2747 "./marpa.w"

Bit_Vector accessible_v;

/*:383*/
#line 2471 "./marpa.w"

/*357:*/
#line 2504 "./marpa.w"

if(g->t_rules->len<=0){g->t_error= "no rules";return NULL;}
/*:357*/
#line 2472 "./marpa.w"

/*358:*/
#line 2511 "./marpa.w"

if(G_is_Precomputed(g)){g->t_error= "precomputed";return NULL;}
/*:358*/
#line 2473 "./marpa.w"

/*360:*/
#line 2517 "./marpa.w"

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

/*:360*/
#line 2474 "./marpa.w"

/*362:*/
#line 2541 "./marpa.w"

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
/*:362*/
#line 2475 "./marpa.w"

/*363:*/
#line 2560 "./marpa.w"

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
/*:363*/
#line 2476 "./marpa.w"

if(have_marked_terminals){
/*367:*/
#line 2591 "./marpa.w"

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

/*:367*/
#line 2478 "./marpa.w"

}else{
/*366:*/
#line 2580 "./marpa.w"

if(have_empty_rule&&g->t_is_lhs_terminal_ok){
g->t_error= "empty rule and unmarked terminals";
return NULL;
}
/*:366*/
#line 2480 "./marpa.w"
;
if(g->t_is_lhs_terminal_ok){
/*368:*/
#line 2615 "./marpa.w"

{Marpa_Symbol_ID symid;
bv_fill(terminal_v);
for(symid= 0;symid<(Marpa_Symbol_ID)g->t_symbols->len;symid++)
{LV_SYMID_is_Terminal(g,symid)= 1;}}
/*:368*/
#line 2482 "./marpa.w"

}else{
/*369:*/
#line 2620 "./marpa.w"

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
/*:369*/
#line 2484 "./marpa.w"

}
}
/*372:*/
#line 2640 "./marpa.w"

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
/*:372*/
#line 2487 "./marpa.w"

/*375:*/
#line 2667 "./marpa.w"

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
/*:375*/
#line 2488 "./marpa.w"

/*376:*/
#line 2681 "./marpa.w"

if(!bv_bit_test(productive_v,(guint)g->t_start_symid))
{
g_context_int_add(g,"symid",g->t_start_symid);
g->t_error= "unproductive start symbol";
return NULL;
}
/*:376*/
#line 2489 "./marpa.w"

/*379:*/
#line 2711 "./marpa.w"

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
/*:379*/
#line 2490 "./marpa.w"

/*382:*/
#line 2733 "./marpa.w"

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
/*:382*/
#line 2491 "./marpa.w"

/*384:*/
#line 2752 "./marpa.w"

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
SYM_is_Nulling(SYM_by_ID(g,productive_id))= 1;
}
}
bv_free(reaches_terminal_v);
}

/*:384*/
#line 2492 "./marpa.w"

/*364:*/
#line 2572 "./marpa.w"

bv_free(terminal_v);
/*:364*//*370:*/
#line 2632 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:370*//*374:*/
#line 2664 "./marpa.w"

bv_free(nullable_v);

/*:374*//*378:*/
#line 2690 "./marpa.w"

bv_free(productive_v);

/*:378*/
#line 2493 "./marpa.w"

/*381:*/
#line 2730 "./marpa.w"

matrix_free(reach_matrix);

/*:381*/
#line 2494 "./marpa.w"

g->t_is_precomputed= TRUE;
return g;
}
/*:354*//*391:*/
#line 2828 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*393:*/
#line 2851 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:393*//*397:*/
#line 2902 "./marpa.w"

guint factor_count;
guint*factor_positions;
/*:397*//*402:*/
#line 2951 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:402*/
#line 2831 "./marpa.w"

/*398:*/
#line 2905 "./marpa.w"

factor_positions= g_new(guint,g->t_max_rule_length);
/*:398*//*403:*/
#line 2954 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->t_max_rule_length);
/*:403*/
#line 2832 "./marpa.w"

/*395:*/
#line 2863 "./marpa.w"

{gint no_of_symbols= SYM_Count_of_G(g);
Marpa_Symbol_ID symid;
for(symid= 0;symid<no_of_symbols;symid++){
SYM symbol= SYM_by_ID(g,symid);
SYM alias;
if(!symbol->t_is_nullable)continue;
if(SYM_is_Nulling(symbol))continue;
if(!symbol->t_is_accessible)continue;
if(!symbol->t_is_productive)continue;
if(symbol_null_alias(symbol))continue;
alias= symbol_alias_create(g,symbol);
symbol_callback(g,ID_of_SYM(alias));
}}

/*:395*/
#line 2833 "./marpa.w"

no_of_rules= RULE_Count_of_G(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
const guint rule_length= Length_of_RULE(rule);
guint nullable_suffix_ix= 0;
/*394:*/
#line 2855 "./marpa.w"

if(!RULE_is_Used(rule)){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){RULE_is_Used(rule)= 0;goto NEXT_RULE;}

/*:394*/
#line 2839 "./marpa.w"

/*396:*/
#line 2886 "./marpa.w"

{guint rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(g,symid);
if(SYM_is_Nulling(symbol))continue;
if(symbol_null_alias(symbol)){

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}}
/*:396*/
#line 2840 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*400:*/
#line 2911 "./marpa.w"

RULE_is_Used(rule)= 0;
{guint unprocessed_factor_count;

guint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= LHS_ID_of_RULE(rule);
guint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*406:*/
#line 2964 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symid;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= first_factor_position-piece_start;
guint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*401:*/
#line 2930 "./marpa.w"
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

/*:401*/
#line 2972 "./marpa.w"

/*407:*/
#line 2991 "./marpa.w"

{
guint remaining_rhs_length,piece_rhs_length;
/*408:*/
#line 3003 "./marpa.w"

{
guint real_symbol_count= piece_end-piece_start+1;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
remaining_rhs[piece_rhs_length]= 
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
}
{RULE chaf_rule;
guint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3015 "./marpa.w"

}

/*:408*/
#line 2994 "./marpa.w"
;
/*409:*/
#line 3018 "./marpa.w"

{
guint chaf_rule_length= Length_of_RULE(rule)-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;remaining_rhs_length++)
{
Marpa_Symbol_ID original_id= 
RHS_ID_of_RULE(rule,piece_start+remaining_rhs_length);
SYM alias= symbol_null_alias(SYM_by_ID(g,original_id));
remaining_rhs[remaining_rhs_length]= 
alias?ID_of_SYM(alias):original_id;
}
}
{
RULE chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= 
rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3036 "./marpa.w"

}

/*:409*/
#line 2995 "./marpa.w"
;
/*410:*/
#line 3041 "./marpa.w"
{
Marpa_Symbol_ID proper_id= RHS_ID_of_RULE(rule,first_factor_position);
SYM alias= symbol_null_alias(SYM_by_ID(g,proper_id));
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
ID_of_SYM(alias);
}
{RULE chaf_rule;
guint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3051 "./marpa.w"

}

/*:410*/
#line 2996 "./marpa.w"
;
/*411:*/
#line 3060 "./marpa.w"

if(piece_start<nullable_suffix_ix){
RULE chaf_rule;
guint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3065 "./marpa.w"

}

/*:411*/
#line 2997 "./marpa.w"
;
}

/*:407*/
#line 2973 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*401:*/
#line 2930 "./marpa.w"
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

/*:401*/
#line 2978 "./marpa.w"

/*413:*/
#line 3070 "./marpa.w"
{
guint piece_rhs_length;
RULE chaf_rule;
guint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:413*//*414:*/
#line 3079 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symid;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3085 "./marpa.w"


/*:414*//*415:*/
#line 3088 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3093 "./marpa.w"


/*:415*//*416:*/
#line 3096 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3102 "./marpa.w"


/*:416*//*417:*/
#line 3105 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3108 "./marpa.w"


/*:417*//*418:*/
#line 3111 "./marpa.w"
}

/*:418*/
#line 2979 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symid;
piece_start= piece_end+1;

/*:406*/
#line 2922 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*419:*/
#line 3115 "./marpa.w"
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
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:419*//*420:*/
#line 3129 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3134 "./marpa.w"


/*:420*//*421:*/
#line 3137 "./marpa.w"

second_factor_proper_id= RHS_ID_of_RULE(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3142 "./marpa.w"


/*:421*//*422:*/
#line 3145 "./marpa.w"

first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3151 "./marpa.w"


/*:422*//*423:*/
#line 3155 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3159 "./marpa.w"

}

/*:423*//*424:*/
#line 3163 "./marpa.w"
}

/*:424*/
#line 2925 "./marpa.w"

}else{
/*425:*/
#line 3166 "./marpa.w"
{
guint piece_rhs_length;
RULE chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
guint real_symbol_count;
guint first_factor_position= factor_positions[factor_position_ix];
guint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= Length_of_RULE(rule)-1;
real_symbol_count= piece_end-piece_start+1;

/*:425*//*426:*/
#line 3177 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= RHS_ID_of_RULE(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3182 "./marpa.w"


/*:426*//*427:*/
#line 3186 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= RHS_ID_of_RULE(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*429:*/
#line 3202 "./marpa.w"

RULE_is_Used(chaf_rule)= 1;
chaf_rule->t_original= rule_id;
chaf_rule->t_is_virtual_lhs= piece_start> 0;
chaf_rule->t_is_semantic_equivalent= !chaf_rule->t_is_virtual_lhs;
chaf_rule->t_is_virtual_rhs= Length_of_RULE(chaf_rule)> real_symbol_count;
chaf_rule->t_virtual_start= piece_start;
chaf_rule->t_virtual_end= piece_start+real_symbol_count-1;
chaf_rule->t_real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->t_id);

/*:429*/
#line 3192 "./marpa.w"

}

/*:427*//*428:*/
#line 3196 "./marpa.w"
}

/*:428*/
#line 2927 "./marpa.w"

}}

/*:400*/
#line 2843 "./marpa.w"

NEXT_RULE:;
}
/*399:*/
#line 2907 "./marpa.w"

g_free(factor_positions);

/*:399*//*404:*/
#line 2957 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:404*/
#line 2846 "./marpa.w"

return g;
}
/*:391*//*430:*/
#line 3216 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
SYM alias= symbol_null_alias(SYM_by_ID(g,proper_id));
return ID_of_SYM(alias);
}
/*:430*//*433:*/
#line 3230 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
SYM proper_old_start= NULL;
SYM nulling_old_start= NULL;
SYM proper_new_start= NULL;
SYM old_start= SYM_by_ID(g,g->t_start_symid);
/*435:*/
#line 3246 "./marpa.w"

if(SYM_is_Nulling(old_start)){
old_start->t_is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->t_is_start= 0;

/*:435*/
#line 3238 "./marpa.w"

if(proper_old_start){/*436:*/
#line 3256 "./marpa.w"
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
new_start_rule->t_is_virtual_lhs= 1;
new_start_rule->t_real_symbol_count= 1;
RULE_is_Used(new_start_rule)= 1;
g->t_proper_start_rule= new_start_rule;
rule_callback(g,new_start_rule->t_id);
}

/*:436*/
#line 3239 "./marpa.w"
}
if(nulling_old_start){/*437:*/
#line 3281 "./marpa.w"
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
new_start_rule->t_is_virtual_lhs= 1;
new_start_rule->t_real_symbol_count= 1;
RULE_is_Used(new_start_rule)= TRUE;
g->t_null_start_rule= new_start_rule;
rule_callback(g,new_start_rule->t_id);
}

/*:437*/
#line 3240 "./marpa.w"
}
return g;
}
/*:433*//*441:*/
#line 3359 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{guint no_of_rules= RULE_Count_of_G(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*443:*/
#line 3382 "./marpa.w"
{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
Marpa_Symbol_ID proper_id;
guint rhs_ix,rule_length;
if(!RULE_is_Used(rule))continue;
rule_length= Length_of_RULE(rule);
proper_id= -1;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
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

/*:443*/
#line 3366 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*444:*/
#line 3421 "./marpa.w"
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

/*:444*/
#line 3368 "./marpa.w"

if(loop_rule_count)g->t_has_loop= TRUE;
/*445:*/
#line 3442 "./marpa.w"

g_context_clear(g);
g_context_int_add(g,"loop_rule_count",loop_rule_count);
grammar_message(g,"loop rule tally");

/*:445*/
#line 3370 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:441*//*460:*/
#line 3601 "./marpa.w"

static inline gboolean item_is_valid(
GRAMMAR_Const g,AIMID item_id){
return item_id<(AIMID)AIM_Count_of_G(g)&&item_id>=0;
}
/*:460*//*466:*/
#line 3642 "./marpa.w"

guint marpa_AHFA_item_count(struct marpa_g*g){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 3644 "./marpa.w"

/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 3645 "./marpa.w"

return AIM_Count_of_G(g);
}
/*:466*//*468:*/
#line 3651 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_item_rule(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 3654 "./marpa.w"

/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 3655 "./marpa.w"

/*1252:*/
#line 11734 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1252*/
#line 3656 "./marpa.w"

return RULE_of_AIM(AIM_by_ID(g,item_id))->t_id;
}
/*:468*//*471:*/
#line 3665 "./marpa.w"

gint marpa_AHFA_item_position(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 3668 "./marpa.w"

/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 3669 "./marpa.w"

/*1252:*/
#line 11734 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1252*/
#line 3670 "./marpa.w"

return Position_of_AIM(AIM_by_ID(g,item_id));
}

/*:471*//*473:*/
#line 3677 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_item_postdot(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 3680 "./marpa.w"

/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 3681 "./marpa.w"

/*1252:*/
#line 11734 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1252*/
#line 3682 "./marpa.w"

return Postdot_SYMID_of_AIM(AIM_by_ID(g,item_id));
}

/*:473*//*475:*/
#line 3688 "./marpa.w"

gint marpa_AHFA_item_sort_key(struct marpa_g*g,
Marpa_AHFA_Item_ID item_id){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 3691 "./marpa.w"

/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 3692 "./marpa.w"

/*1252:*/
#line 11734 "./marpa.w"

if(!item_is_valid(g,item_id)){
g_context_clear(g);
g_context_int_add(g,"item_id",item_id);
g->t_error= "invalid item id";
return failure_indicator;
}
/*:1252*/
#line 3693 "./marpa.w"

return Sort_Key_of_AIM(AIM_by_ID(g,item_id));
}

/*:475*//*477:*/
#line 3704 "./marpa.w"

static inline
void create_AHFA_items(GRAMMAR g){
RULEID rule_id;
guint no_of_items;
guint no_of_rules= RULE_Count_of_G(g);
AIM base_item= g_new(struct s_AHFA_item,Size_of_G(g));
AIM current_item= base_item;
guint symbol_instance_count= 0;
for(rule_id= 0;rule_id<(Marpa_Rule_ID)no_of_rules;rule_id++){
RULE rule= RULE_by_ID(g,rule_id);
if(RULE_is_Used(rule)){
/*479:*/
#line 3730 "./marpa.w"

{
guint leading_nulls= 0;
guint rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_RULE(rule);rhs_ix++)
{
SYMID rh_symid= RHS_ID_of_RULE(rule,rhs_ix);
SYM symbol= SYM_by_ID(g,rh_symid);
if(!symbol->t_is_nullable)
{
/*480:*/
#line 3753 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= rh_symid;
Position_of_AIM(current_item)= rhs_ix;
}

/*:480*/
#line 3740 "./marpa.w"

leading_nulls= 0;
current_item++;
}
else
{
leading_nulls++;
}
}
/*481:*/
#line 3762 "./marpa.w"

{
RULE_of_AIM(current_item)= rule;
Sort_Key_of_AIM(current_item)= current_item-base_item;
Null_Count_of_AIM(current_item)= leading_nulls;
Postdot_SYMID_of_AIM(current_item)= -1;
Position_of_AIM(current_item)= -1;
}

/*:481*/
#line 3749 "./marpa.w"

current_item++;
}

/*:479*/
#line 3716 "./marpa.w"

SYMI_of_RULE(rule)= symbol_instance_count;
symbol_instance_count+= Length_of_RULE(rule);
}
}
SYMI_Count_of_G(g)= symbol_instance_count;
no_of_items= LV_AIM_Count_of_G(g)= current_item-base_item;
g->t_AHFA_items= g_renew(struct s_AHFA_item,base_item,no_of_items);
/*482:*/
#line 3776 "./marpa.w"
{
AIM*items_by_rule= g_new0(AIM,no_of_rules);

AIM items= g->t_AHFA_items;
Marpa_Rule_ID highest_found_rule_id= -1;

Marpa_AHFA_Item_ID item_id;
for(item_id= 0;item_id<(Marpa_AHFA_Item_ID)no_of_items;item_id++){
AIM item= items+item_id;
Marpa_Rule_ID rule_id_for_item= RULE_of_AIM(item)->t_id;
if(rule_id_for_item<=highest_found_rule_id)continue;
items_by_rule[rule_id_for_item]= item;
highest_found_rule_id= rule_id_for_item;
}
g->t_AHFA_items_by_rule= items_by_rule;
}

/*:482*/
#line 3724 "./marpa.w"

/*489:*/
#line 3844 "./marpa.w"

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

/*:489*/
#line 3725 "./marpa.w"

}
/*:477*//*485:*/
#line 3803 "./marpa.w"

static gint cmp_by_aimid(gconstpointer ap,
gconstpointer bp,
gpointer user_data G_GNUC_UNUSED){
AIM a= *(AIM*)ap;
AIM b= *(AIM*)bp;
return a-b;
}

/*:485*//*488:*/
#line 3821 "./marpa.w"

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

/*:488*//*507:*/
#line 4009 "./marpa.w"

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

/*:507*//*517:*/
#line 4080 "./marpa.w"

static inline gint AHFA_state_id_is_valid(
const struct marpa_g*g,AHFAID AHFA_state_id){
return AHFA_state_id<AHFA_Count_of_G(g)&&AHFA_state_id>=0;
}
/*:517*//*521:*/
#line 4099 "./marpa.w"

guint marpa_AHFA_state_count(struct marpa_g*g){
return AHFA_Count_of_G(g);
}
/*:521*//*523:*/
#line 4106 "./marpa.w"

gint
marpa_AHFA_state_item_count(struct marpa_g*g,AHFAID AHFA_state_id)
{/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 4109 "./marpa.w"

AHFA state;
/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 4111 "./marpa.w"

/*1253:*/
#line 11741 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1253*/
#line 4112 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return state->t_item_count;
}
/*:523*//*526:*/
#line 4125 "./marpa.w"

Marpa_AHFA_Item_ID marpa_AHFA_state_item(struct marpa_g*g,
AHFAID AHFA_state_id,
guint item_ix){
AHFA state;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 4130 "./marpa.w"

/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 4131 "./marpa.w"

/*1253:*/
#line 11741 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1253*/
#line 4132 "./marpa.w"

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

/*:526*//*527:*/
#line 4144 "./marpa.w"

gint marpa_AHFA_state_is_predict(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 4148 "./marpa.w"

/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 4149 "./marpa.w"

/*1253:*/
#line 11741 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1253*/
#line 4150 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return AHFA_is_Predicted(state);
}
/*:527*//*532:*/
#line 4189 "./marpa.w"

Marpa_Rule_ID marpa_AHFA_completed_start_rule(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
const gint no_completed_start_rule= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 4193 "./marpa.w"

AHFA state;
/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 4195 "./marpa.w"

/*1253:*/
#line 11741 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1253*/
#line 4196 "./marpa.w"

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
/*1255:*/
#line 11755 "./marpa.w"
{
g_context_clear(g);
g->t_error= "internal error";
return failure_indicator;
}

/*:1255*/
#line 4212 "./marpa.w"

}
return no_completed_start_rule;
}

/*:532*//*536:*/
#line 4231 "./marpa.w"

Marpa_Symbol_ID marpa_AHFA_state_leo_lhs_symbol(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 4234 "./marpa.w"

AHFA state;
/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 4236 "./marpa.w"

/*1253:*/
#line 11741 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1253*/
#line 4237 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
return Leo_LHS_ID_of_AHFA(state);
}

/*:536*//*539:*/
#line 4260 "./marpa.w"

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

/*:539*//*542:*/
#line 4286 "./marpa.w"

PRIVATE_NOT_INLINE
void create_AHFA_states(struct marpa_g*g){
/*543:*/
#line 4305 "./marpa.w"

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

/*:543*/
#line 4289 "./marpa.w"

/*544:*/
#line 4320 "./marpa.w"

/*545:*/
#line 4324 "./marpa.w"

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

/*:545*/
#line 4321 "./marpa.w"

DQUEUE_INIT(states,AHFA_Object,initial_no_of_states);

/*:544*/
#line 4290 "./marpa.w"

/*567:*/
#line 4864 "./marpa.w"
{
Bit_Matrix symbol_by_symbol_matrix= 
matrix_create(symbol_count_of_g,symbol_count_of_g);
/*568:*/
#line 4873 "./marpa.w"

{
RULEID rule_id;
SYMID symid;
AIM*items_by_rule= g->t_AHFA_items_by_rule;
for(symid= 0;symid<(SYMID)symbol_count_of_g;symid++)
{

SYM symbol= SYM_by_ID(g,symid);
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

/*:568*/
#line 4867 "./marpa.w"

transitive_closure(symbol_by_symbol_matrix);
/*569:*/
#line 4910 "./marpa.w"
{
AIM*items_by_rule= g->t_AHFA_items_by_rule;
SYMID from_symid;
guint*sort_key_by_rule_id= g_new(guint,rule_count_of_g);
guint no_of_predictable_rules= 0;
/*570:*/
#line 4940 "./marpa.w"

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

/*:570*/
#line 4916 "./marpa.w"

/*571:*/
#line 4960 "./marpa.w"

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

/*:571*/
#line 4917 "./marpa.w"

/*574:*/
#line 4992 "./marpa.w"

{
guint sort_key;
for(sort_key= 0;sort_key<rule_count_of_g;sort_key++)
{
RULE rule= rule_by_sort_key[sort_key];
sort_key_by_rule_id[rule->t_id]= sort_key;
}
}

/*:574*/
#line 4918 "./marpa.w"

/*575:*/
#line 5002 "./marpa.w"

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

/*:575*/
#line 4919 "./marpa.w"

g_free(sort_key_by_rule_id);
}

/*:569*/
#line 4869 "./marpa.w"

matrix_free(symbol_by_symbol_matrix);
}

/*:567*/
#line 4291 "./marpa.w"

/*552:*/
#line 4458 "./marpa.w"
{
AHFA p_initial_state= DQUEUE_PUSH(states,AHFA_Object);
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

/*:552*/
#line 4292 "./marpa.w"

while((p_working_state= DQUEUE_NEXT(states,AHFA_Object))){
/*546:*/
#line 4337 "./marpa.w"
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
/*554:*/
#line 4559 "./marpa.w"
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
/*556:*/
#line 4649 "./marpa.w"
{
AIM previous_ahfa_item= single_item_p-1;
SYMID predot_symid= Postdot_SYMID_of_AIM(previous_ahfa_item);
if(SYMBOL_LHS_RULE_COUNT(SYM_by_ID(g,predot_symid))
> 0)
{
LV_Leo_LHS_ID_of_AHFA(p_new_state)= lhs_id;
}
}

/*:556*/
#line 4617 "./marpa.w"

}
}

/*:554*/
#line 4357 "./marpa.w"

}else{
/*557:*/
#line 4674 "./marpa.w"
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
/*558:*/
#line 4725 "./marpa.w"

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

/*:558*/
#line 4719 "./marpa.w"

transition_add(&ahfa_work_obs,p_working_state,working_symbol,p_new_state);
/*562:*/
#line 4808 "./marpa.w"
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

/*:562*/
#line 4722 "./marpa.w"

}

/*:557*/
#line 4359 "./marpa.w"

}
NEXT_WORKING_SYMBOL:;
if(current_item_ix>=no_of_items)break;
working_symbol= Postdot_SYMID_of_AIM(item_list[current_item_ix]);
if(working_symbol<0)break;
}
NEXT_AHFA_STATE:;
}

/*:546*/
#line 4294 "./marpa.w"

}
ahfas_of_g= g->t_AHFA= DQUEUE_BASE(states,AHFA_Object);

ahfa_count_of_g= AHFA_Count_of_G(g)= DQUEUE_END(states);
/*547:*/
#line 4369 "./marpa.w"

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

/*:547*/
#line 4299 "./marpa.w"

/*549:*/
#line 4421 "./marpa.w"

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

/*:549*/
#line 4300 "./marpa.w"

/*548:*/
#line 4392 "./marpa.w"

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
MARPA_DEBUG4("Added completion aex at %d for ahfa_id=%d sym=%d",
aex_ix,ahfa_id,completed_symbol_id);
aexes[aex_ix]= aex;
}
}
}
}
}

/*:548*/
#line 4301 "./marpa.w"

/*550:*/
#line 4448 "./marpa.w"

g_free(rule_by_sort_key);
matrix_free(prediction_matrix);
/*551:*/
#line 4454 "./marpa.w"

g_free(singleton_duplicates);
g_tree_destroy(duplicates);

/*:551*/
#line 4451 "./marpa.w"

obstack_free(&ahfa_work_obs,NULL);

/*:550*/
#line 4302 "./marpa.w"

}

/*:542*//*561:*/
#line 4797 "./marpa.w"

static inline AHFA
assign_AHFA_state(AHFA sought_state,GTree*duplicates)
{
const AHFA state_found= g_tree_lookup(duplicates,sought_state);
if(state_found)return state_found;
g_tree_insert(duplicates,sought_state,sought_state);
return NULL;
}

/*:561*//*572:*/
#line 4972 "./marpa.w"
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
/*:572*//*577:*/
#line 5051 "./marpa.w"

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
/*578:*/
#line 5106 "./marpa.w"

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

/*:578*/
#line 5102 "./marpa.w"

return p_new_state;
}

/*:577*//*590:*/
#line 5218 "./marpa.w"

static inline AHFA to_ahfa_of_transition_get(TRANS transition){
if(!transition)return NULL;
return transition->t_ur.t_to_ahfa;
}
/*:590*//*592:*/
#line 5225 "./marpa.w"

static inline gint completion_count_of_transition_get(TRANS transition){
if(!transition)return 0;
return transition->t_ur.t_completion_count;
}

/*:592*//*594:*/
#line 5234 "./marpa.w"

static inline
URTRANS transition_new(struct obstack*obstack,AHFA to_ahfa,gint aim_ix){
URTRANS transition;
transition= obstack_alloc(obstack,sizeof(transition[0]));
transition->t_to_ahfa= to_ahfa;
transition->t_completion_count= aim_ix;
return transition;
}

/*:594*//*596:*/
#line 5246 "./marpa.w"
static inline
TRANS*transitions_new(struct marpa_g*g){
gint symbol_count= SYM_Count_of_G(g);
gint symid= 0;
TRANS*transitions;
transitions= g_malloc(symbol_count*sizeof(transitions[0]));
while(symid<symbol_count)transitions[symid++]= NULL;


return transitions;
}

/*:596*//*598:*/
#line 5261 "./marpa.w"

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

/*:598*//*600:*/
#line 5278 "./marpa.w"

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

/*:600*//*602:*/
#line 5297 "./marpa.w"

gint marpa_AHFA_state_transitions(struct marpa_g*g,
Marpa_AHFA_State_ID AHFA_state_id,
GArray*result){

/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 5302 "./marpa.w"

AHFA from_ahfa_state;
TRANS*transitions;
SYMID symid;
gint symbol_count;

/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 5308 "./marpa.w"

/*1253:*/
#line 11741 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1253*/
#line 5309 "./marpa.w"

/*1254:*/
#line 11748 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
g_context_clear(g);
g_context_int_add(g,"expected size",sizeof(gint));
g->t_error= "garray size mismatch";
return failure_indicator;
}
/*:1254*/
#line 5310 "./marpa.w"

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

/*:602*//*606:*/
#line 5333 "./marpa.w"

AHFAID marpa_AHFA_state_empty_transition(struct marpa_g*g,
AHFAID AHFA_state_id){
AHFA state;
AHFA empty_transition_state;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 5338 "./marpa.w"

/*1249:*/
#line 11714 "./marpa.w"

if(!G_is_Precomputed(g)){
g_context_clear(g);
g->t_error= "grammar not precomputed";
return failure_indicator;
}
/*:1249*/
#line 5339 "./marpa.w"

/*1253:*/
#line 11741 "./marpa.w"

if(!AHFA_state_id_is_valid(g,AHFA_state_id)){
g_context_clear(g);
g_context_int_add(g,"AHFA_state_id",AHFA_state_id);
g->t_error= "invalid AHFA state id";
return failure_indicator;
}
/*:1253*/
#line 5340 "./marpa.w"

state= AHFA_of_G_by_ID(g,AHFA_state_id);
empty_transition_state= Empty_Transition_of_AHFA(state);
if(empty_transition_state)
return ID_of_AHFA(empty_transition_state);
return-1;
}


/*:606*//*612:*/
#line 5381 "./marpa.w"

struct marpa_r*marpa_r_new(const struct marpa_g*const g)
{RECCE r;
/*1246:*/
#line 11700 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1246*/
#line 5384 "./marpa.w"

r= g_slice_new(struct marpa_r);
r->t_grammar= g;
/*701:*/
#line 5868 "./marpa.w"
obstack_init(&r->t_obs);
/*:701*/
#line 5387 "./marpa.w"

/*619:*/
#line 5423 "./marpa.w"

r->t_id= g_atomic_int_exchange_and_add(&next_recce_id,1);
/*:619*//*626:*/
#line 5459 "./marpa.w"

Phase_of_R(r)= initial_phase;
/*:626*//*630:*/
#line 5474 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;
/*:630*//*638:*/
#line 5509 "./marpa.w"

r->t_earley_item_warning_threshold= MAX(DEFAULT_EIM_WARNING_THRESHOLD,AIM_Count_of_G(g)*2);
/*:638*//*644:*/
#line 5537 "./marpa.w"
r->t_furthest_earleme= 0;
/*:644*//*649:*/
#line 5556 "./marpa.w"
r->t_sym_workarea= NULL;
/*:649*//*653:*/
#line 5571 "./marpa.w"
r->t_workarea2= NULL;
/*:653*//*657:*/
#line 5595 "./marpa.w"

r->t_bv_sym= NULL;
r->t_bv_sym2= NULL;
r->t_bv_sym3= NULL;
/*:657*//*661:*/
#line 5618 "./marpa.w"
r->t_bv_symid_is_expected= NULL;
/*:661*//*668:*/
#line 5670 "./marpa.w"

r->t_earley_item_tree= g_tree_new(trace_earley_item_cmp);

/*:668*//*678:*/
#line 5733 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:678*//*684:*/
#line 5774 "./marpa.w"
r->t_is_exhausted= 0;
/*:684*//*688:*/
#line 5798 "./marpa.w"

r->t_is_leo_expanding= 0;

/*:688*//*690:*/
#line 5813 "./marpa.w"

r->t_context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:690*//*705:*/
#line 5884 "./marpa.w"

r->t_error= NULL;
r->t_fatal_error= NULL;
/*:705*//*722:*/
#line 5975 "./marpa.w"

r->t_earley_set_count= 0;

/*:722*//*728:*/
#line 6024 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:728*//*763:*/
#line 6375 "./marpa.w"

r->t_trace_earley_item= NULL;
/*:763*//*804:*/
#line 6838 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;
/*:804*//*847:*/
#line 7333 "./marpa.w"

r->t_trace_source= NULL;
r->t_trace_next_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:847*//*887:*/
#line 7782 "./marpa.w"

DSTACK_INIT(r->t_alternatives,ALT_Object,INITIAL_ALTERNATIVES_CAPACITY);
/*:887*//*915:*/
#line 8086 "./marpa.w"
DSTACK_ZERO_INIT(r->t_eim_work_stack);
/*:915*//*919:*/
#line 8098 "./marpa.w"
DSTACK_ZERO_INIT(r->t_completion_stack);
/*:919*//*923:*/
#line 8110 "./marpa.w"
DSTACK_ZERO_INIT(r->t_earley_set_stack);
/*:923*//*1002:*/
#line 9084 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:1002*//*1089:*/
#line 10277 "./marpa.w"

B_of_R(r)= NULL;

/*:1089*//*1214:*/
#line 11421 "./marpa.w"

psar_init(Dot_PSAR_of_R(r),AHFA_Count_of_R(r));
/*:1214*//*1283:*/
#line 11971 "./marpa.w"

r->t_message_callback_arg= NULL;
r->t_message_callback= NULL;
/*:1283*/
#line 5388 "./marpa.w"

MARPA_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
if(!G_is_Precomputed(g)){
R_ERROR("grammar not precomputed");
return failure_indicator;
}
return r;}

/*:612*//*613:*/
#line 5396 "./marpa.w"

void marpa_r_free(struct marpa_r*r)
{
/*631:*/
#line 5478 "./marpa.w"

{
if(r->t_earley_item_tree)
g_tree_destroy(r->t_earley_item_tree);
}

/*:631*//*691:*/
#line 5815 "./marpa.w"
g_hash_table_destroy(Context_of_R(r));

/*:691*//*725:*/
#line 6001 "./marpa.w"

{
ES set;
for(set= First_ES_of_R(r);set;set= Next_ES_of_ES(set))
{
if(EIMs_of_ES(set))
g_free(EIMs_of_ES(set));
}
}

/*:725*//*888:*/
#line 7784 "./marpa.w"
DSTACK_DESTROY(r->t_alternatives);

/*:888*//*917:*/
#line 8091 "./marpa.w"
DSTACK_DESTROY(r->t_eim_work_stack);

/*:917*//*921:*/
#line 8103 "./marpa.w"
DSTACK_DESTROY(r->t_completion_stack);

/*:921*//*924:*/
#line 8111 "./marpa.w"
DSTACK_DESTROY(r->t_earley_set_stack);

/*:924*//*1003:*/
#line 9086 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:1003*//*1106:*/
#line 10491 "./marpa.w"
/*1110:*/
#line 10515 "./marpa.w"
{
BOC b= B_of_R(r);
MARPA_OFF_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
if(b){
/*1105:*/
#line 10486 "./marpa.w"

/*1043:*/
#line 9608 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
if(or_nodes)
{
g_free(or_nodes);
ORs_of_B(b)= NULL;
}
}

/*:1043*/
#line 10487 "./marpa.w"
;
/*1092:*/
#line 10287 "./marpa.w"

obstack_free(&OBS_of_B(b),NULL);

/*:1092*/
#line 10488 "./marpa.w"
;

/*:1105*/
#line 10519 "./marpa.w"
;
g_slice_free(BOC_Object,b);
B_of_R(r)= NULL;
}
MARPA_OFF_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
}

/*:1110*/
#line 10491 "./marpa.w"


/*:1106*//*1215:*/
#line 11423 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1215*/
#line 5399 "./marpa.w"

if(r->t_sym_workarea)g_free(r->t_sym_workarea);
if(r->t_workarea2)g_free(r->t_workarea2);
/*659:*/
#line 5604 "./marpa.w"

if(r->t_bv_sym)bv_free(r->t_bv_sym);
if(r->t_bv_sym2)bv_free(r->t_bv_sym2);
if(r->t_bv_sym3)bv_free(r->t_bv_sym3);

/*:659*//*663:*/
#line 5621 "./marpa.w"

if(r->t_bv_symid_is_expected){bv_free(r->t_bv_symid_is_expected);}
/*:663*/
#line 5402 "./marpa.w"

/*702:*/
#line 5869 "./marpa.w"
obstack_free(&r->t_obs,NULL);

/*:702*/
#line 5403 "./marpa.w"

g_slice_free(struct marpa_r,r);
}
/*:613*//*620:*/
#line 5425 "./marpa.w"

gint marpa_r_id(struct marpa_r*r){return r->t_id;}
/*:620*//*628:*/
#line 5463 "./marpa.w"

Marpa_Phase marpa_phase(struct marpa_r*r)
{return Phase_of_R(r);}

/*:628*//*634:*/
#line 5491 "./marpa.w"

guint marpa_current_earleme(struct marpa_r*r)
{return Current_Earleme_of_R(r);}

/*:634*//*636:*/
#line 5498 "./marpa.w"

static inline ES current_es_of_r(RECCE r)
{
const ES latest= Latest_ES_of_R(r);
if(Earleme_of_ES(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:636*//*640:*/
#line 5513 "./marpa.w"

guint marpa_earley_item_warning_threshold(struct marpa_r*r)
{return r->t_earley_item_warning_threshold;}

/*:640*//*642:*/
#line 5521 "./marpa.w"

gboolean marpa_earley_item_warning_threshold_set(struct marpa_r*r,guint threshold)
{
r->t_earley_item_warning_threshold= threshold==0?EIM_FATAL_THRESHOLD:threshold;
return TRUE;
}

/*:642*//*646:*/
#line 5540 "./marpa.w"

guint marpa_furthest_earleme(struct marpa_r*r)
{return Furthest_Earleme_of_R(r);}

/*:646*//*665:*/
#line 5633 "./marpa.w"

gint marpa_terminals_expected(struct marpa_r*r,GArray*result)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 5636 "./marpa.w"

guint min,max,start;
/*1263:*/
#line 11805 "./marpa.w"

if(sizeof(gint)!=g_array_get_element_size(result)){
r_context_clear(r);
r_context_int_add(r,"expected size",sizeof(gint));
R_ERROR_CXT("garray size mismatch");
return failure_indicator;
}
/*:1263*/
#line 5638 "./marpa.w"

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

/*:665*//*680:*/
#line 5741 "./marpa.w"

gint marpa_is_use_leo(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 5744 "./marpa.w"

/*1261:*/
#line 11793 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1261*/
#line 5745 "./marpa.w"

return r->t_use_leo_flag?1:0;
}
/*:680*//*681:*/
#line 5750 "./marpa.w"

gboolean marpa_is_use_leo_set(
struct marpa_r*r,gboolean value)
{
/*1245:*/
#line 11698 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1245*/
#line 5754 "./marpa.w"

/*1261:*/
#line 11793 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1261*/
#line 5755 "./marpa.w"

r->t_use_leo_flag= value;
return TRUE;
}
/*:681*//*686:*/
#line 5780 "./marpa.w"

gint marpa_is_exhausted(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 5783 "./marpa.w"

/*1261:*/
#line 11793 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1261*/
#line 5784 "./marpa.w"

return r->t_is_exhausted?1:0;
}

/*:686*//*692:*/
#line 5824 "./marpa.w"

static inline
void r_context_int_add(struct marpa_r*r,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->t_type= MARPA_CONTEXT_INT;
value->t_data= payload;
g_hash_table_insert(Context_of_R(r),(gpointer)key,value);
}
/*:692*//*694:*/
#line 5836 "./marpa.w"

static inline
void r_context_const_add(struct marpa_r*r,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->t_type= MARPA_CONTEXT_CONST;
value->t_data= payload;
g_hash_table_insert(Context_of_R(r),(gpointer)key,value);
}
/*:694*//*696:*/
#line 5851 "./marpa.w"

static inline void r_context_clear(struct marpa_r*r){
g_hash_table_remove_all(Context_of_R(r));}
/*:696*//*698:*/
#line 5857 "./marpa.w"

union marpa_context_value*marpa_r_context_value(struct marpa_r*r,const gchar*key)
{return g_hash_table_lookup(Context_of_R(r),key);}
/*:698*//*707:*/
#line 5893 "./marpa.w"

Marpa_Error_ID marpa_r_error(const struct marpa_r*r)
{return r->t_error?r->t_error:"unknown error";}
/*:707*//*724:*/
#line 5981 "./marpa.w"

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
/*1221:*/
#line 11471 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1221*/
#line 5996 "./marpa.w"

return set;
}

/*:724*//*730:*/
#line 6029 "./marpa.w"

Marpa_Earley_Set_ID marpa_trace_earley_set(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6032 "./marpa.w"

ES trace_earley_set= r->t_trace_earley_set;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6034 "./marpa.w"

if(!trace_earley_set){
R_ERROR("no trace es");
return failure_indicator;
}
return Ord_of_ES(trace_earley_set);
}

/*:730*//*732:*/
#line 6044 "./marpa.w"

Marpa_Earley_Set_ID marpa_latest_earley_set(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6047 "./marpa.w"

/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6048 "./marpa.w"

return Ord_of_ES(Latest_ES_of_R(r));
}

/*:732*//*734:*/
#line 6062 "./marpa.w"

Marpa_Earleme marpa_earleme(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
const gint es_does_not_exist= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6066 "./marpa.w"

ES earley_set;
/*1257:*/
#line 11769 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1257*/
#line 6068 "./marpa.w"

/*1261:*/
#line 11793 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1261*/
#line 6069 "./marpa.w"

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

/*:734*//*737:*/
#line 6087 "./marpa.w"

gint marpa_earley_set_size(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6090 "./marpa.w"

ES earley_set;
/*1257:*/
#line 11769 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1257*/
#line 6092 "./marpa.w"

/*1261:*/
#line 11793 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1261*/
#line 6093 "./marpa.w"

r_update_earley_sets(r);
if(!ES_Ord_is_Valid(r,set_id))
{
R_ERROR("invalid es ordinal");
return failure_indicator;
}
earley_set= ES_of_R_by_Ord(r,set_id);
return EIM_Count_of_ES(earley_set);
}

/*:737*//*747:*/
#line 6192 "./marpa.w"

static inline EIM earley_item_create(const RECCE r,
const EIK_Object key)
{
/*1246:*/
#line 11700 "./marpa.w"
const gpointer failure_indicator= NULL;
/*:1246*/
#line 6196 "./marpa.w"

EIM new_item;
EIM*top_of_work_stack;
const ES set= key.t_set;
const guint count= ++EIM_Count_of_ES(set);
/*752:*/
#line 6267 "./marpa.w"

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

/*:752*/
#line 6201 "./marpa.w"

new_item= obstack_alloc(&r->t_obs,sizeof(*new_item));
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
Ord_of_EIM(new_item)= count-1;
EIM_is_Leo_Expansion(new_item)= 0;
LV_EIM_is_Leo_Expanded(new_item)= 1;

top_of_work_stack= WORK_EIM_PUSH(r);
*top_of_work_stack= new_item;
g_tree_insert(r->t_earley_item_tree,new_item,new_item);
return new_item;
}

/*:747*//*749:*/
#line 6218 "./marpa.w"

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

/*:749*//*751:*/
#line 6235 "./marpa.w"

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

/*:751*//*755:*/
#line 6293 "./marpa.w"

static inline gint trace_earley_item_cmp(gconstpointer ap,gconstpointer bp)
{
const EIM_Object*eim_a= ap;
const EIM_Object*eim_b= bp;
gint subkey= Earleme_of_EIM(eim_a)-Earleme_of_EIM(eim_b);
if(subkey)return subkey;
return earley_item_cmp(ap,bp,0);
}
/*:755*//*757:*/
#line 6306 "./marpa.w"

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

/*:757*//*761:*/
#line 6351 "./marpa.w"

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

/*:761*//*767:*/
#line 6400 "./marpa.w"

Marpa_AHFA_State_ID
marpa_old_earley_item_trace(struct marpa_r*r,
Marpa_Earley_Set_ID origin_set_id,
Marpa_AHFA_State_ID state_id)
{
const gint no_match= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6407 "./marpa.w"

ES current_set= r->t_trace_earley_set;
ES origin_set;
EIM item;
EIK_Object item_key;
GRAMMAR_Const g= G_of_R(r);
/*1257:*/
#line 11769 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1257*/
#line 6413 "./marpa.w"

trace_source_link_clear(r);
if(!current_set){
/*775:*/
#line 6550 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:775*/
#line 6416 "./marpa.w"

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
/*775:*/
#line 6550 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:775*/
#line 6431 "./marpa.w"

R_ERROR("origin es not found");
return failure_indicator;
}
item_key.t_state= AHFA_of_G_by_ID(g,state_id);
item_key.t_origin= origin_set;
item_key.t_set= current_set;
item= r->t_trace_earley_item= g_tree_lookup(r->t_earley_item_tree,&item_key);
if(!item){
/*775:*/
#line 6550 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:775*/
#line 6440 "./marpa.w"

return no_match;
}
return AHFAID_of_EIM(item);
}

/*:767*//*771:*/
#line 6471 "./marpa.w"

Marpa_Earleme
marpa_earley_set_trace(struct marpa_r*r,Marpa_Earley_Set_ID set_id)
{
ES earley_set;
const gint es_does_not_exist= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6477 "./marpa.w"

/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6478 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_ES(r->t_trace_earley_set)==set_id)
{


return Earleme_of_ES(r->t_trace_earley_set);
}
/*772:*/
#line 6501 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*807:*/
#line 6880 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:807*/
#line 6504 "./marpa.w"

}

/*:772*/
#line 6485 "./marpa.w"

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

/*:771*//*774:*/
#line 6511 "./marpa.w"

Marpa_AHFA_State_ID
marpa_earley_item_trace(struct marpa_r*r,Marpa_Earley_Item_ID item_id)
{
const gint eim_does_not_exist= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6516 "./marpa.w"

ES trace_earley_set;
EIM earley_item;
EIM*earley_items;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6520 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*772:*/
#line 6501 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*807:*/
#line 6880 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:807*/
#line 6504 "./marpa.w"

}

/*:772*/
#line 6524 "./marpa.w"

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

/*:774*//*777:*/
#line 6555 "./marpa.w"

static inline void trace_earley_item_clear(struct marpa_r*r)
{
/*775:*/
#line 6550 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:775*/
#line 6558 "./marpa.w"

trace_source_link_clear(r);
}

/*:777*//*779:*/
#line 6564 "./marpa.w"

Marpa_Earley_Set_ID marpa_earley_item_origin(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6567 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1257:*/
#line 11769 "./marpa.w"

if(Phase_of_R(r)==initial_phase){
R_ERROR("initial recce phase");
return failure_indicator;
}
/*:1257*/
#line 6569 "./marpa.w"

if(!item){
/*775:*/
#line 6550 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:775*/
#line 6571 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return Origin_Ord_of_EIM(item);
}

/*:779*//*787:*/
#line 6656 "./marpa.w"

Marpa_Symbol_ID marpa_leo_predecessor_symbol(struct marpa_r*r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6660 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6663 "./marpa.w"

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
/*:787*//*788:*/
#line 6678 "./marpa.w"

Marpa_Earley_Set_ID marpa_leo_base_origin(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6682 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6685 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_EIM(base_earley_item);
}

/*:788*//*790:*/
#line 6697 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_base_state(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6701 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
EIM base_earley_item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6704 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
if(EIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Base_EIM_of_LIM(LIM_of_PIM(postdot_item));
return AHFAID_of_EIM(base_earley_item);
}

/*:790*//*795:*/
#line 6740 "./marpa.w"

Marpa_AHFA_State_ID marpa_leo_expansion_ahfa(struct marpa_r*r)
{
const EARLEME pim_is_not_a_leo_item= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6744 "./marpa.w"

const PIM postdot_item= r->t_trace_postdot_item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6746 "./marpa.w"

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


/*:795*//*800:*/
#line 6800 "./marpa.w"

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
/*:800*//*802:*/
#line 6822 "./marpa.w"

static inline PIM first_pim_of_es_by_symid(ES set,SYMID symid)
{
PIM*pim_sym_p= pim_sym_p_find(set,symid);
return pim_sym_p?*pim_sym_p:NULL;
}

/*:802*//*806:*/
#line 6856 "./marpa.w"

Marpa_Symbol_ID
marpa_postdot_symbol_trace(struct marpa_r*r,
Marpa_Symbol_ID symid)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6861 "./marpa.w"

ES current_es= r->t_trace_earley_set;
PIM*pim_sym_p;
PIM pim;
/*807:*/
#line 6880 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:807*/
#line 6865 "./marpa.w"

/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6866 "./marpa.w"

/*1262:*/
#line 11798 "./marpa.w"

if(!symbol_is_valid(G_of_R(r),symid)){
r_context_clear(r);
r_context_int_add(r,"symid",symid);
R_ERROR_CXT("invalid symid");
return failure_indicator;
}
/*:1262*/
#line 6867 "./marpa.w"

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

/*:806*//*809:*/
#line 6893 "./marpa.w"

Marpa_Symbol_ID
marpa_first_postdot_item_trace(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6897 "./marpa.w"

ES current_earley_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;
/*807:*/
#line 6880 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:807*/
#line 6901 "./marpa.w"

/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6902 "./marpa.w"

if(!current_earley_set){
/*775:*/
#line 6550 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:775*/
#line 6904 "./marpa.w"

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

/*:809*//*811:*/
#line 6926 "./marpa.w"

Marpa_Symbol_ID
marpa_next_postdot_item_trace(struct marpa_r*r)
{
const SYMID no_more_postdot_symbols= -1;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6931 "./marpa.w"

ES current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_sym_p;

pim_sym_p= r->t_trace_pim_sym_p;
pim= r->t_trace_postdot_item;
/*807:*/
#line 6880 "./marpa.w"

r->t_trace_pim_sym_p= NULL;
r->t_trace_postdot_item= NULL;

/*:807*/
#line 6938 "./marpa.w"

if(!pim_sym_p||!pim){
R_ERROR("no trace pim");
return failure_indicator;
}
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6943 "./marpa.w"

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

/*:811*//*813:*/
#line 6965 "./marpa.w"

Marpa_AHFA_State_ID marpa_postdot_item_symbol(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 6968 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 6970 "./marpa.w"

if(!postdot_item){
R_ERROR("no trace pim");
return failure_indicator;
}
return Postdot_SYMID_of_PIM(postdot_item);
}


/*:813*//*829:*/
#line 7102 "./marpa.w"
static inline
void
token_link_add(struct marpa_r*r,
EIM item,
EIM predecessor,
SYMID token_id,
gpointer value)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
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
/*:829*//*836:*/
#line 7192 "./marpa.w"
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

/*:836*//*837:*/
#line 7221 "./marpa.w"
static inline
void
leo_link_add(struct marpa_r*r,
EIM item,
LIM predecessor,
EIM cause)
{
SRCL new_link;
guint previous_source_type= Source_Type_of_EIM(item);
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
/*:837*//*840:*/
#line 7276 "./marpa.w"
static
void earley_item_ambiguate(struct marpa_r*r,EIM item)
{
guint previous_source_type= Source_Type_of_EIM(item);
Source_Type_of_EIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*842:*/
#line 7294 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= new_link;
}

/*:842*/
#line 7283 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*843:*/
#line 7303 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= NULL;
LV_First_Completion_Link_of_EIM(item)= new_link;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:843*/
#line 7285 "./marpa.w"

return;
case SOURCE_IS_LEO:/*844:*/
#line 7312 "./marpa.w"
{
SRCL new_link= obstack_alloc(&r->t_obs,sizeof(*new_link));
new_link->t_next= NULL;
new_link->t_source= item->t_container.t_unique;
LV_First_Leo_SRCL_of_EIM(item)= new_link;
LV_First_Completion_Link_of_EIM(item)= NULL;
LV_First_Token_Link_of_EIM(item)= NULL;
}

/*:844*/
#line 7287 "./marpa.w"

return;
}
}
/*:840*//*850:*/
#line 7346 "./marpa.w"

Marpa_Symbol_ID marpa_first_token_link_trace(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7349 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7353 "./marpa.w"

/*869:*/
#line 7577 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:869*/
#line 7354 "./marpa.w"

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

/*:850*//*854:*/
#line 7391 "./marpa.w"

Marpa_Symbol_ID marpa_next_token_link_trace(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7394 "./marpa.w"

SRCL full_link;
EIM item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7397 "./marpa.w"

/*869:*/
#line 7577 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:869*/
#line 7398 "./marpa.w"

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

/*:854*//*857:*/
#line 7423 "./marpa.w"

Marpa_Symbol_ID marpa_first_completion_link_trace(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7426 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7430 "./marpa.w"

/*869:*/
#line 7577 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:869*/
#line 7431 "./marpa.w"

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

/*:857*//*861:*/
#line 7467 "./marpa.w"

Marpa_Symbol_ID marpa_next_completion_link_trace(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7470 "./marpa.w"

SRC source;
SRCL completion_link;
EIM item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7474 "./marpa.w"

/*869:*/
#line 7577 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:869*/
#line 7475 "./marpa.w"

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

/*:861*//*864:*/
#line 7501 "./marpa.w"

Marpa_Symbol_ID
marpa_first_leo_link_trace(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7505 "./marpa.w"

SRC source;
guint source_type;
EIM item= r->t_trace_earley_item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7509 "./marpa.w"

/*869:*/
#line 7577 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:869*/
#line 7510 "./marpa.w"

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

/*:864*//*868:*/
#line 7548 "./marpa.w"

Marpa_Symbol_ID
marpa_next_leo_link_trace(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7552 "./marpa.w"

SRCL full_link;
SRC source;
EIM item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7556 "./marpa.w"

/*869:*/
#line 7577 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
R_ERROR("no eim");
return failure_indicator;
}

/*:869*/
#line 7557 "./marpa.w"

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

/*:868*//*872:*/
#line 7588 "./marpa.w"

static inline void trace_source_link_clear(struct marpa_r*r){
r->t_trace_next_source_link= NULL;
r->t_trace_source= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:872*//*874:*/
#line 7605 "./marpa.w"

AHFAID marpa_source_predecessor_state(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7608 "./marpa.w"

guint source_type;
SRC source;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7611 "./marpa.w"

source_type= r->t_trace_source_type;
/*883:*/
#line 7747 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:883*/
#line 7613 "./marpa.w"

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

/*:874*//*877:*/
#line 7642 "./marpa.w"

Marpa_Symbol_ID marpa_source_leo_transition_symbol(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7645 "./marpa.w"

guint source_type;
SRC source;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7648 "./marpa.w"

source_type= r->t_trace_source_type;
/*883:*/
#line 7747 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:883*/
#line 7650 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_Symbol_ID_of_SRC(source);
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:877*//*880:*/
#line 7689 "./marpa.w"

Marpa_Earley_Set_ID marpa_source_middle(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7692 "./marpa.w"

const EARLEME no_predecessor= -1;
guint source_type;
SRC source;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7696 "./marpa.w"

source_type= r->t_trace_source_type;
/*883:*/
#line 7747 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:883*/
#line 7698 "./marpa.w"

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

/*:880*//*882:*/
#line 7730 "./marpa.w"

gboolean marpa_source_token_value(struct marpa_r*r,gpointer*value_p)
{
/*1245:*/
#line 11698 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1245*/
#line 7733 "./marpa.w"

guint source_type;
SRC source;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 7736 "./marpa.w"

source_type= r->t_trace_source_type;
/*883:*/
#line 7747 "./marpa.w"

source= r->t_trace_source;
if(!source){
R_ERROR("no trace source link");
return failure_indicator;
}

/*:883*/
#line 7738 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
*value_p= Token_Value_of_SRC(source);
return TRUE;
}
R_ERROR(invalid_source_type_message(source_type));
return failure_indicator;
}

/*:882*//*890:*/
#line 7792 "./marpa.w"

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

/*:890*//*892:*/
#line 7829 "./marpa.w"

static inline void alternative_set(
ALT alternative,ES start,EARLEME end,SYMID token_id,gpointer value)
{
alternative->t_token_id= token_id;
alternative->t_token_value= value;
alternative->t_start_earley_set= start;
alternative->t_end_earleme= end;
}

/*:892*//*894:*/
#line 7852 "./marpa.w"

static inline gint alternative_cmp(const ALT_Const a,const ALT_Const b){
gint subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= Token_ID_of_ALT(a)-Token_ID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:894*//*896:*/
#line 7870 "./marpa.w"

static inline ALT alternative_pop(RECCE r,EARLEME earleme)
{
DSTACK alternatives= &r->t_alternatives;
ALT top_of_stack= DSTACK_TOP(*alternatives,ALT_Object);
if(!top_of_stack)return NULL;
if(earleme!=End_Earleme_of_ALT(top_of_stack))return NULL;
return DSTACK_POP(*alternatives,ALT_Object);
}

/*:896*//*898:*/
#line 7887 "./marpa.w"

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

/*:898*//*901:*/
#line 7907 "./marpa.w"
gboolean marpa_start_input(struct marpa_r*r)
{
ES set0;
EIM item;
EIK_Object key;
AHFA state;
GRAMMAR_Const g= G_of_R(r);
const gint symbol_count_of_g= SYM_Count_of_G(g);
/*1245:*/
#line 11698 "./marpa.w"
const gboolean failure_indicator= FALSE;
/*:1245*/
#line 7915 "./marpa.w"

/*1256:*/
#line 11764 "./marpa.w"

if(Phase_of_R(r)!=initial_phase){
R_ERROR("not initial recce phase");
return failure_indicator;
}
/*:1256*/
#line 7916 "./marpa.w"

/*654:*/
#line 5572 "./marpa.w"

{
const guint sym_workarea_size= sizeof(gpointer)*symbol_count_of_g;
/*650:*/
#line 5557 "./marpa.w"

r->t_sym_workarea= g_malloc(sym_workarea_size);

/*:650*/
#line 5575 "./marpa.w"

r->t_workarea2= g_malloc(2u*sym_workarea_size);
}

/*:654*/
#line 7917 "./marpa.w"

psar_reset(Dot_PSAR_of_R(r));
/*658:*/
#line 5599 "./marpa.w"
{
r->t_bv_sym= bv_create((guint)symbol_count_of_g);
r->t_bv_sym2= bv_create((guint)symbol_count_of_g);
r->t_bv_sym3= bv_create((guint)symbol_count_of_g);
}
/*:658*//*662:*/
#line 5619 "./marpa.w"

r->t_bv_symid_is_expected= bv_create((guint)symbol_count_of_g);
/*:662*/
#line 7919 "./marpa.w"

/*916:*/
#line 8087 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_eim_work_stack)||
DSTACK_INIT(r->t_eim_work_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:916*//*920:*/
#line 8099 "./marpa.w"

DSTACK_IS_INITIALIZED(r->t_completion_stack)||
DSTACK_INIT(r->t_completion_stack,EIM,
MAX(1024,r->t_earley_item_warning_threshold));
/*:920*/
#line 7920 "./marpa.w"

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

/*:901*//*909:*/
#line 7992 "./marpa.w"

gboolean marpa_alternative(struct marpa_r*r,
Marpa_Symbol_ID token_id,void*token_value,gint length){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 7995 "./marpa.w"

const gint duplicate_token_indicator= -3;
const gint unexpected_token_indicator= -1;
ES current_earley_set;
const EARLEME current_earleme= Current_Earleme_of_R(r);
EARLEME target_earleme;
/*1259:*/
#line 11779 "./marpa.w"

if(Phase_of_R(r)!=input_phase){
R_ERROR("recce not in input phase");
return failure_indicator;
}
/*:1259*/
#line 8001 "./marpa.w"

/*1258:*/
#line 11774 "./marpa.w"

if(R_is_Exhausted(r)){
R_ERROR("recce exhausted");
return failure_indicator;
}
/*:1258*/
#line 8002 "./marpa.w"

/*910:*/
#line 8010 "./marpa.w"
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

/*:910*/
#line 8003 "./marpa.w"

/*912:*/
#line 8043 "./marpa.w"
{
current_earley_set= Current_ES_of_R(r);
if(!current_earley_set)return unexpected_token_indicator;
if(!First_PIM_of_ES_by_SYMID(current_earley_set,token_id))
return unexpected_token_indicator;
}

/*:912*/
#line 8004 "./marpa.w"

/*911:*/
#line 8026 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=EARLEME_THRESHOLD){
r_context_clear(r);
r_context_int_add(r,"target_earleme",target_earleme);
R_ERROR_CXT("parse too long");
return failure_indicator;
}
}

/*:911*/
#line 8005 "./marpa.w"

/*913:*/
#line 8066 "./marpa.w"

{
ALT_Object alternative;
if(Furthest_Earleme_of_R(r)<target_earleme)
LV_Furthest_Earleme_of_R(r)= target_earleme;
alternative_set(&alternative,
current_earley_set,target_earleme,token_id,token_value);
if(alternative_insert(r,&alternative)<0)
return duplicate_token_indicator;
}

/*:913*/
#line 8006 "./marpa.w"

return current_earleme;
}

/*:909*//*927:*/
#line 8132 "./marpa.w"

Marpa_Earleme
marpa_earleme_complete(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 8136 "./marpa.w"

EIM*cause_p;
ES current_earley_set;
EARLEME current_earleme;
gint count_of_expected_terminals;
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_symid_is_expected);
/*928:*/
#line 8166 "./marpa.w"
{
current_earleme= ++(LV_Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
LV_R_is_Exhausted(r)= 1;
R_ERROR("parse exhausted");
return failure_indicator;
}
}

/*:928*/
#line 8143 "./marpa.w"

/*930:*/
#line 8191 "./marpa.w"
{
ALT top_of_stack= DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!top_of_stack)return 0;
if(current_earleme!=End_Earleme_of_ALT(top_of_stack))return 0;
}

/*:930*/
#line 8144 "./marpa.w"

/*929:*/
#line 8178 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
LV_Next_ES_of_ES(Latest_ES_of_R(r))= current_earley_set;
LV_Latest_ES_of_R(r)= current_earley_set;
}

/*:929*/
#line 8145 "./marpa.w"

/*931:*/
#line 8197 "./marpa.w"

{
ALT alternative;
while((alternative= alternative_pop(r,current_earleme)))
/*932:*/
#line 8204 "./marpa.w"

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

/*:932*/
#line 8201 "./marpa.w"

}

/*:931*/
#line 8146 "./marpa.w"

/*933:*/
#line 8231 "./marpa.w"
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

/*:933*/
#line 8147 "./marpa.w"

while((cause_p= DSTACK_POP(r->t_completion_stack,EIM))){
EIM cause= *cause_p;
/*934:*/
#line 8250 "./marpa.w"

{
Marpa_Symbol_ID*complete_symbols= Complete_SYMIDs_of_EIM(cause);
gint count= Complete_SYM_Count_of_EIM(cause);
ES middle= Origin_of_EIM(cause);
gint symbol_ix;
for(symbol_ix= 0;symbol_ix<count;symbol_ix++)
{
Marpa_Symbol_ID complete_symbol= complete_symbols[symbol_ix];
/*935:*/
#line 8263 "./marpa.w"

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
/*936:*/
#line 8286 "./marpa.w"

{
ES origin= Origin_of_EIM(predecessor);
effect_AHFA_state= To_AHFA_of_EIM_by_SYMID(predecessor,complete_symbol);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect)){

if(Earley_Item_is_Completion(effect)){
/*937:*/
#line 8302 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:937*/
#line 8295 "./marpa.w"

}
/*938:*/
#line 8309 "./marpa.w"
{
AHFA prediction_AHFA_state= 
Empty_Transition_of_AHFA(effect_AHFA_state);
if(prediction_AHFA_state)
{
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_AHFA_state);
}
}

/*:938*/
#line 8297 "./marpa.w"

}
completion_link_add(r,effect,predecessor,cause);
}

/*:936*/
#line 8274 "./marpa.w"

}
else
{
/*939:*/
#line 8319 "./marpa.w"
{
LIM leo_item= LIM_of_PIM(postdot_item);
ES origin= Origin_of_LIM(leo_item);
effect_AHFA_state= Top_AHFA_of_LIM(leo_item);
effect= earley_item_assign(r,current_earley_set,
origin,effect_AHFA_state);
if(Earley_Item_has_No_Source(effect))
{

/*937:*/
#line 8302 "./marpa.w"
{
EIM*tos= DSTACK_PUSH(r->t_completion_stack,EIM);
*tos= effect;
}



/*:937*/
#line 8328 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:939*/
#line 8278 "./marpa.w"

break;


}
}
}

/*:935*/
#line 8259 "./marpa.w"

}
}

/*:934*/
#line 8150 "./marpa.w"

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

/*:927*//*941:*/
#line 8335 "./marpa.w"

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

/*:941*//*943:*/
#line 8361 "./marpa.w"

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

/*:943*//*947:*/
#line 8399 "./marpa.w"

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
/*948:*/
#line 8421 "./marpa.w"
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

/*:948*/
#line 8410 "./marpa.w"

if(r->t_is_using_leo){
/*950:*/
#line 8467 "./marpa.w"

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
/*951:*/
#line 8497 "./marpa.w"
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

/*:951*/
#line 8484 "./marpa.w"

}
}
}
}
}

/*:950*/
#line 8412 "./marpa.w"

/*960:*/
#line 8582 "./marpa.w"
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

/*963:*/
#line 8641 "./marpa.w"
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

/*:963*/
#line 8600 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*969:*/
#line 8733 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:969*/
#line 8602 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*971:*/
#line 8754 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
LV_Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:971*/
#line 8608 "./marpa.w"

continue;
}
/*964:*/
#line 8656 "./marpa.w"
{
gpointer*const lim_chain= r->t_workarea2;
gint lim_chain_ix;
/*967:*/
#line 8677 "./marpa.w"
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

/*963:*/
#line 8641 "./marpa.w"
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

/*:963*/
#line 8703 "./marpa.w"


lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,(guint)postdot_symid_of_lim_to_process);



if(!predecessor_lim)break;


if(LIM_is_Populated(predecessor_lim))break;



}
}

/*:967*/
#line 8659 "./marpa.w"

/*968:*/
#line 8722 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*969:*/
#line 8733 "./marpa.w"
{
LV_Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
LV_Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
LV_Chain_Length_of_LIM(lim_to_process)= 
Chain_Length_of_LIM(lim_to_process)+1;
LV_Top_AHFA_of_LIM(lim_to_process)= Top_AHFA_of_LIM(predecessor_lim);
}

/*:969*/
#line 8726 "./marpa.w"

}else{
/*971:*/
#line 8754 "./marpa.w"
{
EIM base_eim= Base_EIM_of_LIM(lim_to_process);
LV_Origin_of_LIM(lim_to_process)= Origin_of_EIM(base_eim);
LV_Chain_Length_of_LIM(lim_to_process)= 0;
}

/*:971*/
#line 8728 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:968*/
#line 8660 "./marpa.w"

}

/*:964*/
#line 8611 "./marpa.w"

}
}
}

/*:960*/
#line 8413 "./marpa.w"

}
/*972:*/
#line 8760 "./marpa.w"
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

/*:972*/
#line 8415 "./marpa.w"

bv_and(r->t_bv_symid_is_expected,bv_pim_symbols,g->t_bv_symid_is_terminal);
}

/*:947*//*976:*/
#line 8816 "./marpa.w"

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
/*977:*/
#line 8863 "./marpa.w"
{
this_lim= Predecessor_of_SRCL(leo_link);
previous_eim_on_this_path= Cause_of_SRCL(leo_link);
leo_path_lengths+= 2;

}

/*:977*/
#line 8831 "./marpa.w"

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
/*978:*/
#line 8870 "./marpa.w"
{
LIM next_lim;
while((next_lim= Predecessor_LIM_of_LIM(this_lim))){
/*979:*/
#line 8884 "./marpa.w"

{
const EIM base_eim_of_this_lim= Base_EIM_of_LIM(this_lim);
const SYMID postdot_symbol_of_this_lim= Postdot_SYMID_of_LIM(this_lim);
EIM new_eim_for_this_path= 
old_earley_item_assign(r,earley_set_of_this_path,
ES_of_LIM(next_lim),
To_AHFA_of_EIM_by_SYMID(base_eim_of_this_lim,
postdot_symbol_of_this_lim));
leo_path_lengths++;
EIM_is_Leo_Expansion(new_eim_for_this_path)= 1;
completion_link_add(r,new_eim_for_this_path,
base_eim_of_this_lim,
previous_eim_on_this_path);
previous_eim_on_this_path= new_eim_for_this_path;
}

/*:979*/
#line 8873 "./marpa.w"

this_lim= next_lim;
}
completion_link_add(r,leo_completion,Base_EIM_of_LIM(this_lim),previous_eim_on_this_path);



}

/*:978*/
#line 8848 "./marpa.w"

if(!next_leo_link)break;
{
const SRCL leo_link= next_leo_link;
next_leo_link= Next_SRCL_of_SRCL(leo_link);
/*977:*/
#line 8863 "./marpa.w"
{
this_lim= Predecessor_of_SRCL(leo_link);
previous_eim_on_this_path= Cause_of_SRCL(leo_link);
leo_path_lengths+= 2;

}

/*:977*/
#line 8853 "./marpa.w"

}
}
earley_set_update_items(r,earley_set_of_this_path);
r->t_is_leo_expanding= 0;


return leo_path_lengths;
}

/*:976*//*983:*/
#line 8917 "./marpa.w"

gint marpa_leo_completion_expand(struct marpa_r*r)
{
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 8920 "./marpa.w"

EIM item= r->t_trace_earley_item;
/*1260:*/
#line 11784 "./marpa.w"

switch(Phase_of_R(r)){
default:
R_ERROR("recce not trace-safe");
return failure_indicator;
case input_phase:
case evaluation_phase:
break;
}
/*:1260*/
#line 8922 "./marpa.w"

if(!item){
/*775:*/
#line 6550 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:775*/
#line 8924 "./marpa.w"

R_ERROR("no trace eim");
return failure_indicator;
}
return leo_completion_expand(r,item);
}

/*:983*//*1005:*/
#line 9091 "./marpa.w"

static inline void ur_node_stack_init(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_init %s",G_STRLOC);
obstack_init(&stack->t_obs);
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:1005*//*1007:*/
#line 9101 "./marpa.w"

static inline void ur_node_stack_reset(URS stack){
stack->t_top= stack->t_base;
}

/*:1007*//*1009:*/
#line 9108 "./marpa.w"

static inline void ur_node_stack_destroy(URS stack){
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
if(stack->t_base)obstack_free(&stack->t_obs,NULL);
stack->t_base= NULL;
MARPA_OFF_DEBUG2("ur_node_stack_destroy %s",G_STRLOC);
}

/*:1009*//*1011:*/
#line 9118 "./marpa.w"

static inline UR ur_node_new(URS stack,UR prev){
UR new_ur_node;
new_ur_node= obstack_alloc(&stack->t_obs,sizeof(new_ur_node[0]));
LV_Next_UR_of_UR(new_ur_node)= 0;
LV_Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:1011*//*1013:*/
#line 9129 "./marpa.w"

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

/*:1013*//*1015:*/
#line 9147 "./marpa.w"

static inline UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:1015*//*1020:*/
#line 9257 "./marpa.w"

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
MARPA_DEBUG4("PSIA Set S=%d I=%s A=%d",set_ordinal,eim_tag(earley_item),ahfa_element_ix);
nodes_by_aex[ahfa_element_ix]= dummy_or_node;
return 0;
}
return 1;
}

/*:1020*//*1056:*/
#line 9874 "./marpa.w"

static inline AEX lim_base_data_get(LIM leo_item,EIM*p_base)
{
const SYMID postdot= Postdot_SYMID_of_LIM(leo_item);
const EIM base= Base_EIM_of_LIM(leo_item);
const TRANS transition= TRANS_of_EIM_by_SYMID(base,postdot);
*p_base= base;
return Leo_Base_AEX_of_TRANS(transition);
}

/*:1056*//*1058:*/
#line 9888 "./marpa.w"

static inline AIM base_aim_of_lim(LIM leo_item)
{
EIM base;
const AEX base_aex= lim_base_data_get(leo_item,&base);
return AIM_of_EIM_by_AEX(base,base_aex);
}

/*:1058*//*1065:*/
#line 10011 "./marpa.w"

static inline
DAND draft_and_node_new(struct obstack*obs,OR predecessor,
gint middle,WHEID wheid)
{
DAND draft_and_node= obstack_alloc(obs,sizeof(DAND_Object));
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Middle_ES_Ord_of_DAND(draft_and_node)= middle;
WHEID_of_DAND(draft_and_node)= wheid;
return draft_and_node;
}

/*:1065*//*1068:*/
#line 10038 "./marpa.w"

static inline
void draft_and_node_add(struct obstack*obs,OR parent,OR predecessor,
gint middle,WHEID wheid)
{
const DAND new= draft_and_node_new(obs,predecessor,middle,wheid);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:1068*//*1094:*/
#line 10293 "./marpa.w"

gint marpa_bocage_new(struct marpa_r*r,Marpa_Rule_ID rule_id,Marpa_Earley_Set_ID ordinal){
const gint no_parse= -1;
const gint null_parse= 0;
/*1095:*/
#line 10315 "./marpa.w"

/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 10316 "./marpa.w"

const GRAMMAR_Const g= G_of_R(r);
gint rule_count_of_g= RULE_Count_of_G(g);
BOC b;
ES end_of_parse_es;
RULE completed_start_rule;
EIM start_eim= NULL;
AIM start_aim= NULL;
AEX start_aex= -1;
struct obstack bocage_setup_obs;
guint total_earley_items_in_parse;
guint or_node_estimate= 0;

/*:1095*//*1098:*/
#line 10337 "./marpa.w"

struct s_bocage_setup_per_es*per_es_data= NULL;

/*:1098*/
#line 10297 "./marpa.w"

r_update_earley_sets(r);
MARPA_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
/*1099:*/
#line 10341 "./marpa.w"

{
EARLEME end_of_parse_earleme;
/*1261:*/
#line 11793 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1261*/
#line 10344 "./marpa.w"

MARPA_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
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
if(ordinal==0){
return null_parse;
}
}

/*:1099*/
#line 10301 "./marpa.w"

b= B_of_R(r)= g_slice_new(BOC_Object);
MARPA_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
/*1042:*/
#line 9605 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
/*:1042*//*1091:*/
#line 10285 "./marpa.w"

obstack_init(&OBS_of_B(b));
/*:1091*/
#line 10304 "./marpa.w"

/*1104:*/
#line 10457 "./marpa.w"

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

/*:1104*/
#line 10305 "./marpa.w"

Phase_of_R(r)= evaluation_phase;
obstack_init(&bocage_setup_obs);
/*1100:*/
#line 10399 "./marpa.w"

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

/*:1100*/
#line 10308 "./marpa.w"

/*1101:*/
#line 10427 "./marpa.w"

{
/*1016:*/
#line 9161 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);
{
const EIM ur_earley_item= start_eim;
const AIM ur_aim= start_aim;
const AEX ur_aex= start_aex;
MARPA_DEBUG4("%s: Adding ur-node for %s aex=%d",
G_STRLOC,eim_tag(ur_earley_item),ur_aex);
/*1018:*/
#line 9238 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1018*/
#line 9172 "./marpa.w"

}
while((ur_node= ur_node_pop(ur_node_stack)))
{
const EIM_Const parent_earley_item= EIM_of_UR(ur_node);
if(!EIM_is_Leo_Expansion(parent_earley_item)){
const AEX parent_aex= AEX_of_UR(ur_node);
const AIM parent_aim= AIM_of_EIM_by_AEX(parent_earley_item,parent_aex);
MARPA_ASSERT(parent_aim>=AIM_by_ID(g,1))
const AIM predecessor_aim= parent_aim-1;


guint source_type= Source_Type_of_EIM(parent_earley_item);
MARPA_ASSERT(!EIM_is_Predicted(parent_earley_item))
MARPA_DEBUG3("parent_earley_item=%s, parent_aex=%d",
eim_tag(parent_earley_item),
parent_aex);
/*1021:*/
#line 9286 "./marpa.w"

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
/*1022:*/
#line 9330 "./marpa.w"
{
if(Position_of_AIM(predecessor_aim)> 0){
const gint null_count= Null_Count_of_AIM(predecessor_aim);
if(null_count){
AEX predecessor_aex= AEX_of_EIM_by_AIM(predecessor_earley_item,
predecessor_aim);
or_node_estimate+= null_count;
MARPA_DEBUG4("%s: Initial nulls for %s aex=%d",
G_STRLOC,eim_tag(predecessor_earley_item),predecessor_aex);
psia_test_and_set(&bocage_setup_obs,per_es_data,
predecessor_earley_item,predecessor_aex);
}
}
}

/*:1022*/
#line 9308 "./marpa.w"

}else{
const EIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
MARPA_DEBUG4("%s: Adding ur-node for %s aex=%d",
G_STRLOC,eim_tag(ur_earley_item),ur_aex);
/*1018:*/
#line 9238 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1018*/
#line 9316 "./marpa.w"

}
}
if(!source_link)
break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1021*/
#line 9189 "./marpa.w"

/*1023:*/
#line 9345 "./marpa.w"

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
/*1022:*/
#line 9330 "./marpa.w"
{
if(Position_of_AIM(predecessor_aim)> 0){
const gint null_count= Null_Count_of_AIM(predecessor_aim);
if(null_count){
AEX predecessor_aex= AEX_of_EIM_by_AIM(predecessor_earley_item,
predecessor_aim);
or_node_estimate+= null_count;
MARPA_DEBUG4("%s: Initial nulls for %s aex=%d",
G_STRLOC,eim_tag(predecessor_earley_item),predecessor_aex);
psia_test_and_set(&bocage_setup_obs,per_es_data,
predecessor_earley_item,predecessor_aex);
}
}
}

/*:1022*/
#line 9373 "./marpa.w"

}
else
{
const EIM ur_earley_item= predecessor_earley_item;
const AEX ur_aex= 
AEX_of_EIM_by_AIM(predecessor_earley_item,predecessor_aim);
const AIM ur_aim= predecessor_aim;
MARPA_DEBUG4("%s: Adding ur-node for %s aex=%d",
G_STRLOC,eim_tag(ur_earley_item),ur_aex);
/*1018:*/
#line 9238 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1018*/
#line 9383 "./marpa.w"

}
}
{
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
const EIM ur_earley_item= cause_earley_item;
gint ix;
MARPA_DEBUG4("%s: TRANS of %s, sym=%d",G_STRLOC,
eim_tag(cause_earley_item),transition_symbol_id);
MARPA_DEBUG4("%s: aexes=%p, aex_count=%d",G_STRLOC,aexes,aex_count);
MARPA_DEBUG3("%s transition_symbol_id=%d",
G_STRLOC,transition_symbol_id);
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
MARPA_DEBUG4("%s: Adding ur-node for %s aex=%d",
G_STRLOC,eim_tag(ur_earley_item),ur_aex);
/*1018:*/
#line 9238 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1018*/
#line 9403 "./marpa.w"

}
}
if(!source_link)break;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1023*/
#line 9190 "./marpa.w"

/*1024:*/
#line 9413 "./marpa.w"

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
MARPA_DEBUG3("%s: Processing Leo source link, cause is %s",
G_STRLOC,eim_tag(cause_earley_item));
MARPA_DEBUG4("%s: TRANS of %s, sym=%d",G_STRLOC,
eim_tag(cause_earley_item),transition_symbol_id);
MARPA_DEBUG4("%s: aexes=%p, aex_count=%d",G_STRLOC,aexes,aex_count);
for(ix= 0;ix<aex_count;ix++){
const AEX ur_aex= aexes[ix];
const AIM ur_aim= AIM_of_EIM_by_AEX(ur_earley_item,ur_aex);
MARPA_DEBUG4("%s: Adding ur-node for %s aex=%d",
G_STRLOC,eim_tag(ur_earley_item),ur_aex);
/*1018:*/
#line 9238 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1018*/
#line 9453 "./marpa.w"

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
const EIM predecessor_earley_item= ur_earley_item;
/*1022:*/
#line 9330 "./marpa.w"
{
if(Position_of_AIM(predecessor_aim)> 0){
const gint null_count= Null_Count_of_AIM(predecessor_aim);
if(null_count){
AEX predecessor_aex= AEX_of_EIM_by_AIM(predecessor_earley_item,
predecessor_aim);
or_node_estimate+= null_count;
MARPA_DEBUG4("%s: Initial nulls for %s aex=%d",
G_STRLOC,eim_tag(predecessor_earley_item),predecessor_aex);
psia_test_and_set(&bocage_setup_obs,per_es_data,
predecessor_earley_item,predecessor_aex);
}
}
}

/*:1022*/
#line 9468 "./marpa.w"

}else{
MARPA_DEBUG4("%s: Adding ur-node for %s aex=%d",
G_STRLOC,eim_tag(ur_earley_item),ur_aex);
/*1018:*/
#line 9238 "./marpa.w"
{
if(!psia_test_and_set
(&bocage_setup_obs,per_es_data,ur_earley_item,ur_aex))
{
ur_node_push(ur_node_stack,ur_earley_item,ur_aex);
or_node_estimate+= 1+Null_Count_of_AIM(ur_aim);
}
}

/*:1018*/
#line 9472 "./marpa.w"

}
leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor);
}
if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
source_link= Next_SRCL_of_SRCL(source_link);
}
}

/*:1024*/
#line 9191 "./marpa.w"

}
}
/*1017:*/
#line 9204 "./marpa.w"
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
MARPA_DEBUG5("Setting psia for es=%d,eim=%d,aex=%d to %p",
0,item_ordinal,aex,NULL);
goto FINISHED_UNSET;
}
}
}
}
}
FINISHED_UNSET:;
}

/*:1017*/
#line 9194 "./marpa.w"

}

/*:1016*/
#line 10429 "./marpa.w"

/*1044:*/
#line 9618 "./marpa.w"

{
PSAR_Object and_per_es_arena;
const PSAR and_psar= &and_per_es_arena;
PSAR_Object or_per_es_arena;
const PSAR or_psar= &or_per_es_arena;
const gint earley_set_count= ES_Count_of_R(r);
gint work_earley_set_ordinal;
PSL this_earley_set_psl;
OR last_or_node= NULL;
psar_init(and_psar,AHFA_Count_of_G(g));
MARPA_OFF_DEBUG3("%s SYMI count = %d",G_STRLOC,SYMI_Count_of_G(g));
psar_init(or_psar,SYMI_Count_of_G(g));
ORs_of_B(b)= g_new(OR,or_node_estimate);
for(work_earley_set_ordinal= 0;
work_earley_set_ordinal<earley_set_count;
work_earley_set_ordinal++)
{
const ES_Const earley_set= ES_of_R_by_Ord(r,work_earley_set_ordinal);
psar_dealloc(or_psar);
#define PSL_ES_ORD work_earley_set_ordinal
#define CLAIMED_PSL this_earley_set_psl
/*1228:*/
#line 11532 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
MARPA_DEBUG3("Claiming psl at ordinal=%d as %s",PSL_ES_ORD,G_STRINGIFY(CLAIMED_PSL));
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1228*/
#line 9640 "./marpa.w"

/*1045:*/
#line 9648 "./marpa.w"

{
OR**const nodes_by_item= per_es_data[work_earley_set_ordinal].t_aexes_by_item;
EIM*const eims_of_es= EIMs_of_ES(earley_set);
const gint item_count= EIM_Count_of_ES(earley_set);
/*1046:*/
#line 9659 "./marpa.w"

{
gint item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const work_nodes_by_aex= nodes_by_item[item_ordinal];
MARPA_DEBUG4("Setting work_nodes_by_aex to %p, item=%d, es=%d",work_nodes_by_aex,
item_ordinal,work_earley_set_ordinal);
if(work_nodes_by_aex){
const EIM work_earley_item= eims_of_es[item_ordinal];
const gint work_ahfa_item_count= AIM_Count_of_EIM(work_earley_item);
AEX work_aex;
const gint work_origin_ordinal= Ord_of_ES(Origin_of_EIM(work_earley_item));
for(work_aex= 0;work_aex<work_ahfa_item_count;work_aex++){
if(!work_nodes_by_aex[work_aex])continue;
/*1047:*/
#line 9681 "./marpa.w"

{
AIM ahfa_item= AIM_of_EIM_by_AEX(work_earley_item,work_aex);
SYMI ahfa_item_symbol_instance;
OR psia_or_node= NULL;
ahfa_item_symbol_instance= SYMI_of_AIM(ahfa_item);
{
PSL or_psl;
#define PSL_ES_ORD work_origin_ordinal
#define CLAIMED_PSL or_psl
/*1228:*/
#line 11532 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
MARPA_DEBUG3("Claiming psl at ordinal=%d as %s",PSL_ES_ORD,G_STRINGIFY(CLAIMED_PSL));
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1228*/
#line 9691 "./marpa.w"

/*1048:*/
#line 9709 "./marpa.w"

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
/*1049:*/
#line 9743 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1049*/
#line 9720 "./marpa.w"

or_node= last_or_node;
PSL_Datum(or_psl,ahfa_item_symbol_instance)= last_or_node;
MARPA_DEBUG3("%s: or_psl symi=%d",G_STRLOC,ahfa_item_symbol_instance);
Start_ES_Ord_of_OR(or_node)= Origin_Ord_of_EIM(work_earley_item);
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= rule;
Position_of_OR(or_node)= 
ahfa_item_symbol_instance-SYMI_of_RULE(rule)+1;
MARPA_DEBUG3("%s or_psl SYMI = %d",G_STRLOC,ahfa_item_symbol_instance);
MARPA_DEBUG3("main or-node EIM = %s aex=%d",eim_tag(work_earley_item),work_aex);
MARPA_DEBUG3("Created or-node %s at %s",or_tag(or_node),G_STRLOC);
DANDs_of_OR(or_node)= NULL;
}
psia_or_node= or_node;
}
}

/*:1048*/
#line 9692 "./marpa.w"

/*1051:*/
#line 9767 "./marpa.w"

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
const OR predecessor= symbol_instance?last_or_node:NULL;
const WHEID whole_element_id= WHEID_of_SYMID(RHS_ID_of_RULE(rule,rhs_ix));
/*1049:*/
#line 9743 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1049*/
#line 9788 "./marpa.w"

or_node= PSL_Datum(or_psl,symbol_instance)= last_or_node;
MARPA_DEBUG3("%s: or_psl symi=%d",G_STRLOC,symbol_instance);
Start_ES_Ord_of_OR(or_node)= work_origin_ordinal;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= rule;
MARPA_OFF_DEBUG3("Added rule %p to or-node %p",RULE_of_OR(or_node),or_node);
Position_of_OR(or_node)= rhs_ix+1;
MARPA_DEBUG3("Created or-node %s at %s",or_tag(or_node),G_STRLOC);
draft_and_node= DANDs_of_OR(or_node)= 
draft_and_node_new(&bocage_setup_obs,predecessor,
work_earley_set_ordinal,whole_element_id);
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,DANDs_of_OR(or_node));
Next_DAND_of_DAND(draft_and_node)= NULL;
}
psia_or_node= or_node;
}
}
}

/*:1051*/
#line 9693 "./marpa.w"

}


MARPA_DEBUG3("eim, aex = %s, %d",eim_tag(work_earley_item),work_aex);
MARPA_ASSERT(psia_or_node)
work_nodes_by_aex[work_aex]= psia_or_node;
MARPA_DEBUG4("Setting psia for work_nodes_by_aex=%p,aex=%d to %p",
work_nodes_by_aex,work_aex,psia_or_node);
/*1052:*/
#line 9808 "./marpa.w"
{
SRCL source_link= NULL;
EIM cause_earley_item= NULL;
LIM leo_predecessor= NULL;
switch(Source_Type_of_EIM(work_earley_item))
{
case SOURCE_IS_LEO:
leo_predecessor= Predecessor_of_EIM(work_earley_item);
cause_earley_item= Cause_of_EIM(work_earley_item);
MARPA_DEBUG2("Unique Leo source: cause=%s",eim_tag(cause_earley_item));
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Leo_SRCL_of_EIM(work_earley_item);
if(source_link)
{
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
MARPA_DEBUG2("OR Ambiguous Leo source: cause=%s",eim_tag(cause_earley_item));
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
if(leo_predecessor){
for(;;){
/*1054:*/
#line 9851 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const gint ordinal_of_set_of_this_leo_item= Ord_of_ES(ES_of_LIM(this_leo_item));
const AIM path_ahfa_item= Path_AIM_of_LIM(previous_leo_item);
const RULE path_rule= RULE_of_AIM(path_ahfa_item);
const gint symbol_instance_of_path_ahfa_item= SYMI_of_AIM(path_ahfa_item);
MARPA_DEBUG3("rule=%d symi=%d",
ID_of_RULE(path_rule),
symbol_instance_of_path_ahfa_item);
/*1059:*/
#line 9899 "./marpa.w"

{
{
OR or_node;
PSL leo_psl;
#define PSL_ES_ORD ordinal_of_set_of_this_leo_item
#define CLAIMED_PSL leo_psl
/*1228:*/
#line 11532 "./marpa.w"

{
PSL*psl_owner= &per_es_data[PSL_ES_ORD].t_or_psl;
MARPA_DEBUG3("Claiming psl at ordinal=%d as %s",PSL_ES_ORD,G_STRINGIFY(CLAIMED_PSL));
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
(CLAIMED_PSL)= *psl_owner;
}
#undef PSL_ES_ORD
#undef CLAIMED_PSL

/*:1228*/
#line 9906 "./marpa.w"

or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item);
if(!or_node||ES_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
/*1049:*/
#line 9743 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1049*/
#line 9910 "./marpa.w"

PSL_Datum(leo_psl,symbol_instance_of_path_ahfa_item)= or_node= last_or_node;
MARPA_DEBUG3("%s: leo_psl symi=%d",G_STRLOC,symbol_instance_of_path_ahfa_item);
Start_ES_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
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

/*:1059*/
#line 9864 "./marpa.w"

/*1060:*/
#line 9929 "./marpa.w"

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
OR predecessor= last_or_node;

const gint rhs_ix= symbol_instance-SYMI_of_RULE(path_rule);
const WHEID whole_element_id= WHEID_of_SYMID(RHS_ID_of_RULE(path_rule,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_RULE(path_rule))
MARPA_ASSERT(symbol_instance>=0)
/*1049:*/
#line 9743 "./marpa.w"

{
const gint or_node_id= OR_Count_of_B(b)++;
OR*or_nodes_of_b= ORs_of_B(b);
last_or_node= (OR)obstack_alloc(&OBS_of_B(b),sizeof(OR_Object));
if(G_UNLIKELY(or_node_id>=or_node_estimate))
{
MARPA_ASSERT(0);
or_node_estimate*= 2;
ORs_of_B(b)= or_nodes_of_b= 
g_renew(OR,or_nodes_of_b,or_node_estimate);
}
or_nodes_of_b[or_node_id]= last_or_node;
}


/*:1049*/
#line 9947 "./marpa.w"

PSL_Datum(this_earley_set_psl,symbol_instance)= or_node= last_or_node;
MARPA_DEBUG3("%s: this_earley_set_psl symi=%d",G_STRLOC,symbol_instance);
Start_ES_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
ES_Ord_of_OR(or_node)= work_earley_set_ordinal;
RULE_of_OR(or_node)= path_rule;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_DEBUG3("Created or-node %s at %s",or_tag(or_node),
G_STRLOC);
DANDs_of_OR(or_node)= draft_and_node= 
draft_and_node_new(&bocage_setup_obs,predecessor,
work_earley_set_ordinal,whole_element_id);
MARPA_OFF_DEBUG3("or = %p, setting DAND = %p",or_node,
DANDs_of_OR(or_node));
Next_DAND_of_DAND(draft_and_node)= NULL;
}
MARPA_ASSERT(Position_of_OR(or_node)<=
SYMI_of_RULE(path_rule)+Length_of_RULE(path_rule))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_RULE(path_rule))
}
}

/*:1060*/
#line 9865 "./marpa.w"

previous_leo_item= this_leo_item;
}
}

/*:1054*/
#line 9832 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
MARPA_DEBUG2("OR Additional Leo source: cause=%s",eim_tag(cause_earley_item));
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:1052*/
#line 9702 "./marpa.w"

}

/*:1047*/
#line 9675 "./marpa.w"

}
}
}
}

/*:1046*/
#line 9653 "./marpa.w"

if(0){
/*1069:*/
#line 10048 "./marpa.w"

{
gint item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR*const nodes_by_aex= nodes_by_item[item_ordinal];
if(nodes_by_aex){
const EIM earley_item= eims_of_es[item_ordinal];
const gint aim_count_of_item= AIM_Count_of_EIM(earley_item);
const gint origin_ordinal= Ord_of_ES(Origin_of_EIM(earley_item));
AEX aex;
MARPA_DEBUG2("Creating DANDs for %s",eim_tag(earley_item));
for(aex= 0;aex<aim_count_of_item;aex++){
OR or_node= nodes_by_aex[aex];
MARPA_DEBUG3("OR of aex %d is %p",aex,or_node);
while(or_node){
DAND draft_and_node= DANDs_of_OR(or_node);
MARPA_DEBUG2("or_node = %s",or_tag(or_node));
MARPA_DEBUG2("DAND = %p",draft_and_node);
if(!draft_and_node)
break;
if(Middle_ES_Ord_of_DAND(draft_and_node)!=work_earley_set_ordinal)
break;
or_node= Predecessor_OR_of_DAND(draft_and_node);
}
if(or_node){
/*1070:*/
#line 10081 "./marpa.w"

{
/*1071:*/
#line 10086 "./marpa.w"
{
SRCL source_link= NULL;
EIM cause_earley_item= NULL;
LIM leo_predecessor= NULL;
switch(Source_Type_of_EIM(earley_item))
{
case SOURCE_IS_LEO:
leo_predecessor= Predecessor_of_EIM(earley_item);
cause_earley_item= Cause_of_EIM(earley_item);
break;
case SOURCE_IS_AMBIGUOUS:
source_link= First_Leo_SRCL_of_EIM(earley_item);
if(source_link)
{
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
MARPA_DEBUG2("DAND Ambiguous Leo source: cause=%s",eim_tag(cause_earley_item));
source_link= Next_SRCL_of_SRCL(source_link);
}
break;
}
if(leo_predecessor){
for(;;){
/*1072:*/
#line 10119 "./marpa.w"

{
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);


gint at_top_of_path= !higher_path_leo_item;
PSL or_psl;
/*1073:*/
#line 10142 "./marpa.w"

{
OR bottom_or_node;
/*1074:*/
#line 10149 "./marpa.w"

{
AIM same_rule_ahfa_item;
RULE bottom_or_node_rule;
gint bottom_or_node_origin;
gint bottom_or_node_symi;
MARPA_DEBUG3("%s: eim=%s",G_STRLOC,eim_tag(earley_item));
if(higher_path_leo_item)
{
MARPA_DEBUG2("%s",G_STRLOC);
same_rule_ahfa_item= Base_AIM_of_LIM(path_leo_item);
bottom_or_node_origin= Ord_of_ES(ES_of_LIM(higher_path_leo_item));
}
else
{
MARPA_DEBUG2("%s",G_STRLOC);
same_rule_ahfa_item= AIM_of_EIM_by_AEX(earley_item,aex);
bottom_or_node_origin= Origin_Ord_of_EIM(earley_item);
}
bottom_or_node_rule= RULE_of_AIM(same_rule_ahfa_item);
bottom_or_node_symi= SYMI_of_Completed_RULE(bottom_or_node_rule);
MARPA_DEBUG3("%s bottom_or_node_rule=%d",G_STRLOC,ID_of_RULE(bottom_or_node_rule));
/*1075:*/
#line 10176 "./marpa.w"

{
const PSL or_psl_at_origin= per_es_data[bottom_or_node_origin].t_or_psl;
bottom_or_node= PSL_Datum(or_psl_at_origin,bottom_or_node_symi);
MARPA_DEBUG4("%s: origin=%d, symi=%d",G_STRLOC,
bottom_or_node_origin,bottom_or_node_symi);
MARPA_ASSERT(bottom_or_node);
}

/*:1075*/
#line 10172 "./marpa.w"

}

/*:1074*/
#line 10145 "./marpa.w"

/*1076:*/
#line 10185 "./marpa.w"

{
const SYMID transition_symbol_id= Postdot_SYMID_of_LIM(leo_predecessor);
const TRANS cause_completion_data= 
TRANS_of_EIM_by_SYMID(cause_earley_item,transition_symbol_id);
const gint aex_count= Completion_Count_of_TRANS(cause_completion_data);
const AEX*const aexes= AEXs_of_TRANS(cause_completion_data);
const gint dand_ordinal= Ord_of_ES(ES_of_LIM(path_leo_item));
OR dand_predecessor;
gint ix;
/*1078:*/
#line 10208 "./marpa.w"

{
EIM base_earley_item;
const AEX base_aex= lim_base_data_get(path_leo_item,&base_earley_item);
#define PSIA_EIM base_earley_item
#define PSIA_AEX base_aex
#define PSIA_OR dand_predecessor
/*1079:*/
#line 10220 "./marpa.w"

{
const EIM psia_earley_item= PSIA_EIM;
const gint psia_earley_set_ordinal= ES_Ord_of_EIM(psia_earley_item);
OR**const psia_nodes_by_item= 
per_es_data[psia_earley_set_ordinal].t_aexes_by_item;
const gint psia_item_ordinal= Ord_of_EIM(psia_earley_item);
OR*const psia_nodes_by_aex= psia_nodes_by_item[psia_item_ordinal];
PSIA_OR= psia_nodes_by_aex[PSIA_AEX];
}
#undef PSIA_OR
#undef PSIA_EIM
#undef PSIA_AEX

/*:1079*/
#line 10215 "./marpa.w"

}

/*:1078*/
#line 10195 "./marpa.w"

for(ix= 0;ix<aex_count;ix++)
{
const AEX cause_aex= aexes[ix];
gint dand_wheid;
/*1077:*/
#line 10206 "./marpa.w"
{;}

/*:1077*/
#line 10200 "./marpa.w"

draft_and_node_add(&bocage_setup_obs,bottom_or_node,
dand_predecessor,dand_ordinal,dand_wheid);
}
}

/*:1076*/
#line 10146 "./marpa.w"

}

/*:1073*/
#line 10127 "./marpa.w"

while(!at_top_of_path){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
if(higher_path_leo_item){
/*1080:*/
#line 10234 "./marpa.w"
{;}
/*:1080*/
#line 10132 "./marpa.w"

}else{
at_top_of_path= 1;
/*1081:*/
#line 10235 "./marpa.w"
{;}
/*:1081*/
#line 10135 "./marpa.w"

}
/*1082:*/
#line 10236 "./marpa.w"
{;}

/*:1082*/
#line 10137 "./marpa.w"

}
}

/*:1072*/
#line 10109 "./marpa.w"

if(!source_link)break;
leo_predecessor= Predecessor_of_SRCL(source_link);
cause_earley_item= Cause_of_SRCL(source_link);
MARPA_DEBUG2("DAND Additional Leo source: cause=%s",eim_tag(cause_earley_item));
source_link= Next_SRCL_of_SRCL(source_link);
}
}
}

/*:1071*/
#line 10083 "./marpa.w"

}

/*:1070*/
#line 10074 "./marpa.w"

}
}
}
}
}

/*:1069*/
#line 9655 "./marpa.w"

}
}

/*:1045*/
#line 9641 "./marpa.w"

}
ORs_of_B(b)= g_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
psar_destroy(and_psar);
psar_destroy(or_psar);
}

/*:1044*/
#line 10430 "./marpa.w"

}

/*:1101*/
#line 10309 "./marpa.w"

/*1107:*/
#line 10493 "./marpa.w"
{
;
}


/*:1107*/
#line 10310 "./marpa.w"

obstack_free(&bocage_setup_obs,NULL);
return 1;
}

/*:1094*//*1109:*/
#line 10503 "./marpa.w"

gint marpa_bocage_free(struct marpa_r*r){
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 10505 "./marpa.w"

/*1261:*/
#line 11793 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1261*/
#line 10506 "./marpa.w"

if(Phase_of_R(r)==evaluation_phase){

Phase_of_R(r)= input_phase;
}
/*1110:*/
#line 10515 "./marpa.w"
{
BOC b= B_of_R(r);
MARPA_OFF_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
if(b){
/*1105:*/
#line 10486 "./marpa.w"

/*1043:*/
#line 9608 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
if(or_nodes)
{
g_free(or_nodes);
ORs_of_B(b)= NULL;
}
}

/*:1043*/
#line 10487 "./marpa.w"
;
/*1092:*/
#line 10287 "./marpa.w"

obstack_free(&OBS_of_B(b),NULL);

/*:1092*/
#line 10488 "./marpa.w"
;

/*:1105*/
#line 10519 "./marpa.w"
;
g_slice_free(BOC_Object,b);
B_of_R(r)= NULL;
}
MARPA_OFF_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
}

/*:1110*/
#line 10511 "./marpa.w"

return 1;
}

/*:1109*//*1113:*/
#line 10530 "./marpa.w"

gint marpa_or_node(struct marpa_r*r,int or_node_id,int*or_data)
{
BOC b= B_of_R(r);
OR*or_nodes;
/*1247:*/
#line 11703 "./marpa.w"
const int failure_indicator= -2;

/*:1247*/
#line 10535 "./marpa.w"

/*1261:*/
#line 11793 "./marpa.w"

if(Phase_of_R(r)==error_phase){
R_ERROR(r->t_fatal_error);
return failure_indicator;
}
/*:1261*/
#line 10536 "./marpa.w"

MARPA_OFF_DEBUG3("%s B_of_R=%p",G_STRLOC,B_of_R(r));
if(Phase_of_R(r)!=evaluation_phase){
R_ERROR("recce not being evaluated");
return failure_indicator;
}
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
{
const OR or_node= or_nodes[or_node_id];
or_data[0]= Start_ES_Ord_of_OR(or_node);
or_data[1]= ES_Ord_of_OR(or_node);
or_data[2]= ID_of_RULE(RULE_of_OR(or_node));
or_data[3]= Position_of_OR(or_node);
or_data[4]= 0;
or_data[5]= 0;
}
return 1;
}

/*:1113*//*1116:*/
#line 10594 "./marpa.w"

static inline guint bv_bits_to_size(guint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:1116*//*1118:*/
#line 10602 "./marpa.w"

static inline guint bv_bits_to_unused_mask(guint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:1118*//*1121:*/
#line 10620 "./marpa.w"

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

/*:1121*//*1123:*/
#line 10640 "./marpa.w"

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


/*:1123*//*1124:*/
#line 10661 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:1124*//*1126:*/
#line 10673 "./marpa.w"
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
/*:1126*//*1128:*/
#line 10693 "./marpa.w"
static inline
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}
/*:1128*//*1130:*/
#line 10703 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:1130*//*1132:*/
#line 10712 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:1132*//*1134:*/
#line 10720 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}
/*:1134*//*1138:*/
#line 10735 "./marpa.w"

static inline void bv_clear(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1138*//*1140:*/
#line 10744 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:1140*//*1142:*/
#line 10752 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,guint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:1142*//*1144:*/
#line 10760 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,guint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:1144*//*1148:*/
#line 10771 "./marpa.w"

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

/*:1148*//*1150:*/
#line 10785 "./marpa.w"

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
/*:1150*//*1152:*/
#line 10802 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:1152*//*1154:*/
#line 10814 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:1154*//*1156:*/
#line 10826 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:1156*//*1158:*/
#line 10838 "./marpa.w"

static inline void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}
/*:1158*//*1160:*/
#line 10850 "./marpa.w"

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
/*:1160*//*1162:*/
#line 10926 "./marpa.w"

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
/*:1162*//*1168:*/
#line 10980 "./marpa.w"

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
/*:1168*//*1173:*/
#line 11059 "./marpa.w"

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
/*:1173*//*1175:*/
#line 11079 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:1175*//*1177:*/
#line 11092 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:1177*//*1179:*/
#line 11109 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,guint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:1179*//*1182:*/
#line 11119 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:1182*//*1185:*/
#line 11128 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:1185*//*1188:*/
#line 11137 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,guint row,guint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:1188*//*1190:*/
#line 11151 "./marpa.w"

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
/*:1190*//*1200:*/
#line 11286 "./marpa.w"

static inline gpointer dstack_resize(struct s_dstack*this,gsize type_bytes){
this->t_capacity*= 2;
this->t_base= g_realloc(this->t_base,this->t_capacity*type_bytes);
return this->t_base;
}
/*:1200*//*1217:*/
#line 11429 "./marpa.w"

static inline void
psar_init(const PSAR psar,gint length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1217*//*1218:*/
#line 11436 "./marpa.w"

static inline void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl)
{
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
MARPA_OFF_DEBUG3("%s owner=%p",G_STRLOC,owner);
if(owner)
*owner= NULL;
g_slice_free1(Sizeof_PSL(psar),psl);
psl= next_psl;
}
}
/*:1218*//*1219:*/
#line 11451 "./marpa.w"

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
/*:1219*//*1223:*/
#line 11483 "./marpa.w"

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

/*:1223*//*1225:*/
#line 11502 "./marpa.w"

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

/*:1225*//*1227:*/
#line 11524 "./marpa.w"

static inline void psl_claim(
PSL*const psl_owner,const PSAR psar){
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}

/*:1227*//*1231:*/
#line 11550 "./marpa.w"

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

/*:1231*//*1268:*/
#line 11863 "./marpa.w"

static void r_error(struct marpa_r*r,Marpa_Message_ID message,guint flags){
if(!(flags&CONTEXT_FLAG))r_context_clear(r);
r->t_error= message;
if(flags&FATAL_FLAG)r->t_fatal_error= r->t_error;
r_message(r,message);
}

/*:1268*//*1276:*/
#line 11937 "./marpa.w"

void marpa_g_message_callback_set(struct marpa_g*g,Marpa_G_Message_Callback*cb)
{g->t_message_callback= cb;}
void marpa_g_message_callback_arg_set(struct marpa_g*g,gpointer cb_arg)
{g->t_message_callback_arg= cb_arg;}
gpointer marpa_g_message_callback_arg(struct marpa_g*g)
{return g->t_message_callback_arg;}
/*:1276*//*1278:*/
#line 11954 "./marpa.w"

static inline void grammar_message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_G_Message_Callback*cb= g->t_message_callback;
if(cb){(*cb)(g,id);}}
/*:1278*//*1284:*/
#line 11974 "./marpa.w"

void marpa_r_message_callback_set(struct marpa_r*r,Marpa_R_Message_Callback*cb)
{r->t_message_callback= cb;}
void marpa_r_message_callback_arg_set(struct marpa_r*r,gpointer cb_arg)
{r->t_message_callback_arg= cb_arg;}
gpointer marpa_r_message_callback_arg(struct marpa_r*r)
{return Message_Callback_Arg_of_R(r);}
/*:1284*//*1286:*/
#line 11985 "./marpa.w"

static inline void r_message(struct marpa_r*r,Marpa_Message_ID id)
{Marpa_R_Message_Callback*cb= Message_Callback_of_R(r);
if(cb){(*cb)(r,id);}}
/*:1286*//*1290:*/
#line 12037 "./marpa.w"

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

/*:1290*//*1292:*/
#line 12066 "./marpa.w"

#if MARPA_DEBUG
static inline gchar*
lim_tag(gchar*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_SYMID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}
#endif

/*:1292*//*1294:*/
#line 12088 "./marpa.w"

#if MARPA_DEBUG
PRIVATE_NOT_INLINE const gchar*
or_tag_safe(gchar*buffer,OR or)
{
const gint type= Type_of_OR(or);
if(type==DUMMY_OR_NODE)return"DUMMY";
if(type==TOKEN_OR_NODE)return"TOKEN";
sprintf(buffer,"R%d:%d@%d-%d",
ID_of_RULE(RULE_of_OR(or)),Position_of_OR(or),
Start_ES_Ord_of_OR(or),
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


/*:1294*/
#line 12169 "./marpa.w"


/*:1300*/
