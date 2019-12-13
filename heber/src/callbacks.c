#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include <string.h>


char IDEE[20];


void
on_buttonPageModifier_clicked  (GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget  *entry_FindId;
GtkWidget  *Widget_Modifer;
GtkWidget *gestion_heber;
GtkWidget *Echec_supp;


entry_FindId=lookup_widget(objet_graphique,"entry_FindId");
strcpy(IDEE,gtk_entry_get_text(GTK_ENTRY(entry_FindId)));
gestion_heber=lookup_widget(objet_graphique,"gestion_heber");
if(IDEE=="aaaaab")
{
Echec_supp=create_Echec_supp();
gtk_widget_show(Echec_supp);

}
else
{

gtk_widget_destroy(gestion_heber);
Widget_Modifer=create_Widget_Modifer();
gtk_widget_show(Widget_Modifer);



}
}


void
on_buttonPageSupprimer_clicked  (GtkWidget *objet_graphique,gpointer user_data)
{
int n;
GtkWidget  *entry_FindId;
GtkWidget  *Succes_supp;
GtkWidget *Echec_supp;
GtkWidget *gestion_heber;


entry_FindId=lookup_widget(objet_graphique,"entry_FindId");
strcpy(IDEE,gtk_entry_get_text(GTK_ENTRY(entry_FindId)));
n=supprimer(IDEE);
if(n==1)

{
gestion_heber=lookup_widget(objet_graphique,"gestion_heber"); 
Succes_supp=create_Succes_supp();
gtk_widget_show(Succes_supp);
}
else
{
gestion_heber=lookup_widget(objet_graphique,"gestion_heber"); 
Echec_supp=create_Echec_supp();
gtk_widget_show(Echec_supp);
}




}


void
on_buttonPageAjouter_clicked    (GtkWidget *objet_graphique,gpointer user_data)
{


GtkWidget  *Widget_Ajouter;
GtkWidget *gestion_heber;

gestion_heber=lookup_widget(objet_graphique,"gestion_heber");
gtk_widget_destroy(gestion_heber);
Widget_Ajouter=create_Widget_Ajouter();
gtk_widget_show(Widget_Ajouter);



}




void
on_button_Modifier_clicked  (GtkWidget *objet_graphique,gpointer user_data)
{
int simple,doub,triple,quad,n;

GtkWidget *spinbutton_simple_modif;
GtkWidget *spinbutton_double_modif;
GtkWidget *spinbutton_triple_modif;
GtkWidget *spinbutton_quad_modif;

spinbutton_simple_modif=lookup_widget(objet_graphique,"spinbutton_simple_modif");
spinbutton_double_modif=lookup_widget(objet_graphique,"spinbutton_double_modif");
spinbutton_triple_modif=lookup_widget(objet_graphique,"spinbutton_triple_modif");
spinbutton_quad_modif=lookup_widget(objet_graphique,"spinbutton_double_modif");


simple=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_simple_modif));

doub=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_double_modif));

triple=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_triple_modif));

quad=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_quad_modif));


n=find_heber(IDEE);
modifier(n,simple,doub,triple,quad);

}


void
on_button_Ajouter_clicked    (GtkWidget *objet_graphique,gpointer user_data)
{
int simple,doub,triple,quad;
char nom[20];

GtkWidget *spinbutton_simple_ajout;
GtkWidget *spinbutton_double_ajout;
GtkWidget *spinbutton_triple_ajout;
GtkWidget *spinbutton_quad_ajout;
GtkWidget *entry_Id_ajout;

spinbutton_simple_ajout=lookup_widget(objet_graphique,"spinbutton_simple_ajout");
spinbutton_double_ajout=lookup_widget(objet_graphique,"spinbutton_double_ajout");
spinbutton_triple_ajout=lookup_widget(objet_graphique,"spinbutton_triple_ajout");
spinbutton_quad_ajout=lookup_widget(objet_graphique,"spinbutton_quad_ajout");


simple=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_simple_ajout));

doub=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_double_ajout));

triple=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_triple_ajout));

quad=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_quad_ajout));

entry_Id_ajout=lookup_widget(objet_graphique,"entry_Id_ajout");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry_Id_ajout)));

ajouter(nom,simple,doub,triple,quad);

}


void
on_Button_reserver_clicked  (GtkWidget *objet_graphique,gpointer user_data)
{
int one,two,three,four,jour,mois,annee,x;
char h[20],c[20];

GtkWidget *spinbutton_reserver_simple;
GtkWidget *spinbutton_reserver_double;
GtkWidget *spinbutton_reserver_triple;
GtkWidget *spinbutton_reserver_quad;
GtkWidget *spinbutton_reserver_jour;
GtkWidget *spinbutton_reserver_mois;
GtkWidget *spinbutton_reserver_annee;
GtkWidget *Liste_hotel;
GtkWidget *Client_idee;
GtkWidget *gestion_heber;
GtkWidget  *Succes_supp;
GtkWidget *Echec_supp;

spinbutton_reserver_simple=lookup_widget(objet_graphique,"spinbutton_reserver_simple");
spinbutton_reserver_double=lookup_widget(objet_graphique,"spinbutton_reserver_double");
spinbutton_reserver_triple=lookup_widget(objet_graphique,"spinbutton_reserver_triple");
spinbutton_reserver_quad=lookup_widget(objet_graphique,"spinbutton_reserver_quad");
spinbutton_reserver_jour=lookup_widget(objet_graphique,"spinbutton_reserver_jour");
spinbutton_reserver_mois=lookup_widget(objet_graphique,"spinbutton_reserver_mois");
spinbutton_reserver_annee=lookup_widget(objet_graphique,"spinbutton_reserver_annee");
Liste_hotel=lookup_widget(objet_graphique,"Liste_hotel");
Client_idee=lookup_widget(objet_graphique,"Client_idee");



one=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_reserver_simple));
two=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_reserver_double));
three=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_reserver_triple));
four=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_reserver_quad));
jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_reserver_jour));
mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_reserver_mois));
annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton_reserver_annee));
strcpy(h,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Liste_hotel)));
strcpy(c,gtk_entry_get_text(GTK_ENTRY(Client_idee)));


x=reserver(h,c,one,two,three,four,jour,mois,annee);
if(x==0)

{
gestion_heber=lookup_widget(objet_graphique,"gestion_heber"); 
Succes_supp=create_Succes_supp();
gtk_widget_show(Succes_supp);
}
else
{
gestion_heber=lookup_widget(objet_graphique,"gestion_heber"); 
Echec_supp=create_Echec_supp();
gtk_widget_show(Echec_supp);
}




}


void
on_Button_Reserver_clicked             (GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget  *Widget_reserver;
GtkWidget *gestion_heber;

gestion_heber=lookup_widget(objet_graphique,"gestion_heber");
gtk_widget_destroy(gestion_heber);
Widget_reserver=create_Widget_reserver();
gtk_widget_show(Widget_reserver);




}


void
on_retour_modif_heber_clicked            (GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget  *Widget_Modifer;
GtkWidget *gestion_heber;

Widget_Modifer=lookup_widget(objet_graphique,"Widget_Modifer");
gtk_widget_destroy(Widget_Modifer);
gestion_heber=create_gestion_heber();
gtk_widget_show(gestion_heber);



}


void
on_retour_Ajout_heber_clicked            (GtkWidget *objet_graphique,gpointer user_data)
{

GtkWidget  *Widget_Ajouter;
GtkWidget *gestion_heber;

Widget_Ajouter=lookup_widget(objet_graphique,"Widget_Ajouter");
gtk_widget_destroy(Widget_Ajouter);
gestion_heber=create_gestion_heber();
gtk_widget_show(gestion_heber);


}







void
on_afficher_heber_clicked              (GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *gestion_heber;
GtkWidget *afficher_reservations;
GtkWidget *treeview_reserv;

gestion_heber=lookup_widget(objet_graphique,"gestion_heber");

gtk_widget_destroy(gestion_heber);
afficher_reservations=lookup_widget(objet_graphique,"afficher_reservations");
afficher_reservations=create_afficher_reservations();

gtk_widget_show(afficher_reservations);

treeview_reserv=lookup_widget(afficher_reservations,"treeview_reserv");

afficher_reservation(treeview_reserv);



}

