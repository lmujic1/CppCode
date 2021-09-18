/*
U prethodnom programu dodajte novu strukturu Pravougaonik, a zatim dodajte funkcije obim_pravougaonika i povrsina_pravougaonika,
te funkciju tacka_u_pravougaoniku koja vraća logičku istinu (1) ako se tačka nalazi u pravougaoniku ili na rubu pravougaonika,
a u suprotnom logičku neistinu (0). Radi jednostavnosti pretpostavićemo da su stranice pravougaonika poravnate sa koordinatnim osama
(za vježbu možete probati uraditi zadatak bez ove pretpostavke).
Ovakav pravougaonik može biti opisan preko dvije tačke (koordinate donjeg lijevog i gornjeg desnog ugla).
*/

#include <stdio.h>

struct Tacka {
    float x,y;
};

struct Pravougaonik {
    struct Tacka dole_lijevo;
    struct Tacka gore_desno;
};

struct Tacka unos_tacke() {
    struct Tacka t;
    printf("\nUnesite koordinate tacke (x, y): ");
    scanf("%f,%f",&t.x,&t.y);
    return t;
}

struct Pravougaonik unos_pravougaonika() {
    struct Pravougaonik p;
    printf("\nUnesite koordinate donjeg lijevog ugla: ");
    p.dole_lijevo=unos_tacke();
    p.gore_desno=unos_tacke();
    return p;
}


double obim_pravougaonika(struct Pravougaonik p) {
    return 2*((p.gore_desno.x-p.dole_lijevo.x)+(p.gore_desno.y-p.dole_lijevo.y));
}

double povrsina_pravougaonika(struct Pravougaonik p) {
    return (p.gore_desno.x-p.dole_lijevo.x)*(p.gore_desno.y-p.dole_lijevo.y);
}

int tacka_u_pravougaoniku(struct Tacka t,struct Pravougaonik p) {
    return (t.x>=p.dole_lijevo.x && t.y>=p.dole_lijevo.y && t.x<=p.gore_desno.x && t.y<=p.gore_desno.y);
}

int main() {
    printf("Tutorijal 11, Zadatak 3");
    return 0;
}
