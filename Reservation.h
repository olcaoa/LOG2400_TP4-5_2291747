#pragma once
#include "AbstractReservation.h"

class Reservation : public AbstractReservation
{
public:
	Reservation(std::string nom, std::string description, double prix);
protected:
	void accept(VisiteurImprimeur& visiteur) override;
};