#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "wektor.hh"

/**
 * \brief Szablon Klasy modelujacej pojecie macierzy, za budowe kolumn macierzy odpowiadaja poszczegolne wektor co ulatwia dalsze obliczenia
 **/
template<typename Type, int Size>
class Macierz
{
    private:
    Wektor<Type,Size> tab_wartosci[Size];

    public:
    /** 
     * \brief Konstruktor tworzacy macierz wypelniona zerami
     **/
    Macierz() {for(Wektor<Type,Size> &tab : tab_wartosci) tab = Wektor<Type,Size>();}

    /**
     * \brief Realizuje ulatwienie dostepu do elementow macierzy
     * \param[in] pos_1 - parametr pozycji 1
     * \param[in] pos_2 - parametr pozycji 2
     * \return Element z macierzy
     **/
    Type operator () (unsigned int pos_1, unsigned int pos_2) const {return tab_wartosci[pos_1][pos_2];};

    /**
     * \brief Realizuje ulatwienie dostepu do elementow macierzy
     * \param[in] pos_1 - parametr pozycji 1
     * \param[in] pos_2 - parametr pozycji 2
     * \return Element z macierzy
     **/
    Type & operator () (unsigned int pos_1, unsigned int pos_2) {return tab_wartosci[pos_1][pos_2];};

    /**
     * \brief Przeciazenie [] ulatwiajace dostep do macierzy
     * \param[in] pos - parametr przeciazenia 
     * \return Zwraca wektor odpowiedzialny za budowe wybranego wiersza
     **/
    Wektor<Type,Size> operator [] (unsigned int pos) const { return tab_wartosci[pos];}

    /**
     * \brief Przeciazenie const [] ulatwiajace dostep do macierzy
     * \param[in] pos - parametr przeciazenia 
     * \return Zwraca wektor odpowiedzialny za budowe wybranego wiersza
     **/
    Wektor<Type,Size> & operator [] (unsigned int pos) { return tab_wartosci[pos];}

    /**
     * \brief Realizuje wyliczenie wyznacznika macierzy metoda eliminacji Gaussa, sprowadzamy do macierzy digonalnej, a wyznacznik to iloczyn elementow na przekatnej
     * \return Wartosc wyznacznika
     **/
    Type wyznacznik() const;

    /**
     * \brief Przeciazenie operatora mnozenia macierzy przez wektor (wektor po prawej stronie macierzy)
     * \param[in] wek - wektor przez ktory mnozymy 
     * \return Wektor wynikowy operacji mnozenia
     **/
    Wektor<Type,Size> operator * (const Wektor<Type,Size> &wek) const;
};

template<typename Type, int Size>
Type Macierz<Type,Size>::wyznacznik() const
{
    Type wynik;
    Macierz<Type,Size> macierz_temp = *this;
    Type temp;

    for(int i=1; i<Size; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(macierz_temp[i][j]==0)
            {
                continue;
            }
            else
            {
                temp = macierz_temp[i][j] / macierz_temp[j][j];
                macierz_temp[i] = macierz_temp[i] - macierz_temp[j] * temp;
            }
        }
    }

    wynik = macierz_temp(0,0);

    for(int i=1; i<Size; i++) 
    {
        wynik = wynik * macierz_temp[i][i];
    }

    return wynik;
}

template<typename Type, int Size>
Wektor<Type,Size> Macierz<Type,Size>::operator * (const Wektor<Type,Size> &wek) const
{
    Wektor<Type,Size> temp = Wektor<Type,Size>();

    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            temp[i] = temp[i] + tab_wartosci[i][j] * wek[j];
        }
    }
    return temp;
}

/**
 * \brief Realizuje wypisywanie macierzy na podany strumien
 * \param[in] strm - strumien wyjsciowy
 * \param[in] Mac - objekt macierzy ktory zostanie wypisany
 * \return Strumien wyjsciowy
 **/
template<typename Type, int Size>
std::ostream & operator << (std::ostream &strm, const Macierz<Type,Size> &Mac)
{
    for(int i=0; i<Size; i++)
    {
        strm << " | ";
        for(int j=0; j<Size; j++)
        {
            strm << " " << Mac(i,j) << " "; 
        }
        strm << " | " << std::endl;
    }
    return strm;
}

/**
 * \brief Realizuje wczytywanie macierzy z podanego strumienia (w celu testow)
 * \param[in] strm - strumien wejsciowy
 * \param[in] Mac - objekt macierzy do ktorego nastapi wczytywanie
 * \return Strumien wejsciowy
 **/
template<typename Type, int Size>
std::istream & operator >> (std::istream &strm, Macierz<Type,Size> &Mac)
{
    Type test[Size][Size];

    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++)
        {
            strm >> test[j][i];

            if(strm.fail())
            {
                return strm;
            }
        }
    }

    for(int i=0; i<Size; i++)
    {
        for(int j=0; j<Size; j++) Mac(i,j)=test[i][j];
    }
    return strm;
}

#endif
