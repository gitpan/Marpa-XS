/*203:*/
#line 1525 "./marpa.w"

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

#include "config.h"
#include "marpa.h"

#line 1559 "./marpa.w"

/*189:*/
#line 1350 "./marpa.w"


#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:189*/
#line 1560 "./marpa.w"

/*19:*/
#line 389 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:19*//*32:*/
#line 478 "./marpa.w"
static gint next_grammar_id= 1;
/*:32*/
#line 1561 "./marpa.w"

/*60:*/
#line 602 "./marpa.w"

struct marpa_symbol{
/*69:*/
#line 647 "./marpa.w"
GArray*lhs;
/*:69*//*77:*/
#line 679 "./marpa.w"
GArray*rhs;
/*:77*//*129:*/
#line 899 "./marpa.w"

struct marpa_symbol*alias;
/*:129*/
#line 604 "./marpa.w"

/*67:*/
#line 639 "./marpa.w"
Marpa_Symbol_ID id;
/*:67*/
#line 605 "./marpa.w"

/*85:*/
#line 707 "./marpa.w"
unsigned int is_accessible:1;
/*:85*//*91:*/
#line 733 "./marpa.w"
unsigned int is_counted:1;
/*:91*//*97:*/
#line 759 "./marpa.w"
unsigned int is_nullable:1;
/*:97*//*103:*/
#line 784 "./marpa.w"
unsigned int is_nulling:1;
/*:103*//*109:*/
#line 809 "./marpa.w"
unsigned int is_terminal:1;
/*:109*//*115:*/
#line 835 "./marpa.w"
unsigned int is_productive:1;
/*:115*//*121:*/
#line 860 "./marpa.w"
unsigned int is_start:1;
/*:121*//*128:*/
#line 896 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:128*/
#line 606 "./marpa.w"

};

/*:60*//*155:*/
#line 1055 "./marpa.w"

struct marpa_rule{
/*167:*/
#line 1224 "./marpa.w"
gsize length;
/*:167*/
#line 1057 "./marpa.w"


/*174:*/
#line 1266 "./marpa.w"
Marpa_Rule_ID id;
/*:174*/
#line 1059 "./marpa.w"

/*176:*/
#line 1270 "./marpa.w"
unsigned int is_accessible:1;
/*:176*/
#line 1060 "./marpa.w"

/*168:*/
#line 1227 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:168*/
#line 1061 "./marpa.w"

};
static inline gsize rule_sizeof(length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}

/*:155*/
#line 1562 "./marpa.w"

/*42:*/
#line 509 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id);

/*:42*//*45:*/
#line 531 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:45*//*52:*/
#line 557 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id);

/*:52*//*62:*/
#line 623 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:62*//*66:*/
#line 635 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol);

/*:66*//*75:*/
#line 669 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);
/*:75*//*83:*/
#line 701 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);
/*:83*//*124:*/
#line 876 "./marpa.w"

static inline
gboolean symbol_is_start_value(struct marpa_symbol*symbol);
/*:124*//*132:*/
#line 923 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias_value(struct marpa_symbol*symbol);
/*:132*//*135:*/
#line 945 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias_value(struct marpa_symbol*symbol);
/*:135*//*138:*/
#line 984 "./marpa.w"

static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
/*:138*//*146:*/
#line 1019 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:146*//*153:*/
#line 1049 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:153*//*157:*/
#line 1095 "./marpa.w"

static inline
struct marpa_rule*rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:157*//*161:*/
#line 1113 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule);

/*:161*//*172:*/
#line 1255 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
static inline gsize rule_length_get(struct marpa_rule*rule);
static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,gint index);
/*:172*/
#line 1563 "./marpa.w"

/*43:*/
#line 515 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symbol_id,
struct marpa_symbol*symbol)
{
g_array_insert_val(g->symbols,symbol_id,symbol);
}

/*:43*//*53:*/
#line 563 "./marpa.w"

static inline
void marpa_g_rule_add(
struct marpa_g*g,
Marpa_Rule_ID rule_id,
struct marpa_rule*rule)
{
g_array_insert_val(g->rules,rule_id,rule);
}

/*:53*/
#line 1564 "./marpa.w"

/*20:*/
#line 396 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:20*//*25:*/
#line 450 "./marpa.w"

void marpa_g_init(struct marpa_g*g)
{if(g==(void*)NULL){
g_error("E_NULL_R Cannot initialize null grammar");
}
/*33:*/
#line 479 "./marpa.w"

g->id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:33*//*37:*/
#line 491 "./marpa.w"

g->symbols= g_array_new(FALSE,FALSE,sizeof(struct marpa_symbol*));
/*:37*//*47:*/
#line 539 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(struct marpa_rule*));
/*:47*/
#line 455 "./marpa.w"

return;}
/*:25*//*27:*/
#line 460 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g)
{/*38:*/
#line 493 "./marpa.w"
g_array_free(g->symbols,TRUE);

/*:38*//*48:*/
#line 541 "./marpa.w"
g_array_free(g->rules,TRUE);

/*:48*//*64:*/
#line 629 "./marpa.w"

{int id;for(id= 0;id<g->symbols->len;id++)
{marpa_symbol_free(symbol_id2p(g,id));}}
/*:64*//*159:*/
#line 1104 "./marpa.w"

{int id;for(id= 0;id<g->rules->len;id++)
{marpa_rule_free(rule_id2p(g,id));}}
/*:159*/
#line 462 "./marpa.w"
}
/*:27*//*34:*/
#line 481 "./marpa.w"

gint marpa_grammar_id_value(struct marpa_g*g){return g->id;}
/*:34*//*39:*/
#line 498 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:39*//*41:*/
#line 505 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id)
{return((struct marpa_symbol**)g->symbols->data)[id];}
/*:41*//*44:*/
#line 526 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id){
return symbol_id<g->symbols->len&&symbol_id>=0;
}
/*:44*//*49:*/
#line 546 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:49*//*51:*/
#line 553 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id)
{return((struct marpa_rule**)g->rules->data)[id];}
/*:51*//*55:*/
#line 581 "./marpa.w"

void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

return;

}

/*:55*//*57:*/
#line 594 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce){}
/*:57*//*61:*/
#line 609 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*68:*/
#line 640 "./marpa.w"
symbol->id= g->symbols->len;

/*:68*//*70:*/
#line 648 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:70*//*78:*/
#line 680 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:78*//*86:*/
#line 708 "./marpa.w"

symbol->is_accessible= FALSE;
/*:86*//*92:*/
#line 734 "./marpa.w"

symbol->is_counted= FALSE;
/*:92*//*98:*/
#line 760 "./marpa.w"

symbol->is_nullable= FALSE;
/*:98*//*104:*/
#line 785 "./marpa.w"

symbol->is_nulling= FALSE;
/*:104*//*110:*/
#line 810 "./marpa.w"

symbol->is_terminal= FALSE;
/*:110*//*116:*/
#line 836 "./marpa.w"

symbol->is_productive= FALSE;
/*:116*//*122:*/
#line 861 "./marpa.w"
symbol->is_start= FALSE;
/*:122*//*130:*/
#line 901 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:130*/
#line 613 "./marpa.w"

{Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);}
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;}

/*:61*//*65:*/
#line 632 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol)
{/*71:*/
#line 650 "./marpa.w"
g_array_free(symbol->lhs,TRUE);
/*:71*//*79:*/
#line 682 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:79*/
#line 634 "./marpa.w"
g_free(symbol);}
/*:65*//*72:*/
#line 659 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->lhs;}
/*:72*//*74:*/
#line 664 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:74*//*80:*/
#line 691 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->rhs;}
/*:80*//*82:*/
#line 696 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
void marpa_symbol_rhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_rhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:82*//*87:*/
#line 718 "./marpa.w"

gboolean marpa_symbol_is_accessible_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:87*//*89:*/
#line 724 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:89*//*93:*/
#line 744 "./marpa.w"

gboolean marpa_symbol_is_counted_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:93*//*95:*/
#line 750 "./marpa.w"

void marpa_symbol_is_counted_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_counted= value;}
/*:95*//*99:*/
#line 770 "./marpa.w"

gboolean marpa_symbol_is_nullable_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:99*//*101:*/
#line 776 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:101*//*105:*/
#line 795 "./marpa.w"

gboolean marpa_symbol_is_nulling_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nulling;}
/*:105*//*107:*/
#line 801 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:107*//*111:*/
#line 820 "./marpa.w"

gboolean marpa_symbol_is_terminal_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:111*//*113:*/
#line 826 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:113*//*117:*/
#line 846 "./marpa.w"

gboolean marpa_symbol_is_productive_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:117*//*119:*/
#line 852 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value;}
/*:119*//*123:*/
#line 869 "./marpa.w"

static inline
gboolean symbol_is_start_value(struct marpa_symbol*symbol)
{return symbol->is_start;}
gboolean marpa_symbol_is_start_value(struct marpa_g*g,Marpa_Symbol_ID id){
return symbol_is_start_value(symbol_id2p(g,id));
}
/*:123*//*126:*/
#line 882 "./marpa.w"

void marpa_symbol_is_start_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_start= value;}
/*:126*//*131:*/
#line 912 "./marpa.w"

static inline
struct marpa_symbol*symbol_proper_alias_value(struct marpa_symbol*symbol)
{return symbol->is_proper_alias?symbol:
symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
struct marpa_symbol*proper_alias= symbol_proper_alias_value(symbol);
return proper_alias==NULL?-1:proper_alias->id;
}
/*:131*//*134:*/
#line 934 "./marpa.w"

static inline
struct marpa_symbol*symbol_null_alias_value(struct marpa_symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:
symbol->is_nulling_alias?symbol:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
struct marpa_symbol*alias= symbol_null_alias_value(symbol);
return alias==NULL?-1:alias->id;
}
/*:134*//*137:*/
#line 959 "./marpa.w"
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
alias->is_productive= symbol->is_productive;
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
/*:137*//*143:*/
#line 1003 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->symbol_callback_arg= cb_arg;}
void*marpa_symbol_callback_arg_peek(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:143*//*145:*/
#line 1015 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:145*//*150:*/
#line 1033 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->rule_callback_arg= cb_arg;}
void*marpa_rule_callback_arg_peek(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:150*//*152:*/
#line 1045 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:152*//*156:*/
#line 1068 "./marpa.w"

static inline
struct marpa_rule*rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
int i;
struct marpa_rule*rule;
/*169:*/
#line 1228 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{int i;for(i= 0;i<length;i++){
if(!symbol_is_valid(g,rhs[i])){return NULL;}
}}
/*:169*/
#line 1075 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*170:*/
#line 1233 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{int i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:170*/
#line 1077 "./marpa.w"

/*175:*/
#line 1267 "./marpa.w"
rule->id= g->rules->len;

/*:175*//*177:*/
#line 1271 "./marpa.w"

rule->is_accessible= FALSE;
/*:177*/
#line 1078 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*162:*/
#line 1124 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const gint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*166:*/
#line 1191 "./marpa.w"

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

/*:166*/
#line 1132 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
symbol_id2p(g,rh_symbol_list[rh_list_ix]),
rule->id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:162*/
#line 1080 "./marpa.w"

return rule;
}
Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
Marpa_Rule_ID rule_id;
struct marpa_rule*rule= rule_new(g,lhs,rhs,length);
if(!rule){return-1;}
return rule->id;
}
void marpa_rule_complete(struct marpa_g*g,Marpa_Rule_ID id)
{
rule_callback(g,id);
}
/*:156*//*160:*/
#line 1108 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule)
{

g_free(rule);}
/*:160*//*171:*/
#line 1238 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_lhs_get(rule_id2p(g,rule_id));}
static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_rhs_get(rule_id2p(g,rule_id));}
static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
gsize marpa_rule_length_value(struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_length_get(rule_id2p(g,rule_id));}
static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,gint index){
return rule->symbols[index+1];
}
/*:171*//*178:*/
#line 1281 "./marpa.w"

gboolean marpa_rule_is_accessible_value(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_accessible;}
/*:178*//*180:*/
#line 1287 "./marpa.w"

void marpa_rule_is_accessible_set(
struct marpa_g*g,Marpa_Rule_ID id,gboolean value)
{rule_id2p(g,id)->is_accessible= value;}
/*:180*//*183:*/
#line 1326 "./marpa.w"
MARPA_SHIM
struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:183*//*185:*/
#line 1334 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:185*//*191:*/
#line 1363 "./marpa.w"



const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
int marpa_effective_micro= 1000*MARPA_MINOR_VERSION+MARPA_MICRO_VERSION;
int required_effective_micro= 1000*required_minor+required_micro;
static char output_buffer[1000];

/*193:*/
#line 1393 "./marpa.w"


if(required_major> MARPA_MAJOR_VERSION){
sprintf(output_buffer,"marpa major version too old: "
"require %d.%03d%03d, but have %d.%03d%03d",
required_major,
required_minor,
required_micro,
MARPA_MAJOR_VERSION,
MARPA_MINOR_VERSION,
MARPA_MICRO_VERSION);
return output_buffer;
}

/*:193*/
#line 1375 "./marpa.w"

/*194:*/
#line 1409 "./marpa.w"


if(required_major<MARPA_MAJOR_VERSION){
sprintf(output_buffer,
"marpa major version too new: "
"require %d.%03d%03d, but have %d.%03d%03d",
required_major,
required_minor,
required_micro,
MARPA_MAJOR_VERSION,
MARPA_MINOR_VERSION,
MARPA_MICRO_VERSION);
return output_buffer;
}


/*:194*/
#line 1376 "./marpa.w"

/*195:*/
#line 1427 "./marpa.w"


if(required_effective_micro<marpa_effective_micro){
sprintf(output_buffer,
"marpa minor/micro version too new: "
"require %d.%03d%03d, but have %d.%03d%03d",
required_major,
required_minor,
required_micro,
MARPA_MAJOR_VERSION,
MARPA_MINOR_VERSION,
MARPA_MICRO_VERSION);
return output_buffer;
}


/*:195*/
#line 1377 "./marpa.w"

/*196:*/
#line 1445 "./marpa.w"

if(required_effective_micro> marpa_effective_micro){
sprintf(
output_buffer,
"marpa minor/micro version too old: "
"require %d.%03d%03d, but have %d.%03d%03d",
required_major,
required_minor,
required_micro,
MARPA_MAJOR_VERSION,
MARPA_MINOR_VERSION,
MARPA_MICRO_VERSION);
return output_buffer;
}

/*:196*/
#line 1378 "./marpa.w"


return"Perfect!";
}

/*:191*/
#line 1565 "./marpa.w"





/*:203*/
