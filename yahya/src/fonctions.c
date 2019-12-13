#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>

enum
{
	CIN,
	NOM,
	PRENOM,
	nt,
	mp,
	COLUMNS
};

void ajouter_personne(personne p)
{
 int r=3;
 FILE *f;
 f=fopen("utilisateur.txt","a+");
 FILE *f1;
 f1=fopen("users.txt","a+");
 {
 fprintf(f,"%s %s %s %s %s\n",p.cin,p.nom,p.prenom,p.nt,p.mp);
 
 fprintf(f1,"%s %s 3 \n",p.cin,p.mp);
 fclose(f1);
fclose(f);
 }

}
void ajoutera_personne(personne p)
{
 int r=3;
 FILE *f;
 f=fopen("utilisateura.txt","a+");
 FILE *f1;
 f1=fopen("users.txt","a+");
 {
 fprintf(f,"%s %s %s %s %s \n",p.cin,p.nom,p.prenom,p.nt,p.mp);
 
 fprintf(f1,"%s %s 2 \n",p.cin,p.mp);
 fclose(f1);
fclose(f);
 }

}



void sup_dispo(char a[20])// a dekhla en parametre 
{
	char a1[20];
	char b1[20];
	char c1[20];
        char d1[20];
        char e1[20];

	FILE *l;
	FILE *t;
	l=fopen("utilisateura.txt","r");
	t=fopen("Disponibilite.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s\n ",a1,b1,c1,d1,e1)!=EOF)//na9raw mil fichier temporaire
	{
		if (strcmp(a,a1)!=0)//ken la valeur ili na9raw fiha differente mil parametre ya3ni ncopiw i ligne fel fichier e jdid
		{
			fprintf(t,"%s %s %s %s %s\n ",a1,b1,c1,d1,e1);//copie de la ligne fel fichier jdid
		}
	}
	fclose(l);
	fclose(t);
	remove("Disponibilite.txt");//nfas5ou il fichier li9dim
	rename("Disponibilite.tmp","utilisateura.txt");//enronomiw il fichier ejdid b esm li9dim bech ye5ou blastou
}
void sup_dispou(char a[20])// a dekhla en parametre 
{
	char a1[20];
	char b1[20];
	char c1[20];
        char d1[20];
        char e1[20];

	FILE *l;
	FILE *t;
	l=fopen("utilisateur.txt","r");
	t=fopen("Disponibilite.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s\n ",a1,b1,c1,d1,e1)!=EOF)//na9raw mil fichier temporaire
	{
		if (strcmp(a,a1)!=0)//ken la valeur ili na9raw fiha differente mil parametre ya3ni ncopiw i ligne fel fichier e jdid
		{
			fprintf(t,"%s %s %s %s %s\n ",a1,b1,c1,d1,e1);//copie de la ligne fel fichier jdid
		}
	}
	fclose(l);
	fclose(t);
	remove("Disponibilite.txt");//nfas5ou il fichier li9dim
	rename("Disponibilite.tmp","utilisateur.txt");//enronomiw il fichier ejdid b esm li9dim bech ye5ou blastou
}
void modifier(char cinmod[],char cin[],char nom[],char prenom[],char nt[],char md[])
{
char c[30],n[30],p[30],nt1[30], md1[30];
char ci[30],mdi[30];
int r;
FILE *f,*tmp;
FILE *f1,*tmp1;
f=fopen("users.txt","r");
f1=fopen("utilisateur.txt","r");
tmp=fopen("ut.txt","a+");
tmp1=fopen("ut1.txt","a+");
 
 if(f!=NULL)
 {
 while(fscanf(f1,"%s %s %s %s %s\n",c,n,p,nt1,md1)!=EOF)
 {
     {
      if(strcmp(c,cinmod)!=0)
       
    {

        {fprintf(tmp,"%s %s %s %s %s\n",c,n,p,nt1,md1);
        }
    } 
    
      else
    {
        fprintf(tmp,"%s %s %s %s %s\n",cin,nom,prenom,nt,md);
        
    }
     
}
}
while(fscanf(f,"%s %s %d\n",ci,mdi,&r)!=EOF)
{if(strcmp(ci,cinmod)!=0)
{fprintf(tmp1,"%s %s %d\n",ci,mdi,r);}
else
{fprintf(tmp1,"%s %s %d\n",cin,md,r);}
}
fclose(f1);
fclose(f);
fclose(tmp);
fclose(tmp1);
rename("ut.txt","utilisateur.txt");
rename("ut1.txt","users.txt");
}
}

void modifiera(char cinad[],char cin[],char nom[],char prenom[],char nt[],char md[])
{
char c[30],n[30],p[30],nt1[30], md1[30];
char ci[30],mdi[30];
int r;
FILE *f,*tmp;
FILE *f1,*tmp1;
f=fopen("users.txt","r");
f1=fopen("utilisateura.txt","r");
tmp=fopen("ut.txt","a+");
tmp1=fopen("ut1.txt","a+");
 
 if(f!=NULL)
 {
 while(fscanf(f1,"%s %s %s %s %s\n",c,n,p,nt1,md1)!=EOF)
 {
     {
      if(strcmp(c,cinad)!=0)
       
    {

        {fprintf(tmp,"%s %s %s %s %s\n",c,n,p,nt1,md1);
        }
    } 
    
      else
    {
        fprintf(tmp,"%s %s %s %s %s\n",cin,nom,prenom,nt,md);
        
    }
     
}
}
while(fscanf(f,"%s %s %d\n",ci,mdi,&r)!=EOF)
{if(strcmp(ci,cinad)!=0)
{fprintf(tmp1,"%s %s %d\n",ci,mdi,r);}
else
{fprintf(tmp1,"%s %s %d\n",cin,md,r);}
}
fclose(f1);
fclose(f);
fclose(tmp);
fclose(tmp1);
rename("ut.txt","utilisateura.txt");
rename("ut1.txt","users.txt");
}
}


void afficher_personne(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char nom[30];
char prenom [30];
char nt [30];
char mp [30];
char cin [30];
store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nt",renderer,"text",nt,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mp",renderer,"text",mp,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("utilisateur.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("utilisateur.txt","a+");
		while(fscanf(f,"%s %s %s %s %s \n",cin,nom,prenom,nt,mp)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,nt,nt,mp,mp,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

