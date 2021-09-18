//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 5, Zadatak 3
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <memory>
#include <fstream>
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
    //double DajTezinu() const override {
    //    return tezina;
    //}
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
    //double DajTezinu() const override {
    //    return tezina;
    //}
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

class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> roba;
public:
    Skladiste() {}
    Skladiste(const Skladiste &s) {
        roba.resize(s.roba.size());
        for(int i=0;i<s.roba.size();i++) roba[i]=std::shared_ptr<Spremnik>(s.roba[i]->DajKopiju());
    }
    Skladiste &operator =(const Skladiste &s){
        roba.resize(0);
        roba.resize(s.roba.size());
        for(int i=0;i<roba.size();i++) {
            roba[i]=std::shared_ptr<Spremnik>(s.roba[i]->DajKopiju());
        }
        return *this;
    }
    Spremnik* DodajSanduk(double tezina, std::string naziv_predmeta, std::vector<double> tezine_predmeta) {
        Spremnik *p(new Sanduk(tezina,naziv_predmeta,tezine_predmeta));
        std::shared_ptr<Spremnik> pom=std::shared_ptr<Spremnik>(p);
        roba.push_back(std::shared_ptr<Spremnik>(pom));
        return p;
    }
    Spremnik* DodajVrecu(double tezina, std::string naziv_materije, double tezina_materije) {
        Spremnik *p(new Vreca(tezina,naziv_materije,tezina_materije));
        roba.push_back(std::shared_ptr<Spremnik>(p));
        return p;
    }
    Spremnik* DodajBure(double tezina, std::string naziv_tecnosti, double specificna_tezina_tecnosti, double zapremina_tecnosti) {
        Spremnik *p(new Bure(tezina,naziv_tecnosti, specificna_tezina_tecnosti,zapremina_tecnosti));
        roba.push_back(std::shared_ptr<Spremnik>(p));
        return p;
    }
    Spremnik* DodajSpremnik(Spremnik* s, bool dodaj) {
        if (dodaj) {
            roba.push_back(std::shared_ptr<Spremnik>(s));
            return s;
        }
        else if(!dodaj) {
            Spremnik *p=s->DajKopiju();
            roba.push_back(std::shared_ptr<Spremnik>(p));
            return p;
        }
    }
    void BrisiSpremnik(Spremnik *s) {
        for(int i=0;i<roba.size()-1;i++) {
            if(roba.at(i)->DajTezinu()==s->DajTezinu() && roba.at(i)->DajNaziv()==s->DajNaziv()) {
                std::shared_ptr<Spremnik> tmp=roba.at(i);
                roba.at(i)=roba.at(i+1);
                roba.at(i)=tmp;
            }
        }
        roba.resize(roba.size()-1);
    }
    Spremnik& DajNajlaksi() const  {
        if(roba.size()==0) throw std::range_error("Skladiste je prazno");
        return **(std::min_element(roba.begin(),roba.end(),[](const std::shared_ptr<Spremnik> &s1,const std::shared_ptr<Spremnik> &s2) {
            return s1->DajTezinu()<s2->DajTezinu();
        }));
    }
    Spremnik& DajNajtezi() const {
        if(roba.size()==0) throw std::range_error("Skladiste je prazno");
        return **std::max_element(roba.begin(),roba.end(),[](std::shared_ptr<Spremnik> s1,std::shared_ptr<Spremnik> s2) {
            return s1->DajTezinu()<s2->DajTezinu();
        });
    }
    int BrojPreteskih (int kg) {
        return std::count_if(roba.begin(),roba.end(),[kg](std::shared_ptr<Spremnik> s){
            return s->DajUkupnuTezinu()>kg;
        });
    }
    void IzlistajSkladiste() {
        std::sort(roba.begin(),roba.end(),[]( std::shared_ptr<Spremnik> &s1, std::shared_ptr<Spremnik> &s2){
            return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();
        });
        std::for_each(roba.begin(),roba.end(),[](std::shared_ptr<Spremnik>s){s->Ispisi();});
    } //u opadajuci poredak po tezini
    void UcitajIzDatoteke(std::string naziv_dat){
        if(roba.size()!=0) roba.resize(0);
        std::ifstream ulazni_tok(naziv_dat.c_str());
        if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        else{
            while(!ulazni_tok.eof()) {
                char znak_spremnika,pom;
                std::string roba_u_spremniku;
                double tezina_spremnika;
                ulazni_tok>>znak_spremnika; //znak spremnika

                ulazni_tok.get(pom); //razmak izmedju znaka spremnika i naziva robe;

                while(ulazni_tok.get(pom)){
                    if(pom=='\n') break;
                    roba_u_spremniku+=pom;
                } //citanje stringa

                if(znak_spremnika=='S') {
                    int br_predmeta;
                    ulazni_tok>>tezina_spremnika>>br_predmeta;
                    std::vector<double> tezine_predmeta(br_predmeta);
                    for(int i=0;i<br_predmeta;i++) {
                        ulazni_tok>>tezine_predmeta.at(i);
                    }
                    DodajSanduk(tezina_spremnika,roba_u_spremniku,tezine_predmeta);
                }//sanduk
                else if(znak_spremnika=='V') {
                    double tezina_materije;
                    ulazni_tok>>tezina_spremnika>>tezina_materije;
                    DodajVrecu(tezina_spremnika,roba_u_spremniku,tezina_materije);
                }//vreca
                else if(znak_spremnika=='B') {
                    double specificna_tezina_tecnosti,zapremina_tecnosti;
                    ulazni_tok>>tezina_spremnika>>specificna_tezina_tecnosti>>zapremina_tecnosti;
                    DodajBure(tezina_spremnika,roba_u_spremniku,specificna_tezina_tecnosti,zapremina_tecnosti);
                }//bure
                else throw std::logic_error("Datoteka sadrzi besmislene podatke");
                if(!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
        }
        if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
    }
};
int main ()
{
    std::ofstream izlaz("ROBA.TXT");
    izlaz << "S Tepsije\n10 9 2 3 1 2 2 4 3 1 3\n";
    izlaz << "V Brasno\n0.2 5\n";
    izlaz << "B Suncokretovo ulje\n5 1300 150";
    izlaz.flush();
    izlaz.close();

    Skladiste ETF;
    ETF.DodajSanduk(1, "A", {1, 2, 3});
    ETF.UcitajIzDatoteke("ROBA.TXT");
    ETF.IzlistajSkladiste();
    return 0;
}