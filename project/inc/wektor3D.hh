#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include <iostream>
#include "stale_wartosci.h"
#include "wektor.hh"

/**
 * \brief Klasa pochodna klasy Wektor realizujaca pojecie Wektora3D
 **/
class Wektor3D: public Wektor<double,3>
{
    private:

    /**
     * \brief Pole statyczne zawierajca ogolna ilosc utworzonych wektorow 3D
     **/
    static int lacznie_wek;

    /**
     * \brief Pole statyczne zawierajca ogolna ilosc zniszczonych wektorow 3D
     **/
    static int zniszcz_wek;

    public:

    /**
     * \brief Realizuje wypisanie pola statycznego ilosci utworzonych wektorow 3D
     **/
    int Pokaz_Wek_lacznie() const {return this->lacznie_wek;}

    /**
     * \brief Realizuje wypisanie aktualnej ilosci wektorow 3D na ekranie
     **/
    int Pokaz_wek_teraz() const {return this->lacznie_wek - this->zniszcz_wek;}

    /**
     * \brief Konstruktor bezparametryczny wektora 3D
     **/
    Wektor3D() {lacznie_wek++;}

    /**
     * \brief Destruktor wektora 3D
     **/
    ~Wektor3D() {zniszcz_wek++;}

    /**
     * \brief Konstruktor parametryczny wektora 3D
     * \param[in] x - wartosc x wektora 3D
     * \param[in] y - wartosc y wektora 3D
     * \param[in] z - wartosc z wektora 3D
     **/
    Wektor3D(double x, double y, double z) {(*this)[X]=x; (*this)[Y]=y; (*this)[Z]=z; lacznie_wek++;}

    /**
     * \brief Konstruktor kopiujacy wektora 3D, potrzebny do vector<>.push_back
     * \param[in] wek - wektor ktory zostanie skopiowany
     **/
    Wektor3D(Wektor3D & wek) {(*this)=wek; lacznie_wek++;}

    /**
     * \brief Konstruktor kopiujacy wektora 3D
     * \param[in] wek - wektor ktory zostanie skopiowany
     **/
    Wektor3D(const Wektor3D & wek) {(*this)=wek; lacznie_wek++;}

    /**
     * \brief Konstruktor kopiujacy wektora 3D
     * \param[in] wek - wektor ktory zostanie skopiowany
     **/
    Wektor3D(const Wektor<double,3> & wek) {(*this)=wek; lacznie_wek++;}

    /**
     * \brief Przeciazenie operatora dodawania wektorow 3D
     * \param[in] wek - wektor ktory ma zostac dodany
     * \return Wektor wynikowy dodawania
     **/
    Wektor3D operator + (Wektor3D wek);
};

#endif
