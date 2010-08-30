#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "glib.h"

#undef G_CONST_RETURN
#define G_CONST_RETURN

#include "utils.h"

MODULE = Marpa::XS        PACKAGE = Marpa::XS::Internal

PROTOTYPES: DISABLE

gchar *
libmarpa_check_version (required_major, required_minor, required_micro)
    guint required_major
    guint required_minor
    guint required_micro

