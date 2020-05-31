#include "woda.hh"

Woda::Woda(int x_0, int x, int y_0, int y)
{
    for (int i = x_0;  i <= x; i += KROK_SIATKI) 
    {
        for (int j = y_0;  j <= y; j += KROK_SIATKI) 
        {
            if(j%2==0)
            {
                tablica.push_back(Wektor3D(i,j,1));
            }
            else 
            {
                tablica.push_back(Wektor3D(i,j,-1));
            }
        }
    }
}
