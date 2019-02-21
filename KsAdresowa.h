#include <iostream>
#include <vector>
#include "UzytkownikMenager.h"
#include "AdresatManager.h"

using namespace std;
class KsiazkaAdresowa{

    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    :uzytkownikManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){
       adresatManager=NULL;
    };
    ~KsiazkaAdresowa(){
        delete adresatManager;
        adresatManager=NULL;
    }

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajAdresata();
    int pobierzZPlikuIdOstatniegoAdresata();
    void wyswietlWszystkichAdresatow();
    bool czyUzytkownikJestZalogowany();
    /****************/
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();

};

