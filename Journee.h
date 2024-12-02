#pragma once
#include "AbstractReservationComposite.h"
#include "Reservation.h"

class Journee : public ReservationComposite
{
private:
	std::vector<Reservation*> _reservations;
protected:
	std::string imprimer() override;
};