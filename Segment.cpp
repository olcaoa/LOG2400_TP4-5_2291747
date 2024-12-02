#include "Segment.h"
#include <sstream>


std::string Segment::imprimer()
{
    return "A implementer \n" + imprimerEnfants();
}

Segment::Segment() : ReservationComposite() {}

void Segment::ajouterJournee(Journee* journee) {
    _journees.push_back(journee);
    ajouterReservation(journee); // Ajoute également à la hiérarchie de `ReservationComposite`
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