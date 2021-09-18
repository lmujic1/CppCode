//
// Created by 38760 on 18. 9. 2021..
//

//TP 2016/2017: Tutorijal 1, Zadatak 3
/*
Napišite program koji traži da se sa tastature unesu dva prirodna broja i , ne veća od 9999 i pri
čemu je < , a koji zatim za sve prirodne brojeve u opsegu od do uključivo ispisuje tablicu
njihovih kvadrata, kvadratnih korijena i prirodnih logaritama. Tačan izgled tablice vidljiv je iz
dijaloga koji će biti prikazan. Uglavnom, kolona za prikaz brojeva široka je 9 polja. Brojevi se
ispisuju poravnati ulijevo, pri čemu je prvo polje uvijek razmak. Kolone za prikaz kvadrata i
korijena široke su 10 polja, dok je kolona za prikaz logaritama široka 11 polja. Kvadrati, korijeni i
logaritmi se ispisuju poravnati udesno, pri čemu je posljednje polje uvijek razmak. Pored toga,
korijeni se ispisuju fiksno na tri decimale, a logaritmi fiksno na pet decimala. Slijedi primjer kako
treba izgledati dijalog između korisnika i programa:
Za ispis koristite objekat “cout” iz biblioteke “iostream” i odgovarajuće manipulatore iz iste
biblioteke, kao i biblioteke “iomanip”. U programu ne trebate testirati da li su i zaista prirodni
brojevi ne veći od 9999, i da li je < . Međutim, ispitajte kako će se program ponašati ukoliko se
unesu brojevi koji ne zadovoljavaju ova ograničenja.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
int main ()
{
    std::cout<<"Unesite pocetnu i krajnju vrijednost: "<<std::endl;
    int begin,end;
    std::cin>>begin>>end;
    std::cout<<"+"<<std::setw(10)<<std::setfill('-')<<"+"<<std::setw(11)<<std::setfill('-')<<"+"<<std::setw(11)
             <<std::setfill('-')<<"+"<<std::setw(12)<<std::setfill('-')<<"+"<<std::endl<<"| Brojevi | Kvadrati | Korijeni | Logaritmi |"
             <<std::endl<<"+"<<std::setw(10)<<std::setfill('-')<<"+"<<std::setw(11)<<std::setfill('-')<<"+"<<std::setw(11)
             <<std::setfill('-')<<"+"<<std::setw(12)<<std::setfill('-')<<"+"<<std::endl;
    for(int i=begin;i<=end;i++) {
        std::cout<<"| "<<std::left<<std::setw(7)<<std::setfill(' ')<<i<<" | "<<
                 std::right<<std::setw(8)<<i*i<<" | "<<
                 std::right<<std::setw(8)<<std::setprecision(3)<<std::fixed<<std::sqrt(i)<<" | "<<
                 std::right<<std::setw(9)<<std::setprecision(5)<<std::fixed<<std::log(i)<<" |"<<std::endl;
    }
    std::cout<<"+"<<std::setw(10)<<std::setfill('-')<<"+"<<std::setw(11)<<std::setfill('-')<<"+"<<std::setw(11)
             <<std::setfill('-')<<"+"<<std::setw(12)<<std::setfill('-')<<"+"<<std::endl;
    return 0;
}