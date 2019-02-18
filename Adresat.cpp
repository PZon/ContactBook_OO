#include <iostream>
#include "Adresat.h"

using namespace std;
  //Setter-y
    void Adresat::ustawId(int noweId){
        if(noweId>=0) id=noweId;
    }
    void Adresat::ustawIdUzytkownika(int noweId){
        if(noweId>=0) idUzytkownika=noweId;
    }
    void Adresat::ustawImie(string nowyString){
        imie=nowyString;
    }
    void Adresat::ustawNazwisko(string nowyString){
        nazwisko=nowyString;
    }
    void Adresat::ustawNrTelefonu(string nowyString){
        numerTelefonu=nowyString;
    }
    void Adresat::ustawEmail(string nowyString){
        email=nowyString;
    }
    void Adresat::ustawAdres(string nowyString){
        adres=nowyString;
    }
    //Getter-y
     int Adresat::pobierzId(){
        return id;
    }
    int Adresat::pobierzIdUzytkownika(){
        return idUzytkownika;
    }
    string Adresat::pobierzImie(){
        return imie;
    }
    string Adresat::pobierzNazwisko(){
        return nazwisko;
    }
    string Adresat::pobierzNrTelefonu(){
        return numerTelefonu;
    }
    string Adresat::pobierzEmail(){
        return email;
    }
    string Adresat::pobierzAdres(){
        return adres;
    }

