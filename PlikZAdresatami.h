#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <algorithm>


#include "Adresat.h"
#include "MetodyPomocnicze.h"


using namespace std;
class PlikZAdresatami{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami):NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){
        idOstatniegoAdresata=0;
    }

    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    bool dopiszAdresataDoPliku(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    int pobierzZPlikuIdOstatniegoAdresata();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    vector<Adresat>wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void usunAdresatazPliku(int idUsuwanegoAdresata);
    void zapisWPlikuTymczasowym(Adresat adresat, string tmpPlik);
    void zaktualizujDaneAdresatawPliku(Adresat adresat);

};
#endif


