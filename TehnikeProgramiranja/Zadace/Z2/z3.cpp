//
// Created by 38760 on 18. 9. 2021..
//

/* TP, 2018/2019
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

template <typename Tip1, typename Tip2,typename Tip3>
Tip3 SimetricnaRazlikaBlokova(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 p5) {
    Tip3 p6(p5);
    Tip1 tmp1(p1),tmp2(p2);
    while(p1!=p2) {
        if(std::count(p3,p4,*p1)==0) {
            if(std::count(p5,p6,*p1)==0) {
                *p6=*p1;
                p6++;
            }
        }
        p1++;
    }
    while(p3!=p4) {
        if(std::count(tmp1,tmp2,*p3)==0) {
            if(std::count(p5,p6,*p3)==0) {
                *p6=*p3;
                p6++;
            }
        }
        p3++;
    }
    return p6;
}

int main ()
{
    std::cout<<"Unesite broj elemenata niza";
    int vel;
    std::cin>>vel;
    int niz[100];
    std::cout<<std::endl<<"Unesite elemente niza";
    std::for_each(niz,niz+vel,[](int &n)->void{std::cin>>n;});

    std::cout<<std::endl<<"Unesite broj elemenata deka";
    int vel2;
    std::cin>>vel2;
    std::deque<int> dek;
    dek.resize(vel2);
    std::cout<<std::endl<<"Unesite elemente deka";
    std::for_each(dek.begin(),dek.end(),[](int &n)->void{std::cin>>n;});

    std::vector<int> vektor;
    vektor.resize(vel+vel2);
    auto p(SimetricnaRazlikaBlokova(niz,niz+vel,dek.begin(),dek.end(),vektor.begin()));
    vektor.resize(p-vektor.begin());
    if(vektor.size()==0) std::cout<<std::endl<<"Blokovi nemaju simetricnu razliku";
    else {
        std::cout<<std::endl<<"Simetricna razlika blokova je: ";
        std::for_each(vektor.begin(),vektor.end(),[](int n)->void{std::cout<<n<<" ";});
    }
    return 0;
}



/*while(p1!=p2) {
    Tip2 tmp1(p3), tmp2(p4);
    int brojac(0);
    while(tmp1!=tmp2) {
        if(*p1==*tmp1) brojac++;
        tmp1++;
    }
    if(brojac==0) {
        Tip3 t1(p5), t2(p6);
        int brojac2(0);
        while(t1!=t2) {
            if(*p1==*t1) brojac2++;
            t1++;
        }
        if(brojac2==0) {
            *p6=*p1;
            p6++;
        }
    }
    p1++;
}*/