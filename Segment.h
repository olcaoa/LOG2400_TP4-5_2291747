#pragma once
#include "Journee.h"
#include <vector>
#include <string>

class Segment : public ReservationComposite
{
public:
    Segment();

    void accept(VisiteurImprimeur& visiteur) override;

};