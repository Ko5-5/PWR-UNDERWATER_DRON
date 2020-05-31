#ifndef SCENA_HH
#define SCENA_HH

#include <fstream>
#include "dno.hh"
#include "woda.hh"

/**
 * \brief Klasa realizujaca pojecie sceny, zawiera w sobie Dno oraz Wode
 **/
class Scena
{
    private:
    Dno * dno_wartosci;
    Woda * woda_wartosci;

    public:
    /**
     * \brief Konstruktor parametryczny Sceny
     * \param[in] x_0 - poczatek zakresu x
     * \param[in] x - koniec zakresu x
     * \param[in] y_0 - poczatek zakresu y
     * \param[in] y - koniec zakresu y
     **/
    Scena(int x_0, int x, int y_0, int y) {dno_wartosci = new Dno(x_0,x,y_0,y); woda_wartosci = new Woda(x_0,x,y_0,y);}

    /**
     * \brief Destruktor sceny
     **/
    ~Scena() {delete dno_wartosci; delete woda_wartosci;};

    /**
     * \brief Realizuje zapis sceny do podanego strumienia plikowego
     * \param[in] plik_wyj - strumien plikowy zapisu
     * \return Wartosci logiczna bool powodzenia operacji zapisu do pliku
     **/
    bool zapisz_plik(std::ofstream & plik_wyj);
};



#endif
