#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fonctionvols.h"
void Volselectionner(char choix[])
{
FILE* f;
f=fopen("volselectionner.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s\n",choix);    
fclose(f);
}   
}

void ReserverVols(char Idclient[])
{
char id[30],depart[30],destination[30],jour1[30],mois1[30],annee1[30],jour2[30],mois2[30],annee2[30],prix[30],class[30],Idvol[30];
FILE* f;
f=fopen("volselectionner.txt","r");
while(fscanf(f,"%s\n",Idvol)!=EOF);    
fclose(f);
FILE*t;
FILE*g;
t=fopen("vols.txt","r");
g=fopen("Reservation.txt","a+");
if((t!=NULL)&&(g!=NULL))
{
while(fscanf(t,"%s %s %s %s %s %s %s %s %s %s %s\n",id,depart,destination,jour1,mois1,annee1,jour2,mois2,annee2,prix,class)!=EOF)
if(strcmp(id,Idvol)==0)
{
    fprintf(g,"%s %s %s %s %s %s %s %s ",id,depart,destination,jour1,mois1,annee1,jour2,mois2,annee2,prix,class);
    fprintf(g,"%s %s %s\n",Idclient);
}    
    
}
fclose(t);
fclose(g);

}

int verifier_saisie(char Idclient[])
{
    int i,test=0;
    if((strlen(Idclient)>0))
        return 0;
    else
        return 1;
}

void SupprimerVols(char choix[])
{
char id[30],Depart[30],Destination[30],jour1[30],mois1[30],annee1[30],jour2[30],mois2[30],annee2[30],Prix[30],class[30];
 FILE *f , *tmp;
 f=fopen("vols.txt","r");
 tmp=fopen("vols1.txt","a+");
 if(f!=NULL)
 {
 while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s ",id,Depart,Destination,jour1,mois1,annee1,jour2,mois2,annee2,Prix,class)!=EOF)
    {
    if(strcmp(choix,id)==0)
        {
          continue;
          
        }
        
    else
    {
    fprintf(tmp,"%s %s %s %s %s %s %s %s %s %s %s\n",id,Depart,Destination,jour1,mois1,annee1,jour2,mois2,annee2,Prix,class);
    }
    }
fclose(f);
fclose(tmp);
rename("vols1.txt","vols.txt");   
}
}

void modifier(char choix[],char DepartM[],char DestinationM[],char JourAllM[],char MoisAllM[],char  AnneeAllM[] ,char JourRetM[],char MoisRetM[],char  AnneeRetM[] ,char PrixM[],char ClassM[])
{
char id[30],depart[30],destination[30],class[30],jour1[30],mois1[30],annee1[30],jour2[30],mois2[30],annee2[30],prix[30];
FILE *f,*tmp;

f=fopen("vols.txt","r");
tmp=fopen("vols1.txt","a+");
 
 if(f!=NULL)
 {
 while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",id,depart,destination,jour1,mois1,annee1,jour2,mois2,annee2,prix,class)!=EOF)
 {
     
      if(strcmp(choix,id)==0)
    {

        fprintf(tmp,"%s %s %s %s %s %s %s %s %s %s %s\n",choix,DepartM,DestinationM,JourAllM,MoisAllM,AnneeAllM,JourRetM,MoisRetM,AnneeRetM,PrixM,ClassM);
    } 
    
      else
    {
        fprintf(tmp,"%s %s %s %s %s %s %s %s %s %s %s\n",id,depart,destination,jour1,mois1,annee1,jour2,mois2,annee2,prix,class);
    }
     
}
fclose(f);
fclose(tmp);
rename("vols1.txt","vols.txt");
}
}


int verifier_selection(char choix[])
{
FILE* f;

char ID[5],destination[30],depart[30],class[30],jour1[30],mois1[30],annee1[30],jour2[30],mois2[30],annee2[30],prix[30];
f=fopen("vols.txt","r");

if(f!=NULL)
{
while((fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s",ID,destination,depart,jour1,mois1,annee1,jour2,mois2,annee2,prix,class)!=EOF))
{
    if(strcmp(ID,choix)==0)
    {

        return 0;
        }
    }
}
return 1;
}

int verifier(char Depart[],char Destination[])
{
if(strcmp(Depart,Destination)==0)
return 0;
else
return 1;
}

void AjoutVol(char Depart[],char Destination[],int JourAll,int MoisAll,int AnneeAll,int JourRet,int MoisRet,int AnneeRet,int Prix,char Class[])
{
FILE *f;
int Id=1;
int id,jourAll,moisAll,anneeAll,jourRet,moisRet,anneeRet,prix;
char depart[30],destination[30],class[30];
f=fopen("vols.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %d %d %d %d %d %d %d %s",&id,depart,destination,&jourAll,&moisAll,&anneeAll,&jourRet,&moisRet,&anneeRet,&prix,class)!=EOF)
      {
        Id++;
      }
      fclose(f);
}
id=Id;
f=fopen("vols.txt","a+");

if(f!=NULL)
{
fprintf(f,"%d %s %s %d %d %d %d %d %d %d %s\n",Id,Depart,Destination,JourAll,MoisAll,AnneeAll,JourRet,MoisRet,AnneeRet,Prix,Class);
fclose(f);
}
}

enum
{
    IDVOLS,
    DESTINATION,
    DEPART,
    JOURALL,
    MOISALL,
    ANNEEALL,
    JOURRET,
    MOISRET,
    ANNEERET,
    PRIX,
    CLASS,
    COLUMNS
};

void AfficherVol(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Destination[30],Depart[30],Class[30];
char JourAll[30],MoisAll[30],AnneeAll[30],JourRet[30],MoisRet[30],AnneeRet[30],Prix[30],IdVols[30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("IdVols",renderer,"text",IDVOLS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Depart",renderer,"text",DEPART,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Destination",renderer,"text", DESTINATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JourAll",renderer,"text",JOURALL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("MoisAll",renderer,"text",MOISALL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("AnneeAll",renderer,"text",ANNEEALL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JourRet",renderer,"text",JOURRET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("MoisRet",renderer,"text",MOISRET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("AnneeRet",renderer,"text",ANNEERET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Class",renderer,"text",CLASS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("vols.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	{ 
	f=fopen("vols.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s",IdVols,Depart,Destination,JourAll,MoisAll,AnneeAll,JourRet,MoisRet,AnneeRet,Prix,Class)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDVOLS,IdVols,DEPART,Depart,DESTINATION,Destination,JOURALL,JourAll,MOISALL,MoisAll,ANNEEALL,AnneeAll,JOURRET,JourRet,MOISRET,MoisRet,ANNEERET,AnneeRet,PRIX,Prix,CLASS,Class,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void RechercherVol(GtkWidget *liste,char filtre[])
{

enum
{
    IDVOLS,
    DESTINATION,
    DEPART,
    JOURALL,
    MOISALL,
    ANNEEALL,
    JOURRET,
    MOISRET,
    ANNEERET,
    PRIX,
    CLASS,
    COLUMNS
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Destination[30],Depart[30],Class[30];
char JourAll[30],MoisAll[30],AnneeAll[30],JourRet[30],MoisRet[30],AnneeRet[30],Prix[30],IdVols[30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("IdVols",renderer,"text",IDVOLS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Depart",renderer,"text",DEPART,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Destination",renderer,"text", DESTINATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JourAll",renderer,"text",JOURALL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("MoisAll",renderer,"text",MOISALL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("AnneeAll",renderer,"text",ANNEEALL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JourRet",renderer,"text",JOURRET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("MoisRet",renderer,"text",MOISRET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("AnneeRet",renderer,"text",ANNEERET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Class",renderer,"text",CLASS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("vols.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	{ 
	f=fopen("vols.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s",IdVols,Depart,Destination,JourAll,MoisAll,AnneeAll,JourRet,MoisRet,AnneeRet,Prix,Class)!=EOF)
		{
                        if(strcmp(filtre,IdVols)==0)
                            {
			       gtk_list_store_append(store,&iter); gtk_list_store_set(store,&iter,IDVOLS,IdVols,DEPART,Depart,DESTINATION,Destination,JOURALL,JourAll,MOISALL,MoisAll,ANNEEALL,AnneeAll,JOURRET,JourRet,MOISRET,MoisRet,ANNEERET,AnneeRet,PRIX,Prix,CLASS,Class,-1);
	}
                 }
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}



