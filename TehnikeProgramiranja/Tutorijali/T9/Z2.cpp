//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 16/17 (Tutorijal 9, Zadatak 1)

	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>

class Vektor3d {
    double koordinate[3];
public:

    void Postavi(double x, double y, double z) {
        koordinate[0] = x;
        koordinate[1] = y;
        koordinate[2] = z;
    }

    Vektor3d &PostaviX(double x) { koordinate[0]=x; return *this;}
    Vektor3d &PostaviY(double y) { koordinate[1]=y; return *this;}
    Vektor3d &PostaviZ(double z) { koordinate[2]=z; return *this;}

    void Ocitaj(double &x, double &y, double &z) const {
        x = koordinate[0];
        y = koordinate[1];
        z = koordinate[2];
    }

    void Ispisi() const {
        std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
    }

    double DajX() const { return koordinate[0]; }
    double DajY() const { return koordinate[1]; }
    double DajZ() const { return koordinate[2]; }
    double DajDuzinu() const { return sqrt(koordinate[0] * koordinate[0] + koordinate[1] * koordinate[1] + koordinate[2] * koordinate[2]); }
    Vektor3d &PomnoziSaSkalarom(double s) {
        koordinate[0] *= s;
        koordinate[1] *= s;
        koordinate[2] *= s;
        return *this;
    }
    Vektor3d &SaberiSa(const Vektor3d &v) {
        koordinate[0] += v.koordinate[0];
        koordinate[1] += v.koordinate[1];
        koordinate[2] += v.koordinate[2];
        return *this;
    }
    friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
    Vektor3d rez;
    rez.koordinate[0]=v1.koordinate[0]+v2.koordinate[0];
    rez.koordinate[1]=v1.koordinate[1]+v2.koordinate[1];
    rez.koordinate[2]=v1.koordinate[2]+v2.koordinate[2];
    return rez;
}

int main ()
{

    return 0;
}