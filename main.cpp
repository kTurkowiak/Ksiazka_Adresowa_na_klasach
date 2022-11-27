#include <iostream>

#include "KsiazkaAdresowa.h"

//Dodaj do aplikacji obiektowej pozosta�e funkcjonalno�ci w tym zwr�� szczeg�ln� uwag�, aby stworzy� edycj� i
//usuwanie adresata w spos�b optymalny przedstawiony na powy�szym seminarium.
//Nie zapomnij o funkcjonalno�ciach wyszukiwania adresat�w po imieniu jak i po nazwisku.



//Wykonaj dziedziczenie klasy PlikzZUzytkownikami i PlikZAdresatami

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");
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
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //idUsunietegoAdresata = usunAdresata(adresaci);
                ksiazkaAdresowa.usunAdresata();
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            //case '6':
            //    edytujAdresata(adresaci);
            //    break;
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
