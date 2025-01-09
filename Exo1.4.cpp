#include <stdio.h>
int main () {
	int nbres[10] = {50, 24, 99, 122, 4, 7, 89, 63, 122, 0};
    int i;
    float somme = 0, moyenne;
    int totalSup = 0;
    
    for (i = 0; i < 10; i++){
		somme += nbres[i];
	}	
    moyenne = somme / 10;

    printf("\nLa moyenne est : %f\n", moyenne);

    printf("Les nombres superieurs a la moyenne sont :\n");
    for (i = 0; i < 10; i++) {
        if (nbres[i] > moyenne) {
            printf("%d ", nbres[i]);
            totalSup += nbres[i];
        }
    }

    printf("\nLe total des nombres superieurs a la moyenne est : %d\n", totalSup);

    return 0;
}
