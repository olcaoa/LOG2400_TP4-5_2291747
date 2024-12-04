#pragma once
#include "AbstractReservationDecoree.h"
#include "ImprimeurLoggeur.h"
class ReservationLoggeur : public AbstractReservationDecoree
{
public:
	ReservationLoggeur(AbstractReservation& r);
	const std::string& getNom();
	void accept(VisiteurImprimeur& visiteur);
	virtual void decorer();
	virtual AbstractReservation* clone() const override;
};

