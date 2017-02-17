#ifndef POLYNOME_H
#define POLYNOME_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Polynome{
private:
    vector<int> koeffizienten;
public:
    Polynome(vector<int>);
    ~Polynome();

    int grad() const;
    friend ostream& operator<<(ostream&,const Polynome&);
    int wert(int) const;
    ostream& print_fmt(ostream&) const;
};

#endif
