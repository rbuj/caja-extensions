/*
 *  image-converter.c
 *
 *  Copyright (C) 2004-2005 Jürg Billeter
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 *  Author: Jürg Billeter <j@bitron.ch>
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <glib/gi18n-lib.h>
#include <libcaja-extension/caja-extension-types.h>

#include "caja-image-converter.h"

static GType type_list[1];

void caja_module_initialize(GTypeModule *module) {
  g_print("Initializing caja-image-converter extension\n");

  caja_image_converter_register_type(module);
  type_list[0] = CAJA_TYPE_IMAGE_CONVERTER;
#ifdef ENABLE_NLS
  bindtextdomain(GETTEXT_PACKAGE, MATELOCALEDIR);
  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
#endif /* ENABLE_NLS */
}

void caja_module_shutdown(void) {
  g_print("Shutting down caja-image-converter extension\n");
}

void caja_module_list_types(const GType **types, int *num_types) {
  *types = type_list;
  *num_types = G_N_ELEMENTS(type_list);
}
