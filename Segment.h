#pragma once
#include "Journee.h"
#include <vector>
#include <string>

class Segment : public ReservationComposite
{
private:
    std::vector<Journee*> _journees;
public:
    Segment();

    void ajouterJournee(Journee* journee);
    void enleverJournee(Journee* journee);

    void accept(VisiteurImprimeur& visiteur) override;

    const std::vector<Journee*>& obtenirJournees() const;
};