/*
Napišite funkciju ukloni_komentare koja iz datog stringa, koji predstavlja C kod, izbacuje sve komentare.
Funkcija treba da podržava komentare u C stilu:
     /* komentar
i u C++ stilu:
     // komentar.....
Pretpostavite da će komentari u C stilu biti uvijek propisno zatvoreni. Napravite i kraći program koji demonstrira korištenje ove funkcije.

U zadatku je zabranjeno korištenje funkcija iz biblioteke string.h.

*/
#include <stdio.h>
char * ukloni_komentare(char *s) {
    char *beg=s,*pom1,*pom2;
    while(*s!='\0') {
        if(*s=='/' && *(s+1)=='*') {
            pom1=s;
            pom2=pom1+2;

            while(!(*pom2=='*' && *(pom2+1)=='/') && *pom2!='\0') pom2++;
            if(*pom2=='*' && *(pom2+1)=='/') {
                pom2=pom2+2;

                while(*pom2!='\0') {
                    *pom1=*pom2;
                    pom1++;
                    pom2++;
                }
                *pom1='\0';
                s--;
            }
        }

        else if(*s=='/' && *(s+1)=='/') {
            pom1=s;
            pom2=s;
            while(*pom2!='\0' && *pom2!='\n') pom2++;
            if(*pom2=='\n' || *pom2=='\0') {
                while(*pom2!='\0') {
                    *pom1=*pom2;
                    pom1++;
                    pom2++;
                }
                *pom1='\0';
                s--;
            }
        }

        s++;
    }
    return beg;
}
int main() {
    printf("Tutorijal 10, Zadatak 5");
    return 0;
}
