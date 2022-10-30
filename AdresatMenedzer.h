#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;



class AdresatMenedzer
{

    vector <Adresat> adresaci;
    //PlikZAdresatami plikZAdresatami;

    //string nazwaPlikuZAdresatami;



public:
    //AdresatMenedzer(PlikZAdresatami PLIKZADRESATAMI): plikZAdresatami(PLIKZADRESATAMI) {};
    //AdresatMenedzer();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    //PlikZAdresatami();
    void dopiszAdresataDoPliku(Adresat adresat);

private:
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);

    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);





};







#endif
