#include "Paar.h"
Paar::Paar(int x, int y) : x(x), y(y){};
Paar::~Paar(){};
int Paar::getX() { return this->x; }
int Paar::getY() { return this->y; }

Paar Paar::operator+(Paar p) { return Paar(x + p.x, y + p.y); }
Paar Paar::operator*(int k) { return Paar(x * k, y * k); }
Paar operator*(int k, Paar p) { return Paar(p.x * k, p.y * k); }
ostream &operator<<(ostream &os, const Paar &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}