#include "VisiteurCopieur.h"

AbstractReservation* VisiteurCopieur::visit(Segment& segment) {
    return segment.clone();
}

AbstractReservation* VisiteurCopieur::visit(Voyage& voyage) {
    return voyage.clone();
}

AbstractReservation* VisiteurCopieur::visit(Journee& journee) {
    return journee.clone();
}