#pragma once
#include "AbstractReservationComposite.h"

class Voyage : AbstractReservationComposite
{
protected:
	std::string imprimer() override;
public:
	const std::string& getNom() override;
};

