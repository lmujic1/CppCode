//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 16/17 (Tutorijal 9, Zadatak 4)

	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
class Sat {
    int sekunde;
public:
    static bool DaLiJeIspravno (int h,int m,int s) {
        return (!(h<0 || h>23 || m<0 || m>59 || s<0 || s>59));
    }
    void Postavi (int h,int m,int s) {
        if(!DaLiJeIspravno(h,m,s)) throw std::domain_error("Neispravno vrijeme");
        Sat::sekunde=h*3600+m*60+s;
    }
    void PostaviNormalizirano(int h,int m,int s) {
        while(s<0) { s+=60; m--; }
        while(m<0) { m+=60; h--; }
        while(h<0) { h+=24; }
        while(s>59) { s-=60; m++; }
        while(m>59) { m-=60; h++; }
        while(h>23) { h-=24; }
        Sat::sekunde=h*3600+m*60+s;
    }
    Sat &Sljedeci() {
        sekunde++;
//		PostaviNormalizirano(sat,minute,sekunde);
        return *this;
    }
    Sat &Prethodni() {
        sekunde--;
        while(sekunde<0) sekunde=(24*3600)+sekunde;
//		PostaviNormalizirano(sat,minute,sekunde);
        return *this;
    };
    Sat &PomjeriZa(int br_sec) {
        if(br_sec<0) while(br_sec!=0) {Prethodni(); br_sec++;}
        else sekunde+=br_sec;
//		PostaviNormalizirano(sat,minute,sekunde);
        return *this;
    }
    int DajSate () const {int sat=std::floor(sekunde/3600); while(sat>=24) sat-=24; return sat;}
    int DajMinute () const {return std::floor(sekunde%3600/60);}
    int DajSekunde () const {return std::floor(sekunde%60%60);}
    void Ispisi() const {std::cout<<std::setw(2)<<std::setfill('0')<<DajSate()<<":"<<std::setw(2)<<std::setfill('0')<<DajMinute()<<":"<<std::setw(2)<<std::setfill('0')<<DajSekunde(); }
    friend int BrojSekundiIzmedju (const Sat &s1,const Sat &s2);
    static int Razmak(const Sat &s1,const Sat &s2) { return BrojSekundiIzmedju(s1,s2); }
};

int BrojSekundiIzmedju (const Sat &s1,const Sat &s2) {
    return s1.sekunde-s2.sekunde;
    //return (s1.DajSate()*3600+s1.DajMinute()*60+s1.DajSekunde())-(s2.DajSate()*3600+s2.DajMinute()*60+s2.DajSekunde());
}

int main ()
{
    return 0;
}