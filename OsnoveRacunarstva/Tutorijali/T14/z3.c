#include <stdio.h>
#include<string.h>


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

int main() {


    int i=0,uneseni_predmet=0,polozen_predmet=0,p,suma=0,broj,index,ima=0;
    float prosjek,prolaznost;
    struct Ispit indexi[1000];

    FILE *dat=fopen("ispiti.txt","a+");
    if(dat==NULL) {
        printf("Greska prilikom otvaranja datoteke ispiti.txt");
        return 1;
    }

    while(fscanf(dat,"%d %d %d",&indexi[i].brindexa,&indexi[i].predmet,&indexi[i].ocjena)==3) i++;
    fclose(dat);

    int vel=i;
    while(1) {
        printf("Unesite 1 za statistiku studenta, 2 za statistiku predmeta, 0 za izlaz: ");
        scanf("%d",&broj);
        if(broj==0) break;
        else if(broj==1) {
            uneseni_predmet=0;
            polozen_predmet=0;
            suma=0;
            printf("Unesite broj indexa: ");
            scanf("%d",&index);
            for(i=0;i<vel;i++) {
                if(indexi[i].brindexa==index) {
                    ima=1;
                    uneseni_predmet++;
                    suma+=indexi[i].ocjena;
                    if(indexi[i].ocjena>=6) polozen_predmet++;
                }
            }
            if(ima==0) printf("Zalimo, ali ne postoje podaci o studentu sa brojem indexa %d!\n",index);
            else {
                prosjek=(float)suma/uneseni_predmet;
                prolaznost=100-((uneseni_predmet-polozen_predmet)/(float)uneseni_predmet)*100;
                printf("Student je slusao %d predmeta, a polozio %d (%g%%).\nProsjecna ocjena polozenih predmeta je %.1lf\n",uneseni_predmet,polozen_predmet,prolaznost,prosjek);
            }
        }
        else if(broj==2) {

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
            printf("Unesite predmet: ");
            unesi(unos,100);
            for(i=0; i<broj; i++) {
                rez=strcmp(pred[i],unos);
                if(rez==0) {
                    break;
                }
            }
            //i++;
            p=i;
            uneseni_predmet=0;
            polozen_predmet=0;
            suma=0;
            for(i=0;i<vel;i++) {
                if(indexi[i].predmet==p) {
                    uneseni_predmet++;
                    suma+=indexi[i].ocjena;
                    if(indexi[i].ocjena>=6) polozen_predmet++;
                }
            }
            prosjek=(float)suma/uneseni_predmet;
            prolaznost=100-((uneseni_predmet-polozen_predmet)/(float)uneseni_predmet)*100;
            printf("Prosjecna ocjena: %.2lf\nProlaznost: %g%%\n",prosjek,prolaznost);
        }
    }
    return 0;
}
