/*450:*/
#line 3304 "./marpa.w"

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
#pragma GCC diagnostic warning "-Wmissing-declarations"
#pragma GCC diagnostic warning "-Wconversion"

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
#define DSTACK_PUSH(this,type)  \
((this.ix>=this.size?dstack_resize(&this,sizeof(type) ) :0) , \
((type*) this.base+this.ix++) ) 
#define DSTACK_POP(this,type) (--this.ix,this.ix<0?NULL:(type*) this.base+this.ix) 
#define DSTACK_DESTROY(this) (g_free(this.base) )  \


#line 3340 "./marpa.w"

/*429:*/
#line 3072 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:429*/
#line 3341 "./marpa.w"

/*358:*/
#line 2476 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:358*//*401:*/
#line 2841 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:401*/
#line 3342 "./marpa.w"

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
/*:30*//*359:*/
#line 2483 "./marpa.w"

static const int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const int bv_hiddenwords= 3;
static const int bv_lsb= 1u;
static const int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:359*/
#line 3343 "./marpa.w"

/*113:*/
#line 901 "./marpa.w"

struct marpa_symbol{
/*122:*/
#line 946 "./marpa.w"
GArray*lhs;
/*:122*//*130:*/
#line 978 "./marpa.w"
GArray*rhs;
/*:130*//*180:*/
#line 1192 "./marpa.w"

struct marpa_symbol*alias;
/*:180*/
#line 903 "./marpa.w"

/*120:*/
#line 938 "./marpa.w"
Marpa_Symbol_ID id;
/*:120*/
#line 904 "./marpa.w"

/*138:*/
#line 1006 "./marpa.w"
unsigned int is_accessible:1;
/*:138*//*144:*/
#line 1032 "./marpa.w"
unsigned int is_counted:1;
/*:144*//*148:*/
#line 1050 "./marpa.w"
unsigned int is_nullable:1;
/*:148*//*154:*/
#line 1075 "./marpa.w"
unsigned int is_nulling:1;
/*:154*//*160:*/
#line 1101 "./marpa.w"
unsigned int is_terminal:1;
/*:160*//*166:*/
#line 1127 "./marpa.w"
unsigned int is_productive:1;
/*:166*//*172:*/
#line 1152 "./marpa.w"
unsigned int is_start:1;
/*:172*//*179:*/
#line 1189 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:179*/
#line 905 "./marpa.w"

};

/*:113*//*200:*/
#line 1326 "./marpa.w"

struct marpa_rule{
/*235:*/
#line 1737 "./marpa.w"
gsize length;
/*:235*/
#line 1328 "./marpa.w"


/*255:*/
#line 1798 "./marpa.w"
Marpa_Rule_ID id;
/*:255*//*298:*/
#line 1987 "./marpa.w"
Marpa_Rule_ID original;
/*:298*//*302:*/
#line 1999 "./marpa.w"
gint real_symbol_count;
/*:302*/
#line 1330 "./marpa.w"

/*258:*/
#line 1810 "./marpa.w"
unsigned int is_discard:1;
/*:258*//*274:*/
#line 1900 "./marpa.w"
unsigned int is_used:1;
/*:274*//*278:*/
#line 1927 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:278*//*282:*/
#line 1938 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:282*//*305:*/
#line 2006 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:305*/
#line 1331 "./marpa.w"

/*236:*/
#line 1740 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:236*/
#line 1332 "./marpa.w"

};
/*:200*//*424:*/
#line 3042 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:424*/
#line 3344 "./marpa.w"

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

static inline gint rule_count(struct marpa_g*g);

/*:52*//*54:*/
#line 581 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id);

/*:54*//*57:*/
#line 605 "./marpa.w"

static inline gint rule_is_valid(
struct marpa_g*g,Marpa_Rule_ID rule_id);

/*:57*//*94:*/
#line 815 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:94*//*96:*/
#line 827 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:96*//*98:*/
#line 836 "./marpa.w"

static inline void context_clear(struct marpa_g*g);

/*:98*//*115:*/
#line 922 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:115*//*119:*/
#line 934 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol);

/*:119*//*128:*/
#line 968 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);
/*:128*//*136:*/
#line 1000 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);
/*:136*//*175:*/
#line 1169 "./marpa.w"

static inline
gboolean symbol_is_start_value(struct marpa_symbol*symbol);
/*:175*//*183:*/
#line 1216 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias_value(struct marpa_symbol*symbol);
/*:183*//*186:*/
#line 1238 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias_value(struct marpa_symbol*symbol);
/*:186*//*189:*/
#line 1277 "./marpa.w"

static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
/*:189*//*197:*/
#line 1312 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:197*//*202:*/
#line 1338 "./marpa.w"

static inline gsize rule_sizeof(gint length);

/*:202*//*223:*/
#line 1598 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length);

/*:223*//*224:*/
#line 1603 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:224*//*234:*/
#line 1729 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule);

/*:234*//*240:*/
#line 1754 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:240*//*244:*/
#line 1764 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:244*//*248:*/
#line 1774 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:248*//*252:*/
#line 1785 "./marpa.w"

static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule*rule);
/*:252*//*254:*/
#line 1792 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,gint index);

/*:254*//*265:*/
#line 1857 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule);
/*:265*//*269:*/
#line 1879 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule);
/*:269*//*273:*/
#line 1896 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule);

/*:273*//*296:*/
#line 1980 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:296*//*346:*/
#line 2398 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:346*//*361:*/
#line 2496 "./marpa.w"

static inline guint bv_bits_to_size(gint bits);
/*:361*//*363:*/
#line 2506 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits);

/*:363*//*365:*/
#line 2526 "./marpa.w"

static inline Bit_Vector bv_create(gint bits);

/*:365*//*367:*/
#line 2537 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:367*//*369:*/
#line 2559 "./marpa.w"

Bit_Vector bv_clone(Bit_Vector bv);

/*:369*//*371:*/
#line 2568 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:371*//*373:*/
#line 2576 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:373*//*375:*/
#line 2588 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:375*//*378:*/
#line 2596 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit);

/*:378*//*380:*/
#line 2604 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit);

/*:380*//*382:*/
#line 2612 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit);

/*:382*//*385:*/
#line 2628 "./marpa.w"

gboolean bv_is_empty(Bit_Vector addr);

/*:385*//*387:*/
#line 2640 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:387*//*389:*/
#line 2652 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:389*//*391:*/
#line 2664 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:391*//*393:*/
#line 2737 "./marpa.w"

gboolean BitVector_scan(Bit_Vector bv,gint start,
gint*min,gint*max);

/*:393*//*399:*/
#line 2818 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:399*//*404:*/
#line 2865 "./marpa.w"

static inline Bit_Matrix matrix_create(gint rows,gint columns);

/*:404*//*406:*/
#line 2873 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:406*//*408:*/
#line 2887 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:408*//*410:*/
#line 2905 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,gint row);

/*:410*//*413:*/
#line 2914 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,gint row,gint column);

/*:413*//*416:*/
#line 2923 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,gint row,gint column);

/*:416*//*419:*/
#line 2932 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,gint row,gint column);

/*:419*//*421:*/
#line 2986 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:421*//*426:*/
#line 3050 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:426*//*436:*/
#line 3131 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id);

/*:436*/
#line 3345 "./marpa.w"

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

/*:43*//*55:*/
#line 587 "./marpa.w"

static inline
void marpa_g_rule_add(
struct marpa_g*g,
Marpa_Rule_ID rule_id,
struct marpa_rule*rule)
{
g_array_insert_val(g->rules,rule_id,rule);
g->size+= 1+rule->length;
g->max_rule_length= MAX(rule->length,g->max_rule_length);
}

/*:55*/
#line 3346 "./marpa.w"

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
/*:47*//*59:*/
#line 611 "./marpa.w"

g->start_symbol= -1;
/*:59*//*66:*/
#line 659 "./marpa.w"

g->size= 0;

/*:66*//*69:*/
#line 672 "./marpa.w"

g->max_rule_length= 0;

/*:69*//*71:*/
#line 677 "./marpa.w"

g->is_precomputed= FALSE;
/*:71*//*75:*/
#line 692 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:75*//*81:*/
#line 732 "./marpa.w"

g->is_academic= FALSE;
/*:81*//*87:*/
#line 765 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:87*//*103:*/
#line 858 "./marpa.w"

g->error= 0;
/*:103*/
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

/*:48*//*88:*/
#line 767 "./marpa.w"
g_hash_table_destroy(g->context);

/*:88*//*117:*/
#line 928 "./marpa.w"

{int id;for(id= 0;id<g->symbols->len;id++)
{marpa_symbol_free(symbol_id2p(g,id));}}
/*:117*//*232:*/
#line 1720 "./marpa.w"

{int id;for(id= 0;id<g->rules->len;id++)
{marpa_rule_free(rule_id2p(g,id));}}
/*:232*/
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

static inline gint rule_count(struct marpa_g*g){
return g->rules->len;
}
/*:51*//*53:*/
#line 577 "./marpa.w"

static inline struct marpa_rule*
rule_id2p(struct marpa_g*g,Marpa_Rule_ID id)
{return g_array_index(g->rules,struct marpa_rule*,id);}
/*:53*//*56:*/
#line 600 "./marpa.w"

static inline gint rule_is_valid(
struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_id<g->rules->len&&rule_id>=0;
}
/*:56*//*60:*/
#line 614 "./marpa.w"

gboolean marpa_start_symbol(struct marpa_g*g)
{return g->start_symbol;}
/*:60*//*62:*/
#line 621 "./marpa.w"

gboolean marpa_start_symbol_set(struct marpa_g*g,Marpa_Symbol_ID id)
{
struct marpa_symbol*start;
if(g->is_precomputed){
g->error= "precomputed";
return FALSE;
}
if(!symbol_is_valid(g,id)){
g->error= "invalid start symbol";
return FALSE;
}
g->start_symbol= id;
return TRUE;
}
/*:62*//*72:*/
#line 680 "./marpa.w"

gboolean marpa_is_precomputed(struct marpa_g*g)
{return g->is_precomputed;}
/*:72*//*76:*/
#line 695 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:76*//*78:*/
#line 702 "./marpa.w"

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
/*:78*//*82:*/
#line 735 "./marpa.w"

gboolean marpa_is_academic(struct marpa_g*g)
{return g->is_academic;}
/*:82*//*84:*/
#line 742 "./marpa.w"

gboolean marpa_is_academic_set(
struct marpa_g*g,gboolean value)
{
if(g->is_precomputed){
g->error= "precomputed";
return FALSE;
}
g->is_academic= value;
return TRUE;
}
/*:84*//*93:*/
#line 806 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:93*//*95:*/
#line 818 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:95*//*97:*/
#line 833 "./marpa.w"

static inline void context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:97*//*99:*/
#line 839 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:99*//*105:*/
#line 866 "./marpa.w"

Marpa_Error_ID marpa_error_value(struct marpa_g*g)
{return g->error?:"unknown error";}
/*:105*//*108:*/
#line 880 "./marpa.w"

void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

return;

}

/*:108*//*110:*/
#line 893 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce){}
/*:110*//*114:*/
#line 908 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*121:*/
#line 939 "./marpa.w"
symbol->id= g->symbols->len;

/*:121*//*123:*/
#line 947 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:123*//*131:*/
#line 979 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:131*//*139:*/
#line 1007 "./marpa.w"

symbol->is_accessible= FALSE;
/*:139*//*145:*/
#line 1033 "./marpa.w"

symbol->is_counted= FALSE;
/*:145*//*149:*/
#line 1051 "./marpa.w"

symbol->is_nullable= FALSE;
/*:149*//*155:*/
#line 1076 "./marpa.w"

symbol->is_nulling= FALSE;
/*:155*//*161:*/
#line 1102 "./marpa.w"

symbol->is_terminal= FALSE;
/*:161*//*167:*/
#line 1128 "./marpa.w"

symbol->is_productive= FALSE;
/*:167*//*173:*/
#line 1153 "./marpa.w"
symbol->is_start= FALSE;
/*:173*//*181:*/
#line 1194 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:181*/
#line 912 "./marpa.w"

{Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);}
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;}

/*:114*//*118:*/
#line 931 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol)
{/*124:*/
#line 949 "./marpa.w"
g_array_free(symbol->lhs,TRUE);
/*:124*//*132:*/
#line 981 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:132*/
#line 933 "./marpa.w"
g_free(symbol);}
/*:118*//*125:*/
#line 958 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->lhs;}
/*:125*//*127:*/
#line 963 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:127*//*133:*/
#line 990 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->rhs;}
/*:133*//*135:*/
#line 995 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
void marpa_symbol_rhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_rhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:135*//*140:*/
#line 1017 "./marpa.w"

gboolean marpa_symbol_is_accessible_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:140*//*142:*/
#line 1023 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:142*//*146:*/
#line 1043 "./marpa.w"

gboolean marpa_symbol_is_counted_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:146*//*150:*/
#line 1061 "./marpa.w"

gboolean marpa_symbol_is_nullable_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:150*//*152:*/
#line 1067 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:152*//*156:*/
#line 1086 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*198:*/
#line 1316 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return-1;
}

/*:198*/
#line 1088 "./marpa.w"

return symbol_id2p(g,symbol_id)->is_nulling;}
/*:156*//*158:*/
#line 1093 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:158*//*162:*/
#line 1112 "./marpa.w"

gboolean marpa_symbol_is_terminal_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:162*//*164:*/
#line 1118 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:164*//*168:*/
#line 1138 "./marpa.w"

gboolean marpa_symbol_is_productive_value(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:168*//*170:*/
#line 1144 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value;}
/*:170*//*174:*/
#line 1161 "./marpa.w"

static inline
gboolean symbol_is_start(struct marpa_symbol*symbol)
{return symbol->is_start;}
gboolean marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symbol_id){
/*198:*/
#line 1316 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return-1;
}

/*:198*/
#line 1166 "./marpa.w"

return symbol_is_start(symbol_id2p(g,symbol_id));
}
/*:174*//*177:*/
#line 1175 "./marpa.w"

void marpa_symbol_is_start_set(struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_start= value;}
/*:177*//*182:*/
#line 1205 "./marpa.w"

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
/*:182*//*185:*/
#line 1227 "./marpa.w"

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
/*:185*//*188:*/
#line 1252 "./marpa.w"
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
/*:188*//*194:*/
#line 1296 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->symbol_callback_arg= cb_arg;}
void*marpa_symbol_callback_arg_peek(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:194*//*196:*/
#line 1308 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:196*//*201:*/
#line 1334 "./marpa.w"

static inline gsize rule_sizeof(gint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:201*//*204:*/
#line 1346 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
int i;
struct marpa_rule*rule;
/*237:*/
#line 1741 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{int i;for(i= 0;i<length;i++){
if(!symbol_is_valid(g,rhs[i])){return NULL;}
}}
/*:237*/
#line 1353 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*238:*/
#line 1746 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{int i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:238*/
#line 1355 "./marpa.w"

/*256:*/
#line 1799 "./marpa.w"
rule->id= g->rules->len;

/*:256*//*259:*/
#line 1811 "./marpa.w"

rule->is_discard= FALSE;
/*:259*//*275:*/
#line 1901 "./marpa.w"

rule->is_used= TRUE;
/*:275*//*279:*/
#line 1928 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:279*//*283:*/
#line 1939 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:283*//*299:*/
#line 1988 "./marpa.w"
rule->original= -1;
/*:299*//*303:*/
#line 2000 "./marpa.w"
rule->real_symbol_count= 0;
/*:303*//*306:*/
#line 2007 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:306*/
#line 1356 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*226:*/
#line 1622 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const gint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*230:*/
#line 1689 "./marpa.w"

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

/*:230*/
#line 1630 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
symbol_id2p(g,rh_symbol_list[rh_list_ix]),
rule->id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:226*/
#line 1358 "./marpa.w"

return rule;
}
/*:204*//*205:*/
#line 1361 "./marpa.w"

Marpa_Rule_ID marpa_rule_start_shim(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
struct marpa_rule*rule= rule_start(g,lhs,rhs,length);
if(!rule){return-1;}
return rule->id;
}
/*:205*//*206:*/
#line 1374 "./marpa.w"

void marpa_rule_complete_shim(struct marpa_g*g,Marpa_Rule_ID id)
{
rule_callback(g,id);
}
/*:206*//*207:*/
#line 1379 "./marpa.w"

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

/*:207*//*208:*/
#line 1396 "./marpa.w"

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

/*211:*/
#line 1435 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*210:*/
#line 1433 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1437 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:211*/
#line 1413 "./marpa.w"

/*212:*/
#line 1441 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:212*/
#line 1414 "./marpa.w"

/*213:*/
#line 1445 "./marpa.w"

symbol_id2p(g,rhs_id)->is_counted= 1;
if(separator_id>=0){symbol_id2p(g,separator_id)->is_counted= 1;}
/*:213*/
#line 1415 "./marpa.w"

if(min==0){/*214:*/
#line 1448 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*210:*/
#line 1433 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1450 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:214*/
#line 1416 "./marpa.w"
}
min= 1;
/*215:*/
#line 1455 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:215*/
#line 1418 "./marpa.w"

/*216:*/
#line 1469 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:216*/
#line 1419 "./marpa.w"

/*218:*/
#line 1472 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*210:*/
#line 1433 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1476 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:218*/
#line 1420 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*219:*/
#line 1485 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*210:*/
#line 1433 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1490 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:219*/
#line 1422 "./marpa.w"

}
/*220:*/
#line 1502 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*210:*/
#line 1433 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1512 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:220*/
#line 1424 "./marpa.w"

/*221:*/
#line 1517 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*210:*/
#line 1433 "./marpa.w"
g->error= "internal_error";return-1;
/*:210*/
#line 1524 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:221*/
#line 1425 "./marpa.w"

/*217:*/
#line 1471 "./marpa.w"
g_free(temp_rhs);
/*:217*/
#line 1426 "./marpa.w"

return original_rule_id;
}
/*:208*//*222:*/
#line 1574 "./marpa.w"

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
/*:222*//*233:*/
#line 1724 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule)
{

g_free(rule);}
/*:233*//*239:*/
#line 1751 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
/*:239*//*241:*/
#line 1756 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs_value(struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_lhs_get(rule_id2p(g,rule_id));}
/*:241*//*243:*/
#line 1761 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:243*//*245:*/
#line 1766 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_rhs_get(rule_id2p(g,rule_id));}
/*:245*//*247:*/
#line 1771 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:247*//*249:*/
#line 1776 "./marpa.w"

gsize marpa_rule_length_value(struct marpa_g*g,Marpa_Rule_ID rule_id){
return rule_length_get(rule_id2p(g,rule_id));}
/*:249*//*251:*/
#line 1782 "./marpa.w"

static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule*rule){return rule->symbols[0];}
/*:251*//*253:*/
#line 1787 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,gint index){
return rule->symbols[index+1];
}
/*:253*//*260:*/
#line 1813 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:260*//*264:*/
#line 1846 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule)
{
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
return symbol_id2p(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{struct marpa_rule*rule;
/*309:*/
#line 2026 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:309*/
#line 1853 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:264*//*268:*/
#line 1864 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_productive)return FALSE;
}
return TRUE;}
gint marpa_rule_is_productive(struct marpa_g*g,Marpa_Rule_ID rule_id)
{struct marpa_rule*rule;
/*309:*/
#line 2026 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:309*/
#line 1875 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:268*//*272:*/
#line 1887 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:272*//*276:*/
#line 1905 "./marpa.w"

gboolean marpa_rule_is_used_value(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_used;}
/*:276*//*280:*/
#line 1931 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs_value(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:280*//*284:*/
#line 1942 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs_value(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:284*//*289:*/
#line 1960 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:289*//*291:*/
#line 1965 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:291*//*293:*/
#line 1970 "./marpa.w"

void*marpa_rule_callback_arg_peek(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:293*//*295:*/
#line 1976 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:295*//*300:*/
#line 1989 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}

/*:300*//*304:*/
#line 2001 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}

/*:304*//*307:*/
#line 2018 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent_value(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:307*//*310:*/
#line 2044 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
if(!census(g))return NULL;
if(!CHAF_rewrite(g))return NULL;
return g;
}
/*:310*//*313:*/
#line 2086 "./marpa.w"

static inline struct marpa_g*census(struct marpa_g*g)
{
/*315:*/
#line 2118 "./marpa.w"

gint pre_rewrite_rule_count= g->rules->len;
gint pre_rewrite_symbol_count= g->symbols->len;

/*:315*//*320:*/
#line 2151 "./marpa.w"

Marpa_Symbol_ID original_start_symbol_id= g->start_symbol;
struct marpa_symbol*original_start_symbol;

/*:320*//*324:*/
#line 2184 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:324*//*330:*/
#line 2242 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:330*//*332:*/
#line 2267 "./marpa.w"

Bit_Vector nullable_v;
/*:332*//*336:*/
#line 2290 "./marpa.w"

Bit_Vector productive_v;
/*:336*//*341:*/
#line 2343 "./marpa.w"

Bit_Vector accessible_v;

/*:341*/
#line 2089 "./marpa.w"

/*316:*/
#line 2122 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:316*/
#line 2090 "./marpa.w"

/*317:*/
#line 2129 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:317*/
#line 2091 "./marpa.w"

/*319:*/
#line 2135 "./marpa.w"

if(original_start_symbol_id<0){
g->error= "no start symbol";
return NULL;
}
if(!symbol_is_valid(g,original_start_symbol_id)){
context_int_add(g,"symbol_id",original_start_symbol_id);
g->error= "invalid start symbol";
return NULL;
}
original_start_symbol= symbol_id2p(g,original_start_symbol_id);
if(original_start_symbol->lhs->len<=0){
context_int_add(g,"symbol_id",original_start_symbol_id);
g->error= "start symbol not on LHS";
return NULL;
}
/*:319*/
#line 2092 "./marpa.w"

/*321:*/
#line 2155 "./marpa.w"

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
/*:321*/
#line 2093 "./marpa.w"

/*322:*/
#line 2172 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symbol_id= 0;symbol_id<pre_rewrite_symbol_count;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_terminal){
bv_bit_set(terminal_v,symbol_id);
have_marked_terminals= 1;
}
}}
/*:322*/
#line 2094 "./marpa.w"

if(have_marked_terminals){
/*326:*/
#line 2199 "./marpa.w"

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

/*:326*/
#line 2096 "./marpa.w"

}else{
/*325:*/
#line 2188 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:325*/
#line 2098 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*327:*/
#line 2222 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<g->symbols->len;symbol_id++)
{symbol_id2p(g,symbol_id)->is_terminal= 1;}}
/*:327*/
#line 2100 "./marpa.w"

}else{
/*328:*/
#line 2227 "./marpa.w"

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
/*:328*/
#line 2102 "./marpa.w"

}
}
/*331:*/
#line 2247 "./marpa.w"

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
/*:331*/
#line 2105 "./marpa.w"

/*334:*/
#line 2272 "./marpa.w"

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
/*:334*/
#line 2106 "./marpa.w"

/*335:*/
#line 2283 "./marpa.w"

if(!bv_bit_test(productive_v,g->start_symbol))
{
context_int_add(g,"symbol_id",g->start_symbol);
g->error= "unproductive start symbol";
return NULL;
}
/*:335*/
#line 2107 "./marpa.w"

/*338:*/
#line 2313 "./marpa.w"

Bit_Matrix reach_matrix
= matrix_create(pre_rewrite_symbol_count,pre_rewrite_symbol_count);
{gint symbol_id,no_of_symbols= symbol_count(g);
for(symbol_id= 0;symbol_id<no_of_symbols;symbol_id++){
matrix_bit_set(reach_matrix,symbol_id,symbol_id);
}}
{gint rule_id,no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
gint rhs_ix,rule_length= rule->length;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
matrix_bit_set(reach_matrix,lhs_id,rhs_symbol_id(rule,rhs_ix));
}}}
transitive_closure(reach_matrix);
/*:338*/
#line 2108 "./marpa.w"

/*340:*/
#line 2332 "./marpa.w"

accessible_v= matrix_row(reach_matrix,original_start_symbol_id);
{gint min,max,start,symbol_id;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symbol_id= min;symbol_id<=max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
symbol->is_accessible= 1;
}}
}
/*:340*/
#line 2109 "./marpa.w"

/*342:*/
#line 2348 "./marpa.w"

{Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
gint min,max,start;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
Marpa_Symbol_ID productive_id;
for(productive_id= min;productive_id<=max;productive_id++){
bv_and(reaches_terminal_v,terminal_v,matrix_row(reach_matrix,productive_id));
if(bv_is_empty(reaches_terminal_v))symbol_id2p(g,productive_id)->is_nulling= 1;
}}
bv_free(reaches_terminal_v);}

/*:342*/
#line 2110 "./marpa.w"

/*323:*/
#line 2182 "./marpa.w"

bv_free(terminal_v);
/*:323*//*329:*/
#line 2239 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:329*//*333:*/
#line 2269 "./marpa.w"

bv_free(nullable_v);

/*:333*//*337:*/
#line 2292 "./marpa.w"

bv_free(productive_v);

/*:337*/
#line 2111 "./marpa.w"

/*339:*/
#line 2329 "./marpa.w"

matrix_free(reach_matrix);

/*:339*/
#line 2112 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:313*//*345:*/
#line 2380 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*347:*/
#line 2400 "./marpa.w"

Marpa_Rule_ID rule_id;
struct rule_data{
gint next_proper_nullable;
Marpa_Symbol_ID proper_last_factor;
Marpa_Symbol_ID nulling_last_factor;
}*rule_data;
gint no_of_rules;
/*:347*/
#line 2383 "./marpa.w"

/*348:*/
#line 2408 "./marpa.w"

rule_data= g_new(struct rule_data,g->max_rule_length);
/*:348*/
#line 2384 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
/*350:*/
#line 2412 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:350*/
#line 2388 "./marpa.w"

/*351:*/
#line 2418 "./marpa.w"
{;}

/*:351*/
#line 2389 "./marpa.w"


if(rule_data[0].next_proper_nullable==-1)goto NEXT_RULE;

NEXT_RULE:;
}
/*349:*/
#line 2410 "./marpa.w"
g_free(rule_data);

/*:349*/
#line 2395 "./marpa.w"

return g;
}
/*:345*//*353:*/
#line 2450 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:353*//*355:*/
#line 2458 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:355*//*360:*/
#line 2491 "./marpa.w"

static inline guint bv_bits_to_size(gint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:360*//*362:*/
#line 2499 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:362*//*364:*/
#line 2515 "./marpa.w"

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
/*:364*//*366:*/
#line 2532 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:366*//*368:*/
#line 2544 "./marpa.w"

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
/*:368*//*370:*/
#line 2563 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:370*//*372:*/
#line 2572 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:372*//*374:*/
#line 2580 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
*(--bv)&= BV_MASK(bv);
}
/*:374*//*377:*/
#line 2592 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:377*//*379:*/
#line 2600 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:379*//*381:*/
#line 2608 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:381*//*384:*/
#line 2617 "./marpa.w"

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
/*:384*//*386:*/
#line 2632 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:386*//*388:*/
#line 2644 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:388*//*390:*/
#line 2656 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:390*//*392:*/
#line 2668 "./marpa.w"

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
/*:392*//*398:*/
#line 2780 "./marpa.w"

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
/*:398*//*403:*/
#line 2849 "./marpa.w"

static inline Bit_Matrix matrix_create(gint rows,gint columns)
{
guint bv_data_words= bv_bits_to_size(columns);
guint row_bytes= (bv_data_words+bv_hiddenwords)*sizeof(Bit_Vector_Word);
guint bv_mask= bv_bits_to_unused_mask(columns);
Bit_Vector_Word*matrix_addr= g_malloc0((size_t)(row_bytes*rows));
gint row;
for(row= 0;row<rows;row++){
gint row_start= row*(bv_data_words+bv_hiddenwords);
matrix_addr[row_start]= columns;
matrix_addr[row_start+1]= bv_data_words;
matrix_addr[row_start+2]= bv_mask;
}
return matrix_addr;
}
/*:403*//*405:*/
#line 2869 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:405*//*407:*/
#line 2882 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:407*//*409:*/
#line 2899 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,gint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:409*//*412:*/
#line 2909 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:412*//*415:*/
#line 2918 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:415*//*418:*/
#line 2927 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:418*//*420:*/
#line 2941 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix)
{
gint size= matrix_columns(matrix);
struct transition{gint from,to;};
DSTACK_DEFINE(stack,struct transition);
struct transition*top_of_stack= NULL;
gint row;
DSTACK_INIT(stack,struct transition);
for(row= 0;row<size;row++){
gint min,max,start;
Bit_Vector row_vector= matrix_row(matrix,row);
for(start= 0;bv_scan(row_vector,start,&min,&max);start= max+2){
gint column;
for(column= min;column<=max;column++){
struct transition*t= DSTACK_PUSH(stack,struct transition);
t->from= row;
t->to= column;
}}}
while(top_of_stack= DSTACK_POP(stack,struct transition)){
gint old_from= top_of_stack->from;
gint old_to= top_of_stack->to;
gint new_ix;
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
/*:420*//*425:*/
#line 3044 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:425*//*433:*/
#line 3115 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->message_callback_arg= cb_arg;}
void*marpa_message_callback_arg_peek(struct marpa_g*g)
{return g->message_callback_arg;}
/*:433*//*435:*/
#line 3127 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:435*//*438:*/
#line 3142 "./marpa.w"



const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
int marpa_effective_micro= 1000*MARPA_MINOR_VERSION+MARPA_MICRO_VERSION;
int required_effective_micro= 1000*required_minor+required_micro;
static char output_buffer[1000];

/*440:*/
#line 3172 "./marpa.w"


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

/*:440*/
#line 3154 "./marpa.w"

/*441:*/
#line 3188 "./marpa.w"


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


/*:441*/
#line 3155 "./marpa.w"

/*442:*/
#line 3206 "./marpa.w"


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


/*:442*/
#line 3156 "./marpa.w"

/*443:*/
#line 3224 "./marpa.w"

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

/*:443*/
#line 3157 "./marpa.w"


return"Perfect!";
}

/*:438*/
#line 3347 "./marpa.w"





/*:450*/
