#include "Reservation.h"

Reservation::Reservation(const Reservation& other)
{
    *this = *dynamic_cast<Reservation*>(other.clone());
}

Reservation::Reservation(std::string nom, std::string description, double prix) {
    this->_nom = nom;
    this->_description = description;
    this->_prix = prix;
}

AbstractReservation* Reservation::clone() const
{
    return new Reservation(this->_nom, this->_description, this->_prix);
}

void Reservation::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}
