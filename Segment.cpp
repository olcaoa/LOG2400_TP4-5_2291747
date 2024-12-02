#include "Segment.h"
#include <sstream>


Segment::Segment() : ReservationComposite() {}

void Segment::ajouterJournee(Journee* journee) {
    _journees.push_back(journee);
    ajouterReservation(journee);
}

void Segment::enleverJournee(Journee* journee) {
    auto it = std::find(_journees.begin(), _journees.end(), journee);
    if (it != _journees.end()) {
        _journees.erase(it);
        enleverReservation(journee);
    }
}

const std::vector<Journee*>& Segment::obtenirJournees() const {
    return _journees;
}

void Segment::accept(VisiteurImprimeur& visiteur) {
    visiteur.visit(*this);
    ReservationComposite::accept(visiteur);
}