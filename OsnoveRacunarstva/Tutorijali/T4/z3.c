/*
        X |   1   2   3   4   5   6   7   8   9  10
	----+----------------------------------------
	  1 |   1   2   3   4   5   6   7   8   9  10
	  2 |   2   4   6   8  10  12  14  16  18  20
	......

*/
#include <stdio.h>

int main() {
    int i,j;
    for(i=0;i<12;i++) {

        if(i==0) {
            printf("  X |");
            for(j=1;j<=10;j++) printf("%4d",j);
        }

        else if(i==1) {
            for(j=1;j<=45;j++) {
                if(j==5) printf("+");
                else printf("-");
            }
        }

        else {
            printf("%3d |",i-1);
            for(j=1;j<=10;j++) {
                printf("%4d", (i-1)*j);
            }
        }
        printf("\n");
    }
    return 0;
}
