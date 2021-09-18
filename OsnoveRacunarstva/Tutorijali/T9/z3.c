/*
 Napišite funkciju sortiraj koja slaže po veličini niz realnih brojeva, pri čemu dimenzija niza nije unaprijed poznata nego predstavlja
 jedan od parametara funkcije. Napravite kratak glavni program koji testira ovu funkciju. Primjer algoritma za sortiranje nalazi se na početku Tutorijala 6.

Pri rješavanju zadatka obavezno koristiti pokazivačku aritmetiku.


*/
#include <stdio.h>
void sortiraj (double *n,int duzina) {
    double tmp;
    int i,j,max;
    for(i=0;i<duzina;i++) {
        max=i;
        for(j=i;j<duzina;j++){
            if(*(n+j)<*(n+max)) max=j;
        }
        tmp=*(n+i);
        *(n+i)=*(n+max);
        *(n+max)=tmp;
    }
}
int main() {
    printf("Tutorijal 8, Zadatak 6");
    return 0;
}
