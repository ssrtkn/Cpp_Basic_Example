#include <iostream>
#include <vector>
#include <string>
#include "Polynome.h"

using namespace std;
int main(){

    Polynome p({3,2,1});

    cout<<"p(x)="<<p<<endl;
    p.print_fmt(cout)<<endl;
    cout<<"p(3)="<<p.wert(3)<<endl;

        Polynome p1({-3,0,1});

    cout<<"p1(x)="<<p1<<endl;
    p1.print_fmt(cout)<<endl;
    cout<<"p1(3)="<<p1.wert(3)<<endl;

    return 0;
}
