#include "AdresatMenedzer.h"


void AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika){
    cout<<idZalogowanegoUzytkownika<<" | "<<plikZAdresatami.pobierzIdOstatniegoAdresata()<<" <== AdresatMenedzer::dodajAdresata"<<endl;// <-- tymczasowe
    Adresat adresat;

    //system("cls"); //<-- pozniej sie odkomentuje
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}


Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika){
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1); //<- dlaczego zapis "++idOstatniegoAdresata" dodaje "1" do zmiennej "idOstatniegoAdresata"??
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}


void AdresatMenedzer::wyswietlWszystkichAdresatow(){
    //system("cls");<-- pozniej sie odkomentuje
    if (!adresaci.empty()){
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }else{
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat){
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}


void AdresatMenedzer::wyszukajAdresatowPoImieniu(){
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    //system("cls"); //<-- pozniej sie odkomentuje
    if (!adresaci.empty()){
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++){
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata){
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }else
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;

    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    //system("cls");
    if (!adresaci.empty()){
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata){
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }else
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;

    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow){
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}


void AdresatMenedzer::usunAdresata(){
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {   //metoda "usunWybranegoAdresataZPliku(idUsuwanegoAdresata)" powstala zamiast metod "zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata)" i  "usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata)"
                plikZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                plikZAdresatami.podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsuwanegoAdresata);
                return; //return idUsuwanegoAdresata; //byl chyba int, teraz jest void. Trzeba bedzie ogarnac
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                idUsuwanegoAdresata=0; //zobaczymy czy z tym zadziala
                return; //return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false){
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

int AdresatMenedzer::podajIdWybranegoAdresata(){
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}


void AdresatMenedzer::menuEdycjaAdresata(){
    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();
}

void AdresatMenedzer::wybierzOpcjeZMenuEdycjaAdresata()
{
    //system("cls"); //<-- pozniej sie odkomentuje
    Adresat adresat;
    int idEdytowanegoAdresata = 0;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++){
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            menuEdycjaAdresata();

            switch (wybor){
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);//wczesniej bylo --> (adresaci[i], idEdytowanegoAdresata), ale "idEdytowanegoAdresata" zawiera sie w "adresaci[i]",  wystarczy tylko (w nastepnych implementacjach) "wydobyc" za pomoca gettera id adresata
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
        cout << endl << "Nie ma takiego adresata." << endl << endl;

    system("pause");
}
