#include "Journee.h"
#include <sstream>

Journee::Journee() : _mois(1), _jour(1), _annee(2000) {}

Journee::Journee(const Journee& other)
    : ReservationComposite(other), _mois(other._mois), _jour(other._jour), _annee(other._annee) {}


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
}

AbstractReservation* Journee::clone() const {
    return new Journee(*this);
}