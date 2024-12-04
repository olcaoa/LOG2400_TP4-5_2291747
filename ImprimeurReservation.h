#pragma once
#include <sstream>
#include "VisiteurImprimeur.h"

class ImprimeurReservation : public VisiteurImprimeur {
public:
    std::stringstream lecture;
private:
    void visit(Reservation& reservation) override;
    void visit(Journee& journee) override;
    void visit(Segment& segment) override;
    void visit(Voyage& voyage) override;
    ~ImprimeurReservation() = default;
    friend class AbstractReservation;
};
