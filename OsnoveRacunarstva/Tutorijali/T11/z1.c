/*Modificirajte funkciju iz prethodnog zadatka tako da prima još jedan parametar:

int strcmpi(const char *s1, const char *s2, int velikamala);

Parametar velikamala je logička vrijednost koja određuje da li će se pri poređenju uzimati u
obzir razlika između velikih i malih slova (velika slova su abecedno ispred malih) ili ne.

*/
#include <stdio.h>

int strcmpi (const char *s1,const char *s2,int velikamala) {
    char tmp1,tmp2;
    while(*s1!='\0' && *s2!='\0') {
        tmp1=*s1;
        tmp2=*s2;
        if(!velikamala) {
            if(tmp1>='A'&&tmp1<='Z') tmp1+='a'-'A';
            if(tmp2>='A'&&tmp2<='Z') tmp2+='a'-'A';
        }
        if(tmp1>tmp2) return 1;
        else if(tmp1<tmp2) return -1;

        s1++;
        s2++;
    }
    if(*s1!='\0') return 1;
    else if(*s2!='\0') return -1;
    else return 0;
}

int main() {
    printf("Tutorijal 9, Zadatak 7");
    return 0;
}
