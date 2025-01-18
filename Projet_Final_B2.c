#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct {
    int id;                 // Identifiant unique
    char nom[50];           // Nom de l'étudiant
    float moyenne;          // Moyenne générale
} Etudiant;

// Prototypes des fonctions
void initialiserEtudiants(Etudiant etudiants[], int *nbEtudiants);
void afficherMenu();
void ajouterEtudiant(Etudiant etudiants[], int *nbEtudiants);
void modifierEtudiant(Etudiant etudiants[], int nbEtudiants);
void supprimerEtudiant(Etudiant etudiants[], int *nbEtudiants);
void afficherEtudiants(Etudiant etudiants[], int nbEtudiants);
void trierEtudiants(Etudiant etudiants[], int nbEtudiants);
void rechercherEtudiant(Etudiant etudiants[], int nbEtudiants);

int main() {
    Etudiant etudiants[MAX_ETUDIANTS];
    int nbEtudiants = 0;
    int choix;

    // Initialisation des données prédéfinies
    initialiserEtudiants(etudiants, &nbEtudiants);

    do {
        afficherMenu();
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterEtudiant(etudiants, &nbEtudiants);
                break;
            case 2:
                modifierEtudiant(etudiants, nbEtudiants);
                break;
            case 3:
                supprimerEtudiant(etudiants, &nbEtudiants);
                break;
            case 4:
                afficherEtudiants(etudiants, nbEtudiants);
                break;
            case 5:
                trierEtudiants(etudiants, nbEtudiants);
                break;
            case 6:
                rechercherEtudiant(etudiants, nbEtudiants);
                break;
            case 7:
                printf("Au revoir, merci !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 7);

    return 0;
}

// Fonction pour afficher le menu interactif
void afficherMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Ajouter un etudiant\n");
    printf("2. Modifier un etudiant\n");
    printf("3. Supprimer un etudiant\n");
    printf("4. Afficher tous les etudiants\n");
    printf("5. Trier les etudiants par moyenne\n");
    printf("6. Rechercher un etudiant par nom\n");
    printf("7. Quitter\n");
}

// Fonction pour initialiser des données prédéfinies
void initialiserEtudiants(Etudiant etudiants[], int *nbEtudiants) {
    Etudiant e1 = {1, "Macy", 15.5};
    Etudiant e2 = {2, "Franck", 12.8};
    Etudiant e3 = {3, "Yanis", 18.2};

    etudiants[0] = e1;
    etudiants[1] = e2;
    etudiants[2] = e3;

    *nbEtudiants = 3;
}

// Fonction pour ajouter un étudiant
void ajouterEtudiant(Etudiant etudiants[], int *nbEtudiants) {
    if (*nbEtudiants >= MAX_ETUDIANTS) {
        printf("Erreur : Le tableau est plein.\n");
        return;
    }
    Etudiant nouveau;
    nouveau.id = *nbEtudiants + 1;
    printf("Nom de l'etudiant : ");
    scanf("%s", nouveau.nom);

    do {
        printf("Moyenne de l'etudiant (0 a 20) : ");
        scanf("%f", &nouveau.moyenne);
    } while (nouveau.moyenne < 0 || nouveau.moyenne > 20);

    etudiants[*nbEtudiants] = nouveau;
    (*nbEtudiants)++;
    printf("Etudiant ajoute avec succes !\n");
}

// Fonction pour modifier un étudiant
void modifierEtudiant(Etudiant etudiants[], int nbEtudiants) {
    int id;
    printf("ID de l'etudiant a modifier : ");
    scanf("%d", &id);

    if (id < 1 || id > nbEtudiants) {
        printf("Erreur : ID invalide.\n");
        return;
    }

    Etudiant *etudiant = &etudiants[id - 1];
    printf("Nouveau nom (%s) : ", etudiant->nom);
    scanf("%s", etudiant->nom);
    do {
        printf("Nouvelle moyenne (%.2f) : ", etudiant->moyenne);
        scanf("%f", &etudiant->moyenne);
    } while (etudiant->moyenne < 0 || etudiant->moyenne > 20);

    printf("Etudiant modifie avec succes !\n");
}

// Fonction pour supprimer un étudiant
void supprimerEtudiant(Etudiant etudiants[], int *nbEtudiants) {
    int id;
    printf("ID de l'etudiant a supprimer : ");
    scanf("%d", &id);

    if (id < 1 || id > *nbEtudiants) {
        printf("Erreur : ID invalide.\n");
        return;
    }
    
	int i;
    for ( i = 0 - 1; i < *nbEtudiants - 1; i++) {
        etudiants[i] = etudiants[i + 1];
    }
    (*nbEtudiants)--;
    printf("Etudiant supprime avec succes !\n");
}

// Fonction pour afficher tous les étudiants
void afficherEtudiants(Etudiant etudiants[], int nbEtudiants) {
    if (nbEtudiants == 0) {
        printf("Aucun etudiant a afficher.\n");
        return;
    }
    printf("\nListe des etudiants :\n");
    int i;
    for ( i = 0; i < nbEtudiants; i++) {
        printf("ID: %d, Nom: %s, Moyenne: %.2f\n",
               etudiants[i].id, etudiants[i].nom, etudiants[i].moyenne);
    }
}

// Fonction pour trier les étudiants par moyenne (croissante)
void trierEtudiants(Etudiant etudiants[], int nbEtudiants) {
	int i;
    for ( i = 0; i < nbEtudiants - 1; i++) {
    	int j;
        for ( j = i + 1; j < nbEtudiants; j++) {
            if (etudiants[i].moyenne > etudiants[j].moyenne) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    
    //Afficher les étudiants après le tri
    printf("\nListe des etudiants tries par moyenne (croissante) !\n");
    afficherEtudiants(etudiants, nbEtudiants);
}

// Fonction pour rechercher un étudiant par nom
void rechercherEtudiant(Etudiant etudiants[], int nbEtudiants) {
    char nomRecherche[50];
    printf("Entrez le nom a rechercher : ");
    scanf("%s", nomRecherche);

    int i;
	for ( i = 0; i < nbEtudiants; i++) {
        if (strcmp(etudiants[i].nom, nomRecherche) == 0) {
            printf("ID: %d, Nom: %s, Moyenne: %.2f\n",
                   etudiants[i].id, etudiants[i].nom, etudiants[i].moyenne);
            return;
        }
    }
    printf("Aucun etudiant trouve avec ce nom.\n");
}

