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

void Scena::generuj_dno_woda()
{
    delete dno_obj;
    delete woda_obj;
    dno_obj = new Dno(dron_obj[X]-OTOCZENIE_DRONA,dron_obj[X]+OTOCZENIE_DRONA,dron_obj[Y]-OTOCZENIE_DRONA,dron_obj[Y]+OTOCZENIE_DRONA); 
    woda_obj = new Woda(dron_obj[X]-OTOCZENIE_DRONA,dron_obj[X]+OTOCZENIE_DRONA,dron_obj[Y]-OTOCZENIE_DRONA,dron_obj[Y]+OTOCZENIE_DRONA); 
}

void Scena::generuj_przeszkody()
{
    while(tab_przeszkod.size()<5)
    {
        tab_przeszkod.push_back(Przeszkoda(dron_obj.translacja_wek()));
    }
    for(Przeszkoda temp : tab_przeszkod)
    {
        if(temp.czy_w_zakresie(dron_obj.translacja_wek()))
        {
            tab_przeszkod.remove(temp);
        }
    }
    while(tab_przeszkod.size()<5)
    {
        tab_przeszkod.push_back(Przeszkoda(dron_obj.translacja_wek()));
    }
}

int Scena::czy_kolizja()
{
    //Kolizja z dnem
    if((*this)()[Z]-12 <= POZ_DNA)
    {
        return KOLIZJA_DNO;
    }

    //Kolizja z woda
    if((*this)()[Z]+10 >= POZ_WOD-1)
    {
        return KOLIZJA_WODA;
    }
    /*
    //Kolizja przeszkody
    Wektor3D rog_gora = Wektor3D((*this)()[X]+10, (*this)()[Y]+10, (*this)()[Z]+10);
    Wektor3D rog_dol = Wektor3D((*this)()[X]-10, (*this)()[Y]-12, (*this)()[Z]-12);
    for(Figura_geo przeszkoda : tab_przeszkod)
    {
        for(Wektor3D wektor
        {

        }
    }
    */
   return BRAK_KOLIZJI;
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
    plik_wyj << dron_obj;
    if (plik_wyj.fail())
    {
        wynik = false;
        std::cerr << "Blad zapisu obiektu dron do pliku" << std::endl;
    }
    for(Przeszkoda temp : tab_przeszkod)
    {
        plik_wyj << temp;
        if (plik_wyj.fail())
        {
            wynik = false;
            std::cerr << "Blad zapisu przeszkody do pliku" << std::endl;
        }
    }


    
    return wynik;
}
