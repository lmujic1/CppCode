/*
Napišite funkciju "obrnut" koja vraća primljeni pozitivan cijeli broj okrenut naopako. Npr. ako se funkcija pozove sa vrijednošću
12345 (dvanaest hiljada tristo četrdeset i pet), treba vratiti broj 54321 (pedeset četiri hiljade tristo dvadeset i jedan).
Pri tome nije dozvoljeno koristiti nizove niti raditi bilo kakav ispis u funkciji! Napravite i kraći program koji testira tu funkciju.

*/
#include <stdio.h>
#include <math.h>
int obrnut (int n) {
    int tmp,brojac=0;
    tmp=n;
    while(tmp!=0) {
        tmp/=10;
        brojac++;
    }
    tmp=0;
    while(n!=0) {
        brojac--;
        tmp+=n%10*pow(10,brojac);
        n/=10;
    }
    return tmp;
}

int main() {

    printf("%d",obrnut(12345));
    return 0;
}