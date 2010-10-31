/*177:*/
#line 1357 "./marpa.w"

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

#line 1391 "./marpa.w"

/*163:*/
#line 1182 "./marpa.w"


#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:163*/
#line 1392 "./marpa.w"

/*20:*/
#line 399 "./marpa.w"


const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;

/*:20*/
#line 1393 "./marpa.w"

/*18:*/
#line 393 "./marpa.w"


/*:18*//*54:*/
#line 615 "./marpa.w"

struct marpa_symbol{
/*63:*/
#line 660 "./marpa.w"
GArray*lhs;
/*:63*//*71:*/
#line 692 "./marpa.w"
GArray*rhs;
/*:71*//*123:*/
#line 912 "./marpa.w"

struct marpa_symbol*alias;
/*:123*/
#line 617 "./marpa.w"

/*61:*/
#line 652 "./marpa.w"
Marpa_Symbol_ID id;
/*:61*/
#line 618 "./marpa.w"

/*79:*/
#line 720 "./marpa.w"
unsigned int is_accessible:1;
/*:79*//*85:*/
#line 746 "./marpa.w"
unsigned int is_counted:1;
/*:85*//*91:*/
#line 772 "./marpa.w"
unsigned int is_nullable:1;
/*:91*//*97:*/
#line 797 "./marpa.w"
unsigned int is_nulling:1;
/*:97*//*103:*/
#line 822 "./marpa.w"
unsigned int is_terminal:1;
/*:103*//*109:*/
#line 848 "./marpa.w"
unsigned int is_productive:1;
/*:109*//*115:*/
#line 873 "./marpa.w"
unsigned int is_start:1;
/*:115*//*122:*/
#line 909 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:122*/
#line 619 "./marpa.w"

};

/*:54*//*134:*/
#line 1006 "./marpa.w"

struct marpa_rule{
/*141:*/
#line 1061 "./marpa.w"
gsize length;
/*:141*/
#line 1008 "./marpa.w"


/*148:*/
#line 1098 "./marpa.w"
Marpa_Rule_ID id;
/*:148*/
#line 1010 "./marpa.w"

/*150:*/
#line 1102 "./marpa.w"
unsigned int is_accessible:1;
/*:150*/
#line 1011 "./marpa.w"

/*142:*/
#line 1064 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:142*/
#line 1012 "./marpa.w"

};
static inline gsize rule_sizeof(length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}

/*:134*/
#line 1394 "./marpa.w"

/*36:*/
#line 522 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id);

/*:36*//*39:*/
#line 544 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:39*//*46:*/
#line 570 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id);

/*:46*//*56:*/
#line 636 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:56*//*60:*/
#line 648 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol);

/*:60*//*69:*/
#line 682 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);
/*:69*//*77:*/
#line 714 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);
/*:77*//*118:*/
#line 889 "./marpa.w"

static inline
gboolean symbol_is_start_value(struct marpa_symbol*symbol);
/*:118*//*126:*/
#line 936 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias_value(struct marpa_symbol*symbol);
/*:126*//*129:*/
#line 958 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias_value(struct marpa_symbol*symbol);
/*:129*//*136:*/
#line 1038 "./marpa.w"

static inline
struct marpa_rule*rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:136*//*140:*/
#line 1055 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule);

/*:140*//*146:*/
#line 1088 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
static inline gsize rule_length_get(struct marpa_rule*rule);
/*:146*/
#line 1395 "./marpa.w"

/*37:*/
#line 528 "./marpa.w"

static inline
void marpa_g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symbol_id,
struct marpa_symbol*symbol)
{
g_array_insert_val(g->symbols,symbol_id,symbol);
}

/*:37*//*47:*/
#line 576 "./marpa.w"

static inline
void marpa_g_rule_add(
struct marpa_g*g,
Marpa_Rule_ID rule_id,
struct marpa_rule*rule)
{
g_array_insert_val(g->rules,rule_id,rule);
}

/*:47*/
#line 1396 "./marpa.w"

/*21:*/
#line 409 "./marpa.w"


void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}

/*:21*//*26:*/
#line 484 "./marpa.w"

void marpa_g_init(struct marpa_g*g)
{if(g==(void*)NULL){
g_error("E_NULL_R Cannot initialize null grammar");
}
/*31:*/
#line 504 "./marpa.w"

g->symbols= g_array_new(FALSE,FALSE,sizeof(struct marpa_symbol*));
/*:31*//*41:*/
#line 552 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(struct marpa_rule*));
/*:41*/
#line 489 "./marpa.w"

return;}
/*:26*//*28:*/
#line 494 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g)
{/*32:*/
#line 506 "./marpa.w"
g_array_free(g->symbols,TRUE);

/*:32*//*42:*/
#line 554 "./marpa.w"
g_array_free(g->rules,TRUE);

/*:42*//*58:*/
#line 642 "./marpa.w"

{int id;for(id= 0;id<g->symbols->len;id++)
{marpa_symbol_free(symbol_id2p(g,id));}}
/*:58*//*138:*/
#line 1046 "./marpa.w"

{int id;for(id= 0;id<g->rules->len;id++)
{marpa_rule_free(rule_id2p(g,id));}}
/*:138*/
#line 496 "./marpa.w"
}
/*:28*//*33:*/
#line 511 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:33*//*35:*/
#line 518 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id)
{return((struct marpa_symbol**)g->symbols->data)[id];}
/*:35*//*38:*/
#line 539 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id){
return symbol_id<g->symbols->len&&symbol_id>=0;
}
/*:38*//*43:*/
#line 559 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:43*//*45:*/
#line 566 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id)
{return((struct marpa_rule**)g->rules->data)[id];}
/*:45*//*49:*/
#line 594 "./marpa.w"

void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

return;

}

/*:49*//*51:*/
#line 607 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce){}
/*:51*//*55:*/
#line 622 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{
struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*62:*/
#line 653 "./marpa.w"
symbol->id= g->symbols->len;

/*:62*//*64:*/
#line 661 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:64*//*72:*/
#line 693 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:72*//*80:*/
#line 721 "./marpa.w"

symbol->is_accessible= FALSE;
/*:80*//*86:*/
#line 747 "./marpa.w"

symbol->is_counted= FALSE;
/*:86*//*92:*/
#line 773 "./marpa.w"

symbol->is_nullable= FALSE;
/*:92*//*98:*/
#line 798 "./marpa.w"

symbol->is_nulling= FALSE;
/*:98*//*104:*/
#line 823 "./marpa.w"

symbol->is_terminal= FALSE;
/*:104*//*110:*/
#line 849 "./marpa.w"

symbol->is_productive= FALSE;
/*:110*//*116:*/
#line 874 "./marpa.w"
symbol->is_start= FALSE;
/*:116*//*124:*/
#line 914 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:124*/
#line 627 "./marpa.w"

marpa_g_symbol_add(g,symbol->id,symbol);
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{
return symbol_new(g)->id;
}

/*:55*//*59:*/
#line 645 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol)
{/*65:*/
#line 663 "./marpa.w"
g_array_free(symbol->lhs,TRUE);
/*:65*//*73:*/
#line 695 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:73*/
#line 647 "./marpa.w"
g_free(symbol);}
/*:59*//*66:*/
#line 672 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->lhs;}
/*:66*//*68:*/
#line 677 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:68*//*74:*/
#line 704 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->rhs;}
/*:74*//*76:*/
#line 709 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
void marpa_symbol_rhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_rhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:76*//*81:*/
#line 731 "./marpa.w"

gboolean marpa_symbol_is_accessible_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:81*//*83:*/
#line 737 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:83*//*87:*/
#line 757 "./marpa.w"

gboolean marpa_symbol_is_counted_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:87*//*89:*/
#line 763 "./marpa.w"

void marpa_symbol_is_counted_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_counted= value;}
/*:89*//*93:*/
#line 783 "./marpa.w"

gboolean marpa_symbol_is_nullable_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:93*//*95:*/
#line 789 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:95*//*99:*/
#line 808 "./marpa.w"

gboolean marpa_symbol_is_nulling_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nulling;}
/*:99*//*101:*/
#line 814 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:101*//*105:*/
#line 833 "./marpa.w"

gboolean marpa_symbol_is_terminal_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:105*//*107:*/
#line 839 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:107*//*111:*/
#line 859 "./marpa.w"

gboolean marpa_symbol_is_productive_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:111*//*113:*/
#line 865 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value;}
/*:113*//*117:*/
#line 882 "./marpa.w"

static inline
gboolean symbol_is_start_value(struct marpa_symbol*symbol)
{return symbol->is_start;}
gboolean marpa_symbol_is_start_value(struct marpa_g*g,Marpa_Symbol_ID id){
return symbol_is_start_value(symbol_id2p(g,id));
}
/*:117*//*120:*/
#line 895 "./marpa.w"

void marpa_symbol_is_start_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_start= value;}
/*:120*//*125:*/
#line 925 "./marpa.w"

static inline
struct marpa_symbol*symbol_proper_alias_value(struct marpa_symbol*symbol)
{return symbol->is_proper_alias?symbol:
symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias_value(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
struct marpa_symbol*alias= symbol_proper_alias_value(symbol);
return alias==NULL?-1:alias->id;
}
/*:125*//*128:*/
#line 947 "./marpa.w"

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
/*:128*//*131:*/
#line 972 "./marpa.w"

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
struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
if(symbol_id<0){return-1;}
if(symbol_id>=g->symbols->len){return-1;}
return symbol_alias_create(g,symbol_id2p(g,symbol_id))->id;
}
/*:131*//*135:*/
#line 1018 "./marpa.w"

static inline
struct marpa_rule*rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
struct marpa_rule*rule;
/*143:*/
#line 1065 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{int i;for(i= 0;i<length;i++){
if(!symbol_is_valid(g,rhs[i])){return NULL;}
}}
/*:143*/
#line 1024 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*144:*/
#line 1070 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{int i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:144*/
#line 1026 "./marpa.w"

/*149:*/
#line 1099 "./marpa.w"
rule->id= g->rules->len;

/*:149*//*151:*/
#line 1103 "./marpa.w"

rule->is_accessible= FALSE;
/*:151*/
#line 1027 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
return rule;
}
Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
struct marpa_rule*rule= rule_new(g,lhs,rhs,length);
return rule==NULL?-1:rule->id;
}

/*:135*//*139:*/
#line 1050 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule)
{

g_free(rule);}
/*:139*//*145:*/
#line 1075 "./marpa.w"

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
/*:145*//*152:*/
#line 1113 "./marpa.w"

gboolean marpa_rule_is_accessible_value(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_accessible;}
/*:152*//*154:*/
#line 1119 "./marpa.w"

void marpa_rule_is_accessible_set(
struct marpa_g*g,Marpa_Rule_ID id,gboolean value)
{rule_id2p(g,id)->is_accessible= value;}
/*:154*//*157:*/
#line 1158 "./marpa.w"
MARPA_SHIM
struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:157*//*159:*/
#line 1166 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:159*//*165:*/
#line 1195 "./marpa.w"



const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
int marpa_effective_micro= 1000*MARPA_MINOR_VERSION+MARPA_MICRO_VERSION;
int required_effective_micro= 1000*required_minor+required_micro;
static char output_buffer[1000];

/*167:*/
#line 1225 "./marpa.w"


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

/*:167*/
#line 1207 "./marpa.w"

/*168:*/
#line 1241 "./marpa.w"


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


/*:168*/
#line 1208 "./marpa.w"

/*169:*/
#line 1259 "./marpa.w"


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


/*:169*/
#line 1209 "./marpa.w"

/*170:*/
#line 1277 "./marpa.w"

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

/*:170*/
#line 1210 "./marpa.w"


return"Perfect!";
}

/*:165*/
#line 1397 "./marpa.w"





/*:177*/
