#include "PlikTekstowy.h"

bool PlikTekstowy::czyPlikJestPusty(){
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU.c_str(), ios::app);

    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0){
        plikTekstowy.close();
        return true;
    }else{
        plikTekstowy.close();
        return false;
    }
}

void PlikTekstowy::usunPlik(){
    if (remove(NAZWA_PLIKU.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << NAZWA_PLIKU << endl;
}

void PlikTekstowy::zmienNazwePliku(string nazwaTymczasowa){
    if (rename(nazwaTymczasowa.c_str(), NAZWA_PLIKU.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << nazwaTymczasowa << endl;
}
