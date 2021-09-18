//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 2018/2019: Tutorijal 6, Zadatak 5

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <vector>
#include <deque>

template <typename Kontejner>
auto KreirajDinamickuKopiju2D (Kontejner k) -> typename std::remove_reference<decltype(k[0][0])>::type** {
    try{
        typename std::remove_reference<decltype(k[0][0])>::type** pok=new typename std::remove_reference<decltype(k[0][0])>::type *[k.size()]{};
        try{
            for(int i=0;i<k.size();i++) {
                pok[i]=new typename std::remove_reference<decltype(k[0][0])>::type [k[i].size()];
            }
            for(int i=0;i<k.size();i++) {
                for(int j=0;j<k[i].size();j++) {
                    pok[i][j]=k[i][j];
                }
            }
        }
        catch(...) {
            for(int i=0;i<k.size();i++) delete []pok[i];
            delete [] pok;
            throw;
        }
        return pok;
    }
    catch(...) {
        throw;
    }
}

int main ()
{
    std::cout<<"Unesite broj redova kvadratne matrice: ";
    int n;
    std::cin>>n;

    try {
        std::vector<std::deque<int>> v;
        try{
            v.resize(n);
            try {
                for(int i=0;i<n;i++) v[i].resize(n);
            }
            catch(std::bad_alloc) {
                throw;
            }
        }
        catch(std::bad_alloc){
            throw;
        }
        int k;

        std::cout<<"Unesite elemente matrice: ";
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                std::cin>>k;
                v[i][j]=k;
            }
        }

        int **a(KreirajDinamickuKopiju2D(v));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                std::cout<<a[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        for(int i=0;i<n;i++) delete[] a[i];
        delete [] a;
    }
    catch (std::bad_alloc) {
        std::cout << "Nedovoljno memorije";
    }

    return 0;
}