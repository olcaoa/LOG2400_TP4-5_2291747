#pragma once
#include "Segment.h"
#include <vector>
#include <string>

class Voyage : public ReservationComposite
{
private:
    std::vector<Segment*> _segments;
protected:
    std::string imprimer() override;
public:
    Voyage();

    void ajouterSegment(Segment* segment);
    void enleverSegment(Segment* segment);

    const std::vector<Segment*>& obtenirSegments() const;
};
