#pragma once
#include "VisiteurImprimeur.h"

class ImprimeurReservation : public VisiteurImprimeur {
private:
    void visit(Reservation& reservation) override;
    void visit(Journee& journee) override;
    void visit(Segment& segment) override;
    void visit(Voyage& voyage) override;
    ~ImprimeurReservation() = default;
};
