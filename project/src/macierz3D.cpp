#include "macierz3D.hh"

Macierz3D::Macierz3D()
{
    (*this)[0] = Wektor3D(0,0,0); 
    (*this)[1] = Wektor3D(0,0,0); 
    (*this)[2] = Wektor3D(0,0,0);
}

Macierz3D::Macierz3D(Wektor3D pos_0, Wektor3D pos_1, Wektor3D pos_2)
{
    (*this)[0] = pos_0; 
    (*this)[1] = pos_1; 
    (*this)[2] = pos_2;
}

Wektor3D Macierz3D::operator * (Wektor3D wek)
{
    Wektor3D temp = Wektor3D(0,0,0);

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp[i] = temp[i] + (*this)(i,j) * wek[j];
        }
    }
    return temp;
}
