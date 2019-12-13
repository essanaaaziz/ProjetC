#include <gtk/gtk.h>



typedef struct
{
	char nom[20];
	char referance[20];
	int jour;
	char mois[20];
	int annee;
	char lieu[20];
	int prix;
	int heure;

}excursion;

void ajouter_excursion(excursion e);
void afficher_excursion(GtkListStore *liste);
int recherche_excursion(excursion excinit);
int modifier_excursion(excursion exc );
int supprimer_excursion(char a[20] );
void afficher_excursion_cherchees(GtkListStore *liste);
void recherche (char lieu[20]);
