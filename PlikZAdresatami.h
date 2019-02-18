#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Adresat.h"
#include "MetodyPomocnicze.h"


using namespace std;
class PlikZAdresatami{
    const string nazwaPlikuZAdresatami;

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI):nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI){};
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    void dopiszAdresataDoPliku(Adresat adresat);
    bool czyPlikJestPusty();
    int pobierzZPlikuIdOstatniegoAdresata();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    /****/
    vector<Adresat>wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

};


