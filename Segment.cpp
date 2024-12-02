#include "Segment.h"
#include <sstream>


Segment::Segment() : ReservationComposite() {}


void Segment::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
}