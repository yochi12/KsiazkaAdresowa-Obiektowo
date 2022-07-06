#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt"); //tworzymy pierwszy obiekt klasy "KsiazkaAdresowa"

    ///zabawa z uzytkownikami
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.wylogujUzytkownika();

    ///zabawa z adresatami
    ksiazkaAdresowa.wypiszIdOstatniegoAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wypiszIdOstatniegoAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wypiszIdOstatniegoAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wypiszIdOstatniegoAdresata();

    return 0;
}
