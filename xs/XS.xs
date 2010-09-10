#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "utils.h"

MODULE = Marpa::XS        PACKAGE = Marpa::XS::Internal

PROTOTYPES: DISABLE

const char *
libmarpa_check_version (required_major, required_minor, required_micro)
    unsigned int required_major
    unsigned int required_minor
    unsigned int required_micro

