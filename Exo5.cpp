#include <stdio.h>
int main () {
	int rayon = 5;
	float Perimetre, Surface;
	
	Perimetre = 2 * rayon * 3.14;
		printf("Le perimetre de ce cercle = %fcm\n", Perimetre);
	Surface = rayon * rayon * 3.14;
		printf("La surface de ce cercle = %fcm²\n", Surface);
return 0;
}
