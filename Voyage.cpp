#include "Voyage.h"

Voyage::~Voyage()
{
    _reservations.clear();
    _reservations.shrink_to_fit();
}

Voyage::Voyage(std::string nom) : ReservationComposite() {
    _nom = nom;
}

Voyage::Voyage(const Voyage& autreVoyage)
{
    *this = *dynamic_cast<Voyage*>(autreVoyage.clone());
}

AbstractReservation* Voyage::clone() const {
    Voyage* nouveauVoyage = new Voyage(this->_nom);
    for (AbstractReservation* r : this->_reservations) {
        AbstractReservation* currRes = r;
        Segment* r = dynamic_cast<Segment*>(currRes);
        nouveauVoyage->ajouterReservation(new Segment(*r));
    }
    return nouveauVoyage;
}

void Voyage::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}
