/*
Napravite funkciju izbaci_rijec koja prima string koji predstavlja rečenicu i neki cijeli broj n,
a zatim iz rečenice izbacuje n-tu po redu riječ. Ako je n manje od jedan ili veće od broja riječi u stringu,
funkcija ne treba uraditi ništa. Radi lakšeg lančanog pozivanja, funkcija treba vraćati pokazivač na početak
primljenog stringa.

Riječ se u ovom zadatku definiše kao neprekinuti niz velikih i malih slova. Svaki drugi karakter u stringu
(tačka, zarez, minus itd.) smatraće se prekidom riječi. Npr. ako je dat string "Auto-Stop", smatraće se da
se on sastoji iz dvije riječi od po četiri slova. Znakove koji ne pripadaju riječi (razmaci i sl.) ne treba izbacivati.

Napišite i kraći glavni program koji demonstrira korištenje ove funkcije.

*/
#include <stdio.h>
char *izbaci_rijec(char *s,int n) {
    //pretpostavimo da je prvo na sta cemo naici prolaskom kroz string ustvari neki znak, te povecavamo broj rijeci i br postavljamo na 0 i sve dok ne naidjemo na sljedeci znak (koji nije slovo)
    int br=1,broj_rijeci=0;
    char *pocetak=s,*pom1,*pom2;
    while(*s!='\0') {
        if(!((*s>='A'&&*s<='Z')||(*s>='a'&&*s<='z'))) br=1;
        else if (br==1){
            br=0;
            broj_rijeci++;
            if(broj_rijeci==n) {
                pom1=s;
                pom2=s;
                while((*pom2>='A'&&*pom2<='Z')||(*pom2>='a'&&*pom2<='z')) pom2++;
                while(*pom2!='\0') {
                    *pom1=*pom2;
                    pom1++;
                    pom2++;
                }
                *pom1='\0';
                return pocetak;
            }
        }
        s++;
    }
    //if(n<1 || n>broj_rijeci) return pocetak;
    return pocetak;
}
int main() {
    char t[]="Tutorijal 10, Zadatak 3";
    printf("%s",izbaci_rijec(t,2));
    return 0;
}
