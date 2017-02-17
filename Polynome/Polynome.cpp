#include "Polynome.h"

Polynome::Polynome(vector<int> v)
{
    if (v.size() == 0)
        throw runtime_error("Leer");

    koeffizienten = {};
    for (int i : v)
    {
        koeffizienten.push_back(i);
    }
}
Polynome::~Polynome()
{
}

int Polynome::grad() const
{

    return koeffizienten.size();
}
ostream &operator<<(ostream &os, const Polynome &p)
{
    int currGrad = p.grad();
    for (int i = 0; i < currGrad; i++)
    {
        os << p.koeffizienten.at(currGrad - 1 - i) << "x^" << currGrad - i - 1;
        if (i + 1 < currGrad && p.koeffizienten.at(currGrad - 1 - i) > 0)
            os << "+";
    }
    return os;
}
int Polynome::wert(int x) const
{
    int sum = 0;
    int currGrad = grad();
    for (int i = 0; i < currGrad; i++)
    {
        int count = 1, lvl = 1;
        while (count < currGrad - i)
        {
            lvl *= x;
            count++;
        }

        sum += lvl * koeffizienten.at(currGrad - i - 1);
    }

    return sum;
}
ostream &Polynome::print_fmt(ostream &os) const
{
    int currGrad = grad();
    for (int i = 0; i < currGrad; i++)
    {
        if (i > 0 && koeffizienten.at(currGrad - 1 - i) > 0)
            os << "+";

        if (koeffizienten.at(currGrad - 1 - i) != 0 && koeffizienten.at(currGrad - 1 - i) != 1)
        {
            if (currGrad - i - 1 > 1)
                os << koeffizienten.at(currGrad - 1 - i) << "x^" << currGrad - i - 1;
            else if (currGrad - i - 1 == 1)
                os << koeffizienten.at(currGrad - 1 - i) << "x";
            else if (currGrad - i - 1 == 0)
                os << koeffizienten.at(currGrad - 1 - i);
        }
        else if (koeffizienten.at(currGrad - 1 - i) == 1)
        {
            if (currGrad - i - 1 > 1)
                os << "x^" << currGrad - i - 1;
            else if (currGrad - i - 1 == 1)
                os << "x";
        }
    }

    return os;
}