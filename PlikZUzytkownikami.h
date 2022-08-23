#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include "PlikTekstowy.h"

#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include <fstream>
#include <cstdlib>

using namespace std;

class PlikZUzytkownikami :public PlikTekstowy
{
    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI; //zmieniamy plik na "const", nazwa tej zmiennej ma sie nie zmieniac w calym programie

    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : //korzystamy z listy inicjalizacyjnej
        NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami),
        PlikTekstowy(nazwaPlikuZUzytkownikami) {};

    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};

#endif
