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

#include "about.h"


void about_dialog_open (UniversityApplet *university_applet) {
    const gchar *authors[] = {
        "Stefano Karapetsas <stefano@karapetsas.com>",
        "info-cppsp <info@cppsp.de>",
        NULL
    };

    /* Construct the about dialog */
    gtk_show_about_dialog (NULL,
                  "icon-name", "university-applet",
                  "program-name", PACKAGE_NAME,
                  "version", PACKAGE_VERSION,
                  "copyright", "(C) 2013, Stefano Karapetsas <stefano@karapetsas.com>\n(C) 2012-2018, MATE developers",
                  "authors", authors,
                  "documenters", authors,
                  /* To translator: Put your name here to show up in the About dialog as the translator */
                  "translator-credits", _("translator-credits"),
                  "logo-icon-name", "mate-panel",
                  "website", "http://www.mate-desktop.org",
                  NULL);

}
