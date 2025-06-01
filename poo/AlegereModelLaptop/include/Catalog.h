#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include "Laptop.h"
using namespace std;

class Catalog {
private:
    vector<Laptop> laptopuri;

public:
    void adaugaLaptop(const Laptop &laptop);
    void afiseazaCatalog() const;
    vector<Laptop> filtreazaDuPret(double pretMaxim) const;
    void salveazaInFisier(const string &numeFisier) const;
    void incarcaDinFisier(const string &numeFisier);
    vector<Laptop>& getLaptopuri();
    void sorteazaDupaPret();
    void sorteazaDupaPretDescrescator();
    vector<Laptop> filtreazaDupaBrand(const string& brand) const;
    vector<Laptop> filtreazaDupaProcesor(const string& procesor) const;
    vector<Laptop> filtreazaDupaRAM(int memorieRAM) const;
    vector<Laptop> filtreazaDupaPlacaVideo(const string& placaVideo) const;
};

#endif // CATALOG_H
