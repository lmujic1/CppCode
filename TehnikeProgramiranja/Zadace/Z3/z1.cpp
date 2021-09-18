//
// Created by 38760 on 18. 9. 2021..
//

//TP 2018/2019: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>

double f(double x) {
    return x*x+std::sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvor, int d) {
    if(d<0 || d>=cvor.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<cvor.size();i++)
        for(int j=0;j<cvor.size();j++)
            if(j!=i)
                if(cvor.at(i).first==cvor.at(j).first) throw std::domain_error("Neispravni cvorovi");

    return [cvor,d] (double x) {
        double brojnik(0),nazivnik(0);
        for(int i=0;i<=cvor.size()-1;i++) {
            double w(0);
            int max(0),min(i);
            if(i-d>max) max=i-d;
            if(cvor.size()-d-1<min) min=cvor.size()-d-1;
            for(int k=max;k<=min;k++) {
                double mult(1);
                for(int j=k;j<=k+d;j++) {
                    if(j!=i) {
                        mult*=cvor.at(i).first-cvor.at(j).first;
                    }
                }
                mult=1/mult;
                w+=(pow(-1,k-1))*mult;
            }
            if(x==cvor.at(i).first) x+=0.0000000001;
            nazivnik+=w/(x-cvor.at(i).first);
            brojnik+=(w/(x-cvor.at(i).first))*cvor.at(i).second;
        }
        return brojnik/nazivnik;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin,double xmax,double deltax, int d) {
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvor;
    for(double i=xmin;i<=xmax;i+=deltax) {
        std::pair<double,double> par;
        par.first=i;
        par.second=f(i);
        cvor.push_back(par);
    }

    return [cvor,d] (double x){
        for(auto &par:cvor ) if(fabs(x-par.first)<0.0001) return par.second;
        double brojnik(0),nazivnik(0);
        for(int i=1;i<=cvor.size();i++) {
            double w(0);
            int max(1),min(i);
            if(i-d>max) max=i-d;
            if(cvor.size()-d<min) min=cvor.size()-d;
            for(int k=max;k<=min;k++) {
                double mult(1);
                for(int j=k;j<=k+d;j++) {
                    if(j!=i) mult*=(cvor.at(i-1).first-cvor.at(j-1).first);
                }
                mult=1/mult;
                w=(pow(-1,k-1))*mult+w;
            }
            nazivnik=w/(x-cvor.at(i-1).first)+nazivnik;
            brojnik=((w/(x-cvor.at(i-1).first))*cvor.at(i-1).second)+brojnik;
        }
        return brojnik/nazivnik;
    };

}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int unos;
    std::cin>>unos;
    if(unos==1) {
        std::cout<<"Unesite broj cvorova: ";
        int br_cvorova;
        std::cin>>br_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> cvor(br_cvorova);
        for(int i=0;i<br_cvorova;i++) {
            double x,y;
            std::cin>>x>>y;
            cvor.at(i).first=x;
            cvor.at(i).second=y;
        }
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        std::function<double(double)> fun;
        try {
            fun=(BaricentricnaInterpolacija(cvor,red));
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
        while(1) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double broj;
            std::cin>>broj;
            if(std::cin) std::cout<<"f("<<broj<<") = "<<fun(broj)<<std::endl;
            else  break;
        }
    }
    else if(unos==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax;
        std::cin>>xmin>>xmax;
        double korak;
        std::cin>>korak;
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        std::function<double(double)> fun2;
        try{
            fun2=(BaricentricnaInterpolacija(f,xmin,xmax,korak,red));
        }
        catch(std::domain_error izuzetak) {
            std::cout<< izuzetak.what();
        }
        while(1) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin>>argument;
            if(std::cin) std::cout<<"f("<<argument<<") = "<<f(argument)<<" fapprox("<<argument<<") = "<<fun2(argument)<<std::endl;
            else break;
        }
    }
    return 0;
}