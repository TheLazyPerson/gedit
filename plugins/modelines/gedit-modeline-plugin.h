/*
 * gedit-modeline-plugin.h
 * Emacs, Kate and Vim-style modelines support for gedit.
 *
 * Copyright (C) 2005-2007 - Steve Frécinaux <code@istique.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GEDIT_MODELINE_PLUGIN_H__
#define __GEDIT_MODELINE_PLUGIN_H__

#include <glib.h>
#include <glib-object.h>
#include <libpeas/peas-extension-base.h>
#include <libpeas/peas-object-module.h>

G_BEGIN_DECLS

#define GEDIT_TYPE_MODELINE_PLUGIN		(gedit_modeline_plugin_get_type ())
#define GEDIT_MODELINE_PLUGIN(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), GEDIT_TYPE_MODELINE_PLUGIN, GeditModelinePlugin))
#define GEDIT_MODELINE_PLUGIN_CLASS(k)		(G_TYPE_CHECK_CLASS_CAST((k), GEDIT_TYPE_MODELINE_PLUGIN, GeditModelinePluginClass))
#define GEDIT_IS_MODELINE_PLUGIN(o)		(G_TYPE_CHECK_INSTANCE_TYPE ((o), GEDIT_TYPE_MODELINE_PLUGIN))
#define GEDIT_IS_MODELINE_PLUGIN_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), GEDIT_TYPE_MODELINE_PLUGIN))
#define GEDIT_MODELINE_PLUGIN_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), GEDIT_TYPE_MODELINE_PLUGIN, GeditModelinePluginClass))

typedef struct _GeditModelinePlugin		GeditModelinePlugin;
typedef struct _GeditModelinePluginPrivate	GeditModelinePluginPrivate;
typedef struct _GeditModelinePluginClass	GeditModelinePluginClass;

struct _GeditModelinePlugin {
	PeasExtensionBase parent;

	/*< private >*/
	GeditModelinePluginPrivate *priv;
};

struct _GeditModelinePluginClass {
	PeasExtensionBaseClass parent_class;
};

GType	gedit_modeline_plugin_get_type		(void) G_GNUC_CONST;

G_MODULE_EXPORT void peas_register_types (PeasObjectModule *module);

G_END_DECLS

#endif /* __GEDIT_MODELINE_PLUGIN_H__ */
/* ex:set ts=8 noet: */
