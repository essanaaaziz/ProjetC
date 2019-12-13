#include <gtk/gtk.h>
#include <string.h>

int find_heber(char id[]);
int find_client(char id[]);
void ajouter(char id[],int one,int two,int three,int four);
void modifier (int n,int one,int two,int three,int four);
int supprimer (char c[]);
int reserver(char id_h[],char id_c[],int one,int two,int three,int four,int jour,int mois,int annee);
void afficher_reservation(GtkWidget *liste);


