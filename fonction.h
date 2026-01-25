// Codes couleurs ANSI pour la console
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define CYAN    "\x1b[36m"
#define BOLD    "\x1b[1m"
#define RESET   "\x1b[0m" // Pour remettre la couleur par défaut

#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct Date{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct Etudiant{
    char matricule[20];
    char nom[50];
    char prenom[50];
    Date dateNaissance;
    char sexe[10];
    char departement[50];
    char filiere[50];
    char regionOrigine[50];
} Etudiant;

void viderBuffer();
void lireChaine(char *chaine, int taille);
int lireEntier();
void lireSexe(char *sexe);
int estDateValide(int j, int m, int a);
void pause();
void nettoyerEcran();
int menu();
int menuModification();
void saisirEtudiant(Etudiant *e, Etudiant *tab, int n);
void Enregistrer_Etudiants(Etudiant tab[], int *n);
void afficherEtudiant(Etudiant e);
void afficherListe(Etudiant *tab, int n);
void modifierEtudiant(Etudiant *e, int n);
int rechercherMatricule(Etudiant *tab, int n, char *matricule);
void supprimerEtudiant(Etudiant *tab, int *n, char *matricule);
void trierAlphabetique(Etudiant *tab, int n);
void trierFiliere(Etudiant *tab, int n);
int rechercheDichotomique(Etudiant *tab, int n, char *matricule);
int calculerAge(Date date, int annee_actuelle);
void sauvegarderEtudiants(Etudiant *tab, int n);
int chargerEtudiants(Etudiant *tab);

#endif