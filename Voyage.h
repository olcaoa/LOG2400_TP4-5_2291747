#pragma once
#include "Segment.h"
#include <vector>
#include <string>

class Voyage : public ReservationComposite
{

public:
    Voyage();
    Voyage(const Voyage& autreVoyage);

    void accept(VisiteurImprimeur& visiteur) override;
    AbstractReservation* clone() const override;
};
