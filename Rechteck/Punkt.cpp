#include "Punkt.h"

Punkt::Punkt(int x, int y) : x(x), y(y) {}
Punkt::~Punkt() {}
int Punkt::getX() const{ return x; }
int Punkt::getY() const{ return y; }
void Punkt::setX(int x) { this->x = x; }
void Punkt::setY(int y) { this->y = y; }
ostream &operator<<(ostream &os, const Punkt &p)
{
    os << " (" << p.x << "," << p.y << ") ";
    return os;
}