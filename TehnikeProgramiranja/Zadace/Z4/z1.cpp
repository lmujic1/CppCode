//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 4, Zadatak 1
#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
typedef std::pair<double, double> Tacka;
class Trougao {
    Tacka t1,t2,t3;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) t1=t;
        else if(indeks==2) t2=t;
        else t3=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double orijent(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        if(orijent<0) return -1;
        else if(orijent>0) return 1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return t1;
        else if(indeks==2) return t2;
        else return t3;
    }
    double DajStranicu(int indeks) const {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return sqrt((t2.first-t3.first)*(t2.first-t3.first)+((t2.second-t3.second)*(t2.second-t3.second)));
        else if(indeks==2) return sqrt((t1.first-t3.first)*(t1.first-t3.first)+((t1.second-t3.second)*(t1.second-t3.second)));
        else return sqrt((t1.first-t2.first)*(t1.first-t2.first)+((t1.second-t2.second)*(t1.second-t2.second)));
    }
    double DajUgao(int indeks) const {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        double a(DajStranicu(1));
        double b(DajStranicu(2));
        double c(DajStranicu(3));
        if(indeks==1) return acos((c*c+b*b-a*a)/(2*b*c));
        else if(indeks==2) return acos((c*c+a*a-b*b)/(2*a*c));
        else return acos((a*a+b*b-c*c)/(2*a*b));
    }
    Tacka DajCentar() const {
        return std::make_pair((t1.first+t2.first+t3.first)/3,(t1.second+t2.second+t3.second)/3);
    }
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const {
        return fabs((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))/2);
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(t1,t2,t3)==1) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        int orijent(Orijentacija(t1,t2,t3));
        if(Orijentacija(t1,t2,t)==orijent && Orijentacija(t2,t3,t)==orijent && Orijentacija(t3,t1,t)==orijent ) return true;
        return false;
    }
    void Ispisi() const {
        std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        t1.first+=delta_x;
        t1.second+=delta_y;
        t2.first+=delta_x;
        t2.second+=delta_y;
        t3.first+=delta_x;
        t3.second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        Tacka c(DajCentar());
        double delta_x(t.first-c.first),delta_y(t.second-c.second);
        Transliraj(delta_x,delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao) {
        t1=std::make_pair(t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao),t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao));
        t2=std::make_pair(t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao),t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao));
        t3=std::make_pair(t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao),t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor) {
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
        t1=std::make_pair(t.first+faktor*(t1.first-t.first),t.second+faktor*(t1.second-t.second));
        t2=std::make_pair(t.first+faktor*(t2.first-t.first),t.second+faktor*(t2.second-t.second));
        t3=std::make_pair(t.first+faktor*(t3.first-t.first),t.second+faktor*(t3.second-t.second));
        if(faktor<0) Rotiraj(t,180.);
    }
    void Rotiraj(double ugao) {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor) {
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    std::vector<std::pair<double,double>> v{t1.t1,t1.t2,t1.t3};
    if(std::count(v.begin(),v.end(),t2.t1)==1 && std::count(v.begin(),v.end(), t2.t2)==1 && std::count(v.begin(),v.end(),t2.t3)==1) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> u{t1.DajUgao(1),t1.DajUgao(2),t1.DajUgao(3)};
    int indeks(3);
    for(int i=0;i<3;i++) {
        if(t2.DajUgao(1)==u.at(i)) {
            indeks=i;
            break;
        }
    }
    /*if(indeks==0) {
        if(t1.DajStranicu(3)==t2.DajStranicu(2) && t1.DajStranicu(2)==t2.DajStranicu(3) && t1.DajUgao(1)==t2.DajUgao(1)) return true;
    }
    if(indeks==1) {
        if(t1.DajStranicu(1)==t2.DajStranicu(2) && t1.DajStranicu(3)==t2.DajStranicu(3) && t1.DajUgao(2)==t2.DajUgao(1)) return true;
    }
    if(indeks==2) {
        if(t1.DajStranicu(2)==t2.DajStranicu(2) && t1.DajStranicu(1)==t2.DajStranicu(3) && t1.DajUgao(3)==t2.DajUgao(1)) return true;
    }*/ //sus
    if(indeks==0) {
        if(t2.Orijentacija(t2.t1,t2.t2,t2.t3)!=t1.Orijentacija(t1.t1,t1.t2,t1.t3)) if(t2.DajStranicu(3)==t1.DajStranicu(1) && t2.DajUgao(2)==t1.DajUgao(2)) return true;
            else
            if(t2.DajStranicu(3)==t1.DajStranicu(3) && t2.DajUgao(2)==t1.DajUgao(2)) return false;
    }
    else if(indeks==1) {
        if(t2.Orijentacija(t2.t1,t2.t2,t2.t3)!=t1.Orijentacija(t1.t1,t1.t2,t1.t3)) if(t2.DajStranicu(3)==t1.DajStranicu(3) && t2.DajUgao(2)==t1.DajUgao(1)) return true;
            else
            if(t2.DajStranicu(3)==t1.DajStranicu(1) && t2.DajUgao(2)==t1.DajUgao(3)) return false;
    }
    else if(indeks==2) {
        if(t2.Orijentacija(t2.t1,t2.t2,t2.t3)!=t1.Orijentacija(t1.t1,t1.t2,t1.t3)) if(t2.DajStranicu(3)==t1.DajStranicu(2) && t2.DajUgao(2)==t1.DajUgao(3)) return true;
            else
            if(t2.DajStranicu(3)==t1.DajStranicu(2) && t2.DajUgao(2)==t1.DajUgao(1)) return false;
    }
    return true;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> u{t1.DajUgao(1),t1.DajUgao(2),t1.DajUgao(3)};
    int indeks(3);
    for(int i=0;i<3;i++) {
        if(t2.DajUgao(1)==u.at(i)) {
            indeks=i;
            break;
        }
    }
    if(indeks==0) {
        if(((t2.DajStranicu(2)/t1.DajStranicu(3)) == (t2.DajStranicu(3)/t1.DajStranicu(2))/*+0.000001*/) && t1.DajUgao(1)==t2.DajUgao(1)) return true;
    }
    if(indeks==1) {
        if(((t2.DajStranicu(2)/t1.DajStranicu(1)) == (t2.DajStranicu(3)/t1.DajStranicu(3))/*+0.000001*/) && t1.DajUgao(2)==t2.DajUgao(1)) return true;
    }
    else if(indeks==2) {
        if(((t2.DajStranicu(2)/t1.DajStranicu(2)) == (t2.DajStranicu(3)/t1.DajStranicu(1))/*+0.000001*/) && t1.DajUgao(3)==t2.DajUgao(1)) return true;
    }
    else return false;
}

int main ()
{

    std::cout<<"Koliko zelite kreirati trouglova: ";
    int br_trouglova;
    std::cin>>br_trouglova;
    std::vector<std::shared_ptr<Trougao>>  v,v1;
    for(int i=0;i<br_trouglova;i++) {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1,t2,t3;
        std::cin>>t1.first>>t1.second;
        std::cin>>t2.first>>t2.second;
        std::cin>>t3.first>>t3.second;
        try{
            std::shared_ptr<Trougao> pomocni(std::make_shared<Trougao>(t1,t2,t3));
            v.push_back(pomocni);
            // (*pomocni).Ispisi();
        }
        catch(std::domain_error) {
            std::cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::vector<double> vektor_translacije(2);
    double delta;
    std::cin>>delta;
    vektor_translacije.at(0)=delta;
    std::cin>>delta;
    vektor_translacije.at(1)=delta;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao_rotacije;
    std::cin>>ugao_rotacije;
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor_skaliranja;
    std::cin>>faktor_skaliranja;
    //v1.resize(br_trouglova);
    std::transform(v.begin(),v.end(),v.begin(),[&vektor_translacije,ugao_rotacije,faktor_skaliranja](std::shared_ptr<Trougao> t){
        t->Transliraj(vektor_translacije.at(0),vektor_translacije.at(1));
        Tacka pom(t->DajCentar());
        t->Rotiraj(ugao_rotacije);
        t->Skaliraj(t->DajTjeme(1),faktor_skaliranja);
        return t; });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao>t1,std::shared_ptr<Trougao>t2)->bool{
        return (t1->DajPovrsinu())<(t2->DajPovrsinu());});

    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> t)->void{
        t->Ispisi();
        std::cout<<std::endl;
    });
    auto it=std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao>t1,std::shared_ptr<Trougao> t2)->bool{
        return t1->DajObim()<t2->DajObim();
    });
    std::shared_ptr<Trougao> pom(*it);
    std::cout<<"Trougao sa najmanjim obimom: ";
    pom->Ispisi();
    bool prvi(true);
    for(int i=0;i<br_trouglova;i++) {
        for(int j=i+1;j<br_trouglova;j++) {
            if(DaLiSuIdenticni(*v.at(i),*v.at(j))) {
                if(prvi) {prvi=false; std::cout<<std::endl<<"Parovi identicnih trouglova: "<<std::endl; }
                v.at(i)->Ispisi();
                std::cout<<" i ";
                v.at(j)->Ispisi();
                std::cout<<std::endl;
            }
        }
    }
    if(prvi) std::cout<<std::endl<<"Nema identicnih trouglova!";
    prvi=true;
    for(int i=0;i<br_trouglova;i++) {
        for(int j=i+1;j<br_trouglova;j++) {
            if(!DaLiSuPodudarni(*v.at(i),*v.at(j))) {
                //if(DaLiSuIdenticni(*v.at(i),*v.at(j))) j++;
                //else {
                if(prvi) {prvi=false; std::cout<<"Parovi podudarnih trouglova: "<<std::endl; }
                v.at(i)->Ispisi();
                std::cout<<" i ";
                v.at(j)->Ispisi();
                std::cout<<std::endl;
            }
        }
    }
}
if(prvi) std::cout<<std::endl<<"Nema podudarnih trouglova!";
prvi=true;
// std::map<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> mapa;
for(int i=0;i<br_trouglova;i++) {
for(int j=i+1;j<br_trouglova;j++) {
if(DaLiSuSlicni(*v.at(i),*v.at(j))) {
if(prvi) {prvi=false; std::cout<<"Parovi slicnih trouglova: "<<std::endl; }
v.at(i)->Ispisi();
std::cout<<" i ";
v.at(j)->Ispisi();
std::cout<<std::endl;
}
}
}
if(prvi) std::cout<<std::endl<<"Nema slicnih trouglova!";
return 0;
}
