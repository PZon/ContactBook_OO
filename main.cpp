#include <iostream>
#include "KsAdresowa.h"

using namespace std;

int main()
{
    int idZalogowanegoUzytkownika=0;
    int idOstatniegoAdresata=0;
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
   // ksiazkaAdresowa.rejestracjaUzytkownika();
    idZalogowanegoUzytkownika=ksiazkaAdresowa.logowanieUzytkownika();
        if(idZalogowanegoUzytkownika>0){
            idOstatniegoAdresata=ksiazkaAdresowa.pobierzZPlikuIdOstatniegoAdresata();
            ksiazkaAdresowa.wyswietlWszystkichAdresatow();
            ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
        }
   // ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
   // ksiazkaAdresowa.wylogowanieUzytkownika();


    return 0;
}
