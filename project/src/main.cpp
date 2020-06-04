#include <iostream>
#include "menu.hh"


int main()
{
  menu();
  return 0;
}

/*
int main()
{
  PzG::LaczeDoGNUPlota Lacze;
  char c;

  Lacze.Inicjalizuj();

  Lacze.ZmienTrybRys(PzG::TR_3D);

  Lacze.UstawRotacjeXZ(75,80);
  Lacze.UstawZakresZ(-70,70);

  ofstream Plik;

  ifstream Plik_dron;
  Plik_dron.open("bryly/dron-lok.dat");

  Dron dron = Dron(Plik_dron);

  Lacze.UstawZakresX(-70,70);
  Lacze.UstawZakresY(-70,70);

  Lacze.DodajNazwePliku("bryly/przeszkoda-plaszczyzna.dat");
  Lacze.Rysuj();

  for(int i=0; i<60; i++)
  {
    Plik.open("dat/scena.dat");
    Scena * scena = new Scena(dron[X]-35,dron[X]+35,dron[Y]-35,dron[Y]+35);
    Lacze.UstawZakresX(dron[X]-35,dron[X]+35);
    Lacze.UstawZakresY(dron[Y]-35,dron[Y]+35);
    if(!(*scena).zapisz_plik(Plik))
    {
      cerr << "Blad zapisu sceny do pliku dat" << endl;
      return 1;
    }
    dron.ruch_przod_kat(1,-45);
    dron.translacja_glob();
    if(!dron.zapisz_plik(Plik))
    {
      cerr << "Blad zapisu drona do pliku dat" << endl;
      return 1;
    }
    delete scena;
    Plik.close();
    Lacze.Rysuj();
    if((dron[Z]-10) < POZ_DNA)
    {
      std::cout << "Dron uderza w dno, koniec programu" << std::endl;
      exit(-1);
    }
    usleep(100000);
  }

  Wektor3D licznik = Wektor3D(0,0,0);
  cout << "Łacznie: "<< licznik.Pokaz_Wek_lacznie() << endl;
  cout << "Teraz: " << licznik.Pokaz_wek_teraz() << endl;

  cout << "Nacisnij ENTER, aby zakonczyc." << endl;
  cin >> noskipws >> c;

}
*/
