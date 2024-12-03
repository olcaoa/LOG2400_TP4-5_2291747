#pragma once
#include "Reservation.h"
class AbstractReservationDecoree : public AbstractReservation
{
protected:
	Reservation* _reservation;
	virtual void decorer() = 0;
public:
	AbstractReservationDecoree(Reservation& r);
	const std::string& getNom() override = 0;
	void accept(VisiteurImprimeur& visiteur) override = 0;
};

