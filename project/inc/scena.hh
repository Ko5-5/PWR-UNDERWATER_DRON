#ifndef SCENA_HH
#define SCENA_HH

#include <fstream>
#include <list>
#include <memory>
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
    /**
     * \brief Pole zawierajace wskaznik na obiekt dna
     **/
    Dno * dno_obj;
    /**
     * \brief Pole zawierajace wskaznik na obiekt wody
     **/
    Woda * woda_obj;
    /**
     * \brief Pole zawierajace obiekt drona
     **/
    Dron dron_obj;
    /**
     * \brief Pole zawierajace tablice wskaznikow na przeszkody
     **/
    std::vector<Przeszkoda*> tab_przeszkod;

    public:
    /**
     * \brief Konstruktor parametryczny Sceny
     * \param[in] x_0 - poczatek zakresu x
     * \param[in] x - koniec zakresu x
     * \param[in] y_0 - poczatek zakresu y
     * \param[in] y - koniec zakresu y
     **/
    Scena(int x_0, int x, int y_0, int y);

    /**
     * \brief Konstruktor kopiujacy Sceny
     * \param[in] kopia - objekt sceny bedacy kopiowany
     **/
    Scena(Scena & kopia) {dno_obj = new Dno(0,0,0,0), woda_obj = new Woda(0,0,0,0), dron_obj = kopia(); tab_przeszkod = kopia[PRZESZKODY];}

    /**
     * \brief Przeciazenie operatora () pozwalajacy na dostep do obiektu drona
     * \return Obiekt drona
     **/
    Dron & operator () () {return dron_obj;}

    /**
     * \brief Przeciazenie [] pozwalajace na dostep do tablicy przeszkod
     * \param[in] size - zmienna
     * \return Tablica vector przeszkod
     **/
    std::vector<Przeszkoda*> & operator [] (unsigned int size) {return tab_przeszkod;}

    /**
     * \brief Destruktor sceny
     **/
    ~Scena() {delete dno_obj; delete woda_obj;};

    /**
     * \brief Realizuje generowanie sceny wraz z ruchem drona
     **/
    void generuj_dno_woda();

    /**
     * \brief Realizuje generowanie przeszkod na obecnej scenie, zachowuje stala ilosc przeszkod na scenie
     * \param[in] ilosc - zadana ilosc przeszkod na scenie
     **/
    void generuj_przeszkody(int ilosc);

    /**
     * \brief Realizuje sprawdzenie czy nie nastapila kolizja drona z woda, dnem lub przeszkoda
     * \return Typ kolizji
     **/
    int czy_kolizja();

    /**
     * \brief Realizuje zapis sceny do podanego strumienia plikowego
     * \param[in] plik_wyj - strumien plikowy zapisu
     * \return Wartosc logiczna bool powodzenia operacji zapisu do pliku
     **/
    bool zapisz_plik(std::ofstream & plik_wyj);
};

#endif
