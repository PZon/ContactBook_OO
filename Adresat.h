#ifndef ADRESAT_H
#define ADRESAT_H
#include <iostream>

using namespace std;
class Adresat{
    int id,idUzytkownika;
    string  imie, nazwisko, numerTelefonu , email, adres;
public:
    Adresat(int id=0, int idUzytkownika=0, string imie="", string nazwisko="",
            string numerTelefonu="", string email="", string adres=""){
                this->id=id;
                this->idUzytkownika=idUzytkownika;
                this->imie=imie;
                this->nazwisko=nazwisko;
                this->numerTelefonu=numerTelefonu;
                this->email=email;
                this->adres=adres;
            }

    //Setter-y
    void ustawId(int noweId);
    void ustawIdUzytkownika(int noweId);
    void ustawImie(string nowyString);
    void ustawNazwisko(string nowyString);
    void ustawNrTelefonu(string nowyString);
    void ustawEmail(string nowyString);
    void ustawAdres(string nowyString);
    //Getter-y
    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNrTelefonu();
    string pobierzEmail();
    string pobierzAdres();
};
#endif

