/*
Napraviti program koji sa standardnog ulaza učitava godinu i mjesec kao cijele brojeve,
a potom ispisuje naziv tog mjeseca i broj dana u mjesecu. Pretpostaviti da je prestupna svaka četvrta godina,
iako je pravilo za računanje prestupnih godina nešto složenije. Pri rješavanju zadatka koristiti switch-case programsku strukturu.

Primjeri ulaza i izlaza:
	Unesite mjesec: 2
Unesite godinu: 2004
Februar 2004, broj dana: 29

	Unesite mjesec: 5
Unesite godinu: 2015
Maj 2015, broj dana: 31

*/
#include <stdio.h>

int main() {
    int mjesec,godina;
    printf("Unesite mjesec: ");
    scanf("%d",&mjesec);
    printf("Unesite godinu: ");
    scanf("%d",&godina);
    //prestupna=(((godina%100==0) && (godina%400==0))||(godina%4==0));
    switch (mjesec) {
        case 1:
            printf("Januar %d, broj dana: 31", godina);
            break;
        case 2:
            if(((godina%100) && (godina%400)) || (godina%4==0)) printf("Februar %d, broj dana: 29", godina);
            else printf("Februar %d, broj dana: 28", godina);
            break;
        case 3:
            printf("Mart %d, broj dana: 31", godina);
            break;
        case 4:
            printf("April %d, broj dana: 30", godina);
            break;
        case 5:
            printf("Maj %d, broj dana: 31", godina);
            break;
        case 6:
            printf("Juni %d, broj dana: 30", godina);
            break;
        case 7:
            printf("Juli %d, broj dana: 31", godina);
            break;
        case 8:
            printf("Avgust %d, broj dana: 31", godina);
            break;
        case 9:
            printf("Septembar %d, broj dana: 30", godina);
            break;
        case 10:
            printf("Oktobar %d, broj dana: 31", godina);
            break;
        case 11:
            printf("Novembar %d, broj dana: 30", godina);
            break;
        case 12:
            printf("Decembar %d, broj dana: 31", godina);
            break;
    }
    return 0;
}
