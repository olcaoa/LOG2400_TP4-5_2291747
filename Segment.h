#pragma once
#include "AbstractReservationComposite.h"

class Segment : public ReservationComposite
{
protected:
	std::string imprimer() override;
};

