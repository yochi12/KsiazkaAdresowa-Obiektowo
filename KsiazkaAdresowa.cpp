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
    {cout<<"KsiazkaAdresowa::logowanie NAZWA_PLIKU_Z_ADRESATAMI = "<<NAZWA_PLIKU_Z_ADRESATAMI<<endl;
        ///adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }//musimy sprawdzic co z wczytywaniem wszystkich adresatow w tym "new"....
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
    adresatMenedzer->wyczyscVectorAdresaci(); //pracujac na wskazniku uzywamy strzalki "->"
}

void KsiazkaAdresowa::dodajAdresata()
{///tutaj mozna dac sprawdzenie, czy uzytkownik jest zalogowany
    adresatMenedzer->dodajAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatMenedzer->wypiszWszystkichAdresatow();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}






