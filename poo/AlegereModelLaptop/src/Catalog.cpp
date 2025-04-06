#include "Catalog.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Catalog::adaugaLaptop(const Laptop &laptop) {
    laptopuri.push_back(laptop);
}

void Catalog::afiseazaCatalog() const {
    for (const auto &laptop : laptopuri) {
        laptop.afiseazaInfo();
    }
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
