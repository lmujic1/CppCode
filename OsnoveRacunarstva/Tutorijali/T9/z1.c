/*
Napraviti funkciju drugi koja u datom nizu cijelih brojeva pronalazi drugi po veličini i vraća indeks tog člana u nizu.
U slučaju da niz ne sadrži drugi po veličini element funkcija treba vratiti broj -1.

Primjer ulaza i izlaza programa:

	Unesite niz brojeva: 10 5 4 9 8 3 10 -1
	Indeks drugog po velicini je: 3

Najveći element u unesenom nizu je 10, a drugi po veličini je 9. Broj 9 se nalazi na 4. mjestu odnosno
označen je indeksom 3 (prvi član ima indeks 0, drugi indeks 1 itd.)

*/
#include <stdio.h>
int drugi (int p[], int n) {
    int i,max=0,I=0,drugi=0,isti=0;
    for(i=0; i<n; i++) {
        if (p[i]>max) max=p[i];
    }
    for(i=0; i<n; i++) {
        if (p[i]==max) isti=0;
        else {
            isti=1;
            break;
        }
    }
    for(i=0; i<n; i++) {
        if(p[i]>=drugi && p[i]!=max) {
            drugi=p[i];
            I=i;
        }
    }
    if (isti==0) return -1;
    else return I;
}
int main() {
    int i,n,niz[7];

    printf("Unesite niz brojeva: ");
    for(i=0;i<7;i++) scanf("%d",&niz[i]);
    printf("Indeks drugog po velicini je: %d",drugi(niz,7));
    return 0;
}
