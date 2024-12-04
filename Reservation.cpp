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

Reservation& Reservation::getReservation(std::string nom)
{
    return *dynamic_cast<Reservation*>(ReservationComposite::getReservation(nom));
}

void Reservation::ajouterReservation(Reservation* r)
{
    ReservationComposite::ajouterReservation(r);
}

void Reservation::enleverReservation(Reservation* r)
{
    ReservationComposite::enleverReservation(r);
}


bool Reservation::comparerReservations(Reservation compare)
{
    return this->getNom() == compare.getNom();
}

void Reservation::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}

Reservation::Reservation()
{
}
