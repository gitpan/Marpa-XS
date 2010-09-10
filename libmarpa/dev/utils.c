/*1:*/
#line 47 "./utils.w"


#include <glib.h> 
#include <stdio.h> 

#include "config.h"
#include "utils.h"

const unsigned int libmarpa_major_version= LIBMARPA_MAJOR_VERSION;
const unsigned int libmarpa_minor_version= LIBMARPA_MINOR_VERSION;
const unsigned int libmarpa_micro_version= LIBMARPA_MICRO_VERSION;
const unsigned int libmarpa_interface_age= LIBMARPA_INTERFACE_AGE;
const unsigned int libmarpa_binary_age= LIBMARPA_BINARY_AGE;

/*:1*//*2:*/
#line 88 "./utils.w"


static char output_buffer[1000];

const char*
libmarpa_check_version(unsigned int required_major,
unsigned int required_minor,
unsigned int required_micro)
{
int libmarpa_effective_micro= 1000*LIBMARPA_MINOR_VERSION+LIBMARPA_MICRO_VERSION;
int required_effective_micro= 1000*required_minor+required_micro;

if(required_major> LIBMARPA_MAJOR_VERSION){
sprintf(output_buffer,"libmarpa major version too old: "
"require %d.%03d%03d, but have %d.%03d%03d",
required_major,
required_minor,
required_micro,
LIBMARPA_MAJOR_VERSION,
LIBMARPA_MINOR_VERSION,
LIBMARPA_MICRO_VERSION);
return output_buffer;
}

if(required_major<LIBMARPA_MAJOR_VERSION){
sprintf(output_buffer,
"libmarpa major version too new: "
"require %d.%03d%03d, but have %d.%03d%03d",
required_major,
required_minor,
required_micro,
LIBMARPA_MAJOR_VERSION,
LIBMARPA_MINOR_VERSION,
LIBMARPA_MICRO_VERSION);
return output_buffer;
}

/*:2*//*3:*/
#line 129 "./utils.w"


if(required_effective_micro<libmarpa_effective_micro){
sprintf(output_buffer,
"libmarpa minor/micro version too new: "
"require %d.%03d%03d, but have %d.%03d%03d",
required_major,
required_minor,
required_micro,
LIBMARPA_MAJOR_VERSION,
LIBMARPA_MINOR_VERSION,
LIBMARPA_MICRO_VERSION);
return output_buffer;
}

if(required_effective_micro> libmarpa_effective_micro){
sprintf(
output_buffer,
"libmarpa minor/micro version too old: "
"require %d.%03d%03d, but have %d.%03d%03d",
required_major,
required_minor,
required_micro,
LIBMARPA_MAJOR_VERSION,
LIBMARPA_MINOR_VERSION,
LIBMARPA_MICRO_VERSION);
return output_buffer;
}

return"Perfect!";
}
/*:3*/
