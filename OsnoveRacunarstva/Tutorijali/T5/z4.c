#include <stdio.h>

int main() {
    int n=0, brojac[101]={0},i;
    printf("Unesite brojeve: ");

    do{
        scanf("%d",&n);
        if(n<0 || n>100) printf("Brojevi moraju biti izmedju 0 i 100!");
        else brojac[n]++;
    }while(n!=-1);

    for(i=0;i<101;i++) {
        if(brojac[i]!=0) printf("\nBroj %d se javlja %d puta.",i,brojac[i]);
    }
    return 0;
}
