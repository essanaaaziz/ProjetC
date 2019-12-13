#include <stdio.h>
#include <string.h>
#include "agent.h"
#include <gtk/gtk.h>


enum
{
	TEXTE,
	NOM,
	DATE,
	NUMERO,
	COLUMNS
};




void afficher (GtkTreeView *liste)
{ 
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store=NULL;
char texte [5000];
char nom [30];
char date [20];
char num[20];


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

f = fopen("/home/daly/Projects/project13/recla.txt","r");
if (f== NULL)
{
	return;
}
else
{ f=fopen("/home/daly/Projects/project13/recla.txt","a+");
	while(fscanf(f,"%s %s %s %s \n",texte,nom,date,num)!=EOF)
	{
gtk_list_store_append (store, &iter);
gtk_list_store_set( store,&iter,TEXTE,texte,NOM,nom,DATE,date,NUMERO,num, -1);
	}
fclose(f); }
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}


void ajouter_reponse(reply a) 
{ 
FILE *f;
f=fopen("ageent.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s \n",a.texte,a.num);
fclose(f);
}
}



