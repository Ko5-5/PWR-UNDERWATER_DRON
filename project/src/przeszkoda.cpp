#include "przeszkoda.hh"

Przeszkoda::Przeszkoda(Wektor3D trans)
{
    int los = ((std::rand() % 5 ) + 1);
    std::ifstream plik_przesz;
    switch (los)
    {
        case 1:
        {
            plik_przesz.open(PRZESZ_PROS_1);
            translacja[Z]=(-110)+15+(std::rand() % 30);
            break;
        }
        case 2:
        {
            plik_przesz.open(PRZESZ_PROS_2);
            translacja[Z]=(-110)+70+(std::rand() % 10)+1;
            break;
        }
        case 3:
        {
            plik_przesz.open(PRZESZ_PROS_3);
            translacja[Z]=(-110)+15+(std::rand() % 30)+1;
            break;
        }
        case 4:
        {
            plik_przesz.open(PRZESZ_PLASZ);
            translacja[Z]=(-110)+60+(std::rand() % 10)+1;
            break;
        }
        case 5:
        {
            plik_przesz.open(PRZESZ_PROSTA);
            translacja[Z] = (std::rand() % 109 ) - 110;
            break;
        }
    }
    Wektor3D temp = Wektor3D(0,0,0);
    if(plik_przesz.good())
    { 
        while(!plik_przesz.eof())
        {
            plik_przesz >> temp;
            tablica.push_back(temp);
        }
    }
    plik_przesz.close();
    los = ((std::rand() % 2 ) + 1);
    if(los == 1)
    {
        translacja[X] = (std::rand() % 29 ) + (trans[X]+40);
    }
    else
    {
        translacja[X] = (std::rand() % 29 ) + (trans[X]-40);
    }
    los = ((std::rand() % 2 ) + 1);
    if(los == 1)
    {
        translacja[Y] = (std::rand() % 29 ) + (trans[Y]+40);
    }
    else
    {
        translacja[Y] = (std::rand() % 29 ) + (trans[Y]-40);
    }

    for(Wektor3D wek : tablica)
    {
        tablica_glob.push_back(wek+translacja);
    }
}

bool Przeszkoda::czy_w_zakresie(Wektor3D trans)
{
    if(translacja[X]<trans[X]+OTOCZENIE_DRONA && translacja[X]>trans[X]-OTOCZENIE_DRONA)
    {
        if(translacja[Y]<trans[Y]+OTOCZENIE_DRONA && translacja[Y]>trans[Y]-OTOCZENIE_DRONA) {return true;}
    }
    return false;
}

bool operator == (const Przeszkoda prze1, const Przeszkoda prze2)
{
    if(prze1.tablica_glob == prze2.tablica_glob) return true;
    return false;
}

std::ostream & operator << (std::ostream & Strm, Przeszkoda & tab)
{
    for(int i=0; i<tab.tablica.size(); i++)
    {
        if(i%4==0)
        {
            Strm << std::endl;
        }
        Strm << tab.tablica_glob[i] << std::endl;
    }

    Strm << std::endl << std::endl;

    return Strm;
}