//
// Created by 38760 on 18. 9. 2021..
//

#include <iostream>
#include <vector>

template <typename TipOznake>
class Cvor;
template <typename TipOznake>
class Grana;
template <typename TipOznake>
class GranaIterator;
template <typename TipOznake>
class MatricaGraf;

template <typename TipOznake>
class UsmjereniGraf
{
public:
    UsmjereniGraf () = default;
    virtual ~UsmjereniGraf() {}
    virtual int dajBrojCvorova() =0;
    virtual void postaviBrojCvorova(int brCvorova) = 0;
    virtual void dodajGranu(int polazni, int dolazni, float tezina) =0;
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
};
template <typename TipOznake>
class MatricaGraf : public UsmjereniGraf<TipOznake>
{
protected:
    std::vector<std::vector<Grana<TipOznake>*>> mat;
    std::vector<Cvor<TipOznake>*> cvorovi;
    int brojPosjecenih=0;
public:
    MatricaGraf(int brCvorova)
    {
        mat.resize(brCvorova);
        for(int i=0; i<brCvorova; i++) mat[i].resize(brCvorova, nullptr);
        cvorovi.resize(brCvorova,nullptr);
        for(int i=0; i<brCvorova; i++) cvorovi[i] = new Cvor<TipOznake>(TipOznake{},i,this);
    }

    ~MatricaGraf()
    {
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat.size(); j++) {
                delete mat[i][j];
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
        if(brCvorova<cvorovi.size()) throw "Nedozvoljena vrijednost";
        mat.resize(brCvorova);
        for(int i=0; i<brCvorova; i++) mat[i].resize(brCvorova,nullptr);
        int vel=cvorovi.size();
        cvorovi.resize(brCvorova,nullptr);
        for(int i=vel; i<cvorovi.size(); i++) cvorovi[i]=new Cvor<TipOznake>(TipOznake{},i,this);
    }

    void dodajGranu(int polazni, int dolazni, float tezina)
    {
        if(mat[polazni][dolazni] != nullptr || polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        mat[polazni][dolazni] = new Grana <TipOznake> (tezina, TipOznake{}, cvorovi[polazni],cvorovi[dolazni]);
    }

    void obrisiGranu(int polazni,int dolazni)
    {
        if(mat[polazni][dolazni] == nullptr || polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        delete mat[polazni][dolazni];
        mat[polazni][dolazni] = nullptr;
    }

    void postaviTezinuGrane(int polazni,int dolazni, float tezina)
    {
        if(mat[polazni][dolazni] == nullptr || polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        mat[polazni][dolazni]->postaviTezinu2(tezina);
    }

    float dajTezinuGrane(int polazni,int dolazni)
    {
        if(mat[polazni][dolazni] == nullptr || polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        return mat[polazni][dolazni]->dajTezinu();
    }

    bool postojiGrana(int polazni, int dolazni)
    {
        if(polazni>cvorovi.size() || dolazni>cvorovi.size()) return false;
        return mat[polazni][dolazni];
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
        if(mat[polazni][dolazni] == nullptr || polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        mat[polazni][dolazni]->postaviOznaku2(oznaka);
    }

    TipOznake dajOznakuGrane(int polazni,int dolazni)
    {
        if(mat[polazni][dolazni] == nullptr || polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        return mat[polazni][dolazni]->dajOznaku();
    }

    Grana<TipOznake> dajGranu(int polazni,int dolazni)
    {
        if(mat[polazni][dolazni] == nullptr || polazni>cvorovi.size() || dolazni>cvorovi.size()) throw "Losi podaci";
        return *mat[polazni][dolazni];
    }

    Cvor<TipOznake> dajCvor(int broj)
    {
        if(cvorovi[broj] == nullptr) throw"ne postoji cvor";
        return *cvorovi[broj];
    }

    virtual GranaIterator<TipOznake> dajGranePocetak()
    {
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat.size(); j++) {
                if(mat[i][j]!=nullptr) return GranaIterator<TipOznake>(this,i,j);
            }
        }
        return GranaIterator<TipOznake>(this,0,0);
    }

    virtual GranaIterator<TipOznake> dajGraneKraj()
    {
        for(int i=mat.size()-1; i>0; i--) {
            for(int j=mat.size()-1; j>0; j--) {
                if(mat[i][j]!=nullptr) {
                    if(j<mat.size()-1) return GranaIterator<TipOznake>(this,i,j+1);
                    else GranaIterator<TipOznake>(this,i+1,0);
                }
            }
        }
        return GranaIterator<TipOznake>(this,mat.size()-1,mat.size()-1);
    }


    friend class GranaIterator<TipOznake>;

    template<typename TipOznake1>
    friend void dfs(UsmjereniGraf<TipOznake1> *graf, std::vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor);

    template<typename TipOznake1>
    friend void bfs(UsmjereniGraf<TipOznake1> *graf, std::vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor,int sljedeci);
};

template <typename TipOznake>
class GranaIterator
{
    MatricaGraf<TipOznake> * mat;
    int p,d;
public:
    GranaIterator(MatricaGraf<TipOznake> *pok, int polazni,int dolazni) : mat(pok),p(polazni),d(dolazni) {}
    Grana<TipOznake> operator*()
    {
        if(mat->mat[p][d]) return*(mat->mat[p][d]);
        throw "kraj";
    }
    bool operator==(const GranaIterator &it) const
    {
        return (mat==it.mat && p==it.p && d==it.d);
    }

    bool operator!=(const GranaIterator &it) const
    {
        return !(mat==it.mat && p==it.p && d==it.d);
    }
    GranaIterator& operator++()
    {
        if(p==mat->mat.size()-1 && d==mat->mat.size()-1) throw"kraj";
        bool kraj(false);
        GranaIterator<TipOznake> tmp=mat->dajGraneKraj();
        int x(tmp.p), y(tmp.d);
        for(int i=0; i<mat->mat.size(); i++) {
            for(int j=0; j<mat->mat.size(); j++) {
                if(i==x && j==y) {
                    p=x;
                    d=y;
                    return*this;
                } else if(((i==p && j>d) || i>p) && mat->mat[i][j]!=nullptr) {
                    p=i;
                    d=j;
                    kraj=true;
                    break;
                }
            }
            if(kraj) break;
        }
        return *this;
    }

    GranaIterator operator++(int)
    {
        GranaIterator<TipOznake> stari(mat,p,d);
        if(p==mat->mat.size()-1 && d==mat->mat.size()-1) throw"kraj";
        bool kraj(false);
        GranaIterator<TipOznake> tmp=mat->dajGraneKraj();
        int x(tmp.p), y(tmp.d);
        for(int i=0; i<mat->mat.size(); i++) {
            for(int j=0; j<mat->mat.size(); j++) {
                if(i==x && j==y) {
                    stari.p=x;
                    stari.d=y;
                    return*this;
                } else if(((i==p && j>d) || i>p) && mat->mat[i][j]!=nullptr) {
                    p=i;
                    d=j;
                    kraj=true;
                    break;
                }
            }
            if(kraj) break;
        }
        return stari;
    }
};


template<typename TipOznake1>
void dfs(UsmjereniGraf<TipOznake1> *graf, std::vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor)
{
    MatricaGraf<TipOznake1> *mat=dynamic_cast<MatricaGraf<TipOznake1>*>(graf);
    auto posjecen=TipOznake1(1);
    mat->cvorovi[cvor.dajRedniBroj()]->postaviOznaku(posjecen);
    obilazak.push_back(cvor);
    mat->brojPosjecenih++;
    for(int j=0; j<mat->dajBrojCvorova(); j++) {
        if(mat->mat[cvor.dajRedniBroj()][j] != nullptr && mat->mat[cvor.dajRedniBroj()][j]->dajDolazniCvor().dajOznaku()!=posjecen) {
            dfs(graf,obilazak,mat->mat[cvor.dajRedniBroj()][j]->dajDolazniCvor());
        }
    }
    if(mat->brojPosjecenih <mat->dajBrojCvorova()) {
        for(int i=0; i < mat->dajBrojCvorova(); i++) {
            for(int j=0; j < mat->dajBrojCvorova(); j++) {
                if(mat->mat[cvor.dajRedniBroj()][j] != nullptr && mat->mat[cvor.dajRedniBroj()][j]->dajDolazniCvor().dajOznaku()!=posjecen) {
                    if(mat->cvorovi[i]->dajOznaku()!=posjecen) {
                        mat->cvorovi[i]->postaviOznaku(posjecen);
                        obilazak.push_back(*mat->cvorovi[i]);
                    }
                    dfs(graf,obilazak,mat->mat[i][j]->dajDolazniCvor());
                }
            }
        }
    }
    if(mat->brojPosjecenih == mat->dajBrojCvorova()) mat->brojPosjecenih=0;
}
template<typename TipOznake1>
void bfs(UsmjereniGraf<TipOznake1> *graf, std::vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor,int sljedeci) {
    MatricaGraf<TipOznake1> *mat=dynamic_cast<MatricaGraf<TipOznake1>*>(graf);
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
    for(int i=0;i<mat->dajBrojCvorova();i++) {
        if(mat->mat[cvor.dajRedniBroj()][i] != nullptr && mat->mat[cvor.dajRedniBroj()][i]->dajDolazniCvor().dajOznaku()!=posjecen) {
            obilazak.push_back(mat->mat[cvor.dajRedniBroj()][i]->dajDolazniCvor());
            mat->cvorovi[i]->postaviOznaku(posjecen);
            mat->brojPosjecenih++;
        }
    }
    bfs(graf,obilazak,obilazak[++sljedeci],sljedeci);
}

using namespace std;
int main()
{

    return 0;
}