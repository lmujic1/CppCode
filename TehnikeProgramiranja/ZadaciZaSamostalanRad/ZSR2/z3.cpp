//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 4, Zadatak 3
#include <iostream>
/*Napišite funkciju koja prihvata vektor cijelih brojeva (tipa "int"), a koja kao rezultat vraća vektor
logičkih vrijednosti iste dimenzije, pri čemu je -ti element vektora koji se vraća kao rezultat logička
vrijednost “tačno” ukoliko se -ti element ulaznog vektora moža prikazati kao kub nekog prirodnog
broja (recimo 216 =

), a “netačno” u suprotnom. U slučaju da je neki od elemenata vektora
negativan treba baciti izuzetak tipa "domain_error" sa proizvoljnim tekstom. Napišite i kratki isječak
programa u kojem ćete testirati napisanu funkciju sa fiksnim vektorom od 10 proizvoljnih elemenata
tipa "int", pri čemu ćete ispisati elemente vraćenog vektora odvojene razmakom. Obavezno
predvidite hvatanje eventualno bačenih izuzetaka.*/

#include<vector>
#include<cmath>
#include<stdexcept>

bool Tstepen (int n) {
    for(int i=0;i<=std::sqrt(n);i++) {
        int x=pow(i,3);
        if(x==n) return true;

    }
    return false;
}

std::vector<bool> Stepen(std::vector<int> v) {
    std::vector<bool> v1;
    for(int i=0;i<v.size();i++) {
        if(v.at(i)<0) throw std::domain_error ("Negativan br");
        if(Tstepen(v.at(i))) v1.push_back(true);
        else v1.push_back(false);
    }

    return v1;
}

int main ()
{
    std::vector<int> v{1,3,4,5,6,7,9};
    std::vector<bool> v2(Stepen(v));
    for(int i=0;i<v2.size();i++) {
        std::cout<<std::boolalpha<<v2.at(i)<<" ";
    }
    return 0;
}
