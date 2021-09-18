/*
    TP 16/17 (Tutorijal 9, Zadatak 4)

	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <iomanip>
class Sat {
    int sat,minute,sekunde;
public:
    static bool DaLiJeIspravno (int h,int m,int s) {
        return (!(h<0 || h>23 || m<0 || m>59 || s<0 || s>59));
    }
    void Postavi (int h,int m,int s) {
        if(!DaLiJeIspravno(h,m,s)) throw std::domain_error("Neispravno vrijeme");
        Sat::sat=h;
        Sat::minute=m;
        Sat::sekunde=s;
    }
    void PostaviNormalizirano(int h,int m,int s) {
        while(s<0) { s+=60; m--; }
        while(m<0) { m+=60; h--; }
        while(h<0) { h+=24; }
        while(s>59) { s-=60; m++; }
        while(m>59) { m-=60; h++; }
        while(h>23) { h-=24; }
        Sat::sat=h;
        Sat::minute=m;
        Sat::sekunde=s;
    }
    Sat() {
        sat=0;
        minute=0;
        sekunde=0;
    }
    Sat(int sat,int minute,int sekunde) {
        Sat::sat=sat;
        Sat::minute=minute;
        Sat::sekunde=sekunde;
        PostaviNormalizirano(Sat::sat,Sat::minute,Sat::sekunde);
    }
    Sat (const Sat &s) {
        sat=s.sat;
        minute=s.minute;
        sekunde=s.sekunde;
        PostaviNormalizirano(sat,minute,sekunde);
    }
    virtual ~Sat() {}
    int DajSate () const {return Sat::sat;}
    int DajMinute () const {return Sat::minute;}
    int DajSekunde () const {return Sat::sekunde;}
    Sat &operator++() {
        sekunde++;
        PostaviNormalizirano(sat,minute,sekunde);
        return *this;
    }
    Sat operator++(int) {
        Sat pom(*this);
        sekunde++;
        PostaviNormalizirano(sat,minute,sekunde);
        return pom;
    }
    Sat &operator--() {
        sekunde--;
        PostaviNormalizirano(sat,minute,sekunde);
        return *this;
    }
    Sat operator--(int) {
        Sat pom(*this);
        sekunde--;
        PostaviNormalizirano(sat,minute,sekunde);
        return pom;
    }
    Sat &operator+=(int br_sec) {
        sekunde+=br_sec;
        PostaviNormalizirano(sat,minute,sekunde);
        return *this;
    }
    Sat &operator-=(int br_sec) {
        sekunde-=br_sec;
        PostaviNormalizirano(sat,minute,sekunde);
        return *this;
    }
    Sat operator + (int n) {
        Sat pom(this->sat,this->minute,this->sekunde+n);
        return pom;
    }
    Sat operator - (int n) {
        Sat pom(this->sat,this->minute,this->sekunde-n);
        return pom;
    }
    friend int operator -(const Sat &s1,const Sat &s2);
    friend std::ostream &operator << (std::ostream &tok, Sat s);
};
std::ostream &operator <<(std::ostream &tok, Sat s){
    tok<<std::setw(2)<<std::setfill('0')<<s.sat<<":"<<std::setw(2)<<std::setfill('0')<<s.minute<<":"<<std::setw(2)<<std::setfill('0')<<s.sekunde;
    return tok;
}
int operator - (const Sat &s1,const Sat &s2) {
    return (s1.DajSate()*3600+s1.DajMinute()*60+s1.DajSekunde())-(s2.DajSate()*3600+s2.DajMinute()*60+s2.DajSekunde());
}

int main ()
{
    return 0;
}