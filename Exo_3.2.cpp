#include <stdio.h>
#include <pthread.h> // Bibliothèque pour les threads
#include <unistd.h>  // Bibliothèque pour sleep()

// Fonction pour imprimer "Bonjour"
void* printBonjour(void* arg) {
    for (int i = 0; i < 100; i++) {
        printf("Bonjour\n");
        usleep(50000); // Pause courte pour observer l'alternance
    }
    printf("Thread Bonjour terminé.\n");
    return NULL;
}

// Fonction pour imprimer "Au revoir"
void* printAuRevoir(void* arg) {
    for (int i = 0; i < 100; i++) {
        printf("Au revoir\n");
        usleep(50000); // Pause courte pour observer l'alternance
    }
    printf("Thread Au revoir terminé.\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2; // Déclaration des threads

    // Création du premier thread pour exécuter printBonjour
    if (pthread_create(&thread1, NULL, printBonjour, NULL) != 0) {
        perror("Erreur lors de la création du thread1");
        return 1;
    }

    // Création du second thread pour exécuter printAuRevoir
    if (pthread_create(&thread2, NULL, printAuRevoir, NULL) != 0) {
        perror("Erreur lors de la création du thread2");
        return 1;
    }

    // Attente de la fin des threads
    if (pthread_join(thread1, NULL) != 0) {
        perror("Erreur lors de l'attente du thread1");
        return 1;
    }
    printf("Le thread Bonjour a terminé son exécution.\n");

    if (pthread_join(thread2, NULL) != 0) {
        perror("Erreur lors de l'attente du thread2");
        return 1;
    }
    printf("Le thread Au revoir a terminé son exécution.\n");

    printf("Exécution principale terminée.\n");
    return 0;
}

