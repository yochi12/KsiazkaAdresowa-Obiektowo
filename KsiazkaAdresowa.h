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
    const string NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWO;
    char wybor;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaPlikuZAdresatamiTymczasowo) :
        uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWO(nazwaPlikuZAdresatamiTymczasowo)
    {
        adresatMenedzer = NULL; //aby nie wskazywal na jakiekolwiek, byc moze wazne miejsce w pamieci
    }
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer; //usuwamy za pomoca operatora "delete" utworzony obiekt
        adresatMenedzer = NULL;
    }

    void menuLogowania();
    void menuUzytkownika();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();

    void wybierzOpcjeZMenuUzytkownika();
    void dodajAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void wyswietlWszystkichAdresatow();
    void wybierzOpcjeZMenuEdycjaAdresata();
    void usunAdresata();

    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();

    void wybierzOpcjeZMenuLogowania();
};

#endif
