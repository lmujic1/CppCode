//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 2018/2019: Tutorijal 6, Zadatak 1

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
template <typename Tip>
Tip *GenerirajStepeneDvojke(Tip n) {
    if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
    unsigned long  int a(n);
    if((pow(2,a-1))>std::numeric_limits<Tip>::max()) throw std::overflow_error("Prekoracen dozvoljeni opseg");
    Tip *pokazivac(new Tip[a]);
    for(unsigned long long int i=0;i<a;i++) {
        pokazivac[i]=pow(2,i);
    }
    return pokazivac;
}
int main ()
{
    std::cout<<"Koliko zelite elemenata: ";
    int n;
    std::cin>>n;
    int *stepen2(nullptr);
    try{
        stepen2=GenerirajStepeneDvojke<int>(n);
        for(int i=0;i<n;i++) std::cout<<stepen2[i]<<" ";
        delete [] stepen2;
    }
    catch(std::domain_error poruka){
        std::cout<<"Izuzetak: "<<poruka.what();
    }
    catch(std::overflow_error poruka) {
        std::cout<<"Izuzetak: "<<poruka.what();
    }
    catch(std::runtime_error) {
        std::cout<<"Izuzetak: "<<"Alokacija nije uspjela";
    }
    catch(...) {
        std::cout<<"Izuzetak: "<<"Pogresan izuzetak";
    }
    return 0;
}