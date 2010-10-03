/*42:*/
#line 605 "./marpa.w"

/*41:*/
#line 582 "./marpa.w"

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

/*:41*/
#line 606 "./marpa.w"

#define EVENTUALLY_INLINE  \

#define obstack_chunk_alloc g_malloc
#define obstack_chunk_free g_free \
 \


#line 607 "./marpa.w"

/*2:*/
#line 59 "./marpa.w"


#include "config.h"
#include "marpa.h"

/*:2*//*4:*/
#line 77 "./marpa.w"


/*32:*/
#line 429 "./marpa.w"


#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:32*/
#line 79 "./marpa.w"

/*32:*/
#line 429 "./marpa.w"


#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "Marpa"

/*:32*/
#line 80 "./marpa.w"

/*6:*/
#line 91 "./marpa.w"


const unsigned int marpa_major_version= MARPA_MAJOR_VERSION;
const unsigned int marpa_minor_version= MARPA_MINOR_VERSION;
const unsigned int marpa_micro_version= MARPA_MICRO_VERSION;
const unsigned int marpa_interface_age= MARPA_INTERFACE_AGE;
const unsigned int marpa_binary_age= MARPA_BINARY_AGE;

/*:6*/
#line 81 "./marpa.w"


/*:4*//*5:*/
#line 85 "./marpa.w"


/*25:*/
#line 334 "./marpa.w"


struct marpa_token_link{
struct marpa_token_link*next;
struct marpa_earley_item*predecessor;
struct marpa_symbol*symbol;
void*value;
};

/*:25*//*28:*/
#line 381 "./marpa.w"


struct marpa_cause_link{
struct marpa_cause_link*next;
struct marpa_earley_item*predecessor;
struct marpa_earley_item*cause;
};

/*:28*/
#line 87 "./marpa.w"


/*:5*//*7:*/
#line 101 "./marpa.w"


void marpa_version(int*version){
version[0]= MARPA_MAJOR_VERSION;
version[1]= MARPA_MINOR_VERSION,
version[2]= MARPA_MICRO_VERSION;
}

/*:7*//*12:*/
#line 182 "./marpa.w"


/*:12*//*17:*/
#line 217 "./marpa.w"


void marpa_r_init(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

obstack_init(&recce->stack);

return;

}

/*:17*//*19:*/
#line 239 "./marpa.w"


void marpa_r_destroy(struct marpa_r*recce)
{
obstack_free(&recce->stack,(void*)NULL);
}

/*:19*//*22:*/
#line 302 "./marpa.w"


EVENTUALLY_INLINE
struct marpa_earley_item*marpa_earley_item_new(struct marpa_r*recce)
{
if(recce==(void*)NULL){
g_error("EIF No alloc routine in marpa allocator");
}

struct marpa_earley_item*item= 
obstack_alloc(&recce->stack,sizeof(struct marpa_earley_item));
item->token_links= NULL;
item->cause_links= NULL;
item->leo_links= NULL;

return item;

}

/*:22*//*26:*/
#line 345 "./marpa.w"


EVENTUALLY_INLINE
void
marpa_token_link_add(
struct marpa_r*recce,
struct marpa_earley_item*item,
struct marpa_symbol*symbol,
struct marpa_earley_item*predecessor,
void*value
)
{
struct marpa_token_link*next= item->token_links;
struct marpa_token_link*new= item->token_links= 
obstack_alloc(&recce->stack,sizeof(*next));
new->next= next;
new->symbol= symbol;
new->predecessor= predecessor;
new->value= value;
}

/*:26*//*29:*/
#line 391 "./marpa.w"


EVENTUALLY_INLINE
void
marpa_cause_link_add(
struct marpa_r*recce,
struct marpa_earley_item*item,
struct marpa_earley_item*predecessor,
struct marpa_earley_item*cause
)
{
struct marpa_cause_link*next= item->cause_links;
struct marpa_cause_link*new= item->cause_links= 
obstack_alloc(&recce->stack,sizeof(*next));
new->next= next;
new->predecessor= predecessor;
new->cause= cause;
}

/*:29*//*35:*/
#line 477 "./marpa.w"


static char output_buffer[1000];

const char*
marpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
int marpa_effective_micro= 1000*MARPA_MINOR_VERSION+MARPA_MICRO_VERSION;
int required_effective_micro= 1000*required_minor+required_micro;

/*37:*/
#line 507 "./marpa.w"


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

/*:37*/
#line 489 "./marpa.w"

/*38:*/
#line 523 "./marpa.w"


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


/*:38*/
#line 490 "./marpa.w"

/*39:*/
#line 541 "./marpa.w"


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


/*:39*/
#line 491 "./marpa.w"

/*40:*/
#line 559 "./marpa.w"

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

/*:40*/
#line 492 "./marpa.w"


return"Perfect!";
}

/*:35*/
#line 608 "./marpa.w"


/*:42*/
