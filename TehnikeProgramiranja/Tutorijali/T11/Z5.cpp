//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 16/17 (Tutorijal 11, Zadatak 5)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
/*
    TP 16/17 (Tutorijal 11, Zadatak 4)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <memory>
#include <vector>
class Tim {
    char ime_tima[20];
    int broj_odigranih;
    int broj_pobjeda;
    int broj_nerijesenih;
    int broj_poraza;
    int broj_datih;
    int broj_primljenih;
    int broj_poena;
public:
    Tim(const char ime[]) {
        if(std::strlen(ime)>=20) throw std::range_error("Predugacko ime tima");
        std::strcpy(ime_tima,ime);
        broj_odigranih=0;
        broj_pobjeda=0;
        broj_nerijesenih=0;
        broj_poraza=0;
        broj_datih=0;
        broj_poena=0;
        broj_primljenih=0;
    }
    void ObradiUtakmicu(int broj_datih, int broj_primljenih) {
        if(broj_datih<0 || broj_primljenih<0) throw std::range_error("Neispravan broj golova");
        Tim::broj_datih+=broj_datih;
        Tim::broj_primljenih+=broj_primljenih;
        broj_odigranih++;
        if(broj_datih>broj_primljenih) { broj_pobjeda++; broj_poena+=3; }
        else if(broj_datih==broj_primljenih) { broj_nerijesenih++; broj_poena++; }
        else broj_poraza++;
    }
    const char *DajImeTima() const {
        return ime_tima;
    }
    int DajBrojPoena() const {
        return broj_poena;
    }
    int DajGolRazliku() const {
        return broj_datih-broj_primljenih;
    }
    void IspisiPodatke() const {
        std::cout<<std::left<<std::setw(23)<<ime_tima<<std::right<<broj_odigranih<<std::setw(4)<<
                 broj_pobjeda<<std::setw(4)<<broj_nerijesenih<<std::setw(4)<<
                 broj_poraza<<std::setw(4)<<broj_datih<<std::setw(4)<<broj_primljenih<<std::setw(4)<<broj_poena<<std::endl;
    }
    friend class Liga;
};

class Liga {
    std::vector<std::shared_ptr<Tim>> timovi;
    int PronadjiTim(const char *ime_tima) const {
        for(int i=0; i<broj_timova; i++) if(std::strcmp(ime_tima, timovi[i]->DajImeTima())==0) return i;
        return -1;
    }
public:
    explicit Liga(int velicina_lige) : broj_timova(0), max_br_timova(velicina_lige), timovi(new Tim*[velicina_lige]) {}
    explicit Liga(std::initializer_list<Tim> lista_timova) : broj_timova(lista_timova.size()), max_br_timova(lista_timova.size()), timovi (new Tim*[lista_timova.size()]){
        int br(0);
        try{
            for(auto tim : lista_timova) timovi[br++]=new Tim(tim);
        }
        catch(...) {
            for(int i=0;i<br;i++) delete timovi[i];
            throw;
        }
    }
    ~Liga() {
        for(int i=0;i<broj_timova;i++) delete timovi[i];
        delete [] timovi;
    }
    Liga(const Liga &l) : max_br_timova(l.max_br_timova), broj_timova(l.broj_timova), timovi(new Tim*[l.broj_timova]{}) {
        if(l.max_br_timova!=max_br_timova) throw std::logic_error("Nesaglasni kapaciteti liga");
        try{
            for(int i=0;i<broj_timova;i++)
                timovi[i]=new Tim(*l.timovi[i]);
        }
        catch(...) {
            OslobodiTimove();
            throw;
        }
    }
    Liga(Liga &&l) : max_br_timova(l.max_br_timova), broj_timova(l.broj_timova) {
        if(&l!=this) {
            for(int i=0;i<max_br_timova;i++) delete timovi[i];
            delete [] timovi;
            timovi=l.timovi;
            l.timovi=nullptr;
        }
    }
    Liga &operator =(const Liga &l) {
        if(l.max_br_timova!=max_br_timova) throw std::logic_error("Nesaglasni kapaciteti liga");
        if(&l==this) return *this;
        for(int i=0;i<broj_timova;i++) delete timovi[i];
        broj_timova=l.broj_timova;
        try{
            for(int i=0;i<broj_timova;i++) timovi[i]=new Tim(*l.timovi[i]);
        }
        catch(...) {
            OslobodiTimove();
            throw;
        }
        return *this;
    }
    Liga &operator =(Liga &&l) {
        if(l.max_br_timova!=broj_timova) throw std::logic_error("Nesaglasni kapaciteti liga");
        if(&l==this) return *this;
        timovi=l.timovi;
        broj_timova=l.broj_timova;
        l.timovi=nullptr;
        return *this;
    }
    void DodajNoviTim(const char ime_tima[]) {
        if(broj_timova==max_br_timova) throw std::range_error("Liga popunjena");
        if(PronadjiTim(ime_tima)!=-1) throw std::logic_error("Tim vec postoji");
        if(std::strlen(ime_tima)>20) throw std::range_error("Predugacko ime tima");
        try {
            timovi[broj_timova++]=new Tim(ime_tima);
        }
        catch(std::bad_alloc) {
            broj_timova--;
            throw std::domain_error("Neuspjesno dodavanje u ligu");
        }
    }
    void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2) {
        if(rezultat_1<0 || rezultat_2<0) throw std::range_error("Neispravan broj golova");
        if(PronadjiTim(tim1)==-1 || PronadjiTim(tim2)==-1) throw std::domain_error("Tim nije nadjen");
        timovi[PronadjiTim(tim1)]->ObradiUtakmicu(rezultat_1,rezultat_2);
        timovi[PronadjiTim(tim2)]->ObradiUtakmicu(rezultat_2,rezultat_1);
    }
    void IspisiTabelu() {
        std::sort(timovi, timovi+broj_timova, [](Tim *tim1, Tim*tim2) {
            if(tim1->DajBrojPoena()!=tim2->DajBrojPoena()) return tim1->DajBrojPoena()>tim2->DajBrojPoena();
            else if(tim1->DajGolRazliku()!=tim2->DajGolRazliku()) return tim1->DajGolRazliku()>tim2->DajGolRazliku();
            else {
                return std::strcmp(tim1->DajImeTima(),tim2->DajImeTima())<0;
            }
        });
        for(int i=0; i<broj_timova; i++) timovi[i]->IspisiPodatke();
    }
};

int main() {
    return 0;
}