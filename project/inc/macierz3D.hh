#ifndef MACIERZ3D_HH
#define MACIERZ3D_HH

#include "macierz.hh"
#include "wektor3D.hh"

/**
 * \brief Klasa pochodna macierzy, realizuje Macierz 3D
 **/
class Macierz3D : public Macierz<double,3>
{
    public:
    /**
     * \brief Konstruktor bezparametryczny Macierzy 3D
     **/
    Macierz3D();

    /**
     * \brief Konstruktor parametryczny
     * \param[in] pos_0 - wektor tworzacy macierz 1
     * \param[in] pos_1 - wektor tworzacy macierz 2
     * \param[in] pos_2 - wektor tworzacy macierz 3
     **/
    Macierz3D(Wektor3D pos_0, Wektor3D pos_1, Wektor3D pos_2);

    /**
     * \brief Przeciazenie operatora mnozenia Macierzy 3D przez Wektor 3D
     * \param[in] wek - wektor przez ktory sie mnozy
     * \return Wektor bedacy iloczynem macierzy i wektora
     **/
    Wektor3D operator * (Wektor3D & wek);
};

#endif
