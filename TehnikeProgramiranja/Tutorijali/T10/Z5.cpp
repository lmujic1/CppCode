//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 16/17 (Tutorijal 10, Zadatak 4)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

constexpr double pi=4*atan(1.);
class Ugao {
    int stepeni,minute,sekunde;
    void PretvoriURadijane(double &rad,int stepeni,int minute,int sekunde) {
        while(sekunde>59) {sekunde-=60; minute++;}
        while(minute>59) {minute-=60; stepeni++;}
        while(stepeni>259) {stepeni-=360;}
        while(sekunde<0) {sekunde+=60; minute--;}
        while(minute<0) {minute+=60; stepeni--;}
        while(stepeni<0) {stepeni+=360;}
        rad=((stepeni+(minute*1.)/60+(sekunde*1.)/3600)*pi)/180;
    }
    void PrevoriUStepene (double radijani, int&stepeni, int&minute , int &sekunde) {
        stepeni=int(radijani*180/pi);
        minute=int((radijani*180/pi-stepeni)*60);
        sekunde=int(((radijani*180/pi-stepeni)*60-minute)*60);
    }
public:
    Ugao(double radijani = 0) {
        while(radijani>2*pi-0.0000000001) radijani-=2*pi;
        while(radijani<0) radijani+=2*pi;
        Ugao::radijani=radijani;
    }
    Ugao(int stepeni, int minute, int sekunde) {
        PretvoriURadijane(radijani,stepeni,minute,sekunde);
    }
    void Postavi(double radijani) {
        while(radijani>2*pi-0.0000000001) radijani-=2*pi;
        while(radijani<0) radijani+=2*pi;
        Ugao::radijani=radijani;
    }
    void Postavi(int stepeni, int minute, int sekunde) {
        PretvoriURadijane(radijani,stepeni,minute,sekunde);
    }
    double DajRadijane() const { return radijani; }
    void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde) {
        stepeni=DajStepene();
        minute=DajMinute();
        sekunde=DajSekunde();
    }
    int DajStepene() const {
        return int (radijani*180/pi);
    };
    int DajMinute() const {
        return int((radijani*180/pi-DajStepene())*60);
    }
    int DajSekunde() const {
        return ((radijani*180/pi-int(radijani*180/pi)-(int((radijani*180/pi-int(radijani*180/pi))*60)/60.))*3600.)+0.000000001;
    }
    void Ispisi() const {
        std::cout<<std::fixed<<std::setprecision(5)<<DajRadijane();
    }
    void IspisiKlasicno() const {
        std::cout<<DajStepene()<<"deg "<<DajMinute()<<"min "<<DajSekunde()<<"sec";
    }
    Ugao &SaberiSa(const Ugao &u) {
        Postavi(radijani+u.radijani);
        return *this;
    }
    Ugao &PomnoziSa(double x) {
        Postavi(radijani*x);
        return *this;
    }
    friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
    friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
};

Ugao ZbirUglova(const Ugao &u1, const Ugao &u2) {
    return u1.radijani+u2.radijani;
}
Ugao ProduktUglaSaBrojem(const Ugao &u, double x) {
    return u.radijani*x;
}
int main ()
{
    return 0;
}