//
// Created by 38760 on 18. 9. 2021..
//

#include <iostream>
#include <vector>

template<typename Tip>
class Iterator;
//preipremna zadaca4
template<typename Tip>
class Red
{
    struct Cvor {
        Tip element;
        Cvor *sljedeci;
    };
    Cvor *pocetak,*kraj;
    int broj_elemenata;
public:
    Red() : pocetak(nullptr), kraj(nullptr), broj_elemenata(0) {}
    ~Red()
    {
        while(pocetak!=nullptr) {
            kraj=pocetak;
            pocetak=pocetak->sljedeci;
            delete kraj;
        }
    }
    Red(const Red& r) : pocetak(nullptr), kraj(nullptr), broj_elemenata(0)
    {
        Cvor *pomocni(r.pocetak);
        while(pomocni!=nullptr) {
            Cvor *novi(new Cvor{pomocni->element, nullptr});
            if(pocetak==nullptr) pocetak=novi;
            else kraj->sljedeci=novi;
            kraj=novi;
            pomocni=pomocni->sljedeci;
        }
        broj_elemenata=r.broj_elemenata;
    }
    Red& operator=(const Red& r)
    {
        if(this==&r) return *this;
        while(pocetak!=nullptr) {
            kraj=pocetak;
            pocetak=pocetak->sljedeci;
            delete kraj;
        }
        Cvor *pomocni(r.pocetak);
        while(pomocni!=nullptr) {
            Cvor *novi(new Cvor{pomocni->element, nullptr});
            if(pocetak==nullptr) pocetak=novi;
            else kraj->sljedeci=novi;
            kraj=novi;
            pomocni=pomocni->sljedeci;
        }
        broj_elemenata=r.broj_elemenata;
        return *this;
    }
    void brisi()
    {
        if(pocetak==nullptr) throw "Prazan red";
        Cvor *pomocni(nullptr);
        while(pocetak!=nullptr) {
            pomocni=pocetak;
            pocetak=pocetak->sljedeci;
            delete pomocni;
        }
        kraj=nullptr;
        broj_elemenata=0;
    }
    void stavi(const Tip& el)
    {
        broj_elemenata++;
        if(broj_elemenata==1) {
            Cvor *novi(new Cvor{el,nullptr});
            pocetak=novi;
            kraj=novi;
            novi=nullptr;
        } else {
            Cvor *novi(new Cvor{el,nullptr});
            kraj->sljedeci=novi;
            kraj=novi;
            novi=nullptr;
        }
    }
    Tip skini()
    {
        if(pocetak==nullptr) throw "Prazan red";
        Cvor *pomocni(pocetak);
        pocetak=pocetak->sljedeci;
        Tip celo(pomocni->element);
        delete pomocni;
        broj_elemenata--;
        return celo;
    }
    Tip& celo()
    {
        if(pocetak==nullptr) throw "Prazan red";
        return pocetak->element;
    }
    int brojElemenata()
    {
        return broj_elemenata;
    }
    friend class Iterator<Tip>;
};

//testovi za zamger - pripremna zadaca4
/*template<typename Tip>
void Test1(Red<Tip> &r) {
    std::cout<<r.brojElemenata()<<std::endl;;
}
template<typename Tip>
void Test2(Red<Tip> &r) {
    std::cout<<r.brojElemenata()<<" ";
    Red<Tip> t1=r, t2(r);
    std::cout<<t1.brojElemenata()<<" "<<t2.brojElemenata()<<"    ";
    std::cout<<t1.celo()<<" "<<++t2.celo()<<std::endl;
}
template<typename Tip>
void Test3(Red<Tip> &r,Tip el) {
    std::cout<<r.brojElemenata()<<" ";
    r.stavi(el);
    r.stavi(el);
    std::cout<<r.brojElemenata()<<" "<<std::endl;
}
template<typename Tip>
void Test4(Red<Tip> &r) {
    while(r.brojElemenata()!=0) {
        r.celo()++;
        std::cout<<r.celo()<<" ";
        r.skini();
    }
    std::cout<<std::endl;
}
template<typename Tip>
void Test5(Red<Tip> &r,Tip el) {
    r.brisi();
    std::cout<<r.brojElemenata()<<" ";
    for(int i=0;i<5;i++) r.stavi(el);
    std::cout<<r.brojElemenata()<<" ";
    for(int i=0;i<5;i++) r.skini();
    std::cout<<r.brojElemenata()<<" ";
    std::cout<<std::endl;
}
*/

//iterator za red
template<typename Tip>
class Iterator {
    const Red<Tip> *red;
    typename Red<Tip>::Cvor *tekuci;
public:
    Iterator(const Red<Tip> &r) : red(&r), tekuci(nullptr){}
    Tip trenutni () {
        return tekuci->element;
    }
    bool sljedeci() {
        if(tekuci==red->kraj) return false;
        tekuci=tekuci->sljedeci;
        return true;
    }
    bool prethodni () {
        if(tekuci==red->pocetni) return false;
        typename Red<Tip>::Cvor *pomocni(red->pocetak);
        while(pomocni->sljedeci!=tekuci) pomocni=pomocni->sljedeci;
        tekuci=pomocni;
        return true;
    }
    void pocetak() {
        tekuci=red->pocetak;
    }
    void kraj() {
        tekuci=red->kraj;
    }


};


//pomocna funkcija za zadatak1
template<typename Tip>
Tip srednjaVrijednost(const Red<Tip> &r) {
    Tip srednja{};
    Iterator<Tip> it(r);
    it.pocetak();
    while(!it.sljedeci()) {
        srednja+=it.trenutni;
    }
    return srednja/r.brojElemenata();
}
/*
Napisati funkciju koja prima red i modifikuje ga tako da budu izbačene sve vrijednosti veće od
srednje vrijednosti njegovih elemenata. Ustanoviti koja je vremenska kompleksnost rješenja.
Napomena: Zadatak riješiti koristeći samo ulazni red, nije dozvoljeno korištenje pomoćnih
kolekcija.
*/
template <typename Tip>
void Modifikuj(Red<Tip> &r) {
    Tip srednja_vrijednost=srednjaVrijednost(r);
    Iterator<Tip> it(r);
    it.pocetak();
    while(!it.sljedeci()) {
        if(it.trenutni()>srednja_vrijednost) it.tekuci.obrisi();
    }
}

/*
Napisati funkciju koja prima stek, red i varijablu pocetnaDuzinaReda tipa int koja će
elemente iz reda ubaciti na dno steka u obrnutom redoslijedu. Primjer: Neka je dat red sa
elementima {1, 2, 3, 4} gdje je element 1 na čelu reda i stek sa elementima {5, 6, 7, 8} gdje je
element 8 na vrhu steka. Rezultantni stek se sastoji od elemenata {1, 2, 3, 4, 5, 6, 7, 8} gdje je
element 8 na vrhu steka. Ustanoviti koja je vremenska kompleksnost rješenja.
*/
//stek za prvi dio zadatka
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


//27012020
int sumaSteka(Stek<int> s) {
    if(s.brojElemenata()==0) return 0;
    int prvi=s.skini();
    int suma=sumaSteka(s);
    s.stavi(prvi);
    return suma+prvi;
}
int pretraga(std::vector<Stek<int>> vs, Red<int> r) {
    int velReda=r.brojElemenata(),j=0,sumaReda=0;
    while(j!=velReda) {
        sumaReda+=r.celo();
        r.stavi(r.skini());
        j++;
    }
    int zapamtiIndeks=0, razlikaSumeStekaIReda=0,zapamtiSumu=0;
    zapamtiSumu=sumaSteka(vs[0]);
    razlikaSumeStekaIReda=abs(zapamtiSumu-sumaReda);
    for(int i=1;i<vs.size();i++) {
        int suma=sumaSteka(vs[i]);
        if(abs(suma-sumaReda)<razlikaSumeStekaIReda) {
            razlikaSumeStekaIReda=abs(suma-sumaReda);
            zapamtiSumu=suma;
            zapamtiIndeks=i;
        } else if(abs(suma-sumaReda)==razlikaSumeStekaIReda) {
            if(suma<zapamtiSumu) {
                zapamtiSumu=suma;
                zapamtiIndeks=i;
            }
        }
    }
    return zapamtiIndeks;
}
//funkcija za zadatak2
/*template<typename Tip>
void funkcija(Stek<Tip> s,  Red<Tip> r, int pocetnaDuzinaReda) {
    Stek<Tip> rezultantni;
    for(int i=0;i<r.brojElemenata();i++) {
        rezultantni.stavi(r.skini());
    }
    Stek
}
*/
//26112019 - zadatak 3
int nadjiMax(const std::vector<int>& v, int pocetak,int kraj) {
    int sredina=(pocetak+kraj)/2;
    if(v[pocetak]<v[sredina] && v[sredina]>v[kraj]) {
        if(v[sredina]>v[sredina-1] && v[sredina]>v[sredina+1]) return v[sredina];
        if(v[sredina]<v[sredina-1] && v[sredina]>v[sredina+1]) return nadjiMax(v,pocetak,sredina-1);
        else return nadjiMax(v,sredina+1,kraj);
    }
    else {
        if(v[pocetak]> v[kraj]) return v[pocetak];
        return v[kraj];
    }
}
int nadjiMin(const std::vector<int>&v,int pocetak,int kraj) {
    int sredina=(pocetak+kraj-1)/2;
    if(v[pocetak]>v[sredina] && v[kraj]>v[sredina]) {
        if(v[sredina]<v[sredina-1] && v[sredina]<v[sredina+1]) return v[sredina];
        if(v[sredina-1]<v[sredina] && v[sredina-1]<v[sredina+1]) return nadjiMin(v,pocetak,sredina-1);
        else nadjiMin(v,sredina+1,kraj);
    } else {
        if(v[pocetak]<v[kraj]) return v[pocetak];
        return v[kraj];
    }
}
int funkcijaAV(Red<std::vector<int>> &r) {
    int vel=r.brojElemenata();
    int i=0;
    int max=nadjiMax(r.celo(),0,r.celo().size()-1);
    int min=nadjiMin(r.celo(),0,r.celo().size()-1);
    int pmax,pmin;
    r.stavi(r.skini());
    i++;
    while(i!=vel) {
        pmax=nadjiMax(r.celo(),0,r.celo().size()-1);
        pmin=nadjiMin(r.celo(),0,r.celo().size()-1);
        r.stavi(r.skini());
        if(pmax>max) max=pmax;
        if(pmin<min) min=pmin;
        i++;
    }
    return max+min;
}
//06022017

void idiDoKrajaReda(Red<int> &r, int velicina) {
    int i=0;
    while(i!=velicina-1) {
        r.stavi(r.skini());
        i++;
    }
}

void idiDoKraja(Stek<int>&s, Red<int> &r) {
    if(s.brojElemenata()==0) {
        int velReda=r.brojElemenata();
        while(velReda-1>=0) {
            idiDoKrajaReda(r,velReda);
            int saReda=r.skini();
            if(saReda%2==0) {s.stavi(saReda); }
            else r.stavi(saReda);
            velReda--;
        }
        return;
    }
    int sk=s.skini();
    idiDoKraja(s,r);
    s.stavi(sk);
}

void funkcija(Stek<int> &s, Red<int> &r) {
    if(s.brojElemenata()==0) {
        int velReda=r.brojElemenata();
        while(velReda>0) {
            idiDoKrajaReda(r,velReda);
            int saReda=r.skini();
            if(saReda%2==0) {s.stavi(saReda); }
            else r.stavi(saReda);
            velReda--;
        }
        return;
    }
    int sk=s.skini();
    funkcija(s,r);
    s.stavi(sk);
}
int main()
{

    std::vector<Stek<int>> vs;
    Red<int> r;
    r.stavi(100);
    r.stavi(101);
    r.stavi(102);
    r.stavi(103);
    r.stavi(104);
    r.stavi(105);
    r.stavi(106);

    Stek<int> s1;
    s1.stavi(2);
    s1.stavi(3);
    s1.stavi(4);
    s1.stavi(5);
    s1.stavi(6);


    funkcija(s1,r);
    // idiDoKrajaReda(r,r.brojElemenata()-1);

    while(s1.brojElemenata()!=0) {
        std::cout<<s1.skini()<<" ";
    }
    std::cout<<"\n";
    while(r.brojElemenata()!=0) {
        std::cout<<r.skini()<<" ";
    }




    std::cout << "Pripremna Zadaca Za Vjezbu 4, Zadatak 1";
    return 0;
}