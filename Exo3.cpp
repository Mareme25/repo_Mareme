#include <stdio.h>
int main () {
	float nb1, nb2, somme;
	printf("Entrez le 1er nombre :  ");
		scanf("%f", &nb1);
	printf("Entrez le 2eme nombre :  ");
		scanf("%f", &nb2);
	
	somme = nb1 + nb2;
	printf("La somme de %f et %f est %f\n", nb1, nb2, somme);
	return 0;
}
