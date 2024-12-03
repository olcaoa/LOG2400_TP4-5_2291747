#include "Segment.h"
#include <sstream>


Segment::Segment() : ReservationComposite() {}

Segment::Segment(const Segment& other) : ReservationComposite(other) {}

AbstractReservation* Segment::clone() const {
    return new Segment(*this);
}

void Segment::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}