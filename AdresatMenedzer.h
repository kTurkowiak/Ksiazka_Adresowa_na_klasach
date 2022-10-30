#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;



class AdresatMenedzer
{

    vector <Adresat> adresaci;
    //PlikZAdresatami plikZAdresatami;



public:
    AdresatMenedzer();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

private:
    Adresat podajDaneNowegoAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);
};







#endif
