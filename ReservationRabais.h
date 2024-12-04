#pragma once
#include "AbstractReservationDecoree.h"
class ReservationRabais : public Reservation, public AbstractReservationDecoree
{
private:
	double _rabais = 0;
public:
	ReservationRabais& getReservation(std::string nom);
	ReservationRabais(Reservation& r, double rabais);
	const std::string& getNom() override;
	void accept(VisiteurImprimeur& visiteur) override;
	virtual void decorer() override;
	virtual AbstractReservation* clone() const override;
	const double getPrix() override;
};