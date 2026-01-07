#include "fonction.h"

// Affiche le menu et retourne le choix
int menu() {
    int choix;
    printf("\n--- MENU GESTION DES ETUDIANTS ---\n");
    printf("1. Enregistrer un etudiant\n");
    printf("2. Modifier un etudiant\n");
    printf("3. Rechercher (Lineaire - Matricule)\n");
    printf("4. Supprimer un etudiant\n");
    printf("5. Trier par ordre Alphabetique (Nom)\n");
    printf("6. Rechercher par Dichotomie (Matricule)\n");
    printf("7. Calculer l'Age d'un etudiant\n");
    printf("8. Trier par Filiere\n");
    printf("9. Afficher la liste des etudiants\n");
    printf("0. Quitter\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    return choix;
}

// 1. Enregistrer
void saisirEtudiant(Etudiant *e) {
    printf("\nMatricule: "); scanf("%s", e->matricule);
    printf("Nom: "); scanf("%s", e->nom);
    printf("Prenom: "); scanf("%s", e->prenom);
    printf("Date Naissance (JJ MM AAAA): "); 
    scanf("%d %d %d", &e->dateNaissance.jour, &e->dateNaissance.mois, &e->dateNaissance.annee);
    printf("Sexe (M/F): "); scanf("%s", e->sexe);
    printf("Departement: "); scanf("%s", e->departement);
    printf("Filiere: "); scanf("%s", e->filiere);
    printf("Region d'origine: "); scanf("%s", e->regionOrigine);
}

// 9. Afficher la liste
void afficherListe(Etudiant *tab, int n) {
    printf("\n--- LISTE DES ETUDIANTS ---\n");
    for(int i = 0; i < n; i++) {
        printf("[%d] %s %s (Matricule: %s, Filiere: %s)\n", 
               i+1, tab[i].nom, tab[i].prenom, tab[i].matricule, tab[i].filiere);
    }
}

// 2. Modifier (avec pointeurs)
void modifierEtudiant(Etudiant *e, int n) {
    char mat[20];
    printf("Entrer le matricule a modifier : ");
    scanf("%s", mat);

    int pos = rechercherMatricule(e, n, mat);
    if (pos == -1)
    {
        printf("Etudiant non trouve.\n");
        return;
    }

    printf("Nouveau nom : ");
    scanf("%s", e[pos].nom);
    printf("Nouveau prenom : ");
    scanf("%s", e[pos].prenom);
    printf("Nouvelle date de naissance ");
    printf("jour :");
    scanf("%s", e[pos].dateNaissance.jour); 
    printf("mois :");
    scanf("%s", e[pos].dateNaissance.mois);  
    printf("annee :");
    scanf("%s", e[pos].dateNaissance.annee);
    printf("Nouveau departement : ");
    scanf("%s", e[pos].detartement);
    printf("Nouvelle filiere : ");
    scanf("%s", e[pos].filiere);
    printf("Nouvelle Region d'origine : ");
    scanf("%s", e[pos].regionOrigine); 
}

// 7. Calculer Age
int calculerAge(Date dateNaiss) {
}

// 3. Recherche Linéaire
int rechercherMatricule(Etudiant *tab, int n, char *matricule) {
    for (int i = 0; i < n; i++)
        if (strcmp(tab[i].matricule, matricule) == 0)
            return i;
    return -1;
}

// 5. Tri Alphabétique
void trierAlphabetique(Etudiant *tab, int n) {
}

// 4. Supprimer
void supprimerEtudiant(Etudiant *tab, int *n, char *matricule) {
}

// 6. Recherche Dichotomique (Nécessite un tableau trié par Matricule au préalable)
int rechercheDichotomique(Etudiant *tab, int n, char *matricule) {
}

// 8. Trier par Filière
void trierFiliere(Etudiant *tab, int n) {
}

// Sauvegarde le tableau d'étudiants dans le fichier
void sauvegarderEtudiants(Etudiant *tab, int n) {
}

// Charge les étudiants depuis le fichier dans le tableau
// Retourne le nombre d'étudiants chargés
int chargerEtudiants(Etudiant *tab) {
}