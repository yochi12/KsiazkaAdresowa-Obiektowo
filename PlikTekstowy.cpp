#include "PlikTekstowy.h"

bool PlikTekstowy::czyPlikJestPusty(string nazwaPliku){
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPliku.c_str(), ios::app);

    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0){
        plikTekstowy.close();
        return true;
    }else{
        plikTekstowy.close();
        return false;
    }
}
