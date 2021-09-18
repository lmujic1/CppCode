//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string str) {
    std::map<std::string,std::set<int>> mapa;
    for(auto &i : str)  if(i>='A' && i<='Z') i+='a'-'A';
    for(int i=0;i<str.length();i++) {
        if((str.at(i)>='a' && str.at(i)<='z')||(str.at(i)>='0' && str.at(i)<='9')) {
            int index(i);
            std::string pom;
            while((str.at(i)>='a' && str.at(i)<='z')||(str.at(i)>='0' && str.at(i)<='9')) {
                pom.push_back(str[i]);
                i++;
                if(i==str.length()) break;
            }
            auto it(mapa.find(pom));
            if(it==mapa.end()) {
                std::set<int> skup;
                skup.insert(index);
                mapa.insert({pom,skup});
            }
            else (it->second).insert(index);
        }
        if(i==str.length()) break;
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova (std::string rijec,const std::map<std::string, std::set<int>> &mapa) {
    auto it(mapa.find(rijec));
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}
void IspisiIndeksPojmova (const std::map<std::string,std::set<int>> &mapa) {
    for(auto it=mapa.begin();it!=mapa.end();it++) {
        std::cout<<(it->first)<<": ";
        int broj((it->second).size());
        int brojac(1);
        for(int x : (it->second)) {
            if(brojac==broj) std::cout<<x;
            else std::cout<<x<<",";
            brojac++;
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string str;
    std::getline(std::cin,str);
    std::map<std::string,std::set<int>> mapa;
    mapa=(KreirajIndeksPojmova(str));
    IspisiIndeksPojmova(mapa);
    while(1) {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::cin>>rijec;
        if(rijec.at(0)=='.') break;
        try {
            std::set<int> indeksi;
            indeksi=(PretraziIndeksPojmova(rijec,mapa));
            for(int x: indeksi) std::cout<<x<<" ";
        }
        catch (std::logic_error) {
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
    }
    return 0;
}