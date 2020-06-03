#ifndef WIRNIK_HH
#define WIRNIK_HH

#include <iostream>
#include <fstream>
#include "figura_geo.hh"

class Wirnik : public Figura_geo
{
    private:
    Wektor3D translacja_lok_dron;
    double kat = 0;

    public:
    Wirnik() {};
    Wirnik(std::ifstream & plik_wej, int poz);

    double & operator [] (unsigned int size) {if(size<4) return translacja_lok_dron[size]; else return kat;}
    double operator [] (unsigned int size) const {if(size<4) return translacja_lok_dron[size]; else return kat;}

    Wektor3D translacja () {return translacja_lok_dron;}

    std::vector<Wektor3D> uk_lok() {return tablica;}

    void obrot_lewa(double kat);
    void obrot_prawa(double kat);
};

#endif
