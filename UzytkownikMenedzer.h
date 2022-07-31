#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;//vector "uzytkownicy" jest teraz skladowa klasy,
    //dlatego nie musimy wysylac go np. do voida "rejestracjaUzytkownika"
    PlikZUzytkownikami plikZUzytkownikami;//<- piszemy ten wiersz tylko po to, by w .cpp uzyc funkcji "plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);" na obiekcie "plikZUzy..."

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);


public:

    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
        ///idZalogowanegoUzytkownika=0;
        uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();

    //gettery i settery
    void ustawIdZalogowanegoUzytkownika(int nowyIdZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
