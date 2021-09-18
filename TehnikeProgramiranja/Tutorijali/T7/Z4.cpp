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
        std::unique_ptr<std::shared_ptr<std::string>[]> pok(new std::shared_ptr<std::string>[n]);
        try{
            for(int i=0;i<n;i++) {
                pok[i]=std::make_shared<std::string>();
                std::getline(std::cin,*pok[i]);
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(*pok[i]<*pok[j]) {
                        auto pom=pok[i];
                        pok[i]=pok[j];
                        pok[j]=pom;
                    }
                }
            }
            std::cout<<"Sortirane recenice:"<<std::endl;

            for(int i=0; i<n; i++) std::cout<<*pok[i]<<std::endl;
            std::cout<<std::endl;
        } catch(...) {
            std::cout<<"Problemi s memorijom!";
        }
    } catch(std::bad_alloc) {
        std::cout<<"Problemi s memorijom!";
    }
    return 0;
}
