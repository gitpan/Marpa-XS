#include <glib.h>
#include <stdio.h>

#include "config.h"
#include "utils.h"

const guint libmarpa_major_version = LIBMARPA_MAJOR_VERSION;
const guint libmarpa_minor_version = LIBMARPA_MINOR_VERSION;
const guint libmarpa_micro_version = LIBMARPA_MICRO_VERSION;
const guint libmarpa_interface_age = LIBMARPA_INTERFACE_AGE;
const guint libmarpa_binary_age = LIBMARPA_BINARY_AGE;

/**
 * libmarpa_check_version:
 * @required_major: the required major version.
 * @required_minor: the required minor version.
 * @required_micro: the required micro version.
 *
 * Checks that the libmarpa library in use is compatible with the
 * given version. Generally you would pass in the constants
 * #LIBMARPA_MAJOR_VERSION, #LIBMARPA_MINOR_VERSION, #LIBMARPA_MICRO_VERSION
 * as the three arguments to this function; that produces
 * a check that the library in use is compatible with
 * the version of libmarpa the application or module was compiled
 * against.
 *
 * Compatibility is defined by two things: first the version
 * of the running library is newer than the version
 * @required_major.required_minor.@required_micro. Second
 * the running library must be binary compatible with the
 * version @required_major.required_minor.@required_micro
 * (same major version.)
 *
 * Return value: %NULL if the libmarpa library is compatible with the
 *   given version, or a string describing the version mismatch.
 *   The returned string is owned by libmarpa and must not be modified
 *   or freed.
 *
 **/

static char output_buffer[1000];

G_CONST_RETURN gchar *
libmarpa_check_version (guint required_major,
                    guint required_minor,
                    guint required_micro)
{
  gint libmarpa_effective_micro = 1000 * LIBMARPA_MINOR_VERSION + LIBMARPA_MICRO_VERSION;
  gint required_effective_micro = 1000 * required_minor + required_micro;

  if (required_major > LIBMARPA_MAJOR_VERSION) {
    sprintf(output_buffer, "libmarpa major version too old: require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        LIBMARPA_MAJOR_VERSION,
        LIBMARPA_MINOR_VERSION,
        LIBMARPA_MICRO_VERSION);
    return output_buffer;
  }

  if (required_major < LIBMARPA_MAJOR_VERSION) {
    sprintf(output_buffer, "libmarpa major version too new: require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        LIBMARPA_MAJOR_VERSION,
        LIBMARPA_MINOR_VERSION,
        LIBMARPA_MICRO_VERSION);
    return output_buffer;
  }

  /* Not sure what was going on here
   * if (required_effective_micro < libmarpa_effective_micro - LIBMARPA_BINARY_AGE)
   * return "libmarpa version too new (micro mismatch)";
   */

  if (required_effective_micro < libmarpa_effective_micro) {
    sprintf(output_buffer,
        "libmarpa minor/micro version too new: require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        LIBMARPA_MAJOR_VERSION,
        LIBMARPA_MINOR_VERSION,
        LIBMARPA_MICRO_VERSION);
    return output_buffer;
  }

  if (required_effective_micro > libmarpa_effective_micro) {
    sprintf(
        output_buffer,
        "libmarpa minor/micro version too old: require %d.%03d%03d, but have %d.%03d%03d", 
        required_major,
        required_minor,
        required_micro,
        LIBMARPA_MAJOR_VERSION,
        LIBMARPA_MINOR_VERSION,
        LIBMARPA_MICRO_VERSION);
    return output_buffer;
  }

  return "Perfect!";
}

