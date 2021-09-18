/*
 Sinus broja x može se izračunati koristeći Taylorov razvoj:



Potrebno je napraviti funkciju "sinus" koja na ovaj način računa sinus. Pored broja x čiji se sinus računa, ova funkcija treba imati i
parametar n koji određuje preciznost rješenja: veće n daje tačniju vrijednost sinusa, no obratite pažnju da faktorijel koji se nalazi u
nazivniku vrlo brzo raste tako da će kod dovoljno velikog n biti prekoračen opseg vrijednosti tipa int.

Pri rješavanju zadatka iskoristite funkciju pow iz biblioteke math.h, te funkciju faktorijel koju smo napravili u zadatku 3.21. Zatim
napravite program koji poredi tačnost ove funkcije i ugrađene funkcije sin(x) (u biblioteci math.h) za neke vrijednosti x i n unesene sa tastature.

Primjer ulaza i izlaza:
	Unesite x: 1
	Unesite n: 4
	sin(x)=0.841471
	sinus(x)=0.841468
	Razlika: 0.000003 (0.00%).

*/
#include <stdio.h>
#include <math.h>
long faktorijel (int n) {
    int fact=1,i;
    for(i=1;i<=n;i++) fact*=i;

    return fact;
}

double sinus (double x,int n) {
    int i;
    double s=0;
    for(i=1;i<=n;i++) {
        s+=(pow(-1,i-1)*pow(x,2*i-1))/faktorijel(2*i-1);
    }

    return s;
}
int main() {
    double x,razlika;
    int n;
    printf("Unesite x: ");
    scanf("%lf",&x);
    printf("\nUnesite n: ");
    scanf("%d",&n);
    printf("\nsin(x)=%lf\n",sin(x));
    printf("sinus(x)=%lf\n",sinus(x,n));
    razlika=fabs(sin(x)-sinus(x,n));
    printf("Razlika: %lf (%.2lf%%).",razlika,razlika*100);
    return 0;
}
