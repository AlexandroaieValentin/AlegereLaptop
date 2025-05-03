#include "Laptop.h"
#include <iostream>
#include <iomanip>
using namespace std;


Laptop::Laptop(string brand, string model, double pret, string procesor,
               int memorieRAM, int stocare, string rezolutieEcran, string placaGrafica,
               string baterie)
    : brand(brand), model(model), pret(pret), procesor(procesor), memorieRAM(memorieRAM),
      stocare(stocare), rezolutieEcran(rezolutieEcran), placaGrafica(placaGrafica), baterie(baterie) {}

void Laptop::adaugaReview(const Review &review) {
    reviews.push_back(review);
}

double Laptop::calculeazaRatingMediu() const {
    if (reviews.empty())
        return 0.0;
    int suma = 0;
    for (const auto &rev : reviews) {
        suma += rev.getRating();
    }
    return static_cast<double>(suma) / reviews.size();
}

void Laptop::afiseazaInfo() const {
    cout << "Brand: " << brand << "\n";
    cout << "Model: " << model << "\n";
    cout << "Pret: " << fixed << setprecision(2) << pret << " lei\n";
    cout << "Procesor: " << procesor << "\n";
    cout << "Memorie RAM: " << memorieRAM << " GB\n";
    cout << "Stocare: " << stocare << " GB\n";
    cout << "Rezolutie Ecran: " << rezolutieEcran << "\n";
    cout << "Placa Grafica: " << placaGrafica << "\n";
    cout << "Baterie: " << baterie << "\n";

    double ratingMediu = calculeazaRatingMediu();
    if (ratingMediu > 0)
        cout << "Rating mediu: " << fixed << setprecision(2) << ratingMediu << "/5\n";
    else
        cout << "Fara evaluari\n";

    if (!reviews.empty()) {
        cout << "Review-uri:\n";
        for (const auto& r : reviews) {
            r.afiseazaReview();
        }
    }

    cout << "---------------------\n";
}


double Laptop::getPret() const {
    return pret;
}

string Laptop::getBrand() const {
    return brand;
}
string Laptop::getModel() const { return model; }
string Laptop::getProcesor() const { return procesor; }
int Laptop::getMemorieRAM() const { return memorieRAM; }
int Laptop::getStocare() const { return stocare; }
string Laptop::getRezolutieEcran() const { return rezolutieEcran; }
string Laptop::getPlacaGrafica() const { return placaGrafica; }
string Laptop::getBaterie() const { return baterie; }
