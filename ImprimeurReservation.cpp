#include "ImprimeurReservation.h"
#include "Reservation.h"
#include "Journee.h"
#include "Segment.h"
#include "Voyage.h"
#include <iostream>
#include <format>

void ImprimeurReservation::visit(Reservation& reservation) {
    std::cout << "   Reservation:\n    Nom: " << reservation.getNom()
              << "\n    Description: " << reservation._description
              << "\n    Prix: " << reservation.getPrix() << "$\n";
}

void ImprimeurReservation::visit(Journee& journee) {
    std::cout << std::format("  Journee {} ", journee.getNom()) << 
        "[Date: " << journee.getMois() << "/" << journee.getJour() << "/" << journee.getAnnee() << "]:\n";
    for (auto* reservation : journee.obtenirReservations()) {
        reservation->accept(*this);
    }
}

void ImprimeurReservation::visit(Segment& segment) {
    std::cout << std::format(" Segment {} contenant les journees suivantes:\n", segment.getNom());
    for (auto* journee : segment.obtenirReservations()) {
        journee->accept(*this);
    }
}

void ImprimeurReservation::visit(Voyage& voyage) {
    std::cout << std::format("Voyage {} contenant les segments suivants:\n", voyage.getNom());
    for (auto* segment : voyage.obtenirReservations()) {
        segment->accept(*this);
    }
}
