/*
Modificirati prethodni program (zadatak 2.) tako da broj mjerenja nije konstantan (osam) nego se unosi sa tastature.

Da bi se ove funkcije mogle koristiti i u drugim programima, trebate proslijediti funkcijama broj mjerenja kao parametar,
npr. za funkciju maxtemp() prototip sada treba biti:
float maxtemp(float p[], int br);

*/
#include <stdio.h>
float maxtemp(float p[],int br) {
    float max;
    int i;
    max=p[0];
    for(i=0;i<br;i++) {
        if(p[i]>max) max=p[i];
    }
    return max;
}

float prtemp (float p[],int br) {
    float suma=0;
    int i;
    for(i=0;i<br;i++) suma+=p[i];
    return suma/br;
}
int main() {
    float temp[100];
    int i,n;
    printf("Unesite broj mjerenja: ");
    scanf("%d",&n);
    printf("Unesite temperature: ");
    for(i=0;i<n;i++) scanf("%f",&temp[i]);
    printf("Maksimalna temperatura: %.1f",maxtemp(temp,n));
    printf("\nProsjecna temperatura: %.1f",prtemp(temp,n));
    return 0;
}
