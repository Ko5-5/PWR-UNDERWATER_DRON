#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <cstdlib>
#include <ctime>
#include "figura_geo.hh"

/**
 * \brief Klasa pochodna figury geometrycznej, modeluje pojecie przeszkody
 **/
class Przeszkoda : public Figura_geo
{
    private:
    /**
     * \brief Wektor translacji przeszkody w ukladzie globalnym
     **/
    Wektor3D translacja;

    public:
    /**
     * \brief Konstruktor parametryczny przeszkody, losuje przeszkode oraz losuje jej docelowe miejsce
     * \param[in] trans - obecne polozenie drona
     **/
    Przeszkoda(Wektor3D trans);

    /**
     * \brief Przeciazenie operatora [] pozwalajace na dostep do wektora translacji przeszkody
     * \param[in] size - element wektora translacji
     * \return Element size wektora translacji
     **/
    double & operator [] (unsigned int size) {return translacja[size];}

    /**
     * \brief Przeciazenie operatora [] pozwalajace na dostep do wektora translacji przeszkody
     * \param[in] size - element wektora translacji
     * \return Element size wektora translacji
     **/
    double operator [] (unsigned int size) const {return translacja[size];}

    /**
     * \brief Funkcja realizujaca sprawdzanie czy przeszkoda zawiera sie w zakresie sceny
     * \param[in] trans - wektor translacji sceny
     * \return Wartosc logiczna polozenia przeszkody w scenie
     **/
    bool czy_w_zakresie(Wektor3D trans);
};

/**
 * \brief Przeciazenie operatora == realizujace porownanie dwoch przeszkod 
 * \param[in] prze1 - przeszkoda nr 1
 * \param[in] prze2 - przeszkoda nr 2
 * \return Wartosc logiczna porownania dwoch przeszkod
 **/
bool operator == (const Przeszkoda prze1, const Przeszkoda prze2);

/**
 * \brief Przeciazenie operatora wypisania przeszkody na strumine wyjsciowy
 * \param[in] Strm - strumien wyjsciowy
 * \return Strumien wyjsciowy
 **/
std::ostream & operator << (std::ostream & Strm, Przeszkoda & tab);

#endif