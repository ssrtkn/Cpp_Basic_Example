#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include <vector>
#include <string>
#include "Paar.h"
using namespace std;

class Liste
{
  private:
    int anzahl_paare, startwert_i, startwert_j, schrittweite;
    vector<Paar> list;
  public:
    Liste(int=1,int=0,int=0, int=0);
    ~Liste();
    Liste operator*(int);
    friend Liste operator*(int,Liste);
    Liste operator+(Liste);
    Liste operator+=(Liste);
    friend ostream &operator<<(ostream &os, const Liste &l);
};

#endif