#include <stdio.h>
#include <pthread.h> // Biblioth�que pour les threads
#include <unistd.h>  // Biblioth�que pour sleep()

// Fonction pour imprimer "Bonjour"
void* printBonjour(void* arg) {
    for (int i = 0; i < 100; i++) {
        printf("Bonjour\n");
        usleep(50000); // Pause courte pour observer l'alternance
    }
    return NULL;
}

// Fonction pour imprimer "Au revoir"
void* printAuRevoir(void* arg) {
    for (int i = 0; i < 100; i++) {
        printf("Au revoir\n");
        usleep(50000); // Pause courte pour observer l'alternance
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2; // D�claration des threads

    // Cr�ation du premier thread pour ex�cuter printBonjour
    if (pthread_create(&thread1, NULL, printBonjour, NULL) != 0) {
        perror("Erreur lors de la cr�ation du thread1");
        return 1;
    }

    // Cr�ation du second thread pour ex�cuter printAuRevoir
    if (pthread_create(&thread2, NULL, printAuRevoir, NULL) != 0) {
        perror("Erreur lors de la cr�ation du thread2");
        return 1;
    }

    // Attente de la fin des threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Execution terminee.\n");
    return 0;
}

