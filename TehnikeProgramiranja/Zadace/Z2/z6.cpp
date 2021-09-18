//
// Created by 38760 on 18. 9. 2021..
//

/* TP, 2018/2019
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
bool KriterijSortiranja(std::string s1,std::string s2){
    if(s1.length()==s2.length()) {
        for(auto &x:s1) x=std::toupper(x);
        for(auto &x:s2) x=std::toupper(x);
        return s1<s2;
    }
    return s1.length()<s2.length();
}
bool PretraziBinarno(std::string *p,int br_elemenata,std::string s) {
    return std::binary_search(p,p+br_elemenata,s,KriterijSortiranja);
}
void SortirajPoDuzini(std::string *p,int br_elemenata) {
    std::sort(p,p+br_elemenata,KriterijSortiranja);
}

int main ()
{
    std::cout<<"Unesite broj rijeci: ";
    int broj;
    std::cin>>broj;
    try{
        std::string *p=new std::string [broj];
        std::cout<<"Unesite rijeci: ";
        for(int i=0;i<broj;i++) {
            std::cin>>p[i];
        }
        SortirajPoDuzini(p,broj);
        std::cout<<"Sortirane rijeci:";
        for(int i=0;i<broj;i++) std::cout<<" "<<p[i];

        std::cout<<std::endl<<"Unesite rijec za pretragu: ";
        std::string s1;
        std::cin>>s1;

        if(PretraziBinarno(p,broj,s1))  std::cout<<"Rijec '"<<s1<<"' se nalazi u nizu.";
        else std::cout<<"Rijec '"<<s1<<"' se ne nalazi u nizu.";

        delete [] p;
    }
    catch (...) {
        std::cout<<"Nedovoljno memorije!";
    }
    return 0;
}