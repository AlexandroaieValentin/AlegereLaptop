#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "Laptop.h"
#include "Catalog.h"
#include "Review.h"
#include <sstream>
using namespace std;

void clearConsole()
{
    system("cls");
}

void afiseazaMeniuPrincipal()
{
    cout << "\n";
    cout << "+-----------------------------------------------+\n";
    cout << "|         CATALOGUL DE LAPTOPURI - LOGIN        |\n";
    cout << "+-----------------------------------------------+\n";
    cout << "| Alege un rol pentru a continua:               |\n";
    cout << "|                                               |\n";
    cout << "|  1. Administrator                             |\n";
    cout << "|  2. Utilizator                                |\n";
    cout << "|  3. Iesire                                    |\n";
    cout << "+-----------------------------------------------+\n";
    cout << ">> Introdu rolul: ";
}


void afiseazaMeniuAdministrator()
{
    cout << "\n";
    cout << "+------------------------------------------------------+\n";
    cout << "|                  MENIU ADMINISTRATOR                 |\n";
    cout << "+------------------------------------------------------+\n";
    cout << "|  1. Adauga un laptop                                 |\n";
    cout << "|  2. Afiseaza catalogul complet                       |\n";
    cout << "|  3. Sorteaza catalogul dupa pret (crescator)         |\n";
    cout << "|  4. Cauta laptopuri dupa pret maxim                  |\n";
    cout << "|  5. Salveaza catalogul in fisier                     |\n";
    cout << "|  6. Schimba rolul                                    |\n";
    cout << "|  7. Iesire din program                               |\n";
    cout << "+------------------------------------------------------+\n";
    cout << ">> Alege optiunea: ";
}


void afiseazaMeniuUtilizator()
{
    cout << "\n";
    cout << "+------------------------------------------------------+\n";
    cout << "|                   MENIU UTILIZATOR                   |\n";
    cout << "+------------------------------------------------------+\n";
    cout << "|  1. Afiseaza catalogul complet                       |\n";
    cout << "|  2. Sorteaza dupa pret (crescator)                   |\n";
    cout << "|  3. Sorteaza dupa pret (descrescator)                |\n";
    cout << "|  4. Cauta dupa pret maxim                            |\n";
    cout << "|  5. Cauta dupa brand                                 |\n";
    cout << "|  6. Cauta dupa procesor                              |\n";
    cout << "|  7. Cauta dupa memorie RAM                           |\n";
    cout << "|  8. Cauta dupa placa video                           |\n";
    cout << "|  9. Salveaza review-urile in fisier                  |\n";
    cout << "| 10. Adauga review la un laptop                       |\n";
    cout << "| 11. Schimba rolul                                    |\n";
    cout << "| 12. Iesire din program                               |\n";
    cout << "+------------------------------------------------------+\n";
    cout << ">> Alege optiunea: ";
}



Laptop citesteLaptop()
{
    string brand, model, procesor, rezolutie, placaGrafica, baterieStr;
    double pret;
    int memorieRAM, stocare, baterie;

    // Citire brand si model
    cout << "Introdu brand: ";
    getline(cin, brand);
    cout << "Introdu model: ";
    getline(cin, model);

    // Citire si validare pret
    while (true)
    {
        cout << "Introdu pret: ";
        cin >> pret;
        if (cin.fail() || pret <= 0)
        {
            cin.clear(); // Șterge eroarea
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora restul liniei
            cout << "Pretul trebuie sa fie un numar valid si pozitiv!\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // sterge restul liniei
            break;
        }
    }

    // Citire procesor
    cout << "Introdu procesor: ";
    getline(cin, procesor);

    // Citire si validare memorie RAM
    while (true)
    {
        cout << "Introdu memorie RAM (GB): ";
        cin >> memorieRAM;
        if (cin.fail() || memorieRAM <= 0)
        {
            cin.clear(); // sterge eroarea
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora restul liniei
            cout << "Memoria RAM trebuie sa fie un numar valid si pozitiv!\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // sterge restul liniei
            break;
        }
    }

    // Citire si validare stocare
    while (true)
    {
        cout << "Introdu stocare (GB): ";
        cin >> stocare;
        if (cin.fail() || stocare <= 0)
        {
            cin.clear(); // Șterge eroarea
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora restul liniei
            cout << "Stocarea trebuie sa fie un numar valid si pozitiv!\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // sterge restul liniei
            break;
        }
    }

    // Citire rezolutie ecran
    cout << "Introdu rezolutie ecran (ex: 1920x1080): ";
    getline(cin, rezolutie);

    // Citire placa grafica
    cout << "Introdu placa grafica: ";
    getline(cin, placaGrafica);

    // Citire si validare baterie
    while (true)
    {
        cout << "Introdu capacitate baterie (mAh): ";
        getline(cin, baterieStr); // Citim ca string pentru a verifica input-ul

        // incercam sa convertim stringul intr-un numar intreg
        stringstream ss(baterieStr);
        if (ss >> baterie && baterie > 0)
        {
            break; // Valid daca conversia are succes si numarul este pozitiv
        }
        else
        {
            cout << "Bateria trebuie sa fie un numar valid si pozitiv (in mAh)!\n";
        }
    }

    // Returneaza un laptop validat
    return Laptop(brand, model, pret, procesor, memorieRAM, stocare, rezolutie, placaGrafica, to_string(baterie) + " mAh");
}




void meniuAdministrator(Catalog& catalog)
{
    bool ruleaza = true;
    while (ruleaza)
    {
        afiseazaMeniuAdministrator();

        string input;
        int optiune;
        getline(cin, input);
        stringstream ss(input);
        if (!(ss >> optiune) || !ss.eof())
        {
            cout << "Optiune invalida! Introdu un numar valid.\n";
            continue;
        }
        switch (optiune)
        {
        case 1:
        {
            Laptop laptopNou = citesteLaptop();
            catalog.adaugaLaptop(laptopNou);
            cout << "Laptop adaugat in catalog.\n";
            break;
        }
        case 2:
            catalog.afiseazaCatalog();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 3:
            catalog.sorteazaDupaPret();
            cout << "Catalogul a fost sortat dupa pret.\n";
            break;
        case 4:
        {
            double pretMaxim;
            cout << "Introdu pretul maxim: ";
            cin >> pretMaxim;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            auto laptopuriGasite = catalog.filtreazaDuPret(pretMaxim);
            if (laptopuriGasite.empty())
                cout << "Nu s-au gasit laptopuri sub pretul " << pretMaxim << " lei.\n";
            else
            {
                cout << "\nLaptopurile gasite:\n";
                for (const auto& lap : laptopuriGasite) lap.afiseazaInfo();
            }
            break;
        }
        case 5:
            catalog.salveazaInFisier("laptopuri.txt");
            cout << "Catalog salvat in fisier.\n";
            break;
        case 6:
            clearConsole();
            ruleaza = false;
            break;
        case 7:
            exit(0);
        default:
            cout << "Optiune invalida!\n";
        }
    }
}

void meniuUtilizator(Catalog& catalog)
{
    bool ruleaza = true;
    while (ruleaza)
    {
        afiseazaMeniuUtilizator();

        string input;
        int optiune;
        getline(cin, input);
        stringstream ss(input);
        if (!(ss >> optiune) || !ss.eof())
        {
            cout << "Optiune invalida! Introdu un numar valid.\n";
            continue;
        }
        switch (optiune)
        {
        case 1:
            catalog.afiseazaCatalog();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 2:
            catalog.sorteazaDupaPret();
            cout << "Catalogul a fost sortat crescator.\n";
            break;
        case 3:
            catalog.sorteazaDupaPretDescrescator();
            cout << "Catalogul a fost sortat descrescator.\n";
            break;
        case 4:
        {
            string input;
            double pretMaxim;
            cout << "Introdu pretul maxim: ";
            getline(cin, input);
            stringstream ss(input);
            if (!(ss >> pretMaxim) || pretMaxim <= 0)
            {
                cout << "Pret invalid! Introdu un numar pozitiv.\n";
                break;
            }

            auto rezultate = catalog.filtreazaDuPret(pretMaxim);
            if (rezultate.empty()) cout << "Nu s-au gasit laptopuri sub pretul de " << pretMaxim << ".\n";
            else catalog.afiseazaLaptopuriPaginat(rezultate);
            break;
        }



        case 5:
        {
            string brand;
            cout << "Introdu brandul: ";
            getline(cin, brand);
            auto rezultate = catalog.filtreazaDupaBrand(brand);
            if (rezultate.empty())
                cout << "Nu s-au gasit laptopuri cu brandul " << brand << ".\n";
            else
                catalog.afiseazaLaptopuriPaginat(rezultate);
            break;
        }
        case 6:
        {
            string procesor;
            cout << "Introdu procesorul: ";
            getline(cin, procesor);
            auto rezultate = catalog.filtreazaDupaProcesor(procesor);
            if (rezultate.empty()) cout << "Nu s-au gasit laptopuri cu procesorul " << procesor << ".\n";
            else catalog.afiseazaLaptopuriPaginat(rezultate);
            break;
        }

        case 7:
        {
            string input;
            int ram;
            cout << "Introdu cantitatea de RAM (GB): ";
            getline(cin, input);
            stringstream ss(input);
            if (!(ss >> ram) || ram <= 0)
            {
                cout << "Memoria RAM trebuie sa fie un numar pozitiv!\n";
                break;
            }

            auto rezultate = catalog.filtreazaDupaRAM(ram);
            if (rezultate.empty()) cout << "Nu s-au gasit laptopuri cu " << ram << " GB RAM.\n";
            else catalog.afiseazaLaptopuriPaginat(rezultate);
            break;
        }


        case 8:
        {
            string placaVideo;
            cout << "Introdu placa video: ";
            getline(cin, placaVideo);
            auto rezultate = catalog.filtreazaDupaPlacaVideo(placaVideo);
            if (rezultate.empty()) cout << "Nu s-au gasit laptopuri cu placa video " << placaVideo << ".\n";
            else catalog.afiseazaLaptopuriPaginat(rezultate);
            break;
        }

        case 9:
            catalog.salveazaInFisier("laptopuri.txt");
            cout << "Review-urile au fost salvate.\n";
            break;
        case 10:
        {
            string brand, model;
            cout << "Introdu brandul laptopului: ";
            getline(cin, brand);
            cout << "Introdu modelul laptopului: ";
            getline(cin, model);

            bool gasit = false;
            for (auto& laptop : catalog.getLaptopuri())
            {
                if (laptop.getBrand() == brand && laptop.getModel() == model)
                {
                    gasit = true;
                    int rating;
                    string comentariu;
                    cout << "Introdu ratingul (1-5): ";
                    cin >> rating;
                    cin.ignore();

                    cout << "Vrei sa adaugi un comentariu? (da/nu): ";
                    string raspuns;
                    getline(cin, raspuns);
                    if (raspuns == "da")
                    {
                        cout << "Comentariu: ";
                        getline(cin, comentariu);
                    }
                    laptop.adaugaReview(Review(rating, comentariu));
                    cout << "Review adaugat cu succes.\n";
                    break;
                }
            }
            if (!gasit) cout << "Laptopul nu a fost gasit.\n";
            break;
        }

        case 11:
            clearConsole();
            ruleaza = false;
            break;
        case 12:
            exit(0);


        default:
            cout << "Optiune invalida!\n";
        }
    }
}

int main()
{
    Catalog catalog;
    catalog.incarcaDinFisier("laptopuri.txt");

    while (true)
    {
        string rol;
        afiseazaMeniuPrincipal();
        getline(cin, rol);

        for (auto& c : rol) c = tolower(c);

        if (rol == "3" || rol == "iesire")
        {
            cout << "Iesire din program.\n";
            break;
        }
        else if (rol == "1" || rol == "administrator")
        {
            clearConsole();
            meniuAdministrator(catalog);
        }
        else if (rol == "2" || rol == "utilizator")
        {
            clearConsole();
            meniuUtilizator(catalog);
        }
        else
        {
            cout << "Rol invalid! Te rog introdu '1' sau 'administrator', '2' sau 'utilizator', ori '3' sau 'iesire'.\n";
        }
    }
    return 0;
}
