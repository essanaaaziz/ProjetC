#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "voitures.h"

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

gchar *MODELE; 
gchar *MATRICULE1;
gchar *MATRICULE2;
gchar *DATE;
gchar *PRIX;


GtkWidget *Gestion_Voitures;
GtkWidget *current;
GtkTreeIter iter;

GtkWidget *E1;
GtkWidget *E2;
GtkWidget *E3;
GtkWidget *E4;
GtkWidget *E5;













}


void
on_but_ajout_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestion_Voitures;
GtkWidget *Voitures_Agent;

Voitures_Agent=create_Voitures_Agent();
gtk_widget_show(Voitures_Agent);
Gestion_Voitures=lookup_widget (objet_graphique,"Gestion_Voitures");
gtk_widget_hide(Gestion_Voitures);



}


void
on_but_modif_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *window3;
  GtkWidget *Gestion_Voitures;

window3=create_window3();
gtk_widget_show(window3);
Gestion_Voitures=lookup_widget(objet_graphique,"Gestion_Voitures");
gtk_widget_hide(Gestion_Voitures);


}


void
on_but_supp_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestion_Voitures;
GtkWidget *window5;

window5=create_window5();
gtk_widget_show(window5);
Gestion_Voitures=lookup_widget (objet_graphique,"Gestion_Voitures");
gtk_widget_hide(Gestion_Voitures);
}

//integration
void
on_but_retour_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{ 

}


void
on_back_to_tree1_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Gestion_Voitures;
  GtkWidget *Voitures_Agent;

Gestion_Voitures=create_Gestion_Voitures();
gtk_widget_show(Gestion_Voitures);
Voitures_Agent=lookup_widget (objet_graphique,"Voitures_Agent");
gtk_widget_hide(Voitures_Agent);

}


void
on_but_aff_tree1_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *treeview1;

treeview1 = lookup_widget(objet_graphique,"treeview1");
afficher_voitures(treeview1);

}


void
on_but_ajout_coord_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Voiture	v;


GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input5;
GtkWidget *input3;
GtkWidget *input4;

GtkWidget *Voitures_Agent;


input1=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");
input3=lookup_widget(objet_graphique,"entry3");
input4=lookup_widget(objet_graphique,"entry4");
input5=lookup_widget(objet_graphique,"entry5");

strcpy(v.Matricule1,gtk_entry_get_text(GTK_ENTRY(input1))); 
strcpy(v.Matricule2,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.Modele,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(v.Prix,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(v.Date,gtk_entry_get_text(GTK_ENTRY(input5)));

ajouter_voitures(v);

gtk_entry_set_text(GTK_ENTRY(input1), "");
gtk_entry_set_text(GTK_ENTRY(input2), "");
gtk_entry_set_text(GTK_ENTRY(input3), "");
gtk_entry_set_text(GTK_ENTRY(input4), "");
gtk_entry_set_text(GTK_ENTRY(input5), "");

	


}


void
on_but_ok_modif_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{Voiture v;

FILE *f;
FILE *f1;
	

		
		//char Matricule1[20];
		//char Matricule2[20];
	
	GtkWidget *input10;
	GtkWidget *input11;
	GtkWidget *input12;
	GtkWidget *input13;
	GtkWidget *input14;
	
	GtkWidget *window3;

input10=lookup_widget(objet_graphique,"entry8");
input11=lookup_widget(objet_graphique,"entry9");
input12=lookup_widget(objet_graphique,"entry10");
input13=lookup_widget(objet_graphique,"entry11");
input14=lookup_widget(objet_graphique,"entry12");

strcpy(v.Modele,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(v.Matricule1,gtk_entry_get_text(GTK_ENTRY(input10))); 
strcpy(v.Matricule2,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(v.Prix,gtk_entry_get_text(GTK_ENTRY(input13)));
strcpy(v.Date,gtk_entry_get_text(GTK_ENTRY(input14)));


gtk_entry_set_text(GTK_ENTRY(input10), "");
gtk_entry_set_text(GTK_ENTRY(input11), "");
gtk_entry_set_text(GTK_ENTRY(input12), "");
gtk_entry_set_text(GTK_ENTRY(input13), "");
gtk_entry_set_text(GTK_ENTRY(input14), "");

modifier_voitures(v.Modele, v.Matricule1, v.Matricule2, v.Prix, v.Date);

}

//integration
void
on_but_retourC_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *Voitures_Client;


Voitures_Client=lookup_widget (objet_graphique,"Voitures_Client");
gtk_widget_hide(Voitures_Client);
}


void
on_but_reserver_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_but_annuler_supp_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Gestion_Voitures;
  GtkWidget *window5;

Gestion_Voitures=create_Gestion_Voitures();
gtk_widget_show(Gestion_Voitures);
window5=lookup_widget (objet_graphique,"window5");
gtk_widget_hide(window5);

}


void
on_but_supp_oui_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input13;
GtkWidget *input14;

char Matricule2[30];
char Matricule1[30];
input13=lookup_widget(objet_graphique,"entry13");
input14=lookup_widget(objet_graphique,"entry14");
strcpy(Matricule1,gtk_entry_get_text(GTK_ENTRY(input13)));
strcpy(Matricule2,gtk_entry_get_text(GTK_ENTRY(input14))); 
 supprimer_voitures( Matricule1, Matricule2) ;
gtk_entry_set_text(GTK_ENTRY(input13), "");
gtk_entry_set_text(GTK_ENTRY(input14), "");
}


void
on_but_modif_retour_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *Gestion_Voitures;
  GtkWidget *window3;


Gestion_Voitures=create_Gestion_Voitures();
gtk_widget_show(Gestion_Voitures);
window3=lookup_widget (objet_graphique,"window3");
gtk_widget_hide(window3);

}

