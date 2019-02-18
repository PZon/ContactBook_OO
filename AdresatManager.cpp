#include <iostream>
#include <cstdlib>
#include "AdresatManager.h"
#include "MetodyPomocnicze.h"

int AdresatManager::dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata){
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatManager::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata){
    Adresat adresat;

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    string tmpTxt;

    cout << "Podaj imie: "; cin>>tmpTxt;
    tmpTxt=MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(tmpTxt);
    adresat.ustawImie(tmpTxt);

    cout << "Podaj nazwisko: "; cin>>tmpTxt;
   tmpTxt=MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(tmpTxt);
   adresat.ustawNazwisko(tmpTxt);

    cout << "Podaj numer telefonu: "; cin>>tmpTxt;
    adresat.ustawNrTelefonu(tmpTxt);

    cout << "Podaj email: "; cin>>tmpTxt;
    adresat.ustawEmail(tmpTxt);

    cout << "Podaj adres: "; cin>>tmpTxt;
    adresat.ustawAdres(tmpTxt);

    return adresat;
}

int AdresatManager::pobierzZPlikuIdOstatniegoAdresata(){
    plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata();
}
/*****************/
void AdresatManager::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

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









