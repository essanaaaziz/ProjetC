#include <gtk/gtk.h>


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_but_ajout_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_but_modif_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_but_supp_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_but_retour_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_back_to_tree1_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_but_modif_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_but_aff_tree1_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_but_ajout_coord_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_but_ok_modif_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_but_retourC_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_but_reserver_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_but_afficherC_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_but_annuler_supp_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_but_supp_oui_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_but_modif_retour_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data);
