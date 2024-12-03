#pragma once
#include "Journee.h"
#include <vector>
#include <string>

class Segment : public ReservationComposite
{
public:
    Segment();
    Segment(const Segment& autreSegment);

    void accept(VisiteurImprimeur& visiteur) override;
    AbstractReservation* clone() const override;
};