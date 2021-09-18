//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <string>
#include <vector>
void IzdvojiKrajnjeRijeci (std::vector<std::string> Vstringova, std::string &A, std::string &B)
{
    std::string a;
    std::string b;
    if(Vstringova.size()==0) return;
    a=Vstringova.at(0);
    b=Vstringova.at(0);
    for(auto s: Vstringova) {
        std::string tmp1(s);
        std::string tmp2(a);
        std::string tmp3(b);
        for(auto &l: tmp1) l=toupper(l);
        for(auto &l: tmp2) l=toupper(l);
        for(auto &l: tmp3) l=toupper(l);
        if(tmp1<tmp2) a=s;
        if(tmp1>tmp3) b=s;
    }
    A=a;
    B=b;
}
void ZadrziDuplikate (std::vector<std::string> &string)
{
    std::vector<std::string> v;
    for(int i=0; i<string.size(); i++) {
        std::string v1=string.at(i);
        for(int j=i+1; j<string.size(); j++) {
            std::string v2=string.at(j);
            if(v1==v2) {
                bool put(true);
                for(int k=0; k<v.size(); k++) {
                    std::string v3(v.at(k));
                    if(v1==v3) {
                        put=false;
                        break;
                    }
                }
                if(put) v.push_back(v1);
                break;
            }
        }
    }
    string=v;
}
int main ()
{
    std::cout<<"Koliko zelite unijeti rijeci: ";
    int broj_rijeci;
    std::cin>>broj_rijeci;
    std::cin.ignore(1000,'\n');
    std::string prva,zadnja;
    std::vector<std::string> v(broj_rijeci);
    std::cout<<"Unesite rijeci: ";
    for(int i=0;i<broj_rijeci;i++) {
        std::getline(std::cin,v.at(i));
    }
    IzdvojiKrajnjeRijeci(v,prva,zadnja);
    std::cout<<std::endl<<"Prva rijec po abecednom poretku je: "<<prva<<std::endl<<"Posljednja rijec po abecednom poretku je: "<<zadnja;
    ZadrziDuplikate(v);
    std::cout<<std::endl<<"Rijeci koje se ponavljaju su: ";
    for(int i=0;i< v.size();i++) std::cout<<v.at(i)<<" ";
    return 0;
}
/*
Koliko zelite unijeti rijeci: 10
Unesite rijeci: xyzzy qwert uiop asd rrrfat asd yxcvbb qwert asd cvbnm
Prva rijec po abecednom poretku je: asd
Posljednja rijec po abecednom poretku je: yxcvbb
Rijeci koje se ponavljaju su: qwert asd*/
