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

    if(pos==1) translacja_lok_dron = Wektor3D(-5,-6,-5);
    if(pos==2) translacja_lok_dron = Wektor3D(5,-6,-5);
}

void Wirnik::obrot_lewa(double kat)
{
    kat -= kat;
}

void Wirnik::obrot_prawa(double kat)
{
    kat += kat;
}

std::ostream & operator << (std::ostream & Strm, Wirnik & tab)
{
    for(int i=0; i<(tab.uk_lok().size()); i++)
    {
        if(i%4==0 && i!=0)
        {
            Strm << std::endl;
        }
        Strm << tab.uk_glob()[i] << std::endl;
        if(Strm.fail())
        {
            std::cerr << "Blad zapisu wirnika do pliku" << std::endl;
            return Strm;
        }
    }

    Strm << std::endl;

    return Strm;
}