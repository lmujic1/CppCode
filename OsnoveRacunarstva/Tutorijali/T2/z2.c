#include <stdio.h>

int main() {
    int d,m;
    printf("Dan: ");
    scanf("%d",&d);
    printf("Mjesec: ");
    scanf("%d",&m);
    printf("Vas znak je ");
    if((d>=20 && m==1) || (d<=18 && m==2)) printf ("Vodolija!");
    else if((d>=19 && m==2) || (d<=20 && m==3)) printf("Ribe!");
    else if((d>=21 && m==3) || (d<=19 && m==4)) printf("Ovan!");
    else if((d>=20 && m==4) || (d<=20 && m==5)) printf("Bik!");
    else if((d>=21 && m==5) || (d<=20 && m==6)) printf("Blizanci!");
    else if((d>=21 && m==6) || (d<=22 && m==7)) printf("Rak!");
    else if((d>=23 && m==7) || (d<=22 && m==8)) printf("Lav!");
    else if((d>=23 && m==8) || (d<=22 && m==9)) printf("Djevica!");
    else if((d>=23 && m==9) || (d<=22 && m==10)) printf("Vaga!");
    else if((d>=23 && m==10) || (d<=21 && m==11)) printf("Skorpija!");
    else if((d>=22 && m==11) || (d<=21 && m==12)) printf("Strijelac!");
    else printf("Jarac!");
    return 0;
}
