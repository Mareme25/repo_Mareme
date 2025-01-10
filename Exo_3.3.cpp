
//Les threads sont compréhensibles mais je ne suis pas certaine de pouvoir refaire un programme pareil toute seule


#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // Pour usleep

// Variables globales pour compter les impressions
int countBonjour = 0;
int countAuRevoir = 0;

// Mutex pour protéger l'accès aux variables globales
pthread_mutex_t mutex;

void* printBonjour(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&mutex); // Verrouiller le mutex
        countBonjour++;
        pthread_mutex_unlock(&mutex); // Déverrouiller le mutex
        printf("Bonjour\n");
        usleep(50000); // Pause courte
    }
    printf("Thread Bonjour termine.\n");
    return NULL;
}

void* printAuRevoir(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&mutex); // Verrouiller le mutex
        countAuRevoir++;
        pthread_mutex_unlock(&mutex); // Déverrouiller le mutex
        printf("Au revoir\n");
        usleep(50000); // Pause courte
    }
    printf("Thread Au revoir termine.\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialisation du mutex
    pthread_mutex_init(&mutex, NULL);

    // Création des threads
    if (pthread_create(&thread1, NULL, printBonjour, NULL) != 0) {
        perror("Erreur lors de la creation du thread1");
        return 1;
    }
    if (pthread_create(&thread2, NULL, printAuRevoir, NULL) != 0) {
        perror("Erreur lors de la creation du thread2");
        return 1;
    }

    // Attente de la fin des threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Afficher les résultats
    printf("\nNombre de fois que 'Bonjour' a ete imprime : %d\n", countBonjour);
    printf("Nombre de fois que 'Au revoir' a ete imprime : %d\n", countAuRevoir);

    // Destruction du mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

