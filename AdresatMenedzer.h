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
    PlikZAdresatami plikZAdresatami;
    int idOstatniegoAdresata;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdOstatniegoAdresata(string daneOstaniegoAdresataWPliku);

public:
    vector <Adresat> adresaci; //uzywam polecenia "adresaci.clear()" w "KsiazkaAdresowa", dlatego ten vector jest jako public

    AdresatMenedzer(){idOstatniegoAdresata=0;}
    void dodajAdresata(int idZalogowanegoUzytkownika);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();
    void wyswietlWszystkichAdresatow();
};

#endif
