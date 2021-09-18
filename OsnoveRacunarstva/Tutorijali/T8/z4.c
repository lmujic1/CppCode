/*
Korisnik sa tastature unosi osam realnih brojeva koji predstavljaju mjerenja temperature tokom jednog dana (temperatura se mjeri svaka 3 sata).
Napišite program koji treba ispisati najveću temperaturu tokom jednog dana te prosječnu temperaturu.

Primjer ulaza i izlaza programa:
	Unesite temperature: 10 11 14 18 20 16 12 11
Maksimalna temperatura: 20.0
	Prosjecna temperatura: 14.0

Ovaj zadatak riješite tako što ćete napraviti dvije funkcije:

Funkcija maxtemp() koja vraća maksimalnu vrijednost niza. Prototip:
float maxtemp(float p[8]);

Funkcija prtemp() koja vraća prosječnu vrijednost elemenata niza. Prototip:
float prtemp(float p[8]);

*/
#include <stdio.h>
float maxtemp(float p[8]) {
    float max;
    int i;
    max=p[0];
    for(i=0;i<8;i++) {
        if(p[i]>max) max=p[i];
    }
    return max;
}

float prtemp (float p[8]) {
    float suma=0;
    int i;
    for(i=0;i<8;i++) suma+=p[i];
    return suma/8;
}
int main() {
    float temp[8];
    int i;
    printf("Unesite temperature: ");
    for(i=0;i<8;i++) scanf("%f",&temp[i]);
    printf("Maksimalna temperatura: %.1f",maxtemp(temp));
    printf("\nProsjecna temperatura: %.1f",prtemp(temp));
    return 0;
}
