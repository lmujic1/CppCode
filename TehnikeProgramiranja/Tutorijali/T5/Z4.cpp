//
// Created by 38760 on 18. 9. 2021..
//


#include <iostream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <deque>



int main ()
{
    std::cout<<"Unesite broj elemenata: ";
    int br_el;
    std::deque<int> dek;
    std::cin>>br_el;
    dek.resize(br_el);
    std::cout<<"Unesite elemente: ";
    std::for_each(dek.begin(),dek.end(),[](int &n)->void{std::cin>>n;});

    std::cout<<"Najveci element deka je "<<*(std::max_element(dek.begin(),dek.end()))<<" ";
    std::cout<<std::endl<<"Najmanji element deka se pojavljuje "<<std::count(dek.begin(),dek.end(),*(std::min_element(dek.begin(),dek.end())))<<" puta u deku";
    std::cout<<std::endl<<"U deku ima "<<std::count_if(dek.begin(),dek.end(),[](int n){if(pow(n,1./2)==int(pow(n,1./2))) return true; return false;})<<" brojeva koji su potpuni kvadrati";
    std::cout<<std::endl<<"Prvi element sa najmanjim brojem cifara je "<<*(std::min_element(dek.begin(),dek.end(),[](int x,int y)  {if (int(log10(int(fabs(x)))+1) < int(log10(int(fabs(y)))+1))
        return true; return false;}));

    std::for_each(dek.begin(),dek.end(),[](int x)->void{if(int(log10(int(fabs(x)))+1)!=3) std::cout<<x<<" ";} );
    return 0;
}