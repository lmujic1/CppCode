//
// Created by 38760 on 18. 9. 2021..
//

/* TP, 2018/2019*/
#include <iostream>
#include <stdexcept>
long long int **StirlingoviBrojeviV1(int n) {
    if(n<=0) throw std::domain_error("Parametar ne smije biti negativan");
    try {
        long long int **stirling=new long long int *[n+1]{};
        try{
            for(int i=0;i<n+1;i++) {
                stirling[i]=new long long int[i+1];
            }
            //racunanje stirlingovih brojeva
            for(int i=0;i<n+1;i++) {
                for(int j=0;j<i+1;j++) {
                    if(j==1 || j==i) stirling[i][j]=1;
                    else if(j==0) stirling[i][j]=0;
                    else stirling[i][j]=stirling[i-1][j-1]+j*stirling[i-1][j];
                }
            }
        }
        catch(...) {
            for(int i=0;i<n+1;i++) delete [] stirling[i];
            delete [] stirling;
            throw;
        }
        return stirling;
    }
    catch(...){
        throw std::range_error("Parametar prevelik za raspolozivu memoriju");
    }
}

long long int **StirlingoviBrojeviV2(int n) {
    if(n<0) throw std::domain_error("Parametar ne smije biti negativan");
    try {
        long long int **stirling=new long long int*[n+1]{};
        try{
            int vel=((n*(n+1))/2)+(n+1);
            stirling[0]=new long long int [vel];
            for(int i=1;i<n+1;i++) stirling[i]=stirling[i-1]+i;

            for(int i=0;i<n+1;i++) {
                for(int j=0;j<i+1;j++) {
                    if(j==1 || j==i) stirling[i][j]=1;
                    else if(j==0) stirling[i][j]=0;
                    else stirling[i][j]=stirling[i-1][j-1]+j*stirling[i-1][j];
                }
            }
        }
        catch(...){
            delete[] stirling;
            throw;
        }
        return stirling;
    }
    catch(...) {
        throw std::range_error("Parametar prevelik za raspolozivu memoriju");
    }
}

int main ()
{
    try{
        int n=8;
        long long int **a(StirlingoviBrojeviV1(n));
        for(int i=0;i<n+1;i++) {
            for(int j=0;j<i+1;j++) {
                std::cout<<a[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        for(int i=0;i<n+1;i++) delete[] a[i];
        delete [] a;
    }
    catch(std::domain_error greska) {
        std::cout<<greska.what();
    }
    catch(std::range_error greska) {
        std::cout<<greska.what();
    }


    try {
        int n(5);
        std::cout<<std::endl<<std::endl;
        long long int **a(StirlingoviBrojeviV2(n));
        for(int i=0;i<n+1;i++) {
            for(int j=0;j<i+1;j++) {
                std::cout<<a[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        delete [] a[0];
        delete [] a;
    }
    catch(std::domain_error greska) {
        std::cout<<greska.what();
    }
    catch(std::range_error greska) {
        std::cout<<greska.what();
    }


    return 0;
}
