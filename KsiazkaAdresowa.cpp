#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::menuLogowania(){
    if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()==0){
        cout << "    >>> MENU  GLOWNE <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Rejestracja" << endl;
        cout << "2. Logowanie" << endl;
        cout << "0. Koniec programu" << endl;
        cout << "---------------------------" << endl;
        cout << "Twoj wybor: ";

        wybor = MetodyPomocnicze::wczytajZnak();
    }
}

void KsiazkaAdresowa::wybierzOpcjeZMenuLogowania(){
    while (true){
        menuLogowania();
        switch (wybor){
            case '1':
                KsiazkaAdresowa::rejestracjaUzytkownika();                          break;
            case '2':
                KsiazkaAdresowa::logowanieUzytkownika();                            break;
            case '0':
                exit(0);                                                            break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");                                                    break;
        }

        if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0){
            wybierzOpcjeZMenuUzytkownika();
        }
    }
}

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0){ //<- teraz raczej nie ma sensu tego sprawdzac, skoro sprawdzamy podczas pokazywania menu
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWO, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}


void KsiazkaAdresowa::menuUzytkownika(){
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    wybor = MetodyPomocnicze::wczytajZnak();
    //cout<<"wybor-menuUzytkownika = "<<wybor<<endl; //<- tymczasowe
}

void KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika(){
    while (true){
        menuUzytkownika();
        //cout<<"wybor = "<<wybor<<endl; //<- tymczasowe
        switch (wybor){
            case '1':
                KsiazkaAdresowa::dodajAdresata();                               break;
            case '2':
                KsiazkaAdresowa::wyszukajAdresatowPoImieniu();                  break;
            case '3':
                KsiazkaAdresowa::wyszukajAdresatowPoNazwisku();                 break;
            case '4':
                KsiazkaAdresowa::wyswietlWszystkichAdresatow();                 break;
            case '5':
                KsiazkaAdresowa::usunAdresata();                                break;
            case '6':
                KsiazkaAdresowa::wybierzOpcjeZMenuEdycjaAdresata();             break;
            case '7':
                KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika();          break;
            case '8':
                KsiazkaAdresowa::wylogujUzytkownika();
                wybierzOpcjeZMenuLogowania();                                   break;
            }
    }
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

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){ //tymczasowe
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika(){
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}




