#include <stdio.h>

int main () {
	int tab1[5] = {10, 20, 30, 40, 50};
	int tab2[5] = {56, 80, 14, 5, 6};
	int tabaddition[5];
	
	int *pointeur1 = tab1;
	int *pointeur2 = tab2;
	int *pointeuraddition = tabaddition;
	
	for (int i = 0; i < 5; i++) {
		*(pointeuraddition + i) = *(pointeur1 + i) + *(pointeur2 + i);
	}
	
	printf("Tableau 1 : ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", *(pointeur1 + i));
	}
	printf("\n");
	
	printf("Tableau 2 : ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", *(pointeur2 + i));
	}
	printf("\n");
	
	printf("Tableau addition : ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", *(pointeuraddition + i));
	}
	
	printf("\n");
	return 0;

}
