//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>
void IzvrniString(std::string &s) {
    for(int i=0;i<(s.length()/2);i++) {
        char tmp(s.at(i));
        s.at(i)=s.at(s.length()-1-i);
        s.at(s.length()-1-i)=tmp;
    }
}

int main ()
{
    std::cout<<"Unesi string: ";
    std::string recenica;
    std::getline(std::cin, recenica);
    IzvrniString(recenica);
    std::cout<<"Izvrnuti string je: "<<recenica;
    return 0;
}
