#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <gtk/gtk.h>

typedef struct
{
  char Matricule1[30];
  char Matricule2[30];
  char Modele[30],Prix[30],Date[30];

}Voiture;

 struct cellule
{
  Voiture v;
  struct cellule* suivant;
};

typedef struct cellule* liste;

void afficher_voitures(GtkWidget *liste);
void ajouter_voitures(Voiture v);
void modifier_voitures(char Modele[30], char Matricule1[30], char Matricule2[30], char Prix[30],   char Date[30]);
void supprimer_voitures(char Matricule1[30], char Matricule2[30]) ;
void afficher_voituresC (Voiture v);




#endif
