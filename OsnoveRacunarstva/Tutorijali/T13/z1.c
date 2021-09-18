/*
Data je sljedeća struktura:

	struct Vrijeme {
		int sati;
		int minute;
		int sekunde;
	};

Napišite funkciju unos_vremena koja omogućuje unos vrijednosti tipa struct Vrijeme, a zatim funkciju proteklo koja određuje koliko sekundi
je proteklo između dva vremena koja prima kao parametre v1 i v2. Obratite pažnju da ako je v1 ispred ili iza v2 funkcija treba u oba slučaja
vratiti pozitivan broj sekundi. U mainu treba omogućiti unos dva vremena, a zatim ispisati koliko sekundi je proteklo između njih koristeći
navedene dvije funkcije.

Primjer ulaza i izlaza:
	Unesite prvo vrijeme (h m s): 1 15 30
	Unesite drugo vrijeme (h m s): 2 30 15
	Izmedju dva vremena je proteklo 4485 sekundi.

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

int proteklo(struct Vrijeme v1,struct Vrijeme v2) {
    int broj_sekundi1=v1.sati*3600+v1.minute*60+v1.sekunde;
    int broj_sekundi2=v2.sati*3600+v2.minute*60+v2.sekunde;
    int broj_sekundi=0;
    broj_sekundi=broj_sekundi1-broj_sekundi2;
    if(broj_sekundi<0) broj_sekundi*=-1;
    return broj_sekundi;
}

int main() {
    struct Vrijeme v1,v2;
    printf("\nUnesite prvo vrijeme (h m s): ");
    v1=unos_vremena();
    printf("\nUnesite drugo vrijeme (h m s): ");
    v2=unos_vremena();
    printf("\nIzmedju dva vremena je proteklo %d sekundi.",proteklo(v1,v2));
    return 0;
}
