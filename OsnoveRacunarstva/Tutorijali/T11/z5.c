/*

char* whitespace(char* s)

koja u datom stringu zamjenjuje sve "whitespace" znakove jednim razmakom. Dakle, novi redovi (\n) i tabovi (\t)
trebaju biti zamijenjeni razmacima. Također, ukoliko se javlja više razmaka zaredom, treba ih zamijeniti jednim razmakom.
Whitespace znakove na početku ili kraju stringa treba izbaciti. Ovo uključuje i kombinacije razmak-tab ili novi red-razmak itd.
Funkcija treba vratiti pokazivač na prvi znak primljenog stringa radi lakšeg lančanog pozivanja. Napravite i kraći program koji
demonstrira korištenje ove funkcije.

U zadatku je zabranjeno korištenje funkcija iz biblioteke string.h.

*/
#include <stdio.h>
char *whitespace(char *s) {
    char *begin=s,*beg,*end,*pom1,*pom2;
    int ima=0;
    while(*s!='\0') {
        if(*s==' ' || *s=='\n' || *s=='\t') {
            beg=s;
            end=s;
            while(*end==' ' || *end=='\n' || *end=='\t') end++;
            pom1=beg;
            pom2=beg;
            while(pom1>=begin) {
                if(*pom1!=' ' && *pom1!='\n' && *pom1!='\t') {
                    ima=1;
                    break;
                }
                else ima=0;
                pom1--;
            }
            if(ima) {
                while(*pom2!='\0') {
                    if(*pom2!=' ' && *pom2!='\n' && *pom2!='\t') {
                        ima=1;
                        break;
                    }
                    else ima=0;
                    pom2++;
                }
            }

            if(ima) {
                *beg=' ';
                beg++;
            }

            while(*end!='\0') {
                *beg=*end;
                beg++;
                end++;
            }
            *beg='\0';
        }
        s++;
    }
    return begin;
}


int main() {
    printf("Tutorijal 10, Zadatak 4");
    return 0;
}
