#include "fonction.h"

// Vide le buffer (mémoire tampon) clavier pour éviter les sauts de saisie
void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Remplace scanf pour les chaînes : lit les espaces et retire le '\n' final
void lireChaine(char *chaine, int taille) {
    fgets(chaine, taille, stdin);
    // On cherche le caractère saut de ligne '\n' pour le remplacer par '\0' (fin de chaîne)
    char *p = strchr(chaine, '\n');
    if (p) {
        *p = '\0';
    } else {
        viderBuffer(); // Si la chaîne était trop longue, on vide le reste
    }
}

// Lit une ligne de texte et tente de la convertir en entier
// Redemande tant que la saisie n'est pas un nombre valide
int lireEntier() {
    char buffer[100];
    int nombre;
    int correct = 0;

    while (!correct) {
        // On lit toute la ligne (sécurisé contre overflow)
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // On essaie d'extraire un entier du texte lu
            // sscanf renvoie 1 si elle a réussi à trouver un entier
            if (sscanf(buffer, "%d", &nombre) == 1) {
                correct = 1;
            } else {
                printf("Erreur : Ce n'est pas un nombre. Reessayez : ");
            }
        }
    }
    return nombre;
}

void lireSexe(char *sexe) {
    int valide = 0;
    char buffer[10]; // Petit buffer temporaire

    while (!valide) {
        lireChaine(buffer, 10); // Votre fonction lireChaine existante
        
        // On force en majuscule pour accepter 'm' ou 'M'
        if (strcmp(buffer, "M") == 0 || strcmp(buffer, "m") == 0) {
            strcpy(sexe, "M");
            valide = 1;
        } 
        else if (strcmp(buffer, "F") == 0 || strcmp(buffer, "f") == 0) {
            strcpy(sexe, "F");
            valide = 1;
        } 
        else {
            printf("Erreur : Entrez 'M' ou 'F' uniquement : ");
        }
    }
}

int estDateValide(int j, int m, int a) {
    if (a < 1900 || a > 2100) return 0; // Année réaliste
    if (m < 1 || m > 12) return 0;      // Mois 1-12
    
    int joursDansMois[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Gestion bissextile simple pour février
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
        joursDansMois[2] = 29;
    }

    if (j < 1 || j > joursDansMois[m]) return 0;

    return 1;
}

// Author : @RedThek
//Affiche le menu et retourne le choix
int menu() {
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
    return lireEntier();
}

// Récuperation des Informations By MKR_fire
void saisirEtudiant(Etudiant *e, Etudiant *tab, int n) {
    printf("\n--- Saisie Nouvel Etudiant ---\n");

    // --- GESTION DES DOUBLONS (Partie Modifiée) ---
    int existeDeja = 0;
    char bufferMatricule[20];

    do {
        printf("Matricule : ");
        lireChaine(bufferMatricule, 20);

        // On vérifie si ce matricule est déjà dans le tableau (de 0 à n)
        // La fonction rechercherMatricule renvoie -1 si pas trouvé, sinon l'index
        if (n > 0 && rechercherMatricule(tab, n, bufferMatricule) != -1) {
            printf(RED "ERREUR : Le matricule '%s' existe deja ! Veuillez en choisir un autre.\n" RESET, bufferMatricule);
            existeDeja = 1;
        } else {
            // C'est bon, on copie le matricule validé dans la structure
            strcpy(e->matricule, bufferMatricule);
            existeDeja = 0;
        }
    } while (existeDeja);

    printf("Nom: "); lireChaine(e->nom, 50);
    printf("Prenom: "); lireChaine(e->prenom, 50);

    // 2. Dates (Boucle de validation)
    int dateOk = 0;
    while (!dateOk) {
        printf("Date Naissance (JJ MM AAAA): ");
        
        printf("Annee de naissance (ex: 2000): ");
        e->dateNaissance.annee = lireEntier();

        printf("Mois de naissance (1-12): ");
        e->dateNaissance.mois = lireEntier();

        printf("Jour de naissance (1-31): ");
        e->dateNaissance.jour = lireEntier();

        if (estDateValide(e->dateNaissance.jour, e->dateNaissance.mois, e->dateNaissance.annee)) dateOk = 1;
        else printf(RED "Date invalide.\n" RESET);
    }

    // 3. Sexe (Validation M/F)
    printf("Sexe (M/F): "); 
    lireSexe(e->sexe);

    // 4. Autres chaines
    printf("Departement: "); lireChaine(e->departement, 50);
    printf("Filiere: "); lireChaine(e->filiere, 50);
    printf("Region d'origine: "); lireChaine(e->regionOrigine, 50);

    printf(GREEN "Etudiant ajoute avec succes.\n" RESET);
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

void afficherEtudiant(Etudiant e) {
    printf("\n--- DETAILS DE L'ETUDIANT ---\n");
    printf("Matricule: %s\n", e.matricule);
    printf("Nom: %s\n", e.nom);
    printf("Prenom: %s\n", e.prenom);
    printf("Date de Naissance: %02d/%02d/%04d\n", e.dateNaissance.jour, e.dateNaissance.mois, e.dateNaissance.annee);
    printf("Sexe: %s\n", e.sexe);
    printf("Departement: %s\n", e.departement);
    printf("Filiere: %s\n", e.filiere);
    printf("Region d'Origine: %s\n", e.regionOrigine);
}

// 9. Afficher la liste
void afficherListe(Etudiant *tab, int n) {
    if (n == 0) {
        printf(RED "Aucun etudiant dans la liste.\n" RESET);
        return;
    }

    printf("\n" BOLD "%-10s | %-15s | %-15s | %-10s | %-5s | %-15s\n" RESET, 
           "Matricule", "Nom", "Prenom", "Naissance", "Sexe", "Filiere");
    printf("--------------------------------------------------------------------------------\n");

    for(int i = 0; i < n; i++) {
        printf("%-10s | %-15s | %-15s | %02d/%02d/%04d | %-5s | %-15s\n", 
               tab[i].matricule, 
               tab[i].nom, 
               tab[i].prenom, 
               tab[i].dateNaissance.jour, tab[i].dateNaissance.mois, tab[i].dateNaissance.annee,
               tab[i].sexe,
               tab[i].filiere);
    }
    printf("--------------------------------------------------------------------------------\n");
    printf(GREEN "Total: %d etudiants\n" RESET, n);
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

// 3. Recherche Linéaire MOHAMADOU LAMO BABILA
int rechercherMatricule(Etudiant *tab, int n, char *matricule) {
    for (int i = 0; i < n; i++)
        if (strcmp(tab[i].matricule, matricule) == 0)
            return i;
    return -1;
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

void trierAlphabetique(Etudiant *tab, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(tab[i].nom, tab[j].nom) > 0) {
                Etudiant tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
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

//Calculer d'âge étudiant By MKR_fire
int calculerAge(Date date, int annee_actuelle)
{
    return annee_actuelle - date.annee;
}

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
    }
}

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

void nettoyerEcran() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    printf(YELLOW "\nAppuyez sur Entree pour continuer..." RESET);
    getchar(); // Attend une frappe
}

void afficherBanniere() {
    nettoyerEcran();
    printf(CYAN BOLD);
    printf("======================================================\n");
    printf("   G E S T I O N   D E S   E T U D I A N T S   v1.0   \n");
    printf("======================================================\n");
    printf(RESET);
}
