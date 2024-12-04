#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "VisiteurImprimeur.h"

class BDOR;
class ImprimeurLoggeur :public VisiteurImprimeur
{
public:
    std::stringstream lecture;
private:
    void visit(Reservation& reservation) override;
    void visit(Journee& journee) override;
    void visit(Segment& segment) override;
    void visit(Voyage& voyage) override;
    void visit(BDOR& db);
    ~ImprimeurLoggeur() = default;
    friend class ReservationLoggeur;
    friend class BDOR;
};

