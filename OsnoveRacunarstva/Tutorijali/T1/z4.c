//
// Created by 38760 on 18. 9. 2021..
//

/*
Zadato je geometrijsko tijelo koje izgleda kao na slici 1. Odredite koji su potrebni ulazni podaci u program,
te napravite program koji izračunava površinu i zapreminu tog geometrijskog tijela. U zadatku za broj π koristite
simboličku konstantu odnosno naredbu #define.

Primjer izlaza koji program treba da daje je:

	Povrsina tijela sa slike je 5.234 cm2.
	Zapremina tijela sa slike je 16.200 cm3.

*/
#include <stdio.h>
#define PI 3.14
int main() {
    double a,b,c,h,r,P,V;
    printf("Unesite dimenzije kvadra sa slike: ");
    scanf("%lf,%lf,%lf", &a,&b,&c);
    printf("\nUnesite visinu i poluprecnik valjka sa slike: ");
    scanf("%lf,%lf", &h, &r);
    P=2*a*b+2*a*c+2*b*c+2*PI*r*h;
    V=a*b*c+r*r*PI*h;
    printf("\nPovrsina tijela sa slike je %.3f",P);
    printf("\nZapremina tijela sa slike je %.3f", V);
    return 0;
}
