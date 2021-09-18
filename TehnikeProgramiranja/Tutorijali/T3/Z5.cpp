//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: Tutorijal 3, Zadatak 5

#include <iostream>
#include <deque>
#include <limits>
std::deque<int> IzdvojiElemente(std::deque<int> dek, bool parna) {
    std::deque<int> novi;
    for(int x : dek) {
        long tmp(x),suma(0);
        if(x<0) tmp*=-1;
        while(tmp!=0) {
            suma+=tmp%10;
            tmp/=10;
        }
        if(suma%2!=parna) novi.push_front(x);
    }
    return novi;
}

int main ()
{
    int n;
    std::deque<int> V;
    int x;
    std::cout<<"Koliko zelite unijeti elemenata: ";
    std::cin>>n;

    if(n<=0) {
        std::cout<<"Broj elemenata mora biti veci od 0!";
        return 0;
    }
    else {
        std::cout<<"Unesite elemente: ";
        for(int i=0; i<n; i++) {
            std::cin>>x;
            V.push_front(x);
        }
        -
                std::deque<int> B(IzdvojiElemente(V,true));
        std::deque<int> C(IzdvojiElemente(V,false));

        for(int i=0; i<B.size();i++) {
            if(i==B.size()-1) std::cout<<B.at(i)<<" ";
            else std::cout<<B.at(i)<<",";
        }

        std::cout<<std::endl;

        for(int i=0; i<C.size();i++) {
            if(i==C.size()-1) std::cout<<C.at(i)<<" ";
            else std::cout<<C.at(i)<<",";
        }
    }
    return 0;
}