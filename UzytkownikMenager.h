#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;
class UzytkownikManager{
    int idZalogowanegoUzytkownika;
    vector<Uzytkownik>uzytkownicy;


    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;
public:
    UzytkownikManager(string nazwaPlikuZUzytkownikami):plikZUzytkownikami(nazwaPlikuZUzytkownikami){};
    void rejestracjaUzytkownika();
    Uzytkownik podajDaneNowegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    int logowanieUzytkownika();
    int wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

 };
