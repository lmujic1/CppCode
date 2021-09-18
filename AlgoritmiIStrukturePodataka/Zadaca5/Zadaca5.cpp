//
// Created by 38760 on 18. 9. 2021..
//
#include <iostream>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <list>

using namespace std;

template<typename TipKljuca, typename TipVrijednosti>
class Mapa
{
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
class HashMapaLan : public Mapa<TipKljuca,TipVrijednosti>
{
    std::vector<std::list<std::pair<TipKljuca,TipVrijednosti>>*> elementi;
    int brElemenata=0;
    unsigned int (*pokNaFun)(TipKljuca,unsigned int);
public:
    HashMapaLan() : elementi(1000), brElemenata(0),pokNaFun(nullptr) {}
    HashMapaLan(const HashMapaLan<TipKljuca,TipVrijednosti> &m) : elementi(m.elementi.size()), brElemenata(m.brElemenata),pokNaFun(m.pokNaFun)
    {
        for(int i=0; i<elementi.size(); i++) {
            if(m.elementi[i]) elementi[i]=new std::list<std::pair<TipKljuca,TipVrijednosti>>(*m.elementi[i]);
        }
    }

    HashMapaLan& operator=(const HashMapaLan<TipKljuca,TipVrijednosti> &m)
    {
        if(this==&m) return *this;
        this->obrisi();
        elementi.resize(m.elementi.size(), nullptr);
        brElemenata=m.brElemenata;
        pokNaFun=m.pokNaFun;
        for(int i=0; i<elementi.size(); i++) {
            if(m.elementi[i]) elementi[i]=new std::list<std::pair<TipKljuca,TipVrijednosti>>(*m.elementi[i]);
        }
        return *this;
    }

    TipVrijednosti operator [] (const TipKljuca& kljuc) const
    {
        if(!pokNaFun) throw "postavi hash funkciju";
        unsigned int indeks=pokNaFun(kljuc,elementi.size());
        if(elementi[indeks]) {
            for(auto it1 = elementi[indeks]->begin(); it1!=elementi[indeks]->end(); it1++) {
                if(it1->first == kljuc) return it1->second;
            }
        }
        return TipVrijednosti{};
    }

    TipVrijednosti& operator [] (const TipKljuca& kljuc)
    {
        if(!pokNaFun) throw "postavi hash funkciju";
        unsigned int indeks=pokNaFun(kljuc,elementi.size());
        if(elementi[indeks]==nullptr) {
            elementi[indeks] = new std::list<std::pair<TipKljuca,TipVrijednosti>> {std::pair<TipKljuca,TipVrijednosti>(kljuc,TipVrijednosti{})};
            brElemenata++;
            auto it = elementi[indeks]->begin();
            return it->second;
        } else {
            auto it = elementi[indeks]->begin();
            for(auto it1 = elementi[indeks]->begin(); it1!=elementi[indeks]->end(); it1++) {
                if(it1->first == kljuc) return it1->second;
            }
            while(it!=elementi[indeks]->end() && it->first<kljuc) it++;
            brElemenata++;
            return (elementi[indeks]->insert(it, std::pair<TipKljuca,TipVrijednosti>(kljuc, TipVrijednosti{})))->second;
        }
    }

    int brojElemenata() const
    {
        return brElemenata;
    }

    void obrisi()
    {
        for(int i=0; i<elementi.size(); i++) {
            delete elementi[i];
            brElemenata=0;
            elementi[i]=nullptr;
        }
    }

    void obrisi(const TipKljuca& kljuc)
    {
        if(!pokNaFun) throw"postavi hash funkciju";
        unsigned int indeks=pokNaFun(kljuc,elementi.size());
        if(elementi[indeks]!=nullptr) {
            for(auto it1=elementi[indeks]->begin(); it1!=elementi[indeks]->end(); it1++) {
                if(it1->first==kljuc) {
                    elementi[indeks]->erase(it1);
                    if(elementi[indeks]->empty()) {
                        delete elementi[indeks];
                        elementi[indeks]=nullptr;
                    }
                    brElemenata--;
                    return;
                }
            }
        }
        throw "nije pronadjen element";
    }

    void definisiHashFunkciju(unsigned int (*pokNaFun1)(TipKljuca,unsigned int))
    {
        pokNaFun=pokNaFun1;
    }

    ~HashMapaLan()
    {
        for(int i=0; i<elementi.size(); i++) {
            delete elementi[i];
        }
    }
};

template <typename TipOznake>
class Cvor;
template <typename TipOznake>
class Grana;
template <typename TipOznake>
class GranaIterator;
template <typename TipOznake>
class ListaGraf;

template <typename TipOznake>
class UsmjereniGraf
{
public:
    UsmjereniGraf () = default;
    virtual ~UsmjereniGraf() {}
    virtual int dajBrojCvorova() = 0;
    virtual void postaviBrojCvorova(int brCvorova) = 0;
    virtual void dodajGranu(int polazni, int dolazni, float tezina) = 0;
    virtual void obrisiGranu(int polazni, int dolazni) = 0;
    virtual void postaviTezinuGrane (int polazni, int dolazni, float tezina) = 0;
    virtual float dajTezinuGrane(int polazni, int dolazni) = 0;
    virtual bool postojiGrana(int polazni, int dolazni) = 0;
    virtual void postaviOznakuCvora (int broj, TipOznake oznaka) = 0;
    virtual TipOznake dajOznakuCvora(int cvor) = 0;
    virtual void postaviOznakuGrane(int polazni, int dolazni, TipOznake oznaka) = 0;
    virtual TipOznake dajOznakuGrane(int polazni, int dolazni) = 0;
    virtual Grana<TipOznake> dajGranu(int polazni, int dolazni) = 0;
    virtual Cvor<TipOznake> dajCvor(int broj) = 0;
    virtual GranaIterator<TipOznake> dajGranePocetak() = 0;
    virtual GranaIterator<TipOznake> dajGraneKraj() = 0;
};

template <typename TipOznake>
class Cvor
{
    TipOznake oznaka;
    int redniBroj;
    UsmjereniGraf<TipOznake> *pokNaGraf;
public:
    Cvor (TipOznake oznaka, int redniBroj, UsmjereniGraf<TipOznake> *pokNaGraf) : oznaka(oznaka), redniBroj(redniBroj), pokNaGraf(pokNaGraf) {}
    Cvor () : oznaka(TipOznake{}), redniBroj(0), pokNaGraf(nullptr) {}
    TipOznake dajOznaku()
    {
        return oznaka;
    }
    void postaviOznaku(TipOznake o)
    {
        pokNaGraf->postaviOznakuCvora(redniBroj,o);
    }
    void postaviOznaku2(TipOznake o)
    {
        oznaka=o;
    }
    int dajRedniBroj()
    {
        return redniBroj;
    }
    friend class Grana<TipOznake>;
};

template <typename TipOznake>
class Grana
{
    float tezina;
    TipOznake oznaka;
    Cvor<TipOznake> *polazni, *dolazni;
public:
    Grana() : tezina(0),oznaka(TipOznake{}),polazni(nullptr),dolazni(nullptr) {}
    Grana(float tezina, TipOznake oznaka, Cvor<TipOznake> * p, Cvor<TipOznake> * d) : tezina(tezina), oznaka(oznaka), polazni(p), dolazni(d) {}
    float dajTezinu()
    {
        return tezina;
    }
    void postaviTezinu(float tezina)
    {
        polazni->pokNaGraf->postaviTezinuGrane(polazni->dajRedniBroj(),dolazni->dajRedniBroj(),tezina);
    }
    void postaviTezinu2(float t)
    {
        tezina=t;
    }
    TipOznake dajOznaku()
    {
        return oznaka;
    }
    void postaviOznaku(TipOznake o)
    {
        polazni->pokNaGraf->postaviOznakuGrane(polazni->dajRedniBroj(),dolazni->dajRedniBroj(),o);
    }
    void postaviOznaku2(TipOznake o)
    {
        oznaka=o;
    }
    Cvor<TipOznake> dajPolazniCvor()
    {
        return *polazni;
    }
    Cvor<TipOznake> dajDolazniCvor()
    {
        return *dolazni;
    }
    bool daLiSuIsti(int p,int d)
    {
        return(p==polazni->dajRedniBroj() && d==dolazni->dajRedniBroj());
    }
};

template<typename TipOznake>
class ListaGraf : public UsmjereniGraf<TipOznake>
{
protected:
    std::vector<std::vector<Grana<TipOznake>*>> lista;
    std::vector<Cvor<TipOznake>*> cvorovi;
    int brojPosjecenih=0;
public:
    ListaGraf(int brCvorova)
    {
        lista.resize(brCvorova);
        cvorovi.resize(brCvorova,nullptr);
        for(int i=0; i<brCvorova; i++) {
            cvorovi[i]=new Cvor<TipOznake>(TipOznake{},i,this);
        }
    }

    ~ListaGraf()
    {
        for(int i=0; i<lista.size(); i++) {
            for(int j=0; j<lista[i].size(); j++) {
                delete lista[i][j];
            }
        }

        for(int i=0; i<cvorovi.size(); i++) {
            delete cvorovi[i];
        }
    }


    int dajBrojCvorova()
    {
        return cvorovi.size();
    }

    void postaviBrojCvorova(int brCvorova)
    {
        if(brCvorova< cvorovi.size()) throw "nedozvoljena vrijednost";
        lista.resize(brCvorova);
        int vel=cvorovi.size();
        cvorovi.resize(brCvorova,nullptr);
        for(int i=vel; i<brCvorova; i++)
            cvorovi[i]=new Cvor<TipOznake>(TipOznake{},i,this);
    }


    void dodajGranu(int polazni, int dolazni, float tezina)
    {
        if(polazni>cvorovi.size()) throw "Losi podaci";
        lista[polazni].push_back(new Grana<TipOznake>(tezina, TipOznake{}, cvorovi[polazni],cvorovi[dolazni]));
    }

    void obrisiGranu(int polazni,int dolazni)
    {
        if(polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        for(int i=0; i<lista[polazni].size(); i++) {
            if(lista[polazni][i]->daLiSuIsti(polazni,dolazni)) {
                delete lista[polazni][i];
                lista[polazni].erase(lista[polazni].begin()+i);
                return;
            }
        }
        throw "ne postoji grana";
    }

    void postaviTezinuGrane(int polazni,int dolazni, float tezina)
    {
        if(polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        for(int i=0; i<lista[polazni].size(); i++) {
            if(lista[polazni][i]->daLiSuIsti(polazni,dolazni)) {
                lista[polazni][i]->postaviTezinu2(tezina);
                return;
            }
        }
        throw "ne postoji grana";
    }

    float dajTezinuGrane(int polazni,int dolazni)
    {
        if(polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        for(int i=0; i<lista[polazni].size(); i++) {
            if(lista[polazni][i]->daLiSuIsti(polazni,dolazni)) {
                return lista[polazni][i]->dajTezinu();
            }
        }
        throw "ne postoji grana";
    }

    bool postojiGrana(int polazni, int dolazni)
    {
        if(polazni>cvorovi.size() || dolazni>cvorovi.size()) return false;
        for(int i=0; i<lista[polazni].size(); i++) {
            if(lista[polazni][i]->daLiSuIsti(polazni,dolazni)) {
                return true;
            }
        }
        return false;
    }

    void postaviOznakuCvora(int broj, TipOznake oznaka)
    {
        if(cvorovi[broj] == nullptr) throw"ne postoji cvor";
        cvorovi[broj]->postaviOznaku2(oznaka);
    }

    TipOznake dajOznakuCvora(int broj)
    {
        if(cvorovi[broj] == nullptr) throw"ne postoji cvor";
        return cvorovi[broj]->dajOznaku();
    }

    void postaviOznakuGrane(int polazni,int dolazni, TipOznake oznaka)
    {
        if(polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        for(int i=0; i<lista[polazni].size(); i++) {
            if(lista[polazni][i]->daLiSuIsti(polazni,dolazni)) {
                lista[polazni][i]->postaviOznaku2(oznaka);
                return;
            }
        }
        throw "ne postoji grana";
    }

    TipOznake dajOznakuGrane(int polazni,int dolazni)
    {
        if(polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        for(int i=0; i<lista[polazni].size(); i++) {
            if(lista[polazni][i]->daLiSuIsti(polazni,dolazni)) {
                return lista[polazni][i]->dajOznaku();
            }
        }
        throw "ne postoji grana";
    }

    Grana<TipOznake> dajGranu(int polazni,int dolazni)
    {
        if(polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        for(int i=0; i<lista[polazni].size(); i++) {
            if(lista[polazni][i]->daLiSuIsti(polazni,dolazni)) {
                return *lista[polazni][i];
            }
        }
        throw "ne postoji grana";
    }

    Cvor<TipOznake> dajCvor(int broj)
    {
        if(cvorovi[broj] == nullptr) throw"ne postoji cvor";
        return *cvorovi[broj];
    }

    virtual GranaIterator<TipOznake> dajGranePocetak()
    {
        for(int i=0; i<lista.size(); i++) {
            for(int j=0; j<lista[i].size(); j++) {
                if(lista[i][j]!=nullptr) return GranaIterator<TipOznake>(this,i,j);
            }
        }
        return GranaIterator<TipOznake>(this,0,0);
    }

    virtual GranaIterator<TipOznake> dajGraneKraj()
    {
        for(int i=lista.size()-1; i>0; i--) {
            for(int j=lista[i].size()-1; j>0; j--) {
                if(lista[i][j]!=nullptr) {
                    if(j<lista[i].size()-1)
                        return GranaIterator<TipOznake>(this,i,j+1);
                    else return GranaIterator<TipOznake>(this,i+1,0);
                }
            }
        }
        return GranaIterator<TipOznake>(this,lista.size()-1,lista[lista.size()-1].size()-1);
    }


    friend class GranaIterator<TipOznake>;

    template<typename TipOznake1>
    friend void dfs(UsmjereniGraf<TipOznake1> *graf, std::vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor);
    template<typename TipOznake1>
    friend void bfs(UsmjereniGraf<TipOznake1> *graf, std::vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor,int sljedeci);
};

template<typename TipOznake1>
void dfs(UsmjereniGraf<TipOznake1> *graf, std::vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor)
{
    ListaGraf<TipOznake1> *mat=dynamic_cast<ListaGraf<TipOznake1>*>(graf);
    auto posjecen=TipOznake1(1);
    mat->cvorovi[cvor.dajRedniBroj()]->postaviOznaku(posjecen);
    obilazak.push_back(cvor);
    mat->brojPosjecenih++;
    for(int j=0; j<mat->lista[cvor.dajRedniBroj()].size(); j++) {
        if(mat->lista[cvor.dajRedniBroj()][j]->dajDolazniCvor().dajOznaku()!=posjecen) {
            dfs(graf,obilazak,mat->lista[cvor.dajRedniBroj()][j]->dajDolazniCvor());
        }
    }
    if(mat->brojPosjecenih <mat->dajBrojCvorova()) {
        for(int i=0; i < mat->lista.size(); i++) {
            for(int j=0; j < mat->lista[i].size(); j++) {
                if(mat->lista[i][j] != nullptr && mat->lista[i][j]->dajDolazniCvor().dajOznaku()!=posjecen) {
                    if(mat->cvorovi[i]->dajOznaku()!=posjecen) {
                        mat->cvorovi[i]->postaviOznaku(posjecen);
                        obilazak.push_back(*mat->cvorovi[i]);
                    }
                    dfs(graf,obilazak,mat->lista[i][j]->dajDolazniCvor());
                }
            }
        }
    }
    if(mat->brojPosjecenih == mat->dajBrojCvorova()) mat->brojPosjecenih=0;
}
template<typename TipOznake1>
void bfs(UsmjereniGraf<TipOznake1> *graf, std::vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor,int sljedeci=0)
{
    ListaGraf<TipOznake1> *mat=dynamic_cast<ListaGraf<TipOznake1>*>(graf);
    if(mat->brojPosjecenih == mat->dajBrojCvorova()) {
        mat->brojPosjecenih=0;
        return;
    }
    auto posjecen = TipOznake1(1);
    if(mat->cvorovi[cvor.dajRedniBroj()]->dajOznaku()!=posjecen) {
        mat->cvorovi[cvor.dajRedniBroj()]->postaviOznaku(posjecen);
        obilazak.push_back(cvor);
        mat->brojPosjecenih++;
    }
    for(int i=0; i<mat->lista[cvor.dajRedniBroj()].size(); i++) {
        if(mat->lista[cvor.dajRedniBroj()][i]->dajDolazniCvor().dajOznaku()!=posjecen) {
            obilazak.push_back(mat->lista[cvor.dajRedniBroj()][i]->dajDolazniCvor());
            // mat->cvorovi[i]->postaviOznaku(posjecen);
            mat->lista[cvor.dajRedniBroj()][i]->dajDolazniCvor().postaviOznaku(posjecen);
            mat->brojPosjecenih++;
        }
    }
    bfs(graf,obilazak,obilazak[++sljedeci],sljedeci);
}


template <typename TipOznake>
class GranaIterator
{
    ListaGraf<TipOznake> *lista;
    int p,y;
public:
    GranaIterator(ListaGraf<TipOznake> *pok, int polazni,int dolazni) : lista(pok),p(polazni),y(dolazni) {}
    Grana<TipOznake> operator*()
    {

        return *lista->lista[p][y];
        throw "kraj";
    }
    bool operator==(const GranaIterator &it) const
    {
        return (lista==it.lista && p==it.p && y==it.y);
    }

    bool operator!=(const GranaIterator &it) const
    {
        return !(lista==it.lista && p==it.p && y==it.y);
    }
    GranaIterator& operator++()
    {
        if(p==lista->lista.size()-1 && y==lista->lista[lista->lista.size()-1].size()-1) return *this;
        if(y!=lista->lista[p].size()-1) y++;
        else {
            y=0;
            p++;
        }
        return *this;
    }

    GranaIterator operator++(int)
    {
        GranaIterator<TipOznake> stari(lista,p,y);
        if(p==lista->lista.size()-1 && y==lista->lista[lista.size()-1].size()-1) return *this;
        if(y!=lista->lista[p].size()-1) y++;
        else {
            y=0;
            p++;
        }
        return stari;
    }
};



int main()
{

    UsmjereniGraf<bool> *g = new ListaGraf<bool>(6);
    g->dodajGranu(0, 1, 2.5);
    g->dodajGranu(1, 0, 1.2);
    g->dodajGranu(1, 2, 0.1);
    g->dodajGranu(0, 0, 3.14);
    for (GranaIterator<bool> iter = g->dajGranePocetak();
         iter != g->dajGraneKraj(); ++iter)
        cout << "(" << (*iter).dajPolazniCvor().dajRedniBroj() << ","
             << (*iter).dajDolazniCvor().dajRedniBroj() << ") -> "
             << (*iter).dajTezinu() << "; ";
    delete g;
    std::cout << "Zadaća 5, Zadatak 1";
    return 0;
}