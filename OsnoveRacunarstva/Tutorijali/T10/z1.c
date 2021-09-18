/*
U prethodnom programu dodajte funkciju samoglasnici koja će prebrojati broj samoglasnika u zadatoj riječi.
Prototip funkcije samoglasnici je:

                                int samoglasnici(char *s);

Ova funkcija treba uzimati u obzir i velika i mala slova. Zatim pri kraju main() funkcije umetnite
poziv funkcije samoglasnici tako da program na standardnom izlazu pored dužine riječi i broja pojavljivanja
nekog znaka ispiše i broj samoglasnika u unesenoj riječi.

Primjer ulaza i izlaza sada treba biti:
        Unesite jednu rijec do 80 znakova (ENTER za kraj):
        Otorinolaringologija
        Koji znak treba prebrojati: o
        Broj znakova o je: 4
        Broj samoglasnika je: 10

U ovom primjeru kod broja znakova o nije ubrojano početno veliko slovo O jer
funkcija prebroji koju smo dali iznad razlikuje velika i mala slova.

*/
#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int prebroji(char* s, char znak) {
    int broj = 0;
    while (*s != '\0') {

        if (*s == znak)
            broj++;
        s++;
    }
    return broj;
}

int samoglasnici(char *s) {
    int brojac=0;
    while(*s!='\0') {
        if(*s=='a' || *s=='A' || *s=='e' || *s=='E' || *s=='i' || *s=='I' || *s=='o' || *s=='O' || *s=='u' || *s=='U') brojac++;
        s++;
    }
    return brojac;
}

int main() {
    char a[80],c;
    printf ("\nUnesite jednu rijec do 80 znakova (ENTER za kraj):");
    unesi(a, 80);
    printf ("\nKoji znak treba prebrojati:");
    scanf ("%c", &c);
    printf ("\nBroj znakova %c je: %d\n",c,prebroji(a,c));
    printf("Broj samoglasnika je: %d",samoglasnici(a));
    return 0;
}
