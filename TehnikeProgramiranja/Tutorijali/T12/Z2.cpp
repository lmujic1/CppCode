/*
    TP 16/17 (Tutorijal 12, Zadatak 2)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <utility>
template <typename Tip>
std::set<Tip> operator *(std::set<Tip> s1, std::set<Tip> s2){
    std::set<Tip> Noviskup;
    for(auto x : s1) {
        for(auto y : s2) {
            if(std::count(s1.begin(), s1.end(), x) && std::count(s2.begin(), s2.end(), y) && x==y)
                Noviskup.insert(x);
        }
    }
    return Noviskup;
}
template <typename Tip>
std::set<Tip> operator +(std::set<Tip> s1, std::set<Tip> s2){
    std::set<Tip> Noviskup;
    for(auto x : s1) {
        for (auto y :s2) {
            if(std::count(s1.begin(), s1.end(), x) && std::count(s2.begin(), s2.end(), y))
                Noviskup.insert(x);
            Noviskup.insert(y);
        }
    }
    return Noviskup;
}
template <typename Tip>
std::ostream &operator <<(std::ostream &tok, std::set<Tip> s) {
    int n(0);
    tok<<"{";
    for(auto x:s) {
        if(n==s.size()-1) tok<<x;
        else tok<<x<<",";
        n++;
    }
    tok<<"}";
    return tok;
}
template <typename Tip1, typename Tip2>
std::set<std::pair<Tip1,Tip2>> operator %(const std::set<Tip1> &s1,const std::set<Tip2> &s2) {
    std::set<std::pair<Tip1,Tip2>> dekartov_proizvod;
    for(auto x:s1) {
        for(auto y:s2) {
            std::pair<Tip1,Tip2> par(std::make_pair(x,y));
            dekartov_proizvod.insert(par);
        }
    }
    return dekartov_proizvod;
}
template <typename Tip1, typename Tip2>
std::ostream &operator <<(std::ostream &tok, std::set<std::pair<Tip1,Tip2>> s) {
    int n(0);
    tok<<"{";
    for(auto x:s) {
        if(n==s.size()-1) tok<<"("<<x.first<<","<<x.second<<")";
        else tok<<"("<<x.first<<","<<x.second<<"),";
        n++;
    }
    tok<<"}";
    return tok;
}
template <typename Tip>
std::set<Tip> operator *=(std::set<Tip> &s1, std::set<Tip> s2){
    std::set<Tip> Noviskup;
    for(auto x : s1) {
        for(auto y : s2) {
            if(std::count(s1.begin(), s1.end(), x) && std::count(s2.begin(), s2.end(), y) && x==y)
                Noviskup.insert(x);
        }
    }
    s1=Noviskup;
    return s1;
}
template <typename Tip>
std::set<Tip> operator +=(std::set<Tip> &s1, std::set<Tip> s2){
    std::set<Tip> Noviskup;
    for(auto x : s1) {
        for (auto y :s2) {
            if(std::count(s1.begin(), s1.end(), x) && std::count(s2.begin(), s2.end(), y))
                Noviskup.insert(x);
            Noviskup.insert(y);
        }
    }
    s1=Noviskup;
    return s1;
}
int main ()
{

    return 0;
}