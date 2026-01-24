#include "fonction.h"

//Affiche le menu et retourne le choix
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

//Enregistrement d'un étudiant By MKR_fire
void Enregistrer_Etudiants(Etudiant tab[], int *n)
{
    int i, nombre;

    printf("Combien d'etudiants voulez-vous enregistrer ? ");
    scanf("%d", &nombre);

    for (i = 0; i < nombre; i++)
    {
        if (*n >= 100)
        {
            printf("Tableau plein !\n");
            break;
        }

        printf("\n--- Enregistrement de l'etudiant %d ---\n", i + 1);

        /* Saisie des Informations */
        Enregistrement_Etudiant(&tab[*n]);
        (*n)++;
    }

}
// Récuperation des Informations By MKR_fire
void saisirEtudiant(Etudiant *e)
{
    printf("Entrez le nom : ");
    scanf("%s", e->nom);

    printf("Entrez le prenom : ");
    scanf("%s", e->prenom);

    printf("Entrez le matricule : ");
    scanf("%s", e->matricule);

    printf("Entrez la date de naissance\n");
    printf("Jour : ");
    scanf("%d", &e->dateNaissance.jour);

    printf("Mois : ");
    scanf("%d", &e->dateNaissance.mois);

    printf("Annee : ");
    scanf("%d", &e->dateNaissance.annee);

    printf("Entrez le sexe : ");
    scanf("%s", e->sexe);

    printf("Entrez le departement : ");
    scanf("%s", e->departement);

    printf("Entrez la filiere : ");
    scanf("%s", e->filiere);

    printf("Entrez la region d'origine : ");
    scanf("%s", e->regionOrigine);
}


// 9. Afficher la liste
void afficherListe(Etudiant *tab, int n) {
    printf("\n--- LISTE DES ETUDIANTS ---\n");
    for(int i = 0; i < n; i++) {
        printf("[%d] %s %s (Matricule: %s, Filiere: %s)\n", 
               i+1, tab[i].nom, tab[i].prenom, tab[i].matricule, tab[i].filiere);
    }
}

// 2. Modifier (avec pointeurs) by MOHAMADOU LAMO BABILA
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
    scanf("%s", e[pos].departement);
    printf("Nouvelle filiere : ");
    scanf("%s", e[pos].filiere);
    printf("Nouvelle Region d'origine : ");
    scanf("%s", e[pos].regionOrigine); 
}

//Calculer d'âge étudiant By MKR_fire
int calculerAge(Date date, int annee_actuelle)
{
    return annee_actuelle - date.annee;
}

// 3. Recherche Linéaire MOHAMADOU LAMO BABILA
int rechercherMatricule(Etudiant *tab, int n, char *matricule) {
    for (int i = 0; i < n; i++)
        if (strcmp(tab[i].matricule, matricule) == 0)
            return i;
    return -1;
}

// 5. Tri Alphabétique
void trierAlphabetique(Etudiant *tab, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(tab[i].nom, tab[j].nom) > 0) {
                Etudiant tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
}

// 4. Supprimer
void supprimerEtudiant(Etudiant tab[], int *n, char *matricule) {

    int pos = rechercherMatricule(tab, *n, matricule);

    if (pos == -1) {
        printf("Etudiant introuvable.\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++)
        tab[i] = tab[i + 1];

    (*n)--;
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
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(tab[i].filiere, tab[j].filiere) > 0) {
                Etudiant tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
}

// Sauvegarde le tableau d'étudiants dans le fichier
void sauvegarderEtudiants(Etudiant *tab, int n) {
    FILE *fichier = fopen("etudiants.txt", "w");
    if (fichier != NULL) {
        fprintf(fichier, "%d\n", n);
        for (int i = 0; i < n; i++) {
            // Utilisation du ; comme séparateur
            fprintf(fichier, "%s;%s;%s;%d;%d;%d;%s;%s;%s;%s\n",
                    tab[i].matricule, tab[i].nom, tab[i].prenom,
                    tab[i].dateNaissance.jour, tab[i].dateNaissance.mois, tab[i].dateNaissance.annee,
                    tab[i].sexe, tab[i].departement, tab[i].filiere, tab[i].regionOrigine);
        }
        fclose(fichier);
        printf("Donnees sauvegardees.\n");
    } else {
        printf("Erreur lors de la sauvegarde.\n");
    }
}

// Charge les étudiants depuis le fichier dans le tableau
// Retourne le nombre d'étudiants chargés
int chargerEtudiants(Etudiant *tab) {
    FILE *fichier = fopen("etudiants.txt", "r");
    int n = 0;
    if (fichier != NULL) {
        if (fscanf(fichier, "%d\n", &n) != 1) { fclose(fichier); return 0; } // Le \n après %d est important

        for (int i = 0; i < n; i++) {
            // Lecture formatée complexe : %[^;] signifie "lire tout jusqu'au point virgule"
            fscanf(fichier, "%[^;];%[^;];%[^;];%d;%d;%d;%[^;];%[^;];%[^;];%[^\n]\n",
                    tab[i].matricule,
                    tab[i].nom,
                    tab[i].prenom,
                    &tab[i].dateNaissance.jour,
                    &tab[i].dateNaissance.mois,
                    &tab[i].dateNaissance.annee,
                    tab[i].sexe,
                    tab[i].departement,
                    tab[i].filiere,
                    tab[i].regionOrigine);
        }
        fclose(fichier);
        printf("%d etudiants charges.\n", n);
        return n;
    }
    return 0;
}
