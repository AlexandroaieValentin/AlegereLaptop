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
    void sorteazaDupaPret();
};

#endif // CATALOG_H
