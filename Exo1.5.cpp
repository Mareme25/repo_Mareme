#include <stdio.h>

int main() {
    int nbres[10] = {50, 24, 99, 122, 4, 7, 89, 63, 122, 0};
    int i;

    printf("\nLes nombres pairs sont :\n");
    for (i = 0; i < 10; i++) {
        if (nbres[i] % 2 == 0) {
            printf("%d ", nbres[i]);
        }
    }

    printf("\n\nLes nombres impairs sont :\n");
    for (i = 0; i < 10; i++) {
        if (nbres[i] % 2 != 0) {
            printf("%d ", nbres[i]);
        }
    }

    printf("\n");
    return 0;
}

