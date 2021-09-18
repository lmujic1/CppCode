//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: Tutorijal 3, Zadatak 1
/*
Napišite funkciju “IzdvojiElemente” sa dva parametra, od kojih je prvi vektor cijelih brojeva (tipa
“int”), a drugi logička vrijednost “tačno” ili “netačno”. Funkcija treba da kao rezultat vrati novi vektor
koji se sastoji od onih elemenata čija je suma cifara parna odnosno neparna, ovisno od toga da li drugi
parametar ima vrijednost “tačno” ili “netačno”. Elementi u novokreiranom vektoru trebaju biti u
istom međusobnom poretku u kakvom su bili u izvornom vektoru. Za realizaciju funkcije obavezno
koristite funkciju “push_back”. Napisanu funkciju iskoristite u testnom programu koji traži da se prvo
unese prirodan broj , a nakon toga elementi vektora “a” koji ima cjelobrojnih elemenata. Program
zatim treba da kreira dva nova vektora “b” i “c”, i da u vektor “b” prepiše sve brojeve iz vektora “a” sa
parnom sumom cifara, a u vektor “c” sve brojeve iz vektora “a” sa neparnom sumom cifara. Konačno,
program treba da u jednom redu ispiše brojeve sa parnom sumom cifara, a u drugom redu brojeve sa
neparnim brojem cifara (moguće je da neki red ostane prazan, ukoliko nema niti jedan broj sa
traženim svojstvom). Mogući dijalozi između programa i korisnika trebaju izgledati ovako:
Za sve manipulacije sa vektorima koristite isključivo rasponsku for-petlju, osim za unos elemenata (u
ovom trenutku još ne znate kako koristiti rasponsku for-petlju za unos, jer Vam za to trebaju
reference). Možete pretpostaviti da će svi ulazni podaci biti korektni.

*/

#include <iostream>
#include <vector>
std::vector<int> IzdvojiElemente(std::vector<int> vektor, bool parna) {
    std::vector<int> novi;
    for(int x : vektor) {
        int tmp(x),suma(0);
        if(x<0) tmp*=-1;
        while(tmp!=0) {
            suma+=tmp%10;
            tmp/=10;
        }
        if(suma%2!=parna) novi.push_back(x);
    }
    return novi;
}

int main ()
{
    int n;
    std::vector<int> V;
    int x;
    std::cout<<"Koliko zelite unijeti elemenata: ";
    std::cin>>n;

    if(n<=0) {
        std::cout<<"Broj elemenata mora biti veci od 0!";
        return 0;
    }
    else {
        std::cout<<"Unesite elemente: ";
        for(int i=0; i<n; i++) {
            std::cin>>x;
            V.push_back(x);
        }

        std::vector<int> B(IzdvojiElemente(V,true));
        std::vector<int> C(IzdvojiElemente(V,false));

        for(int i : B) {
            std::cout<<i<<" ";
        }

        std::cout<<std::endl;

        for(int i : C) {
            std::cout<<i<<" ";
        }
    }
    return 0;
}