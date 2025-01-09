#include <stdio.h>

int main() {
    int tab1[5] = {10, 20, 30, 40, 50};
    int tab2[5] = {10, 20, 35, 40, 50};
    
    int *ptr1 = tab1;
    int *ptr2 = tab2;
    int identique = 1;

    for (int i = 0; i < 5; i++) {
        if (*(ptr1 + i) != *(ptr2 + i)) {
            identique = 0;
            break;
        }
    }

    if (identique) {
        printf("Les tableaux sont identiques.\n");
    } else {
        printf("Les tableaux ne sont pas identiques.\n");
    }

    return 0;
}

