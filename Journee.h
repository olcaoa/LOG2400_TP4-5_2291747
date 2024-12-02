#pragma once
#include "ReservationComposite.h"

class Journee : public ReservationComposite
{
protected:
	std::string imprimer() override;
};