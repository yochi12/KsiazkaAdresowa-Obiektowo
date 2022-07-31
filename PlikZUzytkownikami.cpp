#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_UZYTKOWNIKAMI << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}

bool PlikZUzytkownikami::czyPlikJestPusty()
{
    fstream plikTekstowy1;  //dodaje na koniec nazwy "1", aby nie mylilo sie z doklaracja "plikTekstowy" z "PlikZUzytkownik.h"
    plikTekstowy1.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::app);

    plikTekstowy1.seekg(0, ios::end);
    if (plikTekstowy1.tellg() == 0){
        plikTekstowy1.close();
        return true;
    }else{
        plikTekstowy1.close();//otwieram i zamykam plik w tej metodzie, aby byla bardziej "samodzielna"
        return false;
    }
}

string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';//uzywamy tutaj metody statycznej
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
    vector <Uzytkownik> uzytkownicy;

    plikTekstowy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }
    }
    plikTekstowy.close();
    return uzytkownicy;
}

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}

void PlikZUzytkownikami::zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy)
{
    string liniaZDanymiUzytkownika = "";
    vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

    plikTekstowy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::out);

    if (plikTekstowy.good() == true)
    {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
               plikTekstowy << liniaZDanymiUzytkownika;
            }
            else
            {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << NAZWA_PLIKU_Z_UZYTKOWNIKAMI << endl;
    }
    plikTekstowy.close();
}


