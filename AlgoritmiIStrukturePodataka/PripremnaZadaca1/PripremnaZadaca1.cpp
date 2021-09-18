//
// Created by 38760 on 18. 9. 2021..
//

#include "PripremnaZadaca1.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>
template <typename Tip>
class Lista {
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

const int vel=100;
template <typename Tip>
class NizLista : public Lista<Tip> {
    Tip** nizlista;
    int kapacitet, velicina, tekuci;

public:
    NizLista(): Lista<Tip> (), nizlista(new Tip*[vel]{}),kapacitet(vel),velicina(0),tekuci(0) {}
    ~NizLista () {
        for(int i=0;i<velicina;i++) delete nizlista[i];
        delete[] nizlista;
    }
    NizLista(const NizLista& l) : Lista<Tip>(), nizlista(new Tip*[l.kapacitet]{}),kapacitet(l.kapacitet),velicina(l.velicina),tekuci(l.tekuci){
        for(int i=0;i<l.velicina;i++) nizlista[i]=new Tip(*l.nizlista[i]);
    }
    NizLista& operator = (const NizLista &l) {
        Tip** novi(new Tip*[l.kapacitet]);
        for(int i=0;i<l.velicina;i++) novi[i]=new Tip(*l.nizlista[i]);
        for(int i=0;i<kapacitet;i++) delete nizlista[i];
        delete [] nizlista;
        nizlista=novi;
        kapacitet=l.kapacitet;
        velicina=l.velicina;
        tekuci=l.tekuci;
        return *this;
    }
    int brojElemenata() const {
        return velicina;
    };
    Tip& operator [] (int pozicija) {
        if(pozicija<0 || pozicija>=velicina) throw "Neispravan indeks";
        return *nizlista[pozicija];
    }
    const Tip& operator [] (int pozicija) const {
        if(pozicija<0 || pozicija>=velicina) throw "Neispravan indeks";
        return *nizlista[pozicija];
    }
    Tip& trenutni() {
        if(velicina==0) throw "Prazan niz";
        return *nizlista[tekuci];
    }
    const Tip& trenutni() const {
        if(velicina==0) throw "Prazan niz";
        return *nizlista[tekuci];
    }
    bool prethodni() {
        if(tekuci==0) return false;
        tekuci--;
        return true;
    }
    bool sljedeci() {
        if(tekuci==velicina-1) return false;
        tekuci++;
        return true;
    }
    void pocetak() {
        if(velicina!=0) tekuci=0;
    }
    void kraj() {
        if(velicina!=0) tekuci=velicina-1;
    }


    void obrisi() {
        if(velicina==0) throw "Prazan niz";
        delete nizlista[tekuci];
        for(int i=tekuci;i<velicina-1;i++) nizlista[i]=nizlista[i+1];
        velicina--;
        if(tekuci==velicina && velicina>0) tekuci--;
    }

    void dodajIspred(const Tip& el) {
        if(velicina==kapacitet) {
            kapacitet*=2;
            Tip** novi=new Tip*[kapacitet];
            for(int i=0;i<velicina;i++) novi[i]=nizlista[i];
            delete [] nizlista;
            nizlista=novi;
        }

        for(int i=velicina;i>tekuci;i--) nizlista[i]=nizlista[i-1];
        nizlista[tekuci]=new Tip(el);
        velicina++;
        if(velicina!=1 && velicina!=0) tekuci++;
    }

    void dodajIza(const Tip& el) {

        if(velicina==kapacitet) {
            kapacitet*=2;
            Tip** novi=new Tip*[kapacitet];
            for(int i=0;i<velicina;i++) novi[i]=nizlista[i];
            delete [] nizlista;
            nizlista=novi;
        }

        if(velicina==0 || velicina==1) {
            nizlista[velicina]=new Tip(el);
            velicina++;
        }

        else if(velicina>=2) {
            velicina++;
            for(int i=velicina;i>tekuci+1;i--) nizlista[i]=nizlista[i-1];
            nizlista[tekuci+1]=new Tip(el);
        }
    }
};

template <typename Tip>
class JednostrukaLista : public Lista<Tip> {
    struct Cvor {
        Tip info;
        Cvor* sljedeci;
    };
    Cvor *p, *k, *tekuci;
    int velicina;
public:
    JednostrukaLista() : Lista<Tip>(), p(nullptr),k(nullptr),tekuci(nullptr),velicina(0) {}
    ~JednostrukaLista() {
        while(p!=nullptr) {
            tekuci=p;
            p=p->sljedeci;
            delete tekuci;
        }
    }
    JednostrukaLista (const JednostrukaLista &l) {
        Cvor* pom(l.p),*pom2(nullptr);
        while(pom!=nullptr) {
            Cvor *novi(new Cvor{pom->info,nullptr});
            if(pom2==nullptr) p=novi;
            else pom2->sljedeci=novi;
            pom2=novi;
            if(pom==l.tekuci) tekuci=novi;
            pom=pom->sljedeci;
        }
        k=pom2;
        velicina=l.velicina;
    }
    JednostrukaLista& operator =(const JednostrukaLista &l) {
        if(this==&l) return *this;
        while(p!=nullptr) {
            tekuci=p;
            p=p->sljedeci;
            delete tekuci;
        }
        Cvor* pom(l.p),*pom2(nullptr);
        while(pom!=nullptr) {
            Cvor *novi(new Cvor{pom->info,nullptr});
            if(pom2==nullptr) p=novi;
            else pom2->sljedeci=novi;
            pom2=novi;
            if(pom==l.tekuci) tekuci=novi;
            pom=pom->sljedeci;
        }
        k=pom2;
        velicina=l.velicina;
        return *this;
    }
    int brojElemenata() const {
        return velicina;
    }
    Tip& operator [] (int pozicija) {
        if(pozicija<0 || pozicija>velicina) throw "Neispravan indeks";
        Cvor* pom(p);
        for(int i=0;i<pozicija;i++) pom=pom->sljedeci;
        return pom->info;
    }
    const Tip& operator [] (int pozicija) const {
        if(pozicija<0 || pozicija>velicina) throw "Neispravan indeks";
        Cvor* pom(p);
        for(int i=0;i<pozicija;i++) pom=pom->sljedeci;
        return pom->info;
    }
    Tip& trenutni() {
        if(p==nullptr) throw "Preazna lista";
        return tekuci->info;
    }
    const Tip& trenutni() const {
        if(p==nullptr) throw "Preazna lista";
        return tekuci->info;
    }
    bool prethodni() {
        if(p==nullptr) throw "Preazna lista";
        if(tekuci==p) return false;
        Cvor*pom(p);
        while(pom->sljedeci!=tekuci) pom=pom->sljedeci;
        tekuci=pom;
        return true;
    }
    bool sljedeci() {
        if(p==nullptr) throw "Preazna lista";
        if(tekuci==k) return false;
        tekuci=tekuci->sljedeci;
        return true;
    }
    void pocetak() {
        if(p!=nullptr) tekuci=p;
    }
    void kraj() {
        if(p!=nullptr && velicina>1) tekuci=k;
    }
    void obrisi() {
        if(p==nullptr) throw "Prazna lista";
        velicina--;
        if(tekuci==p) {
            p=p->sljedeci;
            delete tekuci;
            tekuci=p;
            if(velicina==0) k=nullptr;
        }
        else {
            Cvor*pom(p);
            while(pom->sljedeci!=tekuci) pom=pom->sljedeci;
            pom->sljedeci=tekuci->sljedeci;
            delete tekuci;
            tekuci=pom->sljedeci;
            if(tekuci==nullptr) {
                k=pom;
                tekuci=pom;
            }
        }
    }
    void dodajIspred(const Tip& el) {
        velicina++;
        if(p==nullptr) {
            Cvor* novi(new Cvor{el,nullptr});
            p=novi;
            k=novi;
            tekuci=novi;
        }
        else if(tekuci==p) {
            Cvor* novi(new Cvor{el,tekuci});
            p=novi;
        }
        else {
            Cvor*pom(p);
            while(pom->sljedeci!=tekuci) pom=pom->sljedeci;
            Cvor* novi(new Cvor{el,pom->sljedeci});
            pom->sljedeci=novi;
        }
    }
    void dodajIza(const Tip& el) {
        velicina++;
        if(p==nullptr) {
            Cvor* novi(new Cvor{el,nullptr});
            p=novi;
            k=novi;
            tekuci=novi;
        } else {
            Cvor* novi(new Cvor{el,tekuci->sljedeci});
            tekuci->sljedeci=novi;
            if(tekuci==k) k=novi;
        }
    }

    void Obrni(int n,int m) {
        int s=((m-n+1)/2)+n;
        if((m-n+1)%2==0) s-=1;
        Cvor *naN=nullptr,*naS=nullptr,*naM=nullptr,*brisanje=nullptr,*pom=nullptr;
        int i=0;
        pom=p;
        while(pom!=nullptr) {
            if(i==n-1) naN=pom;
            if(i==m) naM=pom;
            if(i==s-1) naS=pom;
            i++;
            pom=pom->sljedeci;
        }

        //brisanje
        brisanje=naS->sljedeci;
        naS->sljedeci=brisanje->sljedeci;
        delete brisanje;

        //obrtanje
        // naN->sljedeci=naM;
        Cvor *q=naM->sljedeci,*r=nullptr;
        pom=naN->sljedeci;
        naN->sljedeci=naM;
        // naM=naM->sljedeci;
        i=n;
        while(pom!=naM->sljedeci) {
            if(i==m) break;
            r=q;
            q=pom;
            pom=pom->sljedeci;
            q->sljedeci=r;
            i++;
        }
    }
    void PremjestiSaMax(int n,int m, int k) {
        Cvor* pom = nullptr;
        Cvor *naN=nullptr,*naM=nullptr,*naK=nullptr;
        int i=0;
        pom=p;
        while(pom!=nullptr) {
            if(i==n-1) naN=pom;
            if(i==m) naM=pom;
            if(i==k) naK=pom;
            i++;
            pom=pom->sljedeci;
        }

        pom=naN;
        i=n-1;
        Tip maxi=pom->info;
        while(i!=m+1) {
            if(pom->info > maxi) maxi=pom->info;
            i++;
            pom=pom->sljedeci;
        }

        if(k<n && n-k==1) {
            i=0;
        } else {
            pom=naM->sljedeci;
            naM->sljedeci=naK->sljedeci;
            naK->sljedeci=naN->sljedeci;
            naN->sljedeci=pom;
        }

        Cvor *max=new Cvor{maxi,nullptr};
        pom=naM->sljedeci;
        naM->sljedeci=max;
        max->sljedeci=pom;
    }
    void Premjesti (int n,int m,int k) {
        Cvor*pom(p), *naN=nullptr,*naM=nullptr,*naK=nullptr;
        int i=0;
        while(pom!=nullptr) {
            if(i==n-1) naN=pom;
            if(i==m) naM=pom;
            if(i==k-1) naK=pom;
            i++;
            pom=pom->sljedeci;
        }

        pom=naN->sljedeci;
        naN->sljedeci=naM->sljedeci;
        naM->sljedeci=naK->sljedeci;
        naK->sljedeci=pom;

        Cvor *q=naM,*r=nullptr;
        naK->sljedeci=naM;
        Cvor * pom1=naM->sljedeci;
        naM->sljedeci=pom;
        int vel=m-n+1;
        i=0;
        while(1) {
            if(i==vel) {
                pom->sljedeci=pom1;
                break;
            }
            r=q;
            q=pom;
            pom=pom->sljedeci;
            q->sljedeci=r;
            i++;
        }

    }
    int Suma(Cvor *p,int &s) {
        if(p==nullptr) return s;
        s+=p->info;
        return Suma(p->sljedeci,s);

    }
    void brisiUnazadManjeOdSumePrethodnih() {
        int vel=brojElemenata(),i=0;
        Cvor *pom=p,*pom1=nullptr,*ppotencijalnog=nullptr;
        while(vel-1>=0) {
            pom=p;
            i=0;
            while(i!=vel-1) {
                if(i==vel) {
                    ppotencijalnog=pom;
                    break;
                }
                if(i==vel-2)  ppotencijalnog=pom;
                else ppotencijalnog=pom->sljedeci;
                //if(i==vel-1) ppotencijalnog=pom;
                pom=pom->sljedeci;
                if(pom->sljedeci!=nullptr) pom1=pom->sljedeci;
                else pom1=pom;
                i++;
            }
            int s=0;
            int suma=Suma(pom->sljedeci,s);
            if(pom->info < suma) {
                if(pom==p) {
                    p=p->sljedeci;
                    std::cout<<pom->info<<" ";
                    delete pom;
                } else {
                    if(pom!=nullptr) ppotencijalnog->sljedeci=pom->sljedeci;
                    std::cout<<pom->info<<" ";
                    delete pom;
                }
            }
            vel--;
        }
    }

    void brisiodAdoB(int a,int b) {
        Cvor *pom=p,*nA=nullptr, *nB=nullptr,*brisido=nullptr,*brisi=nullptr;
        int iA=0,iB=0,i=0;
        while(pom!=nullptr) {
            if(pom->info==a) {nA=pom; iA=i;}
            if(pom->info==b) {nB=pom; iB=i;}
            i++;
            pom=pom->sljedeci;
        }
        if(iA<iB) {pom=nA->sljedeci; nA->sljedeci=nB; brisido=nB;}
        else {pom=nB->sljedeci; nB->sljedeci=nA; brisido=nA;}
        while(pom->sljedeci!=brisido) {
            brisi=pom;
            pom=pom->sljedeci;
            delete brisi;
        }
    }
};

/*template<typename Tip>
void Test1NL(NizLista<Tip> & nl) {
  std::cout<<"Test1"<<std::endl;
  std::cout<<nl.brojElemenata()<<" ";
  while(nl.brojElemenata()!=0) nl.obrisi();
  std::cout<<nl.brojElemenata();
  std::cout<<std::endl;
}

template<typename Tip>
void Test2NL(NizLista<Tip> & nl) {
  std::cout<<"Test2"<<std::endl;
  nl.obrisi();
  nl.pocetak();
  std::cout<<nl.trenutni()<<" ";
  nl.kraj();
  std::cout<<nl.trenutni();
  nl.pocetak();
  nl.obrisi();
  nl.kraj();
  nl.obrisi();
  std::cout<<std::endl;
}

template<typename Tip>
void Test3NL(NizLista<Tip> & nl, Tip element) {
  std::cout<<"Test3 - dodavanje elemenata"<<std::endl;
  nl.dodajIspred(element);
  nl.dodajIza(element);
  nl.pocetak();
  nl.dodajIspred(element);
  nl.dodajIza(element);
  nl.kraj();
  nl.dodajIspred(element);
  nl.dodajIza(element);
  std::cout<<std::endl;
}

template<typename Tip>
void Test4NL(NizLista<Tip> & nl, Tip element) {
  std::cout<<"Test4"<<std::endl;
  nl.pocetak();
  nl.dodajIspred(element);
  nl.kraj();
  nl.dodajIza(element);
  for(int i=0;i<nl.brojElemenata();i++) std::cout<<nl[i]<<" ";
  std::cout<<std::endl;
}

template<typename Tip>
void Test5NL(NizLista<Tip> & nl, Tip element) {
  std::cout<<"Test5"<<std::endl;
  for(int i=0;i<nl.brojElemenata();i++) nl[i]=element;
  while(nl.sljedeci()) std::cout<<nl.trenutni()<<" ";
  nl.kraj();
  std::cout<<std::endl;
  while(nl.prethodni()) std::cout<<nl.trenutni();
  std::cout<<std::endl;
}

template<typename Tip>
void Test1L(JednostrukaLista<Tip> & l) {
  std::cout<<"Test1"<<std::endl;
  std::cout<<l.brojElemenata()<<" ";
  while(l.brojElemenata()!=0) l.obrisi();
  std::cout<<l.brojElemenata();
  std::cout<<std::endl;
}

template<typename Tip>
void Test2L(JednostrukaLista<Tip> & l) {
  std::cout<<"Test2"<<std::endl;
  l.obrisi();
  l.pocetak();
  std::cout<<l.trenutni()<<" ";
  l.kraj();
  std::cout<<l.trenutni();
  l.pocetak();
  l.obrisi();
  l.kraj();
  l.obrisi();
  std::cout<<std::endl;
}

template<typename Tip>
void Test3L(JednostrukaLista<Tip> & l, Tip element) {
  std::cout<<"Test3 - dodavanje elemenata"<<std::endl;
  l.dodajIspred(element);
  l.dodajIza(element);
  l.pocetak();
  l.dodajIspred(element);
  l.dodajIza(element);
  l.kraj();
  l.dodajIspred(element);
  l.dodajIza(element);
  std::cout<<std::endl;
}

template<typename Tip>
void Test4L(JednostrukaLista<Tip> & l, Tip element) {
  std::cout<<"Test4"<<std::endl;
  l.pocetak();
  l.dodajIspred(element);
  l.kraj();
  l.dodajIza(element);
  for(int i=0;i<l.brojElemenata();i++) std::cout<<l[i]<<" ";
  std::cout<<std::endl;
}

template<typename Tip>
void Test5L(JednostrukaLista<Tip> & l, Tip element) {
  std::cout<<"Test5"<<std::endl;
  for(int i=0;i<l.brojElemenata();i++) l[i]=element;
  while(l.sljedeci()) std::cout<<l.trenutni()<<" ";
  l.kraj();
  std::cout<<std::endl;
  while(l.prethodni()) std::cout<<l.trenutni();
  std::cout<<std::endl;
}*/

int tt ()
{
    JednostrukaLista<int> l;
    for(int i=0;i<9;i++) {
        l.dodajIspred(i+1);
    }

    l.Premjesti(2,4,7);
    std::cout<<std::endl;
    l.pocetak();
    do {
        std::cout<<l.trenutni()<<" ";
    }while(l.sljedeci());
    std::cout << "\nPripremna Zadaća 2 2019/2020, Zadatak 1";
    return 0;
}
