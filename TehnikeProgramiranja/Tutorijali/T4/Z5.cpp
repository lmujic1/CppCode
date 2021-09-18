//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
template <typename Tip>
std::vector<Tip> Presjek(std::vector<Tip> v1, std::vector<Tip> v2) {
    std::vector<int> pomocni(v1.size(),0);
    std::vector<Tip> v3;
    for(int i=0;i<v1.size();i++) {
        for(int j=0;j<v2.size();j++){
            if(v1.at(i)==v2.at(j)) {
                bool put(true);
                for(int k=0;k<v3.size();k++) {
                    if(v1.at(i)==v3.at(k)) {
                        put=false;
                        break;
                    }
                }
                if(put) v3.push_back(v1.at(i));
            }
        }
    }

    return v3;
}
int main ()
{
    std::cout<<"Test za realne brojeve..."<<std::endl;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    int broj;
    std::cin>>broj;
    std::cout<<"Unesite elemente prvog vektora: ";
    std::vector<double> A;
    for (int i=0;i<broj; i++) {
        double br1;
        std::cin>>br1;
        A.push_back(br1);
    }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>broj;
    std::cout<<"Unesite elemente drugog vektora: ";
    std::vector<double> B;
    for(int i=0;i<broj;i++) {
        double br2;
        std::cin>>br2;
        B.push_back(br2);
    }

    std::cout<<"Zajednicki elementi su: ";
    std::vector<double> C(Presjek(A,B));
    for(int i=0;i<C.size();i++) {
        if(i==C.size()-1) std::cout<<C.at(i);
        else std::cout<<C.at(i)<<" ";
    }
    std::cout<<std::endl<<std::endl;

    std::cout<<"Test za stringove..."<<std::endl;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    std::cin>>broj;
    std::cout<<"Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
    std::vector<std::string> Izraz1;
    std::cin.ignore(100000,'\n');
    for(int i=0;i<broj;i++) {
        std::string rijec;
        std::getline(std::cin, rijec);
        Izraz1.push_back(rijec);
    }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>broj;
    std::cout<<"Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
    std::vector<std::string> Izraz2;
    std::cin.ignore(100000, '\n');
    for(int i=0;i<broj;i++) {
        std::string rijec2;
        std::getline(std::cin,rijec2);
        Izraz2.push_back(rijec2);
    }
    std::cout<<"Zajednicki elementi su:"<<std::endl;
    std::vector<std::string> Izraz3(Presjek(Izraz1,Izraz2));
    for(int i=0; i<Izraz3.size();i++)
        std::cout<<Izraz3.at(i)<<std::endl;

    return 0;
}