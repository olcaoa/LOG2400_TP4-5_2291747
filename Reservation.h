#pragma once
#include "AbstractReservationComposite.h"

class Reservation : public AbstractReservation
{
public:
	Reservation(std::string nom, std::string description, double prix);
protected:
	std::string imprimer() override;
};