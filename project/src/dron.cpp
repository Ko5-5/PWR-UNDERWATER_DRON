#include "dron.hh"

void Dron::ruch_przod_kat(int il_krok, double kat)
{
    double kat_rad = (kat/180) * (M_PI);

    translacja[Z] += il_krok * sin(kat_rad);
    //std::cout << translacja[Z] << std::endl;
    
    switch((int)obrot_kat[Z])
    {
        case 0:
        {
            translacja[Y] += il_krok * cos(kat_rad);
            break;
        }
        case 180:
        {
            translacja[Y] -= il_krok * cos(kat_rad);
            break;
        }
        case -180:
        {
            translacja[Y] -= il_krok * cos(kat_rad);
            break;
        }
        case 90:
        {
            translacja[X] -= il_krok * cos(kat_rad);
            break;
        }
        case -90:
        {
            translacja[X] += il_krok * cos(kat_rad);
            break;
        }

        default:
        {
            translacja[X] += (il_krok * cos(kat_rad))*(sin(obrot_kat[Z]));
            translacja[Y] += (il_krok * cos(kat_rad))*(cos(obrot_kat[Z]));
        }
    }

    //std::cout << translacja[Y] << std::endl;
    
}

void Dron::translacja_glob()
{
    tablica_glob.clear();

    if(obrot_kat[Z]!=0)
    {
        double kat_rad = (obrot_kat[Z]/180) * (M_PI);
        Wektor3D temp = Wektor3D(0,0,0);
        Macierz3D mac_obrot = Macierz3D(Wektor3D(cos(kat_rad),-sin(kat_rad),0),Wektor3D(sin(kat_rad),cos(kat_rad),0),Wektor3D(0,0,1));
        //std::cout << mac_obrot << std::endl;
        for(int i=0; i<(tablica.size()); i++)
        {
            temp = translacja + mac_obrot*tablica[i];
            //std::cout << temp << std::endl;
            tablica_glob.push_back(temp);
            //std::cout << tablica_glob[i] << std::endl;
        }
    }
    else
    {    
        for(int i=0; i<(tablica.size()); i++)
        {
            if(translacja[Z]+tablica[i][Z]>POZ_WOD)
            {
                tablica_glob.push_back(Wektor3D(translacja[X]+tablica[i][X],translacja[Y]+tablica[i][Y],POZ_WOD+1));
            }
            else
            {
                tablica_glob.push_back(Wektor3D(translacja[X]+tablica[i][X],translacja[Y]+tablica[i][Y],translacja[Z]+tablica[i][Z]));
            }
        }
    }
}

void Dron::obrot_os_kat(int os, double kat)
{
    switch(os)
    {
        case X:
        {
            obrot_kat[X]+=kat;
            break;
        }
        case Y:
        {
            obrot_kat[Y]+=kat;
            break;
        }
        case Z:
        {
            obrot_kat[Z]+=kat;
            break;
        }
    }
}

