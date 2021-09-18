//
// Created by 38760 on 18. 9. 2021..
//

/*
Napraviti program koji sa standardnog ulaza (tastature) učitava koordinate dvije tačke u trodimenzionalnom prostoru.
Tačke t1 i t2 su definirane kao trojke:

t1=(x1, y1, z1)
t2=(x2, y2, z2)

Program na standardni izlaz (ekran) treba da ispiše udaljenost između ove dvije tačke. Za računanje drugog korijena možete
koristiti funkciju sqrt koja je definisana u biblioteci “math.h”. Primjer korištenja ove funkcije je:
	x = sqrt(y);  x je korijen od y */


#include <stdio.h>
#include <math.h>

int main() {
    float x1,x2,y1,y2,z1,z2,d;
    printf("Unesite koordinate tacke t1: ");
    scanf("%f,%f,%f", &x1, &y1, &z1);
    printf("\nUnesite koordinate tacke t2: ");
    scanf("%f,%f,%f", &x2, &y2, &z2);
    d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
    printf("\nUdaljenost tacaka t1 i t2 je %.2f", d);
    return 0;
}
