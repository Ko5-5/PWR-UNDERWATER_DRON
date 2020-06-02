#ifndef MENU_HH
#define MENU_HH

#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"
#include "scena.hh"
#include "dron.hh"

/**
 * \brief Realizuje wyswietlenie opcji menu
 **/
void opcje_menu();

/**
 * \brief Realizuje inizjalizacje lacza z gnuplotem
 **/
void inicjalizuj_lacze(PzG::LaczeDoGNUPlota & Lacze);

/**
 * \brief Realizuje obsluge programu i kontakt z uzytkownikiem
 **/
bool menu();

#endif
