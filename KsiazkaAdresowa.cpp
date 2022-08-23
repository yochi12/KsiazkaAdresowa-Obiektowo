#include "KsiazkaAdresowa.h"

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego(){

    cout << "    >>> MENU  GLOWNE <<<" <<       endl;
    cout << "---------------------------" <<    endl;
    cout << "1. Rejestracja" <<                 endl;
    cout << "2. Logowanie" <<                   endl;
    cout << "0. Koniec programu" <<             endl;
    cout << "---------------------------" <<    endl;
    cout << "Twoj wybor: ";

    return MetodyPomocnicze::wczytajZnak();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika(){
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" <<      endl;
    cout << "---------------------------" <<    endl;
    cout << "1. Dodaj adresata" <<              endl;
    cout << "2. Wyszukaj po imieniu" <<         endl;
    cout << "3. Wyszukaj po nazwisku" <<        endl;
    cout << "4. Wyswietl adresatow" <<          endl;
    cout << "5. Usun adresata" <<               endl;
    cout << "6. Edytuj adresata" <<             endl;
    cout << "---------------------------" <<    endl;
    cout << "7. Zmien haslo" <<                 endl;
    cout << "8. Wyloguj sie" <<                 endl;
    cout << "---------------------------" <<    endl;
    cout << "Twoj wybor: ";

    return MetodyPomocnicze::wczytajZnak();
}

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0){ //<- teraz raczej nie ma sensu tego sprawdzac, skoro sprawdzamy podczas pokazywania menu
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany(){
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}


void KsiazkaAdresowa::dodajAdresata(){
    adresatMenedzer->dodajAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatMenedzer->wyswietlWszystkichAdresatow(); //pracujac na wskazniku uzywamy strzalki "->"
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){
    adresatMenedzer->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){
    adresatMenedzer->wyszukajAdresatowPoNazwisku();
}

void KsiazkaAdresowa::usunAdresata(){
    adresatMenedzer->usunAdresata();
}

void KsiazkaAdresowa::wybierzOpcjeZMenuEdycjaAdresata(){
    adresatMenedzer->wybierzOpcjeZMenuEdycjaAdresata();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika(){
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}




