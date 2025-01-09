#include <stdio.h>

int main () {
	int nbres[5] = {56, 2, 34, 10, 7};
	int *pointeur = nbres;
	
	printf("Les elements du tableau sont :\n");
	
	for (int i = 0; i < 5; i++) {
		printf("Element %d : %d\n", i + 1, *(pointeur + i));
	}

return 0;
}
