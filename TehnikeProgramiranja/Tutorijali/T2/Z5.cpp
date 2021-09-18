//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: Tutorijal 2, Zadatak 5
/*
Unesite broj elemenata: 2
Z1 = 10.5
fi1 = 30
Z2 = 2.8
fi2 = -47.6
Paralelna veza ovih elemenata ima Z = 2.57147 i fi = -33.7613.
*/

#include <iostream>
#include <complex>
#include <cmath>
int main ()
{
    const double pi=4*(std::atan(1));
    std::cout<<"Unesi broj elemenata:"<<std::endl;
    int n;
    std::cin>>n;
    double r,fi;
    std::complex<double> z,suma(0,0);
    for(int i=0;i<n;i++) {
        std::cin>>r;
        std::cout<<"Z"<<i+1<<" = ";
        std::cin>>fi;
        fi=fi*(pi/180);
        std::cout<<"fi"<<i+1<<" = ";
        z=std::polar (r,fi);
        suma+=std::complex<double>(1./z);
        std::cout<<std::endl;
    }
    suma=1./suma;
    std::cout<<"Paralelna veza ovih elemenata ima Z = "<<abs(suma)<<" i fi = "<<arg(suma)*(180/pi)<<".";
    return 0;
}