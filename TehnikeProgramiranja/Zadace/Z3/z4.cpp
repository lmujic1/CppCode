//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>

int Broj_slova(std::string s) {
    int brojac(0);
    for(int i=0;i<s.length();i++) {
        if((s.at(i)>='A' && s.at(i)<='Z')||(s.at(i)>='a' && s.at(i)<='z')||(s.at(i)>='0' && s.at(i)<='9')) brojac++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &djeca, int br_timova) {
    if(br_timova<1 || br_timova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");

    std::list<std::string> lista(djeca.size());
    auto it=lista.begin();
    for(int i=0;i<djeca.size();i++,it++) *it=djeca.at(i);

    std::vector<std::set<std::string>> timovi;
    int br_clanova(djeca.size()/br_timova);
    int clan_vise(djeca.size()%br_timova);
    if(clan_vise!=0) br_clanova++;
    it=lista.begin();
    int vel_imena(0);

    for(int i=0;i<br_timova;i++) {
        std::set<std::string> pom_skup;
        if(clan_vise!=0 && i==clan_vise) br_clanova--;
        for(int j=0; j<br_clanova;j++) {

            if(lista.size()==1) {
                pom_skup.insert(*it);
                lista.resize(0);
                break;
            }
            //else if(lista.size()==0) break;

            if(i==0 && j==0) { //prvi clan //poslano ime npr ----- ispitati?
                pom_skup.insert(*it);
                vel_imena=Broj_slova(*it);
                it=lista.erase(it);
            }
            else {
                for(int k=0;k<vel_imena-1;k++,it++) if(it==lista.end()) it=lista.begin();
                if(it==lista.end()) it=lista.begin();
                pom_skup.insert(*it);
                vel_imena=Broj_slova(*it);
                it=lista.erase(it);
                if(it==lista.end()) it=lista.begin();
            }
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
    for(int i=0;i<br_djece;i++) {
        std::getline(std::cin,djeca[i]);
    }
    std::cout<<std::endl<<"Unesite broj timova: ";
    int br_timova;
    std::cin>>br_timova;
    try{
        std::vector<std::set<std::string>> timovi=Razvrstavanje(djeca,br_timova);
        for(int i=0;i<timovi.size();i++) {
            std::cout<<"Tim "<<i+1<<":";
            int brojac(0);
            for(auto x : timovi.at(i)) {
                if(brojac==timovi.at(i).size()-1) std::cout<<" "<<x;
                else std::cout<<" "<<x<<",";
                brojac++;
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error greska) {
        std::cout<<"Izuzetak: "<<greska.what();
    }
    //catch(...) {
    //    std::cout<<"greska";
    //}
    return 0;
}


/*int main() {
    std::vector<std::string> vektor{"lejla","tarik","adna"};

    std::list<std::string> lista(vektor.size());

    auto it1(lista.begin());
    for(int i=0;i<vektor.size();i++,it1++) *it1=vektor.at(i);
    for(auto it=lista.begin();it!=lista.end();it++) std::cout<<*it<<" ";
    return 0;
}*/