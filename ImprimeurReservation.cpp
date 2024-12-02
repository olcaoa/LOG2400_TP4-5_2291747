#include "ImprimeurReservation.h"
#include "Reservation.h"
#include "Journee.h"
#include "Segment.h"
#include "Voyage.h"
#include <iostream>

void ImprimeurReservation::visit(AbstractReservation& reservation) {
    std::cout << "Reservation:\nNom: " << reservation._nom 
              << "\nDescription: " << reservation._description
              << "\nPrix: " << reservation._prix << "$\n";
}

void ImprimeurReservation::visit(Journee& journee) {
    std::cout << "Journee [Date: " << journee.getMois() << "/" << journee.getJour() << "/" << journee.getAnnee() << "]:\n";
    for (auto* reservation : journee.obtenirReservations()) {
        reservation->accept(*this);
    }
}

void ImprimeurReservation::visit(Segment& segment) {
    std::cout << "Segment contenant les journées suivantes:\n";
    for (auto* journee : segment.obtenirJournees()) {
        journee->accept(*this);
    }
}

void ImprimeurReservation::visit(Voyage& voyage) {
    std::cout << "Voyage contenant les segments suivants:\n";
    for (auto* segment : voyage.obtenirSegments()) {
        segment->accept(*this);
    }
}
