#include <stdio.h>

int main() {
    int tab[7] = {15, 20, 38, 40, 50, 67, 70};
    int *ptr = tab;
    int somme = 0;

    for (int i = 0; i < 7; i++) {
        somme += *(ptr + i);
    }

    printf("Les elements du tableau sont :\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    printf("La somme des elements du tableau est : %d\n", somme);

    return 0;
}

