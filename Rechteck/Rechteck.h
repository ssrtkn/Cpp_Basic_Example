#ifndef RECHTECK_H
#define RECHTECK_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Punkt.h"

using namespace std;
class Rechteck{
private:
    Punkt lup, rop; //lup->linken, unteren punkt, rop-> rechten, oberen punkt 
    int breite,hoehe;
public:
    Rechteck(Punkt,Punkt);
    Rechteck(Punkt,int,int);
    ~Rechteck();
    Rechteck operator+(Rechteck);
    friend ostream& operator<<(ostream&, const Rechteck&);
    double flaeche() const;
    bool contains(const Punkt&) const;
    bool contains(const Rechteck&) const;
};
#endif
