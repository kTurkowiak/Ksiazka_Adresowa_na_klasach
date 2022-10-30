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
    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlWszystkichAdresatow();
    //PlikZAdresatami();
    void dopiszAdresataDoPliku(Adresat adresat);

private:
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);

    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);





};







#endif
