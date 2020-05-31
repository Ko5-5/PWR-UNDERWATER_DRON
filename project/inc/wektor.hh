#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <type_traits>

/**
 * \brief Klasa modelujaca pojecie wektora przy pomocy tablicy jednowymiarowej, podstawa budowy pojecia macierzy i ukladu rownan
 **/
template <typename Type, int Size>
class Wektor
{
    private:
    Type tab_wartosci[Size];

    public:
    /** 
     * \brief Konstruktor tworzacy wektor wypelniony zerami
     **/
    Wektor() {for(Type &Elem:tab_wartosci) Elem=0;}

    /**
     * \brief Przeciazenie [] ulatwiajace dostep do wektora
     * \param[in] pos - parametr przeciazenia
     * \return Wartosc z wektora
     **/
    Type operator [] (unsigned int pos) const { return tab_wartosci[pos];}

    /**
     * \brief Przeciazenie const [] ulatwiajace dostep do wektora
     * \param[in] pos - parametr przeciazenia
     * \return Wartosc z wektora
     **/
    Type & operator [] (unsigned int pos) { return tab_wartosci[pos];}

    /**
     * \brief Przeciazenie operatora mnozenia wektora przez liczbe (liczba z prawej strony wektora)
     * \param[in] mnoz - liczba rzeczywista przez ktora bedzie mnozony wektor
     * \return Wektor wynikowy operacji mnozenia
     **/
    Wektor<Type,Size> operator * (const Type mnoz);

    /**
     * \brief Przeciazenie operatora dzielenie wektora przez liczbe
     * \param[in] dziel - liczba rzeczywista przez ktora bedzie dzielony wektor
     * \return Wektor wynikowy operacji dzielenia
     **/
    Wektor<Type,Size> operator / (const Type dziel);

    /**
     * \brief Przeciazenie operatora + dla dodawania wektorow 
     * \param[in] Arg - wektor
     * \return Wektor wynikowy operacji dodawania
     **/
    Wektor<Type,Size> operator + (const Wektor<Type,Size> &Arg);

    /**
     * \brief Przeciazenie operatora - dla odejmowania wektorow 
     * \param[in] Arg - wektor
     * \return Wektor wynikowy operacji odejmowania
     **/
    Wektor<Type,Size> operator - (const Wektor<Type,Size> &Arg) const;

    /**
     * \brief Przeciazenie operatora * dla mnozenia wektorow 
     * \param[in] Arg - wektor
     * \return Wektor wynikowy operacji mnozenia
     **/
    Type operator * (const Wektor<Type,Size> &Arg);

    /**
     * \brief Realizuje wyliczenie dlugosci wektora dla typu double
     * \return Dlugosc wektora
     **/
    Type dlug_wek()
    {
        return sqrt((*this) * (*this));
    }
};

template <typename Type, int Size>
Wektor<Type,Size> Wektor<Type,Size>::operator * (const Type mnoz)
{
    Wektor<Type,Size> wynik;
    for(int i=0; i<Size; i++)
    {
        wynik[i] = tab_wartosci[i] * mnoz;
    } 
    return wynik;
}

template <typename Type, int Size>
Wektor<Type,Size> Wektor<Type,Size>::operator / (const Type dziel)
{
    Wektor<Type,Size> wynik;
    for(int i=0; i<Size; i++)
    {
        wynik[i] = tab_wartosci[i] / dziel;
    } 
    return wynik;
}

template <typename Type, int Size>
Wektor<Type,Size> Wektor<Type,Size>::operator + (const Wektor<Type,Size> &Arg)
{
    Wektor<Type,Size> wynik;
    for(int i=0; i<Size; i++)
    {
        wynik[i] = tab_wartosci[i] + Arg[i];
    } 
    return wynik;
}

template <typename Type, int Size>
Wektor<Type,Size> Wektor<Type,Size>::operator - (const Wektor<Type,Size> &Arg) const
{
    Wektor<Type,Size> wynik;
    for(int i=0; i<Size; i++)
    {
        wynik[i] = tab_wartosci[i] - Arg[i];
    } 
    return wynik;
}

template <typename Type, int Size>
Type Wektor<Type,Size>::operator * (const Wektor<Type,Size> &Arg)
{
    Type wynik;
    for(int i=0; i<Size; i++)
    {
        wynik = wynik + tab_wartosci[i] * Arg[i];
    } 
    return wynik;
}

/**
 * \brief Przeciazenie wypisania wektora na strumien
 * \param[in] strm - strumien wyjsciowy 
 * \param[in] Wek - wektor ktory zostanie wypisany 
 * \return Strumien wypisania
 **/
template <typename Type, int Size>
std::ostream & operator << (std::ostream &strm, const Wektor<Type,Size> &Wek)
{
    for(int i=0; i<Size; i++)
    {
        strm << " " << Wek[i];
    }
    return strm;
}

/**
 * \brief Przeciazenie realizujace wczytanie wektora z strumienia (utworzone w celu testow)
 * \param[in] strm - strumien wejciowy
 * \param[in] Wek - wektor do ktorego nastapi wczytanie
 * \return Strumien wczytania
 **/
template <typename Type, int Size>
std::istream & operator >> (std::istream &strm, Wektor<Type,Size> &Wek)
{
    for(int i=0; i<Size; i++)
    {
        strm >> Wek[i];

        if(strm.fail())
        {
            std::cerr << "Blad wczytywania" << std::endl;
            return strm;
        }
    }
    return strm;
}

#endif
