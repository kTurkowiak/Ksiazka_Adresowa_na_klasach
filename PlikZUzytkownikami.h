#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <filesystem>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;


class PlikZUzytkownikami : public PlikTekstowy
{
    //const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;

    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : PlikTekstowy(nazwaPlikuZUzytkownikami) {};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
};



#endif
