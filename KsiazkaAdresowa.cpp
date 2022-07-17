#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();

    if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0)
    {///problemem jest zmienna "daneOstatniegoAdresataWPliku", ktora okazuje sie pusta(?)
        adresatMenedzer.adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
    adresatMenedzer.adresaci.clear(); //po wylogowaniu czysci vector z adresatami danego uzytkownika
}

void KsiazkaAdresowa::dodajAdresata()
{   ///poniewaz podczas wczytywania adresatow z pliku zmianna "daneOstatniegoAdresataWPliku" zawsze byla pusta, dodano ta zmienna do metody "dodajAdresata"
    adresatMenedzer.dodajAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika(), plikZAdresatami.daneOstaniegoAdresataWPliku);
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatMenedzer.wypiszWszystkichAdresatow();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}






