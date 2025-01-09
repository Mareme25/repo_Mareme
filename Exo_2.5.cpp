#include <stdio.h>

int main () {
	int tab[6] = {45, 63, 89, 47, 2, 5};
	int *ptr = tab;
	int temp;
	
	printf("Tableau avant le tri :\n");
	for (int i = 0; i < 6; i++) {
		printf("%d ", *(ptr + i));
	}
	printf("\n");
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6 - i - 1; j++) {
			if (*(ptr + j) > *(ptr + j + 1)) {
				temp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = temp;
			}
		}
	}
	
	printf("Tableau apres le tri dans l'ordre croissant :\n");
	for (int i = 0; i < 6; i++) {
		printf("%d ", *(ptr + i));
	}
	printf("\n");
	
	return 0;
	
}
