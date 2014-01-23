/* cairo-test.c:
 *
 * Copyright (C) 2014 Stefano Karapetsas
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
#include <gdk/gdk.h>

/* drawing event */
static gboolean
#if GTK_CHECK_VERSION (3, 0, 0)
window_draw (GtkWidget *widget, cairo_t *cr, gpointer data)
#else
window_expose_event (GtkWidget *widget, GdkEventExpose *event, gpointer data)
#endif
{
#if !GTK_CHECK_VERSION (3, 0, 0)
    cairo_t *cr;

    cr = gdk_cairo_create(widget->window);
#endif

    /* draw a line */
    cairo_move_to (cr, 20, 20);
    cairo_line_to (cr, 180, 20);
    cairo_set_line_width (cr, 5.0);
    cairo_set_line_cap (cr, CAIRO_LINE_CAP_ROUND);
    cairo_stroke (cr);

#if !GTK_CHECK_VERSION (3, 0, 0)
    cairo_destroy(cr);
#endif
    return FALSE;
}

int
main(int argc, char** argv)
{
    GtkWindow *window = NULL;
    GtkWidget *widget = NULL;

    /* initialize GTK+ */
    gtk_init (&argc, &argv);

    /* create window */
    window = GTK_WINDOW (gtk_window_new (GTK_WINDOW_TOPLEVEL));

    gtk_window_set_title (window, _("Cairo Test"));

    /* create drawing area */
    widget = gtk_drawing_area_new ();

    /* set a minimum size */
    gtk_widget_set_size_request (widget, 200, 200);

    /* add drawing area to window */
    gtk_container_add (GTK_CONTAINER (window), widget);

    /* quit signal */
    g_signal_connect (GTK_WIDGET (window), "destroy", gtk_main_quit, NULL);

    /* drawing signal */
#if GTK_CHECK_VERSION (3, 0, 0)
    g_signal_connect (widget, "draw", G_CALLBACK (window_draw), NULL);
#else
    g_signal_connect (widget, "expose-event", G_CALLBACK (window_expose_event), NULL);
#endif

    gtk_widget_show_all (GTK_WIDGET (window));

    /* start application */
    gtk_main ();

    return 0;
}
