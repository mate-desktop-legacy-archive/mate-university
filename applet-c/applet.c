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


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include "applet.h"
#include "about.h"


/* This runs if the user clicks the 'About' button in the context menu */
static void about_cb (GtkAction *action, gpointer data) {
    UniversityApplet *university_applet;
    university_applet = (UniversityApplet *) data;

    about_dialog_open (university_applet);
}

/* Add menu entry actions */
static const GtkActionEntry university_applet_menu_actions[] = {

    { "About", "help-about", N_("_About"),
        NULL, NULL,
        G_CALLBACK(about_cb) }
};

static gboolean
university_applet_fill (MatePanelApplet* applet)
{
    UniversityApplet *university_applet;

    /* set mate-panel applet options */
    mate_panel_applet_set_flags (applet, MATE_PANEL_APPLET_EXPAND_MINOR);
    mate_panel_applet_set_background_widget (applet, GTK_WIDGET(applet));

    /* create the UniversityApplet struct */
    university_applet = g_malloc0 (sizeof (UniversityApplet));
    university_applet->applet = applet;

/* To pack more thing next to each other, a container is needed.
 * (like GtkGrid)
 * comment out the following define to use the label */
#define USE_PICTURE

#ifdef USE_PICTURE
/* image */
    /* Create an image from one of the current theme icons */
    /* GtkWidget * gtk_image_new_from_icon_name (const gchar *icon_name, GtkIconSize size); */
    GtkWidget *image = gtk_image_new_from_icon_name ("go-up", GTK_ICON_SIZE_BUTTON);

    /* add a tooltip to the image */
    /* void gtk_widget_set_tooltip_text (GtkWidget *widget, const gchar *text); */
    gtk_widget_set_tooltip_text (image, _("Hello world!"));

    /* add it to the applet */
    gtk_container_add (GTK_CONTAINER(applet), image);

#else

/* label */

    /* create new label */
    university_applet->label = gtk_label_new (_("Hello world!"));

    /* we add the Gtk label into the applet */
    gtk_container_add (GTK_CONTAINER(applet), university_applet->label);

#endif

/* menu */

    /* Adding menu with the built in, now deprecated GtkUIManager
     * The factory adds ui_manager automatically to an applet
     * and sets up the basic context menu
     * ('Remove from panel', 'Move', 'Lock to panel') */

    /* Menu definition for the ui_manager */
    gchar *ui_xml = g_strdup ("<menuitem name=\"About Item\" action=\"About\"/>");

    /* suppress compiler warnings */
    G_GNUC_BEGIN_IGNORE_DEPRECATIONS;

    /* create action group */
    GtkActionGroup *action_group = gtk_action_group_new ("University Applet Actions");
    gtk_action_group_set_translation_domain (action_group, GETTEXT_PACKAGE);

    /* add previously defined actions */
    gtk_action_group_add_actions (action_group,
                                  university_applet_menu_actions,
                                  G_N_ELEMENTS (university_applet_menu_actions),
                                  applet);

    G_GNUC_END_IGNORE_DEPRECATIONS;

    /* MatePanelApplet *applet, const gchar *xml, GtkActionGroup *applet_action_group */
    mate_panel_applet_setup_menu (applet, ui_xml, action_group);

    /* free reference from this function
     * the applet / ui_manager is going to take ownership */
    g_object_unref (action_group);

    /* this string gets copied, so free it */
    g_free (ui_xml);

/* menu end */

    /* show applet and all of its children, like label */
    gtk_widget_show_all (GTK_WIDGET(applet));

    return TRUE;
}

/* This function, called by mate-panel, will create the applet */
static gboolean
university_factory (MatePanelApplet* applet, const char* iid, gpointer data)
{
    gboolean retval = FALSE;

    if (!g_strcmp0 (iid, "UniversityApplet"))
        retval = university_applet_fill (applet);

    return retval;
}

/* https://github.com/mate-desktop/mate-panel/blob/master/libmate-panel-applet/mate-panel-applet.h#L145 */
/* This function essentially makes a new factory and
 * registers it as a DBus service.
 * When a user adds this applet to the mate-panel,
 * the callback is called, creating an applet. */
MATE_PANEL_APPLET_OUT_PROCESS_FACTORY("UniversityAppletFactory",    /* factory_id */
                                      PANEL_TYPE_APPLET,            /* type */
                                      "Sample applet",              /* name */
                                      university_factory,           /* callback */
                                      NULL)                         /* data */

