#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;

    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) :
        uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMenedzer = NULL; //aby nie wskazywal na jakiekolwiek, byc moze wazne miejsce w pamieci
    }
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer; //usuwamy za pomoca operatora "delete" utworzony obiekt
        adresatMenedzer = NULL;
    }

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();

    void dodajAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void wyswietlWszystkichAdresatow();
    void wybierzOpcjeZMenuEdycjaAdresata();
    void usunAdresata();

    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();


};

#endif
