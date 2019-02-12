#include <iostream>
#include <vector>
#include "Uzytkownik.h"

using namespace std;
class KsiazkaAdresowa{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    vector<Uzytkownik>uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
public:
    void rejestracjaUzytkownika();
    bool czyIstniejeLogin(string login);
    void wypiszWszystkichUzytkownikow();
};

