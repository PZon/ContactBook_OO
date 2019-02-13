#include <iostream>
#include <windows.h>
#include "KsAdresowa.h"

using namespace std;
KsiazkaAdresowa::KsiazkaAdresowa(){
    uzytkownikManager.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}
