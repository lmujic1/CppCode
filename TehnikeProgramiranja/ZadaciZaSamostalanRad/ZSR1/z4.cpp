//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 1, Zadatak 5
#include <iostream>
#include <cmath>
int main ()
{
    int n;
    std::cin>>n;
    int c;
    int b(0);
    do {
        c+=n*pow(10,b);
        b++;
    } while (b!=3);
    std::cout<<c;
    return 0;
}
