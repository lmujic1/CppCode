/*
Data je datoteka ispiti.txt čiji redovi imaju sljedeću strukturu:

brindexa predmet ocjena

gdje brindexa predstavlja broj indeksa studenta koji je polagao ispit, predmet je broj koji
označava predmet iz kojeg je upisana ocjena, a ocjena je konačna ocjena koju je student osvojio. Na primjer:

12345 3 10
12345 4 9
12233 4 10
13579 2 8
13579 3 8

Prvi red označava da je student sa brojem indexa 12345 iz predmeta broj 3 (npr. to mogu biti Osnove računarstva) dobio ocjenu 10 itd.
Ako je isti student položio više predmeta, jednostavno se dodaje još jedan red sa istim brojem indexa, ali drugim predmetom.

Kreirajte ovu datoteku i napunite je nekim testnim podacima. Zatim napravite program koji na ulazu traži broj predmeta, te ispisuje
prosječnu ocjenu i prolaznost (procenat studenata koji su položili tj. dobili ocjenu 6 ili više) . Primjer ulaza i izlaza je:

Unesite predmet: 4
Prosječna ocjena: 7.23
Prolaznost: 60%


*/
#include <stdio.h>
struct Ispit {
    int brindexa,predmet,ocjena;
};


int main() {
    int i=0,uneseni_predmet=0,polozen_predmet=0,predmet,suma=0;
    double prosjek,prolaznost;
    struct Ispit indexi[1000];
    FILE *dat=fopen("ispiti.txt","a+");
    if(dat==NULL) {
        printf("Greska prilikom otvaranja datoteke ispiti.txt");
        return 1;
    }
    printf("Unesite predmet: ");
    scanf("%d",&predmet);
    if(predmet>5) printf("Zalimo, ali ne postoje podaci o predmetu sa brojem %d!",predmet);
    while(fscanf(dat,"%d %d %d",&indexi[i].brindexa,&indexi[i].predmet,&indexi[i].ocjena)==3) {
        if(indexi[i].predmet==predmet) {
            uneseni_predmet++;
            suma+=indexi[i].ocjena;
            if(indexi[i].ocjena>=6) polozen_predmet++;
        }
        i++;
    }
    fclose(dat);
    prosjek=(double)suma/uneseni_predmet;
    prolaznost=100-((uneseni_predmet-polozen_predmet)/(double)uneseni_predmet)*100;
    printf("Prosjecna ocjena: %.2lf\nProlaznost: %g%%",prosjek,prolaznost);

    return 0;
}
