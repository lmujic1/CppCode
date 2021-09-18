#include <stdio.h>

int main() {

    double A[5],B[5];
    int i;

    printf("Unesite clanove niza A: ");
    for(i=0;i<5;i++) {
        scanf("%lf",&A[i]);
    }

    printf("Unesite clanove niza B: ");
    for(i=0;i<5;i++) {
        scanf("%lf",&B[i]);
    }

    printf("Niz A glasi: ");
    for(i=0;i<5;i++) {
        if(i==4) printf("%.2lf\n",A[i]);
        else printf("%.2lf, ",A[i]);
    }

    printf("Niz B glasi: ");
    for(i=0;i<5;i++) {
        if(i==4) printf("%.2lf\n",B[i]);
        else printf("%.2lf, ",B[i]);
    }

    printf("Niz C glasi: ");
    for(i=0;i<5;i++) {
        if(i==4) printf("%.2lf",2*A[i]+B[i]);
        else printf("%.2lf, ",2*A[i]+B[i]);
    }
    return 0;
}
