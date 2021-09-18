//
// Created by 38760 on 18. 9. 2021..
//

// TP, 2018/2019, Zadaća 1, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool Palindrom(std::string s) {

    for(int i=0;i<s.length();i++) {
        if(s.at(i)>='a' && s.at(i)<='z') s.at(i)=std::toupper(s.at(i));
    }
    for(int i=0;i<s.length();i++) {
        if(s.at(i)!=s.at(s.length()-1-i)) return false;
    }
    return true;
}

std::vector<std::string> NadjiSimetricneRijeci(std::string recenica) {
    std::vector<std::string> rezultat;
    for(int i=0;i<recenica.length();i++){
        std::string pomocni;
        if(((recenica.at(i)>='a' && recenica.at(i)<='z') || (recenica.at(i)>='A' && recenica.at(i)<='Z'))||(recenica.at(i)>='0' && recenica.at(i)<='9')) {
            while(((recenica.at(i)>='a' && recenica.at(i)<='z') || (recenica.at(i)>='A' && recenica.at(i)<='Z'))||(recenica.at(i)>='0' && recenica.at(i)<='9')){
                pomocni.push_back(recenica.at(i));
                if(i==recenica.length()-1) break;
                i++;
            }
        }
        if(pomocni.length()>=2 && Palindrom(pomocni)) rezultat.push_back(pomocni);
    }
    return rezultat;
}

int main ()
{
    std::cout<<"Unesite recenicu: ";
    std::string recenica;
    std::getline(std::cin, recenica);
    std::vector<std::string> s(NadjiSimetricneRijeci(recenica));
    if(s.size()>0) {
        std::cout<<std::endl<<"Simetricne rijeci unutar recenice su: "<<std::endl;
        for(int i=0;i<s.size();i++) {
            std::cout<<s.at(i)<<std::endl;
        }
    }
    else std::cout<<std::endl<<"Recenica ne sadrzi simetricne rijeci!";
    return 0;
}