#include "fonction.h"
#define MAX_ETUDIANTS 500

int main() {
    Etudiant liste[MAX_ETUDIANTS];
    int choix, index, nombreEtudiants = 0;
    char matRech[20];

    nombreEtudiants = chargerEtudiants(liste);

    do {
        choix = menu();

        switch(choix) {

            case 1:
                if (nombreEtudiants <= 0) {
                    printf(RED "Aucune donnee trouvee. Entrez le nombre initial d'etudiants a saisir: " RESET);
                    int aSaisir = lireEntier();
                    for(int i = 0; i < aSaisir; i++) {
                        printf("\n--- Etudiant %d ---\n", i+1);
                        saisirEtudiant(&liste[nombreEtudiants], liste, nombreEtudiants); // Utilise l'index courant
                        nombreEtudiants++;
                    }
                    sauvegarderEtudiants(liste, nombreEtudiants);
                } else if(nombreEtudiants < MAX_ETUDIANTS) {
                    saisirEtudiant(&liste[nombreEtudiants], liste, nombreEtudiants);
                    nombreEtudiants++;
                    sauvegarderEtudiants(liste, nombreEtudiants);
                } else { printf(RED "Liste pleine impossible d'ajouter.\n" RESET); }
                break;
            
            case 2:
                printf("Matricule a modifier: "); scanf("%s", matRech);
                index = rechercherMatricule(liste, nombreEtudiants, matRech);
                if(index != -1) {
                    modifierEtudiant(&liste[index], index);
                    sauvegarderEtudiants(liste, nombreEtudiants);
                }
                else printf("Introuvable.\n");
                break;

            case 3:
                printf("Matricule a chercher: "); scanf("%s", matRech);
                index = rechercherMatricule(liste, nombreEtudiants, matRech);
                if(index != -1) afficherListe(&liste[index], 1);
                else printf("Introuvable.\n");
                break;

            case 4:
                printf("Matricule a supprimer: "); scanf("%s", matRech);
                supprimerEtudiant(liste, &nombreEtudiants, matRech);
                sauvegarderEtudiants(liste, nombreEtudiants);
                break;
            case 5:
                trierAlphabetique(liste, nombreEtudiants);
                afficherListe(liste, nombreEtudiants);
                break;
            case 6:
                printf("Matricule a chercher (Dichotomie): "); scanf("%s", matRech);
                index = rechercheDichotomique(liste, nombreEtudiants, matRech);
                if(index != -1) printf("Trouve a la position %d\n", index);
                else printf("Non trouve (Avez-vous trie par matricule ?)\n");
                break;
            case 7:
                printf("Matricule pour calcul age: "); scanf("%s", matRech);
                index = rechercherMatricule(liste, nombreEtudiants, matRech);
                if(index != -1) 
                    printf("Age: %d ans\n", calculerAge(liste[index].dateNaissance, 2025));
                break;
            case 8:
                trierFiliere(liste, nombreEtudiants);
                afficherListe(liste, nombreEtudiants);
                break;
            case 9:
                afficherListe(liste, nombreEtudiants);
                break;
            case 0:
                printf("Au revoir !\n");
                sauvegarderEtudiants(liste, nombreEtudiants);
                break;
            default:
                printf(RED "Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
