#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include "Paar.h"
#include "Liste.h"

using namespace std;

int main(){
    Paar x;
    Paar y(5);
    Paar z(5,5);
    cout<<"x"<<x<<'\n'<<"y"<<y<<'\n'<<"z"<<z<<'\n';
    cout<<"x+y"<<x+y<<'\n';
    cout<<"3*z"<<3*z<<'\n';
    cout<<"z*3"<<z*3<<'\n';

    Liste l(3,4,-1,2);
    Liste k(5,2,-1,3);
    cout<<"l"<<l<<endl;
    cout<<"k"<<k<<endl;
    cout<<"l*3"<<l*3<<endl;
    cout<<"3*l"<<3*l<<endl;
    cout<<"l+k"<<l+k<<endl;
    l+=k;
    cout<<"l"<<l<<endl;
    return 0;
}