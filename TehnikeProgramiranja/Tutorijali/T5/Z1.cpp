//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 2018/2019: Tutorijal 5, Zadatak 1

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
int main ()
{
    std::cout<<"Unesite recenicu: ";
    char recenica[1000];
    std::cin.getline(recenica,sizeof recenica);
    char *pok(recenica);
    while(*pok==' ') pok++;
    while(*pok!=' ' and *pok!='\0') pok++;
    while(*pok==' ') pok++;
    std::cout<<"Recenica bez prve rijeci glasi: ";
    while(*pok!='\0') {std::cout<<*pok; pok++;}
    std::cout<<std::endl;
    return 0;
}