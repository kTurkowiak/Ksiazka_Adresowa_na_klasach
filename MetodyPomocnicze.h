#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class MetodyPomocnicze
{

public:
    static string wczytajLinie();
    static string konwerjsaIntNaString(int liczba);
    static char wczytajZnak();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int konwersjaStringNaInt(string liczba);


};

#endif
