#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include <iostream>
#include <vector>
#include "wektor3D.hh"
#include "stale_wartosci.h"

/**
 * \brief Bazowa klasa realizujaca pojecie powierzchni posiadajacej dynamiczna tablice wektorow 3D
 **/
class Powierzchnia
{
    public:
    std::vector<Wektor3D> tablica;

    /**
     * \brief Przeciazenie operatora [] pozwalajace na dostep do wektorow w tablicy
     * \param[in] size - liczba wskazujaca na element tablicy
     * \return Wybrany wektor 3D
     **/
    Wektor3D operator [] (unsigned int size) const {return tablica[size];}

    /**
     * \brief Przeciazenie operatora [] pozwalajace na dostep do wektorow w tablicy
     * \param[in] size - liczba wskazujaca na element tablicy
     * \return Wybrany wektor 3D
     **/
    Wektor3D & operator [] (unsigned int size) {return tablica[size];}

    /**
     * \brief Przeciazenie operatora () pozwalajace na dostep do wartosci double w podanym wektorze tablicy wektorow 
     * \param[in] size1 - liczba wskazujaca na dany wektor z tablicy
     * \param[in] size2 - liczba wskazujaca na dany element z wektora
     * \return Wybrana wartosc double z danego wektora 3D
     **/
    double operator () (unsigned int size1, unsigned int size2) const {return tablica[size1][size2];}

    /**
     * \brief Przeciazenie operatora () pozwalajace na dostep do wartosci double w podanym wektorze tablicy wektorow 
     * \param[in] size1 - liczba wskazujaca na dany wektor z tablicy
     * \param[in] size2 - liczba wskazujaca na dany element z wektora
     * \return Wybrana wartosc double z danego wektora 3D
     **/
    double & operator () (unsigned int size1, unsigned int size2) {return tablica[size1][size2];}

    /**
     * \brief Funkcja realizujaca ukazanie wielkosci tablicy wektorow
     * \return Wielkosc tablicy
     **/
    int size () {return tablica.size();}

    /**
     * \brief Funkcja realizujaca ukazanie wielkosci tablicy wektorow
     * \return Wielkosc tablicy
     **/
    int size () const {return tablica.size();}
};

/**
 * \brief Przeciazenie operatora << dla wypisania powierzchni na strumien wyjsciowy
 * \param[in] Strm - strumien wyjsciowy
 * \param[in] tab - powierzchnia do wyswietlenia
 * \return Strumien wyjsciowy
 **/
std::ostream & operator << (std::ostream & Strm, const Powierzchnia & tab);

#endif
