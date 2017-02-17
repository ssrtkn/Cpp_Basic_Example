#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>
#include <stdexcept>
using namespace std;

class Punkt{
private:
    int x, y;
public:
    Punkt(int=0,int=0);
    ~Punkt();
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
    friend ostream &operator<<(ostream &, const Punkt&) ;
};

#endif