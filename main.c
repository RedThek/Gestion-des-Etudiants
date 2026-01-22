#include "fonction.h"
#define MAX_ETUDIANTS 100

int main() {
    Etudiant liste[MAX_ETUDIANTS];
    int nombreEtudiants = 0;
    int choix;
    char matRech[20];
    int index;

    // 1. CHARGEMENT AUTOMATIQUE AU DEMARRAGE
    printf("Voulez-vous charger les donnees depuis le fichier ? (1=Oui, 0=Non): ");
    int charger;
    scanf("%d", &charger);
    if (charger) {
        nombreEtudiants = chargerEtudiants(liste);
    }

    // Si aucun étudiant chargé (fichier inexistant ou vide), on demande la saisie initiale
    if (nombreEtudiants == 0) {
        printf("Aucune donnee trouvee. Entrez le nombre initial d'etudiants a saisir: ");
        int aSaisir;
        scanf("%d", &aSaisir);
        for(int i=0; i<aSaisir; i++) {
            printf("\n--- Etudiant %d ---\n", i+1);
            saisirEtudiant(&liste[nombreEtudiants]); // Utilise l'index courant
            nombreEtudiants++;
        }
        // Sauvegarde immédiate après la première saisie
        sauvegarderEtudiants(liste, nombreEtudiants);
    }

    do {
        choix = menu();

        switch(choix) {

            case 1: // Enregistrer
                if(nombreEtudiants < MAX_ETUDIANTS) {
                    saisirEtudiant(&liste[nombreEtudiants]);
                    nombreEtudiants++;
                    // Sauvegarde automatique après ajout (Sécurité)
                    sauvegarderEtudiants(liste, nombreEtudiants);
                } else { printf("Liste pleine.\n"); }
                break;
            
            case 2: // Modifier
                printf("Matricule a modifier: "); scanf("%s", matRech);
                index = rechercherMatricule(liste, nombreEtudiants, matRech);
                if(index != -1) {
                    modifierEtudiant(&liste[index]);
                    sauvegarderEtudiants(liste, nombreEtudiants); // Sauvegarde après modif
                }
                else printf("Introuvable.\n");
                break;

            case 3: // Rechercher
                printf("Matricule a chercher: "); scanf("%s", matRech);
                index = rechercherMatricule(liste, nombreEtudiants, matRech);
                if(index != -1) afficherListe(&liste[index], 1);
                else printf("Introuvable.\n");
                break;

            case 4: // Supprimer
                printf("Matricule a supprimer: "); scanf("%s", matRech);
                // Note: Il faudrait modifier la fonction supprimer pour qu'elle renvoie 1 si succès
                // Pour l'instant on sauvegarde après tentative
                supprimerEtudiant(liste, &nombreEtudiants, matRech);
                sauvegarderEtudiants(liste, nombreEtudiants);
                break;
            case 5:
                trierAlphabetique(liste, nombreEtudiants);
                afficherListe(liste, nombreEtudiants);
                break;
            case 6:
                // Attention: Trier par matricule avant la dichotomie serait ideal ici
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
                // Sauvegarde finale par sécurité
                sauvegarderEtudiants(liste, nombreEtudiants);
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
