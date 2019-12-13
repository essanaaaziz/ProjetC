#include <gtk/gtk.h>

typedef struct 
{
char texte [5000];
char nom [30];
char date [20];
char numero [20];
}reclamation;

typedef struct 
{
char texte [5000];
char num[20];

}reply;

void afficher(GtkTreeView *liste);
void ajouter_reponse(reply a);
