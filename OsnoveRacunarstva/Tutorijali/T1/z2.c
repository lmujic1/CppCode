//
// Created by 38760 on 18. 9. 2021..
//

/*
 Modificirajte prethodni program tako da program pored površine kruga i zapremine kugle sa poluprečnikom R
 izračunava i površinu lopte sa tim poluprečnikom.

Napomena: Površina lopte se računa po formuli:

P=4r2

gdje je r poluprečnik lopte.

*/
#include <stdio.h>
#define PI 3.14
int main() {
    float R, P, V, PL;

    printf("\nUnesite poluprecnik: ");
    scanf("%f", &R);
    P=R*R*PI;
    V=(4./3)*R*R*R*PI;
    PL=4*R*R*PI;
    printf("\n Povrsina kruga sa poluprecnikom %.2f je %.2f",R,P);
    printf("\n Zapremina kugle sa poluprecnikom %.2f je %.2f", R, V);
    printf("\n Povrsina lopte sa poluprecnikom %.2f je %.2f", R,PL);
    return 0;
}
