#include <iostream>
#include <vector>
#include "UzytkownikMenager.h"

using namespace std;
class KsiazkaAdresowa{

    UzytkownikManager uzytkownikManager;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami):uzytkownikManager(nazwaPlikuZUzytkownikami){
        uzytkownikManager.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    int wylogowanieUzytkownika();

};

