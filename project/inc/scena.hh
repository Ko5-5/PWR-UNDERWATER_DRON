#ifndef SCENA_HH
#define SCENA_HH

#include <fstream>
#include "dno.hh"
#include "woda.hh"
#include "dron.hh"

/**
 * \brief Klasa realizujaca pojecie sceny, zawiera w sobie Dno oraz Wode
 **/
class Scena
{
    private:
    Dno * dno_obj;
    Woda * woda_obj;
    Dron dron_obj;

    public:
    /**
     * \brief Konstruktor parametryczny Sceny
     * \param[in] x_0 - poczatek zakresu x
     * \param[in] x - koniec zakresu x
     * \param[in] y_0 - poczatek zakresu y
     * \param[in] y - koniec zakresu y
     **/
    Scena(int x_0, int x, int y_0, int y);

    Dron & operator () () {return dron_obj;}
    /**
     * \brief Destruktor sceny
     **/
    ~Scena() {delete dno_obj; delete woda_obj;};

    void generuj_dno_woda(int x_0, int x, int y_0, int y);

    /**
     * \brief Realizuje zapis sceny do podanego strumienia plikowego
     * \param[in] plik_wyj - strumien plikowy zapisu
     * \return Wartosc logiczna bool powodzenia operacji zapisu do pliku
     **/
    bool zapisz_plik(std::ofstream & plik_wyj);
};



#endif
