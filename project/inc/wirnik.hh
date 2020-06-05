#ifndef WIRNIK_HH
#define WIRNIK_HH

#include <iostream>
#include <fstream>
#include "figura_geo.hh"

/**
 * \brief Klasa modelujaca pojecie wirnika wirnika
 **/
class Wirnik : public Figura_geo
{
    private:
    /**
     * \brief Pole wektora translacji wirnika w ukladzie lokalnym wirnika
     **/
    Wektor3D translacja_lok_dron = Wektor3D(0,-6,-5);
    /**
     * \brief Pole modelujace obecny kat obrotu wirnika
     **/
    double kat = 0.00;

    public:
    /**
     * \brief Konstruktor bezparametryczny wirnika
     **/
    Wirnik() {};
    /**
     * \brief Konstruktor parametryczny wirnika 
     * \param[in] plik_wej - plik ukladu lokalnego wirnika
     * \param[in] poz - pozycja wirnika (prawy lub lewy)
     **/
    Wirnik(std::ifstream & plik_wej, int poz);
    /**
     * \brief Konstruktor kopiujacy wirnika
     * \param[in] wir - wirnik do skopiowania
     * \param[in] pos - pozycja wirnika (prawy lub lewy)
     **/
    Wirnik(Wirnik & wir, int pos);

    /**
     * \brief Przeciazenie operatora [] pozwalajace na dostep do skladowych wektora translacji oraz kata obrotu wirnika
     * \param[in] size - zmienna pozycji 
     * \return Wartosc skladowej wektora translacji lub kata obrotu wirnika
     **/
    double & operator [] (unsigned int size) {if(size<4) return translacja_lok_dron[size]; else return kat;}
    /**
     * \brief Przeciazenie operatora [] pozwalajace na dostep do skladowych wektora translacji oraz kata obrotu wirnika
     * \param[in] size - zmienna pozycji 
     * \return Wartosc skladowej wektora translacji lub kata obrotu wirnika
     **/
    double operator [] (unsigned int size) const {if(size<4) return translacja_lok_dron[size]; else return kat;}

    /**
     * \brief Funkcja pozwalajaca na dostep do wektora translacji lok wirnika 
     * \return Wektor translacji lok wirnika 
     **/
    Wektor3D & translacja() {return translacja_lok_dron;}
    /**
     * \brief Funkcja pozwalajace na dostep do wektora translacji lok wirnika 
     * \return Wektor translacji lok wirnika 
     **/
    Wektor3D translacja () const {return translacja_lok_dron;}

    /**
     * \brief Funkcja pozwalajace na dostep do ukladu lokalnego wirnika
     * \return Uklad lokalny wirnika
     **/
    std::vector<Wektor3D> & uk_lok() {return tablica;}
    /**
     * \brief Funkcja pozwalajace na dostep do ukladu lokalnego wirnika
     * \return Uklad lokalny wirnika
     **/
    std::vector<Wektor3D> uk_lok() const {return tablica;}

    /**
     * \brief Funkcja pozwalajace na dostep do ukladu globalnego wirnika
     * \return Uklad globalny wirnika
     **/
    std::vector<Wektor3D> & uk_glob() {return tablica_glob;}
    /**
     * \brief Funkcja pozwalajace na dostep do ukladu globalnego wirnika
     * \return Uklad globalny wirnika
     **/
    std::vector<Wektor3D> uk_glob() const {return tablica_glob;}

    /**
     * \brief Funkcja pozwalajace na obrot wirnika w lewo
     **/
    void obrot_lewa(double kat);

    /**
     * \brief Funkcja pozwalajace na obrot wirnika w prawo
     **/
    void obrot_prawa(double kat);
};

/**
 * \brief Przeciazenie operatora << pozwalajace na wypisanie wirnika na strumien wyjsciowy
 * \param[in] Strm - strumien wyjsciowy
 * \param[in] tab - wirnik do wypisania
 * \return Strumine wyjsciowy
 **/
std::ostream & operator << (std::ostream & Strm, Wirnik & tab);

#endif
