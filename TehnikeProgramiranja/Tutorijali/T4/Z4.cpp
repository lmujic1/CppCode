//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <string>
#include <cmath>
template <typename Tip>
void UnosBroja(std::string unos,std::string greska, Tip &broj) {
    Tip br;
    while(true) {
        std::cout<<unos;
        std::cin>>br;
        if(std::cin.peek()!='\n'){
            std::cout<<std::endl<<greska<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        else break;
    }
    broj=br;
}
int main ()
{
    double broj;
    int eksponent;
    UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...", broj);
    std::cout<<std::endl;
    UnosBroja("Unesite cjelobrojni eksponent: ","Neispravan unos, pokusajte ponovo...", eksponent);
    double stepen(1);
    for(int i=0;i<abs(eksponent);i++) stepen*=broj;
    if(eksponent<0) stepen=1./stepen;
    std::cout<<std::endl<<broj<<" na "<<eksponent<<" iznosi "<<stepen;
    return 0;
}