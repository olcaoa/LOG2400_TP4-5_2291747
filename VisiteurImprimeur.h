#pragma once
#include "AbstractReservation.h"

class Journee;
class Segment;
class Voyage;

class VisiteurImprimeur
{
public:
    virtual void visit(AbstractReservation& reservation) = 0;
    virtual void visit(Journee& journee) = 0;
    virtual void visit(Segment& segment) = 0;
    virtual void visit(Voyage& voyage) = 0;

    virtual ~VisiteurImprimeur() = default;
};
