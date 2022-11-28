#include "PlikZAdresatami.h"

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);
    if (plikTekstowy.good())
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
        if (czyPlikJestPusty())
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    idOstatniegoAdresata++;
    plikTekstowy.close();
    system("pause");
}

bool PlikZAdresatami::czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
    {
        plikTekstowy.close();
        return true;
    }
    else
    {
        plikTekstowy.close();
        return false;
    }
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdAdresata()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';
    return liniaZDanymiAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    if (plikTekstowy.good())
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
        idOstatniegoAdresata = 0;
    }
    plikTekstowy.close();
    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return adresaci;
    }
    else
    {
        idOstatniegoAdresata = 0;
        return adresaci;
    }
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
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
    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
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
                adresat.ustawIdAdresata(atoi(pojedynczaDanaAdresata.c_str()));

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
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);

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

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunAdresataZpliku(int idUsuwanegoAdresata)
{
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);
    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (odczytywanyPlikTekstowy.good() && idUsuwanegoAdresata != 0)
    {
        while(getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idUsuwanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                czyIstniejeAdresat = true;
                numerLiniiWPlikuTekstowym++;
            }
            else
            {
                if (numerLiniiWPlikuTekstowym == 1)
                {
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                    idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami);
                    numerLiniiWPlikuTekstowym++;
                }
                else if ((numerLiniiWPlikuTekstowym == 2) && (czyIstniejeAdresat == true))
                {
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                    idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami);
                    numerLiniiWPlikuTekstowym++;
                }
                else
                {
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                    idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami);
                    numerLiniiWPlikuTekstowym++;
                }
            }
        }
        if (czyIstniejeAdresat == false)
        {
            odczytywanyPlikTekstowy.close();
            tymczasowyPlikTekstowy.close();
            cout << endl << endl << "Nie znaleziono adresata w ksiazce adresowej." << endl << endl;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
    }
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";
    zaktualizujDaneWybranegoAdresataWPliku (adresat);
    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresataWPliku(Adresat adresat)
{
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    int idEdytowanegoAdresata = adresat.pobierzIdAdresata();
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    string liniaZDanymiEdytowanegoAdresata;
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);
    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    if ((odczytywanyPlikTekstowy.good()) && (idEdytowanegoAdresata != 0))
    {
        while(getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                if (numerLiniiWPlikuTekstowym == 1)
                {
                    liniaZDanymiEdytowanegoAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
                    tymczasowyPlikTekstowy << liniaZDanymiEdytowanegoAdresata;
                    czyIstniejeAdresat = true;
                    numerLiniiWPlikuTekstowym++;
                }
                else if (numerLiniiWPlikuTekstowym > 1)
                {
                    liniaZDanymiEdytowanegoAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
                    tymczasowyPlikTekstowy << endl << liniaZDanymiEdytowanegoAdresata;
                    czyIstniejeAdresat = true;
                    numerLiniiWPlikuTekstowym++;
                }
            }
            else
            {
                if (numerLiniiWPlikuTekstowym == 1)
                {
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                    numerLiniiWPlikuTekstowym++;
                }
                else if (numerLiniiWPlikuTekstowym > 1)
                {
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                    numerLiniiWPlikuTekstowym++;
                }
            }
        }
        if (czyIstniejeAdresat = false)
        {
            cout << endl << endl << "Nie znaleziono adresata w ksiazce adresowej." << endl << endl;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);

    }
}
