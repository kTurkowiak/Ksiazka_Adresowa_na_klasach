#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>


#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"


using namespace std;

class PlikZAdresatami
{
   const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;


public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {};     //stworzernie konstruktora z lista inicjalizacyjna, tak aby byla przyporzadkowana stala cons "Adresaci.txt"
    void dopiszAdresataDoPliku(Adresat adresat);


    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();

private:

    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);



};

//


#endif

