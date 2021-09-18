/*
Napišite funkciju pod nazivom rot13 koja vrši šifrovanje i ujedno dešifrovanje primljenog stringa po ROT13 algoritmu.

Pod pojmom “ROT13 algoritam” misli se na to da se svako slovo u primljenom tekstu zamjenjuje slovom
koje je udaljeno za 13 mjesta u engleskoj abecedi. Npr. slovo A se zamjenjuje slovom N, slovo B slovom O itd.
Ako se pri brojanju mjesta dođe do slova Z, brojanje se nastavlja od početka, pa se npr. slovo M zamjenjuje slovom Z,
a slovo N se zamjenjuje slovom A jer smo krenuli od početka abecede, slovo O se zamjenjuje slovom B itd.
Iz ovoga vidimo da ista funkcija radi i šifrovanje i dešifrovanje teksta pošto engleska abeceda ima tačno 26 slova.

Pazite da se u funkciji velika slova zamjenjuju velikim a mala malim, dok ostale znakove (razmake, brojeve itd.)
ostavljate nepromijenjenim. Radi lakšeg lančanog pozivanja, funkcija treba da vraća pokazivač na prvo slovo
primljenog stringa.

Napišite i glavni program u kojem se unosi string, poziva funkcija i zatim ispisuje (de)šifrovani string.

*/
#include <stdio.h>
char *rot13 (char* s){
    char *pocetak=s;
    while(*s!='\0') {
        if((*s>='A' && *s<='M')||(*s>='a' && *s<='m')) *s+=13;
        else if((*s>='N'&& *s<='Z')||(*s>='n' && *s<='z')) *s-=13;
        s++;
    }
    return pocetak;
}
int main() {
    char test[]="Tutorijal 10, Zadatak 2";
    printf("%s",rot13(test));
    return 0;
}
