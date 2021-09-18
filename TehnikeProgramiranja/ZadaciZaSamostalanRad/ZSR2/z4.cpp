//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 4, Zadatak 4 primjer 2 zadatak 8
/*Zadatak 8 (2,5 poena)
Neka je dat slijed brojeva , , …, koji se sastoji od neparnog broja elemenata (tj. je neparan
broj). Za neki element tog slijeda kažemo da je njegov medijan ukoliko postoji podjednako mnogo
elemenata u tom slijedu koji su veći ili jednaki od njega i koji su manji ili jednaki od njega (tj. koji bi
se, u slučaju da slijed sortiramo, našao tačno na sredini sortiranog slijeda). Inače, definicija medijana
se može proširiti i za slijedove sa parnim brojem elemenata, ali to nas u ovom zadatku ne zanima.
Napravite funkciju koja kao parametar prima dek cijelih brojeva koji sadrži slijed čiji medijan
tražimo, a koja kao rezultat vraća nađeni medijan. Pri tome funkcija ne smije vršiti sortiranje deka, niti
koristi pomoćne kontejnerske tipove podataka. Možete pretpostaviti da će dek imati neparan broj
elemenata (i tu pretpostavku ne trebate provjeravati u funkciji). Međutim, trebate odgovoriti na
pitanje šta će Vaša funkcija (koju ste napisali) vratiti kao rezultat ukoliko joj se ponudi dek koji ima
paran broj elemenata (odgovor na ovo pitanje nosi 0.5 poena).*/

#include <iostream>
#include <deque>

int Medijan(std::deque<int> d) {


    for(int i=0;i<d.size();i++) {
        int el(d.at(i));
        for(int j=i+1;j<d.size();j++){
            int v(0),m(0);
            if(d.at(j)>=el) v++;
            else if(d.at(j)<=el) m++;
            if(v==m) return el;
            else continue;
        }}

}
int main ()
{
    return 0;
}
