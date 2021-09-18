//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 1, Zadatak 2

/*Napišite program koji traži da se sa tastature unese brzina broda u čvorovima koja se zadaje
isključivo kao cijeli broj (obavezno koristiti promjenljivu tipa “int”), a zatim izračunava i ispisuje
brzinu broda u km/h kao decimalan broj. Koristite činjenicu da je čvor morska milja na sat, a da je
jedna morska milja 1852 m (ovaj podatak obavezno definirati u programu kao konstantu). Na
primjer, ukoliko se kao brzina broda unese broj 20, program treba da ispiše rezultat 37.04 jer je
20 čvorova = 37.04 km/h.*/

#include <iostream>

int main ()
{
    int v1;
    std::cout<<"Unesite brzinu broda u cvorovima: ";
    std::cin>>v1;
    double v=(v1*1852)/1000.;
    std::cout<<v1<<" cvorova = "<<v<<" km/h.";

    return 0;
}
