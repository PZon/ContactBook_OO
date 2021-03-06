#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H
#include <iostream>
#include <vector>
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenager.h"


using namespace std;
class AdresatManager{

   const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector<Adresat>adresaci;
    PlikZAdresatami plikZAdresatami;

public:
    AdresatManager(string nazwaPlikuZAdresatami,int idZalogowanegoUzytkownika)
    :plikZAdresatami(nazwaPlikuZAdresatami),ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();
    int pobierzZPlikuIdOstatniegoAdresata();
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    void usunAdresata();
    void edytujAdresata();
    char wybierzOpcjeZMenuEdycja();
};
#endif


