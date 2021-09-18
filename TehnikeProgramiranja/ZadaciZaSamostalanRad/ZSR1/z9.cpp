//
// Created by 38760 on 18. 9. 2021..
//

/* TP, 2017/2018, ZSR 2, Zadatak 1 */
#include <iostream>
#include<iomanip>
struct v1{
    int s,m,c;
};
int main ()
{
    v1 v{3,45,4};
    std::cout<<std::setw(2)<<std::setfill('0')<<v.s<<":"<<std::setw(2)<<std::setfill('0')<<v.m<<":"<<std::setw(2)<<std::setfill('0')<<v.c;
    return 0;
}