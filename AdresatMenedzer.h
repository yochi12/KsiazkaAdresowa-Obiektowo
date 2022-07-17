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
    int idOstatniegoAdresata;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdOstatniegoAdresata(string daneOstaniegoAdresataWPliku);

public:
    vector <Adresat> adresaci; //uzywam polecenia "adresaci.clear()" w "KsiazkaAdresowa", dlatego ten vector jest jako public

    AdresatMenedzer();
    void dodajAdresata(int idZalogowanegoUzytkownika, string daneOstaniegoAdresataWPliku);
    void wypiszWszystkichAdresatow();
    void wyswietlWszystkichAdresatow();
};

#endif
