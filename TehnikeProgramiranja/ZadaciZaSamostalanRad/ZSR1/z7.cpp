//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 1, Zadatak 9
#include <iostream>
#include <vector>
#include <deque>
typedef std::vector<int> Vektor;
typedef std::deque<std::vector<int>> Dek;
Dek Maxpodniz(Vektor A)
{
    Dek M;
    Vektor C;
    for(int i=1;i<A.size();i++) {
        if(i==A.size()-1) break;
        for (int j=i+1;j<A.size();j++) {
            if(A.at(i)>A.at(i-1) && A.at(i)<A.at(j)) C.push_back(A.at(i-1));
        }

        M.push_back(C);
        C.clear();
    }
    return M;
}
int main ()
{
    std::vector<int> A;
    int a;
    std::cout<<"Unesi broj elemenata niza ";
    int n;
    std::cin>>n;
    std::cout<<"Unesi elemente niza: ";
    for(int i=0; i<n; i++) {
        std::cin>>a;
        A.push_back(a);
    }
    Dek B(Maxpodniz(A));
    std::cout<<"Rezultujuci vektor je: ";
    for(auto b : B) {
        for(int i:b) {
            std::cout<<i<<" ";
        }
    }

    return 0;
}
//TP 2017/2018: ZSR 1, Zadatak 10
#include <iostream>

int main ()
{
    return 0;
}


for(int i=0; ; i++) {
cin>>a;
if(a==-1) break;
v.push_back(a);
}