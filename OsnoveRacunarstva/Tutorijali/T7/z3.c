/*
Napravite funkciju "faktorijel" koja računa faktorijel datog broja. Zatim iskoristite ovu funkciju za program koji računa sumu:

Primjer ulaza i izlaza:
Unesite broj n u intervalu [1, 12]: 1
Unesite realan broj x: 2.45
Suma od 1 do 1 za x = 2.450 je 2.450

*/
#include <stdio.h>

long faktorijel (int n) {
    int fact=1,i;
    for(i=1;i<=n;i++) fact*=i;

    return fact;
}

int main() {
    double rez=0,x;
    int i, n;
    printf("Unesite broj n u intervalu [1, 12]: ");
    scanf("%d",&n);
    printf("Unesite realan broj x: ");
    scanf("%lf",&x);

    for(i=n;i>=1;i--) {
        rez+=x/faktorijel(i);
    }
    printf("Suma od 1 do %d za x = %.3lf je %.3lf",n,x,rez);
    return 0;
}