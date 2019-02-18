#include <iostream>
#include <vector>
#include "UzytkownikMenager.h"
#include "AdresatManager.h"

using namespace std;
class KsiazkaAdresowa{

    UzytkownikManager uzytkownikManager;
    AdresatManager adresatManager;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    :uzytkownikManager(nazwaPlikuZUzytkownikami), adresatManager(nazwaPlikuZAdresatami){
        uzytkownikManager.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    int wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();
    void wyswietlWszystkichAdresatow();

};

