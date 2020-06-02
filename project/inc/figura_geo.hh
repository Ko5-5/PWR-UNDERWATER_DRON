#ifndef FIGURA_HH
#define FIGURA_HH

#include <fstream>
#include "powierzchnia.hh"

/**
 * \brief Klasa pochodna powierzchni, realizujaca modelowanie figury geometrycznej
 **/
class Figura_geo : public Powierzchnia
{
    public:
    std::vector<Wektor3D> tablica_glob;

    Figura_geo() {};

    /**
     * \brief Konstruktor parametryczny figury geometrycznej
     * \param[in] plik_wej - plik ukladu lokalnego figury geometrycznej
     **/
    Figura_geo(std::ifstream & plik_wej);

    /**
     * \brief Realizuje zapis figury do podanego strumienia plikowego
     * \param[in] plik_wyj - strumine plikowy
     * \return Wartosc logiczna powodzenia zapisania figury
     **/
    bool zapisz_plik(std::ostream & plik_wyj); 
};

#endif
