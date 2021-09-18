/*
Napravite funkciju

int prost(int x)

koja vraća 1 (logička istina) ako je broj x prost, a 0 (logička neistina) ako x nije prost.
Zatim iskoristite ovu funkciju u programu koji ispisuje sve proste brojeve između 1 i 100 (svaki broj u zasebnom redu).
*/
#include <stdio.h>

int prost (int x) {
    int i,brojac=1;
    for(i=2;i<x;i++) if(x%i==0) brojac++;
    if(brojac>1 || x==1) return 0;
    else return 1;
}

int main() {
    int i;
    for(i=1;i<100;i++) {
        if(prost(i)) printf("%d\n",i);
    }
    return 0;
}
