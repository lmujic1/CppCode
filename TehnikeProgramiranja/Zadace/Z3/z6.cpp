//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

int Broj_slova(std::string s) {
    int broj(0);
    for(int i=0;i<s.length();i++) if((s.at(i)>='A' && s.at(i)<='Z')||(s.at(i)>='a' && s.at(i)<='z')||(s.at(i)>='0' && s.at(i)<='9')) broj++;
    return broj;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &djeca, int br_timova) {
    if(br_timova<1 || br_timova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");

    std::shared_ptr<Dijete> pocetak(nullptr),prethodni(nullptr);
    for(int i=0;i<djeca.size();i++) {
        std::shared_ptr<Dijete> novi=std::make_shared<Dijete>();
        novi->ime=djeca.at(i);
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;

    std::vector<std::set<std::string>> timovi;

    int br_clanova(djeca.size()/br_timova);
    int clan_vise(djeca.size()%br_timova);
    if(clan_vise!=0) br_clanova++;
    int vel_imena(0),broj_elemenata(djeca.size());

    std::shared_ptr<Dijete> pomocni(pocetak);
    for(int i=0;i<br_timova;i++) {
        std::set<std::string> pom_skup;
        if(clan_vise!=0 && i==clan_vise) br_clanova--;
        for(int j=0;j<br_clanova;j++) {
            if(broj_elemenata==1) {
                pom_skup.insert(pomocni->ime);
                pomocni->sljedeci=nullptr;
                break;
            }
            for(int k=0;k<vel_imena-1;k++) {pomocni=pomocni->sljedeci; prethodni=prethodni->sljedeci; }
            pom_skup.insert(pomocni->ime);
            vel_imena=Broj_slova(pomocni->ime);
            prethodni->sljedeci=pomocni->sljedeci;
            pomocni=prethodni->sljedeci;
            broj_elemenata--;
        }
        timovi.push_back(pom_skup);
    }
    return timovi;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int br_djece;
    std::cin>>br_djece;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string> djeca(br_djece);
    for(int i=0;i<br_djece;i++) std::getline(std::cin,djeca.at(i));
    std::cout<<std::endl<<"Unesite broj timova: ";
    int br_timova;
    std::cin>>br_timova;
    try{
        std::vector<std::set<std::string>> timovi(Razvrstavanje(djeca,br_timova));
        for(int i=0;i<timovi.size();i++) {
            std::cout<<"Tim "<<i+1<<":";
            int brojac(0);
            for(auto x: timovi.at(i)) {
                if(brojac==timovi.at(i).size()-1) std::cout<<" "<<x;
                else std::cout<<" "<<x<<",";
                brojac++;
            }
            std::cout<< std::endl;
        }
    }
    catch(std::logic_error greska) {
        std::cout<<"Izuzetak: "<<greska.what();
    }
    return 0;
}

