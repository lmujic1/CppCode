/*
Prepravite prethodni program tako da određuje koliko sati, minuta i sekundi je proteklo između dva vremena. 
Funkcija proteklo treba vraćati struct Vrijeme. Na primjer:

	Unesite prvo vrijeme (h m s): 1 15 30
	Unesite drugo vrijeme (h m s): 2 30 15
	Izmedju dva vremena je proteklo: 1 sati, 14 minuta i 45 sekundi.

Ponovo obratite pažnju na situaciju kada je drugo vrijeme ispred prvog.

*/
#include <stdio.h>

struct Vrijeme {
    int sati;
    int minute;
    int sekunde;
};

struct Vrijeme unos_vremena() {
    struct Vrijeme v;
    scanf("%d %d %d",&v.sati,&v.minute,&v.sekunde);
    return v;
}

struct Vrijeme proteklo(struct Vrijeme v1,struct Vrijeme v2) {
    struct Vrijeme v3;
    int broj_sekundi1=v1.sati*3600+v1.minute*60+v1.sekunde;
    int broj_sekundi2=v2.sati*3600+v2.minute*60+v2.sekunde;
    int broj_sekundi=0;
    broj_sekundi=broj_sekundi1-broj_sekundi2;
    if(broj_sekundi<0) broj_sekundi*=-1;
    v3.sati=broj_sekundi/3600;
    v3.minute=broj_sekundi/60%60;
    v3.sekunde=broj_sekundi%60;
    return v3;
}

int main() {
    struct Vrijeme v1,v2;
    printf("\nUnesite prvo vrijeme (h m s): ");
    v1=unos_vremena();
    printf("\nUnesite drugo vrijeme (h m s): ");
    v2=unos_vremena();
    struct Vrijeme v3=proteklo(v1,v2);
    printf("\nIzmedju dva vremena je proteklo %d sati, %d minuta i %d sekundi.",v3.sati,v3.minute,v3.sekunde);
    return 0;
}