//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 16/17 (Tutorijal 7, Zadatak 1)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>
int main ()
{
    std::cout<<"Koliko zelite recenica: ";
    int n;
    std::cin>>n;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite recenice:"<<std::endl;
    try{
        std::shared_ptr<std::shared_ptr<std::string>> pok(new std::shared_ptr<std::string>[n]{},[](std::shared_ptr<std::string> *pok){delete []pok;});

        for(int i=0;i<n;i++) {
            pok.get()[i]=std::make_shared<std::string>();
            std::getline(std::cin,*(pok.get()[i]));
        }
        std::sort(pok.get(),pok.get()+n,[](std::shared_ptr<std::string> s1,std::shared_ptr<std::string> s2){return *s1<*s2;});
        std::cout<<"Sortirane recenice:"<<std::endl;

        for(int i=0; i<n; i++) std::cout<<*(pok.get()[i])<<std::endl;
        std::cout<<std::endl;
    } catch(std::bad_alloc) {
        std::cout<<"Problemi s memorijom!";
    }
    return 0;
}

