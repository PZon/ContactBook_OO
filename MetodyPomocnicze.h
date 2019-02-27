#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
class MetodyPomocnicze{
public:
      static string konwerjsaIntNaString(int liczba);
      static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
      static int konwersjaStringNaInt(string liczba);
      static string pobierzLiczbe(string tekst, int pozycjaZnaku);
      static string wczytajLinie();
      static char wczytajZnak();
      static int podajIdWybranegoAdresata();
      static int wczytajLiczbeCalkowita();



};
#endif
