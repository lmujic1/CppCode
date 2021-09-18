//TP 2017/2018: Tutorijal 2, Zadatak 2
/*
Za slijed brojeva , , …, kažemo da ima period ukoliko je 1 ≤ < i ukoliko vrijedi da je
 = za sve vrijednosti za koje ova jednakost ima smisla (tj. za koju su oba indeksa i +
legalni). Na primjer, slijed brojeva 1, 3, 1, 4, 2, 1, 3, 1, 4, 2, 1, 3 ima period 5, jer je = za sve
vrijednosti takve da su oba indeksa i + 5 unutar dozvoljenog opsega (tj. za od 1 do 7 uključivo).
Isti slijed također ima i period 10. Dalje, za slijed brojeva kažemo da je periodičan ukoliko postoji
makar jedan broj koji je period tog slijeda, pri čemu najmanji takav broj nazivamo osnovni
period slijeda. Ukoliko takav broj ne postoji, slijed nije periodičan. Na primjer, gore navedeni
slijed brojeva je periodičan s osnovnim periodom 5, dok slijed brojeva 4, 5, 1, 7, 1, 5 nije periodičan.
Vaš zadatak je da napišete dvije funkcije “TestPerioda” i “OdrediOsnovniPeriod”.

Prva funkcija
prima dva parametra, pri čemu je prvi parametar vektor realnih brojeva, dok je drugi parametar cijeli
broj . Funkcija treba da vrati kao rezultat logičku vrijednost “tačno” ili “netačno” ovisno od toga da
li slijed brojeva pohranjen u vektoru periodičan sa periodom ili ne.

Druga funkcija prima samo
jedan parametar koji je vektor realnih brojeva, a ona kao rezultat vraća osnovni period slijeda
pohranjenog u vektoru ukoliko je slijed periodičan, ili nulu ukoliko slijed nije periodičan. To ćete
najlakše izvesti tako što ćete iz druge funkcije pozivati prvu funkciju kao pomoćnu, a kako to tačno
izvesti, ostavlja Vam se za razmišljanje.

Napisane funkcije iskoristite u glavnom programu u kojem
ćete unositi elemente sa tastature u neki vektor sve dok se sa tastature ne unese nula, koja
označava kraj unosa (tu nulu ne treba smjestiti u vektor). Nakon završetka unosa, program poziva
funkciju “OdrediOsnovniPeriod” sa ciljem da utvrdi da li se elementi periodično ponavljaju ili ne,
nakon čega ispisuje odgovarajuči komentar na ekranu (informaciju o dužini perioda, ili da elementi
ne čine periodičan slijed). Napomenimo da nije unaprijed poznato koliko će korisnik unijeti elemenata
prije nego što unese nulu kao oznaku završetka unosa. Dijalozi između korisnika i programa trebali
bi izgledati poput sljedećih (ovisno da li je slijed periodičan ili ne):

Unesite slijed brojeva (0 za kraj): 1 3 1 4 2 1 3 1 4 2 1 3 0
Slijed je periodican sa osnovnim periodom 5.
Unesite slijed brojeva (0 za kraj): 4 5 1 7 1 5 0
Slijed nije periodican!
*/
#include <iostream>
#include <vector>
bool TestPerioda (std::vector<double> vektor, int n) {
    if(n<=0 || vektor.size()<=n) return false;
    for(int i=0;i<vektor.size()-n;i++) {
        if(vektor.at(i)!=vektor.at(i+n)) return false;
    }
    return true;
}


int OdrediOsnovniPeriod(std::vector<double> vektor) {
    for(int i=0;i<vektor.size();i++) {
        if(TestPerioda(vektor,i)!=0) return i;
    }
    return 0;
}
int main ()
{
    std::cout<<"Unesite slijed brojeva (0 za kraj): ";
    std::vector<double> vektor;
    double n;
    do {
        std::cin>>n;
        if(n==0) break;
        vektor.push_back(n);
    } while(n!=0);
    if(OdrediOsnovniPeriod(vektor)) std::cout<<"Slijed je periodican sa osnovnim periodom "<<OdrediOsnovniPeriod(vektor)<<".";
    else std::cout<<"Slijed nije periodican!";
    return 0;
}
