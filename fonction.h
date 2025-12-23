#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char matricule[20];
    char nom[50];
    char prenom[50];
    Date dateNaissance;
    char sexe[10];
    char departement[50];
    char filiere[50];
    char regionOrigine[50];
} Etudiant;

int menu();
void saisirEtudiant(Etudiant *e);
void afficherEtudiant(Etudiant e);
void afficherListe(Etudiant *tab, int n);
void modifierEtudiant(Etudiant *e);
int rechercherMatricule(Etudiant *tab, int n, char *matricule);
void supprimerEtudiant(Etudiant *tab, int *n, char *matricule);
void trierAlphabetique(Etudiant *tab, int n);
void trierFiliere(Etudiant *tab, int n);
int rechercheDichotomique(Etudiant *tab, int n, char *matricule);
int calculerAge(Date dateNaiss);
void sauvegarderEtudiants(Etudiant *tab, int n);
int chargerEtudiants(Etudiant *tab);

#endif