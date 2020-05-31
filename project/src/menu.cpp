#include "menu.hh"

void opcje_menu()
{
    std::cout << std::endl;
    std::cout << " r - ruch przed siebie pod zadanym katem" << std::endl;
    std::cout << " o - obrot wokol osi Z pod zadanym katem" << std::endl;
    std::cout << " m - wyswietl menu programu" << std::endl << std::endl;
    std::cout << " k - zakoncz program" << std::endl << std::endl;

    Wektor3D licznik;

    licznik.Pokaz_Wek_lacznie();
    licznik.Pokaz_wek_teraz();

    std::cout << std::endl;
}

bool menu()
{
    char znak = 'm';
    
    PzG::LaczeDoGNUPlota Lacze;

    Lacze.Inicjalizuj();

    Lacze.ZmienTrybRys(PzG::TR_3D);

    Lacze.UstawRotacjeXZ(75,80);
    Lacze.UstawZakresZ(-110,10);

    ofstream Plik;

    ifstream Plik_dron;
    Plik_dron.open("bryly/dron-lok.dat");

    Dron dron = Dron(Plik_dron);

    Lacze.UstawZakresX(0,70);
    Lacze.UstawZakresY(0,70);

    Lacze.DodajNazwePliku("dat/scena.dat");

    while(znak!='k')
    {
        std::cout << "___DRON (POD)WODNY___" << std::endl;
        opcje_menu();
        std::cout << " Twoj wybor> ";
        std::cin >> znak;

        switch(znak)
        {
            case 'r':
            {
                std::cout << "Podaj wartosc ruchu oraz kat wznoszenia (ruch kat)" << std::endl;
                std::cout << "Twoj wybor> ";
                int krok, kat;
                std::cin >> krok >> kat;
                if(std::cin.fail())
                {
                    std::cerr << "Blad wczytywania wartosci ruchu" << std::endl;
                    exit(1);
                }
                while(kat>90)
                {
                    std::cout << "Podany zly kat ruchu, podaj kat z zakresu -90/90" << std::endl;
                    std::cin >> kat;
                }
                for(int i=0; i<krok; i++)
                {
                    Plik.open("dat/scena.dat");
                    Lacze.UstawZakresX(dron[X]-OTOCZENIE_DRONA,dron[X]+OTOCZENIE_DRONA);
                    Lacze.UstawZakresY(dron[Y]-OTOCZENIE_DRONA,dron[Y]+OTOCZENIE_DRONA);
                    Scena * scena = new Scena(dron[X]-OTOCZENIE_DRONA,dron[X]+OTOCZENIE_DRONA,dron[Y]-OTOCZENIE_DRONA,dron[Y]+OTOCZENIE_DRONA);
                    if(!(*scena).zapisz_plik(Plik))
                    {
                        cerr << "Blad zapisu sceny do pliku dat" << endl;
                        return 1;
                    }
                    delete scena;
                    dron.ruch_przod_kat(1,kat);
                    dron.translacja_glob();
                    if(!dron.zapisz_plik(Plik))
                    {
                        cerr << "Blad zapisu drona do pliku dat" << endl;
                        return 1;
                    }
                    Plik.close();
                    Lacze.Rysuj();
                    if((dron[Z]-10) < POZ_DNA)
                    {
                        std::cout << "Dron uderza w dno, koniec programu" << std::endl;
                        exit(-1);
                    }
                    usleep(100000);
                }
                break;
            }
            case 'o':
            {
                std::cout << "Podaj wartosc kata obrotu wokol osi Z" << std::endl;
                std::cout << "Twoj wybor> ";
                double kat;
                std::cin >> kat;
                if(std::cin.fail())
                {
                    std::cerr << "Blad wczytywania wartosci ruchu" << std::endl;
                    exit(1);
                }
                for(int i=0; i<abs(kat); i++)
                {
                    Plik.open("dat/scena.dat");
                    Scena * scena = new Scena(dron[X]-35,dron[X]+35,dron[Y]-35,dron[Y]+35);
                    if(!(*scena).zapisz_plik(Plik))
                    {
                        cerr << "Blad zapisu sceny do pliku dat" << endl;
                        return 1;
                    }
                    if(kat>0)
                    {
                        dron.obrot_os_kat(Z,1);
                    }
                    else
                    {
                        dron.obrot_os_kat(Z,-1);
                    }
                    dron.translacja_glob();
                    if(!dron.zapisz_plik(Plik))
                    {
                        cerr << "Blad zapisu drona do pliku dat" << endl;
                        return 1;
                    }
                    delete scena;
                    Plik.close();
                    Lacze.Rysuj();
                    usleep(100000);
                }
                break;
            }
            case 'm':
            {
                opcje_menu();
                break;
            }
            case 'k':
            {
                std::cout << "Dzięki za plywanie z nami!!!" << std::endl;
                exit(0);
                break;
            }
            default:
            {
                std::cout << "Brak podanej opcji, prosze wybrac opcje z listy" << std::endl;
                break;
            }

        }
    }
    return true;
}
