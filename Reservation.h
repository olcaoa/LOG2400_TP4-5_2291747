#pragma once
#include "AbstractReservation.h"

class Reservation : public AbstractReservation
{
public:
	Reservation(const Reservation& other);
	Reservation(std::string nom, std::string description, double prix);
	AbstractReservation* clone() const override;
protected:
	void accept(VisiteurImprimeur& visiteur) override;
};