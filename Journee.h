#pragma once
#include "ReservationComposite.h"
#include "Reservation.h"
#include <vector>
#include <string>

class Journee : public ReservationComposite
{
protected:
	std::string imprimer() override;
};


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
};
