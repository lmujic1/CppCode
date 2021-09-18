//TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>
template <typename Tip>
struct Cvor{
    Tip element;
    Cvor *veza;
};

template <typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni) {
    Cvor<TipElemenata> *pocetak(nullptr),*prethodni(nullptr);
    for(;;) {
        TipElemenata x;
        std::cin>>x;
        if(x==zavrsni) break;
        Cvor<TipElemenata> *novi(new Cvor<TipElemenata>{x,nullptr});
        if(!pocetak) pocetak=novi;
        else prethodni->veza=novi;
        prethodni=novi;
    }
    return pocetak;
}
template <typename TipElemenata>
int BrojElemenata(Cvor<TipElemenata> *pocetak) {
    //if(!pocetak) return 0;
    int broj(0);
    for(Cvor<TipElemenata> *p=pocetak;p!=nullptr;p=p->veza) broj++;
    return broj;
}

template <typename TipElemenata>
TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak){
    TipElemenata suma{};
    for(Cvor<TipElemenata> *p=pocetak;p!=nullptr;p=p->veza) suma=suma+p->element;
    return suma;
}

template <typename TipElemenata>
int BrojVecihOd(Cvor<TipElemenata> *pocetak, TipElemenata prag) {
    int brojac(0);
    for(Cvor<TipElemenata> *p=pocetak;p!=nullptr;p=p->veza) {
        if(p->element>prag) brojac++;
    }
    return brojac;
}
template <typename TipElemenata>
void UnistiListu(Cvor<TipElemenata> *pocetak) {
    while(pocetak!=nullptr) {
        auto pom(pocetak);
        pocetak=pocetak->veza;
        delete pom;
    }
}

int main ()
{
    std::cout<<"Unesite slijed brojeva (0 za kraj): ";
    auto lista(KreirajPovezanuListu<double>(0));
    double suma(SumaElemenata(lista));
    int broj_elemenata(BrojElemenata<double>(lista));

    double sredina(suma/broj_elemenata);
    int BrojVeciOdSredine(BrojVecihOd<double>(lista, sredina));
    std::cout<<"U slijedu ima "<<BrojVeciOdSredine<<" brojeva vecih od njihove aritmeticke sredine";
    UnistiListu<double>(lista);
    return 0;
}