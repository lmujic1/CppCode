//
// Created by 38760 on 18. 9. 2021..
//

/*
Napravite program koji učitava potrošnju električne energije u kWh (velika tarifa (VT) i mala tarifa (MT)) i pripadajuće
cijene po kWh (cijena za malu tarifu i cijena za veliku tarifu). Izlaz programa treba biti:
ukupna potrošnja u kWh;
novčani iznos računa;
udio velike tarife i male tarife u ukupnoj potrošnji.

Primjer: ako su dati ulazi: VT=58.56, MT=175.68, cijena VT=0.3, cijena MT=0.2, izlaz programa glasi:

	Ukupna potrosnja je 234.24 KWh.
	Udio velike tarife u ukupnoj potrosnji je 25%.
	Udio male tarife u ukupnoj potrosnji je 75%.
	Iznos racuna je 52.70 KM.

*/
#include <stdio.h>

int main() {
    float VT, MT, cVT, cMT;
    int uvt,umt;
    printf("Unesite potrosnju velike tarife (u kWh) i cijenu za veliku tarifu (u KM): ");
    scanf("%f,%f", &VT, &cVT);
    printf("Unesite potrosnju male tarike (u kWh) i cijenu za malu tarifu (u KM): ");
    scanf("%f,%f", &MT, &cMT);
    printf("\nUkupna potrosnja je %.2f KWh", VT+MT);
    uvt=(VT/(VT+MT))*100;
    umt=(MT/(VT+MT))*100;
    printf("\nUdio velike tarife u ukupnoj potrosnji je %d%%.", uvt);
    printf("\nUdio male tarife u ukupnoj potrosnji je %d%%.",umt);
    printf("\nIznos racuna je %.2f KM.", VT*cVT+MT*cMT);
    return 0;
}
