#pragma once
#include <sstream>
#include "VisiteurImprimeur.h"
class BDOR;

class ImprimeurReservation : public VisiteurImprimeur {
public:
    std::stringstream lecture;
private:
    void visit(Reservation& reservation) override;
    void visit(Journee& journee) override;
    void visit(Segment& segment) override;
    void visit(Voyage& voyage) override;
    void visit(BDOR& db);
    ~ImprimeurReservation() = default;
    friend class AbstractReservation;
    friend class ReservationLoggeur;
    friend class ReservationCommentee;
    friend class BDOR;
};
