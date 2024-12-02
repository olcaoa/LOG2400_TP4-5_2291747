#pragma once
#include "AbstractReservationComposite.h"
#include "Reservation.h"
#include <vector>
#include <string>

class Journee : public ReservationComposite
{
private:
    int _mois;
    int _jour;
    int _annee;

public:
	Journee();

    Journee(int mois, int jour, int annee);

    int getMois() const;
    int getJour() const;
    int getAnnee() const;
    std::string getDate() const;

    std::string imprimer() override;
};
