//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 16/17 (Tutorijal 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
class StedniRacun {
    static int aktivni;
    static int kreirani;
    double stanje_racuna;
public:
    /*StedniRacun() {
        stanje_racuna=0;
        aktivni++;
        kreirani++;
    }*/
    StedniRacun(const StedniRacun &s) {
        kreirani++;
        aktivni++;
        stanje_racuna=s.stanje_racuna;
    }
    ~StedniRacun () {
        aktivni--;
    }
    StedniRacun(double pocetna_vrijednost=0) {
        if(pocetna_vrijednost<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
        stanje_racuna=pocetna_vrijednost;
        kreirani++;
        aktivni++;
    }
    StedniRacun &Ulozi(double n) {
        if(stanje_racuna+n<0) throw std::logic_error("Transakcija odbijena");
        stanje_racuna+=n;
        return *this;
    }
    StedniRacun &Podigni(double n) {
        if(n>stanje_racuna) throw std::logic_error("Transakcija odbijena");
        stanje_racuna-=n;
        return *this;
    }
    double DajStanje() const { return stanje_racuna; }
    StedniRacun & ObracunajKamatu(double kamatna_stopa) {
        if(kamatna_stopa<0) throw std::logic_error("Nedozvoljena kamatna stopa");
        stanje_racuna+=((stanje_racuna*kamatna_stopa)/100);
        return *this;
    }
    static int DajBrojAktivnih() {
        return aktivni;
    }
    static int DajBrojKreiranih() {
        return kreirani;
    }
};
int StedniRacun::aktivni=0;
int StedniRacun::kreirani=0;
int main ()
{
    try {
        StedniRacun student=557;
        std::cout<<student.DajStanje();
        student.Ulozi(-656);
    } catch (std::logic_error a) {
        std::cout<<a.what()<<std::endl;
    }
    return 0;
}