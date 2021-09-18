/*
Napravite program koji učivata matricu cijelih brojeva dimenzija 10x10, a zatim pronalazi red sa najvećim i red sa najmanjim elementom.
Ako se oba elementa nalaze u istom redu, program treba ispisati poruku "Najveci i najmanji element se nalaze u istom redu." i završiti s radom.
U suprotnom, potrebno je zamijeniti mjesta ta dva reda u matrici i ispisati tako modifikovanu matricu na ekranu.

Primjer ulaza i izlaza:
	Unesite elemente matrice: 1 2 3 4 ...
	Nakon zamjene matrica glasi:
	1 2 3 4 ...

*/
#include <stdio.h>

int main() {
    int i,j,max,min,zapamtipoziciju1=0,zapamtipoziciju2=0,mat[10][10],temp;
    printf("Unesite elemente matrice: ");
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            scanf("%d",&mat[i][j]);

    max=mat[0][0];
    min=mat[0][0];
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            if(mat[i][j]>max) {max=mat[i][j]; zapamtipoziciju1=i;}
            if(mat[i][j]<min) {min=mat[i][j]; zapamtipoziciju2=i;}
        }
    }

    if(zapamtipoziciju1==zapamtipoziciju2) printf("Najmanji i najveci element se nalaze u istom redu.");
    else {

        for(i=0;i<10;i++) {
            temp=mat[zapamtipoziciju2][i];
            mat[zapamtipoziciju2][i]=mat[zapamtipoziciju1][i];
            mat[zapamtipoziciju1][i]=temp;
        }

        printf("Nakon zamjene matrica glasi:\n");

        for(i=0;i<10;i++) {
            for(j=0;j<10;j++) {
                if(i==zapamtipoziciju2 && j>0) printf("%2d",mat[i][j]);
                else if(j==9) printf("%-2d",mat[i][j]);
                else printf("%-2d",mat[i][j]);
            }	printf("\n");
        }
    }

    return 0;
}
