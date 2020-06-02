#include "wirnik.hh"

Wirnik::Wirnik(std::ifstream & plik_wej, int pos)
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

    if(pos==1) translacja_lok_dron = Wektor3D(0,-5,5);
    if(pos==2) translacja_lok_dron = Wektor3D(0,5,5);
}

void Wirnik::obrot_lewa(double kat)
{
    kat -= kat;
}

void Wirnik::obrot_prawa(double kat)
{
    kat += kat;
}