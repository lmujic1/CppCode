//TP 2017/2018: Tutorijal 1, Zadatak 2
/*
Napišite program koji traži da se sa tastature unesu tri realna broja , i , i koji ispisuje da li ta tri
broja mogu biti stranice nekog trougla. Podsjetimo se da za stranice trougla mora vrijediti uvjet da
su sve pozitivne i da je zbir dužina ma koje dvije stranice veći od dužine treće stranice. Ukoliko
uneseni brojevi mogu predstavljati dužine stranica trougla, treba izračunati njegov obim, površinu i
najmanji ugao, a zatim ispisati izračunate vrijednosti obima, površine i najmanjeg ugla, pri čemu
ugao trea ispisati u stepenima, minutama i sekundama. Za računanje površine trougla koristite
poznatu Heronovu formulu prema kojoj je P = ( )( )( ) gdje je = ( + + )/2, a
za računanje ugla koristite kosinusnu teoremu prema kojoj je
 =
 +
 2 cos γ (i analogno
tome za preostale kombinacije stranica i uglova). Računajte da 1 radijan ima 180/π stepeni, dok
vrijednost π možete računati po formuli π = 4 ∙ arctg1 (predmetni nastavnik ne želi da vidi da neko
misli da je π = 3.14, to mu pokvari dan). Ukoliko uneseni brojevi ne mogu predstavljati dužine
stranica trougla, treba ispisati odgovarajući komentar. Dijalozi koje formira program trebaju
izgledati poput sljedećih (zanemarite eventualne probleme sa padežima i ostalom gramatikom):
Za unos podataka i ispis rezultata koristite objekte “cin” i “cout” iz biblioteke “iostream”, a za
odgovarajuća računanja funkcije iz biblioteke “cmath”. Pretpostavite da će korisnik zaista unositi
brojeve (ne nužno cijele), a ne neko “smeće”.
*/

#include <iostream>
#include <cmath>
int main ()
{
    std::cout<<"Unesite tri broja: ";
    double a,b,c;
    std::cin>>a>>b>>c;
    if((a+b)>c && (a+c)>b && (b+c)>a) {
        const double pi=4*(std::atan(1));
        double O=a+b+c;
        double S=O/2;
        double P=std::sqrt(S*(S-a)*(S-b)*(S-c));
        std::cout<<"Obim trougla sa duzinama stranica "<<a<<", "<<b<<" i "<<c<<" iznosi "<<O<<"."<<std::endl<<"Njegova povrsina iznosi "<<P<<"."<<std::endl;
        float gama=(std::acos((a*a+b*b-c*c)/(2*a*b)))*(180/pi);
        float alfa=(std::acos((b*b+c*c-a*a)/(2*b*c)))*(180/pi);
        float beta=(std::acos((a*a+c*c-b*b)/(2*a*c)))*(180/pi);
        if (alfa<=beta && alfa<=gama) {
            float amin=(alfa-static_cast<int>(alfa))*60;
            float asec=(amin-static_cast<int>(amin))*60;
            std::cout<<"Njegov najmanji ugao ima " <<int(alfa)<<" stepeni, "<<(int)amin<<" minuta i "<<(int)asec<<" sekundi."<<std::endl;
        } else if(beta<=alfa && beta<=gama) {
            float bmin=(beta-static_cast<int>(beta))*60;
            float bsec=(bmin-static_cast<int>(bmin))*60;
            std::cout<<"Njegov najmanji ugao ima " <<(int)beta<<" stepeni, "<<(int)bmin<<" minuta i "<<(int)bsec<<" sekundi."<<std::endl;
        } else {
            float gmin=(gama-static_cast<int>(gama))*60;
            float gsec=(gmin-static_cast<int>(gmin))*60;
            std::cout<<"Njegov najmanji ugao ima " <<(int)gama<<" stepeni, "<<(int)gmin<<" minuta i "<<(int)gsec<<" sekundi."<<std::endl;
        }
    }
    else
        std::cout<<"Ne postoji trougao cije su duzine stranica "<<a<<", "<<b<<" i "<<c<<"!";

    return 0;
}
