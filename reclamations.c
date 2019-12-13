#include <stdio.h>
#include <string.h>
#include "reclamations.h"
#include <gtk/gtk.h>

enum
{
	TEXT,
	NUM,
	COLUMNS1
};


void afficher_reponse(GtkTreeView *liste)
{ 
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL;
char texte [5000];
char num[20];


FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{ renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes ("texte",renderer,"text",TEXT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes ("num",renderer,"text",NUM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING);

f = fopen("/home/daly/Projects/project14/src/ageent.txt","r");
if (f== NULL)
{
	return;
}
else
{ f=fopen("/home/daly/Projects/project14/src/ageent.txt","a+");
	while(fscanf(f,"%s %s \n" ,texte,num)!=EOF)
	{
gtk_list_store_append (store, &iter);
gtk_list_store_set( store,&iter,TEXT,texte,NUM,num,-1);
	}
fclose(f); }
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);

}

}


void supprimer ( char a[20])
{
char texte[5000];
char nom[30];
char date [20];
char numero[20];

FILE *l;
FILE *t;
l=fopen("recla.txt","r");
t=fopen("recla.tmp","a");
while (fscanf(l,"%s %s %s %s",texte,nom,date,numero)!=EOF)
{
if (strcmp (a,numero)!=0)
{ fprintf (t,"%s %s %s %s \n",texte,nom,date,numero); }
}
fclose(l);
fclose(t);
remove("recla.txt");
rename("recla.tmp","recla.txt");



}

void modifier (char EntreNum[] ,char texteM[],char nomM[],char dateM[],char numeroM[] )
{ 
char texte [5000] , nom[30],date[20],numero[20]  ;
FILE *f,*tmp;

f=fopen("recla.txt","r");
tmp=fopen("recla1.txt","a+");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s " ,texte,nom,date,numero)!=EOF)
{
if (strcmp(EntreNum,numero)==0)
{ 
fprintf(tmp,"%s %s %s %s",texteM,nomM,dateM,numeroM);
}
else
{ 
fprintf (tmp,"%s %s %s %s",texte,nom,date,numero);
}
}
fclose(f);
fclose(tmp);
rename("recla1.txt","recla.txt");
}
}

void ajouter_reclamation(reclamation r) 
{ 
FILE *f;
f=fopen("recla.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s \n",r.texte,r.nom,r.date,r.numero);
fclose(f);
}
}


enum
{
	TEXTE,
	NOM,
	DATE,
	NUMERO,
	COLUMNS
};




void afficher_reclamation(GtkTreeView *liste)
{ 
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL;
char texte [5000];
char nom [30];
char date [20];
char numero[20];


FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{ renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes ("texte",renderer,"text",TEXTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes ("date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes ("numero",renderer,"text",NUMERO,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

f = fopen("recla.txt","r");
if (f== NULL)
{
	return;
}
else
{ f=fopen("recla.txt","a+");
	while(fscanf(f,"%s %s %s %s \n" ,texte,nom,date,numero)!=EOF)
	{
gtk_list_store_append (store, &iter);
gtk_list_store_set( store,&iter,TEXTE,texte,NOM,nom,DATE,date,NUMERO,numero,-1);
	}
fclose(f); }
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}


}










