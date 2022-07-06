#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <vector>
#include <windows.h> //potrzebne do "system("cls")"

#include "Adresat.h"

using namespace std;

class AdresatMenedzer
{
public:
    vector <Adresat> adresaci;
    int idOstatniegoAdresata; //musimy ogarnac, aby ta zmienna byla aktualna

    AdresatMenedzer();

    void wypiszIdOstatniegoAdresata();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
};

#endif
