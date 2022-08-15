#include "PlikZAdresatami.h"

bool PlikZAdresatami::czyPlikJestPusty(){
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::app);

    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0){
        plikTekstowy.close();
        return true;
    }else{
        plikTekstowy.close();//otwieram i zamykam plik w tej metodzie, aby byla bardziej "samodzielna"
        return false;
    }
}


void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat){
    fstream plikTekstowy;
    string liniaZDanymiAdresata = "";
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true){
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
            plikTekstowy << liniaZDanymiAdresata;
        else
            plikTekstowy << endl << liniaZDanymiAdresata ;

    }else
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;

    idOstatniegoAdresata++;
    plikTekstowy.close();
}


string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat){
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}


vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika){
    Adresat adresat;
    fstream plikTekstowy;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true){
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)){
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)){
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }

    if (daneOstaniegoAdresataWPliku != "")
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    else
        idOstatniegoAdresata = 0;

    plikTekstowy.close();
    return adresaci;
}


int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami){
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));
    return idUzytkownika;
}


Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami){
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++){
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|'){
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }else{
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));              break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));   break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);                          break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);                      break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);                 break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);                         break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);                         break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}


int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami){
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata(){
    return idOstatniegoAdresata;
}


void PlikZAdresatami::usunWybranegoAdresataZPliku(int idUsuwanegoAdresata){
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWO.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0)
    {///odczytujemy linijke po linijce, jesli trafimy na linijke z (id)adresatem do usuniecia,
    ///to po prostu nie zapisujemy go do pliku tymczasowego, po tym zmieniamy nazwe pliku tymczasowego
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if(idUsuwanegoAdresata!=pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                if(numerWczytanejLinii>1)
                    tymczasowyPlikTekstowy<<endl;

                tymczasowyPlikTekstowy<<wczytanaLinia;
                numerWczytanejLinii++;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWO, NAZWA_PLIKU_Z_ADRESATAMI);
    }
}


void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem){
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa){
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

int PlikZAdresatami::podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata){
    if (idUsuwanegoAdresata == idOstatniegoAdresata)
        pobierzZPlikuIdOstatniegoAdresata();
}


int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata(){
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true){
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            plikTekstowy.close();
    }else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
}


///edycja adresata
void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat){//(Adresat adresat, int idEdytowanegoAdresata) <-- bylo, zamiast "idEdytowanegoAdresata" mamy nizej "adresat.pobierzId()"
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujAdresataWPliku(adresat.pobierzId(), liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void PlikZAdresatami::edytujAdresataWPliku(int idSzukanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami){
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWO.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if(idSzukanegoAdresata!=pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                if(numerWczytanejLinii>1)//ten maly "if" rozwiazuje problemy z pustymi linijkami w przypadku pierwszej osoby
                    tymczasowyPlikTekstowy<<endl;

                tymczasowyPlikTekstowy<<wczytanaLinia;
            }else{
                if(numerWczytanejLinii>1)
                    tymczasowyPlikTekstowy<<endl;

                tymczasowyPlikTekstowy<<liniaZDanymiAdresataOddzielonePionowymiKreskami;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWO, NAZWA_PLIKU_Z_ADRESATAMI);
    }
}
