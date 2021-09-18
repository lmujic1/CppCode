//TP 2016/2017: Tutorijal 1, Zadatak 1
/*
Neka je dat bazen oblika kvadra dimenzije × × i keramičke pločice oblika kvadrata dimenzija
 × . Napišite program koji prvo zahtijeva od korisnika da unese dužinu, širinu i dubinu bazena (tj.
 , i ) u metrima, kao i širinu keramičke pločice u centimetrima. Program zatim treba da ispita
da li je bazen moguće popločati takvim pločicama, a da se pri tome niti jedna pločica ne treba lomiti
(debljinu pločice zanemariti). Ukoliko to nije moguće, treba ispisati odgovarajući komentar.
Ukoliko jeste, treba ispisati koliko je pločica potrebno za popločavanje (naravno, popločavaju se
zidovi i dno bazena). Slijede primjeri dva dijaloga između programa i korisnika. Radi autotestiranja,
dijalozi bi trebali izgledati tačno kako je prikazano, uključujući i mjesta gdje se prelazi u novi red i
prazne redove, samo se brojevi koje unosi korisnik mogu razlikovati (iza posljednje rečenice
također je potreban prelazak u novi red). Afrikati poput “č”, “ć” itd. se ne koriste u ispisu zbog
činjenice da nije sasvim jednostavno podesiti da se oni ispravno prikazuju (to će vrijediti i ubuduće).
Za unos podataka i ispis rezultata koristite objekte “cin” i “cout” iz biblioteke “iostream”. Koristite
isključivo cjelobrojni tip podataka (tačnije tip “int”). Pretpostavite da su ulazni podaci smisleni (tj.
ne morate testirati da li je korisnik unio smislene podatke).

*/

#include <iostream>
#include <cmath>
int main ()
{
    std::cout<<"Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    int a,b,c,d;
    std::cin>>a>>b>>c;
    std::cout<<"Unesite sirinu plocice u centimetrima: "<<std::endl;
    std::cin>>d;
    int povrsina_bazena=(a*b+2*a*c+2*b*c)*10000;
    int povrsina_plocice=d*d;
    if(povrsina_bazena%povrsina_plocice==0 && a*100%d==0 && b*100%d==0 && c*100%d==0)
        std::cout<<"Za poplocavanje bazena dimenzija "<<a<<"x"<<b<<"x"<<c<<"m sa plocicama dimenzija "<<d<<"x"<<d<<"cm "<<std::endl<<"potrebno je "<<povrsina_bazena/povrsina_plocice<<" plocica.";
    else
        std::cout<<"Poplocavanje bazena dimenzija "<<a<<"x"<<b<<"x"<<c<<"m sa plocicama dimenzija "<<d<<"x"<<d<<"cm "<<std::endl<<"nije izvodljivo bez lomljenja plocica!";
    return 0;
}
