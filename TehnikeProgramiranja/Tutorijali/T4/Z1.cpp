//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <cmath>
int Cifre(long long int n,int &c_min,int &c_max) {
    int brojac(0),maxi;
    long long int tmp(n);
    c_min=abs(tmp%10);
    c_max=abs(tmp%10);
    do{
        brojac++;
        maxi=abs(tmp%10);
        tmp/=10;
        if(c_max<maxi) c_max=maxi;
        if(c_min>maxi) c_min=maxi;
    }while(tmp!=0);

    return brojac;
}
int main ()
{
    std::cout<<"Unesite broj: ";
    long long int n;
    int e,l,m;
    std::cin>>n;
    e=Cifre(n,l,m);
    std::cout<<"Broj "<<n<<" ima "<<e<<" cifara, najveca je "<<m<<" a najmanja "<<l<<".";
    return 0;
}