#pragma once
#include "ReservationComposite.h"

class Voyage : public ReservationComposite
{
protected:
	std::string imprimer() override;
};

