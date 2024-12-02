#include "Journee.h"
#include <sstream>

Journee::Journee() : _mois(1), _jour(1), _annee(2000) {}

Journee::Journee(int mois, int jour, int annee) : _mois(mois), _jour(jour), _annee(annee) {
    _nom = "Journee " + getDate();
    _description = "Réservations pour la journée " + getDate();
}

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
        << _jour << "/"
        << _annee;
    return oss.str();
}

void Journee::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
    ReservationComposite::accept(visiteur); // Enfants
}