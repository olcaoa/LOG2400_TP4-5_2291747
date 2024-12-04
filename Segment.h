#pragma once
#include "Journee.h"
#include <vector>
#include <string>

class Segment : public ReservationComposite
{
public:
    Journee getJournee(std::string nom);
    Segment(std::string nom);
    ~Segment();
    Segment(const Segment& autreSegment);
    void ajouterJournee(Journee& j);
    void accept(VisiteurImprimeur& visiteur) override;
    AbstractReservation* clone() const override;
};