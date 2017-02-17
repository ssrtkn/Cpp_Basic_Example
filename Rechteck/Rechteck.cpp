#include "Rechteck.h"
Rechteck::Rechteck(Punkt p1, Punkt p2) : lup(p1), rop(p2)
{
    this->breite = p2.getX() - p1.getX();
    this->hoehe = p2.getY() - p1.getY();

    if(lup.getX() > rop.getX() || lup.getY() > rop.getY())
        throw exception();
}
Rechteck::Rechteck(Punkt p, int b, int h): lup(p), breite(b), hoehe(h)  {
    this->rop.setX(p.getX()+b);
    this->rop.setY(p.getY()+h);

    if(lup.getX() > rop.getX() || lup.getY() > rop.getY())
        throw exception();
}
Rechteck::~Rechteck() {}
Rechteck Rechteck::operator+(Rechteck r) {
    int n_lup_x, n_lup_y, n_rop_x, n_rop_y;
    (lup.getX() < r.lup.getX()) ? n_lup_x=lup.getX():n_lup_x=r.lup.getX();
    (lup.getY() < r.lup.getY()) ? n_lup_y=lup.getY():n_lup_y=r.lup.getY();
    (rop.getX() > r.rop.getX()) ? n_rop_x=rop.getX():n_rop_x=r.rop.getX();
    (rop.getY() > r.rop.getY()) ? n_rop_y=rop.getY():n_rop_y=r.rop.getY();

    
    return Rechteck(Punkt( n_lup_x, n_lup_y),Punkt( n_rop_x, n_rop_y));
}
ostream &operator<<(ostream & os, const Rechteck &r) {
    os<<"LUP:"<<r.lup<<" ROP:"<<r.rop<<" Breite: "<<r.breite<<" Hoehe "<<r.hoehe<<" ";
    return os;
}
double Rechteck::flaeche() const { return (hoehe*breite);}

bool Rechteck::contains(const Punkt & p) const {
    if(p.getX() < lup.getX() || p.getX() > rop.getX() || p.getY() < lup.getY() || p.getY() > rop.getY() )
        return false;

    return true;
}
bool Rechteck::contains(const Rechteck &r) const {
    if(contains(r.lup) && contains(r.rop))
        return true;
    return false;
}