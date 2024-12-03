#pragma once
#include "AbstractReservationDecoree.h"
#include "ImprimeurLoggeur.h"
class ReservationLoggeur : public AbstractReservationDecoree
{
	ReservationLoggeur(Reservation& r);
	const std::string& getNom();
	void accept(VisiteurImprimeur& visiteur);
	virtual void decorer();
};

