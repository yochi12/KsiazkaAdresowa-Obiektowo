#include "AdresatMenedzer.h" ///pozostalo zmienic rzeczy z public na private oraz zabawa z konstruktorem nazwy pliku z adresatami


int AdresatMenedzer::podajIdOstatniegoAdresata(string daneOstaniegoAdresataWPliku)
{
    //cout<<"daneOstaniegoAdresataWPliku(AdresatMenedzer) = "<<daneOstaniegoAdresataWPliku<<endl; //tymczasowe
    //cout<<"daneOstaniegoAdresataWPliku(AdresatMenedzer, plikZAdresatami) = "<<plikZAdresatami.daneOstaniegoAdresataWPliku<<endl; system("pause"); //tymczasowe
    if (plikZAdresatami.daneOstaniegoAdresataWPliku != "")
    {
        cout<<"- | "<<idOstatniegoAdresata<<" <== podajIdOstatniegoAdresata, if"<<endl;// <-- tymczasowe
        idOstatniegoAdresata = plikZAdresatami.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }
    else
        cout<<"- | "<<idOstatniegoAdresata<<" <== podajIdOstatniegoAdresata, else"<<endl;// <-- tymczasowe
        return 0;
}


vector <Adresat> AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    return adresaci;
}


void AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika)//<-trzeba bedzie zmienic ze zmiennej na funkcje, ktora pobiera zmienna
{
    cout<<idZalogowanegoUzytkownika<<" | "<<idOstatniegoAdresata<<" <== dodajAdresata"<<endl;// <-- tymczasowe
    Adresat adresat;

    //za kazdym razem kiedy dodajemy nowego uzytkownika wczytujemy jego WSZYSTKICH adresatow, lepiej jakby raz ich wczytac dla danego uzytkownika
    ///adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    //linijka wyzej byla zanim udalo sie ja zaimplementowac do "KsiazkaAdresowa"

    if (idOstatniegoAdresata==0) //teraz tutaj nadajemy "idOstatniegoAdresata"
    {
        cout<<"ID USTATNIEGO UZYTKOWNIKA = 0"<<endl<<endl;
        idOstatniegoAdresata = podajIdOstatniegoAdresata(plikZAdresatami.daneOstaniegoAdresataWPliku);
    }

    //system("cls"); //<-- pozniej sie odkomentuje
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    system("pause");
}


Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
    cout<<idZalogowanegoUzytkownika<<" | "<<idOstatniegoAdresata<<" <== podajIdOstatniegoAdresata"<<endl;// <-- tymczasowe
    Adresat adresat;

    adresat.ustawId(++idOstatniegoAdresata); //<- dlaczego ta linijka dodaje "1" do zmiennej "idOstatniegoAdresata"??
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


void AdresatMenedzer::wypiszWszystkichAdresatow() //to samo co "wyswietlWszystkichAdresatow()", ale na razie niech bedzie
{
    for(int i=0; i<adresaci.size(); i++)
    {
        cout<<adresaci[i].pobierzId()<<endl;
        cout<<adresaci[i].pobierzIdUzytkownika()<<endl;
        cout<<adresaci[i].pobierzImie()<<endl;
        cout<<adresaci[i].pobierzNazwisko()<<endl;
        cout<<adresaci[i].pobierzNumerTelefonu()<<endl;
        cout<<adresaci[i].pobierzEmail()<<endl;
        cout<<adresaci[i].pobierzAdres()<<endl<<endl;
    }
}


void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    //system("cls");<-- pozniej sie odkomentuje
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
    //adresaci.clear();
}


void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}




