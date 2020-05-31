#include "wektor3D.hh"

int Wektor3D::lacznie_wek = 0;
int Wektor3D::zniszcz_wek = 0;

Wektor3D Wektor3D::operator + (Wektor3D wek)
{
    Wektor3D temp;

    for(int i=0; i<3; i++)
    {
        temp[i] = (*this)[i] + wek[i];
    }

    return temp;
}
