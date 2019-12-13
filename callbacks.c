#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include"fonctions.h"

char cinmod[30];
char cinad[30];

void
on_catalogue_clicked                   (GtkWidget      *og,
                                        gpointer         user_data)
{
GtkWidget *pageca,*pageac;
pageac=lookup_widget(og,"pageac");
pageca = create_pageca ();
 gtk_widget_show (pageca);
gtk_widget_destroy(pageac);
	
}





void
on_inscription_clicked                 (GtkWidget      *og,
                                        gpointer         user_data)
{
GtkWidget *pagei,*pageac;
pageac=lookup_widget(og,"pageac");
pagei = create_pagei ();
 gtk_widget_show (pagei);
gtk_widget_destroy(pageac);
}


void
on_seconnecter_clicked                 (GtkWidget      *og,
                                        gpointer         user_data)
{
GtkWidget *pageco,*pageac;
pageac=lookup_widget(og,"pageac");
pageco = create_pageco ();
 gtk_widget_show (pageco);
gtk_widget_destroy(pageac);
}


void
on_hotel_clicked                       (GtkWidget      *og,
                                        gpointer         user_data)
{

}


void
on_retour_clicked                      (GtkWidget      *og,
                                        gpointer         user_data)
{
GtkWidget *pageca,*pageac;
pageca=lookup_widget(og,"pageca");
pageac = create_pageac ();
 gtk_widget_show (pageac);
gtk_widget_destroy(pageca);
	
}


void
on_voiture_clicked                     (GtkWidget      *og,
                                        gpointer         user_data)
{

}


void
on_heb_clicked                         (GtkWidget      *og,
                                        gpointer         user_data)
{

}


void
on_vol_clicked                         (GtkWidget      *og,
                                        gpointer         user_data)
{

}


void
on_quitter1_clicked                    (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *pagec,*pageac;
pageac=lookup_widget(og,"pageac");
gtk_widget_destroy(pageac);
}




void
on_enregistrer_clicked                 (GtkWidget       *og,
                                        gpointer         user_data)
{personne p;
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *window1,*inscription;

window1=lookup_widget(og,"window1");
inscription=lookup_widget(og,"inscription");

input1=lookup_widget(og,"nom");
input2=lookup_widget(og,"prenom");
input3=lookup_widget(og,"md");
input4=lookup_widget(og,"cin");
input5=lookup_widget(og,"nt");

strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.nt,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.mp,gtk_entry_get_text(GTK_ENTRY(input3)));

ajouter_personne(p);
GtkWidget *pagei,*f,*output;
pagei=lookup_widget(og,"pagei");
f = create_f ();
gtk_widget_destroy(pagei);
gtk_widget_show (f);


}

void
on_retour1_clicked                     (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *pagei,*pageac;
pagei=lookup_widget(og,"pagei");
pageac = create_pageac ();
 gtk_widget_show (pageac);
gtk_widget_destroy(pagei);
	
}


void
on_retour2_clicked                     (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *f,*pageac;
f=lookup_widget(og,"f");
pageac = create_pageac();
 gtk_widget_show (pageac);
gtk_widget_destroy(f);
}


void
on_seconnecter1_clicked                (GtkWidget       *og,
                                        gpointer         user_data)
{
{GtkWidget *inputl,*inputp,*window1,*windowy,*label=NULL,*pageco;
char log[30];
char pwd[30];
int y;
char yes[30];
pageco=lookup_widget(og,"pageco");
inputl=lookup_widget(og,"entryl");
inputp=lookup_widget(og,"entryp");
strcpy(log,gtk_entry_get_text(GTK_ENTRY(inputl)));
strcpy(pwd,gtk_entry_get_text(GTK_ENTRY(inputp)));
if (verifier(log,pwd)==1){

GtkWidget *pageco,*pagea;
pageco=lookup_widget(og,"pageco");
pagea = create_pagea ();
 gtk_widget_show (pagea);
gtk_widget_destroy(pageco);}
else if (verifier(log,pwd)==2){

GtkWidget *pageag,*pageco;
pageco=lookup_widget(og,"pageco");
pageag = create_pageag ();
 gtk_widget_show (pageag);
gtk_widget_destroy(pageco);

}
else if (verifier(log,pwd)==3){

GtkWidget *pageut,*pageco;
pageco=lookup_widget(og,"pageco");
pageut = create_pageut ();
 gtk_widget_show (pageut);
gtk_widget_destroy(pageco);

}
else {GtkWidget *windowy,*pageco;
pageco=lookup_widget(og,"pageco");
windowy=lookup_widget(og,"windowy");
gtk_widget_destroy(pageco);
windowy = create_windowy();
gtk_widget_show (windowy);
}
}
}




void
on_retour3_clicked                     (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *windowy,*pageac;
windowy=lookup_widget(og,"windowy");
pageac = create_pageac();
 gtk_widget_show (pageac);
gtk_widget_destroy(windowy);
}


void
on_ajouterag_clicked                   (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *pagea,*ajag;
pagea=lookup_widget(og,"pagea");
ajag = create_ajag();
 gtk_widget_show (ajag);
gtk_widget_destroy(pagea);
}


void
on_modifierag_clicked                  (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *pagea,*smag;
pagea=lookup_widget(og,"pagea");
smag = create_smag();
 gtk_widget_show (smag);
gtk_widget_destroy(pagea);
}


void
on_quitteradmin_clicked                (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *pagea,*pageac;
pagea=lookup_widget(og,"pagea");
pageac = create_pageac();
 gtk_widget_show (pageac);
gtk_widget_destroy(pagea);
}


void
on_supprimerag_clicked                 (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *pagea,*smag;
pagea=lookup_widget(og,"pagea");
smag = create_smag();
 gtk_widget_show (smag);
gtk_widget_destroy(pagea);
}


void
on_enregister2_clicked                 (GtkWidget       *og,
                                        gpointer         user_data)
{personne p;
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *window1,*inscription;

window1=lookup_widget(og,"window1");
inscription=lookup_widget(og,"inscription");

input1=lookup_widget(og,"nomage");
input2=lookup_widget(og,"prenomag");
input3=lookup_widget(og,"mdag");
input4=lookup_widget(og,"cinag");


strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.nt,"0");
strcpy(p.mp,gtk_entry_get_text(GTK_ENTRY(input3)));


ajoutera_personne(p);

}


void
on_retour5_clicked                     (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *pagea,*ajag;
ajag=lookup_widget(og,"ajag");
pagea = create_pagea ();
 gtk_widget_show (pagea );
gtk_widget_destroy(ajag);
}






void
on_modifierag1_clicked                 (GtkWidget       *og,
                                        gpointer         user_data)
{
GtkWidget *modag,*smag,*input1;
smag=lookup_widget(og,"smag");
modag = create_modag();
 gtk_widget_show (modag);
input1=lookup_widget(og,"ms");
strcpy(cinad,gtk_entry_get_text(GTK_ENTRY(input1)));

gtk_widget_destroy(smag);
}


void
on_supprimerag1_clicked                (GtkWidget       *og,
                                        gpointer         user_data)
{
char c[30];
GtkWidget *pagea,*smag,*input1;
smag=lookup_widget(og,"smag");

 

input1=lookup_widget(og,"ms");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input1)));

sup_dispo(c);
pagea = create_pagea();
gtk_widget_show (pagea);
gtk_widget_destroy(smag);

}


void
on_afficherut_clicked                  (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *afficheragent,*pageag;
pageag=lookup_widget(og,"pageag");
afficheragent= create_afficheragent();
 gtk_widget_show (afficheragent);
gtk_widget_destroy(pageag);

GtkWidget *treeview1;

treeview1=lookup_widget(afficheragent,"treeview1");

afficher_personne(treeview1);
}


void
on_ajouterut_clicked                   (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *pagei,*pageag;
pageag=lookup_widget(og,"pageag");
pagei = create_pagei();
 gtk_widget_show (pagei);
gtk_widget_destroy(pageag);



}


void
on_retour6_clicked                     (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *pageag,*pageac;
pageag=lookup_widget(og,"pageag");
pageac = create_pageac();
 gtk_widget_show (pageac);
gtk_widget_destroy(pageag);
}


void
on_supprimerut_clicked                 (GtkWidget     *og,
                                        gpointer         user_data)
{
char c[30];
GtkWidget *pageag,*pageac,*input1;
pageag=lookup_widget(og,"pageag");

 

input1=lookup_widget(og,"entry17");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input1)));

sup_dispou(c);
pageac = create_pageac();
gtk_widget_show (pageac);
gtk_widget_destroy(pageag);
}


void
on_modifierut_clicked                  (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *pageut,*modut,*input1;
pageut=lookup_widget(og,"pageut");
modut = create_modut();
 gtk_widget_show (modut);

input1=lookup_widget(og,"entry16");
strcpy(cinmod,gtk_entry_get_text(GTK_ENTRY(input1)));

gtk_widget_destroy(pageut);
}


void
on_reserverag_clicked                  (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *pageag,*r;
pageag=lookup_widget(og,"pageag");
r= create_r();
 gtk_widget_show (r);
gtk_widget_destroy(pageag);
}


void
on_desabonner_enter                    (GtkWidget     *og,
                                        gpointer         user_data)
{
char c[30];
GtkWidget *pageut,*pageac,*input1;
pageut=lookup_widget(og,"pageut");

 

input1=lookup_widget(og,"entry16");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input1)));

sup_dispou(c);
pageac = create_pageac();
gtk_widget_show (pageac);
gtk_widget_destroy(pageut);
}


void
on_reserverut_clicked                  (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *pageut,*r;
pageut=lookup_widget(og,"pageut");
r= create_r();
 gtk_widget_show (r);
gtk_widget_destroy(pageut);
}





void
on_retour8_clicked                     (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *pageut,*pageac;
pageut=lookup_widget(og,"pageut");
pageac = create_pageac();
 gtk_widget_show (pageac);
gtk_widget_destroy(pageut);
}


void
on_modifierutilisateur_clicked         (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *modut,*smut;
smut=lookup_widget(og,"smut");
modut = create_modut();
 gtk_widget_show (modut);
gtk_widget_destroy(smut);
}


void
on_supprimerutilisateur_clicked        (GtkWidget     *og,
                                        gpointer         user_data)
{

}


void
on_re_clicked                          (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *modut,*smut;
smut=lookup_widget(og,"smut");
modut = create_modut();
 gtk_widget_show (modut);
gtk_widget_destroy(smut);
}


void
on_v_clicked                           (GtkWidget     *og,
                                        gpointer         user_data)
{

}


void
on_he_clicked                          (GtkWidget     *og,
                                        gpointer         user_data)
{

}


void
on_h_clicked                           (GtkWidget     *og,
                                        gpointer         user_data)
{

}


void
on_retourr_clicked                     (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *pageac,*r;
r=lookup_widget(og,"r");
pageac= create_pageac();
 gtk_widget_show (pageac);
gtk_widget_destroy(r);
}


void
on_reu_clicked                         (GtkWidget     *og,
                                        gpointer         user_data)
{
GtkWidget *modut,*smut;
smut=lookup_widget(og,"smut");
modut = create_modut();
 gtk_widget_show (modut);
gtk_widget_destroy(smut);
}





void
on_modifierut1_clicked                 (GtkWidget     *og,
                                        gpointer         user_data)
{char cin[30];
char nom[30];
char prenom[30];
char nt[30];
char md[30];
GtkWidget *input1,*input2,*input3,*input4,*input5;
input1=lookup_widget(og,"unom");
input2=lookup_widget(og,"uprenom");
input3=lookup_widget(og,"umd");
input4=lookup_widget(og,"ucin");
input5=lookup_widget(og,"unt");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nt,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(md,gtk_entry_get_text(GTK_ENTRY(input3)));

modifier(cinmod,cin,nom,prenom,nt,md);
}


void
on_modifieradmin_clicked               (GtkWidget         *og,
                                        gpointer         user_data)
{
char cin[30];
char nom[30];
char prenom[30];
char nt[30];
char md[30];
GtkWidget *input1,*input2,*input3,*input4,*input5;
input1=lookup_widget(og,"mnom");
input2=lookup_widget(og,"entry18");
input3=lookup_widget(og,"mmd");
input4=lookup_widget(og,"mcin");
input5=lookup_widget(og,"entry19");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nt,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(md,gtk_entry_get_text(GTK_ENTRY(input3)));

modifiera(cinad,cin,nom,prenom,nt,md);
}

