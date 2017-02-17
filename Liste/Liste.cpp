#include "Liste.h"

Liste::Liste(int anzahl_paare, int startwert_i, int startwert_j, int schrittweite)
{
    this->anzahl_paare = anzahl_paare;
    this->startwert_i = startwert_i;
    this->startwert_j = startwert_j;
    this->schrittweite = schrittweite;

    if (anzahl_paare < 0)
        throw runtime_error("groesse darf nicht kleiner als 0 sein");
    else if (anzahl_paare > 0)
    {
        int next = 0;
        for (int i = 0; i < anzahl_paare; i++)
        {
            list.push_back(Paar(startwert_i + next, startwert_j + next));
            next += schrittweite;
        }
    }
}
Liste::~Liste() {}

Liste Liste::operator*(int k)
{
    return Liste(anzahl_paare, startwert_i * k, startwert_j * k, schrittweite * k);
}
Liste operator*(int k, Liste l)
{
    return l*k;
}
Liste Liste::operator+(Liste l)
{
    int anz = 0;
    anz += anzahl_paare;
    anz += l.anzahl_paare;

    Liste nl(anz);

    int count=0, fCount = 0, sCount = 0, fSize = this->list.size(), sSize = l.list.size();

    while (fCount+ sCount < anz)
    {
        if (fCount < fSize)
        {
            nl.list.at(count) = this->list.at(fCount);
            fCount++; 
            count++;
        }
        if (sCount < sSize)
        {
            nl.list.at(count) = l.list.at(sCount);
            sCount++;
            count++;
        }
    }

    return nl;
}
Liste Liste::operator+=(Liste l) {
     Liste &m = *this;
     m = m + l;
     return m;
}
ostream &operator<<(ostream &os, const Liste &l)
{
    os << "{";
    for (int i = 0; i < l.anzahl_paare; i++)
    {
        os << l.list.at(i);
        if (i + 1 < l.anzahl_paare)
            os << ",";
    }
    os << "}";
    return os;
}