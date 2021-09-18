//
// Created by 38760 on 18. 9. 2021..
//

#include <iostream>

template <typename Tip>
class Lista
{
public:
    Lista() {}
    virtual ~Lista() {}
    virtual int brojElemenata() const = 0;
    virtual Tip& operator [] (int pozicija) = 0;
    virtual const Tip& operator [] (int pozicija) const = 0;
    virtual Tip& trenutni() = 0;
    virtual const Tip& trenutni() const = 0;
    virtual bool prethodni() = 0;
    virtual bool sljedeci() = 0;
    virtual void pocetak() = 0;
    virtual void kraj() = 0;
    virtual void obrisi() = 0;
    virtual void dodajIspred(const Tip& el) = 0;
    virtual void dodajIza(const Tip& el) = 0;
};

template <typename Tip>
class Iterator;

template<typename Tip>
class DvostrukaLista : public Lista<Tip>
{
    struct Cvor {
        Tip element;
        Cvor *previous, *next;
    };
    int broj_elemenata;
    Cvor *pocetni,*tekuci,*krajnji;
public:
    DvostrukaLista() : Lista<Tip>(), pocetni(nullptr), tekuci(nullptr), krajnji(nullptr), broj_elemenata(0) {}
    ~DvostrukaLista()
    {
        while(pocetni!=nullptr) {
            tekuci=pocetni;
            pocetni=pocetni->previous;
            tekuci->previous=nullptr;
            tekuci->next=nullptr;
            delete tekuci;
        }
    }
    DvostrukaLista(const DvostrukaLista &d)
    {
        broj_elemenata=d.broj_elemenata;
        Cvor *pomocni1(d.pocetni),*pomocni2(nullptr);
        while(pomocni1!=nullptr) {
            Cvor *novi(new Cvor{pomocni1->element,nullptr,nullptr});
            if(pomocni2==nullptr) pocetni=novi;
            else {
                novi->next=pomocni2;
                pomocni2->previous=novi;
            }
            pomocni2=novi;
            if(pomocni1==d.tekuci) tekuci=novi;
            pomocni1=pomocni1->previous;
        }
        krajnji=pomocni2;

    }
    DvostrukaLista& operator=(const DvostrukaLista &d)
    {
        if(this==&d) return *this;
        while(pocetni!=nullptr) {
            tekuci=pocetni;
            pocetni=pocetni->previous;
            tekuci->previous=nullptr;
            tekuci->next=nullptr;
            delete tekuci;
        }
        broj_elemenata=d.broj_elemenata;
        Cvor *pomocni1(d.pocetni),*pomocni2(nullptr);
        while(pomocni1!=nullptr) {
            Cvor *novi(new Cvor{pomocni1->element,nullptr,nullptr});
            if(pomocni2==nullptr) pocetni=novi;
            else {
                novi->next=pomocni2;
                pomocni2->previous=novi;
            }
            pomocni2=novi;
            if(pomocni1==d.tekuci) tekuci=novi;
            pomocni1=pomocni1->previous;
        }
        krajnji=pomocni2;

        return *this;
    }
    int brojElemenata() const override
    {
        return broj_elemenata;
    }
    Tip& operator [] (int pozicija) override
    {
        if(pozicija<0 || pozicija>=broj_elemenata) throw "Neispravan indeks!";
        Cvor *pomocni(pocetni);
        for(int i=0; i<pozicija; i++) {
            pomocni=pomocni->previous;
        }
        return pomocni->element;
    }
    const Tip& operator [] (int pozicija) const override
    {
        if(pozicija<0 || pozicija>=broj_elemenata) throw "Neispravan indeks!";
        Cvor *pomocni(pocetni);
        for(int i=0; i<pozicija; i++) {
            pomocni=pomocni->previous;
        }
        return pomocni->element;
    }
    Tip& trenutni() override
    {
        if(pocetni==nullptr) throw "Prazna lista";
        return tekuci->element;
    }
    const Tip& trenutni() const override
    {
        if(pocetni==nullptr) throw "Prazna lista";
        return tekuci->element;
    }
    bool prethodni() override
    {
        if(pocetni==nullptr) throw "Prazna lista";
        if(tekuci==pocetni) return false;
        tekuci=tekuci->next;
        return true;
    }
    bool sljedeci() override
    {
        if(pocetni==nullptr) throw "Prazna lista";
        if(tekuci==krajnji) return false;
        tekuci=tekuci->previous;
        return true;
    }
    void pocetak() override
    {
        tekuci=pocetni;
    }
    void kraj() override
    {
        tekuci=krajnji;
    }
    void obrisi() override
    {
        if(pocetni==nullptr) throw "Prazna lista";
        broj_elemenata--;
        if(tekuci==pocetni) {
            tekuci=pocetni->previous;
            pocetni->previous=nullptr;
            delete pocetni;
            pocetni=tekuci;
        } else {
            Cvor *pomocni(tekuci->next);
            pomocni->previous=tekuci->previous;
            //pomocni->previous->next=tekuci->next;
            delete tekuci;
            tekuci=pomocni->previous;
            if(tekuci==nullptr) {
                krajnji=pomocni;
                tekuci=pomocni;
            }
        }

    }
    void dodajIspred(const Tip& el) override
    {
        if(pocetni==nullptr) {
            Cvor *novi(new Cvor{el, nullptr, nullptr});
            pocetni=novi;
            tekuci=novi;
            krajnji=novi;
        } else if(tekuci==pocetni) {
            Cvor *novi(new Cvor{el,pocetni,nullptr});
            tekuci->next=novi;
            pocetni=novi;
        } else {
            Cvor *pomocni(tekuci->next);
            Cvor *novi(new Cvor{el,tekuci,tekuci->next});
            pomocni->previous=novi;
            tekuci->next=novi;
        }
        broj_elemenata++;
    }
    void dodajIza(const Tip& el) override
    {
        if(pocetni==nullptr) {
            Cvor *novi(new Cvor{el,nullptr,nullptr});
            pocetni=novi;
            tekuci=novi;
            krajnji=novi;
        } else {
            Cvor *pomocni(tekuci->previous);
            Cvor *novi(new Cvor{el,tekuci->previous,tekuci});
            tekuci->previous=novi;
            if(tekuci!=krajnji) pomocni->next=novi;
            else if(tekuci==krajnji) krajnji=novi;
        }
        broj_elemenata++;
    }

    friend class Iterator<Tip>;
};

template<typename Tip>
Tip dajMaksimum(const Lista<Tip>& n)
{
    DvostrukaLista<Tip> p= DvostrukaLista<Tip>(*((DvostrukaLista<Tip>*)(&n)));
    Iterator<Tip> it(p);
    Tip max(it.trenutni());
    while(it.sljedeci()) {
        if(it.trenutni() > max ) max=it.trenutni();
    }
    return max;
}

template<typename Tip>
class Iterator
{
    const DvostrukaLista<Tip> *dLista;
    typename DvostrukaLista<Tip>::Cvor *tekuci;
public:
    Iterator(const DvostrukaLista<Tip> &l) : dLista(&l), tekuci(l.pocetni) {}
    Tip trenutni()
    {
        return tekuci->element;
    }
    bool sljedeci()
    {
        if(tekuci->previous == nullptr) return false;
        tekuci=tekuci->previous;
        return true;
    }
    bool prethodni()
    {
        if(tekuci->next == nullptr) return false;
        tekuci=tekuci->next;
        return true;
    }
    void pocetak()
    {
        tekuci=dLista->pocetni;
    }
    void kraj()
    {
        tekuci=dLista->krajnji;
    }

};

template<typename Tip>
void Test1(DvostrukaLista<Tip> &l)
{
    std::cout<<l.brojElemenata()<<std::endl;
}

template<typename Tip>
void Test2(DvostrukaLista<Tip> &l)
{
    l.pocetak();
    std::cout<<l.trenutni()<<" ";
    l.sljedeci();
    l.sljedeci();
    std::cout<<l.trenutni()<<" ";
    l.prethodni();
    std::cout<<l.trenutni()<<" ";
    l.obrisi();
    std::cout<<l.trenutni();
}

template<typename Tip>
void Test3(DvostrukaLista<Tip> &l)
{
    l.pocetak();
    std::cout<<l.trenutni();
    l.kraj();
    std::cout<<" "<<l.trenutni();
}


template<typename Tip>
void Test4(DvostrukaLista<Tip> &l)
{
    std::cout<<l.brojElemenata()<<" ";
    while(l.brojElemenata()!=0) {
        l.obrisi();
    }
    std::cout<<l.brojElemenata();
}

template<typename Tip>
void Test5(DvostrukaLista<Tip> &l, Tip element)
{
    std::cout<<l.brojElemenata()<<std::endl;
    l.kraj();
    l.dodajIza(element);
    l.pocetak();
    l.dodajIza(element);
    std::cout<<l.brojElemenata()<<std::endl;
}

template<typename Tip>
void Test6(DvostrukaLista<Tip> &l, Tip element)
{
    l.dodajIspred(element);
    l.dodajIza(element);
    l.pocetak();
    l.dodajIspred(element);
    l.kraj();
    l.dodajIza(element);
}

template<typename Tip>
void Test7(DvostrukaLista<Tip> &l,Tip element)
{
    for(int i=0;i<l.brojElemenata();i++) std::cout<<l[i]<<" ";
    std::cout<<std::endl<<l[0]<<" ";
    l[0]=element;
    std::cout<<l[0]<<std::endl;
}

int main()
{
    DvostrukaLista<int> lista;
    for (int i(1); i<=5; i++) lista.dodajIspred(i);
    std::cout<<std::endl<<"Test7"<<std::endl;
    Test7(lista, 1);
    std::cout<<std::endl<<"Test6"<<std::endl;
    Test6(lista,6);
    for(int i=0;i<lista.brojElemenata();i++) std::cout<<lista[i]<<" ";
    std::cout<<std::endl<<"Test5"<<std::endl;
    Test5(lista,0);
    for(int i=0;i<lista.brojElemenata();i++) std::cout<<lista[i]<<" ";
    std::cout<<std::endl<<"Test1"<<std::endl;
    Test1(lista);
    std::cout<<std::endl<<"Test2"<<std::endl;
    Test2(lista);
    std::cout<<std::endl<<"Test3"<<std::endl;
    Test3(lista);
    std::cout<<std::endl<<"Test4"<<std::endl;
    Test4(lista);
    std::cout << std::endl <<"Zadaća 1, Zadatak 1";
    return 0;
}