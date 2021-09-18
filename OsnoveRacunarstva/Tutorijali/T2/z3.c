#include <stdio.h>

int main() {
    int a,b,c;
    printf("Unesite tri broja: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a<50 || a>200)
        printf("Svi brojevi nisu iz intervala 50 do 200");
    else if(b<50 || b>200)
        printf("Svi brojevi nisu iz intervala 50 do 200");
    else if(c<50 || c>200)
        printf("Svi brojevi nisu iz intervala 50 do 200");
    else {
        printf("Brojevi poredani po velicini glase: ");

        if(a>=b && a>=c) {
            if(b>c) printf("%d,%d,",c,b);
            else printf("%d,%d,",b,c);
            printf("%d",a);
        }
        else if(b>=a && b>=c) {
            if(a>c) printf("%d,%d,",c,a);
            else printf("%d,%d,",a,c);
            printf("%d",b);
        }
        else if(c>=a && c>=b) {

            if(a>b) printf("%d,%d,",b,a);
            else printf("%d,%d,",a,b);
            printf("%d",c);
        }
        else printf("%d,%d,%d",a,b,c);

        if(a==b && b==c && a==c) printf("\nUnesen je 1 razlicit broj");
        else if(a==b && a!=c && b!=c) printf("\nUnesena su 2 razlicita broja");
        else if(a==c && a!=b && c!=b) printf("\nUnesena su 2 razlicita broja");
        else if(b==c && b!=a && c!=a) printf("\nUnesena su 2 razlicita broja");
        else printf("\nUnesena su 3 razlicita broja");
    }
    return 0;
}
