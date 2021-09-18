//
// Created by 38760 on 18. 9. 2021..
//

// TP, 2018/2019, Zadaća 1, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

int Obrni(int n) {
    int br(0);
    do{
        br=br*10+n%10;
        n/=10;
    }while(n!=0);
    return br;
}

std::vector<int> PalindromskaOtpornost(std::vector<int> vektor) {
    std::vector<int> otpornost;
    int brojac;
    for(int i=0;i<vektor.size();i++) {
        brojac=0;
        int tmp=abs(vektor.at(i)),novi;
        while(1) {
            novi=Obrni(tmp);
            if(tmp==novi) break;
            tmp+=novi;
            brojac++;
        }
        otpornost.push_back(brojac);
    }
    return otpornost;
}

int main ()
{
    std::cout<<"Koliko zelite unijeti elemenata: ";
    int n;
    std::cin>>n;

    std::vector<int> vektor;
    int broj;

    std::cout<<"Unesite elemente: ";
    for(int i=0;i<n;i++) {
        std::cin>>broj;
        vektor.push_back(broj);
    }

    std::vector<int> otpornost(PalindromskaOtpornost(vektor));

    for(int i=0;i<n;i++)
        std::cout<<"Palindromska otpornost broja "<<vektor.at(i)<<" iznosi "<<otpornost.at(i)<<std::endl;
    return 0;
}