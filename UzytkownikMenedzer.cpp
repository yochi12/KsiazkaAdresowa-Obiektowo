#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika(){
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
    system("cls");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika(){
    Uzytkownik uzytkownik;

    //uzytkownik.id = pobierzIdNowegoUzytkownika();//linijka nizej powstala z tego wiesza, nie mozna bylo dostac sie do "id", poniewaz jest to zmienna prywatna (gettery settery)
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do{
        cout << "Podaj login: ";
        uzytkownik.ustawLogin(MetodyPomocnicze::wczytajLinie());
    }while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);//nie trzeba tego porownywac do "true", wychodzi na tao samo : ]
                                        //jesli chcemy porownac do "false" to wykrzyknik przed, np. "(!uzytkownik.pobierzLogin())"
    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(MetodyPomocnicze::wczytajLinie());

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika(){
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login){
    for(int i=0; i<(int)uzytkownicy.size(); i++){///inne typy zmiennych ("i" i "uzytkownicy.size()", dlatego int w nawiasie (warning, nie error))
        if(uzytkownicy[i].pobierzLogin()==login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow(){
    for(int i=0; i<(int)uzytkownicy.size(); i++){
        cout<<uzytkownicy[i].pobierzId()<<endl;
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
        cout<<uzytkownicy[i].pobierzHaslo()<<endl<<endl;
    }
}

void UzytkownikMenedzer::logowanieUzytkownika(){
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();

    while (itr != uzytkownicy.end()){
        if (itr -> pobierzLogin() == login)/// tutaj przechodze po wektorze zawierajacym obiekty typu "Uzytkownik", dlatego nie uzywam kropek ani innych znakow
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--){
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo){
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> pobierzId(); return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            system("cls");
            idZalogowanegoUzytkownika = 0; return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    system("cls");
    idZalogowanegoUzytkownika = 0; return;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika(){
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++){
        if (itr -> pobierzId() == idZalogowanegoUzytkownika){
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wylogujUzytkownika(){
    idZalogowanegoUzytkownika = 0;
    cout << "Trwa wylogowywanie..." << endl << endl;
    system("pause");
    system("cls");
}

//gettery i settery
void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int nowyIdZalogowanegoUzytkownika){
    idZalogowanegoUzytkownika = nowyIdZalogowanegoUzytkownika;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}
