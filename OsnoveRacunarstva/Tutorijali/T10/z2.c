#include <stdio.h>
void unesi (char s[],int velicina) {
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i=0;
    while(i<velicina-1 && znak!='\n'){
        s[i]=znak;
        i++;
        znak=getchar();
    }
    s[i]='\0';
}


char *kapitaliziraj(char *s) {
    char *pocetak=s;
    while(*s!='\0') {
        if(s==pocetak || *(s-1)==' ') {
            if(*s>='a' && *s<='z') *s-='a'-'A';
        }
        s++;
    }
    return pocetak;
}

int main() {
    char s[100];
    printf("Unesite neki tekst: ");
    unesi(s,100);
    printf("%s",kapitaliziraj(s));
    return 0;
}
