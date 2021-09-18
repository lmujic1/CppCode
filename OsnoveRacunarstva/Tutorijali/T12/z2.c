/*
*/
#include <stdio.h>
#define max 10

int provjera(char *s, char *pom) {
    int ima=1;
    char *pom1=pom,*pom2=pom;
    if(s==pom) return 0;
    while(pom1>=s) {
        if(*pom1!=' ') {
            ima=1;
            break;
        }
        else ima=0;
        pom1--;
    }

    if(ima) {
        while(*pom2!='\0') {
            if(*pom2!=' ') {
                ima=1;
                break;
            }
            else ima=0;
            pom2++;
        }
    }

    return ima;
}


char *tritacke(char *s) {
    int br_slova;
    char* beg=s,*b=NULL,*e=NULL;
    while(*s!='\0') {
        if(*s!=' '){
            b=s;
            e=s;
            br_slova=0;
            while(*e!=' ' && *e!='\0') {
                e++;
                br_slova++;
            }

            if(br_slova>=max && provjera(s,e)) {
                e=e-br_slova+3;
                *e++='.';
                *e='\0';
                break;
            }

            else if(br_slova>=max && !provjera(s,e)){
                b=b+3;
                *b++='.';
                *b++=' ';
                //s=b;
                e++;
                while(*e!='\0') {
                    *b=*e;
                    b++;
                    e++;
                }
                *b='\0';
                s--;
            }
        }
        s++;
    }
    return beg;
}

int main() {
    printf("Tutorijal 10, Zadatak 6");
    return 0;
}
