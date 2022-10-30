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
    //AdresatMenedzer(PlikZAdresatami PLIKZADRESATAMI): plikZAdresatami(PLIKZADRESATAMI) {};
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();

private:
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);
};







#endif
