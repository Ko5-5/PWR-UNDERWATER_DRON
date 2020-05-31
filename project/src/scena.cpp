#include "scena.hh"

bool Scena::zapisz_plik(std::ofstream & plik_wyj)
{
    bool wynik = true;

    plik_wyj << *dno_wartosci;
    if(plik_wyj.fail())
    {
        wynik = false;
        std::cerr << "Blad zapisu obiektu dno do pliku" << std::endl;
    }
    plik_wyj << *woda_wartosci;
    if(plik_wyj.fail())
    {
        wynik = false;
        std::cerr << "Blad zapisu obiektu woda do pliku" << std::endl;
    }
    
    return wynik;
}
