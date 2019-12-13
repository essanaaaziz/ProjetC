#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include <stdlib.h>	
#include <stdio.h>

#include "fonctions.h"

#include <string.h>

//1]espace excusion-agent :
//1.1) button (ajouter excursion) dans la fenetre excursion
void
on_ajouter_excursion_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_ajouter;
	GtkWidget *fenetre_excursion;
	

	fenetre_excursion=lookup_widget (button, "fenetre_excursion");
	gtk_widget_destroy(fenetre_excursion);
	

	fenetre_ajouter=lookup_widget(button,"fenetre_ajouter");
	fenetre_ajouter=create_fenetre_ajouter();
	gtk_widget_show(fenetre_ajouter);

}

//1.2) button (modifier excursion) dans la fenetre excursion
void
on_modifier_excursion_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_modifier;
	GtkWidget *fenetre_excursion;
	

	fenetre_excursion=lookup_widget (button, "fenetre_excursion");
	gtk_widget_destroy(fenetre_excursion);
	

	fenetre_modifier=lookup_widget(button,"fenetre_modifier");
	fenetre_modifier=create_fenetre_modifier();
	gtk_widget_show(fenetre_modifier);

}

//1.3) button (supprimer excursion) dans la fenetre excursion
void
on_supprimer_excursion_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
	FILE *f=fopen("liste_excursion.txt","r");	
	GtkWidget *fenetre_supprimer;
	GtkWidget *fenetre_excursion;
	GtkWidget *comboboxRefSupp;      //Combobox pour le choix de l'excursion à supprimer

	char nom[20];
	char referance[20];
	int jour;
	char mois[20];
	int annee;
	char lieu[20];
	int prix;
	int heure;
	

	fenetre_excursion=lookup_widget (button, "fenetre_excursion");
	gtk_widget_destroy(fenetre_excursion);
	

	fenetre_supprimer=lookup_widget(button,"fenetre_supprimer");
	fenetre_supprimer=create_fenetre_supprimer();
	gtk_widget_show(fenetre_supprimer);

	comboboxRefSupp=lookup_widget (button, "comboboxentrysupp");     //associer l'objet avec la variable
	
	

	if(f==NULL)
	{
		return;
	}
	else
	{ 		
		while(fscanf(f,"%s %s %s %d %d %s %d %d \n",nom,referance,lieu,&prix,&jour,mois,&annee,&heure)!=EOF)
		{
			gtk_combo_box_append_text(GTK_COMBO_BOX(comboboxRefSupp), (referance) );
		}
	}
	fclose(f);


}

//1.4) button (consultation excursion) dans la fenetre excursion
void
on_consultation_excursion_clicked      (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_consultation_excursion;
	GtkWidget *fenetre_excursion;
	GtkListStore *treeview1;

	fenetre_excursion=lookup_widget (button, "fenetre_excursion");
	
	

	fenetre_consultation_excursion=create_fenetre_consultation_excursion();
	gtk_widget_show(fenetre_consultation_excursion);
	gtk_widget_destroy(fenetre_excursion);
	treeview1=lookup_widget (fenetre_consultation_excursion,"treeview1");
	afficher_excursion(treeview1);
}



//1.5) button (recherche) dans la fenetre excursion
void
on_recherche_excursion_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{

	
	GtkWidget *fenetre_rechercher;
	GtkWidget *fenetre_excursion;                         
	GtkWidget *input;
	GtkListStore *treeview2;
	char lieu[20];

	input=lookup_widget(button ,"entrylieu" );
	
	strcpy(lieu,gtk_entry_get_text(GTK_ENTRY(input)));
	
	recherche (lieu);
	fenetre_excursion=lookup_widget (button, "fenetre_excursion");
	fenetre_rechercher=create_fenetre_rechercher();
	gtk_widget_show(fenetre_rechercher);
	gtk_widget_destroy(fenetre_excursion);
	treeview2=lookup_widget (fenetre_rechercher,"treeview2");
	afficher_lieu_recherche(treeview2);
		
	


}

//1.6) button (Reserver excursion) dans la fenetre excursion
void
on_buttonReserver_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_reserver_excursion;
	GtkWidget *fenetre_excursion;
	GtkListStore *treeview1;

	

	fenetre_excursion=lookup_widget (button, "fenetre_excursion");
	gtk_widget_destroy(fenetre_excursion);
	

	fenetre_reserver_excursion=lookup_widget(button,"fenetre_reserver_excursion");
	fenetre_reserver_excursion=create_fenetre_reserver_excursion();

	gtk_widget_show(fenetre_reserver_excursion);
	treeview1=lookup_widget (fenetre_reserver_excursion,"treeview1");
	afficher_excursion(treeview1);
}


//1.7) button (mon compte) dans la fenetre excursion
void
on_buttoncompte_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	
	
}


//1.8)button Mes Réservations dans la fenetre excursion

void
on_button_mes_Reservations_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_Reservation;
	GtkWidget *fenetre_excursion;
	

	fenetre_excursion=lookup_widget (button, "fenetre_excursion");
	gtk_widget_destroy(fenetre_excursion);
	

	fenetre_Reservation=lookup_widget(button,"fenetre_Reservation");
	fenetre_Reservation=create_fenetre_Reservation();

	gtk_widget_show(fenetre_Reservation);

}












//2] fenetre_ajouter :
//2.1) button (Retour) dans la fenetre ajouter
void
on_buttonRetourA_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_ajouter;
	GtkWidget *fenetre_excursion;
	

	fenetre_ajouter=lookup_widget (button, "fenetre_ajouter");
	gtk_widget_destroy(fenetre_ajouter);
	

	fenetre_excursion=lookup_widget(button,"fenetre_excursion");
	fenetre_excursion=create_fenetre_excursion();
	gtk_widget_show(fenetre_excursion);
}



		


//2.2) button (Valider_Ajout) dans la fenetre ajouter
void
on_buttonValider_Ajout_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
	FILE *f=fopen("liste_excursion.txt","a+");
	GtkWidget *jour;
	GtkWidget *mois;
	GtkWidget *annee;
	GtkWidget *nom_excursion;
	GtkWidget *prix;
	GtkWidget *lieu;
	GtkWidget *heure;
	GtkWidget *reference;
	GtkWidget *output;
	
	excursion exc;

	char tmp[20];

	//associer les objets avec des variables :
	jour=lookup_widget(button, "spinbuttonJour");
	mois=lookup_widget(button, "comboboxentryMois");
	annee=lookup_widget(button, "spinbuttonAnnee");
	heure=lookup_widget(button, "comboboxHeure_excursion");

	nom_excursion=lookup_widget(button, "entryNom_exc");
	reference=lookup_widget(button, "entryReference_exc");
	prix=lookup_widget(button, "spinbuttonPrix");
	lieu=lookup_widget(button, "entrylieu_exc");
	output=lookup_widget(button,"labelEnregistrer");



	//récupérer les valeurs des spins buttons :
	exc.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));	
	exc.prix=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (prix));
	exc.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
	

	//récupérer les valeurs des combobox :
	if(strcmp("09h==>12h15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(heure)))==0)
		exc.heure=1;
	else
		exc.heure=2;

	
	strcpy(exc.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
	

	//récupérer les textes des zones de textes
	strcpy(exc.nom,gtk_entry_get_text(GTK_ENTRY(nom_excursion)));
	strcpy(exc.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
	strcpy(exc.referance,gtk_entry_get_text(GTK_ENTRY(reference)));
	
	
	//enregistrer dans le fichier liste_excurtions.txt
	ajouter_excursion(exc);

	//Changer le message de validation
	gtk_label_set_text(GTK_LABEL(output),"Enregistrement Réussit .");
	
	
}












//3] fenetre_modifier :
//3.1) button (Retour) dans la fenetre modifier
void
on_buttonRetour_Mod_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_modifier;
	GtkWidget *fenetre_excursion;
	

	fenetre_modifier=lookup_widget (button, "fenetre_modifier");
	gtk_widget_destroy(fenetre_modifier);
	

	fenetre_excursion=lookup_widget(button,"fenetre_excursion");
	fenetre_excursion=create_fenetre_excursion();
	gtk_widget_show(fenetre_excursion);

}

// 3.2) button (confirmer) dans la fenetre modifier 
void
on_buttonConfirmer_Modif_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *reference;
	GtkWidget *jour;
	GtkWidget *mois;
	GtkWidget *annee;
	GtkWidget *nom_excursion;
	GtkWidget *prix;
	GtkWidget *heure;
	GtkWidget *lieu;
	GtkWidget *output;
	int v;
	
	excursion exc;

	char tmp[20];

	//associer les objets avec des variables :
	reference=lookup_widget(button, "entryreference");
	jour=lookup_widget(button, "spinbutton_nouv_jour");
	mois=lookup_widget(button, "combobox_nou_mois");
	annee=lookup_widget(button, "spinbutton_nou_annee");
	heure=lookup_widget(button, "combobox_nouv_heure");

	nom_excursion=lookup_widget(button, "entry_nou_nom");
	prix=lookup_widget(button, "spinbutton_nou_prix");
	lieu=lookup_widget(button, "entrylieu_exc");
	output=lookup_widget(button,"labelConfirmation_Mod");



	//récupérer les valeurs des spins buttons :
	exc.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));	
	exc.prix=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (prix));
	exc.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
	

	//récupérer les valeurs des combobox :
	if(strcmp("09h==>12h15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(heure)))==0)
		exc.heure=1;
	else
		exc.heure=2;

	
	strcpy(exc.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
	

	//récupérer les textes des zones de textes
	strcpy(exc.nom,gtk_entry_get_text(GTK_ENTRY(nom_excursion)));
	strcpy(exc.referance,gtk_entry_get_text(GTK_ENTRY(reference)));
	
	//enregistrer dans le fichier liste_excurtions.txt
	v=modifier_excursion(exc);

	//Changer le message de validation
	switch (v)
	{ 
		case 1: gtk_label_set_text(GTK_LABEL(output),"Modification Réussite .");
			break;
		default : gtk_label_set_text(GTK_LABEL(output),"Modification réussite .");
			break;
	}
	

}







//4] fenetre_supprimer :
//4.1) button (Retour) dans la fenetre supprimer
void
on_buttonRetour_Sup_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_supprimer;
	GtkWidget *fenetre_excursion;
	

	fenetre_supprimer=lookup_widget (button, "fenetre_supprimer");
	gtk_widget_destroy(fenetre_supprimer);
	

	fenetre_excursion=lookup_widget(button,"fenetre_excursion");
	fenetre_excursion=create_fenetre_excursion();
	gtk_widget_show(fenetre_excursion);


}


//4.2) button(Supprimer) dans la fenêtre supprimer
void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *input;
	GtkWidget *output;
	char referance1[20];
	char Validation[50];
	int v1;	
	
	input=lookup_widget(button, "entryRefSupp");
	output=lookup_widget(button, "labelText_Sup");
	
	strcpy(referance1, gtk_entry_get_text(GTK_ENTRY(input)));
	
	v1=supprimer_excursion(referance1);
	validsuppression(v1,Validation);

	gtk_label_set_text(GTK_LABEL(output),Validation);
	
	
	
	

	


}







//5] fenetre_Consultation_Excursion :
//5.1) button (Retour) dans la fenetre_Consultation_Excursion
void
on_buttonRetourCons_excu_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_consultation_excursion;
	GtkWidget *fenetre_excursion;
	

	fenetre_consultation_excursion=lookup_widget (button, "fenetre_consultation_excursion");
	gtk_widget_destroy(fenetre_consultation_excursion);
	

	fenetre_excursion=lookup_widget(button,"fenetre_excursion");
	fenetre_excursion=create_fenetre_excursion();
	gtk_widget_show(fenetre_excursion);

}








//6] fenetre_reserver_excursion :
//6.1) button (Retour) dans la fenetre_reserver_excursion
void
on_buttonAnnuler_Reservation_clicked   (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_reserver_excursion;
	GtkWidget *fenetre_excursion;
	

	fenetre_reserver_excursion=lookup_widget (button, "fenetre_reserver_excursion");
	gtk_widget_destroy(fenetre_reserver_excursion);
	

	fenetre_excursion=lookup_widget(button,"fenetre_excursion");
	fenetre_excursion=create_fenetre_excursion();
	gtk_widget_show(fenetre_excursion);

}





//7] fenetre_rechercher
//7.1)  buttonRetourRech dans la fenetre_rechercher
void
on_buttonRetourRech_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_rechercher;
	GtkWidget *fenetre_excursion;
	

	fenetre_rechercher=lookup_widget (button, "fenetre_rechercher");
	gtk_widget_destroy(fenetre_rechercher);
	

	fenetre_excursion=lookup_widget(button,"fenetre_excursion");
	fenetre_excursion=create_fenetre_excursion();
	gtk_widget_show(fenetre_excursion);

}







//8] fenetre (mes reservations)
//8.1) buttonRetourMR dans la fenetre mes reservations


void
on_buttonRetourMR_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_Reservation;
	GtkWidget *fenetre_excursion;
	

	fenetre_Reservation=lookup_widget (button, "fenetre_Reservation");
	gtk_widget_destroy(fenetre_Reservation);
	

	fenetre_excursion=lookup_widget(button,"fenetre_excursion");
	fenetre_excursion=create_fenetre_excursion();
	gtk_widget_show(fenetre_excursion);

}









