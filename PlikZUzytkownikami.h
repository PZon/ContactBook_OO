#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"


using namespace std;
class PlikZUzytkownikami{
    string nazwaPlikuZUzytkownikami;
    fstream plikTekstowy;
public:
    PlikZUzytkownikami();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    void wczytajUzytkownikowZPliku(vector <Uzytkownik> &uzytkownicy);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
};


