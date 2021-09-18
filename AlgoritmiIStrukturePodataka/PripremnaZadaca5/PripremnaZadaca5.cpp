//
// Created by 38760 on 18. 9. 2021..
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>


template <typename Tip>
void bubble_sort(Tip* niz, int vel)
{
    for(int i=vel-1; i>0; i--) {
        for(int j=1; j<=i; j++) {
            if(niz[j-1]>niz[j]) {
                Tip tmp=niz[j];
                niz[j]=niz[j-1];
                niz[j-1]=tmp;
            }
        }
    }
}

template <typename Tip>
void selection_sort(Tip* niz, int vel)
{
    for(int i=0; i<=vel-2; i++) {
        Tip min=niz[i];
        int index=i;
        for(int j=i+1; j<=vel-1; j++) {
            if(niz[j]<min) {
                min=niz[j];
                index=j;
            }
        }
        niz[index]=niz[i];
        niz[i]=min;
    }

}

template<typename Tip>
int particija(Tip * niz, int prvi,int zadnji) {
    for(int i=prvi;i<=zadnji;i++) {
        std::cout<<niz[i]<<" ";
    }
    std::cout<<std::endl;

    Tip pivot=niz[prvi];
    int p=prvi+1;
    while(p<=zadnji && niz[p]<pivot) p++;
    for(int i=p+1;i<=zadnji;i++) {
        if(niz[i]<pivot) {
            Tip tmp=niz[i];
            niz[i]=niz[p];
            niz[p]=tmp;
            p++;
        }
    }
    Tip tmp=niz[prvi];
    niz[prvi]=niz[p-1];
    niz[p-1]=tmp;



    return p-1;
}

template<typename Tip>
void quick_sort1(Tip* niz, int prvi,int zadnji) {
    for(int i=prvi;i<=zadnji;i++) {
        std::cout<<niz[i]<<" ";
    }
    std::cout<<std::endl;
    if(prvi<zadnji) {
        int j=particija(niz,prvi,zadnji);
        quick_sort1(niz,prvi,j-1);
        quick_sort1(niz,j+1,zadnji);
    }
}

template <typename Tip>
void quick_sort(Tip* niz, int vel)
{
    quick_sort1(niz,0,vel-1);
}


template<typename Tip>
void merge(Tip* niz, int pocetak, int sredina1, int sredina2, int kraj)
{
    int i=0;
    int j=sredina2-pocetak;
    int k=pocetak;
    Tip *B=new Tip[kraj-pocetak+1];
    for(int m=0; m<=kraj-pocetak; m++)
        B[m]=niz[pocetak+m];
    while(i<=sredina1-pocetak && j<=kraj-pocetak) {
        if(B[i]<B[j]) niz[k]=B[i++];
        else niz[k]=B[j++];
        k++;
    }
    while(i<=sredina1-pocetak) niz[k++]=B[i++];
    while(j<=kraj-pocetak) niz[k++]=B[j++];

    delete [] B ;

}

template<typename Tip>
void merge_sort1(Tip* niz, int pocetak,int kraj)
{
    if(kraj>pocetak) {
        int sredina=(kraj+pocetak-1)/2;
        merge_sort1(niz, pocetak,sredina);
        merge_sort1(niz,sredina+1, kraj);
        merge(niz,pocetak,sredina,sredina+1,kraj);
    }
}

template <typename Tip>
void merge_sort(Tip* niz, int vel)
{
    merge_sort1(niz,0,vel-1);
}


void ucitaj(std::string filename, int*& niz, int &vel)
{
    std::ifstream ulazni_tok(filename);
    int broj;
    std::vector<int> v;
    while(ulazni_tok >> broj) v.push_back(broj);
    int *niz1=new int[v.size()];
    std::copy(v.begin(),v.end(),niz1);
    niz=niz1;
    vel=v.size();
}
void generisi(std::string filename, int vel)
{
    std::ofstream izlazni_tok(filename);
    for(int i=0;i<vel;i++) izlazni_tok<<rand()<<" ";
}


bool daLiJeSortiran(int *niz,int vel) {
    for(int i=0;i<vel-1;i++){
        if(niz[i]>niz[i+1]) return false;
    }
    return true;
}
int main()
{
    int *niz;
    int vel,unos,ukupno_vrijeme;
    std::cout << "Unesite broj elemenata niza: ";
    std::cin>>vel;
    std::cout<<"\n. . . Generisanje slucajnih brojeva u datoteku . . . \n";
    generisi("dat", vel);
    std::cout<<"\n. . . Ucitavanje brojeva iz datoteke . . . \n";
    ucitaj("dat", niz,vel);
    std::cout<<"Odaberite jedan od algoritama za sortiranje: \n1 - Bubble sort\n2 - Selection sort\n3 - Quick sort\n4 - Merge sort\n";
    std::cin>>unos;
    clock_t pocetak=clock();
    if(unos==1) bubble_sort(niz,vel);
    else if(unos==2) selection_sort(niz,vel);
    else if(unos==3) quick_sort(niz,vel);
    else if(unos==4) merge_sort(niz,vel);
    clock_t kraj=clock();
    ukupno_vrijeme=(kraj-pocetak)/(CLOCKS_PER_SEC/1000);
    std::cout<<"Vrijeme izvrsavanja trazenog algoritma: "<<ukupno_vrijeme<<" ms\n";
    if(daLiJeSortiran(niz,vel)) std::cout<<"Niz je sortiran\n";
    else std::cout<<"Niz nije sortiran\n";
    std::ofstream tok("Sortiran");
    for(int i=0;i<vel;i++) tok<<niz[i]<<" ";
    int niz1[]{17,9,11,10,5,18,24,1,35,3,12,21};

    quick_sort(niz1,12);


    return 0;
}