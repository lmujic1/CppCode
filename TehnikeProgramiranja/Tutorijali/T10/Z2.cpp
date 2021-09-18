//
// Created by 38760 on 18. 9. 2021..
//

#include <iostream>
#include <cmath>
#include <iomanip>
class Krug {
    double poluprecnik;
public:
    explicit Krug(double poluprecnik) {
        if(poluprecnik<=0) throw std::domain_error("Neispravan poluprecnik");
        Krug::poluprecnik=poluprecnik;
    }
    void Postavi(double poluprecnik) {
        if(poluprecnik<=0) throw std::domain_error("Neispravan poluprecnik");
        Krug::poluprecnik=poluprecnik;
    }
    double DajPoluprecnik() const { return poluprecnik; }
    double DajObim() const { return 2*poluprecnik*4*atan(1); }
    double DajPovrsinu() const { return poluprecnik*poluprecnik*4*atan(1); }
    Krug &Skaliraj(double faktor_skaliranja) {
        if(faktor_skaliranja<=0) throw std::domain_error("Neispravan faktor skaliranja");
        poluprecnik*=faktor_skaliranja;
        return *this;
    }
    void Ispisi() const {std::cout<<std::setprecision(5)<<std::fixed<<"R="<<DajPoluprecnik()<<" O="<<DajObim()<<" P="<<DajPovrsinu();}
    friend class Valjak;
};

class Valjak {
    double visina;
    Krug baza;
public:
    explicit Valjak(double poluprecnik_baze,double visina) : baza(poluprecnik_baze) {
        if(poluprecnik_baze<0) throw std::domain_error("Neispravan poluprecnik");
        if(visina<0) throw  std::domain_error("Neispravna visina");
        Valjak::visina=visina;
    }
    void Postavi (double poluprecnik_baze,double visina) {
        if(poluprecnik_baze<0) throw std::domain_error("Neispravan poluprecnik");
        if(visina<0) throw  std::domain_error("Neispravna visina");
        baza=Krug(poluprecnik_baze);
        Valjak::visina=visina;
    }
    Krug DajBazu() const { return baza; }
    double DajPoluprecnikBaze() const { return baza.DajPoluprecnik(); }
    double DajVisinu() const { return visina; }
    double DajPovrsinu() const { return baza.DajPovrsinu()*2+baza.DajObim()*visina; }
    double DajZapreminu() const { return baza.DajPovrsinu()*visina; }
    Valjak &Skaliraj(double faktor_skaliranja) {
        if(faktor_skaliranja<=0) throw std::domain_error("Neispravan faktor skaliranja");
        baza.Skaliraj(faktor_skaliranja);
        visina*=faktor_skaliranja;
        return *this;
    }
    void Ispisi() const { std::cout<<std::setprecision(5)<<std::fixed<<"R="<<DajPoluprecnikBaze()<<" H="<<DajVisinu()<<" P="<<DajPovrsinu()<<" V="<<DajZapreminu(); }
};

int main() {
    return 0;
}