//TP 2018/2019: Tutorijal 8, Zadatak 1
#include <iostream>
#include <iomanip>

struct Vrijeme {
    int sati,minute,sekunde;
};


void TestirajVrijeme(const Vrijeme &t) {
    if(t.sati<0 || t.sati>23 || t.minute<0 || t.minute>59 || t.sekunde<0 || t.sekunde>59) throw std::domain_error("Neispravno vrijeme");
}

void UnesiVrijeme(Vrijeme &t) {
    std::cin>>t.sati>>t.minute>>t.sekunde;
    TestirajVrijeme(t);
}

void IspisiVrijeme(const Vrijeme &t) {
    TestirajVrijeme(t);
    std::cout<<std::setw(2)<<std::setfill('0')<<t.sati<<":"<<std::setw(2)<<std::setfill('0')<<t.minute<<":"<<std::setw(2)<<std::setfill('0')<<t.sekunde;
}

Vrijeme SaberiVrijeme(const Vrijeme &t1,const Vrijeme &t2) {
    TestirajVrijeme(t1);
    TestirajVrijeme(t2);
    int us(t1.sekunde+t2.sekunde);
    int um((us-(us%60))/60+t1.minute+t2.minute);
    int uh((um-(um%60))/60+t1.sati+t2.sati);
    Vrijeme t3;
    t3.sekunde=us%60;
    t3.minute=um%60;
    t3.sati=uh%24;
    return t3;
}
int main ()
{
    try {
        std::cout<<"Unesite prvo vrijeme (h m s): ";
        Vrijeme t1;
        UnesiVrijeme(t1);
        std::cout<<("Unesite drugo vrijeme (h m s): ");
        Vrijeme t2;
        UnesiVrijeme(t2);

        std::cout<<"Prvo vrijeme: ";
        IspisiVrijeme(t1);
        std::cout<<std::endl<<"Drugo vrijeme: ";
        IspisiVrijeme(t2);

        Vrijeme v3(SaberiVrijeme(t1,t2));
        std::cout<<std::endl<<"Zbir vremena: ";
        IspisiVrijeme(v3);
    }
    catch (std::domain_error greska) {
        std::cout << greska.what() << std::endl;
    }


    return 0;
}
