/*517:*/
#line 3952 "./marpa.w"

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


#line 3988 "./marpa.w"

/*496:*/
#line 3720 "./marpa.w"

#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:496*/
#line 3989 "./marpa.w"

/*425:*/
#line 3124 "./marpa.w"

typedef guint Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:425*//*468:*/
#line 3489 "./marpa.w"

typedef Bit_Vector_Word*Bit_Matrix;

/*:468*/
#line 3990 "./marpa.w"

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
/*:30*//*426:*/
#line 3131 "./marpa.w"

static const int bv_wordbits= sizeof(Bit_Vector_Word)*8u;
static const int bv_modmask= sizeof(Bit_Vector_Word)*8u-1u;
static const int bv_hiddenwords= 3;
static const int bv_lsb= 1u;
static const int bv_msb= (1u<<(sizeof(Bit_Vector_Word)*8u-1u));

/*:426*/
#line 3991 "./marpa.w"

/*117:*/
#line 912 "./marpa.w"

struct marpa_symbol{
/*126:*/
#line 957 "./marpa.w"
GArray*lhs;
/*:126*//*133:*/
#line 983 "./marpa.w"
GArray*rhs;
/*:133*//*180:*/
#line 1177 "./marpa.w"

struct marpa_symbol*alias;
/*:180*/
#line 914 "./marpa.w"

/*124:*/
#line 949 "./marpa.w"
Marpa_Symbol_ID id;
/*:124*/
#line 915 "./marpa.w"

/*140:*/
#line 1003 "./marpa.w"
unsigned int is_accessible:1;
/*:140*//*146:*/
#line 1029 "./marpa.w"
unsigned int is_counted:1;
/*:146*//*150:*/
#line 1047 "./marpa.w"
unsigned int is_nullable:1;
/*:150*//*156:*/
#line 1072 "./marpa.w"
unsigned int is_nulling:1;
/*:156*//*162:*/
#line 1098 "./marpa.w"
unsigned int is_terminal:1;
/*:162*//*168:*/
#line 1124 "./marpa.w"
unsigned int is_productive:1;
/*:168*//*174:*/
#line 1149 "./marpa.w"
unsigned int is_start:1;
/*:174*//*179:*/
#line 1174 "./marpa.w"

unsigned int is_proper_alias:1;
unsigned int is_nulling_alias:1;
/*:179*/
#line 916 "./marpa.w"

};

/*:117*//*201:*/
#line 1325 "./marpa.w"

struct marpa_rule{
/*234:*/
#line 1715 "./marpa.w"
gsize length;
/*:234*/
#line 1327 "./marpa.w"


/*254:*/
#line 1779 "./marpa.w"
Marpa_Rule_ID id;
/*:254*//*295:*/
#line 1971 "./marpa.w"
gint virtual_start;
/*:295*//*297:*/
#line 1978 "./marpa.w"
gint virtual_end;
/*:297*//*311:*/
#line 2020 "./marpa.w"
Marpa_Rule_ID original;
/*:311*//*315:*/
#line 2032 "./marpa.w"
gint real_symbol_count;
/*:315*/
#line 1329 "./marpa.w"

/*257:*/
#line 1791 "./marpa.w"
unsigned int is_discard:1;
/*:257*//*271:*/
#line 1871 "./marpa.w"
unsigned int is_loop:1;
/*:271*//*276:*/
#line 1890 "./marpa.w"
unsigned int is_virtual_loop:1;
/*:276*//*283:*/
#line 1918 "./marpa.w"
unsigned int is_used:1;
/*:283*//*287:*/
#line 1946 "./marpa.w"
unsigned int is_virtual_lhs:1;
/*:287*//*291:*/
#line 1957 "./marpa.w"
unsigned int is_virtual_rhs:1;
/*:291*//*318:*/
#line 2039 "./marpa.w"
unsigned int is_semantic_equivalent:1;
/*:318*/
#line 1330 "./marpa.w"

/*235:*/
#line 1718 "./marpa.w"
Marpa_Symbol_ID symbols[1];
/*:235*/
#line 1331 "./marpa.w"

};
/*:201*//*491:*/
#line 3690 "./marpa.w"

struct dstack{gint ix;gint size;gpointer base;};
/*:491*/
#line 3992 "./marpa.w"

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

/*:57*//*98:*/
#line 826 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint value);
/*:98*//*100:*/
#line 838 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*value);

/*:100*//*102:*/
#line 847 "./marpa.w"

static inline void context_clear(struct marpa_g*g);

/*:102*//*119:*/
#line 933 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g);
/*:119*//*123:*/
#line 945 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol);

/*:123*//*132:*/
#line 975 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);

/*:132*//*139:*/
#line 999 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id);

/*:139*//*177:*/
#line 1161 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol);
/*:177*//*183:*/
#line 1201 "./marpa.w"

static inline struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol);
/*:183*//*186:*/
#line 1228 "./marpa.w"

static inline struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol);
/*:186*//*189:*/
#line 1267 "./marpa.w"

static inline
struct marpa_symbol*symbol_alias_create(struct marpa_g*g,
struct marpa_symbol*symbol);
/*:189*//*197:*/
#line 1302 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id);

/*:197*//*203:*/
#line 1337 "./marpa.w"

static inline gsize rule_sizeof(gint length);

/*:203*//*222:*/
#line 1579 "./marpa.w"

static inline
gboolean is_rule_duplicate(struct marpa_g*g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,gint length);

/*:222*//*223:*/
#line 1584 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length);
/*:223*//*233:*/
#line 1707 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule);

/*:233*//*239:*/
#line 1732 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule);
/*:239*//*243:*/
#line 1743 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule);
/*:243*//*247:*/
#line 1754 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule);
/*:247*//*251:*/
#line 1766 "./marpa.w"

static inline Marpa_Symbol_ID lhs_symbol_id(struct marpa_rule*rule);
/*:251*//*253:*/
#line 1773 "./marpa.w"

static inline Marpa_Symbol_ID rhs_symbol_id(struct marpa_rule*rule,gint index);

/*:253*//*264:*/
#line 1838 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule);
/*:264*//*268:*/
#line 1860 "./marpa.w"

static inline gint rule_is_productive(struct marpa_g*g,struct marpa_rule*rule);
/*:268*//*282:*/
#line 1914 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule);

/*:282*//*309:*/
#line 2013 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id);

/*:309*//*365:*/
#line 2488 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g);
/*:365*//*404:*/
#line 2857 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id);

/*:404*//*407:*/
#line 2878 "./marpa.w"

static inline struct marpa_g*g_augment(struct marpa_g*g);

/*:407*//*415:*/
#line 2995 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g);

/*:415*//*428:*/
#line 3144 "./marpa.w"

static inline guint bv_bits_to_size(gint bits);
/*:428*//*430:*/
#line 3154 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits);

/*:430*//*432:*/
#line 3174 "./marpa.w"

static inline Bit_Vector bv_create(gint bits);

/*:432*//*434:*/
#line 3185 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv);

/*:434*//*436:*/
#line 3207 "./marpa.w"

Bit_Vector bv_clone(Bit_Vector bv);

/*:436*//*438:*/
#line 3216 "./marpa.w"

static inline void bv_free(Bit_Vector vector);

/*:438*//*440:*/
#line 3224 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv);

/*:440*//*442:*/
#line 3236 "./marpa.w"

static inline void bv_fill(Bit_Vector bv);

/*:442*//*445:*/
#line 3244 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit);

/*:445*//*447:*/
#line 3252 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit);

/*:447*//*449:*/
#line 3260 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit);

/*:449*//*452:*/
#line 3276 "./marpa.w"

gboolean bv_is_empty(Bit_Vector addr);

/*:452*//*454:*/
#line 3288 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y);

/*:454*//*456:*/
#line 3300 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:456*//*458:*/
#line 3312 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z);

/*:458*//*460:*/
#line 3385 "./marpa.w"

gboolean BitVector_scan(Bit_Vector bv,gint start,
gint*min,gint*max);

/*:460*//*466:*/
#line 3466 "./marpa.w"

static void rhs_closure(struct marpa_g*g,Bit_Vector bv);

/*:466*//*471:*/
#line 3513 "./marpa.w"

static inline Bit_Matrix matrix_create(gint rows,gint columns);

/*:471*//*473:*/
#line 3521 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix);

/*:473*//*475:*/
#line 3535 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix);

/*:475*//*477:*/
#line 3553 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,gint row);

/*:477*//*480:*/
#line 3562 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,gint row,gint column);

/*:480*//*483:*/
#line 3571 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,gint row,gint column);

/*:483*//*486:*/
#line 3580 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,gint row,gint column);

/*:486*//*488:*/
#line 3634 "./marpa.w"

static void transitive_closure(Bit_Matrix matrix);

/*:488*//*493:*/
#line 3698 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_size);

/*:493*//*503:*/
#line 3779 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id);

/*:503*/
#line 3993 "./marpa.w"

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
#line 3994 "./marpa.w"

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
#line 688 "./marpa.w"

g->has_loop= FALSE;
/*:75*//*79:*/
#line 703 "./marpa.w"

g->is_lhs_terminal_ok= TRUE;
/*:79*//*85:*/
#line 743 "./marpa.w"

g->is_academic= FALSE;
/*:85*//*91:*/
#line 776 "./marpa.w"

g->context= g_hash_table_new_full(g_str_hash,g_str_equal,NULL,g_free);
/*:91*//*107:*/
#line 869 "./marpa.w"

g->error= 0;
/*:107*/
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

/*:48*//*92:*/
#line 778 "./marpa.w"
g_hash_table_destroy(g->context);

/*:92*//*121:*/
#line 939 "./marpa.w"

{int id;for(id= 0;id<g->symbols->len;id++)
{marpa_symbol_free(symbol_id2p(g,id));}}
/*:121*//*231:*/
#line 1698 "./marpa.w"

{int id;for(id= 0;id<g->rules->len;id++)
{marpa_rule_free(rule_id2p(g,id));}}
/*:231*/
#line 470 "./marpa.w"
}
/*:25*//*32:*/
#line 490 "./marpa.w"

gint marpa_grammar_id(struct marpa_g*g){return g->id;}
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

Marpa_Symbol_ID marpa_start_symbol(struct marpa_g*g)
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
#line 691 "./marpa.w"

gboolean marpa_has_loop(struct marpa_g*g)
{return g->has_loop;}
/*:76*//*80:*/
#line 706 "./marpa.w"

gboolean marpa_is_lhs_terminal_ok(struct marpa_g*g)
{return g->is_lhs_terminal_ok;}
/*:80*//*82:*/
#line 713 "./marpa.w"

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
/*:82*//*86:*/
#line 746 "./marpa.w"

gboolean marpa_is_academic(struct marpa_g*g)
{return g->is_academic;}
/*:86*//*88:*/
#line 753 "./marpa.w"

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
/*:88*//*97:*/
#line 817 "./marpa.w"

static inline
void context_int_add(struct marpa_g*g,const gchar*key,gint payload)
{
struct marpa_context_int_value*value= g_new(struct marpa_context_int_value,1);
value->type= MARPA_CONTEXT_INT;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:97*//*99:*/
#line 829 "./marpa.w"

static inline
void marpa_context_const_add(struct marpa_g*g,const gchar*key,const gchar*payload)
{
struct marpa_context_const_value*value= g_new(struct marpa_context_const_value,1);
value->type= MARPA_CONTEXT_CONST;
value->data= payload;
g_hash_table_insert(g->context,(gpointer)key,value);
}
/*:99*//*101:*/
#line 844 "./marpa.w"

static inline void context_clear(struct marpa_g*g){
g_hash_table_remove_all(g->context);}
/*:101*//*103:*/
#line 850 "./marpa.w"

union marpa_context_value*marpa_context_value_look(struct marpa_g*g,const gchar*key)
{return g_hash_table_lookup(g->context,key);}
/*:103*//*109:*/
#line 877 "./marpa.w"

Marpa_Error_ID marpa_error(struct marpa_g*g)
{return g->error?:"unknown error";}
/*:109*//*112:*/
#line 891 "./marpa.w"

void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

return;

}

/*:112*//*114:*/
#line 904 "./marpa.w"

void marpa_r_destroy(struct marpa_r*recce){}
/*:114*//*118:*/
#line 919 "./marpa.w"

static inline
struct marpa_symbol*symbol_new(struct marpa_g*g)
{struct marpa_symbol*symbol= g_malloc(sizeof(struct marpa_symbol));
/*125:*/
#line 950 "./marpa.w"
symbol->id= g->symbols->len;

/*:125*//*127:*/
#line 958 "./marpa.w"

symbol->lhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:127*//*134:*/
#line 984 "./marpa.w"

symbol->rhs= g_array_new(FALSE,FALSE,sizeof(Marpa_Rule_ID));
/*:134*//*141:*/
#line 1004 "./marpa.w"

symbol->is_accessible= FALSE;
/*:141*//*147:*/
#line 1030 "./marpa.w"

symbol->is_counted= FALSE;
/*:147*//*151:*/
#line 1048 "./marpa.w"

symbol->is_nullable= FALSE;
/*:151*//*157:*/
#line 1073 "./marpa.w"

symbol->is_nulling= FALSE;
/*:157*//*163:*/
#line 1099 "./marpa.w"

symbol->is_terminal= FALSE;
/*:163*//*169:*/
#line 1125 "./marpa.w"

symbol->is_productive= FALSE;
/*:169*//*175:*/
#line 1150 "./marpa.w"
symbol->is_start= FALSE;
/*:175*//*181:*/
#line 1179 "./marpa.w"

symbol->is_proper_alias= FALSE;
symbol->is_nulling_alias= FALSE;
symbol->alias= NULL;

/*:181*/
#line 923 "./marpa.w"

{Marpa_Symbol_ID id= symbol->id;
g_symbol_add(g,id,symbol);}
return symbol;
}
Marpa_Symbol_ID marpa_symbol_new(struct marpa_g*g)
{Marpa_Symbol_ID id= symbol_new(g)->id;
symbol_callback(g,id);
return id;}

/*:118*//*122:*/
#line 942 "./marpa.w"

static inline void marpa_symbol_free(struct marpa_symbol*symbol)
{/*128:*/
#line 960 "./marpa.w"
g_array_free(symbol->lhs,TRUE);
/*:128*//*135:*/
#line 986 "./marpa.w"
g_array_free(symbol->rhs,TRUE);
/*:135*/
#line 944 "./marpa.w"
g_free(symbol);}
/*:122*//*129:*/
#line 964 "./marpa.w"

GArray*marpa_symbol_lhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*199:*/
#line 1314 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return NULL;
}

/*:199*/
#line 966 "./marpa.w"

return symbol_id2p(g,symbol_id)->lhs;}
/*:129*//*131:*/
#line 970 "./marpa.w"
static inline
void symbol_lhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->lhs,rule_id);}
void marpa_symbol_lhs_add(struct marpa_g*g,Marpa_Symbol_ID symbol_id,Marpa_Rule_ID rule_id)
{symbol_lhs_add(symbol_id2p(g,symbol_id),rule_id);}
/*:131*//*136:*/
#line 990 "./marpa.w"

GArray*marpa_symbol_rhs_peek(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*199:*/
#line 1314 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return NULL;
}

/*:199*/
#line 992 "./marpa.w"

return symbol_id2p(g,symbol_id)->rhs;}
/*:136*//*138:*/
#line 996 "./marpa.w"
static inline
void symbol_rhs_add(struct marpa_symbol*symbol,Marpa_Rule_ID rule_id)
{g_array_append_val(symbol->rhs,rule_id);}
/*:138*//*142:*/
#line 1014 "./marpa.w"

gboolean marpa_symbol_is_accessible(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_accessible;}
/*:142*//*144:*/
#line 1020 "./marpa.w"

void marpa_symbol_is_accessible_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_accessible= value;}
/*:144*//*148:*/
#line 1040 "./marpa.w"

gboolean marpa_symbol_is_counted(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_counted;}
/*:148*//*152:*/
#line 1058 "./marpa.w"

gboolean marpa_symbol_is_nullable(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_nullable;}
/*:152*//*154:*/
#line 1064 "./marpa.w"

void marpa_symbol_is_nullable_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nullable= value;}
/*:154*//*158:*/
#line 1083 "./marpa.w"

gint marpa_symbol_is_nulling(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{/*198:*/
#line 1306 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return-1;
}

/*:198*/
#line 1085 "./marpa.w"

return symbol_id2p(g,symbol_id)->is_nulling;}
/*:158*//*160:*/
#line 1090 "./marpa.w"

void marpa_symbol_is_nulling_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_nulling= value;}
/*:160*//*164:*/
#line 1109 "./marpa.w"

gboolean marpa_symbol_is_terminal(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_terminal;}
/*:164*//*166:*/
#line 1115 "./marpa.w"

void marpa_symbol_is_terminal_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_terminal= value;}
/*:166*//*170:*/
#line 1135 "./marpa.w"

gboolean marpa_symbol_is_productive(struct marpa_g*g,Marpa_Symbol_ID id)
{return symbol_id2p(g,id)->is_productive;}
/*:170*//*172:*/
#line 1141 "./marpa.w"

void marpa_symbol_is_productive_set(
struct marpa_g*g,Marpa_Symbol_ID id,gboolean value)
{symbol_id2p(g,id)->is_productive= value;}
/*:172*//*176:*/
#line 1153 "./marpa.w"

static inline
gint symbol_is_start(struct marpa_symbol*symbol)
{return symbol->is_start;}
gint marpa_symbol_is_start(struct marpa_g*g,Marpa_Symbol_ID symbol_id){
/*198:*/
#line 1306 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return-1;
}

/*:198*/
#line 1158 "./marpa.w"

return symbol_is_start(symbol_id2p(g,symbol_id));
}
/*:176*//*182:*/
#line 1188 "./marpa.w"

static inline
struct marpa_symbol*symbol_proper_alias(struct marpa_symbol*symbol)
{return symbol->is_nulling_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_proper_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*proper_alias;
/*198:*/
#line 1306 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return-1;
}

/*:198*/
#line 1196 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
proper_alias= symbol_proper_alias(symbol);
return proper_alias==NULL?-1:proper_alias->id;
}
/*:182*//*185:*/
#line 1210 "./marpa.w"

static inline
struct marpa_symbol*symbol_null_alias(struct marpa_symbol*symbol)
{return symbol->is_proper_alias?symbol->alias:NULL;}
Marpa_Symbol_ID marpa_symbol_null_alias(struct marpa_g*g,Marpa_Symbol_ID symbol_id)
{
struct marpa_symbol*symbol;
struct marpa_symbol*alias;
/*198:*/
#line 1306 "./marpa.w"

if(!symbol_is_valid(g,symbol_id)){
context_clear(g);
context_int_add(g,"symbol_id",symbol_id);
g->error= "invalid symbol id";
return-1;
}

/*:198*/
#line 1218 "./marpa.w"

symbol= symbol_id2p(g,symbol_id);
alias= symbol_null_alias(symbol);
if(alias==NULL){
context_int_add(g,"symbol_id",symbol_id);
g->error= "no alias";
return-1;
}
return alias->id;
}
/*:185*//*188:*/
#line 1242 "./marpa.w"
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
#line 1286 "./marpa.w"

void marpa_symbol_callback_set(struct marpa_g*g,Marpa_Symbol_Callback*cb)
{g->symbol_callback= cb;}
void marpa_symbol_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->symbol_callback_arg= cb_arg;}
void*marpa_symbol_callback_arg_peek(struct marpa_g*g)
{return g->symbol_callback_arg;}
/*:194*//*196:*/
#line 1298 "./marpa.w"

static inline symbol_callback(struct marpa_g*g,Marpa_Symbol_ID id)
{Marpa_Symbol_Callback*cb= g->symbol_callback;
if(cb){(*cb)(g,id);}}
/*:196*//*202:*/
#line 1333 "./marpa.w"

static inline gsize rule_sizeof(gint length){
return sizeof(struct marpa_rule)+length*sizeof(Marpa_Symbol_ID);
}
/*:202*//*205:*/
#line 1345 "./marpa.w"

static inline
struct marpa_rule*rule_start(struct marpa_g*g,
Marpa_Symbol_ID lhs,Marpa_Symbol_ID*rhs,gint length)
{
int i;
struct marpa_rule*rule;
/*236:*/
#line 1719 "./marpa.w"

if(!symbol_is_valid(g,lhs)){return NULL;}
{int i;for(i= 0;i<length;i++){
if(!symbol_is_valid(g,rhs[i])){return NULL;}
}}
/*:236*/
#line 1352 "./marpa.w"

rule= g_malloc(rule_sizeof(length));
/*237:*/
#line 1724 "./marpa.w"

rule->length= length;
rule->symbols[0]= lhs;
{int i;for(i= 0;i<length;i++){
rule->symbols[i+1]= rhs[i];}}
/*:237*/
#line 1354 "./marpa.w"

/*255:*/
#line 1780 "./marpa.w"
rule->id= g->rules->len;

/*:255*//*258:*/
#line 1792 "./marpa.w"

rule->is_discard= FALSE;
/*:258*//*272:*/
#line 1872 "./marpa.w"

rule->is_loop= FALSE;
/*:272*//*277:*/
#line 1891 "./marpa.w"

rule->is_virtual_loop= FALSE;
/*:277*//*284:*/
#line 1919 "./marpa.w"

rule->is_used= TRUE;
/*:284*//*288:*/
#line 1947 "./marpa.w"

rule->is_virtual_lhs= FALSE;
/*:288*//*292:*/
#line 1958 "./marpa.w"

rule->is_virtual_rhs= FALSE;
/*:292*//*296:*/
#line 1972 "./marpa.w"
rule->virtual_start= -1;

/*:296*//*298:*/
#line 1979 "./marpa.w"
rule->virtual_end= -1;

/*:298*//*312:*/
#line 2021 "./marpa.w"
rule->original= -1;
/*:312*//*316:*/
#line 2033 "./marpa.w"
rule->real_symbol_count= 0;
/*:316*//*319:*/
#line 2040 "./marpa.w"

rule->is_semantic_equivalent= FALSE;
/*:319*/
#line 1355 "./marpa.w"

marpa_g_rule_add(g,rule->id,rule);
/*225:*/
#line 1600 "./marpa.w"

symbol_lhs_add(symbol_id2p(g,rule->symbols[0]),rule->id);
if(rule->length> 0){
gint rh_list_ix;
const gint alloc_size= rule->length*sizeof(Marpa_Symbol_ID);
Marpa_Symbol_ID*rh_symbol_list= g_slice_alloc(alloc_size);
gint rh_symbol_list_length= 1;
/*229:*/
#line 1667 "./marpa.w"

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

/*:229*/
#line 1608 "./marpa.w"

for(rh_list_ix= 0;
rh_list_ix<rh_symbol_list_length;
rh_list_ix++){
symbol_rhs_add(
symbol_id2p(g,rh_symbol_list[rh_list_ix]),
rule->id);
}
g_slice_free1(alloc_size,rh_symbol_list);
}

/*:225*/
#line 1357 "./marpa.w"

return rule;
}
/*:205*//*206:*/
#line 1360 "./marpa.w"

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

/*:206*//*207:*/
#line 1377 "./marpa.w"

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

/*210:*/
#line 1416 "./marpa.w"

original_rule= rule_start(g,lhs_id,&rhs_id,1);
if(!original_rule){/*209:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:209*/
#line 1418 "./marpa.w"
}
original_rule->is_used= 0;
original_rule_id= original_rule->id;
rule_callback(g,original_rule_id);
/*:210*/
#line 1394 "./marpa.w"

/*211:*/
#line 1422 "./marpa.w"

if(separator_id!=-1&&!symbol_is_valid(g,separator_id)){
g->error= "bad separator";return-1;
}
/*:211*/
#line 1395 "./marpa.w"

/*212:*/
#line 1426 "./marpa.w"

symbol_id2p(g,rhs_id)->is_counted= 1;
if(separator_id>=0){symbol_id2p(g,separator_id)->is_counted= 1;}
/*:212*/
#line 1396 "./marpa.w"

if(min==0){/*213:*/
#line 1429 "./marpa.w"

{struct marpa_rule*rule= rule_start(g,lhs_id,0,0);
if(!rule){/*209:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:209*/
#line 1431 "./marpa.w"
}
rule->is_semantic_equivalent= TRUE;
rule->original= original_rule_id;
rule_callback(g,rule->id);
}
/*:213*/
#line 1397 "./marpa.w"
}
min= 1;
/*214:*/
#line 1436 "./marpa.w"

internal_lhs_id= symbol_new(g)->id;
symbol_callback(g,internal_lhs_id);
/*:214*/
#line 1399 "./marpa.w"

/*215:*/
#line 1450 "./marpa.w"

temp_rhs= g_new(Marpa_Symbol_ID,(3+(separator_id<0?1:2)*min));
/*:215*/
#line 1400 "./marpa.w"

/*217:*/
#line 1453 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
rule= rule_start(g,lhs_id,temp_rhs,1);
if(!rule){/*209:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:209*/
#line 1457 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;

rule->is_virtual_rhs= TRUE;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION)&&separator_id>=0;
rule_callback(g,rule->id);
}
/*:217*/
#line 1401 "./marpa.w"

if(separator_id>=0&&!(flags&MARPA_PROPER_SEPARATION)){
/*218:*/
#line 1466 "./marpa.w"

{struct marpa_rule*rule;
temp_rhs[0]= internal_lhs_id;
temp_rhs[1]= separator_id;
rule= rule_start(g,lhs_id,temp_rhs,2);
if(!rule){/*209:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:209*/
#line 1471 "./marpa.w"
}
rule->original= original_rule_id;
rule->is_semantic_equivalent= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= 1;
rule->is_discard= !(flags&MARPA_KEEP_SEPARATION);
rule_callback(g,rule->id);
}
/*:218*/
#line 1403 "./marpa.w"

}
/*219:*/
#line 1483 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix,i;
temp_rhs[0]= rhs_id;
rhs_ix= 1;
for(i= 0;i<min-1;i++){
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
}
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*209:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:209*/
#line 1493 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->real_symbol_count= rhs_ix;
rule_callback(g,rule->id);
}
/*:219*/
#line 1405 "./marpa.w"

/*220:*/
#line 1498 "./marpa.w"

{struct marpa_rule*rule;
gint rhs_ix= 0;
temp_rhs[rhs_ix++]= internal_lhs_id;
if(separator_id>=0)temp_rhs[rhs_ix++]= separator_id;
temp_rhs[rhs_ix++]= rhs_id;
rule= rule_start(g,internal_lhs_id,temp_rhs,rhs_ix);
if(!rule){/*209:*/
#line 1414 "./marpa.w"
g->error= "internal_error";return-1;
/*:209*/
#line 1505 "./marpa.w"
}
rule->is_virtual_lhs= TRUE;
rule->is_virtual_rhs= TRUE;
rule->real_symbol_count= rhs_ix-1;
rule_callback(g,rule->id);
}

/*:220*/
#line 1406 "./marpa.w"

/*216:*/
#line 1452 "./marpa.w"
g_free(temp_rhs);
/*:216*/
#line 1407 "./marpa.w"

return original_rule_id;
}
/*:207*//*221:*/
#line 1555 "./marpa.w"

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
/*:221*//*232:*/
#line 1702 "./marpa.w"

static inline void marpa_rule_free(struct marpa_rule*rule)
{

g_free(rule);}
/*:232*//*238:*/
#line 1729 "./marpa.w"

static inline Marpa_Symbol_ID rule_lhs_get(struct marpa_rule*rule){
return rule->symbols[0];}
/*:238*//*240:*/
#line 1734 "./marpa.w"

Marpa_Symbol_ID marpa_rule_lhs(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*322:*/
#line 2059 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:322*/
#line 1736 "./marpa.w"

return rule_lhs_get(rule_id2p(g,rule_id));}
/*:240*//*242:*/
#line 1740 "./marpa.w"

static inline Marpa_Symbol_ID*rule_rhs_get(struct marpa_rule*rule){
return rule->symbols+1;}
/*:242*//*244:*/
#line 1745 "./marpa.w"

Marpa_Symbol_ID*marpa_rule_rhs_peek(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*323:*/
#line 2066 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return NULL;
}

/*:323*/
#line 1747 "./marpa.w"

return rule_rhs_get(rule_id2p(g,rule_id));}
/*:244*//*246:*/
#line 1751 "./marpa.w"

static inline gsize rule_length_get(struct marpa_rule*rule){
return rule->length;}
/*:246*//*248:*/
#line 1756 "./marpa.w"

gsize marpa_rule_length(struct marpa_g*g,Marpa_Rule_ID rule_id){
/*322:*/
#line 2059 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:322*/
#line 1758 "./marpa.w"

return rule_length_get(rule_id2p(g,rule_id));}
/*:248*//*250:*/
#line 1763 "./marpa.w"

static inline Marpa_Symbol_ID
lhs_symbol_id(struct marpa_rule*rule){return rule->symbols[0];}
/*:250*//*252:*/
#line 1768 "./marpa.w"

static inline Marpa_Symbol_ID
rhs_symbol_id(struct marpa_rule*rule,gint index){
return rule->symbols[index+1];
}
/*:252*//*259:*/
#line 1794 "./marpa.w"

gboolean marpa_rule_is_discard_separation(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_discard;}
/*:259*//*263:*/
#line 1827 "./marpa.w"

static inline gint rule_is_accessible(struct marpa_g*g,struct marpa_rule*rule)
{
Marpa_Symbol_ID lhs_id= lhs_symbol_id(rule);
return symbol_id2p(g,lhs_id)->is_accessible;}
gint marpa_rule_is_accessible(struct marpa_g*g,Marpa_Rule_ID rule_id)
{struct marpa_rule*rule;
/*322:*/
#line 2059 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:322*/
#line 1834 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_accessible(g,rule);
}
/*:263*//*267:*/
#line 1845 "./marpa.w"

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
/*322:*/
#line 2059 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:322*/
#line 1856 "./marpa.w"

rule= rule_id2p(g,rule_id);
return rule_is_productive(g,rule);
}
/*:267*//*273:*/
#line 1876 "./marpa.w"

gint marpa_rule_is_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{/*322:*/
#line 2059 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:322*/
#line 1878 "./marpa.w"

return rule_id2p(g,rule_id)->is_loop;}
/*:273*//*278:*/
#line 1895 "./marpa.w"

gint marpa_rule_is_virtual_loop(struct marpa_g*g,Marpa_Rule_ID rule_id)
{/*322:*/
#line 2059 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:322*/
#line 1897 "./marpa.w"

return rule_id2p(g,rule_id)->is_virtual_loop;}
/*:278*//*281:*/
#line 1905 "./marpa.w"

static inline gint rule_is_nulling(struct marpa_g*g,struct marpa_rule*rule)
{
gint rh_ix;
for(rh_ix= 0;rh_ix<rule->length;rh_ix++){
Marpa_Symbol_ID rhs_id= rhs_symbol_id(rule,rh_ix);
if(!symbol_id2p(g,rhs_id)->is_nulling)return FALSE;
}
return TRUE;}
/*:281*//*285:*/
#line 1923 "./marpa.w"

gint marpa_rule_is_used(struct marpa_g*g,Marpa_Rule_ID rule_id)
{/*322:*/
#line 2059 "./marpa.w"

if(!rule_is_valid(g,rule_id)){
context_int_add(g,"rule_id",rule_id);
g->error= "invalid rule id";
return-1;
}

/*:322*/
#line 1925 "./marpa.w"

return rule_id2p(g,rule_id)->is_used;}
/*:285*//*289:*/
#line 1950 "./marpa.w"

gboolean marpa_rule_is_virtual_lhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_lhs;}
/*:289*//*293:*/
#line 1961 "./marpa.w"

gboolean marpa_rule_is_virtual_rhs(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->is_virtual_rhs;}
/*:293*//*302:*/
#line 1993 "./marpa.w"

void marpa_rule_callback_set(struct marpa_g*g,Marpa_Rule_Callback*cb)
{g->rule_callback= cb;}
/*:302*//*304:*/
#line 1998 "./marpa.w"

void marpa_rule_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->rule_callback_arg= cb_arg;}
/*:304*//*306:*/
#line 2003 "./marpa.w"

void*marpa_rule_callback_arg_peek(struct marpa_g*g)
{return g->rule_callback_arg;}
/*:306*//*308:*/
#line 2009 "./marpa.w"

static inline rule_callback(struct marpa_g*g,Marpa_Rule_ID id)
{Marpa_Rule_Callback*cb= g->rule_callback;
if(cb){(*cb)(g,id);}}
/*:308*//*313:*/
#line 2022 "./marpa.w"

Marpa_Rule_ID marpa_rule_original(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->original;}

/*:313*//*317:*/
#line 2034 "./marpa.w"

gint marpa_real_symbol_count(struct marpa_g*g,Marpa_Rule_ID id)
{return rule_id2p(g,id)->real_symbol_count;}

/*:317*//*320:*/
#line 2051 "./marpa.w"

Marpa_Rule_ID marpa_rule_semantic_equivalent(struct marpa_g*g,Marpa_Rule_ID id)
{
struct marpa_rule*rewrite_rule= rule_id2p(g,id);
return rewrite_rule->is_semantic_equivalent?rewrite_rule->original:-1;}
/*:320*//*324:*/
#line 2084 "./marpa.w"

struct marpa_g*marpa_precompute(struct marpa_g*g)
{
if(!census(g))return NULL;
if(!g->is_academic){
if(!CHAF_rewrite(g))return NULL;
if(!g_augment(g))return NULL;
loop_detect(g);
}else{
/*326:*/
#line 2100 "./marpa.w"

Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<g->rules->len;rule_id++)
{rule_id2p(g,rule_id)->is_used= 1;}

/*:326*/
#line 2093 "./marpa.w"

}
return g;
}
/*:324*//*328:*/
#line 2137 "./marpa.w"

static inline struct marpa_g*census(struct marpa_g*g)
{
/*330:*/
#line 2169 "./marpa.w"

gint pre_rewrite_rule_count= g->rules->len;
gint pre_rewrite_symbol_count= g->symbols->len;

/*:330*//*335:*/
#line 2202 "./marpa.w"

Marpa_Symbol_ID original_start_symbol_id= g->start_symbol;
struct marpa_symbol*original_start_symbol;

/*:335*//*339:*/
#line 2235 "./marpa.w"

Bit_Vector terminal_v;
gboolean have_marked_terminals= 0;

/*:339*//*345:*/
#line 2293 "./marpa.w"

Bit_Vector lhs_v;
Bit_Vector empty_lhs_v;
gboolean have_empty_rule= 0;

/*:345*//*347:*/
#line 2318 "./marpa.w"

Bit_Vector nullable_v;
/*:347*//*351:*/
#line 2341 "./marpa.w"

Bit_Vector productive_v;
/*:351*//*356:*/
#line 2394 "./marpa.w"

Bit_Vector accessible_v;

/*:356*/
#line 2140 "./marpa.w"

/*331:*/
#line 2173 "./marpa.w"

if(g->rules->len<=0){g->error= "no rules";return NULL;}
/*:331*/
#line 2141 "./marpa.w"

/*332:*/
#line 2180 "./marpa.w"

if(g->is_precomputed){g->error= "precomputed";return NULL;}
/*:332*/
#line 2142 "./marpa.w"

/*334:*/
#line 2186 "./marpa.w"

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
/*:334*/
#line 2143 "./marpa.w"

/*336:*/
#line 2206 "./marpa.w"

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
/*:336*/
#line 2144 "./marpa.w"

/*337:*/
#line 2223 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
terminal_v= bv_create(pre_rewrite_symbol_count);
for(symbol_id= 0;symbol_id<pre_rewrite_symbol_count;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_terminal){
bv_bit_set(terminal_v,symbol_id);
have_marked_terminals= 1;
}
}}
/*:337*/
#line 2145 "./marpa.w"

if(have_marked_terminals){
/*341:*/
#line 2250 "./marpa.w"

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

/*:341*/
#line 2147 "./marpa.w"

}else{
/*340:*/
#line 2239 "./marpa.w"

if(have_empty_rule&&g->is_lhs_terminal_ok){
g->error= "empty rule and unmarked terminals";
return NULL;
}
/*:340*/
#line 2149 "./marpa.w"
;
if(g->is_lhs_terminal_ok){
/*342:*/
#line 2273 "./marpa.w"

{Marpa_Symbol_ID symbol_id;
bv_fill(terminal_v);
for(symbol_id= 0;symbol_id<g->symbols->len;symbol_id++)
{symbol_id2p(g,symbol_id)->is_terminal= 1;}}
/*:342*/
#line 2151 "./marpa.w"

}else{
/*343:*/
#line 2278 "./marpa.w"

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
/*:343*/
#line 2153 "./marpa.w"

}
}
/*346:*/
#line 2298 "./marpa.w"

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
/*:346*/
#line 2156 "./marpa.w"

/*349:*/
#line 2323 "./marpa.w"

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
/*:349*/
#line 2157 "./marpa.w"

/*350:*/
#line 2334 "./marpa.w"

if(!bv_bit_test(productive_v,g->start_symbol))
{
context_int_add(g,"symbol_id",g->start_symbol);
g->error= "unproductive start symbol";
return NULL;
}
/*:350*/
#line 2158 "./marpa.w"

/*353:*/
#line 2364 "./marpa.w"

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
/*:353*/
#line 2159 "./marpa.w"

/*355:*/
#line 2383 "./marpa.w"

accessible_v= matrix_row(reach_matrix,original_start_symbol_id);
{gint min,max,start,symbol_id;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2){
for(symbol_id= min;symbol_id<=max;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
symbol->is_accessible= 1;
}}
}
/*:355*/
#line 2160 "./marpa.w"

/*357:*/
#line 2399 "./marpa.w"

{Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
gint min,max,start;
for(start= 0;bv_scan(productive_v,start,&min,&max);start= max+2){
Marpa_Symbol_ID productive_id;
for(productive_id= min;productive_id<=max;productive_id++){
bv_and(reaches_terminal_v,terminal_v,matrix_row(reach_matrix,productive_id));
if(bv_is_empty(reaches_terminal_v))symbol_id2p(g,productive_id)->is_nulling= 1;
}}
bv_free(reaches_terminal_v);}

/*:357*/
#line 2161 "./marpa.w"

/*338:*/
#line 2233 "./marpa.w"

bv_free(terminal_v);
/*:338*//*344:*/
#line 2290 "./marpa.w"

bv_free(lhs_v);
bv_free(empty_lhs_v);
/*:344*//*348:*/
#line 2320 "./marpa.w"

bv_free(nullable_v);

/*:348*//*352:*/
#line 2343 "./marpa.w"

bv_free(productive_v);

/*:352*/
#line 2162 "./marpa.w"

/*354:*/
#line 2380 "./marpa.w"

matrix_free(reach_matrix);

/*:354*/
#line 2163 "./marpa.w"

g->is_precomputed= TRUE;
return g;
}
/*:328*//*364:*/
#line 2467 "./marpa.w"

static inline struct marpa_g*CHAF_rewrite(struct marpa_g*g)
{
/*366:*/
#line 2490 "./marpa.w"

Marpa_Rule_ID rule_id;
gint no_of_rules;

/*:366*//*370:*/
#line 2541 "./marpa.w"

gint factor_count;
gint*factor_positions;
/*:370*//*375:*/
#line 2590 "./marpa.w"

Marpa_Symbol_ID*piece_rhs;
Marpa_Symbol_ID*remaining_rhs;
/*:375*/
#line 2470 "./marpa.w"

/*371:*/
#line 2544 "./marpa.w"

factor_positions= g_new(gint,g->max_rule_length);
/*:371*//*376:*/
#line 2593 "./marpa.w"

piece_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
remaining_rhs= g_new(Marpa_Symbol_ID,g->max_rule_length);
/*:376*/
#line 2471 "./marpa.w"

/*368:*/
#line 2502 "./marpa.w"

{gint no_of_symbols= symbol_count(g);
Marpa_Symbol_ID symbol_id;
for(symbol_id= 0;symbol_id<no_of_symbols;symbol_id++){
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
struct marpa_symbol*alias;
if(!symbol->is_nullable)continue;
if(symbol->is_nulling)continue;
if(!symbol->is_accessible)continue;
if(!symbol->is_productive)continue;
if(symbol_null_alias(symbol))continue;
alias= symbol_alias_create(g,symbol);
symbol_callback(g,alias->id);
}}

/*:368*/
#line 2472 "./marpa.w"

no_of_rules= rule_count(g);
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
gint rule_length= rule->length;
gint nullable_suffix_ix= 0;
/*367:*/
#line 2494 "./marpa.w"

if(!rule->is_used){goto NEXT_RULE;}
if(rule_is_nulling(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_accessible(g,rule)){rule->is_used= 0;goto NEXT_RULE;}
if(!rule_is_productive(g,rule)){rule->is_used= 0;goto NEXT_RULE;}

/*:367*/
#line 2478 "./marpa.w"

/*369:*/
#line 2525 "./marpa.w"

{gint rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_nulling)continue;
if(symbol_null_alias(symbol)){

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}}
/*:369*/
#line 2479 "./marpa.w"


if(factor_count<=0)goto NEXT_RULE;
/*373:*/
#line 2550 "./marpa.w"

rule->is_used= 0;
{gint unprocessed_factor_count;

gint factor_position_ix= 0;
Marpa_Symbol_ID current_lhs_id= lhs_symbol_id(rule);
gint piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*379:*/
#line 2603 "./marpa.w"

Marpa_Symbol_ID chaf_virtual_symbol_id;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;

/*374:*/
#line 2569 "./marpa.w"
{
struct marpa_symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
context_clear(g);
context_int_add(g,"rule_id",rule_id);
context_int_add(g,"lhs_id",lhs_symbol_id(rule));
context_int_add(g,"virtual_end",piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:374*/
#line 2611 "./marpa.w"

/*380:*/
#line 2630 "./marpa.w"

{
gint remaining_rhs_length,piece_rhs_length;
/*381:*/
#line 2642 "./marpa.w"

{
gint real_symbol_count= piece_end-piece_start+1;
for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
remaining_rhs[piece_rhs_length]= 
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
}
{struct marpa_rule*chaf_rule;
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2654 "./marpa.w"

}

/*:381*/
#line 2633 "./marpa.w"
;
/*382:*/
#line 2657 "./marpa.w"

{gint piece_rhs_ix;
gint chaf_rule_length= rule->length-piece_start;
for(remaining_rhs_length= piece_rhs_length-1;
remaining_rhs_length<chaf_rule_length;
remaining_rhs_length++){
Marpa_Symbol_ID original_id= rhs_symbol_id(rule,piece_start+remaining_rhs_length);
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,original_id));
remaining_rhs[remaining_rhs_length]= alias?alias->id:original_id;
}}
{struct marpa_rule*chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2670 "./marpa.w"

}

/*:382*/
#line 2634 "./marpa.w"
;
/*383:*/
#line 2675 "./marpa.w"
{
Marpa_Symbol_ID proper_id= rhs_symbol_id(rule,first_factor_position);
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
gint first_factor_piece_position= first_factor_position-piece_start;
remaining_rhs[first_factor_piece_position]= 
piece_rhs[first_factor_piece_position]= 
alias->id;
}
{struct marpa_rule*chaf_rule;
gint real_symbol_count= piece_rhs_length-1;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2686 "./marpa.w"

}

/*:383*/
#line 2635 "./marpa.w"
;
/*384:*/
#line 2695 "./marpa.w"

if(piece_start<nullable_suffix_ix){
struct marpa_rule*chaf_rule;
gint real_symbol_count= remaining_rhs_length;
chaf_rule= rule_start(g,current_lhs_id,remaining_rhs,remaining_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2700 "./marpa.w"

}

/*:384*/
#line 2636 "./marpa.w"
;
}

/*:380*/
#line 2612 "./marpa.w"

factor_position_ix++;
}else{
gint second_factor_piece_position= second_factor_position-piece_start;
piece_end= second_factor_position;
/*374:*/
#line 2569 "./marpa.w"
{
struct marpa_symbol*chaf_virtual_symbol= symbol_new(g);
chaf_virtual_symbol->is_accessible= 1;
chaf_virtual_symbol->is_productive= 1;
chaf_virtual_symbol_id= chaf_virtual_symbol->id;
context_clear(g);
context_int_add(g,"rule_id",rule_id);
context_int_add(g,"lhs_id",lhs_symbol_id(rule));
context_int_add(g,"virtual_end",piece_end);
symbol_callback(g,chaf_virtual_symbol_id);
}

/*:374*/
#line 2617 "./marpa.w"

/*386:*/
#line 2705 "./marpa.w"
{
gint piece_rhs_length;
struct marpa_rule*chaf_rule;
gint real_symbol_count;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
real_symbol_count= piece_end-piece_start+1;

/*:386*//*387:*/
#line 2714 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
piece_rhs[piece_rhs_length++]= chaf_virtual_symbol_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2720 "./marpa.w"


/*:387*//*388:*/
#line 2723 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2728 "./marpa.w"


/*:388*//*389:*/
#line 2731 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2737 "./marpa.w"


/*:389*//*390:*/
#line 2740 "./marpa.w"

piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2743 "./marpa.w"


/*:390*//*391:*/
#line 2746 "./marpa.w"
}

/*:391*/
#line 2618 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_id= chaf_virtual_symbol_id;
piece_start= piece_end+1;

/*:379*/
#line 2561 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*392:*/
#line 2750 "./marpa.w"
{
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= first_factor_position-piece_start;
gint second_factor_position= factor_positions[factor_position_ix+1];
gint second_factor_piece_position= second_factor_position-piece_start;
gint real_symbol_count;
gint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,second_factor_proper_id,
first_factor_alias_id,second_factor_alias_id;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:392*//*393:*/
#line 2764 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2769 "./marpa.w"


/*:393*//*394:*/
#line 2772 "./marpa.w"

second_factor_proper_id= rhs_symbol_id(rule,second_factor_position);
piece_rhs[second_factor_piece_position]
= second_factor_alias_id= alias_by_id(g,second_factor_proper_id);
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2777 "./marpa.w"


/*:394*//*395:*/
#line 2780 "./marpa.w"

first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
piece_rhs[first_factor_piece_position]
= first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[second_factor_piece_position]= second_factor_proper_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2786 "./marpa.w"


/*:395*//*396:*/
#line 2790 "./marpa.w"

if(piece_start<nullable_suffix_ix){
piece_rhs[second_factor_piece_position]= second_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2794 "./marpa.w"

}

/*:396*//*397:*/
#line 2798 "./marpa.w"
}

/*:397*/
#line 2564 "./marpa.w"

}else{
/*398:*/
#line 2801 "./marpa.w"
{
gint piece_rhs_length;
struct marpa_rule*chaf_rule;
Marpa_Symbol_ID first_factor_proper_id,first_factor_alias_id;
gint real_symbol_count;
gint first_factor_position= factor_positions[factor_position_ix];
gint first_factor_piece_position= factor_positions[factor_position_ix]-piece_start;
piece_end= rule->length-1;
real_symbol_count= piece_end-piece_start+1;

/*:398*//*399:*/
#line 2812 "./marpa.w"

for(piece_rhs_length= 0;piece_rhs_length<real_symbol_count;piece_rhs_length++){
piece_rhs[piece_rhs_length]= rhs_symbol_id(rule,piece_start+piece_rhs_length);
}
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2817 "./marpa.w"


/*:399*//*400:*/
#line 2821 "./marpa.w"

if(piece_start<nullable_suffix_ix){
first_factor_proper_id= rhs_symbol_id(rule,first_factor_position);
first_factor_alias_id= alias_by_id(g,first_factor_proper_id);
piece_rhs[first_factor_piece_position]= first_factor_alias_id;
chaf_rule= rule_start(g,current_lhs_id,piece_rhs,piece_rhs_length);
/*402:*/
#line 2837 "./marpa.w"

chaf_rule->is_used= 1;
chaf_rule->original= rule_id;
chaf_rule->is_virtual_lhs= piece_start> 0;
chaf_rule->is_semantic_equivalent= !chaf_rule->is_virtual_lhs;
chaf_rule->is_virtual_rhs= chaf_rule->length> real_symbol_count;
chaf_rule->virtual_start= piece_start;
chaf_rule->virtual_end= piece_start+real_symbol_count-1;
chaf_rule->real_symbol_count= real_symbol_count;
rule_callback(g,chaf_rule->id);

/*:402*/
#line 2827 "./marpa.w"

}

/*:400*//*401:*/
#line 2831 "./marpa.w"
}

/*:401*/
#line 2566 "./marpa.w"

}}

/*:373*/
#line 2482 "./marpa.w"

NEXT_RULE:;
}
/*372:*/
#line 2546 "./marpa.w"

g_free(factor_positions);

/*:372*//*377:*/
#line 2596 "./marpa.w"

g_free(piece_rhs);
g_free(remaining_rhs);

/*:377*/
#line 2485 "./marpa.w"

return g;
}
/*:364*//*403:*/
#line 2851 "./marpa.w"

static inline
Marpa_Symbol_ID alias_by_id(struct marpa_g*g,Marpa_Symbol_ID proper_id){
struct marpa_symbol*alias= symbol_null_alias(symbol_id2p(g,proper_id));
return alias->id;
}
/*:403*//*406:*/
#line 2865 "./marpa.w"

static inline
struct marpa_g*g_augment(struct marpa_g*g){
Marpa_Symbol_ID proper_new_start_id= -1;
struct marpa_symbol*proper_old_start= NULL;
struct marpa_symbol*nulling_old_start= NULL;
struct marpa_symbol*proper_new_start= NULL;
struct marpa_symbol*old_start= symbol_id2p(g,g->start_symbol);
/*408:*/
#line 2881 "./marpa.w"

if(old_start->is_nulling){
old_start->is_accessible= 0;
nulling_old_start= old_start;
}else{
proper_old_start= old_start;
nulling_old_start= symbol_null_alias(old_start);
}
old_start->is_start= 0;

/*:408*/
#line 2873 "./marpa.w"

if(proper_old_start){/*409:*/
#line 2891 "./marpa.w"
{
struct marpa_rule*new_start_rule;
proper_old_start->is_start= 0;
proper_new_start= symbol_new(g);
proper_new_start_id= proper_new_start->id;
g->start_symbol= proper_new_start_id;
proper_new_start->is_accessible= TRUE;
proper_new_start->is_productive= TRUE;
proper_new_start->is_start= TRUE;
context_clear(g);
context_int_add(g,"old_start_id",old_start->id);
symbol_callback(g,proper_new_start_id);
new_start_rule= rule_start(g,proper_new_start_id,&old_start->id,1);
new_start_rule->is_virtual_lhs= 1;
new_start_rule->real_symbol_count= 1;
new_start_rule->is_used= TRUE;
rule_callback(g,new_start_rule->id);
}

/*:409*/
#line 2874 "./marpa.w"
}
if(nulling_old_start){/*410:*/
#line 2914 "./marpa.w"
{
Marpa_Symbol_ID nulling_new_start_id;
struct marpa_rule*new_start_rule;
struct marpa_symbol*nulling_new_start;
if(proper_new_start){
nulling_new_start= symbol_alias_create(g,proper_new_start);
nulling_new_start_id= nulling_new_start->id;
}else{
nulling_new_start= symbol_new(g);
nulling_new_start_id= nulling_new_start->id;
g->start_symbol= nulling_new_start_id;
nulling_new_start->is_nulling= TRUE;
nulling_new_start->is_nullable= TRUE;
nulling_new_start->is_productive= TRUE;
nulling_new_start->is_accessible= TRUE;
}
nulling_new_start->is_start= TRUE;
context_clear(g);
context_int_add(g,"old_start_id",old_start->id);
symbol_callback(g,nulling_new_start_id);
new_start_rule= rule_start(g,nulling_new_start_id,0,0);
new_start_rule->is_virtual_lhs= 1;
new_start_rule->real_symbol_count= 1;
new_start_rule->is_used= TRUE;
rule_callback(g,new_start_rule->id);
}

/*:410*/
#line 2875 "./marpa.w"
}
return g;
}
/*:406*//*414:*/
#line 2981 "./marpa.w"

static inline
void loop_detect(struct marpa_g*g)
{gint rule_id,no_of_rules= rule_count(g);
gint loop_rule_count= 0;
Bit_Matrix unit_transition_matrix
= matrix_create(no_of_rules,no_of_rules);
/*416:*/
#line 3004 "./marpa.w"

for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule= rule_id2p(g,rule_id);
Marpa_Symbol_ID proper_id;
Marpa_Symbol_ID lhs_id;
gint rhs_ix,rule_length;
if(!rule->is_used)continue;
rule_length= rule->length;
proper_id= -1;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++){
Marpa_Symbol_ID symbol_id= rhs_symbol_id(rule,rhs_ix);
struct marpa_symbol*symbol= symbol_id2p(g,symbol_id);
if(symbol->is_nullable)continue;
if(proper_id>=0)goto NEXT_RULE;

proper_id= symbol_id;
}

if(proper_id<0)continue;

{struct marpa_symbol*rhs_symbol= symbol_id2p(g,proper_id);
GArray*lhs_rules= rhs_symbol->lhs;
gint ix,no_of_lhs_rules= lhs_rules->len;
for(ix= 0;ix<no_of_lhs_rules;ix++){


matrix_bit_set(unit_transition_matrix,rule_id,
g_array_index(lhs_rules,Marpa_Rule_ID,ix));
}}
NEXT_RULE:;
}

/*:416*/
#line 2988 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*417:*/
#line 3043 "./marpa.w"
{Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<no_of_rules;rule_id++){
struct marpa_rule*rule;
if(!matrix_bit_test(unit_transition_matrix,rule_id,rule_id))continue;
loop_rule_count++;
rule= rule_id2p(g,rule_id);
rule->is_loop= TRUE;
rule->is_virtual_loop= rule->virtual_start<0||!rule->is_virtual_rhs;
context_clear(g);
context_int_add(g,"rule_id",rule_id);
message(g,"loop rule");
}}

/*:417*/
#line 2990 "./marpa.w"

if(loop_rule_count)g->has_loop= TRUE;
/*418:*/
#line 3063 "./marpa.w"

context_clear(g);
context_int_add(g,"loop_rule_count",loop_rule_count);
message(g,"loop rule tally");

/*:418*/
#line 2992 "./marpa.w"

matrix_free(unit_transition_matrix);
}
/*:414*//*420:*/
#line 3098 "./marpa.w"

struct marpa_earley_item*marpa_earley_item_new(void)
{struct marpa_earley_item*item= 
g_malloc(sizeof(struct marpa_earley_item));
return item;}
/*:420*//*422:*/
#line 3106 "./marpa.w"

void marpa_earley_item_free(struct marpa_earley_item*item)
{g_free(item);}
/*:422*//*427:*/
#line 3139 "./marpa.w"

static inline guint bv_bits_to_size(gint bits)
{
return(bits+bv_modmask)/bv_wordbits;
}
/*:427*//*429:*/
#line 3147 "./marpa.w"

static inline bv_bits_to_unused_mask(gint bits)
{
guint mask= bits&bv_modmask;
if(mask)mask= (guint)~(~0uL<<mask);else mask= (guint)~0uL;
return(mask);
}
/*:429*//*431:*/
#line 3163 "./marpa.w"

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
/*:431*//*433:*/
#line 3180 "./marpa.w"

static inline Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create(BV_BITS(bv));
}
/*:433*//*435:*/
#line 3192 "./marpa.w"

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
/*:435*//*437:*/
#line 3211 "./marpa.w"

static inline void bv_free(Bit_Vector vector){
vector-= bv_hiddenwords;
g_free(vector);
}
/*:437*//*439:*/
#line 3220 "./marpa.w"

static inline gint bv_bytes(Bit_Vector bv){
return(BV_SIZE(bv)+bv_hiddenwords)*sizeof(Bit_Vector_Word);
}
/*:439*//*441:*/
#line 3228 "./marpa.w"

static inline void bv_fill(Bit_Vector bv)
{
guint size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
*(--bv)&= BV_MASK(bv);
}
/*:441*//*444:*/
#line 3240 "./marpa.w"

static inline void bv_bit_set(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}
/*:444*//*446:*/
#line 3248 "./marpa.w"

static inline void bv_bit_clear(Bit_Vector vector,gint bit){
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}
/*:446*//*448:*/
#line 3256 "./marpa.w"

static inline gboolean bv_bit_test(Bit_Vector vector,gint bit){
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}
/*:448*//*451:*/
#line 3265 "./marpa.w"

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
/*:451*//*453:*/
#line 3280 "./marpa.w"

static inline void bv_not(Bit_Vector X,Bit_Vector Y)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}
/*:453*//*455:*/
#line 3292 "./marpa.w"

static inline void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}
/*:455*//*457:*/
#line 3304 "./marpa.w"

static inline void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
guint size= BV_SIZE(X);
guint mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}
/*:457*//*459:*/
#line 3316 "./marpa.w"

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
/*:459*//*465:*/
#line 3428 "./marpa.w"

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
/*:465*//*470:*/
#line 3497 "./marpa.w"

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
/*:470*//*472:*/
#line 3517 "./marpa.w"

static inline void matrix_free(Bit_Matrix matrix){
g_free(matrix);
}
/*:472*//*474:*/
#line 3530 "./marpa.w"

static inline gint matrix_columns(Bit_Matrix matrix){
Bit_Vector row0= matrix+bv_hiddenwords;
return BV_BITS(row0);
}
/*:474*//*476:*/
#line 3547 "./marpa.w"

static inline Bit_Vector matrix_row(Bit_Matrix matrix,gint row){
Bit_Vector row0= matrix+bv_hiddenwords;
guint words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+row*words_per_row;
}
/*:476*//*479:*/
#line 3557 "./marpa.w"

static inline void matrix_bit_set(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}
/*:479*//*482:*/
#line 3566 "./marpa.w"

static inline void matrix_bit_clear(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}
/*:482*//*485:*/
#line 3575 "./marpa.w"

static inline gboolean matrix_bit_test(Bit_Matrix matrix,gint row,gint column){
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}
/*:485*//*487:*/
#line 3589 "./marpa.w"

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
/*:487*//*492:*/
#line 3692 "./marpa.w"

static inline gpointer dstack_resize(struct dstack*this,gsize type_bytes){
this->size*= 2;
this->base= g_realloc(this->base,this->size*type_bytes);
return this->base;
}
/*:492*//*500:*/
#line 3763 "./marpa.w"

void marpa_message_callback_set(struct marpa_g*g,Marpa_Message_Callback*cb)
{g->message_callback= cb;}
void marpa_message_callback_arg_set(struct marpa_g*g,void*cb_arg)
{g->message_callback_arg= cb_arg;}
void*marpa_message_callback_arg_peek(struct marpa_g*g)
{return g->message_callback_arg;}
/*:500*//*502:*/
#line 3775 "./marpa.w"

static inline message(struct marpa_g*g,Marpa_Message_ID id)
{Marpa_Message_Callback*cb= g->message_callback;
if(cb){(*cb)(g,id);}}
/*:502*//*505:*/
#line 3790 "./marpa.w"



const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
int marpa_effective_micro= 1000*MARPA_MINOR_VERSION+MARPA_MICRO_VERSION;
int required_effective_micro= 1000*required_minor+required_micro;
static char output_buffer[1000];

/*507:*/
#line 3820 "./marpa.w"


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

/*:507*/
#line 3802 "./marpa.w"

/*508:*/
#line 3836 "./marpa.w"


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


/*:508*/
#line 3803 "./marpa.w"

/*509:*/
#line 3854 "./marpa.w"


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


/*:509*/
#line 3804 "./marpa.w"

/*510:*/
#line 3872 "./marpa.w"

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

/*:510*/
#line 3805 "./marpa.w"


return"Perfect!";
}

/*:505*/
#line 3995 "./marpa.w"





/*:517*/
