#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
//#include "AdresatManager.h"


using namespace std;
class PlikZAdresatami{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_TMP_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami)
    :NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami),NAZWA_TMP_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami){
        idOstatniegoAdresata=0;
    };
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    bool dopiszAdresataDoPliku(Adresat adresat);
    bool czyPlikJestPusty();
    int pobierzZPlikuIdOstatniegoAdresata();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    vector<Adresat>wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void zapiszZmianyPoUsunieciu(int idUsuwanegoAdresata);
    void saveContactsToTmpFile(Adresat adresat);
    void saveEditedChanges(Adresat singleAdresat);

};
#endif


