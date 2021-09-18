//
// Created by 38760 on 18. 9. 2021..
//

#include <iostream>
#include <utility>
template<typename TipKljuca, typename TipVrijednosti>
class Mapa {
public:
    Mapa() {}
    virtual ~Mapa() {}
    virtual TipVrijednosti& operator [] (const TipKljuca& kljuc) = 0;
    virtual TipVrijednosti operator [] (const TipKljuca& kljuc) const = 0;
    virtual int brojElemenata() const = 0;
    virtual void obrisi() = 0;
    virtual void obrisi(const TipKljuca& kljuc) = 0;
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

template<typename TipKljuca, typename TipVrijednosti>
void Test1(NizMapa<TipKljuca,TipVrijednosti>& m) {
    std::cout<<"Test1"<<std::endl;
    std::cout<<m.brojElemenata()<<" ";
    m.obrisi();
    std::cout<<m.brojElemenata()<<std::endl;
}

template<typename TipKljuca, typename TipVrijednosti>
void Test2(NizMapa<TipKljuca,TipVrijednosti>& m, const TipKljuca& k) {
    std::cout<<"Test2"<<std::endl;
    std::cout<<m.brojElemenata()<<" "<<m[k]<<" ";
    m.obrisi(k);
    std::cout<<m.brojElemenata()<<std::endl;
}

template<typename TipKljuca, typename TipVrijednosti>
void Test3(NizMapa<TipKljuca,TipVrijednosti>& m, const TipKljuca& k, const TipVrijednosti& t) {
    std::cout<<"Test3"<<std::endl;
    std::cout<<m[k]<<" ";
    m[k]=t;
    std::cout<<m[k]<<std::endl;
}

template<typename TipKljuca, typename TipVrijednosti>
void Test4(const NizMapa<TipKljuca,TipVrijednosti>& m) {
    std::cout<<"Test4"<<std::endl;
    NizMapa<TipKljuca,TipVrijednosti> m1(m);
    std::cout<<m.brojElemenata()<<" "<<m1.brojElemenata()<<" ";
    m1.obrisi();
    m1=m;
    std::cout<<m.brojElemenata()<<" "<<m1.brojElemenata()<<std::endl;
}
int main()
{
    NizMapa<int,int> m;
    m[4]=8;
    m[7]=12;
    m[20]=11;
    Test1(m);
    m[4]=8;
    m[7]=12;
    m[20]=11;
    Test2(m,0);
    Test3(m,555,666);
    Test4(m);
    std::cout << "Pripremna Zadaca Za Vjezbu 7, Zadatak 1";
    return 0;
}