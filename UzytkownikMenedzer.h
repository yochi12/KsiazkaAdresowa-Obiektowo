#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer
{

    vector <Uzytkownik> uzytkownicy;//vector "uzytkownicy" jest teraz skladowa klasy,
    //dlatego nie musimy wysylac go np. do voida "rejestracjaUzytkownika"

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;//<- piszemy ten wiersz tylko po to, by w .cpp uzyc funkcji "plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);" na obiekcie "plikZUzy..."



public:

    int idZalogowanegoUzytkownika=5; ///tymczasowo przerzucony z "private" do "public"
    ///nie mozna zrobic tego jako "static", jest wywolywane w kilku miejscach, trzeba pomyslec

    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
};

#endif
