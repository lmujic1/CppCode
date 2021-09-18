//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 2018/2019: Tutorijal 6, Zadatak 2

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iterator>
template <typename IterTip>
auto KreirajIzvrnutiNiz(IterTip p1,IterTip p2) -> typename std::remove_reference<decltype(*p1)>::type*{
    int velicina(0);
    IterTip tmp(p1);
    while(tmp!=p2){
        tmp++;
        velicina++;
    }
    //krahira se ukoliko pisemo p2-p1 jer zaodrezene tipove pok/it to nije podrzano
    typename std::remove_reference<decltype(*p1)>::type* pokazivac=new typename std::remove_reference<decltype(*p1)>::type[velicina];
    while(p1!=p2) {
        pokazivac[velicina-1]=*p1;
        p1++;
        velicina--;
    }
    return pokazivac;
}
int main ()
{
    std::cout<<"Koliko zelite elemenata: ";
    int broj;
    std::cin>>broj;
    std::vector<double> v;

    double *niz(nullptr);
    try{
        try {
            v.resize(broj);
        }
        catch(std::bad_alloc) {
            throw;
        }
        std::cout<<"Unesite elemente: ";
        std::for_each(v.begin(),v.end(),[](double &n)->void{std::cin>>n;});
        niz=KreirajIzvrnutiNiz(v.begin(),v.end());
        std::cout<<"Kreirani niz: ";
        for(int i=0;i<broj;i++) std::cout<<niz[i]<<" ";
        delete [] niz;
    }
    catch(std::bad_alloc) {
        std::cout<<"Nedovoljno memorije!";
    }
    catch (std::exception &izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    return 0;
}