#include <stdio.h>
int main () {
	int nbres[10] = {50, 24, 99, 122, 4, 7, 89, 63, 122, 0};
	int aRechercher, compteur = 0;
	int i;
	
	printf("Entrez le nombre a rechercher: ");
	scanf("%d", &aRechercher);
	
	for (i = 0; i < 10; i++) {
		if (nbres[i] == aRechercher) {
			compteur++;
		}
	}
	printf("Le nombre %d apparait %d fois dans le tableau.\n", aRechercher, compteur);
	
	return 0;
}
