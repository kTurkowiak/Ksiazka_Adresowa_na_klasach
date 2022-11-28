#include "PlikTekstowy.h"

bool PlikTekstowy::czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU.c_str(), ios::app);
    plikTekstowy.seekg(0, ios_base::end);
    if (plikTekstowy.tellg() == 0)
    {
        plikTekstowy.close();
        return true;
    }
    else
    {
        plikTekstowy.close();
        return false;
    }
}

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}
