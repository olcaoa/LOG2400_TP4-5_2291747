#include "Voyage.h"

Voyage::Voyage() : ReservationComposite() {}

Voyage::Voyage(const Voyage& other) : ReservationComposite(other) {}

AbstractReservation* Voyage::clone() const {
    return new Voyage(*this);
}

void Voyage::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}
