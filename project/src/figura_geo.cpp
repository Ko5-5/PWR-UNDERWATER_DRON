#include "figura_geo.hh"

Figura_geo::Figura_geo(std::ifstream & plik_wej)
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

Wektor3D Figura_geo::maks_wek()
{
    Wektor3D wynik = Wektor3D(-1000,-1000,-110);
    for(Wektor3D wek : tablica_glob)
    {
        if(wek[X]>wynik[X]) wynik[X]=wek[X];
        if(wek[Y]>wynik[Y]) wynik[Y]=wek[Y];
        if(wek[Z]>wynik[Z]) wynik[Z]=wek[Z];
    }
    return wynik;
}

Wektor3D Figura_geo::min_wek()
{
    Wektor3D wynik = Wektor3D(1000,1000,10);
    for(Wektor3D wek : tablica_glob)
    {
        if(wek[X]<wynik[X]) wynik[X]=wek[X];
        if(wek[Y]<wynik[Y]) wynik[Y]=wek[Y];
        if(wek[Z]<wynik[Z]) wynik[Z]=wek[Z];
    }
    return wynik;
}
/*
bool Figura_geo::zapisz_plik(std::ostream & plik_wyj)
{
    for(int i=0; i<(tablica.size()); i++)
    {
        if(i%4==0 && i!=0)
        {
            plik_wyj << std::endl;
        }
        plik_wyj << tablica_glob[i] << std::endl;
        if(plik_wyj.fail())
        {
            std::cerr << "Blad zapisu figury geometrycznej do pliku" << std::endl;
            return false;
        }
    }

    plik_wyj << std::endl;

    return true;
}
*/
