#ifndef SCENA_HH
#define SCENA_HH

#include <fstream>
#include <list>
#include "dno.hh"
#include "woda.hh"
#include "dron.hh"
#include "przeszkoda.hh"

/**
 * \brief Klasa realizujaca pojecie sceny, zawiera w sobie Dno oraz Wode
 **/
class Scena
{
    private:
    Dno * dno_obj;
    Woda * woda_obj;
    Dron dron_obj;
    std::list<Przeszkoda> tab_przeszkod;

    public:
    /**
     * \brief Konstruktor parametryczny Sceny
     * \param[in] x_0 - poczatek zakresu x
     * \param[in] x - koniec zakresu x
     * \param[in] y_0 - poczatek zakresu y
     * \param[in] y - koniec zakresu y
     **/
    Scena(int x_0, int x, int y_0, int y);

    Scena(Scena & kopia) {dno_obj = new Dno(0,0,0,0), woda_obj = new Woda(0,0,0,0), dron_obj = kopia(); tab_przeszkod = kopia[PRZESZKODY];}

    Dron & operator () () {return dron_obj;}

    std::list<Przeszkoda> & operator [] (unsigned int size) {return tab_przeszkod;}

    /**
     * \brief Destruktor sceny
     **/
    ~Scena() {delete dno_obj; delete woda_obj;};

    void generuj_dno_woda();

    int generuj_przeszkody();

    int czy_kolizja();

    /**
     * \brief Realizuje zapis sceny do podanego strumienia plikowego
     * \param[in] plik_wyj - strumien plikowy zapisu
     * \return Wartosc logiczna bool powodzenia operacji zapisu do pliku
     **/
    bool zapisz_plik(std::ofstream & plik_wyj);
};



#endif
