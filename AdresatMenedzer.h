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
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdOstatniegoAdresata(string daneOstaniegoAdresataWPliku);

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){
        idOstatniegoAdresata=0;
    }

    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();
    void wyswietlWszystkichAdresatow();
    void wyczyscVectorAdresaci();
};

#endif
