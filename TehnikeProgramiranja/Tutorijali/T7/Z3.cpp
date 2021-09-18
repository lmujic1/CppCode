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

int main ()
{
    std::cout<<"Koliko zelite recenica: ";
    int n;
    std::cin>>n;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite recenice:"<<std::endl;
    std::string **pok(nullptr);

    try{
        pok=new std::string *[n];
    }
    catch(...) {
        delete [] pok;
        std::cout<<"Problemi s memorijom!";
        return 0;
    }

    try{

        for(int i=0; i<n; i++) 	pok[i]=nullptr;

        for(int i=0;i<n;i++) {
            pok[i]=new std::string;
            std::getline(std::cin,*pok[i]);
        }

        std::sort(pok,pok+n,[](std::string *s1,std::string *s2){return *s1<*s2;});

        std::cout<<"Sortirane recenice:"<<std::endl;
        for(int i=0; i<n; i++) {
            std::cout<<*pok[i]<<std::endl;
        }
        std::cout<<std::endl;

        for(int i=0; i<n; i++) delete  pok[i];
        delete [] pok;
    }
    catch(...) {
        for(int i=0;i<n;i++) delete pok[i];
        delete [] pok;
        std::cout<<"Problemi s memorijom!";

    }
    return 0;
}
