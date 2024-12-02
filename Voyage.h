#pragma once
#include "ReservationComposite.h"
#include "Segment.h"
#include <vector>
#include <string>

class Voyage : public ReservationComposite
{
private:
    std::string imprimer() override;
    std::vector<Segment*> _segments;

public:
    Voyage();

    void ajouterSegment(Segment* segment);
    void enleverSegment(Segment* segment);

    const std::vector<Segment*>& obtenirSegments() const;
};
