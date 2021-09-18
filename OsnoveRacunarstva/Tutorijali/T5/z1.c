#include <stdio.h>
#define BR_EL 10
int main() {

    int niz[BR_EL], suma=0,i,suma_parnih=0,broj_parnih=0,max,min;
    float prosjek,prosjek_parnih;
    for(i=0;i<BR_EL;i++) {
        /*uunos niza*/
        printf("Unesite %d. cijeli broj: ",i+1);
        scanf("%d",&niz[i]);
    }
    /*racunanje prosjeka*/
    for(i=0;i<BR_EL;i++) {
        suma+=niz[i];
        if(niz[i]%2==0) {
            suma_parnih+=niz[i];
            broj_parnih++;
        }
        if(i==0 || niz[i]>=max) {
            max=niz[i];
        }
        if(i==0 || niz[i]<=min) {
            min=niz[i];
        }
    }
    prosjek=(float)suma/BR_EL;
    if(broj_parnih!=0) prosjek_parnih=(float)suma_parnih/broj_parnih;
    else prosjek_parnih=0;

    printf("Srednja vrijednost unesenih brojeva je %.2f.\n",prosjek);
    printf("Srednja vrijednost parnih brojeva je %.2f.\n",prosjek_parnih);
    printf("Najveci element je %d a najmanji %d.",max,min);
    return 0;
}
