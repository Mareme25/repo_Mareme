#include <stdio.h>
int main () {
	int nbres[10] = {52, 23, 96, 2, 4, 7, 89, 63, 47, 0};
	
	int max, min;
	max = min = nbres[0];
	for (int i = 1; i < 10; i++) {
		if (nbres[i] > max) {
			max = nbres[i];
		}
		if (nbres[i] < min) {
			min = nbres[i];
		}
	}
	printf("Le plus grand nombre est: %d\n", max);
	printf("Le plus petit nombre est: %d\n", min);
	
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 10; j++) {
			if (nbres[i] > nbres[j]) {
				int temp = nbres[i];
				nbres[i] = nbres[j];
				nbres[j] = temp;
			}
		}
	}
	printf ("Tableau trie :\n");
	for (int i = 0; i < 10; i++) {
		printf ("%d\n", nbres[i]);
	}
	printf("\n");
return 0;	
}
