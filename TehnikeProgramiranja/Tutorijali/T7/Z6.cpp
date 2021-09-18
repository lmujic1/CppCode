//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
//template <typename tip>
/*std::list<tip> SortirajListu (std::list<tip> s) {

*/

int main ()
{
    std::cout<<"Koliko elemenata ima: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente: ";
    std::list<int> lista;
    for(auto it=lista.begin();it<lista.begin(;it++) {
        int br;
        std::cin>>br;
        lista.insert(it,br);
    }
    return 0;
}


/*

Koliko ima elemenata: 5
Unesite elemente: 3 1 7 6 2
Sortirana lista: 1 2 3 6 7

Napišite generičku funkciju “SortirajListu” koja kao parametar prima neku listu (tj. objekat tipa
“list”) čiji su elementi proizvoljnog tipa, ali koji se mogu upoređivati pomoću operatora “<”. Funkcija
treba da kao rezultat vrati novu listu čiji su elementi isti kao u listi navedenoj kao parametar, ali
sortirani u rastući poredak. Pri tome, sortiranje treba obaviti “ručno”, ne koristeći nikakve bibliotečke
funkcije. Nije bitno da postupak sortiranja bude efikasan, bitno je samo da radi (sa znanjem koje
trenutno imate, nećete moći napisati ikakav iole efikasniji postupak). Funkciju demonstrirajte u
testnom programu koji će za listu cijelih brojeva unesenu sa tastature (broj elemenata se također
zadaje putem tastature) kreirati novu sortiranu listu i ispisati njen sadržaj na ekran. Dijalog između
programa i korisnika treba izgledati poput sljedečeg:

*/