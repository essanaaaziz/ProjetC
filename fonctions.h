#include <gtk/gtk.h>

typedef struct
{
char cin[20];
char nom[20];
char prenom[30];
char nt[30];
char mp[10];

}personne;

void ajouter_personne(personne p);
void ajoutera_personne(personne p);
void sup_dispo(char a[20]);
void sup_dispou(char a[20]);
void afficher_personne(GtkWidget *liste);
void modifiera(char cinad[],char cin[],char nom[],char prenom[],char nt[],char md[]);
void modifiera(char cinmod[],char cin[],char nom[],char prenom[],char nt[],char md[]);
