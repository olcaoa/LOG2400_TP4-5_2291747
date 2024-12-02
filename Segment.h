#pragma once
#include "Journee.h"
#include <vector>
#include <string>

class Segment : public ReservationComposite
{
private:
    std::vector<Journee*> _journees;
protected:
    std::string imprimer() override;
public:
    Segment();

    void ajouterJournee(Journee* journee);
    void enleverJournee(Journee* journee);

    const std::vector<Journee*>& obtenirJournees() const;
};