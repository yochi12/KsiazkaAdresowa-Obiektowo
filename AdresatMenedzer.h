#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <vector>
#include <windows.h> //potrzebne do "system("cls")"
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    string nazwaPlikuZAdresatami = "Adresaci.txt";//<- trzeba zrobic tak jak uzytkownikow, za pomoca konstruktora etc.
    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenedzer();
    int podajIdOstatniegoAdresata();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();
    void wyswietlWszystkichAdresatow();
    void nadajIdOstatniegoAdresata(int idZalogowanegoUzytkownika);
};

#endif
