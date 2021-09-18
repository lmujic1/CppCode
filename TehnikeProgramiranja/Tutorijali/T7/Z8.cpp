//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 16/17 (Tutorijal 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
std::string IzvrniBezRazmaka (std::string s) {
    std::string pom;
    std::remove_copy(s.rbegin(),s.rend(),std::back_inserter(pom),' ');
    return pom;
}
int main ()
{
    return 0;
}

/*
Napišite funkciju “IzvrniBezRazmaka” koja kao parametar prima neki string, a kao rezultat vraća
taj string izvrnut naopačke, sa izbačenim razmacima (tj. ako je ulaz string “Evo pada kiša”, izlazni
rezultat treba da bude string “ašikadapovE”). Pri tome, funkcija treba da ima samo tri naredbe, od
kojih je prva deklariranje pomoćnog stringa, a treća naredba “return”, tako da sva “logika” funkcije
treba biti izvedena u jednoj jedinoj (drugoj) naredbi. Uputa: poslužite se funkcijom “remove copy”,
zatim obrnutim iteratorima te umetačima (inserterima). Napišite i kratki testni program u kojem
ćete testirati napisanu funkciju.
*/