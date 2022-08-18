#include <iostream>
#include "KsiazkaAdresowa.h"///menu trzeba bedzie zrobic tutaj (wideo okolo 3:30)
///w przypadku zlego hasla logowania dac informacje o blednym hasle (4:30)

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt", "Adresaci_tymczasowo.txt"); //tworzymy pierwszy obiekt klasy "KsiazkaAdresowa"

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();//tymczasowe

    ///zabawa z menu
    ksiazkaAdresowa.wybierzOpcjeZMenuLogowania();


    return 0;
}
