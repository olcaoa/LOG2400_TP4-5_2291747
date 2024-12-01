#pragma once
#include "AbstractReservationComposite.h"

class Reservation : AbstractReservationComposite
{
protected:
	std::string imprimer() override;
public:
	const std::string& getNom() override;
};