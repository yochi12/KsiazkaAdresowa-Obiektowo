#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include "Adresat.h"
#include <fstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami :public PlikTekstowy
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWO;
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    int pobierzZPlikuIdOstatniegoAdresata();
    void edytujAdresataWPliku(int idSzukanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami); //kolejna metoda ktora powstala z dwoch innych

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami, string nazwaPlikuZAdresatamiTymczasowo) :
        NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami),
        NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWO(nazwaPlikuZAdresatamiTymczasowo)
    {
        idOstatniegoAdresata = 0;
    }

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    void usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);//ta metoda powstala zamiast metod "zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata)" i  "usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata)"
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);

    //gettery i settery
    int pobierzIdOstatniegoAdresata();
};

#endif
