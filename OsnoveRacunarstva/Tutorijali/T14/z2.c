#include <stdio.h>
#include <string.h>
struct Ispit {
    int brindexa,predmet,ocjena;
};
void unesi (char niz [], int velicina)
{
    char znak = getchar();
    int i=0;
    while (i<velicina-1 && znak != '\n') {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

int main ()
{
    char pred[100][100];
    int broj=0;
    int brojac=0;
    char znak;
    FILE *predmeti;
    predmeti =fopen("predmeti.txt","a+");
    while((znak=fgetc(predmeti))!=EOF) {
        if((znak>='A' && znak<='Z') || (znak>='a' && znak<='z')) {
            brojac=0;
            do {
                pred[broj][brojac]=znak;
                brojac++;
            } while ((znak=fgetc(predmeti))!='\n');
            pred[broj][brojac]='\0';
            broj++;
        }
    }
    fclose(predmeti);

    char unos[100];
    int postoji=0;
    int rez=0;
    int i=0;
    do {
        printf("Unesite predmet: ");
        unesi(unos,100);
        for(i=0; i<broj; i++) {
            rez=strcmp(pred[i],unos);
            if(rez==0) {
                postoji=1;
                break;
            }
        }
        if(!postoji) printf("Nepostojeci predmet!\n");
        else break;

    } while(1);

    i++;

    int uneseni_predmet=0,polozen_predmet=0,predmet,suma=0;
    double prosjek,prolaznost;
    struct Ispit indexi[1000];
    FILE *dat=fopen("ispiti.txt","a+");
    if(dat==NULL) {
        printf("Greska prilikom otvaranja datoteke ispiti.txt");
        return 1;
    }
    predmet=i;
    if(predmet>5) {printf("Zalimo, ali ne postoje podaci o predmetu %s!",pred[i-1]); return 0;}
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