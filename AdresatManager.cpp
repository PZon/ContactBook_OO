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

void AdresatManager::wyszukajAdresatowPoImieniu(){
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

          for (int i=0; i<adresaci.size();i++){
            if (adresaci[i].pobierzImie() == imiePoszukiwanegoAdresata){
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }

        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatManager::wyszukajAdresatowPoNazwisku(){
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (int i=0; i<adresaci.size();i++){
            if (adresaci[i].pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata){
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }

         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatManager::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow){
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

/*****************/
void AdresatManager::usunAdresata(){
    int idUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = MetodyPomocnicze::podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (int i=0; i<adresaci.size();i++){
        if (adresaci[i].pobierzId() == idUsuwanegoAdresata){
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.zapiszZmianyPoUsunieciu(idUsuwanegoAdresata);
                //adresaci.erase(adresaci.begin()+i,adresaci.begin()+i+6);
                adresaci.erase(adresaci.begin(),adresaci.end());

                cout << endl << endl << "Wybrany adresat zostal USUNIETY" << endl << endl;
                system("pause");
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }

    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}
/***************************************/
void AdresatManager::edytujAdresata()
{
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";
    string imie,nazwisko, numerTelefonu, email, adres;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = MetodyPomocnicze::podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i=0; i<adresaci.size();i++){
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                imie=MetodyPomocnicze::wczytajLinie();
                imie=MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
                adresaci[i].ustawImie(imie);
                plikZAdresatami.saveEditedChanges(idEdytowanegoAdresata);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                nazwisko=MetodyPomocnicze::wczytajLinie();
                nazwisko=MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
                adresaci[i].ustawNazwisko(nazwisko);
                plikZAdresatami.saveEditedChanges(idEdytowanegoAdresata);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                numerTelefonu=MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawNrTelefonu(numerTelefonu);
                plikZAdresatami.saveEditedChanges(idEdytowanegoAdresata);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                email=MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawEmail(email);
                plikZAdresatami.saveEditedChanges(idEdytowanegoAdresata);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                 adres=MetodyPomocnicze::wczytajLinie();
                 adresaci[i].ustawAdres(adres);
                 plikZAdresatami.saveEditedChanges(idEdytowanegoAdresata);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatManager::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

Adresat AdresatManager::uploadSingleContact(int contactId){
    Adresat adresat;
        for (int i=0; i<adresaci.size();i++){
            if(contactId==adresaci[i].pobierzId()){
                adresat.pobierzId();
                adresat.pobierzIdUzytkownika();
                adresat.pobierzImie();
                adresat.pobierzNazwisko();
                adresat.pobierzNrTelefonu();
                adresat.pobierzEmail();
                adresat.pobierzAdres();
            }
        }
    return adresat;
}





