/*
Napravite program koji učitava realnu matricu dimenzija A×B te pronalazi sumu elemenata na rubu matrice.
Korisnik najprije unosi dimenzije A i B (ne veće od 100) a zatim unosi elemente matrice. Rub matrice sačinjavaju
elementi prvog i zadnjeg reda, te elementi prve i zadnje kolone. Pri tome pazite da se elementi u ćoškovima ne
budu dvaput uračunati u sumu! Primjer:

Suma = a11+a12+a13+...+a1n+a2n+a3n+...+amn+...+am3+am2+am1+...+a31+a21

Primjer ulaza i izlaza:
	Unesite dimenzije matrice: 2 2
	Unesite elemente matrice: 1 2 3 4
	Suma elemenata na rubu je 10.00

*/
#include <stdio.h>

int main() {
    int a,b,i,j;
    double mat[100][100],suma=0;
    printf("Unesite dimenzije matrice: ");
    scanf("%d %d",&a,&b);
    printf("Unesite elemente matrice: ");
    for(i=0;i<a;i++) {
        for(j=0;j<b;j++) {
            scanf("%lf",&mat[i][j]);
            if(i==0 || i==a-1) suma+=mat[i][j];
            else if(i>0 && i<a-1) {
                if(j==0 || j==b-1) suma+=mat[i][j];
            }
        }
    }

    printf("Suma elemenata na rubu je %.2f",suma);
    return 0;
}