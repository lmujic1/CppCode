/*
    TP 16/17 (Tutorijal 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <memory>
#include <vector>
const double pi=4*atan(1.);
class Lik {
public:
    virtual ~Lik() {}
    virtual void IspisiSpecificnosti() const=0;
    virtual double DajObim() const=0;
    virtual double DajPovrsinu() const=0;
    void Ispisi() {
        IspisiSpecificnosti();
        std::cout<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu()<<std::endl;
    }
};
class Krug : public Lik {
    double poluprecnik;
public:
    Krug(double poluprecnik) : poluprecnik(poluprecnik) {
        if(poluprecnik<=0) throw std::domain_error("Neispravni parametri");
    }
    void IspisiSpecificnosti() const override {
        std::cout<<"Krug poluprecnika "<<poluprecnik<<std::endl;
    }
    double DajObim() const override {
        return 2*poluprecnik*pi;
    }
    double DajPovrsinu() const override {
        return poluprecnik*poluprecnik*pi;
    }
};
class Pravougaonik : public Lik {
    double a,b;
public:
    Pravougaonik (double a,double b) : a(a),b(b) {
        if(a<=0 || b<=0) throw std::domain_error("Neispravni parametri");
    }
    void IspisiSpecificnosti() const override {
        std::cout<<"Pravougaonik sa stranicama duzine "<<a<<" i "<<b<<std::endl;
    }
    double DajObim() const override {
        return 2*a+2*b;
    }
    double DajPovrsinu() const override {
        return a*b;
    }
};
class Trougao : public Lik {
    double a,b,c;
public:
    Trougao(double a,double b,double c) :a(a),b(b),c(c) {
        if(a+b<=c || a+c<=b || b+c<=a) throw std::domain_error("Neispravni parametri");
    }
    void IspisiSpecificnosti() const override {
        std::cout<<"Trougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c<<std::endl;
    }
    double DajObim() const override {
        return a+b+c;
    }
    double DajPovrsinu() const override {
        double s((a+b+c)/2);
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};
int main ()
{
    std::cout<<"Koliko zelite likova: ";
    int n;
    std::cin>>n;
    if(!std::cin) return 0;
    int i(1);
    std::vector<std::shared_ptr<Lik>> vektor;
    while(true) {
        try {
            std::cout<<"Lik "<<i<<": ";
            char znak;
            std::cin>>znak;
            if(znak=='P') {
                double a,b;
                std::cin>>a;
                std::cin>>znak;
                std::cin>>b;
                if(!std::cin ||std::cin.peek()!='\n') {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                    continue;
                }
                auto p(std::shared_ptr<Lik>(new Pravougaonik(a,b)));
                vektor.push_back(p);
            }
            else if (znak=='K') {
                double r;
                std::cin>>r;
                if(!std::cin || std::cin.peek()!='\n') {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                    continue;
                }
                auto p(std::shared_ptr<Lik>(new Krug(r)));
                vektor.push_back(p);
            }

            else if(znak=='T') {
                double a,b,c;
                std::cin>>a;
                std::cin>>znak;
                std::cin>>b;
                std::cin>>znak;
                std::cin>>c;
                if(!std::cin ||std::cin.peek()!='\n') {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                    continue;
                }
                auto p(std::shared_ptr<Lik>(new Trougao(a,b,c)));
                vektor.push_back(p);

            }
            else {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                continue;
            }
            if(i==n) break;
            i++;
        } catch (...) {
            std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
        }

    }
    std::cout<<std::endl;
    for(auto p :vektor) {
        p->Ispisi();
    }
    return 0;
}