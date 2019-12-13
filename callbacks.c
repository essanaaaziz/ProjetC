#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamations.h"

void
on_bouton_reply_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)

{
GtkWidget *window_gestion;
GtkWidget *Reponses;
GtkTreeView *treeview2;

window_gestion=lookup_widget(objet,"window_gestion");

Reponses=lookup_widget(objet,"Reponses");
Reponses=create_Reponses();
gtk_widget_destroy(window_gestion);


treeview2=lookup_widget(Reponses,"treeview2");
gtk_widget_show(Reponses);

afficher_reponse(treeview2);
}






void
on_Entrer_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data)
{
char chaine[20],chaine1[20],chaine2[20],chaine3[20],chaine4[20];
GtkWidget *input,*input1,*input2,*input3,*input4;
input=lookup_widget(objet,"inputNum");
input1=lookup_widget(objet,"inputTex");
input2=lookup_widget(objet,"inputNo");
input3=lookup_widget(objet,"inputDat");
input4=lookup_widget(objet,"inputNuum");
strcpy(chaine,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(chaine1,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(chaine2,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(chaine3,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(chaine4,gtk_entry_get_text(GTK_ENTRY(input4)));
modifier(chaine,chaine1,chaine2,chaine3,chaine4);
}












void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_gestion , *window_ecrire ;
window_gestion=lookup_widget(objet,"window_gestion");
gtk_widget_destroy(window_gestion);
window_ecrire=create_window_ecrire();
gtk_widget_show(window_ecrire);

}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_gestion;
GtkWidget *window_tree;
GtkWidget *treeview1;

window_gestion=lookup_widget(objet,"window_gestion");
gtk_widget_destroy(window_gestion);
window_tree=lookup_widget(objet,"window_tree");
window_tree=create_window_tree();
gtk_widget_show(window_tree);
treeview1=lookup_widget(window_tree,"treeview1");
afficher_reclamation(treeview1);

}





void
on_button_ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2, *input3,*input4;
GtkWidget *window_ecrire;
reclamation r;

window_ecrire=lookup_widget(objet,"window_ecrire");

input1=lookup_widget(objet,"entry1");
input2=lookup_widget(objet,"entry2");
input3=lookup_widget(objet,"entry3");
input4=lookup_widget(objet,"entry4");

strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.date,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.numero,gtk_entry_get_text(GTK_ENTRY(input4)));
ajouter_reclamation(r);
}
void
on_valider_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{ char chaine [20];
GtkWidget *input;
input=lookup_widget(objet,"input_supprimer");
strcpy(chaine,gtk_entry_get_text(GTK_ENTRY(input)));
supprimer(chaine);
}




void
on_button_retour_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window_gestion,*window_ecrire;

window_ecrire=lookup_widget(objet,"window_ecrire");
gtk_widget_destroy(window_ecrire);
window_gestion=create_window_gestion();
gtk_widget_show(window_gestion);

}


void
on_retour_tree_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *window_gestion,*window_tree;
window_tree=lookup_widget(objet,"window_tree");
gtk_widget_destroy(window_tree);
window_gestion=create_window_gestion();
gtk_widget_show(window_gestion);

}




void
on_Retouur_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window_modifier, *window_gestion;
window_modifier=lookup_widget(objet,"window_modifier");
gtk_widget_destroy(window_modifier);
window_gestion=create_window_gestion();
gtk_widget_show(window_gestion);
}












void
on_reply_retour_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reponses; 
GtkWidget *window_gestion;
Reponses=lookup_widget(objet,"Reponses");
gtk_widget_destroy(Reponses);
window_gestion=create_window_gestion();
gtk_widget_show(window_gestion);
}




void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Supprimer; 
GtkWidget *window_tree;
window_tree=lookup_widget(objet,"window_tree");
gtk_widget_destroy(window_tree);
Supprimer=create_Supprimer();
gtk_widget_show(Supprimer);
}


void
on_Retouuuur_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Supprimer; 
GtkWidget *window_gestion;
Supprimer=lookup_widget(objet,"Supprimer");
gtk_widget_destroy(Supprimer);
window_gestion=create_window_gestion();
gtk_widget_show(window_gestion);
}











void
on_modifier_clicked                    (GtkWidget  *objet,
                                        gpointer         user_data)
{
GtkWidget *Modifier; 
GtkWidget *window_tree;
window_tree=lookup_widget(objet,"window_tree");
gtk_widget_destroy(window_tree);
Modifier=create_Modifier();
gtk_widget_show(Modifier);
}


void
on_retour_modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
GtkWidget *Modifier; 
GtkWidget *window_gestion;
Modifier=lookup_widget(objet,"Modifier");
gtk_widget_destroy(Modifier);
window_gestion=create_window_gestion();
gtk_widget_show(window_gestion);
}
















