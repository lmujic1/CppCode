//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 5, Zadatak 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <iterator>
class Berza {
    std::vector<int> stanje;
    int min_cijena,max_cijena;
public:
    Berza(int min_cijena,int max_cijena) : min_cijena(min_cijena),max_cijena(max_cijena) {
        if(min_cijena<0 || max_cijena<0) throw std::range_error("Ilegalne granice cijene");
    }
    Berza(int max_cijena) : min_cijena(0),max_cijena(max_cijena) {
        if(max_cijena<0) throw std::range_error("Ilegalne granice cijene");
    }
    void RegistrirajCijenu(int nova_cijena) {
        if(nova_cijena<min_cijena || nova_cijena>max_cijena) throw std::range_error("Ilegalna cijena");
        stanje.push_back(nova_cijena);
    }
    int DajMinimalnuCijenu() const {
        if(stanje.size()==0) throw std::range_error("Nema registriranih cijena");
        return *std::min_element(stanje.begin(),stanje.end());
    }
    int DajMaksimalnuCijenu() const {
        if(stanje.size()==0) throw std::range_error("Nema registriranih cijena");
        return *std::max_element(stanje.begin(),stanje.end());
    }
    int DajBrojRegistriranihCijena () const {
        return stanje.size();
    }
    int DajBrojCijenaVecihOd(int n) const {
        if(stanje.size()==0) throw std::range_error("Nema registriranih cijena");
        return std::count_if(stanje.begin(),stanje.end(),std::bind(std::greater<int>(),std::placeholders::_1,n));
    }
    void BrisiSve() {
        stanje.resize(0);
    }
    void Ispisi() const {
        std::vector<double> pomocni(stanje.size());
        std::transform(stanje.begin(),stanje.end(),pomocni.begin(),std::bind(std::divides<double>(),std::placeholders::_1,100));
        std::sort(pomocni.begin(),pomocni.end(),std::greater<double>());
        //for(int i=0;i<pomocni.size();i++) std::cout<<std::fixed<<std::setprecision(2)<<pomocni.at(i)<<std::endl;
        std::cout<<std::fixed<<std::setprecision(2);
        std::copy(pomocni.begin(),pomocni.end(),std::ostream_iterator<double>(std::cout,"\n"));
    }
    bool operator ! () const {
        if(stanje.size()==0) return true;
        return false;
    }
    int operator [] (int indeks) const {
        if(indeks>stanje.size()) throw std::range_error("Neispravan indeks");
        return stanje.at(indeks-1);
    }
    Berza &operator ++();
    Berza &operator --();
    Berza operator ++(int);
    Berza operator --(int);
    Berza operator -();
    Berza operator + (int b);
    Berza operator + (const Berza &b);
    Berza operator - (int b);
    Berza operator - (const Berza &b);
    Berza &operator += (const Berza &b);
    Berza &operator -= (const Berza &b);
    Berza &operator +=(int b);
    Berza &operator -=(int b);
    friend Berza operator + (int b1,const Berza &b2);
    friend Berza operator - (int b1,const Berza &b2);
    friend bool operator == (const Berza &b1,const Berza &b2);
    friend bool operator != (const Berza &b1,const Berza &b2);

    template<typename Tip>
    Berza operator +(Tip b) = delete ;
    template<typename Tip>
    Berza operator -(Tip b) = delete ;
    template<typename Tip>
    Berza &operator ++(Tip b) = delete ;
    template<typename Tip>
    Berza &operator --(Tip b) = delete ;
    template<typename Tip>
    Berza &operator +=(Tip b) = delete ;
    template<typename Tip>
    Berza &operator -=(Tip b) = delete ;
    template<typename Tip>
    friend Berza operator +(Tip b1, const Berza &b2) = delete ;
    template<typename Tip>
    friend Berza operator -(Tip b1, const Berza &b2) = delete ;
};
Berza &Berza::operator ++() {
    std::vector<int> pom(stanje.size());
    std::transform(stanje.begin(),stanje.end(),pom.begin(),std::bind(std::logical_and<bool>(),
                                                                     std::bind(std::less_equal<int>(),std::bind(std::plus<int>(),std::placeholders::_1,100),max_cijena),
                                                                     std::bind(std::greater_equal<int>(),std::bind(std::plus<int>(),std::placeholders::_1,-100),min_cijena)));
    if(!std::all_of(pom.begin(),pom.end(),std::bind(std::equal_to<int>(),std::placeholders::_1, 1))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(stanje.begin(),stanje.end(),stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    return *this;
}
Berza Berza::operator ++(int) {
    std::vector<int> pom(stanje.size());
    Berza b(*this);
    std::transform(this->stanje.begin(),this->stanje.end(),pom.begin(),std::bind(std::logical_and<bool>(),
                                                                                 std::bind(std::less_equal<int>(),std::bind(std::plus<int>(),std::placeholders::_1,100),max_cijena),
                                                                                 std::bind(std::greater_equal<int>(),std::bind(std::plus<int>(),std::placeholders::_1,-100),min_cijena))
    );
    if(!std::all_of(pom.begin(),pom.end(),std::bind(std::equal_to<int>(),std::placeholders::_1, 1))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(this->stanje.begin(),this->stanje.end(),this->stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    return b;
}
Berza &Berza::operator --() {
    std::vector<int> pom(stanje.size());
    std::transform(stanje.begin(),stanje.end(),pom.begin(),std::bind(std::logical_and<bool>(),
                                                                     std::bind(std::less_equal<int>(),std::bind(std::plus<int>(),std::placeholders::_1,100),max_cijena),
                                                                     std::bind(std::greater_equal<int>(),std::bind(std::plus<int>(),std::placeholders::_1,-100),min_cijena)));
    if(!std::all_of(pom.begin(),pom.end(),std::bind(std::equal_to<int>(),std::placeholders::_1, 1))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(stanje.begin(),stanje.end(),stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,-100));
    return *this;
}
Berza Berza::operator --(int) {
    Berza b(*this);
    std::vector<int> pom(stanje.size());
    std::transform(stanje.begin(),stanje.end(),pom.begin(),std::bind(std::logical_and<bool>(),
                                                                     std::bind(std::less_equal<int>(),std::bind(std::plus<int>(),std::placeholders::_1,100),max_cijena),
                                                                     std::bind(std::greater_equal<int>(),std::bind(std::plus<int>(),std::placeholders::_1,-100),min_cijena)));
    if(!std::all_of(pom.begin(),pom.end(),std::bind(std::equal_to<int>(),std::placeholders::_1, 1))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(this->stanje.begin(),this->stanje.end(),this->stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,-100));
    return b;
}
Berza Berza::operator -() {
    int n((*std::min_element(stanje.begin(),stanje.end()))-min_cijena);
    Berza b(*this);
    std::transform(this->stanje.begin(),this->stanje.end(),b.stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,-n));
    return b;
}
Berza Berza::operator + (int b) {
    Berza p(*this);
    std::transform(this->stanje.begin(),this->stanje.end(),p.stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,b));
    if(!std::all_of(p.stanje.begin(),p.stanje.end(),std::bind(std::less_equal<int>(),std::placeholders::_1, this->max_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return p;
}
Berza Berza::operator + (const Berza &b) {
    Berza p(*this);
    if(this->stanje.size()!=b.stanje.size() || this->min_cijena!=b.min_cijena || this->max_cijena!=b.max_cijena) throw std::domain_error("Nesaglasni operandi");
    std::transform(this->stanje.begin(),this->stanje.end(),b.stanje.begin(),p.stanje.begin(),std::plus<int>());
    if(!std::all_of(p.stanje.begin(),p.stanje.end(),std::bind(std::less_equal<int>(),std::placeholders::_1, this->max_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return p;
}
Berza Berza::operator - (int b) {
    Berza p(*this);
    std::transform(this->stanje.begin(),this->stanje.end(),p.stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,-b));
    if(!std::all_of(p.stanje.begin(),p.stanje.end(),std::bind(std::greater_equal<int>(),std::placeholders::_1, this->min_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return p;
}
Berza Berza::operator - (const Berza &b) {
    Berza p(*this);
    if(this->stanje.size()!=b.stanje.size() || this->min_cijena!=b.min_cijena || this->max_cijena!=b.max_cijena) throw std::domain_error("Nesaglasni operandi");
    std::transform(this->stanje.begin(),this->stanje.end(),b.stanje.begin(),p.stanje.begin(),std::minus<int>());
    if(!std::all_of(p.stanje.begin(),p.stanje.end(),std::bind(std::greater_equal<int>(),std::placeholders::_1, this->min_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return p;
}
Berza &Berza::operator +=(const Berza &b) {
    if(this->stanje.size()!=b.stanje.size() || this->min_cijena!=b.min_cijena || this->max_cijena!=b.max_cijena) throw std::domain_error("Nesaglasni operandi");
    std::transform(this->stanje.begin(),this->stanje.end(),b.stanje.begin(),this->stanje.begin(),std::plus<int>());
    if(!std::all_of(this->stanje.begin(),this->stanje.end(),std::bind(std::less_equal<int>(),std::placeholders::_1, this->max_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}
Berza &Berza::operator-=(const Berza &b) {
    if(this->stanje.size()!=b.stanje.size() || this->min_cijena!=b.min_cijena || this->max_cijena!=b.max_cijena) throw std::domain_error("Nesaglasni operandi");
    std::transform(this->stanje.begin(),this->stanje.end(),b.stanje.begin(),this->stanje.begin(),std::minus<int>());
    if(!std::all_of(this->stanje.begin(),this->stanje.end(),std::bind(std::greater_equal<int>(),std::placeholders::_1, this->min_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}
Berza operator + (int b1,const Berza &b2) {
    Berza p(b2);
    std::transform(b2.stanje.begin(),b2.stanje.end(),p.stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,b1));
    if(!std::all_of(p.stanje.begin(),p.stanje.end(),std::bind(std::less_equal<int>(),std::placeholders::_1, b2.max_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return p;
}
Berza operator - (int b1,const Berza &b2) {
    Berza p(b2);
    std::transform(b2.stanje.begin(),b2.stanje.end(),p.stanje.begin(),std::bind(std::minus<int>(),b1,std::placeholders::_1));
    if(!std::all_of(p.stanje.begin(),p.stanje.end(),std::bind(std::greater_equal<int>(),std::placeholders::_1, b2.min_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return p;
}
Berza &Berza::operator +=(int b) {
    //Berza p(*this);
    std::transform(this->stanje.begin(),this->stanje.end(),this->stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,b));
    if(!std::all_of(this->stanje.begin(),this->stanje.end(),std::bind(std::less_equal<int>(),std::placeholders::_1, this->max_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}
Berza &Berza::operator -=(int b) {
    //Berza p(*this);
    std::transform(this->stanje.begin(),this->stanje.end(),this->stanje.begin(),std::bind(std::plus<int>(),std::placeholders::_1,-b));
    if(!std::all_of(this->stanje.begin(),this->stanje.end(),std::bind(std::greater_equal<int>(),std::placeholders::_1, this->min_cijena))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}
bool operator == (const Berza &b1,const Berza &b2) {
    std::vector<int> pom;
    if(b1.stanje.size()==b2.stanje.size()) pom.resize(b1.stanje.size());
    std::transform(b1.stanje.begin(),b1.stanje.end(),b2.stanje.begin(),pom.begin(),std::equal_to<int>());
    return b1.stanje.size()==b2.stanje.size() && b1.max_cijena==b2.max_cijena && b1.min_cijena==b2.min_cijena
           && std::all_of(pom.begin(),pom.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,1));
}
bool operator != (const Berza &b1,const Berza &b2) {
    return !(b1==b2);
}

int main ()
{
    try{
        Berza b1 = Berza(1000,4000);
        Berza b2=Berza (1000,4000);
        b1.RegistrirajCijenu(1000);
        b2.RegistrirajCijenu(1000);
        Berza c=3000+b2;
        c.Ispisi();
        std::cout<<std::endl;
        b1.RegistrirajCijenu(2000);
        b2.RegistrirajCijenu(1500);
        std::cout<<b1[1];
        std::cout<<std::endl;
        b1+=5;
        std::cout<<std::endl;
        b1.Ispisi();
        std::cout<<std::endl<<(b1!=b2);
        std::cout<<std::endl;
        (--b1).Ispisi();
        std::cout<<std::endl;
        (b1++).Ispisi();
        std::cout<<std::endl;
        b1++;
        b1.Ispisi();
        std::cout<<std::endl;
        (-b1).Ispisi();
        b1.BrisiSve();
    }
    catch(std::range_error e) {
        std::cout<<std::endl<<e.what();
    }
    return 0;
}

