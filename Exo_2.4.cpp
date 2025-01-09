#include <stdio.h>

int main () {
	int tab[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int *pointeur = tab;
	int nbre, i;
	int trouve = 0;
	
	printf("Veuillez entrez un nombre a rechercher : ");
	scanf ("%d", &nbre);
	
	for (i = 0; i < 10; i++) {
		if (*(pointeur + i) == nbre) {
			printf("Le nombre %d est present dans le tableau.\n", nbre, i);
			trouve = 1;
			break;
		}
	}
	if (!trouve) {
		printf("Le nombre %d n'est pas present dans le tableau.\n", nbre);
	}
	
return 0;
}
