/*
4.  Napisati program koji iz datog niza cijelih brojeva izbacuje uneseni element pri čemu se ne mijenja redoslijed ostalih elemenata. ž
Korisnik najprije unosi niz cijelih pozitivnih brojeva (-1 za kraj unosa, maksimalno 10 elemenata). Zatim se unosi element koji treba izbaciti.
Program treba iz niza izbaciti sva pojavljivanja unesenog elementa, i na kraju ispisati novi niz na ekranu.

Primjer:
	Unesite elemente niza: 2 3 1 5 1 -1
	Unesite element koji treba izbaciti: 1
	Novi niz glasi: 2,3,5

Napomena: Ponovo, ovaj zadatak se može uraditi tako što se u petlji za ispis na ekran stavi npr.:
	if (niz[i] != trazeni) printf(...)
ali radi vježbe probajte uraditi zadatak tako da se najprije izbaci element iz niza, a zatim ispiše tako modifikovan niz.
Ovakav zadatak je vrlo važan za drugi parcijalni ispit! U mnogim zadacima na ispitu traži se neka varijanta izbacivanja člana iz niza
(nevezano za ispis na ekranu) što studenti često ne uspiju ispravno uraditi.

*/
#include <stdio.h>

int main() {

    int i,j,broj,niz[10],dim=0;
    printf("Unesite elemente niza: ");
    for(i=0;i<10;i++) {
        scanf("%d",&broj);
        if(broj==-1) break;
        else {
            niz[i]=broj;
            dim++;
        }
    }

    printf("Unesite element koji treba izbaciti: ");
    scanf("%d",&broj);

    for(i=0;i<dim;i++) {
        if(niz[i]==broj) {
            for(j=i;j<dim-1;j++)
                niz[j]=niz[j+1];
            dim--;i--;
        }
    }

    printf("Novi niz glasi: ");
    for(i=0;i<dim;i++) {
        if(i==dim-1) printf("%d",niz[i]);
        else printf("%d,",niz[i]);
    }
    return 0;
}
