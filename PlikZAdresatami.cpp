#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "PlikZAdresatami.h"

using namespace std;

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat){
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);
    if (plikTekstowy.good() == true){
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

    if (czyPlikJestPusty() == true)
        {
           plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
           plikTekstowy << endl << liniaZDanymiAdresata ;
        }
         plikTekstowy.close();
        idOstatniegoAdresata++;

        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat){
    string liniaZDanymiAdresata;

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNrTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

bool PlikZAdresatami::czyPlikJestPusty(){
    fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)return true;
    else return false;
}

int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata(){
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
   {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
   }
    else
        return 0;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

vector<Adresat>PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector<Adresat>adresaci;
   // int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku=daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }
    if(daneOstaniegoAdresataWPliku!=""){
        idOstatniegoAdresata=pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }

        return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNrTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
/******************************************************************/
void PlikZAdresatami::zapiszZmianyPoUsunieciu(int idUsuwanegoAdresata){
    fstream odczytywanyPlikTekstowy;
    string daneAdresataOddzielonePionowymiKreskami;
    Adresat adresat;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(),ios::in);
    if (odczytywanyPlikTekstowy.good() == true){
        while(getline(odczytywanyPlikTekstowy,daneAdresataOddzielonePionowymiKreskami)){
            adresat=pobierzDaneAdresata(daneAdresataOddzielonePionowymiKreskami);
            if(daneAdresataOddzielonePionowymiKreskami!=""){
                if(idUsuwanegoAdresata==adresat.pobierzId()){
                   continue;
                }else{
                    saveContactsToTmpFile(adresat);
                }
            }
        }
        odczytywanyPlikTekstowy.close();
        remove(NAZWA_PLIKU_Z_ADRESATAMI.c_str());
        rename(NAZWA_TMP_PLIKU_Z_ADRESATAMI.c_str(),NAZWA_PLIKU_Z_ADRESATAMI.c_str());
    }else{
        cout << "ERROR: Contacts not saved." << endl;
        system("pause");
    }
}

void PlikZAdresatami::saveContactsToTmpFile(Adresat adresat){
    fstream tymczasowyPlikTekstowy;
    tymczasowyPlikTekstowy.open(NAZWA_TMP_PLIKU_Z_ADRESATAMI.c_str(),ios::out|ios::app);
    if (tymczasowyPlikTekstowy.good() == true){

        tymczasowyPlikTekstowy<<endl<<adresat.pobierzId()<<"|"<<adresat.pobierzIdUzytkownika()<<"|"<<adresat.pobierzImie()<<"|"
        <<adresat.pobierzNazwisko()<<"|"<<adresat.pobierzNrTelefonu()<<"|"<<adresat.pobierzEmail()<<"|"<<adresat.pobierzAdres()<<"|";
        tymczasowyPlikTekstowy.close();
    }else{
        cout << "ERROR: Contact not saved." << endl;
        system("pause");
    }
}

void PlikZAdresatami::saveEditedChanges(int idEdytowanegoAdresata, vector<Adresat>&adresaci){
    fstream odczytywanyPlikTekstowy;
    string daneAdresataOddzielonePionowymiKreskami;
    Adresat singleAdresat=uploadSingleContact(idEdytowanegoAdresata,adresaci);
    Adresat adresatCopy;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(),ios::in);
    if (odczytywanyPlikTekstowy.good() == true){
        while(getline(odczytywanyPlikTekstowy,daneAdresataOddzielonePionowymiKreskami)){
            adresatCopy=pobierzDaneAdresata(daneAdresataOddzielonePionowymiKreskami);
            if(daneAdresataOddzielonePionowymiKreskami!=""){
                if(idUsuwanegoAdresata==adresatCopy.pobierzId()){
                    saveContactsToTmpFile(singleAdresat);
                }else{
                    saveContactsToTmpFile(adresatCopy);
                }
            }
        }
        odczytywanyPlikTekstowy.close();
        remove(NAZWA_PLIKU_Z_ADRESATAMI.c_str());
        rename(NAZWA_TMP_PLIKU_Z_ADRESATAMI.c_str(),NAZWA_PLIKU_Z_ADRESATAMI.c_str());
        cout<<"\nZmiany zapisane!!!"<<endl; Sleep(2000);
    }else{
        cout << "Blad podczas zapisu." << endl;
        system("pause");
    }
}

Adresat PlikZAdresatami::uploadSingleContact(int contactId,vector<Adresat>&adresaci){

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




