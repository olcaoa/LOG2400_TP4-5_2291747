#pragma once
#include "AbstractReservationComposite.h"

class Journee : AbstractReservationComposite
{
protected:
	std::string imprimer() override;
public:
	const std::string& getNom() override;

};