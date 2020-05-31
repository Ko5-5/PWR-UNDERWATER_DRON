#include "powierzchnia.hh"

std::ostream & operator << (std::ostream & Strm, const Powierzchnia & tab)
{
    int y_0;
    y_0 = tab[0][Y];

    Strm << tab[0] << std::endl;

    for(int i=1; i<tab.size(); i++)
    {
        if(tab[i][Y]==y_0)
        {
            Strm << std::endl;
        }
        Strm << tab[i] << std::endl;
    }

    Strm << std::endl << std::endl;
    
    return Strm;
}
