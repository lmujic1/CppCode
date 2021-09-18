//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 5, Zadatak 1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

template <typename TipEl, template <typename...> class Kontejner = std::vector>
class Tok {
    Kontejner<TipEl> kolekcija;
public:
    template <typename TipEl2, template <typename...> class Kontejner2>
    friend class Tok; // Stvara prijateljstvo između različitih vrsta tokova
    template <typename IterTip>
    Tok(IterTip pocetak, const IterTip iza_kraja) {
        unsigned int i(0);
        while(pocetak!=iza_kraja) {
            kolekcija.insert(std::begin(kolekcija)+i,(TipEl)*pocetak);
            i++;
            pocetak++;
        }
    }
    template <typename IterabilniKontejner>
    Tok(const IterabilniKontejner &kontejner) {
        unsigned int i(0);
        //auto p(std::begin(kolekcija));
        for(auto it=std::begin(kontejner);it!=std::end(kontejner);it++,i++) {
            kolekcija.insert(std::begin(kolekcija)+i,*it);
            //kolekcija.insert(p,*it);
            //p++;
        }
    }
    Tok(std::initializer_list<TipEl> lista) {
        unsigned int i(0);
        for(auto it=lista.begin();it!=lista.end();it++,i++) {
            kolekcija.insert(std::begin(kolekcija)+i,*it);
        }
    }
    static Tok<TipEl, Kontejner> Opseg(TipEl poc, TipEl kraj, TipEl korak = 1) {
        Tok<TipEl, Kontejner> k=Tok<TipEl>(poc,poc);
        unsigned int j(0);
        auto p(std::begin(k.kolekcija));
        for(TipEl i=poc;i<=kraj;i=i+korak,j++) {
            k.kolekcija.insert(std::begin(k.kolekcija)+j,i);
            //*p=TipEl(i);
            //p++;
        }
        return Tok<TipEl>(std::begin(k.kolekcija),std::end(k.kolekcija));
    }
    unsigned int Velicina() const {
        return std::end(kolekcija)-std::begin(kolekcija);
    }
    bool Prazan() const {
        if(Velicina()!=0) return false;
        return true;
    }
    Tok<TipEl, Kontejner> Limitiraj(unsigned int n) const  {
        if(n>Velicina()) return Tok<TipEl>(std::begin(kolekcija),std::end(kolekcija));
        Tok<TipEl, Kontejner> k=Tok<TipEl>(std::begin(kolekcija),std::begin(kolekcija)+n);

        unsigned int i(0);
        auto p(std::begin(k.kolekcija));
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++,i++) {
            if(i==n) break;
            *p=*it;
            p++;
        }
        return k;
    }
    Tok<TipEl, Kontejner> Preskoci(unsigned int n) const {
        if(n<0 || n>Velicina()) return Tok<TipEl>(std::begin(kolekcija),std::begin(kolekcija));
        Tok<TipEl, Kontejner> k=Tok<TipEl>(std::begin(kolekcija),std::begin(kolekcija)+(Velicina()-n));
        unsigned int i(0);
        auto p(std::begin(k.kolekcija));
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++,i++) {
            if(i>=n) {
                *p=*it;
                p++;
            }
        }
        return k;
    }
    Tok<TipEl, Kontejner> Obrnut() const {
        Tok<TipEl, Kontejner> k=Tok<TipEl>(std::begin(kolekcija),std::end(kolekcija));
        auto it2(std::begin(k.kolekcija));
        for(auto it=std::end(kolekcija);it>=std::begin(kolekcija);it--,it2++) {
            if(it==std::end(kolekcija)) it--;
            *it2=*it;
        }
        return k;
    }
    Tok<TipEl, Kontejner> Akcija(std::function<void(void)> akcija) const {
        Tok<TipEl, Kontejner> novi(*this);
        akcija();
        return novi;
    }
    void ZaSvaki(std::function<void(TipEl)> akcija) const {
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) {
            akcija(*it);
        }
    }
    Tok<TipEl, Kontejner> Filtriraj(std::function<bool(TipEl)> predikat) const {
        Tok<TipEl, Kontejner> k=Tok<TipEl>(std::begin(kolekcija),std::end(kolekcija));
        auto p(std::begin(k.kolekcija));
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) {
            if(predikat(*it)==true) {
                *p=*it;
                p++;
                //k.kolekcija.insert(p,*it);p++;
            }
        }
        //return k;
        return Tok<TipEl>(std::begin(k.kolekcija),p);
    }
    TipEl PronadjiPrvi() const {
        if(std::begin(kolekcija)==std::end(kolekcija)) throw std::logic_error("Tok je prazan");
        return *std::begin(kolekcija);
    }
    TipEl PronadjiPosljednji() const {
        if(std::begin(kolekcija)==std::end(kolekcija)) throw std::logic_error("Tok je prazan");
        return *(--std::end(kolekcija));
    }
    bool ZadovoljavaBaremJedan(std::function<bool(TipEl)> kriterij) const {
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) {
            if(kriterij(*it)==true) return true;
        }
        return false;
    }
    bool ZadovoljavaNijedan(std::function<bool(TipEl)> kriterij) const {
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) {
            if(kriterij(*it)==true) return false;
        }
        return true;
    }
    bool ZadovoljavajuSvi(std::function<bool(TipEl)> kriterij) const {
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) {
            if(kriterij(*it)==false) return false;
        }
        return true;
    }
    TipEl Akumuliraj(TipEl inicijalna, std::function<TipEl(TipEl, TipEl)> akumulator) const {
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) {
            inicijalna=akumulator(inicijalna,*it);
        }
        return inicijalna;
    }
    TipEl Akumuliraj(std::function<TipEl(TipEl, TipEl)> akumulator) const {
        if(std::begin(kolekcija)==std::end(kolekcija)) throw std::logic_error("Tok je prazan");
        TipEl inicijalna(*std::begin(kolekcija));
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) {
            if(it==std::begin(kolekcija)) it++;
            inicijalna=akumulator(inicijalna,*it);
        }
        return inicijalna;
    }
    Tok<TipEl, Kontejner> Sortirano(std::function<bool(TipEl, TipEl)> komparator = [](TipEl x, TipEl y) { return x < y; }) const {
        Tok<TipEl, Kontejner> k=Tok<TipEl>(std::begin(kolekcija),std::end(kolekcija));
        std::sort(std::begin(k.kolekcija),std::end(k.kolekcija),komparator);
        return k;
    }
    Tok<TipEl, Kontejner> Unikatno(std::function<bool(TipEl, TipEl)> komparator = [](TipEl x, TipEl y) { return x == y; }) const {
        Tok<TipEl, Kontejner> k=Tok<TipEl>(std::begin(kolekcija),std::end(kolekcija));
        //k.Sortirano();
        auto p=std::begin(k.kolekcija);
        for(auto it1=std::begin(k.kolekcija);it1!=std::end(k.kolekcija);it1++) {
            if(!komparator(*p,*it1)) *(++p)=*it1;
        }
        p++;
        return Tok<TipEl>(std::begin(k.kolekcija),p);
    }
    Tok<TipEl, Kontejner> Proviri(std::function<void(TipEl)> akcija) const {
        Tok<TipEl, Kontejner> k=Tok<TipEl>(std::begin(kolekcija),std::end(kolekcija));
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) akcija(*it);
        return k;
    }
    TipEl Minimalan(std::function<bool(TipEl, TipEl)> komparator = [](TipEl x, TipEl y) { return x < y; }) const {
        if(std::begin(kolekcija)==std::end(kolekcija)) throw std::logic_error("Tok je prazan");
        return *std::min_element(std::begin(kolekcija),std::end(kolekcija),komparator);
    }
    TipEl Maksimalan(std::function<bool(TipEl, TipEl)> komparator = [](TipEl x, TipEl y) { return x > y; }) const {
        if(std::begin(kolekcija)==std::end(kolekcija)) throw std::logic_error("Tok je prazan");
        return *std::min_element(std::begin(kolekcija),std::end(kolekcija),komparator);
    }
    template <typename Kont2>
    Kont2 Sakupi(std::function<void(Kont2 &, TipEl)> kombinator) const {
        Kont2 k;
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++)
            kombinator(k,*it);
        return k;
    }
    template <typename TipEl2>
    Tok<TipEl2, Kontejner> Mapiraj(std::function<TipEl2(TipEl)> maper) const {

        Tok<TipEl2, Kontejner> k=Tok<TipEl2>(std::begin(kolekcija),std::end(kolekcija));
        auto p(std::begin(k.kolekcija));
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) {*p=maper(*it); p++;}
        return k;
    }
    template <typename TipEl2>
    Tok<TipEl2, Kontejner> MapirajPoravnato(std::function<Tok<TipEl2, Kontejner>(TipEl)> maper) const {
        auto it=std::begin(kolekcija);
        Tok<TipEl2,Kontejner> k(maper(*it));
        unsigned int i(k.Velicina());
        for(auto it=std::begin(kolekcija);it!=std::end(kolekcija);it++) {
            if(it==std::begin(kolekcija)) it++;
            Tok<TipEl2,Kontejner> k1(maper(*it));
            for(auto m=std::begin(k1.kolekcija);m!=std::end(k1.kolekcija);m++,i++)
                k.kolekcija.insert(std::begin(k.kolekcija)+i,*m);
        }
        return k;
    }
};

#include <vector>
template <typename T>
class MojNizKontejner {
    static constexpr const unsigned int MAX_EL = 100;
    T arr[MAX_EL]{};
    unsigned int len = 0;
public:
    const T *begin() const { return &arr[0]; }

    const T *end() const { return arr + len; }

    T *insert(const T *position, T el) {
        if (position < begin() || position > end()) throw "Pozicija ne valja!";
        if (len++ >= MAX_EL) throw "Maksimalan kapacitet dostignut, nije potrebno autotestom!";
        T *i;
        for (i = arr + len; i > position; --i)
            *i = *(i - 1);
        *i = el;
        return i;
    }

};

int main ()
{

    {//AT44 (javni): filtriraj, ali vrati sve elemente + vlastiti kontejner
        Tok<int, MojNizKontejner>{1, -1, 2, 5, 7, -3, 0}
                .Filtriraj([](int i) { return i > -10; })
                .ZaSvaki([](int i) { std::cout << i << " "; });
    }//1 -1 2 5 7 -3 0

    return 0;
}

