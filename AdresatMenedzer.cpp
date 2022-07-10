#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer()
{
    idOstatniegoAdresata=0;//zainicjalizowana wartosc zmiennej, aby nie byla "jakakolwiek" (raczej malo istotne i nic nie zmienia)
}

void AdresatMenedzer::nadajIdOstatniegoAdresata(int idZalogowanegoUzytkownika)
{
    adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    idOstatniegoAdresata = podajIdOstatniegoAdresata(); //wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);//ta linijka nie jest (oryginalnie) z tej funkcji (metody)

    cout<<"nadajIdOstatniegoAdresata="<<idOstatniegoAdresata;
}


int AdresatMenedzer::podajIdOstatniegoAdresata()
{
    if (plikZAdresatami.daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = plikZAdresatami.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(plikZAdresatami.daneOstaniegoAdresataWPliku);
        cout<<"wczytajAdresatowZalogowanegoUzytkownikaZPliku, if= "<<idOstatniegoAdresata;
        system("pause");
        return idOstatniegoAdresata;
    }
    else
        cout<<"wczytajAdresatowZalogowanegoUzytkownikaZPliku, return=0 ="<<idOstatniegoAdresata;
        system("pause");
        return 0;
}


void AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika)//<-trzeba bedzie zmienic ze zmiennej na funkcje, ktora pobiera zmienna
{
    Adresat adresat;

    //system("cls"); //<- pozniej dodamy funkcje kasujaca poprzednie rzeczy
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    cout<<"idZalogowanegoUzytkownika = "<<idZalogowanegoUzytkownika<<endl;

    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    //idOstatniegoAdresata=+1; //-> to mi psulo ta zmienna (?)

    cout<<"dodajAdresata = "<<idOstatniegoAdresata;
    system("pause");
}


Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
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

    cout<<"podajDaneNowegoAdresata="<<idOstatniegoAdresata;
    system("pause");

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
    adresaci.clear();
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




