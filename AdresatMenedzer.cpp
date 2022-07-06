#include "AdresatMenedzer.h"
#include "MetodyPomocnicze.h"

AdresatMenedzer::AdresatMenedzer()
{
    idOstatniegoAdresata=0;//pozniej bedzie zalezne od ostatniego wczytanego adresta
}

void AdresatMenedzer::wypiszIdOstatniegoAdresata()
{
    cout<<idOstatniegoAdresata;
}

void AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika)//<-trzeba bedzie zmienic ze zmiennej na funkcje, ktora pobiera zmienna
{
    Adresat adresat;

    //system("cls"); //<- pozniej dodamy funkcje kasujaca poprzednie rzeczy
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    cout<<idZalogowanegoUzytkownika;

    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    //dopiszAdresataDoPliku(adresat); //<- to dodamy kiedy juz wszystko bedzie dobrze z wektorem

    wyswietlWszystkichAdresatow();//tymczasowo

    idOstatniegoAdresata=+1;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    adresat.id = ++idOstatniegoAdresata;
    adresat.idUzytkownika = idZalogowanegoUzytkownika;

    cout << "Podaj imie: ";
    adresat.imie = MetodyPomocnicze::wczytajLinie();
    adresat.imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.imie);

    cout << "Podaj nazwisko: ";
    adresat.nazwisko = MetodyPomocnicze::wczytajLinie();
    adresat.nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.numerTelefonu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    adresat.email = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adresat.adres = MetodyPomocnicze::wczytajLinie();

    return adresat;
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
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.id << endl;
    cout << "Imie:               " << adresat.imie << endl;
    cout << "Nazwisko:           " << adresat.nazwisko << endl;
    cout << "Numer telefonu:     " << adresat.numerTelefonu << endl;
    cout << "Email:              " << adresat.email << endl;
    cout << "Adres:              " << adresat.adres << endl;
}

