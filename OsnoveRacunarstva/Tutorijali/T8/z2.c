/*Pascalov trougao*/
#include <stdio.h>

long faktorijel (int n) {
    int fact=1,i;
    for(i=1;i<=n;i++) fact*=i;
    return fact;
}

int pascal(int x,int y) {
    x--;
    y--;
    return faktorijel(x)/(faktorijel(y)*faktorijel(x-y));
}

int main() {
    int i,j,n;
    printf("Unesite n: ");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(i>=j) printf("%-4d",pascal(i+1,j+1));
        } printf("\n");
    }
    return 0;
}