/*
 * gedit-tab.h
 * This file is part of gedit
 *
 * Copyright (C) 2005 - Paolo Maggi
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GEDIT_TAB_PRIVATE_H__
#define __GEDIT_TAB_PRIVATE_H__

#include <gedit/gedit-tab.h>

G_BEGIN_DECLS

GtkWidget	*_gedit_tab_new				(void);

/* Whether create is TRUE, creates a new empty document if location does
 * not refer to an existing location
 */
GtkWidget	*_gedit_tab_new_from_location		(GFile                   *location,
							 const GtkSourceEncoding *encoding,
							 gint                     line_pos,
							 gint                     column_pos,
							 gboolean                 create);

GtkWidget	*_gedit_tab_new_from_stream		(GInputStream            *stream,
							 const GtkSourceEncoding *encoding,
							 gint                     line_pos,
							 gint                     column_pos);
	
gchar 		*_gedit_tab_get_name			(GeditTab                *tab);

gchar 		*_gedit_tab_get_tooltip			(GeditTab                *tab);

GdkPixbuf 	*_gedit_tab_get_icon			(GeditTab                *tab);

void		 _gedit_tab_load			(GeditTab                *tab,
							 GFile                   *location,
							 const GtkSourceEncoding *encoding,
							 gint                     line_pos,
							 gint                     column_pos,
							 gboolean                 create);

void		 _gedit_tab_load_stream			(GeditTab                *tab,
							 GInputStream            *location,
							 const GtkSourceEncoding *encoding,
							 gint                     line_pos,
							 gint                     column_pos);

void		 _gedit_tab_revert			(GeditTab                *tab);

void		 _gedit_tab_save_async			(GeditTab                *tab,
							 GCancellable            *cancellable,
							 GAsyncReadyCallback      callback,
							 gpointer                 user_data);

gboolean	 _gedit_tab_save_finish			(GeditTab                *tab,
							 GAsyncResult            *result);

void		 _gedit_tab_save_as_async		(GeditTab                 *tab,
							 GFile                    *location,
							 const GtkSourceEncoding  *encoding,
							 GtkSourceNewlineType      newline_type,
							 GtkSourceCompressionType  compression_type,
							 GCancellable             *cancellable,
							 GAsyncReadyCallback       callback,
							 gpointer                  user_data);

void		 _gedit_tab_print			(GeditTab                 *tab);

void		 _gedit_tab_mark_for_closing		(GeditTab                 *tab);

gboolean	 _gedit_tab_get_can_close		(GeditTab                 *tab);

GtkWidget	*_gedit_tab_get_view_frame		(GeditTab                 *tab);

void		 _gedit_tab_set_network_available	(GeditTab	     *tab,
							 gboolean	     enable);

G_END_DECLS

#endif  /* __GEDIT_TAB_PRIVATE_H__ */

/* ex:set ts=8 noet: */
