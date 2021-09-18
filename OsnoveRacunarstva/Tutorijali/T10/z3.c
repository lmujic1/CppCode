/*
Napišite funkciju max_slovo koja prima string a vraća (veliko) slovo koje se najviše puta pojavljuje u stringu.
Funkcija ne treba razlikovati velika i mala slova. Ukoliko se više slova ponavlja isti broj puta, treba vratiti
najmanje takvo slovo. Znakovi koji nisu slova nas ne zanimaju.

Primjer: Ako string glasi:
	"Ovo je probni primjer."
Funkcija treba vratiti slovo O jer se ono pojavljuje tri puta u stringu a manje je od slova R koje se također
pojavljuje tri puta.

*/
#include <stdio.h>

char max_slovo(char *s) {
    int i,brojac[91]={0},pozicija1,tmp,max=0;
    while(*s!='\0') {
        if(*s>='A' && *s<='Z') {
            tmp=*s;
            brojac[tmp]++;
        }
        else if(*s>='a' && *s<='z') {
            tmp=*s;
            tmp-='a'-'A';
            brojac[tmp]++;
        }
        s++;
    }
    for(i='A';i<='Z';i++) {
        if(brojac[i]>max) {
            max=brojac[i];
            pozicija1=i;
        }
    }
    return pozicija1;
}

int main() {
    //char s[]="Ovo je probni primjer.";
    printf("Lejla voli Tarika najvise na svijetu.");
    printf("\n%c",max_slovo("Lejla voli Tarika najvise na svijetu."));
    return 0;
}
