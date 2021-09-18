/*
Napišite funkciju zamijeni koja vrši zamjenu dva cijela broja. Npr. ako je funkcija pozvana sa varijablama a=3 i b=5, nakon poziva funkcije vrijednosti tih varijabli trebaju biti a=5 i b=3.
*/
#include <stdio.h>
void zamijeni(int *a, int*b) {
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
int main() {
    printf("Tutorijal 8, Zadatak 7");
    return 0;
}
