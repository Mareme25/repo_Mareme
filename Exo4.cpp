#include <stdio.h>
int main () {
	int hauteur = 8;
	int largeur = 4;
	int Perimetre, Surface;

Perimetre = 2*(hauteur + largeur);
Surface = hauteur * largeur;
	printf("Le perimetre de ce rectangle = %dcm\n", Perimetre);
	printf("La surface de ce rectangle = %dcm²\n", Surface);
return 0;
}
