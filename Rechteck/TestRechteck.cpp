#include <iostream>
#include <stdexcept>

#include "Punkt.h"
#include "Rechteck.h"

using namespace std;

int main()
{
    Punkt p1(1, -10), p2(4, 8), p3; //p3 hat Koordinaten (0.0);
    Rechteck r1(p1, p2), r2(p3, 10, 5);

    try
    {
		Rechteck r(p2, p1);
    }
    catch (...)
    {
		cout << "Illegales Rechteck!" << endl;
    }

    try
    {
		Rechteck r(p1, -3, -2);
    }
    catch (...)
    {
		cout << "Breite und Hoehe muessen positiv sein!" << endl;
    }

    cout << r1 << " / " << r2 << endl;
    cout << r1.flaeche() << endl;
    cout << r2.flaeche() << endl;
    cout << r1 + r2 << endl;
    cout << (r1 + r2).flaeche() << endl;

    cout << r2.contains(p1) << r2.contains(p2) << r2.contains(p3) << endl;
    cout << (r1 + r2).contains(r1) << r1.contains(r2) << (r1 + r2).contains(r2) << endl;

    return 0;
}