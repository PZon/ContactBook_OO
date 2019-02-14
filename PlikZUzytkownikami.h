#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"


using namespace std;
class PlikZUzytkownikami{
    const string nazwaPlikuZUzytkownikami;

public:
    PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI):nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    vector<Uzytkownik>wczytajUzytkownikowZPliku();
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    void zapiszWszystkichUzytkownikowDoPliku(vector<Uzytkownik>&);
};


