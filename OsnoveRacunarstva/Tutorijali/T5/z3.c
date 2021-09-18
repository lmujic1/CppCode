#include <stdio.h>

int main() {
    int n,brojac[3]={0};
    printf("Unesite brojeve: ");
    do {
        scanf("%d",&n);
        if(n%5==0) brojac[0]++;
        if(n%7==0) brojac[1]++;
        if(n%11==0) brojac[2]++;
    } while(n!=-1);
    printf("\n");
    printf("Djeljivih sa 5: %d\n", brojac[0]);
    printf("Djeljivih sa 7: %d\n",brojac[1]);
    printf("Djeljivih sa 11: %d\n",brojac[2]);
    return 0;
}
