//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> &mat) {
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova]{};
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona]{};
    }//hehe
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu( Matrica<TipElemenata> &mat, int sirina_ispisa,int preciznost=6,bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++)
            for(int k=0;k<m1.br_kolona;k++)
                m3.elementi[i][j]=m3.elementi[i][j]+(m1.elementi[i][k]*m2.elementi[k][j]);
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> p) {
    if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> rezultat(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    if(p.size()==0) return rezultat;
    else {
        TipElemenata broj(p.at(0));
        for(int i=0;i<A.br_redova;i++)
            for(int j=0;j<A.br_redova;j++)
                if(i==j) rezultat.elementi[i][j]=broj;
    }



    Matrica<TipElemenata> B=StvoriMatricu<TipElemenata>(A.br_redova,A .br_kolona);
    for(int i=0;i<A.br_redova;i++)
        for(int j=0;j<A.br_redova;j++)
            B.elementi[i][j]=A.elementi[i][j];

    for(int i=1;i<p.size();i++) {
        Matrica<TipElemenata> pomocna;
        if(i==1) {
            pomocna=StvoriMatricu<TipElemenata>(A.br_redova,A.br_redova) ;
            for(int j=0;j<A.br_redova;j++)
                for(int k=0;k<A.br_redova;k++)
                    pomocna.elementi[j][k]=A.elementi[j][k];
        }
        else pomocna=ProduktMatrica(B,A);

        for(int j=0;j<A.br_redova;j++)
            for(int k=0;k<A.br_redova;k++)
                B.elementi[j][k]=pomocna.elementi[j][k];

        for(int j=0;j<A.br_redova;j++) {
            for(int k=0;k<A.br_kolona;k++) {
                pomocna.elementi[j][k]=pomocna.elementi[j][k]*p[i];
            }
        }

        Matrica<TipElemenata> pomocna2(ZbirMatrica(rezultat,pomocna));

        for(int j=0;j<A.br_redova;j++)
            for(int k=0;k<A.br_redova;k++)
                rezultat.elementi[j][k]=pomocna2.elementi[j][k];

        UnistiMatricu<TipElemenata>(pomocna); UnistiMatricu<TipElemenata>(pomocna2);

    }

    UnistiMatricu<TipElemenata>(B);

    return rezultat;
}

int main() {
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int dim1,dim2;
    std::cin>>dim1;
    dim2=dim1;
    Matrica<double> a,rez;
    try{

        a=StvoriMatricu<double>(dim1,dim2);
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti;
        for(int i=0;i<red+1;i++) {
            double k;
            std::cin>>k;
            koeficijenti.push_back(k);
        }
        IspisiMatricu(rez=MatricniPolinom(a,koeficijenti),10,6);
    }
    catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!"<<std::endl;
    }
    catch(std::domain_error greska) {
        std::cout<<greska.what()<<std::endl;
    }
    UnistiMatricu(a); UnistiMatricu(rez);

    return 0;
}
