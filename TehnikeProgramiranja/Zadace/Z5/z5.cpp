//TP 2018/2019: Zadaća 5, Zadatak 5
#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <fstream>
template <typename TipEl>
class Matrica {
    int br_redova, br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);
    void TestIndeksa(int index1, int index2) const {
        if(index1<1 || index2<1 || index1>br_redova || index2>br_kolona)
            throw std::range_error("Neispravan indeks");
    }
public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);
    friend std::ostream& operator<<(std::ostream& tok, const Matrica &m) {
        int a(tok.width());
        for(int i=0;i<m.br_redova;i++) {
            for(int j=0;j<m.br_kolona;j++){
                tok<<std::setw(a)<<m.elementi[i][j];
            }
            tok<<std::endl;
        }
        return tok;
    }
    friend std::istream& operator>>(std::istream& tok, const Matrica &m) {
        for(int i=0;i<m.br_redova;i++) {
            for(int j=0;j<m.br_kolona;j++) {
                std::cout<<m.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                tok>>m.elementi[i][j];
            }
        }
        return tok;
    }
    friend Matrica operator +(const Matrica &t1,const Matrica &t2) {
        if(t1.br_redova!=t2.br_redova || t1.br_kolona!=t2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica t3(t1.br_redova,t1.br_kolona);
        for(int i=0;i<t1.br_redova;i++) {
            for(int j=0;j<t1.br_kolona;j++) {
                t3.elementi[i][j]=t1.elementi[i][j]+t2.elementi[i][j];
            }
        }
        return t3;
    }
    friend Matrica operator -(const Matrica &t1,const Matrica &t2) {
        if(t1.br_redova!=t2.br_redova || t1.br_kolona!=t2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica t3(t1.br_redova,t1.br_kolona);
        for(int i=0;i<t1.br_redova;i++) {
            for(int j=0;j<t1.br_kolona;j++) {
                t3.elementi[i][j]=t1.elementi[i][j]-t2.elementi[i][j];
            }
        }
        return t3;
    }
    friend Matrica operator *(const Matrica &t,double x) {
        Matrica t3(t.br_redova,t.br_kolona);
        for(int i=0;i<t.br_redova;i++) {
            for(int j=0;j<t.br_kolona;j++) {
                t3.elementi[i][j]=t.elementi[i][j]*x;
            }
        }
        return t3;
    }
    friend Matrica operator *(double x,const Matrica &t) {
        Matrica t3(t.br_redova,t.br_kolona);
        for(int i=0;i<t.br_redova;i++) {
            for(int j=0;j<t.br_kolona;j++) {
                t3.elementi[i][j]=t.elementi[i][j]*x;
            }
        }
        return t3;
    }
    friend Matrica operator *(const Matrica &t1, const Matrica &t2) {
        if(t1.br_redova!=t2.br_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        Matrica t3(t1.br_redova,t2.br_kolona);
        for(int i=0;i<t1.br_redova;i++) {
            for(int j=0;j<t2.br_kolona;j++) {
                for(int k=0;k<t2.br_redova;k++)
                    t3.elementi[i][j]+=t1.elementi[i][k]*t2.elementi[k][j];
            }

        }
        return t3;
    }
    Matrica operator +=(const Matrica &t) {
        if(this->br_redova!=t.br_redova || this->br_kolona!=t.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica t3(t.br_redova,t.br_kolona);
        for(int i=0;i<t.br_redova;i++) {
            for(int j=0;j<t.br_kolona;j++) {
                this->elementi[i][j]+=t.elementi[i][j];
            }
        }
        return *this;
    }
    Matrica operator -=(const Matrica &t) {
        if(this->br_redova!=t.br_redova || this->br_kolona!=t.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica t3(t.br_redova,t.br_kolona);
        for(int i=0;i<t.br_redova;i++) {
            for(int j=0;j<t.br_kolona;j++) {
                this->elementi[i][j]-=t.elementi[i][j];
            }
        }
        return *this;
    }
    Matrica operator *=(double x) {
        for(int i=0;i<br_redova;i++) {
            for(int j=0;j<br_kolona;j++) {
                this->elementi[i][j]*=x;
            }
        }
        return *this;
    }
    Matrica operator *=(const Matrica &t) {
        if(br_redova!=t.br_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        Matrica t3(br_redova,t.br_kolona);
        for(int i=0;i<br_redova;i++) {
            for(int j=0;j<t.br_kolona;j++) {
                for(int k=0;k<t.br_redova;k++)
                    t3.elementi[i][j]+=elementi[i][k]*t.elementi[k][j];
            }

        }
        *this=t3;
        return *this;
    }
    TipEl* operator [] (int indeks) const {
        return elementi[indeks];
    }
    TipEl* &operator [] (int indeks) {
        return elementi[indeks];
    }
    TipEl &operator ()(int a, int b){
        TestIndeksa(a,b); return elementi[a-1][b-1];
    }
    TipEl operator ()(int a, int b) const {
        TestIndeksa(a,b); return elementi[a-1][b-1];
    }
    operator std::string() const{
        std::string s;
        s.push_back('{');
        for(int i=0; i<br_redova; i++){
            s.push_back('{');
            for(int j=0; j<br_kolona; j++){
                if(j==br_kolona-1){
                    s+=std::to_string(int(elementi[i][j]));
                    s.push_back('}');
                    break;
                }
                s+=std::to_string(int(elementi[i][j]));
                s.push_back(',');
            }
            if(i==br_redova-1) { s.push_back('}'); break; }
            s.push_back(',');
        }
        return s;
    }
    void SacuvajUTekstualnuDatoteku(const std::string &ime) const {
        std::ofstream izlazni(ime);
        for(int i=0;i<br_redova;i++) {
            for(int j=0;j<br_kolona;j++) {
                if(j==br_kolona-1) izlazni<<elementi[i][j]<<"\n";
                else izlazni<<elementi[i][j]<<",";
            }
            //izlazni<<"\n";
        }
        if(!izlazni) throw std::logic_error("Problemi sa upisom u datoteku");
    }
    void SacuvajUBinarnuDatoteku(const std::string &ime) const {
        std::ofstream izlazni(ime,std::ios::binary);
        izlazni.write(reinterpret_cast<const char*>(this), sizeof *this);
        for(int i=0;i<br_redova;i++) {
            izlazni.write(reinterpret_cast<char*>(elementi[i]),sizeof(TipEl[br_kolona]));
        }
        if(!izlazni) throw std::logic_error("Problemi sa upisom u datoteku");
    }
    void ObnoviIzTekstualneDatoteke(const std::string &ime) {
        std::ifstream ulaz(ime);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        char pom;
        int kolone(0),redovi(0);
        while(!ulaz.eof()) {
            while(ulaz.get(pom)) {
                if(pom==',') kolone++;
                else if(pom=='\n'){ kolone++; redovi++; break; }
                else if(!(pom>='0' && pom<='9') && pom!=',' && pom!='.' && pom!=' ' && pom!='-') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                //if(pom==' ') pom=' ';
            }
        }
        redovi++;
        //ulaz.clear();
        ulaz.seekg(0);
        if(elementi==nullptr) {
            elementi=new TipEl*[redovi-1]{};
            for(int i=0;i<redovi-1;i++) elementi[i]=new TipEl[kolone-1]{}; }
        TipEl t;
        while(!ulaz.eof()) {
            for(int i=0;i<redovi-1;i++) {
                for(int j=0;j<kolone-1;j++){
                    if(j==kolone-1) {
                        ulaz>>t>>pom;
                        elementi[i][j]=t;
                        break;
                    }
                    else {
                        ulaz>>t>>pom;
                        elementi[i][j]=t;
                    }
                }
                //ulaz>>pom;
                if(pom!='\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
        }
        if(!ulaz) {
            for(int i=0;i<br_redova;i++) delete [] elementi[i];
            delete[] elementi;
            throw std::logic_error("Problemi pri citanju datoteke");
        }
    }
    void ObnoviIzBinarneDatoteke(const std::string &ime) {
        std::ifstream ulaz(ime,std::ios::binary);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        //for(int i=0;i<br_redova;i++) delete[]elementi[i];
        //delete[]elementi;
        ulaz.read(reinterpret_cast<char*>(this),sizeof *this);
        elementi=new TipEl*[br_redova]{};
        for(int i=0;i<br_redova;i++) {
            elementi[i]=new TipEl[br_kolona];
            ulaz.read(reinterpret_cast<char*>(elementi[i]),sizeof(TipEl[br_kolona])); //??
        }
        if(!ulaz) {
            for(int i=0;i<br_redova;i++) delete [] elementi[i];
            delete[] elementi;
            throw std::logic_error("Problemi pri citanju datoteke");
        }
    }
    Matrica(const std::string &ime,bool dat) {
        elementi=nullptr;
        if(dat) ObnoviIzBinarneDatoteke(ime);
        else if(!dat) ObnoviIzTekstualneDatoteke(ime);
    }
};
template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
    TipEl **elementi(new TipEl*[br_redova]{});
    try {
        for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona]{};
    }
    catch(...) {
        DealocirajMemoriju(elementi, br_redova); throw;
    }
    return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
    for(int i = 0; i < br_redova; i++) delete[] elementi[i];
    delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona),
                                                                  ime_matrice(ime), elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona),
                                                   ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
    KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona),
                                              elementi(m.elementi), ime_matrice(m.ime_matrice) {
    m.br_redova = 0; m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m) {
    if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
        TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
        DealocirajMemoriju(elementi, br_redova);
        elementi = novi_prostor;
    }
    else if(br_redova > m.br_redova)
        for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
    br_redova = m.br_redova; br_kolona = m.br_kolona;
    ime_matrice = m.ime_matrice; KopirajElemente(m.elementi);
    return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
    std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
    std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
    return *this;
}

int main() {
    int m, n;
    std::cout << "Unesi broj redova i kolona za matrice:\n";
    std::cin >> m >> n;
    try {
        Matrica<double> a(m, n, 'A'), b(m, n, 'B');
        std::cout << "Unesi matricu A:\n";
        std::cin >> a;
        std::cout << "Unesi matricu B:\n";
        std::cin >> b;
        std::cout << "Zbir ove dvije matrice je:\n";
        std::cout << std::setw(7) << a + b;
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return 0;
}
