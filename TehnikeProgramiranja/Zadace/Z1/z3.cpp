//
// Created by 38760 on 18. 9. 2021..
//

// TP, 2018/2019, Zadaća 1, Zadatak 3
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;

int MaxSirina(Matrica mat) {
    int max_sirina(0);
    for(auto i:mat) {
        for(int j:i) {
            int sirina(0);
            if(j<0) sirina++;
            while(j!=0) {
                j/=10;
                sirina++;
            }
            if(sirina>max_sirina) max_sirina=sirina;
        }
    }
    return max_sirina;
}

Matrica KroneckerovProizvod (Matrica A, Matrica B) {
    //bacanje izuzetaka
    bool prvi(false),drugi(false);
    for(int i=0;i<A.size();i++) {
        if(A.at(i).size()!=A.at(0).size()) {
            prvi=true;
            break;
        }
    }
    for(int i=0;i<B.size();i++) {
        if(B.at(i).size()!=B.at(0).size()) {
            drugi=true;
            break;
        }
    }
    if(prvi && drugi) throw std::domain_error("Parametri nemaju formu matrice");
    else if(prvi) throw std::domain_error("Prvi parametar nema formu matrice");
    else if (drugi) throw std::domain_error("Drugi parametar nema formu matrice");

    Matrica C;
    if(A.size()!=0 && B.size()!=0) {
        int m(0),n(0);
        C=Matrica(A.size()*B.size(),std::vector<int> (A.at(0).size()*B.at(0).size()));
        for(int i=0;i<A.at(0).size();i++) {
            for(int k=0;k<B.at(0).size();k++) {
                for(int j=0;j<A.size();j++) {
                    for(int l=0;l<B.size();l++) {
                        C.at(m).at(n)=A.at(j).at(i)*B.at(l).at(k);
                        m++;
                    }
                }
                m=0;
                n++;
            }
        }
    }
    return C;
}
int main ()
{
    //unos prve matrice
    std::cout<<"Unesite dimenzije prve matrice: ";
    int k,l;
    std::cin>>k>>l;
    Matrica A(k,std::vector<int> (l));
    int broj;
    std::cout<<std::endl<<"Unesite elemente prve matrice: ";
    for(int i=0;i<k;i++) {
        for(int j=0;j<l;j++) {
            std::cin>>broj;
            A.at(i).at(j)=broj;
        }
    }
    //unos druge matrice
    std::cout<<std::endl<<"Unesite dimenzije druge matrice: ";
    std::cin>>k>>l;
    Matrica B(k,std::vector<int> (l));
    std::cout<<std::endl<<"Unesite elemente druge matrice: ";
    for(int i=0;i<k;i++) {
        for(int j=0;j<l;j++) {
            std::cin>>broj;
            B.at(i).at(j)=broj;
        }
    }
    //Kroneckerov Proizvod
    try {
        Matrica C(KroneckerovProizvod(A,B));
        int ispis(MaxSirina(C));
        std::cout<<std::endl<<"Njihov Kroneckerov proizvod glasi: "<<std::endl;
        for(auto i : C) {
            for(int j : i) {
                std::cout<<std::setw(ispis+1)<<std::right<<j;
            }
            std::cout<<std::endl;
        }
    }
    catch(std::domain_error izuzetak) {
        std::cout<<std::endl<<izuzetak.what();
    }
    return 0;
}