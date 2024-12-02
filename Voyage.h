#pragma once
#include "AbstractReservationComposite.h"
#include "Segment.h"
#include <vector>
#include <string>

class Voyage : public ReservationComposite
{
private:
    std::vector<Segment*> _segments;

public:
    Voyage();

    void ajouterSegment(Segment* segment);
    void enleverSegment(Segment* segment);

    const std::vector<Segment*>& obtenirSegments() const;

    std::string imprimer() override;
};
