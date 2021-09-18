//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: Tutorijal 2, Zadatak 3
/*
Kompleksni brojevi svoju najveću primjenu nalaze upravo u elektrotehnici (i u kvantnoj fizici).
Recimo, u teoriji električnih kola uvodi se pojam impedanse, koja je kompleksan broj Z definiran
kao Z = R+ Xi, gdje je R tzv. aktivni otpor, a X tzv. reaktivni otpor (ili reaktansa), koji može biti i
negativan. Ukoliko imamo paralelni spoj elemenata čije su impedanse Z
 , Z
 , …, Z
 , ukupna
impedansa paralelne veze Z računa se kao Z = 1/(1/Z
 +1/Z
 +…+1/Z
 ). Drugim riječima, situacija
je slična paralelnom spajanju otpornika, osim što se ovdje radi sa kompleksnim impedansama.
Napišite program u kojem se korisnika traži da se unese broj elemenata , a zatim impedansi Z

za sve od 1 do . Impedanse se unose kao kompleksni brojevi, tačnije kao parovi realnih i
imaginarnih dijelova unutar zagrada, razdvojeni zarezom. Nakon toga, treba da izračuna i ispiše
impedansu paralelne veze svih elemenata, ponovo kao kompleksan broj. Dijalog između programa
i korisnika treba da izgleda poput sljedećeg:
Za realizaciju programa koristite kompleksni tip podataka. Nemojte koristiti niti nizove niti vektore,
nego sumu 1/Z
 + 1/Z
 + ...+1/Z
 računajte “u hodu”, uporedo sa unosom podataka. Također,
možete pretpostaviti da će svi uneseni podaci biti smisleni.


Unesite broj elemenata: 3
Z_1 = (3.5,2.8)
Z_2 = (10,-1.54)
Z_3 = (12.37,0.24)
Paralelna veza ovih elemenata ima impedansu Z_ = (2.51479,0.897637).

*/
#include <iostream>
#include <complex>
int main ()
{
    std::cout<<"Unesite broj elemenata: "<<std::endl;
    int n;
    std::cin>>n;

    std::complex<double> z,suma(0,0);
    for(int i=0;i<n;i++) {
        std::cout<<"Z_"<<i+1<<" = ";
        std::cin>>z;
        suma+=1./z;
    }
    std::cout<<std::endl<<"Paralelna veza ovih elemenata ima impedansu Z_ = "<<1./suma<<".";
    return 0;
}
