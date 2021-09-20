#include <stdio.h>
#define BR_EL 10
int main() {
    int f;
    int niz[BR_EL], suma=0,i;
    float prosjek;
    for(i=0;i<BR_EL;i++) {
        /*uunos niza*/
        printf("Unesite %d. cijeli broj: ",i+1);
        scanf("%d",&niz[i]);
    }
    /*racunanje prosjeka*/
    for(i=0;i<BR_EL;i++)
        suma+=niz[i];

    prosjek=(float)suma/BR_EL;

    printf("Srednja vrijednost unesenih brojeva je %.2f.\n",prosjek);
    return 0;
}
