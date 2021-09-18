//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <iomanip>
std::vector<std::vector<int>> KroneckerovProizvod (std::vector<int> a, std::vector<int> b) {
    std::vector<std::vector<int>> c(a.size(),std::vector<int>(b.size()));
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b.size();j++) {
            c.at(i).at(j)=a.at(i)*b.at(j);
        }
    }
    return c;
}

int NajvecaSirina(std::vector<std::vector<int>> matrica) {
    int max(0);
    for(auto i:matrica) {
        for(int j: i) {
            int br(0);
            if(j<0) br++;
            while(j!=0) {
                j/=10;
                br++;
            }
            if(br>max) max=br;
        }
    }
    return max;
}
int main ()
{
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    int m;
    std::cin>>m;
    std::cout<<"Unesite elemente prvog vektora: ";
    int a;
    std::vector<int> A;
    for(int i=0;i<m;i++) {
        std::cin>>a;
        A.push_back(a);
    }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>m;
    std::cout<<"Unesite elemente drugog vektora: ";
    std::vector<int>B;
    for(int i=0;i<m;i++) {
        std::cin>>a;
        B.push_back(a);
    }

    std::vector<std::vector<int>> C(KroneckerovProizvod(A,B));
    int ispis(NajvecaSirina(C));
    std::cout<<std::endl;
    for(auto i:C) {
        for(int j:i) {
            std::cout<<std::setw(ispis+1)<<std::right<<j;
        }
        std::cout<<std::endl;
    }
    return 0;
}
