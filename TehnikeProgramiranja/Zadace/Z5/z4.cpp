//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 5, Zadatak 4
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
class Spremnik {
    //protected:
    double tezina;
    std::string naziv_robe;
public:
    Spremnik (double tezina, std::string naziv_robe) : tezina(tezina), naziv_robe(naziv_robe) {}
    virtual ~Spremnik() {}
    double DajTezinu() const {return tezina;}
    std::string DajNaziv() const {return naziv_robe;}
    virtual double DajUkupnuTezinu () const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik* DajKopiju () const =0;
};
class Sanduk :public Spremnik {
    std::vector<double> tezine_predmeta;
public:
    Sanduk (double tezina, std::string naziv_predmeta, std::vector<double> tezine_predmeta) : Spremnik(tezina,naziv_predmeta), tezine_predmeta(tezine_predmeta) {}
    double DajUkupnuTezinu() const override {
        return std::accumulate(tezine_predmeta.begin(),tezine_predmeta.end(),DajTezinu(),std::plus<double>());
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Sanduk\nSadrzaj: "<<DajNaziv()<<std::endl<<"Tezine predmeta: ";
        std::for_each(tezine_predmeta.begin(), tezine_predmeta.end(),[](double n){std::cout<<n<<" ";});
        std::cout<<"(kg)\nVlastita tezina: "<<DajTezinu()<<" (kg)\nUkupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
    }
    Spremnik* DajKopiju () const override {
        return new Sanduk(*this);
    }
};
class Vreca : public Spremnik {
    double tezina_materije;//praskasta materija
public:
    Vreca (double tezina, std::string naziv_materije, double tezina_materije) : Spremnik(tezina,naziv_materije), tezina_materije(tezina_materije) {}

    double DajUkupnuTezinu() const override {
        return DajTezinu()+tezina_materije;
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Vreca\nSadrzaj: "<<DajNaziv()<<"\nVlastita tezina: "<<DajTezinu()<<" (kg)\n"<<
                 "Tezina pohranjene materije: "<<tezina_materije<<" (kg)\nUkupna tezina: "<<DajUkupnuTezinu();
        std::cout<<" (kg)\n";
    }
    Spremnik* DajKopiju () const override {
        return new Vreca(*this);
    }
};
class Bure : public Spremnik {
    double specificna_tezina_tecnosti;
    double zapremina_tecnosti;
public:
    Bure (double tezina, std::string naziv_tecnosti, double specificna_tezina_tecnosti, double zapremina_tecnosti) : Spremnik(tezina,naziv_tecnosti), specificna_tezina_tecnosti(specificna_tezina_tecnosti),zapremina_tecnosti(zapremina_tecnosti) {}
    double DajUkupnuTezinu() const override {
        return DajTezinu()+specificna_tezina_tecnosti*(zapremina_tecnosti/1000);
    }
    void Ispisi() const override {
        std::cout<<"Vrsta spremnika: Bure\nSadrzaj: "<<DajNaziv()<<"\nVlastita tezina: "<<DajTezinu()<<" (kg)\nSpecificna tezina tecnosti: "
                 <<specificna_tezina_tecnosti<<" (kg/m^3)\nZapremina tecnosti: "<<zapremina_tecnosti<<" (l)\nUkupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
    }
    Spremnik* DajKopiju () const override {
        return new Bure(*this);
    }
};
class PolimorfniSpremnik {
    Spremnik* p_spremnik;
    void Test() const {
        if(!p_spremnik) throw std::logic_error("Nespecificiran spremnik");
    }
public:
    PolimorfniSpremnik() : p_spremnik(nullptr) {}
    ~PolimorfniSpremnik() { delete p_spremnik; }
    PolimorfniSpremnik(const Spremnik &s) : p_spremnik(s.DajKopiju()) {}
    PolimorfniSpremnik(const PolimorfniSpremnik &s) {
        if(!s.p_spremnik) p_spremnik=nullptr;
        else p_spremnik=s.p_spremnik->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&s) {
        p_spremnik=s.p_spremnik;
        s.p_spremnik=nullptr;
    }
    PolimorfniSpremnik &operator=(const PolimorfniSpremnik &s) {
        Spremnik *p_novi(nullptr);
        if(s.p_spremnik!=nullptr) p_novi=s.p_spremnik->DajKopiju();
        delete p_spremnik;
        p_spremnik=p_novi;
        return *this;

    }
    PolimorfniSpremnik &operator=(PolimorfniSpremnik &&s) {
        std::swap(p_spremnik,s.p_spremnik);
        return *this;
    }
    double DajTezinu() const {
        Test();
        return p_spremnik->DajTezinu();
    }
    double DajUkupnuTezinu() const {
        Test();
        return p_spremnik->DajUkupnuTezinu();
    }
    void Ispisi() const {
        Test();
        p_spremnik->Ispisi();
    }
};
int main ()
{

    return 0;
}