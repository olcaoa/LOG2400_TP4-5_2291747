#pragma once
#include "LecteurFichier.h"
#include "Reservation.h"
#include <string>
#include <vector>
#include <map>

class IterateurLecteurFichier {
private:
    LecteurFichier& lecteurFichier;
    std::string categorie;
    size_t index;
    const std::map<std::string, double> tauxDeChange = {
        {"CAD", 1.0}, {"EURO", 1.5}, {"USD", 1.2} // taux de change arbitraires
    };

    double convertirPrix(const std::string& prix, const std::string& devise);

public:
    IterateurLecteurFichier(LecteurFichier& lecteur, const std::string& categorie);

    bool aSuivant() const;
    Reservation* suivant();

    void reinitialiser();
};
