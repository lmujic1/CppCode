//
// Created by 38760 on 18. 9. 2021..
//

#include "PpiremnaZadaca2.h"
#include <iostream>

template <typename Tip>
class Stek  {
    struct Cvor {
        Tip info;
        Cvor *sljedeci;
    };
    int broj_elemenata;
    Cvor *pocetni;

public:

    Stek() : pocetni(nullptr), broj_elemenata(0) {}
    ~Stek() {
        Cvor *trenutni(pocetni);
        while(pocetni!=nullptr) {
            trenutni=pocetni;
            pocetni=pocetni->sljedeci;
            delete trenutni;
        }
    }
    Stek(const Stek &s) {
        Cvor *pom(s.pocetni),*pomocni(nullptr);
        while(pom!=nullptr) {
            Cvor *novi(new Cvor{pom->info, nullptr});
            if(pomocni==nullptr) this->pocetni=novi;
            else pomocni->sljedeci=novi;
            pomocni=novi;
            pom=pom->sljedeci;
        }
        broj_elemenata=s.broj_elemenata;
    }
    Stek& operator =(const Stek &s) {
        if(this==&s) return *this;
        Cvor *trenutni(pocetni);
        while(pocetni!=nullptr) {
            trenutni=pocetni;
            pocetni=pocetni->sljedeci;
            delete trenutni;
        }
        Cvor *pom(s.pocetni),*pomocni(nullptr);
        while(pom!=nullptr) {
            Cvor *novi(new Cvor{pom->info, nullptr});
            if(pomocni==nullptr) this->pocetni=novi;
            else pomocni->sljedeci=novi;
            pomocni=novi;
            pom=pom->sljedeci;
        }
        broj_elemenata=s.broj_elemenata;
        return *this;
    }

    void brisi() {
        Cvor *trenutni(pocetni);
        while(pocetni!=nullptr) {
            trenutni=pocetni;
            pocetni=pocetni->sljedeci;
            delete trenutni;
        }
        broj_elemenata=0;
    }

    void stavi(const Tip& el) {
        broj_elemenata++;
        Cvor *novi(new Cvor{el,pocetni});
        pocetni=novi;
    }

    Tip skini() {
        if(broj_elemenata==0) throw std::domain_error("Prazan stek");
        Tip prvi(pocetni->info);
        Cvor *pomocni(pocetni);
        pocetni=pocetni->sljedeci;
        delete pomocni;
        broj_elemenata--;
        return prvi;
    }
    Tip& vrh() {
        if(broj_elemenata==0) throw std::domain_error("Prazan stek");
        return pocetni->info;
    }

    int brojElemenata() const {
        return broj_elemenata;
    }

};


// int pretraga(std::vector<Stek<>>) {}

/*template<typename Tip>
void Test1(Stek<Tip> &s) {
  std::cout<<s.brojElemenata()<<std::endl;
}
template<typename Tip>
void Test2(Stek<Tip> &s,Tip element) {
  std::cout<<s.vrh();
  s.stavi(element);
}
template<typename Tip>
void Test3(Stek<Tip> &s, Tip element) {
  s.stavi(element);
  std::cout<<s.vrh();
  s.skini();
}
template<typename Tip>
void Test4(Stek<Tip> &s, Tip element) {
  std::cout<<s.brojElemenata()<<std::endl;
  s.stavi(element);
  s.stavi(element);
  std::cout<<s.brojElemenata()<<std::endl;
  s.brisi();
  std::cout<<s.brojElemenata()<<std::endl;
}
*/
void isti_Red(Stek<int> &s) {
    if(s.brojElemenata()==0) return;
    int a=s.skini();
    isti_Red(s);
    s.stavi(a);
}


int main() {

    Stek<int> s;
    for (int i(1); i<10; i++)
        s.stavi(i);
    isti_Red(s);
    for (int i(1); i<10; i++)
        std::cout<<s.skini()<<" ";
    std::cout << "Pripremna Zadaca Za Vjezbu 3, Zadatak 1";
    return 0;
}