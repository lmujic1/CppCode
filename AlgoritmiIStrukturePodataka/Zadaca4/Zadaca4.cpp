//
// Created by 38760 on 18. 9. 2021..
//


#include <iostream>

template <typename Tip>
class DvostraniRed
{
    struct Cvor {
        Tip element;
        Cvor*sljedeci,*prethodni;
    };
    Cvor *pocetak, *kraj;
    int broj_elemenata;
public:
    DvostraniRed() : pocetak(nullptr),kraj(nullptr),broj_elemenata(0) {}
    ~DvostraniRed()
    {
        if(pocetak==kraj) delete pocetak;
        else {
            while(pocetak!=nullptr) {
                kraj=pocetak;
                pocetak=pocetak->prethodni;
                kraj->prethodni=nullptr;
                kraj->sljedeci=nullptr;
                delete kraj;
            }
        }
    }
    DvostraniRed(const DvostraniRed &dr) : pocetak(nullptr), kraj(nullptr), broj_elemenata(dr.broj_elemenata)
    {
        Cvor * pomocni(dr.pocetak);
        while(pomocni!=nullptr) {
            Cvor *novi(new Cvor{pomocni->element, nullptr,nullptr});
            if(pocetak==nullptr) pocetak=novi;
            else {
                novi->sljedeci=kraj;
                kraj->prethodni=novi;
            }
            kraj=novi;
            pomocni=pomocni->prethodni;
        }
    }
    DvostraniRed& operator=(const DvostraniRed &dr)
    {
        if(this==&dr) return *this;
        while(pocetak!=nullptr) {
            kraj=pocetak;
            pocetak=pocetak->prethodni;
            kraj->sljedeci=nullptr;
            kraj->prethodni=nullptr;
            delete kraj;
        }
        Cvor * pomocni(dr.pocetak);
        while(pomocni!=nullptr) {
            Cvor *novi(new Cvor{pomocni->element, nullptr,nullptr});
            if(pocetak==nullptr) pocetak=novi;
            else {
                novi->sljedeci=kraj;
                kraj->prethodni=novi;
            }
            kraj=novi;
            pomocni=pomocni->prethodni;
        }
        broj_elemenata=dr.broj_elemenata;
        return*this;
    }
    void staviNaVrh(Tip el)
    {
        broj_elemenata++;
        if(pocetak==nullptr) {
            Cvor *novi(new Cvor{el, nullptr,nullptr});
            pocetak=novi;
            kraj=novi;
        } else {
            Cvor *novi(new Cvor{el,nullptr,pocetak});
            pocetak->sljedeci=novi;
            pocetak=novi;
        }
    }
    void staviNaCelo(Tip el)
    {
        broj_elemenata++;
        if(pocetak==nullptr) {
            Cvor *novi(new Cvor{el,nullptr,nullptr});
            pocetak=novi;
            kraj=novi;
        } else {
            Cvor *novi(new Cvor{el, kraj, nullptr});
            kraj->prethodni=novi;
            kraj=novi;
        }
    }
    Tip skiniSaVrha()
    {
        if(pocetak==nullptr) throw "Prazan dvostrani red";
        Tip vrh(pocetak->element);
        Cvor *pomocni(pocetak);
        pocetak=pocetak->prethodni;
        //pomocni->prethodni=nullptr;
        delete pomocni;
        broj_elemenata--;
        if(broj_elemenata==0) {
            kraj=nullptr;
            pocetak=nullptr;
        }
        return vrh;
    }
    Tip skiniSaCela()
    {
        if(pocetak==nullptr) throw "Prazan dvostrani red";
        Tip celo(kraj->element);
        Cvor *pomocni(kraj);
        kraj=kraj->sljedeci;
        delete pomocni;
        broj_elemenata--;
        if(broj_elemenata==0) {
            pocetak=nullptr;
            kraj=nullptr;
        }
        return celo;
    }
    Tip& celo()
    {
        if(pocetak==nullptr) throw "Prazan dvostrani red";
        return kraj->element;
    }
    Tip& vrh()
    {
        if(pocetak==nullptr) throw "Prazan dvostrani red";
        return pocetak->element;
    }
    void brisi()
    {
        if(pocetak==nullptr) throw "Prazan dvostrani red";
        while(pocetak!=nullptr) {
            kraj=pocetak;
            pocetak=pocetak->prethodni;
            kraj->prethodni=nullptr;

            delete kraj;

        }
        broj_elemenata=0;
    }
    int brojElemenata()
    {
        return broj_elemenata;
    }
};

template<typename Tip>
void Test1(DvostraniRed<Tip> &l)
{
    std::cout<<l.brojElemenata()<<std::endl;
}

template<typename Tip>
void Test2(DvostraniRed<Tip> &l)
{
    std::cout<<l.brojElemenata()<<" ";
    l.brisi();
    std::cout<<l.brojElemenata()<<std::endl;
}

template<typename Tip>
void Test3(DvostraniRed<Tip> &l)
{
    std::cout<<l.brojElemenata()<<" "<<l.vrh()<<" "<<l.celo()<<" ";
    while (l.brojElemenata()!=1) {
        std::cout<<l.skiniSaCela()<<" ";
    }
    std::cout<<l.brojElemenata()<<" "<<l.vrh()<<" "<<l.celo()<<std::endl;
}


template<typename Tip>
void Test4(DvostraniRed<Tip> &l)
{
    std::cout<<l.brojElemenata()<<" "<<l.vrh()<<" "<<l.celo()<<" ";
    while (l.brojElemenata()!=1) {
        l.skiniSaVrha();
    }
    std::cout<<l.brojElemenata()<<" "<<l.vrh()<<" "<<l.celo()<<std::endl;
}

template<typename Tip>
void Test5(DvostraniRed<Tip> &l, Tip element)
{
    l.brisi();
    for(int i=1;i<5;i++) l.staviNaVrh(element);
    for(int i=1;i<5;i++) l.staviNaCelo(element);
    std::cout<<l.brojElemenata()<<" "<<l.celo()<<" "<<l.vrh()<<std::endl;

}

template<typename Tip>
void Test6(DvostraniRed<Tip> &l, Tip element)
{
    DvostraniRed<Tip> s(l);
    std::cout<<s.brojElemenata();
    s.staviNaCelo(element);
    std::cout<<" "<<s.celo();
}


int main()
{
    DvostraniRed<int> dr;
    for (int i(0); i<5; i++)
        dr.staviNaVrh(i);
    std::cout<<std::endl<<"Test1"<<std::endl;
    Test1(dr);
    std::cout<<std::endl<<"Test1"<<std::endl;
    Test2(dr);

    for (int i(0); i<5; i++)
        dr.staviNaVrh(i);

    std::cout<<std::endl<<"Test3"<<std::endl;
    Test3(dr);

    for (int i(0); i<5; i++)
        dr.staviNaVrh(i);

    std::cout<<std::endl<<"Test4"<<std::endl;
    Test4(dr);
    std::cout<<std::endl<<"Test5"<<std::endl;
    Test5(dr,100);
    std::cout<<std::endl<<"Test6"<<std::endl;
    Test6(dr,20);
    std::cout << " Zadaća 2, Zadatak 1";
    return 0;
}
