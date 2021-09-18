/*
Napravite program "Snijeg" koji, za uneseni broj n, na ekranu iscrtava uzorak od n×n zvjezdica koja su
naizmjenično razmaknute sa po jednim razmakom.

Primjer ulaza i izlaza programa

Unesite broj n: 5
	* * * * *
	 * * * * *
	* * * * *
	 * * * * *
	* * * * *

*/

#include <stdio.h>

int main() {
    int i,j,n;
    printf("Unesite broj n: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        if(i%2==0) printf(" ");
        for(j=1;j<=n;j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
