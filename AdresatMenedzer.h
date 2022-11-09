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
    PlikZAdresatami plikZAdresatami;
    int ID_ZALOGOWANEGO_UZYTKOWNIKA;


public:

    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();

    AdresatMenedzer(string nazwaPlikuZAdresatami)
        : plikZAdresatami(nazwaPlikuZAdresatami)
        {
            //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
        }
    void dopiszAdresataDoPliku(Adresat adresat);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);



private:
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);


};


/*
    AdresatMenedzer(string nazwaPlikuZAdresatami, int IdZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(IdZalogowanegoUzytkownika) {
            adresaci = PlikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(
    };
*/




#endif
