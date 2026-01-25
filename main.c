#include "fonction.h"
#define MAX_ETUDIANTS 500

int main() {
    Etudiant liste[MAX_ETUDIANTS];
    int choix, index, nombreEtudiants = 0;
    char matRech[20];

    nombreEtudiants = chargerEtudiants(liste);

    while (nombreEtudiants <= 0) {
        printf(RED "Aucune donnee trouvee. Entrez le nombre initial d'etudiants a saisir: " RESET);
        int aSaisir = lireEntier();
        for(int i = 0; i < aSaisir; i++) {
            printf("\n--- Etudiant %d ---\n", i+1);
            saisirEtudiant(&liste[nombreEtudiants], liste, nombreEtudiants); // Utilise l'index courant
            nombreEtudiants++;
            sauvegarderEtudiants(liste, nombreEtudiants);
        }
    }

    do {
        choix = menu();

        switch(choix) {

            case 1:
                printf(CYAN "\n--- Enregistrement d'un Nouvel Etudiant ---\n" RESET);
                if(nombreEtudiants < MAX_ETUDIANTS) {
                    saisirEtudiant(&liste[nombreEtudiants], liste, nombreEtudiants);
                    nombreEtudiants++;
                    sauvegarderEtudiants(liste, nombreEtudiants);
                } else { printf(RED "Liste pleine impossible d'ajouter.\n" RESET); }
                break;
            
            case 2:
                printf(CYAN "\n--- Modification des informations d'un Etudiant ---\n" RESET);
                printf("Matricule a modifier: "); lireChaine(matRech, 20);
                index = rechercherMatricule(liste, nombreEtudiants, matRech);
                if(index != -1) {
                    modifierEtudiant(&liste[index], index);
                    sauvegarderEtudiants(liste, nombreEtudiants);
                } else {
                    printf(RED "Etudiant Introuvable.\n" RESET);
                    pause();
                }
                break;

            case 3:
                printf(CYAN "\n--- Recherche d'un Etudiant (Lineaire) ---\n" RESET);
                printf("Matricule a chercher: "); lireChaine(matRech, 20);
                index = rechercherMatricule(liste, nombreEtudiants, matRech);
                if(index != -1) afficherEtudiant(liste[index]);
                else printf(RED "Etudiant Introuvable.\n");
                break;

            case 4:
                printf(CYAN "\n--- Suppression d'un Etudiant ---\n" RESET);
                printf("Matricule a supprimer: "); lireChaine(matRech, 20);
                supprimerEtudiant(liste, &nombreEtudiants, matRech);
                sauvegarderEtudiants(liste, nombreEtudiants);
                break;
            case 5:
                printf(CYAN "\n--- Trier les etudiants par ordre alphabetique ---\n" RESET);
                trierAlphabetique(liste, nombreEtudiants);
                afficherListe(liste, nombreEtudiants);
                break;
            case 6:
                printf(CYAN "\n--- Recherche d'un Etudiant (Dichotomique) ---\n" RESET);
                printf("Matricule a chercher : "); lireChaine(matRech, 20);
                index = rechercheDichotomique(liste, nombreEtudiants, matRech);
                if(index != -1) printf("Trouve a la position %d\n", index);
                else printf("Non trouve (Avez-vous trie par matricule ?)\n");
                break;
            case 7:
                printf(CYAN "\n--- Calcul de l'age d'un Etudiant ---\n" RESET);
                printf("Matricule pour calcul age: "); lireChaine(matRech, 20);
                index = rechercherMatricule(liste, nombreEtudiants, matRech);
                if(index != -1) {
                    printf("Age: %d ans\n", calculerAge(liste[index].dateNaissance, 2026));
                    pause();
                } else {
                    printf(RED "Etudiant Introuvable.\n" RESET);
                    pause();
                }
                break;
            case 8:
                printf(CYAN "\n--- Trier les etudiants par filiere ---\n" RESET);
                trierFiliere(liste, nombreEtudiants);
                afficherListe(liste, nombreEtudiants);
                break;
            case 9:
                printf(CYAN "\n--- Liste des Etudiants ---\n" RESET);
                afficherListe(liste, nombreEtudiants);
                break;
            case 10:
                printf(CYAN "\n--- Options avancees ---\n" RESET);
                // Options avancees...
                pause();
                break;
            case 0:
                printf(BLUE BOLD "Au revoir et merci !\n" RESET);
                sauvegarderEtudiants(liste, nombreEtudiants);
                break;
            default:
                printf(RED "Choix invalide.\n");
                pause();
                break;
        }
    } while (choix != 0);
    sauvegarderEtudiants(liste, nombreEtudiants);
    return 0;
}
