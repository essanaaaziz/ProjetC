#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>

enum
{
	hotel,
	nom,
	SIMPLES,
	DOUBLES,
	TRIPLES,
	QUADRUPLES,
	DATE,
	COLUMNS1
};


int find_heber(char id[])
{FILE *f;
    int n;
    char nom[20];
int one,two,three,four;
int test, i;
test=0;
i=0;
    f=fopen("/home/aziz/Projects/heber/src/heber1.txt","r");
    
if(f!=NULL)
{ while(fscanf(f,"%s %d %d %d %d\n",nom,&one,&two,&three,&four)!=EOF)
 {if ((strcmp(nom,id))==1)
     {i++;
      }
else
test=1;
}
if (test==1)
{
n=i;
test=0;
}
} 


return (n);


}





int find_client(char id[])
{FILE *f;
    int n;
    char id_h[20],id_c[20];

int one,two,three,four,jour,mois,annee;
int test;


n=0;
    f=fopen("/home/aziz/Projects/heber/src/clients.txt","r");
    
if(f!=NULL)
{ while(fscanf(f,"%s %s %d %d %d %d %d/%d/%d",id_h,id_c,&one,&two,&three,&four,&jour,&mois,&annee)!=EOF)
 {if ((strcmp(id,id_c))==1)
     {n++;
       test=1;}
}} 


if(test==1)
return (n);

else
return (-1);
}



void ajouter(char id[],int one,int two,int three,int four)
{ FILE* f;

 
    f=fopen("/home/aziz/Projects/heber/src/heber1.txt","a+");


    if(f!=NULL)
{



    fprintf(f,"%s %d %d %d %d\n",id,one,two,three,four);

fclose(f);
}
else
    printf("impossible d'ouvrir le ficher");
}






void modifier (int n,int one,int two,int three,int four)
{FILE *f,*f1;
    char nom[20],id[20];
int un,deux,trois,quat;

int i;
i=0;

    f=fopen("/home/aziz/Projects/heber/src/heber1.txt","r");
    f1=fopen("/home/aziz/Projects/heber/src/heber2.txt","a+");

if(f!=NULL)
{ while(fscanf(f,"%s %d %d %d %d\n",nom,&un,&deux,&trois,&quat)!=EOF)
 {if (i!=n)
   fprintf(f1,"%s %d %d %d %d\n",nom,un,deux,trois,quat);
 else
  strcpy(id,nom);
   i++;
}}
fprintf(f1,"%s %d %d %d %d\n",id,one,two,three,four);

fclose(f);
fclose (f1);
remove("/home/aziz/Projects/heber/src/heber1.txt");
rename("/home/aziz/Projects/heber/src/heber2.txt","/home/aziz/Projects/heber/src/heber1.txt");

}







int supprimer (char c[])
{FILE *f,*f1;
    char cou[20];
int test,r1,one,two,three,four;
test=0;
    f=fopen("/home/aziz/Projects/heber/src/heber1.txt","r");
    f1=fopen("/home/aziz/Projects/heber/src/heber2.txt","a+");
if(f!=NULL)
{ while(fscanf(f,"%s %d %d %d %d\n",cou,&one,&two,&three,&four)!=EOF)
 {if ((strcmp(cou,c)))




    fprintf(f1,"%s %d %d %d %d\n",cou,one,two,three,four);

else
  test=1;

}}
fclose(f);
fclose (f1);
remove("/home/aziz/Projects/heber/src/heber1.txt");
rename("/home/aziz/Projects/heber/src/heber2.txt","/home/aziz/Projects/heber/src/heber1.txt");
return test;
}



int reserver(char id_h[],char id_c[],int one,int two,int three,int four,int jour,int mois,int annee)
{
FILE *f1,*f2,*f3;
    char nom2[50];
int un1,deux2,trois3,quat4;
int un,deux,trois,quat,test,n,i;
char nom[50];
test=0;

n=find_heber(id_h);
f1=fopen("/home/aziz/Projects/heber/src/heber1.txt","a+");
f2=fopen("/home/aziz/Projects/heber/src/liste_reservations.txt","a+");
f3=fopen("/home/aziz/Projects/heber/src/heber2.txt","a+");



for (i=0;i<n;i++)

    fscanf(f1,"%s %d %d %d %d\n",nom,&un,&deux,&trois,&quat);


if((one<=un)&&(two<=deux)&&(three<=trois)&&(four<=quat))
    test=1;


if (test==1)
{un=un-one;
deux=deux-two;
trois=trois-three;
quat=quat-four;


i=1;

fclose(f1);
f1=fopen("/home/aziz/Projects/heber/src/heber1.txt","a+");


if(f3!=NULL)
{ while(fscanf(f1,"%s %d %d %d %d\n",nom2,&un1,&deux2,&trois3,&quat4)!=EOF)
 {if (i!=n)
   fprintf(f3,"%s %d %d %d %d\n",nom2,un1,deux2,trois3,quat4);

   i++;
}}
fprintf(f3,"%s %d %d %d %d\n",id_h,un,deux,trois,quat);
}
fclose(f1);
fclose(f3);
remove("/home/aziz/Projects/heber/src/heber1.txt");
rename("/home/aziz/Projects/heber/src/heber2.txt","/home/aziz/Projects/heber/src/heber1.txt");


fprintf(f2,"%s %s %d %d %d %d %d/%d/%d\n",id_h,id_c,one,two,three,four,jour,mois,annee);

fclose(f2);


return test;
}

void afficher_reservation(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char id_h[30];
char id_c[30];
char simplesc[30],doublesc[30],triplesc[30],quadruplesc[30],jourc[30],moisc[30],anneec[30];
int simples,doubles,triples,quadruples,jour,mois,annee;
store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
f=fopen("/home/aziz/Projects/heber/src/liste_reservations.txt","r");
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Hotel",renderer,"text",hotel,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",nom,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Chambres simples",renderer,"text",SIMPLES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Chambres doubles",renderer,"text",DOUBLES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Chambres triples",renderer,"text",TRIPLES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();

column=gtk_tree_view_column_new_with_attributes("Chambres quad",renderer,"text",QUADRUPLES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
renderer=gtk_cell_renderer_text_new();
	
column=gtk_tree_view_column_new_with_attributes("Date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	

	store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("/home/aziz/Projects/heber/src/liste_reservations.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("/home/aziz/Projects/heber/src/liste_reservations.txt","a+");
		while(fscanf(f,"%s %s %d %d %d %d %d/%d/%d\n",id_h,id_c,&simples,&doubles,&triples,&quadruples,&jour,&mois,&annee)!=EOF)
		{ sprintf(simplesc,"%d",simples);
sprintf(doublesc,"%d",doubles);
sprintf(triplesc,"%d",triples);
sprintf(quadruplesc,"%d",quadruples);
sprintf(jourc,"%d/%d/%d",jour,mois,annee);

			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,hotel,id_h,nom,id_c,SIMPLES,simplesc,DOUBLES,doublesc,TRIPLES,triplesc,QUADRUPLES,quadruplesc,DATE,jourc, -1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}




















