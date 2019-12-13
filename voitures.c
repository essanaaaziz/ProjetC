#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voitures.h"
#include <gtk/gtk.h>


enum
{
         MATRICULE1,
         MATRICULE2,
         MODELE,
         PRIX,											
         DATE,
	COLUMNS1
};

void afficher_voitures(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char Matricule1[30], Matricule2[30];
char Modele[30], Prix[30], Date[30];


store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
        f=fopen("/home/yasmine/Projects/Loc-voiture/src/voitures.txt","r");

	if (store==NULL)
	{ 
             
                
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Matricule1", renderer, "text",MATRICULE1, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Matricule2", renderer, "text",MATRICULE2, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Modele", renderer, "text",MODELE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}


	store=gtk_list_store_new (COLUMNS1, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("/home/yasmine/Projects/Loc-voiture/src/voitures.txt", "r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("/home/yasmine/Projects/Loc-voiture/src/voitures.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s \n",Matricule1,Matricule2,Modele,Prix,Date)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,  MATRICULE1, Matricule1, MATRICULE2, Matricule2, MODELE, Modele,PRIX,Prix, DATE, Date,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

void ajouter_voitures(Voiture v)
{

FILE *f;
  f=fopen("/home/yasmine/Projects/Loc-voiture/src/voitures.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s\n",v.Matricule1,v.Matricule2,v.Modele,v.Prix,v.Date);
}
 fclose(f);

}
//modifier la voiture

void modifier_voitures(char Modele[30], char Matricule1[30], char Matricule2[30], char Prix[30], char Date[30])
{

FILE* f;
FILE* f1;
        char Modele1[30];
	char Matricule01[30];
	char Matricule02[30];
	char date1[30];
	char prix1[30];

f=fopen("/home/yasmine/Projects/Loc-voiture/src/voitures.txt","r");
f1=fopen("/home/yasmine/Projects/Loc-voiture/src/voiturestmp.txt","w");

while (fscanf(f,"%s %s %s %s %s \n",Matricule01,Matricule02,Modele1,prix1,date1)!=EOF)
{
	if((strcmp(Matricule2,Matricule02)==0) && (strcmp(Matricule1,Matricule01)==0) )
	{
		fprintf(f1,"%s %s %s %s %s\n",Matricule1,Matricule2,Modele,Prix,Date);
	}
	else
	{
		fprintf(f1,"%s %s %s %s %s\n",Matricule01,Matricule02,Modele1,prix1,date1);
	}
}
fclose(f);
fclose(f1);
remove("/home/yasmine/Projects/Loc-voiture/src/voitures.txt");
rename("/home/yasmine/Projects/Loc-voiture/src/voiturestmp.txt","/home/yasmine/Projects/Loc-voiture/src/voitures.txt");
}


void supprimer_voitures(char Matricule1[30], char Matricule2[30]) 
{ 

 	char Modele1[30];
	char Matricule01[30];
	char Matricule02[30];
	char date1[30];
	char prix1[30];
 
     FILE *s;
     FILE *t;


 	s=fopen("/home/yasmine/Projects/Loc-voiture/src/voitures.txt","r");
 	t=fopen("/home/yasmine/Projects/Loc-voiture/src/voiturestmp.txt","a+");


	while (fscanf(s,"%s %s %s %s %s \n", Matricule01, Matricule02, Modele1, prix1, date1)!=EOF)	
        {
          if (strcmp(Matricule2,Matricule02)!=0)
           {
            	if (strcmp(Matricule1,Matricule01)!=0)
                   fprintf(t,"%s %s %s %s %s \n", Matricule01, Matricule02, Modele1, prix1, date1);
           }
        }

 	fclose(s);
	fclose(t);
	remove("/home/yasmine/Projects/Loc-voiture/src/voitures.txt");
	rename("/home/yasmine/Projects/Loc-voiture/src/voiturestmp.txt","voitures.txt");
}












































