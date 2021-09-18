/*
    TP 16/17 (Tutorijal 12, Zadatak 3)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
std::ostream & operator<< (std::ostream &tok, Dani dan) {
    if(dan==0) tok<<"Ponedjeljak";
    if(dan==1) tok<<"Utorak";
    if(dan==2) tok<<"Srijeda";
    if(dan==3) tok<<"Cetvrtak";
    if(dan==4) tok<<"Petak";
    if(dan==5) tok<<"Subota";
    if(dan==6) tok<<"Nedjelja";
    return tok;
}
Dani &operator ++(Dani &dan) {
    return dan=Dani(((int)dan+1)%7);
}
Dani operator++(Dani &dan, int) {
    auto dan2(dan); ++dan;
    return dan2;
}
int main ()
{
    return 0;
}