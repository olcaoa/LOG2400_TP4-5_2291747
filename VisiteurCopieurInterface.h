#pragma once
#include "AbstractReservation.h"
#include "Segment.h"
#include "Voyage.h"
#include "Journee.h"

class VisiteurCopieurInterface {
public:
    virtual AbstractReservation* visit(Segment& segment) = 0;
    virtual AbstractReservation* visit(Voyage& voyage) = 0;
    virtual AbstractReservation* visit(Journee& journee) = 0;
};