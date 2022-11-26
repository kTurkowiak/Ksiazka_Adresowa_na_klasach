#include <iostream>

#include "KsiazkaAdresowa.h"

//skonwertowaæ ID zalogowanego uzytkownika w klasie Adresaci Menedzer do wskaznika i przerobic go na liste inicjalizujaca/wskaznik




using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");  //przesyla nazwe pliku do kolejnych klas wykorzystujac listy inicjalizacyjne w kolejnych klasach

    char wybor;

       while (true)
    {

        if (!ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            //case '2':
            //    wyszukajAdresatowPoImieniu(adresaci);
                //break;

            //case '3':
            //    wyszukajAdresatowPoNazwisku(adresaci);
            //    break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
                /*
            case '5':
                idUsunietegoAdresata = usunAdresata(adresaci);
                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                edytujAdresata(adresaci);
                break;
            */
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;

            case '8':
                ksiazkaAdresowa.wylogowanie();
                break;
            }
        }
    }
    return 0;
}
