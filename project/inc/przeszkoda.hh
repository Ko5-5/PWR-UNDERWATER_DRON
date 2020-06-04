#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <cstdlib>
#include <ctime>
#include "figura_geo.hh"

class Przeszkoda : public Figura_geo
{
    private:
    Wektor3D translacja;

    public:
    Przeszkoda(Wektor3D trans);

    double & operator [] (unsigned int size) {return translacja[size];}
    double operator [] (unsigned int size) const {return translacja[size];}

    bool czy_w_zakresie(Wektor3D trans);
};

bool operator == (const Przeszkoda prze1, const Przeszkoda prze2);

std::ostream & operator << (std::ostream & Strm, Przeszkoda & tab);

#endif