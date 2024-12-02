#include "Journee.h"
#include <sstream>

// Constructeur
Journee::Journee(int mois, int jour, int annee) : _mois(mois), _jour(jour), _annee(annee) {
    _nom = "Journee " + getDate();
    _description = "Réservations pour la journée " + getDate();
}

// Accesseurs pour la date
int Journee::getMois() const {
    return _mois;
}

int Journee::getJour() const {
    return _jour;
}

int Journee::getAnnee() const {
    return _annee;
}

std::string Journee::getDate() const {
    std::ostringstream oss;
    oss << _mois << "/"
        <<  _jour << "/"
        << _annee;
    return oss.str();
}

std::string Journee::imprimer() {
    return "Date: " + getDate() + "\nRéservations :\n" + imprimerEnfants();
}
