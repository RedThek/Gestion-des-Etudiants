#include "fonction.h"
#define MAX_ETUDIANTS 70

//Enregistrement d'un étudiant By MKR_fire
void Enregistrer_Etudiants(Etudiant tab[], int *n)
{
    FILE *fichier;
    int i, nombre;

    /* Ouverture du fichier en mode ajout */
    fichier = fopen("Donnee_des_Etudiants.txt", "a");

    if (fichier == NULL)
    {
        printf("Erreur d'ouverture du fichier !\n");
        return;
    }

    printf("Combien d'etudiants voulez-vous enregistrer ? ");
    scanf("%d", &nombre);

    for (i = 0; i < nombre; i++)
    {
        if (*n >= MAX_ETUDIANTS)
        {
            printf("Tableau plein !\n");
            break;
        }

        printf("\n--- Enregistrement de l'etudiant %d ---\n", i + 1);

        /* Saisie des Informations */
        Enregistrement_Etudiant(&tab[*n]);

        /* Ecriture dans le fichier */
        Ecriture_Etudiant(&tab[*n], fichier);

        (*n)++;
    }

    fclose(fichier);

    printf("\nEnregistrement termine avec succes.\n");
}
// Récuperation des Informations By MKR_fire
void Enregistrement_Etudiant(Etudiant *Personne)
{
    printf("Entrez le nom : ");
    scanf("%s", Personne->nom);

    printf("Entrez le prenom : ");
    scanf("%s", Personne->prenom);

    printf("Entrez le matricule : ");
    scanf("%s", Personne->matricule);

    printf("Entrez la date de naissance\n");
    printf("Jour : ");
    scanf("%d", &Personne->dateNaissance.jour);

    printf("Mois : ");
    scanf("%d", &Personne->dateNaissance.mois);

    printf("Annee : ");
    scanf("%d", &Personne->dateNaissance.annee);

    printf("Entrez le sexe : ");
    scanf("%s", Personne->sexe);

    printf("Entrez le departement : ");
    scanf("%s", Personne->departement);

    printf("Entrez la filiere : ");
    scanf("%s", Personne->filiere);

    printf("Entrez la region d'origine : ");
    scanf("%s", Personne->regionOrigine);
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
void modifierEtudiant(Etudiant *e) {

}

//Calculer d'âge étudiant By MKR_fire
int calculerAge(Etudiant etu, int annee_actuelle)
{
    return annee_actuelle - etu.dateNaissance.annee;
}

// 3. Recherche Linéaire
int rechercherMatricule(Etudiant *tab, int n, char *matricule) {
}

// 5. Tri Alphabétique
void trierAlphabetique(Etudiant *tab, int n) {
}

// 4. Supprimer
void supprimerEtudiant(Etudiant *tab, int *n, char *matricule) {
}

// 6. Recherche Dichotomique By MKR_fire
int rechercheDichotomique(Etudiant *tab, int n, char *matr)
{
    int debut = 0, fin = n - 1, milieu;

    while (debut <= fin)
    {
        milieu = (debut + fin) / 2;

        if (strcmp(tab[milieu].matricule, matr) == 0)
            return milieu;
        else if (strcmp(tab[milieu].matricule, matr) < 0)
            debut = milieu + 1;
        else
            fin = milieu - 1;
    }
    return -1;
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