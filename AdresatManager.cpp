#include <iostream>
#include <cstdlib>
#include "AdresatManager.h"
#include "MetodyPomocnicze.h"

void AdresatManager::dodajAdresata(){
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat)){
        cout<<"Nowy adresat zostal dodany"<<endl;
    }else cout<<"Blad. Nie udalo sie dodac nowego adresata do pliku";
    system("pause");

}

Adresat AdresatManager::podajDaneNowegoAdresata(){
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    string imie,nazwisko, numerTelefonu, email, adres;

    cout << "Podaj imie: ";
    imie=MetodyPomocnicze::wczytajLinie();
    imie=MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    nazwisko=MetodyPomocnicze::wczytajLinie();
    nazwisko=MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu=MetodyPomocnicze::wczytajLinie();
    adresat.ustawNrTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    email=MetodyPomocnicze::wczytajLinie();
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    adres=MetodyPomocnicze::wczytajLinie();
    adresat.ustawAdres(adres);

    return adresat;
}

int AdresatManager::pobierzZPlikuIdOstatniegoAdresata(){
    plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata();

}
/*****************/

void AdresatManager::wyswietlWszystkichAdresatow(){
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i=0; i<adresaci.size(); i++)
        {
            wyswietlDaneAdresata(adresaci[i]);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatManager::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNrTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}









