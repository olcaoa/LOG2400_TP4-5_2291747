#include "ImprimeurReservation.h"
#include "Reservation.h"
#include "Journee.h"
#include "Segment.h"
#include "Voyage.h"
#include <iostream>
#include <format>


void ImprimeurReservation::visit(Reservation& reservation) {
    lecture << "        Reservation:   " << reservation.getNom();
    if (!reservation._description.empty()) {
        lecture << "    Description: " << reservation._description;
    }
    lecture << "    Prix: " << reservation.getPrix() << "$\n";
}

void ImprimeurReservation::visit(Journee& journee) {
    lecture << std::format("     {} ", journee.getNom()) << ": \n";
    for (auto* reservation : journee.obtenirReservations()) {
        reservation->accept(*this);
    }
}

void ImprimeurReservation::visit(Segment& segment) {
    lecture << std::format("  Segment{} contenant les journees suivantes:\n", segment.getNom());
    for (auto* journee : segment.obtenirReservations()) {
        journee->accept(*this);
    }
}

void ImprimeurReservation::visit(Voyage& voyage) {
    lecture << std::format("\n{} contenant les segments suivants:\n", voyage.getNom());
    for (auto* segment : voyage.obtenirReservations()) {
        segment->accept(*this);
    }
}
