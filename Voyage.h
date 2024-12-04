#pragma once
#include "Segment.h"
#include <vector>
#include <string>

class Voyage : public ReservationComposite
{
public:
    Segment getSegment(std::string nom);
    void ajouterSegment(Segment& s);
    void enleverSegment(Segment& s);
    Voyage(std::string nom);
    Voyage(const Voyage& autreVoyage);
    ~Voyage();
    void accept(VisiteurImprimeur& visiteur) override;
    AbstractReservation* clone() const override;
};
