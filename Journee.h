#pragma once
#include <vector>
#include <string>
#include "ReservationComposite.h"
#include "Reservation.h"

class Journee : public ReservationComposite
{
private:
    int _mois;
    int _jour;
    int _annee;

public:
	Journee();
    Journee(const Journee& other);
    Journee(int mois, int jour, int annee);
    ~Journee();
    int getMois() const;
    int getJour() const;
    int getAnnee() const;
    std::string getDate() const;

    void accept(VisiteurImprimeur& visiteur) override;
    AbstractReservation* clone() const override;
};
