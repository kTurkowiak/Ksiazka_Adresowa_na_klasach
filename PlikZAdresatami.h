#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <iostream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    string nazwaPlikuZAdresatami;

public:
    PlikZAdresatami();
    void dopiszAdresataDoPliku();

private:

    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);



};




#endif
