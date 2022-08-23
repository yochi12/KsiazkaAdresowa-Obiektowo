#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H
#include <vector>
#include <windows.h>
#include <fstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    PlikZAdresatami plikZAdresatami;

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    char wybor;

    Adresat podajDaneNowegoAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);

    void menuEdycjaAdresata();

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    }

    void dodajAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    void wyswietlWszystkichAdresatow();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    int podajIdWybranegoAdresata();
    void wybierzOpcjeZMenuEdycjaAdresata();
};

#endif
