#include "Catalog.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

void Catalog::adaugaLaptop(const Laptop &laptop) {
    laptopuri.push_back(laptop);
}

void Catalog::afiseazaCatalog() const {
    const int laptopuriPePagina = 5;
    int total = laptopuri.size();
    int paginaCurenta = 0;
    char optiune;

    if (total == 0) {
        cout << "Catalogul este gol.\n";
        return;
    }

    do {
        system("cls"); // curăță ecranul (pe Windows).
        int start = paginaCurenta * laptopuriPePagina;
        int end = min(start + laptopuriPePagina, total);

        cout << "\n--- Afisare Laptopuri (pagina " << paginaCurenta + 1 << " din " << (total + laptopuriPePagina - 1) / laptopuriPePagina << ") ---\n\n";

        for (int i = start; i < end; ++i) {
            cout << "Laptop #" << i + 1 << ":\n";
            laptopuri[i].afiseazaInfo();
            cout << "-------------------------------\n";
        }

        cout << "[n] Pagina urmatoare | [p] Pagina anterioara | [x] Iesire afisare\n";
        cout << "Alege optiune: ";
        cin >> optiune;
        optiune = tolower(optiune);

        if (optiune == 'n' && end < total) {
            ++paginaCurenta;
        } else if (optiune == 'p' && paginaCurenta > 0) {
            --paginaCurenta;
        } else if (optiune != 'x') {
            cout << "Optiune invalida.\n";
        }

    } while (optiune != 'x');
}

vector<Laptop> Catalog::filtreazaDuPret(double pretMaxim) const {
    vector<Laptop> filtrate;
    for (const auto &laptop : laptopuri) {
        if (laptop.getPret() <= pretMaxim)
            filtrate.push_back(laptop);
    }
    return filtrate;
}

void Catalog::sorteazaDupaPret() {
    sort(laptopuri.begin(), laptopuri.end(), [](const Laptop &a, const Laptop &b) {
        return a.getPret() < b.getPret();
    });
}
void Catalog::sorteazaDupaPretDescrescator() {
    sort(laptopuri.begin(), laptopuri.end(), [](const Laptop &a, const Laptop &b) {
        return a.getPret() > b.getPret();
    });
}
void Catalog::salveazaInFisier(const string& numeFisier) const {
    ofstream fout(numeFisier);

    for (const auto& laptop : laptopuri) {
        fout << laptop.getBrand() << "\n";
        fout << laptop.getModel() << "\n";
        fout << laptop.getPret() << "\n";
        fout << laptop.getProcesor() << "\n";
        fout << laptop.getMemorieRAM() << "\n";
        fout << laptop.getStocare() << "\n";
        fout << laptop.getRezolutieEcran() << "\n";
        fout << laptop.getPlacaGrafica() << "\n";
        fout << laptop.getBaterie() << "\n";


        fout << laptop.getReviews().size() << "\n";
        for (const auto& review : laptop.getReviews()) {
            fout << review.getRating() << "\n";
            fout << review.getComment() << "\n";
        }
    }

    fout.close();
}

void Catalog::incarcaDinFisier(const string &numeFisier) {
    ifstream fin(numeFisier);
    string brand, model, procesor, rezolutie, placaGrafica, baterie;
    double pret;
    int memorieRAM, stocare;

    while (getline(fin, brand) &&
           getline(fin, model) &&
           fin >> pret &&
           fin.ignore() &&
           getline(fin, procesor) &&
           fin >> memorieRAM &&
           fin.ignore() &&
           fin >> stocare &&
           fin.ignore() &&
           getline(fin, rezolutie) &&
           getline(fin, placaGrafica) &&
           getline(fin, baterie)) {

        Laptop l(brand, model, pret, procesor, memorieRAM, stocare, rezolutie, placaGrafica, baterie);

        int nrReviewuri;
        if (fin >> nrReviewuri) {
            fin.ignore();
            for (int i = 0; i < nrReviewuri; ++i) {
                int rating;
                string comentariu;
                fin >> rating;
                fin.ignore();
                getline(fin, comentariu);
                l.adaugaReview(Review(rating, comentariu));
            }
        } else {
            fin.clear();
        }

        laptopuri.push_back(l);
    }
}


vector<Laptop>& Catalog::getLaptopuri() {
    return laptopuri;
}
vector<Laptop> Catalog::filtreazaDupaBrand(const string& brand) const {
    vector<Laptop> rezultate;
    for (const auto& laptop : laptopuri) {
        if (laptop.getBrand() == brand)
            rezultate.push_back(laptop);
    }
    return rezultate;
}

vector<Laptop> Catalog::filtreazaDupaProcesor(const string& procesor) const {
    vector<Laptop> rezultate;
    for (const auto& laptop : laptopuri) {
        if (laptop.getProcesor() == procesor)
            rezultate.push_back(laptop);
    }
    return rezultate;
}
vector<Laptop> Catalog::filtreazaDupaRAM(int memorieRAM) const {
    vector<Laptop> rezultate;
    for (const auto& laptop : laptopuri) {
        if (laptop.getMemorieRAM() == memorieRAM)
            rezultate.push_back(laptop);
    }
    return rezultate;
}

vector<Laptop> Catalog::filtreazaDupaPlacaVideo(const string& placaVideo) const {
    vector<Laptop> rezultate;
    for (const auto& laptop : laptopuri) {
        if (laptop.getPlacaGrafica() == placaVideo)
            rezultate.push_back(laptop);
    }
    return rezultate;
}

void Catalog::afiseazaLaptopuriPaginat(const vector<Laptop>& lista, int pePagina) const {
    if (lista.empty()) {
        cout << "Nu exista laptopuri de afisat.\n";
        return;
    }

    int total = lista.size();
    int pagini = (total + pePagina - 1) / pePagina;
    int paginaCurenta = 0;

    while (true) {
        system("cls"); // sterge consola pentru o afisare mai clara (sau poti comenta pe Linux)

        cout << "Pagina " << paginaCurenta + 1 << " din " << pagini << "\n";
        cout << "--------------------------------------\n";

        int start = paginaCurenta * pePagina;
        int end = min(start + pePagina, total);

        for (int i = start; i < end; ++i) {
            lista[i].afiseazaInfo();
            cout << "--------------------------------------\n";
        }

        cout << "Navigare: [n] | [p]| [x]\n>> ";
        string optiune;
        getline(cin, optiune);

        if (optiune == "n" && paginaCurenta < pagini - 1)
            paginaCurenta++;
        else if (optiune == "p" && paginaCurenta > 0)
            paginaCurenta--;
        else if (optiune == "x")
            break;
    }
}


