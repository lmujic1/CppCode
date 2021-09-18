/*
Implementirajte funkciju strcmp() iz biblioteke string.h. Funkcija ima sljedeći prototip:

      int strcmp(const char *s1, const char *s2);

Funkcija vrši abecedno poređenje dva data stringa i vraća cjelobrojnu vrijednost:
-1 ako je prvi string abecedno ispred drugog,
0 ako su stringovi jednaki,
1 ako je prvi string abecedno iza drugog.

Ako su dva stringa različite dužine, a identični su do kraja kraćeg, smatra se da je kraći string
abecedno ispred dužeg.
*/
#include <stdio.h>
int strcmp (const char *s1,const char *s2) {
    while(*s1!='\0' && *s2!='\0') {
        if(*s1>*s2) return 1;
        else if(*s1<*s2) return -1;

        s1++;
        s2++;
    }
    if(*s1!='\0') return 1;
    else if(*s2!='\0') return -1;
    else return 0;
}
int main() {
    printf("Tutorijal 9, Zadatak 6");
    return 0;
}
