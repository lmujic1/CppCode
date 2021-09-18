/*
 Napisati program koji će izračunavati vrijednost konačnog reda:

S=i=1n(-1)i-1i

Broj n se unosi sa tastature, a rezultat sume treba ispisati na ekranu zaokružen na tri decimale. Primjer ulaza i izlaza:

Unesite broj n: 5
Koristeci 5 clanova suma je 0.783.

*/
#include <stdio.h>
#include <math.h>
int main() {
    int i,n;
    double suma=0;
    printf("Unesite broj n: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        suma=suma+((pow(-1,i-1)*1.)/i);
    }
    printf("Koristeci %d clanova suma je %.3lf.", n,suma);
    return 0;
}
