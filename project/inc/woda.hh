#ifndef WODA_HH
#define WODA_HH

#include "powierzchnia.hh"

/**
 * \brief Pochodna klasa powierzchni, realizujaca modelowanie wody
 **/
class Woda : public Powierzchnia
{
    public:
    /**
     * \brief Konstruktor parametryczny Wody, podaje do tablicy wektory 3D w podanym zakresie 
     * \param[in] x_0 - poczatek zakresu x
     * \param[in] x - koniec zakresu x
     * \param[in] y_0 - poczatek zakresu y
     * \param[in] y - koniec zakresu y
     **/
    Woda(int x_0, int x, int y_0, int y);
};

#endif
