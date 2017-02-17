#include "Exponential.h"

Exponential::Exponential(int b, int e) : basis(b), exp(e)
{
    if (b == 0 && e == 0)
        throw runtime_error("0^0 ist nicht erlaubt.");
    else if (b == 0 && e > 0)
        exp = 1;
    else if (b == 0 && e < 0)
        exp = -1;
    else if (b == 1)
        exp = 0;
    else if (b != 0 && e == 0)
    {
        basis = 1;
        exp = 0;
    }
}

Exponential::~Exponential() {}

Exponential Exponential::operator*(Exponential e)
{
    if (basis == e.basis && exp == e.exp)
        return Exponential(basis, exp * 2);
    else if (basis == e.basis)
        return Exponential(basis, exp + e.exp);
    else if (exp == e.exp)
        return Exponential(basis * e.basis, exp);
    else
        throw runtime_error("Multiplikation nicht durchgeführt werden.");
}

ostream &operator<<(ostream &os, const Exponential &e)
{
    os << e.basis << "^" << e.exp;
    return os;
}

bool Exponential::basiswechsel(int b)
{

    if (b == 0 || basis == 0)
        return false;
    else if (b == basis)
        return true;
    else
    {
        bool chk = false;
        int count = 0, small, big;
        if (basis > b)
        {
            big = basis;
            small = b;
        }
        else
        {
            small = basis;
            big = b;
            chk = true;
        }

        while (big % small == 0 && big != 0)
        {
            big /= small;
            count++;
        }

        if (count > 0)
        {
            basis = b;
            if (chk)
            {
                exp /= count;
            }
            else
            {
                exp *= count;
            }
            return true;
        }
    }

    return false;
}

vector<Exponential> Exponential::faktoren() const
{
    vector<Exponential> vec = {};
    vector<int> div = {2, 3, 5, 7};
    vector<int> count = {0,0,0,0};
    int tmp = basis;

    for (size_t i = 0; i < div.size(); i++)
    {
        while (tmp % div.at(i) == 0 && tmp != 0)
        {
            count.at(i)++;
            tmp /= div.at(i);
        }
    }

    for (size_t i = 0; i < div.size(); i++)
    {
        if(count.at(i) > 0){
            vec.push_back(Exponential(div.at(i),count.at(i) *exp ));
        }
    }

    vec.push_back(Exponential(tmp,exp));

    return vec;
}