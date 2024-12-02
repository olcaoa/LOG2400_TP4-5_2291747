#pragma once
#include "ReservationComposite.h"

class Segment : public ReservationComposite
{
protected:
	std::string imprimer() override;
};

