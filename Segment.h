#pragma once
#include "AbstractReservationComposite.h"

class Segment : AbstractReservationComposite
{
protected:
	std::string imprimer() override;
public:
	const std::string& getNom() override;
};

