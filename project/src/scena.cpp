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

void Scena::generuj_przeszkody(int ilosc)
{
    while(tab_przeszkod.size()<ilosc)
    {
        tab_przeszkod.push_back(new Przeszkoda(dron_obj.translacja_wek()));
    }
    for(int i=0; i<tab_przeszkod.size(); i++)
    {
        if(!tab_przeszkod[i]->czy_w_zakresie(dron_obj.translacja_wek()))
        {
            delete tab_przeszkod[i];
            tab_przeszkod[i] = new Przeszkoda(dron_obj.translacja_wek());
        }
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
    Wektor3D rog_gora = dron_obj.maks_wek();
    Wektor3D rog_dol = dron_obj.min_wek();
    Wektor3D temp_gora, temp_dol;
    for(Przeszkoda przeszkoda : tab_przeszkod)
    {
        temp_gora = przeszkoda.maks_wek();
        temp_dol = przeszkoda.min_wek();

        if(rog_gora)
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
    for(int i=0; i<tab_przeszkod.size(); i++)
    {
        plik_wyj << (*tab_przeszkod[i]);
        if (plik_wyj.fail())
        {
            wynik = false;
            std::cerr << "Blad zapisu przeszkody do pliku" << std::endl;
        }
    }


    
    return wynik;
}
