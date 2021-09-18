//
// Created by 38760 on 18. 9. 2021..
//

// TP, 2018/2019, Zadaća 1, Zadatak 2
#include <iostream>
#include <vector>
#include <complex>
#include <stdexcept>
#include <limits>

typedef std::vector<std::vector<int>> Matrica;

std::complex<double> VrhMatrice (Matrica mat, int br_red, int br_kol) {
    //bacanje izuzetaka
    if(mat.size()==0 || mat.at(0).size()==0) throw std::domain_error("Nekorektna matrica");
    for(int i=0;i<mat.size();i++) {
        if(mat.at(i).size()!=mat.at(0).size()) {
            throw std::domain_error("Nekorektna matrica");
            break;
        }
    }
    if(br_red>(mat.size()-1) || br_red<0 || br_kol>(mat.at(0).size()-1) || br_kol<0) throw std::range_error("Nekorektna pocetna pozicija");

    std::vector<int> pom(8);
    int zapamti_i(br_red),zapamti_j(br_kol);
    while(true) {
        int i=zapamti_i;
        int	j=zapamti_j;
        //clanovi oko poslanog elementa
        std::vector<int> pom(8,std::numeric_limits<int>::min());
        if(i!=0) pom.at(0)=mat.at(i-1).at(j);
        if(i!=0 && j!=mat.at(0).size()-1) pom.at(1)=mat.at(i-1).at(j+1);
        if(j!=mat.at(0).size()-1) pom.at(2)=mat.at(i).at(j+1);
        if(i!=mat.size()-1 && j!=mat.at(0).size()-1) pom.at(3)=mat.at(i+1).at(j+1);
        if(i!=mat.size()-1) pom.at(4)=mat.at(i+1).at(j);
        if(i!=mat.size()-1 && j!=0) pom.at(5)=mat.at(i+1).at(j-1);
        if(j!=0) pom.at(6)=mat.at(i).at(j-1);
        if(i!=0 && j!=0) pom.at(7)=mat.at(i-1).at(j-1);
        //max element
        int max=std::numeric_limits<int>::min();
        int pozicija(8);
        for(int k=0;k<pom.size();k++)
            if(pom.at(k)>max) {
                max=pom.at(k);
                pozicija=k;
            }

        if(max>mat.at(i).at(j)) {
            if(pozicija==0) { zapamti_i=i-1; zapamti_j=j; }
            if(pozicija==1) { zapamti_i=i-1; zapamti_j=j+1; }
            if(pozicija==2) { zapamti_i=i; zapamti_j=j+1; }
            if(pozicija==3) { zapamti_i=i+1; zapamti_j=j+1; }
            if(pozicija==4) { zapamti_i=i+1; zapamti_j=j; }
            if(pozicija==5) { zapamti_i=i+1; zapamti_j=j-1; }
            if(pozicija==6) { zapamti_i=i; zapamti_j=j-1; }
            if(pozicija==7) { zapamti_i=i-1; zapamti_j=j-1; }
        }
        else break;
    }

    return std::complex<double>(zapamti_i,zapamti_j);
}

int main ()
{
    std::cout<<"Unesite broj redova i kolona matrice:";
    int red,kolona;
    std::cin>>red>>kolona;
    std::cout<<std::endl<<"Unesite elemente matrice:";
    Matrica A(red,std::vector<int>(kolona));
    int broj;
    for(int i=0;i<red;i++) {
        for(int j=0;j<kolona;j++) {
            std::cin>>broj;
            A.at(i).at(j)=broj;
        }
    }
    std::cout<<std::endl<<"Unesite poziciju odakle zapocinje pretraga:";
    std::cin>>red>>kolona;
    try {
        std::complex<double> vrh(VrhMatrice(A,red,kolona));
        std::cout<<std::endl<<"Nadjen je vrh matrice na poziciji "<<vrh.real()<<" "<<vrh.imag();
        std::cout<<std::endl<<"Njegova vrijednost je "<<A.at(int(vrh.real())).at(int(vrh.imag()));
    }
    catch (std::domain_error error) {
        std::cout<<std::endl<<"Greska: "<<error.what()<<std::endl;
    }
    catch (std::range_error error) {
        std::cout<<std::endl<<"Greska: "<<error.what()<<std::endl;
    }
    return 0;
}