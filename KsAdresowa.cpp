#include <iostream>
#include <windows.h>
#include "KsAdresowa.h"

using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}
int KsiazkaAdresowa::logowanieUzytkownika(){
    int idZalogowanegoUzytkownika=0;
    idZalogowanegoUzytkownika=uzytkownikManager.logowanieUzytkownika();
    if(idZalogowanegoUzytkownika>0) adresatManager.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);

    return idZalogowanegoUzytkownika;
}

int KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikManager.wylogowanieUzytkownika();
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}
int KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata){
    adresatManager.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
}

int KsiazkaAdresowa::pobierzZPlikuIdOstatniegoAdresata(){
    adresatManager.pobierzZPlikuIdOstatniegoAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatManager.wyswietlWszystkichAdresatow();
}
/*void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika){
    adresatManager.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}*/
