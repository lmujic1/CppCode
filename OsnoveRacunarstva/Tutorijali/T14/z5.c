/*
U datoteku ispit.txt dodajte kolonu [brbod2] koja predstavlja broj bodova na drugom parcijalnom ispitu, dok je [brbod1] prvi parcijalni ispit. Dakle:
[ prezime          ] · · · · · · · [ ime       ] · · · · · [brbod1] [brbod2]

Zatim prepravite program tako da:
Struktura Student sadrži oba podatka koji se trebaju zvati broj_bodova1 i broj_bodova2.
U datoteku usmeni.txt (obratite pažnju da se datoteka sada zove drugačije!) upisuju se studenti koji su položili oba parcijalna ispita (na oba imaju 10 ili više bodova).
Datoteka usmeni.txt ima sljedeću strukturu:
[ prezime          ] · · · · · · · [ ime       ] · · · · · [ukupno]
gdje [ukupno] predstavlja zbir bodova na prvoj i drugoj parcijali.
Ova datoteka mora biti sortirana prema polju [ukupno] od većih prema manjim.

*/
#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */

struct Student {
    char prezime[20];
    char ime[15];
    int  broj_bodova1,broj_bodova2;
};

int main() {
    struct Student studenti[300], tmp;
    FILE *ulaz, *izlaz;
    int i, j, vel, max;

    /* Otvaranje datoteka */
    if ((ulaz = fopen("ispit.txt","r")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.txt");
        return 1;
    }

    if ((izlaz = fopen("usmeni.txt","w")) == NULL) {
        fclose(ulaz);
        printf("Greska pri otvaranju datoteke usmeni.txt");
        return 1;
    }

    /* Ucitavanje datoteke u niz studenti */
    i=0;

    while (i<300 && fscanf(ulaz,"%20s%15s%2d%2d%\n", studenti[i].prezime, studenti[i].ime, &studenti[i].broj_bodova1,&studenti[i].broj_bodova2) == 4)
        i++;
    vel = i;

    for(i=0;i<vel;i++) {
        if((studenti[i].broj_bodova1>=10 && studenti[i].broj_bodova1<=20) && (studenti[i].broj_bodova2>=10 && studenti[i].broj_bodova2<=20))
            studenti[i].broj_bodova1+=studenti[i].broj_bodova2;
        else {
            for(j=i;j<vel-1;j++) {
                studenti[j]=studenti[j+1];
            }
            i--;
            vel--;
        }
    }
    /* Sortiranje niza po broju bodova */
    for (i=0; i<vel; i++) {
        max = i;
        for (j=i+1; j<vel; j++)
            if (studenti[j].broj_bodova1 > studenti[max].broj_bodova1)
                max = j;

        tmp = studenti[i];
        studenti[i] = studenti[max];
        studenti[max] = tmp;
    }

    // Upis niza u datoteku
    for (i=0; i<vel; i++)
        fprintf(izlaz,"%-15s%-10s%-2d\n", studenti[i].prezime, studenti[i].ime, studenti[i].broj_bodova1);

    printf ("Izlazna datoteka usmeni.txt je kreirana\n");
    fclose(ulaz);
    fclose(izlaz);
    return 0;
}

