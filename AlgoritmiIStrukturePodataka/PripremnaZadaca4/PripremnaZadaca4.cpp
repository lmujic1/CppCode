//
// Created by 38760 on 18. 9. 2021..
//
#include <iostream>

int fib_petlja (int n)
{
    if (n<=1) return n; // 0 i 1
    int pretprosli(0), prosli(1), rezultat;
    for (int i(2); i<=n; i++) {
        rezultat = pretprosli+prosli;
        pretprosli = prosli;
        prosli = rezultat;
    }
    return rezultat;
}
int fib2_0(int n) {
    return fib_petlja(n);
}


int nzd(int x, int y) {
    if(y==0) return x;
    return nzd(y,x%y);
}

int main()
{
    std::cout<<fib2_0(20);
    std::cout << "Pripremna Zadaca Za Vjezbu 5, Zadatak 1";
    return 0;
}