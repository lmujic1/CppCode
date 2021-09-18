//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>

template <typename t>
std::set<t> Unija (std::set<t> s1,std::set<t> s2) {
    for(t x:s2) s1.insert(x);
    return s1;
}

template <typename t>
std::set<t> Presjek(std::set<t> s1,std::set<t> s2) {
    std::set<t> novi;
    for(auto x:s1) {
        for(auto y:s2) {
            if(x==y) novi.insert(x);
        }
    }
    return novi;
}

int main ()
{
    return 0;
}

/*
Napišite generičke funkcije “Unija” i “Presjek” koje kao parametre primaju dva skupa (tj. objekta
tipa “set”) proizvoljnog ali istog tipa elemenata, i koje kao rezultat daju novi skup koji predstavlja
njihovu uniju, odnosno presjek. Napisane funkcije demonstrirajte u testnom programu koji nalazi
uniju i presjek dva fiksna skupa čiji su elementi stringovi
*/