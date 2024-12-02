#include "Voyage.h"

Voyage::Voyage() : ReservationComposite() {}

void Voyage::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}