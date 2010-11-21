/*378:*/
#line 2806 "./marpa.w"

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
#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DEFINE(name,type) struct{gint ix;type*base;}name;
#define FSTACK_INIT(name,type,n) ((name.ix= 0) ,(name.base= g_new(type,n) ) ) 
#define FSTACK_PUSH(name) (name.base+name.ix++) 
#define FSTACK_POP(name) (--name.ix<0?NULL:name.base+name.ix) 
#define FSTACK_DESTROY(name) (g_free(name.base) )  \

#define DSTACK_INITIAL_SIZE 2
#define DSTACK_DEFINE(this,type) struct dstack this;
#define DSTACK_INIT(this,type)  \
((this.ix= 0) ,(this.size= DSTACK_INITIAL_SIZE) , \
(this.base= g_new(type,DSTACK_INITIAL_SIZE) ) ) 
#define DSTACK_PUSH(stack_name,type)  \
((type*) (this.ix>=this.size \
?(dstack_resize(&this,sizeof(type) ) +this.ix++)  \
:(this.base+this.ix++) ) ) 
#define DSTACK_POP(this,type) (--this.ix<0?NULL:(type*) this.base+this.ix) 
#define DSTACK_DESTROY(this) (g_free(this.base) )  \


#line 2840 "./marpa.w"

/*357:*/
#line 2574 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:357*/
#line 2841 "./marpa.w"

/*310:*/
#line 2154 "./marpa.w"

typedef guint Bit_Vector_Piece;
typedef Bit_Vector_Piece*Bit_Vector;
/*:310*/
#line 2842 "./marpa.w"

/*17:*/
#line 396 "./marpa.w"

const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;
/*:17*//*30:*/
#line 487 "./marpa.w"
static gint next_grammar_id= 1;
/*:30*//*311:*/
#line 2161 "./marpa.w"

static const int bv_wordbits= sizeof(Bit_Vector_Piece)*8u;
static const int bv_modmask= sizeof(Bit_Vector_Piece)*8u-1u;
static const int bv_hiddenwords= 3;
static const int bv_lsb= 1u;
static const int bv_msb= (1u<<(sizeof(Bit_Vector_Piece)*8u-1u));

/*:311*/
#line 2843 "./marpa.w"

/*91:*/
#line 776 "./marpa.w"

struct marpa_symbol{
/*100:*/
#line 821 "./marpa.w"
GArray*lhs;
/*:100*//*108:*/
#line 853 "./marpa.w"
GArray*rhs;
/*:108*//*158:*/
#line 1065 "./marpa.w"

struct marpa_symbol*alias;
/*:158*/
#line 778 "./marpa.w"

/*98:*/
#line 813 "./marpa.w"
Marpa_Symbol_ID id;
/*:98*/
#line 779 "./marpa.w"

/*116:*/
#line 881 "./marpa.w"
unsigned int is_accessible:1;
/*:116*//*122:*/
#line 907 "./marpa.w"
unsigned int is_counted:1;
/*:122*//*126:*/
#line 925 "./marpa.w"
unsigned int is_nullable:1;
/*:126*//*132:*/
#line 950 "./marpa.w"
unsigned int is_nulling:1;
/*:132*//*138:*/
#line 975 "./marpa.w"
unsigned int is_terminal:1;
/*:138*//*144:*/
#line 1001 "./marpa.w"
unsigned int is_productive:1;
/*:144*//*150:*/
#line 1026 "./marpa.w"
unsigned int is_start:1;
/*:150*//*157:*/
#line 1062 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:157*/
#line 780 "./marpa.w"

};

/*:91*//*177:*/
#line 1191 "./marpa.w"

struct marpa_rule{
/*212:*/
#line 1591 "./marpa.w"
gsize length;
/*:212*/
#line 1193 "./marpa.w"


/*232:*/
#line 1652 "./marpa.w"
Marpa_Rule_ID id;
/*:232*//*270:*/
#line 1810 "./marpa.w"
Marpa_Rule_ID original;
/*:270*//*274:*/
#line 1822 "./marpa.w"
gint real_symbol_count;
/*:274*/
#line 1195 "./marpa.w"

/*235:*/
#line 1664 "./marpa.w"
unsigned int is_discard:1;
/*:235*//*246:*/
#line 1723 "./marpa.w"
unsigned int is_used:1;
/*:246*//*250:*/
#line 1750 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:250*//*254:*/
#line 1761 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:254*//*277:*/
#line 1829 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:277*/
#line 1196 "./marpa.w"

/*213:*/
#line 1594 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:213*/
#line 1197 "./marpa.w"

};
/*:177*//*352:*/
#line 2544 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:352*/
#line 2844 "./marpa.w"

/*40:*/
#line 517 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g);

/*:40*//*42:*/
#line 525 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id);

/*:42*//*45:*/
#line 547 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id);

/*:45*//*52:*/
#line 573 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id);

/*:52*//*72:*/
#line 689 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:72*//*74:*/
#line 701 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:74*//*76:*/
#line 710 "./marpa.w"

static inline void context_clear(struct marpa_g*g);

/*:76*//*93:*/
#line 797 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:93*//*97:*/
#line 809 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol);

/*:97*//*106:*/
#line 843 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);
/*:106*//*114:*/
#line 875 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);
/*:114*//*153:*/
#line 1042 "./marpa.w"

static inline
gboolean symbol_is_start_value(struct marpa_symbol*symbol);
/*:153*//*161:*/
#line 1089 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias_value(struct marpa_symbol*symbol);
/*:161*//*164:*/
#line 1111 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias_value(struct marpa_symbol*symbol);
/*:164*//*167:*/
#line 1150 "./marpa.w"

static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
/*:167*//*175:*/
#line 1185 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:175*//*179:*/
#line 1203 "./marpa.w"

static inline gsize rule_sizeof(gint length);

/*:179*//*200:*/
#line 1452 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length);

/*:200*//*201:*/
#line 1457 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:201*//*211:*/
#line 1583 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule);

/*:211*//*217:*/
#line 1608 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:217*//*221:*/
#line 1618 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:221*//*225:*/
#line 1628 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:225*//*229:*/
#line 1639 "./marpa.w"

static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule*rule);
/*:229*//*231:*/
#line 1646 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,gint index);

/*:231*//*268:*/
#line 1803 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:268*//*313:*/
#line 2174 "./marpa.w"

static inline guint bv_bits_to_size(gint bits);
/*:313*//*315:*/
#line 2184 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits);

/*:315*//*317:*/
#line 2204 "./marpa.w"

static inline Bit_Vector bv_create(gint bits);

/*:317*//*319:*/
#line 2215 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:319*//*321:*/
#line 2237 "./marpa.w"

Bit_Vector bv_clone(Bit_Vector bv);

/*:321*//*323:*/
#line 2246 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:323*//*325:*/
#line 2258 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:325*//*328:*/
#line 2266 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit);

/*:328*//*330:*/
#line 2274 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit);

/*:330*//*332:*/
#line 2282 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit);
/*:332*//*335:*/
#line 2297 "./marpa.w"

gboolean bv_is_empty(Bit_Vector addr);

/*:335*//*337:*/
#line 2309 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:337*//*339:*/
#line 2321 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:339*//*341:*/
#line 2333 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:341*//*343:*/
#line 2406 "./marpa.w"

gboolean BitVector_scan(Bit_Vector bv,gint start,
gint*min,gint*max);

/*:343*//*349:*/
#line 2487 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:349*//*354:*/
#line 2552 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:354*//*364:*/
#line 2633 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id);

/*:364*/
#line 2845 "./marpa.w"

/*43:*/
#line 531 "./marpa.w"

static inline
void g_symbol_add(
struct marpa_g*g,
Marpa_Symbol_ID symbol_id,
struct marpa_symbol*symbol)
{
g_array_insert_val(g->symbols,symbol_id,symbol);
}

/*:43*//*53:*/
#line 579 "./marpa.w"

static inline
void marpa_g_rule_add(
struct marpa_g*g,
Marpa_Rule_ID rule_id,
struct marpa_rule*rule)
{
g_array_insert_val(g->rules,rule_id,rule);
}

/*:53*/
#line 2846 "./marpa.w"

/*18:*/
#line 403 "./marpa.w"

void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}
/*:18*//*23:*/
#line 458 "./marpa.w"

void marpa_g_init(struct marpa_g*g)
{if(g==(void*)NULL){
g_error("E_NULL_R Cannot initialize null grammar");
}
/*31:*/
#line 488 "./marpa.w"

g->id= g_atomic_int_exchange_and_add(&next_grammar_id,1);
/*:31*//*35:*/
#line 499 "./marpa.w"

g->symbols= g_array_new(FALSE,FALSE,sizeof(struct marpa_symbol*));
/*:35*//*47:*/
#line 555 "./marpa.w"

g->rules= g_array_new(FALSE,FALSE,sizeof(struct marpa_rule*));
/*:47*//*55:*/
#line 591 "./marpa.w"

g->is_precomputed= FALSE;
/*:55*//*59:*/
#line 606 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:59*//*65:*/
#line 639 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:65*//*81:*/
#line 733 "./marpa.w"

g->error= 0;
/*:81*/
#line 463 "./marpa.w"

return;}
/*:23*//*25:*/
#line 468 "./marpa.w"

void marpa_g_destroy(struct marpa_g*g)
{/*36:*/
#line 501 "./marpa.w"
g_array_free(g->symbols,TRUE);

/*:36*//*48:*/
#line 557 "./marpa.w"
g_array_free(g->rules,TRUE);

/*:48*//*66:*/
#line 641 "./marpa.w"
g_hash_table_destroy(g->context);

/*:66*//*95:*/
#line 803 "./marpa.w"

{int id;for(id= 0;id<g->symbols->len;id++)
{marpa_symbol_free(symbol_id2p(g,id));}}
/*:95*//*209:*/
#line 1574 "./marpa.w"

{int id;for(id= 0;id<g->rules->len;id++)
{marpa_rule_free(rule_id2p(g,id));}}
/*:209*/
#line 470 "./marpa.w"
}
/*:25*//*32:*/
#line 490 "./marpa.w"

gint marpa_grammar_id_value(struct marpa_g*g){return g->id;}
/*:32*//*37:*/
#line 506 "./marpa.w"

GArray*marpa_g_symbols_peek(struct marpa_g*g)
{return g->symbols;}
/*:37*//*39:*/
#line 513 "./marpa.w"

static inline gint symbol_count(struct marpa_g*g){
return g->symbols->len;
}
/*:39*//*41:*/
#line 521 "./marpa.w"

static inline struct marpa_symbol*
symbol_id2p(struct marpa_g*g,Marpa_Symbol_ID id)
{return g_array_index(g->symbols,struct marpa_symbol*,id);}
/*:41*//*44:*/
#line 542 "./marpa.w"

static inline gint symbol_is_valid(
struct marpa_g*g,Marpa_Symbol_ID symbol_id){
return symbol_id<g->symbols->len&&symbol_id>=0;
}
/*:44*//*49:*/
#line 562 "./marpa.w"

GArray*marpa_g_rules_peek(struct marpa_g*g)
{return g->rules;}
/*:49*//*51:*/
#line 569 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id)
{return g_array_index(g->rules,struct marpa_rule*,id);}
/*:51*//*56:*/
#line 594 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{return g->is_precomputed;}
/*:56*//*60:*/
#line 609 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:60*//*62:*/
#line 616 "./marpa.w"

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
/*:62*//*71:*/
#line 680 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:71*//*73:*/
#line 692 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:73*//*75:*/
#line 707 "./marpa.w"

static inline void context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:75*//*77:*/
#line 714 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:77*//*83:*/
#line 741 "./marpa.w"

Marpa_Error_ID marpa_error_value(struct marpa_g*g)
{return g->error?:"unknown error";}
/*:83*//*86:*/
#line 755 "./marpa.w"

void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

return;

}

/*:86*//*88:*/
#line 768 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce){}
/*:88*//*92:*/
#line 783 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*99:*/
#line 814 "./marpa.w"
symbol->id= g->symbols->len;

/*:99*//*101:*/
#line 822 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:101*//*109:*/
#line 854 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:109*//*117:*/
#line 882 "./marpa.w"

symbol->is_accessible= FALSE;
/*:117*//*123:*/
#line 908 "./marpa.w"

symbol->is_counted= FALSE;
/*:123*//*127:*/
#line 926 "./marpa.w"

symbol->is_nullable= FALSE;
/*:127*//*133:*/
#line 951 "./marpa.w"

symbol->is_nulling= FALSE;
/*:133*//*139:*/
#line 976 "./marpa.w"

symbol->is_terminal= FALSE;
/*:139*//*145:*/
#line 1002 "./marpa.w"

symbol->is_productive= FALSE;
/*:145*//*151:*/
#line 1027 "./marpa.w"
symbol->is_start= FALSE;
/*:151*//*159:*/
#line 1067 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:159*/
#line 787 "./marpa.w"

{Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);}
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;}

/*:92*//*96:*/
#line 806 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol)
{/*102:*/
#line 824 "./marpa.w"
g_array_free(symbol->lhs,TRUE);
/*:102*//*110:*/
#line 856 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:110*/
#line 808 "./marpa.w"
g_free(symbol);}
/*:96*//*103:*/
#line 833 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->lhs;}
/*:103*//*105:*/
#line 838 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:105*//*111:*/
#line 865 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->rhs;}
/*:111*//*113:*/
#line 870 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
void marpa_symbol_rhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_rhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:113*//*118:*/
#line 892 "./marpa.w"

gboolean marpa_symbol_is_accessible_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:118*//*120:*/
#line 898 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:120*//*124:*/
#line 918 "./marpa.w"

gboolean marpa_symbol_is_counted_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:124*//*128:*/
#line 936 "./marpa.w"

gboolean marpa_symbol_is_nullable_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:128*//*130:*/
#line 942 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:130*//*134:*/
#line 961 "./marpa.w"

gboolean marpa_symbol_is_nulling_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nulling;}
/*:134*//*136:*/
#line 967 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:136*//*140:*/
#line 986 "./marpa.w"

gboolean marpa_symbol_is_terminal_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:140*//*142:*/
#line 992 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:142*//*146:*/
#line 1012 "./marpa.w"

gboolean marpa_symbol_is_productive_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:146*//*148:*/
#line 1018 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value;}
/*:148*//*152:*/
#line 1035 "./marpa.w"

static inline
gboolean symbol_is_start_value(struct marpa_symbol*symbol)
{return symbol->is_start;}
gboolean marpa_symbol_is_start_value(struct marpa_g*g,Marpa_Symbol_ID id){
return symbol_is_start_value(symbol_id2p(g,id));
}
/*:152*//*155:*/
#line 1048 "./marpa.w"

void marpa_symbol_is_start_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_start= value;}
/*:155*//*160:*/
#line 1078 "./marpa.w"

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
/*:160*//*163:*/
#line 1100 "./marpa.w"

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
/*:163*//*166:*/
#line 1125 "./marpa.w"
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
if(original_id>=g->symbols->len){return-1;}
alias_id= symbol_alias_create(g,symbol_id2p(g,original_id))->id;
symbol_callback(g,alias_id);
return alias_id;}
/*:166*//*172:*/
#line 1169 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->symbol_callback_arg= cb_arg;}
void*marpa_symbol_callback_arg_peek(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:172*//*174:*/
#line 1181 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:174*//*178:*/
#line 1199 "./marpa.w"

static inline gsize rule_sizeof(gint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:178*//*181:*/
#line 1211 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
int i;
struct marpa_rule*rule;
/*214:*/
#line 1595 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{int i;for(i= 0;i<length;i++){
if(!symbol_is_valid(g,rhs[i])){return NULL;}
}}
/*:214*/
#line 1218 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*215:*/
#line 1600 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{int i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:215*/
#line 1220 "./marpa.w"

/*233:*/
#line 1653 "./marpa.w"
rule->id= g->rules->len;

/*:233*//*236:*/
#line 1665 "./marpa.w"

rule->is_discard= FALSE;
/*:236*//*247:*/
#line 1724 "./marpa.w"

rule->is_used= TRUE;
/*:247*//*251:*/
#line 1751 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:251*//*255:*/
#line 1762 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:255*//*271:*/
#line 1811 "./marpa.w"
rule->original= -1;
/*:271*//*275:*/
#line 1823 "./marpa.w"
rule->real_symbol_count= 0;
/*:275*//*278:*/
#line 1830 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:278*/
#line 1221 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*203:*/
#line 1476 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const gint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*207:*/
#line 1543 "./marpa.w"

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

/*:207*/
#line 1484 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
symbol_id2p(g,rh_symbol_list[rh_list_ix]),
rule->id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:203*/
#line 1223 "./marpa.w"

return rule;
}
/*:181*//*182:*/
#line 1226 "./marpa.w"

Marpa_Rule_ID marpa_rule_start_shim(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
struct marpa_rule*rule= rule_start(g,lhs,rhs,length);
if(!rule){return-1;}
return rule->id;
}
/*:182*//*183:*/
#line 1239 "./marpa.w"

void marpa_rule_complete_shim(struct marpa_g*g,Marpa_Rule_ID id)
{
rule_callback(g,id);
}
/*:183*//*184:*/
#line 1244 "./marpa.w"

Marpa_Rule_ID marpa_rule_new(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
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

/*:184*//*185:*/
#line 1261 "./marpa.w"

Marpa_Rule_ID marpa_sequence_new(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
gint min,gint flags)
{
Marpa_Rule_ID original_rule_id;
struct marpa_rule*original_rule;
Marpa_Symbol_ID internal_lhs_id,*temp_rhs;
if(min<0){
g->error= (Marpa_Error_ID)"bad min";
return-1;
}
if(is_rule_duplicate(g,lhs_id,&rhs_id,1)==TRUE){
g->error= (Marpa_Error_ID)"duplicate rule";
return-1;
}

/*188:*/
#line 1300 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*187:*/
#line 1298 "./marpa.w"
g->error= "internal_error";return-1;
/*:187*/
#line 1302 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:188*/
#line 1278 "./marpa.w"

/*189:*/
#line 1306 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:189*/
#line 1279 "./marpa.w"

/*190:*/
#line 1310 "./marpa.w"

symbol_id2p(g,rhs_id)->is_counted= 1;
if(separator_id>=0){symbol_id2p(g,separator_id)->is_counted= 1;}
/*:190*/
#line 1280 "./marpa.w"

if(min==0){/*191:*/
#line 1313 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*187:*/
#line 1298 "./marpa.w"
g->error= "internal_error";return-1;
/*:187*/
#line 1315 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:191*/
#line 1281 "./marpa.w"
}
min= 1;
/*192:*/
#line 1320 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:192*/
#line 1283 "./marpa.w"

/*193:*/
#line 1323 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,MAX(2,(1+(separator_id<0?1:2)*(min-1))));
/*:193*/
#line 1284 "./marpa.w"

/*195:*/
#line 1326 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*187:*/
#line 1298 "./marpa.w"
g->error= "internal_error";return-1;
/*:187*/
#line 1330 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:195*/
#line 1285 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*196:*/
#line 1339 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*187:*/
#line 1298 "./marpa.w"
g->error= "internal_error";return-1;
/*:187*/
#line 1344 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:196*/
#line 1287 "./marpa.w"

}
/*197:*/
#line 1356 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*187:*/
#line 1298 "./marpa.w"
g->error= "internal_error";return-1;
/*:187*/
#line 1366 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:197*/
#line 1289 "./marpa.w"

/*198:*/
#line 1371 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*187:*/
#line 1298 "./marpa.w"
g->error= "internal_error";return-1;
/*:187*/
#line 1378 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:198*/
#line 1290 "./marpa.w"

/*194:*/
#line 1325 "./marpa.w"
g_free(temp_rhs);
/*:194*/
#line 1291 "./marpa.w"

return original_rule_id;
}
/*:185*//*199:*/
#line 1428 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length)
{
gint ix;
struct marpa_symbol*lhs= symbol_id2p(g,lhs_id);
GArray*same_lhs_array= lhs->lhs;
gint same_lhs_count= same_lhs_array->len;
for(ix= 0;ix<same_lhs_count;ix++){
Marpa_Rule_ID same_lhs_rule_id= ((Marpa_Rule_ID*)(same_lhs_array->data))[ix];
gint rhs_position;
struct marpa_rule*rule= rule_id2p(g,same_lhs_rule_id);
if(rule->length!=length){goto rule_is_not_duplicate;}
for(rhs_position= 0;rhs_position<rule->length;rhs_position++){
if(rhs_symbol_id(rule,rhs_position)!=rhs_ids[rhs_position]){
goto rule_is_not_duplicate;
}
}
return TRUE;
rule_is_not_duplicate:;
}
return FALSE;
}
/*:199*//*210:*/
#line 1578 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule)
{

g_free(rule);}
/*:210*//*216:*/
#line 1605 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
/*:216*//*218:*/
#line 1610 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_lhs_get(rule_id2p(g,rule_id));}
/*:218*//*220:*/
#line 1615 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:220*//*222:*/
#line 1620 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_rhs_get(rule_id2p(g,rule_id));}
/*:222*//*224:*/
#line 1625 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:224*//*226:*/
#line 1630 "./marpa.w"

gsize marpa_rule_length_value(struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_length_get(rule_id2p(g,rule_id));}
/*:226*//*228:*/
#line 1636 "./marpa.w"

static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule*rule){return rule->symbols[0];}
/*:228*//*230:*/
#line 1641 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,gint index){
return rule->symbols[index+1];
}
/*:230*//*237:*/
#line 1667 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:237*//*241:*/
#line 1700 "./marpa.w"

gboolean marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID id)
{struct marpa_rule*rule= rule_id2p(g,id);
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
return symbol_id2p(g,lhs_id)->is_accessible;}
/*:241*//*244:*/
#line 1710 "./marpa.w"

gboolean marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID id)
{struct marpa_rule*rule= rule_id2p(g,id);
gint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_productive)return FALSE;
}
return TRUE;}
/*:244*//*248:*/
#line 1728 "./marpa.w"

gboolean marpa_rule_is_used_value(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_used;}
/*:248*//*252:*/
#line 1754 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs_value(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:252*//*256:*/
#line 1765 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs_value(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:256*//*261:*/
#line 1783 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:261*//*263:*/
#line 1788 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:263*//*265:*/
#line 1793 "./marpa.w"

void*marpa_rule_callback_arg_peek(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:265*//*267:*/
#line 1799 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:267*//*272:*/
#line 1812 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}

/*:272*//*276:*/
#line 1824 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}

/*:276*//*279:*/
#line 1841 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent_value(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:279*//*282:*/
#line 1894 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
/*284:*/
#line 1920 "./marpa.w"

gint pre_rewrite_rule_count= g->rules->len;
gint pre_rewrite_symbol_count= g->symbols->len;

/*:284*//*290:*/
#line 1965 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:290*//*296:*/
#line 2023 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:296*//*298:*/
#line 2048 "./marpa.w"

Bit_Vector nullable_v;
/*:298*//*301:*/
#line 2064 "./marpa.w"

Bit_Vector productive_v;
/*:301*/
#line 1897 "./marpa.w"

/*285:*/
#line 1924 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:285*/
#line 1898 "./marpa.w"

/*286:*/
#line 1931 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:286*/
#line 1899 "./marpa.w"

/*287:*/
#line 1936 "./marpa.w"
{;}
{Marpa_Rule_ID rule_id;
lhs_v= bv_create(pre_rewrite_symbol_count);
empty_lhs_v= bv_shadow(lhs_v);
for(rule_id= 0;rule_id<pre_rewrite_rule_count;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
bv_bit_set(lhs_v,lhs_id);
if(rule->length<=0){
bv_bit_set(empty_lhs_v,lhs_id);
have_empty_rule= 1;
}
}
}
/*:287*/
#line 1900 "./marpa.w"

/*288:*/
#line 1953 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symbol_id= 0;symbol_id<pre_rewrite_symbol_count;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_terminal){
bv_bit_set(terminal_v,symbol_id);
have_marked_terminals= 1;
}
}}
/*:288*/
#line 1901 "./marpa.w"

if(have_marked_terminals){
/*292:*/
#line 1980 "./marpa.w"

if(!g->is_lhs_terminal_ok){
gboolean have_bad_lhs= 0;
gint start= 0;
gint min,max;
Bit_Vector bad_lhs_v= bv_clone(terminal_v);
bv_and(bad_lhs_v,bad_lhs_v,lhs_v);
while(bv_scan(bad_lhs_v,start,&min,&max)){
gint i;
for(i= min;i<=max;i++){
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

/*:292*/
#line 1903 "./marpa.w"

}else{
/*291:*/
#line 1969 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:291*/
#line 1905 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*293:*/
#line 2003 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<g->symbols->len;symbol_id++)
{symbol_id2p(g,symbol_id)->is_terminal= 1;}}
/*:293*/
#line 1907 "./marpa.w"

}else{
/*294:*/
#line 2008 "./marpa.w"

{gint start= 0;
gint min,max;
bv_not(terminal_v,lhs_v);
while(bv_scan(terminal_v,start,&min,&max)){
gint symbol_id;
for(symbol_id= min;symbol_id<=max;symbol_id++){
symbol_id2p(g,symbol_id)->is_terminal= 1;
}
start= max+2;
}
}
/*:294*/
#line 1909 "./marpa.w"

}
}
/*297:*/
#line 2028 "./marpa.w"

nullable_v= bv_clone(empty_lhs_v);
rhs_closure(g,nullable_v);
{gint min,max,start,symbol_id;
gint counted_nullables= 0;
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2){
for(symbol_id= min;symbol_id<=max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_counted){
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
/*:297*/
#line 1912 "./marpa.w"

/*300:*/
#line 2053 "./marpa.w"

productive_v= bv_shadow(nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v);
{gint min,max,start,symbol_id;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
for(symbol_id= min;symbol_id<=max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
symbol->is_productive= 1;
}}
}
/*:300*/
#line 1913 "./marpa.w"

/*289:*/
#line 1963 "./marpa.w"

bv_free(terminal_v);
/*:289*//*295:*/
#line 2020 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:295*//*299:*/
#line 2050 "./marpa.w"

bv_free(nullable_v);

/*:299*//*302:*/
#line 2066 "./marpa.w"

bv_free(productive_v);

/*:302*/
#line 1914 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:282*//*305:*/
#line 2128 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:305*//*307:*/
#line 2136 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:307*//*312:*/
#line 2169 "./marpa.w"

static inline guint bv_bits_to_size(gint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:312*//*314:*/
#line 2177 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:314*//*316:*/
#line 2193 "./marpa.w"

static inline Bit_Vector bv_create(gint bits)
{
guint size= bv_bits_to_size(bits);
guint bytes= (size+bv_hiddenwords)<<sizeof(guint);
guint*addr= (Bit_Vector)g_malloc0((size_t)bytes);
*addr++= bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}
/*:316*//*318:*/
#line 2210 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:318*//*320:*/
#line 2222 "./marpa.w"

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
/*:320*//*322:*/
#line 2241 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:322*//*324:*/
#line 2250 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
*(--bv)&= BV_MASK(bv);
}
/*:324*//*327:*/
#line 2262 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:327*//*329:*/
#line 2270 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:329*//*331:*/
#line 2278 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:331*//*334:*/
#line 2286 "./marpa.w"

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
/*:334*//*336:*/
#line 2301 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:336*//*338:*/
#line 2313 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:338*//*340:*/
#line 2325 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:340*//*342:*/
#line 2337 "./marpa.w"

gboolean bv_scan(Bit_Vector bv,gint start,
gint*min,gint*max)
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
bitmask= 1<<(start&bv_modmask);
mask= ~(bitmask|(bitmask-1));
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
/*:342*//*348:*/
#line 2449 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv)
{
gint min,max,start= 0;
FSTACK_DEFINE(stack,Marpa_Symbol_ID);
Marpa_Symbol_ID*top_of_stack= NULL;
FSTACK_INIT(stack,Marpa_Symbol_ID,symbol_count(g));
while(bv_scan(bv,start,&min,&max)){
gint symbol_id;
for(symbol_id= min;symbol_id<=max;symbol_id++){
*(FSTACK_PUSH(stack))= symbol_id;
}
start= max+2;
}
while(top_of_stack= FSTACK_POP(stack)){
gint rule_ix;
GArray*rules= symbol_id2p(g,*top_of_stack)->rhs;
for(rule_ix= 0;rule_ix<rules->len;rule_ix++){
Marpa_Rule_ID rule_id= g_array_index(rules,Marpa_Rule_ID,rule_ix);
struct marpa_rule*rule= rule_id2p(g,rule_id);
gint rule_length;
gint rh_ix;
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
if(bv_bit_test(bv,lhs_id))goto NEXT_RULE;
rule_length= rule->length;
for(rh_ix= 0;rh_ix<rule_length;rh_ix++){
if(!bv_bit_test(bv,rhs_symbol_id(rule,rh_ix)))goto NEXT_RULE;
}



bv_bit_set(bv,lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}
/*:348*//*353:*/
#line 2546 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:353*//*361:*/
#line 2617 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->message_callback_arg= cb_arg;}
void*marpa_message_callback_arg_peek(struct marpa_g*g)
{return g->message_callback_arg;}
/*:361*//*363:*/
#line 2629 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:363*//*366:*/
#line 2644 "./marpa.w"



const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
int marpa_effective_micro= 1000*MARPA_MINOR_VERSION+MARPA_MICRO_VERSION;
int required_effective_micro= 1000*required_minor+required_micro;
static char output_buffer[1000];

/*368:*/
#line 2674 "./marpa.w"


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

/*:368*/
#line 2656 "./marpa.w"

/*369:*/
#line 2690 "./marpa.w"


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


/*:369*/
#line 2657 "./marpa.w"

/*370:*/
#line 2708 "./marpa.w"


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


/*:370*/
#line 2658 "./marpa.w"

/*371:*/
#line 2726 "./marpa.w"

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

/*:371*/
#line 2659 "./marpa.w"


return"Perfect!";
}

/*:366*/
#line 2847 "./marpa.w"





/*:378*/
