#ifndef DRON_HH
#define DRON_HH

#include <cmath>
#include <ostream>
#include <fstream>
#include "figura_geo.hh"
#include "macierz3D.hh"
#include "wirnik.hh"

/**
 * \brief Klasa pochodna figury geometrycznej realizujaca modelowanie drona
 **/
class Dron : public Figura_geo
{
    private:
    /**
     * \brief Pole translacji z ukladu lokalnego do globalnego
     **/
    Wektor3D translacja = Wektor3D(35,35,-50);
    /**
     * \brief Pole obrotu drona wzgledem oryginalnego polozenia
     **/
    double obrot = 0.00;

    Wirnik wir_prawy, wir_lewy;

    public:
    Dron():Figura_geo() {};

    /**
     * \brief Konstruktor parametryczny Drona, bierze plik z wsp lokalnymi i zapisuje do tablicy lokalnej
     * \param[in] plik_wej - strumien plikowy wczytywania drona w ukladzie lokalnym
     **/
    Dron(std::ifstream & plik_wej):Figura_geo(plik_wej)
    {
        Wektor3D temp = Wektor3D(0,0,0);
        if(plik_wej.good())
        { 
            while(!plik_wej.eof())
            {
                plik_wej >> temp;
                tablica.push_back(temp);
            }
        }

        std::ifstream plik_wir;
        plik_wir.open("bryly/wirniki-dron-lok1.dat");
        wir_lewy = Wirnik(plik_wir,LEWY);
        plik_wir.close();
        plik_wir.open("bryly/wirniki-dron-lok2.dat");
        wir_prawy = Wirnik(plik_wir,PRAWY);
        plik_wir.close();
    }

    /**
     * \brief Przeciazenie operatora dostepu do translacji drona
     * \param[in] size - zadane pole
     * \return Zadane pole translacji drona
     **/
    double & operator [] (unsigned int size) {return translacja[size];}

    /**
     * \brief Przeciazenie operatora dostepu do translacji drona
     * \param[in] size - zadane pole
     * \return Zadane pole translacji drona
     **/
    double operator [] (unsigned int size) const {return translacja[size];}

    Wirnik & operator () (unsigned int size) {if(size==LEWY) return wir_lewy; else return wir_prawy;}

    Wirnik operator () (unsigned int size) const {if(size==LEWY) return wir_lewy; else return wir_prawy;}

    /**
     * \brief Realizuje translacje ukladu lokalnego do globalnego
     **/
    void translacja_glob();

    /** 
     * \brief Realizuje zapis ruchu drona do przodu
     * \param[in] il_krok - wielkosci ruchu
     * \param[in] kat - kat wznoszenia
     **/
    void ruch_przod_kat(int il_krok, double kat);

    /**
     * \brief Realizuje obrot drona wokol osi
     * \param[in] os - os obrotu
     * \param[in] kat - kat obrotu
     **/
    void obrot_kat(int kat);

};

std::ostream & operator << (std::ostream & strm, Dron & tab);

#endif
