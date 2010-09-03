#ifndef __UTILS_H__
#define __UTILS_H__

#include "glib.h"

/* libmarpa version.
 * we prefix variable declarations so they can
 * properly get exported in windows dlls.
 */
GLIB_VAR const guint libmarpa_major_version;
GLIB_VAR const guint libmarpa_minor_version;
GLIB_VAR const guint libmarpa_micro_version;
GLIB_VAR const guint libmarpa_interface_age;
GLIB_VAR const guint libmarpa_binary_age;

G_CONST_RETURN gchar * libmarpa_check_version (guint required_major,
                                  guint required_minor,
                                  guint required_micro);

#define LIBMARPA_CHECK_VERSION(major,minor,micro)    \
    (LIBMARPA_MAJOR_VERSION > (major) || \
     (LIBMARPA_MAJOR_VERSION == (major) && LIBMARPA_MINOR_VERSION > (minor)) || \
     (LIBMARPA_MAJOR_VERSION == (major) && LIBMARPA_MINOR_VERSION == (minor) && \
      LIBMARPA_MICRO_VERSION >= (micro)))

#endif /* __UTILS_H__ */
