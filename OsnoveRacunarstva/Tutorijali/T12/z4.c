/*
Napišite funkciju sa prototipom:

                                int prva_rijec(char *s);

koja string zamjenjuje prvom riječi u stringu. Npr. ako je dat string:
	"Danas je lijep dan."
funkcija ga treba pretvoriti u:
	"Danas"
Funkcija vraća broj riječi u polaznom stringu (prije odsijecanja ostalih riječi).

Radi jednostavnosti zadatka, pretpostavite da je riječ bilo koji niz znakova razdvojen znakom razmak.
Za vježbu možete napraviti složenija pravila za riječi uzimajući u obzir znakove interpunkcije.

*/
#include <stdio.h>

int prva_rijec(char *s) {
    int broj_rijeci=0,brojac=0;
    while(*s!='\0') {
        if((*s==' ' || *(s+1)=='\0')&&(*(s+1)!=' ')) broj_rijeci++;
        if(brojac==0){
            while(*s==' ') s++;
            brojac=1;
        }
        else if(*s==' ') *s='\0';
        s++;
    }
    return broj_rijeci;
}

int main() {
    char recenica[]="     Danas je lijep dan.";
    printf("%s",recenica);
    printf("\n%d",prva_rijec(recenica));
    printf("\n%s",recenica);
    return 0;
}
