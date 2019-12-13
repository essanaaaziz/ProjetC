#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h" 


void
on_bouton_lire_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_window;
GtkWidget *treeview;
GtkWidget *treeview1;

gestion_window=lookup_widget(objet,"gestion_window");
gtk_widget_destroy(gestion_window);
treeview=lookup_widget(objet,"treeview");
treeview=create_treeview();
gtk_widget_show(treeview);
treeview1=lookup_widget(treeview,"treeview1");
afficher(treeview1);
}

void
on_retour_button_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview , *gestion_window ;
treeview=lookup_widget(objet,"treeview");
gtk_widget_destroy(treeview);
gestion_window=create_gestion_window();
gtk_widget_show(gestion_window);
}


void
on_bouton_repondre_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview , *reponse ;
treeview=lookup_widget(objet,"treeview");

reponse=create_reponse();
gtk_widget_show(reponse);
gtk_widget_destroy(treeview);
}


void
on_button_envoyer_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2,*reponse;
reply r;

reponse=lookup_widget(objet,"reponse");

input1=lookup_widget(objet,"entry_numero");
input2=lookup_widget(objet,"entry_texte");

strcpy(r.num,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(input2)));

ajouter_reponse(r);
}


void
on_retour_reponse_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_window , *reponse ;
reponse=lookup_widget(objet,"reponse");
gtk_widget_destroy(reponse);
gestion_window=create_gestion_window();
gtk_widget_show(gestion_window);
}

