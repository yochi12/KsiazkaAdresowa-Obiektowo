#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class PlikTekstowy
{
    const string NAZWA_PLIKU;

public:
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {}//ten string nie zostaje do niczego wykorzystany w metodach, nadaje tylko wartosc stalej

    string pobierzNazwePliku();
    bool czyPlikJestPusty();
    void usunPlik();
    void zmienNazwePliku(string nazwaTymczasowa);
};

#endif
