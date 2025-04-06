#include <iostream>
#include <string>
#include <limits>
#include "Laptop.h"
#include "Catalog.h"
#include "Review.h"
using namespace std;


Laptop citesteLaptop() {
    string brand, model, procesor, rezolutie, placaGrafica, baterie;
    double pret;
    int memorieRAM, stocare;

    cout << "Introdu brand: ";
    getline(cin, brand);
    cout << "Introdu model: ";
    getline(cin, model);
    cout << "Introdu pret: ";
    cin >> pret;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Introdu procesor: ";
    getline(cin, procesor);
    cout << "Introdu memorie RAM (GB): ";
    cin >> memorieRAM;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Introdu stocare (GB): ";
    cin >> stocare;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Introdu rezolutie ecran (ex: 1920x1080): ";
    getline(cin, rezolutie);
    cout << "Introdu placa grafica: ";
    getline(cin, placaGrafica);
    cout << "Introdu baterie (ex: 4500 mAh): ";
    getline(cin, baterie);

    return Laptop(brand, model, pret, procesor, memorieRAM, stocare, rezolutie, placaGrafica, baterie);
}

int main() {
    Catalog catalog;
    int optiune = 0;

    do {
        cout << "Meniu:\n";
        cout << "1. Adauga un laptop\n";
        cout << "2. Afiseaza catalogul complet\n";
        cout << "3. Sorteaza catalogul dupa pret (crescator)\n";
        cout << "4. Cauta laptopuri dupa pret maxim\n";
        cout << "5. Iesire\n";
        cout << "Alege optiunea: ";
        cin >> optiune;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(optiune) {
            case 1: {
                Laptop laptopNou = citesteLaptop();
                catalog.adaugaLaptop(laptopNou);
                cout << "Laptop adaugat in catalog.\n";
                break;
            }
            case 2: {
                cout << "\nCatalogul complet de laptopuri:\n";
                catalog.afiseazaCatalog();
                break;
            }
            case 3: {
                catalog.sorteazaDupaPret();
                cout << "Catalogul a fost sortat dupa pret.\n";
                break;
            }
            case 4: {
                double pretMaxim;
                cout << "Introdu pretul maxim: ";
                cin >> pretMaxim;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                vector<Laptop> laptopuriGasite = catalog.filtreazaDuPret(pretMaxim);
                if (laptopuriGasite.empty())
                    cout << "Nu s-au gasit laptopuri sub pretul " << pretMaxim << " lei.\n";
                else {
                    cout << "\nLaptopurile gasite:\n";
                    for (const auto &lap : laptopuriGasite) {
                        lap.afiseazaInfo();
                    }
                }
                break;
            }
            case 5: {
                cout << "Iesire din program.\n";
                break;
            }
            default: {
                cout << "Optiune invalida! Te rog alege din nou.\n";
                break;
            }
        }
    } while(optiune != 5);

    return 0;
}
