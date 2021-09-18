//
// Created by 38760 on 18. 9. 2021..
//

#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
using namespace std;

template <typename TipKljuca, typename TipVrijednosti>
class Mapa {
public :
    Mapa () {}
    virtual TipVrijednosti operator[] (const TipKljuca& kljuc) const = 0;
    virtual TipVrijednosti& operator[] (const TipKljuca& kljuc) = 0;
    virtual int brojElemenata() const = 0;
    virtual void obrisi() = 0;
    virtual void obrisi(const TipKljuca& kljuc) = 0;
    virtual ~Mapa() {};
};



template<typename TipKljuca, typename TipVrijednosti>
class HashMapa : public Mapa<TipKljuca,TipVrijednosti>
{
    std::tuple<TipKljuca,TipVrijednosti,bool> **niz;
    int max, brojEl;
    unsigned int (*pokNaFun) (TipKljuca, unsigned int);
public:
    HashMapa() {
        niz=new std::tuple<TipKljuca,TipVrijednosti,bool> * [1000]{};
        max=1000;
        brojEl=0;
        pokNaFun=nullptr;
    }
    HashMapa (const HashMapa<TipKljuca,TipVrijednosti> &k) {
        niz=new std::tuple<TipKljuca,TipVrijednosti,bool> * [k.max]{};
        max=k.max;
        brojEl=k.brojEl;
        pokNaFun=k.pokNaFun;
        for(int i=0;i<max;i++) {
            if(k.niz[i] != nullptr) niz[i]=new std::tuple<TipKljuca,TipVrijednosti,bool>(*k.niz[i]);
        }
    }


    HashMapa& operator= (const HashMapa<TipKljuca,TipVrijednosti> &k) {
        if(this == &k) return *this;
        for(int i=0;i<max;i++) {
            delete niz[i];
            niz[i]=nullptr;
        }
        delete[] niz;
        niz=new std::tuple<TipKljuca,TipVrijednosti,bool>*[k.max]{};
        max=k.max;
        brojEl=k.brojEl;
        pokNaFun=k.pokNaFun;
        for(int i=0;i<k.max;i++)
            if(k.niz[i]!=nullptr) niz[i]=new std::tuple<TipKljuca,TipVrijednosti,bool>(*k.niz[i]);

        return *this;
    }

    ~HashMapa() {
        for(int i=0;i<max;i++)  {
            delete niz[i];
            niz[i]=nullptr;
        }
        delete[] niz;

    }

    TipVrijednosti operator[] (const TipKljuca& kljuc) const {
        if(!pokNaFun) throw "Nema hash funkcije, postavite hash funkciju";
        unsigned int indeks=pokNaFun(kljuc,max);
        int i=0;
        do {
            if(niz[indeks]!=nullptr && std::get<0>(*niz[indeks])==kljuc && !std::get<2>(*niz[indeks])) return std::get<1>(*niz[indeks]);
            else {
                i++;
                indeks=(indeks+1)%max;
            }
        } while(!(niz[indeks]==nullptr) && i!=max);

        return TipVrijednosti{};
    }

    TipVrijednosti& operator[] (const TipKljuca& kljuc) {
        if(!pokNaFun) throw "Postavite hash funkciju";
        unsigned int indeks=pokNaFun(kljuc,max);
        int i(0);
        do {
            if(niz[indeks]!=nullptr && std::get<0>(*niz[indeks])==kljuc && !std::get<2>(*niz[indeks])) return std::get<1>(*niz[indeks]);
            else {
                i++;
                indeks=(indeks+1)%max;
            }
        } while(!(niz[indeks]==nullptr) && i!=max);

        if(brojEl<max) {
            int j=pokNaFun(kljuc,max);
            i = 0;
            return dodajElement(kljuc,j,i);
        } else {
            std::tuple<TipKljuca,TipVrijednosti,bool> **novi = new std::tuple<TipKljuca,TipVrijednosti,bool> *[max*2]{};
            for(int i=0; i<max; i++) {
                if(niz[i]!=nullptr) {
                    int j=pokNaFun(std::get<0>(*niz[i]),max*2);
                    int k=0;
                    do {
                        if(!novi[j]) {
                            novi[j]=new std::tuple<TipKljuca,TipVrijednosti,bool> (std::get<0>(*niz[i]), TipVrijednosti{},false);
                            break;
                        } else {
                            k++;
                            j=(j+1)%(max*2);
                        }
                    } while (k<max*2);
                    delete niz[i];
                    niz[i]=nullptr;
                }
            }
            delete [] niz;
            max*=2;
            niz=novi;
            int vratiIndeks = pokNaFun(kljuc,max);
            i = 0;
            return dodajElement(kljuc,vratiIndeks,i);
        }
    }

    TipVrijednosti& dodajElement(TipKljuca kljuc, int j, int i) {
        do {
            if(!niz[j] || std::get<2>(*niz[j])) {
                delete niz[j];
                niz[j]=new std::tuple<TipKljuca,TipVrijednosti,bool>(kljuc,TipVrijednosti{},false);
                brojEl++;
                return std::get<1>(*niz[j]);
            } else {
                i++;
                j=(j+1)%max;
            }
        } while(i<max);
    }

    int brojElemenata() const {
        return brojEl;
    }

    void obrisi() {
        for(int i=0;i<max;i++) {
            delete niz[i];
            niz[i]=nullptr;
        }
        brojEl=0;
    }

    void obrisi(const TipKljuca &kljuc) {
        if(!pokNaFun) throw "Postavi hash funkciju";
        unsigned int indeks= pokNaFun(kljuc,max);
        int i=0;
        do {
            if(niz[indeks]!=nullptr && std::get<0>(*niz[indeks])==kljuc && !std::get<2>(*niz[indeks])) {
                std::get<2>(*niz[indeks])=true;
                brojEl--;
                return;
            } else {
                i++;
                indeks=(indeks+1)%max;
            }
        } while(!(niz[indeks]==nullptr) && i!=max);
        throw "Nije pronadjen element";
    }

    void definisiHashFunkciju(unsigned int (*pokNaFun1)(TipKljuca, unsigned int)) {
        pokNaFun=pokNaFun1;
    }

};


template<typename TipKljuca,typename TipVrijednosti>
class BSCvor {
public:
    TipKljuca kljuc;
    TipVrijednosti vrijednost;
    BSCvor *lijevo,*desno,*roditelj;
    BSCvor() {
        lijevo=nullptr;
        desno=nullptr;
        roditelj=nullptr;
    }
    BSCvor(const TipKljuca &k, const TipVrijednosti &v, BSCvor* l=nullptr, BSCvor* d=nullptr, BSCvor* r=nullptr) {
        kljuc=k;
        vrijednost=v;
        lijevo=l;
        desno=d;
        roditelj=r;
    }
};


template<typename TipKljuca, typename TipVrijednosti>
class BinStabloMapa : public Mapa<TipKljuca,TipVrijednosti> {
    BSCvor<TipKljuca,TipVrijednosti>* korijen;
    int brojEl=0;
    void brisi(BSCvor<TipKljuca,TipVrijednosti> *r) {
        if (r) {
            brisi(r->lijevo);
            brisi(r->desno);
            delete r;
        }
        korijen=nullptr;
    }
public:
    BinStabloMapa() {
        korijen=nullptr;
    }

    BinStabloMapa(const BinStabloMapa<TipKljuca,TipVrijednosti> &bsm) {
        korijen=nullptr;
        BSCvor<TipKljuca,TipVrijednosti>* cvor=bsm.korijen;
        Preorder(cvor);
    }

    TipVrijednosti &dodaj(TipKljuca &k) {
        BSCvor<TipKljuca,TipVrijednosti> *novi=new BSCvor<TipKljuca,TipVrijednosti>(k,TipVrijednosti{});
        Umetni(novi);
        return novi->vrijednost;
    }

    void Preorder(BSCvor<TipKljuca,TipVrijednosti> *r) {
        if(r!=nullptr) {
            dodaj(r->kljuc)=r->vrijednost;
            Preorder(r->lijevo);
            Preorder(r->desno);
        }
    }


    BinStabloMapa& operator=(const BinStabloMapa<TipKljuca,TipVrijednosti> &bsm) {
        if(this==&bsm) return *this;
        obrisi();
        korijen=nullptr;
        BSCvor<TipKljuca,TipVrijednosti> *cvor=bsm.korijen;
        Preorder(cvor);
        return *this;
    }

    ~BinStabloMapa() {
        brisi(korijen);
    }

    void Umetni(BSCvor<TipKljuca,TipVrijednosti>* &n) {
        BSCvor<TipKljuca,TipVrijednosti> *y=nullptr, *x=korijen;
        while(x!=nullptr) {
            y=x;
            if(n->kljuc<x->kljuc) x=x->lijevo;
            else x=x->desno;
        }
        if(y==0) {
            korijen=n;
            brojEl++;
        } else {
            if(n->kljuc < y->kljuc) {
                y->lijevo=n;
                n->roditelj=y;
                brojEl++;
            } else {
                y->desno=n;
                n->roditelj=y;
                brojEl++;
            }
        }
    }

    TipVrijednosti& operator [] (const TipKljuca& kljuc) {
        BSCvor<TipKljuca,TipVrijednosti> *p=korijen;
        while(p!=nullptr && kljuc!=p->kljuc) {
            if(kljuc<p->kljuc) p=p->lijevo;
            else p=p->desno;
        }
        if(p!=nullptr) return p->vrijednost;
        BSCvor<TipKljuca,TipVrijednosti> * novi=new BSCvor<TipKljuca,TipVrijednosti>{kljuc, TipVrijednosti{}};
        Umetni(novi);
        return novi->vrijednost;
    }
    TipVrijednosti operator [] (const TipKljuca& kljuc) const {
        BSCvor<TipKljuca,TipVrijednosti> *p=korijen;
        while(p!=nullptr && kljuc!=p->kljuc) {
            if(kljuc<p->kljuc) p=p->lijevo;
            else p=p->desno;
        }
        if(p!=nullptr) return p->vrijednost;
        TipVrijednosti v{};
        return v;
    }
    int brojElemenata() const {
        return brojEl;
    }
    void obrisi() {
        brisi(korijen);
        brojEl=0;
    }
    void obrisi(const TipKljuca& kljuc) {
        BSCvor<TipKljuca,TipVrijednosti> *p=korijen,*rod=nullptr;
        BSCvor<TipKljuca,TipVrijednosti> *tmp=nullptr,*pm=nullptr,*m=nullptr;
        while(p!=nullptr && kljuc!=p->kljuc) {
            rod=p;
            if(kljuc< p->kljuc) p=p->lijevo;
            else p=p->desno;
        }
        if(p==nullptr) throw "Greska: ne postoji kljuc u BinStabloMapa";
        if(p->lijevo==nullptr) m=p->desno;
        else if(p->desno==nullptr) m=p->lijevo;
        else {
            pm=p;
            m=p->lijevo;
            tmp=m->desno;
            while(tmp!=nullptr) {
                pm=m;
                m=tmp;
                tmp=m->desno;
            }
            if(pm!=p) {
                pm->desno=m->lijevo;
                m->lijevo=p->lijevo;
                pm->roditelj=m;
                m->roditelj=rod;
                if(pm->desno) pm->desno->roditelj=pm;
            }
            m->desno=p->desno;
        }
        if(rod==nullptr) {
            korijen=m;
        }
        else {
            if(p==rod->lijevo) rod->lijevo=m;
            else rod->desno=m;
        }
        delete p;
        brojEl--;
    }
};


template<typename TipKljuca, typename TipVrijednosti>
class NizMapa : public Mapa<TipKljuca,TipVrijednosti> {
    std::pair<TipKljuca,TipVrijednosti> *nizMapa=nullptr;
    int maxBrojEl;
    int brojEl;
public:

    NizMapa () {
        nizMapa=new std::pair<TipKljuca,TipVrijednosti>[10];
        maxBrojEl=10;
        brojEl=0;
    }

    ~NizMapa() {
        delete [] nizMapa;
    }

    NizMapa(const NizMapa<TipKljuca,TipVrijednosti>& m) {
        maxBrojEl=m.maxBrojEl;
        brojEl=m.brojEl;
        nizMapa=new std::pair<TipKljuca,TipVrijednosti>[m.maxBrojEl];
        for(int i=0;i<brojEl;i++) nizMapa[i]=m.nizMapa[i];
    }

    NizMapa& operator= (const NizMapa<TipKljuca,TipVrijednosti>& m) {
        if(this==&m) return *this;
        maxBrojEl=m.maxBrojEl;
        brojEl=m.brojEl;
        delete [] nizMapa;
        nizMapa=new std::pair<TipKljuca,TipVrijednosti>[m.maxBrojEl];
        for(int i=0;i<brojEl;i++) nizMapa[i]=m.nizMapa[i];
        return *this;
    }

    int brojElemenata() const {
        return brojEl;
    }

    TipVrijednosti& operator [] (const TipKljuca& kljuc) {
        for(int i=0;i<brojEl;i++) {
            if(nizMapa[i].first==kljuc) return nizMapa[i].second;
        }
        if(brojEl>=maxBrojEl) {
            maxBrojEl*=2;
            std::pair<TipKljuca,TipVrijednosti> * novi=new std::pair<TipKljuca,TipVrijednosti>[maxBrojEl];
            for(int i=0;i<brojEl;i++) novi[i]=nizMapa[i];
            novi[brojEl].first=kljuc;
            novi[brojEl++].second=TipVrijednosti();
            delete[]nizMapa;
            nizMapa=novi;
            novi=nullptr;
            return nizMapa[brojEl-1].second;
        }
        else {
            nizMapa[brojEl].first=kljuc;
            nizMapa[brojEl++].second=TipVrijednosti();
            return nizMapa[brojEl-1].second;
        }
    }

    TipVrijednosti operator [] (const TipKljuca& kljuc) const {
        for(int i=0;i<brojEl;i++) {
            if(nizMapa[i].first==kljuc) return nizMapa[i].second;
        }
        return TipVrijednosti();
    }

    void obrisi() {
        brojEl=0;
    }
    void obrisi(const TipKljuca& kljuc) {
        bool ima=false;
        for(int i=0;i<brojEl;i++) {
            if(nizMapa[i].first==kljuc) {
                ima=true;
                for(int j=i;j<brojEl-1;j++) nizMapa[j]=nizMapa[j+1];
                brojEl--;
            }
        }
        if(!ima) throw "Ne postoji par sa datim kljucem";
    }

};


int dodajElementeUHashMapu(HashMapa<int,int> &mapa) {
    int br=0;
    int n=10000;
    for(int i=0;i<n;i++) {
        int v=rand() % 100000;
        mapa[v]=48;
        if(i== n /2) br=v;
    }
    return br;
}

int dodajElementeUBinStabloMapa(BinStabloMapa<int,int> &mapa) {
    int br=0;
    int n=10000;
    for(int i=0;i<n;i++) {
        int v=rand() % 100000;
        mapa[v]=48;
        if(i==n/2) br=v;
    }
    return br;
}


int dodajElementeUNizMapa(NizMapa<int,int> &mapa) {
    int br=0;
    int n=10000;
    for(int i=0;i<n;i++) {
        int v=rand() % 100000;
        mapa[v]=48;
        if(i==n/2) br=v;
    }
    return br;
}

unsigned int hashFunkcija(int x, unsigned int max) {
    x = ((x>>16)^x) * 0x45d9f3b;
    x = ((x>>16)^x) * 0x45d9f3b;
    x = (x>>16)^x;
    return x % max;
}

int main() {
    BinStabloMapa<int,int> bMapa;
    NizMapa<int,int> nMapa;
    HashMapa<int,int> hMapa;
    int t1,t2,t3,tuk;
    clock_t v1,v2;
    hMapa.definisiHashFunkciju(hashFunkcija);
    t1=dodajElementeUBinStabloMapa(bMapa);
    t2=dodajElementeUNizMapa(nMapa);
    t3=dodajElementeUHashMapu(hMapa);
    v1=clock();
    bMapa[100001]=1;
    v2=clock();
    tuk=(v2-v1)/(CLOCKS_PER_SEC/100000);
    std::cout<<"Vrijeme dodavanja novog elementa u binarno-stablo mapu: "<<tuk<<" ms(/100)\n";
    v1=clock();
    nMapa[100001]=1;
    v2=clock();
    tuk=(v2-v1)/(CLOCKS_PER_SEC/100000);
    std::cout<<"Vrijeme dodavanja novog elementa u niz mapu: "<<tuk<<" ms(/100)\n";
    v1=clock();
    hMapa[100001]=1;
    v2=clock();
    tuk=(v2-v1)/(CLOCKS_PER_SEC/100000);
    std::cout<<"Vrijeme dodavanja novog elementa u hash-mapu: "<<tuk<<" ms(/100)\n";

    v1=clock();
    bMapa[t1]=99999;
    v2=clock();
    tuk=(v2-v1)/(CLOCKS_PER_SEC/100000);
    std::cout<<"Vrijeme trazenja novog elementa u binarno-stablo mapi: "<<tuk<<" ms(/100)\n";
    v1=clock();
    nMapa[t2]=99999;
    v2=clock();
    tuk=(v2-v1)/(CLOCKS_PER_SEC/100000);
    std::cout<<"Vrijeme trazenja novog elementa u niz mapi: "<<tuk<<" ms(/100)\n";
    v1=clock();
    hMapa[t3]=99999;
    v2=clock();
    tuk=(v2-v1)/(CLOCKS_PER_SEC/100000);
    std::cout<<"Vrijeme trazenja novog elementa u hash-mapi: "<<tuk<<" ms(/100)\n";
    return 0;
}