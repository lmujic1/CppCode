/*
    TP 2018/2019: Tutorijal 5, Zadatak 7

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
#include <deque>
#include <stdexcept>
#include <string>
#include<vector>
template <typename Iterator>
auto SumaBloka(Iterator i1,Iterator i2) -> decltype (*i1+*i2) {
    if(i2-i1==0) throw std::range_error("Blok je prazan");
    decltype (*i1+*i2) suma(*i1);
    i1++;
    while(i1!=i2) {
        suma+=*i1;
        i1++;
    }
    return suma;
}
int main ()
{
    return 0;
}