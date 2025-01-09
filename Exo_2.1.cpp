#include <stdio.h>
int main () {
	int nbre = 26;
	int *pointeur = &nbre; //déclaration d'un pointeur
	
	printf("Avant modification : nbre = %d\n", nbre);
	*pointeur = 46;
	
	printf("Apres modification : nbre = %d\n", nbre);
	
	return 0;

}
