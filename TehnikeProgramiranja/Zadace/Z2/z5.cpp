//
// Created by 38760 on 18. 9. 2021..
//

/* TP, 2018/2019*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <cmath>

template <typename Iter>
bool ZaSve(Iter p1, Iter p2, bool f(typename std::remove_reference<decltype(*p1)>::type)) {
    while(p1!=p2) {
        if(f(*p1)==false) return false;
        p1++;
    }
    return true;
}

template <typename Iter2>
bool MakarJedan(Iter2 p1,Iter2 p2, bool f(typename std::remove_reference<decltype(*p1)>::type)) {
    while(p1!=p2) {
        if(f(*p1)==true) return true;
        p1++;
    }
    return false;
}

template<typename Iter3>
auto Akumuliraj(Iter3 p1, Iter3 p2, typename std::remove_reference<decltype(*p1)>::type f(typename std::remove_reference<decltype(*p1)>::type, typename std::remove_reference<decltype(*p1)>::type),typename std::remove_reference<decltype(*p1)>::type a0=0) -> typename std::remove_reference<decltype(*p1)>::type {
    while(p1!=p2) {
        a0=f(a0,*p1);
        p1++;
    }
    return a0;
}

int main ()
{
    std::cout<<"Unesite string: ";
    std::string recenica;
    std::getline(std::cin,recenica);
    if(ZaSve(recenica.begin(),recenica.end(),[](char n)->bool{if (((n>='a'&&n<='z')||(n>='A'&&n<='Z'))||(n>='0' && n<='9')) return true; return false;})) std::cout<<"Uneseni string sadrzi samo slova i cifre";
    else std::cout<<"Uneseni string sadrzi i druge znakove osim slova i cifara";
    std::cout<<std::endl<<"Unesite niz od 10 brojeva: ";
    int niz[10];
    std::for_each(niz,niz+10,[](int &n)->void{std::cin>>n;});
    if(MakarJedan(niz,niz+10,[](int n)->bool{
        if (n==0) return false;
        int tmp(n),suma(0);
        if(n<0) tmp*=-1;
        while(tmp!=0) {
            suma+=tmp%10;
            tmp/=10;
        }
        if(n%suma==0) return true;
        return false;
    })) std::cout<<"U nizu ima brojeva djeljivih sa sumom svojih cifara";
    else std::cout<<"U nizu nema brojeva djeljivih sa sumom svojih cifara";
    std::cout<<std::endl<<"Unesite dek od 10 elemenata: ";
    std::deque<double> dek(10);
    std::for_each(dek.begin(),dek.end(),[](double &n){std::cin>>n;});
    std::deque<double>::iterator it(dek.begin());
    double n(*it);
    std::cout<<std::endl<<"Suma deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double x,double y){return x+y;});
    std::cout<<std::endl<<"Produkt deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double x,double y){return x*y;},1);
    std::cout<<std::endl<<"Najveci elemenat deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double x,double y){if (x>y) return x; return y;},n);
    std::cout<<std::endl<<"Najmanji elemenat deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double x,double y){if (x<y) return x; return y;},n);

    return 0;
}