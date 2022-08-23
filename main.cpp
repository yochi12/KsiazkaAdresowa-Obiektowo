#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt", "Adresaci_tymczasowo.txt"); //tworzymy pierwszy obiekt klasy "KsiazkaAdresowa"
    ksiazkaAdresowa.wybierzOpcjeZMenuLogowania();


    /*char wybor;

    while (true){
        ksiazkaAdresowa.menuLogowania();
        ksiazkaAdresowa.wybierzOpcjeZMenuLogowania();//trzeba to menu ogarnac do konca, na razie to sam poczatek
        switch (wybor){
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();                          break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();                            break;
            case '0':
                exit(0);                                                            break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");                                                    break;
        }

        //if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0){
        //    wybierzOpcjeZMenuUzytkownika();
        }*/


    return 0;
}
