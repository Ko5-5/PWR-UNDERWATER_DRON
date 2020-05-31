#include "dno.hh"

Dno::Dno(int x_0, int x, int y_0, int y)
{
    for (int i = x_0;  i <= x; i += KROK_SIATKI) 
    {
        for (int j = y_0;  j <= y; j += KROK_SIATKI) 
        {
            tablica.push_back(Wektor3D(i,j,POZ_DNA));
        }
    }
}
