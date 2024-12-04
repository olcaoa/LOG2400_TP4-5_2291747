#pragma once
#include "Reservation.h"
class AbstractReservationDecoree : virtual public AbstractReservation
{
protected:
	AbstractReservation* _reservation;
	virtual void decorer() = 0;
public:
	const std::string& getNom() override = 0;
	void accept(VisiteurImprimeur& visiteur) override = 0;
	virtual AbstractReservation* clone() const override = 0;
};

