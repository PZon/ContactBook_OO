#include <iostream>
#include "UzytkownikMenager.h"

using namespace std;

void UzytkownikManager::rejestracjaUzytkownika(){
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika(){
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;

    do
    {
        cout << "Podaj login: ";
        cin >>login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);
    return uzytkownik;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika(){
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikManager::czyIstniejeLogin(string login){
    for(int i=0; i<uzytkownicy.size();i++){
        if(uzytkownicy[i].pobierzLogin()==login){
        cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
         return true;
        }
    }
    return false;
}

void UzytkownikManager::wypiszWszystkichUzytkownikow(){
    for(int i=0; i<uzytkownicy.size(); i++){
        cout<<uzytkownicy[i].pobierzId()<<"|"<<uzytkownicy[i].pobierzLogin()
        <<"|"<<uzytkownicy[i].pobierzHaslo()<<"|"<<endl;
    }
}

void UzytkownikManager::logowanieUzytkownika(){
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login=MetodyPomocnicze::wczytajLinie();

    for(int i=0; i<uzytkownicy.size();i++){
        if (uzytkownicy[i].pobierzLogin() == login){
            for (int iloscProb = 3; iloscProb > 0; iloscProb--){
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo=MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo){
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idZalogowanegoUzytkownika=uzytkownicy[i].pobierzId();
                    system("pause");
                    return ;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return ;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return ;
}


int UzytkownikManager::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}

bool UzytkownikManager::czyUzytkownikJestZalogowany(){
    if(idZalogowanegoUzytkownika>0) return true;
    else return false;
}

void UzytkownikManager::wylogowanieUzytkownika(){
    cout<<"Zostales wylogowany";
    idZalogowanegoUzytkownika=0;
}

void UzytkownikManager::zmianaHaslaZalogowanegoUzytkownika(){
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (int i=0; i<uzytkownicy.size();i++){
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika){
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
   plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

