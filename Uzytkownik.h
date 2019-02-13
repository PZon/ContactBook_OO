#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include <iostream>

using namespace std;
class Uzytkownik{
    int id;
    string login, haslo;
public:
    //Setter-y
    void ustawId(int noweId);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);
    //Getter-y
    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();
};
#endif

