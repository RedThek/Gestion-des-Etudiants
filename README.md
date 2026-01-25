# 🎓 Gestion des Étudiants

Bienvenue dans le projet **Gestion des Étudiants**, une application console développée en langage C permettant de gérer efficacement une base de données étudiante.

Ce projet a été réalisé dans le cadre de notre TP académique par une équipe de 5 développeurs.

## 🚀 Fonctionnalités Principales

Le programme offre une interface modulaire pour effectuer les opérations CRUD (Create, Read, Update, Delete) et bien plus :

* **💾 Persistance des données :** Sauvegarde et chargement automatique via un fichier CSV (`etudiants.txt`).
* **🛡️ Saisie Sécurisée :** Protection contre les entrées invalides (dates, chiffres, buffer overflow).
* **🔍 Recherche Avancée :** * Recherche linéaire par Matricule.
  * Recherche dichotomique (pour les grands volumes de données).
* **⚡ Tri :** Algorithmes de tri par ordre alphabétique (Nom) et par Filière.
* **📊 Utilitaires :** Calcul automatique de l'âge à partir de la date de naissance.

## 🛠️ Prérequis techniques

* **Compilateur C :** GCC (recommandé) ou Clang.
* **OS :** Windows, Linux, ou macOS.
* **Encodage :** UTF-8 (pour l'affichage correct des caractères).

## 📥 Installation et Compilation

1. **Cloner le dépôt :**

    ```bash
    git clone https://github.com/RedThek/Gestion-des-Etudiants.git
    ```

    **Et naviguez dans le dossier correspondant :**

    ```bash
    cd Gestion-des-Etudiants
    ```

2. **Compiler le projet :**
    Nous utilisons une architecture modulaire. Compilez les fichiers sources ensemble :

    *Sur Linux / Mac :*

    ```bash
    gcc main.c fonction.c -o app_etudiant
    ```

    *Sur Windows :*

    ```bash
    gcc main.c fonction.c -o app_etudiant.exe
    ```

3. **Lancer l'application :**
    *Sur Linux / Mac :* `./app_etudiant`
    *Sur Windows :* `app_etudiant.exe`

## 📂 Structure du Projet

```text
gestion-etudiants/
│
├── main.c           # Point d'entrée, gestion de la boucle principale et du menu
├── fonction.c       # Implémentation de la logique (Algo de tri, recherche, fichiers)
├── fonction.h       # Définition des structures (Etudiant, Date) et prototypes
├── etudiants.txt    # Base de données (générée automatiquement)
└── README.md        # Documentation du projet

## La team derriere ce projet
