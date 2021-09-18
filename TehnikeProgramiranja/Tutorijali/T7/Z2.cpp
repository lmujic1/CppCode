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
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite recenice: "<<std::endl;
    char **pok(nullptr);
    try{
        pok=new char*[n];
    }
    catch(...) {
        delete [] pok;
        std::cout<<"Problemi s memorijom!";
        return 0;
    }

    try{

        for(int i=0;i<n;i++) {
            char pomocni[1000];
            std::cin.getline(pomocni,sizeof pomocni);
            pok[i]=new char[std::strlen(pomocni)+1];
            std::strcpy(pok[i],pomocni);
        }

        std::sort(pok,pok+n,[](const char *a,const char *b)->bool{return std::strcmp(a,b)<0;});

        std::cout<<"Sortirane recenice:"<<std::endl;
        for(int i=0; i<n; i++) {
            std::cout<<pok[i]<<std::endl;
        }
        std::cout<<std::endl;

        for(int i=0; i<n; i++) delete [] pok[i];
        delete [] pok;
    }
    catch(...) {
        for(int i=0;i<n;i++) delete [] pok[i];
        delete [] pok;
        std::cout<<"Problemi s memorijom!";

    }
    return 0;
}
