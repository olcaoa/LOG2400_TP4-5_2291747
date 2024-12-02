#pragma once
#include "AbstractReservationComposite.h"

class Voyage : public ReservationComposite
{
protected:
	std::string imprimer() override;
};

