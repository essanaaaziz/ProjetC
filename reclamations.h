#include <gtk/gtk.h> 

typedef struct 
{
char texte [5000];
char nom [30];
char date [20];
char numero [20];
}reclamation;

void modifier (char EntreNum[] ,char texteM[],char nomM[],char dateM[],char numeroM[] );
void ajouter_reclamation(reclamation r);
void afficher_reclamation(GtkTreeView *liste);
void supprimer(char a[20]);
void afficher_reponse(GtkTreeView *liste);
