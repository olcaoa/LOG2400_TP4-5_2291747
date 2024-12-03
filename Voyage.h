#pragma once
#include "Segment.h"
#include <vector>
#include <string>

class Voyage : public ReservationComposite
{
public:
    Voyage(std::string nom);
    Voyage(const Voyage& autreVoyage);
    ~Voyage();
    void accept(VisiteurImprimeur& visiteur) override;
    AbstractReservation* clone() const override;
};
