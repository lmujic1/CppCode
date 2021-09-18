//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 1, Zadatak 8
#include <iostream>
#include <vector>
typedef std::vector<int> Vektor;

int main ()

{
    Vektor A;
    Vektor B;
    Vektor C;
    int a,b;
    std::cout<<"A:";
    do{
        std::cin>>a;
        A.push_back(a);
    } while(a!=0);
    std::cout<<"B:";
    do{
        std::cin>>b;
        B.push_back(b);
    }while(b!=0);

    for (int i=0;i<A.size();i++) {
        int tmp1(A.at(i));
        int tmp2(B.at(i));
        if(tmp1==tmp2) C.push_back(tmp1);
    }

    for( int x : C) std::cout<<x<<" ";
    return 0;
}
