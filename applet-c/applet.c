/* applet.c:
 *
 * Copyright (C) 2013 Stefano Karapetsas
 *
 *  This file is part of MATE University.
 *
 *  MATE University is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  MATE University is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with MATE University.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *      Stefano Karapetsas <stefano@karapetsas.com>
 */

#include <config.h>

#include <glib.h>
#include <glib/gi18n.h>
#include <gtk/gtk.h>

#include <mate-panel-applet.h>
#include <mate-panel-applet-gsettings.h>

typedef struct
{
    MatePanelApplet   *applet;
    GtkWidget         *label;
} UniversityApplet;

static gboolean
university_applet_fill (MatePanelApplet* applet)
{
    UniversityApplet *university_applet;

    /* set mate-panel applet options */
    mate_panel_applet_set_flags (applet, MATE_PANEL_APPLET_EXPAND_MINOR);
    mate_panel_applet_set_background_widget(applet, GTK_WIDGET(applet));

    /* create the UniversityApplet struct */
    university_applet = g_malloc0(sizeof(UniversityApplet));
    university_applet->applet = applet;
    university_applet->label = gtk_label_new("Hello world!");

    /* we add the Gtk label into the applet */
    gtk_container_add (GTK_CONTAINER(applet), university_applet->label);

    gtk_widget_show_all (applet);

    return TRUE;
}

/* This function, called by mate-panel, will create the applet */
static gboolean
university_factory (MatePanelApplet* applet, const char* iid, gpointer data)
{
    gboolean retval = FALSE;

    if (!g_strcmp0(iid, "UniversityApplet"))
        retval = university_applet_fill (applet);

    return retval;
}

MATE_PANEL_APPLET_OUT_PROCESS_FACTORY("UniversityAppletFactory",
                                      PANEL_TYPE_APPLET,
                                      "Sample applet",
                                      university_factory,
                                      NULL)
