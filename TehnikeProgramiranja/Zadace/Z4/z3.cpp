//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>
class Datum {
    int dan,mjesec,godina;
    static bool IspravnostDatuma(int dan,int mjesec,int godina) {
        int dani[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) dani[1]++;
        return dan<1 || mjesec<1 || mjesec>12 || dan>dani[mjesec-1];
    }
public:
    Datum(int dan, int mjesec, int godina) {
        if(IspravnostDatuma(dan,mjesec,godina)) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
        if(IspravnostDatuma(dan,mjesec,godina)) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    friend class Pregled;
    friend class Pregledi;
};
class Vrijeme {
    int sati, minute;
    static bool IspravnostVremena(int sati,int minute) {
        return (sati<0 || sati>23 || minute<0 || minute>59);
    }
public:
    Vrijeme(int sati, int minute) {
        if(IspravnostVremena(sati,minute)) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute) {
        if(IspravnostVremena(sati,minute)) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj () const {
        return std::make_pair(sati,minute);
    }
    void Ispisi() const {
        std::cout<<std::setprecision(2)<<std::setfill('0')<<sati<<":"<<std::setprecision(2)<<std::setfill('0')<<minute;
    }
    friend class Pregled;
    friend class Pregledi;
};
class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme_pregleda(sati_pregleda,minute_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        datum_pregleda.Postavi(novi_datum.dan,novi_datum.mjesec,novi_datum.godina);
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda.Postavi(novo_vrijeme.sati,novo_vrijeme.minute);
    }
    void PomjeriDanUnaprijed() {
        int dani[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((datum_pregleda.godina%4==0 && datum_pregleda.godina%100!=0) || datum_pregleda.godina%400==0) dani[1]++;
        datum_pregleda.dan++;
        if(datum_pregleda.dan>dani[datum_pregleda.mjesec-1]) {datum_pregleda.dan=1; datum_pregleda.mjesec++;}
        if(datum_pregleda.mjesec>12) {datum_pregleda.mjesec--; datum_pregleda.godina++;}
    }
    void PomjeriDanUnazad() {
        datum_pregleda.dan--;
        if(datum_pregleda.dan<1) {datum_pregleda.dan=1; datum_pregleda.mjesec--;}
        if(datum_pregleda.mjesec<1) {datum_pregleda.mjesec=1; datum_pregleda.godina--;}
    }
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        if(p1.datum_pregleda.godina>=p2.datum_pregleda.godina) {
            if(p1.datum_pregleda.mjesec>=p2.datum_pregleda.mjesec) {
                if(p1.datum_pregleda.dan>=p2.datum_pregleda.dan) {
                    if(p1.vrijeme_pregleda.sati>=p2.vrijeme_pregleda.sati) {
                        if(p1.vrijeme_pregleda.minute>=p2.vrijeme_pregleda.minute) return false;
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return true;
    }

    void Ispisi() const {
        std::cout<<std::left<<std::setw(30)<<std::setfill(' ')<<DajImePacijenta();
        datum_pregleda.Ispisi();
        std::cout<<" ";
        vrijeme_pregleda.Ispisi();
        std::cout<<std::endl;
    }
    friend class Pregledi;
};
class Pregledi {
    const int broj_pregleda;
    int trenutni_br_pregleda;
    Pregled **pok_na_listu_pregleda;
public:
    explicit Pregledi(int max_broj_pregleda) : broj_pregleda(max_broj_pregleda), trenutni_br_pregleda(0),pok_na_listu_pregleda(new Pregled*[max_broj_pregleda]{}) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda) :broj_pregleda(spisak_pregleda.size()),trenutni_br_pregleda(spisak_pregleda.size()),pok_na_listu_pregleda(new Pregled*[spisak_pregleda.size()]{}) {
        int brojac(0);
        try{
            for(auto x:spisak_pregleda) pok_na_listu_pregleda[brojac++]=new Pregled(x);
        }
        catch(...) {
            for(int i=0;i<brojac;i++)  delete pok_na_listu_pregleda[i];
            throw;
        }
    }
    ~Pregledi() {
        for(int i=0;i<trenutni_br_pregleda;i++) {
            delete pok_na_listu_pregleda[i];
        }
        //delete []pok_na_listu_pregleda;
    }
    Pregledi(const Pregledi &pregledi) : trenutni_br_pregleda(pregledi.broj_pregleda), broj_pregleda(pregledi.broj_pregleda), pok_na_listu_pregleda(new Pregled*[pregledi.broj_pregleda]{}) {
        if(pregledi.broj_pregleda>broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        try{
            for(int i=0;i<trenutni_br_pregleda;i++) pok_na_listu_pregleda[i]=new Pregled(*pok_na_listu_pregleda[i]);
        }
        catch(...) {
            for(int i=0;i<trenutni_br_pregleda;i++) {
                delete pok_na_listu_pregleda[i];
            }
            delete [] pok_na_listu_pregleda;
        }
    }
    Pregledi(Pregledi &&pregledi) :broj_pregleda(pregledi.broj_pregleda), trenutni_br_pregleda(pregledi.trenutni_br_pregleda) {
        if(&pregledi!=this) {
            for(int i=0;i<broj_pregleda;i++) {
                delete pok_na_listu_pregleda[i];
            }
            delete [] pok_na_listu_pregleda;
            pok_na_listu_pregleda=pregledi.pok_na_listu_pregleda;
            pregledi.pok_na_listu_pregleda=nullptr;
        }
    }
    Pregledi &operator =(const Pregledi &pregledi) {
        //if(&pregledi=this) return *this;
        for(int i=0;i<trenutni_br_pregleda;i++) delete pok_na_listu_pregleda[i];
        trenutni_br_pregleda=pregledi.trenutni_br_pregleda;
        try{
            for(int i=0;i<trenutni_br_pregleda;i++) pok_na_listu_pregleda[i]=new Pregled(*pregledi.pok_na_listu_pregleda[i]);
        }
        catch(...){
            for(int i=0;i<trenutni_br_pregleda;i++) delete pok_na_listu_pregleda[i];
            delete [] pok_na_listu_pregleda ;
            throw;
        }
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi) {
        //if(&pregledi=this) return *this;
        pok_na_listu_pregleda=pregledi.pok_na_listu_pregleda;
        pregledi.pok_na_listu_pregleda=nullptr;
        return *this;
    }


    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        //for(int i=0;i<broj_pregleda;i++) {
        //    if(pok_na_listu_pregleda[i]==nullptr) {
        try{
            pok_na_listu_pregleda[trenutni_br_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
            trenutni_br_pregleda++;
        }
        catch(...) {
            delete pok_na_listu_pregleda[trenutni_br_pregleda];
            pok_na_listu_pregleda[trenutni_br_pregleda]=nullptr;
        }
        //   break;
        //}
        //}
        for(int i=0;i<trenutni_br_pregleda;i++) {
            for(int j=i;j<trenutni_br_pregleda-1;j++) {
                if(!Pregled::DolaziPrije(*pok_na_listu_pregleda[i],*pok_na_listu_pregleda[j])){
                    Pregled *tmp=pok_na_listu_pregleda[i];
                    pok_na_listu_pregleda[i]=pok_na_listu_pregleda[j];
                    pok_na_listu_pregleda[j]=tmp;
                    //break;
                }
            }
        }
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda) {
        //for(int i=0;i<broj_pregleda;i++) {
        //   if(pok_na_listu_pregleda[i]==nullptr) {
        try{
            pok_na_listu_pregleda[trenutni_br_pregleda]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
            trenutni_br_pregleda++;
        }
        catch(...) {
            delete pok_na_listu_pregleda[trenutni_br_pregleda];
            pok_na_listu_pregleda[trenutni_br_pregleda]=nullptr;
        }
        //  break;
        //}
        //}
        for(int i=0;i<trenutni_br_pregleda;i++) {
            int indeks=i;
            for(int j=i+1;j<trenutni_br_pregleda;j++) {
                if(Pregled::DolaziPrije(*pok_na_listu_pregleda[i],*pok_na_listu_pregleda[j])){ indeks=j;}
                Pregled *tmp=pok_na_listu_pregleda[i];
                pok_na_listu_pregleda[i]=pok_na_listu_pregleda[indeks];
                pok_na_listu_pregleda[indeks]=tmp;
                //break;

            }
        }
    }

    void RegistrirajPregled(Pregled *pregled) {
        for(int i=0;i<broj_pregleda;i++) {
            if(pok_na_listu_pregleda[i]->ime_pacijenta==pregled->ime_pacijenta) {
                (*pok_na_listu_pregleda[i]).PromijeniDatum(pregled->datum_pregleda);
                (*pok_na_listu_pregleda[i]).PromijeniVrijeme(pregled->vrijeme_pregleda);
                break;
            }
        }
    }

    int DajBrojPregleda() const {
        return trenutni_br_pregleda;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const {
        int brojac(0);
        for(int i=0;i<trenutni_br_pregleda;i++)
            if(pok_na_listu_pregleda[i]->datum_pregleda.dan==datum.dan
               && pok_na_listu_pregleda[i]->datum_pregleda.mjesec==datum.mjesec
               && pok_na_listu_pregleda[i]->datum_pregleda.godina==datum.godina)
                brojac++;
        return brojac;
    }
    Pregled &DajNajranijiPregled() { //
        auto min=std::min_element(pok_na_listu_pregleda,pok_na_listu_pregleda+trenutni_br_pregleda,[](Pregled *p1, Pregled *p2){
            //if(p1==p2) return true;
            return Pregled::DolaziPrije(*p1,*p2);
        });
        return **min;
    }
    Pregled DajNajranijiPregled() const {
        auto min(std::min_element(pok_na_listu_pregleda,pok_na_listu_pregleda+trenutni_br_pregleda,[](Pregled *p1, Pregled *p2){
            //if(p1==p2) return true;
            return Pregled::DolaziPrije(*p1,*p2);
        }));
        return **min;
    }
    void IsprazniKolekciju() {
        for(int i=0;i<broj_pregleda;i++) {
            delete pok_na_listu_pregleda [i];
        }
        trenutni_br_pregleda=0;

        delete [] pok_na_listu_pregleda;
    }
    void ObrisiNajranijiPregled() {
        Pregled p(DajNajranijiPregled());
        for(int i=0;i<trenutni_br_pregleda;i++) {
            if(pok_na_listu_pregleda[i]->datum_pregleda.dan==p.datum_pregleda.dan
               && pok_na_listu_pregleda[i]->datum_pregleda.mjesec==p.datum_pregleda.mjesec
               && pok_na_listu_pregleda[i]->datum_pregleda.godina==p.datum_pregleda.godina) {
                for(int j=i+1;j<trenutni_br_pregleda;j++) {
                    Pregled *pom=pok_na_listu_pregleda[i];
                    pok_na_listu_pregleda[i]=pok_na_listu_pregleda[j];
                    pok_na_listu_pregleda[j]=pom;
                }
                /*delete pok_na_listu_pregleda[j];
                pok_na_listu_pregleda[j]=nullptr;
                trenutni_br_pregleda--;
                i--;
                break;*/
            }
        }
        delete pok_na_listu_pregleda[trenutni_br_pregleda-1];
        pok_na_listu_pregleda[trenutni_br_pregleda-1]=nullptr;
        trenutni_br_pregleda--;
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        for(int i=0;i<trenutni_br_pregleda;i++) {
            if(pok_na_listu_pregleda[i]->ime_pacijenta==ime_pacijenta) {
                for(int j=i+1;j<trenutni_br_pregleda;j++) {
                    Pregled *pom=pok_na_listu_pregleda[i];
                    pok_na_listu_pregleda[i]=pok_na_listu_pregleda[j];
                    pok_na_listu_pregleda[j]=pom;
                }
                /*delete pok_na_listu_pregleda[j];
                pok_na_listu_pregleda[j]=nullptr;
                trenutni_br_pregleda--;
                i--;*/
            }
        }
        delete pok_na_listu_pregleda[trenutni_br_pregleda-1];
        pok_na_listu_pregleda[trenutni_br_pregleda-1]=nullptr;
        trenutni_br_pregleda--;
    }
    void IspisiPregledeNaDatum(const Datum &datum) const {
        for(int i=0;i<trenutni_br_pregleda;i++) {
            if(pok_na_listu_pregleda[i]->datum_pregleda.dan==datum.dan
               && pok_na_listu_pregleda[i]->datum_pregleda.mjesec==datum.mjesec
               && pok_na_listu_pregleda[i]->datum_pregleda.godina==datum.godina) {
                pok_na_listu_pregleda[i]->Ispisi();
            }
        }
    }
    void IspisiSvePreglede() const {
        //std::sort(pok_na_listu_pregleda,pok_na_listu_pregleda+trenutni_br_pregleda,[](Pregled *p1,Pregled *p2){return Pregled::DolaziPrije(*p1,*p2);});



        for(int i=0;i<trenutni_br_pregleda;i++) {
            pok_na_listu_pregleda[i]->Ispisi();
        }
    }
};


int main ()
{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int max_br_pregleda;
    std::cin>>max_br_pregleda;
    Pregledi p(max_br_pregleda);
    //std::cin.ignore(10000,'\n');
    try{
        //Pregledi p(max_br_pregleda);
        for(int i=0;i<max_br_pregleda;i++) {
            std::cout<<"Unesite ime novog pacijenta ili \'kraj\' za zavrsetak unosa: ";
            std::string ime_pacijenta;
            //std::cin.ignore(10000,'\n');
            std::cin>>ime_pacijenta;
            if(ime_pacijenta=="kraj") break;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            int dan,mjesec,godina;
            std::cin>>dan>>mjesec>>godina;
            std::cout<<"Unesite sate i minute pregleda: ";
            int sati,minute;
            std::cin>>sati>>minute;
            p.RegistrirajPregled(ime_pacijenta,dan,mjesec,godina,sati,minute);
        }
        //std::sort(p.pok_na_listu_pregleda,p.pok_na_listu_pregleda+p.trenutni_br_pregleda,[](Pregled **p1,Pregled **p2){return Pregled::DolaziPrije(**p1,**p2);});
        std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
        p.IspisiSvePreglede();
        while(1) {
            std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"
                     <<std::endl<<"1 - Broj pregleda na datum"
                     <<std::endl<<"2 - Najraniji pregled"
                     <<std::endl<<"3 - Obrisi pregled pacijenta"
                     <<std::endl<<"4 - Obrisi najraniji pregled"
                     <<std::endl<<"5 - Ispisi sve pregleda na datum"
                     <<std::endl<<"6 - Ispisi sve preglede"
                     <<std::endl<<"7 - Kraj programa";
            int unos;
            std::cin>>unos;
            if(unos==1) {
                std::cout<<std::endl<<"Unesite dan mjesec i godinu : ";
                int dan,mjesec,godina;
                std::cin>>dan>>mjesec>>godina;
                Datum dat(dan,mjesec,godina);

                int br=p.DajBrojPregledaNaDatum(dat);
                std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<br<<std::endl;
            }
            else if(unos==2) {
                Pregled nr(p.DajNajranijiPregled());
                std::cout<<std::endl<<"Najraniji pregled je:"<<std::endl;
                nr.Ispisi();
            }
            else if(unos==3) {
                //std::cin.ignore(10000,'\n');
                std::cout<<std::endl<<"Unesite ime pacijenta: ";
                std::string ime;
                std::cin>>ime;
                int t(p.DajBrojPregleda());
                p.ObrisiPregledePacijenta(ime);
                int t1(p.DajBrojPregleda());
                std::cout<<"Uspjesno obrisano "<<t-t1<<" pregleda"<<std::endl;
            }
            else if(unos==4) {
                int t(p.DajBrojPregleda());
                p.ObrisiNajranijiPregled();
                int t1(p.DajBrojPregleda());
                if(t!=t1) std::cout<<std::endl<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            }
            else if(unos==5) {
                std::cout<<std::endl<<"Unesite dan mjesec i godinu : ";
                int d,m,g;
                std::cin>>d>>m>>g;
                Datum dat(d,m,g);
                std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:"<<std::endl;
                p.IspisiPregledeNaDatum(dat);
            }
            else if(unos==6) { std::cout<<std::endl; p.IspisiSvePreglede(); }
            else if(unos==7) break;
            //p.IsprazniKolekciju();
        }
        p.IsprazniKolekciju();
    }
    catch(...) {
        //p.IsprazniKolekciju();
        throw;
    }
    return 0;
}
