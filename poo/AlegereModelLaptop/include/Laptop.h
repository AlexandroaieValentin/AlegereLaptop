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
    Laptop() = default;
    Laptop(string brand, string model, double pret, string procesor,
           int memorieRAM, int stocare, string rezolutieEcran, string placaGrafica,
           string baterie);

    void adaugaReview(const Review &review);
    double calculeazaRatingMediu() const;
    void afiseazaInfo() const;

    double getPret() const;
    string getBrand() const;
    string getModel() const;
    string getProcesor() const;
    int getMemorieRAM() const;
    int getStocare() const;
    string getRezolutieEcran() const;
    string getPlacaGrafica() const;
    string getBaterie() const;
    const vector<Review>& getReviews() const { return reviews; }

};

#endif // LAPTOP_H
