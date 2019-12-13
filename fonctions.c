#include "fonctions.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
				
enum
{
	REFERANCE,
	NOM,
	JOUR,
	MOIS,
	ANNEE,
	LIEU,
	PRIX,
	HEURE,
};
	
	
	
//fonction recherche excursion
int recherche_excursion(excursion excinit)
{
	excursion exc;
	int v=0;	//excursion non trouvée
	FILE* f=fopen("liste_Excursions.txt","r");
	if (f!=NULL)
	{
		while (!v && fscanf(f,"%s %s %s %d %d %s %d %d \n",exc.nom, exc.referance,exc.lieu, &exc.prix, &exc.jour, exc.mois, &exc.annee, &exc.heure)!=EOF)
		{
			if (strcmp(exc.nom,excinit.nom)==0)
			{
				v=1;
			}
		}
	}
	fclose(f);
	return v;
}


// fonction ajouter excursion
void ajouter_excursion(excursion e)
{
	FILE *f=fopen("liste_excursion.txt","a+");
	if (f!=NULL)
	{
		fprintf(f,"%s %s %s %d %d %s %d %d \n",e.nom, e.referance,e.lieu, e.prix, e.jour, e.mois, e.annee, e.heure);
			
	}
	fclose(f);
}




// fonction afficher excursion avec treeview :
void afficher_excursion(GtkListStore *liste)
{
enum
{
	REFERANCE,
	NOM,
	JOUR,
	MOIS,
	ANNEE,
	LIEU,
	PRIX,
	HEURE,
	COLUMNS
};
	GtkCellRenderer *renderer; //afficheur de cellule
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	

	char nom[20];
	char referance[20];
	int jour;
	char Jour[20];
	char mois[20];
	int annee;
	char Annee[20];
	char lieu[20];
	int prix;
	char Prix[20];
	int heure;
	char Heure[20];

	store =NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("referance",renderer,"text",REFERANCE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("lieu",renderer,"text",LIEU,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

		f=fopen("liste_excursion.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
	
		{ 		
			f=fopen("liste_excursion.txt","a+");
			while(fscanf(f,"%s %s %s %d %d %s %d %d \n",nom,referance,lieu,&prix,&jour,mois,&annee,&heure)!=EOF)
			{
				sprintf(Prix,"%d",prix);
				sprintf(Jour,"%d",jour);
				sprintf(Annee,"%d",annee);
				sprintf(Heure,"%d",heure);
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,REFERANCE,referance,NOM,nom,JOUR,Jour,MOIS,mois,ANNEE,Annee,LIEU,lieu,PRIX,Prix,HEURE,Heure,-1);
			}
	   	fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
	}
}


// fonction supprimer excursion
int supprimer_excursion(char a[20] )
{
	FILE *f=fopen("liste_excursion.txt","r");
	FILE *t=fopen("liste_excursion1.tmp","a+");
	char nom[20];
	char referance[20];
	int jour;
	char Jour[20];
	char mois[20];
	int annee;
	char Annee[20];
	char lieu[20];
	int prix;
	char Prix[20];
	int heure;
	char Heure[20];
	int v=0;
	
	if (f!=NULL)
	{
		while(fscanf(f,"%s %s %s %d %d %s %d %d \n",nom,referance,lieu,&prix,&jour,mois,&annee,&heure)!=EOF)
		{
			if (strcmp(a,referance)!=0)
			{
				fprintf(t,"%s %s %s %d %d %s %d %d \n",nom,referance,lieu,prix,jour,mois,annee,heure);
			}
			else 
			{
				v=1;
				
			}
		}

		
		
	}
	fclose(f);
	fclose(t);
	remove ("liste_excursion.txt");
	rename ("liste_excursion1.tmp","liste_excursion.txt");
	
}





// Déclaration de la fonction Modifier-Excursion :

int modifier_excursion(excursion exc )
{
	FILE *f=fopen("liste_excursion.txt","r");
	FILE *t=fopen("liste_excursion1.tmp","a+");
	char nom[20];
	char referance[20];
	int jour;
	char Jour[20];
	char mois[20];
	int annee;
	char Annee[20];
	char lieu[20];
	int prix;
	char Prix[20];
	int heure;
	char Heure[20];
	int v=0;
	
	if (f!=NULL)
	{
		while(fscanf(f,"%s %s %s %d %d %s %d %d \n",nom,referance,lieu,&prix,&jour,mois,&annee,&heure)!=EOF)
		{
			if (strcmp(exc.referance,referance)!=0)
			{
				fprintf(t,"%s %s %s %d %d %s %d %d \n",nom,referance,lieu,prix,jour,mois,annee,heure);
			}
			else 
			{
				strcpy (exc.referance, referance);
				strcpy (exc.lieu , lieu);
				fprintf(t,"%s %s %s %d %d %s %d %d \n", exc.nom, exc.referance, exc.lieu, exc.prix, exc.jour, exc.mois, exc.annee, exc.heure);
				v=1;
				
			}
		}

		
		
	}
	fclose(f);
	fclose(t);
	remove ("liste_excursion.txt");
	rename ("liste_excursion1.tmp","liste_excursion.txt");
	
}






//déclaration de la fonction recherche dans la fenetre excursion
void recherche (char lieu[20])
{
	excursion exc;
	FILE *f=fopen("liste_excursion.txt","r");
	FILE *f1=fopen("recherche.txt","w");


	if (f!=NULL)
	{
		while (fscanf(f,"%s %s %s %d %d %s %d %d \n",exc.nom, exc.referance,exc.lieu, &exc.prix, &exc.jour, exc.mois, &exc.annee, &exc.heure)!=EOF)
		{
			if (strcmp(exc.lieu,lieu)==0)
			{
				
				if (f1!=NULL)
				{
					fprintf(f1,"%s %s %s %d %d %s %d %d \n",exc.nom, exc.referance,exc.lieu, exc.prix, exc.jour, exc.mois, exc.annee, exc.heure);
			
				}
				
			}
		}
	}
	fclose(f);
	fclose(f1);

}






//déclaration de la fonction affichage du treeview concernant la recherche du lieu (fenetre excursion)

void afficher_lieu_recherche(GtkListStore *liste)
{
enum
{
	REFERANCE,
	NOM,
	JOUR,
	MOIS,
	ANNEE,
	LIEU,
	PRIX,
	HEURE,
	COLUMNS
};
	GtkCellRenderer *renderer; //afficheur de cellule
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	

	char nom[20];
	char referance[20];
	int jour;
	char Jour[20];
	char mois[20];
	int annee;
	char Annee[20];
	char lieu[20];
	int prix;
	char Prix[20];
	int heure;
	char Heure[20];

	store =NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("referance",renderer,"text",REFERANCE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("lieu",renderer,"text",LIEU,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

		f=fopen("recherche.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
	
		{ 		
			f=fopen("recherche.txt","a+");
			while(fscanf(f,"%s %s %s %d %d %s %d %d \n",nom,referance,lieu,&prix,&jour,mois,&annee,&heure)!=EOF)
			{
				sprintf(Prix,"%d",prix);
				sprintf(Jour,"%d",jour);
				sprintf(Annee,"%d",annee);
				sprintf(Heure,"%d",heure);
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,REFERANCE,referance,NOM,nom,JOUR,Jour,MOIS,mois,ANNEE,Annee,LIEU,lieu,PRIX,Prix,HEURE,Heure,-1);
			}
	   	fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
	}
}




















	
	






	

