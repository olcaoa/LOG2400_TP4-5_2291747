#pragma once
#include "VisiteurImprimeur.h"

class ImprimeurReservation : public VisiteurImprimeur {
public:
    void visit(AbstractReservation& reservation) override;
    void visit(Journee& journee) override;
    void visit(Segment& segment) override;
    void visit(Voyage& voyage) override;
};
