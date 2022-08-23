#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt"); //tworzymy pierwszy obiekt klasy "KsiazkaAdresowa"

    char wybor;

    while (true){
        if(ksiazkaAdresowa.czyUzytkownikJestZalogowany()==false){
            wybor=ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor){
                case '1':
                    ksiazkaAdresowa.rejestracjaUzytkownika();                           break;
                case '2':
                    ksiazkaAdresowa.logowanieUzytkownika();                             break;
                case '0':
                    exit(0);                                                            break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    system("cls");                                                      break;
            }
        }
        else
        {
            wybor=ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor){
                case '1':
                    ksiazkaAdresowa.dodajAdresata();                        break;
                case '2':
                    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();           break;
                case '3':
                    ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();          break;
                case '4':
                    ksiazkaAdresowa.wyswietlWszystkichAdresatow();          break;
                case '5':
                    ksiazkaAdresowa.usunAdresata();                         break;
                case '6':
                    ksiazkaAdresowa.wybierzOpcjeZMenuEdycjaAdresata();      break;
                case '7':
                    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();   break;
                case '8':
                    ksiazkaAdresowa.wylogujUzytkownika();                   break;
                }
        }
    }
    return 0;
}
