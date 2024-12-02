#include "Voyage.h"

Voyage::Voyage() : ReservationComposite() {}

void Voyage::ajouterSegment(Segment* segment) {
    _segments.push_back(segment);
    ajouterReservation(segment);
}

void Voyage::enleverSegment(Segment* segment) {
    auto it = std::find(_segments.begin(), _segments.end(), segment);
    if (it != _segments.end()) {
        _segments.erase(it);
        enleverReservation(segment);
    }
}

const std::vector<Segment*>& Voyage::obtenirSegments() const {
    return _segments;
}

