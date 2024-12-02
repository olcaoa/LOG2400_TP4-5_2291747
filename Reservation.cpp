#include "Reservation.h"

Reservation::Reservation(std::string nom, std::string description, double prix) {
    this->_nom = nom;
    this->_description = description;
    this->_prix = prix;
}

void Reservation::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}
