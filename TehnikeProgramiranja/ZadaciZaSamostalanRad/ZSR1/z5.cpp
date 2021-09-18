//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 1, Zadatak 6
#include <iostream>
#include <vector>
bool stependvojke(int n) {
    while(n!=1) {
        if(n%2!=0) return false;
        n/=2;
    }
    return true;
}

std::vector<int> ispisistependvojke(std::vector<int> A) {
    std::vector<int> B;
    for(int i=0;i<A.size();i++) {
        if(stependvojke(A.at(i))) B.push_back(A.at(i));
    }
    return B;
}

int main ()
{
    std::vector<int> A;
    int a;
    std::cout<<"Unesi broj elemenata niza ";
    int n;
    std::cin>>n;
    std::cout<<"Unesi elemente niza: ";
    for(int i=0;i<n;i++){
        std::cin>>a;
        A.push_back(a);
    }
    std::vector<int> B(ispisistependvojke(A));
    std::cout<<"Rezultujuci vektor je: ";
    for(auto b : B) std::cout<<b<<" ";
    return 0;
}
