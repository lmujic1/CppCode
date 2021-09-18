/*
Napisati program koji najprije traži da se unesu dva niza pozitivnih cijelih brojeva A i B. Unos niza se prekida kada korisnik unese broj -1,
a maksimalan broj elemenata u nizovima je 10. Nakon unosa, nizove A i B je potrebno spojiti u novi niz C. Konačno, tako formirani niz C treba ispisati na ekranu.

Ovaj zadatak je vrlo jednostavno riješiti bez korištenja niza C, no za vježbu pokušajte ga uraditi tačno po koracima koji su dati iznad.

Primjer ulaza i izlaza:
	Unesite elemente niza A: 5 3 8 -1
	Unesite elemente niza B: 2 3 1 5 1 -1
	Niz C glasi: 5,3,8,2,3,1,5,1

Napomena: U gornjem primjeru demonstrirana je pojava da se više uzastopnih naredbi scanf može izvršiti tako što se vrijednosti unose razdvojene razmakom. Npr. ako kod glasi:
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
korisnik može kucati
	1 2 3 (Enter)
i ova tri broja će biti upisana u varijable a, b i c respektivno.

*/
#include <stdio.h>

int main() {
    int i=0, n1=0, n2=0, broj, A[10], B[10], C[20]={0};
    printf("Unesite elemente niza A: ");
    for(i=0;i<10;i++) {
        scanf("%d",&broj);
        if(broj==-1) break;
        else {
            A[i]=broj;
            n1++;
        }
    }

    printf("Unesite elemente niza B: ");
    for(i=0;i<10;i++) {
        scanf("%d",&broj);
        if(broj==-1) break;
        else {
            B[i]=broj;
            n2++;
        }
    }

    for(i=0;i<n1;i++) {
        C[i]=A[i];
    }
    for(i=0;i<n2;i++) {
        C[i+n1]=B[i];
    }

    printf("Niz C glasi: ");
    for(i=0;i<n1+n2;i++) {
        if(i==n1+n2-1 ) printf("%d",C[i]);
        else printf("%d,", C[i]);
    }
    return 0;
}