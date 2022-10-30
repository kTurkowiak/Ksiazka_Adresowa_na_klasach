#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;



class AdresatMenedzer
{

    vector <Adresat> adresaci;
    //PlikZAdresatami plikZAdresatami;


public:
    AdresatMenedzer();
    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();
};







#endif
