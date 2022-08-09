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
    char wybor;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) :
        uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMenedzer = NULL; //aby nie wskazywal na jakiekolwiek, byc moze wazne miejsce w pamieci
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer; //usuwamy za pomoca operatora "delete" utworzony obiekt
        adresatMenedzer = NULL;
    }

    void menuLogowania();
    void wybierzOpcjeZMenuLogowania();
    void menuUzytkownika();
    void wybierzOpcjeZMenuUzytkownika();
    void usunAdresata();
    void menuEdycjaAdresata();
    void wybierzOpcjeZMenuEdycjaAdresata();

    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();//metoda ze strukturalnego pliku
};

#endif
