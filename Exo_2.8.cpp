#include <stdio.h>

int main() {
    int tab[8] = {45, 17, 89, 32, 12, 81, 64, 28};
    int *ptr = tab;

    int max = *ptr; 
    int min = *ptr;

    for (int i = 0; i < 8; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
    }

    printf("Les elements du tableau sont :\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    printf("Le plus grand element du tableau est : %d\n", max);
    printf("Le plus petit element du tableau est : %d\n", min);

    return 0;
}

