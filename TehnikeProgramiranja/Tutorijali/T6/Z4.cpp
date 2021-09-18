//
// Created by 38760 on 18. 9. 2021..
//

/*
    TP 2018/2019: Tutorijal 6, Zadatak 3

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <stdexcept>
int **KreirajTrougao(int n) {
    if(n<=0) throw std::domain_error("Broj redova mora biti pozitivan");

    try {
        int **grbava_matrica=new int*[n]{};
        try{
            grbava_matrica[0]=new int[n*n];

            for(int i=1;i<n;i++)
                grbava_matrica[i]=grbava_matrica[i-1]+2*i-1;

            for(int i=0;i<n;i++)
                for(int j=0;j<2*i+1;j++) {
                    if(j==0) grbava_matrica[i][j]=i+1;
                    else if(j<=i) grbava_matrica[i][j]=grbava_matrica[i][j-1]-1;
                    else grbava_matrica[i][j]=grbava_matrica[i][j-1]+1;
                }
        }
        catch(...) {
            delete[] grbava_matrica;
            throw;
        }

        return grbava_matrica;
    }
    catch(...) {
        throw;
    }

}
int main ()
{
    std::cout<<"Koliko zelite redova: ";
    int n;
    std::cin>>n;
    int **a(nullptr);
    try{
        a=KreirajTrougao(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<2*i+1;j++) {
                std::cout<<a[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        delete [] a[0];
        delete [] a;
    }
    catch(std::domain_error poruka) {
        std::cout<<"Izuzetak: "<<poruka.what();
    }
    catch(std::bad_alloc) {
        std::cout<<"Izuzetak: Nedovoljno memorije!";
    }
    return 0;
}