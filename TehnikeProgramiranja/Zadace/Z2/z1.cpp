//
// Created by 38760 on 18. 9. 2021..
//

// TP, 2018/2019
#include <iostream>
#include <limits>
bool status(true);
enum class Smjer {Nalijevo, Nadesno};
enum class Pravci {Sjever, Istok, Jug, Zapad};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {Aktiviraj, Deaktiviraj, Nalijevo, Nadesno, Idi, Kraj};

void AktivirajRobota(){
    status=true;
}
void DeaktivirajRobota(){
    status=false;
}
void Rotiraj(Pravci &orijentacija, Smjer na_koju_stranu) {
    if(status) {
        if(na_koju_stranu==Smjer::Nadesno) {
            if(orijentacija==Pravci::Sjever) orijentacija=Pravci::Istok;
            else if(orijentacija==Pravci::Istok) orijentacija=Pravci::Jug;
            else if(orijentacija==Pravci::Jug) orijentacija=Pravci::Zapad;
            else if(orijentacija==Pravci::Zapad) orijentacija=Pravci::Sjever;
        }
        else if(na_koju_stranu==Smjer::Nalijevo) {
            if(orijentacija==Pravci::Sjever) orijentacija=Pravci::Zapad;
            else if(orijentacija==Pravci::Zapad) orijentacija=Pravci::Jug;
            else if(orijentacija==Pravci::Jug) orijentacija=Pravci::Istok;
            else if(orijentacija==Pravci::Istok) orijentacija=Pravci::Sjever;
        }
    }
}
bool Provjeri_min(long long int n,long long int korak) {
    if((n-korak)<=std::numeric_limits<int>::min()) return true;
    return false;
}
bool Provjeri_max(long long int n,long long int korak) {
    if((n+korak)>=std::numeric_limits<int>::max()) return true;
    return false;
}
void Idi(int &x, int &y, Pravci orijentacija, int korak) {
    if(status) {
        if(korak<0) {
            if(orijentacija==Pravci::Sjever) {if(Provjeri_min(y,abs(korak)))y=std::numeric_limits<int>::min(); else y-=abs(korak);}
            else if(orijentacija==Pravci::Jug) {if(Provjeri_max(y,abs(korak)))y=std::numeric_limits<int>::max(); else y+=abs(korak);}
            else if(orijentacija==Pravci::Istok) {if(Provjeri_min(x,abs(korak)))x=std::numeric_limits<int>::min(); else x-=abs(korak);}
            else if(orijentacija==Pravci::Zapad) {if(Provjeri_max(x,abs(korak)))x=std::numeric_limits<int>::max(); else x+=abs(korak);}
            /*
             if(orijentacija==Pravci::Sjever) {if(Provjeri_min(y,abs(korak)))y=std::numeric_limits<int>::min(); else y+=korak;}
             else if(orijentacija==Pravci::Jug) {if(Provjeri_max(y,abs(korak)))y=std::numeric_limits<int>::max(); else y-=korak;}
             else if(orijentacija==Pravci::Istok) {if(Provjeri_min(x,abs(korak)))x=std::numeric_limits<int>::min(); else x+=korak;}
             else if(orijentacija==Pravci::Zapad) {if(Provjeri_max(x,abs(korak)))x=std::numeric_limits<int>::max(); else x-=korak;}*/
        }
        else {
            if(orijentacija==Pravci::Sjever) {if(Provjeri_max(y,korak)) {y=std::numeric_limits<int>::max(); std::cout<<y;} else y+=korak;}
            else if(orijentacija==Pravci::Jug) {if(Provjeri_min(y,korak)) y=std::numeric_limits<int>::min(); else y-=korak;}
            else if(orijentacija==Pravci::Istok) {if(Provjeri_max(x,korak))x=std::numeric_limits<int>::max(); else x+=korak;}
            else if(orijentacija==Pravci::Zapad) {if(Provjeri_min(x,korak))x=std::numeric_limits<int>::min(); else x-=korak;}
        }
    }
}
void IspisiPoziciju(int x, int y, Pravci orijentacija) {
    std::cout<<"Robot je trenutno ";
    if(status==true) std::cout<<"aktivan, ";
    else std::cout<<"neaktivan, ";
    std::cout<<"nalazi se na poziciji ("<<x<<","<<y<<") i gleda na ";
    if(orijentacija==Pravci::Sjever) std::cout<<"sjever.";
    else if(orijentacija==Pravci::Istok) std::cout<<"istok.";
    else if(orijentacija==Pravci::Jug) std::cout<<"jug.";
    else std::cout<<"zapad.";
    std::cout<<std::endl;
}
void PrijaviGresku(KodoviGresaka kod_greske) {
    if(kod_greske==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
    else if(kod_greske==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
    else if(kod_greske==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
    else if(kod_greske==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
}
void IzvrsiKomandu(Komande komanda, int parametar, int &x, int &y, Pravci &orijentacija) {
    if(komanda==Komande::Kraj) return;
    else if(komanda==Komande::Aktiviraj) AktivirajRobota();
    else if(komanda==Komande::Deaktiviraj) DeaktivirajRobota();
    else if(komanda==Komande::Nalijevo) Rotiraj(orijentacija,Smjer::Nalijevo);
    else if(komanda==Komande::Nadesno) Rotiraj(orijentacija,Smjer::Nadesno);
    else if(komanda==Komande::Idi) Idi(x,y,orijentacija,parametar);
}
bool UnosKomande (Komande &komanda,int &parametar, KodoviGresaka &kod_greske) {
    std::cout<<"Unesi komandu: ";
    char kom('P'),znak('x'),pom('P'),jeste;
    bool smece(false),minus(false);
    long long int broj;
    int prvi(1),prvibr(1),br(1),prije_komande(0),razmak_iza_br(0);
    char pomocni(std::cin.get());
    while(pomocni!='\n') {
        if(pomocni==' ' && prvibr!=1) razmak_iza_br=1;
        else if(pomocni==' ') jeste=pomocni;
        else if((pomocni=='A' || pomocni=='L' || pomocni=='I'|| pomocni=='D' || pomocni=='K')&&prvi==1) {kom=pomocni; prvi++; }
        else if((pomocni>='0' && pomocni<='9')&&kom=='I'&&prvibr==1) {broj=0; broj=broj*10+pomocni-'0';prvibr++;}
        else if((pomocni>='0' && pomocni<='9')&&kom=='I'&&prvibr!=1&&razmak_iza_br==0) {broj=broj*10+pomocni-'0';}
        else if((pomocni=='+' || pomocni=='-')&&kom=='A'&&znak=='x') znak=pomocni;
        else if((pomocni=='+' || pomocni=='-')&&kom=='A'&&znak!='x') {br++;}
        else if(pomocni=='-' && kom=='I' && pom=='P' && prvibr==1) minus=true;
        else if(prvi!=1)pom=pomocni;
        else if(pomocni=='\n') break;
        else if(prvi==1) {pom=pomocni; prije_komande++;}
        else smece=true;
        pomocni=std::cin.get();
    }

    if(prvibr==1 && kom=='I')  {kod_greske=KodoviGresaka::NedostajeParametar; return false;}
    else if(kom=='A' && br!=1) {kod_greske=KodoviGresaka::NeispravanParametar; return false;}
    else if(kom=='P') {kod_greske=KodoviGresaka::PogresnaKomanda; return false;}
    else if(pom!='P' && prije_komande) {kod_greske=KodoviGresaka::PogresnaKomanda; return false;}
    else if(pom!='P' && (kom=='L' || kom=='D' ||kom=='K')) {kod_greske=KodoviGresaka::SuvisanParametar; return false;}
    else if(pom!='P' && kom=='A') {kod_greske=KodoviGresaka::PogresnaKomanda; return false;}
    else if(pom!='P') {kod_greske=KodoviGresaka::NeispravanParametar; return false;}
    else if(kom=='A' && znak=='x') {kod_greske=KodoviGresaka::NedostajeParametar; return false;}
        // else if(kom!='I' && (broj>=0 && broj<=9)) {kod_greske=KodoviGresaka::PogresnaKomanda; return false;}
    else if(smece) {kod_greske=KodoviGresaka::SuvisanParametar; return false;}

    if(kom=='A' && znak=='+') komanda=Komande::Aktiviraj;
    else if(kom=='A' && znak=='-') komanda=Komande::Deaktiviraj;
    else if(kom=='L') komanda=Komande::Nalijevo;
    else if(kom=='D') komanda=Komande::Nadesno;
    else if(kom=='I') {
        komanda=Komande::Idi;
        if(minus) broj*=-1;
        if(Provjeri_max(broj,0)) broj=std::numeric_limits<int>::max();
        else if(Provjeri_min(broj,0)) broj=std::numeric_limits<int>::min();
        parametar=broj;
    }
    else if(kom=='K') komanda=Komande::Kraj;
    return true;

}

int main ()
{
    Pravci orien=Pravci::Sjever;

    int x(0),y(0);
    IspisiPoziciju(x,y,orien);
    while(true) {
        Komande kom;
        int par;
        KodoviGresaka kod;
        bool unos=UnosKomande(kom,par,kod);
        if(unos) {
            IzvrsiKomandu(kom,par,x,y,orien);
            if(kom==Komande::Kraj) {std::cout<<"Dovidjenja!"; break;}
            else IspisiPoziciju(x,y,orien);
        }
        else PrijaviGresku(kod);
    }
    return 0;
}


/*bool prije_komande(false),prvo_slovo(false),prvi_broj(false),poslije_komande(false);
    bool prvi_znak(false),poslije_komande_A(false),poslije_komande_I(false),minus(false),plus(false);
    long long int broj;
    char kom='p',znak,jeste;
    char pomocni(std::cin.get());
    if(pomocni=='\n') pomocni=std::cin.get();
    while(pomocni!='\n') {
        if((pomocni=='A' || pomocni=='I' || pomocni=='L' || pomocni=='D' || pomocni=='K')&& prije_komande==false) {kom=pomocni; prvo_slovo=true;}
        else if(prvo_slovo) poslije_komande=true;
        else if(pomocni==' ') jeste=pomocni;
        else if(prvo_slovo==false) prije_komande=true;
        else if(kom=='I') {
            if(pomocni==' ' && prvi_broj) jeste=pomocni;
            else if(pomocni==' '&&prvi_broj==false) poslije_komande_I=true;
            else if((pomocni>='0' && pomocni<='9')&&kom=='I'&&prvi_broj==false&&poslije_komande_I==false){broj=0; broj=broj*10+pomocni-'0'; prvi_broj=true;}
            else if((pomocni>='0' && pomocni<='9')&&prvi_broj&&poslije_komande_I==false) broj=broj*10+pomocni-'0';
            else if(pomocni=='-'&&kom=='I'&&poslije_komande_I==false&&prvi_broj==false) minus=true;
            else if(pomocni=='+'&&kom=='I'&&poslije_komande_I==false&&prvi_broj==false) plus=true;
            else if(poslije_komande_I==false && prvi_broj==false) poslije_komande=true;
        }
        else if(kom=='A') {
            if(pomocni==' ' && prvi_znak) jeste=pomocni;
            else if(pomocni==' '&&prvi_znak==false) poslije_komande_A=true;
            else if((pomocni=='-' || pomocni=='+')&&kom=='A'&&prvi_znak==false&&poslije_komande_A==false) {znak=pomocni; prvi_znak=true;}
            else poslije_komande=true;
        }
        else if(pomocni=='\n') break;
        pomocni=std::cin.get();
    }
    if(prije_komande) {kod_greske=KodoviGresaka::PogresnaKomanda; return false;}
    else if(kom=='I') {
        if(prvi_broj==false) {kod_greske=KodoviGresaka::NedostajeParametar; return false;}
        else if(poslije_komande && prvi_broj) {kod_greske=KodoviGresaka::NeispravanParametar; return false;}
        else if(poslije_komande_I) {kod_greske=KodoviGresaka::NeispravanParametar; return false;}

    }
    else if(kom=='A') {
        //if(prvi_znak==false) {kod_greske=KodoviGresaka::NedostajeParametar; return false;}
        if(poslije_komande_A) {kod_greske=KodoviGresaka::NeispravanParametar; return false;}
        else if(poslije_komande && prvi_znak==false) {kod_greske=KodoviGresaka::PogresnaKomanda; return false;}
        else if(poslije_komande) {kod_greske=KodoviGresaka::SuvisanParametar; return false;}
    }
    //else if(poslije_komande&&(kom=='L' || kom=='D')) {kod_greske=KodoviGresaka::SuvisanParametar; return false;}
    else if(poslije_komande && kom=='K') {kom='z'; kod_greske=KodoviGresaka::SuvisanParametar; return false;}
*/

