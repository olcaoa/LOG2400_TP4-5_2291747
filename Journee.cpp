#include "Journee.h"
#include <sstream>

Reservation Journee::getReservation(std::string nom)
{
    return *dynamic_cast<Reservation*>(ReservationComposite::getReservation(nom));
}

Journee::Journee() : _mois(1), _jour(1), _annee(2000) {}

Journee::Journee(const Journee& other)
{
    *this = *dynamic_cast<Journee*>(other.clone());
}

Journee::Journee(int mois, int jour, int annee) : _mois(mois), _jour(jour), _annee(annee) {
    _nom = "Journee " + getDate();
    _description = "Réservations pour la journée " + getDate();
}

Journee::~Journee()
{
    _reservations.clear();
    _reservations.shrink_to_fit();
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

void Journee::ajouterReservation(Reservation& r)
{
    ReservationComposite::ajouterReservation(&r);
}

void Journee::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}

AbstractReservation* Journee::clone() const {
    Journee* nouveauJour = new Journee(this->getMois(), this->getJour(), this->getAnnee());
    for (AbstractReservation* r : this->_reservations) {
        AbstractReservation* currRes = r;
        Reservation* r = dynamic_cast<Reservation*>(currRes);
        nouveauJour->ReservationComposite::ajouterReservation(new Reservation(*r));
    }
    return nouveauJour;
}