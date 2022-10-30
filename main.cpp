#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");  //przesyla nazwe pliku do kolejnych klas wykorzystujac listy inicjalizacyjne w kolejnych klasach

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
   // ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
   // ksiazkaAdresowa.logowanieUzytkownika();
    int idZalogowanegoUzytkownika = 0;
    int idOstatniegoAdresata = 0;
    char wybor;

       while (true)
    {   cout<<" linia 21:idZalogowanegoUzytkownika w Menu glownym->"<<idZalogowanegoUzytkownika<<endl<<endl; // do pozniejszego usuniecia
        cout<<" linia 22:idOstatniegoAdresata w Menu glownym->"<<idOstatniegoAdresata<<endl<<endl; // do pozniejszego usuniecia
        if (idZalogowanegoUzytkownika == 0)
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();

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

            //if (adresaci.empty() == true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
            idOstatniegoAdresata = ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
            //    idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
            cout<<" linia 55:idOstatniegoAdresata w Menu glownym->"<<idOstatniegoAdresata<<endl<<endl; // do pozniejszego usuniecia
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                idOstatniegoAdresata = ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            //case '2':
            //    wyszukajAdresatowPoImieniu(adresaci);
            //    break;

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
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                break;

            case '8':
                idZalogowanegoUzytkownika = 0;
               //adresaci.clear();
                break;
            }
        }
    }
    return 0;
}
