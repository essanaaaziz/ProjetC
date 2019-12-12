#include <gtk/gtk.h>
 typedef struct
{
int Jour;
int Mois;
int Annee;
}Date;

void AjoutVol(char Depart[],char Destination[],int JourAll,int MoisAll,int AnneeAll,int JourRet,int MoisRet,int AnneeRet,int Prix,char Class[]);
int verifier(char Depart[],char Destination[]);
void AfficherVol(GtkWidget *liste);
int verifier_selection(char choix[]);
void modifier(char choix[],char DepartM[],char DestinationM[],char JourAllM[],char  MoisAllM[],char  AnneeAllM[] ,char JourRetM[],char  MoisRetM[],char  AnneeRetM[], char PrixM[],char ClassM[]);
void Volselectionner(char choix[]);
void SupprimerVols(char choix[]);
void RechercherVol(GtkWidget *liste,char filtre[]);
int verifier_saisie(char Idclient[]);
void ReserverVols(char Idclient[]);
