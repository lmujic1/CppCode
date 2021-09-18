//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 2018/2019: Tutorijal 5, Zadatak 5

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
#include <cmath>
#include <iomanip>
double TrapeznoPravilo(double f(double),double a,double b,int n) {
    double suma(0);
    for(int i=1;i<n;i++) {
        suma+=f(a+(((b-a)/n)*i));
    }
    return ((b-a)/n)*(0.5*f(a)+0.5*f(b)+suma);
}
int main ()
{
    std::cout<<"Unesite broj podintervala: ";
    int broj;
    std::cin>>broj;
    std::cout<<"Za taj broj podintervala priblizne vrijednosti integrala iznose:";
    std::cout<<std::endl<<"- Za funkciju sin x na intervalu (0,pi): "<<std::fixed<<std::setprecision(5)<<TrapeznoPravilo(std::sin,0,4*atan(1),broj);
    std::cout<<std::endl<<"- Za funkciju x^3 na intervalu (0,10): "<<std::setprecision(2)<<TrapeznoPravilo([](double x){return x*x*x;},0,10,broj);
    std::cout<<std::endl<<"- Za funkciju 1/x na intervalu (1,2): "<<std::setprecision(5)<<TrapeznoPravilo([](double x){return 1/x;},1,2,broj);

    return 0;
}