//
// Created by 38760 on 18. 9. 2021..
//

/* TP, 2018/2019
*/
#include <iostream>
#include <cmath>
void RastavaBroja (int n, int &p, int &q) {
    if(n<=0) throw std::domain_error("Broj koji se rastavlja mora biti prirodan");
    p=1;
    q=1;
    int tmp(n);
    for(int i=2;i<tmp;i++) {
        int brojac(0);
        while(n%i==0) {
            brojac++;
            n/=i;
            if(brojac%2==0) q*=i;
        }
        if(brojac%2==1) p*=i;
    }
}
int main ()
{
    int n,p,q;
    std::cout<<"Unesite prirodan broj ";
    std::cin>>n;
    try{
        RastavaBroja(n,p,q);
        std::cout<<std::endl<<p<<" "<<q;
    }
    catch(std::domain_error greska) {
        std::cout<<std::endl<<"Izuzetak: "<<greska.what()<<"!";
    }
    return 0;
}