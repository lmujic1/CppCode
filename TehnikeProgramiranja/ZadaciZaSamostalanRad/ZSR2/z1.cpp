//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 4, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>

template <typename Tip>
std::vector<Tip> ZajednickiElementi(std::vector<Tip> V1, std::vector<Tip> V2) {
    std::vector<Tip> V3;
    for(int i=0;i<V1.size();i++) {
        for(int j=0;j<V2.size();j++) {
            if (V1.at(i)==V2.at(j))
                V3.push_back(V1.at(i));
        }
    }

    std::sort(V3.begin(), V3.end());
    for(int i=0;i<V3.size()-1;i++) {
        if(V3.at(i)==V3.at(i+1)) V3.erase(V3.begin() + i);
    }
    return V3;

}

int main ()
{
    std::vector<int> v1{2,3,4,5,6,7};
    std::vector<int> v2{7,4,5,2,3,4,3};
    std::vector<int> v3;
    v3=ZajednickiElementi(v1,v2);
    for(int i=0;i<v3.size();i++) std::cout<<v3.at(i)<<" ";
    return 0;
}
