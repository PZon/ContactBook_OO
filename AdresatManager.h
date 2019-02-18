#include <iostream>
#include <vector>
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenager.h"

using namespace std;
class AdresatManager{
    int idOstatniegoAdresata;
    vector<Adresat>adresaci;
    PlikZAdresatami plikZAdresatami;

public:
    AdresatManager(string nazwaPlikuZAdresatami):plikZAdresatami(nazwaPlikuZAdresatami){};
    int dodajAdresata(int idZalogowanegoUzytkownika,int idOstatniegoAdresata);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika,int idOstatniegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();
/*********************/
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void wyswietlDaneAdresata(Adresat adresat);

};


