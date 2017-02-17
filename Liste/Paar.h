#ifndef PAAR_H
#define PAAR_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Paar
{
  private:
    int x, y;

  public:
    Paar(int x = 0, int y = 0);
    ~Paar();
    int getX();
    int getY();
    Paar operator+(Paar p);
    Paar operator*(int k);
    friend Paar operator*(int k, Paar p);
    friend ostream &operator<<(ostream & os, const Paar & p);
};

#endif