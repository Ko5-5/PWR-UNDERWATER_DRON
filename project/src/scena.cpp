#include "scena.hh"

Scena::Scena(int x_0, int x, int y_0, int y) 
{
    dno_obj = new Dno(x_0,x,y_0,y); 
    woda_obj = new Woda(x_0,x,y_0,y);
    ifstream plik_wej;
    plik_wej.open("bryly/dron-lok.dat");
    dron_obj = Dron(plik_wej);
    plik_wej.close();
}

void Scena::generuj_dno_woda(int x_0, int x, int y_0, int y)
{
    delete dno_obj;
    delete woda_obj;
    dno_obj = new Dno(x_0,x,y_0,y); 
    woda_obj = new Woda(x_0,x,y_0,y);
}


bool Scena::zapisz_plik(std::ofstream & plik_wyj)
{
    bool wynik = true;

    plik_wyj << *dno_obj;
    if(plik_wyj.fail())
    {
        wynik = false;
        std::cerr << "Blad zapisu obiektu dno do pliku" << std::endl;
    }
    plik_wyj << *woda_obj;
    if(plik_wyj.fail())
    {
        wynik = false;
        std::cerr << "Blad zapisu obiektu woda do pliku" << std::endl;
    }
    dron_obj.zapisz_plik(plik_wyj);
    
    return wynik;
}
