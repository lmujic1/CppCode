//TP 2018/2019: Zadaća 5, Zadatak 6
#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
template <typename TipElemenata>
class DatotecniKontejner {
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime_datoteke)  {
        tok.clear();
        std::ifstream tok1(ime_datoteke,std::ios::binary);
        if(tok1.fail()){
            std::ofstream tok2(ime_datoteke,std::ios::binary);
            if(tok2.fail()) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
            tok2.close();
        }
        else tok1.close();
        tok.open(ime_datoteke,std::ios::in | std::ios::out | std::ios::binary);

    }
    void DodajNoviElement(const TipElemenata &element) {
        tok.clear();
        tok.seekp((DajBrojElemenata())*sizeof(TipElemenata));
        TipElemenata t(element);
        tok.write(reinterpret_cast<char*>(&t),sizeof (TipElemenata));
        if(tok.fail()) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.seekg(0,std::ios::cur);
    }
    int DajBrojElemenata() {
        tok.clear();
        tok.seekg(0,std::ios::end);
        int duzina_dat=tok.tellg();
        int br_el=duzina_dat/sizeof(TipElemenata);
        return br_el;
    }
    TipElemenata DajElement(int pozicija) {
        if(pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        TipElemenata t;
        tok.seekg(pozicija*sizeof(TipElemenata));
        tok.read(reinterpret_cast<char*>(&t),sizeof t);
        if(tok.fail()) throw std::logic_error("Probemi prilikom pristupa datoteci");
        return t;
    }
    void IzmijeniElement(int pozicija, const TipElemenata &element) {
        if(pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
        TipElemenata t(element);
        tok.seekp(pozicija*sizeof(TipElemenata));
        tok.write(reinterpret_cast<char*> (&t), sizeof t);
        if(tok.fail()) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.seekg(0,std::ios::end);
    }
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>()) {
        tok.seekg(0);
        std::vector<TipElemenata> v;
        TipElemenata t;
        while(tok.read(reinterpret_cast<char*>(&t),sizeof t)) {
            v.push_back(t);
        }
        //if(tok.fail()) throw std::logic_error("Probemi prilikom pristupa datoteci");
        tok.clear();
        std::sort(v.begin(),v.end(),kriterij);
        for(int i=0;i<v.size();i++) {
            tok.seekp(i*sizeof(TipElemenata));
            TipElemenata t(v.at(i));
            tok.write(reinterpret_cast<char*>(&t),sizeof t);
        }
        if(tok.fail()) {tok.clear();throw std::logic_error("Probemi prilikom pristupa datoteci");}
        tok.seekg(0);
    }
};

int main ()
{

    //AT3 (c9) - Testiranje konstruktora
    DatotecniKontejner<int> dk1("ime5.DAT");
    DatotecniKontejner<int> dk2("ime5.DAT");
    DatotecniKontejner<int> dk3("ime6.DAT");
    DatotecniKontejner<double> dk5("ime3.DAT");
    DatotecniKontejner<double> dk6("ime3.DAT");
    DatotecniKontejner<double> dk7("ime4.DAT");
    //dk1.DodajNoviElement(1);

    //dk2.DodajNoviElement(1);

    std::cout<<dk1.DajBrojElemenata()<<" "<<dk2.DajBrojElemenata()<<" "<<dk3.DajBrojElemenata()<<std::endl;

    return 0;
}
//
// Created by 38760 on 18. 9. 2021..
//

