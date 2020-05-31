#ifndef DRON_HH
#define DRON_HH

#include <cmath>
#include "figura_geo.hh"
#include "macierz3D.hh"

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
    Wektor3D obrot_kat = Wektor3D(0,0,0);

    public:
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
    void obrot_os_kat(int os, double kat);

};

#endif
