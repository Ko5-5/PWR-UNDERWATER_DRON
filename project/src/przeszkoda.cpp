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
            break;
        }
        case 2:
        {
            plik_przesz.open(PRZESZ_PROS_2);
            break;
        }
        case 3:
        {
            plik_przesz.open(PRZESZ_PROS_3);
            break;
        }
        case 4:
        {
            plik_przesz.open(PRZESZ_PLASZ);
            break;
        }
        case 5:
        {
            plik_przesz.open(PRZESZ_PROSTA);
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
        translacja[X] = (std::rand() % 29 ) + (trans[X]+30);
    }
    else
    {
        translacja[X] = (std::rand() % 29 ) + (trans[X]-30);
    }
    los = ((std::rand() % 2 ) + 1);
    if(los == 1)
    {
        translacja[Y] = (std::rand() % 29 ) + (trans[Y]+30);
    }
    else
    {
        translacja[Y] = (std::rand() % 29 ) + (trans[Y]-30);
    }
    translacja[Z] = (std::rand() % 109 ) - 110;

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
    for(int i=1; i<(tab.tablica.size()+1); i++)
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