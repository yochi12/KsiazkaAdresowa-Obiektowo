#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    string nazwaPlikuZUzytkownikami;

    vector <Uzytkownik> uzytkownicy;//vector "uzytkownicy" jest teraz skladowa klasy,
    //dlatego nie musimy wysylac go np. do voida "rejestracjaUzytkownika"

private:
    Uzytkownik podajDaneNowegoUzytkownika();
    //sa prywatne, poniewaz beda uzywane tylko wewnatrz danej klasy
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    string wczytajLinie();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    string konwerjsaIntNaString(int liczba);
    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};
