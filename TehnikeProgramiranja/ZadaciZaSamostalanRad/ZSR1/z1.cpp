//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 1, Zadatak 1

/*Napišite program koji traži da sa tastature unesemo podatke o dva vremenska trenutka, u satima,
minutama i sekundama, a koji računa i ispisuje vrijeme koje je proteklo između ta dva vremenska
trenutka, također u satima, minutama i sekundama. Pretpostaviti da je drugi vremenski trenutak
uvijek nakon prvog. Na primjer, dijalog nakon pokretanja programa može da izgleda poput sljedećeg:

Unesi prvo vrijeme (h min s): 14 15 7
Unesi drugo vrijeme (h min s): 16 9 34

Između ova dva trenutka proteklo je 1h 54min 27s.

Uputa: Jedan način rješavanja mogao bi biti sljedeći: pretvorite oba unesena vremena u broj
sekundi. Na primer, imamo 14h 15min 7s = 51307s i 16h 9min 34s = 58174s. Oduzmite broj
sekundi da dobijete broj sekundi između ovih trenutaka (6867s u zadanom primjeru). Konačno,
razložite dobijeni broj sekundi ponovo na sate, minute i sekunde (6867s = 1h 54min 27s)*/
#include <iostream>
#include<cmath>
int main ()
{
    int h1,m1,s1;
    std::cout<<"Unesi prvo vrijeme (h min s): ";
    std::cin>>h1>>m1>>s1;
    int h2,m2,s2;
    std::cout<<"Unesi drugo vrijeme (h min s): ";
    std::cin>>h2>>m2>>s2;
    std::cout<<"\n";
    int s1u=s1+m1*60+h1*3600;
    int s2u=s2+m2*60+h2*3600;
    int proteklo=abs(s1u-s2u);
    int min=proteklo/60;
    proteklo=proteklo%60;
    int h=min/60;
    min=min%60;
    std::cout<<"Izmedju ova dva trenutka proteklo je: "<<h <<"h "<<min<<"min "<<proteklo<<"s.";
    return 0;
}

