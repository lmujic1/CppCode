//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 4, Zadatak 2
#include <iostream>
#include <string>
#include <cmath>

//enum class Pol {Musko, Zensko};
class GradjaninBiH {
    std::string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH *prethodni;
    static GradjaninBiH *zadnji;

    void RasclanjeniJMBG(const long long int JMBG, int &dan, int &mjesec,int &godina, int &sifra_regije, int &pol, int &kod) {
        long long int pom(JMBG);
        kod=pom%10; pom/=10;
        pol=pom%1000; pom/=1000;
        sifra_regije=pom%100; pom/=100;
        godina=pom%1000; pom/=1000;
        mjesec=pom%100; pom/=100;
        dan=pom;
    }
    void PretvoriUJMBG(long long int &jmbg, long long int dan, long long int mjesec, long long int godina,long long int sifra_regije,long long int pol) {
        if(godina>=2000 && godina<=2017) godina-=2000;
        else if(godina>=1917 && godina<=1999) godina-=1000;

        jmbg=0;
        jmbg=dan*100000000000;
        jmbg+=mjesec*1000000000;
        jmbg+=godina*1000000;
        jmbg+=sifra_regije*10000;
        jmbg+=pol*10;
        int c13(KodOsobe(dan,mjesec,godina,sifra_regije,pol));
        if(c13==11) c13=0;
        jmbg+=c13;
    }
    static int KodOsobe(int dan,int mjesec,int godina,int sifra_regije,int pol) {
        if(godina>=2000 && godina<=2017) godina-=2000;
        else if(godina>=1917 && godina<=1999) godina-=1000;
        int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13;
        c1=dan/10;
        c2=dan%10;
        c3=mjesec/10;
        c4=mjesec%10;
        c5=godina/100;
        c6=godina/10-c5*10;
        c7=godina%10;
        c8=sifra_regije/10;
        c9=sifra_regije%10;
        c10=pol/100;
        c11=pol/10-c10*10;
        c12=pol%10;
        c13=11-(7*(c1+c7)+6*(c2+c8)+5*(c3+c9)+4*(c4+c10)+3*(c5+c11)+2*(c6+c12))%11;
        return c13;
    }
    static bool IspravnostDatuma(int dan,int mjesec,int godina) {
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina>=0 && godina<=17) godina+=2000;
        else if(godina>=917 && godina<=999) godina+=1000;
        else if((godina>=2000 && godina<=2017)||(godina>=1917 && godina<=1999)) godina+=0;
        else return false;

        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if(dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1] ) {/* std::cout<<"greska ";*/ return false;}
        return true;
    }

public:

    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {

        int dan,mjesec,godina,sifra_regije,pol,kod,c13;
        GradjaninBiH::RasclanjeniJMBG(jmbg,dan,mjesec,godina,sifra_regije,pol,kod);
        c13=KodOsobe(dan,mjesec,godina,sifra_regije,pol);

        if(!GradjaninBiH::IspravnostDatuma(dan,mjesec,godina) || (sifra_regije<0 || sifra_regije>99) || (c13==10)) throw std::logic_error("JMBG nije validan");
        for(GradjaninBiH *p=zadnji;p!=nullptr;p=p->prethodni) if(jmbg==p->jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");

        this->prethodni=zadnji;
        this->ime_i_prezime=ime_i_prezime;
        this->jmbg=jmbg;
        zadnji=this;

    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        int pol1;
        if(pol==GradjaninBiH::Pol::Musko) pol1=0;
        else pol1=500;
        int c13(KodOsobe(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol1));
        if(!GradjaninBiH::IspravnostDatuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || (sifra_regije<0 || sifra_regije>99) || c13==10) throw std::logic_error("Neispravni podaci");
        long long int j; GradjaninBiH::PretvoriUJMBG(j,dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol1);

        for(GradjaninBiH *p=zadnji;p!=nullptr;p=p->prethodni) if(j==p->jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");

        this->prethodni=zadnji;
        this->ime_i_prezime=ime_i_prezime;
        this->jmbg=j;
        zadnji=this;

    }
    std::string DajImeIPrezime() const {
        return ime_i_prezime;
    }
    virtual ~GradjaninBiH() {
        if(this->prethodni==nullptr) {
            for(GradjaninBiH *p=zadnji;p!=nullptr;p=zadnji->prethodni) {
                if(p->prethodni==this) {
                    p->prethodni=nullptr;
                    break;
                }
            }
        }
        else {
            for(GradjaninBiH *p=zadnji;p!=nullptr;p=zadnji->prethodni){
                if(p==this) {
                    p=this->prethodni;
                    this->prethodni=nullptr;
                    break;
                }
                else if(p->prethodni==this) {
                    p->prethodni=this->prethodni;
                    this->prethodni=nullptr;
                    break;
                }
            }
        }

    }
    long long int DajJMBG() const {
        return jmbg;
    }
    int DajDanRodjenja() const {
        return jmbg/100000000000;
    }
    int DajMjesecRodjenja() const {
        return jmbg/1000000000-DajDanRodjenja()*100;
    }
    int DajGodinuRodjenja() const {
        int god=jmbg/1000000-DajDanRodjenja()*100000-DajMjesecRodjenja()*1000;
        if(god>=0 && god<=17) god+=2000;
        else if(god>=917 && god<=999) god+=1000;
        return god;
    }
    int DajSifruRegije() const {
        int god=DajGodinuRodjenja();
        if(god>=2000 && god<=2017) god-=2000;
        else if(god>=1917 && god<=1999) god-=1000;
        return jmbg/10000-DajDanRodjenja()*10000000-DajMjesecRodjenja()*100000-god*100;
    }
    Pol DajPol() const {
        int god=DajGodinuRodjenja();
        if(god>=2000 && god<=2017) god-=2000;
        else if(god>=1917 && god<=1999) god-=1000;
        long long int pol(jmbg/10-DajDanRodjenja()*10000000000-DajMjesecRodjenja()*100000000-god*100000-DajSifruRegije()*1000);
        if(pol>=0 && pol<=499) return Pol::Musko;
        else if(pol>=500 && pol<=999) return Pol::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        ime_i_prezime=novo_ime;
    }
};

GradjaninBiH * GradjaninBiH::zadnji=nullptr;

int main ()
{
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    int n;
    std::cin>>n;
    std::cin.ignore(1000,'\n');
    for(int i=0;i<n;i++) {
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::string ime_i_prezime;
        std::getline(std::cin,ime_i_prezime);
        std::cout<<std::endl<<"Unesite JMBG: ";
        long long int jmbg;
        std::cin>>jmbg;
        std::cin.ignore(1000,'\n');
        try{
            GradjaninBiH g(ime_i_prezime,jmbg);
            std::cout<<std::endl<<"Unijeli ste gradjanina "<<g.DajImeIPrezime()<<" rodjenog "<<g.DajDanRodjenja()<<"."<<g.DajMjesecRodjenja()<<"."<<g.DajGodinuRodjenja()<<" u regiji "<<g.DajSifruRegije();
            int pol(g.DajPol());
            if(pol==0) std::cout<<", musko.";
            else if(pol==1) std::cout<<", zensko.";
        }
        catch(std::logic_error greska) {
            i--;
            std::cout<<std::endl<<greska.what();
        }
        std::cout<<std::endl;
    }

    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    int br;
    std::cin>>br;
    std::cin.ignore(1000,'\n');
    for(int i=0;i<br;i++) {
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::string ime_i_prezime;
        std::getline(std::cin,ime_i_prezime);
        std::cout<<std::endl<<"Unesite datum rodjenja (format dd/mm/gggg): ";
        int dan,mjesec,godina;
        char znak;
        std::cin>>dan>>znak>>mjesec>>znak>>godina;
        std::cout<<std::endl<<"Unesite sifru regije: ";
        int sifra_regije;
        std::cin>>sifra_regije;
        std::cin.ignore(1000,'\n');
        std::cout<<std::endl<<"Unesite M za musko, Z za zensko: ";
        char pol;
        std::cin>>pol;
        std::cin.ignore(1000,'\n');
        try{
            GradjaninBiH::Pol pom;
            if(pol=='M') pom=GradjaninBiH::Pol::Musko;
            else if(pol=='Z') pom=GradjaninBiH::Pol::Zensko;
            GradjaninBiH gr(ime_i_prezime,dan,mjesec,godina,sifra_regije,pom);
            std::cout<<std::endl<<"Unijeli ste gradjanina "<<gr.DajImeIPrezime()<<" JMBG: "<<gr.DajJMBG()<<".";
        }
        catch(std::logic_error greska) {
            i--;
            std::cout<<std::endl<<greska.what();
        }
        std::cout<<std::endl;
    }

    return 0;
}
