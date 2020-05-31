#ifndef DNO_HH
#define DNO_HH

#include "powierzchnia.hh"

using namespace std;

/**
 * \brief Pochodna klasa powierzchni, realizujaca modelowanie dna
 **/
class Dno : public Powierzchnia
{
    public:
    /**
     * \brief Konstruktor parametryczny Dna, podaje do tablicy wektory 3D w podanym zakresie 
     * \param[in] x_0 - poczatek zakresu x
     * \param[in] x - koniec zakresu x
     * \param[in] y_0 - poczatek zakresu y
     * \param[in] y - koniec zakresu y
     **/
    Dno(int x_0, int x, int y_0, int y);
};

#endif
