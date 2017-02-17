#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Exponential{
    private:
        int basis, exp;
    public:
        Exponential(int=1,int=1);
        ~Exponential();

        Exponential operator*(Exponential);
        friend ostream& operator<<(ostream&,const Exponential&);
        bool basiswechsel(int);
        vector<Exponential> faktoren() const;
};
#endif