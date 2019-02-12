#include <iostream>
#include <vector>
#include "Uzytkownik.h"

using namespace std;
class KsiazkaAdresowa{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    string nazwaPlikuZUzytkownikami;


    vector<Uzytkownik>uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    string konwerjsaIntNaString(int liczba);
    bool czyPlikJestPusty(fstream &plikTekstowy);


public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    bool czyIstniejeLogin(string login);
    void wypiszWszystkichUzytkownikow();
};

