#ifndef FONCTION_H
#define FONCTION_H

//Definition des structures date et etudiant

typedef struct Date
{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct Etudiant
{
    char matricule[11];
    char nom[30];
    char prenom[30];
    Date dateNaissance;
    char sexe[5];
    char departement[20];
    char filiere[20];
    char regionOrigine[20];
}Etudiant;

//Prototypes des fonctions

//Zone d'affichage

void afficherMenuPrincipal();
void afficherEtudiant(Etudiant *etudiant);
void afficherEtudiants(Etudiant *etudiants, int nombreEtudiants);

//Zone d'enregistrement des etudiants

void enregistrerEtudiant(Etudiant *etudiants);
void enregistrerPlusieursEtudiants(Etudiant *etudiants, int nombreEtudiants);

//Zone de recherche des etudiants
int rechercherEtudiantParMatricule(Etudiant *etudiants, int nombreEtudiants, const char *matricule);
void rechercherEtudiantsParNom(Etudiant *etudiants, int nombreEtudiants, const char *nom);
void rechercherEtudiantsParFiliere(Etudiant *etudiants, int nombreEtudiants, const char *filiere);
void rechercherEtudiantsParMotClef(Etudiant *etudiants, int nombreEtudiants, const char *motCle);

//Zone de modification/suppression des etudiants

void modifierEtudiant(Etudiant *etudiants, int nombreEtudiants, const char *matricule);
void supprimerEtudiant(Etudiant *etudiants, int *nombreEtudiants, const char *matricule);

//Zone de tri des etudiants
void trierEtudiantsParFiliere(Etudiant *etudiants, int nombreEtudiants);
void trierEtudiantsParNom(Etudiant *etudiants, int nombreEtudiants);
void trierEtudiantsParDateNaissance(Etudiant *etudiants, int nombreEtudiants);

//Zone de manipulation des fichiers

void sauvegarderEtudiantsDansFichier(Etudiant *etudiants, int nombreEtudiants, const char *nomFichier);
int chargerEtudiantsDepuisFichier(Etudiant *etudiants, const char *nomFichier);

//Zone des statistiques

int calculerAge(Etudiant etudiant);
int calculerAgeMoyen(Etudiant *etudiants, int nombreEtudiants);
int compterEtudiantsParFiliere(Etudiant *etudiants, int nombreEtudiants, const char *filiere);
int compterEtudiantsParRegion(Etudiant *etudiants, int nombreEtudiants, const char *region);


#endif // FONCTION_H