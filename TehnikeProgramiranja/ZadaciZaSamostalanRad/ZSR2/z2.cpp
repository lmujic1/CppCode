//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 4, Zadatak 2
#include <iostream>
/*Neka je “v” neki vektor čiji su elementi liste cijelih brojeva (tj. tipa “std::vector<std::list<int>>”).
Napišite isječak programa u kojima ćete pozivom bibliotečke funkcije “sort” uz odgovarajuću funkciju
kriterija implementiranu kao lambda funkciju sortirati ovaj vektor u rastući poredak po sumi
elemenata u listama, tj. tako da u njemu liste sa manjom sumom elemenata dolaze prije listi sa većom
sumom elemenata (elementi unutar svake od listi ostaju u istom redoslijedu u kakvom su bili i prije
sotriranja). Po obavljenom sortiranju, treba ispisati sortirani vektor tako da se svaka lista ispisuje u
posebnom redu, pri čemu se elementi unutar jedne liste međusobno razdvajaju jednim razmakom*/
#include<vector>
#include<list>
#include<algorithm>
int main ()
{
    std::vector<std::list<int>> V{{10,3,4},{4,5,7},{5,6,7}};
    std::sort(V.begin(), V.end(), [](std::list<int> l1, std::list<int> l2){
        int suma1(0);
        int suma2(0);
        auto it1(l1.begin());
        while(it1!=l1.end()) {
            suma1+=*it1;
            it1++;
        }

        auto it2(l2.begin());
        while(it2!=l2.end()) {
            suma2+=*it2;
            it2++;
        }
        return suma1<suma2;
    });

    for(auto x:V) {
        for(auto y:x) {
            std::cout<<y<<" ";
        }
    }
    return 0;
}
