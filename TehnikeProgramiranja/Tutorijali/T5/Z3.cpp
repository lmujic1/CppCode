//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 2018/2019: Tutorijal 5, Zadatak 3

	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.

	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.

			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <algorithm>
#include <cmath>

void Unesi(int &p) {
    std::cin>>p;
}

int Logaritam(int n) {
    if(n==0) return 1;
    return (log10(abs(n))+1);
}

int main ()
{
    std::cout<<"Unesite broj elemenata (max. 1000): ";
    int niz[1000],br_el;
    std::cin>>br_el;
    std::cout<<"Unesite elemente: ";
    std::for_each(niz,niz+br_el,Unesi);

    std::cout<<"Najveci element niza je "<<*(std::max_element(niz,niz+br_el))<<" ";
    std::cout<<std::endl<<"Najmanji element niza se pojavljuje "<<std::count(niz,niz+br_el,*(std::min_element(niz,niz+br_el)))<<" puta u nizu";
    std::cout<<std::endl<<"U nizu ima "<<std::count_if(niz,niz+br_el,[](int n){if(pow(n,1./2)==int(pow(n,1./2))) return true; return false;})<<" brojeva koji su potpuni kvadrati";
    std::cout<<std::endl<<"Prvi element sa najmanjim brojem cifara je "<<*(std::min_element(niz,niz+br_el,[](int x,int y) {if(Logaritam(x)<Logaritam(y)) return true; return false;}));

    int niz1[1000];
    int *p(std::remove_copy_if(niz,niz+br_el,niz1,[](int x){if(Logaritam(x)!=3) return false; return true;}));
    std::cout<<std::endl<<"Elementi koji nisu trocifreni su: ";
    std::for_each(niz1,p,[](int x)->void{std::cout<<x<<" ";} );
    return 0;
}