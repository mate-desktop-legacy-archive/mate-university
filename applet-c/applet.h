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


#ifndef APPLET_H
#define APPLET_H


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include <glib.h>
#include <glib/gi18n.h>
#include <gtk/gtk.h>

#include <mate-panel-applet.h>
#include <mate-panel-applet-gsettings.h>


typedef struct {
    MatePanelApplet   *applet;
    GtkWidget         *label;
} UniversityApplet;


#endif /* APPLET_H */
