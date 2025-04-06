#ifndef LAPTOP_H
#define LAPTOP_H

#include <string>
#include <vector>
#include "Review.h"
using namespace std;

class Laptop {
private:
    string brand;
    string model;
    double pret;
    string procesor;
    int memorieRAM;
    int stocare;
    string rezolutieEcran;
    string placaGrafica;
    string baterie;
    vector<Review> reviews;

public:
    Laptop(string brand, string model, double pret, string procesor,
           int memorieRAM, int stocare, string rezolutieEcran, string placaGrafica,
           string baterie);

    void adaugaReview(const Review &review);
    double calculeazaRatingMediu() const;
    void afiseazaInfo() const;


    double getPret() const;
    string getBrand() const;
};

#endif // LAPTOP_H
