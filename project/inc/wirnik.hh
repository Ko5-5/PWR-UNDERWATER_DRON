#ifndef WIRNIK_HH
#define WIRNIK_HH

#include <iostream>
#include <fstream>
#include "figura_geo.hh"

class Wirnik : public Figura_geo
{
    private:
    Wektor3D translacja_lok_dron = Wektor3D(0,-6,-5);
    double kat = 0.00;

    public:
    Wirnik() {};
    Wirnik(std::ifstream & plik_wej, int poz);
    Wirnik(Wirnik & wir, int pos);

    double & operator [] (unsigned int size) {if(size<4) return translacja_lok_dron[size]; else return kat;}
    double operator [] (unsigned int size) const {if(size<4) return translacja_lok_dron[size]; else return kat;}

    Wektor3D & translacja () {return translacja_lok_dron;}
    Wektor3D translacja () const {return translacja_lok_dron;}

    std::vector<Wektor3D> & uk_lok() {return tablica;}
    std::vector<Wektor3D> uk_lok() const {return tablica;}

    std::vector<Wektor3D> & uk_glob() {return tablica_glob;}
    std::vector<Wektor3D> uk_glob() const {return tablica_glob;}

    void obrot_lewa(double kat);
    void obrot_prawa(double kat);
};

std::ostream & operator << (std::ostream & Strm, Wirnik & tab);

#endif
