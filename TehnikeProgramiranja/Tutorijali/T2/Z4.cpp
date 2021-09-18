//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: Tutorijal 2, Zadatak 4
/*
Unesite broj elemenata: 3
R1 = 3.5
X1 = 2.8
R2 = 10
X2 = -1.54
R3 = 12.37
X3 = 0.24
Paralelna veza ovih elemenata ima R = 2.51479 i X = 0.897637.
*/
#include <iostream>
#include <complex>
int main ()
{
    std::cout<<"Unesite broj elemenata: "<<std::endl<<std::endl;
    int n;
    std::cin>>n;
    double re,im;
    std::complex<double> z,suma(0,0);
    for(int i=0;i<n;i++) {
        std::cout<<"R"<<i+1<<" = ";
        std::cin>>re;
        std::cout<<"X"<<i+1<<" = ";
        std::cin>>im;
        z=std::complex<double> (re,im);
        suma+=1./z;
        std::cout<<std::endl;
    }
    suma=1./suma;
    std::cout<<std::endl<<"Paralelna veza ovih elemenata ima R = "<<suma.real()<<" i X = "<<suma.imag()<<".";
    return 0;
}
