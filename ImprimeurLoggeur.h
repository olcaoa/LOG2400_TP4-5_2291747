#pragma once
#include <iostream>
#include <fstream>
#include "VisiteurImprimeur.h"
class ImprimeurLoggeur :public VisiteurImprimeur
{
    void visit(Reservation& reservation) override;
    void visit(Journee& journee) override;
    void visit(Segment& segment) override;
    void visit(Voyage& voyage) override;
    ~ImprimeurLoggeur() = default;
};

