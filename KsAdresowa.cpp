#include <iostream>
#include <windows.h>
#include "KsAdresowa.h"

using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikManager.rejestracjaUzytkownika();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany(){
    uzytkownikManager.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
   uzytkownikManager.logowanieUzytkownika();
   if(uzytkownikManager.czyUzytkownikJestZalogowany()){
        adresatManager=new AdresatManager(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
   }
}
void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikManager.wylogowanieUzytkownika();
    delete adresatManager;
    adresatManager=NULL;
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::dodajAdresata(){
    adresatManager->dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatManager->wyswietlWszystkichAdresatow();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
/********************************/
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){
    adresatManager->wyszukajAdresatowPoImieniu();
}
void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){
    adresatManager->wyszukajAdresatowPoNazwisku();
}
