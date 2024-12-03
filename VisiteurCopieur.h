#pragma once
#include "VisiteurCopieurInterface.h"
#include "Segment.h"
#include "Voyage.h"
#include "Journee.h"

class VisiteurCopieur : public VisiteurCopieurInterface {
public:
    AbstractReservation* visit(Segment& segment) override;
    AbstractReservation* visit(Voyage& voyage) override;
    AbstractReservation* visit(Journee& journee) override;
};