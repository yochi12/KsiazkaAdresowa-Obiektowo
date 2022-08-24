#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami :public PlikTekstowy
{
    string tymczasowaNazwaPlikuZAdresatami;
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void pobierzZPlikuIdOstatniegoAdresata();
    void edytujAdresataWPliku(int idSzukanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami); //kolejna metoda ktora powstala z dwoch innych

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami){
        idOstatniegoAdresata = 0;
        tymczasowaNazwaPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    }

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    void usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);//ta metoda powstala zamiast metod "zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata)" i  "usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata)"
    void podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);

    //gettery i settery
    int pobierzIdOstatniegoAdresata();
};

#endif
