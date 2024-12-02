#pragma once
#include "Segment.h"
#include <vector>
#include <string>

class Voyage : public ReservationComposite
{

public:
    Voyage();
    void accept(VisiteurImprimeur& visiteur) override;

};
