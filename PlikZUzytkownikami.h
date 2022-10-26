#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <fstream>
#include <vector>
#include <iostream>


#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami
{

    string nazwaPlikuZUzytkownikami;
    fstream plikTekstowy;


    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    bool czyPlikJestPusty();

public:
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    PlikZUzytkownikami();




};



#endif
