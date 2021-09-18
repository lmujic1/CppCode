/*
Napišite funkciju zaokruzi koja kao parametar prima niz proizvoljne dužine sastavljen od realnih brojeva dvostruke preciznosti, a zatim sve brojeve u nizu zaokružuje na jednu decimalu.

*/
#include <stdio.h>
#include <math.h>
void zaokruzi (double *n, int duzina) {
    int i;
    for(i=0;i<duzina;i++)
        *(n+i)=round((*(n+i))*10)/10;
}
int main() {
    return 0;
}
