#include <stdio.h>

int main() {
    int tab1[5] = {10, 20, 30, 40, 50};
    int tab2[5];
    
    int *ptr1 = tab1;
    int *ptr2 = tab2;

    for (int i = 0; i < 5; i++) {
        *(ptr2 + i) = *(ptr1 + i);
    }

    printf("Tableau 1 :\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr1 + i));
    }
    printf("\n");

    printf("Tableau 2 (la copie de tableau 1) :\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr2 + i));
    }
    printf("\n");

    return 0;
}

