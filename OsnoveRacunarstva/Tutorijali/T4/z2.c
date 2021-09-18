#include <stdio.h>

int main() {
    int a,b,i,j;
    printf("Unesite stranice pravougaonika a,b: ");
    scanf("%d,%d",&a,&b);
    for(i=1;i<=b;i++) {
        for(j=1;j<=a;j++) {
            if(i==1 || i==b) {
                if(j==1 || j==a) printf("+");
                else printf("-");
            }
            else if(i>=2 && i<=b-1) {
                if(j==1 || j==a) printf("|");
                else printf(" ");
            }

        }
        printf("\n");
    }
    return 0;
}
