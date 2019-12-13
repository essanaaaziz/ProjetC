/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *gestion_heber;
  GtkWidget *Widget_Modifer;
  GtkWidget *Widget_Ajouter;
  GtkWidget *Widget_reserver;
  GtkWidget *Succes_supp;
  GtkWidget *Echec_supp;
  GtkWidget *afficher_reservations;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  gestion_heber = create_gestion_heber ();
  gtk_widget_show (gestion_heber);
  /*Widget_Modifer = create_Widget_Modifer ();
  gtk_widget_show (Widget_Modifer);
  Widget_Ajouter = create_Widget_Ajouter ();
  gtk_widget_show (Widget_Ajouter);
  Widget_reserver = create_Widget_reserver ();
  gtk_widget_show (Widget_reserver);
  Succes_supp = create_Succes_supp ();
  gtk_widget_show (Succes_supp);
  Echec_supp = create_Echec_supp ();
  gtk_widget_show (Echec_supp);
  afficher_reservations = create_afficher_reservations ();
  gtk_widget_show (afficher_reservations);*/

  gtk_main ();
  return 0;
}

