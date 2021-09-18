/*
Data je sljedeća struktura podataka:

	struct Osoba {
		char ime[15];
		char prezime[20];
		int telefon;
	};

Napravite program koji sadrži niz od 100 osoba:

	struct Osoba imenik[100];

te omogućuje unos osobe ili ispis do sada unesenih osoba. Primjer ulaza i izlaza:

	Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: 1
	Unesite ime: Meho
	Unesite prezime: Mehic
	Unesite broj telefona: 123456
	Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: 2
	1. Meho Mehic, Tel: 123456
	Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: 0

Program treba sadržavati funkcije po uzoru na prethodne zadatke:
unos_osobe
ispis_osobe
Niz ne smije biti deklarisan kao globalna promjenljiva nego treba biti lokalan za funkciju main.

*/
#include <stdio.h>

struct Osoba {
    char ime[15];
    char prezime[20];
    int telefon;
};

void unesi (char niz[], int velicina) {
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i=0;
    while(i<velicina-1 && znak!='\n'){
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

struct Osoba unos_osobe(){
    struct Osoba o;
    printf("Unesite ime: ");
    unesi(o.ime,15);
    printf("Unesite prezime: ");
    unesi(o.prezime,20);
    printf("Unesite broj telefona: ");
    scanf("%d",&o.telefon);
    return o;
}

void ispis_osobe(struct Osoba o){
    printf("%s %s, Tel: %d",o.ime,o.prezime,o.telefon);
}

int main() {
    int i=0,n,broj_osoba;
    struct Osoba imenik[100];
    do {
        printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: ");
        scanf("%d",&n);
        if(n==1) {
            imenik[i]=unos_osobe();
            i++;
        }
        else if(n==2) {
            broj_osoba=i;
            for(i=0;i<broj_osoba;i++) {
                printf("\n%d. ",i+1);
                ispis_osobe(imenik[i]);
            }
            printf("\n");
        }

        else if(n==0) return 0;
    } while(n!=0);
    return 0;
}
