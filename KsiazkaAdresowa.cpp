#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::menuLogowania()
{
    if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()==0)
    {
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

void KsiazkaAdresowa::wybierzOpcjeZMenuLogowania()
{
    while (true)
    {
        menuLogowania();
        switch (wybor)
        {
        case '1':
            KsiazkaAdresowa::rejestracjaUzytkownika();                              break;
        case '2':
            KsiazkaAdresowa::logowanieUzytkownika();                                break;
        case '0':
            exit(0);                                                                break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");                                                        break;
        }

        if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0){
            wybierzOpcjeZMenuUzytkownika();
        }
    }
}

char KsiazkaAdresowa::menuUzytkownika()
{
    char wybor;
    //system("cls");
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

    wybor = MetodyPomocnicze::wczytajZnak(); ///z jakiegos powodu zmienna tutaj rozni sie od zmiennej w "wybierzOpcjeZMenuUzytkownika()"
    //cout<<"wybormenuUzytkownika = "<<wybor<<endl; //<- tymczasowe
    return wybor; //podczas proby wyboru opcji z tego menu, ta zmienna pokazywala inna wartosc (poprzednia podczas logowania, czyli "2"), dlatego jest "return" mimo, ze to jest jedna zmienna dla calej klasy
}

void KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    while (true)
    {
        wybor = menuUzytkownika();
        //cout<<"wybor = "<<wybor<<endl; //<- tymczasowe
        switch (wybor)
            {
            case '1':
                KsiazkaAdresowa::dodajAdresata();                       break;
            case '2':
                //wyszukajAdresatowPoImieniu(adresaci);                 break;
            case '3':
                //wyszukajAdresatowPoNazwisku(adresaci);                break;
                break;
            case '4':
                KsiazkaAdresowa::wyswietlWszystkichAdresatow();         break;
            case '5':
                //idUsunietegoAdresata = usunAdresata(adresaci);
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                //edytujAdresata(adresaci);                             break;
                break;
            case '7':
                KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika();  break;
            case '8':
                KsiazkaAdresowa::wylogujUzytkownika();
                wybierzOpcjeZMenuLogowania();                           break;
            }
    }
}








void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0){ //<- teraz raczej nie ma sensu tego sprawdzac, skoro sprawdzamy podczas pokazywania menu
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika(){
    uzytkownikMenedzer.wylogujUzytkownika();
    adresatMenedzer->wyczyscVectorAdresaci(); //pracujac na wskazniku uzywamy strzalki "->"
}

void KsiazkaAdresowa::dodajAdresata(){
    if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0){ //<- teraz raczej nie ma sensu tego sprawdzac, skoro sprawdzamy podczas pokazywania menu
        adresatMenedzer->dodajAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }

}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatMenedzer->wyswietlWszystkichAdresatow();
}






