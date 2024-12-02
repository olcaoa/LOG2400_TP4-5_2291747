#pragma once
#include "AbstractReservation.h"

class ImprimeurReservation
{
protected:
	const std::string& imprimer(AbstractReservation& r);
	friend class ReservationComposite;
};

