#include <stdio.h>
#include <string.h>

#define MAX_PERSONNES 50
#define TAILLE_MAX 30

typedef struct {
    char nom[TAILLE_MAX];
    char prenom[TAILLE_MAX];
    char telephone[11];
    char email[TAILLE_MAX];
} Personne;

void ajouterPersonne(Personne personnes[], int *nb_personnes) {
    if (*nb_personnes >= MAX_PERSONNES) {
        printf("Le repertoire est plein.\n");
        return;
    }
    
    printf("Entrez le nom: ");
    fgets(personnes[*nb_personnes].nom, TAILLE_MAX, stdin);
    personnes[*nb_personnes].nom[strcspn(personnes[*nb_personnes].nom, "\n")] = 0;
    
    printf("Entrez le prenom: ");
    fgets(personnes[*nb_personnes].prenom, TAILLE_MAX, stdin);
    personnes[*nb_personnes].prenom[strcspn(personnes[*nb_personnes].prenom, "\n")] = 0;
    
    printf("Entrez le numero de telephone (10 chiffres): ");
    fgets(personnes[*nb_personnes].telephone, 11, stdin);
    personnes[*nb_personnes].telephone[strcspn(personnes[*nb_personnes].telephone, "\n")] = 0;
    
    printf("Entrez l'adresse email: ");
    fgets(personnes[*nb_personnes].email, TAILLE_MAX, stdin);
    personnes[*nb_personnes].email[strcspn(personnes[*nb_personnes].email, "\n")] = 0;
    
    (*nb_personnes)++;
}

void afficherRepertoire(Personne personnes[], int nb_personnes) {
    if (nb_personnes == 0) {
        printf("Le répertoire est vide.\n");
        return;
    }

    printf("Répertoire des personnes:\n");
    for (int i = 0; i < nb_personnes; i++) {
        printf("Nom: %s, Prenom: %s, Telephone: %s, Email: %s\n", 
            personnes[i].nom, 
            personnes[i].prenom, 
            personnes[i].telephone, 
            personnes[i].email);
    }
}

void rechercherParTelephone(Personne personnes[], int nb_personnes, char telephone[]) {
    int trouve = 0;
    for (int i = 0; i < nb_personnes; i++) {
        if (strcmp(personnes[i].telephone, telephone) == 0) {
            printf("Personne trouvee:\n");
            printf("Nom: %s, Prenom: %s, Telephone: %s, Email: %s\n", 
                personnes[i].nom, 
                personnes[i].prenom, 
                personnes[i].telephone, 
                personnes[i].email);
            trouve = 1;
            break;
        }
    }
    if (!trouve) {
        printf("Aucune personne trouvee avec ce numero de telephone.\n");
    }
}

int main() {
    Personne personnes[MAX_PERSONNES];
    int nb_personnes = 0;
    int choix;
    char telephoneRecherche[11];

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter une personne\n");
        printf("2. Afficher le repertoire\n");
        printf("3. Rechercher une personne par numero de telephone\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        getchar();
        
        switch (choix) {
            case 1:
                ajouterPersonne(personnes, &nb_personnes);
                break;
            case 2:
                afficherRepertoire(personnes, nb_personnes);
                break;
            case 3:
                printf("Entrez le numéro de telephone a rechercher: ");
                fgets(telephoneRecherche, 11, stdin);
                telephoneRecherche[strcspn(telephoneRecherche, "\n")] = 0;
                rechercherParTelephone(personnes, nb_personnes, telephoneRecherche);
                break;
            case 4:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);

    return 0;
}

