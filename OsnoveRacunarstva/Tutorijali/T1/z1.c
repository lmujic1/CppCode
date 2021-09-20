//
// Created by 38760 on 18. 9. 2021..
//

/*
#include <stdio.h>
#define PI 3.14

int main()
{
    float R, P, V;

    // Unos poluprecnika sa tastature i izracunavanje

    printf (“\Unesite poluprecnik:”);
    scanf (“%f”, &R);
    P=(R*R)*PI;
    V=(4/3)*R*R*R*PI;

    // Ispis na monitoru
    printf(“\n Povrsina kruga sa poluprecnikom %  2f je %.2f”, R,P);

    printf(“\n Zapremina kugle sa poluprecnikom %2f je %.2f”, R,V);
    return 0;
}

*/
#include <stdio.h>
#define PI 3.14
int main() {
    float R, P, V;

    printf("\nUnesite poluprecnik: ");
    scanf("%f", &R);
    P=R*R*PI;
    V=(4./3)*R*R*R*PI;

    printf("\n Povrsina kruga sa poluprecnikom %.2f je %.2f",R,P);
    printf("\n Zapremina kugle sa poluprecnikom %.2f je %.2f", R, V);
    return 0;
}
