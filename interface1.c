/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window_gestion (void)
{
  GtkWidget *window_gestion;
  GtkWidget *fixed1;
  GtkWidget *label1;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *bouton_reply;

  window_gestion = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window_gestion), _("window_gestion"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (window_gestion), fixed1);

  label1 = gtk_label_new (_("Gestion des reclamations (client)"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed1), label1, 96, 24);
  gtk_widget_set_size_request (label1, 248, 48);

  button1 = gtk_button_new_with_mnemonic (_("\303\251crire une reclamation"));
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed1), button1, 128, 88);
  gtk_widget_set_size_request (button1, 168, 72);

  button2 = gtk_button_new_with_mnemonic (_("suivis des reclamations"));
  gtk_widget_show (button2);
  gtk_fixed_put (GTK_FIXED (fixed1), button2, 128, 160);
  gtk_widget_set_size_request (button2, 168, 72);

  button3 = gtk_button_new_with_mnemonic (_("Retour"));
  gtk_widget_show (button3);
  gtk_fixed_put (GTK_FIXED (fixed1), button3, 128, 304);
  gtk_widget_set_size_request (button3, 168, 72);

  bouton_reply = gtk_button_new_with_mnemonic (_("Lire les reponses"));
  gtk_widget_show (bouton_reply);
  gtk_fixed_put (GTK_FIXED (fixed1), bouton_reply, 128, 232);
  gtk_widget_set_size_request (bouton_reply, 168, 72);
  gtk_container_set_border_width (GTK_CONTAINER (bouton_reply), 1);

  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_button1_clicked),
                    NULL);
  g_signal_connect ((gpointer) button2, "clicked",
                    G_CALLBACK (on_button2_clicked),
                    NULL);
  g_signal_connect ((gpointer) bouton_reply, "clicked",
                    G_CALLBACK (on_bouton_reply_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_gestion, window_gestion, "window_gestion");
  GLADE_HOOKUP_OBJECT (window_gestion, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (window_gestion, label1, "label1");
  GLADE_HOOKUP_OBJECT (window_gestion, button1, "button1");
  GLADE_HOOKUP_OBJECT (window_gestion, button2, "button2");
  GLADE_HOOKUP_OBJECT (window_gestion, button3, "button3");
  GLADE_HOOKUP_OBJECT (window_gestion, bouton_reply, "bouton_reply");

  return window_gestion;
}

GtkWidget*
create_window_ecrire (void)
{
  GtkWidget *window_ecrire;
  GtkWidget *fixed2;
  GtkWidget *label_texte;
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkWidget *label_date;
  GtkWidget *label_nom;
  GtkWidget *label5;
  GtkWidget *entry4;
  GtkWidget *button_retour;
  GtkWidget *button_ajouter;

  window_ecrire = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window_ecrire), _("window_ecrire"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (window_ecrire), fixed2);

  label_texte = gtk_label_new (_("texte de reclamation"));
  gtk_widget_show (label_texte);
  gtk_fixed_put (GTK_FIXED (fixed2), label_texte, 16, 48);
  gtk_widget_set_size_request (label_texte, 168, 56);

  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_fixed_put (GTK_FIXED (fixed2), entry1, 224, 64);
  gtk_widget_set_size_request (entry1, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry1), 8226);

  entry2 = gtk_entry_new ();
  gtk_widget_show (entry2);
  gtk_fixed_put (GTK_FIXED (fixed2), entry2, 224, 120);
  gtk_widget_set_size_request (entry2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry2), 8226);

  entry3 = gtk_entry_new ();
  gtk_widget_show (entry3);
  gtk_fixed_put (GTK_FIXED (fixed2), entry3, 216, 184);
  gtk_widget_set_size_request (entry3, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry3), 8226);

  label_date = gtk_label_new (_("date"));
  gtk_widget_show (label_date);
  gtk_fixed_put (GTK_FIXED (fixed2), label_date, 56, 192);
  gtk_widget_set_size_request (label_date, 56, 24);

  label_nom = gtk_label_new (_("nom du service"));
  gtk_widget_show (label_nom);
  gtk_fixed_put (GTK_FIXED (fixed2), label_nom, 32, 120);
  gtk_widget_set_size_request (label_nom, 128, 32);

  label5 = gtk_label_new (_("Numero identifiant"));
  gtk_widget_show (label5);
  gtk_fixed_put (GTK_FIXED (fixed2), label5, 24, 224);
  gtk_widget_set_size_request (label5, 160, 33);

  entry4 = gtk_entry_new ();
  gtk_widget_show (entry4);
  gtk_fixed_put (GTK_FIXED (fixed2), entry4, 216, 224);
  gtk_widget_set_size_request (entry4, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry4), 8226);

  button_retour = gtk_button_new_with_mnemonic (_("Retour"));
  gtk_widget_show (button_retour);
  gtk_fixed_put (GTK_FIXED (fixed2), button_retour, 216, 272);
  gtk_widget_set_size_request (button_retour, 66, 29);

  button_ajouter = gtk_button_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (button_ajouter);
  gtk_fixed_put (GTK_FIXED (fixed2), button_ajouter, 128, 272);
  gtk_widget_set_size_request (button_ajouter, 66, 29);

  g_signal_connect ((gpointer) button_retour, "clicked",
                    G_CALLBACK (on_button_retour_clicked),
                    NULL);
  g_signal_connect ((gpointer) button_ajouter, "clicked",
                    G_CALLBACK (on_button_ajouter_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_ecrire, window_ecrire, "window_ecrire");
  GLADE_HOOKUP_OBJECT (window_ecrire, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (window_ecrire, label_texte, "label_texte");
  GLADE_HOOKUP_OBJECT (window_ecrire, entry1, "entry1");
  GLADE_HOOKUP_OBJECT (window_ecrire, entry2, "entry2");
  GLADE_HOOKUP_OBJECT (window_ecrire, entry3, "entry3");
  GLADE_HOOKUP_OBJECT (window_ecrire, label_date, "label_date");
  GLADE_HOOKUP_OBJECT (window_ecrire, label_nom, "label_nom");
  GLADE_HOOKUP_OBJECT (window_ecrire, label5, "label5");
  GLADE_HOOKUP_OBJECT (window_ecrire, entry4, "entry4");
  GLADE_HOOKUP_OBJECT (window_ecrire, button_retour, "button_retour");
  GLADE_HOOKUP_OBJECT (window_ecrire, button_ajouter, "button_ajouter");

  return window_ecrire;
}

GtkWidget*
create_window_tree (void)
{
  GtkWidget *window_tree;
  GtkWidget *fixed3;
  GtkWidget *treeview1;
  GtkWidget *supprimer;
  GtkWidget *retour_tree;
  GtkWidget *modifier;

  window_tree = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window_tree), _("window_tree"));

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (window_tree), fixed3);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_fixed_put (GTK_FIXED (fixed3), treeview1, 56, 16);
  gtk_widget_set_size_request (treeview1, 300, 200);

  supprimer = gtk_button_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (supprimer);
  gtk_fixed_put (GTK_FIXED (fixed3), supprimer, 136, 256);
  gtk_widget_set_size_request (supprimer, 88, 32);

  retour_tree = gtk_button_new_with_mnemonic (_("Retour"));
  gtk_widget_show (retour_tree);
  gtk_fixed_put (GTK_FIXED (fixed3), retour_tree, 64, 256);
  gtk_widget_set_size_request (retour_tree, 66, 29);

  modifier = gtk_button_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (modifier);
  gtk_fixed_put (GTK_FIXED (fixed3), modifier, 240, 256);
  gtk_widget_set_size_request (modifier, 88, 29);

  g_signal_connect ((gpointer) supprimer, "clicked",
                    G_CALLBACK (on_supprimer_clicked),
                    NULL);
  g_signal_connect ((gpointer) retour_tree, "clicked",
                    G_CALLBACK (on_retour_tree_clicked),
                    NULL);
  g_signal_connect ((gpointer) modifier, "clicked",
                    G_CALLBACK (on_modifier_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_tree, window_tree, "window_tree");
  GLADE_HOOKUP_OBJECT (window_tree, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (window_tree, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (window_tree, supprimer, "supprimer");
  GLADE_HOOKUP_OBJECT (window_tree, retour_tree, "retour_tree");
  GLADE_HOOKUP_OBJECT (window_tree, modifier, "modifier");

  return window_tree;
}

GtkWidget*
create_Supprimer (void)
{
  GtkWidget *Supprimer;
  GtkWidget *fixed5;
  GtkWidget *label6;
  GtkWidget *label7;
  GtkWidget *input_supprimer;
  GtkWidget *valider;
  GtkWidget *Retouuuur;

  Supprimer = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Supprimer), _("Supprimer"));

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (Supprimer), fixed5);

  label6 = gtk_label_new (_("Supprimer une reclamation"));
  gtk_widget_show (label6);
  gtk_fixed_put (GTK_FIXED (fixed5), label6, 112, 24);
  gtk_widget_set_size_request (label6, 224, 64);

  label7 = gtk_label_new (_("Entrer le numero de la reclamation"));
  gtk_widget_show (label7);
  gtk_fixed_put (GTK_FIXED (fixed5), label7, 0, 136);
  gtk_widget_set_size_request (label7, 312, 16);

  input_supprimer = gtk_entry_new ();
  gtk_widget_show (input_supprimer);
  gtk_fixed_put (GTK_FIXED (fixed5), input_supprimer, 312, 136);
  gtk_widget_set_size_request (input_supprimer, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (input_supprimer), 8226);

  valider = gtk_button_new_with_mnemonic (_("Valider"));
  gtk_widget_show (valider);
  gtk_fixed_put (GTK_FIXED (fixed5), valider, 120, 232);
  gtk_widget_set_size_request (valider, 66, 29);

  Retouuuur = gtk_button_new_with_mnemonic (_("Retour"));
  gtk_widget_show (Retouuuur);
  gtk_fixed_put (GTK_FIXED (fixed5), Retouuuur, 232, 232);
  gtk_widget_set_size_request (Retouuuur, 80, 29);

  g_signal_connect ((gpointer) valider, "clicked",
                    G_CALLBACK (on_valider_clicked),
                    NULL);
  g_signal_connect ((gpointer) Retouuuur, "clicked",
                    G_CALLBACK (on_Retouuuur_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Supprimer, Supprimer, "Supprimer");
  GLADE_HOOKUP_OBJECT (Supprimer, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (Supprimer, label6, "label6");
  GLADE_HOOKUP_OBJECT (Supprimer, label7, "label7");
  GLADE_HOOKUP_OBJECT (Supprimer, input_supprimer, "input_supprimer");
  GLADE_HOOKUP_OBJECT (Supprimer, valider, "valider");
  GLADE_HOOKUP_OBJECT (Supprimer, Retouuuur, "Retouuuur");

  return Supprimer;
}

GtkWidget*
create_Modifier (void)
{
  GtkWidget *Modifier;
  GtkWidget *fixed6;
  GtkWidget *label8;
  GtkWidget *label9;
  GtkWidget *label10;
  GtkWidget *label12;
  GtkWidget *inputNum;
  GtkWidget *inputTex;
  GtkWidget *inputNo;
  GtkWidget *inputDat;
  GtkWidget *inputNuum;
  GtkWidget *label11;
  GtkWidget *Entrer;
  GtkWidget *retour_modifier;

  Modifier = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Modifier), _("Modifier"));

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (Modifier), fixed6);

  label8 = gtk_label_new (_("Entrer le numero de la reclamation"));
  gtk_widget_show (label8);
  gtk_fixed_put (GTK_FIXED (fixed6), label8, 0, 56);
  gtk_widget_set_size_request (label8, 240, 32);

  label9 = gtk_label_new (_("Nouveau texte :"));
  gtk_widget_show (label9);
  gtk_fixed_put (GTK_FIXED (fixed6), label9, 40, 104);
  gtk_widget_set_size_request (label9, 136, 16);

  label10 = gtk_label_new (_("Nouveau nom :"));
  gtk_widget_show (label10);
  gtk_fixed_put (GTK_FIXED (fixed6), label10, 48, 128);
  gtk_widget_set_size_request (label10, 120, 16);

  label12 = gtk_label_new (_("Nouveau numero :"));
  gtk_widget_show (label12);
  gtk_fixed_put (GTK_FIXED (fixed6), label12, 48, 176);
  gtk_widget_set_size_request (label12, 128, 32);

  inputNum = gtk_entry_new ();
  gtk_widget_show (inputNum);
  gtk_fixed_put (GTK_FIXED (fixed6), inputNum, 248, 64);
  gtk_widget_set_size_request (inputNum, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (inputNum), 8226);

  inputTex = gtk_entry_new ();
  gtk_widget_show (inputTex);
  gtk_fixed_put (GTK_FIXED (fixed6), inputTex, 200, 96);
  gtk_widget_set_size_request (inputTex, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (inputTex), 8226);

  inputNo = gtk_entry_new ();
  gtk_widget_show (inputNo);
  gtk_fixed_put (GTK_FIXED (fixed6), inputNo, 200, 120);
  gtk_widget_set_size_request (inputNo, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (inputNo), 8226);

  inputDat = gtk_entry_new ();
  gtk_widget_show (inputDat);
  gtk_fixed_put (GTK_FIXED (fixed6), inputDat, 192, 152);
  gtk_widget_set_size_request (inputDat, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (inputDat), 8226);

  inputNuum = gtk_entry_new ();
  gtk_widget_show (inputNuum);
  gtk_fixed_put (GTK_FIXED (fixed6), inputNuum, 192, 176);
  gtk_widget_set_size_request (inputNuum, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (inputNuum), 8226);

  label11 = gtk_label_new (_("Nouvelle date :"));
  gtk_widget_show (label11);
  gtk_fixed_put (GTK_FIXED (fixed6), label11, 48, 152);
  gtk_widget_set_size_request (label11, 120, 24);

  Entrer = gtk_button_new_with_mnemonic (_("Entrer"));
  gtk_widget_show (Entrer);
  gtk_fixed_put (GTK_FIXED (fixed6), Entrer, 144, 240);
  gtk_widget_set_size_request (Entrer, 66, 29);

  retour_modifier = gtk_button_new_with_mnemonic (_("Retour"));
  gtk_widget_show (retour_modifier);
  gtk_fixed_put (GTK_FIXED (fixed6), retour_modifier, 224, 240);
  gtk_widget_set_size_request (retour_modifier, 72, 32);

  g_signal_connect ((gpointer) Entrer, "clicked",
                    G_CALLBACK (on_Entrer_clicked),
                    NULL);
  g_signal_connect ((gpointer) retour_modifier, "clicked",
                    G_CALLBACK (on_retour_modifier_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Modifier, Modifier, "Modifier");
  GLADE_HOOKUP_OBJECT (Modifier, fixed6, "fixed6");
  GLADE_HOOKUP_OBJECT (Modifier, label8, "label8");
  GLADE_HOOKUP_OBJECT (Modifier, label9, "label9");
  GLADE_HOOKUP_OBJECT (Modifier, label10, "label10");
  GLADE_HOOKUP_OBJECT (Modifier, label12, "label12");
  GLADE_HOOKUP_OBJECT (Modifier, inputNum, "inputNum");
  GLADE_HOOKUP_OBJECT (Modifier, inputTex, "inputTex");
  GLADE_HOOKUP_OBJECT (Modifier, inputNo, "inputNo");
  GLADE_HOOKUP_OBJECT (Modifier, inputDat, "inputDat");
  GLADE_HOOKUP_OBJECT (Modifier, inputNuum, "inputNuum");
  GLADE_HOOKUP_OBJECT (Modifier, label11, "label11");
  GLADE_HOOKUP_OBJECT (Modifier, Entrer, "Entrer");
  GLADE_HOOKUP_OBJECT (Modifier, retour_modifier, "retour_modifier");

  return Modifier;
}

GtkWidget*
create_Reponses (void)
{
  GtkWidget *Reponses;
  GtkWidget *fixed7;
  GtkWidget *treeview2;
  GtkWidget *reply_retour;

  Reponses = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Reponses), _("Les reponses"));

  fixed7 = gtk_fixed_new ();
  gtk_widget_show (fixed7);
  gtk_container_add (GTK_CONTAINER (Reponses), fixed7);

  treeview2 = gtk_tree_view_new ();
  gtk_widget_show (treeview2);
  gtk_fixed_put (GTK_FIXED (fixed7), treeview2, 24, 8);
  gtk_widget_set_size_request (treeview2, 300, 200);

  reply_retour = gtk_button_new_with_mnemonic (_("retour"));
  gtk_widget_show (reply_retour);
  gtk_fixed_put (GTK_FIXED (fixed7), reply_retour, 144, 232);
  gtk_widget_set_size_request (reply_retour, 66, 29);

  g_signal_connect ((gpointer) reply_retour, "clicked",
                    G_CALLBACK (on_reply_retour_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Reponses, Reponses, "Reponses");
  GLADE_HOOKUP_OBJECT (Reponses, fixed7, "fixed7");
  GLADE_HOOKUP_OBJECT (Reponses, treeview2, "treeview2");
  GLADE_HOOKUP_OBJECT (Reponses, reply_retour, "reply_retour");

  return Reponses;
}
