/*
Napisati program koji učitava matricu cijelih brojeva dimenzija 10x10 te pronalazi najmanji element na glavnoj dijagonali.

*/
#include <stdio.h>

int main() {
    int i,j,min,mat[10][10];
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            scanf("%d",&mat[i][j]);

    min=mat[0][0];

    for(i=0;i<10;i++) {
        if(mat[i][i]<min) min=mat[i][i];
    }

    printf("%d",min);
    return 0;
}
